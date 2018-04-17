#include "LINUXV4L2.h" 
#include "property.h"
#include "tw6805.h"
#include "cx2581.h"
#include "sa7160.h"
#include "sl6010.h"
#include "tw5864.h"
#include "fh8735.h"
#include "mz0380.h"
#include "pl330b.h"
#include "version.h"

// ##########################################################################################################################################################################################################
// #
// # PRODUCT NAME: LINUXV4L2
// #        CHIPS: NONE
// #  MANUFACTORY: NONE
// #         DATE: 2008.06.24 ~ 201X.XX.XX
// #
// ##########################################################################################################################################################################################################
//

// ##########################################################################################################################################################################################################
//
static int  __init       FAF86DD63BEE049469391C62866E9E0BB( void );
static void __exit       FFEAB2309379F4a9fA0EB36080145582B( void );

#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,8,0)
#define __devinit        __section(.devinit.text) __cold notrace
#define __devexit        __section(.devexit.text) __exitused __cold notrace
#endif

#ifdef AME_PL330A
static int			F0251D2D952114606BEF15BFE3B8A3F85( struct usb_interface *intf, const struct usb_device_id* p_usb_device_id );
static void				F8B4E2049BF8D40a696F2510D0478FDC7( struct usb_interface *intf );
#else
static int  __devinit    F0251D2D952114606BEF15BFE3B8A3F85( struct pci_dev * F74930C6A858F43258B265F9ABB2DA5BC, const struct pci_device_id * F4085ACF1E4454fdb939A7943E6BC5888 );
static void __devexit    F8B4E2049BF8D40a696F2510D0478FDC7( struct pci_dev * F74930C6A858F43258B265F9ABB2DA5BC );
#endif
static int               F7AC7AD5156484fefAE9BE50C131694AD( struct pci_dev * F74930C6A858F43258B265F9ABB2DA5BC, pm_message_t F8CDF42B603CB436a9B7EB67E32DCF20A );
static int               F6D23A5636B0944c6A31D79C17B0C1D51( struct pci_dev * F74930C6A858F43258B265F9ABB2DA5BC );
static irqreturn_t       F391BB5CA4D5340ebB43E88B1EE6AC5B5( int F6B022DA61D9041f097FAFF570254C019, void * FD51B2B4E0CAC4359A9EFA429A9E16157 );
static irqreturn_t       F8A5688FD85F74b49AC6FA87B1FBE25F3( int F6B022DA61D9041f097FAFF570254C019, void * FD51B2B4E0CAC4359A9EFA429A9E16157, struct pt_regs * F2A2C6E4229F04f18B01249677FEECBA6 );
static void              FF6E02BBAFF114b048DA9EFBDC06CA997( unsigned long FD51B2B4E0CAC4359A9EFA429A9E16157 );

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,29)

static int               F974CC188B92849b9A9A52461E68698A2( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4 );
static int               F12AEFCB1CDFB499381DEE6D2FF4E0918( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4 );
#else
static int               F974CC188B92849b9A9A52461E68698A2( struct inode * F9E62F5638C29456b95618E44A5D0C9F3, struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4 );
static int               F12AEFCB1CDFB499381DEE6D2FF4E0918( struct inode * F9E62F5638C29456b95618E44A5D0C9F3, struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4 );
#endif

static ssize_t           FF3D65C9920534a488D1C01121CB1C678( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, char __user * F7DCDC607F3644b1591980748EA26F4D8, size_t n_count, loff_t * p_offset );
static unsigned int      FB13405624203472eAC9FD4691E20F851( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, struct poll_table_struct * p_poll_table_struct_wait );
static int               F79CFA56F35EA47608155CF434ADDCB8B( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, struct vm_area_struct * p_vma );
static int               FAE35D846200744d5B6365397A4074669( struct inode * F9E62F5638C29456b95618E44A5D0C9F3, struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, unsigned int cmd, unsigned long arg );
static int               F15ABF438BBB140ed867AE71A23421A04( struct inode * F9E62F5638C29456b95618E44A5D0C9F3, struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, unsigned int cmd, void * p_arg );
static int               FF32A4269941249bd9B5BD16974ED6CB2( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_capability * p_cap );
static int               F96755FB5B1A9478792D0C210A81B9715( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, v4l2_std_id * s );

#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0)
static int               F73F097AB862A4a558752C68773915A0F( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, v4l2_std_id  s );
#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,20)
static int               F73F097AB862A4a558752C68773915A0F( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, v4l2_std_id * s );
#else
static int               F73F097AB862A4a558752C68773915A0F( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, v4l2_std_id  s );
#endif

static int               F783F7A3A79A048369E71D95A51792A65( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, v4l2_std_id * s );
static int               FC515D62374DA4b188AA6842A8E9F246F( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_input * p_input );
static int				 common_video_device_vidioc_enumaudio(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *priv, struct v4l2_audio *a);

static int               F900393DC47254043B8F2CF7DC5194C99( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, unsigned int i );
static int               F03780B4A26054956B7A6CD9624B20D85( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, unsigned int * i );

static int				 common_video_device_vidioc_s_audio( struct file *file, void *fh, const struct v4l2_audio *a );
static int				 common_video_device_vidioc_g_audio( struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_audio *a);

//static int				common_video_device_vidioc_enum_dv_presets(struct file *file, void *fh, struct v4l2_dv_enum_preset *preset);

static int               common_video_device_vidioc_s_parm( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_streamparm *sp );
static int               common_video_device_vidioc_g_parm( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_streamparm *sp );

static int				 common_video_device_vidioc_enum_frameintervals(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_frmivalenum *fival);
static int				 common_video_device_vidioc_enum_framesizes(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_frmsizeenum *fsize);

static int				 common_video_device_vidioc_cropcap(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_cropcap *cropcap);
static int				 common_video_device_vidioc_s_crop(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_cropcap *cropcap);
static int				 common_video_device_vidioc_g_crop(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_cropcap *cropcap);

static int               F4AE125B7768742c4ADCFED552CAF7C82( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_fmtdesc * p_fmtdesc );
static int               FAA9A4D7A9B264da19300EE68477972A1( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_format * p_fmt );
static int               FEE6EBBFC370841adADAA57CE5BEE5614( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_format * p_fmt );
static int               F6727CA3250D341ac870EBFB883ABD913( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_format * p_fmt );
static int               FE378301A538E42ca99A12D118AA57A57( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_queryctrl * p_queryctrl );
static int				 common_video_device_vidioc_querymenu( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_querymenu *a);

static int               FE2A7B4A8EE7849ceA91671F8DE876A7F( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_control * p_control );
static int               F84B3BF483AB54d12922BBF693119ED0A( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_control * p_control );

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,18)

static int               F91C01BFADB8E43df81EC6CC41D2EE087( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_ext_controls * F6537805ACA4443d5AA5A380BA0BC5276 );
static int               F82E24F268CBB49ca9A83789D7475B068( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_ext_controls * F6537805ACA4443d5AA5A380BA0BC5276 );
static int				 common_video_device_vidioc_try_ext_ctrls( struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_ext_controls * F6537805ACA4443d5AA5A380BA0BC5276);
static int				common_video_device_vidioc_query_ext_ctrl(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_query_ext_ctrl *a);
#endif

static int               FFAC5AD9B7CD64ca28E7E9847C52A6E92( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_mpeg_compression * F4C7025F96E0944f2A84D86762A483F4A );
static int               FA09B89F985B34f599FA8349FDB25C1CF( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_mpeg_compression * F4C7025F96E0944f2A84D86762A483F4A );
static int               FE64270764DAF4bdbA2DF5779584DF0F7( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_encoder_cmd * F685481532C82490191EB3B24CC84235E );
static int               FD89C51CD80FB47949EE4D5A090E1ED6D( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_requestbuffers * p_requestbuffers );
static int               FC28B4FA81CB44cd2A02DAABFB15C0175 ( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_buffer * F947DB5F969484d42AA3A243E06DB35EB );
static int               F1CEFD4E364F942d5A796687660DF4476( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_buffer * F947DB5F969484d42AA3A243E06DB35EB );
static int               F8ED1C78CFCE74f82A69E33D70B8A0DB3( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_buffer * F947DB5F969484d42AA3A243E06DB35EB );
static int               F4B0874C1F68D498bA1262243B9C11323( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, enum v4l2_buf_type F7F32101CEC1342f984C871B134196B83 );
static int               FBD214630F7C445f9B3050CEFDBB729B2( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, enum v4l2_buf_type F7F32101CEC1342f984C871B134196B83 );
static int               FDE722856BB1E40ad93279EA24FDADC7A( struct videobuf_queue * p_queue, unsigned int * p_count, unsigned int * p_size );
static int               F89FBFD276737452cB02B90E1858E414B( struct videobuf_queue * p_queue, struct videobuf_buffer * F947DB5F969484d42AA3A243E06DB35EB, enum v4l2_field e_field );
static void              F3A12A0E868554cb0AFE2F5789D55B19F( struct videobuf_queue * p_queue, struct videobuf_buffer * F947DB5F969484d42AA3A243E06DB35EB );
static void              FF7C28EE760F14ad99457A74168D0FFBF( struct videobuf_queue * p_queue, struct videobuf_buffer * F947DB5F969484d42AA3A243E06DB35EB );
static int               FD1CD603E47C14387BB6036D48A0561AC( struct snd_pcm_substream * F41E35C5990A344ab87C1D53585EECFCC );
static int               F60F0B859ED1E4629B7AEB0CA9D7F2B88( struct snd_pcm_substream * F41E35C5990A344ab87C1D53585EECFCC );
static int               F4C56246F2BE94db4BE8768BA7A9C5533( struct snd_pcm_substream * F41E35C5990A344ab87C1D53585EECFCC, struct snd_pcm_hw_params * FEFDE7BA45F8545a798597EF0EA7A6AE9 );
static int               F6525289DC9394f89A6A83BF3B47999D1( struct snd_pcm_substream * F41E35C5990A344ab87C1D53585EECFCC );
static int               F4CDEFE2B56A34d09AA9D79A19C5CF6D0( struct snd_pcm_substream * F41E35C5990A344ab87C1D53585EECFCC );
static int               F3E0B683669C740f88340BEF43A17FAE5( struct snd_pcm_substream * F41E35C5990A344ab87C1D53585EECFCC, int cmd );
static snd_pcm_uframes_t F288016094808405fA40919514F2E4114( struct snd_pcm_substream * F41E35C5990A344ab87C1D53585EECFCC );
static int               F610D5F7D4CF6401bB7731B627A42CA8A( struct snd_kcontrol * F04E034030A5B43c3BD4AAB3057666A39, struct snd_ctl_elem_info * FB9478A2460F34931B3461172D5275F1E );
static int               F6FA3AF8CA60D42f4AE4A40E78BE032B8( struct snd_kcontrol * F04E034030A5B43c3BD4AAB3057666A39, struct snd_ctl_elem_value * p_value );
static int               F14A737D3699C4edfB41D3701838B2D5F( struct snd_kcontrol * F04E034030A5B43c3BD4AAB3057666A39, struct snd_ctl_elem_value * p_value );



static struct pci_device_id FA7B99DBE9A7D4ff88FF7526CEDB7C5AA[ ] = {

#ifdef AME_SC300_SC330_SC310_SC3B0
	{ 0x1797, 0x6801, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, //
	{ 0x1797, 0x6802, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 },

	{ 0x1797, 0x6804, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, //
//peter[2011.07.06]
	{ 0x1797, 0x6805, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, 

	{ 0x1797, 0x6810, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, //
	{ 0x1797, 0x6811, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 },
	{ 0x1797, 0x6812, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, 
	{ 0x1797, 0x6813, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, 

	{ 0x1797, 0x6814, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 },
	{ 0x1797, 0x6815, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 },
	{ 0x1797, 0x6816, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, 
	{ 0x1797, 0x6817, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, 

	{ 0x14F1, 0x8210, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, //

	{ 0x1797, 0x5864, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, // TECHWELL TW5864 PRODUCTS
#endif

#ifdef AME_SA7160
	//#ifdef ENABLE_8CHS
	//{ 0x1131, 0x7160, 0xF512, 0x12AB, 0, 0, 0 }, // NXP SAA7160 PRODUCTS
	//{ 0x1131, 0x7160, 0xF514, 0x12AB, 0, 0, 0 }, // NXP SAA7160 PRODUCTS
	//{ 0x1131, 0x7160, 0xF519, 0x12AB, 0, 0, 0 }, // NXP SAA7160 PRODUCTS
	//#elif defined (SC502_MIX_8CH)
	//{ 0x1131, 0x7160, 0xF508, 0x12AB, 0, 0, 0 }, // NXP SAA7160 PRODUCTS
	//{ 0x1131, 0x7160, 0xF50C, 0x12AB, 0, 0, 0 }, // NXP SAA7160 PRODUCTS
	//#else
	{ 0x1131, 0x7160, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, // NXP SAA7160 PRODUCTS
	//#endif
#endif


#ifdef AME_FH8735
	{ 0x3086, 0x0101, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, // FULLHAN FH8735 PRODUCTS
#endif
	
#ifdef AME_MZ0380
	{ 0x0907, 0x0100, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, // VATICS MOZART 380 PRODUCTS
	{ 0x12AB, 0x0380, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, // VATICS MOZART 380 PRODUCTS
	{ 0x12AB, 0x0370, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, // VATICS MOZART 380 PRODUCTS
#endif

#ifdef AME_PL330B
	{ 0x1AF2, 0xA001, PCI_ANY_ID, PCI_ANY_ID, 0, 0, 0 }, // SIGNADESIGN PL330B PRODUCTS
#endif

	{ 0x0000, }
};

static struct usb_device_id LINUXV4L2_USB_DEVICE_ID_TABLE[] =
{
	{USB_DEVICE(0x1164, 0xF5A0)},
	{USB_DEVICE(0x1164, 0xF5A1)},
	{USB_DEVICE(0x1164, 0xF5AB)},
	{USB_DEVICE(0x1164, 0xF5AD)},
	{}
};

#ifdef AME_FH8735
static struct pci_driver linuxv4l2_pci_driver8735 = { //

	.name     = "LINUXV4L28735",
	.id_table =  FA7B99DBE9A7D4ff88FF7526CEDB7C5AA,
	.probe    =  F0251D2D952114606BEF15BFE3B8A3F85,
	.remove   =  F8B4E2049BF8D40a696F2510D0478FDC7,
	.suspend  =  F7AC7AD5156484fefAE9BE50C131694AD,
	.resume   =  F6D23A5636B0944c6A31D79C17B0C1D51,
};
#endif

#ifdef AME_SA7160
static struct pci_driver linuxv4l2_pci_driver7160 = { //

//#ifdef ENABLE_8CHS
//	.name     = "LINUXV4L27160_8CHS",
//#elif SC502_MIX_8CH
//	.name     = "LINUXV4L27160_502",
//#else
	.name     = "LINUXV4L27160",
//#endif
	.id_table =  FA7B99DBE9A7D4ff88FF7526CEDB7C5AA,
	.probe    =  F0251D2D952114606BEF15BFE3B8A3F85,
	.remove   =  F8B4E2049BF8D40a696F2510D0478FDC7,
	.suspend  =  F7AC7AD5156484fefAE9BE50C131694AD,
	.resume   =  F6D23A5636B0944c6A31D79C17B0C1D51,
};
#endif


#ifdef AME_MZ0380
static struct pci_driver linuxv4l2_pci_driver0380 = { //

	.name     = "LINUXV4L20380",
	.id_table =  FA7B99DBE9A7D4ff88FF7526CEDB7C5AA,
	.probe    =  F0251D2D952114606BEF15BFE3B8A3F85,
	.remove   =  F8B4E2049BF8D40a696F2510D0478FDC7,
	.suspend  =  F7AC7AD5156484fefAE9BE50C131694AD,
	.resume   =  F6D23A5636B0944c6A31D79C17B0C1D51,
};
#endif

#ifdef AME_PL330B
static struct pci_driver linuxv4l2_pci_driver330b = { //

	.name     = "LINUXV4L2330b",
	.id_table =  FA7B99DBE9A7D4ff88FF7526CEDB7C5AA,
	.probe    =  F0251D2D952114606BEF15BFE3B8A3F85,
	.remove   =  F8B4E2049BF8D40a696F2510D0478FDC7,
	.suspend  =  F7AC7AD5156484fefAE9BE50C131694AD,
	.resume   =  F6D23A5636B0944c6A31D79C17B0C1D51,
};
#endif

#ifdef AME_PL330A
static struct usb_driver linuxv4l2_usb_driver330a =
{
    .name        = "LINUXV4L2330a",
    .id_table    = LINUXV4L2_USB_DEVICE_ID_TABLE,
    .probe       = F0251D2D952114606BEF15BFE3B8A3F85,
    .disconnect  = F8B4E2049BF8D40a696F2510D0478FDC7,
};
#endif


#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,1,0)

static const struct v4l2_file_operations F077C6DE00EBA4b6788650097637A83F3 =
{
	.owner	  = THIS_MODULE,
	.open	  = F974CC188B92849b9A9A52461E68698A2,
	.release  = F12AEFCB1CDFB499381DEE6D2FF4E0918,
	.read	  = FF3D65C9920534a488D1C01121CB1C678,
	.poll     = FB13405624203472eAC9FD4691E20F851,
	.mmap	  = F79CFA56F35EA47608155CF434ADDCB8B,
	.unlocked_ioctl	  = video_ioctl2,
};

#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,29)

static const struct v4l2_file_operations F077C6DE00EBA4b6788650097637A83F3 =
{
	.owner	  = THIS_MODULE,
	.open	  = F974CC188B92849b9A9A52461E68698A2,
	.release  = F12AEFCB1CDFB499381DEE6D2FF4E0918,
	.read	  = FF3D65C9920534a488D1C01121CB1C678,
	.poll     = FB13405624203472eAC9FD4691E20F851,
	.mmap	  = F79CFA56F35EA47608155CF434ADDCB8B,
	.ioctl	  = video_ioctl2,
};

#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,18)

static const struct file_operations F077C6DE00EBA4b6788650097637A83F3 =
{
	.owner	  = THIS_MODULE,
	.open	  = F974CC188B92849b9A9A52461E68698A2,
	.release  = F12AEFCB1CDFB499381DEE6D2FF4E0918,
	.read	  = FF3D65C9920534a488D1C01121CB1C678,
	.poll     = FB13405624203472eAC9FD4691E20F851,
	.mmap	  = F79CFA56F35EA47608155CF434ADDCB8B,
	.ioctl	  = video_ioctl2,
	.llseek   = no_llseek, 
};

#else

static const struct file_operations F077C6DE00EBA4b6788650097637A83F3 =
{
	.owner	  = THIS_MODULE,
	.open	  = F974CC188B92849b9A9A52461E68698A2,
	.release  = F12AEFCB1CDFB499381DEE6D2FF4E0918,
	.read	  = FF3D65C9920534a488D1C01121CB1C678,
	.poll     = FB13405624203472eAC9FD4691E20F851,
	.mmap	  = F79CFA56F35EA47608155CF434ADDCB8B,
	.ioctl	  = FAE35D846200744d5B6365397A4074669,
	.llseek   = no_llseek,
};

#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)

static const struct v4l2_ioctl_ops F4A7EB68C671744bfA1F46C39EC3E4730 =
{
	.vidioc_querycap         = FF32A4269941249bd9B5BD16974ED6CB2,
	.vidioc_querystd         = F96755FB5B1A9478792D0C210A81B9715,
	.vidioc_s_std            = F73F097AB862A4a558752C68773915A0F,
	.vidioc_g_std            = F783F7A3A79A048369E71D95A51792A65,
	.vidioc_enum_input       = FC515D62374DA4b188AA6842A8E9F246F,
	.vidioc_s_input          = F900393DC47254043B8F2CF7DC5194C99,
	.vidioc_g_input          = F03780B4A26054956B7A6CD9624B20D85,
	.vidioc_enum_fmt_vid_cap = F4AE125B7768742c4ADCFED552CAF7C82,
	.vidioc_try_fmt_vid_cap  = FAA9A4D7A9B264da19300EE68477972A1,
	.vidioc_s_fmt_vid_cap    = FEE6EBBFC370841adADAA57CE5BEE5614,
	.vidioc_g_fmt_vid_cap    = F6727CA3250D341ac870EBFB883ABD913,
	.vidioc_queryctrl        = FE378301A538E42ca99A12D118AA57A57,
	.vidioc_querymenu		 = common_video_device_vidioc_querymenu,
	.vidioc_s_ctrl           = FE2A7B4A8EE7849ceA91671F8DE876A7F,
	.vidioc_g_ctrl           = F84B3BF483AB54d12922BBF693119ED0A,
	.vidioc_s_ext_ctrls		 = F91C01BFADB8E43df81EC6CC41D2EE087,
	.vidioc_g_ext_ctrls		 = F82E24F268CBB49ca9A83789D7475B068,
	.vidioc_try_ext_ctrls	 = common_video_device_vidioc_try_ext_ctrls,
	//.vidioc_query_ext_ctrl	 = common_video_device_vidioc_query_ext_ctrl,
	.vidioc_encoder_cmd      = FE64270764DAF4bdbA2DF5779584DF0F7,
	.vidioc_reqbufs          = FD89C51CD80FB47949EE4D5A090E1ED6D,
	.vidioc_querybuf         = FC28B4FA81CB44cd2A02DAABFB15C0175,
	.vidioc_qbuf             = F1CEFD4E364F942d5A796687660DF4476,
	.vidioc_dqbuf            = F8ED1C78CFCE74f82A69E33D70B8A0DB3,
	.vidioc_streamon         = F4B0874C1F68D498bA1262243B9C11323,
	.vidioc_streamoff        = FBD214630F7C445f9B3050CEFDBB729B2,
	.vidioc_s_audio          = common_video_device_vidioc_s_audio,
	.vidioc_g_audio          = common_video_device_vidioc_g_audio,
	.vidioc_enumaudio		 = common_video_device_vidioc_enumaudio,
//	.vidioc_enum_dv_presets  = common_video_device_vidioc_enum_dv_presets,
	.vidioc_s_parm          = common_video_device_vidioc_s_parm,
	.vidioc_g_parm          = common_video_device_vidioc_g_parm,
	.vidioc_enum_frameintervals = common_video_device_vidioc_enum_frameintervals,
	.vidioc_enum_framesizes	= common_video_device_vidioc_enum_framesizes,
	.vidioc_cropcap			= common_video_device_vidioc_cropcap,
	//.vidioc_s_crop			= common_video_device_vidioc_s_crop,
	//.vidioc_g_crop			= common_video_device_vidioc_g_crop,

};
#endif

#if (LINUX_VERSION_CODE == KERNEL_VERSION(2,6,18)) || (LINUX_VERSION_CODE == KERNEL_VERSION(2,6,19))

static struct v4l2_tvnorm F2C001A2C84284862A15E366960EAC325[ 2 ] = 
{
	{	.name = "V4L2_STD_525_60",
		.id   = V4L2_STD_525_60,
	},
	{	.name = "V4L2_STD_625_50",
		.id   = V4L2_STD_625_50,
	},
};

#endif

static struct videobuf_queue_ops F978008BE1AA54f2cA568185B87EA4843 =
{
	.buf_setup   = FDE722856BB1E40ad93279EA24FDADC7A,
	.buf_prepare = F89FBFD276737452cB02B90E1858E414B,
	.buf_queue   = F3A12A0E868554cb0AFE2F5789D55B19F,
	.buf_release = FF7C28EE760F14ad99457A74168D0FFBF,
};

static struct snd_kcontrol_new FDBCA1261C6CF40d3B59939C30BB92BFF = {

	.iface = SNDRV_CTL_ELEM_IFACE_MIXER,
	.access = SNDRV_CTL_ELEM_ACCESS_READWRITE | SNDRV_CTL_ELEM_ACCESS_TLV_READ,
	.name  = "VOLUME",
	.info  = F610D5F7D4CF6401bB7731B627A42CA8A,
	.get   = F6FA3AF8CA60D42f4AE4A40E78BE032B8,
	.put   = F14A737D3699C4edfB41D3701838B2D5F,
};

static struct snd_pcm_ops FB3AA7AC41ACB495795F77C974CDB32EE =
{
	.open      = FD1CD603E47C14387BB6036D48A0561AC,
	.close     = F60F0B859ED1E4629B7AEB0CA9D7F2B88,
	.ioctl     = snd_pcm_lib_ioctl,
	.hw_params = F4C56246F2BE94db4BE8768BA7A9C5533,
	.hw_free   = F6525289DC9394f89A6A83BF3B47999D1,
	.prepare   = F4CDEFE2B56A34d09AA9D79A19C5CF6D0,
	.trigger   = F3E0B683669C740f88340BEF43A17FAE5,
	.pointer   = F288016094808405fA40919514F2E4114,
	.page      = snd_pcm_sgbuf_ops_page,
};

static struct snd_pcm_hardware FEAF4AC49BEDE45c48099A8E9544363A3_FH8735 =
{
	.info             = SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID | SNDRV_PCM_INFO_INTERLEAVED | SNDRV_PCM_INFO_BLOCK_TRANSFER,
	.formats          = SNDRV_PCM_FMTBIT_S16_LE,
	.rates            = SNDRV_PCM_RATE_48000 | SNDRV_PCM_RATE_44100 | SNDRV_PCM_RATE_32000,
	.rate_min         = 32000,
	.rate_max         = 48000,
	.channels_min     = 2,
	.channels_max     = 2,
	.buffer_bytes_max = 8192 * 64,
	.period_bytes_min = 8192,
	.period_bytes_max = 8192,
	.periods_max      = 64,
	.periods_min      = 64,
};

static struct snd_pcm_hardware FEAF4AC49BEDE45c48099A8E9544363A3_FH8735_SC3A0 =
{
	.info             = SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID | SNDRV_PCM_INFO_INTERLEAVED | SNDRV_PCM_INFO_BLOCK_TRANSFER,
	.formats          = SNDRV_PCM_FMTBIT_S16_LE,
	.rates            = SNDRV_PCM_RATE_48000,
	.rate_min         = 48000,
	.rate_max         = 48000,
#ifdef SC3A0_STEREO 
	.channels_min     = 2,
	.channels_max     = 2,
	.buffer_bytes_max = 4096 * 64,
	.period_bytes_min = 4096,
	.period_bytes_max = 4096,
#else
	.channels_min     = 1,
	.channels_max     = 1,
	.buffer_bytes_max = 2048 * 64,
	.period_bytes_min = 2048,
	.period_bytes_max = 2048,
#endif
	.periods_max      = 64,
	.periods_min      = 64,
};

static struct snd_pcm_hardware FEAF4AC49BEDE45c48099A8E9544363A3_SA7160_ENABLE_8CHS =
{
	.info             = SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID | SNDRV_PCM_INFO_INTERLEAVED | SNDRV_PCM_INFO_BLOCK_TRANSFER,
	.formats          = SNDRV_PCM_FMTBIT_S16_LE,
	.rates            = SNDRV_PCM_RATE_48000 | SNDRV_PCM_RATE_44100 | SNDRV_PCM_RATE_32000,
	.rate_min         = 32000,
	.rate_max         = 48000,
//#ifdef ENABLE_8CHS
	.channels_min     = 8,
	.channels_max     = 8,
	.buffer_bytes_max = 4 * 4096 * 64,
	.period_bytes_min = 4 * 4096,
	.period_bytes_max = 4 * 4096,
//#else
//	.channels_min     = 2,
//	.channels_max     = 2,
//	.buffer_bytes_max = 4096 * 64,
//	.period_bytes_min = 4096,
//	.period_bytes_max = 4096,
//#endif
	.periods_max      = 64,
	.periods_min      = 64,
};

static struct snd_pcm_hardware FEAF4AC49BEDE45c48099A8E9544363A3_SA7160 =
{
	.info             = SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID | SNDRV_PCM_INFO_INTERLEAVED | SNDRV_PCM_INFO_BLOCK_TRANSFER,
	.formats          = SNDRV_PCM_FMTBIT_S16_LE,
	.rates            = SNDRV_PCM_RATE_48000 | SNDRV_PCM_RATE_44100 | SNDRV_PCM_RATE_32000,
	.rate_min         = 32000,
	.rate_max         = 48000,
//#ifdef ENABLE_8CHS
//	.channels_min     = 8,
//	.channels_max     = 8,
//	.buffer_bytes_max = 4 * 4096 * 64,
//	.period_bytes_min = 4 * 4096,
//	.period_bytes_max = 4 * 4096,
//#else
	.channels_min     = 2,
	.channels_max     = 2,
	.buffer_bytes_max = 4096 * 64,
	.period_bytes_min = 4096,
	.period_bytes_max = 4096,
//#endif
	.periods_max      = 64,
	.periods_min      = 64,
};


static struct snd_pcm_hardware FEAF4AC49BEDE45c48099A8E9544363A3_MZ0380_SC5C0 =
{
	.info             = SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID | SNDRV_PCM_INFO_INTERLEAVED | SNDRV_PCM_INFO_BLOCK_TRANSFER,
	.formats          = SNDRV_PCM_FMTBIT_S16_LE,
	.rates            = SNDRV_PCM_RATE_48000 | SNDRV_PCM_RATE_44100 | SNDRV_PCM_RATE_32000,
	.rate_min         = 32000,
	.rate_max         = 48000,
	.channels_min     = 2,
	.channels_max     = 2,
	.buffer_bytes_max = 4096 * 64,
	.period_bytes_min = 4096,
	.period_bytes_max = 4096,
	.periods_max      = 64,
	.periods_min      = 64,
};

static struct snd_pcm_hardware FEAF4AC49BEDE45c48099A8E9544363A3_MZ0380_SC3C0 =
{
	.info             = SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID | SNDRV_PCM_INFO_INTERLEAVED | SNDRV_PCM_INFO_BLOCK_TRANSFER,
	.formats          = SNDRV_PCM_FMTBIT_S16_LE,
	.rates            = SNDRV_PCM_RATE_48000,
	.rate_min         = 48000,
	.rate_max         = 48000,
	.channels_min     = 1,
	.channels_max     = 1,
	.buffer_bytes_max = 4096 * 64,
	.period_bytes_min = 4096,
	.period_bytes_max = 4096,
	.periods_max      = 64,
	.periods_min      = 64,
};

static struct snd_pcm_hardware FEAF4AC49BEDE45c48099A8E9544363A3_TW5864 =
{
	.info             = SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID | SNDRV_PCM_INFO_INTERLEAVED | SNDRV_PCM_INFO_BLOCK_TRANSFER,
	.formats          = SNDRV_PCM_FMTBIT_S16_LE,
	.rates            = SNDRV_PCM_RATE_8000,
	.rate_min         = 8000,
	.rate_max         = 8000,
	.channels_min     = 1,
	.channels_max     = 1,
	.buffer_bytes_max = 498 * 64,
	.period_bytes_min = 498,
	.period_bytes_max = 498,
	.periods_max      = 64,
	.periods_min      = 64,
};

static struct snd_pcm_hardware FEAF4AC49BEDE45c48099A8E9544363A3_CX2581 =
{
	.info             = SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID | SNDRV_PCM_INFO_INTERLEAVED | SNDRV_PCM_INFO_BLOCK_TRANSFER,
	.formats          = SNDRV_PCM_FMTBIT_S16_LE,
	.rates            = SNDRV_PCM_RATE_48000 ,
	.rate_min         = 48000,
	.rate_max         = 48000,
	.channels_min     = 1,
	.channels_max     = 1,
	.buffer_bytes_max = 960 * 64,
	.period_bytes_min = 960,
	.period_bytes_max = 960,
	.periods_max      = 64,
	.periods_min      = 64,
};
static struct snd_pcm_hardware FEAF4AC49BEDE45c48099A8E9544363A3_SC300_SQUARE_PIXEL =
{
	.info             = SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID | SNDRV_PCM_INFO_INTERLEAVED | SNDRV_PCM_INFO_BLOCK_TRANSFER,
	.formats          = SNDRV_PCM_FMTBIT_S16_LE,
	.rates            = SNDRV_PCM_RATE_48000,
	.rate_min         = 48000,
	.rate_max         = 48000,
	.channels_min     = 2,
	.channels_max     = 2,
	.buffer_bytes_max = 1920 * 64,
	.period_bytes_min = 1920,
	.period_bytes_max = 1920,
	.periods_max      = 64,
	.periods_min      = 64,
};
struct snd_pcm_hardware FEAF4AC49BEDE45c48099A8E9544363A3_PL330B =
{
	.info             = SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID | SNDRV_PCM_INFO_INTERLEAVED | SNDRV_PCM_INFO_BLOCK_TRANSFER,
	.formats          = SNDRV_PCM_FMTBIT_S16_LE,
	.rates            = SNDRV_PCM_RATE_48000 | SNDRV_PCM_RATE_44100 | SNDRV_PCM_RATE_32000,
	.rate_min         = 32000,
	.rate_max         = 48000,
	.channels_min     = 2,
	.channels_max     = 2,

#ifdef CUEBI_WEBRTC
	.buffer_bytes_max = 3764 * 64,
	.period_bytes_min = 3764,
	.period_bytes_max = 3764,
#else
	.buffer_bytes_max = 4096 * 64,
	.period_bytes_min = 4096,
	.period_bytes_max = 4096,
#endif

	.periods_max      = 64,
	.periods_min      = 64,
};

//peter [2011.07.15]
static struct snd_pcm_hardware FEAF4AC49BEDE45c48099A8E9544363A3 =
{
	.info             = SNDRV_PCM_INFO_MMAP | SNDRV_PCM_INFO_MMAP_VALID | SNDRV_PCM_INFO_INTERLEAVED | SNDRV_PCM_INFO_BLOCK_TRANSFER,
	.formats          = SNDRV_PCM_FMTBIT_S16_LE,
	.rates            = SNDRV_PCM_RATE_48000,
	.rate_min         = 48000,
	.rate_max         = 48000,
	.channels_min     = 1,
	.channels_max     = 1,
	.buffer_bytes_max = 1920 * 64,
	.period_bytes_min = 1920,
	.period_bytes_max = 1920,
	.periods_max      = 64,
	.periods_min      = 64,
};
ULONG g_n_bus_number[ 32 ] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };

static ULONG FB8FF609F538541e69F50B4A5C3F035DA[ 21 ][ 22 ] = 
{
	{ 0x1797, 0x6801, 128, 100, 128, 128,  16, 1, 120, 2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1797, 0x6802, 128, 100, 128, 128,  16, 1, 120, 2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1797, 0x6804, 128, 100, 128, 128,  16, 1, 120, 2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1797, 0x6805, 128, 100, 128, 128,  16, 1, 120, 2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1797, 0x6810, 128, 100, 128, 128,  16, 1, 120, 2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1797, 0x6811, 128, 100, 128, 128,  16, 1, 120, 2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1797, 0x6812, 128, 100, 128, 128,  16, 1, 120, 2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1797, 0x6813, 128, 100, 128, 128,  16, 1, 120, 2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1797, 0x6814, 128, 100, 128, 128,  16, 1, 120, 2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1797, 0x6815, 128, 100, 128, 128,  16, 1, 120, 2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1797, 0x6816, 128, 100, 128, 128,  16, 1, 120, 2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1797, 0x6817, 128, 100, 128, 128,  16, 1, 120, 2, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x14F1, 0x8210, 128, 128, 128, 128, 128, 1, 256, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x14F1, 0x5851, 128, 128, 128, 128, 128, 1, 256, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1131, 0x7160, 128, 128, 128, 128, 128, 1, 256, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1999, 0xA04C, 128, 128, 128, 128,  16, 1, 256, 0, 0x00000000, 0x00000000, 0x00000003, 0x00000001, 0x3FFFFFFF, 0x00FFFFFF, 0x00000008, 0x00000008, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x3086, 0x0101, 128, 128, 128, 128, 128, 1, 256, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1797, 0x5864, 128, 128, 128, 128, 128, 1, 256, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x0907, 0x0100, 128, 128, 128, 128, 128, 1, 256, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x12AB, 0x0380, 128, 128, 128, 128, 128, 1, 256, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
	{ 0x1AF2, 0xA001, 128, 128, 128, 128, 128, 1, 256, 0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 /*GPIO DIRECTION*/, 0x00000000 /*GPIO DATA*/ },
};

static ULONG F6965D2100E0840159702EF5670FD1E02[ 21 ][ 22 ] = 
{
	{ 0x1797, 0x6801, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1797, 0x6802, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1797, 0x6804, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1797, 0x6805, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1797, 0x6810, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1797, 0x6811, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1797, 0x6812, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1797, 0x6813, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1797, 0x6814, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1797, 0x6815, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1797, 0x6816, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1797, 0x6817, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x14F1, 0x8210, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x14F1, 0x5851, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1131, 0x7160, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1999, 0xA04C, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x3086, 0x0101, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1797, 0x5864, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x0907, 0x0100, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x12AB, 0x0380, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
	{ 0x1AF2, 0xA001, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 /*GPIO DIRECTION*/, 1 /*GPIO DATA*/ },
};


//not finished
/*
static struct v4l2_query_ext_ctrl LINUXV4L2_V4L2_QUERY_EXT_CTRL[ ] = 
{
	{	.id            =  V4L2_CID_MPEG_VIDEO_BITRATE,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "BITRATE",
		.minimum       =  1000000,
		.maximum       =  60000000,
		.step          =  1000000,
		.default_value =  12000000,
		.flags         =  0,
		.elem_size		= 0,
		.elems = 0,
		.nr_of_dims = 0,
		//.dims[V4L2_CTRL_MAX_DIMS] = {0},
		//.reserved[32] = {0},
	}, 
};
*/
static struct v4l2_queryctrl F7CCABE6CE7AF4796BF5AA27C4E82D0EE[ ] = 
{
	{	.id            =  V4L2_CID_BRIGHTNESS,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "BRIGHTNESS",
		.minimum       =  0,
		.maximum       =  255,
		.step          =  1,
		.default_value =  128,
		.flags         =  0,
	}, 
	{	.id            =  V4L2_CID_CONTRAST,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "CONTRAST",
		.minimum       =  0,
		.maximum       =  255,
		.step          =  1,
		.default_value =  128,
		.flags         =  0,
	}, 
	{	.id            =  V4L2_CID_SATURATION,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "SATURATION",
		.minimum       =  0,
		.maximum       =  255,
		.step          =  1,
		.default_value =  128,
		.flags         =  0,
	}, 
	{	.id            =  V4L2_CID_HUE,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "HUE",
		.minimum       =  0,
		.maximum       =  255,
		.step          =  1,
		.default_value =  128,
		.flags         =  0,
	},
	{	.id            =  V4L2_CID_SHARPNESS,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "SHARPNESS",
		.minimum       =  0,
		.maximum       =  255,
		.step          =  1,
		.default_value =  128,
		.flags         =  0,
	},
	{	.id            =  V4L2_CID_AUTOGAIN,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "AUTO GAIN",
		.minimum       =  0,
		.maximum       =  1,
		.step          =  1,
		.default_value =  1,
		.flags         =  0,
	},
	{	.id            =  V4L2_CID_GAIN,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "GAIN",
		.minimum       =  0,
		.maximum       =  511,
		.step          =  1,
		.default_value =  256,
		.flags         =  0,
	},
	{	.id            =  F4E4758ED106F4fbcBC46709DCC7A3FEB,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "SWITCH SPEED",
		.minimum       =  0,
		.maximum       =  2,
		.step          =  1,
		.default_value =  1,
		.flags         =  0,
	},
	{	.id            =  F0A6769CE1DE64a25A308D9585D0949DE,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "SWITCH TABLE",
		.minimum       =  0x00000000,
		.maximum       =  0x00FFFFFF,
		.step          =  1,
		.default_value =  0x00000000,
		.flags         =  0,
	},
	{	.id            =  F82EB10A02CBD4cc081D849D39629049B,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "MOTION STATUS",
		.minimum       =  0,
		.maximum       =  1,
		.step          =  1,
		.default_value =  0,
		.flags         =  0,
	},
	{	.id            =  F23AEF06C35E84e268F8348DE745D6E9D,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "MOTION SENSITIVITY (TH.L)",
		.minimum       =  0,
		.maximum       =  127,
		.step          =  1,
		.default_value =  64,
		.flags         =  0,
	},
	{	.id            =  F00654B9494C14259AB67D0B82BB2B4F4,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "MOTION SENSITIVITY (TH.H)",
		.minimum       =  0,
		.maximum       =  127,
		.step          =  1,
		.default_value =  64,
		.flags         =  0,
	},
	{	.id            =  FA15402C642F34d2cAC2720CC357D2D38,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "MOTION MASK (CX)",
		.minimum       =  0x00000000,
		.maximum       =  0x3FFFFFFF,
		.step          =  1,
		.default_value =  0x00000000,
		.flags         =  0,
	},
	{	.id            =  FB399C846A91D403eA55BF95B2B5BAA5C,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "MOTION MASK (CY)",
		.minimum       =  0x00000000,
		.maximum       =  0x00FFFFFF,
		.step          =  1,
		.default_value =  0x00000000,
		.flags         =  0,
	},
	{	.id            =  FFD08F80E390E49fcB67A2308CB62684C,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "OSD POS (X)",
		.minimum       =  0,
		.maximum       =  255,
		.step          =  1,
		.default_value =  0x00000000,
		.flags         =  0,
	},
	{	.id            =  FABAFB2ADBCD8465eA4F4B681511D1E3E,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "OSD POS (Y)",
		.minimum       =  0,
		.maximum       =  255,
		.step          =  1,
		.default_value =  0x00000000,
		.flags         =  0,
	},
	{	.id            =  F0B76EDE3B1154d53872CEEDCE52A97DC,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "OSD COLOR",
		.minimum       =  0,
		.maximum       =  15,
		.step          =  1,
		.default_value =  0x00000000,
		.flags         =  0,
	},
	{	.id            =  F755BEAF2318846358DA840FAC6E9E8F7,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "OSD TEXT",
		.minimum       =  0x00000000,
		.maximum       =  0x000000FF,
		.step          =  1,
		.default_value =  0x00000000,
		.flags         =  0,
	},
	{	.id            =  V4L2_CID_GPIO_DIRECTION,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "GPIO DIRECTION",
		.minimum       =  0x00000000,
		.maximum       =  0xFFFFFFFF,
		.step          =  1,
		.default_value =  0x00000000,
		.flags         =  0,
	},
	{	.id            =  V4L2_CID_GPIO_DATA,
		.type          =  V4L2_CTRL_TYPE_INTEGER,
		.name          = "GPIO DATA",
		.minimum       =  0x00000000,
		.maximum       =  0xFFFFFFFF,
		.step          =  1,
		.default_value =  0x00000000,
		.flags         =  0,
	},
};

#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,18)

extern struct video_device * video_devdata( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4 );

static inline void * video_get_drvdata( struct video_device * p_dev ) { return p_dev->priv; }

static inline void video_set_drvdata( struct video_device * p_dev, void * F7DCDC607F3644b1591980748EA26F4D8 ) { p_dev->priv = F7DCDC607F3644b1591980748EA26F4D8; }

#endif



#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,37)

#define init_MUTEX(sem)         sema_init(sem, 1)
#define init_MUTEX_LOCKED(sem)  sema_init(sem, 0)

#endif

UINT FADD02C9C13B14f83989880EFACB8D8DC                    [ 64 ][ 4 ] = { { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 } };

UINT F3A66BD0F0BCB4afcAD006E378E671B9A                      [ 64 ][ 4 ] = { { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 } };

UINT F925442591E22492f9239C6028CE3DD94                    [ 64 ][ 4 ] = { { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 } };

UINT F42BAA55A84E847faA4D0C0565699845E                           [ 64 ][ 4 ] = { { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 } };

UINT F1D56E1ED762E4b99BB2BD370DFE317D1                     [ 64 ][ 4 ] = { { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 }, { 128, 128, 128, 128 } };

UINT FF41F97A51B484aaa8170BEE8828CFCF0                     [ 64 ] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

UINT F9CA17C2FDE5B4c94B2594B65842E7387                          [ 64 ] = { 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256, 256 };

//ULONG FC9D92723A8E44565883875F77CA4E561                   [ 64 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//peter [2011.04.12]
UINT FC9D92723A8E44565883875F77CA4E561                   [ 64 ] = { 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102, 0x102 };


UINT F5DCAF3AAB0BA4f659145B0B8C7EB74F6                    [ 64 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

UINT FB5061B6847674d5cAA4512F2524B22CA [ 64 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

UINT FB4585649D2BE488f8DAB3BE4ACEC1C0C[ 64 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

UINT F24FF8C85BBB142d68BD24A8AEE14C2A0                   [ 64 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

UINT F9245F416BCD64da6857AA7F60AC69BDC                   [ 64 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };


UINT FCF4231953179448dA85C9CE2854BDAB0                            [ 64 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

UINT FAB3E37A5903246ce815D399EE1B19200                            [ 64 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

UINT F9C0567FC340549ddAF206705D1028554                            [ 64 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

CHAR  FE2D83A80F4E94ef188507C175ABF3840                             [ 64 ][ 64 + 1 ] = { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" };


UINT g_n_gpio_direction                               [ 64 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

UINT g_n_gpio_data                                    [ 64 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

F42A18AF66EFF459eA332CA253FFF8A65 * g_pDevice[ 128 ] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

							   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

							   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

							   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

							   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

							   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

							   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,

							   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };


//below is from kernel 3.2
//////////////////////////////////////////////////////////////////////////////////////////////////////
BOOLEAN F6B9E557A4BA24ffd926B820B836289C8_100NS( ULONG F6B9E557A4BA24ffd926B820B836289C8 )
{
//#ifdef AME_MZ0380
#if defined(AME_MZ0380) || defined(AME_PL330B) || defined(AME_PL330A)
	//do not use busy delay
	
	schedule_timeout_interruptible( msecs_to_jiffies( F6B9E557A4BA24ffd926B820B836289C8/10000 ) );

#else

	ndelay( F6B9E557A4BA24ffd926B820B836289C8 * 100 );

#endif

	return TRUE;
}
void RtlFillMemory(BYTE* pe , int size, BYTE set_value)
{
	memset(pe, set_value, size);
}

void RtlZeroMemory(BYTE* pe , int size)
{
	memset(pe, 0x00, size);
}

void RtlCopyMemory( BYTE* pe, BYTE* po, int nFileSize )
{
	memcpy(pe, po, nFileSize);
}


// ##############################################################################################################################################################################
//

static int Init_pci_driver( void * FD51B2B4E0CAC4359A9EFA429A9E16157 )
{
	int ret = 0;

#ifdef AME_PL330A

	ret = usb_register( FD51B2B4E0CAC4359A9EFA429A9E16157 );

	if( ret != 0 ) { 
		
		F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "Init_pci_driver() - usb_register() - [FAIL]\n" ); 
		
		return ret; 
	}
#else

	ret = pci_register_driver( FD51B2B4E0CAC4359A9EFA429A9E16157 );

	if( ret != 0 ) { 
		
		F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "Init_pci_driver() - pci_register_driver() - [FAIL]\n" ); 
		
		return ret; 
	}
#endif

}
BYTE* colorbar_image_1920_1080 = NULL;
BYTE* colorbar_image_1280_720 = NULL;
BYTE* colorbar_image_720_576 = NULL;

//must be universal since it will be used in F974CC188B92849b9A9A52461E68698A2, at that time, nothing exist
struct semaphore      m_pFile_Stream_ControlSemaphore;					
ULONG		           m_nDummy7[8];//for semaphore access????? do not remove
struct semaphore       m_sComponentAccessSemaphore;					// shawn 2010.07.26
ULONG		           m_nDummy8[8];//for semaphore access????? do not remove
wait_queue_head_t	  m_wait_queue_component;
BYTE m_component_ready = 1;

BYTE BLACK_LINE_TW6816_768[ 768 * 2 ];

//static pthread_mutex_t	g_sdlSurfaceLock = PTHREAD_MUTEX_INITIALIZER;

const char colorbar[8][3] = { {235, 128, 128},//white
								{210, 16, 146}, //yellow
								{170, 166, 16}, //cyan
								{145, 54, 34}, //green
								{107, 202, 221}, //magenta
								{82, 90, 240}, //red
								{41, 240, 110}, //blue
								{16, 128, 128} //black
							  };

#define DRIVER_VERSION 457

static int __init FAF86DD63BEE049469391C62866E9E0BB( void )
{	
	int ret = 0;

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "FAF86DD63BEE049469391C62866E9E0BB(), 1.1.0.101.%d, 2017.03.06 PAL\n", DRIVER_VERSION );

#ifdef MEDICAL
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "MEDICAL\n" );
#endif

#ifdef FFMPEG
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "FFMPEG\n" );
#endif

#ifdef FFMPEG_TW5864
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "FFMPEG_TW5864\n" );
#endif

#ifdef AUDIO_STAND_ALONE
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "AUDIO_STAND_ALONE\n" );
#endif

#ifdef AME_SC300_SC330_SC310_SC3B0
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "AME_SC300_SC330_SC310_SC3B0\n" );
#endif

#ifdef CUEBI_WEBRTC
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "CUEBI_WEBRTC\n" );
#endif

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "sizeof(ULONG)(0x%x)\n", sizeof(ULONG) );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "sizeof(SHORT)(0x%x)\n", sizeof(SHORT) );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "sizeof(LONG)(0x%x)\n", sizeof(LONG) );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "sizeof(LONGLONG)(0x%x)\n", sizeof(LONGLONG) );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "sizeof(UINT)(0x%x)\n", sizeof(UINT) );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "sizeof(WORD)(0x%x)\n", sizeof(WORD) );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "sizeof(DWORD)(0x%x)\n", sizeof(DWORD) );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "sizeof(DWORD*)(0x%x)\n", sizeof(DWORD*) );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "sizeof(UINT*)(0x%x)\n", sizeof(UINT*) );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "sizeof(LONG*)(0x%x)\n", sizeof(LONG*) );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "sizeof(BYTE*)(0x%x)\n", sizeof(BYTE*) );

	init_MUTEX( &m_pFile_Stream_ControlSemaphore );
	init_MUTEX( &m_sComponentAccessSemaphore );
	init_waitqueue_head( &m_wait_queue_component );

//	ippStaticInit();

#ifdef AME_FH8735
	//ret = pci_register_driver( &linuxv4l2_pci_driver8735 );

	struct task_struct * init_thread = kthread_run( Init_pci_driver, &linuxv4l2_pci_driver8735, "Init_pci_driver" );

#endif

#ifdef AME_SA7160
	//ret = pci_register_driver( &linuxv4l2_pci_driver7160 );
	
	struct task_struct * init_thread = kthread_run( Init_pci_driver, &linuxv4l2_pci_driver7160, "Init_pci_driver" );

#endif

#ifdef AME_MZ0380

	struct task_struct * init_thread = kthread_run( Init_pci_driver, &linuxv4l2_pci_driver0380, "Init_pci_driver" );

#endif

#ifdef AME_PL330B

	struct task_struct * init_thread = kthread_run( Init_pci_driver, &linuxv4l2_pci_driver330b, "Init_pci_driver" );

#endif

#ifdef AME_PL330A

	struct task_struct * init_thread = kthread_run( Init_pci_driver, &linuxv4l2_usb_driver330a, "Init_pci_driver" );

#endif

//create YV12 colorbar
#if defined(AME_PL330B) || defined(AME_MZ0380) || defined(AME_FH8735)

	colorbar_image_1920_1080 = vmalloc( (1920*1080*12) >> 3);
	colorbar_image_1280_720 = vmalloc( (1280*720*12) >> 3); 
	colorbar_image_720_576 = vmalloc( (720*576*12) >> 3);

	if( colorbar_image_1920_1080 && colorbar_image_1280_720 && colorbar_image_720_576)
	{
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "create YV12 colorbar success\n" );
		
		//draw colorbar
		int pattern = 0;

		for( pattern=0; pattern < 3; pattern ++)
		{
			int line = 0;
			int color_segment = 0;
			int pixel = 0;
			int width = 0;
			int height = 0;
			BYTE* prt = NULL;

			if( pattern == 0)
			{
				width = 1920;
				height = 1080;
				prt = colorbar_image_1920_1080;
			}
			else if( pattern == 1)
			{
				width = 1280;
				height = 720;
				prt = colorbar_image_1280_720;
			}
			else
			{
				width = 720;
				height = 576;
				prt = colorbar_image_720_576;
			}

			//create Y
			for( line = 0; line < height; line ++)
			{
				for( color_segment = 0; color_segment < 8; color_segment++)
				{
					for( pixel = 0; pixel < width/8; pixel++)
					{
						//fprintf( fp_w,"%x", colorbar[color_segment][0] );
						//fputc( colorbar[color_segment][0], fp_w );
						*prt++ = colorbar[color_segment][0];
					}
				}
			}
		
			//create U
			for( line = 0; line < height/2; line ++)
			{
				for( color_segment = 0; color_segment < 8; color_segment++)
				{
					for( pixel = 0; pixel < width/16; pixel++)
					{
						//fprintf( fp_w,"%x", colorbar[color_segment][1] );
						//fputc( colorbar[color_segment][1], fp_w );
						*prt++ = colorbar[color_segment][1];
					}
				}
			}

			//create V
			for( line = 0; line < height/2; line ++)
			{
				for( color_segment = 0; color_segment < 8; color_segment++)
				{
					for( pixel = 0; pixel < width/16; pixel++)
					{
						//fprintf( fp_w,"%x", colorbar[color_segment][2] );
						//fputc( colorbar[color_segment][2], fp_w );
						*prt++ = colorbar[color_segment][2];
					}
				}
			}
		}
	}
	else
	{
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "create YV12 colorbar failed!!!\n" );
	}

#endif

	//create black line
	{
		BYTE* color_array = BLACK_LINE_TW6816_768;
		int i = 0;

		for(i = 0; i < 768 * 2; i++)
		{
			if( (i % 4 == 0) || (i % 4 == 2) )
			{
				*(color_array + i) = 16;
			}
			if( i % 4 == 1 )
			{
				*(color_array + i) = 128;
			}

			if( i % 4 == 3)
			{
				*(color_array + i) = 128;
			}
		}
	}

	//if( ret != 0 ) { 
	if( IS_ERR( init_thread ) ) {
		
		F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "FAF86DD63BEE049469391C62866E9E0BB() - kthread_run() - [FAIL]\n" ); 
		
		return ret; 
	}
	return 0;
}

static void __exit FFEAB2309379F4a9fA0EB36080145582B( void )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FFEAB2309379F4a9fA0EB36080145582B()\n" );

#ifdef AME_FH8735
	pci_unregister_driver( &linuxv4l2_pci_driver8735 );
#endif

#ifdef AME_SA7160
	pci_unregister_driver( &linuxv4l2_pci_driver7160 );
#endif

#ifdef AME_MZ0380
	pci_unregister_driver( &linuxv4l2_pci_driver0380 );
#endif

#ifdef AME_PL330B
	pci_unregister_driver( &linuxv4l2_pci_driver330b );
#endif

#ifdef AME_PL330A
	usb_deregister( &linuxv4l2_usb_driver330a );
#endif

	if(colorbar_image_1920_1080)
	{
		vfree(colorbar_image_1920_1080);

		colorbar_image_1920_1080 = NULL;
	}
	if(colorbar_image_1280_720)
	{
		vfree(colorbar_image_1280_720);

		colorbar_image_1280_720 = NULL;
	}
	if(colorbar_image_720_576)
	{
		vfree(colorbar_image_720_576);

		colorbar_image_720_576 = NULL;
	}
}

// ##############################################################################################################################################################################
// 
static ULONG F6565D1746098454893ED99FB59FED8CF         = 0x00000000;
static ULONG FCA4AB238CA5A417aA5CAB676739AD5C1         = 0x00000000;
static ULONG FF5B984F968D94ac9A59072C8F0E8BA8F         = 0x00000000;
static ULONG FDD11F4D2F288473fB7F4E66ED0258C5D = 0x00000000;
static ULONG FE2971C08ECA24a0b829472D1A1C1FCFC = 0x00000000;

#ifdef AME_PL330A
static int F0251D2D952114606BEF15BFE3B8A3F85( struct usb_interface *intf, const struct usb_device_id* p_usb_device_id )
#else
static int __devinit F0251D2D952114606BEF15BFE3B8A3F85( struct pci_dev * F74930C6A858F43258B265F9ABB2DA5BC, const struct pci_device_id * F4085ACF1E4454fdb939A7943E6BC5888 )
#endif
{
	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = NULL;

	USHORT F5B7AE88070A649078E1EC526AC07E94A = 0x0000;

	USHORT F49A4A3E130C344fdBCAA9C82CDD98055 = 0x0000;

	USHORT F2D022FE82B144b41BC844A149F53AA1C = 0x0000;

	USHORT F7ABB2B6163A5467eAC235EF2347FF3E6 = 0x0000;

	CHAR psz[ 256 ];

	int ret = 0;

	int i = 0;

	#ifndef AME_PL330A
	pci_read_config_word( F74930C6A858F43258B265F9ABB2DA5BC, 0x00, &F5B7AE88070A649078E1EC526AC07E94A );

	pci_read_config_word( F74930C6A858F43258B265F9ABB2DA5BC, 0x02, &F49A4A3E130C344fdBCAA9C82CDD98055 );

	pci_read_config_word( F74930C6A858F43258B265F9ABB2DA5BC, 0x2C, &F2D022FE82B144b41BC844A149F53AA1C );

	pci_read_config_word( F74930C6A858F43258B265F9ABB2DA5BC, 0x2E, &F7ABB2B6163A5467eAC235EF2347FF3E6 );

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85( %02X:%06X:%04X:%04X:%04X:%04X (%04X:%04X:%04X:%04X) )\n", (int)(F6565D1746098454893ED99FB59FED8CF), F74930C6A858F43258B265F9ABB2DA5BC->bus->number, F74930C6A858F43258B265F9ABB2DA5BC->class, F74930C6A858F43258B265F9ABB2DA5BC->vendor, F74930C6A858F43258B265F9ABB2DA5BC->device, F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor, F74930C6A858F43258B265F9ABB2DA5BC->subsystem_device, F5B7AE88070A649078E1EC526AC07E94A, F49A4A3E130C344fdBCAA9C82CDD98055, F2D022FE82B144b41BC844A149F53AA1C, F7ABB2B6163A5467eAC235EF2347FF3E6 );
	#endif	

	//
	// 
	pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(kmalloc( sizeof(struct F42A18AF66EFF459eA332CA253FFF8A65), GFP_KERNEL ));

	if( pDevice == NULL ) {

		F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - kmalloc() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

		ret = -ENOMEM;

		goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
	}
	else { 

		#ifndef AME_PL330A
		pci_set_drvdata( F74930C6A858F43258B265F9ABB2DA5BC, (PVOID)(pDevice) );

		memset( pDevice, 0, sizeof(struct F42A18AF66EFF459eA332CA253FFF8A65) );

		pci_read_config_dword( F74930C6A858F43258B265F9ABB2DA5BC, 0x10, &pDevice->m_nKsDeviceAddress );

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - w_bar0(0x%x)\n", (int)(F6565D1746098454893ED99FB59FED8CF), pDevice->m_nKsDeviceAddress );

		tasklet_init( &(pDevice->FB12FC3D237104676BD149F25E3D08571), FF6E02BBAFF114b048DA9EFBDC06CA997_EX, (unsigned long)(pDevice) );

		#else
		
		memset( pDevice, 0, sizeof(struct F42A18AF66EFF459eA332CA253FFF8A65) );
		
		#endif

		spin_lock_init( &(pDevice->FFCB115F553804bc7A991C2C6B50FDDFC) );

// peter [2011.05.09]

		//init_MUTEX( &(pDevice->m_sSGSemaphore) );

		mutex_init( &(pDevice->m_sSGSemaphore) ) ;

		init_MUTEX( &(pDevice->B170D6CC53FA433DB899522A0B0325FC) ); 

		init_MUTEX( &(pDevice->m_MZ0380AccessSemaphore) ); 

		init_MUTEX( &(pDevice->FB35780EBCC0F4f1c869121F03566FA3B) );

		init_MUTEX( &(pDevice->m_pControlSemaphore) );

		#ifndef AME_PL330A

		pDevice->F9D9594A095F0463193B7588374CF8310 = F74930C6A858F43258B265F9ABB2DA5BC;

		pDevice->FF362AA37F7D046bf90568AC1600626D9 = F74930C6A858F43258B265F9ABB2DA5BC->bus->number;

		#else
		
		pDevice->F9D9594A095F0463193B7588374CF8310 = interface_to_usbdev(intf);

		#endif

		pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE = F6565D1746098454893ED99FB59FED8CF;

		pDevice->F303D369E48FE4a678735A832DB68BC28 = 0x00000000;

		pDevice->F987A77560CED4a97977C18B30809471E = 0x00000000;

		pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0x00000000;

		pDevice->F85D95817054C4a10BA000A8CC5704576 = 0x00000000;

		pDevice->F69679D3D75724cd281AAC93AE8DFDF35 = 0x00000000;

		pDevice->F9D066B94377B4a9aB14E37D504955651 = 0x00000000;

		pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = FALSE;

		pDevice->FF049D1BE4BF24dd794D611B48835D184 = 0x00000000;

		pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 = 0x00000000;

		pDevice->m_nCustomGpioDirectionProperty = 0;

		pDevice->m_nCustomGpioDataProperty = 0;
		
		pDevice->m_nCustomGpioSupportProperty = 0;

		pDevice->m_nCustomSoftwareWatchdogDurationProperty = 180; // shawn 2010.08.11

		pDevice->m_nCustomAnalogVideoScaleOutputProperty = 1; // shawn 2010.10.04

		pDevice->m_nAnalogCopyProtMacrovisionProperty = 0; // shawn 2010.10.19

		pDevice->m_nAnalogVideoDecoderStatusProperty = 0; // shawn 2010.10.19

		pDevice->m_nAnalogCrossbarVideoInputProperty = 4; // shawn 2010.10.25

		#ifndef AME_PL330A
		if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1131 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x7160 )
		{
			if( (F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0xFF) == 0x1A ||
				(F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0xFF) == 0x18 ||
				(F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0xFF) == 0x16 ||
				(F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0xFF) == 0x0D ||
				(F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0xFF) == 0x0A ||
				(F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0xFF) == 0x13 )
			{
				pDevice->m_nAnalogCrossbarVideoInputProperty = 0; // shawn 2010.10.25
			}
			if( (F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0xFF) == 0x04 )//Euresys SC512L-DVI
			{
				pDevice->m_nAnalogCrossbarVideoInputProperty = 1;
			}
			if( (F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0xFF) == 0x17 )//SC512L-DVI
			{
				pDevice->m_nAnalogCrossbarVideoInputProperty = 1;
			}

		}
		if( (F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x0907 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0100) ||

			(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0370) ||
			
			(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0380) )
		{
			if( (F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0xFF) == 0x5A ||  // SC550N4 HDMI
			
				 (F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0xFF) == 0xCA ) { // SC5C0N4 HDMI

				pDevice->m_nAnalogCrossbarVideoInputProperty = 0;
			}
			else if( (F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0xFF) == 0x54 ||  // SC550N1 MC SDI
			
					 (F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0xFF) == 0x5B ||  // SC550N4 SDI

					 (F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0xFF) == 0xC4 ||  // SC5C0N1 MC SDI
			
					 (F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0xFF) == 0xCB ) { // SC5C0N4 SDI

				pDevice->m_nAnalogCrossbarVideoInputProperty = 4;
			}
			else
			{
				pDevice->m_nAnalogCrossbarVideoInputProperty = 1; // shawn 2010.10.25
			}
		}

		if( F74930C6A858F43258B265F9ABB2DA5BC->vendor ==  0x1797 )
		{
			pDevice->m_nAnalogCrossbarVideoInputProperty = 0; // shawn 2010.10.25
		}
		#endif

		//put PL330B select inside hwinit, only there ID is set
		//put FH8735 select inside hwinit, only there ID is set

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "m_nAnalogCrossbarVideoInputProperty(0d%d)\n",pDevice->m_nAnalogCrossbarVideoInputProperty );

		pDevice->m_nAnalogCrossbarAudioInputProperty = 0;//compatible to previous, do not change

//		pDevice->m_nAnalogCrossbarVideoInputProperty = 6; // shawn 2010.10.25

//		pDevice->m_nAnalogCrossbarVideoInputProperty = 0; // shawn 2010.10.25

//HDMI 0
//DVI.DIGITAL (TMDS.A) 1
//COMPONENT 2
//DVI.ANALOG 3
//SDI 4
//COMPOSITE 5
//S 6
		pDevice->m_pCustomSystemConfigProperty = NULL; // shawn 2010.10.25


		pDevice->m_nCustomAnalogVideoFrameRateProperty = 0;

		pDevice->m_nCustomAnalogVideoInterleavedProperty = 1;//for analog signal

		pDevice->m_nCustomSoftwareWatchdogResetProperty = 0;

		pDevice->m_nAnalogCopyProtMacrovisionEnableProperty = 1;

		pDevice->m_nHVScaleFactor = 0x00010001;

		pDevice->m_nH264HVScaleFactor = 0x00000202;

		pDevice->m_nCustomAnalogVideoVgaHActiveProperty = 640;

		pDevice->m_nCustomAnalogVideoVgaAspectRatioProperty =  0;

		pDevice->m_nCustomCompanyVision4CEProperty = 0;

		pDevice->m_nCustomAnalogVideoColorRangeProperty = 0x00010000;

		pDevice->m_MST3367_bank = 0xFF;//invalid value

		pDevice->C4E7BABA3C164ABA99E460C0B8165385 = 0;

		pDevice->m_nCustomCompanyIvsProperty = 0;

		pDevice->m_nCustomSpecialCameraInputProperty = 0;

		pDevice->m_nCustomAnalogVideoVbiLinesEnableProperty = 0;
		
		pDevice->m_nCustomAnalogVideoVbiLinesProperty = 0;

		pDevice->m_No_Signal_black_pattern_property = 0;

		pDevice->m_No_Signal_yuv_pattern_property = 0;

		pDevice->m_No_Signal_no_output_property = 0;

		pDevice->m_nCustomHDMI_Mixer = 0;

		pDevice->m_nCustomAnalogVideoSplitProperty = 1;

		pDevice->m_nCustomAnalogAudioVolumeProperty = 128;

		pDevice->m_nCustomAnalogAudioDirectSoundPatchProperty = 0;

		pDevice->D8B74534E3F446EC9637B41BE21BE297[ 0 ] = 0x00;
		pDevice->D8B74534E3F446EC9637B41BE21BE297[ 1 ] = 0x00;
		pDevice->D8B74534E3F446EC9637B41BE21BE297[ 2 ] = 0x00;
		pDevice->D8B74534E3F446EC9637B41BE21BE297[ 3 ] = 0x00;

		for( i = 0 ; i < 8 ; i++ ) {

			pDevice->m_CX2581_video_buffer_count[ i ] = 0;
		}

		pDevice->m_ReadyToStopControlThread = 0;

		pDevice->m_ReadyToStopVideoLossThread = 0;

		pDevice->m_ReadyToStopAudioLossThread = 0;

		for( i = 0 ; i < F91863BEB45D34624A724F2D29823D9E3 ; i++ ) {

			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ] = NULL;

			pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ] = NULL;

			pDevice->FCB465449C23D4d298E73233A42203CD6[ i ] = NULL;

			//pDevice->m_pVideo[ i ] = NULL;

			pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ] = NULL;

			pDevice->FA12AAA3D283C4cf0BF02ACD3957899B0[ i ] = 0x00000000;

			pDevice->F13A906F1479D4245B9F207A09C70BCE6[ i ] = 0x00000000;
		}

		for( i = 0 ; i < F91863BEB45D34624A724F2D29823D9E3 ; i++ ) {

			int k = 0;
			for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
			{
				pDevice->m_pVideo[ i ][ k ] = NULL;

				pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ i ][ k ] = NULL;
			}
		
		}

		for( i = 0 ; i < F91863BEB45D34624A724F2D29823D9E3 ; i++ ) {

			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ] = NULL;

			pDevice->FB1A1EF5BAA2243f4833747083423997C[ i ] = NULL;

			pDevice->FF5F61842BBC24b458D103EF08357C4CD[ i ] = NULL;

			//pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ i ] = NULL;

			pDevice->FCD654CA89AC34227BE068F80A85776C6[ i ] = NULL;

			pDevice->FDB274CD437614fec94859748411FE56A[ i ] = 0x00000000;

			pDevice->FC1FFB6B00E034c0993BE8A598C730AA4[ i ] = 0x00000000;
		}
		for( i = 0 ; i < F933F2ACDBCE3443093DDB4DCB3597BDE ; i++ ) {

			pDevice->F66FD293166B14f93A084AE0E6BD0F196[ i ] = 0;

			pDevice->F03D1DD650AC64c28B04687338F970D0E[ i ] = 0;

			pDevice->FF3B74CCEF832433c856908721A61A034[ i ] = 0;

			pDevice->F41F19BDAA144449fA254B8E3282D1425[ i ] = NULL;

			pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i ] = 0x00000000; //
		}
		for( i = 0 ; i < F67472E4DF55F4f65AAB4E0860EFF1AD5 ; i++ ) {

			pDevice->F57270173C138422aA83C0FF58A259F4D[ i ] = 0;

			pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ i ] = NULL;
		}

		//
		// 
		pDevice->F4C79718693FD4bd39C552E932C7E4FB5 = 0x00000000; 

		pDevice->FD314ADAD9404496b842EBFC396E875CB = LINUXV4L2_DEFAULT_VIDEO_STANDARD;

		pDevice->F64E8BDD78F2944b8B21DE5BF5CF2A021 = 0x00000000;

		pDevice->m_IRQ_ready = 1; //0 is got IRQ

		pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] = 100000; //100000;//max

		pDevice->m_pl330b_combine_4_chip = 0;

		pDevice->m_nCustomAnalogVideoSubEncoderEnableProperty = 0;

		pDevice->m_size_not_match_no_signal_blue_pattern = 0;

		pDevice->m_timeperframe_denominator = 0;

		pDevice->m_timeperframe_numerator = 0;

		pDevice->m_Invert_UV = 0;
	}

	#ifndef AME_PL330A

	ret = pci_enable_device( F74930C6A858F43258B265F9ABB2DA5BC );

	if( ret != 0 ) {

		F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - pci_enable_device() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

		goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
	}

	pDevice->CFG0 = 0x00000000; pci_read_config_dword( F74930C6A858F43258B265F9ABB2DA5BC, 0x00, &(pDevice->CFG0) );

	pDevice->CFGB = 0x00000000; pci_read_config_dword( F74930C6A858F43258B265F9ABB2DA5BC, 0x2C, &(pDevice->CFGB) );

	pDevice->CFG2 = 0x00000000; pci_read_config_dword( F74930C6A858F43258B265F9ABB2DA5BC, 0x08, &(pDevice->CFG2) );

	pDevice->idVendor      = (USHORT)((pDevice->CFG0 & 0x0000FFFF) >>  0);
	pDevice->idProduct     = (USHORT)((pDevice->CFG0 & 0xFFFF0000) >> 16);
	pDevice->bcdDevice     = (USHORT)((pDevice->CFGB & 0xFFFF0000) >> 16);
	pDevice->iManufacturer = (  BYTE)((pDevice->CFGB & 0x000000FF) >>  0);
	pDevice->iProduct      = (  BYTE)((pDevice->CFGB & 0x0000FF00) >>  8);
	pDevice->iSerialNumber = (  BYTE)((pDevice->CFG2 & 0x000000FF) >>  0);

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "    idVendor           = %04X\n", pDevice->idVendor );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "    idProduct          = %04X\n", pDevice->idProduct );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "    bcdDevice          = %04X\n", pDevice->bcdDevice );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "    iManufacturer      = %02X\n", pDevice->iManufacturer );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "    iProduct           = %02X\n", pDevice->iProduct );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "    iSerialNumber      = %02X\n", pDevice->iSerialNumber );


	pci_set_master( F74930C6A858F43258B265F9ABB2DA5BC );

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,4,0)

	ret = pci_set_dma_mask( F74930C6A858F43258B265F9ABB2DA5BC, DMA_32BIT_MASK );

	if( ret != 0 ) {

		F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - pci_dma_supported() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

		goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
	}
#else
	ret = pci_dma_supported( F74930C6A858F43258B265F9ABB2DA5BC, DMA_32BIT_MASK );

	if( ret == 0 ) {

		F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - pci_dma_supported() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

		goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
	}
#endif
	ret = pci_request_regions( F74930C6A858F43258B265F9ABB2DA5BC, "LINUXV4L2" );

	if( ret != 0 ) {

		F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - pci_request_regions() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

		goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
	}

	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6801 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = F648D519438F246f6926E9C5A8F1AB132; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6802 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = F999D9A639D7D483c832149A449DEC4A2; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] =                     1920 * 4 * 1; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6804 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = F648D519438F246f6926E9C5A8F1AB132; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6805 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = F999D9A639D7D483c832149A449DEC4A2; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] =                     1920 * 4 * 1; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6810 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = F648D519438F246f6926E9C5A8F1AB132; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6811 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = F648D519438F246f6926E9C5A8F1AB132; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6812 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = F648D519438F246f6926E9C5A8F1AB132; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6813 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = F648D519438F246f6926E9C5A8F1AB132; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6814 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = F999D9A639D7D483c832149A449DEC4A2; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] =                     1920 * 4 * 1; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6815 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = F999D9A639D7D483c832149A449DEC4A2; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] =                     1920 * 4 * 1; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6816 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = F999D9A639D7D483c832149A449DEC4A2; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] =                     1920 * 4 * 1; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6817 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = F999D9A639D7D483c832149A449DEC4A2; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] =                     1920 * 4 * 1; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x14F1 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x8210 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = F73ABAF3DA1E74460B62EE54E4669F354; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] = F2D03C174E8CF4eea8F3ECFCF8A103118; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =                     1920 * 4 * 4; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1131 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x7160 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = cc178591b6d74b57bc680e9715715b23; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] = edf64860fb974a6aa7dfe1b4557f75c8; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =	e86cad15f8e349d3868f1160049ff548; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =								0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }

	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1131 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x7160 )
	{
		if((F74930C6A858F43258B265F9ABB2DA5BC->subsystem_vendor & 0x10) == 0x10)
		{
			pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] =	 4096 *  8 * 4;
		}
	}

	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x9413 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6010 ) { pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = F3A2AB9276F634b32A042CD3A1D8E5F04; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] = F3A814C2DAC584c07B68E5A6B72DF27EF; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] = FAC43334A7F814c21A0D09BF3FC1D934C; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] = F0F2939CCDD0D402aAB4EF1940D0A8985; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1Af2 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0xA001 ) 
	{ 
		pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = PL330B_MAX_VIDEO_DMA_BUFFER_SIZE; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] = PL330B_MAX_AUDIO_DMA_BUFFER_SIZE; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] = PL330B_MAX_VIDEO_DMA_BUFFER_SIZE; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] =                                0; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = 0; pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0; 
		
		#ifdef NEVRON
		pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = 0;
		#endif
	}
	
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x5864 ) 
	{	
		pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = a5ba11e017e349568504a4ba37df8b79; pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] = a5ba11e017e349568504a4ba37df8b79; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] = a5ba11e017e349568504a4ba37df8b79; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] = a5ba11e017e349568504a4ba37df8b79; 
		pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = ba98f190f54d44ba894e79c3bc107b50; 
		pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = a5ba11e017e349568504a4ba37df8b79; pDevice->FF3B74CCEF832433c856908721A61A034[ 6 ] = a5ba11e017e349568504a4ba37df8b79; pDevice->FF3B74CCEF832433c856908721A61A034[ 7 ] = a5ba11e017e349568504a4ba37df8b79; pDevice->FF3B74CCEF832433c856908721A61A034[ 8 ] = a5ba11e017e349568504a4ba37df8b79;

		#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,24)
		pDevice->FF3B74CCEF832433c856908721A61A034[ 9 ] = a5ba11e017e349568504a4ba37df8b79; //temp buffer to separate uvuvuv to uuu vvv, ch1
		pDevice->FF3B74CCEF832433c856908721A61A034[ 10 ] = a5ba11e017e349568504a4ba37df8b79; //ch2
		pDevice->FF3B74CCEF832433c856908721A61A034[ 11 ] = a5ba11e017e349568504a4ba37df8b79; //ch3
		pDevice->FF3B74CCEF832433c856908721A61A034[ 12 ] = a5ba11e017e349568504a4ba37df8b79; //ch4

		pDevice->FF3B74CCEF832433c856908721A61A034[ 13 ] = a5ba11e017e349568504a4ba37df8b79; //temp buffer for H264
		#endif
	}

//peter[2011.06.29]
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x3086 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0101 )
	{ 
		pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = c74c55fc490345ba9750570701c84599; 
		pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] = a7d5606420be4603a64a664b3e793889; pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] = a7d5606420be4603a64a664b3e793889; pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] = a7d5606420be4603a64a664b3e793889; pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = c9010eea9f744361b49021b2a765f8b5; 
		pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = c74c55fc490345ba9750570701c84599;
	}
	BOOL is_sc550_product = FALSE;

	if( (F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x0907 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0100) ||

		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0370) ||
			
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0380) )
	{

		if( F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0370 ) {

			is_sc550_product = TRUE;
		}
		
		if( ((pDevice->iProduct & 0x0F) == 0x02 && (pDevice->iManufacturer & 0x0F) == 0x0A) || // 960H & D1
			
			((pDevice->iProduct & 0x0F) == 0x03 && (pDevice->iManufacturer & 0x0F) == 0x0A) ){ // 960H & D1
			
			//buffer 0~7 preview, buffer 8 audio, buffer 16~23 main H264
			pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE * 4 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE * 4 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE * 4 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE * 4 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE * 4 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE * 4 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 6 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE * 4 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4;
			pDevice->FF3B74CCEF832433c856908721A61A034[ 7 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE * 4 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4;

			pDevice->FF3B74CCEF832433c856908721A61A034[ 8 ] = MZ0380_MAX_AUDIO_SD_DMA_BUFFER_SIZE;

			pDevice->FF3B74CCEF832433c856908721A61A034[ 16 ] = (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4;
			pDevice->FF3B74CCEF832433c856908721A61A034[ 17 ] = (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4;
			pDevice->FF3B74CCEF832433c856908721A61A034[ 18 ] = (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4;
			pDevice->FF3B74CCEF832433c856908721A61A034[ 19 ] = (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4;
			pDevice->FF3B74CCEF832433c856908721A61A034[ 20 ] = (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4;
			pDevice->FF3B74CCEF832433c856908721A61A034[ 21 ] = (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4;
			pDevice->FF3B74CCEF832433c856908721A61A034[ 22 ] = (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4;
			pDevice->FF3B74CCEF832433c856908721A61A034[ 23 ] = (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4;

		}
		else if( ((pDevice->iProduct & 0x0F) == 0x02 && (pDevice->iManufacturer & 0x0F) == 0x0C) || // 960H & D1
			
				 ((pDevice->iProduct & 0x0F) == 0x03 && (pDevice->iManufacturer & 0x0F) == 0x0B) ){ // 960H & D1


			//buffer 0~7 preview, buffer 8 audio, buffer 16~23 main H264
			pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE * 4 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE * 4 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE * 4 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE * 4 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4; 

			pDevice->FF3B74CCEF832433c856908721A61A034[ 8 ] = MZ0380_MAX_AUDIO_SD_DMA_BUFFER_SIZE;

			pDevice->FF3B74CCEF832433c856908721A61A034[ 16 ] = (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4;
			pDevice->FF3B74CCEF832433c856908721A61A034[ 17 ] = (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4;
			pDevice->FF3B74CCEF832433c856908721A61A034[ 18 ] = (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4;
			pDevice->FF3B74CCEF832433c856908721A61A034[ 19 ] = (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE * 4;
		}
		else {
			//buffer 0, 1, 2, 3 preview, buffer 4 audio, buffer 5,6, 7, 8 main H264, buffer 9, 10, 11, 12 sub H264
			pDevice->FF3B74CCEF832433c856908721A61A034[ 0 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_DMA_BUFFER_SIZE : MZ0380_HD_VIDEO_DMA_BUFFER_SIZE; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_DMA_BUFFER_SIZE : MZ0380_HD_VIDEO_DMA_BUFFER_SIZE; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_DMA_BUFFER_SIZE : MZ0380_HD_VIDEO_DMA_BUFFER_SIZE; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_DMA_BUFFER_SIZE : MZ0380_HD_VIDEO_DMA_BUFFER_SIZE; 

			pDevice->FF3B74CCEF832433c856908721A61A034[ 4 ] = MZ0380_MAX_AUDIO_DMA_BUFFER_SIZE; 

			pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = (is_sc550_product) ? 0 : MZ0380_HD_VIDEO_DMA_BUFFER_SIZE; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 6 ] = (is_sc550_product) ? 0 : MZ0380_HD_VIDEO_DMA_BUFFER_SIZE; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 7 ] = (is_sc550_product) ? 0 : MZ0380_HD_VIDEO_DMA_BUFFER_SIZE; 
			pDevice->FF3B74CCEF832433c856908721A61A034[ 8 ] = (is_sc550_product) ? 0 : MZ0380_HD_VIDEO_DMA_BUFFER_SIZE; 
		}
	}
	for( i = 0 ; i < F933F2ACDBCE3443093DDB4DCB3597BDE ; i++ ) {

		if( pDevice->FF3B74CCEF832433c856908721A61A034[ i ] != 0 ) {

			//pDevice->F41F19BDAA144449fA254B8E3282D1425[ i ] = pci_alloc_consistent( F74930C6A858F43258B265F9ABB2DA5BC, pDevice->FF3B74CCEF832433c856908721A61A034[ i ], &pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i ] );
			
			pDevice->F41F19BDAA144449fA254B8E3282D1425[ i ] = dma_alloc_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, pDevice->FF3B74CCEF832433c856908721A61A034[ i ], &pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i ], GFP_KERNEL);
			
			if( pDevice->F41F19BDAA144449fA254B8E3282D1425[ i ] == NULL ) {
		
				F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - pci_alloc_consistent() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );
		
				ret = -ENOMEM;
		
				goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
			}

			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() FF3B74CCEF832433c856908721A61A034[%d] (0d%d)\n", (int)(F6565D1746098454893ED99FB59FED8CF), i, pDevice->FF3B74CCEF832433c856908721A61A034[ i ] );
			#ifdef CONFIG_64BIT
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() F41F19BDAA144449fA254B8E3282D1425[%d] (llx%llx)\n", (int)(F6565D1746098454893ED99FB59FED8CF), i, pDevice->F41F19BDAA144449fA254B8E3282D1425[ i ] );
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() FA81F93DB0A8D49bdBC3753334A5D581D[%d] (llx%llx)\n", (int)(F6565D1746098454893ED99FB59FED8CF), i, pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i ] );
			#else
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() F41F19BDAA144449fA254B8E3282D1425[%d] (0x%x)\n", (int)(F6565D1746098454893ED99FB59FED8CF), i, pDevice->F41F19BDAA144449fA254B8E3282D1425[ i ] );
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() FA81F93DB0A8D49bdBC3753334A5D581D[%d] (0x%x)\n", (int)(F6565D1746098454893ED99FB59FED8CF), i, pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i ] );
			#endif
			memset( pDevice->F41F19BDAA144449fA254B8E3282D1425[ i ], 0x00, pDevice->FF3B74CCEF832433c856908721A61A034[ i ] );
		}
	}

	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1131 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x7160 )
	{
	//allocate memory for SA7160 video DMA	
		int index = 0;

		memset( pDevice->m_SA7160_video_buffer, 0x00, sizeof(ULONG*) *  SA7160_MAX_BUFFER );

		memset( pDevice->m_SA7160_video_buffer_F6F32B5439E4C42f095E08326DFA73107, 0x00, sizeof(ULONG) *  SA7160_MAX_BUFFER);

		for( index = 0; index < SA7160_MAX_BUFFER; index++ )
		{

			pDevice->m_SA7160_video_buffer[ index ] = dma_alloc_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, 1920 * 1080 * 2, &pDevice->m_SA7160_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ index ], GFP_KERNEL );

			if(pDevice->m_SA7160_video_buffer[ index ]  == NULL)
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " can not be allocated m_SA7160_video_buffer[ %d ]\n", index );

				ret = -ENOMEM;

				goto F0251D2D952114606BEF15BFE3B8A3F85_fail;

			}
			else
			{
				#ifdef CONFIG_64BIT
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " M virtual(llx%llx)\n",  pDevice->m_SA7160_video_buffer[ index ] );

				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " M physical(llx%llx)\n",  pDevice->m_SA7160_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ index ]  );
				#else
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " M virtual(0x%x)\n",  pDevice->m_SA7160_video_buffer[ index ] );
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " M physical(0x%x)\n",  pDevice->m_SA7160_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ index ]  );
				#endif
			}

		}

	}

#ifdef TW6805_64bit

	if( (F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6801) || 
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6804) || 
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6810) || 
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6811) || 
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6812) || 
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6813)  )
	{
	//allocate memory for TW6816 video DMA	
		int index = 0;

		memset( pDevice->m_TW6816_video_buffer, 0x00, sizeof(ULONG*) *  TW6816_MAX_BUFFER );

		memset( pDevice->m_TW6816_video_buffer_F6F32B5439E4C42f095E08326DFA73107, 0x00, sizeof(ULONG) *  TW6816_MAX_BUFFER);

		for( index = 0; index < TW6816_MAX_BUFFER; index++ )
		{

			pDevice->m_TW6816_video_buffer[ index ] = dma_alloc_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, 768 * 576 * 2, &pDevice->m_TW6816_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ index ], GFP_KERNEL );

			if(pDevice->m_TW6816_video_buffer[ index ]  == NULL)
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " can not be allocated m_TW6816_video_buffer[ %d ]\n", index );

				ret = -ENOMEM;

				goto F0251D2D952114606BEF15BFE3B8A3F85_fail;

			}
			else
			{
				#ifdef CONFIG_64BIT
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " M virtual(llx%llx)\n",  pDevice->m_TW6816_video_buffer[ index ] );
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " M physical(llx%llx)\n",  pDevice->m_TW6816_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ index ]  );
				#else
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " M virtual(0x%x)\n",  pDevice->m_TW6816_video_buffer[ index ] );
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " M physical(0x%x)\n",  pDevice->m_TW6816_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ index ]  );
				#endif
			}

		}

	}
#endif //TW6805_64bit

#ifdef CX2581_64bit

	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x14F1 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x8210)  
	{
	//allocate memory for CX2581 video DMA	
		int index = 0;

		int cx2581_ch = 0;

		memset( pDevice->m_CX2581_video_buffer, 0x00, sizeof(ULONG*) *  CX2581_MAX_BUFFER * 8 );

		memset( pDevice->m_CX2581_video_buffer_F6F32B5439E4C42f095E08326DFA73107, 0x00, sizeof(ULONG) *  CX2581_MAX_BUFFER * 8 );

		for( cx2581_ch = 0; cx2581_ch < 8; cx2581_ch++ )
		{
			for( index = 0; index < CX2581_MAX_BUFFER; index++ )
			{

				pDevice->m_CX2581_video_buffer[ cx2581_ch ][ index ] = dma_alloc_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, 720 * 576 * 2, &pDevice->m_CX2581_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ cx2581_ch ][ index ], GFP_KERNEL );

				if(pDevice->m_CX2581_video_buffer[ cx2581_ch ][ index ]  == NULL)
				{
					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " can not be allocated m_CX2581_video_buffer[ %d ][ %d ]\n", cx2581_ch, index );

					ret = -ENOMEM;

					goto F0251D2D952114606BEF15BFE3B8A3F85_fail;

				}
				else
				{
					#ifdef CONFIG_64BIT
					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " M virtual(llx%llx)\n",  pDevice->m_CX2581_video_buffer[ cx2581_ch ][ index ] );
					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " M physical(llx%llx)\n",  pDevice->m_CX2581_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ cx2581_ch ][ index ]  );
					#else
					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " M virtual(0x%x)\n",  pDevice->m_CX2581_video_buffer[ cx2581_ch ][ index ] );
					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " M physical(0x%x)\n",  pDevice->m_CX2581_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ cx2581_ch ][ index ]  );
					#endif
				}

			}
		}
	}
#endif //CX2581_64bit

	if( (F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6801) || 
	    (F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6802) || 
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6804) || 
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6805) || 
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6810) || 
	    (F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6811) || 
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6812) || 
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6813) || 
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6814) || 
	    (F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6815) || 
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6816) || 
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6817) || 
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x14F1 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x8210) ||
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1131 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x7160) ||
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x9413 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6010) ||
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x5864) ) { 

//if below function return 0, turn off blue tooth, Y Fi !!!!!!!!!
		pDevice->F57270173C138422aA83C0FF58A259F4D[ 0 ] = pci_resource_len( F74930C6A858F43258B265F9ABB2DA5BC, 0 );

		if( pDevice->F57270173C138422aA83C0FF58A259F4D[ 0 ] != 0 ) {

			pDevice->m_pRegBaseCommonPhysicalBuffer[ 0 ] = pci_resource_start( F74930C6A858F43258B265F9ABB2DA5BC, 0 );

			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() m_pRegBaseCommonPhysicalBuffer[ 0 ] (llx%llx)\n", (int)(F6565D1746098454893ED99FB59FED8CF), pDevice->m_pRegBaseCommonPhysicalBuffer[ 0 ] );

			pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] = ioremap_nocache( pci_resource_start( F74930C6A858F43258B265F9ABB2DA5BC, 0 ), pDevice->F57270173C138422aA83C0FF58A259F4D[ 0 ] );
		
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] (llx%llx)\n", (int)(F6565D1746098454893ED99FB59FED8CF), pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] );

			if( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] == NULL ) {
		
				F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - ioremap_nocache() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );
		
				ret = -EIO;
		
				goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
			}
		}
		else
		{
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - pci_resource_len() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );
	
			ret = -EIO;
	
			goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
		}
	}

	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x3086 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0101 ) { 

		pDevice->F57270173C138422aA83C0FF58A259F4D[ 0 ] = pci_resource_len( F74930C6A858F43258B265F9ABB2DA5BC, 0 );

		if(pDevice->F57270173C138422aA83C0FF58A259F4D[ 0 ] > fab512bee67447e5ad487ff8c9141384)
		{
			pDevice->F57270173C138422aA83C0FF58A259F4D[ 0 ] = fab512bee67447e5ad487ff8c9141384;
		}


		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() pDevice->F57270173C138422aA83C0FF58A259F4D[ 0 ](0d%d)\n", pDevice->F57270173C138422aA83C0FF58A259F4D[ 0 ] );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() addr0 (0x%x)\n", pci_resource_start( F74930C6A858F43258B265F9ABB2DA5BC, 0 ) );

		ULONG CFG10 = 0;

		pci_read_config_dword( F74930C6A858F43258B265F9ABB2DA5BC, 0x10, &CFG10 );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() CFG10 (0x%x)\n", CFG10 );


		if( pDevice->F57270173C138422aA83C0FF58A259F4D[ 0 ] != 0 ) {

			pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] = ioremap_nocache( pci_resource_start( F74930C6A858F43258B265F9ABB2DA5BC, 0 ), pDevice->F57270173C138422aA83C0FF58A259F4D[ 0 ] );
			
			if( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] == NULL ) {
			
				F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - ioremap_nocache() - [FAIL] 0\n", (int)(F6565D1746098454893ED99FB59FED8CF) );
			
				ret = -EIO;
			
				goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
			}
		}

		pDevice->F57270173C138422aA83C0FF58A259F4D[ 1 ] = pci_resource_len( F74930C6A858F43258B265F9ABB2DA5BC, 1 );

		if(pDevice->F57270173C138422aA83C0FF58A259F4D[ 1 ] > fab512bee67447e5ad487ff8c9141384)
		{
			pDevice->F57270173C138422aA83C0FF58A259F4D[ 1 ] = fab512bee67447e5ad487ff8c9141384;
		}

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() pDevice->F57270173C138422aA83C0FF58A259F4D[ 1 ](0d%d)\n", pDevice->F57270173C138422aA83C0FF58A259F4D[ 1 ] );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() addr1 (0x%x)\n", pci_resource_start( F74930C6A858F43258B265F9ABB2DA5BC, 1 ) );

		ULONG CFG14 = 0;

		pci_read_config_dword( F74930C6A858F43258B265F9ABB2DA5BC, 0x14, &CFG14 );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() CFG14 (0x%x)\n", CFG14 );

		if( pDevice->F57270173C138422aA83C0FF58A259F4D[ 1 ] != 0 ) {

			pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 1 ] = ioremap_nocache( pci_resource_start( F74930C6A858F43258B265F9ABB2DA5BC, 1 ), pDevice->F57270173C138422aA83C0FF58A259F4D[ 1 ] );
			
			if( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 1 ] == NULL ) {
			
				F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - ioremap_nocache() - [FAIL] 1\n", (int)(F6565D1746098454893ED99FB59FED8CF) );
			
				ret = -EIO;
			
				goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
			}
		}

		pDevice->F57270173C138422aA83C0FF58A259F4D[ 2 ] = pci_resource_len( F74930C6A858F43258B265F9ABB2DA5BC, 2 );

		if(pDevice->F57270173C138422aA83C0FF58A259F4D[ 2 ] > fab512bee67447e5ad487ff8c9141384)
		{
			pDevice->F57270173C138422aA83C0FF58A259F4D[ 2 ] = fab512bee67447e5ad487ff8c9141384;
		}

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() pDevice->F57270173C138422aA83C0FF58A259F4D[ 2 ](0d%d)\n", pDevice->F57270173C138422aA83C0FF58A259F4D[ 2 ] );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() addr2 (0x%x)\n", pci_resource_start( F74930C6A858F43258B265F9ABB2DA5BC, 2 ) );

		ULONG CFG18 = 0;

		pci_read_config_dword( F74930C6A858F43258B265F9ABB2DA5BC, 0x18, &CFG18 );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() CFG18 (0x%x)\n", CFG18 );

		if( pDevice->F57270173C138422aA83C0FF58A259F4D[ 2 ] != 0 ) {

			pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 2 ] = ioremap_nocache( pci_resource_start( F74930C6A858F43258B265F9ABB2DA5BC, 2 ), pDevice->F57270173C138422aA83C0FF58A259F4D[ 2 ] );
			
			if( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 2 ] == NULL ) {
			
				F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - ioremap_nocache() - [FAIL] 2\n", (int)(F6565D1746098454893ED99FB59FED8CF) );
			
				ret = -EIO;
			
				goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
			}
		}

		pDevice->F57270173C138422aA83C0FF58A259F4D[ 3 ] = pci_resource_len( F74930C6A858F43258B265F9ABB2DA5BC, 3 );

		if(pDevice->F57270173C138422aA83C0FF58A259F4D[ 3 ] > fab512bee67447e5ad487ff8c9141384)
		{
			pDevice->F57270173C138422aA83C0FF58A259F4D[ 3 ] = fab512bee67447e5ad487ff8c9141384;
		}

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() pDevice->F57270173C138422aA83C0FF58A259F4D[ 3 ](0d%d)\n", pDevice->F57270173C138422aA83C0FF58A259F4D[ 3 ] );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() addr3 (0x%x)\n", pci_resource_start( F74930C6A858F43258B265F9ABB2DA5BC, 3 ) );

		ULONG CFG1C = 0;

		pci_read_config_dword( F74930C6A858F43258B265F9ABB2DA5BC, 0x1C, &CFG1C );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() CFG1C (0x%x)\n", CFG1C );

		if( pDevice->F57270173C138422aA83C0FF58A259F4D[ 3 ] != 0 ) {

			pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 3 ] = ioremap_nocache( pci_resource_start( F74930C6A858F43258B265F9ABB2DA5BC, 3 ), pDevice->F57270173C138422aA83C0FF58A259F4D[ 3 ] );
			
			if( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 3 ] == NULL ) {
			
				F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - ioremap_nocache() - [FAIL] 3\n", (int)(F6565D1746098454893ED99FB59FED8CF) );
			
				ret = -EIO;
			
				goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
			}
		}

	}
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x3086 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0101 ) { 

		ULONG R400008 = readl( (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 1 ] + 0x400000 + 0x08) ) & 0xFFFFFFFF;
		
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "R400008(0x%x)------\n", R400008 );

		pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = TRUE;
	}

	if( (F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x0907 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0100) ||

		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0370) ||
			
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0380) )
	{
		UINT CFG10 = 0;
		UINT CFG14 = 0;
		UINT CFG18 = 0;
		UINT CFG1C = 0;
		UINT CFG20 = 0;
		UINT CFG24 = 0;

		pci_read_config_dword( F74930C6A858F43258B265F9ABB2DA5BC, 0x10, &CFG10 );
		pci_read_config_dword( F74930C6A858F43258B265F9ABB2DA5BC, 0x14, &CFG14 );
		pci_read_config_dword( F74930C6A858F43258B265F9ABB2DA5BC, 0x18, &CFG18 );
		pci_read_config_dword( F74930C6A858F43258B265F9ABB2DA5BC, 0x1C, &CFG1C );
		pci_read_config_dword( F74930C6A858F43258B265F9ABB2DA5BC, 0x20, &CFG20 );
		pci_read_config_dword( F74930C6A858F43258B265F9ABB2DA5BC, 0x24, &CFG24 );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() CFG10 (0x%x)\n", CFG10 );
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() CFG14 (0x%x)\n", CFG14 );
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() CFG18 (0x%x)\n", CFG18 );
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() CFG1C (0x%x)\n", CFG1C );
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() CFG20 (0x%x)\n", CFG20 );
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() CFG24 (0x%x)\n", CFG24 );

		pDevice->F57270173C138422aA83C0FF58A259F4D[ 0 ] = pci_resource_len( F74930C6A858F43258B265F9ABB2DA5BC, 0 );

		if( pDevice->F57270173C138422aA83C0FF58A259F4D[ 0 ] != 0 ) { //should be 33554432

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() F57270173C138422aA83C0FF58A259F4D[ 0 ] (0d%d)\n", (int)(F6565D1746098454893ED99FB59FED8CF), pDevice->F57270173C138422aA83C0FF58A259F4D[ 0 ] );

			pDevice->m_pRegBaseCommonPhysicalBuffer[ 0 ] = pci_resource_start( F74930C6A858F43258B265F9ABB2DA5BC, 0 );

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() m_pRegBaseCommonPhysicalBuffer[ 0 ] (llx%llx)\n", (int)(F6565D1746098454893ED99FB59FED8CF), pDevice->m_pRegBaseCommonPhysicalBuffer[ 0 ] );

			pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] = ioremap_nocache( pci_resource_start( F74930C6A858F43258B265F9ABB2DA5BC, 0 ), pDevice->F57270173C138422aA83C0FF58A259F4D[ 0 ] );
		
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] (llx%llx)\n", (int)(F6565D1746098454893ED99FB59FED8CF), pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] );

			if( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] == NULL ) {
		
				F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - ioremap_nocache() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );
		
				ret = -EIO;
		
				goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
			}
		}
		
		pDevice->F57270173C138422aA83C0FF58A259F4D[ 5 ] = pci_resource_len( F74930C6A858F43258B265F9ABB2DA5BC, 5 );

		if( pDevice->F57270173C138422aA83C0FF58A259F4D[ 5 ] != 0 ) {//should be 4096

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() F57270173C138422aA83C0FF58A259F4D[ 5 ] (0d%d)\n", (int)(F6565D1746098454893ED99FB59FED8CF), pDevice->F57270173C138422aA83C0FF58A259F4D[ 5 ] );

			pDevice->m_pRegBaseCommonPhysicalBuffer[ 5 ] = pci_resource_start( F74930C6A858F43258B265F9ABB2DA5BC, 5 );

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() m_pRegBaseCommonPhysicalBuffer[ 5 ] (llx%llx)\n", (int)(F6565D1746098454893ED99FB59FED8CF), pDevice->m_pRegBaseCommonPhysicalBuffer[ 5 ] );

			pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 5 ] = ioremap_nocache( pci_resource_start( F74930C6A858F43258B265F9ABB2DA5BC, 5 ), pDevice->F57270173C138422aA83C0FF58A259F4D[ 5 ] );

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() F760673FD1F8F4f22914515A9DC68C7C9[ 5 ] (llx%llx)\n", (int)(F6565D1746098454893ED99FB59FED8CF), pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 5 ] );

			if( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 5 ] == NULL ) {
		
				F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - ioremap_nocache() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );
		
				ret = -EIO;
		
				goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
			}
		}
		

	}

	//
	// 
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6801 ) { if( FALSE == F3ED26781FA0A4d69ADAA7F22BA6A4338( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6802 ) { if( FALSE == F3ED26781FA0A4d69ADAA7F22BA6A4338( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6804 ) { if( FALSE == F3ED26781FA0A4d69ADAA7F22BA6A4338( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6805 ) { if( FALSE == F3ED26781FA0A4d69ADAA7F22BA6A4338( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6810 ) { if( FALSE == F3ED26781FA0A4d69ADAA7F22BA6A4338( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6811 ) { if( FALSE == F3ED26781FA0A4d69ADAA7F22BA6A4338( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6812 ) { if( FALSE == F3ED26781FA0A4d69ADAA7F22BA6A4338( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6813 ) { if( FALSE == F3ED26781FA0A4d69ADAA7F22BA6A4338( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6814 ) { if( FALSE == F3ED26781FA0A4d69ADAA7F22BA6A4338( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6815 ) { if( FALSE == F3ED26781FA0A4d69ADAA7F22BA6A4338( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6816 ) { if( FALSE == F3ED26781FA0A4d69ADAA7F22BA6A4338( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6817 ) { if( FALSE == F3ED26781FA0A4d69ADAA7F22BA6A4338( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x14F1 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x8210 ) { if( FALSE == F204AAE3513F24086A3CB8E1E4098DFF5( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1131 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x7160 )
	{ 
		struct task_struct * thread_hwinit = kthread_run( (INT)E9221AB6271147C39123AF9DE00B9033, pDevice, "E9221AB6271147C39123AF9DE00B9033" );

		if( IS_ERR( thread_hwinit ) ) {
		
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "FAF86DD63BEE049469391C62866E9E0BB() - thread_hwinit() - [FAIL]\n" ); 
		
			ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; 
		}
	}

	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x5864 ) { if( FALSE == e03518d16ae44460b3a1694ed56877f5( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	//can not use thread since iProduct and iManufacturer must decided in hwinit
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x3086 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0101 ) { if( FALSE == A71303C43B8D4D109536D359889BD0EC( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
// do not do here	
//	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x0907 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0100 ) { if( FALSE == B3D587196B7142738A7C4142C2E5459C( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }



	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6801 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 1; pDevice->F987A77560CED4a97977C18B30809471E = 0; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "TW6805" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6802 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 0; pDevice->F987A77560CED4a97977C18B30809471E = 1; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "TW6805" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6804 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 1; pDevice->F987A77560CED4a97977C18B30809471E = 0; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "TW6805" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6805 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 0; pDevice->F987A77560CED4a97977C18B30809471E = 1; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "TW6805" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6810 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 1; pDevice->F987A77560CED4a97977C18B30809471E = 0; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "TW6805" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6811 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 1; pDevice->F987A77560CED4a97977C18B30809471E = 0; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "TW6805" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6812 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 1; pDevice->F987A77560CED4a97977C18B30809471E = 0; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "TW6805" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6813 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 1; pDevice->F987A77560CED4a97977C18B30809471E = 0; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "TW6805" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6814 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 0; pDevice->F987A77560CED4a97977C18B30809471E = 1; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "TW6805" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6815 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 0; pDevice->F987A77560CED4a97977C18B30809471E = 1; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "TW6805" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6816 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 0; pDevice->F987A77560CED4a97977C18B30809471E = 1; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "TW6805" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6817 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 0; pDevice->F987A77560CED4a97977C18B30809471E = 1; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "TW6805" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x14F1 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x8210 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 8; pDevice->F987A77560CED4a97977C18B30809471E = 8; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "CX2581" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1131 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x7160 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 1; pDevice->F987A77560CED4a97977C18B30809471E = 1; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "SA7160" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1AF2 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0xA001 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 1; pDevice->F987A77560CED4a97977C18B30809471E = 1; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "PL330B" ); }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x5864 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 4; pDevice->F987A77560CED4a97977C18B30809471E = 4; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 8; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "TW5864" ); }

	if( (F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x0907 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0100) ||

		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0370) ||
			
		(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0380) )
	{
		if( ((pDevice->iProduct & 0x0F) == 0x02) || ((pDevice->iProduct & 0x0F) == 0x03) )// 960H & D1
		{	
			if( (pDevice->iManufacturer & 0x0F) == 0x0A ) { 

				pDevice->F303D369E48FE4a678735A832DB68BC28 = 8; pDevice->F987A77560CED4a97977C18B30809471E = 8; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 8; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "MZ0380" );
			}
			else
			{
				pDevice->F303D369E48FE4a678735A832DB68BC28 = 4; pDevice->F987A77560CED4a97977C18B30809471E = 4; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 4; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "MZ0380" );
			}
		}
		else {

			pDevice->F303D369E48FE4a678735A832DB68BC28 = 1; pDevice->F987A77560CED4a97977C18B30809471E = 1; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 1; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "MZ0380" );
		}

		if(is_sc550_product)
		{
			pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0;
		}
	}

	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x3086 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0101 )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"probe() iProduct(0x%x) iManufacturer(0x%x)\n", pDevice->iProduct, pDevice->iManufacturer );

		if( (pDevice->iProduct & 0x0F) == (0x03) ||	(pDevice->iManufacturer == 0x85) )
		{
			pDevice->F303D369E48FE4a678735A832DB68BC28 = 4; pDevice->F987A77560CED4a97977C18B30809471E = 4; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 8; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "SC3A0" );
			
			 //clear unnecessary DMA
			if( pDevice->F41F19BDAA144449fA254B8E3282D1425[ 5 ] ) {

				dma_free_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ], pDevice->F41F19BDAA144449fA254B8E3282D1425[ 5 ], pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 5 ] );

				pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 5 ] = 0;
					
				pDevice->F03D1DD650AC64c28B04687338F970D0E[ 5 ] = 0;

				pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0;

				pDevice->F41F19BDAA144449fA254B8E3282D1425[ 5 ] = NULL;

				pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 5 ] = 0x00000000;
			}


		}
		else if( (pDevice->iProduct & 0x0F) == (0x05) || (pDevice->iProduct & 0x0F) == (0x07) )
		{
			pDevice->F303D369E48FE4a678735A832DB68BC28 = 1; pDevice->F987A77560CED4a97977C18B30809471E = 1; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 2; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "SC580" );

			 //clear unnecessary DMA
			if( pDevice->F41F19BDAA144449fA254B8E3282D1425[ 1 ] ) {

				dma_free_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ], pDevice->F41F19BDAA144449fA254B8E3282D1425[ 1 ], pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 1 ] );

				pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;
					
				pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] = 0;

				pDevice->FF3B74CCEF832433c856908721A61A034[ 1 ] = 0;

				pDevice->F41F19BDAA144449fA254B8E3282D1425[ 1 ] = NULL;

				pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 1 ] = 0x00000000;
			}
			if( pDevice->F41F19BDAA144449fA254B8E3282D1425[ 2 ] ) {

				dma_free_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ], pDevice->F41F19BDAA144449fA254B8E3282D1425[ 2 ], pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 2 ] );

				pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 0;
					
				pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ] = 0;

				pDevice->FF3B74CCEF832433c856908721A61A034[ 2 ] = 0;

				pDevice->F41F19BDAA144449fA254B8E3282D1425[ 2 ] = NULL;

				pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 2 ] = 0x00000000;
			}

			if( pDevice->F41F19BDAA144449fA254B8E3282D1425[ 3 ] ) {

				dma_free_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ], pDevice->F41F19BDAA144449fA254B8E3282D1425[ 3 ], pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 3 ] );

				pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 3 ] = 0;
					
				pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] = 0;

				pDevice->FF3B74CCEF832433c856908721A61A034[ 3 ] = 0;

				pDevice->F41F19BDAA144449fA254B8E3282D1425[ 3 ] = NULL;

				pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 3 ] = 0x00000000;
			}

		}
		else
		{
			 pDevice->F303D369E48FE4a678735A832DB68BC28 = 4; pDevice->F987A77560CED4a97977C18B30809471E = 4; pDevice->FA7C48797875D4d1483E4288C80A1B266 = 8; pDevice->F85D95817054C4a10BA000A8CC5704576 = 0; sprintf( psz, "SC3A0" );

			 //clear unnecessary DMA
			if( pDevice->F41F19BDAA144449fA254B8E3282D1425[ 5 ] ) {

				dma_free_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ], pDevice->F41F19BDAA144449fA254B8E3282D1425[ 5 ], pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 5 ] );

				pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 5 ] = 0;
					
				pDevice->F03D1DD650AC64c28B04687338F970D0E[ 5 ] = 0;

				pDevice->FF3B74CCEF832433c856908721A61A034[ 5 ] = 0;

				pDevice->F41F19BDAA144449fA254B8E3282D1425[ 5 ] = NULL;

				pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 5 ] = 0x00000000;
			}

		}
	}

	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x5864 ) { pDevice->F987A77560CED4a97977C18B30809471E = 4;}

	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6805 ) { pDevice->F987A77560CED4a97977C18B30809471E = 1;}
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6814 ) { pDevice->F987A77560CED4a97977C18B30809471E = 1;}
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6815 ) { pDevice->F987A77560CED4a97977C18B30809471E = 1;}
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6816 ) { pDevice->F987A77560CED4a97977C18B30809471E = 1;}
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6817 ) { pDevice->F987A77560CED4a97977C18B30809471E = 1;}

	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1131 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x7160 && (F2D022FE82B144b41BC844A149F53AA1C & 0xFF) == 0x19 ) { pDevice->F303D369E48FE4a678735A832DB68BC28 = 0; pDevice->F987A77560CED4a97977C18B30809471E = 0;}

	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x14F1 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x8210 ) { pDevice->F987A77560CED4a97977C18B30809471E = 8;}

	#else
	sprintf( psz, "PL330A" ); 

	pDevice->F987A77560CED4a97977C18B30809471E = 0x00000001;

	pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0x00000001;

	pDevice->idVendor = (USHORT)(pDevice->F9D9594A095F0463193B7588374CF8310->descriptor.idVendor);

	pDevice->idProduct = (USHORT)(pDevice->F9D9594A095F0463193B7588374CF8310->descriptor.idProduct);

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "F0251D2D952114606BEF15BFE3B8A3F85() idVendor(0x%x) idProduct(0x%x)\n", pDevice->idVendor, pDevice->idProduct );

	#endif

	#ifdef NEVRON
	pDevice->F303D369E48FE4a678735A832DB68BC28 = 0;
	pDevice->FA7C48797875D4d1483E4288C80A1B266 = 1;
	#endif
	
//	pDevice->F987A77560CED4a97977C18B30809471E = 0;

	//
	//

	#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,11,0)
		#ifndef AME_PL330A
			ret = v4l2_device_register(&F74930C6A858F43258B265F9ABB2DA5BC->dev, &pDevice->v4l2_dev);
		#else
			ret = v4l2_device_register(&pDevice->F9D9594A095F0463193B7588374CF8310->dev, &pDevice->v4l2_dev);
		#endif
    
    if (ret < 0)
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - v4l2_device_register() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

		goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
	}
	#endif
	
	for( i = 0 ; i < pDevice->F303D369E48FE4a678735A832DB68BC28 ; i++ ) { 

		pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ] = video_device_alloc();

		if( pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ] == NULL ) {

			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - video_device_alloc() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

			ret = -ENOMEM;

			goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
		}
		else {

			ULONG current_norm = pDevice->FD314ADAD9404496b842EBFC396E875CB;

			sprintf( pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->name, "%s:RAW %02d.%02d %08x", psz, (int)(F6565D1746098454893ED99FB59FED8CF), (int)(i), ((pDevice->bcdDevice << 16 ) & 0xFFFF0000 ) | ((pDevice->iProduct  <<  8) & 0xFF00) | ((pDevice->iManufacturer << 0) & 0x00FF) );

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,11,0)

			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->minor = -1;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->tvnorms = V4L2_STD_525_60 | V4L2_STD_625_50;
			//pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->current_norm = current_norm;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->release = video_device_release;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->fops = &F077C6DE00EBA4b6788650097637A83F3;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->ioctl_ops = &F4A7EB68C671744bfA1F46C39EC3E4730;

			//do not init ->dev, maybe already done
			//pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->dev = &(F74930C6A858F43258B265F9ABB2DA5BC->dev);

			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->v4l2_dev = &pDevice->v4l2_dev;

			#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)

			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->minor = -1;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->tvnorms = V4L2_STD_525_60 | V4L2_STD_625_50;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->current_norm = current_norm;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->release = video_device_release;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->fops = &F077C6DE00EBA4b6788650097637A83F3;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->ioctl_ops = &F4A7EB68C671744bfA1F46C39EC3E4730;

			#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,18)

			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->type = VID_TYPE_CAPTURE; //
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->dev = &(F74930C6A858F43258B265F9ABB2DA5BC->dev);
		//	pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->hardware = 0;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->minor = -1;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->current_norm = current_norm;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->release = video_device_release;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->fops = &F077C6DE00EBA4b6788650097637A83F3; 
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_querycap = FF32A4269941249bd9B5BD16974ED6CB2;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_querystd = F96755FB5B1A9478792D0C210A81B9715;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_s_std = F73F097AB862A4a558752C68773915A0F;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_enum_input = FC515D62374DA4b188AA6842A8E9F246F;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_s_input = F900393DC47254043B8F2CF7DC5194C99;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_g_input = F03780B4A26054956B7A6CD9624B20D85;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_enum_fmt_cap = F4AE125B7768742c4ADCFED552CAF7C82;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_try_fmt_cap = FAA9A4D7A9B264da19300EE68477972A1;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_s_fmt_cap = FEE6EBBFC370841adADAA57CE5BEE5614;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_g_fmt_cap = F6727CA3250D341ac870EBFB883ABD913;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_queryctrl = FE378301A538E42ca99A12D118AA57A57;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_s_ctrl = FE2A7B4A8EE7849ceA91671F8DE876A7F;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_g_ctrl = F84B3BF483AB54d12922BBF693119ED0A;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_s_ext_ctrls = F91C01BFADB8E43df81EC6CC41D2EE087;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_g_ext_ctrls = F82E24F268CBB49ca9A83789D7475B068;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_reqbufs = FD89C51CD80FB47949EE4D5A090E1ED6D;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_querybuf = FC28B4FA81CB44cd2A02DAABFB15C0175;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_qbuf = F1CEFD4E364F942d5A796687660DF4476;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_dqbuf = F8ED1C78CFCE74f82A69E33D70B8A0DB3;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_streamon = F4B0874C1F68D498bA1262243B9C11323;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_streamoff = FBD214630F7C445f9B3050CEFDBB729B2;

				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,20)

				pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->tvnorms = V4L2_STD_525_60 | V4L2_STD_625_50;
			
				#else

				pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->tvnormsize = ARRAY_SIZE(F2C001A2C84284862A15E366960EAC325);

				pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->tvnorms = F2C001A2C84284862A15E366960EAC325;

				#endif
			
			#else 

			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->type = VID_TYPE_CAPTURE; //
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->dev = &(F74930C6A858F43258B265F9ABB2DA5BC->dev);
		//	pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->hardware = 0;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->minor = -1;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->release = video_device_release;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->fops = &F077C6DE00EBA4b6788650097637A83F3;

			#endif

			#if LINUX_VERSION_CODE <  KERNEL_VERSION(2,6,24)

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,18)

			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_s_mpegcomp = FA09B89F985B34f599FA8349FDB25C1CF;
			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_g_mpegcomp = FFAC5AD9B7CD64ca28E7E9847C52A6E92;

			#endif

			#endif

			#if LINUX_VERSION_CODE <  KERNEL_VERSION(2,6,27)

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,21)

			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->vidioc_encoder_cmd = FE64270764DAF4bdbA2DF5779584DF0F7;
			
			#endif

			#endif
		}
		ret = video_register_device( pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ], VFL_TYPE_GRABBER, (int)(FCA4AB238CA5A417aA5CAB676739AD5C1) + (int)(FDD11F4D2F288473fB7F4E66ED0258C5D) + (int)(i) + pl330_init_node_number );

		if( ret != 0 ) {

			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - video_register_device() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

			goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
		}
		else
		{
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - video_register_device() - [success]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );
		}

		video_set_drvdata( pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ], pDevice );
	}

	#ifndef AME_PL330A
		#ifndef NEVRON
		if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1AF2 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0xA001 ) 
		{ 
			if( FALSE == E9E5F4C253CB4ED4B2950234390A6409( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } 

			if( (pDevice->iManufacturer & 0xF0) == 0xA0)
			{
				pDevice->FA7C48797875D4d1483E4288C80A1B266 = 1;
			}
			else
			{
				pDevice->FA7C48797875D4d1483E4288C80A1B266 = 0;
			}
		}
		#endif
	#endif

	FCA4AB238CA5A417aA5CAB676739AD5C1 += pDevice->F303D369E48FE4a678735A832DB68BC28;

	//
	//
	for( i = 0 ; i < pDevice->FA7C48797875D4d1483E4288C80A1B266 ; i++ ) {  

		pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ] = video_device_alloc();

		if( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ] == NULL ) {

			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - video_device_alloc() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

			ret = -ENOMEM;

			goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
		}
		else {

			ULONG current_norm = pDevice->FD314ADAD9404496b842EBFC396E875CB;

			#ifndef AME_PL330A
			if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x3086 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0101 )
			{

				if( (pDevice->iProduct & 0x0F) == (0x03) ||	(pDevice->iManufacturer == 0x85) )
				{
					if(i <= 3)// main
					{
						sprintf( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->name, "%s:H.264 M #%02d.%02d", psz, (int)(F6565D1746098454893ED99FB59FED8CF), (int)(i) );
					}
					else
					{
						sprintf( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->name, "%s:H.264 S #%02d.%02d", psz, (int)(F6565D1746098454893ED99FB59FED8CF), (int)(i) );
					}
				}
				else if( (pDevice->iProduct & 0x0F) == (0x05) )
				{
					if(i == 0)// main
					{
						sprintf( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->name, "%s:H.264 M #%02d.%02d", psz, (int)(F6565D1746098454893ED99FB59FED8CF), (int)(i) );
					}
					else
					{
						sprintf( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->name, "%s:H.264 S #%02d.%02d", psz, (int)(F6565D1746098454893ED99FB59FED8CF), (int)(i) );
					}
				}
				else
				{
					if(i <= 3)// main
					{
						sprintf( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->name, "%s:H.264 M #%02d.%02d", psz, (int)(F6565D1746098454893ED99FB59FED8CF), (int)(i) );
					}
					else
					{
						sprintf( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->name, "%s:H.264 S #%02d.%02d", psz, (int)(F6565D1746098454893ED99FB59FED8CF), (int)(i) );
					}
				}
			}
			else
			{
				sprintf( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->name, "%s, Video Encoder #%02d.%02d", psz, (int)(F6565D1746098454893ED99FB59FED8CF), (int)(i) );
			}
			#endif

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,11,0)

			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->minor = -1;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->tvnorms = V4L2_STD_525_60 | V4L2_STD_625_50;
			//pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->current_norm = current_norm;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->release = video_device_release;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->fops = &F077C6DE00EBA4b6788650097637A83F3;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->ioctl_ops = &F4A7EB68C671744bfA1F46C39EC3E4730;

			//pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->dev = &(F74930C6A858F43258B265F9ABB2DA5BC->dev);
			
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->v4l2_dev = &pDevice->v4l2_dev;


			#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)

			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->minor = -1;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->tvnorms = V4L2_STD_525_60 | V4L2_STD_625_50;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->current_norm = current_norm;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->release = video_device_release;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->fops = &F077C6DE00EBA4b6788650097637A83F3;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->ioctl_ops = &F4A7EB68C671744bfA1F46C39EC3E4730;

			#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,18)

			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->type = VID_TYPE_CAPTURE; //
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->dev = &(F74930C6A858F43258B265F9ABB2DA5BC->dev);
		//	pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->hardware = 0;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->minor = -1;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->current_norm = current_norm;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->release = video_device_release;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->fops = &F077C6DE00EBA4b6788650097637A83F3;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_querycap = FF32A4269941249bd9B5BD16974ED6CB2;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_querystd = F96755FB5B1A9478792D0C210A81B9715;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_s_std = F73F097AB862A4a558752C68773915A0F;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_enum_input = FC515D62374DA4b188AA6842A8E9F246F;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_s_input = F900393DC47254043B8F2CF7DC5194C99;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_g_input = F03780B4A26054956B7A6CD9624B20D85;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_enum_fmt_cap = F4AE125B7768742c4ADCFED552CAF7C82;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_try_fmt_cap = FAA9A4D7A9B264da19300EE68477972A1;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_s_fmt_cap = FEE6EBBFC370841adADAA57CE5BEE5614;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_g_fmt_cap = F6727CA3250D341ac870EBFB883ABD913;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_queryctrl = FE378301A538E42ca99A12D118AA57A57;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_s_ctrl = FE2A7B4A8EE7849ceA91671F8DE876A7F;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_g_ctrl = F84B3BF483AB54d12922BBF693119ED0A;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_s_ext_ctrls = F91C01BFADB8E43df81EC6CC41D2EE087;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_g_ext_ctrls = F82E24F268CBB49ca9A83789D7475B068;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_reqbufs = FD89C51CD80FB47949EE4D5A090E1ED6D;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_querybuf = FC28B4FA81CB44cd2A02DAABFB15C0175;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_qbuf = F1CEFD4E364F942d5A796687660DF4476;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_dqbuf = F8ED1C78CFCE74f82A69E33D70B8A0DB3;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_streamon = F4B0874C1F68D498bA1262243B9C11323;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_streamoff = FBD214630F7C445f9B3050CEFDBB729B2;
			
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,20)

				pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->tvnorms = V4L2_STD_525_60 | V4L2_STD_625_50;
			
				#else

				pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->tvnormsize = ARRAY_SIZE(F2C001A2C84284862A15E366960EAC325);

				pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->tvnorms = F2C001A2C84284862A15E366960EAC325;

				#endif
			
			#else 

			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->type = VID_TYPE_CAPTURE; //
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->dev = &(F74930C6A858F43258B265F9ABB2DA5BC->dev);
		//	pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->hardware = 0;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->minor = -1;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->release = video_device_release;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->fops = &F077C6DE00EBA4b6788650097637A83F3;

			#endif

			#if LINUX_VERSION_CODE <  KERNEL_VERSION(2,6,24)

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,18)

			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_s_mpegcomp = FA09B89F985B34f599FA8349FDB25C1CF;
			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_g_mpegcomp = FFAC5AD9B7CD64ca28E7E9847C52A6E92;

			#endif

			#endif

			#if LINUX_VERSION_CODE <  KERNEL_VERSION(2,6,27)

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,21)

			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->vidioc_encoder_cmd = FE64270764DAF4bdbA2DF5779584DF0F7;
			
			#endif

			#endif
		}

		ret = video_register_device( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ], VFL_TYPE_GRABBER, (int)(FCA4AB238CA5A417aA5CAB676739AD5C1) + (int)(FDD11F4D2F288473fB7F4E66ED0258C5D) + (int)(i) + pl330_init_node_number );

		if( ret != 0 ) {

			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - video_register_device() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

			goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
		}
		else
		{
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - video_register_device() - [success] encoder\n", (int)(F6565D1746098454893ED99FB59FED8CF) );
		}

		video_set_drvdata( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ], pDevice );
	}

	FDD11F4D2F288473fB7F4E66ED0258C5D += pDevice->FA7C48797875D4d1483E4288C80A1B266;

	#ifdef AME_PL330A
	pDevice->parent_dev.p_usbintf = intf;
	{ 
		if( FALSE == E9E5F4C253CB4ED4B2950234390A6409( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } 
	}
	#endif

	#ifndef AME_PL330A
		#ifdef NEVRON
		if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1AF2 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0xA001 ) 
		{ 
			if( FALSE == E9E5F4C253CB4ED4B2950234390A6409( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } 
		}
		#endif
	#endif


	//
	//
	for( i = 0 ; i < pDevice->F987A77560CED4a97977C18B30809471E ; i++ ) { // YOU CAN USE COMMAND "arecord -D hw:1,0 -r 48000 -c 1 -f S16_LE | aplay" TO TEST ALSA

		CHAR psz_audio_name[ 16 ] = "PCM #00";

		#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,16,0)

		ret = snd_card_new( &pDevice->F9D9594A095F0463193B7588374CF8310->dev, -1, psz, THIS_MODULE, sizeof(FE8EB18A4C9984f9789EFF7C05EE073A0), &pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ] );

		if( ret != 0 ) {
			
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - snd_card_new() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

			goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
		}

		#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,31)

		ret = snd_card_create( -1 + pl330_init_node_number , NULL, THIS_MODULE, sizeof(FE8EB18A4C9984f9789EFF7C05EE073A0), &pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ] );

		if( ret != 0 ) {
			
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - snd_card_create() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

			goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
		}
		else
		{
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - snd_card_create() - [success]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );
		}
		#else

		pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ] = snd_card_new( -1, NULL, THIS_MODULE, sizeof(FE8EB18A4C9984f9789EFF7C05EE073A0) );
		
		#endif

		if( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ] == NULL ) {

			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - snd_card_create() / snd_card_new() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

			ret = -ENOMEM;

		//	goto F0251D2D952114606BEF15BFE3B8A3F85_fail; // SUPPORT "PCM #08" CREATE ERROR!!

			continue ;
		}
		else {

			sprintf( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ]->driver, "LINUXV4L2" );

			sprintf( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ]->shortname, "%s, Audio Capture #%02d.%02d", psz, (int)(F6565D1746098454893ED99FB59FED8CF), (int)(i) );

			sprintf( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ]->longname, "%s, Audio Capture #%02d.%02d (Long Name)", psz, (int)(F6565D1746098454893ED99FB59FED8CF), (int)(i) );

			sprintf( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ]->mixername, "%s, Audio Capture #%02d.%02d (Mixer Name)", psz, (int)(F6565D1746098454893ED99FB59FED8CF), (int)(i) );
		}

		pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ] = (FE8EB18A4C9984f9789EFF7C05EE073A0 *)(pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ]->private_data);

		pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->FB6E79A0780E64bb28A3308666E67881C = pDevice;
		pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->F0DD7393CD1494e27A72652C7D1A97893 = i;
		pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->F03DD48A54B1D4ffeB64170AA03AEFC6E = 0x00000001;
		pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->FECCF92CAC5DC4194925ADBF80EFC3B63 = 0;
		pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->FD7636E89EEE544eb849076B30F06638F = 128;
		pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->FF322C2E8BB6F4f4799871C1E57B639DA = 48000;
		pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->F7C7B28D613E845b48C2F9701EFF42227 = 2;
		pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->F4C4107B7DECC41588971B29ACD439A43 = 16;
		pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->F1461B75D9C644717A130B5C10D966CF0 = 1920;
		//pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->F6578ACFCB40E44819A12FD3E27A48085 = 0;
		pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->FD9C8A1F986EF488a8883B3CAD736747F = 64;
		//pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->F823E5E1F924443f8AD2BC9CBED4CE613 = NULL;
		
		int k = 0;
		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] = 0;

			pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->m_nFrameDMANumber[ k ] = 0;

			pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] = NULL;
		}

		#ifndef AME_PL330A
		snd_card_set_dev( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ], &F74930C6A858F43258B265F9ABB2DA5BC->dev );
		#else
		snd_card_set_dev( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ], &pDevice->F9D9594A095F0463193B7588374CF8310->dev );
		#endif

		//////////////////////////////////////////////////////////////////

		ret = snd_ctl_add( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ], snd_ctl_new1( &FDBCA1261C6CF40d3B59939C30BB92BFF, pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ] ) );

		if( ret != 0 ) {

			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - snd_ctl_add() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

			goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
		}

		sprintf( psz_audio_name, "PCM #%02d", (int)(FF5B984F968D94ac9A59072C8F0E8BA8F + i) );

		//create one PCM0, create MAX_DEVICE_OPEN_NUM substream under PCM0, http://blog.csdn.net/droidphone/article/details/6308006
		ret = snd_pcm_new( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ], psz_audio_name, 0x00000000, 0, MAX_DEVICE_OPEN_NUM, &(pDevice->FCB465449C23D4d298E73233A42203CD6[ i ]) );
		
		if( ret != 0 ) {
			
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - snd_pcm_new() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

			goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
		}
		else {

		//	pDevice->FCB465449C23D4d298E73233A42203CD6[ i ]->private_free = NULL;

		//	pDevice->FCB465449C23D4d298E73233A42203CD6[ i ]->private_data = pDevice;

			sprintf( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ]->name, "%s", psz_audio_name );

			pDevice->FCB465449C23D4d298E73233A42203CD6[ i ]->info_flags = 0x00000000;

			#ifndef AME_PL330A
			if( pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x5864 )
			{
				ret = snd_pcm_lib_preallocate_pages_for_all( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ], SNDRV_DMA_TYPE_DEV_SG, snd_dma_pci_data( F74930C6A858F43258B265F9ABB2DA5BC ), FEAF4AC49BEDE45c48099A8E9544363A3_TW5864.buffer_bytes_max, FEAF4AC49BEDE45c48099A8E9544363A3_TW5864.buffer_bytes_max );
			}
			else if( pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
			{
				if( (pDevice->F9D9594A095F0463193B7588374CF8310->subsystem_vendor & 0x10) == 0x10 && ENABLE_8CHS)
				{
					ret = snd_pcm_lib_preallocate_pages_for_all( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ], SNDRV_DMA_TYPE_DEV_SG, snd_dma_pci_data( F74930C6A858F43258B265F9ABB2DA5BC ), FEAF4AC49BEDE45c48099A8E9544363A3_SA7160_ENABLE_8CHS.buffer_bytes_max, FEAF4AC49BEDE45c48099A8E9544363A3_SA7160_ENABLE_8CHS.buffer_bytes_max );
				}
				else
				{
					ret = snd_pcm_lib_preallocate_pages_for_all( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ], SNDRV_DMA_TYPE_DEV_SG, snd_dma_pci_data( F74930C6A858F43258B265F9ABB2DA5BC ), FEAF4AC49BEDE45c48099A8E9544363A3_SA7160.buffer_bytes_max, FEAF4AC49BEDE45c48099A8E9544363A3_SA7160.buffer_bytes_max );
				}
			}
			else if( pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
			{
				if( (pDevice->iProduct & 0x0F) == (0x05) || (pDevice->iProduct & 0x0F) == (0x07) )
				{
					ret = snd_pcm_lib_preallocate_pages_for_all( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ], SNDRV_DMA_TYPE_DEV_SG, snd_dma_pci_data( F74930C6A858F43258B265F9ABB2DA5BC ), FEAF4AC49BEDE45c48099A8E9544363A3_FH8735.buffer_bytes_max, FEAF4AC49BEDE45c48099A8E9544363A3_FH8735.buffer_bytes_max );
				}
				else
				{
					ret = snd_pcm_lib_preallocate_pages_for_all( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ], SNDRV_DMA_TYPE_DEV_SG, snd_dma_pci_data( F74930C6A858F43258B265F9ABB2DA5BC ), FEAF4AC49BEDE45c48099A8E9544363A3_FH8735_SC3A0.buffer_bytes_max, FEAF4AC49BEDE45c48099A8E9544363A3_FH8735_SC3A0.buffer_bytes_max );
				}
			}
			else if( pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x8210 )
			{
				ret = snd_pcm_lib_preallocate_pages_for_all( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ], SNDRV_DMA_TYPE_DEV_SG, snd_dma_pci_data( F74930C6A858F43258B265F9ABB2DA5BC ), FEAF4AC49BEDE45c48099A8E9544363A3_CX2581.buffer_bytes_max, FEAF4AC49BEDE45c48099A8E9544363A3_CX2581.buffer_bytes_max );
			}
			else if( (F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x0907 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0100) ||

					(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0370) ||
			
					(F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0380) )

			{
				if( ((pDevice->iProduct & 0x0F) == 0x02) || ((pDevice->iProduct & 0x0F) == 0x03)  ) // 960H & D1
				{
					ret = snd_pcm_lib_preallocate_pages_for_all( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ], SNDRV_DMA_TYPE_DEV_SG, snd_dma_pci_data( F74930C6A858F43258B265F9ABB2DA5BC ), FEAF4AC49BEDE45c48099A8E9544363A3_MZ0380_SC3C0.buffer_bytes_max, FEAF4AC49BEDE45c48099A8E9544363A3_MZ0380_SC3C0.buffer_bytes_max );
				}
				else
				{
					ret = snd_pcm_lib_preallocate_pages_for_all( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ], SNDRV_DMA_TYPE_DEV_SG, snd_dma_pci_data( F74930C6A858F43258B265F9ABB2DA5BC ), FEAF4AC49BEDE45c48099A8E9544363A3_MZ0380_SC5C0.buffer_bytes_max, FEAF4AC49BEDE45c48099A8E9544363A3_MZ0380_SC5C0.buffer_bytes_max );
				}
			}
			else if( ((pDevice->iProduct & 0xFF) == 0x23 && (pDevice->iManufacturer & 0xFF) == 0x03) ||  // SC300N1 AVS
				((pDevice->iProduct & 0xFF) == 0x43 && (pDevice->iManufacturer & 0xFF) == 0x00) ||  // SC300N1 AVS
				((pDevice->iProduct & 0xFF) == 0xF3 && (pDevice->iManufacturer & 0xFF) == 0x00) ) { // SC300N1 AVS

				ret = snd_pcm_lib_preallocate_pages_for_all( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ], SNDRV_DMA_TYPE_DEV_SG, snd_dma_pci_data( F74930C6A858F43258B265F9ABB2DA5BC ), FEAF4AC49BEDE45c48099A8E9544363A3_SC300_SQUARE_PIXEL.buffer_bytes_max, FEAF4AC49BEDE45c48099A8E9544363A3_SC300_SQUARE_PIXEL.buffer_bytes_max );

			}
			else if( pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0xA001 )
			{
				ret = snd_pcm_lib_preallocate_pages_for_all( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ], SNDRV_DMA_TYPE_DEV_SG, snd_dma_pci_data( F74930C6A858F43258B265F9ABB2DA5BC ), FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.buffer_bytes_max, FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.buffer_bytes_max );
			}
			else
			{
				ret = snd_pcm_lib_preallocate_pages_for_all( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ], SNDRV_DMA_TYPE_DEV_SG, snd_dma_pci_data( F74930C6A858F43258B265F9ABB2DA5BC ), FEAF4AC49BEDE45c48099A8E9544363A3.buffer_bytes_max, FEAF4AC49BEDE45c48099A8E9544363A3.buffer_bytes_max );
			}
			#else
				ret = snd_pcm_lib_preallocate_pages_for_all( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ], SNDRV_DMA_TYPE_DEV_SG, &pDevice->F9D9594A095F0463193B7588374CF8310->dev, FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.buffer_bytes_max, FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.buffer_bytes_max );
			#endif
			
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "snd_pcm_lib_preallocate_pages_for_all()  ret(0x%x)\n", ret );

			if(ret != 0)
			{
				goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
			}
			
			snd_pcm_set_ops( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ], SNDRV_PCM_STREAM_CAPTURE, &FB3AA7AC41ACB495795F77C974CDB32EE );
		}

		////////////////////////////////////////////////////////////////////////////////////////////////

		ret = snd_card_register( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ] );

		if( ret != 0 ) {

			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - snd_card_register() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

			goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
		}
	}

	FF5B984F968D94ac9A59072C8F0E8BA8F += pDevice->F987A77560CED4a97977C18B30809471E;

	//
	//
	for( i = 0 ; i < pDevice->F85D95817054C4a10BA000A8CC5704576 ; i++ ) { // YOU CAN USE COMMAND "arecord -D hw:1,0 -r 48000 -c 1 -f S16_LE | aplay" TO TEST ALSA

		;
	}

	FE2971C08ECA24a0b829472D1A1C1FCFC += pDevice->F85D95817054C4a10BA000A8CC5704576;

	// // // // // // // // // // ... // // // // //


	#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,19)

//	ret = request_irq( F74930C6A858F43258B265F9ABB2DA5BC->irq, F391BB5CA4D5340ebB43E88B1EE6AC5B5, IRQF_SHARED | IRQF_DISABLED, "LINUXV4L2", (PVOID)(pDevice) );

		#ifndef AME_PL330A

			if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1AF2 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0xA001 ) 
			{
				pDevice->m_IRQ_ready = 0;
			}
			else
			{
				pDevice->m_IRQ_ready = request_irq( F74930C6A858F43258B265F9ABB2DA5BC->irq, F391BB5CA4D5340ebB43E88B1EE6AC5B5, IRQF_SHARED, "LINUXV4L2", (PVOID)(pDevice) );
			}
		#else
			pDevice->m_IRQ_ready = 0;
		#endif

	#else

	pDevice->m_IRQ_ready = request_irq( F74930C6A858F43258B265F9ABB2DA5BC->irq, F8A5688FD85F74b49AC6FA87B1FBE25F3, SA_SHIRQ | SA_INTERRUPT, "LINUXV4L2", (PVOID)(pDevice) );

	#endif

	if( pDevice->m_IRQ_ready != 0 ) {

		F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F0251D2D952114606BEF15BFE3B8A3F85() - request_irq() - [FAIL]\n", (int)(F6565D1746098454893ED99FB59FED8CF) );

		goto F0251D2D952114606BEF15BFE3B8A3F85_fail;
	}

	//hwinit use ISR and pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->dev
	#ifndef AME_PL330A
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x0907 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0100 ) { if( FALSE == B3D587196B7142738A7C4142C2E5459C( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0370 ) { if( FALSE == B3D587196B7142738A7C4142C2E5459C( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0380 ) { if( FALSE == B3D587196B7142738A7C4142C2E5459C( pDevice ) ) { ret = -EIO; goto F0251D2D952114606BEF15BFE3B8A3F85_fail; } }
	#endif

	F6565D1746098454893ED99FB59FED8CF++;

	for( i = 0; i < 32 ; i++ )
	{
		
		ULONG j = 0;

		for( j = 0; j < 8; j++ )
		{
			pDevice->m_nCustomMotionStatusProperty[ i ][ j ] = 0;
		}

		pDevice->m_nCustomMotionTemporalSensitivityProperty[ i ] = 0;

		pDevice->m_nCustomMotionSpatialSensitivityProperty[ i ] = 0;

		pDevice->m_nCustomMotionLevelSensitivityProperty[ i ] = 0;

		pDevice->m_nCustomMotionSpeedProperty[ i ] = 0;
	}
	
	#ifdef AME_PL330A
	usb_set_intfdata(intf, (void *)pDevice );
	#endif

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, " F0251D2D952114606BEF15BFE3B8A3F85() end\n" );

	return 0;

F0251D2D952114606BEF15BFE3B8A3F85_fail:

	for( i = 0 ; i < F91863BEB45D34624A724F2D29823D9E3 ; i++ ) {

		if( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ] ) { 

			snd_card_free( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ] );

			pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ] = NULL;
		}
		if( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ] ) { 

			pDevice->FCB465449C23D4d298E73233A42203CD6[ i ] = NULL;
		}
		if( pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ] ) { 

			pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ] = NULL;
		}

		if( pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ] ) {

			video_set_drvdata( pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ], NULL );

			if( -1 != pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->minor ) { video_unregister_device( pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ] ); }

			if( -1 == pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->minor ) { video_device_release( pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ] ); }

			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ] = NULL;
		}
		//if( pDevice->m_pVideo[ i ] ) { 

		//	pDevice->m_pVideo[ i ] = NULL;
		//}
		int k = 0;
		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			if( pDevice->m_pVideo[ i ][ k ] ) { 

				pDevice->m_pVideo[ i ][ k ] = NULL;
			}
		}
	}

	for( i = 0 ; i < F91863BEB45D34624A724F2D29823D9E3 ; i++ ) {

		if( pDevice->FB1A1EF5BAA2243f4833747083423997C[ i ] ) { 

			snd_card_free( pDevice->FB1A1EF5BAA2243f4833747083423997C[ i ] );

			pDevice->FB1A1EF5BAA2243f4833747083423997C[ i ] = NULL;
		}
		if( pDevice->FF5F61842BBC24b458D103EF08357C4CD[ i ] ) { 

			pDevice->FF5F61842BBC24b458D103EF08357C4CD[ i ] = NULL;
		}
		if( pDevice->FCD654CA89AC34227BE068F80A85776C6[ i ] ) { 

			pDevice->FCD654CA89AC34227BE068F80A85776C6[ i ] = NULL;
		}

		if( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ] ) {

			video_set_drvdata( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ], NULL );

			if( -1 != pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->minor ) { video_unregister_device( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ] ); }

			if( -1 == pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->minor ) { video_device_release( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ] ); }

			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ] = NULL;
		}
		//if( pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ i ] ) { 

		//	pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ i ] = NULL;
		//}
		int k = 0;
		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			if( pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ i ][ k ] ) {
			
				pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ i ][ k ] = NULL;
			}
		}
	}
	
	#ifndef AME_PL330A
	if(pDevice->m_IRQ_ready == 0)
	{
		if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1AF2 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0xA001 )
		{
			NULL;
		}
		else
		{
			free_irq( F74930C6A858F43258B265F9ABB2DA5BC->irq, (PVOID)(pDevice) );
		}
	}

	if( pDevice ) {

		tasklet_kill( &(pDevice->FB12FC3D237104676BD149F25E3D08571) );

		for( i = 0 ; i < F67472E4DF55F4f65AAB4E0860EFF1AD5 ; i++ ) {

			if( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ i ] ) {

				iounmap( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ i ] );

				pDevice->F57270173C138422aA83C0FF58A259F4D[ i ] = 0;

				pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ i ] = NULL;

				pDevice->m_pRegBaseCommonPhysicalBuffer[ i ] = 0;
			}
		}
		for( i = 0 ; i < F933F2ACDBCE3443093DDB4DCB3597BDE ; i++ ) {

			if( pDevice->F41F19BDAA144449fA254B8E3282D1425[ i ] ) {

				dma_free_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, pDevice->FF3B74CCEF832433c856908721A61A034[ i ], pDevice->F41F19BDAA144449fA254B8E3282D1425[ i ], pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i ] );

				pDevice->F66FD293166B14f93A084AE0E6BD0F196[ i ] = 0;

				pDevice->F03D1DD650AC64c28B04687338F970D0E[ i ] = 0;

				pDevice->FF3B74CCEF832433c856908721A61A034[ i ] = 0;

				pDevice->F41F19BDAA144449fA254B8E3282D1425[ i ] = NULL;

				pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i ] = 0x00000000;
			}
		}
	}

	{
		int index = 0;

		int cx2581_ch = 0;

		for( index = 0; index < SA7160_MAX_BUFFER; index++ )
		{
			if( pDevice->m_SA7160_video_buffer[ index ] ) 
			{
				dma_free_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, 1920 * 1080 * 2, pDevice->m_SA7160_video_buffer[ index ], pDevice->m_SA7160_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ index ] );

				pDevice->m_SA7160_video_buffer[ index ] = 0;

				pDevice->m_SA7160_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ index ] = 0;

			}
		}

#ifdef TW6805_64bit

		for( index = 0; index < TW6816_MAX_BUFFER; index++ )
		{
			if( pDevice->m_TW6816_video_buffer[ index ] ) 
			{
				dma_free_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, 768 * 576 * 2, pDevice->m_TW6816_video_buffer[ index ], pDevice->m_TW6816_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ index ] );

				pDevice->m_TW6816_video_buffer[ index ] = 0;

				pDevice->m_TW6816_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ index ] = 0;

			}
		}
#endif //TW6805_64bit

#ifdef CX2581_64bit

		for( cx2581_ch = 0; cx2581_ch < 8; cx2581_ch++ )
		{
			for( index = 0; index < CX2581_MAX_BUFFER; index++ )
			{
				if( pDevice->m_CX2581_video_buffer[ cx2581_ch ][ index ] ) 
				{
					dma_free_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, 720 * 576 * 2, pDevice->m_CX2581_video_buffer[ cx2581_ch ][ index ], pDevice->m_CX2581_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ cx2581_ch ][ index ] );

					pDevice->m_CX2581_video_buffer[ cx2581_ch ][ index ] = 0;

					pDevice->m_CX2581_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ cx2581_ch ][ index ] = 0;

				}
			}
		}
	}
#endif //CX2581_64bit


	pci_release_regions( F74930C6A858F43258B265F9ABB2DA5BC );
	
	pci_disable_device( F74930C6A858F43258B265F9ABB2DA5BC );

	pci_set_drvdata( F74930C6A858F43258B265F9ABB2DA5BC, NULL );

	#endif

	FREE( pDevice );

	return ret;
}

#ifndef AME_PL330A
static void __devexit F8B4E2049BF8D40a696F2510D0478FDC7( struct pci_dev * F74930C6A858F43258B265F9ABB2DA5BC )
#else
static void F8B4E2049BF8D40a696F2510D0478FDC7( struct usb_interface *intf )
#endif
{

	#ifndef AME_PL330A
	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = pci_get_drvdata( F74930C6A858F43258B265F9ABB2DA5BC );
	#else
	F42A18AF66EFF459eA332CA253FFF8A65* pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)usb_get_intfdata(intf);
	#endif

	unsigned int i = 0;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F8B4E2049BF8D40a696F2510D0478FDC7()\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	//
	// 
	#ifndef AME_PL330A
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6801 ) { if( FALSE == F79D1B9E87BDE4792BDB0AD8801D48CB9( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6802 ) { if( FALSE == F79D1B9E87BDE4792BDB0AD8801D48CB9( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6804 ) { if( FALSE == F79D1B9E87BDE4792BDB0AD8801D48CB9( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6805 ) { if( FALSE == F79D1B9E87BDE4792BDB0AD8801D48CB9( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6810 ) { if( FALSE == F79D1B9E87BDE4792BDB0AD8801D48CB9( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6811 ) { if( FALSE == F79D1B9E87BDE4792BDB0AD8801D48CB9( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6812 ) { if( FALSE == F79D1B9E87BDE4792BDB0AD8801D48CB9( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6813 ) { if( FALSE == F79D1B9E87BDE4792BDB0AD8801D48CB9( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6814 ) { if( FALSE == F79D1B9E87BDE4792BDB0AD8801D48CB9( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6815 ) { if( FALSE == F79D1B9E87BDE4792BDB0AD8801D48CB9( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6816 ) { if( FALSE == F79D1B9E87BDE4792BDB0AD8801D48CB9( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6817 ) { if( FALSE == F79D1B9E87BDE4792BDB0AD8801D48CB9( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x14F1 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x8210 ) { if( FALSE == FDC55275102FD43c4A48060995AD2A497( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1131 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x7160 ) { if( FALSE == DA4990901F0C404EB66C1B0FC874B8DD( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x9413 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6010 ) { if( FALSE == FC59B2DDEB4CD4effBB984F6CD37BDC47( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x5864 ) { if( FALSE == c3575033ae26421c8cee90cc36197e5c( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x3086 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0101 ) { if( FALSE == A6BB52FABC024195927059E4CF9B9ADA( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x0907 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0100 ) { if( FALSE == B16CE70E9F854A62A76BD6F2B7781E3E( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0370 ) { if( FALSE == B16CE70E9F854A62A76BD6F2B7781E3E( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0380 ) { if( FALSE == B16CE70E9F854A62A76BD6F2B7781E3E( pDevice ) ) { ; } }
	if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1AF2 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0xA001 ) { if( FALSE == E8588277E602465EAFD7A57A276FEDF7( pDevice ) ) { ; } }
	#else
	E8588277E602465EAFD7A57A276FEDF7( pDevice );	
	#endif
	// // // // // // // // // // ... // // // // //

	//
	// 
	for( i = 0 ; i < F91863BEB45D34624A724F2D29823D9E3 ; i++ ) {

		//
		// 
		if( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ] ) {

		//	snd_card_free_when_closed( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ] );

			snd_card_free( pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ] );

			pDevice->F1784891F2DFB4dd0896C54A4C0D96463[ i ] = NULL;
		}
		if( pDevice->FCB465449C23D4d298E73233A42203CD6[ i ] ) { 

			pDevice->FCB465449C23D4d298E73233A42203CD6[ i ] = NULL; //
		}
		if( pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ] ) { 

			pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ] = NULL;
		}
		
		//
		// 
		if( pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ] ) { 

			video_set_drvdata( pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ], NULL );

			if( -1 != pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->minor ) { video_unregister_device( pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ] ); }

			if( -1 == pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ]->minor ) { video_device_release( pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ] ); }

			pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ] = NULL;
		}
		//if( pDevice->m_pVideo[ i ] ) { 

		//	pDevice->m_pVideo[ i ] = NULL;
		//}
		int k = 0;
		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			if( pDevice->m_pVideo[ i ][ k ] ) { 

				pDevice->m_pVideo[ i ][ k ] = NULL;
			}
		}
	}

	for( i = 0 ; i < F91863BEB45D34624A724F2D29823D9E3 ; i++ ) {

		//
		// 
		if( pDevice->FB1A1EF5BAA2243f4833747083423997C[ i ] ) {

		//	snd_card_free_when_closed( pDevice->FB1A1EF5BAA2243f4833747083423997C[ i ] );

			snd_card_free( pDevice->FB1A1EF5BAA2243f4833747083423997C[ i ] );

			pDevice->FB1A1EF5BAA2243f4833747083423997C[ i ] = NULL;
		}
		if( pDevice->FF5F61842BBC24b458D103EF08357C4CD[ i ] ) { 

			pDevice->FF5F61842BBC24b458D103EF08357C4CD[ i ] = NULL; //
		}
		if( pDevice->FCD654CA89AC34227BE068F80A85776C6[ i ] ) { 

			pDevice->FCD654CA89AC34227BE068F80A85776C6[ i ] = NULL;
		}
		
		//
		// 
		if( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ] ) { 

			video_set_drvdata( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ], NULL );

			if( -1 != pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->minor ) { video_unregister_device( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ] ); }

			if( -1 == pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ]->minor ) { video_device_release( pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ] ); }

			pDevice->F590A429DF6D145f288A92DDF1547AC46[ i ] = NULL;
		}
		//if( pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ i ] ) { 

		//	pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ i ] = NULL;
		//}
		int k = 0;
		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			if( pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ i ][ k ] ) {
			
				pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ i ][ k ] = NULL;
			}
		}
	}

	//
	// 
	#ifndef AME_PL330A
	if(pDevice->m_IRQ_ready == 0)
	{
		if( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1AF2 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0xA001 )
		{
			NULL;
		}
		else
		{
			free_irq( F74930C6A858F43258B265F9ABB2DA5BC->irq, (PVOID)(pDevice) );
		}
	}

	if( pDevice ) {

		tasklet_kill( &(pDevice->FB12FC3D237104676BD149F25E3D08571) );

		for( i = 0 ; i < F67472E4DF55F4f65AAB4E0860EFF1AD5 ; i++ ) {

			if( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ i ] ) {

				iounmap( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ i ] );

				pDevice->F57270173C138422aA83C0FF58A259F4D[ i ] = 0;

				pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ i ] = NULL;

				pDevice->m_pRegBaseCommonPhysicalBuffer[ i ] = 0;
			}
		}
		for( i = 0 ; i < F933F2ACDBCE3443093DDB4DCB3597BDE ; i++ ) {

			if( pDevice->F41F19BDAA144449fA254B8E3282D1425[ i ] ) {

				dma_free_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, pDevice->FF3B74CCEF832433c856908721A61A034[ i ], pDevice->F41F19BDAA144449fA254B8E3282D1425[ i ], pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i ] );

				pDevice->F66FD293166B14f93A084AE0E6BD0F196[ i ] = 0;
					
				pDevice->F03D1DD650AC64c28B04687338F970D0E[ i ] = 0;

				pDevice->FF3B74CCEF832433c856908721A61A034[ i ] = 0;

				pDevice->F41F19BDAA144449fA254B8E3282D1425[ i ] = NULL;

				pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i ] = 0x00000000;
			}
		}
	}

	{
		int index = 0;

		int cx2581_ch = 0;

		for( index = 0; index < SA7160_MAX_BUFFER; index++ )
		{
			if( pDevice->m_SA7160_video_buffer[ index ] ) 
			{
				dma_free_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, 1920 * 1080 * 2, pDevice->m_SA7160_video_buffer[ index ], pDevice->m_SA7160_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ index ] );

				pDevice->m_SA7160_video_buffer[ index ] = 0;

				pDevice->m_SA7160_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ index ] = 0;

			}
		}

#ifdef TW6805_64bit

		for( index = 0; index < TW6816_MAX_BUFFER; index++ )
		{
			if( pDevice->m_TW6816_video_buffer[ index ] ) 
			{
				dma_free_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, 768 * 576 * 2, pDevice->m_TW6816_video_buffer[ index ], pDevice->m_TW6816_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ index ] );

				pDevice->m_TW6816_video_buffer[ index ] = 0;

				pDevice->m_TW6816_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ index ] = 0;

			}
		}
#endif //TW6805_64bit

#ifdef CX2581_64bit

		for( cx2581_ch = 0; cx2581_ch < 8; cx2581_ch++ )
		{
			for( index = 0; index < CX2581_MAX_BUFFER; index++ )
			{
				if( pDevice->m_CX2581_video_buffer[ cx2581_ch ][ index ] ) 
				{
					dma_free_coherent( &F74930C6A858F43258B265F9ABB2DA5BC->dev, 720 * 576 * 2, pDevice->m_CX2581_video_buffer[ cx2581_ch ][ index ], pDevice->m_CX2581_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ cx2581_ch ][ index ] );

					pDevice->m_CX2581_video_buffer[ cx2581_ch ][ index ] = 0;

					pDevice->m_CX2581_video_buffer_F6F32B5439E4C42f095E08326DFA73107[ cx2581_ch ][ index ] = 0;

				}
			}
		}
	}
#endif //CX2581_64bit


	pci_release_regions( F74930C6A858F43258B265F9ABB2DA5BC );

	pci_disable_device( F74930C6A858F43258B265F9ABB2DA5BC );

	pci_set_drvdata( F74930C6A858F43258B265F9ABB2DA5BC, NULL );

	#endif

	FREE( pDevice );

	#ifdef AME_PL330A
	F6565D1746098454893ED99FB59FED8CF--;
	FDD11F4D2F288473fB7F4E66ED0258C5D--;
	#endif
}

static int F7AC7AD5156484fefAE9BE50C131694AD( struct pci_dev * F74930C6A858F43258B265F9ABB2DA5BC, pm_message_t F8CDF42B603CB436a9B7EB67E32DCF20A )
{
	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = pci_get_drvdata( F74930C6A858F43258B265F9ABB2DA5BC );

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F7AC7AD5156484fefAE9BE50C131694AD()\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) ); 

	return 0;
}

static int F6D23A5636B0944c6A31D79C17B0C1D51( struct pci_dev * F74930C6A858F43258B265F9ABB2DA5BC )
{
	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = pci_get_drvdata( F74930C6A858F43258B265F9ABB2DA5BC );

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F6D23A5636B0944c6A31D79C17B0C1D51()\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	return 0;
}

#ifndef AME_PL330A

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,19)

static irqreturn_t F8A5688FD85F74b49AC6FA87B1FBE25F3( int F6B022DA61D9041f097FAFF570254C019, void * FD51B2B4E0CAC4359A9EFA429A9E16157, struct pt_regs * F2A2C6E4229F04f18B01249677FEECBA6 ) { return IRQ_HANDLED; }

static irqreturn_t F391BB5CA4D5340ebB43E88B1EE6AC5B5( int F6B022DA61D9041f097FAFF570254C019, void * FD51B2B4E0CAC4359A9EFA429A9E16157 )

#else

static irqreturn_t F391BB5CA4D5340ebB43E88B1EE6AC5B5( int F6B022DA61D9041f097FAFF570254C019, void * FD51B2B4E0CAC4359A9EFA429A9E16157 ) { return IRQ_HANDLED; }

static irqreturn_t F8A5688FD85F74b49AC6FA87B1FBE25F3( int F6B022DA61D9041f097FAFF570254C019, void * FD51B2B4E0CAC4359A9EFA429A9E16157, struct pt_regs * F2A2C6E4229F04f18B01249677FEECBA6 )

#endif

{	

	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(FD51B2B4E0CAC4359A9EFA429A9E16157);

	if( pDevice == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F391BB5CA4D5340ebB43E88B1EE6AC5B5() pDevice == NULL\n" );

		return 0;
	}

	ULONG FDA01864545BC42d7BB09ECE078605249 = 0x00000000;

	ULONG interrupt_params = 0x00000000;

	ULONG i = 0;

	if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
		(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6802) ||
		(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ||
		(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6805) ||
		(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6810) || 
	    (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6811) || 
		(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6812) || 
		(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6813) || 
		(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6814) || 
	    (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6815) || 
		(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6816) || 
		(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6817) ) {

		//
		//
		FDA01864545BC42d7BB09ECE078605249 = (ULONG)(readl( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x0000001C ));

		//if( ((FDA01864545BC42d7BB09ECE078605249 & 0xFFFFFFFF) == 0xFFFFFFFF) ) { return IRQ_NONE; }

		//if( ((FDA01864545BC42d7BB09ECE078605249 & 0x1C00006A) == 0x00000000) ) { return IRQ_NONE; }
		
		//for boser
		if( ((FDA01864545BC42d7BB09ECE078605249 & 0xFFFFFFFF) == 0xFFFFFFFF) ) { return IRQ_HANDLED; }

		if( ((FDA01864545BC42d7BB09ECE078605249 & 0x1C00006A) == 0x00000000) ) { return IRQ_HANDLED; }

		if( ((FDA01864545BC42d7BB09ECE078605249 & 0x10000000) == 0x10000000) ||  //
			((FDA01864545BC42d7BB09ECE078605249 & 0x08000000) == 0x08000000) ||  //
			((FDA01864545BC42d7BB09ECE078605249 & 0x04000000) == 0x04000000) ||  //
			((FDA01864545BC42d7BB09ECE078605249 & 0x00000040) == 0x00000040) ||  //
			((FDA01864545BC42d7BB09ECE078605249 & 0x00000020) == 0x00000020) ||  //
			((FDA01864545BC42d7BB09ECE078605249 & 0x00000008) == 0x00000008) ) { //

			// RESTART ENGINE
			// 
			ULONG R00000000 = readl( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00000000 ) & 0xFFFFFFFC; 
		  
			writel( R00000000 | 0x00000000, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00000000 );

			writel( R00000000 | 0x00000003, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00000000 ); 

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] HARDWARE RESET (S:%08X)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(FDA01864545BC42d7BB09ECE078605249) );
		}
		//
		//
		writel( 0x00000000, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00000020 );

		//
		//
		writel( 0xFFFFFFFF, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x0000001C );

		//
		// 
		pDevice->F69679D3D75724cd281AAC93AE8DFDF35 = FDA01864545BC42d7BB09ECE078605249;

		pDevice->F9D066B94377B4a9aB14E37D504955651 = interrupt_params;

		tasklet_hi_schedule( &(pDevice->FB12FC3D237104676BD149F25E3D08571) ); //
	}
	if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) {

		if( pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 == FALSE ) { return IRQ_NONE; }

		for( i = 0 ; i < 8 ; i++ ) {

			ULONG R00040028 = 0x00000000;

			ULONG R00040020 = 0x00000000;

			//
			//
			R00040028 = (ULONG)(readl( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00040028 + (0x00000010 * i) ));

			if( ((R00040028 & 0xFFFFFFFF) == 0xFFFFFFFF) ) { continue ; }

			if( ((R00040028 & 0x00033303) == 0x00000000) ) { continue ; }

		//	if( ((R00040028 & 0x00010000) == 0x00000000) &&  //
		//		((R00040028 & 0x00001000) == 0x00000000) &&  //
		//		((R00040028 & 0x00000100) == 0x00000000) &&  //
		//		((R00040028 & 0x00020000) == 0x00000000) &&  //
		//		((R00040028 & 0x00002000) == 0x00000000) &&  //
		//		((R00040028 & 0x00000200) == 0x00000000) ) { //
		//	}
			if( ((R00040028 & 0x00000001) == 0x00000001) ) { 
				
				FDA01864545BC42d7BB09ECE078605249 |= (0x00000001 << (i + 0)); 
			}
			if( ((R00040028 & 0x00033303) != 0x00000000) ) { 
				
				FDA01864545BC42d7BB09ECE078605249 |= (0x00010000 << (i + 0)); 
			}
			//
			//
			R00040020 = (ULONG)(readl( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00040020 + (0x00000010 * i) ));

			writel( 0x00000000, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00040020 + (0x00000010 * i) );

			//
			// 
			writel( 0x00000001, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00040024 + (0x00000010 * i) );
		}
		for( i = 0 ; i < 4 ; i++ ) {

			ULONG R000400C8 = 0x00000000;

			//
			//
			R000400C8 = (ULONG)(readl( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x000400C8 + (0x00000010 * i) ));

			if( ((R000400C8 & 0xFFFFFFFF) == 0xFFFFFFFF) ) { continue ; }

			if( ((R000400C8 & 0x00033303) == 0x00000000) ) { continue ; }

		//	if( ((R000400C8 & 0x00010000) == 0x00000000) &&  //
		//		((R000400C8 & 0x00001000) == 0x00000000) &&  //
		//		((R000400C8 & 0x00000100) == 0x00000000) &&  //
		//		((R000400C8 & 0x00020000) == 0x00000000) &&  //
		//		((R000400C8 & 0x00002000) == 0x00000000) &&  //
		//		((R000400C8 & 0x00000200) == 0x00000000) ) { //
		//	}
			if( ((R000400C8 & 0x00000001) == 0x00000001) ) { 
				
				FDA01864545BC42d7BB09ECE078605249 |= (0x00000001 << (i + 8)); 
			}
			if( ((R000400C8 & 0x00033303) != 0x00000000) ) { 
				
				FDA01864545BC42d7BB09ECE078605249 |= (0x00010000 << (i + 8)); 
			}
			//
			//
			writel( 0x00000000, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x000400C0 + (0x00000010 * i) );

			//
			// 
			writel( 0x00000001, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x000400C4 + (0x00000010 * i) );
		}
		if( FDA01864545BC42d7BB09ECE078605249 == 0x00000000 ) {
			
			return IRQ_NONE;
		} 
		for( i = 0 ; i < 8 ; i++ ) {

			//
			// 
			writel( 0x00000000, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00040020 + (0x00000010 * i) );
		}
		for( i = 0 ; i < 4 ; i++ ) {

			//
			//
			writel( 0x00000000, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x000400C0 + (0x00000010 * i) );
		}
		//
		//
		pDevice->F69679D3D75724cd281AAC93AE8DFDF35 = FDA01864545BC42d7BB09ECE078605249;

		pDevice->F9D066B94377B4a9aB14E37D504955651 = interrupt_params;

		pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = FALSE;

		tasklet_hi_schedule( &(pDevice->FB12FC3D237104676BD149F25E3D08571) ); //
	}
	if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x7160) ) {

//		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "F5C8C1DAFA2D74241A96FE41ED93197F8(0x%x)\n", pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 );

		//if( pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 == FALSE ) { return IRQ_NONE; }
		
		if( pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 == FALSE ) { return IRQ_HANDLED; }//for IRQ nobody cared

		//
		//
		ULONG R0000AFC0 = (ULONG)(readl( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x0000A000 + 0x0FC0)); // MSI.INT.STATUS.L

		ULONG R0000AFC4 = (ULONG)(readl( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x0000A000 + 0x0FC4)); // MSI.INT.STATUS.H

//		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "R0000AFC0(0x%x) R0000AFC4(0x%x)\n", R0000AFC0, R0000AFC4 );

		if( R0000AFC0 == 0x00000000 && R0000AFC4 == 0x00000000 ) { return IRQ_NONE ; }

		if( R0000AFC0 == 0xFFFFFFFF && R0000AFC4 == 0xFFFFFFFF ) { return IRQ_NONE ; }

		if( R0000AFC0 & 0x00000001 )
		{
			//register 0xFE0 will change very fast, get it ASAP
			pDevice->F9D066B94377B4a9aB14E37D504955651 = interrupt_params = A77C4935F8134B048348571A43F2A9CA( pDevice, 0x00000000 + 0x00000FE0 );

			//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] interrupt_params(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, interrupt_params );
		}

		//
		//
		if( R0000AFC0 ) { writel( R0000AFC0, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x0000A000 + 0x0FC8 ); } // MSI.INT.STATUS.CLR.L

		if( R0000AFC4 ) { writel( R0000AFC4, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x0000A000 + 0x0FCC ); } // MSI.INT.STATUS.CLR.H

		if( R0000AFC0 & 0x00000C01 )
		{
			//
			// 
			pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = FALSE;

			pDevice->F69679D3D75724cd281AAC93AE8DFDF35 = FDA01864545BC42d7BB09ECE078605249 = R0000AFC0;

			//pDevice->F9D066B94377B4a9aB14E37D504955651 = interrupt_params = R0000AFC4;
			
			
			tasklet_hi_schedule( &(pDevice->FB12FC3D237104676BD149F25E3D08571) ); //
		}
	}
	if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) {

//		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TW5864() interrupt\n" );

		if( pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 == FALSE ) { return IRQ_HANDLED; }

		//
		//
		FDA01864545BC42d7BB09ECE078605249 = (ULONG)(readl( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018000 ));

		if( ((FDA01864545BC42d7BB09ECE078605249 & 0xFFFFFFFF) == 0xFFFFFFFF) ) { return IRQ_NONE; }

		if( ((FDA01864545BC42d7BB09ECE078605249 & 0xFFFFFFFF) == 0x00000000) ) { return IRQ_NONE; }

		//
		//
		writel( 0x0000FF37, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018004 );

		if( FDA01864545BC42d7BB09ECE078605249 & 0x00000020 ) { // ISIL_INTR_OVERFLOW

			writel( 0x00000020, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018000 );

			writel( 0x00000001, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x0000C02C );// 解決 SC3B0N16 平台當機問題

			//
			//
			writel( 0x0000FF77, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018004 );

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "ISIL.INTR.OVERFLOW#%02d\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

			return IRQ_HANDLED;
		}

		if( FDA01864545BC42d7BB09ECE078605249 & 0x00000002 ) {

			ULONG R00001004 = 0x00000000;
			
			//
			// 
			writel( 0x00000002, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018000 );

			writel( 0x00000001, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00008814 );

			R00001004 = (ULONG)(readl( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00001004 ));

			if( R00001004 > (384 * 1024 * 8) ) { R00001004 = (384 * 1024 * 8); }
	
			if( R00001004 > (0x00097E00 * 8) ) { R00001004 = (0x00097E00 * 8); }

			pDevice->F69679D3D75724cd281AAC93AE8DFDF35 = 0x00000002;

			pDevice->F9D066B94377B4a9aB14E37D504955651 = R00001004;

			goto TW5864_DPC_JUMP;
		}
		if( FDA01864545BC42d7BB09ECE078605249 & 0x00000040 ) {

			//
			// 
			writel( 0x00000040, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018000 );

			pDevice->F69679D3D75724cd281AAC93AE8DFDF35 = 0x00000040;

			pDevice->F9D066B94377B4a9aB14E37D504955651 = 0x00000000;

			goto TW5864_DPC_JUMP;
		}
		if( FDA01864545BC42d7BB09ECE078605249 & 0x00000010 ) {

			ULONG R00018008 = 0x00000000;

			ULONG R00018010 = 0x00000000;

			ULONG i = 0;

			//
			// 
			writel( 0x00000010, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018000 );

			R00018008 = (ULONG)(readl( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018008 )) & 0x0000FFFF;

			R00018010 = (ULONG)(readl( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018010 )) & 0x0000FFFF;

			pDevice->F69679D3D75724cd281AAC93AE8DFDF35 = 0x00000010;

			pDevice->F9D066B94377B4a9aB14E37D504955651 = (R00018010 << 16) | (R00018008 << 0);

			for( i = 0 ; i < 16 ; i++ ) {

				if( (R00018008 >> i) & 0x01 ) {

					writel( (1) << (i + 0), pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018008 );

					writel( (1) << (i + 5), pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00008814 );
				}
			}
			goto TW5864_DPC_JUMP;
		}	
		if( FDA01864545BC42d7BB09ECE078605249 & 0x00000100 ) {

			ULONG R00018008 = 0x00000000;

			ULONG R00018010 = 0x00000000;

			ULONG i = 0;

			//
			// 

			writel( 0x000000100, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018000 );

			R00018008 = (ULONG)(readl( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018008 )) >> 16;

			R00018010 = (ULONG)(readl( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018010 )) >> 16;

			pDevice->F69679D3D75724cd281AAC93AE8DFDF35 = 0x00000100;

			pDevice->F9D066B94377B4a9aB14E37D504955651 = (R00018010 << 16) | (R00018008 << 0);

			for( i = 0 ; i < 16 ; i++ ) {

				if( (R00018008 >> i) & 0x01 ) {

					writel( (1) << (i + 16), pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018008 );

					writel( (1) << (i + 9), pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00008814 );
				}
			}
			goto TW5864_DPC_JUMP;
		}	

		//
		// 
		writel( FDA01864545BC42d7BB09ECE078605249, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018000 );

		if( FDA01864545BC42d7BB09ECE078605249 & 0x00000020 ) { // ISIL_INTR_OVERFLOW

			writel( 0x00000001, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x0000C02C );// 解決 SC3B0N16 平台當機問題
		}

		//
		//
		writel( 0x0000FF77, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018004 );

		return IRQ_HANDLED;


TW5864_DPC_JUMP:

		pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = FALSE;

		tasklet_hi_schedule( &(pDevice->FB12FC3D237104676BD149F25E3D08571) ); //
	}

//peter [2011.06.29]
	if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) {

//		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735() interrupt------------ F5C8C1DAFA2D74241A96FE41ED93197F8(0x%x)\n", pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 );
//FH8735 does not need to disable/enable interrupt
		if( pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 == FALSE ) { return IRQ_HANDLED; }

		//
		// 
		ULONG checks = (ULONG) (readl(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 1 ] + 0x0040001C));
		
//		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%d]FH8735() interrupt -------- checks = %08X\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), checks );

		if( ((checks & 0xFFFFFFFF) == 0x00000000) ) { return IRQ_HANDLED; }

		ULONG status = (ULONG) readl( (ULONG *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 1 ] + 0x00400008) ) & 0x0000FFFF;

//		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%d]FH8735() interrupt -------- status = %08X\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), status );

		if( ((status & 0xFFFFFFFF) == 0xFFFFFFFF) ) { return IRQ_HANDLED; }

		if( ((status & 0xFFFFFFFF) == 0x00000000) ) { return IRQ_HANDLED; }

		if( status == 0x00000013 ) { // HCMD_REQ_DATA

			pDevice->F9D066B94377B4a9aB14E37D504955651 = (ULONG) readl( (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 1 ] + 0x00400078) );

			writel( 0x00000000, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 1 ] + 0x00400078 );
		}

		pDevice->F69679D3D75724cd281AAC93AE8DFDF35 = status; 
		
		pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = FALSE;

		tasklet_hi_schedule( &(pDevice->FB12FC3D237104676BD149F25E3D08571) );
	}

	if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

		(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			
		(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
	{

		if( pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 == 0x00000000 ) { return IRQ_HANDLED; }

		//
		// 
		ULONG status = readl( (ULONG *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00000030) );

		if( ((status & 0xFFFFFFFF) == 0xFFFFFFFF) ) { return FALSE; }

		if( ((status & 0xFFFFFFFF) == 0x00000000) ) { return FALSE; }

		ULONG arguments = 0x00000000;

		//
		//
		writel( 0x00000002, (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 5 ] + 0x000000DC) ); // 手動清掉 INTX 中斷, 否則會一直發中斷不會停 (為什麼非 MSI 模式還不知道)

		writel( 0x00000000, (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00000030) ); // 這段程式必須清除中斷

		writel( 0x00000400, (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00000000) ); // 通知硬體可以發下個 INT 了

		if( status & 0x00000800 ) {

			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "OnInterruptHandle( %04x %04x %04x * 0x00000030 = 0x%08X )\n", pDevice->idVendor, pDevice->idProduct, pDevice->bcdDevice, status);
		}
		pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = 0x00000000;

		pDevice->F69679D3D75724cd281AAC93AE8DFDF35 = status; 

		tasklet_hi_schedule( &(pDevice->FB12FC3D237104676BD149F25E3D08571) );

		pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = 0x00000001;
	}
	if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0xA001) ) {

		NULL; 
	}
//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_pci_driver_on_interrupt( S:%08X, M:%08X )\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(FDA01864545BC42d7BB09ECE078605249), (unsigned int)(interrupt_params) );

	return IRQ_HANDLED; 
}
#endif

// ##############################################################################################################################################################################
//
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,29)

static int F974CC188B92849b9A9A52461E68698A2( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4 )

#else

static int F974CC188B92849b9A9A52461E68698A2( struct inode * F9E62F5638C29456b95618E44A5D0C9F3, struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4 )

#endif
{
	struct video_device * F6CA67B866FA04fab8C939AEA549AEEBA = (struct video_device *)(video_devdata( FEBA6DA02A6244ff7AFA9DCC660800FB4 ));

	if( F6CA67B866FA04fab8C939AEA549AEEBA == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F974CC188B92849b9A9A52461E68698A2() F6CA67B866FA04fab8C939AEA549AEEBA == NULL\n" );

		return 0;
	}

	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(video_get_drvdata( F6CA67B866FA04fab8C939AEA549AEEBA ));

	if( pDevice == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F974CC188B92849b9A9A52461E68698A2() pDevice == NULL\n" );

		return 0;
	}

	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = NULL;

	int ret = 0;

	int is_success = 0;

	//for different thread must not be interruptable
	if( 0 == wait_event_timeout( m_wait_queue_component, m_component_ready == 1, msecs_to_jiffies( 6000 ) )){
	
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F974CC188B92849b9A9A52461E68698A2() time out(2)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );
	} 
	else { 
		
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F974CC188B92849b9A9A52461E68698A2() success(2), m_component_ready(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, m_component_ready );
		
		down( &m_sComponentAccessSemaphore ); 

		m_component_ready = 0;

		up( &m_sComponentAccessSemaphore ); 
	} 


	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F974CC188B92849b9A9A52461E68698A2()\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(kmalloc( sizeof(struct F301FA49098CE4d9eB95F22BBD388E837), GFP_KERNEL ));

	if( pVideo == NULL ) {

		F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F974CC188B92849b9A9A52461E68698A2() - kmalloc() - [FAIL]\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

		ret = -ENOMEM;

		goto F974CC188B92849b9A9A52461E68698A2_fail;
	}
	else {

		memset( pVideo, 0, sizeof(struct F301FA49098CE4d9eB95F22BBD388E837) );

		BYTE F675786930896474f9DA4061E2FD16EC5[ 13 ] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 };

	//	BYTE F675786930896474f9DA4061E2FD16EC5[ 13 ] = { 0x00, 0x01, 0x02, 0x03, 0x00, 0x01, 0x02, 0x03, 0x00, 0x01, 0x02, 0x03, 0x0F };
	
	//	BYTE F675786930896474f9DA4061E2FD16EC5[ 13 ] = { 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x03 };

		unsigned int F60CA5EA814604b04A15099F1FD94C684 = 0;

		unsigned int F43FF52E68CCE447dBD4CA805D6B9C13C = 0x00000000;

		unsigned int i = 0;

		unsigned int j = 0;

		for( i = 0 ; i < F91863BEB45D34624A724F2D29823D9E3 ; i++ ) { //
			
			if( F6CA67B866FA04fab8C939AEA549AEEBA == pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ i ] ) { break; }
		} 
		for( j = 0 ; j < F91863BEB45D34624A724F2D29823D9E3 ; j++ ) { //
			
			if( F6CA67B866FA04fab8C939AEA549AEEBA == pDevice->F590A429DF6D145f288A92DDF1547AC46[ j ] ) { break; }
		}
		if( i < 16 ) { F60CA5EA814604b04A15099F1FD94C684 = i; F43FF52E68CCE447dBD4CA805D6B9C13C = 0x00000001; } //

		if( j < 16 ) { F60CA5EA814604b04A15099F1FD94C684 = j; F43FF52E68CCE447dBD4CA805D6B9C13C = 0x00000002; } //

		pVideo->FB6E79A0780E64bb28A3308666E67881C                         = video_get_drvdata( video_devdata( FEBA6DA02A6244ff7AFA9DCC660800FB4 ) );
		pVideo->F0DD7393CD1494e27A72652C7D1A97893                = F60CA5EA814604b04A15099F1FD94C684;
		pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E                  = F43FF52E68CCE447dBD4CA805D6B9C13C;

		if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001 )
		{
			int preview_node_opened_counter = 0;

			int k = 0;
			for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
			{
				char for_control_counter = 40;// * 5 ms //must be signed, it will turn to -1

				#ifndef AME_PL330A
				if( pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0xA001 )
				#endif
				{
					//wait 1 second to let previous stopfirmware setcrossbar thread finish
					struct timeval ts;

					do_gettimeofday( &ts );

					ULONGLONG start_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);

					if( (start_times - pDevice->m_pl330b_stopfirmware_time) > 1200000)
					{
						NULL;
					}
					else
					{
						if( (start_times - pDevice->m_pl330b_stopfirmware_time) > 0 ) 
						{
							ULONGLONG diff = 1200000 - ( start_times - pDevice->m_pl330b_stopfirmware_time );
					
							do_div( diff, 1000);

							schedule_timeout_interruptible( msecs_to_jiffies( diff ) );
						}
					}
				}

				while( pDevice->m_pVideo[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] )
				{
					//wait to discard thread control to see if there is other thread( buf_release) need to do their work, turn m_pVideo[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] to NULL

					schedule_timeout_interruptible( msecs_to_jiffies( 5 ) );

					if(for_control_counter--)
					{
						continue;
					}

					break;//for_control_counter is 0
				}

				if( for_control_counter > 0 )//m_pVideo[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] not exist
				{
					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F974CC188B92849b9A9A52461E68698A2() k(%d) not exists, for_control_counter(%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), k, for_control_counter );

					break;
				}
				else //( for_control_counter == 0 )//m_pVideo[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] really exist
				{
					preview_node_opened_counter++;

					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F974CC188B92849b9A9A52461E68698A2() k(%d) really exists\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), k );
				}
			}//end of for

			if( preview_node_opened_counter >= MAX_DEVICE_OPEN_NUM )
			{
				FREE( pVideo );

				down( &m_sComponentAccessSemaphore ); 

				m_component_ready = 1;

				up( &m_sComponentAccessSemaphore ); 
				
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] F974CC188B92849b9A9A52461E68698A2() over limit, preview_node_opened_counter(%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), preview_node_opened_counter );
	
				return -ENOMEM;
			}

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F974CC188B92849b9A9A52461E68698A2() open preview k(%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), k );
		}

		if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002 )
		{
			int encode_node_opened_counter = 0;

			int k = 0;
			for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
			{
				char for_control_counter = 40;// * 5 ms //must be signed, it iwll turn to -1

				while( pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] )
				{
					//wait to discard thread control to see if there is other thread( buf_release) need to do their work, turn m_pVideo[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] to NULL
					schedule_timeout_interruptible( msecs_to_jiffies( 5 ) ); 

					if(for_control_counter--)
					{
						continue;
					}

					break;//for_control_counter is 0
				}

				if( for_control_counter > 0 )//m_pVideo[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] not exist
				{
					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F974CC188B92849b9A9A52461E68698A2() k(%d) not exists, for_control_counter(%d)--\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), k, for_control_counter );

					break;
				}
				else //( for_control_counter == 0 )//m_pVideo[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] really exist
				{
					encode_node_opened_counter++;

					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F974CC188B92849b9A9A52461E68698A2() k(%d) really exists --\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), k );
				}
			}//end of for

			if( encode_node_opened_counter >= MAX_DEVICE_OPEN_NUM )
			{
				FREE( pVideo );

				down( &m_sComponentAccessSemaphore ); 

				m_component_ready = 1;

				up( &m_sComponentAccessSemaphore ); 
				
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] F974CC188B92849b9A9A52461E68698A2() over limit, encode_node_opened_counter(%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), encode_node_opened_counter );
	
				return -ENOMEM;
			}

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F974CC188B92849b9A9A52461E68698A2() open encode k(%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), k );
		}

		pVideo->F18B6587C912F463c932DEE9FF8B93AAE                       = pDevice->FD314ADAD9404496b842EBFC396E875CB;
		pVideo->FECCF92CAC5DC4194925ADBF80EFC3B63                          = pDevice->m_nAnalogCrossbarVideoInputProperty;
		pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9                     = 0;
		pVideo->F3390EC7F04704cc1A843000DB76617C3 = 0;
		pVideo->FE9AF51EBD0D4401eA4E5E0F6868A9A53 = 0;
		pVideo->FD49577B6E6624669BFA3A840079514E8           = 0;
		pVideo->F3FCE6081A67349839E69BEDE056CFEED                  = (pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (            352) : (            352);
		pVideo->F2039B582640548a6B3F55D13092DCF5F                 = (pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (            240) : (            288);
		pVideo->F10CC5793AEB4486dA7AFE99A1176E51D               = (pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (             16) : (             16);
		pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003                   = (pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (  352 * 240 * 2) : (  352 * 288 * 2);
		pVideo->FD1832F8D382F4e91914C0048CC5A9DD8                  = (pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (            352) : (            352);
		pVideo->F5B8891B732954fc2B26B7BFFCB15B596                 = (pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (            240) : (            288);
		pVideo->F71FE13C55F1948828A7FA0A0A5800543                  = (pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (           704) : (           704);
		pVideo->FFA9FA378762B440d9F8489DE5A6432B3               = (pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (             16) : (             16);
		pVideo->F07563F8419D74e1cB3F1A4F962EBACE8                   = (pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (  352 * 240 * 2) : (  352 * 288 * 2);

		#ifdef CUEBI_WEBRTC
		pVideo->FD1832F8D382F4e91914C0048CC5A9DD8                  = 1920;
		pVideo->F5B8891B732954fc2B26B7BFFCB15B596                 = 1080;
		pVideo->F71FE13C55F1948828A7FA0A0A5800543                  = pVideo->FD1832F8D382F4e91914C0048CC5A9DD8;
		pVideo->FFA9FA378762B440d9F8489DE5A6432B3               = 16;
		pVideo->F07563F8419D74e1cB3F1A4F962EBACE8                   = pVideo->FD1832F8D382F4e91914C0048CC5A9DD8 * pVideo->F5B8891B732954fc2B26B7BFFCB15B596 * 2;
		#endif


		pVideo->FA8153D6A19C2451d94BB0F52E68471F1               = V4L2_PIX_FMT_YUYV;
		pVideo->FEDE037FA62F943829C230928859309D9                = V4L2_FIELD_INTERLACED;
		pVideo->FB4E9A11D151C4d93B0C750EC1BE4C7C5                      = (pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (          30000) : (          25000);
		pVideo->F6578ACFCB40E44819A12FD3E27A48085                    = 0;
		pVideo->F8C5A9629DDA74022A5888D194EA3D926              = 0;
		pVideo->F3D935AFB5C164dac97F5A7CA0150BC60                    = V4L2_MPEG_VIDEO_BITRATE_MODE_CBR;
		pVideo->F65C8BF3BAA2D4fbb876EE33F491F1931                 = (pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (4 * 1024 * 1024) : (4 * 1024 * 1024);
		pVideo->FF63087B4098B4de18859989009950824                 = (pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (           6000) : (           6000);
		pVideo->F1CA927B5918D436c9F5839C9727D620E                     = (pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (             30) : (             25);
		pVideo->FD9E5DCB7C0F94c32AF5A086BA8C007EC                  = (pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (              1) : (              1);
		pVideo->FB5D90351C9FF410eBE4CB7D22E016687            = NULL;
		pVideo->m_video_preview_frame_number	  = 0;

		#ifndef AME_PL330A
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ) { j =  0; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6802) ) { j =  1; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ) { j =  2; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6805) ) { j =  3; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ) { j =  4; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ) { j =  5; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ) { j =  6; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) { j =  7; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6814) ) { j =  8; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6815) ) { j =  9; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6816) ) { j = 10; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6817) ) { j = 11; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) { j = 12; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x5851) ) { j = 13; } // shawn 2010.07.26
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x7160) ) { j = 14; } // shawn 2010.07.26
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1999 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0xA04C) ) { j = 15; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) { j = 16; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) { j = 17; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ) { j = 18; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ) { j = 19; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0380) ) { j = 19; }
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0xA001) ) { j = 20; }
		#else
		{ j = 20; }
		#endif

		spin_lock_init( &(pVideo->F4ECA473514304aecA7885A0D80438003) );

		spin_lock_init( &(pVideo->FE0A97B802F3C400aBD7CD5D313825C31) );

		memcpy( pVideo->F59B6B40F8D70445eB5D4ACA63BE8A26E, F675786930896474f9DA4061E2FD16EC5, 12 );

		pVideo->FA7E81415668A414bB9DED82DB85E4B48 = F675786930896474f9DA4061E2FD16EC5[ 12 ];

		pVideo->F3F00596420D64210BB4DDAF0945F5388 = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 7 + 2 ];

		if (mutex_lock_interruptible( &(pDevice->m_sSGSemaphore) ) )
		{
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F974CC188B92849b9A9A52461E68698A2() -get mutex- [FAIL]\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

			FREE( pVideo );

			ret = -ENOMEM;

			goto F974CC188B92849b9A9A52461E68698A2_fail;
		}

		//
		//
		#ifndef AME_PL330A
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160) ||
			//(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001)	)
			{

			FADD02C9C13B14f83989880EFACB8D8DC [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  0 + 2 ];
			FADD02C9C13B14f83989880EFACB8D8DC [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 1 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  0 + 2 ];
			FADD02C9C13B14f83989880EFACB8D8DC [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 2 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  0 + 2 ];
			FADD02C9C13B14f83989880EFACB8D8DC [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 3 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  0 + 2 ];
			F3A66BD0F0BCB4afcAD006E378E671B9A   [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  1 + 2 ];
			F3A66BD0F0BCB4afcAD006E378E671B9A   [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 1 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  1 + 2 ];
			F3A66BD0F0BCB4afcAD006E378E671B9A   [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 2 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  1 + 2 ];
			F3A66BD0F0BCB4afcAD006E378E671B9A   [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 3 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  1 + 2 ];
			F925442591E22492f9239C6028CE3DD94 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  2 + 2 ];
			F925442591E22492f9239C6028CE3DD94 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 1 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  2 + 2 ];
			F925442591E22492f9239C6028CE3DD94 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 2 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  2 + 2 ];
			F925442591E22492f9239C6028CE3DD94 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 3 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  2 + 2 ];
			F42BAA55A84E847faA4D0C0565699845E        [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  3 + 2 ];
			F42BAA55A84E847faA4D0C0565699845E        [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 1 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  3 + 2 ];
			F42BAA55A84E847faA4D0C0565699845E        [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 2 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  3 + 2 ];
			F42BAA55A84E847faA4D0C0565699845E        [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 3 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  3 + 2 ];
			F1D56E1ED762E4b99BB2BD370DFE317D1  [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  4 + 2 ];
			F1D56E1ED762E4b99BB2BD370DFE317D1  [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 1 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  4 + 2 ];
			F1D56E1ED762E4b99BB2BD370DFE317D1  [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 2 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  4 + 2 ];
			F1D56E1ED762E4b99BB2BD370DFE317D1  [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 3 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  4 + 2 ];
			FF41F97A51B484aaa8170BEE8828CFCF0  [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  5 + 2 ];
			F9CA17C2FDE5B4c94B2594B65842E7387       [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  6 + 2 ];
			FC9D92723A8E44565883875F77CA4E561[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ]      = 0x103;
			g_n_gpio_direction            [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 18 + 2 ];
			g_n_gpio_data                 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 19 + 2 ];
		}
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) )
		{
			if(pVideo->F0DD7393CD1494e27A72652C7D1A97893 < 4)//only for preview and main H264, not for sub H264
			{
				FADD02C9C13B14f83989880EFACB8D8DC [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  0 + 2 ];
				F3A66BD0F0BCB4afcAD006E378E671B9A   [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  1 + 2 ];
				F925442591E22492f9239C6028CE3DD94 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  2 + 2 ];
				F42BAA55A84E847faA4D0C0565699845E        [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  3 + 2 ];
				F1D56E1ED762E4b99BB2BD370DFE317D1  [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  4 + 2 ];
				FF41F97A51B484aaa8170BEE8828CFCF0  [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ] 							  = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  5 + 2 ];
				F9CA17C2FDE5B4c94B2594B65842E7387       [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ] 							  = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  6 + 2 ];
				FC9D92723A8E44565883875F77CA4E561[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ] 							  = 0x103;
				g_n_gpio_direction            [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ] 							  = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 18 + 2 ];
				g_n_gpio_data                 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ] 							  = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 19 + 2 ];
			}
		}


		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5851) ) {

			FADD02C9C13B14f83989880EFACB8D8DC [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 8 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  0 + 2 ];
			F3A66BD0F0BCB4afcAD006E378E671B9A   [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 8 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  1 + 2 ];
			F925442591E22492f9239C6028CE3DD94 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 8 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  2 + 2 ];
			F42BAA55A84E847faA4D0C0565699845E        [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 8 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  3 + 2 ];
			F1D56E1ED762E4b99BB2BD370DFE317D1  [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 8 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  4 + 2 ];
			FF41F97A51B484aaa8170BEE8828CFCF0  [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 8 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  5 + 2 ];
			F9CA17C2FDE5B4c94B2594B65842E7387       [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 8 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  6 + 2 ];
			FC9D92723A8E44565883875F77CA4E561[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 8 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = 0x103;
			g_n_gpio_direction            [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 8 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 18 + 2 ];
			g_n_gpio_data                 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 8 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 19 + 2 ];
		}
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x9413 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6010) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1999 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA04C) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864)  ) {

			FADD02C9C13B14f83989880EFACB8D8DC                    [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  0 + 2 ];
			F3A66BD0F0BCB4afcAD006E378E671B9A                      [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  1 + 2 ];
			F925442591E22492f9239C6028CE3DD94                    [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  2 + 2 ];
			F42BAA55A84E847faA4D0C0565699845E                           [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  3 + 2 ];
			F1D56E1ED762E4b99BB2BD370DFE317D1                     [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  4 + 2 ];
			FF41F97A51B484aaa8170BEE8828CFCF0                     [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  5 + 2 ];
			F9CA17C2FDE5B4c94B2594B65842E7387                          [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  6 + 2 ];
			FC9D92723A8E44565883875F77CA4E561                   [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = 0x103;
			F5DCAF3AAB0BA4f659145B0B8C7EB74F6                    [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  9 + 2 ];
			FB5061B6847674d5cAA4512F2524B22CA [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 10 + 2 ];
			FB4585649D2BE488f8DAB3BE4ACEC1C0C[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 11 + 2 ];
			F24FF8C85BBB142d68BD24A8AEE14C2A0                   [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 12 + 2 ];
			F9245F416BCD64da6857AA7F60AC69BDC                   [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 13 + 2 ];
			FCF4231953179448dA85C9CE2854BDAB0                            [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 14 + 2 ];
			FAB3E37A5903246ce815D399EE1B19200                            [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 15 + 2 ];			
			F9C0567FC340549ddAF206705D1028554                            [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 16 + 2 ];			
			g_n_gpio_direction								 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 18 + 2 ];
			g_n_gpio_data									 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 19 + 2 ];
		}

		//
		//

//for FC16 X64 , kernel 3.4.9  4G RAM NULL->pVideo->FB6E79A0780E64bb28A3308666E67881C
//for FC16 X64 , kernel 3.4.6  NULL->pVideo->FB6E79A0780E64bb28A3308666E67881C
//for Ubuntu 12.04, kernel 3.2.0 , 4G RAM NULL->pVideo->FB6E79A0780E64bb28A3308666E67881C
//for FC16 X64 , kernel 3.1.0  , 4G RAM, NULL->pVideo->FB6E79A0780E64bb28A3308666E67881C, 3G NULL, 2G NULL

//for Ubuntu 12.04, kernel 3.2.0-24 , 4G RAM NULL
//for FC16 X86 , kernel 3.4.6  NULL->pVideo->FB6E79A0780E64bb28A3308666E67881C
//for FC16 X86 , kernel 3.1.0  NULL
//for Ubuntu 12.04 kernel3.2.0-31-generic 4G NULL
//for Ubuntu 12.04 kernel3.2.0-23-generic 4G NULL

		if(	(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5851) ){

			#ifdef CX2581_64bit
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,37)

				#ifdef LINUXV4L2_VMALLOC_MODULE

				videobuf_queue_vmalloc_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, &pDevice->F9D9594A095F0463193B7588374CF8310->dev, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo, &(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_sSGSemaphore) ); // [PETER] 

				#endif

				#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

				#ifdef LINUXV4L2_VMALLOC_MODULE

				videobuf_queue_vmalloc_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, pVideo->FB6E79A0780E64bb28A3308666E67881C, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

				#endif

				#else

				videobuf_queue_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, pVideo->FB6E79A0780E64bb28A3308666E67881C, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

				#endif
			#else
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,1,0)

				#ifdef CONFIG_64BIT
					videobuf_queue_sg_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, pVideo->FB6E79A0780E64bb28A3308666E67881C, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo, &(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_sSGSemaphore) ); // [PETER]
				#else
					videobuf_queue_sg_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, NULL, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo, &(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_sSGSemaphore) ); // [PETER]
				#endif

				#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,7,0)

				videobuf_queue_sg_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, NULL, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo, &(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_sSGSemaphore) ); // [PETER]

				#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,37)

				videobuf_queue_sg_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, NULL, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo, &(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_sSGSemaphore) ); // [PETER]

				#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,26)

				videobuf_queue_sg_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, NULL, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

				#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

				videobuf_queue_pci_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, NULL, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

				#else

				videobuf_queue_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, pVideo->FB6E79A0780E64bb28A3308666E67881C, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

				#endif
			#endif
		}
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160) )
		{
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,7,0)

				videobuf_queue_sg_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, &(pDevice->F9D9594A095F0463193B7588374CF8310->dev), &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo, &(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_sSGSemaphore) ); // [PETER]

				#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,37)

				videobuf_queue_sg_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, &(pDevice->F9D9594A095F0463193B7588374CF8310->dev), &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo, &(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_sSGSemaphore) ); // [PETER]

				#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,26)

				videobuf_queue_sg_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, &(pDevice->F9D9594A095F0463193B7588374CF8310->dev), &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

				#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

				videobuf_queue_pci_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, &(pDevice->F9D9594A095F0463193B7588374CF8310->dev), &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

				#else

				videobuf_queue_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, pVideo->FB6E79A0780E64bb28A3308666E67881C, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

				#endif

		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1999 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA04C) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001)) {
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,37)

			#ifdef LINUXV4L2_VMALLOC_MODULE

			videobuf_queue_vmalloc_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, &pDevice->F9D9594A095F0463193B7588374CF8310->dev, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo, &(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_sSGSemaphore) ); // [PETER] 

			#endif

			#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

			#ifdef LINUXV4L2_VMALLOC_MODULE

			videobuf_queue_vmalloc_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, pVideo->FB6E79A0780E64bb28A3308666E67881C, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

			#endif

			#else

			videobuf_queue_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, pVideo->FB6E79A0780E64bb28A3308666E67881C, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

			#endif
		}
		if(	(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817) ){
			
			#ifdef TW6805_64bit

				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,37)

				#ifdef LINUXV4L2_VMALLOC_MODULE

				videobuf_queue_vmalloc_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, &pDevice->F9D9594A095F0463193B7588374CF8310->dev, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo, &(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_sSGSemaphore) ); // [PETER] 

				#endif

				#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

				#ifdef LINUXV4L2_VMALLOC_MODULE

				videobuf_queue_vmalloc_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, pVideo->FB6E79A0780E64bb28A3308666E67881C, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

				#endif

				#else

				videobuf_queue_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, pVideo->FB6E79A0780E64bb28A3308666E67881C, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

				#endif

			#else

				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,7,0)

				videobuf_queue_sg_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, NULL, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo, &(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_sSGSemaphore) ); // [PETER]

				#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,37)

				videobuf_queue_sg_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, NULL, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo, &(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_sSGSemaphore) ); // [PETER]

				#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,26)

				videobuf_queue_sg_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, NULL, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

				#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

				videobuf_queue_pci_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, NULL, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

				#else

				videobuf_queue_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, pVideo->FB6E79A0780E64bb28A3308666E67881C, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

				#endif

			#endif //TW6805_64bit

		}
		#else
		{
			FADD02C9C13B14f83989880EFACB8D8DC [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  0 + 2 ];
			FADD02C9C13B14f83989880EFACB8D8DC [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 1 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  0 + 2 ];
			FADD02C9C13B14f83989880EFACB8D8DC [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 2 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  0 + 2 ];
			FADD02C9C13B14f83989880EFACB8D8DC [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 3 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  0 + 2 ];
			F3A66BD0F0BCB4afcAD006E378E671B9A   [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  1 + 2 ];
			F3A66BD0F0BCB4afcAD006E378E671B9A   [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 1 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  1 + 2 ];
			F3A66BD0F0BCB4afcAD006E378E671B9A   [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 2 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  1 + 2 ];
			F3A66BD0F0BCB4afcAD006E378E671B9A   [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 3 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  1 + 2 ];
			F925442591E22492f9239C6028CE3DD94 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  2 + 2 ];
			F925442591E22492f9239C6028CE3DD94 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 1 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  2 + 2 ];
			F925442591E22492f9239C6028CE3DD94 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 2 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  2 + 2 ];
			F925442591E22492f9239C6028CE3DD94 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 3 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  2 + 2 ];
			F42BAA55A84E847faA4D0C0565699845E        [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  3 + 2 ];
			F42BAA55A84E847faA4D0C0565699845E        [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 1 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  3 + 2 ];
			F42BAA55A84E847faA4D0C0565699845E        [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 2 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  3 + 2 ];
			F42BAA55A84E847faA4D0C0565699845E        [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 3 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  3 + 2 ];
			F1D56E1ED762E4b99BB2BD370DFE317D1  [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 0 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  4 + 2 ];
			F1D56E1ED762E4b99BB2BD370DFE317D1  [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 1 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  4 + 2 ];
			F1D56E1ED762E4b99BB2BD370DFE317D1  [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 2 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  4 + 2 ];
			F1D56E1ED762E4b99BB2BD370DFE317D1  [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ][ 3 ] = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  4 + 2 ];
			FF41F97A51B484aaa8170BEE8828CFCF0  [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  5 + 2 ];
			F9CA17C2FDE5B4c94B2594B65842E7387       [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][  6 + 2 ];
			FC9D92723A8E44565883875F77CA4E561[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ]      = 0x103;
			g_n_gpio_direction            [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 18 + 2 ];
			g_n_gpio_data                 [ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0 ]      = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ 19 + 2 ];
		}
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,37)

			#ifdef LINUXV4L2_VMALLOC_MODULE

			videobuf_queue_vmalloc_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, &pDevice->F9D9594A095F0463193B7588374CF8310->dev, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo, &(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_sSGSemaphore) ); // [PETER] 

			#endif

			#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

			#ifdef LINUXV4L2_VMALLOC_MODULE

			videobuf_queue_vmalloc_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, pVideo->FB6E79A0780E64bb28A3308666E67881C, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

			#endif

			#else

			videobuf_queue_init( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), &F978008BE1AA54f2cA568185B87EA4843, pVideo->FB6E79A0780E64bb28A3308666E67881C, &(pVideo->F4ECA473514304aecA7885A0D80438003), V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_INTERLACED, sizeof(struct F170997530C6943659ECE8DEC21301F66), pVideo ); //

			#endif
		#endif

		mutex_unlock( &(pDevice->m_sSGSemaphore) );

		INIT_LIST_HEAD( &(pVideo->F0EA6D27495A14af1A9607DE7C222A3B1) );

		INIT_LIST_HEAD( &(pVideo->FDA1F8237E2D04e5a8737CF587701D54D) );
	}

	FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data = (PVOID)(pVideo);

	int k = 0;
	if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001 ) {

		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			if( pDevice->m_pVideo[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] == NULL ) { 
			
				pDevice->m_pVideo[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] = pVideo; 

				pDevice->FA12AAA3D283C4cf0BF02ACD3957899B0[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] &= ~( 1 << k );//clear k bit

				is_success = 1;

				F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F974CC188B92849b9A9A52461E68698A2() pDevice->m_pVideo[ %d ] [ %d ] = 0x%x\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->F0DD7393CD1494e27A72652C7D1A97893, k, pVideo );

				break; //add only once
			}
		}
	}
	if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002 ) {

		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			if( pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] == NULL ) { 
			
				pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] = pVideo; 

				pDevice->FDB274CD437614fec94859748411FE56A[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] &= ~( 1 << k );//clear k bit;

				is_success = 1;

				pDevice->m_TW5864_video_h264_count[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = 0;
				pDevice->m_H264_left[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = 0;

				F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F974CC188B92849b9A9A52461E68698A2() pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ %d ] [ %d ] = 0x%x ---\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->F0DD7393CD1494e27A72652C7D1A97893, k, pVideo );

				break; //add only once
			}
		}
	}
	if( is_success == 0 ) {

		F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "[%02d] F974CC188B92849b9A9A52461E68698A2() - reopen() - [FAIL]\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

		FREE( pVideo );

		ret = -ENOMEM;

		goto F974CC188B92849b9A9A52461E68698A2_fail;
	}

	down( &m_sComponentAccessSemaphore ); 

	m_component_ready = 1;

	up( &m_sComponentAccessSemaphore ); 

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F974CC188B92849b9A9A52461E68698A2() pVideo(0x%x) k(%d) end\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo, k );

	wake_up( &m_wait_queue_component );

	return 0;

F974CC188B92849b9A9A52461E68698A2_fail:

	down( &m_sComponentAccessSemaphore ); 

	m_component_ready = 1;

	up( &m_sComponentAccessSemaphore ); 

	wake_up( &m_wait_queue_component );

	return ret;
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,29)

static int F12AEFCB1CDFB499381DEE6D2FF4E0918( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4 )

#else

static int F12AEFCB1CDFB499381DEE6D2FF4E0918( struct inode * F9E62F5638C29456b95618E44A5D0C9F3, struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4 )

#endif
{
	struct video_device * F6CA67B866FA04fab8C939AEA549AEEBA = (struct video_device *)(video_devdata( FEBA6DA02A6244ff7AFA9DCC660800FB4 ));

	if( F6CA67B866FA04fab8C939AEA549AEEBA == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F12AEFCB1CDFB499381DEE6D2FF4E0918() F6CA67B866FA04fab8C939AEA549AEEBA == NULL\n" );

		return 0;
	}

	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(video_get_drvdata( F6CA67B866FA04fab8C939AEA549AEEBA ));

	if( pDevice == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F12AEFCB1CDFB499381DEE6D2FF4E0918() pDevice == NULL\n" );

		return 0;
	}

	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F12AEFCB1CDFB499381DEE6D2FF4E0918() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F12AEFCB1CDFB499381DEE6D2FF4E0918() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	down( &m_pFile_Stream_ControlSemaphore );

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F12AEFCB1CDFB499381DEE6D2FF4E0918() F03DD48A54B1D4ffeB64170AA03AEFC6E(0x%x) pVideo(0x%x)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) , pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E, pVideo);

	//do not need to check if release > 4, since already check at open

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F12AEFCB1CDFB499381DEE6D2FF4E0918() enter\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

//	F000A7C48E6C9447e8E19759FDCA2E917( FEBA6DA02A6244ff7AFA9DCC660800FB4 );

	#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

	//???? sometimes killall -9 vlc will error
	videobuf_stop( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A) ); //

	#endif

	videobuf_mmap_free( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A) );//pass all buffer unmap and send to FF7C28EE760F14ad99457A74168D0FFBF

	if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001 ) {

		int k = 0;
		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			if( pVideo == pDevice->m_pVideo[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] )
			{ 
				pDevice->FA12AAA3D283C4cf0BF02ACD3957899B0[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] &= ~( 1 << k );//clear k bit

				pDevice->m_pVideo[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] = NULL;

				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F12AEFCB1CDFB499381DEE6D2FF4E0918() k(%d) set to NULL\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), k );

				break;//only once
			}
		}
	}
	if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002 ) {

		int k = 0;
		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			if( pVideo == pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] )
			{ 
				pDevice->FDB274CD437614fec94859748411FE56A[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] &= ~( 1 << k );//clear k bit;

				pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] = NULL;

				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F12AEFCB1CDFB499381DEE6D2FF4E0918() k(%d) set to NULL ---\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), k );

				break;
			}
		}
	}
	FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data = NULL;

	FREE( pVideo );

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F12AEFCB1CDFB499381DEE6D2FF4E0918() end\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	up( &m_pFile_Stream_ControlSemaphore );

	return 0;
}

static ssize_t FF3D65C9920534a488D1C01121CB1C678( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, char __user * F7DCDC607F3644b1591980748EA26F4D8, size_t n_count, loff_t * p_offset )
{
	struct video_device * F6CA67B866FA04fab8C939AEA549AEEBA = (struct video_device *)(video_devdata( FEBA6DA02A6244ff7AFA9DCC660800FB4 ));

	if( F6CA67B866FA04fab8C939AEA549AEEBA == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FF3D65C9920534a488D1C01121CB1C678() F6CA67B866FA04fab8C939AEA549AEEBA == NULL\n" );

		return 0;
	}

	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(video_get_drvdata( F6CA67B866FA04fab8C939AEA549AEEBA ));

	if( pDevice == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FF3D65C9920534a488D1C01121CB1C678() pDevice == NULL\n" );

		return 0;
	}


//	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FF3D65C9920534a488D1C01121CB1C678( B:%08X, C:%08d, O:%08d )\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(F7DCDC607F3644b1591980748EA26F4D8), (int)(n_count), (int)(*p_offset) );
/*
	ssize_t videobuf_read_one(struct videobuf_queue *q,
			      char __user *data, size_t count, 
			      loff_t *ppos, int nonblocking);

    ssize_t videobuf_read_stream(struct videobuf_queue *q,
			         char __user *data, size_t count, 
				 loff_t *ppos, int vbihack, int nonblocking);
*/
	return -ENODEV;
}

static unsigned int FB13405624203472eAC9FD4691E20F851( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, struct poll_table_struct * p_poll_table_struct_wait )
{
	struct video_device * F6CA67B866FA04fab8C939AEA549AEEBA = (struct video_device *)(video_devdata( FEBA6DA02A6244ff7AFA9DCC660800FB4 ));

	unsigned int ret = POLLERR;

	unsigned long flags = 0x00000000;

	//int count = 0;

	if( F6CA67B866FA04fab8C939AEA549AEEBA == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FB13405624203472eAC9FD4691E20F851() F6CA67B866FA04fab8C939AEA549AEEBA == NULL\n" );

		return 0;
	}

	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(video_get_drvdata( F6CA67B866FA04fab8C939AEA549AEEBA ));

	if( pDevice == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FB13405624203472eAC9FD4691E20F851() pDevice == NULL\n" );

		return 0;
	}

	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

//	while( ((ret & POLLIN) == 0) && (count < 15) )
	{
		//do not know how to use it
		//poll_wait(FEBA6DA02A6244ff7AFA9DCC660800FB4, , p_poll_table_struct_wait);

		spin_lock_irqsave( &pVideo->FE0A97B802F3C400aBD7CD5D313825C31, flags );

		ret = videobuf_poll_stream( FEBA6DA02A6244ff7AFA9DCC660800FB4, &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), p_poll_table_struct_wait);

		spin_unlock_irqrestore( &pVideo->FE0A97B802F3C400aBD7CD5D313825C31, flags );

		//schedule_timeout_interruptible( msecs_to_jiffies( 1 ) );//4ms ??

		//count++;
	}
	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FB13405624203472eAC9FD4691E20F851() ret(0x%x)\n", ret );

	return ret;

//	return POLLIN | POLLRDNORM;
}

static int F79CFA56F35EA47608155CF434ADDCB8B( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, struct vm_area_struct * p_vma )
{
	struct video_device * F6CA67B866FA04fab8C939AEA549AEEBA = (struct video_device *)(video_devdata( FEBA6DA02A6244ff7AFA9DCC660800FB4 ));

	if( F6CA67B866FA04fab8C939AEA549AEEBA == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F79CFA56F35EA47608155CF434ADDCB8B() F6CA67B866FA04fab8C939AEA549AEEBA == NULL\n" );

		return 0;
	}

	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(video_get_drvdata( F6CA67B866FA04fab8C939AEA549AEEBA ));

	if( pDevice == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F79CFA56F35EA47608155CF434ADDCB8B() pDevice == NULL\n" );

		return 0;
	}

	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F79CFA56F35EA47608155CF434ADDCB8B() pVideo == NULL\n" );

		return 0;
	}

	int ret = 0;

	{
		ret = videobuf_mmap_mapper( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), p_vma );
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F79CFA56F35EA47608155CF434ADDCB8B( S:%08X, E:%08X, R:%08X )\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(p_vma->vm_start), (unsigned int)(p_vma->vm_end), ret );

	return ret;
}

#if LINUX_VERSION_CODE <= KERNEL_VERSION(2,6,17)

static int FAE35D846200744d5B6365397A4074669( struct inode * F9E62F5638C29456b95618E44A5D0C9F3, struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, unsigned int cmd, unsigned long arg )
{
//	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(video_get_drvdata( video_devdata( FEBA6DA02A6244ff7AFA9DCC660800FB4 ) ));

//	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FAE35D846200744d5B6365397A4074669( %08X )\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (cmd) );

	return video_usercopy( F9E62F5638C29456b95618E44A5D0C9F3, FEBA6DA02A6244ff7AFA9DCC660800FB4, cmd, arg, F15ABF438BBB140ed867AE71A23421A04 );
}

static int F15ABF438BBB140ed867AE71A23421A04( struct inode * F9E62F5638C29456b95618E44A5D0C9F3, struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, unsigned int cmd, void * p_arg )
{
	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(video_get_drvdata( video_devdata( FEBA6DA02A6244ff7AFA9DCC660800FB4 ) ));

	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F15ABF438BBB140ed867AE71A23421A04( %08X )\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (cmd) );

	switch( cmd ) {

	case VIDIOC_QUERYCAP:   return FF32A4269941249bd9B5BD16974ED6CB2( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_capability *)(p_arg) ); 

	case VIDIOC_ENUMINPUT:  return FC515D62374DA4b188AA6842A8E9F246F( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_input *)(p_arg) );

	case VIDIOC_S_INPUT:    return F900393DC47254043B8F2CF7DC5194C99( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, *((unsigned int *)(p_arg)) );

	case VIDIOC_G_INPUT:    return F03780B4A26054956B7A6CD9624B20D85( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (unsigned int *)(p_arg) );

	case VIDIOC_ENUM_FMT:   return F4AE125B7768742c4ADCFED552CAF7C82( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_fmtdesc *)(p_arg) );
	
	case VIDIOC_TRY_FMT:    return FAA9A4D7A9B264da19300EE68477972A1( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_format *)(p_arg) );
	
	case VIDIOC_G_FMT:      return F6727CA3250D341ac870EBFB883ABD913( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_format *)(p_arg) );
	
	case VIDIOC_S_FMT:      return FEE6EBBFC370841adADAA57CE5BEE5614( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_format *)(p_arg) );
	
	case VIDIOC_QUERYCTRL:  return FE378301A538E42ca99A12D118AA57A57( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_queryctrl *)(p_arg) );

	case VIDIOC_G_CTRL:     return F84B3BF483AB54d12922BBF693119ED0A( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_control *)(p_arg) );

	case VIDIOC_S_CTRL:     return FE2A7B4A8EE7849ceA91671F8DE876A7F( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_control *)(p_arg) );

	case VIDIOC_G_MPEGCOMP: return FFAC5AD9B7CD64ca28E7E9847C52A6E92( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_mpeg_compression *)(p_arg) );

	case VIDIOC_S_MPEGCOMP: return FA09B89F985B34f599FA8349FDB25C1CF( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_mpeg_compression *)(p_arg) );

	case VIDIOC_REQBUFS:    return FD89C51CD80FB47949EE4D5A090E1ED6D( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_requestbuffers *)(p_arg) );
	
	case VIDIOC_QUERYBUF:   return FC28B4FA81CB44cd2A02DAABFB15C0175( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_buffer *)(p_arg) );

	case VIDIOC_QBUF:       return F1CEFD4E364F942d5A796687660DF4476( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_buffer *)(p_arg) );

	case VIDIOC_DQBUF:      return F8ED1C78CFCE74f82A69E33D70B8A0DB3( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (struct v4l2_buffer *)(p_arg) );

	case VIDIOC_STREAMON:   return F4B0874C1F68D498bA1262243B9C11323( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, *((unsigned int *)(p_arg)) );
	
	case VIDIOC_STREAMOFF:  return FBD214630F7C445f9B3050CEFDBB729B2( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, *((unsigned int *)(p_arg)) );

	case VIDIOC_S_STD: 	return F73F097AB862A4a558752C68773915A0F( FEBA6DA02A6244ff7AFA9DCC660800FB4, FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data, (v4l2_std_id *)(p_arg) );

	case VIDIOC_G_STD: {

		v4l2_std_id * p_std_id = (v4l2_std_id *)(p_arg);

		*p_std_id = pVideo->F18B6587C912F463c932DEE9FF8B93AAE;

		*p_std_id = pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB;

//		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F783F7A3A79A048369E71D95A51792A65( %08X )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(*p_std_id) );

		return 0;
	}
	case VIDIOC_ENUMSTD: {

		struct v4l2_standard * F6601EC10325B431990033D0A00E2AA2A = (struct v4l2_standard *)(p_arg);

		int ret = -EINVAL;

		if( F6601EC10325B431990033D0A00E2AA2A->index == 0 ) {

			ret = v4l2_video_std_construct( F6601EC10325B431990033D0A00E2AA2A, V4L2_STD_525_60, "V4L2_STD_525_60" );
		}
		if( F6601EC10325B431990033D0A00E2AA2A->index == 1 ) {

			ret = v4l2_video_std_construct( F6601EC10325B431990033D0A00E2AA2A, V4L2_STD_625_50, "V4L2_STD_625_50" );
		}
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_enum_std( %02d )\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), F6601EC10325B431990033D0A00E2AA2A->index );

		return ret;
	}
	}
	return v4l_compat_translate_ioctl( F9E62F5638C29456b95618E44A5D0C9F3, FEBA6DA02A6244ff7AFA9DCC660800FB4, cmd, p_arg, F15ABF438BBB140ed867AE71A23421A04 );
}

#endif

// ##############################################################################################################################################################################
// 
#if LINUX_VERSION_CODE < KERNEL_VERSION(3,17,0)
#define V4L2_CAP_EXT_PIX_FORMAT         0x00200000  /* Supports the extended pixel format */
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(3,4,0)
#define V4L2_CAP_DEVICE_CAPS            0x80000000  /* sets device capabilities field */
#endif

static int FF32A4269941249bd9B5BD16974ED6CB2( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_capability * p_cap )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FF32A4269941249bd9B5BD16974ED6CB2()\n" );

	memset( p_cap, 0, sizeof(struct v4l2_capability) );

	strcpy( p_cap->driver, "LINUXV4L2" );
	
	struct video_device * F6CA67B866FA04fab8C939AEA549AEEBA = (struct video_device *)(video_devdata( FEBA6DA02A6244ff7AFA9DCC660800FB4 ));

	if( F6CA67B866FA04fab8C939AEA549AEEBA )
	{
		if( F6CA67B866FA04fab8C939AEA549AEEBA->name )
		{
			strcpy( p_cap->card, F6CA67B866FA04fab8C939AEA549AEEBA->name ); // i.e., "TW6805, Video Capture #00.00"
		}
	}

	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	#ifndef AME_PL330A
	strcpy( p_cap->bus_info, "PCIe: " );

	if( pVideo )
	{
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C )
		{
			strcat( p_cap->bus_info, pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->bus->name );
		}
	}
	#else
	strcpy( p_cap->bus_info, "USB" );

	//strcat( p_cap->bus_info, pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->bus->name );
	#endif

	p_cap->version = KERNEL_VERSION(3,12,0);
	
	p_cap->capabilities = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING | V4L2_CAP_TIMEPERFRAME | V4L2_CAP_AUDIO | V4L2_CAP_DEVICE_CAPS | V4L2_CAP_EXT_PIX_FORMAT;

	#ifndef AME_PL330A
	if( pVideo )
	{
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C )
		{
			if(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160)
			{
				p_cap->capabilities |= V4L2_CAP_VBI_CAPTURE;
			}
		}
	}
	#endif

	#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,4,0)
	p_cap->device_caps = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING | V4L2_CAP_AUDIO;
	#endif

	// reserved 0 must be 0 for some AP
	p_cap->reserved[ 1 ] = DRIVER_VERSION;
	
	if( pVideo )
	{
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C )
		{
			p_cap->reserved[ 2 ] = (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct << 24) | (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer << 16) | pVideo->FB6E79A0780E64bb28A3308666E67881C->bcdDevice;
		}
	}

	//possible no pVideo
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FF32A4269941249bd9B5BD16974ED6CB2() end\n" );

	return 0;
}

static int F96755FB5B1A9478792D0C210A81B9715( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, v4l2_std_id * s )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F96755FB5B1A9478792D0C210A81B9715() pVideo == NULL\n" );

		return 0;
	}
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F96755FB5B1A9478792D0C210A81B9715() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F96755FB5B1A9478792D0C210A81B9715( %08X )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(pVideo->F18B6587C912F463c932DEE9FF8B93AAE) );

 	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F96755FB5B1A9478792D0C210A81B9715( %08X )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB) );

   *s = (v4l2_std_id)(pVideo->F18B6587C912F463c932DEE9FF8B93AAE);

   *s = (v4l2_std_id)(pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB);

	return 0;
}

static int F783F7A3A79A048369E71D95A51792A65( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, v4l2_std_id * s )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F783F7A3A79A048369E71D95A51792A65() pVideo == NULL\n" );

		return 0;
	}
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F783F7A3A79A048369E71D95A51792A65() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	*s = pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB;
	/*
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) || 
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) || 
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) || 
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) || 
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) || 
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813)  )
	{

		BYTE R00000204 = (BYTE)(TW6802_GetRegister( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00000204, 1 ));

		if( (R00000204 & 0x000000C0) == 0x00000040 )
		{
			if( R00000204 & 0x1)
			{
				*s = V4L2_STD_PAL_B;
		
				//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F783F7A3A79A048369E71D95A51792A65( PAL )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

			}
			else
			{
				*s = V4L2_STD_NTSC_M;

				//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F783F7A3A79A048369E71D95A51792A65( NTSC )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );
			}
		}
	}
	*/
//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F783F7A3A79A048369E71D95A51792A65( %08X )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(*s) );
	
	return 0;
}
#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0)
//vidioc_s_std is wrong, parameter should be pointer
static int F73F097AB862A4a558752C68773915A0F( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, v4l2_std_id s )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F73F097AB862A4a558752C68773915A0F() pVideo == NULL\n" );

		return 0;
	}
	
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F73F097AB862A4a558752C68773915A0F() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310 == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F73F097AB862A4a558752C68773915A0F() pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310 == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F73F097AB862A4a558752C68773915A0F( %08X ) 1\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), s );

	struct pci_dev *F74930C6A858F43258B265F9ABB2DA5BC = (struct pci_dev *)pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310;
	
	int std_err = 0;

	#ifndef AME_PL330A
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty == 4) )
	{ 
		NULL; // do not set it, standard will be decided by signal

		std_err = 0;
	}
	else
	{
		pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB = (ULONG)(s);

		pVideo->F18B6587C912F463c932DEE9FF8B93AAE = (ULONG)(s);
	}
	#endif
	
	if((unsigned int)(s) & V4L2_STD_NTSC)
	{
		if((unsigned int)(s) & V4L2_STD_PAL)//std err
		{
			std_err = 1;		
		}
		else
		{
			std_err = 0;		
		}
			
	}	
	if((unsigned int)(s) & V4L2_STD_PAL)
	{
		if((unsigned int)(s) & V4L2_STD_NTSC)//std err
		{
			std_err = 1;		
		}
		else
		{
			std_err = 0;		
		}
			
	}	
//force to default
	if(std_err)

#elif LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,20)
static int F73F097AB862A4a558752C68773915A0F( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, v4l2_std_id * s )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F73F097AB862A4a558752C68773915A0F() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F73F097AB862A4a558752C68773915A0F() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310 == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F73F097AB862A4a558752C68773915A0F() pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310 == NULL\n" );

		return 0;
	}

	struct pci_dev *F74930C6A858F43258B265F9ABB2DA5BC = pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F73F097AB862A4a558752C68773915A0F( %08X ) 2\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(*s) );

	int std_err = 0;

	#ifndef AME_PL330A
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty == 4) )
	{ 
		NULL; // do not set it, standard will be decided by signal

		std_err = 0;
	}
	else
	{
		pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB = (ULONG)(*s);

		pVideo->F18B6587C912F463c932DEE9FF8B93AAE = (ULONG)(*s);
	}
	#endif

	if((unsigned int)(*s) & V4L2_STD_NTSC)
	{
		if((unsigned int)(*s) & V4L2_STD_PAL)//std err
		{
			std_err = 1;		
		}
		else
		{
			std_err = 0;		
		}
			
	}	
	if((unsigned int)(*s) & V4L2_STD_PAL)
	{
		if((unsigned int)(*s) & V4L2_STD_NTSC)//std err
		{
			std_err = 1;		
		}
		else
		{
			std_err = 0;		
		}
			
	}	
	if(std_err)

#else
//vidioc_s_std is wrong, parameter should be pointer
static int F73F097AB862A4a558752C68773915A0F( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, v4l2_std_id s )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F73F097AB862A4a558752C68773915A0F() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F73F097AB862A4a558752C68773915A0F() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310 == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F73F097AB862A4a558752C68773915A0F() pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310 == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F73F097AB862A4a558752C68773915A0F( %08X ) 3\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), s );

	struct pci_dev *F74930C6A858F43258B265F9ABB2DA5BC = pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310;
	
	int std_err = 0;

	#ifndef AME_PL330A
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty == 4) )
	{ 
		NULL; // do not set it, standard will be decided by signal

		std_err = 0;
	}
	else
	{
		pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB = (ULONG)(s);

		pVideo->F18B6587C912F463c932DEE9FF8B93AAE = (ULONG)(s);
	}
	#endif
	
	if((unsigned int)(s) & V4L2_STD_NTSC)
	{
		if((unsigned int)(s) & V4L2_STD_PAL)//std err
		{
			std_err = 1;		
		}
		else
		{
			std_err = 0;		
		}
			
	}	
	if((unsigned int)(s) & V4L2_STD_PAL)
	{
		if((unsigned int)(s) & V4L2_STD_NTSC)//std err
		{
			std_err = 1;		
		}
		else
		{
			std_err = 0;		
		}
			
	}	
//force to default
//	if(std_err)
#endif
	{	
		pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB = LINUXV4L2_DEFAULT_VIDEO_STANDARD;

		pVideo->F18B6587C912F463c932DEE9FF8B93AAE = LINUXV4L2_DEFAULT_VIDEO_STANDARD;

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F73F097AB862A4a558752C68773915A0F( %08X ) force to default\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->F18B6587C912F463c932DEE9FF8B93AAE );

	}
	
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F73F097AB862A4a558752C68773915A0F( %08X ) 4\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->F18B6587C912F463c932DEE9FF8B93AAE );


	#ifndef AME_PL330A
	if( ( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6801 ) ) { F4983E91D247340728C0AAAD98ED7322D( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

	if( ( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6804 ) ) { F4983E91D247340728C0AAAD98ED7322D( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

	if( ( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6810 ) ) { F4983E91D247340728C0AAAD98ED7322D( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

	if( ( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6811 ) ) { F4983E91D247340728C0AAAD98ED7322D( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

	if( ( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6812 ) ) { F4983E91D247340728C0AAAD98ED7322D( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

	if( ( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1797 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x6813 ) ) { F4983E91D247340728C0AAAD98ED7322D( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

	if( ( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x14F1 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x8210 ) ) { FCBA209FA64CC4f3084F86F7B3CC8FEE2( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo ); }

	if( ( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1131 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x7160 ) ) { B6B487882F964675B66617C7847B8BB5EX( pVideo->FB6E79A0780E64bb28A3308666E67881C ); A2490F6314B2455F9693604A03D8A34B( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo->F18B6587C912F463c932DEE9FF8B93AAE );  F5D69F1955AA4EBCAF770CF98A9B4992EX( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

	if( ( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x0907 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0100 ) ) { ADF0B0E919E0488A9DECD29D67A7F9A8( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo->F18B6587C912F463c932DEE9FF8B93AAE, false); }

	if( ( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0370 ) ) { ADF0B0E919E0488A9DECD29D67A7F9A8( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo->F18B6587C912F463c932DEE9FF8B93AAE, false); }

	if( ( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x12AB && F74930C6A858F43258B265F9ABB2DA5BC->device == 0x0380 ) ) { ADF0B0E919E0488A9DECD29D67A7F9A8( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo->F18B6587C912F463c932DEE9FF8B93AAE, false); }

	if( ( F74930C6A858F43258B265F9ABB2DA5BC->vendor == 0x1AF2 && F74930C6A858F43258B265F9ABB2DA5BC->device == 0xA001 ) ) { D585A1C8DE8349C5A903B8F61B5E0A9F( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo->F18B6587C912F463c932DEE9FF8B93AAE, false); }
	#else
	D585A1C8DE8349C5A903B8F61B5E0A9F( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo->F18B6587C912F463c932DEE9FF8B93AAE, false);	
	#endif
	return 0;
}

static int common_video_device_vidioc_enumaudio(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *priv, struct v4l2_audio *a)
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_enumaudio() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_enumaudio() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	//F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = pVideo->FB6E79A0780E64bb28A3308666E67881C; // shawn 2010.11.26

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] vidioc_enumaudio( %02d )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), a->index );

	#ifndef AME_PL330A
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ||

		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160)	) { 

        if (a->index == 0)
		{
			strcpy(a->name, "embedded");

			a->capability = V4L2_AUDCAP_STEREO;
			
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] vidioc_enumaudio() index(0d%d) capability(0x%x)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), a->index, a->capability );

			return 0;
		}

        if (a->index == 1)
		{

			strcpy(a->name, "Line in");

			a->capability = V4L2_AUDCAP_STEREO;
			
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] vidioc_enumaudio() index(0d%d) capability(0x%x) ---\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), a->index, a->capability );
			return 0;
		}

	}
	#endif

	return -EINVAL;
}

static int FC515D62374DA4b188AA6842A8E9F246F( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_input * p_input )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FC515D62374DA4b188AA6842A8E9F246F() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FC515D62374DA4b188AA6842A8E9F246F() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = pVideo->FB6E79A0780E64bb28A3308666E67881C; // shawn 2010.11.26

	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FC515D62374DA4b188AA6842A8E9F246F( %02d )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_input->index );

	#ifndef AME_PL330A
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) { 
		
		if( p_input->index == 0 ) {

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
//			p_input->status = (pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 >> 0) & (0x00000001);
//peter[2011.04.29]
			p_input->status = ((pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 >> 0) & (0x00000001))? 0x0: 0x102;

			strcpy( p_input->name, "#00 COMPOSITE INPUT" ); 
			
			return 0;
		}
		if( p_input->index == 1 ) {

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
//			p_input->status = (pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 >> 1) & (0x00000001);
//peter[2011.04.29]
			p_input->status = ((pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 >> 0) & (0x00000001))? 0x0: 0x102;

			strcpy( p_input->name, "#01 COMPOSITE INPUT" );
			
			return 0;
		}
		if( p_input->index == 2 ) {

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
//			p_input->status = (pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 >> 2) & (0x00000001);
//peter[2011.04.29]
			p_input->status = ((pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 >> 0) & (0x00000001))? 0x0: 0x102;

			strcpy( p_input->name, "#02 COMPOSITE INPUT" );
			
			return 0;
		}
		if( p_input->index == 3 ) {

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
//			p_input->status = (pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 >> 3) & (0x00000001);
//peter[2011.04.29]
			p_input->status = ((pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 >> 0) & (0x00000001))? 0x0: 0x102;

			strcpy( p_input->name, "#03 COMPOSITE INPUT" );
			
			return 0;
		}
		//this is for ffmpeg 2.X, 
		if( p_input->index == 4 ) {

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			p_input->status = 0x0;

			strcpy( p_input->name, "dummy INPUT for ffmpeg V2.X" );
			
			return 0;
		}
	}

	//shawn 2010.11.26
	//
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) || 
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5851) ) { // shawn 2010.07.12
		
		if( p_input->index == 0 ) {

			ULONG R0000100C = 0x00000000;

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			//R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * pVideo->F0DD7393CD1494e27A72652C7D1A97893)), 1 ); 

			R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * 0)), 1 ); 

			pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 = (R0000100C & 0x00000010) ? (0) : (0x102);

			p_input->status = (R0000100C & 0x00000010) ? (0) : (0x102);

			strcpy( p_input->name, "#00 COMPOSITE INPUT" ); 

			return 0;
		}
		if( p_input->index == 1 ) {

			ULONG R0000100C = 0x00000000;

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			//R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * pVideo->F0DD7393CD1494e27A72652C7D1A97893)), 1 ); 

			R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * 1)), 1 ); 

			pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 = (R0000100C & 0x00000010) ? (0) : (0x102);

			p_input->status = (R0000100C & 0x00000010) ? (0) : (0x102);

			strcpy( p_input->name, "#01 COMPOSITE INPUT" ); 

			return 0;
		}
		if( p_input->index == 2 ) {

			ULONG R0000100C = 0x00000000;

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			//R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * pVideo->F0DD7393CD1494e27A72652C7D1A97893)), 1 ); 

			R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * 2)), 1 ); 

			pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 = (R0000100C & 0x00000010) ? (0) : (0x102);

			p_input->status = (R0000100C & 0x00000010) ? (0) : (0x102);

			strcpy( p_input->name, "#02 COMPOSITE INPUT" ); 

			return 0;
		}
		if( p_input->index == 3 ) {

			ULONG R0000100C = 0x00000000;

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			//R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * pVideo->F0DD7393CD1494e27A72652C7D1A97893)), 1 ); 

			R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * 3)), 1 ); 

			pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 = (R0000100C & 0x00000010) ? (0) : (0x102);

			p_input->status = (R0000100C & 0x00000010) ? (0) : (0x102);

			strcpy( p_input->name, "#03 COMPOSITE INPUT" ); 

			return 0;
		}
		if( p_input->index == 4 ) {

			ULONG R0000100C = 0x00000000;

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			//R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * pVideo->F0DD7393CD1494e27A72652C7D1A97893)), 1 ); 

			R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * 4)), 1 ); 

			pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 = (R0000100C & 0x00000010) ? (0) : (0x102);

			p_input->status = (R0000100C & 0x00000010) ? (0) : (0x102);

			strcpy( p_input->name, "#04 COMPOSITE INPUT" ); 

			return 0;
		}
		if( p_input->index == 5 ) {

			ULONG R0000100C = 0x00000000;

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			//R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * pVideo->F0DD7393CD1494e27A72652C7D1A97893)), 1 ); 

			R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * 5)), 1 ); 

			pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 = (R0000100C & 0x00000010) ? (0) : (0x102);

			p_input->status = (R0000100C & 0x00000010) ? (0) : (0x102);

			strcpy( p_input->name, "#05 COMPOSITE INPUT" ); 

			return 0;
		}
		if( p_input->index == 6 ) {

			ULONG R0000100C = 0x00000000;

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			//R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * pVideo->F0DD7393CD1494e27A72652C7D1A97893)), 1 ); 

			R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * 6)), 1 ); 

			pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 = (R0000100C & 0x00000010) ? (0) : (0x102);

			p_input->status = (R0000100C & 0x00000010) ? (0) : (0x102);

			strcpy( p_input->name, "#06 COMPOSITE INPUT" ); 

			return 0;
		}
		if( p_input->index == 7 ) {

			ULONG R0000100C = 0x00000000;

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			//R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * pVideo->F0DD7393CD1494e27A72652C7D1A97893)), 1 ); 

			R0000100C = FDD9F9CAA436D42598730DCC97387C22C( pDevice, (USHORT)(0x100C + (0x0200 * 7)), 1 ); 

			pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 = (R0000100C & 0x00000010) ? (0) : (0x102);

			p_input->status = (R0000100C & 0x00000010) ? (0) : (0x102);

			strcpy( p_input->name, "#07 COMPOSITE INPUT" ); 

			return 0;
		}
		if( p_input->index == 8 ) {

			ULONG R0000100C = 0x00000000;

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //

			pVideo->F5BB6BD5E849C46bfAD76032D5E2E47B9 = 0;

			p_input->status = 0;

			strcpy( p_input->name, "dummy INPUT for ffmpeg V2.X" ); 

			return 0;
		}
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 ) { 

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x03) ||	(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x85) )
		{
			if( p_input->index == 0 || p_input->index == 4) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				p_input->status = ((((pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogVideoDecoderStatusProperty) >> (pVideo->F0DD7393CD1494e27A72652C7D1A97893 % 4) ) & 0x1) ? 0: 0x102);

				strcpy( p_input->name, "COMPOSITE INPUT" ); 

				//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FC515D62374DA4b188AA6842A8E9F246F( 0x%x )--\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pDevice->m_nAnalogVideoDecoderStatusProperty );
				return 0;
			}	
		}


		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) || (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x07) )
		{
			if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer) == 0x8A )
			{
				if( p_input->index == 0 ) {

					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
					
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
					
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);

					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif
					
					strcpy( p_input->name, "HDMI INPUT(0)" ); 

					//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FC515D62374DA4b188AA6842A8E9F246F( 0x%x )--\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pDevice->m_nAnalogVideoDecoderStatusProperty );
					return 0;
				}	
			}
			else if((pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer) == 0x8B)
			{
				/*
				if( p_input->index == 0 ) {

					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
					
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
					
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);

					strcpy( p_input->name, "SDI INPUT" ); 

					//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FC515D62374DA4b188AA6842A8E9F246F( 0x%x )--\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pDevice->m_nAnalogVideoDecoderStatusProperty );
					return 0;
				}
				*/
				// 0 must exist
				if( (p_input->index == 0) || (p_input->index == 1) || (p_input->index == 2) || (p_input->index == 3) ) {

					p_input->status = 0x102;

					strcpy( p_input->name, "NULL" ); 

					//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FC515D62374DA4b188AA6842A8E9F246F( 0x%x )--\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pDevice->m_nAnalogVideoDecoderStatusProperty );
				
					return 0;
				}
				
				if( p_input->index == 4 ) {

					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
					
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
					
					if(pDevice->m_nAnalogCrossbarVideoInputProperty == 4)
					{
						p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
					}
					else
					{
						p_input->status = 0x102;
					}
					
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif

					strcpy( p_input->name, "SDI INPUT(4)" ); 

					//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FC515D62374DA4b188AA6842A8E9F246F( 0x%x )--\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pDevice->m_nAnalogVideoDecoderStatusProperty );
				
					return 0;
				}

			}
			else
			{
				if( p_input->index == 0 ) {

					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
					
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
					
					if(pDevice->m_nAnalogCrossbarVideoInputProperty == 0)
					{
						p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
					}
					else
					{
						p_input->status = 0x102;
					}
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif

					strcpy( p_input->name, "HDMI INPUT(0)" ); 

					//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FC515D62374DA4b188AA6842A8E9F246F( 0x%x )--\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pDevice->m_nAnalogVideoDecoderStatusProperty );
				
					return 0;
				}

				if( p_input->index == 1 ) {

					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
					
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
					
					if(pDevice->m_nAnalogCrossbarVideoInputProperty == 1)
					{
						p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
					}
					else
					{
						p_input->status = 0x102;
					}
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif

					strcpy( p_input->name, "DVI-D INPUT(1)" ); 

					//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FC515D62374DA4b188AA6842A8E9F246F( 0x%x )--\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pDevice->m_nAnalogVideoDecoderStatusProperty );
				
					return 0;
				}
				if( p_input->index == 2 ) {

					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
					
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
					
					if(pDevice->m_nAnalogCrossbarVideoInputProperty == 2)
					{
						p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
					}
					else
					{
						p_input->status = 0x102;
					}
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif

					strcpy( p_input->name, "COMPONENT(YPbPr) INPUT(2)" ); 

					//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FC515D62374DA4b188AA6842A8E9F246F( 0x%x )--\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pDevice->m_nAnalogVideoDecoderStatusProperty );
				
					return 0;
				}
				if( p_input->index == 3 ) {

					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
					
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
					
					if(pDevice->m_nAnalogCrossbarVideoInputProperty == 3)
					{
						p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
					}
					else
					{
						p_input->status = 0x102;
					}
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif

					strcpy( p_input->name, "DVI-A INPUT(3)" ); 

					//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FC515D62374DA4b188AA6842A8E9F246F( 0x%x )--\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pDevice->m_nAnalogVideoDecoderStatusProperty );
				
					return 0;
				}
				if( p_input->index == 4 ) {

					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
					
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
					
					if(pDevice->m_nAnalogCrossbarVideoInputProperty == 4)
					{
						p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
					}
					else
					{
						p_input->status = 0x102;
					}
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif

					strcpy( p_input->name, "SDI INPUT(4)" ); 

					//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FC515D62374DA4b188AA6842A8E9F246F( 0x%x )--\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pDevice->m_nAnalogVideoDecoderStatusProperty );
				
					return 0;
				}

			}
		}
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 ) { 

		if( p_input->index == 0 ) {
		
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			p_input->status = ((pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogVideoDecoderStatusProperty) >> 0 ) & 0x1 ? 0: 0x102;

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif

			strcpy( p_input->name, "#00 COMPOSITE INPUT" ); 

			return 0;
		}
		if( p_input->index == 1 ) {
		
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			p_input->status = ((pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogVideoDecoderStatusProperty) >> 1 ) & 0x1 ? 0: 0x102;

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif

			strcpy( p_input->name, "#00 COMPOSITE INPUT" ); 

			return 0;
		}
		if( p_input->index == 2 ) {
		
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			p_input->status = ((pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogVideoDecoderStatusProperty) >> 2 ) & 0x1 ? 0: 0x102;

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif

			strcpy( p_input->name, "#00 COMPOSITE INPUT" ); 

			return 0;
		}
		if( p_input->index == 3 ) {
		
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			p_input->status = ((pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogVideoDecoderStatusProperty) >> 3 ) & 0x1 ? 0: 0x102;

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif

			strcpy( p_input->name, "#00 COMPOSITE INPUT" ); 

			return 0;
		}
		//this is for ffmpeg 2.X, 
		if( p_input->index == 4 ) {

			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			p_input->status = 0x0;

			strcpy( p_input->name, "dummy INPUT for ffmpeg V2.X" );
			
			return 0;
		}
	}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 ) { 

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x17) ||

			(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x04 && pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct == 0x07) ||
				
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x0A && pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct == 0x07) )
		{
			// 0 must exist
			if( (p_input->index == 0) || (p_input->index == 4) ) {

				p_input->status = 0x102;

				strcpy( p_input->name, "NULL" ); 

				return 0;
			}
			
			if( p_input->index == 1 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 1)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif

				strcpy( p_input->name, "DVI-D INPUT(1)" ); 

				return 0;
			}

			if( p_input->index == 2 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 2)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif

				strcpy( p_input->name, "COMPONENT(YPbPr) INPUT(2)" ); 

				return 0;
			}

			if( p_input->index == 3 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 3)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "DVI-A INPUT(3)" ); 

				return 0;
			}

			if( p_input->index == 5 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 5)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif

				strcpy( p_input->name, "COMPOSITE INPUT(5)" ); 

				return 0;
			}
			if( p_input->index == 6 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 6)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif

				strcpy( p_input->name, "S-VIDEO INPUT(6)" ); 

				return 0;
			}
		}

		if( ((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x1B)) || //SC510 SDI N4
			
			((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x12)) ||  //SC510 SDI N2

			((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x14)) ||  //MC512 SDI N1

			((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x08)) )  //SC502 SDI MC
		{
			// 0 must exist
			if( (p_input->index == 0) || (p_input->index == 1) || (p_input->index == 2) || (p_input->index == 3) ) {

				p_input->status = 0x102;

				strcpy( p_input->name, "NULL" ); 

				return 0;
			}
			
			if( p_input->index == 4 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 4)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "SDI INPUT(4)" ); 

				return 0;
			}
		}

		if( ((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x1A)) || //SC510 HDMI N4
			
			((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x18)) || //SC510 HDMI N2

			((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x16)) || //SC510 HDMI N2
			
			((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x0D)) ||  //SC502 HDMI MC

			((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x0A)) ||  //SC502 HDMI MC

			((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x13)) )  //SC510N2-L4K

		{
			// 0 must exist
			
			if( p_input->index == 0 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "HDMI INPUT(0)" ); 

				return 0;
			}
		}

		if( ((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x00)) || //SC500 N1
			((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x10)) )  //SC510 N1
		{
			// 0 must exist
			if( p_input->index == 0 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 0)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "HDMI INPUT(0)" ); 

				return 0;
			}
			if( p_input->index == 1 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 1)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "DVI-D INPUT(1)" ); 

				return 0;
			}

			if( p_input->index == 2 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 2)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "COMPONENT(YPbPr) INPUT(2)" ); 

				return 0;
			}

			if( p_input->index == 3 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 3)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "DVI-A INPUT(3)" ); 

				return 0;
			}

			if( p_input->index == 4 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 4)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "SDI INPUT(4)" ); 

				return 0;
			}
			if( p_input->index == 5 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 5)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "COMPOSITE INPUT(5)" ); 

				return 0;
			}

			if( p_input->index == 6 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 6)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "S-VIDEO INPUT(6)" ); 

				return 0;
			}

		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x0C) )     //SC502 MC HDMI, DVI, VGA, component
		{
			// 0 must exist
			if( p_input->index == 0 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 0)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "HDMI INPUT(0)" ); 

				return 0;
			}
			if( p_input->index == 1 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 1)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "DVI-D INPUT(1)" ); 

				return 0;
			}

			if( p_input->index == 2 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 2)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "COMPONENT(YPbPr) INPUT(2)" ); 

				return 0;
			}

			if( p_input->index == 3 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 3)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif

				strcpy( p_input->name, "DVI-A INPUT(3)" ); 

				return 0;
			}
		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x00 && pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct == 0x07) ||

			(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x01 && pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct == 0x07) ||

			(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x03 && pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct == 0x07) )
		{
			// 0 must exist
			if( p_input->index == 0 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 0)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "HDMI INPUT(0)" ); 

				return 0;
			}
			if( p_input->index == 1 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 1)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "DVI-D INPUT(1)" ); 

				return 0;
			}

			if( p_input->index == 2 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 2)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "COMPONENT(YPbPr) INPUT(2)" ); 

				return 0;
			}

			if( p_input->index == 3 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 3)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif

				strcpy( p_input->name, "DVI-A INPUT(3)" ); 

				return 0;
			}
			if( p_input->index == 4 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 4)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif

				strcpy( p_input->name, "SDI INPUT(4)" ); 

				return 0;
			}
		}
////////////////////////////////////////
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x03) ) //SC500, DVI-D, DVI-A, component
		{
			// 0 must exist
			if( p_input->index == 0 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 0)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "HDMI INPUT(0)" ); 

				return 0;
			}
			if( p_input->index == 1 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 1)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "DVI-D INPUT(1)" ); 

				return 0;
			}

			if( p_input->index == 2 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 2)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif
				
				strcpy( p_input->name, "COMPONENT(YPbPr) INPUT(2)" ); 

				return 0;
			}

			if( p_input->index == 3 ) {

				p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
				p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
				if(pDevice->m_nAnalogCrossbarVideoInputProperty == 3)
				{
					p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
				}
				else
				{
					p_input->status = 0x102;
				}
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
				p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
				#endif

				strcpy( p_input->name, "DVI-A INPUT(3)" ); 

				return 0;
			}
		}

//////////////////////////////////////////
	}

	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
		
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) ) { 
	
		if( ((pDevice->iProduct & 0x0F) == 0x02) || ((pDevice->iProduct & 0x0F) == 0x03)  )  // 960H & D1
		{
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //

			if( p_input->index == 0 ) {
				
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty >> 0) & (0x00000001))? 0x0: 0x102;

				strcpy( p_input->name, "#00 COMPOSITE INPUT" ); 
				
				return 0;
			}

			if( p_input->index == 1 ) {
				
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty >> 1) & (0x00000001))? 0x0: 0x102;

				strcpy( p_input->name, "#01 COMPOSITE INPUT" ); 
				
				return 0;
			}

			if( p_input->index == 2 ) {
				
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty >> 2) & (0x00000001))? 0x0: 0x102;

				strcpy( p_input->name, "#02 COMPOSITE INPUT" ); 
				
				return 0;
			}
			if( p_input->index == 3 ) {
				
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty >> 3) & (0x00000001))? 0x0: 0x102;

				strcpy( p_input->name, "#03 COMPOSITE INPUT" ); 
				
				return 0;
			}
			if( p_input->index == 4 ) {
				
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty >> 4) & (0x00000001))? 0x0: 0x102;

				strcpy( p_input->name, "#04 COMPOSITE INPUT" ); 
				
				return 0;
			}
			if( p_input->index == 5 ) {
				
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty >> 5) & (0x00000001))? 0x0: 0x102;

				strcpy( p_input->name, "#05 COMPOSITE INPUT" ); 
				
				return 0;
			}
			if( p_input->index == 6 ) {
				
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty >> 6) & (0x00000001))? 0x0: 0x102;

				strcpy( p_input->name, "#06 COMPOSITE INPUT" ); 
				
				return 0;
			}
			if( p_input->index == 7 ) {
				
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty >> 7) & (0x00000001))? 0x0: 0x102;

				strcpy( p_input->name, "#07 COMPOSITE INPUT" ); 
				
				return 0;
			}
		}
		else
		{
			if( pDevice->iManufacturer == 0x54 ||  // SC550N1 MC SDI
			
				 pDevice->iManufacturer == 0x5B ||  // SC550N4 SDI

				 pDevice->iManufacturer == 0xC4 ||  // SC5C0N1 MC SDI
			
				 pDevice->iManufacturer == 0xCB ) { // SC5C0N4 SDI

				// 0 must exist
				if( p_input->index == 0 ) {

					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
					if(pDevice->m_nAnalogCrossbarVideoInputProperty == 0)
					{
						p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
					}
					else
					{
						p_input->status = 0x102;
					}
				
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif
				
					strcpy( p_input->name, "HDMI INPUT(0)" ); 

					return 0;
				}
				if( p_input->index == 4 ) {

					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
					if(pDevice->m_nAnalogCrossbarVideoInputProperty == 4)
					{
						p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
					}
					else
					{
						p_input->status = 0x102;
					}
				
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif

					strcpy( p_input->name, "SDI INPUT(4)" ); 

					return 0;
				}

			}
			else if( pDevice->iManufacturer == 0x5A ||  // SC550N4 HDMI
			
					 pDevice->iManufacturer == 0xCA ) { // SC5C0N4 HDMI

				// 0 must exist
				if( p_input->index == 0 ) {

					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
				
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
				
					if(pDevice->m_nAnalogCrossbarVideoInputProperty == 0)
					{
						p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
					}
					else
					{
						p_input->status = 0x102;
					}
				
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif
				
					strcpy( p_input->name, "HDMI INPUT(0)" ); 

					return 0;
				}
			}
			else
			{

				// 0 must exist
				if( p_input->index == 0 ) {
	
					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
					
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
					
					if(pDevice->m_nAnalogCrossbarVideoInputProperty == 0)
					{
						p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
					}
					else
					{
						p_input->status = 0x102;
					}
					
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif
					
					strcpy( p_input->name, "HDMI INPUT(0)" ); 
	
					return 0;
				}
				if( p_input->index == 1 ) {
	
					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
					
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
					
					if(pDevice->m_nAnalogCrossbarVideoInputProperty == 1)
					{
						p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
					}
					else
					{
						p_input->status = 0x102;
					}
					
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif
					
					strcpy( p_input->name, "DVI-D INPUT(1)" ); 
	
					return 0;
				}
	
				if( p_input->index == 2 ) {
	
					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
					if(pDevice->m_nAnalogCrossbarVideoInputProperty == 2)
					{
						p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
					}
					else
					{
						p_input->status = 0x102;
					}
			
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif
			
					strcpy( p_input->name, "COMPONENT(YPbPr) INPUT(2)" ); 
	
					return 0;
				}

				if( p_input->index == 3 ) {
	
					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
					
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
					
					if(pDevice->m_nAnalogCrossbarVideoInputProperty == 3)
					{
						p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
					}
					else
					{
						p_input->status = 0x102;
					}
					
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif
	
					strcpy( p_input->name, "DVI-A INPUT(3)" ); 
	
					return 0;
				}
				if( p_input->index == 4 ) {
	
					p_input->type = V4L2_INPUT_TYPE_CAMERA; //
					
					p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
					
					if(pDevice->m_nAnalogCrossbarVideoInputProperty == 4)
					{
						p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
					}
					else
					{
						p_input->status = 0x102;
					}
					
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
					p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
					#endif
	
					strcpy( p_input->name, "SDI INPUT(4)" ); 
	
					return 0;
				}
			}
		}
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001)
	{ 
		// 0 must exist
		if( p_input->index == 0 ) {
	
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			if(pDevice->m_nAnalogCrossbarVideoInputProperty == 0)
			{
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
			}
			else
			{
				p_input->status = 0x102;
			}
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif
			
			strcpy( p_input->name, "HDMI INPUT(0)" ); 
	
			return 0;
		}
		if( p_input->index == 1 ) {
	
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			if(pDevice->m_nAnalogCrossbarVideoInputProperty == 1)
			{
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
			}
			else
			{
				p_input->status = 0x102;
			}
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif
			
			strcpy( p_input->name, "DVI-D INPUT(1)" ); 
	
			return 0;
		}
	
		if( p_input->index == 2 ) {
	
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			if(pDevice->m_nAnalogCrossbarVideoInputProperty == 2)
			{
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
			}
			else
			{
				p_input->status = 0x102;
			}
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif
			
			strcpy( p_input->name, "COMPONENT(YPbPr) INPUT(2)" ); 
	
			return 0;
		}

		if( p_input->index == 3 ) {
	
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			if(pDevice->m_nAnalogCrossbarVideoInputProperty == 3)
			{
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
			}
			else
			{
				p_input->status = 0x102;
			}
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif
	
			strcpy( p_input->name, "DVI-A INPUT(3)" ); 
	
			return 0;
		}
		if( p_input->index == 4 ) {
	
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			if(pDevice->m_nAnalogCrossbarVideoInputProperty == 4)
			{
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
			}
			else
			{
				p_input->status = 0x102;
			}
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif
	
			strcpy( p_input->name, "SDI INPUT(4)" ); 
	
			return 0;
		}
		if( p_input->index == 5 ) {
	
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			if(pDevice->m_nAnalogCrossbarVideoInputProperty == 5)
			{
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
			}
			else
			{
				p_input->status = 0x102;
			}
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif
	
			strcpy( p_input->name, "COMPOSITE INPUT(5)" ); 
	
			return 0;
		}
		if( p_input->index == 6 ) {
	
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			if(pDevice->m_nAnalogCrossbarVideoInputProperty == 6)
			{
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
			}
			else
			{
				p_input->status = 0x102;
			}
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif
	
			strcpy( p_input->name, "S-CONNECTOR INPUT(6)" ); 
	
			return 0;
		}
	}
	#else
	{ 
		// 0 must exist
		if( p_input->index == 0 ) {
	
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			if(pDevice->m_nAnalogCrossbarVideoInputProperty == 0)
			{
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
			}
			else
			{
				p_input->status = 0x102;
			}
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif
			
			strcpy( p_input->name, "HDMI INPUT(0)" ); 
	
			return 0;
		}
		if( p_input->index == 1 ) {
	
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			if(pDevice->m_nAnalogCrossbarVideoInputProperty == 1)
			{
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
			}
			else
			{
				p_input->status = 0x102;
			}
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif
			
			strcpy( p_input->name, "DVI-D INPUT(1)" ); 
	
			return 0;
		}
	
		if( p_input->index == 2 ) {
	
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			if(pDevice->m_nAnalogCrossbarVideoInputProperty == 2)
			{
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
			}
			else
			{
				p_input->status = 0x102;
			}
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif
			
			strcpy( p_input->name, "COMPONENT(YPbPr) INPUT(2)" ); 
	
			return 0;
		}

		if( p_input->index == 3 ) {
	
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			if(pDevice->m_nAnalogCrossbarVideoInputProperty == 3)
			{
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
			}
			else
			{
				p_input->status = 0x102;
			}
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif
	
			strcpy( p_input->name, "DVI-A INPUT(3)" ); 
	
			return 0;
		}
		if( p_input->index == 4 ) {
	
			p_input->type = V4L2_INPUT_TYPE_CAMERA; //
			
			p_input->std = V4L2_STD_525_60 | V4L2_STD_625_50; //
			
			if(pDevice->m_nAnalogCrossbarVideoInputProperty == 4)
			{
				p_input->status = ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x01) ? 0x0: 0x102);
			}
			else
			{
				p_input->status = 0x102;
			}
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,33)
			p_input->capabilities = V4L2_IN_CAP_PRESETS | V4L2_IN_CAP_STD;
			#endif
	
			strcpy( p_input->name, "SDI INPUT(4)" ); 
	
			return 0;
		}
	}
	#endif

return -EINVAL;
}

static int F900393DC47254043B8F2CF7DC5194C99( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, unsigned int i )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F900393DC47254043B8F2CF7DC5194C99() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F900393DC47254043B8F2CF7DC5194C99() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F900393DC47254043B8F2CF7DC5194C99( %02d )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), i );


	if( ( i ) != pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty )
	{
		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty = ( i);

		pVideo->FECCF92CAC5DC4194925ADBF80EFC3B63 = ( i);

		#ifndef AME_PL330A
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			B49E7A6E108B44028748F460FC068D23(pVideo->FB6E79A0780E64bb28A3308666E67881C);

			if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x17) ||

				(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x04 && pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct == 0x07) ||
					
				(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x0A && pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct == 0x07) )
			{
				if(pVideo->FECCF92CAC5DC4194925ADBF80EFC3B63 > 6)
				{
					return -EINVAL;
				}
			}

			if( ((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x1B)) || //SC510 SDI N4
				
				((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x12)) ||  //SC510 SDI N2

				((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x08)) )  //SC502 SDI MC
			{
				if(pVideo->FECCF92CAC5DC4194925ADBF80EFC3B63 > 4)
				{
					return -EINVAL;
				}
			}

			if( ((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x1A)) || //SC510 HDMI N4
				
				((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x18)) || //SC510 HDMI N2

				((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x16)) || //SC510 HDMI N2
				
				((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x0D)) ||  //SC502 HDMI MC

				((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x0A)) ||  //SC502 HDMI MC

				((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x13)) )  //SC510N2-L4K

			{
				if(pVideo->FECCF92CAC5DC4194925ADBF80EFC3B63 > 0)
				{
					return -EINVAL;
				}
			}

			if( ((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x00)) || //SC500 N1
				((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x10)) )  //SC510 N1
			{

				if(pVideo->FECCF92CAC5DC4194925ADBF80EFC3B63 > 6)
				{
					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] wrong input(%d) ??????????????????", pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE, pVideo->FECCF92CAC5DC4194925ADBF80EFC3B63 );
					return -EINVAL;
				}
			}

			if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x0C) )     //SC502 MC HDMI, DVI, VGA, component
			{
				if(pVideo->FECCF92CAC5DC4194925ADBF80EFC3B63 > 3)
				{
					return -EINVAL;
				}
			}

			if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x00 && pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct == 0x07) ||

				(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x01 && pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct == 0x07) ||

				(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x03 && pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct == 0x07) )
			{
				if(pVideo->FECCF92CAC5DC4194925ADBF80EFC3B63 > 4)
				{
					return -EINVAL;
				}
			}
			if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x03) ) //SC500, DVI-D, DVI-A, component
			{
				if(pVideo->FECCF92CAC5DC4194925ADBF80EFC3B63 > 3)
				{
					return -EINVAL;
				}
			}
		}
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
		{
			E00CC1590A6D4C3FB115D1D67C891FE3(pVideo->FB6E79A0780E64bb28A3308666E67881C);

		}
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
		{
			E8FFA7FBB87647EDA2877C2FAC2B2F1C(pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty, 0, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarAudioInputProperty, 0, FALSE);
		}
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804 )
		{
			TW6802_SetAnalogCrossbarRouteProperty( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty, 0, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarAudioInputProperty, 0);
		}				
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 )
		{
			E9D4315DBD2D4358B221B0E3A1963008( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty, 0, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarAudioInputProperty, 0, FALSE);
		}				
		#else
			E9D4315DBD2D4358B221B0E3A1963008( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty, 0, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarAudioInputProperty, 0, FALSE);
		#endif
	}
	else
	{
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] same input(%d)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE, pVideo->FECCF92CAC5DC4194925ADBF80EFC3B63 );
	}

	return 0;
}

static int F03780B4A26054956B7A6CD9624B20D85( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, unsigned int * i )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F03780B4A26054956B7A6CD9624B20D85() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F03780B4A26054956B7A6CD9624B20D85() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F03780B4A26054956B7A6CD9624B20D85( %02d )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), (int)(pVideo->FECCF92CAC5DC4194925ADBF80EFC3B63) );

   *i = pVideo->FECCF92CAC5DC4194925ADBF80EFC3B63;

	return 0;
}

static int common_video_device_vidioc_s_audio( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, const struct v4l2_audio *a )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_s_audio() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_s_audio() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_s_audio() index(0d%d)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), a->index );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_s_audio() mode(0x%x)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), a->mode );

	if(a->index > 2)
	{
		return -EINVAL;
	}

	if( (a->index & 0xF) != pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarAudioInputProperty)
	{
		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarAudioInputProperty = (a->index & 0xF);


		#ifndef AME_PL330A
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			B49E7A6E108B44028748F460FC068D23(pVideo->FB6E79A0780E64bb28A3308666E67881C);


		}
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
		{
			E00CC1590A6D4C3FB115D1D67C891FE3(pVideo->FB6E79A0780E64bb28A3308666E67881C);
		}

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 )
		{
			E9D4315DBD2D4358B221B0E3A1963008( pVideo->FB6E79A0780E64bb28A3308666E67881C, -1, -1, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarAudioInputProperty, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarAudioOutputProperty, TRUE );
		}
		#endif
	}
	return 0;
}
static int common_video_device_vidioc_g_audio(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_audio *a)
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_g_audio() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_g_audio() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	a->index = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarAudioInputProperty;

	return 0;
}
/*
static int	common_video_device_vidioc_enum_dv_presets(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_dv_enum_preset *preset)
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);
	return 0;
}
*/
static int common_video_device_vidioc_s_parm( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_streamparm *sp )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_s_parm() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_s_parm() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_s_parm() \n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	if (sp->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
		return -EINVAL;
	/*
	if( (sp->parm.capture.timeperframe.numerator > 0) && (sp->parm.capture.timeperframe.denominator > 0) && (sp->parm.capture.timeperframe.denominator > sp->parm.capture.timeperframe.numerator) )
	{
		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] = (sp->parm.capture.timeperframe.denominator * 1000)/ sp->parm.capture.timeperframe.numerator;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 )
	{
		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] /= 1000;
	}
	pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] |= 0x88000000;
	*/
	if( (sp->parm.capture.timeperframe.numerator > 0) && (sp->parm.capture.timeperframe.denominator > 0) && (sp->parm.capture.timeperframe.denominator > sp->parm.capture.timeperframe.numerator) )
	{
		
		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_timeperframe_denominator = sp->parm.capture.timeperframe.denominator;

		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_timeperframe_numerator = sp->parm.capture.timeperframe.numerator;

		ULONG modified_numerator = sp->parm.capture.timeperframe.numerator;

		if( modified_numerator == 1001)
		{
			modified_numerator = 1000;
		}

		#ifndef AME_PL330A
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 )
		{
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] == (sp->parm.capture.timeperframe.denominator / modified_numerator) )//minus 1 is to make 1001 to 1000, otherwise 30000/1001 = 29.xxx
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_s_parm() same value(0x%x) \n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] );
			}
			else
			{
				pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] = (sp->parm.capture.timeperframe.denominator / modified_numerator);
				
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0 )
				{
					pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] |= 0x88000000;
				}
			}
		}
		else
		{
			pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] = (sp->parm.capture.timeperframe.denominator * 1000)/ modified_numerator;
			pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] |= 0x88000000;
		}
		#else
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] == (sp->parm.capture.timeperframe.denominator / modified_numerator ) )
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_s_parm() same value(0x%x) \n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] );
			}
			else
			{
				pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] = (sp->parm.capture.timeperframe.denominator / modified_numerator );
				pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] |= 0x88000000;
			}
		#endif
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_s_parm() numerator(0d%d) denominator(0d%d) m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ](0x%x)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), sp->parm.capture.timeperframe.numerator, sp->parm.capture.timeperframe.denominator, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] );

	return 0;
}
static int common_video_device_vidioc_g_parm( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_streamparm *sp )
{

	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_g_parm() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_g_parm() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	//if below is enabled, "frame=25/1 " should appeared in gst command
	//otherwise, frame drop if videoscale is issued by gst command

	#ifndef AME_FH8735 //8735 without preview rate control
	sp->parm.capture.capability |= V4L2_CAP_TIMEPERFRAME;
	#endif

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_g_parm() capability(0x%x)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), sp->parm.capture.capability );

	#ifdef AME_SA7160
	
	SA7160_SYS_CFG * p_sys_cfg = (SA7160_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);

	#endif

	#ifdef AME_FH8735
	
	FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);
	
	#endif

	#if defined(AME_PL330B) || defined(AME_PL330A)
	
	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);
	
	#endif

	#ifdef AME_MZ0380
	
	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);
	
	#endif

	if (sp->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
		return -EINVAL;

	if(p_sys_cfg)
	{
		sp->parm.capture.timeperframe.denominator = p_sys_cfg->n_input_video_resolution_fps * 1000;

		if( p_sys_cfg->n_input_video_resolution_interleaved == 1 )
		{
			sp->parm.capture.timeperframe.denominator /= 2;
		}

		if(p_sys_cfg->n_input_video_resolution_fps_m == 1)
		{
			sp->parm.capture.timeperframe.numerator = 1001;
		}
		else
		{
			sp->parm.capture.timeperframe.numerator = 1000;
		}
	}
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_g_parm() numerator(0d%d) denominator(0d%d)!!!!!!!!!\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), sp->parm.capture.timeperframe.numerator, sp->parm.capture.timeperframe.denominator );


	return 0;
}
#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,27)

static int common_video_device_vidioc_enum_frameintervals(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_frmivalenum *fival)
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_enum_frameintervals() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_enum_frameintervals() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}
	//this is related to framerate
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_enum_frameintervals() index(0x%x) width(0d%d) height(0d%d) pixel_format(0x%x)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), fival->index, fival->width, fival->height, fival->pixel_format );

	if (fival->index > 0)
		return -EINVAL;

	#ifdef AME_SA7160
	
	SA7160_SYS_CFG * p_sys_cfg = (SA7160_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);

	#endif

	#ifdef AME_FH8735
	
	FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);
	
	#endif

	#if defined(AME_PL330B) || defined(AME_PL330A)
	
	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);
	
	#endif

	#ifdef AME_MZ0380
	
	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);
	
	#endif

	if(p_sys_cfg)//HD
	{
		fival->type = V4L2_FRMIVAL_TYPE_DISCRETE;

		if(p_sys_cfg->n_input_video_resolution_fps_m == 1)
		{
			fival->discrete.numerator = 1001;
		}
		else
		{
			fival->discrete.numerator = 1000;
		}
	

		fival->discrete.denominator = p_sys_cfg->n_input_video_resolution_fps * 1000;

		if( p_sys_cfg->n_input_video_resolution_interleaved == 1 )
		{
			fival->discrete.denominator /= 2;
		}
	}
	else//pure analog
	{
		//strange, fival->type = V4L2_FRMIVAL_TYPE_DISCRETE; can not be set ??
		/*
		if(pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50)
		{
			fival->discrete.numerator = 1000;

			fival->discrete.denominator = 25 * 1000;
		}
		else
		{
			fival->discrete.numerator = 1001;

			fival->discrete.denominator = 30 * 1000;
		}
		*/
	}
	return 0;

}

static int common_video_device_vidioc_enum_framesizes(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_frmsizeenum *fsize)
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_enum_framesizes() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_enum_framesizes() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_enum_framesizes() \n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	if (fsize->index > 0)
	    return -EINVAL;
 
	fsize->type = V4L2_FRMSIZE_TYPE_DISCRETE;

	if(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty)
	{
		fsize->discrete.width = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty >> 16 ) & 0xFFFF;

		fsize->discrete.height = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty ) & 0xFFFF;
	
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoInterleavedProperty == 1 )
		{
			fsize->discrete.height *= 2;
		}
	}
	else
	{
		fsize->discrete.width = pVideo->FD1832F8D382F4e91914C0048CC5A9DD8; 

		fsize->discrete.height = pVideo->F5B8891B732954fc2B26B7BFFCB15B596;
	}
	return 0;
}

static int common_video_device_vidioc_s_crop(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_cropcap *cropcap)
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_s_crop() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_s_crop() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_s_crop()\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	return 0;
}
static int common_video_device_vidioc_g_crop(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_cropcap *cropcap)
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_g_crop() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_g_crop() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_g_crop()\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	return 0;
}

static int common_video_device_vidioc_cropcap(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_cropcap *cropcap)
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_cropcap() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_cropcap() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_cropcap()\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	int type = cropcap->type;
 
	memset(cropcap, 0, sizeof(*cropcap));
	
	cropcap->type = type;

	if (cropcap->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
		return -EINVAL;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_cropcap() enter\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

//no crop
	cropcap->bounds.top = cropcap->bounds.left = 0;
	cropcap->defrect.top = cropcap->defrect.left = 0;
	
	if(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty)
	{
		cropcap->bounds.width = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty >> 16 ) & 0xFFFF;
		cropcap->bounds.height = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty ) & 0xFFFF;

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoInterleavedProperty == 1 )
		{
			cropcap->bounds.height *= 2;
		}
	
	
		cropcap->defrect.width = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty >> 16 ) & 0xFFFF;
		cropcap->defrect.height = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty ) & 0xFFFF;
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoInterleavedProperty == 1 )
		{
			cropcap->defrect.height *= 2;
		}
	}
	else
	{
		cropcap->bounds.width = pVideo->FD1832F8D382F4e91914C0048CC5A9DD8;

		cropcap->bounds.height = pVideo->F5B8891B732954fc2B26B7BFFCB15B596;

		cropcap->defrect.width = pVideo->FD1832F8D382F4e91914C0048CC5A9DD8;

		cropcap->defrect.height = pVideo->F5B8891B732954fc2B26B7BFFCB15B596;
	}
						 
	cropcap->pixelaspect.numerator = 1;
	cropcap->pixelaspect.denominator = 1;
	
	return 0;
}

#endif


#define V4L2_PIX_FMT_MPG4 v4l2_fourcc( 'M', 'P', 'G', '4' )

#define V4L2_PIX_FMT_H264 v4l2_fourcc( 'H', '2', '6', '4' )

static int F4AE125B7768742c4ADCFED552CAF7C82( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_fmtdesc * p_fmtdesc )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F4AE125B7768742c4ADCFED552CAF7C82() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F4AE125B7768742c4ADCFED552CAF7C82() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F4AE125B7768742c4ADCFED552CAF7C82( I:%02d, T:%02d )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_fmtdesc->index, p_fmtdesc->type );

	if( p_fmtdesc->type == V4L2_BUF_TYPE_VIDEO_CAPTURE ) {

		if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001 ) {

			if( p_fmtdesc->index == 0 ) {

				#ifndef AME_PL330A
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5851 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x9413 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6010 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1999 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA04C ) { sprintf( p_fmtdesc->description, "%s", "UYVY 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_UYVY; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 ) { sprintf( p_fmtdesc->description, "%s", "YV12 4:2:0" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YVU420; }
//below is for FC16X64				
//				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 ) { sprintf( p_fmtdesc->description, "%s", "UYVY 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_UYVY; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 ) { sprintf( p_fmtdesc->description, "%s", "YV12 4:2:0" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YVU420; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100 ) { sprintf( p_fmtdesc->description, "%s", "YV12 4:2:0" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YVU420; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370 ) { sprintf( p_fmtdesc->description, "%s", "YV12 4:2:0" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YVU420; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380 ) { sprintf( p_fmtdesc->description, "%s", "YV12 4:2:0" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YVU420; }
				#ifdef CUEBI_WEBRTC
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				#else
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 ) { sprintf( p_fmtdesc->description, "%s", "YV12 4:2:0" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YVU420; }
				#endif
								
				#endif
				return 0;
			}
		}
		if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002 ) {

			if( p_fmtdesc->index == 0 ) {

				#ifndef AME_PL330A
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5851 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 ) { sprintf( p_fmtdesc->description, "%s", "YUYV 4:2:2" ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
			//	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x9413 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6010 ) { sprintf( p_fmtdesc->description, "%s", "MPEG4"      ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_MPG4; }
			//	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1999 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA04C ) { sprintf( p_fmtdesc->description, "%s", "H.264"      ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_H264; }
			//	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 ) { sprintf( p_fmtdesc->description, "%s", "H.264"      ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_H264; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x9413 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6010 ) { sprintf( p_fmtdesc->description, "%s", "MPEG4"      ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1999 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA04C ) { sprintf( p_fmtdesc->description, "%s", "H.264"      ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YUYV; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 ) { sprintf( p_fmtdesc->description, "%s", "H.264"      ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_YVU420; }
//peter [2011.06.29]
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 ) { sprintf( p_fmtdesc->description, "%s", "H.264"      ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_H264; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100 ) { sprintf( p_fmtdesc->description, "%s", "H.264"      ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_H264; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370 ) { sprintf( p_fmtdesc->description, "%s", "H.264"      ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_H264; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380 ) { sprintf( p_fmtdesc->description, "%s", "H.264"      ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_H264; }
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 ) { sprintf( p_fmtdesc->description, "%s", "H.264"      ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_H264; }
				#else
				sprintf( p_fmtdesc->description, "%s", "H.264"      ); p_fmtdesc->pixelformat = V4L2_PIX_FMT_H264;				
				#endif

				return 0;
			}
		}
	}
	return -EINVAL;
}

static int FAA9A4D7A9B264da19300EE68477972A1( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_format * p_fmt )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FAA9A4D7A9B264da19300EE68477972A1() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FAA9A4D7A9B264da19300EE68477972A1() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FAA9A4D7A9B264da19300EE68477972A1( T:%02d, F:%02d )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_fmt->type, p_fmt->fmt.pix.field );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FAA9A4D7A9B264da19300EE68477972A1() width(%d) height(%d) pixelformat(%x)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_fmt->fmt.pix.width, p_fmt->fmt.pix.height, p_fmt->fmt.pix.pixelformat );

	if( p_fmt->type == V4L2_BUF_TYPE_VIDEO_CAPTURE ) {

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "try_fmt- %08X:%03dX%03d:%d:%d\n", p_fmt->fmt.pix.pixelformat, p_fmt->fmt.pix.width, p_fmt->fmt.pix.height, p_fmt->fmt.pix.bytesperline, p_fmt->fmt.pix.sizeimage );

//V4L2_PIX_FMT_UYVY //UYVY
//V4L2_PIX_FMT_YVU420 //YV12
//V4L2_PIX_FMT_YUYV //YUYV

		if( p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUYV ||
			p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_UYVY ||
			p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420  ||
			p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_GREY  ||
//not work for ffmpeg			
			p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420  ||
			p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_MPG4 ||
			p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_H264 ) { 

			if( p_fmt->fmt.pix.field == V4L2_FIELD_ANY ) { p_fmt->fmt.pix.field = V4L2_FIELD_INTERLACED; }
			
			//if( p_fmt->fmt.pix.field != V4L2_FIELD_INTERLACED ) { return -EINVAL; }
//below is for gstreamer
/*
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoInterleavedProperty == 1)
			{
				if(p_fmt->fmt.pix.field != V4L2_FIELD_INTERLACED)
				{ 
					return -EINVAL;
				}
			}
			else
			{
				if(p_fmt->fmt.pix.field == V4L2_FIELD_INTERLACED)
				{ 
					return -EINVAL;
				}
			}
*/
	
			#ifndef AME_PL330A
			if(p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420 || p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420)//YV12
			{
				if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5851) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160) 	)
				{
				    return -EINVAL;
				}

				#ifdef CUEBI_WEBRTC
				if(	pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 )
				{
				    return -EINVAL;
				}
				#endif

			}
			if(p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUYV || p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_UYVY)
			{
				if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) || 
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
					(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) 	)
				{
					#ifdef CUEBI_WEBRTC
					NULL;
					#else
				    return -EINVAL;
					#endif
				}
			}

			if(p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420)
			{
				if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) )
				{
				    return -EINVAL;
				}
			}
			#endif

			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) { 

				if( p_fmt->fmt.pix.width  <  320 ) { p_fmt->fmt.pix.width  =  320; }

				if( p_fmt->fmt.pix.height <  240 ) { p_fmt->fmt.pix.height =  240; }

//				if( p_fmt->fmt.pix.width  > 1024 ) { p_fmt->fmt.pix.width  = 1024; }

//				if( p_fmt->fmt.pix.height >  768 ) { p_fmt->fmt.pix.height =  768; }
			}
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) { 

				if( p_fmt->fmt.pix.width  <  320 ) { p_fmt->fmt.pix.width  =  320; }

				if( p_fmt->fmt.pix.height <  288 ) { p_fmt->fmt.pix.height =  288; }

//				if( p_fmt->fmt.pix.width  > 1024 ) { p_fmt->fmt.pix.width  = 1024; }

//				if( p_fmt->fmt.pix.height >  768 ) { p_fmt->fmt.pix.height =  768; }
			}
//gstreamer 1.2
			if( p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420  || p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420 ) {

				p_fmt->fmt.pix.bytesperline = (p_fmt->fmt.pix.width );
				p_fmt->fmt.pix.sizeimage = (p_fmt->fmt.pix.bytesperline * p_fmt->fmt.pix.height * 12) >> 3;
			}
			else {
				
				p_fmt->fmt.pix.bytesperline = (p_fmt->fmt.pix.width * 16) >> (3);
				p_fmt->fmt.pix.sizeimage = (p_fmt->fmt.pix.bytesperline * p_fmt->fmt.pix.height);
			}

			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) { 

				if( p_fmt->fmt.pix.width >= 768 && p_fmt->fmt.pix.height >= 480 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 768; pVideo->F2039B582640548a6B3F55D13092DCF5F = 480; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 768 * 480 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 720 && p_fmt->fmt.pix.height >= 480 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 720; pVideo->F2039B582640548a6B3F55D13092DCF5F = 480; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 720 * 480 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 720 && p_fmt->fmt.pix.height <  480 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 720; pVideo->F2039B582640548a6B3F55D13092DCF5F = 240; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 720 * 240 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 704 && p_fmt->fmt.pix.height >= 480 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 704; pVideo->F2039B582640548a6B3F55D13092DCF5F = 480; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 704 * 480 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 704 && p_fmt->fmt.pix.height <  480 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 704; pVideo->F2039B582640548a6B3F55D13092DCF5F = 240; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 704 * 240 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 640 && p_fmt->fmt.pix.height >= 480 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 640; pVideo->F2039B582640548a6B3F55D13092DCF5F = 480; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 640 * 480 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 640 && p_fmt->fmt.pix.height <  480 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 640; pVideo->F2039B582640548a6B3F55D13092DCF5F = 240; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 640 * 240 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else
				//
				if( p_fmt->fmt.pix.width >= 384 && p_fmt->fmt.pix.height >= 240 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 384; pVideo->F2039B582640548a6B3F55D13092DCF5F = 240; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 384 * 240 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 360 && p_fmt->fmt.pix.height >= 240 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 360; pVideo->F2039B582640548a6B3F55D13092DCF5F = 240; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 360 * 240 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 352 && p_fmt->fmt.pix.height >= 240 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 352; pVideo->F2039B582640548a6B3F55D13092DCF5F = 240; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 352 * 240 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 320 && p_fmt->fmt.pix.height >= 240 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 320; pVideo->F2039B582640548a6B3F55D13092DCF5F = 240; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 320 * 240 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; }
			}
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) { 

				if( p_fmt->fmt.pix.width >= 768 && p_fmt->fmt.pix.height >= 576 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 768; pVideo->F2039B582640548a6B3F55D13092DCF5F = 576; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 768 * 576 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 720 && p_fmt->fmt.pix.height >= 576 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 720; pVideo->F2039B582640548a6B3F55D13092DCF5F = 576; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 720 * 576 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 720 && p_fmt->fmt.pix.height <  576 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 720; pVideo->F2039B582640548a6B3F55D13092DCF5F = 288; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 720 * 288 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 704 && p_fmt->fmt.pix.height >= 576 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 704; pVideo->F2039B582640548a6B3F55D13092DCF5F = 576; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 704 * 576 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 704 && p_fmt->fmt.pix.height <  576 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 704; pVideo->F2039B582640548a6B3F55D13092DCF5F = 288; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 704 * 288 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 640 && p_fmt->fmt.pix.height >= 576 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 640; pVideo->F2039B582640548a6B3F55D13092DCF5F = 576; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 640 * 576 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 640 && p_fmt->fmt.pix.height <  576 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 640; pVideo->F2039B582640548a6B3F55D13092DCF5F = 288; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 640 * 288 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else
				//
				if( p_fmt->fmt.pix.width >= 384 && p_fmt->fmt.pix.height >= 288 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 384; pVideo->F2039B582640548a6B3F55D13092DCF5F = 288; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 384 * 288 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 360 && p_fmt->fmt.pix.height >= 288 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 360; pVideo->F2039B582640548a6B3F55D13092DCF5F = 288; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 360 * 288 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 352 && p_fmt->fmt.pix.height >= 288 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 352; pVideo->F2039B582640548a6B3F55D13092DCF5F = 288; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 352 * 288 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; } else

				if( p_fmt->fmt.pix.width >= 320 && p_fmt->fmt.pix.height >= 288 ) { pVideo->F3FCE6081A67349839E69BEDE056CFEED = 320; pVideo->F2039B582640548a6B3F55D13092DCF5F = 288; pVideo->F10CC5793AEB4486dA7AFE99A1176E51D = ( (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420) || (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ) ? 12 : 16; pVideo->F9D5A3DD27B7F43ea83AF4273BB7AE003 = 320 * 288 * pVideo->F10CC5793AEB4486dA7AFE99A1176E51D / 8; }
			}
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "- RESET!!\n" );
			return 0;

		}//end of format 

	}//end of capture
    return -EINVAL;
}
extern BOOLEAN C2B253D32391436C99E0206137A018A8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, BYTE bValue );
extern BYTE E4353F1BD7E74904BE78DD9F001BD652( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex );

static int FEE6EBBFC370841adADAA57CE5BEE5614( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_format * p_fmt )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FEE6EBBFC370841adADAA57CE5BEE5614() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FEE6EBBFC370841adADAA57CE5BEE5614() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FEE6EBBFC370841adADAA57CE5BEE5614( T:%02d )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_fmt->type );

	if( p_fmt->type == V4L2_BUF_TYPE_VIDEO_CAPTURE ) {

		int ret = FAA9A4D7A9B264da19300EE68477972A1( FEBA6DA02A6244ff7AFA9DCC660800FB4, FBC3D436FD4754a78A5BE6F92EB05E3FE, p_fmt );

		if( ret != 0 ) { return ret; }

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "s_fmt- %08X:%03dX%03d:%d:%d\n", p_fmt->fmt.pix.pixelformat, p_fmt->fmt.pix.width, p_fmt->fmt.pix.height, p_fmt->fmt.pix.bytesperline, p_fmt->fmt.pix.sizeimage );

		if( p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUYV ||
			p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_UYVY ||
			p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420  ||
			p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_GREY  ||
//not work for ffmpeg			
			p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420  ||
			p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_MPG4 ||
			p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_H264 ) { 

			pVideo->FD1832F8D382F4e91914C0048CC5A9DD8    = p_fmt->fmt.pix.width;
			pVideo->F5B8891B732954fc2B26B7BFFCB15B596   = p_fmt->fmt.pix.height;
			pVideo->F71FE13C55F1948828A7FA0A0A5800543    = p_fmt->fmt.pix.bytesperline;
			pVideo->F07563F8419D74e1cB3F1A4F962EBACE8     = p_fmt->fmt.pix.sizeimage;
			pVideo->FA8153D6A19C2451d94BB0F52E68471F1 = p_fmt->fmt.pix.pixelformat;
			pVideo->FEDE037FA62F943829C230928859309D9  = p_fmt->fmt.pix.field;
			
			pVideo->FFA9FA378762B440d9F8489DE5A6432B3 = (p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YVU420 || p_fmt->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) ? 12 : 16;

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "- MATCH!! (SRC:%d:%d) (DST:%d:%d)\n", (int)(pVideo->F3FCE6081A67349839E69BEDE056CFEED), (int)(pVideo->F2039B582640548a6B3F55D13092DCF5F), (int)(pVideo->FD1832F8D382F4e91914C0048CC5A9DD8), (int)(pVideo->F5B8891B732954fc2B26B7BFFCB15B596) );

			#ifndef AME_PL330A
			if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) {

				c6c3937b81f94efaa887c881fbb5fb63( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo );						
			}

			if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) {
		
				int index = 0;

				if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x03) ||	(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x85) )
				{
					index = ((pVideo->F0DD7393CD1494e27A72652C7D1A97893 < 4) ? pVideo->F0DD7393CD1494e27A72652C7D1A97893: pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 4);// subdevice 0~3 use array 0~3, subdevice 4~7 use array 8~11
				}
				else if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) )
				{
					index = ((pVideo->F0DD7393CD1494e27A72652C7D1A97893 < 1) ? pVideo->F0DD7393CD1494e27A72652C7D1A97893: pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 7);// subdevice 0 use array 0, subdevice 1 use array 8
				}
				else
				{
					index = ((pVideo->F0DD7393CD1494e27A72652C7D1A97893 < 4) ? pVideo->F0DD7393CD1494e27A72652C7D1A97893: pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 4);// subdevice 0~3 use array 0~3, subdevice 4~7 use array 8~11
				}

				if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001)
				{
					pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomPreviewVideoResolutionProperty[ index ]  =   0x88000000 | (pVideo->FD1832F8D382F4e91914C0048CC5A9DD8) << 12 | (pVideo->F5B8891B732954fc2B26B7BFFCB15B596);
				}

				if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
				{
					
					pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoResolutionProperty[ index ]  =   0x88000000 | (pVideo->FD1832F8D382F4e91914C0048CC5A9DD8) << 12 | (pVideo->F5B8891B732954fc2B26B7BFFCB15B596);
				
				}
			}

			if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||
				
				(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||

				(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) ) {
		
				int index = 0;
				/*
				if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x03) ||	(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x85) )
				{
					index = ((pVideo->F0DD7393CD1494e27A72652C7D1A97893 < 4) ? pVideo->F0DD7393CD1494e27A72652C7D1A97893: pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 4);// subdevice 0~3 use array 0~3, subdevice 4~7 use array 8~11
				}
				else if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) )
				{
					index = ((pVideo->F0DD7393CD1494e27A72652C7D1A97893 < 1) ? pVideo->F0DD7393CD1494e27A72652C7D1A97893: pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 7);// subdevice 0 use array 0, subdevice 1 use array 8
				}
				else
				{
					index = ((pVideo->F0DD7393CD1494e27A72652C7D1A97893 < 4) ? pVideo->F0DD7393CD1494e27A72652C7D1A97893: pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 4);// subdevice 0~3 use array 0~3, subdevice 4~7 use array 8~11
				}
				*/
				if( ((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == 0x02) || ((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == 0x03)  ) { // 960H & D1
				
					if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer & 0x0F) == 0x0A ) {

						//counts = 8;
						index = ((pVideo->F0DD7393CD1494e27A72652C7D1A97893 < 8) ? pVideo->F0DD7393CD1494e27A72652C7D1A97893: pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 8);// subdevice 0~7 use array 0~7, subdevice 8~15 use array 8~15
					}
					else {

						//counts = 4;
						index = ((pVideo->F0DD7393CD1494e27A72652C7D1A97893 < 4) ? pVideo->F0DD7393CD1494e27A72652C7D1A97893: pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 4);// subdevice 0~3 use array 0~3, subdevice 4~7 use array 8~11

					}
				}

				if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
				{
					pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoResolutionProperty[ index ]  =   0x88000000 | (pVideo->FD1832F8D382F4e91914C0048CC5A9DD8) << 12 | (pVideo->F5B8891B732954fc2B26B7BFFCB15B596);
				}
			}
			//after vidioc_s_input
			//euresys square pixel

			if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160) ) {

				if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty == 5) || (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty == 6) ) 
				{

					B6B487882F964675B66617C7847B8BB5EX( pVideo->FB6E79A0780E64bb28A3308666E67881C );

					SA7160_SYS_CFG * p_sys_cfg = (SA7160_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);

					p_sys_cfg->n_input_video_resolution_cx = pVideo->FD1832F8D382F4e91914C0048CC5A9DD8;

					p_sys_cfg->n_input_video_resolution_cy = pVideo->F5B8891B732954fc2B26B7BFFCB15B596 / 2;

					BYTE reg02 = E4353F1BD7E74904BE78DD9F001BD652( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x02 );

					BYTE reg07 = E4353F1BD7E74904BE78DD9F001BD652( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x07 ); reg07 &= 0xFC;

					BYTE reg0B = E4353F1BD7E74904BE78DD9F001BD652( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x0B );

					BYTE gpio2 = 0;
					BYTE gpio3 = 0;


					if( (pVideo->FD1832F8D382F4e91914C0048CC5A9DD8 == 720) && (pVideo->F5B8891B732954fc2B26B7BFFCB15B596 == 480) )
					{
						//only update bit 6 // 0 is square pixel
						reg02 |= 0x40;

						p_sys_cfg->n_input_video_resolution_cx = 720;

						p_sys_cfg->n_input_video_resolution_cy = 240;

						//set Hactive to 722

						reg07 |= 0x02;

						reg0B = 0xD2;

						gpio2 = 1;
						gpio3 = 0;
					}
					else if( (pVideo->FD1832F8D382F4e91914C0048CC5A9DD8 == 640) && (pVideo->F5B8891B732954fc2B26B7BFFCB15B596 == 480) )
					{
						reg02 &= ~0x40;

						p_sys_cfg->n_input_video_resolution_cx = 640;

						p_sys_cfg->n_input_video_resolution_cy = 240;

						//set Hactive to 654

						reg07 |= 0x02;

						reg0B = 0x8E;

						gpio2 = 0;
						gpio3 = 0;
					}
					else if( (pVideo->FD1832F8D382F4e91914C0048CC5A9DD8 == 768) && (pVideo->F5B8891B732954fc2B26B7BFFCB15B596 == 576) )
					{
						reg02 &= ~0x40;

						p_sys_cfg->n_input_video_resolution_cx = 768;

						p_sys_cfg->n_input_video_resolution_cy = 288;

						//set Hactive to 782

						reg07 |= 0x03;

						reg0B = 0x0E;

						gpio2 = 1;
						gpio3 = 1;
					}
					else if( (pVideo->FD1832F8D382F4e91914C0048CC5A9DD8 == 720) && (pVideo->F5B8891B732954fc2B26B7BFFCB15B596 == 576) )
					{
						reg02 |= 0x40;

						p_sys_cfg->n_input_video_resolution_cx = 720;

						p_sys_cfg->n_input_video_resolution_cy = 288;

						//set Hactive to 722

						reg07 |= 0x02;

						reg0B = 0xD2;

						gpio2 = 1;
						gpio3 = 0;
					}
					else
					{
						p_sys_cfg->n_input_video_resolution_cx = 720;

						p_sys_cfg->n_input_video_resolution_cy = 240;

						//set Hactive to 722

						reg07 |= 0x02;

						reg0B = 0xD2;

						gpio2 = 1;
						gpio3 = 0;
					}

					C2B253D32391436C99E0206137A018A8( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x02, reg02 );
					
					C2B253D32391436C99E0206137A018A8( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x07, reg07 );

					C2B253D32391436C99E0206137A018A8( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x0B, reg0B );

					ULONG R0000E004 = A77C4935F8134B048348571A43F2A9CA( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x0000E000 + 0x0004 ); // GPIO.WR
	
					R0000E004 &= 0xFFFFFFF3; 

					R0000E004 |= (gpio2 << 2); 
					R0000E004 |= (gpio3 << 3); 

					A60D06861EDC409FA66867980ABA9748( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x0000E000 + 0x0004, R0000E004 );

					p_sys_cfg->b_input_video_signal_changed = TRUE;

					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "$$$ n_input_video_resolution_cx(%d) n_input_video_resolution_cy(%d)\n", p_sys_cfg->n_input_video_resolution_cx, p_sys_cfg->n_input_video_resolution_cy);

					F5D69F1955AA4EBCAF770CF98A9B4992EX( pVideo->FB6E79A0780E64bb28A3308666E67881C );
				}

			}
			#endif

			return 0;
		}
	}
	return -EINVAL;
}

static int F6727CA3250D341ac870EBFB883ABD913( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_format * p_fmt )
{
	struct video_device * F6CA67B866FA04fab8C939AEA549AEEBA = (struct video_device *)(video_devdata( FEBA6DA02A6244ff7AFA9DCC660800FB4 ));

	if( F6CA67B866FA04fab8C939AEA549AEEBA == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F6727CA3250D341ac870EBFB883ABD913() F6CA67B866FA04fab8C939AEA549AEEBA == NULL\n" );

		return 0;
	}

	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F6727CA3250D341ac870EBFB883ABD913() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F6727CA3250D341ac870EBFB883ABD913() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F6727CA3250D341ac870EBFB883ABD913( T:%02d )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_fmt->type );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F6727CA3250D341ac870EBFB883ABD913() FD1832F8D382F4e91914C0048CC5A9DD8(%d)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->FD1832F8D382F4e91914C0048CC5A9DD8 );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F6727CA3250D341ac870EBFB883ABD913() F5B8891B732954fc2B26B7BFFCB15B596(%d)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->F5B8891B732954fc2B26B7BFFCB15B596 );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F6727CA3250D341ac870EBFB883ABD913() F71FE13C55F1948828A7FA0A0A5800543(%d)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->F71FE13C55F1948828A7FA0A0A5800543 );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F6727CA3250D341ac870EBFB883ABD913() F07563F8419D74e1cB3F1A4F962EBACE8(%d)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->F07563F8419D74e1cB3F1A4F962EBACE8 );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F6727CA3250D341ac870EBFB883ABD913() FA8153D6A19C2451d94BB0F52E68471F1(0x%x)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->FA8153D6A19C2451d94BB0F52E68471F1 );
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F6727CA3250D341ac870EBFB883ABD913() FEDE037FA62F943829C230928859309D9(0x%x)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->FEDE037FA62F943829C230928859309D9 );

	if( p_fmt->type == V4L2_BUF_TYPE_VIDEO_CAPTURE ) {

		#ifndef AME_PL330A
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			if(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty != 0)
			{
				pVideo->FD1832F8D382F4e91914C0048CC5A9DD8                  = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty >> 16 ) & 0xFFFF;
				pVideo->F5B8891B732954fc2B26B7BFFCB15B596                 = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty ) & 0xFFFF;

				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoInterleavedProperty == 1 )
				{
					pVideo->F5B8891B732954fc2B26B7BFFCB15B596 *= 2;
				}

				pVideo->F71FE13C55F1948828A7FA0A0A5800543                  = pVideo->FD1832F8D382F4e91914C0048CC5A9DD8 * 2;
				pVideo->FFA9FA378762B440d9F8489DE5A6432B3               = 16;
				pVideo->F07563F8419D74e1cB3F1A4F962EBACE8                   = pVideo->FD1832F8D382F4e91914C0048CC5A9DD8 * pVideo->F5B8891B732954fc2B26B7BFFCB15B596 * 2;
			}
		}
		#endif

		p_fmt->fmt.pix.colorspace   = V4L2_COLORSPACE_SMPTE170M; //
		p_fmt->fmt.pix.width        = pVideo->FD1832F8D382F4e91914C0048CC5A9DD8;
		p_fmt->fmt.pix.height       = pVideo->F5B8891B732954fc2B26B7BFFCB15B596;
		p_fmt->fmt.pix.bytesperline = pVideo->F71FE13C55F1948828A7FA0A0A5800543;
		p_fmt->fmt.pix.sizeimage    = pVideo->F07563F8419D74e1cB3F1A4F962EBACE8;
		p_fmt->fmt.pix.pixelformat  = pVideo->FA8153D6A19C2451d94BB0F52E68471F1;
		p_fmt->fmt.pix.field        = pVideo->FEDE037FA62F943829C230928859309D9;
		p_fmt->fmt.pix.priv         = 0;


		#ifndef AME_PL330A
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) 
		{
			p_fmt->fmt.pix.width        = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty >> 16 ) & 0xFFFF;

			p_fmt->fmt.pix.height       = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty ) & 0xFFFF;

			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoInterleavedProperty == 1 )
			{
				p_fmt->fmt.pix.height *= 2;
		
				p_fmt->fmt.pix.field        = V4L2_FIELD_INTERLACED;
			}
			else
			{
				//p_fmt->fmt.pix.field        = V4L2_FIELD_NONE;
			}

			if(p_fmt->fmt.pix.width >= 1280)
			{
				p_fmt->fmt.pix.colorspace   = V4L2_COLORSPACE_REC709;
			}
			else
			{
				p_fmt->fmt.pix.colorspace   = V4L2_COLORSPACE_SMPTE170M;
			}


			if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001)//preview
			{
				if( (p_fmt->fmt.pix.width == 1280) && (p_fmt->fmt.pix.height == 720) )
				{
					if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nHVScaleFactor == 0x00020002 )
					{
						p_fmt->fmt.pix.width /= 2;
						p_fmt->fmt.pix.height /= 2;
					}
				}
			
				if( (p_fmt->fmt.pix.width == 1920) && (p_fmt->fmt.pix.height == 1080) )
				{
					if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nHVScaleFactor == 0x00020002 )
					{
						p_fmt->fmt.pix.width /= 2;
						p_fmt->fmt.pix.height /= 2;
					}

					if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nHVScaleFactor == 0x00040004 )
					{
						p_fmt->fmt.pix.width /= 4;
						p_fmt->fmt.pix.height /= 4;
					}

				}
				p_fmt->fmt.pix.bytesperline = (p_fmt->fmt.pix.width );
				p_fmt->fmt.pix.sizeimage = (p_fmt->fmt.pix.bytesperline * p_fmt->fmt.pix.height * 12) >> 3;

				p_fmt->fmt.pix.pixelformat  = V4L2_PIX_FMT_YVU420;

			}

			if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)//encode
			{
				
				BYTE* pch = NULL;
				
				pch = strchr(F6CA67B866FA04fab8C939AEA549AEEBA->name,'M');

				if( pch )
				{
					//main
					if( ( (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nH264HVScaleFactor >> 16) & 0x303) == 0x0202)
					{
						p_fmt->fmt.pix.width /= 2;
						p_fmt->fmt.pix.height /= 2;
					}

					if( ( (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nH264HVScaleFactor >> 16) & 0x303) == 0x0303)
					{
						p_fmt->fmt.pix.width /= 4;
						p_fmt->fmt.pix.height /= 4;
					}
				
					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F6727CA3250D341ac870EBFB883ABD913( main ) width(%d) height(%d) m_nH264HVScaleFactor(0x%x)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_fmt->fmt.pix.width, p_fmt->fmt.pix.height, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nH264HVScaleFactor  );

				}
				else
				{
					//sub
					if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nH264HVScaleFactor & 0xFFFF) == 0x0202)
					{
						p_fmt->fmt.pix.width /= 2;
						p_fmt->fmt.pix.height /= 2;
					}

					if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nH264HVScaleFactor & 0xFFFF) == 0x0303)
					{
						p_fmt->fmt.pix.width /= 4;
						p_fmt->fmt.pix.height /= 4;
					}
					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F6727CA3250D341ac870EBFB883ABD913( sub ) width(%d) height(%d)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_fmt->fmt.pix.width, p_fmt->fmt.pix.height  );

				}
				p_fmt->fmt.pix.pixelformat  = V4L2_PIX_FMT_H264;
			}


		}
		
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			p_fmt->fmt.pix.width        = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty >> 16 ) & 0xFFFF;

			p_fmt->fmt.pix.height       = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty ) & 0xFFFF;

			if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty == 5) || (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty == 6) )//AV, S
			{
				p_fmt->fmt.pix.width = 720;

				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 )
				{
					p_fmt->fmt.pix.height = 240;
				}
				else
				{
					p_fmt->fmt.pix.height = 288;
				}
			}

//if gstreamer, disable below
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoInterleavedProperty == 1 )
			{
				p_fmt->fmt.pix.height *= 2;
		
				p_fmt->fmt.pix.field        = V4L2_FIELD_INTERLACED;
			}
			else
			{
				p_fmt->fmt.pix.field        = V4L2_FIELD_NONE;
			}

			if(p_fmt->fmt.pix.width >= 1280)
			{
				p_fmt->fmt.pix.colorspace   = V4L2_COLORSPACE_REC709;
			}
			else
			{
				p_fmt->fmt.pix.colorspace   = V4L2_COLORSPACE_SMPTE170M;
			}

			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty == 3)//VGA
			{
				p_fmt->fmt.pix.colorspace   = V4L2_COLORSPACE_SRGB;
			}

			p_fmt->fmt.pix.bytesperline = p_fmt->fmt.pix.width * 2;

			p_fmt->fmt.pix.sizeimage    = p_fmt->fmt.pix.bytesperline * p_fmt->fmt.pix.height;


		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
		{
			//if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001)//preview
			{
				p_fmt->fmt.pix.width        = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty >> 16 ) & 0xFFFF;

				p_fmt->fmt.pix.height       = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty ) & 0xFFFF;

				if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty == 5) || (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty == 6) )//AV, S
				{
					p_fmt->fmt.pix.width = 720;

					if( pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 )
					{
						p_fmt->fmt.pix.height = 240;
					}
					else
					{
						p_fmt->fmt.pix.height = 288;
					}
				}

	//if gstreamer, disable below
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoInterleavedProperty == 1 )
				{
					p_fmt->fmt.pix.height *= 2;
		
					p_fmt->fmt.pix.field        = V4L2_FIELD_INTERLACED;
				}
				else
				{
					//p_fmt->fmt.pix.field        = V4L2_FIELD_NONE;
				}

				if(p_fmt->fmt.pix.width >= 1280)
				{
					p_fmt->fmt.pix.colorspace   = V4L2_COLORSPACE_REC709;
				}
				else
				{
					p_fmt->fmt.pix.colorspace   = V4L2_COLORSPACE_SMPTE170M;
				}

				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty == 3)//VGA
				{
					p_fmt->fmt.pix.colorspace   = V4L2_COLORSPACE_SRGB;
				}

				if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001)//preview
				{
					p_fmt->fmt.pix.pixelformat  = V4L2_PIX_FMT_YVU420;
				}
				else
				{
					p_fmt->fmt.pix.pixelformat  = V4L2_PIX_FMT_H264;
				}

				p_fmt->fmt.pix.bytesperline = p_fmt->fmt.pix.width;

				p_fmt->fmt.pix.sizeimage    = (p_fmt->fmt.pix.bytesperline * p_fmt->fmt.pix.height * 3) >> 1;
			}
		}

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 )
		{
			p_fmt->fmt.pix.width        = 704;

			p_fmt->fmt.pix.height       = (pVideo->FB6E79A0780E64bb28A3308666E67881C->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60) ? (480) : (576);

			p_fmt->fmt.pix.colorspace   = V4L2_COLORSPACE_SMPTE170M;


			if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001)//preview
			{
				p_fmt->fmt.pix.pixelformat  = V4L2_PIX_FMT_YVU420;

				p_fmt->fmt.pix.bytesperline = p_fmt->fmt.pix.width;

				p_fmt->fmt.pix.sizeimage    = (p_fmt->fmt.pix.bytesperline * p_fmt->fmt.pix.height * 3) >> 1;
			}
			else
			{
				p_fmt->fmt.pix.pixelformat  = V4L2_PIX_FMT_H264;
			}
		}

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 )
		{
			if(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty != 0)
			{
				p_fmt->fmt.pix.width        = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty >> 16 ) & 0xFFFF;

				p_fmt->fmt.pix.height       = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty ) & 0xFFFF;

				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoInterleavedProperty == 1 )
				{
					p_fmt->fmt.pix.height *= 2;
		
					p_fmt->fmt.pix.field        = V4L2_FIELD_INTERLACED;
				}
				else
				{
					//if gstreamer, disable below
					//p_fmt->fmt.pix.field        = V4L2_FIELD_NONE;
				}

				if(p_fmt->fmt.pix.width >= 1280)
				{
					p_fmt->fmt.pix.colorspace   = V4L2_COLORSPACE_REC709;
				}
				else
				{
					p_fmt->fmt.pix.colorspace   = V4L2_COLORSPACE_SMPTE170M;
				}

				p_fmt->fmt.pix.bytesperline = (p_fmt->fmt.pix.width );

				p_fmt->fmt.pix.sizeimage = (p_fmt->fmt.pix.bytesperline * p_fmt->fmt.pix.height * 12) >> 3;
			}

			if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001)//preview
			{
				p_fmt->fmt.pix.pixelformat = V4L2_PIX_FMT_YVU420;
			}
			else
			{
				p_fmt->fmt.pix.pixelformat = V4L2_PIX_FMT_H264;
			}
		}
		#else
		{
			if(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty != 0)
			{
				p_fmt->fmt.pix.width        = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty >> 16 ) & 0xFFFF;

				p_fmt->fmt.pix.height       = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty ) & 0xFFFF;

				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoInterleavedProperty == 1 )
				{
					p_fmt->fmt.pix.height *= 2;
		
					p_fmt->fmt.pix.field        = V4L2_FIELD_INTERLACED;
				}
				else
				{
					//if gstreamer, disable below
					//p_fmt->fmt.pix.field        = V4L2_FIELD_NONE;
				}

				if(p_fmt->fmt.pix.width >= 1280)
				{
					p_fmt->fmt.pix.colorspace   = V4L2_COLORSPACE_REC709;
				}
				else
				{
					p_fmt->fmt.pix.colorspace   = V4L2_COLORSPACE_SMPTE170M;
				}

				p_fmt->fmt.pix.bytesperline = (p_fmt->fmt.pix.width );

				p_fmt->fmt.pix.sizeimage = (p_fmt->fmt.pix.bytesperline * p_fmt->fmt.pix.height * 12) >> 3;
			}

			p_fmt->fmt.pix.pixelformat = V4L2_PIX_FMT_H264;
		}
		#endif

		//one strange thing, if below are not 0, s_fmt_cap will not be issued
		#ifdef FFMPEG_V1_1_5
		p_fmt->fmt.pix.width = 0;
		p_fmt->fmt.pix.height = 0;
		#endif

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "g_fmt- %08X:%03dX%03d:%d:%d\n", p_fmt->fmt.pix.pixelformat, p_fmt->fmt.pix.width, p_fmt->fmt.pix.height, p_fmt->fmt.pix.bytesperline, p_fmt->fmt.pix.sizeimage );


		return 0;
	}
    return -EINVAL;
}
static int common_video_device_vidioc_querymenu( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_querymenu *a)
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_querymenu() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_querymenu() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	ULONG i = 0;

	ULONG j = 0;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_querymenu( %08X )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), a->id );

}


static int FE378301A538E42ca99A12D118AA57A57( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_queryctrl * p_queryctrl )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FE378301A538E42ca99A12D118AA57A57() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FE378301A538E42ca99A12D118AA57A57() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	ULONG i = 0;

	ULONG j = 0;

//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FE378301A538E42ca99A12D118AA57A57( %08X )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_queryctrl->id );

	#ifndef AME_PL330A
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ) { j =  0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802) ) { j =  1; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ) { j =  2; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805) ) { j =  3; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ) { j =  4; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ) { j =  5; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ) { j =  6; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) { j =  7; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814) ) { j =  8; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815) ) { j =  9; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816) ) { j = 10; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817) ) { j = 11; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) { j = 12; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5851) ) { j = 13; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160) ) { j = 14; }

//	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x9413 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6010) ) { j = 15; }
//	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1999 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA04C) ) { j = 16; }

//peter [2011.06.29]
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1999 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA04C) ) { j = 15; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) { j = 16; }

	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) { j = 17; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ) { j = 18; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x3800) ) { j = 19; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) ) { j = 20; }
	#else
	 j = 20;
	#endif

	for( i = 0 ; i < ARRAY_SIZE(F7CCABE6CE7AF4796BF5AA27C4E82D0EE); i++ ) {

		if( p_queryctrl->id == F7CCABE6CE7AF4796BF5AA27C4E82D0EE[ i ].id ) {

			if( F6965D2100E0840159702EF5670FD1E02[ j ][ i + 2 ] == 1 ) {

				memcpy( p_queryctrl, &(F7CCABE6CE7AF4796BF5AA27C4E82D0EE[ i ]), sizeof(struct v4l2_queryctrl) );

				p_queryctrl->default_value = FB8FF609F538541e69F50B4A5C3F035DA[ j ][ i + 2 ];

				return 0;
			}
		}
	}
    return -EINVAL;
}

static int F84B3BF483AB54d12922BBF693119ED0A( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_control * p_control )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F84B3BF483AB54d12922BBF693119ED0A() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F84B3BF483AB54d12922BBF693119ED0A() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	ULONG i = 0;

	ULONG j = 0;

//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F84B3BF483AB54d12922BBF693119ED0A( %08X )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_control->id - V4L2_CID_BASE );

	#ifndef AME_PL330A
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 8 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5851) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 8 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1999 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA04C) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }

	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5851) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1999 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA04C) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893 % 4; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) ) { j = 0; }
	#else
	i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0;
	j = 0;
	#endif

	if( p_control->id == V4L2_CID_BRIGHTNESS ) { //0

		p_control->value = FADD02C9C13B14f83989880EFACB8D8DC[ i ][ j ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == V4L2_CID_CONTRAST ) { //1

		p_control->value = F3A66BD0F0BCB4afcAD006E378E671B9A[ i ][ j ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == V4L2_CID_SATURATION ) { //2

		p_control->value = F925442591E22492f9239C6028CE3DD94[ i ][ j ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == V4L2_CID_HUE ) { //3

		p_control->value = F42BAA55A84E847faA4D0C0565699845E[ i ][ j ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == V4L2_CID_SHARPNESS ) { //27

		p_control->value = F1D56E1ED762E4b99BB2BD370DFE317D1[ i ][ j ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == V4L2_CID_AUTOGAIN ) { //18

		p_control->value = FF41F97A51B484aaa8170BEE8828CFCF0[ i ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == V4L2_CID_GAIN ) { //19

		p_control->value = F9CA17C2FDE5B4c94B2594B65842E7387[ i ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == F4E4758ED106F4fbcBC46709DCC7A3FEB ) { //200

		p_control->value = pVideo->F3F00596420D64210BB4DDAF0945F5388 & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == F0A6769CE1DE64a25A308D9585D0949DE ) { //201

		p_control->value = 0x00000000;

		for( i = 0 ; i < 12 ; i++ ) {

			p_control->value |= (ULONG)(pVideo->F59B6B40F8D70445eB5D4ACA63BE8A26E[ i ] & 0x03) << (i * 2);
		}
		return 0;
	}

	if( p_control->id == F82EB10A02CBD4cc081D849D39629049B ) { //250

		p_control->value = F5DCAF3AAB0BA4f659145B0B8C7EB74F6[ i ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == F23AEF06C35E84e268F8348DE745D6E9D ) { //251
		
		p_control->value = FB5061B6847674d5cAA4512F2524B22CA[ i ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == F00654B9494C14259AB67D0B82BB2B4F4 ) { //252
		
		p_control->value = FB4585649D2BE488f8DAB3BE4ACEC1C0C[ i ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == FA15402C642F34d2cAC2720CC357D2D38 ) { //253

		p_control->value = F24FF8C85BBB142d68BD24A8AEE14C2A0[ i ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == FB399C846A91D403eA55BF95B2B5BAA5C ) { //254

		p_control->value = F9245F416BCD64da6857AA7F60AC69BDC[ i ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == FFD08F80E390E49fcB67A2308CB62684C ) { //260

		p_control->value = FCF4231953179448dA85C9CE2854BDAB0[ i ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == FABAFB2ADBCD8465eA4F4B681511D1E3E ) { //261

		p_control->value = FAB3E37A5903246ce815D399EE1B19200[ i ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == F0B76EDE3B1154d53872CEEDCE52A97DC ) { //262

		p_control->value = F9C0567FC340549ddAF206705D1028554[ i ] & 0x7FFFFFFF;

		return 0;
	}
	if( p_control->id == V4L2_CID_GPIO_DIRECTION ) { //270

		#ifndef AME_PL330A
		if(	(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) {

			g_n_gpio_direction[ i ] = (BYTE)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomGpioDirectionProperty & 0xFF); 
		}


		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ) {

			g_n_gpio_direction[ i ] = TW6802_GetRegister( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00000028, 4 );
		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) {

			ULONG R00110018 = 0x00000000;

			ULONG R0011001C = 0x00000000;

			R00110018 = FD6B0AA2D8C0D4a6a9DED7BCD2255FA85( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00110018, 4 ); R00110018 = ~R00110018; R00110018 &= 0xFFFFFF00; 

//			R0011001C = FD6B0AA2D8C0D4a6a9DED7BCD2255FA85( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x0011001C, 4 ); R0011001C = ~R0011001C; R0011001C &= 0x000000FF; 

//			g_n_gpio_direction[ i ] = (R00110018 >> 8) | (R0011001C << 24);
			g_n_gpio_direction[ i ] = (R00110018 >> 8);
		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) {
//note: dir can not be read, chip feature

//			p_control->value = g_n_gpio_direction[ pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE ];

			TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);

			p_control->value = (p_sys_cfg->R00009801 >> 12) & 0xF;
	
			return 0;
		}
		#endif

		//
		p_control->value = g_n_gpio_direction[ i ];

		return 0;
	}
	if( p_control->id == V4L2_CID_GPIO_DATA ) { //271
	
		#ifndef AME_PL330A
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) {
/*
			TW6802_CLOSE_THREAD();

			BYTE R = (BYTE)(pDevice->m_nCustomGpioDirectionProperty & 0xFF); 

			R = ~R; // INPUT PIN IS ALWAYS HIGH

			R |= (BYTE)(pDevice->m_nCustomGpioDataProperty & 0xFF);

			F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x40, 125 ); F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, R, 125 ); F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 );

			F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x41, 125 ); R = F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 1, 125 ); F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 );

			R &= ~((BYTE)(pDevice->m_nCustomGpioDirectionProperty & 0xFF));

			R |= (BYTE)((pDevice->m_nCustomGpioDataProperty & pDevice->m_nCustomGpioDirectionProperty) & 0xFF);

			pDevice->m_nCustomGpioDataProperty = R;

			F6B9E557A4BA24ffd926B820B836289C8_100NS( 1250000 );

			TW6802_START_THREAD();
*/

			BYTE R = (BYTE)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomGpioDirectionProperty & 0xFF); 

			R = ~R; // INPUT PIN IS ALWAYS HIGH

			R |= (BYTE)g_n_gpio_data[ i ];
			
			R = TW6816_GET_GPIO_DATA( pVideo->FB6E79A0780E64bb28A3308666E67881C, R );

			R &= ~((BYTE)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomGpioDirectionProperty & 0xFF));

			R |= (BYTE) ( (g_n_gpio_data[ i ] & pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomGpioDirectionProperty) & 0xFF);

			g_n_gpio_data[ i ] = R;

		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ) {

			g_n_gpio_data[ i ] = TW6802_GetRegister( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00000100, 4 );
		
		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) {

			ULONG R00110010 = 0x00000000;

			ULONG R00110014 = 0x00000000;

//			R00110010 = FD6B0AA2D8C0D4a6a9DED7BCD2255FA85( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00110010, 4 ); R00110010 &= 0xFFFFFF00; 
			R00110010 = FD6B0AA2D8C0D4a6a9DED7BCD2255FA85( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00110010, 4 ); R00110010 &= 0x0000FF00; 
			
//			R00110014 = FD6B0AA2D8C0D4a6a9DED7BCD2255FA85( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00110014, 4 ); R00110014 &= 0x000000FF; 
			
//			g_n_gpio_data[ i ] = (R00110010 >> 8) | (R00110014 << 24);
			g_n_gpio_data[ i ] = (R00110010 >> 8);
		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) {

/*
			ULONG R00009800 = 0x00000000;

			f74f60e6b0814257af133a93b451d6b1_EX( pVideo->FB6E79A0780E64bb28A3308666E67881C );

			R00009800 = c3c09a67df944bec9b42209724048dc4( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00009800 );	R00009800 &= 0x000000F0;

			a0c563aa017e45aa898479fcd6f672e2_EX( pVideo->FB6E79A0780E64bb28A3308666E67881C );

			g_n_gpio_data[ i ] = R00009800 >> 4;
*/
			ULONG R00009800 = c3c09a67df944bec9b42209724048dc4( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x9800 ) & 0x00F0;

			g_n_gpio_data[ i ] = ( R00009800 >> 4 ) & 0xF;

		}


		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) 
		{
			AD96690602C7413AAC57A6B84A1747FEEX( pVideo->FB6E79A0780E64bb28A3308666E67881C );

			{	ULONG R = g_n_gpio_direction[ i ] & 0xFFFF;
			
				R = ~R; // INPUT PIN IS ALWAYS HIGH

				R |= g_n_gpio_data[ i ] & 0xFFFF;

				bde2191b41de49a5bdd64acc79f9ea2c( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00, 0x40, (BYTE)(R >> 0) );

				bde2191b41de49a5bdd64acc79f9ea2c( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00, 0x42, (BYTE)(R >> 8) );
			}
			USHORT R40 = (USHORT)(f385217a66354b98bbcf13b193cb54d6( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00, 0x40 ));

			USHORT R42 = (USHORT)(f385217a66354b98bbcf13b193cb54d6( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00, 0x42 ));

			USHORT R = (R42 << 8) | (R40 << 0); 

			R &= ~(USHORT)(g_n_gpio_direction[ i ] & 0xFFFF);

			R |=  (USHORT)((g_n_gpio_data[ i ] & g_n_gpio_direction[ i ]) & 0xFFFF);

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F84B3BF483AB54d12922BBF693119ED0A() data R( %08X ) \n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), R );

			g_n_gpio_data[ i ] = R;

			//F6B9E557A4BA24ffd926B820B836289C8_100NS( 1250000 );

			EBE5DCE0DB554397A79605FEA343FE27EX( pVideo->FB6E79A0780E64bb28A3308666E67881C );
		}
		#endif
		//
		p_control->value = g_n_gpio_data[ i ];

		return 0;
	}
	#ifndef AME_PL330A
	if( p_control->id == V4L2_CID_TW5864_MOTION_STATUS_00 ) { //280

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) )
		{
			p_control->value = (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionStatusProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ 0 ]) & 0xFFFFFFFF;
		}

		return 0;

	}
	if( p_control->id == V4L2_CID_TW5864_MOTION_STATUS_01 ) { //281

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) )
		{

			p_control->value = (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionStatusProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ 1 ]) & 0xFFFFFFFF;
		}

		return 0;

	}
	if( p_control->id == V4L2_CID_TW5864_MOTION_STATUS_02 ) { //282

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) )
		{

			p_control->value = (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionStatusProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ 2 ]) & 0xFFFFFFFF;
		}

		return 0;

	}
	if( p_control->id == V4L2_CID_TW5864_MOTION_STATUS_03 ) { //283

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) )
		{

			p_control->value = (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionStatusProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ 3 ]) & 0xFFFFFFFF;
		}

		return 0;

	}
	if( p_control->id == V4L2_CID_TW5864_MOTION_STATUS_04 ) { //284

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) )
		{

			p_control->value = (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionStatusProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ 4 ]) & 0xFFFFFFFF;
		}

		return 0;

	}
	if( p_control->id == V4L2_CID_TW5864_MOTION_STATUS_05 ) { //285

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) )
		{

			p_control->value = (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionStatusProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ 5 ]) & 0xFFFFFFFF;
		}

		return 0;

	}
	if( p_control->id == V4L2_CID_TW5864_MOTION_STATUS_06 ) { //286

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) )
		{

			p_control->value = (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionStatusProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ 6 ]) & 0xFFFFFFFF;
		}

		return 0;

	}
	if( p_control->id == V4L2_CID_TW5864_MOTION_STATUS_07 ) { //287

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) )
		{

			p_control->value = (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionStatusProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ 7 ]) & 0xFFFFFFFF;
		}

		return 0;

	}
	if( p_control->id == V4L2_CID_TW5864_MOTION_TEMPORAL_SENSITIVITY ) { //290

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 )
		{

			p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionTemporalSensitivityProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] & 0x77FFFFFF;;

		}
		return 0;
	}

	if( p_control->id == V4L2_CID_TW5864_MOTION_SPATIAL_SENSITIVITY ) { //291

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 )
		{

			p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionSpatialSensitivityProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] & 0x77FFFFFF;;

		}
		return 0;
	}

	if( p_control->id == V4L2_CID_TW5864_MOTION_LEVEL_SENSITIVITY ) { //292

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 )
		{

			p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionLevelSensitivityProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] & 0x77FFFFFF;;

		}
		return 0;
	}

	if( p_control->id == V4L2_CID_TW5864_MOTION_SPEED ) { //293

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 )
		{

			p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionSpeedProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] & 0x77FFFFFF;;

		}
		return 0;
	}
	#endif

	if( p_control->id == V4L2_CID_FRAME_RATE ) { //208

		p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoFrameRateProperty & 0x77FFFFFF;;

		#ifndef AME_PL330A
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ];
		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||
			
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||

			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
		{
			if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001)//for preview
			{
				p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ];
			}
		}

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 )
		{
			p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ];
		}
		#else
			p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ];
		#endif

		return 0;
	}

	if( p_control->id == V4L2_CID_WATCH_DOG ) { //207

		p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomSoftwareWatchdogResetProperty & 0x77FFFFFF;

		return 0;
	}

	if( p_control->id == V4L2_CID_X_RES_DETECTED ) { //294

		p_control->value = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty >> 16 ) & 0xFFFF;
		
		return 0;
	}

	if( p_control->id == V4L2_CID_Y_RES_DETECTED ) { //295

		p_control->value = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoResolutionProperty ) & 0xFFFF;

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoInterleavedProperty == 1 )
		{
			p_control->value *= 2;
		}

		return 0;
	}

	if( p_control->id == V4L2_CID_FPS_DETECTED ) { //296

		p_control->value = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoFrameRateProperty ) & 0xFFFF;
		
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoInterleavedProperty == 1 )
		{
			p_control->value /= 2;
		}
		return 0;
	}

	if( p_control->id == V4L2_CID_HDCP_ENABLE ) { //202

		#ifndef AME_PL330A
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCopyProtMacrovisionEnableProperty & 0x1;
		}
		#endif
		return 0;
	}

	if( p_control->id == V4L2_CID_HDCP_STATUS ) { //203

		//if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCopyProtMacrovisionProperty & 0x1;
		}
		return 0;
	}

	if( p_control->id == V4L2_CID_AUDIO_SAMPLING_FREQ ) { //211

/*
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			SA7160_SYS_CFG * p_sys_cfg = (SA7160_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);

			p_control->value = p_sys_cfg->n_input_audio_sampling_frequency;
		}
*/
		p_control->value = ( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogAudioSampleFrequencyProperty ) & 0xFFFF;

		return 0;
	}

	if( p_control->id == V4L2_CID_SPECIAL_CAMERA ) { //214
		
		p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomSpecialCameraInputProperty;

		return 0;
	}

	if( p_control->id == V4L2_CID_NO_SIGNAL_YUV_PATTERN ) { //216
		
		p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_No_Signal_yuv_pattern_property;

		return 0;
	}

	if( p_control->id == V4L2_CID_HV_SCALE_FACTOR ) { //204

		#ifndef AME_PL330A
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
		{
			p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nHVScaleFactor;
		}
		#endif
		return 0;
	}

	if( p_control->id == V4L2_CID_H264_HV_SCALE_FACTOR ) { //205

		#ifndef AME_PL330A
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
		{
			p_control->value = (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nH264HVScaleFactor) & 0x77FFFFFF;
		}
		#endif
		return 0;
	}

	if( p_control->id == V4L2_CID_INTERLEAVE_DETECTED ) { //297

		//if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
		{
			p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoInterleavedProperty;
		}
		return 0;
	}

	if( p_control->id == V4L2_CID_ENC_DEINTERLACE ) { //298

		#ifndef AME_PL330A
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
		{
			p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoDeinterlaceTypeProperty[ 0 ]; 
		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
		{
			p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoDeinterlaceTypeProperty[ 0 ]; 
		}
		#endif

		return 0;
	}
	if( p_control->id == V4L2_CID_VBI_ENABLE ) { //300

		p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoVbiLinesEnableProperty;

		return 0;
	}

	if( p_control->id == V4L2_CID_VBI_LINE ) { //301

		p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoVbiLinesProperty;

		return 0;
	}

	if( p_control->id == V4L2_CID_HANC_TIMECODE_H_M ) { //303

		p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_GENNUM_INFO.m_HOURS << 16 | pVideo->FB6E79A0780E64bb28A3308666E67881C->m_GENNUM_INFO.m_MINUTES;

		return 0;
	}

	if( p_control->id == V4L2_CID_HANC_TIMECODE_S_F ) { //304

		p_control->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_GENNUM_INFO.m_SECONDS << 16 | pVideo->FB6E79A0780E64bb28A3308666E67881C->m_GENNUM_INFO.m_FRAMES;

		return 0;
	}

	if( p_control->id == V4L2_CID_ACCESS_I2C_REGISTER ) { //306

#ifdef AME_MZ0380
		ADD5FE824A3C48E6B58F402E38497D21( pVideo->FB6E79A0780E64bb28A3308666E67881C );

		p_control->value = E6FB1249C1F642A38BC0228741149CD8( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0, 0x50, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "V4L2_CID_ACCESS_I2C_REGISTER get register(0x%x) value(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, p_control->value );

		B61F92BFB9094377AA7CFF54EC29E79D( pVideo->FB6E79A0780E64bb28A3308666E67881C );

#endif

#ifdef AME_PL330B
		E0DDF28968D942EAB74C3DD59AD1E41BEX( pVideo->FB6E79A0780E64bb28A3308666E67881C );

		//p_control->value = F7B4503FC4AA4710AEC20FC4C587ACB8( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0, 0x94, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register );
		
		//p_control->value = C12B7BD9B5134F53981EE3E7702A7E44( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0, 0x66, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register );

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_chipaddr == 0x88 )//TW9910
		{
			p_control->value = (BYTE)(DD0D84BB34264335874009D864B98B9C( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0, 0x88, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register ));
		}

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "V4L2_CID_ACCESS_I2C_REGISTER get chipaddr(0x%x) register(0x%x) value(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_chipaddr, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, p_control->value );

		C46ED33BB5514DE9B78DCDFF16BAC52EEX( pVideo->FB6E79A0780E64bb28A3308666E67881C );

#endif

#ifdef AME_SA7160

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			B6B487882F964675B66617C7847B8BB5EX( pVideo->FB6E79A0780E64bb28A3308666E67881C );

			BYTE value = 0x00;
			/*
			if( SA7160_GetADV7619Register( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x68, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, &value ) == TRUE )
			{
				p_control->value = value;
			}
			*/
			p_control->value = E9FDD7B155AA445A84F2F4493591369B( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register );

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "V4L2_CID_ACCESS_I2C_REGISTER get register(0x%x) value(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, p_control->value );

			F5D69F1955AA4EBCAF770CF98A9B4992EX( pVideo->FB6E79A0780E64bb28A3308666E67881C );
		}
		else //TW6805
		{
			p_control->value = (BYTE)(TW6802_GetRegister( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, 1 ));

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "V4L2_CID_ACCESS_I2C_REGISTER get register(0x%x) value(0x%x)--\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, p_control->value );
		}

#endif
		return 0;
	}

	return -EINVAL;
}

static int FE2A7B4A8EE7849ceA91671F8DE876A7F( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_control * p_control )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FE2A7B4A8EE7849ceA91671F8DE876A7F() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FE2A7B4A8EE7849ceA91671F8DE876A7F() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	ULONG i = 0;

	ULONG j = 0;

//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FE2A7B4A8EE7849ceA91671F8DE876A7F( %08X )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_control->id - V4L2_CID_BASE );
	
	#ifndef AME_PL330A
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 8 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5851) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 8 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1999 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA04C) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) ) { i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0; }

	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817) ) { j = pVideo->F0DD7393CD1494e27A72652C7D1A97893; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5851) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1999 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA04C) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) { j = (pVideo->F0DD7393CD1494e27A72652C7D1A97893) % 4; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) ) { j = 0; }
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) ) { j = 0; }
	#else
	i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 0;
	j = 0;
	#endif

	#ifndef AME_PL330A

	if( p_control->id == V4L2_CID_BRIGHTNESS ) { //0

		if(p_control->value < 1 || p_control->value > 255) return 0;

		FADD02C9C13B14f83989880EFACB8D8DC[ i ][ j ] = p_control->value | 0x80000000;

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) { F2DA00EC43E5A44df82C0A06D7C6465D3( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo ); } // [2010.06.02] [HUENGPEI]
//peter [2011.07.11]
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) { c08e773e16fb4ac7a4a5ed488cd4b12c( pVideo->FB6E79A0780E64bb28A3308666E67881C, (0x0000000A + ((pVideo->F0DD7393CD1494e27A72652C7D1A97893) % 4) * 0x10) << (2), (FADD02C9C13B14f83989880EFACB8D8DC[ i ][ j ] & 0xFF) -128 ); } // BRIGHTNESS 

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 ) { AE7C8644E545419889F245065E2144A7( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 ) { B12F437EF90146B0802BBBAD0AA3AD24( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }
		
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) {

			F05281060197A4ade8E66A1B73DEBA15B( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, pVideo->F0DD7393CD1494e27A72652C7D1A97893 );
		}

		
		return 0;
	}
	if( p_control->id == V4L2_CID_CONTRAST ) { //1

		if(p_control->value < 1 || p_control->value > 255) return 0;

		F3A66BD0F0BCB4afcAD006E378E671B9A[ i ][ j ] = p_control->value | 0x80000000;

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) { F2DA00EC43E5A44df82C0A06D7C6465D3( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo ); } // [2010.06.02] [HUENGPEI]
//peter [2011.07.11]
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) { c08e773e16fb4ac7a4a5ed488cd4b12c( pVideo->FB6E79A0780E64bb28A3308666E67881C, (0x00000009 + ((pVideo->F0DD7393CD1494e27A72652C7D1A97893) % 4) * 0x10) << (2), F3A66BD0F0BCB4afcAD006E378E671B9A[ i ][ j ] & 0xFF ); }  

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 ) { AE7C8644E545419889F245065E2144A7( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 ) { B12F437EF90146B0802BBBAD0AA3AD24( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) {

			F05281060197A4ade8E66A1B73DEBA15B( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, pVideo->F0DD7393CD1494e27A72652C7D1A97893 );
		}
		return 0;
	}
	if( p_control->id == V4L2_CID_SATURATION ) { //2

		if(p_control->value < 1 || p_control->value > 255) return 0;

		F925442591E22492f9239C6028CE3DD94[ i ][ j ] = p_control->value | 0x80000000;

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) { F2DA00EC43E5A44df82C0A06D7C6465D3( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo ); } // [2010.06.02] [HUENGPEI]
//peter [2011.07.11]
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) { c08e773e16fb4ac7a4a5ed488cd4b12c( pVideo->FB6E79A0780E64bb28A3308666E67881C, (0x0000000B + ((pVideo->F0DD7393CD1494e27A72652C7D1A97893) % 4) * 0x10) << (2), F925442591E22492f9239C6028CE3DD94[ i ][ j ] & 0xFF ); }  
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) { c08e773e16fb4ac7a4a5ed488cd4b12c( pVideo->FB6E79A0780E64bb28A3308666E67881C, (0x0000000C + ((pVideo->F0DD7393CD1494e27A72652C7D1A97893) % 4) * 0x10) << (2), F925442591E22492f9239C6028CE3DD94[ i ][ j ] & 0xFF ); }  

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 ) { AE7C8644E545419889F245065E2144A7( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 ) { B12F437EF90146B0802BBBAD0AA3AD24( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) {

			F05281060197A4ade8E66A1B73DEBA15B( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, pVideo->F0DD7393CD1494e27A72652C7D1A97893 );
		}
		return 0;
	}
	if( p_control->id == V4L2_CID_HUE ) { //3

		if(p_control->value < 1 || p_control->value > 255) return 0;

		F42BAA55A84E847faA4D0C0565699845E[ i ][ j ] = p_control->value | 0x80000000;

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) { F2DA00EC43E5A44df82C0A06D7C6465D3( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo ); } // [2010.06.02] [HUENGPEI]
//peter [2011.07.11]
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) { c08e773e16fb4ac7a4a5ed488cd4b12c( pVideo->FB6E79A0780E64bb28A3308666E67881C, (0x00000007 + ((pVideo->F0DD7393CD1494e27A72652C7D1A97893) % 4) * 0x10)  << (2), (F42BAA55A84E847faA4D0C0565699845E[ i ][ j ] & 0xFF) -128 ); }  

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 ) { AE7C8644E545419889F245065E2144A7( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 ) { B12F437EF90146B0802BBBAD0AA3AD24( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) {

			F05281060197A4ade8E66A1B73DEBA15B( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, pVideo->F0DD7393CD1494e27A72652C7D1A97893 );
		}
		return 0;
	}
	if( p_control->id == V4L2_CID_SHARPNESS ) { //27

		if(p_control->value < 1 || p_control->value > 255) return 0;

		F1D56E1ED762E4b99BB2BD370DFE317D1[ i ][ j ] = p_control->value | 0x80000000;

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) { F2DA00EC43E5A44df82C0A06D7C6465D3( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo ); } // [2010.06.02] [HUENGPEI]
//peter [2011.07.11]
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) { c08e773e16fb4ac7a4a5ed488cd4b12c( pVideo->FB6E79A0780E64bb28A3308666E67881C, (0x00000008 + ((pVideo->F0DD7393CD1494e27A72652C7D1A97893) % 4) * 0x10) << (2), ((F1D56E1ED762E4b99BB2BD370DFE317D1[ i ][ j ] & 0xFF) >> 4) | 0x10 ); }  

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 ) { AE7C8644E545419889F245065E2144A7( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 ) { B12F437EF90146B0802BBBAD0AA3AD24( pVideo->FB6E79A0780E64bb28A3308666E67881C ); }

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) {

			F05281060197A4ade8E66A1B73DEBA15B( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, pVideo->F0DD7393CD1494e27A72652C7D1A97893 );
		}
		return 0;
	}
	#endif

	if( p_control->id == V4L2_CID_AUTOGAIN ) { //18

		if(p_control->value < 1 || p_control->value > 255) return 0;

		FF41F97A51B484aaa8170BEE8828CFCF0[ i ] = p_control->value | 0x80000000;

		return 0;
	}
	if( p_control->id == V4L2_CID_GAIN ) { //19

		if(p_control->value < 1 || p_control->value > 255) return 0;

		F9CA17C2FDE5B4c94B2594B65842E7387[ i ] = p_control->value | 0x80000000;

		return 0;
	}
	if( p_control->id == F4E4758ED106F4fbcBC46709DCC7A3FEB ) { //200

		pVideo->F3F00596420D64210BB4DDAF0945F5388 = p_control->value;

		pVideo->FE9AF51EBD0D4401eA4E5E0F6868A9A53 = 3;

		return 0;
	}
	if( p_control->id == F0A6769CE1DE64a25A308D9585D0949DE ) { //201

		BYTE F675786930896474f9DA4061E2FD16EC5[ 13 ] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };

		for( i = 0 ; i < 12 ; i++ ) {

			F675786930896474f9DA4061E2FD16EC5[ i ] = (BYTE)(((p_control->value) >> (i * 2)) & 0x00000003);

			if( F675786930896474f9DA4061E2FD16EC5[ i ] == 0x00 ) { F675786930896474f9DA4061E2FD16EC5[ 12 ] |= 0x01; }

			if( F675786930896474f9DA4061E2FD16EC5[ i ] == 0x01 ) { F675786930896474f9DA4061E2FD16EC5[ 12 ] |= 0x02; }

			if( F675786930896474f9DA4061E2FD16EC5[ i ] == 0x02 ) { F675786930896474f9DA4061E2FD16EC5[ 12 ] |= 0x04; }

			if( F675786930896474f9DA4061E2FD16EC5[ i ] == 0x03 ) { F675786930896474f9DA4061E2FD16EC5[ 12 ] |= 0x08; }
		}
		memcpy( pVideo->F59B6B40F8D70445eB5D4ACA63BE8A26E, F675786930896474f9DA4061E2FD16EC5, 12 );

		pVideo->FA7E81415668A414bB9DED82DB85E4B48 = F675786930896474f9DA4061E2FD16EC5[ 12 ];

		pVideo->FE9AF51EBD0D4401eA4E5E0F6868A9A53 = 3;

		return 0;
	}
	if( p_control->id == F23AEF06C35E84e268F8348DE745D6E9D ) { //251

		FB5061B6847674d5cAA4512F2524B22CA[ i ] = p_control->value | 0x80000000;

		return 0;
	}
	if( p_control->id == F00654B9494C14259AB67D0B82BB2B4F4 ) { //252

		FB4585649D2BE488f8DAB3BE4ACEC1C0C[ i ] = p_control->value | 0x80000000;

		return 0;
	}
	if( p_control->id == FA15402C642F34d2cAC2720CC357D2D38 ) { //253

		F24FF8C85BBB142d68BD24A8AEE14C2A0[ i ] = p_control->value | 0x80000000;

		return 0;
	}
	if( p_control->id == FB399C846A91D403eA55BF95B2B5BAA5C ) { //254

		F9245F416BCD64da6857AA7F60AC69BDC[ i ] = p_control->value | 0x80000000;

		return 0;
	}
	if( p_control->id == FFD08F80E390E49fcB67A2308CB62684C ) { //260

		FCF4231953179448dA85C9CE2854BDAB0[ i ] = p_control->value | 0x80000000;

		return 0;
	}
	if( p_control->id == FABAFB2ADBCD8465eA4F4B681511D1E3E ) { //261

		FAB3E37A5903246ce815D399EE1B19200[ i ] = p_control->value | 0x80000000;

		return 0;
	}
	if( p_control->id == F0B76EDE3B1154d53872CEEDCE52A97DC ) { //262

		F9C0567FC340549ddAF206705D1028554[ i ] = p_control->value | 0x80000000;

		return 0;
	}

	#ifndef AME_PL330A

	if( p_control->id == V4L2_CID_GPIO_DIRECTION ) { //270

		g_n_gpio_direction[ i ] = p_control->value;

		if(	(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) {

			pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomGpioDirectionProperty = g_n_gpio_direction[ i ] & 0xFF;
		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ) {

			TW6802_SetRegister( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00000028, g_n_gpio_direction[ i ], 4 );

		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) {

			ULONG R00110018 = 0x00000000;

			ULONG R0011001C = 0x00000000;

//			R00110018 = FD6B0AA2D8C0D4a6a9DED7BCD2255FA85( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00110018, 4 ); R00110018 &= 0x000000FF; R00110018 |= (((~g_n_gpio_direction[ i ]) & 0x00FFFFFF) << ( 8));
			R00110018 = FD6B0AA2D8C0D4a6a9DED7BCD2255FA85( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00110018, 4 ); R00110018 &= 0x000000FF; R00110018 |= (((~g_n_gpio_direction[ i ]) & 0x000000FF) << ( 8));

			FF8FFEAB4276140da9857B707AAA77F43( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00110018, R00110018, 4 );

//			R0011001C = FD6B0AA2D8C0D4a6a9DED7BCD2255FA85( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x0011001C, 4 ); R0011001C &= 0xFFFFFF00; R0011001C |= (((~g_n_gpio_direction[ i ]) & 0xFF000000) >> (24));

//			FF8FFEAB4276140da9857B707AAA77F43( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x0011001C, R0011001C, 4 );
		}
		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) {
		
			//direction will not be remember by register
			
			g_n_gpio_direction[ pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE ] = (p_control->value) & 0xF;

			TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);

			p_sys_cfg->R00009801 &= 0x0F00;
				
			p_sys_cfg->R00009801 |=	((p_control->value & 0x0F) << 12) | 0x0F00;

			ULONG R00009800 = c3c09a67df944bec9b42209724048dc4( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x9800 ) & 0x00FF;

			R00009800 |= p_sys_cfg->R00009801;

			b13825e2dd0b4ba4a5c7741536f21277( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x9800, R00009800 );

		}

		//
		return 0;
	}
	if( p_control->id == V4L2_CID_GPIO_DATA ) { //271

		g_n_gpio_data[ i ] = p_control->value;

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) {
/*
			TW6802_CLOSE_THREAD();

			BYTE R = (BYTE)(pDevice->m_nCustomGpioDirectionProperty & 0xFF); 

			R = ~R; // INPUT PIN IS ALWAYS HIGH

			R |= (BYTE)(*pPropertyValue & 0xFF);

			F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x40, 125 ); F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, R, 125 ); F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 );

			F6B9E557A4BA24ffd926B820B836289C8_100NS( 1250000 );

			TW6802_START_THREAD();
*/

			BYTE R = (BYTE)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomGpioDirectionProperty & 0xFF); 

			R = ~R; // INPUT PIN IS ALWAYS HIGH

			R |= (BYTE)(g_n_gpio_data[ i ] & 0xFF);

			TW6816_SET_GPIO_DATA( pVideo->FB6E79A0780E64bb28A3308666E67881C, R );
		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) )
		{
			TW6802_SetRegister( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00000100, g_n_gpio_data[ i ], 4 );
		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) {

			ULONG R00110010 = 0x00000000;

			ULONG R00110014 = 0x00000000;

//			R00110010 = FD6B0AA2D8C0D4a6a9DED7BCD2255FA85( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00110010, 4 ); R00110010 &= 0x000000FF; R00110010 |= ((g_n_gpio_data[ i ] & 0x00FFFFFF) << ( 8));
			R00110010 = FD6B0AA2D8C0D4a6a9DED7BCD2255FA85( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00110010, 4 ); R00110010 &= 0x000000FF; R00110010 |= ((g_n_gpio_data[ i ] & 0x000000FF) << ( 8));

			FF8FFEAB4276140da9857B707AAA77F43( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00110010, R00110010, 4 );

//			R00110014 = FD6B0AA2D8C0D4a6a9DED7BCD2255FA85( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00110014, 4 ); R00110014 &= 0xFFFFFF00; R00110014 |= ((g_n_gpio_data[ i ] & 0xFF000000) >> (24));

//			FF8FFEAB4276140da9857B707AAA77F43( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00110014, R00110014, 4 );
		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) {
/*
			f74f60e6b0814257af133a93b451d6b1_EX( pVideo->FB6E79A0780E64bb28A3308666E67881C );
			
			ULONG R00009800 = 0x00000000;

			R00009800 = c3c09a67df944bec9b42209724048dc4( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00009800 );	

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FE2A7B4A8EE7849ceA91671F8DE876A7F() read R00009800( %08X )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), R00009800 );
			
			R00009800 &= 0xFFFFFF0F;

			R00009800 |= (g_n_gpio_data[ i ] & 0x0000000F) << 4;

			R00009800 |= g_n_gpio_direction[ pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE ] << 12;

			b13825e2dd0b4ba4a5c7741536f21277( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x9800, R00009800);

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FE2A7B4A8EE7849ceA91671F8DE876A7F() data R00009800( %08X )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), R00009800 );
			
			a0c563aa017e45aa898479fcd6f672e2_EX( pVideo->FB6E79A0780E64bb28A3308666E67881C );
*/
			g_n_gpio_data[ pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE ] = (p_control->value) & 0xF;
			
			TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);

			ULONG R00009800 = c3c09a67df944bec9b42209724048dc4( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x9800 ) & 0x000F;

			R00009800 |= p_sys_cfg->R00009801;

			R00009800 |= (p_control->value & 0x0F) << 4;

			b13825e2dd0b4ba4a5c7741536f21277( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x9800, R00009800 );

		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) 
		{
			AD96690602C7413AAC57A6B84A1747FEEX( pVideo->FB6E79A0780E64bb28A3308666E67881C );

			ULONG R = g_n_gpio_direction[ i ] & 0xFFFF;
			
			R = ~R; // INPUT PIN IS ALWAYS HIGH

			R |= g_n_gpio_data[ i ] & 0xFFFF;

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FE2A7B4A8EE7849ceA91671F8DE876A7F() data R( %08X ) direct\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), R );

			bde2191b41de49a5bdd64acc79f9ea2c( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00, 0x40, (BYTE)(R >> 0) );

			bde2191b41de49a5bdd64acc79f9ea2c( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00, 0x42, (BYTE)(R >> 8) );

			//F6B9E557A4BA24ffd926B820B836289C8_100NS( 1250000 );

			EBE5DCE0DB554397A79605FEA343FE27EX( pVideo->FB6E79A0780E64bb28A3308666E67881C );
		}
		//
		return 0;
	}

	if( p_control->id == V4L2_CID_PCM_UPDATE ) { //272

		ULONG i = 0;
	
//		for( i = 0; i < 16; i++ )
//		{
//			pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pcm_update[ i ] = p_control->value & 0x1;
//		
//			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, " m_pcm_update[%d] (%d)\n", i, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pcm_update[ i ] );
//		}

		return 0;
	}

	if( p_control->id == V4L2_CID_TW5864_MOTION_TEMPORAL_SENSITIVITY ) { //290

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 )
		{

				pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionTemporalSensitivityProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = (p_control->value) | 0x08000000;

		}
		return 0;
	}

	if( p_control->id == V4L2_CID_TW5864_MOTION_SPATIAL_SENSITIVITY ) { //291

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 )
		{

				pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionSpatialSensitivityProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = (p_control->value) | 0x08000000;

	}
		return 0;
	}

	if( p_control->id == V4L2_CID_TW5864_MOTION_LEVEL_SENSITIVITY ) { //292

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 )
		{

				pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionLevelSensitivityProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = (p_control->value) | 0x08000000;

		}
		return 0;
	}

	if( p_control->id == V4L2_CID_TW5864_MOTION_SPEED ) { //293

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 )
		{

				pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomMotionSpeedProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = (p_control->value) | 0x08000000;

		}
		return 0;
	}

	if( p_control->id == V4L2_CID_FRAME_RATE ) { //208

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) {

				pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoFrameRateProperty = (p_control->value) & 0xFF;

				OnSetCustomAnalogVideoFrameRateProperty( pVideo->FB6E79A0780E64bb28A3308666E67881C );
		}
		
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] = (p_control->value) & 0xFFFF;
		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||
			
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||

			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
		{
			if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001)//for preview
			{
				pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] = ((p_control->value & 0xFFFF) / 1000) | 0x88000000;
			}
		}

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 )
		{
			if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001)//for preview
			{
				pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] = ((p_control->value & 0xFFFF) / 1000) | 0x88000000;
			}
		}
		return 0;
	}
	#endif

	if( p_control->id == V4L2_CID_WATCH_DOG_PERIOD ) { //206

		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomSoftwareWatchdogResetProperty = 0x80000001;

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomSoftwareWatchdogDurationProperty) != ((p_control->value) & 0xFF) )
		{
			pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomSoftwareWatchdogDurationProperty = ((p_control->value) & 0xFF) | 0x80000000;
		}

		return 0;
	}

	if( p_control->id == V4L2_CID_WATCH_DOG ) { //207
		
		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomSoftwareWatchdogResetProperty = 0x80000001;

		return 0;
	}

	if( p_control->id == V4L2_CID_WATCH_DOG_ENABLE ) { //212
		
		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomSoftwareWatchdogEnableProperty = 0x80000001;

		return 0;
	}

	if( p_control->id == V4L2_CID_NO_SIGNAL_BLACK_PATTERN ) { //213
		
		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_No_Signal_black_pattern_property = 0x00000001;

		return 0;
	}

	if( p_control->id == V4L2_CID_SPECIAL_CAMERA ) { //214
		
		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomSpecialCameraInputProperty = 0x00000001;

		return 0;
	}

	if( p_control->id == V4L2_CID_NO_SIGNAL_NO_OUTPUT ) { //215
		
		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_No_Signal_no_output_property = 0x00000001;

		//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "m_No_Signal_no_output_property(0x%x)------\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->m_No_Signal_no_output_property );

		return 0;
	}

	if( p_control->id == V4L2_CID_NO_SIGNAL_YUV_PATTERN ) { //216
		
		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_No_Signal_yuv_pattern_property = (p_control->value) & 0xFFFFFF;

		return 0;
	}
	
	#ifndef AME_PL330A
	if( p_control->id == V4L2_CID_HDCP_ENABLE ) { //202

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCopyProtMacrovisionEnableProperty = (p_control->value) & 0xFF;
		}
		return 0;
	}

	if( p_control->id == V4L2_CID_HV_SCALE_FACTOR ) { //204

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
		{
			pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nHVScaleFactor = p_control->value & 0x000F000F; 
		}
		return 0;
	}

	if( p_control->id == V4L2_CID_H264_HV_SCALE_FACTOR ) { //205

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
		{
			pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nH264HVScaleFactor = (p_control->value & 0x03030303) | 0x88000000; 
		}
		return 0;
	}

	if( p_control->id == V4L2_CID_ENC_DEINTERLACE ) { //298

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
		{
			pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoDeinterlaceTypeProperty[ 0 ] = (p_control->value) | 0x88000000; 
		}

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			
			(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
		{
			pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoDeinterlaceTypeProperty[ 0 ] = (p_control->value) | 0x88000000; 
		}

		return 0;
	}

	if( p_control->id == V4L2_CID_RESET_I2S ) { //299

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
		{
			aafd0c9462784a14a89d8308fa9ca1cb( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x00000023, 0x00000000 );
		}
		return 0;
	}

	if( p_control->id == V4L2_CID_VBI_ENABLE ) { //300

		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoVbiLinesEnableProperty = (p_control->value ? TRUE : 0);

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] V4L2_CID_VBI_ENABLE(%d)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoVbiLinesEnableProperty );

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty == 4 )
			{
				SA7160_SYS_CFG * p_sys_cfg = (SA7160_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);

				p_sys_cfg->n_input_video_resolution_fps = 0;//reset fps to make reset m_nCustomAnalogVideoVbiLinesEnableProperty
			}
		}
		return 0;
	}

	if( p_control->id == V4L2_CID_VBI_LINE ) { //301

		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoVbiLinesProperty = p_control->value;

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] V4L2_CID_VBI_LINE(%d)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomAnalogVideoVbiLinesProperty );

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogCrossbarVideoInputProperty == 4 )
			{
				SA7160_SYS_CFG * p_sys_cfg = (SA7160_SYS_CFG *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomSystemConfigProperty);

				p_sys_cfg->n_input_video_resolution_fps = 0;//reset fps to make reset m_nCustomAnalogVideoVbiLinesProperty
			}
		}
		return 0;
	}

	if( p_control->id == V4L2_CID_HDMI_MIXER ) { //302

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomHDMI_Mixer = p_control->value | 0x88000000;
		}
		return 0;
	}
	#endif

	if( p_control->id == V4L2_CID_SET_I2C_REGISTER ) { //305

		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register = p_control->value;

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "V4L2_CID_SET_I2C_REGISTER set register(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register );

		return 0;
	}

	if( p_control->id == V4L2_CID_ACCESS_I2C_REGISTER ) { //306

#ifdef AME_MZ0380
		ADD5FE824A3C48E6B58F402E38497D21( pVideo->FB6E79A0780E64bb28A3308666E67881C );

		DBF051EEA3B648B49859145F02FA268C( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0, 0x50, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, (BYTE)p_control->value );
		
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "V4L2_CID_ACCESS_I2C_REGISTER set register(0x%x) value(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, p_control->value );

		B61F92BFB9094377AA7CFF54EC29E79D( pVideo->FB6E79A0780E64bb28A3308666E67881C );
#endif


#ifdef AME_PL330B
		E0DDF28968D942EAB74C3DD59AD1E41BEX( pVideo->FB6E79A0780E64bb28A3308666E67881C );

		//FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0, 0x94, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, (BYTE)p_control->value );
		//F163E0DBD4F44FD18730544917C904D1( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0, 0x66, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, p_control->value );

		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_chipaddr == 0x88 )
		{
			E057E022AA684160B92E903D99235927( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0, 0x88, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, p_control->value);
		}

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "V4L2_CID_ACCESS_I2C_REGISTER set chipaddr(0x%x) register(0x%x) value(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_chipaddr, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, p_control->value );

		C46ED33BB5514DE9B78DCDFF16BAC52EEX( pVideo->FB6E79A0780E64bb28A3308666E67881C );
#endif


#ifdef AME_SA7160
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
		{
			B6B487882F964675B66617C7847B8BB5EX( pVideo->FB6E79A0780E64bb28A3308666E67881C );

			//SA7160_SetADV7619Register( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0x68, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, (BYTE)p_control->value );

			DFD7C3CC812B44E2A9BDB8C9C6C4BC84( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, (BYTE)p_control->value );
		
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "V4L2_CID_ACCESS_I2C_REGISTER set register(0x%x) value(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, p_control->value );

			F5D69F1955AA4EBCAF770CF98A9B4992EX( pVideo->FB6E79A0780E64bb28A3308666E67881C );
		}
		else //TW6805
		{
			TW6802_SetRegister( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_register, (BYTE)p_control->value, 1 );
		}
#endif

		return 0;
	}

	if( p_control->id == V4L2_CID_SIZE_NOT_MATCH ) { //307

		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_size_not_match_no_signal_blue_pattern = p_control->value;

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "V4L2_CID_SIZE_NOT_MATCH m_size_not_match_no_signal_blue_pattern(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->m_size_not_match_no_signal_blue_pattern );

		return 0;
	}

	if( p_control->id == V4L2_CID_INVERT_UV ) { //308

		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_Invert_UV = p_control->value;

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "V4L2_CID_INVERT_UV m_Invert_UV(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->m_Invert_UV );

		return 0;
	}

	if( p_control->id == V4L2_CID_SET_I2C_CHIPADDR ) { //309

		pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_chipaddr = p_control->value;

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "V4L2_CID_SET_I2C_CHIPADDR set chipaddr(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->m_i2c_chipaddr );

		return 0;
	}

	return -EINVAL;
}

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,18)

static int F82E24F268CBB49ca9A83789D7475B068( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_ext_controls * F6537805ACA4443d5AA5A380BA0BC5276 )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F82E24F268CBB49ca9A83789D7475B068() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F82E24F268CBB49ca9A83789D7475B068() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	struct v4l2_ext_control * FDBE4DC4E08D348b98D2A9A10762FF9A2 = F6537805ACA4443d5AA5A380BA0BC5276->controls;

	int count = F6537805ACA4443d5AA5A380BA0BC5276->count;

	int size = sizeof(struct v4l2_ext_control);

	int i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1;
	
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F82E24F268CBB49ca9A83789D7475B068()\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,5,0)
	
	if( F6537805ACA4443d5AA5A380BA0BC5276->which == V4L2_CTRL_CLASS_MPEG ) {

	#else
	
	if( F6537805ACA4443d5AA5A380BA0BC5276->ctrl_class == V4L2_CTRL_CLASS_MPEG ) {
	
	#endif

		if( count > 6 ) return 0;

		while( count ) {

			switch( FDBE4DC4E08D348b98D2A9A10762FF9A2->id ) {

			case V4L2_CID_MPEG_VIDEO_BITRATE_MODE: FDBE4DC4E08D348b98D2A9A10762FF9A2->value = pVideo->F3D935AFB5C164dac97F5A7CA0150BC60; break;
			
			case V4L2_CID_MPEG_VIDEO_BITRATE:      FDBE4DC4E08D348b98D2A9A10762FF9A2->value = pVideo->F65C8BF3BAA2D4fbb876EE33F491F1931; break;
			
			case F50EB0715BAAC4d35AA3EE21A2F673819:      FDBE4DC4E08D348b98D2A9A10762FF9A2->value = pVideo->FF63087B4098B4de18859989009950824; break;
			
			case V4L2_CID_MPEG_VIDEO_GOP_SIZE:     FDBE4DC4E08D348b98D2A9A10762FF9A2->value = pVideo->F1CA927B5918D436c9F5839C9727D620E; break;
			
			case F59D7E164EA0643c987147244BD095662:    FDBE4DC4E08D348b98D2A9A10762FF9A2->value = pVideo->FB4E9A11D151C4d93B0C750EC1BE4C7C5; break;
			
			case FE8CF9C6EC12A48c79FEBD36B2EAD2642:       FDBE4DC4E08D348b98D2A9A10762FF9A2->value = pVideo->FD9E5DCB7C0F94c32AF5A086BA8C007EC; break;
			
			case V4L2_CID_MPEG_VIDEO_OSD_ENABLE:	FDBE4DC4E08D348b98D2A9A10762FF9A2->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_bCustomOsdTextEnableProperty;	break;

			#ifndef AME_PL330A
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,32)
			
			case V4L2_CID_MPEG_VIDEO_OSD:		   //memcpy( FDBE4DC4E08D348b98D2A9A10762FF9A2->string, FE2D83A80F4E94ef188507C175ABF3840[ i ], 32 ); break;

													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) )
													{
														if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x03) ||	(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x85) )
														{
															memcpy( FDBE4DC4E08D348b98D2A9A10762FF9A2->string, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ (pVideo->F0DD7393CD1494e27A72652C7D1A97893 % 4)  ][ 0 ], 64 );

														}
														else if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) || (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x07) )
														{
															memcpy( FDBE4DC4E08D348b98D2A9A10762FF9A2->string, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ 0 ][ 0 ], 64 );
														}
														else
														{
															memcpy( FDBE4DC4E08D348b98D2A9A10762FF9A2->string, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ (pVideo->F0DD7393CD1494e27A72652C7D1A97893 % 4)  ][ 0 ], 64 );
														}

													}
													else if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

															(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||

															(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )

													{
														memcpy( FDBE4DC4E08D348b98D2A9A10762FF9A2->string, (CHAR *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ 0 ]), 64 );
													}
													else
													{
														memcpy( FDBE4DC4E08D348b98D2A9A10762FF9A2->string, FE2D83A80F4E94ef188507C175ABF3840[ i ], 32 );
													}
													break;

			#else
			
			case V4L2_CID_MPEG_VIDEO_OSD:		   //memcpy( FDBE4DC4E08D348b98D2A9A10762FF9A2->reserved, FE2D83A80F4E94ef188507C175ABF3840[ i ], 32 ); break;

													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) )
													{
														if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x03) ||	(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x85) )
														{
															memcpy( FDBE4DC4E08D348b98D2A9A10762FF9A2->reserved, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ (pVideo->F0DD7393CD1494e27A72652C7D1A97893 % 4)  ][ 0 ], 64 );

														}
														else if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) || (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x07) )
														{
															memcpy( FDBE4DC4E08D348b98D2A9A10762FF9A2->reserved, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ 0 ][ 0 ], 64 );
														}
														else
														{
															memcpy( FDBE4DC4E08D348b98D2A9A10762FF9A2->reserved, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ (pVideo->F0DD7393CD1494e27A72652C7D1A97893 % 4)  ][ 0 ], 64 );
														}

													}
													else if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

															(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			
															(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )

													{
														memcpy( FDBE4DC4E08D348b98D2A9A10762FF9A2->reserved, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ 0 ], 64 );
													}
													else
													{
														memcpy( FDBE4DC4E08D348b98D2A9A10762FF9A2->reserved, FE2D83A80F4E94ef188507C175ABF3840[ i ], 32 );
													}
													break;


			#endif
			#endif

			case V4L2_CID_MPEG_VIDEO_H264_PROFILE:	FDBE4DC4E08D348b98D2A9A10762FF9A2->value = (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoProfileProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ]) & 0xFF;	break;

			case V4L2_CID_MPEG_VIDEO_H264_LEVEL:	FDBE4DC4E08D348b98D2A9A10762FF9A2->value = (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustom_H264_Level_Property) & 0xFF;	break;

			case V4L2_CID_MPEG_VIDEO_ASPECT:		FDBE4DC4E08D348b98D2A9A10762FF9A2->value = (pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoAspectRatioProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ]) & 0x77FFFFFF; break;

			case V4L2_CID_MPEG_SET_SLICE:			FDBE4DC4E08D348b98D2A9A10762FF9A2->value = pVideo->m_nCustomEncoderSlice; break;

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,1,0)
			case V4L2_CID_MPEG_VIDEO_H264_ENTROPY_MODE:			FDBE4DC4E08D348b98D2A9A10762FF9A2->value = pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoEntropyProperty[ 0 ] ? V4L2_MPEG_VIDEO_H264_ENTROPY_MODE_CAVLC : V4L2_MPEG_VIDEO_H264_ENTROPY_MODE_CABAC; break;
			#endif

			default:  return -EINVAL;
			}
			FDBE4DC4E08D348b98D2A9A10762FF9A2 = FDBE4DC4E08D348b98D2A9A10762FF9A2 + size;

			count--;
		}
	}
	return 0;
}

static int F91C01BFADB8E43df81EC6CC41D2EE087( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_ext_controls * F6537805ACA4443d5AA5A380BA0BC5276 )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F91C01BFADB8E43df81EC6CC41D2EE087() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F91C01BFADB8E43df81EC6CC41D2EE087() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	struct v4l2_ext_control * FDBE4DC4E08D348b98D2A9A10762FF9A2 = F6537805ACA4443d5AA5A380BA0BC5276->controls;

	int count = F6537805ACA4443d5AA5A380BA0BC5276->count;

	int size = sizeof(struct v4l2_ext_control);

	int i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1;

	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F91C01BFADB8E43df81EC6CC41D2EE087()\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	int index = 0;

	#ifndef AME_PL330A
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) {

		if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x03) ||	(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x85) )
		{
			index = ((pVideo->F0DD7393CD1494e27A72652C7D1A97893 < 4) ? pVideo->F0DD7393CD1494e27A72652C7D1A97893: pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 4);// subdevice 0~3 use array 0~3, subdevice 4~7 use array 8~11
		}
		else if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) )
		{
			index = ((pVideo->F0DD7393CD1494e27A72652C7D1A97893 < 1) ? pVideo->F0DD7393CD1494e27A72652C7D1A97893: pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 7);// subdevice 0 use array 0, subdevice 1 use array 8
		}
		else
		{
			index = ((pVideo->F0DD7393CD1494e27A72652C7D1A97893 < 4) ? pVideo->F0DD7393CD1494e27A72652C7D1A97893: pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 4);// subdevice 0~3 use array 0~3, subdevice 4~7 use array 8~11
		}
	}

	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
	{
		ULONG counts = 1;
		
		if( ((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == 0x02) || ((pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == 0x03)  ) {

			if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer & 0x0F) == 0x0A ) 
			{
				counts = 8;
			}
			else
			{
				counts = 4;
			}
		}
		
		index = pVideo->F0DD7393CD1494e27A72652C7D1A97893;
	}
	#endif

	#if LINUX_VERSION_CODE >= KERNEL_VERSION(4,5,0)
	
	if( F6537805ACA4443d5AA5A380BA0BC5276->which == V4L2_CTRL_CLASS_MPEG ) {

	#else
	
	if( F6537805ACA4443d5AA5A380BA0BC5276->ctrl_class == V4L2_CTRL_CLASS_MPEG ) {
	
	#endif


		if( count > 7 ) return 0;

		while( count ) {

			switch(FDBE4DC4E08D348b98D2A9A10762FF9A2->id) {

			case V4L2_CID_MPEG_VIDEO_BITRATE_MODE:	pVideo->F3D935AFB5C164dac97F5A7CA0150BC60    = (FDBE4DC4E08D348b98D2A9A10762FF9A2->value ) & 1; // do not use V4L2_BITRATE_NONE = 0, V4L2_BITRATE_CBR = 1, V4L2_BITRATE_VBR = 2, confilct with 
																											 // V4L2_MPEG_VIDEO_BITRATE_MODE_VBR = 0, V4L2_MPEG_VIDEO_BITRATE_MODE_CBR = 1
									
													#ifndef AME_PL330A

													if(pVideo->F3D935AFB5C164dac97F5A7CA0150BC60 == V4L2_MPEG_VIDEO_BITRATE_MODE_VBR )
													{
														if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 )
														{
															if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 2 )
															{
																CBR_to_VBR( pVideo, pVideo->F0DD7393CD1494e27A72652C7D1A97893 );//0~7
															}
														}
													}

													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) {
														//only for encoder
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoBitRateModeProperty[ index ]  =   0x88000000 | pVideo->F3D935AFB5C164dac97F5A7CA0150BC60;
														}
													}
													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

														(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			
														(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
													{
														//only for encoder
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoBitRateModeProperty[ index ]  =   0x88000000 | pVideo->F3D935AFB5C164dac97F5A7CA0150BC60;
														}
													}
													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) ) {
														//only for encoder
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoBitRateModeProperty[ 0 ]  =   0x88000000 | pVideo->F3D935AFB5C164dac97F5A7CA0150BC60;
														}
													}
													#else
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoBitRateModeProperty[ 0 ]  =   0x88000000 | pVideo->F3D935AFB5C164dac97F5A7CA0150BC60;
														}
													#endif

													break;

			case V4L2_CID_MPEG_VIDEO_BITRATE:		pVideo->F65C8BF3BAA2D4fbb876EE33F491F1931 = FDBE4DC4E08D348b98D2A9A10762FF9A2->value; 

												
													#ifndef AME_PL330A
													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) {
														//only for encoder
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoBitRateProperty[ index ]  =   0x88000000 | pVideo->F65C8BF3BAA2D4fbb876EE33F491F1931;
														}
													}

													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

														(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			
														(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
													{
														//only for encoder
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoBitRateProperty[ index ]  =   0x88000000 | pVideo->F65C8BF3BAA2D4fbb876EE33F491F1931;
														}
													}
													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) ) {
														//only for encoder
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoBitRateProperty[ 0 ]  =   0x88000000 | pVideo->F65C8BF3BAA2D4fbb876EE33F491F1931;
														}
													}
													#else
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoBitRateProperty[ 0 ]  =   0x88000000 | pVideo->F65C8BF3BAA2D4fbb876EE33F491F1931;
														}
													#endif
													break;


			case F50EB0715BAAC4d35AA3EE21A2F673819:		pVideo->FF63087B4098B4de18859989009950824 = FDBE4DC4E08D348b98D2A9A10762FF9A2->value; 

													#ifndef AME_PL330A
													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) {
														//only for encoder
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogVideoCompressionQualityProperty[ index ]  =   0x88000000 | pVideo->FF63087B4098B4de18859989009950824;
														}
													}

													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

														(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			
														(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
													{
														//only for encoder
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogVideoCompressionQualityProperty[ index ]  =   0x88000000 | pVideo->FF63087B4098B4de18859989009950824;
														}
													}
													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) ) {
														//only for encoder
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogVideoCompressionQualityProperty[ 0 ]  =   0x88000000 | pVideo->FF63087B4098B4de18859989009950824;
														}
													}
													#else
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogVideoCompressionQualityProperty[ 0 ]  =   0x88000000 | pVideo->FF63087B4098B4de18859989009950824;
														}
													#endif
				
													break;

			case V4L2_CID_MPEG_VIDEO_GOP_SIZE:		pVideo->F1CA927B5918D436c9F5839C9727D620E     = FDBE4DC4E08D348b98D2A9A10762FF9A2->value; 

													#ifndef AME_PL330A
													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) {
														//only for encoder
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogVideoCompressionKeyframeRateProperty[ index ]  =   0x88000000 | pVideo->F1CA927B5918D436c9F5839C9727D620E;
														}
													}
				
													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

														(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			
														(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
													{
														//only for encoder
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogVideoCompressionKeyframeRateProperty[ index ]  =   0x88000000 | pVideo->F1CA927B5918D436c9F5839C9727D620E;
														}
													}
				
													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) ) {
														//only for encoder
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogVideoCompressionKeyframeRateProperty[ 0 ]  =   0x88000000 | pVideo->F1CA927B5918D436c9F5839C9727D620E;
														}
													}
													#else
														if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogVideoCompressionKeyframeRateProperty[ 0 ]  =   0x88000000 | pVideo->F1CA927B5918D436c9F5839C9727D620E;
														}
													#endif
													break;

			case F59D7E164EA0643c987147244BD095662:		pVideo->FB4E9A11D151C4d93B0C750EC1BE4C7C5      = FDBE4DC4E08D348b98D2A9A10762FF9A2->value; 


													#ifndef AME_PL330A
													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) {

														if(pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															
															int skip = 0;

															switch(pVideo->FB4E9A11D151C4d93B0C750EC1BE4C7C5)
															{
																case 50000:
																case 60000:
																	skip = 0;
																	break;

																case 25000:
																case 30000:
																	skip = 0;
																	break;

																case 12500:
																case 15000:
																	skip = 1;
																	break;

																case 6250:
																case 7500:
																	skip = 3;
																	break;

																case 5000:
																case 6000:
																	skip = 4;
																	break;

																case 2500:
																case 3000:
																	skip = 9;
																	break;
															
																default:
																	skip = 0;
																	break;
															};
															
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoSkipFrameRateProperty[ index ]  =   0x88000000 | skip;
														}

													}

													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

														(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			
														(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
													{

														if(pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoAvgFrameRateProperty[ index ]  =   0x88000000 | (pVideo->FB4E9A11D151C4d93B0C750EC1BE4C7C5/1000);
														}
													}
													
													if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 )
													{
														if(pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoAvgFrameRateProperty[ 0 ] = pVideo->FB4E9A11D151C4d93B0C750EC1BE4C7C5/1000;

															if( pVideo->FB6E79A0780E64bb28A3308666E67881C->FC3FEC90DD3E6414c83437752D6A0B4B2 > 0 )
															{
																pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoAvgFrameRateProperty[ 0 ]  |=   0x88000000;
															}
														}
													}
													#else
														if(pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoAvgFrameRateProperty[ 0 ] = pVideo->FB4E9A11D151C4d93B0C750EC1BE4C7C5/1000;

															if( pVideo->FB6E79A0780E64bb28A3308666E67881C->FC3FEC90DD3E6414c83437752D6A0B4B2 > 0 )
															{
																pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoAvgFrameRateProperty[ 0 ]  |=   0x88000000;
															}
														}
													#endif
													break;

			case FE8CF9C6EC12A48c79FEBD36B2EAD2642:		pVideo->FD9E5DCB7C0F94c32AF5A086BA8C007EC  = FDBE4DC4E08D348b98D2A9A10762FF9A2->value; 

													
													break;

			case V4L2_CID_MPEG_SET_KEY_FRAME:		
													#ifndef AME_PL330A
													if(pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
													{													
														if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nAnalogVideoCompressionOverrideKeyframeProperty[ index ]  =   0x1;
														}
													}
													#endif

													break;

			case V4L2_CID_MPEG_VIDEO_OSD_LINE:		
													if(pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
													{													
														pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomOsdTextLineProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = (FDBE4DC4E08D348b98D2A9A10762FF9A2->value) % 8; 
													}

													break;

			case V4L2_CID_MPEG_VIDEO_OSD_ENABLE:		
													{													
														pVideo->FB6E79A0780E64bb28A3308666E67881C->m_bCustomOsdTextEnableProperty = (FDBE4DC4E08D348b98D2A9A10762FF9A2->value) & 0x1;
													}

													break;


			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,32)

			case V4L2_CID_MPEG_VIDEO_OSD:			
													#ifndef AME_PL330A
													
													if(pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
													{													
														if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 )
														{
															memcpy( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomOsdTextLineProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] ], FDBE4DC4E08D348b98D2A9A10762FF9A2->string, 32 );

															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_bCustomOsdTextStringRefreshProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomOsdTextLineProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] ] = TRUE; 
														}
														else if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

																(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
															
																(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_bCustomOsdTextStringRefreshProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ 0 ] = TRUE; 
															
															memcpy( (CHAR *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ 0 ]), FDBE4DC4E08D348b98D2A9A10762FF9A2->string, 64 );
														}
														else
														{
															memcpy( FE2D83A80F4E94ef188507C175ABF3840[ i ], FDBE4DC4E08D348b98D2A9A10762FF9A2->string, 64 );
														}
													}

													if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) )
													{
														if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x03) ||	(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x85) )
														{
															memcpy( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ (pVideo->F0DD7393CD1494e27A72652C7D1A97893 % 4)  ][ 0 ], FDBE4DC4E08D348b98D2A9A10762FF9A2->string, 64 );
														}
														else if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) || (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x07) )
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_bCustomOsdTextStringRefreshProperty[ 0 ][ 0 ] = TRUE; 
															
															memcpy( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ 0 ][ 0 ], FDBE4DC4E08D348b98D2A9A10762FF9A2->string, 64 );
															memcpy( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ 4 ][ 0 ], FDBE4DC4E08D348b98D2A9A10762FF9A2->string, 64 );

															//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "OSD %s\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ 0 ][ 0 ] );

															CBAA449B6EB840758260682DA8444D8C( pVideo->FB6E79A0780E64bb28A3308666E67881C, 0, FALSE );

														}
														else
														{
															memcpy( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ (pVideo->F0DD7393CD1494e27A72652C7D1A97893 % 4)  ][ 0 ], FDBE4DC4E08D348b98D2A9A10762FF9A2->string, 64 );
														}

													}
													#endif
													break;

			#else
			
			case V4L2_CID_MPEG_VIDEO_OSD:			
													#ifndef AME_PL330A
													if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 )
													{
														memcpy( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomOsdTextLineProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] ], FDBE4DC4E08D348b98D2A9A10762FF9A2->reserved, 32 );

														pVideo->FB6E79A0780E64bb28A3308666E67881C->m_bCustomOsdTextStringRefreshProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomOsdTextLineProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] ] = TRUE; 
													}
													else if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) )
													{
														if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x03) ||	(pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x85) )
														{
															memcpy( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ (pVideo->F0DD7393CD1494e27A72652C7D1A97893 % 4)  ][ 0 ], FDBE4DC4E08D348b98D2A9A10762FF9A2->reserved, 64 );
														}
														else if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) || (pVideo->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x07) )
														{
															memcpy( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ 0 ][ 0 ], FDBE4DC4E08D348b98D2A9A10762FF9A2->reserved, 64 );
															memcpy( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ 4 ][ 0 ], FDBE4DC4E08D348b98D2A9A10762FF9A2->reserved, 64 );
														}
														else
														{
															memcpy( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ (pVideo->F0DD7393CD1494e27A72652C7D1A97893 % 4)  ][ 0 ], FDBE4DC4E08D348b98D2A9A10762FF9A2->reserved, 64 );
														}
													}
													else if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

															(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
															
															(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
													{
														pVideo->FB6E79A0780E64bb28A3308666E67881C->m_bCustomOsdTextStringRefreshProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ 0 ] = TRUE; 
															
														memcpy( (CHAR *)(pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pCustomOsdTextStringProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ 0 ]), FDBE4DC4E08D348b98D2A9A10762FF9A2->reserved, 64 );
													}
													else
													{
														memcpy( FE2D83A80F4E94ef188507C175ABF3840[ i ], FDBE4DC4E08D348b98D2A9A10762FF9A2->reserved, 64 );
													}
													#endif

													break;


			#endif
			
			case V4L2_CID_MPEG_VIDEO_H264_PROFILE:		
													{													
														if(pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoProfileProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = 0x88000000 | ((FDBE4DC4E08D348b98D2A9A10762FF9A2->value) & 0xFF);

															F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] m_nCustomEncoderVideoProfileProperty[%d] = 0x%x\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE, pVideo->F0DD7393CD1494e27A72652C7D1A97893, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoProfileProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] );
														}
													}

													break;

			case V4L2_CID_MPEG_VIDEO_H264_LEVEL:		
													{													
														pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustom_H264_Level_Property = 0x88000000 | ((FDBE4DC4E08D348b98D2A9A10762FF9A2->value) & 0xFF); 
													}

													break;

			case V4L2_CID_MPEG_VIDEO_ASPECT:		
													{													
														if(pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoAspectRatioProperty[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = 0x88000000 | (FDBE4DC4E08D348b98D2A9A10762FF9A2->value); 
														}
													}

													break;

			case V4L2_CID_MPEG_SET_SLICE:

													{													
														if(pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->m_nCustomEncoderSlice = FDBE4DC4E08D348b98D2A9A10762FF9A2->value; 
					
															F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] m_nCustomEncoderSlice(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE, pVideo->m_nCustomEncoderSlice);
														}
													}

													break;

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,1,0)
			case V4L2_CID_MPEG_VIDEO_H264_ENTROPY_MODE:	
													//V4L2_MPEG_VIDEO_H264_ENTROPY_MODE_CAVLC = 0, V4L2_MPEG_VIDEO_H264_ENTROPY_MODE_CABAC = 1
													// windows and liux are invert
													{
														if(pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002)
														{
															pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoEntropyProperty[ 0 ] = (FDBE4DC4E08D348b98D2A9A10762FF9A2->value & 0x1) ? 0 : 1; 

															F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] m_nCustomEncoderVideoEntropyProperty[ 0 ](0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE, pVideo->FB6E79A0780E64bb28A3308666E67881C->m_nCustomEncoderVideoEntropyProperty[ 0 ]);
														}
													}
													break;
			#endif

			default: break;
			}
			FDBE4DC4E08D348b98D2A9A10762FF9A2 = FDBE4DC4E08D348b98D2A9A10762FF9A2 + size;

			count--;
		}
	}
	
	return 0;
}
static int common_video_device_vidioc_try_ext_ctrls( struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_ext_controls * F6537805ACA4443d5AA5A380BA0BC5276)
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_try_ext_ctrls() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_try_ext_ctrls() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	struct v4l2_ext_control * FDBE4DC4E08D348b98D2A9A10762FF9A2 = F6537805ACA4443d5AA5A380BA0BC5276->controls;

	int count = F6537805ACA4443d5AA5A380BA0BC5276->count;

	int size = sizeof(struct v4l2_ext_control);

	int i = pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE * 4 + pVideo->F0DD7393CD1494e27A72652C7D1A97893 * 1;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] common_video_device_vidioc_try_ext_ctrls()\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

}
//not finished
/*
static int common_video_device_vidioc_query_ext_ctrl(struct file *FEBA6DA02A6244ff7AFA9DCC660800FB4, void *fh, struct v4l2_query_ext_ctrl *p_query_ext_ctrl)
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_query_ext_ctrl() pVideo == NULL\n" );

		return -EINVAL;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_query_ext_ctrl() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return -EINVAL;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "common_video_device_vidioc_query_ext_ctrl() id(0x%x) type(0x%x) name(%s)\n", p_query_ext_ctrl->id, p_query_ext_ctrl->type, p_query_ext_ctrl->name );

	int i = 0;
	for( i = 0 ; i < ARRAY_SIZE(LINUXV4L2_V4L2_QUERY_EXT_CTRL); i++ ) {

		if( p_query_ext_ctrl->id == LINUXV4L2_V4L2_QUERY_EXT_CTRL[ i ].id ) {

			//if( F6965D2100E0840159702EF5670FD1E02[ j ][ i + 2 ] == 1 )
			{

				memcpy( p_query_ext_ctrl, &(LINUXV4L2_V4L2_QUERY_EXT_CTRL[ i ]), sizeof(struct v4l2_query_ext_ctrl) );

				return 0;
			}
		}
	}

	//error
	return -EINVAL;

}
*/
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,24)

static int FFAC5AD9B7CD64ca28E7E9847C52A6E92( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_mpeg_compression * F4C7025F96E0944f2A84D86762A483F4A )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FFAC5AD9B7CD64ca28E7E9847C52A6E92()\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	if( pVideo->F3D935AFB5C164dac97F5A7CA0150BC60 == V4L2_BITRATE_CBR ) {

		//
		//
		//
		//
		F4C7025F96E0944f2A84D86762A483F4A->vi_bitrate.mode = V4L2_BITRATE_CBR;            //

		F4C7025F96E0944f2A84D86762A483F4A->vi_bitrate.target = pVideo->F65C8BF3BAA2D4fbb876EE33F491F1931; //

		F4C7025F96E0944f2A84D86762A483F4A->vi_frames_per_gop = pVideo->F1CA927B5918D436c9F5839C9727D620E;     //

		F4C7025F96E0944f2A84D86762A483F4A->vi_frame_rate = pVideo->FB4E9A11D151C4d93B0C750EC1BE4C7C5;          //
		
																           //

		F4C7025F96E0944f2A84D86762A483F4A->reserved_5[ 0 ] = pVideo->FD9E5DCB7C0F94c32AF5A086BA8C007EC;    //

		return 0;
	}
	if( pVideo->F3D935AFB5C164dac97F5A7CA0150BC60 == V4L2_BITRATE_VBR ) {

		//
		//
		//B DEFAULT: MODE = VBR / QUALITY = 6000 / GOP = 25 / QPSTEP = 1 / FPS = 25000 (25.000 FPS)
		//
		F4C7025F96E0944f2A84D86762A483F4A->vi_bitrate.mode = V4L2_BITRATE_VBR;            //

		F4C7025F96E0944f2A84D86762A483F4A->vi_bitrate.target = pVideo->FF63087B4098B4de18859989009950824; // 

		F4C7025F96E0944f2A84D86762A483F4A->vi_frames_per_gop = pVideo->F1CA927B5918D436c9F5839C9727D620E;     //

		F4C7025F96E0944f2A84D86762A483F4A->vi_frame_rate = pVideo->FB4E9A11D151C4d93B0C750EC1BE4C7C5;          //

																           //

		F4C7025F96E0944f2A84D86762A483F4A->reserved_5[ 0 ] = pVideo->FD9E5DCB7C0F94c32AF5A086BA8C007EC;    //

		return 0;
	}
	return -EINVAL;
}

static int FA09B89F985B34f599FA8349FDB25C1CF( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_mpeg_compression * F4C7025F96E0944f2A84D86762A483F4A )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FA09B89F985B34f599FA8349FDB25C1CF()\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	if( F4C7025F96E0944f2A84D86762A483F4A->vi_bitrate.mode == V4L2_BITRATE_CBR ) {

		pVideo->F3D935AFB5C164dac97F5A7CA0150BC60 = F4C7025F96E0944f2A84D86762A483F4A->vi_bitrate.mode;      //

		pVideo->F65C8BF3BAA2D4fbb876EE33F491F1931 = F4C7025F96E0944f2A84D86762A483F4A->vi_bitrate.target; //

		pVideo->F1CA927B5918D436c9F5839C9727D620E = F4C7025F96E0944f2A84D86762A483F4A->vi_frames_per_gop;     //

		pVideo->FD9E5DCB7C0F94c32AF5A086BA8C007EC = 	F4C7025F96E0944f2A84D86762A483F4A->reserved_5[ 0 ];   //

		pVideo->FB4E9A11D151C4d93B0C750EC1BE4C7C5 = F4C7025F96E0944f2A84D86762A483F4A->vi_frame_rate;          //
		
																           //
		return 0;
	}
	if( F4C7025F96E0944f2A84D86762A483F4A->vi_bitrate.mode == V4L2_BITRATE_VBR ) {

		pVideo->F3D935AFB5C164dac97F5A7CA0150BC60 = F4C7025F96E0944f2A84D86762A483F4A->vi_bitrate.mode;      //

		pVideo->FF63087B4098B4de18859989009950824 = F4C7025F96E0944f2A84D86762A483F4A->vi_bitrate.target; // 

		pVideo->F1CA927B5918D436c9F5839C9727D620E = F4C7025F96E0944f2A84D86762A483F4A->vi_frames_per_gop;     //

		pVideo->FD9E5DCB7C0F94c32AF5A086BA8C007EC = 	F4C7025F96E0944f2A84D86762A483F4A->reserved_5[ 0 ];   //

		pVideo->FB4E9A11D151C4d93B0C750EC1BE4C7C5 = F4C7025F96E0944f2A84D86762A483F4A->vi_frame_rate;          //

																           //
		return 0;
	}
	return -EINVAL;
}

#endif

static int FE64270764DAF4bdbA2DF5779584DF0F7( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_encoder_cmd * F685481532C82490191EB3B24CC84235E )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FE64270764DAF4bdbA2DF5779584DF0F7( %08X )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), F685481532C82490191EB3B24CC84235E->cmd );

//	enum v4l2_bitrate_mode { V4L2_BITRATE_NONE = 0, V4L2_BITRATE_CBR = 1, V4L2_BITRATE_VBR = 2 };

	if( F685481532C82490191EB3B24CC84235E->cmd == 0x00000004 ) { //

		F685481532C82490191EB3B24CC84235E->raw.data[ 0 ] = pVideo->F3D935AFB5C164dac97F5A7CA0150BC60;    //

		F685481532C82490191EB3B24CC84235E->raw.data[ 1 ] = pVideo->F65C8BF3BAA2D4fbb876EE33F491F1931; //

		F685481532C82490191EB3B24CC84235E->raw.data[ 2 ] = pVideo->FF63087B4098B4de18859989009950824; // 

		F685481532C82490191EB3B24CC84235E->raw.data[ 3 ] = pVideo->F1CA927B5918D436c9F5839C9727D620E;     //

		F685481532C82490191EB3B24CC84235E->raw.data[ 4 ] = pVideo->FD9E5DCB7C0F94c32AF5A086BA8C007EC;  //

		F685481532C82490191EB3B24CC84235E->raw.data[ 5 ] = pVideo->FB4E9A11D151C4d93B0C750EC1BE4C7C5;      //

															      //
		return 0;
	}
	if( F685481532C82490191EB3B24CC84235E->cmd == 0x00000005 ) { //

		pVideo->F3D935AFB5C164dac97F5A7CA0150BC60    = F685481532C82490191EB3B24CC84235E->raw.data[ 0 ]; //

		pVideo->F65C8BF3BAA2D4fbb876EE33F491F1931 = F685481532C82490191EB3B24CC84235E->raw.data[ 1 ]; //

		pVideo->FF63087B4098B4de18859989009950824 = F685481532C82490191EB3B24CC84235E->raw.data[ 2 ]; // 

		pVideo->F1CA927B5918D436c9F5839C9727D620E     = F685481532C82490191EB3B24CC84235E->raw.data[ 3 ]; //

		pVideo->FD9E5DCB7C0F94c32AF5A086BA8C007EC  = F685481532C82490191EB3B24CC84235E->raw.data[ 4 ]; //

		pVideo->FB4E9A11D151C4d93B0C750EC1BE4C7C5      = F685481532C82490191EB3B24CC84235E->raw.data[ 5 ]; //

																  //
		return 0;
	}
	return -EINVAL;
}

static int FD89C51CD80FB47949EE4D5A090E1ED6D( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_requestbuffers * p_requestbuffers )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FD89C51CD80FB47949EE4D5A090E1ED6D() pVideo == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FD89C51CD80FB47949EE4D5A090E1ED6D()\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	{
		return videobuf_reqbufs( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), p_requestbuffers );
	}
}

static int FC28B4FA81CB44cd2A02DAABFB15C0175( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_buffer * F947DB5F969484d42AA3A243E06DB35EB )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FC28B4FA81CB44cd2A02DAABFB15C0175() pVideo == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FC28B4FA81CB44cd2A02DAABFB15C0175( I:%d )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), F947DB5F969484d42AA3A243E06DB35EB->index );

	{
		return videobuf_querybuf( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), F947DB5F969484d42AA3A243E06DB35EB );
	}
}
#ifdef AME_MZ0380
	#if LINUX_VERSION_CODE >= KERNEL_VERSION(3,6,0)
		#define V4L2_BUF_FLAG_INPUT     0x0200
	#endif
#endif


static int F1CEFD4E364F942d5A796687660DF4476( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_buffer * F947DB5F969484d42AA3A243E06DB35EB )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	int ret = -EINVAL;

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F1CEFD4E364F942d5A796687660DF4476() pVideo == NULL\n" );

		return 0;
	}
	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F1CEFD4E364F942d5A796687660DF4476( I:%d ) flags(0x%x)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), F947DB5F969484d42AA3A243E06DB35EB->index , F947DB5F969484d42AA3A243E06DB35EB->flags);

#ifdef AME_MZ0380
	//must set this otherwise H264 will have error
	F947DB5F969484d42AA3A243E06DB35EB->flags &= ~V4L2_BUF_FLAG_INPUT;
#endif
/*
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F1CEFD4E364F942d5A796687660DF4476() type(0d%d) memory(0d%d) index(0x%x) m.userptr(llx%llx) length(0d%d)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), 
		
	F947DB5F969484d42AA3A243E06DB35EB->type,
	F947DB5F969484d42AA3A243E06DB35EB->memory, 
	F947DB5F969484d42AA3A243E06DB35EB->index,
	F947DB5F969484d42AA3A243E06DB35EB->m.userptr,
	F947DB5F969484d42AA3A243E06DB35EB->length 
	);
*/
	ret = videobuf_qbuf( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), F947DB5F969484d42AA3A243E06DB35EB );
	
	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F1CEFD4E364F942d5A796687660DF4476( I:%d ) flags(0x%x) ret(0x%x) pVideo(0x%x) bytesused(0d%d)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), F947DB5F969484d42AA3A243E06DB35EB->index , F947DB5F969484d42AA3A243E06DB35EB->flags, ret, pVideo, F947DB5F969484d42AA3A243E06DB35EB->bytesused);

	return ret;

}

static int F8ED1C78CFCE74f82A69E33D70B8A0DB3( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, struct v4l2_buffer * F947DB5F969484d42AA3A243E06DB35EB )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	int ret = -EINVAL;

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F8ED1C78CFCE74f82A69E33D70B8A0DB3() pVideo == NULL\n" );

		return 0;
	}

	ret =  videobuf_dqbuf( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A), F947DB5F969484d42AA3A243E06DB35EB, FEBA6DA02A6244ff7AFA9DCC660800FB4->f_flags & O_NONBLOCK );

	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F8ED1C78CFCE74f82A69E33D70B8A0DB3( I:%d ) flags(0x%x) ret(0x%x) pVideo(0x%x) bytesused(0d%d)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), F947DB5F969484d42AA3A243E06DB35EB->index, F947DB5F969484d42AA3A243E06DB35EB->flags, ret, pVideo, F947DB5F969484d42AA3A243E06DB35EB->bytesused );

	return ret;
}

static int F4B0874C1F68D498bA1262243B9C11323( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, enum v4l2_buf_type F7F32101CEC1342f984C871B134196B83 )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F4B0874C1F68D498bA1262243B9C11323() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F4B0874C1F68D498bA1262243B9C11323() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	unsigned long flags = 0x00000000;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F4B0874C1F68D498bA1262243B9C11323( T:%02d )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), F7F32101CEC1342f984C871B134196B83 );

	INIT_LIST_HEAD( &(pVideo->F0EA6D27495A14af1A9607DE7C222A3B1) );

	INIT_LIST_HEAD( &(pVideo->FDA1F8237E2D04e5a8737CF587701D54D) );

	//for different thread must not be interruptable
	if( 0 == wait_event_timeout( m_wait_queue_component, m_component_ready == 1, msecs_to_jiffies( 6000 ) )){
	
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F4B0874C1F68D498bA1262243B9C11323() time out\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE );
	} 
	else { 
		
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F4B0874C1F68D498bA1262243B9C11323() success, m_component_ready(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE, m_component_ready );
		
		down( &m_sComponentAccessSemaphore ); 

		m_component_ready = 0;

		up( &m_sComponentAccessSemaphore ); 
	} 
	
	#ifndef AME_PL330A
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210 ) { if( FALSE == FBA8330CBDD2A44deB393BF473548E5C4( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 ) { if( FALSE == EE7012456B844F189B414E6E9F80974A( pVideo->FB6E79A0780E64bb28A3308666E67881C, NULL, FALSE ) ) { ; } }

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 ) { if( FALSE == daab48e1fab545a880ab7abf60648829( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 ) { if( FALSE == E055660A74D541D98AED7EB16E515E32( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100 ) { if( FALSE == D443ECD5E9B94AC5B04BB7489B656CAD( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370 ) { if( FALSE == D443ECD5E9B94AC5B04BB7489B656CAD( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380 ) { if( FALSE == D443ECD5E9B94AC5B04BB7489B656CAD( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
	if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 ) { if( FALSE == B2FA3948CEE84C26A7E4AE5AF5AB51C0( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
	#else
	B2FA3948CEE84C26A7E4AE5AF5AB51C0( pVideo->FB6E79A0780E64bb28A3308666E67881C );
	#endif

	if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001 )
	{ 
		int k = 0;
		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			if( pVideo == pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pVideo[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] )
			{
				pVideo->FB6E79A0780E64bb28A3308666E67881C->FA12AAA3D283C4cf0BF02ACD3957899B0[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] |= (1 << k);

				#ifndef AME_PL330A
				if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) )
				{
					if( pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x4A || pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x4B )
					{
						if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pl330b_combine_4_chip )
						{
							if(  g_pDevice[ 1 ] )
							{
								g_pDevice[ 1 ]->FA12AAA3D283C4cf0BF02ACD3957899B0[ 0 ] |= (1 << k);
							}
							if(  g_pDevice[ 2 ] )
							{
								g_pDevice[ 2 ]->FA12AAA3D283C4cf0BF02ACD3957899B0[ 0 ] |= (1 << k);
							}
							if(  g_pDevice[ 3 ] )
							{
								g_pDevice[ 3 ]->FA12AAA3D283C4cf0BF02ACD3957899B0[ 0 ] |= (1 << k);
							}
						}
					}
				}
				#endif
				
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F4B0874C1F68D498bA1262243B9C11323() FA12AAA3D283C4cf0BF02ACD3957899B0(0x%x)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->FB6E79A0780E64bb28A3308666E67881C->FA12AAA3D283C4cf0BF02ACD3957899B0[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] );
	
				break;
			}
		}
	}

	if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002 ) //{ pVideo->FB6E79A0780E64bb28A3308666E67881C->FDB274CD437614fec94859748411FE56A[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] = 0x00000001; }
	{ 
		int k = 0;
		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			if( pVideo == pVideo->FB6E79A0780E64bb28A3308666E67881C->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] )
			{
				pVideo->FB6E79A0780E64bb28A3308666E67881C->FDB274CD437614fec94859748411FE56A[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] |= (1 << k);
			
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F4B0874C1F68D498bA1262243B9C11323() FDB274CD437614fec94859748411FE56A(0x%x)\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pVideo->FB6E79A0780E64bb28A3308666E67881C->FDB274CD437614fec94859748411FE56A[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] );
	
				break;
			}
		}
	}

	int ret =  videobuf_streamon( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A) );

	down( &m_sComponentAccessSemaphore ); 

	m_component_ready = 1;

	up( &m_sComponentAccessSemaphore ); 

	wake_up( &m_wait_queue_component );

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F4B0874C1F68D498bA1262243B9C11323( T:%02d ) end\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), F7F32101CEC1342f984C871B134196B83 );

	return ret;

}

static int FBD214630F7C445f9B3050CEFDBB729B2( struct file * FEBA6DA02A6244ff7AFA9DCC660800FB4, void * FBC3D436FD4754a78A5BE6F92EB05E3FE, enum v4l2_buf_type F7F32101CEC1342f984C871B134196B83 )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(FEBA6DA02A6244ff7AFA9DCC660800FB4->private_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FBD214630F7C445f9B3050CEFDBB729B2() pVideo == NULL\n" );

		return 0;
	}

	if( pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FBD214630F7C445f9B3050CEFDBB729B2() pVideo->FB6E79A0780E64bb28A3308666E67881C == NULL\n" );

		return 0;
	}

	int returns = 0;

	unsigned long flags = 0x00000000;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FBD214630F7C445f9B3050CEFDBB729B2( T:%02d )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), F7F32101CEC1342f984C871B134196B83 );

	down( &m_pFile_Stream_ControlSemaphore );

	int ret = videobuf_streamoff( &(pVideo->FFDA6DA912A8649aeB0BC30D3D43DCD7A) );

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FBD214630F7C445f9B3050CEFDBB729B2( T:%02d ) end\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), F7F32101CEC1342f984C871B134196B83 );

	up( &m_pFile_Stream_ControlSemaphore );

	return ret;
}

// ##########################################################################################################################################################################################################
// 
static int FDE722856BB1E40ad93279EA24FDADC7A( struct videobuf_queue * p_queue, unsigned int * p_count, unsigned int * p_size )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(p_queue->priv_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FDE722856BB1E40ad93279EA24FDADC7A() pVideo == NULL\n" );

		return 0;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FDE722856BB1E40ad93279EA24FDADC7A( C:%02d, S:%02d )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), *p_count, *p_size );


	*p_size = pVideo->FD1832F8D382F4e91914C0048CC5A9DD8 * pVideo->F5B8891B732954fc2B26B7BFFCB15B596 * 2;

   *p_size = pVideo->F71FE13C55F1948828A7FA0A0A5800543 * pVideo->F5B8891B732954fc2B26B7BFFCB15B596;

   *p_size = pVideo->F07563F8419D74e1cB3F1A4F962EBACE8;

	if( *p_count == 0 ) { 
		
		*p_count = 32; //
	}
    while( (*p_size) * (*p_count) > (1024 * 1024 * 48) ) { // 48MB

		*p_count = *p_count - 1;
	}
	return 0;
}

static int F89FBFD276737452cB02B90E1858E414B( struct videobuf_queue * p_queue, struct videobuf_buffer * F947DB5F969484d42AA3A243E06DB35EB, enum v4l2_field e_field ) 
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(p_queue->priv_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F89FBFD276737452cB02B90E1858E414B() pVideo == NULL\n" );

		return 0;
	}

	F170997530C6943659ECE8DEC21301F66 * pVideoBuffer = (F170997530C6943659ECE8DEC21301F66 *)(container_of(F947DB5F969484d42AA3A243E06DB35EB, F170997530C6943659ECE8DEC21301F66, F6A821C5E7AA043f999FB3C51DB94DD2B));

	int ret = 0;

//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F89FBFD276737452cB02B90E1858E414B( B:%08X/%08X, F:%08X )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(F947DB5F969484d42AA3A243E06DB35EB), (unsigned int)(&(pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B)), e_field );


	if( F947DB5F969484d42AA3A243E06DB35EB->baddr != 0x00000000 && F947DB5F969484d42AA3A243E06DB35EB->bsize < pVideo->F07563F8419D74e1cB3F1A4F962EBACE8 ) { return -EINVAL; }

	#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25)

	if( F947DB5F969484d42AA3A243E06DB35EB->state == VIDEOBUF_NEEDS_INIT ) {

	#else

	if( F947DB5F969484d42AA3A243E06DB35EB->state == STATE_NEEDS_INIT ) {

	#endif

		F947DB5F969484d42AA3A243E06DB35EB->width = pVideo->FD1832F8D382F4e91914C0048CC5A9DD8;

		F947DB5F969484d42AA3A243E06DB35EB->height = pVideo->F5B8891B732954fc2B26B7BFFCB15B596;

		F947DB5F969484d42AA3A243E06DB35EB->bytesperline = pVideo->F71FE13C55F1948828A7FA0A0A5800543;

		F947DB5F969484d42AA3A243E06DB35EB->size = pVideo->F07563F8419D74e1cB3F1A4F962EBACE8;

		F947DB5F969484d42AA3A243E06DB35EB->field = e_field;

		ret = videobuf_iolock( p_queue, F947DB5F969484d42AA3A243E06DB35EB, NULL ); //allocate buffer here

		if( ret != 0 ) { 
			
			FF7C28EE760F14ad99457A74168D0FFBF( p_queue, F947DB5F969484d42AA3A243E06DB35EB );

			return ret;
		}
	}
	#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25)

	F947DB5F969484d42AA3A243E06DB35EB->state = VIDEOBUF_PREPARED;

	#else

	F947DB5F969484d42AA3A243E06DB35EB->state = STATE_PREPARED;

	#endif

	return 0;
}

static void F3A12A0E868554cb0AFE2F5789D55B19F( struct videobuf_queue * p_queue, struct videobuf_buffer * F947DB5F969484d42AA3A243E06DB35EB )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(p_queue->priv_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F3A12A0E868554cb0AFE2F5789D55B19F() pVideo == NULL\n" );

		return 0;
	}

	F170997530C6943659ECE8DEC21301F66 * pVideoBuffer = (F170997530C6943659ECE8DEC21301F66 *)(container_of(F947DB5F969484d42AA3A243E06DB35EB, F170997530C6943659ECE8DEC21301F66, F6A821C5E7AA043f999FB3C51DB94DD2B));

	unsigned long flags = 0x00000000;

//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F3A12A0E868554cb0AFE2F5789D55B19F( B:%08X/%08X )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(F947DB5F969484d42AA3A243E06DB35EB), (unsigned int)(&(pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B)) );


	#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25)

	F947DB5F969484d42AA3A243E06DB35EB->state = VIDEOBUF_QUEUED;

	#else

	F947DB5F969484d42AA3A243E06DB35EB->state = STATE_QUEUED;

	#endif

	spin_lock_irqsave( &pVideo->FE0A97B802F3C400aBD7CD5D313825C31, flags );

	list_add_tail( &pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue, &pVideo->F0EA6D27495A14af1A9607DE7C222A3B1 );

	spin_unlock_irqrestore( &pVideo->FE0A97B802F3C400aBD7CD5D313825C31, flags );
}

static void FF7C28EE760F14ad99457A74168D0FFBF( struct videobuf_queue * p_queue, struct videobuf_buffer * F947DB5F969484d42AA3A243E06DB35EB )
{
	F301FA49098CE4d9eB95F22BBD388E837 * pVideo = (F301FA49098CE4d9eB95F22BBD388E837 *)(p_queue->priv_data);

	if( pVideo == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FF7C28EE760F14ad99457A74168D0FFBF() pVideo == NULL\n" );

		return 0;
	}

	unsigned long flags = 0x00000000;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FF7C28EE760F14ad99457A74168D0FFBF( B:%08X )\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(F947DB5F969484d42AA3A243E06DB35EB) );

	//for different thread must not be interruptable
	if( 0 == wait_event_timeout( m_wait_queue_component, m_component_ready == 1, msecs_to_jiffies( 6000 ) )){
	
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FF7C28EE760F14ad99457A74168D0FFBF() time out\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE );
	} 
	else { 
		
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FF7C28EE760F14ad99457A74168D0FFBF() success, m_component_ready(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE, m_component_ready );
		
		down( &m_sComponentAccessSemaphore ); 

		m_component_ready = 0;

		up( &m_sComponentAccessSemaphore ); 
	} 

	if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001 ) { 
		
		int k = 0;
		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			if( pVideo == pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pVideo[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] )
			{ 
				//pVideo->FB6E79A0780E64bb28A3308666E67881C->FA12AAA3D283C4cf0BF02ACD3957899B0[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] &= ~( 1 << k );//clear k bit
		
				break;//only once
			}
		}

		if( k >= MAX_DEVICE_OPEN_NUM )
		{
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] strange ??? pVideo(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE, pVideo );

			down( &m_sComponentAccessSemaphore ); 

			m_component_ready = 1;

			up( &m_sComponentAccessSemaphore ); 

			wake_up( &m_wait_queue_component );

			return;
		}

		//if( pVideo->FB6E79A0780E64bb28A3308666E67881C->FA12AAA3D283C4cf0BF02ACD3957899B0[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] == 0x00000000 )
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->FA12AAA3D283C4cf0BF02ACD3957899B0[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] & ( 1 << k ) )
		{
			pVideo->FB6E79A0780E64bb28A3308666E67881C->FA12AAA3D283C4cf0BF02ACD3957899B0[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] &= ~( 1 << k );//clear k bit

			#ifndef AME_PL330A
			if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2) && (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) )
			{
				if( pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x4A || pVideo->FB6E79A0780E64bb28A3308666E67881C->iManufacturer == 0x4B )
				{
					if( pVideo->FB6E79A0780E64bb28A3308666E67881C->m_pl330b_combine_4_chip )
					{
						if(  g_pDevice[ 1 ] )
						{
							g_pDevice[ 1 ]->FA12AAA3D283C4cf0BF02ACD3957899B0[ 0 ] &= ~( 1 << k );
						}
						if(  g_pDevice[ 2 ] )
						{
							g_pDevice[ 2 ]->FA12AAA3D283C4cf0BF02ACD3957899B0[ 0 ] &= ~( 1 << k );
						}
						if(  g_pDevice[ 3 ] )
						{
							g_pDevice[ 3 ]->FA12AAA3D283C4cf0BF02ACD3957899B0[ 0 ] &= ~( 1 << k );
						}
					}
				}
			}
			#endif
			
			#ifndef AME_PL330A
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } } //
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210 ) { if( FALSE == F345FBFC397C04b6881D42414F15E44F4( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 ) { if( FALSE == EF8E67A5A31D4630AAB8CB2F9CE53E35( pVideo->FB6E79A0780E64bb28A3308666E67881C, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x9413 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6010 ) { if( FALSE == F02E4073E417A4ac9881C3E749255E2C7( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 ) { if( FALSE == fae68fd0b91c4995ba7b2f17b5913633( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 ) { if( FALSE == F80DB77E35D0448E838D583A1BE0B96E( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100 ) { if( FALSE == C823B90222FD455CB0C3A8BA17ADF490( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370 ) { if( FALSE == C823B90222FD455CB0C3A8BA17ADF490( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380 ) { if( FALSE == C823B90222FD455CB0C3A8BA17ADF490( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 ) { if( FALSE == F1D8A4353DCB40E3AC555846B3DD656A( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
			#endif
		}
	}
	if( pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002 ) { 
		
		int k = 0;
		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			if( pVideo == pVideo->FB6E79A0780E64bb28A3308666E67881C->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ][ k ] )
			{ 
				//pVideo->FB6E79A0780E64bb28A3308666E67881C->FDB274CD437614fec94859748411FE56A[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] &= ~( 1 << k );//clear k bit
		
				break;//only once
			}
		}

		if( k >= MAX_DEVICE_OPEN_NUM )
		{
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] strange h264 ??? pVideo(0x%x)\n", pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE, pVideo );

			down( &m_sComponentAccessSemaphore ); 

			m_component_ready = 1;

			up( &m_sComponentAccessSemaphore ); 

			wake_up( &m_wait_queue_component );

			return;
		}

		//if( pVideo->FB6E79A0780E64bb28A3308666E67881C->FDB274CD437614fec94859748411FE56A[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] == 0x00000000 ) 
		if( pVideo->FB6E79A0780E64bb28A3308666E67881C->FDB274CD437614fec94859748411FE56A[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] & ( 1 << k ) )
		{
			pVideo->FB6E79A0780E64bb28A3308666E67881C->FDB274CD437614fec94859748411FE56A[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] &= ~( 1 << k );//clear k bit

			#ifndef AME_PL330A
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } } //
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210 ) { if( FALSE == F345FBFC397C04b6881D42414F15E44F4( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 ) { if( FALSE == EF8E67A5A31D4630AAB8CB2F9CE53E35( pVideo->FB6E79A0780E64bb28A3308666E67881C, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 ) { if( FALSE == fae68fd0b91c4995ba7b2f17b5913633( pVideo->FB6E79A0780E64bb28A3308666E67881C, pVideo, NULL ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 ) { if( FALSE == F80DB77E35D0448E838D583A1BE0B96E( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100 ) { if( FALSE == C823B90222FD455CB0C3A8BA17ADF490( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370 ) { if( FALSE == C823B90222FD455CB0C3A8BA17ADF490( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380 ) { if( FALSE == C823B90222FD455CB0C3A8BA17ADF490( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
			if( pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 ) { if( FALSE == F1D8A4353DCB40E3AC555846B3DD656A( pVideo->FB6E79A0780E64bb28A3308666E67881C ) ) { ; } }
			#else
			F1D8A4353DCB40E3AC555846B3DD656A( pVideo->FB6E79A0780E64bb28A3308666E67881C );
			#endif
		}
	}

	#ifndef AME_PL330A
	if(	(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5851) ) 
	{

#ifdef CX2581_64bit

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

			#ifdef LINUXV4L2_VMALLOC_MODULE

			videobuf_vmalloc_free( F947DB5F969484d42AA3A243E06DB35EB ); //

			#endif

			#else

			struct videobuf_dmabuf * p_dma_buffer = &(F947DB5F969484d42AA3A243E06DB35EB->dma); //

			videobuf_dma_unmap( p_queue, p_dma_buffer );

			videobuf_dma_free( p_dma_buffer );

			#endif

#else

		#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,36)

		struct videobuf_dmabuf * p_dma_buffer = videobuf_to_dma( F947DB5F969484d42AA3A243E06DB35EB ); //

		videobuf_dma_unmap( p_queue->dev, p_dma_buffer ); 

		videobuf_dma_free( p_dma_buffer );


		#else 
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

			struct videobuf_dmabuf * p_dma_buffer = videobuf_to_dma( F947DB5F969484d42AA3A243E06DB35EB ); //

			videobuf_dma_unmap( p_queue, p_dma_buffer );

	//		videobuf_dma_unmap( p_queue->dev, p_dma_buffer ); // [2011.07.01] [MARCELO]


			videobuf_dma_free( p_dma_buffer );

			#else

			struct videobuf_dmabuf * p_dma_buffer = &(F947DB5F969484d42AA3A243E06DB35EB->dma); //

			videobuf_dma_unmap( p_queue, p_dma_buffer );

			videobuf_dma_free( p_dma_buffer );

			#endif

		#endif

#endif

	}
	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160) )
	{

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,36)

				struct videobuf_dmabuf * p_dma_buffer = videobuf_to_dma( F947DB5F969484d42AA3A243E06DB35EB ); //

				videobuf_dma_unmap( p_queue->dev, p_dma_buffer ); 

				videobuf_dma_free( p_dma_buffer );

			#else 
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

				struct videobuf_dmabuf * p_dma_buffer = videobuf_to_dma( F947DB5F969484d42AA3A243E06DB35EB ); //

				videobuf_dma_unmap( p_queue, p_dma_buffer );

		//		videobuf_dma_unmap( p_queue->dev, p_dma_buffer ); // [2011.07.01] [MARCELO]


				videobuf_dma_free( p_dma_buffer );

				#else

				struct videobuf_dmabuf * p_dma_buffer = &(F947DB5F969484d42AA3A243E06DB35EB->dma); //

				videobuf_dma_unmap( p_queue, p_dma_buffer );

				videobuf_dma_free( p_dma_buffer );

				#endif

			#endif

	}

	if( (pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1999 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA04C) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001) ) {
		
		#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

		#ifdef LINUXV4L2_VMALLOC_MODULE
		
		videobuf_vmalloc_free( F947DB5F969484d42AA3A243E06DB35EB ); //

		#endif

		#else

		struct videobuf_dmabuf * p_dma_buffer = &(F947DB5F969484d42AA3A243E06DB35EB->dma); //

		videobuf_dma_unmap( p_queue, p_dma_buffer );

		videobuf_dma_free( p_dma_buffer );

		#endif
	}
	if(	(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816) ||
		(pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pVideo->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817) )
	{
	
		#if TW6805_64bit

			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

			#ifdef LINUXV4L2_VMALLOC_MODULE

			videobuf_vmalloc_free( F947DB5F969484d42AA3A243E06DB35EB ); //

			#endif

			#else

			struct videobuf_dmabuf * p_dma_buffer = &(F947DB5F969484d42AA3A243E06DB35EB->dma); //

			videobuf_dma_unmap( p_queue, p_dma_buffer );

			videobuf_dma_free( p_dma_buffer );

			#endif

		#else
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,36)

				struct videobuf_dmabuf * p_dma_buffer = videobuf_to_dma( F947DB5F969484d42AA3A243E06DB35EB ); //

				videobuf_dma_unmap( p_queue->dev, p_dma_buffer ); 

				videobuf_dma_free( p_dma_buffer );


			#else 
				
				#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

				struct videobuf_dmabuf * p_dma_buffer = videobuf_to_dma( F947DB5F969484d42AA3A243E06DB35EB ); //

				videobuf_dma_unmap( p_queue, p_dma_buffer );

		//		videobuf_dma_unmap( p_queue->dev, p_dma_buffer ); // [2011.07.01] [MARCELO]


				videobuf_dma_free( p_dma_buffer );

				#else

				struct videobuf_dmabuf * p_dma_buffer = &(F947DB5F969484d42AA3A243E06DB35EB->dma); //

				videobuf_dma_unmap( p_queue, p_dma_buffer );

				videobuf_dma_free( p_dma_buffer );

				#endif

			#endif

		#endif //TW6805_64bit
	}
	#else
		#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

		#ifdef LINUXV4L2_VMALLOC_MODULE
		
		videobuf_vmalloc_free( F947DB5F969484d42AA3A243E06DB35EB ); //

		#endif

		#else

		struct videobuf_dmabuf * p_dma_buffer = &(F947DB5F969484d42AA3A243E06DB35EB->dma); //

		videobuf_dma_unmap( p_queue, p_dma_buffer );

		videobuf_dma_free( p_dma_buffer );

		#endif
	#endif

	#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25)

	F947DB5F969484d42AA3A243E06DB35EB->state = VIDEOBUF_NEEDS_INIT;	

	#else

	F947DB5F969484d42AA3A243E06DB35EB->state = STATE_NEEDS_INIT;

	#endif

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FF7C28EE760F14ad99457A74168D0FFBF( B:%08X ) end\n", (int)(pVideo->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(F947DB5F969484d42AA3A243E06DB35EB) );

	down( &m_sComponentAccessSemaphore ); 

	m_component_ready = 1;

	up( &m_sComponentAccessSemaphore ); 

	wake_up( &m_wait_queue_component );

}

// ##########################################################################################################################################################################################################
//
static int FD1CD603E47C14387BB6036D48A0561AC( struct snd_pcm_substream * F41E35C5990A344ab87C1D53585EECFCC )
{
//	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(snd_pcm_substream_chip( F41E35C5990A344ab87C1D53585EECFCC ));

	FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio = (FE8EB18A4C9984f9789EFF7C05EE073A0 *)(F41E35C5990A344ab87C1D53585EECFCC->pcm->card->private_data);
	
	if( pAudio == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FD1CD603E47C14387BB6036D48A0561AC() pAudio == NULL\n" );

		return 0;
	}

	int ret = 0;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FD1CD603E47C14387BB6036D48A0561AC() F41E35C5990A344ab87C1D53585EECFCC(0x%x)\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), F41E35C5990A344ab87C1D53585EECFCC );

	int k = 0;
	for( k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
	{
		if( pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] == NULL )
		{
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FD1CD603E47C14387BB6036D48A0561AC() k(%d) is empty\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), k );

			break;
		}
	}

	//never enter here, PCM will check if all substream are used, if yes, it will not issue "open" command
	if( k >= MAX_DEVICE_OPEN_NUM )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FD1CD603E47C14387BB6036D48A0561AC() no empty\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

		return -ENODEV;
	}

	F41E35C5990A344ab87C1D53585EECFCC->runtime->private_data = NULL;

	F41E35C5990A344ab87C1D53585EECFCC->runtime->private_free = NULL;

	#ifndef AME_PL330A
	if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x5864 )
	{
		F41E35C5990A344ab87C1D53585EECFCC->runtime->hw = FEAF4AC49BEDE45c48099A8E9544363A3_TW5864;
	}
	else if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x7160 )
	{
		if( (pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->subsystem_vendor & 0x10) == 0x10 && ENABLE_8CHS )
		{
			F41E35C5990A344ab87C1D53585EECFCC->runtime->hw = FEAF4AC49BEDE45c48099A8E9544363A3_SA7160_ENABLE_8CHS;
		}
		else
		{
			F41E35C5990A344ab87C1D53585EECFCC->runtime->hw = FEAF4AC49BEDE45c48099A8E9544363A3_SA7160;
		}
	}
	else if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
	{
		if( (pAudio->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x05) || (pAudio->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == (0x07) )
		{
			F41E35C5990A344ab87C1D53585EECFCC->runtime->hw = FEAF4AC49BEDE45c48099A8E9544363A3_FH8735;
		}
		else
		{
			F41E35C5990A344ab87C1D53585EECFCC->runtime->hw = FEAF4AC49BEDE45c48099A8E9544363A3_FH8735_SC3A0;
		}
	}
	else if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x8210 )
	{
		F41E35C5990A344ab87C1D53585EECFCC->runtime->hw = FEAF4AC49BEDE45c48099A8E9544363A3_CX2581;
	}
	else if( (pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

			(pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
		
			(pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0380) )
	{
		if( ((pAudio->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == 0x02) || ((pAudio->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0x0F) == 0x03) ) // 960H & D1
		{
			F41E35C5990A344ab87C1D53585EECFCC->runtime->hw = FEAF4AC49BEDE45c48099A8E9544363A3_MZ0380_SC3C0;
		}
		else
		{
			F41E35C5990A344ab87C1D53585EECFCC->runtime->hw = FEAF4AC49BEDE45c48099A8E9544363A3_MZ0380_SC5C0;
		}
	}
	else if( ((pAudio->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0xFF) == 0x23 && (pAudio->FB6E79A0780E64bb28A3308666E67881C->iManufacturer & 0xFF) == 0x03) ||  // SC300N1 AVS
			((pAudio->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0xFF) == 0x43 && (pAudio->FB6E79A0780E64bb28A3308666E67881C->iManufacturer & 0xFF) == 0x00) ||  // SC300N1 AVS
			((pAudio->FB6E79A0780E64bb28A3308666E67881C->iProduct & 0xFF) == 0xF3 && (pAudio->FB6E79A0780E64bb28A3308666E67881C->iManufacturer & 0xFF) == 0x00) ) { // SC300N1 AVS
	
		F41E35C5990A344ab87C1D53585EECFCC->runtime->hw = FEAF4AC49BEDE45c48099A8E9544363A3_SC300_SQUARE_PIXEL;
	}
	else if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 )
	{
		F41E35C5990A344ab87C1D53585EECFCC->runtime->hw = FEAF4AC49BEDE45c48099A8E9544363A3_PL330B;
	}
	else
	{
		F41E35C5990A344ab87C1D53585EECFCC->runtime->hw = FEAF4AC49BEDE45c48099A8E9544363A3;
	}
	#else
		F41E35C5990A344ab87C1D53585EECFCC->runtime->hw = FEAF4AC49BEDE45c48099A8E9544363A3_PL330B;
	#endif


	ret = snd_pcm_hw_constraint_integer( F41E35C5990A344ab87C1D53585EECFCC->runtime, SNDRV_PCM_HW_PARAM_PERIODS );

	if( ret < 0 ) { return ret; }

	//pAudio->F823E5E1F924443f8AD2BC9CBED4CE613 = F41E35C5990A344ab87C1D53585EECFCC;
	
	for( k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
	{
		if( pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] == NULL )
		{
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FD1CD603E47C14387BB6036D48A0561AC() open k(%d)\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), k );

			pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] = F41E35C5990A344ab87C1D53585EECFCC;
		
			break;
		}
	}

	return 0;
}

static int F60F0B859ED1E4629B7AEB0CA9D7F2B88( struct snd_pcm_substream * F41E35C5990A344ab87C1D53585EECFCC )
{
//	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(snd_pcm_substream_chip( F41E35C5990A344ab87C1D53585EECFCC ));

	FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio = (FE8EB18A4C9984f9789EFF7C05EE073A0 *)(F41E35C5990A344ab87C1D53585EECFCC->pcm->card->private_data);

	if( pAudio == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F60F0B859ED1E4629B7AEB0CA9D7F2B88() pAudio == NULL\n" );

		return 0;
	}
//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F60F0B859ED1E4629B7AEB0CA9D7F2B88()\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F60F0B859ED1E4629B7AEB0CA9D7F2B88() F41E35C5990A344ab87C1D53585EECFCC(%x)\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), F41E35C5990A344ab87C1D53585EECFCC );

	//pAudio->F823E5E1F924443f8AD2BC9CBED4CE613 = NULL;

	int k = 0;
	for( k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
	{
		if( F41E35C5990A344ab87C1D53585EECFCC == pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] )
		{
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F60F0B859ED1E4629B7AEB0CA9D7F2B88() close k(%d)\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), k );

			pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] = NULL;
		
			break;
		}
	}


	return 0;
}

static int F4C56246F2BE94db4BE8768BA7A9C5533( struct snd_pcm_substream * F41E35C5990A344ab87C1D53585EECFCC, struct snd_pcm_hw_params * p_hw_params )
{
//	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(snd_pcm_substream_chip( F41E35C5990A344ab87C1D53585EECFCC ));

	FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio = (FE8EB18A4C9984f9789EFF7C05EE073A0 *)(F41E35C5990A344ab87C1D53585EECFCC->pcm->card->private_data);

	if( pAudio == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F4C56246F2BE94db4BE8768BA7A9C5533() pAudio == NULL\n" );

		return 0;
	}
//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F4C56246F2BE94db4BE8768BA7A9C5533( PERIODS:%d BYTES/PERIOD:%d )\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), params_periods(p_hw_params), params_period_bytes(p_hw_params) );

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F4C56246F2BE94db4BE8768BA7A9C5533( PERIODS:%d BYTES/PERIOD:%d )\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), params_periods(p_hw_params), params_period_bytes(p_hw_params) );

	return snd_pcm_lib_malloc_pages( F41E35C5990A344ab87C1D53585EECFCC, params_buffer_bytes( p_hw_params ) );
}

static int F6525289DC9394f89A6A83BF3B47999D1( struct snd_pcm_substream * F41E35C5990A344ab87C1D53585EECFCC )
{
//	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(snd_pcm_substream_chip( F41E35C5990A344ab87C1D53585EECFCC ));

	FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio = (FE8EB18A4C9984f9789EFF7C05EE073A0 *)(F41E35C5990A344ab87C1D53585EECFCC->pcm->card->private_data);

	if( pAudio == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F6525289DC9394f89A6A83BF3B47999D1() pAudio == NULL\n" );

		return 0;
	}
//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F6525289DC9394f89A6A83BF3B47999D1()\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F6525289DC9394f89A6A83BF3B47999D1()\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	return snd_pcm_lib_free_pages( F41E35C5990A344ab87C1D53585EECFCC );
}

static int F4CDEFE2B56A34d09AA9D79A19C5CF6D0( struct snd_pcm_substream * F41E35C5990A344ab87C1D53585EECFCC )
{
//	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(snd_pcm_substream_chip( F41E35C5990A344ab87C1D53585EECFCC ));

	FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio = (FE8EB18A4C9984f9789EFF7C05EE073A0 *)(F41E35C5990A344ab87C1D53585EECFCC->pcm->card->private_data);

	if( pAudio == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F4CDEFE2B56A34d09AA9D79A19C5CF6D0() pAudio == NULL\n" );

		return 0;
	}
//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F4CDEFE2B56A34d09AA9D79A19C5CF6D0( R:%d C:%d F:%d PERIODS:%d BYTES/PERIOD:%d TOTAL:%d )\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), F41E35C5990A344ab87C1D53585EECFCC->runtime->rate, F41E35C5990A344ab87C1D53585EECFCC->runtime->channels, F41E35C5990A344ab87C1D53585EECFCC->runtime->sample_bits, F41E35C5990A344ab87C1D53585EECFCC->runtime->periods, (int)(F41E35C5990A344ab87C1D53585EECFCC->runtime->period_size) * (int)(F41E35C5990A344ab87C1D53585EECFCC->runtime->frame_bits) / (int)(8), (int)(F41E35C5990A344ab87C1D53585EECFCC->runtime->buffer_size) * (int)(F41E35C5990A344ab87C1D53585EECFCC->runtime->frame_bits) / (int)(8) );

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F4CDEFE2B56A34d09AA9D79A19C5CF6D0( R:%d C:%d F:%d PERIODS:%d BYTES/PERIOD:%d TOTAL:%d )\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), F41E35C5990A344ab87C1D53585EECFCC->runtime->rate, F41E35C5990A344ab87C1D53585EECFCC->runtime->channels, F41E35C5990A344ab87C1D53585EECFCC->runtime->sample_bits, F41E35C5990A344ab87C1D53585EECFCC->runtime->periods, (int)(F41E35C5990A344ab87C1D53585EECFCC->runtime->period_size) * (int)(F41E35C5990A344ab87C1D53585EECFCC->runtime->frame_bits) / (int)(8), (int)(F41E35C5990A344ab87C1D53585EECFCC->runtime->buffer_size) * (int)(F41E35C5990A344ab87C1D53585EECFCC->runtime->frame_bits) / (int)(8) );

	pAudio->FF322C2E8BB6F4f4799871C1E57B639DA = F41E35C5990A344ab87C1D53585EECFCC->runtime->rate;

	pAudio->F7C7B28D613E845b48C2F9701EFF42227 = F41E35C5990A344ab87C1D53585EECFCC->runtime->channels;

	pAudio->F4C4107B7DECC41588971B29ACD439A43 = F41E35C5990A344ab87C1D53585EECFCC->runtime->sample_bits;

	pAudio->F1461B75D9C644717A130B5C10D966CF0 = (int)(F41E35C5990A344ab87C1D53585EECFCC->runtime->period_size) * (int)(F41E35C5990A344ab87C1D53585EECFCC->runtime->frame_bits) / (int)(8);

	//pAudio->F6578ACFCB40E44819A12FD3E27A48085 = 0;
	int k = 0;
	for( k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
	{
		if( F41E35C5990A344ab87C1D53585EECFCC == pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] )
		{
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F4CDEFE2B56A34d09AA9D79A19C5CF6D0() k(%d)\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), k );

			pAudio->F6578ACFCB40E44819A12FD3E27A48085[ k ] = 0;

			pAudio->m_nFrameDMANumber[ k ] = 0;
		
			pAudio->m_audio_data_residue[ k ] = 0;

			break;
		}
	}

	pAudio->FD9C8A1F986EF488a8883B3CAD736747F = F41E35C5990A344ab87C1D53585EECFCC->runtime->periods;

//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "pAudio->FD9C8A1F986EF488a8883B3CAD736747F = %d \n", pAudio->FD9C8A1F986EF488a8883B3CAD736747F );

	return 0;
}

static int F3E0B683669C740f88340BEF43A17FAE5( struct snd_pcm_substream * F41E35C5990A344ab87C1D53585EECFCC, int cmd )
{
//	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(snd_pcm_substream_chip( F41E35C5990A344ab87C1D53585EECFCC ));

	FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio = (FE8EB18A4C9984f9789EFF7C05EE073A0 *)(F41E35C5990A344ab87C1D53585EECFCC->pcm->card->private_data);

	if( pAudio == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F3E0B683669C740f88340BEF43A17FAE5() pAudio == NULL\n" );

		return 0;
	}
//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F3E0B683669C740f88340BEF43A17FAE5( %08X )\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), cmd );

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F3E0B683669C740f88340BEF43A17FAE5( %08X ) F41E35C5990A344ab87C1D53585EECFCC(0x%x)\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), cmd, F41E35C5990A344ab87C1D53585EECFCC );
	
	int k = 0;
	for( k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
	{
		if( F41E35C5990A344ab87C1D53585EECFCC == pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] )
		{
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F3E0B683669C740f88340BEF43A17FAE5() k(%d)\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), k );
	
			break;
		}
	}
	
	//never enter here
	if( k >= MAX_DEVICE_OPEN_NUM )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F3E0B683669C740f88340BEF43A17FAE5() no audio device found\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

		return -ENODEV;
	}

	if( cmd == SNDRV_PCM_TRIGGER_START ) { //1

		unsigned long flags = 0x00000000;

		pAudio->F6578ACFCB40E44819A12FD3E27A48085[ k ] = 0;
		pAudio->m_nFrameDMANumber[ k ] = 0;
		pAudio->m_audio_data_residue[ k ] = 0;
		
		#ifndef AME_PL330A
		if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
		if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
		if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
		if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
		if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
		if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
		if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
		if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
		if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
		if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
		if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
		if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817 ) { if( FALSE == FD6A86F4A91BC4e3aACB97CF7067D5A0A( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
		#endif
	
		if( pAudio->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001 ) { pAudio->FB6E79A0780E64bb28A3308666E67881C->F13A906F1479D4245B9F207A09C70BCE6[ pAudio->F0DD7393CD1494e27A72652C7D1A97893 ] |= ( 1 << k ); }

		if( pAudio->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002 ) { pAudio->FB6E79A0780E64bb28A3308666E67881C->FC1FFB6B00E034c0993BE8A598C730AA4[ pAudio->F0DD7393CD1494e27A72652C7D1A97893 ] = 0x00000001; }

	}
	if( cmd == SNDRV_PCM_TRIGGER_STOP ) { //0

		unsigned long flags = 0x00000000;

		if( pAudio->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001 ) { pAudio->FB6E79A0780E64bb28A3308666E67881C->F13A906F1479D4245B9F207A09C70BCE6[ pAudio->F0DD7393CD1494e27A72652C7D1A97893 ] &= ~( 1 << k ); }

		if( pAudio->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002 ) { pAudio->FB6E79A0780E64bb28A3308666E67881C->FC1FFB6B00E034c0993BE8A598C730AA4[ pAudio->F0DD7393CD1494e27A72652C7D1A97893 ] = 0x00000000; }

		if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F13A906F1479D4245B9F207A09C70BCE6[ pAudio->F0DD7393CD1494e27A72652C7D1A97893 ] == 0x00000000 )
		{
			#ifndef AME_PL330A
			if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6801 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
			if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
			if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6804 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
			if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
			if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6810 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
			if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6811 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
			if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6812 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
			if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6813 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
			if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
			if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
			if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
			if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817 ) { if( FALSE == FF2DCC6B39AEC4347A6B796D58B481AE0( pAudio->FB6E79A0780E64bb28A3308666E67881C, NULL, pAudio ) ) { ; } }
			#endif
		}
		pAudio->F6578ACFCB40E44819A12FD3E27A48085[ k ] = 0;
		pAudio->m_nFrameDMANumber[ k ] = 0;
		pAudio->m_audio_data_residue[ k ] = 0;

	}
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F3E0B683669C740f88340BEF43A17FAE5() end, pAudio(0x%x) F13A906F1479D4245B9F207A09C70BCE6(0x%x)\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), pAudio, pAudio->FB6E79A0780E64bb28A3308666E67881C->F13A906F1479D4245B9F207A09C70BCE6[ pAudio->F0DD7393CD1494e27A72652C7D1A97893 ] );

	return 0;
}

static snd_pcm_uframes_t F288016094808405fA40919514F2E4114( struct snd_pcm_substream * F41E35C5990A344ab87C1D53585EECFCC )
{
//	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(snd_pcm_substream_chip( F41E35C5990A344ab87C1D53585EECFCC ));

	FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio = (FE8EB18A4C9984f9789EFF7C05EE073A0 *)(F41E35C5990A344ab87C1D53585EECFCC->pcm->card->private_data);

	if( pAudio == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F288016094808405fA40919514F2E4114() pAudio == NULL\n" );

		return 0;
	}
//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F288016094808405fA40919514F2E4114( %d )\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (int)(pAudio->F6578ACFCB40E44819A12FD3E27A48085) );

//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F288016094808405fA40919514F2E4114( %d )\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), (int)(pAudio->F6578ACFCB40E44819A12FD3E27A48085) );

	int k = 0;
	for( k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
	{
		if( F41E35C5990A344ab87C1D53585EECFCC == pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] )
		{
			//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F288016094808405fA40919514F2E4114() k(%d)\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), k );
	
			break;
		}
	}

	return bytes_to_frames( F41E35C5990A344ab87C1D53585EECFCC->runtime, (pAudio->F6578ACFCB40E44819A12FD3E27A48085[ k ]) * (pAudio->F1461B75D9C644717A130B5C10D966CF0) );
}

static int F610D5F7D4CF6401bB7731B627A42CA8A( struct snd_kcontrol * F04E034030A5B43c3BD4AAB3057666A39, struct snd_ctl_elem_info * FB9478A2460F34931B3461172D5275F1E )
{
	FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio = (FE8EB18A4C9984f9789EFF7C05EE073A0 *)(snd_kcontrol_chip( F04E034030A5B43c3BD4AAB3057666A39 ));

	if( pAudio == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F610D5F7D4CF6401bB7731B627A42CA8A() pAudio == NULL\n" );

		return 0;
	}
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F610D5F7D4CF6401bB7731B627A42CA8A()\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	FB9478A2460F34931B3461172D5275F1E->type = SNDRV_CTL_ELEM_TYPE_INTEGER;

	FB9478A2460F34931B3461172D5275F1E->count = 1;

	FB9478A2460F34931B3461172D5275F1E->value.integer.min = 0;

	FB9478A2460F34931B3461172D5275F1E->value.integer.max = 255;

	//this function will be called at booting time by alsa
	pAudio->FB6E79A0780E64bb28A3308666E67881C->possible_booting = 1;

	return 0;
}

static int F6FA3AF8CA60D42f4AE4A40E78BE032B8( struct snd_kcontrol * F04E034030A5B43c3BD4AAB3057666A39, struct snd_ctl_elem_value * p_value )
{
	FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio = (FE8EB18A4C9984f9789EFF7C05EE073A0 *)(snd_kcontrol_chip( F04E034030A5B43c3BD4AAB3057666A39 ));

	if( pAudio == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F6FA3AF8CA60D42f4AE4A40E78BE032B8() pAudio == NULL\n" );

		return 0;
	}
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F6FA3AF8CA60D42f4AE4A40E78BE032B8()\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	#ifndef AME_PL330A
	if( (pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802) ||
		(pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805) ||
		(pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814) ||
		(pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815) ||
		(pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816) ||
		(pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817) ) {
	
		ULONG R00000048 = 0x00000000;

		R00000048 = TW6802_GetRegister( pAudio->FB6E79A0780E64bb28A3308666E67881C, 0x00000048, 4 ) & 0x0000003F;

		p_value->value.integer.value[ 0 ] = pAudio->FD7636E89EEE544eb849076B30F06638F = R00000048 << 2;
	}
	if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
	{
		p_value->value.integer.value[ 0 ] = pAudio->FD7636E89EEE544eb849076B30F06638F;
	}
	#endif

	return 0;
}

static int F14A737D3699C4edfB41D3701838B2D5F( struct snd_kcontrol * F04E034030A5B43c3BD4AAB3057666A39, struct snd_ctl_elem_value * p_value )
{
	FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio = (FE8EB18A4C9984f9789EFF7C05EE073A0 *)(snd_kcontrol_chip( F04E034030A5B43c3BD4AAB3057666A39 ));

	if( pAudio == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F14A737D3699C4edfB41D3701838B2D5F() pAudio == NULL\n" );

		return 0;
	}
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F14A737D3699C4edfB41D3701838B2D5F( %d )\n", (int)(pAudio->FB6E79A0780E64bb28A3308666E67881C->F0C7DF8CDF1004a6eB97071CBDF459ECE), (int)(p_value->value.integer.value[ 0 ]) );

	pAudio->FD7636E89EEE544eb849076B30F06638F = p_value->value.integer.value[ 0 ]; 

	if( pAudio->FD7636E89EEE544eb849076B30F06638F > 255 ) { pAudio->FD7636E89EEE544eb849076B30F06638F = 255; }

	if( pAudio->FD7636E89EEE544eb849076B30F06638F <   0 ) { pAudio->FD7636E89EEE544eb849076B30F06638F =   0; }

	#ifndef AME_PL330A
	if( (pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6802) ||
		(pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6805) ||
		(pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6814) ||
		(pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6815) ||
		(pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6816) ||
		(pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x6817) ){
	
		ULONG R00000048 = 0x00000000;

		R00000048 = TW6802_GetRegister( pAudio->FB6E79A0780E64bb28A3308666E67881C, 0x00000048, 4 ) & 0xFFFFFFC0;
		
		TW6802_SetRegister( pAudio->FB6E79A0780E64bb28A3308666E67881C, 0x00000048, R00000048 | (pAudio->FD7636E89EEE544eb849076B30F06638F >> 2), 4 );
	}

	if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0x0101 )
	{
		FH8735_SetAnalogAudioVoulmeProperty( pAudio->FB6E79A0780E64bb28A3308666E67881C, pAudio->FD7636E89EEE544eb849076B30F06638F, pAudio->F0DD7393CD1494e27A72652C7D1A97893);
	}

	if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->vendor == 0x1AF2 && pAudio->FB6E79A0780E64bb28A3308666E67881C->F9D9594A095F0463193B7588374CF8310->device == 0xA001 )
	{
		C03EDD59F4A64C2084BB2C70FC794214( pAudio->FB6E79A0780E64bb28A3308666E67881C, pAudio->FD7636E89EEE544eb849076B30F06638F, FALSE);
	}
	#endif

	return 0;
}
// ##############################################################################################################################################################################
// 
MODULE_DEVICE_TABLE( pci, FA7B99DBE9A7D4ff88FF7526CEDB7C5AA );
#ifdef AME_PL330A
MODULE_DEVICE_TABLE( usb, LINUXV4L2_USB_DEVICE_ID_TABLE );
#endif
MODULE_AUTHOR( "Linux V4L2" );

MODULE_DESCRIPTION( "Linux V4L2 Device Driver" );

MODULE_LICENSE( "GPL" );

MODULE_VERSION( LXV4L2D_VER );

unsigned int g_dw_common_command_param = 0x00000000;

module_param_named( command, g_dw_common_command_param, uint, 0 );

module_init( FAF86DD63BEE049469391C62866E9E0BB );

module_exit( FFEAB2309379F4a9fA0EB36080145582B );

