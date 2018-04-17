#ifndef LINUXV4L2_H
#define LINUXV4L2_H

#include <linux/version.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pci.h>
#include <linux/usb.h>
#include <linux/interrupt.h>
#include <linux/vmalloc.h>
#include <linux/delay.h>
#include <linux/kthread.h>
#include <linux/firmware.h>

#include <media/videobuf-core.h>

//#include <asm-generic/rtc.h>
//#include <asm/rtc.h>

//#include "ippcore.h"
//#include "ippi.h"
//#include "ipp.h"

#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,11,0)
#include <media/v4l2-device.h>
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)
#include <media/v4l2-common.h>
#include <media/v4l2-ioctl.h>
#include <media/videobuf-vmalloc.h>
#include <media/videobuf-dma-sg.h>
#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)
#include <media/v4l2-common.h>
#include <media/videobuf-vmalloc.h>
#include <media/videobuf-dma-sg.h>
#else
#include <media/v4l2-common.h>
#include <media/video-buf.h>
#include <linux/highmem.h>
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)
#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/control.h>
#include <sound/initval.h>
#else
#include <sound/driver.h>
#include <sound/core.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/control.h>
#include <sound/initval.h>
#endif

#if LINUX_VERSION_CODE >=  KERNEL_VERSION(3,1,0)

typedef u64 DMA_nnBIT_MASK __deprecated;

#define DMA_32BIT_MASK  (DMA_nnBIT_MASK)DMA_BIT_MASK(32)

#endif

#if LINUX_VERSION_CODE <  KERNEL_VERSION(2,6,21)

struct v4l2_encoder_cmd { __u32 cmd; __u32 flags; union { struct { __u32 data[ 8 ]; } raw; }; };

#endif

#if LINUX_VERSION_CODE <  KERNEL_VERSION(2,6,22)

#define list_first_entry( ptr, type, member ) list_entry( (ptr)->next, type, member )

#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

enum v4l2_bitrate_mode { V4L2_BITRATE_NONE = 0, V4L2_BITRATE_CBR, V4L2_BITRATE_VBR };

struct v4l2_mpeg_compression { __u32 _unsupport_struct; };

#endif

#if LINUX_VERSION_CODE <  KERNEL_VERSION(2,6,26)

#define V4L2_CID_SHARPNESS (V4L2_CID_BASE + 27)

#endif

#if LINUX_VERSION_CODE >=  KERNEL_VERSION(3,6,0)

#pragma message("3,6,0")
//no this member 
#define input privsize

#endif

#if LINUX_VERSION_CODE <= KERNEL_VERSION(3,1,0)
#define V4L2_CID_MPEG_VIDEO_H264_PROFILE                (V4L2_CID_MPEG_BASE+363)
enum v4l2_mpeg_video_h264_profile {
        V4L2_MPEG_VIDEO_H264_PROFILE_BASELINE                   = 0,
        V4L2_MPEG_VIDEO_H264_PROFILE_CONSTRAINED_BASELINE       = 1,
        V4L2_MPEG_VIDEO_H264_PROFILE_MAIN                       = 2,
        V4L2_MPEG_VIDEO_H264_PROFILE_EXTENDED                   = 3,
        V4L2_MPEG_VIDEO_H264_PROFILE_HIGH                       = 4,
        V4L2_MPEG_VIDEO_H264_PROFILE_HIGH_10                    = 5,
        V4L2_MPEG_VIDEO_H264_PROFILE_HIGH_422                   = 6,
        V4L2_MPEG_VIDEO_H264_PROFILE_HIGH_444_PREDICTIVE        = 7,
        V4L2_MPEG_VIDEO_H264_PROFILE_HIGH_10_INTRA              = 8,
        V4L2_MPEG_VIDEO_H264_PROFILE_HIGH_422_INTRA             = 9,
        V4L2_MPEG_VIDEO_H264_PROFILE_HIGH_444_INTRA             = 10,
        V4L2_MPEG_VIDEO_H264_PROFILE_CAVLC_444_INTRA            = 11,
        V4L2_MPEG_VIDEO_H264_PROFILE_SCALABLE_BASELINE          = 12,
        V4L2_MPEG_VIDEO_H264_PROFILE_SCALABLE_HIGH              = 13,
        V4L2_MPEG_VIDEO_H264_PROFILE_SCALABLE_HIGH_INTRA        = 14,
        V4L2_MPEG_VIDEO_H264_PROFILE_STEREO_HIGH                = 15,
        V4L2_MPEG_VIDEO_H264_PROFILE_MULTIVIEW_HIGH             = 16,
};

#define V4L2_CID_MPEG_VIDEO_H264_LEVEL                  (V4L2_CID_MPEG_BASE+359)
enum v4l2_mpeg_video_h264_level {
        V4L2_MPEG_VIDEO_H264_LEVEL_1_0  = 0,
        V4L2_MPEG_VIDEO_H264_LEVEL_1B   = 1,
        V4L2_MPEG_VIDEO_H264_LEVEL_1_1  = 2,
        V4L2_MPEG_VIDEO_H264_LEVEL_1_2  = 3,
        V4L2_MPEG_VIDEO_H264_LEVEL_1_3  = 4,
        V4L2_MPEG_VIDEO_H264_LEVEL_2_0  = 5,
        V4L2_MPEG_VIDEO_H264_LEVEL_2_1  = 6,
        V4L2_MPEG_VIDEO_H264_LEVEL_2_2  = 7,
        V4L2_MPEG_VIDEO_H264_LEVEL_3_0  = 8,
        V4L2_MPEG_VIDEO_H264_LEVEL_3_1  = 9,
        V4L2_MPEG_VIDEO_H264_LEVEL_3_2  = 10,
        V4L2_MPEG_VIDEO_H264_LEVEL_4_0  = 11,
        V4L2_MPEG_VIDEO_H264_LEVEL_4_1  = 12,
        V4L2_MPEG_VIDEO_H264_LEVEL_4_2  = 13,
        V4L2_MPEG_VIDEO_H264_LEVEL_5_0  = 14,
        V4L2_MPEG_VIDEO_H264_LEVEL_5_1  = 15,
};
#endif

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,24)
enum videobuf_state2 {
         VIDEOBUF_NEEDS_INIT = 0,
         VIDEOBUF_PREPARED   = 1,
         VIDEOBUF_QUEUED     = 2,
         VIDEOBUF_ACTIVE     = 3,
         VIDEOBUF_DONE       = 4,
         VIDEOBUF_ERROR      = 5,
         VIDEOBUF_IDLE       = 6,
};
#endif


typedef          char           CHAR;//    1     1
typedef          short         SHORT;//    2     2
typedef			 int			 INT;//	   4     4

typedef          int            LONG;//    4     8
typedef unsigned int           ULONG;//    4     8

typedef     long long       LONGLONG;//    8     8
typedef unsigned char          UCHAR;//    1     1
typedef unsigned short        USHORT;//    2     2
typedef unsigned int		    UINT;//    4     4
typedef unsigned long long ULONGLONG;//    8     8
typedef unsigned char           BYTE;//    1     1
typedef unsigned short          WORD;//    2     2
typedef unsigned int           DWORD;//    4     4
typedef unsigned char        BOOLEAN;//    1     1
typedef void                    VOID;
typedef void *                 PVOID;//    4     8

//#define APLUS 1

//#define Excelement 1

#define ENABLE_1920X1080PX60FPS 1

#define MEDICAL 1

//#define FFMPEG 1

//#define FFMPEG_TW5864 1

//#define FFMPEG_V1_1_5 1

#define DMA_ERROR_1080i 1

#define CX2581_64bit 1

#define TW6805_64bit 1

#define SC3A0_STEREO 1

//#define HDMI_MIXER 1

//#define FH8735_DEBUG_TIMESTAMP 1

//#define AUDIO_STAND_ALONE 1

//#define RAYAN 1 //invert U V

//#define NEVRON 1 //only H264

//#define CUEBI_WEBRTC 1 //output YUY2 for PL330B, convert 48k audio to 44.1k

#if defined(AME_PL330B) && defined(PL330B_MIX_FH8735)
	#define pl330_init_node_number 20
#else
	#define pl330_init_node_number 0
#endif

#define V4L2_IN_CAP_PRESETS             0x00000001 /* Supports S_DV_PRESET */
#define V4L2_IN_CAP_CUSTOM_TIMINGS      0x00000002 /* Supports S_DV_TIMINGS */
#define V4L2_IN_CAP_STD                 0x00000004 

//#define LINUXV4L2_DEFAULT_VIDEO_STANDARD	V4L2_STD_NTSC_M //
#define LINUXV4L2_DEFAULT_VIDEO_STANDARD	V4L2_STD_PAL_B

#define F1838C0176E054c129B7F2BF440D1236E( level, msg... )	printk( level "[LINUXV4L2] : " msg )

#define F966EAAB748564259849CBD3F3D6C48A7( level, msg... )	printk( level "[LINUXV4L2] : " msg )

//#define F966EAAB748564259849CBD3F3D6C48A7( level, msg... )

#define LINUXV4L2_VMALLOC_MODULE

#define MIN(x,y) (x<y)?(x):(y)

#define FREE( p ) { if( p ) { kfree( p ); p = NULL; } }

#define FALSE 0

#define TRUE 1

#define F03706E45925547d799BA016E4F0F6D6B 32

#define F91863BEB45D34624A724F2D29823D9E3     16

#define F933F2ACDBCE3443093DDB4DCB3597BDE      32

#define F67472E4DF55F4f65AAB4E0860EFF1AD5      6

#define MAX_DEVICE_OPEN_NUM		4

#define F4E4758ED106F4fbcBC46709DCC7A3FEB                       (V4L2_CID_BASE + 200) //

#define F0A6769CE1DE64a25A308D9585D0949DE                       (V4L2_CID_BASE + 201)

#define V4L2_CID_HDCP_ENABLE                        (V4L2_CID_BASE + 202)

#define V4L2_CID_HDCP_STATUS                        (V4L2_CID_BASE + 203)

#define V4L2_CID_HV_SCALE_FACTOR                    (V4L2_CID_BASE + 204)

#define V4L2_CID_H264_HV_SCALE_FACTOR               (V4L2_CID_BASE + 205)

#define V4L2_CID_WATCH_DOG_PERIOD                   (V4L2_CID_BASE + 206)

#define V4L2_CID_WATCH_DOG		                    (V4L2_CID_BASE + 207)

#define V4L2_CID_WATCH_DOG_ENABLE                   (V4L2_CID_BASE + 212)

#define V4L2_CID_NO_SIGNAL_BLACK_PATTERN            (V4L2_CID_BASE + 213)

#define V4L2_CID_SPECIAL_CAMERA			            (V4L2_CID_BASE + 214)

#define V4L2_CID_NO_SIGNAL_NO_OUTPUT	            (V4L2_CID_BASE + 215)

#define V4L2_CID_NO_SIGNAL_YUV_PATTERN				(V4L2_CID_BASE + 216)

#define V4L2_CID_FRAME_RATE		                    (V4L2_CID_BASE + 208)

#define V4L2_CID_AUDIO_SAMPLING_FREQ                (V4L2_CID_BASE + 211) 

#define F82EB10A02CBD4cc081D849D39629049B						(V4L2_CID_BASE + 250) //

#define F23AEF06C35E84e268F8348DE745D6E9D	(V4L2_CID_BASE + 251)

#define F00654B9494C14259AB67D0B82BB2B4F4	(V4L2_CID_BASE + 252)

#define FA15402C642F34d2cAC2720CC357D2D38						(V4L2_CID_BASE + 253)

#define FB399C846A91D403eA55BF95B2B5BAA5C						(V4L2_CID_BASE + 254)

#define FFD08F80E390E49fcB67A2308CB62684C							(V4L2_CID_BASE + 260) //

#define FABAFB2ADBCD8465eA4F4B681511D1E3E							(V4L2_CID_BASE + 261)

#define F0B76EDE3B1154d53872CEEDCE52A97DC							(V4L2_CID_BASE + 262)

#define F755BEAF2318846358DA840FAC6E9E8F7							(V4L2_CID_BASE + 263)

#define V4L2_CID_GPIO_DIRECTION						(V4L2_CID_BASE + 270) // CUSTOM GPIO IOCTL

#define V4L2_CID_GPIO_DATA							(V4L2_CID_BASE + 271)

#define V4L2_CID_PCM_UPDATE							(V4L2_CID_BASE + 272)

#define V4L2_CID_TW5864_MOTION_STATUS_00			(V4L2_CID_BASE + 280) 
#define V4L2_CID_TW5864_MOTION_STATUS_01			(V4L2_CID_BASE + 281) 
#define V4L2_CID_TW5864_MOTION_STATUS_02			(V4L2_CID_BASE + 282) 
#define V4L2_CID_TW5864_MOTION_STATUS_03			(V4L2_CID_BASE + 283) 
#define V4L2_CID_TW5864_MOTION_STATUS_04			(V4L2_CID_BASE + 284) 
#define V4L2_CID_TW5864_MOTION_STATUS_05			(V4L2_CID_BASE + 285) 
#define V4L2_CID_TW5864_MOTION_STATUS_06			(V4L2_CID_BASE + 286) 
#define V4L2_CID_TW5864_MOTION_STATUS_07			(V4L2_CID_BASE + 287) 

#define V4L2_CID_TW5864_MOTION_TEMPORAL_SENSITIVITY	(V4L2_CID_BASE + 290) 
#define V4L2_CID_TW5864_MOTION_SPATIAL_SENSITIVITY	(V4L2_CID_BASE + 291) 
#define V4L2_CID_TW5864_MOTION_LEVEL_SENSITIVITY	(V4L2_CID_BASE + 292) 
#define V4L2_CID_TW5864_MOTION_SPEED				(V4L2_CID_BASE + 293) 

#define V4L2_CID_X_RES_DETECTED						(V4L2_CID_BASE + 294) 
#define V4L2_CID_Y_RES_DETECTED						(V4L2_CID_BASE + 295) 
#define V4L2_CID_FPS_DETECTED						(V4L2_CID_BASE + 296) 

#define V4L2_CID_INTERLEAVE_DETECTED				(V4L2_CID_BASE + 297) 
#define V4L2_CID_ENC_DEINTERLACE					(V4L2_CID_BASE + 298) 

#define V4L2_CID_RESET_I2S							(V4L2_CID_BASE + 299) 

#define V4L2_CID_VBI_ENABLE							(V4L2_CID_BASE + 300) 

#define V4L2_CID_VBI_LINE							(V4L2_CID_BASE + 301) 

#define V4L2_CID_HDMI_MIXER							(V4L2_CID_BASE + 302) 

#define V4L2_CID_HANC_TIMECODE_H_M					(V4L2_CID_BASE + 303) 
#define V4L2_CID_HANC_TIMECODE_S_F					(V4L2_CID_BASE + 304) 


#define V4L2_CID_SET_I2C_CHIPADDR					(V4L2_CID_BASE + 309) 

#define V4L2_CID_SET_I2C_REGISTER					(V4L2_CID_BASE + 305) 

#define V4L2_CID_ACCESS_I2C_REGISTER				(V4L2_CID_BASE + 306) 

#define V4L2_CID_SIZE_NOT_MATCH						(V4L2_CID_BASE + 307) 

#define V4L2_CID_INVERT_UV							(V4L2_CID_BASE + 308)


#define F50EB0715BAAC4d35AA3EE21A2F673819					(V4L2_CID_MPEG_BASE + 250) //

#define F59D7E164EA0643c987147244BD095662				(V4L2_CID_MPEG_BASE + 251)

#define FE8CF9C6EC12A48c79FEBD36B2EAD2642					(V4L2_CID_MPEG_BASE + 252)
//shawn 2010.09.08
#define V4L2_CID_MPEG_VIDEO_OSD						(V4L2_CID_MPEG_BASE + 253)

#define V4L2_CID_MPEG_VIDEO_OSD_LINE				(V4L2_CID_MPEG_BASE + 254)

#define V4L2_CID_MPEG_VIDEO_OSD_ENABLE				(V4L2_CID_MPEG_BASE + 256)

#define V4L2_CID_MPEG_SET_KEY_FRAME					(V4L2_CID_MPEG_BASE + 255)

#define V4L2_CID_MPEG_SET_SLICE						(V4L2_CID_MPEG_BASE + 257)

#define F6B9E557A4BA24ffd926B820B836289C8_to_PLAY								60 //min 50

#if defined(AME_PL330B) || defined(AME_PL330A)
#include "PL330B/common/qpdbgmgr.h"
#include "PL330B/common/qpmgrspriv.h"
#include "PL330B/common/qpdevcntl.h"
#include "PL330B/common/qpdevdiag.h"
#include "PL330B/common/qpcodeclib.h"
#include "PL330B/common/qpmpgcodec.h"

typedef union _PLV4LDEV_PARENT_DEV
{
#ifndef __LINUX24__
	struct usb_interface	*p_usbintf;
#else //__LINUX24__
	struct usb_device		*p_usbdev;
#endif //__LINUX24__
	struct pci_dev			*p_pciedev;
	struct device			*p_dev;
	void					*read;

} PLV4LDEV_PARENT_DEV, *PPLV4LDEV_PARENT_DEV;
#endif

typedef struct _GENNUM_INFO_
{
	WORD m_FRAMES;
	WORD m_SECONDS;
	WORD m_MINUTES;
	WORD m_HOURS;

} _GENNUM_INFO;

typedef union _CSCMatrix
{
    struct
	{
	    BYTE data[ 24 ];

	} b;

	struct
	{
		USHORT CSC_M11, CSC_M12, CSC_M13, CSC_M21, CSC_M22, CSC_M23, CSC_M31, CSC_M32, CSC_M33;

		USHORT CSC_A1, CSC_A2, CSC_A3;

	} w;

} CSCMatrix;

typedef struct _H264_STREAM_HEADER
{
	DWORD nFrameBufferSize : 24; // FRAME BUFFER SIZE (H.264 BITSTREAM LENGTH) = 0x00000000 ~ 0x00FFFFFFFF

	DWORD nFrameType       :  1; // 0 = I FRAME / 1 = P FRAME

	DWORD nMotionStatus    :  1; // 0 = STATIC / 1 = MOTION

	DWORD nLockStatus      :  1; // 0 = UNLOCK / 1 = LOCK

	DWORD nReserved        :  5;
		
} H264_STREAM_HEADER;

typedef struct Interrupt_Container {

	BYTE interrupt_arrived;

	struct timeval ts;

} Interrupt_Container;

typedef struct F170997530C6943659ECE8DEC21301F66 {

	struct videobuf_buffer  F6A821C5E7AA043f999FB3C51DB94DD2B;

} F170997530C6943659ECE8DEC21301F66;

typedef struct FFE3034C8E38D40dbAF3D2CD6E461C55C {

	struct snd_dma_buffer * F8D610AAF366C41f6B931686A6238A390;

} FFE3034C8E38D40dbAF3D2CD6E461C55C;

typedef struct F301FA49098CE4d9eB95F22BBD388E837 {

	struct F42A18AF66EFF459eA332CA253FFF8A65 *        FB6E79A0780E64bb28A3308666E67881C;
	ULONG                   F0DD7393CD1494e27A72652C7D1A97893;
	ULONG                   F03DD48A54B1D4ffeB64170AA03AEFC6E;

	ULONG                   F18B6587C912F463c932DEE9FF8B93AAE;
	ULONG                   FECCF92CAC5DC4194925ADBF80EFC3B63;
	ULONG                   F5BB6BD5E849C46bfAD76032D5E2E47B9;
	ULONG                   FA7E81415668A414bB9DED82DB85E4B48;
	ULONGLONG               F3390EC7F04704cc1A843000DB76617C3;
	ULONG					FE9AF51EBD0D4401eA4E5E0F6868A9A53;
	ULONG					FD49577B6E6624669BFA3A840079514E8;
	ULONG					F3F00596420D64210BB4DDAF0945F5388;
	BYTE					F59B6B40F8D70445eB5D4ACA63BE8A26E[ 12 ];

	ULONG                   F3FCE6081A67349839E69BEDE056CFEED; //
	ULONG                   F2039B582640548a6B3F55D13092DCF5F;
	ULONG                   F10CC5793AEB4486dA7AFE99A1176E51D;
	ULONG                   F9D5A3DD27B7F43ea83AF4273BB7AE003;
	ULONG                   FD1832F8D382F4e91914C0048CC5A9DD8; //
	ULONG                   F5B8891B732954fc2B26B7BFFCB15B596;
	ULONG                   F71FE13C55F1948828A7FA0A0A5800543;
	ULONG                   FFA9FA378762B440d9F8489DE5A6432B3;
	ULONG                   F07563F8419D74e1cB3F1A4F962EBACE8;
	ULONG                   FA8153D6A19C2451d94BB0F52E68471F1; //
	ULONG                   FEDE037FA62F943829C230928859309D9;
	ULONG                   FB4E9A11D151C4d93B0C750EC1BE4C7C5;
	ULONG                   F6578ACFCB40E44819A12FD3E27A48085;
	UINT                    F8C5A9629DDA74022A5888D194EA3D926;

	ULONG					F3D935AFB5C164dac97F5A7CA0150BC60; //
	ULONG					F65C8BF3BAA2D4fbb876EE33F491F1931;
	ULONG					FF63087B4098B4de18859989009950824;
	ULONG					F1CA927B5918D436c9F5839C9727D620E;
	ULONG					FD9E5DCB7C0F94c32AF5A086BA8C007EC;
	
    spinlock_t              F4ECA473514304aecA7885A0D80438003; //
	struct videobuf_queue   FFDA6DA912A8649aeB0BC30D3D43DCD7A;
	spinlock_t              FE0A97B802F3C400aBD7CD5D313825C31; //
	struct list_head        F0EA6D27495A14af1A9607DE7C222A3B1;
	struct list_head        FDA1F8237E2D04e5a8737CF587701D54D;
//peter [2011.05.09]
	struct completion       F55A66E1F15B447008EB0B5BC1827F424;

	struct task_struct *    FB5D90351C9FF410eBE4CB7D22E016687; //

	ULONG					m_video_preview_frame_number;//for custom fps
	
	ULONG	   				n_main_H264_count;//number of bytes in AP buffer
	ULONG	   				n_main_H264_left;//number of bytes in temp buffer

	ULONG	   				n_sub_H264_count;//number of bytes in AP buffer
	ULONG	   				n_sub_H264_left;//number of bytes in temp buffer

	LONGLONG			m_nLastReferenceClockTime;
	LONGLONG			m_nLastPresentationTime;
//peter add
	LONGLONG			m_nNowPresentationTime;

	LONG			   m_nLastPresentationTimeMultipler;
	LONGLONG		   m_nLastPresentationTimeFps;
	LONGLONG		   m_nLastPresentationTimeFpsCounts;
	LONGLONG		   m_nLastPresentationTimeFpsErrors;
	ULONG				m_nCustomEncoderSlice;//add yuan h264 headers or not
	ULONG				m_nCustomEncoderKeyFrameArrived;//skip P frame until I frame arrived

	ULONG				m_nCustomSubEncoderKeyFrameArrived;

} F301FA49098CE4d9eB95F22BBD388E837;

typedef struct FE8EB18A4C9984f9789EFF7C05EE073A0 {

	struct F42A18AF66EFF459eA332CA253FFF8A65 *           FB6E79A0780E64bb28A3308666E67881C;
	ULONG                      F0DD7393CD1494e27A72652C7D1A97893;
	ULONG                      F03DD48A54B1D4ffeB64170AA03AEFC6E;
	ULONG                      FECCF92CAC5DC4194925ADBF80EFC3B63;
	ULONG                      FD7636E89EEE544eb849076B30F06638F;
	ULONG                      FF322C2E8BB6F4f4799871C1E57B639DA;
	ULONG                      F7C7B28D613E845b48C2F9701EFF42227;
	ULONG                      F4C4107B7DECC41588971B29ACD439A43;
	ULONG                      F1461B75D9C644717A130B5C10D966CF0;
	ULONG                      F6578ACFCB40E44819A12FD3E27A48085[ MAX_DEVICE_OPEN_NUM ];
	ULONG                      m_nFrameDMANumber[ MAX_DEVICE_OPEN_NUM ];//counter of DMA
	ULONG                      FD9C8A1F986EF488a8883B3CAD736747F;
	struct snd_pcm_substream * F823E5E1F924443f8AD2BC9CBED4CE613[ MAX_DEVICE_OPEN_NUM ];

	BYTE						m_audio_temp[ 3764 ]; //temp buffer to convert 48k to 44.1k
	BYTE						m_audio_residue_buffer[ MAX_DEVICE_OPEN_NUM ][ 3764 * 2 ]; // buffer to store audio data
	ULONG						m_audio_data_residue[ MAX_DEVICE_OPEN_NUM ]; // counter of audio data in m_audio_residue_buffer
} FE8EB18A4C9984f9789EFF7C05EE073A0;

//do not shorten than 3, since DMA is i = i + 1, (prepare for next)
#define SA7160_MAX_BUFFER 3

#define TW6816_MAX_BUFFER 2

#define CX2581_MAX_BUFFER 2

typedef struct F42A18AF66EFF459eA332CA253FFF8A65 {

	#ifndef AME_PL330A
	struct pci_dev *       F9D9594A095F0463193B7588374CF8310;
	#else
	struct usb_device*		F9D9594A095F0463193B7588374CF8310;
	#endif

	ULONG                  F0C7DF8CDF1004a6eB97071CBDF459ECE;
	ULONG                  FF362AA37F7D046bf90568AC1600626D9;
	ULONG                  F303D369E48FE4a678735A832DB68BC28;
	ULONG                  F987A77560CED4a97977C18B30809471E;
	ULONG                  FA7C48797875D4d1483E4288C80A1B266;
	ULONG                  F85D95817054C4a10BA000A8CC5704576;
	struct video_device *  FF0CEC78D40C5466a849834697C6AE8A8                              [ F91863BEB45D34624A724F2D29823D9E3 ];
	struct snd_card *      F1784891F2DFB4dd0896C54A4C0D96463                          [ F91863BEB45D34624A724F2D29823D9E3 ];
	struct snd_pcm  *      FCB465449C23D4d298E73233A42203CD6                           [ F91863BEB45D34624A724F2D29823D9E3 ];
	F301FA49098CE4d9eB95F22BBD388E837 *               m_pVideo                                [ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ];
	FE8EB18A4C9984f9789EFF7C05EE073A0 *               FF6347EA309EF49519F7F07D0B6B28662                                [ F91863BEB45D34624A724F2D29823D9E3 ];
	ULONG			       FA12AAA3D283C4cf0BF02ACD3957899B0                     [ F91863BEB45D34624A724F2D29823D9E3 ];//use bit 0 to represent first open status, bit 1 2nd, ...
	ULONG				   F13A906F1479D4245B9F207A09C70BCE6                     [ F91863BEB45D34624A724F2D29823D9E3 ];//use bit 0 to represent substream0, bit 1 substream1...
	struct video_device *  F590A429DF6D145f288A92DDF1547AC46                       [ F91863BEB45D34624A724F2D29823D9E3 ];
	struct snd_card *      FB1A1EF5BAA2243f4833747083423997C                   [ F91863BEB45D34624A724F2D29823D9E3 ];
	struct snd_pcm  *      FF5F61842BBC24b458D103EF08357C4CD                    [ F91863BEB45D34624A724F2D29823D9E3 ];
	F301FA49098CE4d9eB95F22BBD388E837 *               F7E9FB3BB25C34ddd9C2E2E73E181A1F8                         [ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ];
	FE8EB18A4C9984f9789EFF7C05EE073A0 *               FCD654CA89AC34227BE068F80A85776C6                         [ F91863BEB45D34624A724F2D29823D9E3 ];
	ULONG				   FDB274CD437614fec94859748411FE56A              [ F91863BEB45D34624A724F2D29823D9E3 ];
	ULONG				   FC1FFB6B00E034c0993BE8A598C730AA4              [ F91863BEB45D34624A724F2D29823D9E3 ];
	dma_addr_t             FA81F93DB0A8D49bdBC3753334A5D581D          [ F933F2ACDBCE3443093DDB4DCB3597BDE ]; // // shawn 2010.11.09
	BYTE *                 F41F19BDAA144449fA254B8E3282D1425                  [ F933F2ACDBCE3443093DDB4DCB3597BDE ]; //
	ULONG                  FF3B74CCEF832433c856908721A61A034              [ F933F2ACDBCE3443093DDB4DCB3597BDE ]; //
	ULONG                  F03D1DD650AC64c28B04687338F970D0E            [ F933F2ACDBCE3443093DDB4DCB3597BDE ]; //
	ULONG                  F66FD293166B14f93A084AE0E6BD0F196[ F933F2ACDBCE3443093DDB4DCB3597BDE ]; //
	BYTE __iomem *         F760673FD1F8F4f22914515A9DC68C7C9                  [ F67472E4DF55F4f65AAB4E0860EFF1AD5 ]; //
	ULONG                  F57270173C138422aA83C0FF58A259F4D              [ F67472E4DF55F4f65AAB4E0860EFF1AD5 ]; //
	ULONG			       m_pRegBaseCommonPhysicalBuffer          [ F67472E4DF55F4f65AAB4E0860EFF1AD5 ]; // REG BASE BUFFER (PHYSICAL ADDRESS)

	struct tasklet_struct  FB12FC3D237104676BD149F25E3D08571;
	ULONGLONG              F69679D3D75724cd281AAC93AE8DFDF35;
	ULONGLONG              F9D066B94377B4a9aB14E37D504955651;
	spinlock_t             FFCB115F553804bc7A991C2C6B50FDDFC;
	volatile BOOLEAN	   F5C8C1DAFA2D74241A96FE41ED93197F8;
	struct semaphore	   FB35780EBCC0F4f1c869121F03566FA3B;
	ULONG		           m_nDummy0[8];//for semaphore access????? do not remove

	ULONG                  FF049D1BE4BF24dd794D611B48835D184;
	volatile ULONG         FC3FEC90DD3E6414c83437752D6A0B4B2;
	ULONG                  F4C79718693FD4bd39C552E932C7E4FB5; 
	ULONG                  FD314ADAD9404496b842EBFC396E875CB;
	ULONG                  F64E8BDD78F2944b8B21DE5BF5CF2A021;

	ULONG		           m_nCustomAnalogAudioSampleFrequencyProperty;

	ULONG					m_nCustomGpioDirectionProperty;
	ULONG					m_nCustomGpioDataProperty;
	ULONG					m_nCustomGpioSupportProperty;

	ULONG				   m_nCustomSoftwareWatchdogDurationProperty;	// shawn 2010.08.11
	struct task_struct *   m_pControlThread;							// shawn 2010.08.11
	struct task_struct *   m_pVideoLossThread;							// shawn 2010.08.11
	struct task_struct *   FF6347EA309EF49519F7F07D0B6B28662LossThread;							// shawn 2010.08.11

	ULONG				   m_ReadyToStopControlThread;	// shawn 2010.08.11
	ULONG				   m_ReadyToStopVideoLossThread;	// shawn 2010.08.11
	ULONG				   m_ReadyToStopAudioLossThread;

	ULONG				   m_nCustomAnalogVideoScaleOutputProperty;		// shawn 2010.10.04
	PVOID				   m_pCustomSystemConfigProperty;				// shawn 2010.11.04
	ULONG				   m_nAnalogCopyProtMacrovisionProperty;		// shawn 2010.10.19
	ULONG				   m_nAnalogVideoDecoderStatusProperty;			// shawn 2010.10.19
	ULONG				   m_nAnalogCrossbarVideoInputProperty;						// shawn 2010.10.25
	ULONG				   m_nAnalogCrossbarAudioInputProperty;

	ULONG				   m_nAnalogCrossbarVideoOutputProperty;
	ULONG				   m_nAnalogCrossbarAudioOutputProperty;

	ULONG				   m_nCustomAnalogVideoResolutionProperty;		// shawn 2010.11.04
	ULONG				   m_nCustomAnalogVideoFrameRateProperty;		// shawn 2010.11.04
	ULONG				   m_nCustomAnalogVideoInterleavedProperty;
//peter [2011.05.09]
	//struct semaphore       m_sComponentAccessSemaphore;					// shawn 2010.07.26
	//ULONG		           m_nDummy1[8];//for semaphore access????? do not remove

	struct mutex       m_sSGSemaphore;					// shawn 2010.07.26

	ULONG		           m_nDummy3[8];//for semaphore access????? do not remove

//peter
	ULONG		          m_nCustomEncoderVideoResolutionProperty[ 32 ];//pay attention to this, it might be changed by above semaphore
	ULONG		          m_nAnalogVideoCompressionKeyframeRateProperty[ 32 ];
	ULONG		          m_nCustomEncoderVideoBitRateModeProperty[ 32 ];
	ULONG		          m_nCustomEncoderVideoBitRateProperty[ 32 ];
	ULONG		          m_nAnalogVideoCompressionQualityProperty[ 32 ];
	ULONG		          m_nAnalogVideoCompressionOverrideKeyframeProperty[ 32 ];
	ULONG		          m_nCustomEncoderVideoBframesPerKeyframeProperty[ 32 ];
	//
	BOOLEAN				m_bCustomOsdTextEnableProperty;
	ULONG				  m_nCustomOsdTextLineProperty[ 32 ];
	CHAR				  m_pCustomOsdTextStringProperty[ 32 ][ 16 ][ 64 + 1 ];
	BOOLEAN				  m_bCustomOsdTextStringRefreshProperty[ 32 ][ 16 ];
	ULONG				  m_nCustomOsdTextColorProperty[ 32 ][ 16 ];
	ULONG				m_nCustomOsdTextFontSizeProperty[ 32 ][ 16 ];
	ULONG				m_nCustomOsdTextPositionXProperty[ 32 ][ 16 ];
	ULONG				m_nCustomOsdTextPositionYProperty[ 32 ][ 16 ];


	ULONG				  m_nCustomAnalogVideoVbiLinesEnableProperty;
	ULONG				  m_nCustomAnalogVideoVbiLinesProperty;
	ULONG				  m_nCustomSpecialCameraInputProperty;
	ULONG				  m_nCustomCompanyIvsProperty;
	ULONG				  m_nCustomAnalogVideoSdiSingalStatusProperty;


//peter [2011.08.23]
	wait_queue_head_t	  m_wait_queue_head;
	//wait_queue_t          m_wait_queue;
	ULONG				  EA72172D8A27470AA2580EC509460D34;
	struct semaphore      B170D6CC53FA433DB899522A0B0325FC;					
	ULONG		           m_nDummy2[8];//for semaphore access????? do not remove

	ULONG				  E92EA7106EDE415589FC494AF89F85E0;
	struct semaphore      m_MZ0380AccessSemaphore;					
	ULONG		           m_nDummy5[8];//for semaphore access????? do not remove

	struct semaphore      m_pControlSemaphore;					
	ULONG		           m_nDummy6[8];//for semaphore access????? do not remove

//	ULONG				  m_pcm_update[16];

	ULONG 				  CFG0;
	ULONG 				  CFGB;
	ULONG 				  CFG2;
	ULONG				  idVendor;      
	ULONG				  idProduct;     
	ULONG				  bcdDevice;    
	ULONG				  iManufacturer;
	ULONG				  iProduct;      
	ULONG				  iSerialNumber;

//
	ULONG				  m_nCustomMotionStatusProperty[ 32 ][ 8 ];
	ULONG				  m_nCustomMotionTemporalSensitivityProperty[ 32 ];
	ULONG				  m_nCustomMotionSpatialSensitivityProperty[ 32 ];
	ULONG				  m_nCustomMotionLevelSensitivityProperty[ 32 ];
	ULONG				  m_nCustomMotionSpeedProperty[ 32 ];
	ULONG				  m_nCustomSoftwareWatchdogResetProperty;

	ULONG				  m_nAnalogCopyProtMacrovisionEnableProperty;

	ULONG*				  m_SA7160_video_buffer[ SA7160_MAX_BUFFER ];//virtual address
	dma_addr_t				  m_SA7160_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ SA7160_MAX_BUFFER ];

#ifdef TW6805_64bit
	ULONG*				  m_TW6816_video_buffer[ TW6816_MAX_BUFFER ];//virtual address
	dma_addr_t				  m_TW6816_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ TW6816_MAX_BUFFER ];
#endif //TW6805_64bit

#ifdef CX2581_64bit
	ULONG*				  m_CX2581_video_buffer[ 8 ][ CX2581_MAX_BUFFER ];//virtual address
	dma_addr_t				  m_CX2581_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ 8 ][ CX2581_MAX_BUFFER ];
#endif //CX2581_64bit

	ULONG				 m_IRQ_ready;
//FH8735
	ULONG				   m_nCustomAnalogVideo720OutputProperty;     //??
	ULONG		          m_nCustomEncoderVideoProfileProperty[ 32 ]; //??
	ULONG		          m_nCustomEncoderVideoLevelProperty[ 32 ];

	ULONG		          m_nCustomPreviewVideoResolutionProperty[ 32 ];
	ULONG				  m_nCustomRegionMaskParamsProperty[ 32 ][ 2 ][ 4 ];
	ULONG		          m_nCustomAnalogVideoDeinterlaceTypeProperty[ 16 ];
	ULONG		          m_nCustomAnalogVideoDenoiseTypeProperty[ 16 ];
	ULONG		          m_nCustomAnalogVideoDemiseTypeProperty[ 16 ];
	ULONG				  m_nCustomAnalogVideoAutoPhaseTypeProperty[ 16 ];
	ULONG		          m_nCustomEncoderVideoEntropyProperty[ 32 ];
	ULONG		          m_nCustomEncoderVideoAspectRatioProperty[ 32 ];
	ULONG		          m_nCustomEncoderVideoCropProperty[ 4 ][ 32 ];
	ULONG		          m_nCustomEncoderVideoAvgFrameRateProperty[ 32 ];
	ULONG		          m_nCustomEncoderVideoSkipFrameRateProperty[ 32 ];

	ULONG		          m_nCustomEncoderVideoPeakBitRateProperty[ 32 ];
	ULONG		          m_nCustomEncoderVideoTroughQualityProperty[ 32 ];

	ULONG				  m_nCustomAnalogVideoSkipFrameRateProperty[ 16 ];
	ULONG				  m_nCustomAnalogVideoAvgFrameRateProperty[ 32 ];

	ULONG				  m_nHVScaleFactor;//preview
	ULONG				  m_nH264HVScaleFactor;//0x00 00 00 00, mainH mainV subH subV

	ULONG				  m_nCustom_H264_Level_Property;

	ULONG				  m_nCustomSoftwareWatchdogEnableProperty;

#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,11,0)

	struct v4l2_device		v4l2_dev;
#endif

	BOOLEAN				m_pControlThread_already_stop;

	BOOLEAN				m_pVideoLosslThread_already_stop;
	BOOLEAN				FF6347EA309EF49519F7F07D0B6B28662LosslThread_already_stop;

	ULONG				H264_main_frame_count;
	ULONG				audio_F2B6709824D504332834A012BCBE1945D;
	
	struct timeval		A999292E148D40E58CCA15DC366CF956;

	ULONG				FE995CA4291A4F109AAE766EB116EB25;

	ULONG				m_nCustomAnalogVideoVgaHActiveProperty;
	ULONG				m_nCustomAnalogVideoVgaAspectRatioProperty;
	ULONG				m_nCustomCompanyVision4CEProperty;
	ULONG				m_nCustomAnalogVideoColorRangeProperty;

	ULONG				m_MST3367_bank;

	ULONG				C4E7BABA3C164ABA99E460C0B8165385; //7160, 6805 is buffer number
											  

	ULONG				m_CX2581_video_buffer_count[ 8 ];

	ULONG				m_TW5864_video_h264_count[ 8 ]; //TW5864 is h264 quantity filled in temp buffer
	ULONG				m_H264_left[ 8 ];

	ULONG				m_No_Signal_black_pattern_property;

	ULONG				m_No_Signal_yuv_pattern_property;

	ULONG				m_No_Signal_no_output_property;

	//ULONG				m_colorbar_pos;////position of colobar buffer
	ULONG				m_buf_pos;//position of desination buffer
	ULONG				m_src_pos;//position of source buffer
	BYTE				D8B74534E3F446EC9637B41BE21BE297[ 4 ];

	ULONG				m_nCustomAnalogVideoSplitProperty;
	ULONG				m_nCustomAnalogAudioVolumeProperty;
	ULONG				m_nCustomHDMI_Mixer;

	UINT				m_nKsDeviceAddress;

	ULONG				m_nCustomAnalogAudioDirectSoundPatchProperty; //must be 0 in linux

	ULONG				possible_booting;
	LONGLONG			m_booting_time;//avoid componentinit during booting

#if defined(AME_PL330B) || defined(AME_PL330A)
	QPCODECLIB_INITDATA			  m_initData;
	QPCODEC_USB_BUS_DATA		  m_sUsbBusData;
	//peter add
	//CObjectMgr*					  m_pComponentMgr;

	ICodecLib *					  m_pCodecLib;
	IMpegCodec *				  m_pMpegCodec;
	TQP_OBJECT_HANDLE			  BA3E1E68758F40848036F186E1A9DF05;
	TQP_OBJECT_HANDLE			  BE6018DEEC2C4BFAA101248A9C6F312F[ 4 ];
	TQP_OBJECT_HANDLE			  E23A0EAB120B4C609DC336EB8B99BE11[ 4 ];

	QP_BUFFER_DESCRIPTOR		  CDA0E8191AB44A53A0F640EDE8B8F70C[ 4 ][ 32 ];
	QP_KSSTREAM_HEADER			  BFAB79E4FD214756B9AF4B16FC78A0C5[ 4 ][ 32 ];
	ULONG						  B9F485FBC2EE44B287E5FA879D64F1F7[ 4 ];
	PLV4LDEV_PARENT_DEV				parent_dev;
	
	struct Interrupt_Container	m_intrrupt_array[ 4 ];

	F170997530C6943659ECE8DEC21301F66*				m_previewbuffer[ MAX_DEVICE_OPEN_NUM ];

#endif
	ULONG						m_pl330b_combine_4_chip;

	ULONGLONG					m_pl330b_stopfirmware_time;
	
	_GENNUM_INFO				m_GENNUM_INFO;
	WORD						m_USER_id;

	ULONG						m_i2c_chipaddr;
	ULONG						m_i2c_register;
	ULONG						m_pl330b_control_thread_stop;// 0 is run

	ULONG						m_nCustomAnalogVideoSubEncoderEnableProperty;

	ULONG						m_size_not_match_no_signal_blue_pattern;
	ULONG						m_timeperframe_denominator;
	ULONG						m_timeperframe_numerator;

	ULONG						m_Invert_UV;

	ULONG						m_nCustomAnalogVideoPinTopologyProperty;
	ULONG						m_nCustomAnalogVideoMultiSyncChannels;
	ULONG						  m_nCustomAnalogVideoMultiSyncPositionX;
	ULONG						  m_nCustomAnalogVideoMultiSyncPositionY;

} F42A18AF66EFF459eA332CA253FFF8A65;

#define BCD_TO_BINARY( counts ) (((counts) >> 4) * 10 + ((counts) & 0x0F)) 


#define F648D519438F246f6926E9C5A8F1AB132	(     3624 * 16)
#define F999D9A639D7D483c832149A449DEC4A2	(      24 * 128)
#define F7C753D18C94D4e6e8646BF67EB485B42	(             0)
#define FA2EAD3C05CDA4684824B70E456A61478	(             0)
#define FCABFFE666DB04b3d8DAF44353F9D8F09	(             0)
#define FAEE21C28BD554396B13BD4457ACCE69C	(             0)

#define F73ABAF3DA1E74460B62EE54E4669F354	( 7020 *  2 * 8)
#define F2D03C174E8CF4eea8F3ECFCF8A103118	(   24 * 60 * 4)
#define F238BE07276134b19B26EB51BA406C48F	(             0)
#define FA6288726E1B54d58800148E8FEF67C4A	(             0)
#define F2A850CD43FB040ddBB14F00080BD496D	(             0)
#define F5566F71042AB4ca8BF67E1349CF9CB75	(             0)

#define cc178591b6d74b57bc680e9715715b23	( 4096 *  2 *10)
#define edf64860fb974a6aa7dfe1b4557f75c8	( 4096 *  2 *10)//address to put audio data
#define AMEBDAD_MAX_AUDIO_DMA_BUFFER_SIZE	( 4096 *  2 *10)

//#ifdef ENABLE_8CHS
//	#define e86cad15f8e349d3868f1160049ff548	( 4096 *  8 * 4)//audio data
//#else
	#define e86cad15f8e349d3868f1160049ff548	( 4096 *  1 *10)//audio data
//#endif

#define ENABLE_8CHS 0 //0

#define b7c9dc950e38409fb7ec73d6ab0e0aa9	(			  0)
#define d809740c16e2435597dc685afc1339ea	(			  0)
#define b6527f4db0f44123a692b2fe16581386	(             0)
//

#define F3A2AB9276F634b32A042CD3A1D8E5F04	(0x000C6000 * 3)
#define F3A814C2DAC584c07B68E5A6B72DF27EF	(0x00010000 * 1)
#define FAC43334A7F814c21A0D09BF3FC1D934C	(0x00010000 * 4)
#define FAB54A133F8724a47AF66D1A793F28097	(             0)
#define F0F2939CCDD0D402aAB4EF1940D0A8985	(0x00096000 * 8)
#define FA65A02308839427a88745FFB68570C27	(             0)

#define a5ba11e017e349568504a4ba37df8b79	(	 0x00097E00) //preview buffer 1, in case no continous memory to allocate 
#define ed402a0345394412a4ffd4df74b3e391	(             0)
#define a64b931327b94bc7a58fcd1fd3f1bfd6	(             0)
#define ba98f190f54d44ba894e79c3bc107b50	(	1024 * 1024)//audio and H.264
#define a66316d33603423597a516a5c20b4353	(			  0)
#define b4fbeedf49894ccdba909e8b3b351901	(             0)

#ifdef FFMPEG_TW5864
#define TW5864_MAX_HX264_TMP_BUFFER_SIZE	(	622080    )//720*576*1.5
#define TW5864_MAX_HX264_RESIDUE_BUFFER_SIZE (	622080    )//720*576*1.5
#endif //FFMPEG_TW5864


//peter [2011.06.29]
#define fab512bee67447e5ad487ff8c9141384					0xc00000
#define a7d5606420be4603a64a664b3e793889	(0x00097E20 * 2) 
#define c74c55fc490345ba9750570701c84599	(    0x002FD020) 
#define c943dd7b9ba1473495174654db6e0a6a	(            64)
#define b23a1dd1038a44d9af452101ded182df	(             0)
#define c9010eea9f744361b49021b2a765f8b5	(0x00100000 * 3) //1024 * 1024)
#define a17f72b7dfb14276a9447efc8043e424	(             0)
#define c38773527ae34cff8475f0a1946c61f6	(             0)


#define MZ0380_HD_VIDEO_DMA_BUFFER_SIZE			(0x0034BD00) //HD
//#define MZ0380_MAX_VIDEO_DMA_BUFFER_SIZE		(0x00655000) //HD
#define MZ0380_MAX_VIDEO_DMA_BUFFER_SIZE		(0x0034BD00) //HD

//#define MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE	(0x0010F000 * 4)//960*576*2 (YUYV) * 4
#define MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE	(0x000CA900)//960*576*1.5 (YV12)
#define MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE 	(0x000CA900)

#define MZ0380_MAX_AUDIO_DMA_BUFFER_SIZE		(      4096 * 4)
#define MZ0380_MAX_AUDIO_SD_DMA_BUFFER_SIZE		(	   8192 * 16)


#define PL330B_MAX_VIDEO_DMA_BUFFER_SIZE	 (            0)
#define PL330B_MAX_AUDIO_DMA_BUFFER_SIZE	 (            0)
#define PL330B_MAX_VBI_DMA_BUFFER_SIZE		 (            0)
#define PL330B_MAX_MPEG_DMA_BUFFER_SIZE		 (            0)


#define DEFAULT_MST3367_VESA_SIZE	325 // NEED +0

#define DEFAULT_MST3367_EIA_SIZE	25

#define NTSTATUS		int

#define STATUS_SUCCESS		0x00000001
#define STATUS_UNSUCCESSFUL 0x00000000
#define STATUS_INSUFFICIENT_RESOURCES (0xc000009a)

#define SUPPORTED_ANALOG_VIDEO_STANDARDS_60HZ	V4L2_STD_525_60 //NTSC
#define SUPPORTED_ANALOG_VIDEO_STANDARDS_50HZ	V4L2_STD_625_50 //PAL

#define MAX_PATH 260

#define FREE_MEMORY( p ) { if( p ) { vfree( p ); p = NULL; } }

BOOLEAN F6B9E557A4BA24ffd926B820B836289C8_100NS( ULONG F6B9E557A4BA24ffd926B820B836289C8 );

typedef BOOLEAN BOOL;                  

#endif


// windows m_nStreamBaseCommonBufferLockNumber linux F66FD293166B14f93A084AE0E6BD0F196
// m_nStreamBaseCommonBufferFrameNumber F03D1DD650AC64c28B04687338F970D0E[ 0 ]
// 
