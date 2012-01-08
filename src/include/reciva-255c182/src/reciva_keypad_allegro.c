/*
 * linux/reciva/reciva_keypad_allegro.c
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * Copyright (c) 2004 Reciva Ltd. All Rights Reserved
 * 
 * Keyboard driver for Reciva Allegro-Strontium radio
 *
 * Version 1.0 2003-12-12  John Stirling <js@reciva.com>
 *
 */

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/input.h>
#include <linux/slab.h>

#include <asm/delay.h>
#include <asm/hardware.h>
#include <asm/irq.h>
#include <asm/mach-types.h>

#include "reciva_keypad_driver.h"
#include "reciva_keypad_generic.h"

   /*************************************************************************/
   /***                        Local typedefs                             ***/
   /*************************************************************************/

   /*************************************************************************/
   /***                        Static functions                           ***/
   /*************************************************************************/

/* Driver functions */
static int allegro_decode_key_press(int row, int column, int shift);
static int *allegro_keys_present(void);
static int *allegro_alt_key_functions(void);


   /*************************************************************************/
   /***                        Local Constants                            ***/
   /*************************************************************************/

   /*************************************************************************/
   /***                        Static Data                                ***/
   /*************************************************************************/

/* Converts a columnn and row into an ascii key press value (shift off) */
static const int aacKeyDecodeShiftOff[RKD_NUM_ROWS][RKD_NUM_COLS] =
{
  /* Column 0          Column 1       Column 2      Column 3 */
  {RKD_BACK,           RKD_SELECT,    RKD_REPLY,    RKD_UNUSED}, // Row 0
  {RKD_PRESET_2,       RKD_PRESET_3,  RKD_PRESET_4, RKD_VOL_UP}, // Row 1
  {RKD_PRESET_5,       RKD_PRESET_6,  RKD_ALARM,    RKD_UNUSED}, // Row 2
  {RKD_PRESET_1,       RKD_SHIFT,     RKD_POWER,    RKD_VOL_DOWN}// Row 3
};

/* Converts a columnn and row into an ascii key press value (shift on) */
static const int aacKeyDecodeShiftOn[RKD_NUM_ROWS][RKD_NUM_COLS] =
{
  /* Column 0          Column 1       Column 2      Column 3 */
  {RKD_BACK,           RKD_SELECT,    RKD_REPLY,    RKD_UNUSED}, // Row 0
  {RKD_PRESET_8,       RKD_PRESET_9,  RKD_PRESET_10,RKD_VOL_UP}, // Row 1
  {RKD_PRESET_11,      RKD_PRESET_12, RKD_ALARM,    RKD_UNUSED}, // Row 2
  {RKD_PRESET_7,       RKD_SHIFT,     RKD_POWER,    RKD_VOL_DOWN}// Row 3
};

/* A list of keys that are present */
static int aiKeysPresent[RKD_MAX_KEYS] =
{
  RKD_PRESET_1,
  RKD_PRESET_2,
  RKD_PRESET_3,
  RKD_PRESET_4,
  RKD_PRESET_5,
  RKD_PRESET_6,
  RKD_SELECT,
  RKD_BACK,
  RKD_REPLY,
  RKD_POWER,
  RKD_SHIFT,
  RKD_ALARM,
  RKD_VOL_UP,
  RKD_VOL_DOWN,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0
};

/* A list of alternate key functions */
static int aiAlternateKeyFunctions[RKD_MAX_KEYS] =
{
  RKD_STOP,          /* PRESET1 */
  RKD_SKIP_PREVIOUS, /* PRESET2 */
  RKD_PLAY_PAUSE,    /* PRESET3 */
  RKD_SKIP_NEXT,     /* PRESET4 */
  RKD_BROWSE_QUEUE,  /* PRESET5 */
  RKD_PLAYBACK_MODE, /* PRESET6 */
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
  RKD_UNUSED,
};

static char acModuleName[] = "Reciva Allegro Strontium Keypad Driver";

static const reciva_keypad_driver_t driver =
{
  name:              acModuleName,
  decode_key_press:  allegro_decode_key_press,
  keys_present:      allegro_keys_present,
  alt_key_functions: allegro_alt_key_functions,
};

   /*************************************************************************/
   /***                        Public functions                           ***/
   /*************************************************************************/


/****************************************************************************
 * Module initialisation
 ****************************************************************************/
static int __init 
rkd_init(void)
{
  printk("RKD:%s module: loaded\n", acModuleName);
  rkg_register(&driver); /* Register driver */
  return 0;
}

/****************************************************************************
 * Module tidy up
 ****************************************************************************/
static void __exit 
rkd_exit(void)
{
  printk("RKD:%s module: unloaded\n", acModuleName);
}


/****************************************************************************
 * Decode key press
 * row - keypad row
 * column - keypad column
 * shift - shift key status
 ****************************************************************************/
static int allegro_decode_key_press(int row, int column, int shift)
{
  if (row > RKD_NUM_ROWS)
    row = 0;
  if (column > RKD_NUM_COLS)
    column = 0;

  if (shift)
    return aacKeyDecodeShiftOn[row][column];
  else
    return aacKeyDecodeShiftOff[row][column];
}  

/****************************************************************************
 * Return pointer to array containing a list of keys that are supported by
 * this hardware
 ****************************************************************************/
static int *allegro_keys_present()
{
  return aiKeysPresent;
}

/****************************************************************************
 * Return pointer to array containing a list of alternate key functions
 ****************************************************************************/
static int *allegro_alt_key_functions(void)
{
  return aiAlternateKeyFunctions;
}


   /*************************************************************************/
   /***                        Private functions                          ***/
   /*************************************************************************/

module_init(rkd_init);
module_exit(rkd_exit);

MODULE_AUTHOR("John Stirling <js@reciva.com>");
MODULE_DESCRIPTION("Reciva Keypad");
MODULE_LICENSE("GPL");

