#ifndef _MZ0380_H
#define _MZ0380_H

#include "LINUXV4L2.h"

#include "ite6603.h"
#include "tp2834.h"

typedef struct _MZ0380_SYS_CFG
{
	CSCMatrix  o_csc_matrix;

	CSCMatrix  o_csc_original;

	ULONG      n_output_video_resolution_vi_fw;

	ULONG      n_output_video_resolution_cx;

	ULONG      n_output_video_resolution_cy;

	ULONG      n_output_video_resolution_fps;

	ULONG      n_output_video_resolution_fps_m;

	ULONG      n_output_video_resolution_interleaved;

	ULONG      n_output_video_resolution_is_nosg;

	ULONG	   n_output_video_resolution_vbi_F3B543EB6D1C348648C2947A125F64000;

	ULONG      n_output_audio_sampling_frequency;

	ULONG	   n_output_multi_sync_channels;

	ULONG      n_input_video_resolution_cx;

	ULONG      n_input_video_resolution_cy;

	ULONG      n_input_video_resolution_fps;

	ULONG      n_input_video_resolution_fps_m;

	ULONG      n_input_video_resolution_interleaved;

	ULONG      n_input_video_resolution_ch_info;

	ULONG      n_input_video_resolution_vbi_F3B543EB6D1C348648C2947A125F64000;

	ULONG      n_input_video_resolution_h_total;

	ULONG      n_input_video_resolution_v_total;

	ULONG      n_input_video_resolution_hv_polarity;

	ULONG      n_input_video_resolution_color_colorimetry;

	ULONG      n_input_video_resolution_color_range;

	BOOL       b_input_video_resolution_spliter_mode;

	BOOL	   b_input_video_resolution_external_sync;

	ULONG      b_input_video_resolution_vga_h_period_us;

	ULONG      b_input_video_resolution_vga_v_period_us;

	ULONGLONG  b_input_video_resolution_vga_h_period_us_sum;

	ULONGLONG  b_input_video_resolution_vga_v_period_us_sum;

	ULONG      b_input_video_resolution_vga_period_us_counts;

	LONG	   n_input_video_resolution_offset_x_start_vesa[ DEFAULT_MST3367_VESA_SIZE ];

	LONG	   n_input_video_resolution_offset_y_start_vesa[ DEFAULT_MST3367_VESA_SIZE ];

	LONG	   n_input_video_resolution_offset_dirty_vesa[ DEFAULT_MST3367_VESA_SIZE ];

	LONG	   n_input_video_resolution_offset_x_start_eia[ DEFAULT_MST3367_EIA_SIZE ];

	LONG	   n_input_video_resolution_offset_y_start_eia[ DEFAULT_MST3367_EIA_SIZE ];

	LONG	   n_input_video_resolution_offset_dirty_eia[ DEFAULT_MST3367_EIA_SIZE ];

	LONG	   n_input_video_resolution_offset_index;

	LONG	   n_input_video_resolution_offset_x_start_fetch;

	LONG	   n_input_video_resolution_offset_y_start_fetch;

	ULONG      n_input_video_colorspace;

	BOOL       b_input_video_signal_changed;

	ULONG      n_input_video_good_adc_phase;

	ULONG      n_input_audio_sampling_frequency;

	BYTE	   n_input_audio_adc_register_pages[ 4 ];

	ULONG	   n_input_mode_index;

	ULONG	   n_is_firmware_ready;

	ULONG	   n_is_firmware_just_begin;

	ULONG	   n_board_major_version;

	ULONG	   n_board_minor_version;

	ULONG	   n_firmware_major_version;

	ULONG	   n_firmware_minor_version;

	ULONG	   n_firmware_timeouts;

	BOOL	   b_is_techpoint_support;

	ULONG      m_b_is_vbi_fpga_support;

	BYTE	   n_bank_reg;

	CIT6603    o_input_ite6603;

	//CIT6612    o_input_ite6612;

	TP2834_SIGNAL_INFO	m_s_tp2834_sg_info;

	INT		   n_nvp6124_bri_def;

	INT		   n_nvp6124_con_def;

	INT		   n_nvp6124_sat_def;

	INT		   n_nvp6124_hue_def;

	BYTE       n_TvMode;
	
//daniel, add RGB SOG input 2015, 10, 7
	BYTE	  n_SOG_mode;				//1 = SEP_H_V, 2 = composite sync, 3 = SOG mode
	BYTE	  n_SOG_vsync_mode;			//0 = SEP H_V, 1 = SOG_NO_HSYNC, 2 = SOG_WITH_HSYNC, 3 = SOG_TV_MODE
	BYTE	  n_Interlace_mode;			//1 = interlace, 
	ULONG	  n_vsync_width;


	ULONG     n_output_video_resolution_fps_1_2;//for update_video_time_stamp()

} MZ0380_SYS_CFG;

#define  MZ0380_START_THREAD() { B61F92BFB9094377AA7CFF54EC29E79D( pDevice ); }
#define  MZ0380_CLOSE_THREAD() { ADD5FE824A3C48E6B58F402E38497D21( pDevice ); }

NTSTATUS B3D587196B7142738A7C4142C2E5459C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
NTSTATUS B16CE70E9F854A62A76BD6F2B7781E3E( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
NTSTATUS D443ECD5E9B94AC5B04BB7489B656CAD( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
NTSTATUS C823B90222FD455CB0C3A8BA17ADF490( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
NTSTATUS B3F2D4647EDD4CEB87D04AC6E9463337( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG status, ULONG mask, F301FA49098CE4d9eB95F22BBD388E837 * pVideos[ F03706E45925547d799BA016E4F0F6D6B ][ MAX_DEVICE_OPEN_NUM ], F170997530C6943659ECE8DEC21301F66 * pVideoBuffers[ F03706E45925547d799BA016E4F0F6D6B ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN p_FDFC345768E394d138EA574DEB55B7949s[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN F6E2E659AAB8C4494A193C313276DAA65[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ] );
NTSTATUS BC50A3FAA8804CF3AE611AFFE6606AA2( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, F170997530C6943659ECE8DEC21301F66 * pVideoBuffer );
NTSTATUS A3D659176692446A99A673EE21731E20( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG status, ULONG mask, FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudios[ F03706E45925547d799BA016E4F0F6D6B ], FFE3034C8E38D40dbAF3D2CD6E461C55C * pAudioBuffers[ F03706E45925547d799BA016E4F0F6D6B ], BOOLEAN p_FDFC345768E394d138EA574DEB55B7949s[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN F6E2E659AAB8C4494A193C313276DAA65[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ] );
NTSTATUS B7D0BE55F4E84F7A8DDDDACB6072D4D8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, F170997530C6943659ECE8DEC21301F66 * pVideoBuffer );

NTSTATUS CC7AF56407504E059A58F55D48A142C1( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BOOL THREAD );
NTSTATUS ADF0B0E919E0488A9DECD29D67A7F9A8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nStandard, BOOL THREAD );
NTSTATUS E8FFA7FBB87647EDA2877C2FAC2B2F1C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nVideoInput, ULONG nVideoOutput, ULONG nAudioInput, ULONG nAudioOutput, BOOL THREAD );

NTSTATUS MZ0380_PowerDownPeripherals( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
int B61F92BFB9094377AA7CFF54EC29E79D( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
int ADD5FE824A3C48E6B58F402E38497D21( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
int E3FC26436F414315AA1D019E5B2BF5C3( void * FD51B2B4E0CAC4359A9EFA429A9E16157 );

BOOLEAN  DBF051EEA3B648B49859145F02FA268C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE bValue );
BYTE     E6FB1249C1F642A38BC0228741149CD8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77 );
BOOLEAN	 DBF051EEA3B648B49859145F02FA268C_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE nBank, BYTE F6B106280018F45d7A077070B88512C77, BYTE nValue );
BYTE     E6FB1249C1F642A38BC0228741149CD8_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE nBank, BYTE F6B106280018F45d7A077070B88512C77 );

BOOLEAN DBF051EEA3B648B49859145F02FA268CS( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE * pValue, ULONG F02179B6B95CB43eeB160478D8CF83778 );
BOOLEAN E6FB1249C1F642A38BC0228741149CD8S( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE * pValue, ULONG F02179B6B95CB43eeB160478D8CF83778 );

BYTE	 E0F67604297A4CE5A8921272CF92A6AD( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bBitNum );
BOOLEAN  F67AC086BDA7447FB39DC135EB20D85D( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bBitNum, BYTE bDirection );
BYTE	 E6C9EBA914124FC394536744C5A0DA8C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bBitNum );
BOOLEAN	 D8735A9140EC43B888E108661E19175A( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bBitNum, BYTE bValue );
BOOLEAN  BCAF0A9A9C414EDE9F39B78A1F1FDF37( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F919EED126B2940ce99A1F7F66A333338, ULONG F0FAB4549F1C3407aACDBD483D0D23C86, ULONG F09894BF114FE4ee592C232BC39730E91 );
ULONG    A350149D4A8740248A2A95D637054F72( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F919EED126B2940ce99A1F7F66A333338, ULONG F0FAB4549F1C3407aACDBD483D0D23C86 );

BOOLEAN E7E90BC718B74429BB9234213955A126( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, DWORD config[ 12 ], ULONG length );

BOOLEAN MZ0380_SendVendorCommand( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, DWORD config[ 12 ], ULONG length, BOOL wait_semaphore );

BOOLEAN B601B66F1570418A9F5091D6133C37B8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, DWORD config[ 12 ], ULONG length, BOOL wait_semaphore, LONGLONG F6B9E557A4BA24ffd926B820B836289C8 );

BOOLEAN E6FB1249C1F642A38BC0228741149CD8S_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE nBank, BYTE F6B106280018F45d7A077070B88512C77, BYTE * pValue, ULONG F02179B6B95CB43eeB160478D8CF83778 );
BOOLEAN DBF051EEA3B648B49859145F02FA268CS_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE nBank, BYTE F6B106280018F45d7A077070B88512C77, BYTE * pValue, ULONG F02179B6B95CB43eeB160478D8CF83778 );

#endif //_MZ0380_H