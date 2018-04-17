#ifndef _PL330B_H
#define _PL330B_H


#include "LINUXV4L2.h"

#if defined(AME_PL330B) || defined(AME_PL330A)
#include "PL330B/common/qpmpgcodec.h"
#else
typedef void * TQP_PVOID;
typedef int TQP_INT32;
typedef TQP_INT32 *PTQP_INT32;
typedef unsigned int TQP_UINT32;
typedef TQP_UINT32 *PTQP_UINT32;
typedef enum _EQPErrors {
	QPERR_SUCCESS = 0,
	QPERR_PENDING = 1,			// requested operation pending
	QPERR_FAIL = -1,			// generic error
	QPERR_NOMEM = -2,			// insufficient memory
	QPERR_PARMS = -3,			// parameters error
	QPERR_NOTIMPL = -4,			// not implemented
	QPERR_NOTSUPP = -5,			// not supported
	QPERR_TIMEOUT = -6,			// timed out
	QPERR_INVALID = -7,			// invalid operation in the current state
	QPERR_CANCELLED = -8,		// requested operation cancelled
	QPERR_NOTFOUND = -9,		// requested entry not found
	QPERR_AGAIN = -10,			// try again
	QPERR_CTRL_VERSION = -11
} EQP_Errors;
#endif

#include "ite6603.h"

typedef struct _IppImage8u 
{
	BYTE* image;

	int step;

	int size;

	BOOLEAN enable;

	/*
	IppImage() : image(NULL), step(0), size(0), enable(false) {}

	IppImage(const IppImage & i) : image(i.image), step(i.step), enable(i.enable) {}

	IppImage(T * image, int step, BOOL enable) : image(image), step(step), enable(enable) {}

	T * ptr(int x, int y) const 
	{
		return (T *)((Ipp8u *)image + y * step) + x;
	}

	T * ptr(int x, int y, int c) const
	{
		return (T *)((Ipp8u *)image + y * step) + x * c;
	}
	
	void safeFree()
	{
		if( image )
		{
			ippiFree( image );

			image = NULL;
		}
		step = 0;

		size = 0;

		enable = false;
	}
	*/
}IppImage8u;


typedef struct _PL330B_SYS_CFG
{
	CSCMatrix  o_csc_matrix;

	CSCMatrix  o_csc_original;

	ULONG      n_output_video_resolution_cx;

	ULONG      n_output_video_resolution_cy;

	ULONG      n_output_video_resolution_fps;

	ULONG      n_output_video_resolution_fps_m;

	ULONG      n_output_video_resolution_fps_1_2;

	ULONG      n_output_video_resolution_fps_yv12;

	ULONG      n_output_video_resolution_fps_h264;

	ULONG      n_output_video_resolution_interleaved;

	ULONG      n_output_video_resolution_lock;

	ULONG      n_output_audio_sampling_frequency;
	
	IppImage8u o_output_dma_buffers[ 3 ][ 16 ];

	//IppImage8u o_output_audio_temF947DB5F969484d42AA3A243E06DB35EB;

	ULONG	   n_output_firmware_reset;

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

	BOOLEAN    b_input_video_resolution_spliter_mode;

	BOOLEAN	   b_input_video_resolution_external_sync;


	ULONG      b_input_video_resolution_vga_h_period_us;

	ULONG      b_input_video_resolution_vga_v_period_us;

	ULONGLONG  b_input_video_resolution_vga_h_period_us_sum;

	ULONGLONG  b_input_video_resolution_vga_v_period_us_sum;

	ULONG      b_input_video_resolution_vga_period_us_counts;

	LONG	   n_input_video_resolution_offset_x_start_vesa[ DEFAULT_MST3367_VESA_SIZE ];

	LONG	   n_input_video_resolution_offset_y_start_vesa[ DEFAULT_MST3367_VESA_SIZE ];

	LONG	   n_input_video_resolution_offset_x_start_eia[ DEFAULT_MST3367_EIA_SIZE ];

	LONG	   n_input_video_resolution_offset_y_start_eia[ DEFAULT_MST3367_EIA_SIZE ];

	LONG	   n_input_video_resolution_offset_index;

	LONG	   n_input_video_resolution_offset_x_start_fetch;

	LONG	   n_input_video_resolution_offset_y_start_fetch;

	ULONG      n_input_video_colorspace;

	BOOLEAN       b_input_video_signal_changed;

	ULONG      n_input_video_good_adc_phase;

	ULONG      n_input_audio_sampling_frequency;

	BYTE	   n_input_audio_adc_register_pages[ 4 ];

	ULONG	   n_input_mode_index;

	USHORT	   n_it1412_register_value;

	LONG	   n_mst3367_register_bank;

	CIT6603    o_input_ite6603;

	BOOLEAN	   m_bFastHwInitialzied;

	BOOLEAN	   m_b_is_firmware_started;

	BOOL	   m_b_is_old_mst3367_circuit;

//daniel, add RGB SOG input 2015, 10, 7
	BYTE	  n_SOG_mode;				//1 = SEP_H_V, 2 = composite sync, 3 = SOG mode
	BYTE	  n_SOG_vsync_mode;			//0 = SEP H_V, 1 = SOG_NO_HSYNC, 2 = SOG_WITH_HSYNC, 3 = SOG_TV_MODE
	BYTE	  n_Interlace_mode;			//1 = interlace, 
	ULONG	  n_vsync_width;

} PL330B_SYS_CFG;

#define  PL330B_START_THREAD() { C46ED33BB5514DE9B78DCDFF16BAC52E( pDevice ); }
#define  PL330B_CLOSE_THREAD() { E0DDF28968D942EAB74C3DD59AD1E41B( pDevice ); }

#define  PL330B_START_VIDEO_LOSS_THREAD() { PL330B_StartVideoLossThread( pDevice ); }
#define  PL330B_CLOSE_VIDEO_LOSS_THREAD() { PL330B_StopVideoLossThread( pDevice ); }

#define  PL330B_START_AUDIO_LOSS_THREAD() { PL330B_StartAudioLossThread( pDevice ); }
#define  PL330B_CLOSE_AUDIO_LOSS_THREAD() { PL330B_StopAudioLossThread( pDevice ); }

#if defined(AME_PL330B) || defined(AME_PL330A)
BOOLEAN	 AC2AF440EE544A07939115ECB1E826B8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, ULONG j, PQP_BUFFER_DESCRIPTOR pBufDesc, BYTE* pStreamPointer, IppImage8u * pCloneStreamBuffer );
#endif
// BOOL  AC2AF440EE544A07939115ECB1E826B8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, ULONG j, PQP_BUFFER_DESCRIPTOR pBufDesc, PKSSTREAM_POINTER pStreamPointer, BYTE * pCloneStreamBuffer );

BOOLEAN  B6DA6D73E4484C36B5A7CF9DFE4BBFB0( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG dwOldLockStatus, ULONG dwNewLockStatus );

NTSTATUS E9E5F4C253CB4ED4B2950234390A6409( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
NTSTATUS E8588277E602465EAFD7A57A276FEDF7( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
NTSTATUS B0D1CA46CA50499F8C9856675F0D1590( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
NTSTATUS B2FA3948CEE84C26A7E4AE5AF5AB51C0( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
NTSTATUS F1D8A4353DCB40E3AC555846B3DD656A( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );

NTSTATUS AC2EB3596394401F99E0E3A4946A9436( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BOOLEAN THREAD );
NTSTATUS D585A1C8DE8349C5A903B8F61B5E0A9F( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nStandard, BOOLEAN THREAD );
NTSTATUS E9D4315DBD2D4358B221B0E3A1963008( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nVideoInput, ULONG nVideoOutput, ULONG nAudioInput, ULONG nAudioOutput, BOOLEAN THREAD );
NTSTATUS C03EDD59F4A64C2084BB2C70FC794214( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nVolume, BOOLEAN THREAD );

NTSTATUS FBDC25F28F4A496BBEC83A29B30FB46F( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
NTSTATUS C46ED33BB5514DE9B78DCDFF16BAC52E( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
NTSTATUS E0DDF28968D942EAB74C3DD59AD1E41B( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
VOID     A7C0450F9E8E4C14975C2EC9EF06A513( void * FD51B2B4E0CAC4359A9EFA429A9E16157 );
NTSTATUS PL330B_StartVideoLossThread( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
NTSTATUS PL330B_StartAudioLossThread( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
NTSTATUS PL330B_StopVideoLossThread( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
NTSTATUS PL330B_StopAudioLossThread( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
VOID     PL330B_OnVideoLossThread( void * FD51B2B4E0CAC4359A9EFA429A9E16157 );
VOID     PL330B_OnAudioLossThread( void * FD51B2B4E0CAC4359A9EFA429A9E16157 );

BOOLEAN  E057E022AA684160B92E903D99235927( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE bValue );
BYTE     DD0D84BB34264335874009D864B98B9C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77 );
BOOLEAN	 F3442C8F4E5244B4852C27C401ED415E( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE nBank, BYTE F6B106280018F45d7A077070B88512C77, BYTE nValue );
BYTE     C6F39DAE1CE54F0D873113FD657C7FA3( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE nBank, BYTE F6B106280018F45d7A077070B88512C77 );
BYTE     F7B4503FC4AA4710AEC20FC4C587ACB8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77 );
BOOLEAN	 FC5FCF2C4E50436EA8A2A8C98E4C1AC2( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE bValue );
BOOLEAN  B7348427B3AB4369914C8A1ED8C306B5( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, DWORD F09894BF114FE4ee592C232BC39730E91 );
DWORD    F9EAF79B03A148CA8238A894135B8327( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77 );

USHORT C12B7BD9B5134F53981EE3E7702A7E44( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, USHORT wIndex );

USHORT   C00DF1D7428943A5A947C729729E597F( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, USHORT wIndex, BOOLEAN * p_returns );
BOOLEAN  F163E0DBD4F44FD18730544917C904D1( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, USHORT wIndex, USHORT wValue );

BYTE	 PL330B_GetGpioValue( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bBitNum );
BOOLEAN	 CBFDDC6395144862ACEDAD3C092FC9A6( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bBitNum, BYTE bValue );
BOOLEAN  PL330B_SetRegister( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F919EED126B2940ce99A1F7F66A333338, ULONG F0FAB4549F1C3407aACDBD483D0D23C86, ULONG F09894BF114FE4ee592C232BC39730E91, ULONG F02179B6B95CB43eeB160478D8CF83778 );
ULONG    PL330B_GetRegister( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F919EED126B2940ce99A1F7F66A333338, ULONG F0FAB4549F1C3407aACDBD483D0D23C86, ULONG F02179B6B95CB43eeB160478D8CF83778 );

int C46ED33BB5514DE9B78DCDFF16BAC52EEX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
int E0DDF28968D942EAB74C3DD59AD1E41BEX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
#endif // _PL330B_H
