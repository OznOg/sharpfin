/*
 * CTX2050 Registers
 * Copyright (c) 2008 Reciva Ltd
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version
 * 2 of the License, or (at your option) any later version.
 */

#ifndef __CTX2050_REGS_H__
#define __CTX2050_REGS_H__

// BBM BANK 
#define BBM_CTRL_BANK 			0x0000
#define BBM_DIDP_BANK 			0x0003
#define BBM_FIC0_BANK 			0x0004
#define BBM_FIC1_BANK 			0x0005
#define BBM_MSC0_BANK 			0x0007
#define BBM_MSC1_BANK 			0x0008
#define BBM_MSC2_BANK 			0x0009
#define BBM_MSC3_BANK 			0x000A
#define BBM_MSC4_BANK 			0x000B
#define BBM_PAD0_BANK 			0x000D
#define BBM_PAD1_BANK 			0x000E
#define BBM_PAD2_BANK 			0x000F

// BBM INTERRUPT SOURCE
#define BBM_BANK_REG			0x0000
#define BBM_FIC_INT			0x0001
#define BBM_MSC_INT			0x0002
#define BBM_SYNC_INT			0x0004
#define BBM_MP2_INT			0x0008
#define BBM_WAGC_INT			0x0010
#define BBM_I2C_INT			0x0020
#define BBM_RECFG_INT			0x0040
#define BBM_SPI_INT			0x0080
#define BBM_RS_INT			0x0100
#define BBM_TII_INT			0x0200

// BBM MODEM REGISTER MAP
#define BBM_SW_RESET_REG		0x0001	
#define BBM_INT_STATUS_REG		0x0002
#define BBM_INT_MASK_REG		0x0004
#define BBM_INT_CLEAR_REG		0x0006
#define BBM_DBG_SEL1_REG		0x0008
#define BBM_DBG_SEL2_REG		0x0009
#define BBM_STATUS_REG			0x000A
#define BBM_FICERR_REG			0x000B
#define BBM_LED_REG			0x000C

// BBM RS REGISTER MAP
#define RSD_FAIL_CNT_REG		0x0024
#define RSD_ERR_SUM_REG			0x0026
#define RSD_NFRAME_REG			0x0028

#define RSD_TSMODE1_REG			0x002C
#define RSD_TSMODE2_REG			0x002D
#define FFT_SCALEV_REG			0x0020
#define IFFT_SCALEV_REG			0x0021

// Centronix , OuterCoder ����
#define RS_SYNC_DET_REG0		0x0030
#define CDI_SYNC_DET_REG0		0x0030
#define CDI_SYNC_DET_REG1		0x0031
#define CDI_SYNC_DET_REG2		0x0032
#define CDI_SYNC_DET_REG3		0x0033

// BBM DESCRAMBLER REGISTER MAP
#define DESCR_CFG0_REG			0x0040
#define DESCR_CFG1_REG			0x0041
#define DESCR_CFG2_REG			0x0042
#define DESCR_CFG3_REG			0x0043
#define DESCR_CFG4_REG			0x0044
#define DESCR_CFG5_REG			0x0045
#define DESCR_CFG6_REG			0x0046
#define DESCR_CFG7_REG			0x0047

#define DESCR_DATA_REG			0x0200	
//#define DESCR_SCHID_REG			0x0045
#define DESCR_WDEPTH_REG		0x0044 

#define DSCR_MEM_ENABLE			0x00E9

#define MSC_WDEPTH_REG			0x004C	
#define MSC_DDEPTH_REG			0x004E
#define FIC_WDEPTH_REG			0x0048
#define FIC_DDEPTH_REG			0x004A

#define MSC_SCHID_REG			0x00E0
#define FIC_INT_MODE_REG		0x00E1
#define MSC_HW_BANK_SEL			0x00E2

// BBM VITERBI REGISTER MAP
#define VIT_REF_TYPE_REG		0x0050
#define VIT_BPER_REG			0x0050

#define VIT_TBE_REG			0x0054

#define VIT_BERMEM_REG			0x005C

// BBM AGC REGISTER MAP
#define AGC_QDD_RDATA1_REG		0x0060
#define AGC_QDD_RDATA2_REG		0x0061
#define AGC_QDD_WDATA1_REG		0x0062
#define AGC_REFGAIN_REG			0x0068
#define AGC_ONOFF_REG			0x006A

// BBM SYNC REGISTER MAP
#define SYNC_MODE_REG			0x0090
#define SYNC_FFT_SHIFT_REG		0x0091
#define SYNC_FF_EZ_FRACT_REG		0x0092
#define SYNC_FF_EST_PERIOD_REG		0x0093
#define SYNC_FF_AVG_LEN_REG		0x0094
#define SYNC_FF_D4GIBSHIFT_REG		0x0095
#define SYNC_CF_EINT_REG		0x0096
#define SYNC_CF_CBW1_REG		0x0097
#define SYNC_NSBLK1_REG			0x0098
#define SYNC_OFFSET_RANGEP_REG		0x0099
#define SYNC_OFFSET_RANGEM_REG		0x009a
#define SYNC_CF_OVF_THRES_REG		0x009b
#define SYNC_FT_TOFFSET_REG		0x009c
#define SYNC_FT_TOFST_SCAN_REG		0x009d
#define SYNC_FT_OVF_THRES_REG		0x009e
#define SYNC_CTRL0_REG			0x0096
#define SYNC_CTRL1_REG			0x0097
#define SYNC_STATUS_REG			0x0098

// BBM MP2 AUDIO REGISTER MAP
#define MP2_HEADER_INFO1_REG		0x00C0
#define MP2_HEADER_INFO2_REG		0x00C1
#define MP2_HEADER_INFO3_REG		0x00C2
#define MP2_CH_SELECT_REG		0x00C3
#define MP2_CTRL1_REG			0x00C4
#define MP2_CTRL2_REG			0x00C5
#define MP2_INT_CTRL_REG		0x00C6
#define MP2_INT_STATUS_REG		0x00C7
#define MP2_DBG_SEL_REG			0x00C8
#define MP2_ALARM_CTRL_REG		0x00C9
#define MP2_ALARM_STATUS_REG		0x00CA
#define MP2_BSBUF_LV_REG		0x00CB
#define MP2_PCMBUF_LV_REG		0x00CC
#define MP2_PAD_DEPTH_REG		0x00D0
#define MP2_PAD_CTRL_REG		0x00D1
#define MP2_EQ_GAIN_REG			0x00D3
#define MP2_SYNC_ERROR_REG		0x00D4
#define MP2_HEAD_ERROR_REG		0x00D5
#define MP2_CRC_ERROR_REG		0x00D6

#define FIC_DATA_REG_L			0x0410	
#define FIC_DATA_REG_H			0x0510

#define MSC_DATA0_REG			0x0710
#define MSC_DATA1_REG			0x0810
#define MSC_DATA2_REG			0x0910
#define MSC_DATA3_REG			0x0A10
#define MSC_DATA4_REG			0x0B10

// BBM Time Deinterleaver REGISTER MAP
#define TDLV_CIF_REG			0x0310
#define TDLV_CFG_EN_REG			0x0311
#define TDLV_CIF_CTRL_REG0		0x0312	// +0x06*4, +0x18 * 4   // DIDP  16bit 0x201
#define TDLV_CIF_CTRL_REG1		0x0212	

// I2C Master 
#define I2C_PRER_REG			0x10
#define I2C_CTR_REG			0x12
#define I2C_RXR_REG			0x13
#define I2C_SR_REG			0x14
#define I2C_TXR_REG			0x15
#define I2C_CR_REG			0x16

#endif // __CTX2050_REGS_H__