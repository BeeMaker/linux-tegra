#ifndef  SA7160_H
#define  SA7160_H

#include "LINUXV4L2.h"

#include "ite6603.h"

//#define  SA7160_START_THREAD() { F5D69F1955AA4EBCAF770CF98A9B4992( pDevice ); }
//#define  SA7160_CLOSE_THREAD() { B6B487882F964675B66617C7847B8BB5( pDevice ); }

#define C_CGU_CLKS 14
typedef struct _SA7160_SYS_CFG
{
	ULONG     n_boot_clock_divider[ C_CGU_CLKS ];

	ULONG     n_current_clock_divider[ C_CGU_CLKS ];

	ULONG     n_frequency_table[ C_CGU_CLKS ];

	CSCMatrix o_csc_matrix;

	CSCMatrix o_csc_original;

	ULONG     n_min_frequency;

	ULONG     n_max_frequency;

	ULONG     n_output_audio_sampling_frequency;

	ULONG     n_input_video_resolution_cx;

	ULONG     n_input_video_resolution_cy;

	ULONG     n_input_video_resolution_fps;

	ULONG     n_input_video_resolution_fps_m;
	
	ULONG     n_input_video_resolution_interleaved;
	
	ULONG     n_input_video_resolution_vbi_F3B543EB6D1C348648C2947A125F64000;

	ULONG     n_input_video_resolution_h_total;

	ULONG     n_input_video_resolution_v_total;

	ULONG     n_input_video_resolution_hv_polarity;

	ULONG     n_input_video_resolution_color_colorimetry;

	ULONG     n_input_video_resolution_color_range;

	BOOL      b_input_video_resolution_spliter_mode;

	BOOL      b_input_video_resolution_external_sync;

	ULONG     b_input_video_resolution_vga_h_period_us;

	ULONG     b_input_video_resolution_vga_v_period_us;

	ULONGLONG b_input_video_resolution_vga_h_period_us_sum;

	ULONGLONG b_input_video_resolution_vga_v_period_us_sum;

	ULONG     b_input_video_resolution_vga_period_us_counts;

	LONG	  n_input_video_resolution_offset_x_start_vesa[ DEFAULT_MST3367_VESA_SIZE ];

	LONG	  n_input_video_resolution_offset_y_start_vesa[ DEFAULT_MST3367_VESA_SIZE ];

	LONG	  n_input_video_resolution_offset_x_start_eia[ DEFAULT_MST3367_EIA_SIZE ];

	LONG	  n_input_video_resolution_offset_y_start_eia[ DEFAULT_MST3367_EIA_SIZE ];

	LONG	  n_input_video_resolution_offset_index;

	LONG	  n_input_video_resolution_offset_x_start_fetch;

	LONG	  n_input_video_resolution_offset_y_start_fetch;

	ULONG     n_input_video_colorspace;

	BOOL      b_input_video_signal_changed;

	ULONG     n_input_video_good_adc_phase;

	ULONG     n_input_audio_sampling_frequency;

	BYTE	  n_input_audio_adc_register_pages[ 4 ];

	ULONG	  n_input_mode_index;

	CIT6603   o_input_ite6603;

	BOOL	  b_input_disable_device;

	ULONG     m_STDI_LINE_COUNT_MODE; // ADV7181

	ULONG     m_blBackup; // ADV7181

	ULONG     m_cpVideoStd; // ADV7181

	ULONG     m_filterSrc; // ADV7181


	ULONG	n_previous_audio_channel;

	ULONG	C4E7BABA3C164ABA99E460C0B8165385;

	ULONG     n_output_video_resolution_cx;

	ULONG     n_output_video_resolution_cy;

	ULONG     n_output_video_resolution_fps;

	ULONG     n_output_video_resolution_fps_m;

	ULONG     n_output_video_resolution_fps_1_2;

	ULONG	previous_x; 
	ULONG	previous_y; 
	ULONG	previous_fps;
	ULONG	updating_x;
	ULONG	updating_y;
	ULONG	updating_fps;
	ULONG	Decoder_status_counter;

//daniel, add RGB SOG input 2015, 10, 7
	BYTE	  n_SOG_mode;				//1 = SEP_H_V, 2 = composite sync, 3 = SOG mode
	BYTE	  n_SOG_vsync_mode;			//0 = SEP H_V, 1 = SOG_NO_HSYNC, 2 = SOG_WITH_HSYNC, 3 = SOG_TV_MODE
	BYTE	  n_Interlace_mode;			//1 = interlace, 
	ULONG	  n_vsync_width;

} SA7160_SYS_CFG;

BOOLEAN E9221AB6271147C39123AF9DE00B9033( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
BOOLEAN DA4990901F0C404EB66C1B0FC874B8DD( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
BOOLEAN EE7012456B844F189B414E6E9F80974A( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, SA7160_SYS_CFG * p_brother_sys_cfg, BOOL is_ite_table);
BOOLEAN EF8E67A5A31D4630AAB8CB2F9CE53E35( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, SA7160_SYS_CFG * p_brother_sys_cfg );
BOOLEAN AF6D1A686DC84B949B3B1770AC209112( F42A18AF66EFF459eA332CA253FFF8A65 *pDevice, ULONG status, ULONG mask, F301FA49098CE4d9eB95F22BBD388E837* pVideos[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ], F170997530C6943659ECE8DEC21301F66* pVideoBuffers[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN p_FDFC345768E394d138EA574DEB55B7949s[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN F6E2E659AAB8C4494A193C313276DAA65[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ] );
BOOLEAN	EBCFB2FF0E5F46BAB89C2DCB6DC14419( F42A18AF66EFF459eA332CA253FFF8A65 *pDevice, ULONG status, ULONG mask, FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudios[ F03706E45925547d799BA016E4F0F6D6B ], FFE3034C8E38D40dbAF3D2CD6E461C55C * pAudioBuffers[ F03706E45925547d799BA016E4F0F6D6B ], BOOLEAN p_FDFC345768E394d138EA574DEB55B7949s[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN F6E2E659AAB8C4494A193C313276DAA65[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ] );

//BOOLEAN AF6D1A686DC84B949B3B1770AC209112(  PKSPIN pStreamKsPin[ 32 ], PKSSTREAM_POINTER pStreamPointer[ 32 ], BYTE * pPacketDataBuffer, ULONG nPacketDataBufferSize, BYTE * pRawFrameBuffer[ 32 ], ULONG nRawFrameLength[ 32 ], LONGLONG nRawFrameNumber[ 32 ], BOOLEAN bRawFrameComplete[ 32 ], BOOLEAN bRawFrameDrop[ 32 ], PVOID pArgumentA, PVOID pArgumentB, PVOID pArgumentC );
//BOOLEAN SA7160_HwProcessAnalogRawVideoFrame( CStreamPin * pStreamPin, BYTE * pRawFrameBuffer, ULONG nRawFrameLength, ULONG nRawFrameActualLength, BYTE * pFrameBuffer, ULONG nFrameLength, LONGLONG nFrameNumber, BOOLEAN bFrameDrop, PKSSTREAM_HEADER pStreamHeader );
//BOOLEAN SA7160_HwProcessAnalogRawAudioFrame( CStreamPin * pStreamPin, BYTE * pRawFrameBuffer, ULONG nRawFrameLength, ULONG nRawFrameActualLength, BYTE * pFrameBuffer, ULONG nFrameLength, LONGLONG nFrameNumber, BOOLEAN bFrameDrop, PKSSTREAM_HEADER pStreamHeader );

BOOLEAN AE7C8644E545419889F245065E2144A7( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
BOOLEAN B49E7A6E108B44028748F460FC068D23( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
BOOLEAN A2490F6314B2455F9693604A03D8A34B( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nStandard );

BOOLEAN SA7160_PowerDownPeripherals( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
//BOOLEAN F5D69F1955AA4EBCAF770CF98A9B4992( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
//BOOLEAN B6B487882F964675B66617C7847B8BB5( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
//VOID     DD0AB4D2D5F0453B8F9DEFA51F43AC42( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );

BYTE     E4353F1BD7E74904BE78DD9F001BD652( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex );
BOOLEAN  C2B253D32391436C99E0206137A018A8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, BYTE bValue );

BYTE     E9FDD7B155AA445A84F2F4493591369B( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nBank, BYTE nIndex );
BOOLEAN  DFD7C3CC812B44E2A9BDB8C9C6C4BC84( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nBank, BYTE nIndex, BYTE bValue );

BOOLEAN  D102DB268C564A38A6914E7613DF0410( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nBus, BYTE * pIndex, ULONG nIndexLen, BYTE * pValue, ULONG nValueLen );
BOOLEAN  C1927E78C828471394AE300589EB1258( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nBus, BYTE * pIndexVlaue, ULONG nIndexVlaueLen );
BOOLEAN  A60D06861EDC409FA66867980ABA9748( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F0FAB4549F1C3407aACDBD483D0D23C86, ULONG F09894BF114FE4ee592C232BC39730E91 );
ULONG    A77C4935F8134B048348571A43F2A9CA( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F0FAB4549F1C3407aACDBD483D0D23C86 );

BYTE E31CFF96CC1A4681A81E682331CFC3F3( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex );
BOOLEAN FB416CF1CDE54D39BFB1E336A29493C2( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, BYTE nValue );

BOOLEAN EB81DC0C97B1494483D7CA0ED36B5459( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );

static int B6B487882F964675B66617C7847B8BB5( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
static int F5D69F1955AA4EBCAF770CF98A9B4992( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );

int F5D69F1955AA4EBCAF770CF98A9B4992EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );

int B6B487882F964675B66617C7847B8BB5EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );

BOOLEAN SA7160_GetADV7619Register( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nAddr, BYTE nIndex, BYTE * pValue );
BOOLEAN SA7160_SetADV7619Register( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nAddr, BYTE nIndex, BYTE bValue );

#endif
