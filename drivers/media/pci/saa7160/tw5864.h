#ifndef TW5864_H
#define TW5864_H

#include "LINUXV4L2.h"

BOOLEAN e03518d16ae44460b3a1694ed56877f5( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
BOOLEAN c3575033ae26421c8cee90cc36197e5c( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
BOOLEAN daab48e1fab545a880ab7abf60648829( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio );
BOOLEAN fae68fd0b91c4995ba7b2f17b5913633( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio );

BOOLEAN TW5864_PowerDownPeripherals( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );

BOOLEAN b13825e2dd0b4ba4a5c7741536f21277( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F0FAB4549F1C3407aACDBD483D0D23C86, ULONG F09894BF114FE4ee592C232BC39730E91 );
ULONG   c3c09a67df944bec9b42209724048dc4( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F0FAB4549F1C3407aACDBD483D0D23C86 );

//peter [2011.05.18]
BOOLEAN c08e773e16fb4ac7a4a5ed488cd4b12c( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F0FAB4549F1C3407aACDBD483D0D23C86, ULONG F09894BF114FE4ee592C232BC39730E91 );
ULONG	c18095576e1242d39e06f837c6599bee( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F0FAB4549F1C3407aACDBD483D0D23C86 );

BOOLEAN a17141c0224e4e82a01dd2dc46f8ba6b( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG status, ULONG mask, F301FA49098CE4d9eB95F22BBD388E837 * pVideos[ F03706E45925547d799BA016E4F0F6D6B ][ MAX_DEVICE_OPEN_NUM ], F170997530C6943659ECE8DEC21301F66 * pVideoBuffers[ F03706E45925547d799BA016E4F0F6D6B ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN p_FDFC345768E394d138EA574DEB55B7949s[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN F6E2E659AAB8C4494A193C313276DAA65[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ] );
BOOLEAN e08691f8c8594763a7fbd04765388c57( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG status, ULONG mask, FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudios[ F03706E45925547d799BA016E4F0F6D6B ], FFE3034C8E38D40dbAF3D2CD6E461C55C * pAudioBuffers[ F03706E45925547d799BA016E4F0F6D6B ], BOOLEAN p_FDFC345768E394d138EA574DEB55B7949s[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN F6E2E659AAB8C4494A193C313276DAA65[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ] );

BOOLEAN e3893c33768249bf80049109b1ca7e11( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, F170997530C6943659ECE8DEC21301F66 * pVideoBuffer );

BOOLEAN ef27344a3deb4785b7467dc69926a0f8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, F170997530C6943659ECE8DEC21301F66 * pVideoBuffer );

#define _byteswap_ulong(x) \
     (u32) ( (( ((u32)(x)) & 0xff000000 ) >> 24) | \
                    (( ((u32)(x)) & 0x00ff0000 ) >> 8 ) | \
     (( ((u32)(x)) & 0x0000ff00 ) << 8 ) | \
     (( ((u32)(x)) & 0x000000ff ) << 24) \
              )


#define VLD_MAX_CW_LEN              33
#define VLD_MAX_LONG_CW_LEN         65

#define VLD_MAX_UVLC_CODE_NUM       65535         /* 2^16-1 */


typedef struct _bitbuffer_s
{
	/* Bit buffer memory */
	unsigned char  * bufAddr;
	int bufSize;

	/* Bit buffer state */
	unsigned bytePos;
	unsigned currentBits;
	unsigned  bitpos;
} bitbuffer_s;

#define BIT_PUT_BYTE(bitbuf , byte) bitbuf->bufAddr[bitbuf->bytePos++] = (byte)
#define vlcuMapSigned(sV)   (((sV) > 0) ? (2*(sV) - 1) : (2*(-(sV))))

#define ue_v(bitbuf, codeNum)  vlcuSendUVLC(bitbuf, codeNum)
#define se_v(bitbuf, codeNum)  vlcuSendUVLC(bitbuf, vlcuMapSigned((codeNum)))
#define u_n(bitbuf, bits, len) bibPutBits(bitbuf, bits, len)

#define bibGetBit(bitbuf, bit) \
	if ((bitbuf)->bitpos <= 0) { \
	(bitbuf)->currentBits = (bitbuf)->bufAddr[(bitbuf)->bytePos++]; \
	(bitbuf)->bitpos = 7; \
	*(bit) = ((bitbuf)->currentBits >> (bitbuf)->bitpos) & 1; \
	} \
  else { \
  (bitbuf)->bitpos--; \
  *(bit) = ((bitbuf)->currentBits >> (bitbuf)->bitpos) & 1; \
  }

#define bibGetMax16bits(bitbuf, n, bits) \
	if ((n) > (bitbuf)->bitpos) { \
	(bitbuf)->currentBits = ((bitbuf)->currentBits << 8) | (bitbuf)->bufAddr[(bitbuf)->bytePos++]; \
	(bitbuf)->currentBits = ((bitbuf)->currentBits << 8) | (bitbuf)->bufAddr[(bitbuf)->bytePos++]; \
	(bitbuf)->bitpos += 16; \
	(bitbuf)->bitpos -= (n); \
	*(bits) = ((bitbuf)->currentBits >> (bitbuf)->bitpos) & ~(((unsigned)-1)<<(n)); \
	} \
  else { \
  (bitbuf)->bitpos -= (n); \
  *(bits) = ((bitbuf)->currentBits >> (bitbuf)->bitpos) & ~(((unsigned)-1)<<(n)); \
  }



void bibInit(bitbuffer_s *bitbuf , int size , unsigned char * bufAddr);
int bibPutByte(bitbuffer_s *bitbuf, unsigned char byte);
int bibPutBits(bitbuffer_s *bitbuf, unsigned bits, unsigned len);
int bibByteAlign(bitbuffer_s *bitbuf);
int bibTrailingBits(bitbuffer_s *bitbuf);

int vlcuSendUVLC(bitbuffer_s *bitbuf, unsigned int codeNum);
int vlcuSendNalUnitStartCodePrefix(bitbuffer_s *bitbuf, int zeroByte);
int vlcuSendNalHead(bitbuffer_s *bitbuf, int nal_ref_idc, int nal_type);
unsigned int vldGetUVLC(bitbuffer_s *bitbuf);

void CBR_to_VBR( F301FA49098CE4d9eB95F22BBD388E837 * pVideo, ULONG F0DD7393CD1494e27A72652C7D1A97893 );

void c6c3937b81f94efaa887c881fbb5fb63( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo );						

typedef struct _TIME_FIELDS {
    USHORT Year;        // range [1601...]
    USHORT Month;       // range [1..12]
    USHORT Day;         // range [1..31]
    USHORT Hour;        // range [0..23]
    USHORT Minute;      // range [0..59]
    USHORT Second;      // range [0..59]
    USHORT Milliseconds;// range [0..999]
    USHORT Weekday;     // range [0..6] == [Sunday..Saturday]
} TIME_FIELDS;

typedef struct _TW5864_SYS_CFG
{
//	x264_encoder_t s_video_encoder[ 16 ];

	ULONG		   n_video_encoder_reference_buffer_index[ 16 ];

	ULONG		   n_video_encoder_input_buffer_index[ 16 ];

	ULONG		   n_video_encoder_selected_channel;

	ULONG		   n_video_encoder_frame_cx[ 16 ];

	ULONG		   n_video_encoder_frame_cy[ 16 ];

	ULONG		   n_video_encoder_frame_skip_fps[ 16 ];

	ULONG		   n_video_encoder_frame_avg_fps[ 16 ];

	ULONG		   n_video_encoder_frame_fps_mask[ 16 ];

	ULONG		   n_video_encoder_frame_fps_mask_length[ 16 ];

	ULONGLONG	   n_video_encoder_frame_number[ 16 ];

	ULONG		   n_video_encoder_gop[ 16 ];

	ULONG		   n_video_encoder_gop_step[ 16 ];
//??
	ULONG		   n_picture_number_to_user[ 16 ];

	ULONG		   n_video_encoder_record_mode[ 16 ];

	UINT		   n_video_encoder_init_qp[ 16 ];

	UINT		   n_video_encoder_qp[ 16 ];

	ULONG		   n_video_encoder_bitrate[ 16 ];

	ULONG		   n_viode_encoder_cbr_frame_size_window[ 16 ][ 256 ]; // CBR.WINDOW.SIZE = 256

	ULONG		   n_viode_encoder_cbr_frame_size_window_step[ 16 ];

	ULONGLONG	   n_viode_encoder_cbr_frame_size_sum[ 16 ];

	ULONG		   n_viode_encoder_cbr_qp_base[ 16 ];

	ULONG		   n_viode_encoder_cbr_qp_base_updated_damping[ 16 ];

	BYTE		   p_video_encoder_osd_punchanged_buf[ 88 * 32 ];

	BYTE		   p_video_encoder_osd_pchanged_buf[ 88 * 32 ];

	TIME_FIELDS	   s_video_encoder_osd_timer[ 16 ];

	ULONG          n_audio_encoder_reference_buffer_index[ 8 ];

	ULONG		   R00009801;
//TW5864 encode
	ULONG		   n_preview_video_satrt;
	ULONG		   n_H264_output_enable;

} TW5864_SYS_CFG;


#endif
