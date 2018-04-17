#include "LINUXV4L2.h"
#include "property.h"
#include "wrapper.h"
#include "pl330b.h"
#include "mst3367.h"
#include "tlv320adc3101.h"
#include "it1412.h"


#define PL330B_MAX_H264_SIZE ((960 * 1080 * 12) >> 3)

volatile ULONG g_n_debug_instances = 0;

extern void RtlCopyMemory( BYTE* pe, BYTE* po, int nFileSize );

extern struct snd_pcm_hardware FEAF4AC49BEDE45c48099A8E9544363A3_PL330B;

extern BOOLEAN update_video_time_stamp( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, F170997530C6943659ECE8DEC21301F66 * pVideoBuffer );

extern BYTE* colorbar_image_1920_1080;
extern BYTE* colorbar_image_1280_720;
extern BYTE* colorbar_image_720_576;

extern F42A18AF66EFF459eA332CA253FFF8A65 * g_pDevice[ 128 ];

typedef struct _UINT128 {

  ULONGLONG lower;

  ULONGLONG upper;

} UINT128;

int resampleAudioBuffer2(unsigned char *inBuf, int inBufLength, unsigned char *outBuf, int outBufLength)
{
	int inSampleSize = inBufLength/4;
	int outSampleSize = outBufLength/4;

//	double inPitch = outSampleSize - 1;
//	double outPitch = inSampleSize - 1;

	int inPitch = outSampleSize - 1;
	int outPitch = inSampleSize - 1;

	short *inBufPtrL = (short*)inBuf;
	short *inBufPtrR = (short*)(inBuf+2);

	short *outBufPtrL = (short*)outBuf;
	short *outBufPtrR = (short*)(outBuf+2);

	int inPositionLow = 0;
	int inPositionHigh = inPitch;
	int outPosition = 0;
	int outIndex = 0;
	int inIndex = 0;
	while(1)
	{
		if((outPosition>=inPositionLow)&&((outPosition<inPositionHigh)))
		{
			outBufPtrL[outIndex*2] = inBufPtrL[inIndex*2];
			outBufPtrR[outIndex*2] = inBufPtrR[inIndex*2];
			outIndex++;
			if(outIndex>=outSampleSize)
			{
				break;
			}
			else
			{
				outPosition += outPitch;
				continue;
			}
		}
		else
		{
			inIndex++;
			inPositionLow += inPitch;
			inPositionHigh += inPitch;
		}
	}
	return outSampleSize*4;
}



ULONG PL330B_GetRegister( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F919EED126B2940ce99A1F7F66A333338, ULONG F0FAB4549F1C3407aACDBD483D0D23C86, ULONG F02179B6B95CB43eeB160478D8CF83778 )
{
	return 0x00000000;
}

BOOLEAN PL330B_SetRegister( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F919EED126B2940ce99A1F7F66A333338, ULONG F0FAB4549F1C3407aACDBD483D0D23C86, ULONG F09894BF114FE4ee592C232BC39730E91, ULONG F02179B6B95CB43eeB160478D8CF83778 )
{
	return TRUE;
}
extern BOOLEAN F6B9E557A4BA24ffd926B820B836289C8_100NS( ULONG F6B9E557A4BA24ffd926B820B836289C8 );
extern void RtlFillMemory(BYTE* pe , int size, BYTE set_value);
extern void RtlZeroMemory(BYTE* pe , int size);

BOOLEAN PL330B_F6B9E557A4BA24ffd926B820B836289C8_100NS( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	//wrapper_ndelay( F6B9E557A4BA24ffd926B820B836289C8 * 100 );

	schedule_timeout_interruptible( msecs_to_jiffies( F6B9E557A4BA24ffd926B820B836289C8/10000 ) );

	return TRUE;
}
BYTE C6F39DAE1CE54F0D873113FD657C7FA3( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE nBank, BYTE F6B106280018F45d7A077070B88512C77 )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	if( pDevice->m_pCodecLib == QP_NULL ) { return 0x00; }

	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	QPCODEC_DIAG_I2C_STRUCT s_i2c_bank;

	QPCODEC_DIAG_I2C_WRITE_THEN_READ_STRUCT s_i2c_get;

	EQP_Errors qp_status = QPERR_SUCCESS;

	DWORD size_bank = sizeof(QPCODEC_DIAG_I2C_STRUCT);

	DWORD size_get = sizeof(QPCODEC_DIAG_I2C_WRITE_THEN_READ_STRUCT);

	s_i2c_bank.chip_address = F3E85D87 >> 1;

	s_i2c_bank.num_bytes = 2;

	s_i2c_bank.bytes[ 0 ] = 0x00;

	s_i2c_bank.bytes[ 1 ] = nBank;

	s_i2c_get.chip_address = F3E85D87 >> 1;

	s_i2c_get.num_write_bytes = 1;

	s_i2c_get.write_bytes[ 0 ] = F6B106280018F45d7A077070B88512C77;

	s_i2c_get.num_read_bytes = 1;

	s_i2c_get.read_bytes[ 0 ] = 0x00;

	if( p_sys_cfg->n_mst3367_register_bank != nBank ) {

		p_sys_cfg->n_mst3367_register_bank = nBank;

		qp_status = pDevice->m_pCodecLib->Set( pDevice->m_pCodecLib, 
	
											  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),
	
											   TQP_NULL_HANDLE,
	
											   QPCODEC_DIAG_I2C_WRITE,
	
											  (TQP_PVOID)(&s_i2c_bank),
	
											   QP_NULL,
	
											   sizeof(QPCODEC_DIAG_I2C_STRUCT) );
	}
	if( QP_SUCCESS(qp_status) == FALSE ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_GetAnalogVideoDecoderRegister( 1 ): GET REGISTER %02X.%02X ERROR!!\n", nBank, F6B106280018F45d7A077070B88512C77); return 0x00; }

	qp_status = pDevice->m_pCodecLib->Get( pDevice->m_pCodecLib, 

										  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

										   TQP_NULL_HANDLE,

										   QPCODEC_DIAG_I2C_WRITE_THEN_READ,

										  (TQP_PVOID)(&s_i2c_get),

										  (TQP_PVOID)(&s_i2c_get),

										  (PTQP_UINT32)(&size_get) );

	if( QP_SUCCESS(qp_status) == FALSE ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_GetAnalogVideoDecoderRegister( 2 ): GET REGISTER %02X.%02X ERROR!!\n", nBank, F6B106280018F45d7A077070B88512C77); return 0x00; }

	return s_i2c_get.read_bytes[ 0 ];
#endif
	return 0x00;
}

BOOLEAN F3442C8F4E5244B4852C27C401ED415E( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE nBank, BYTE F6B106280018F45d7A077070B88512C77, BYTE bValue )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	if( pDevice->m_pCodecLib == QP_NULL ) { return FALSE; }

	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	QPCODEC_DIAG_I2C_STRUCT s_i2c_bank;

	QPCODEC_DIAG_I2C_STRUCT s_i2c_set;

	EQP_Errors qp_status = QPERR_SUCCESS;

	s_i2c_bank.chip_address = F3E85D87 >> 1;

	s_i2c_bank.num_bytes = 2;

	s_i2c_bank.bytes[ 0 ] = 0x00;

	s_i2c_bank.bytes[ 1 ] = nBank;

	s_i2c_set.chip_address = F3E85D87 >> 1;

	s_i2c_set.num_bytes = 2;

	s_i2c_set.bytes[ 0 ] = F6B106280018F45d7A077070B88512C77;

	s_i2c_set.bytes[ 1 ] = bValue;

	if( p_sys_cfg->n_mst3367_register_bank != nBank ) {

		p_sys_cfg->n_mst3367_register_bank = nBank;

		qp_status = pDevice->m_pCodecLib->Set( pDevice->m_pCodecLib, 
	
											  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),
	
											   TQP_NULL_HANDLE,
	
											   QPCODEC_DIAG_I2C_WRITE,
	
											  (TQP_PVOID)(&s_i2c_bank),
	
											   QP_NULL,
	
											   sizeof(QPCODEC_DIAG_I2C_STRUCT) );
	}
	if( QP_SUCCESS(qp_status) == FALSE ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_SetAnalogVideoDecoderRegister( 1 ): SET REGISTER %02X.%02X ERROR!!\n", nBank, F6B106280018F45d7A077070B88512C77); return FALSE; }

	qp_status = pDevice->m_pCodecLib->Set( pDevice->m_pCodecLib, 

										  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

										   TQP_NULL_HANDLE,

										   QPCODEC_DIAG_I2C_WRITE,

										  (TQP_PVOID)(&s_i2c_set),

										   QP_NULL,

										   sizeof(QPCODEC_DIAG_I2C_STRUCT) );

	if( QP_SUCCESS(qp_status) == FALSE ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_SetAnalogVideoDecoderRegister( 2 ): SET REGISTER %02X.%02X ERROR!!\n", nBank, F6B106280018F45d7A077070B88512C77); return FALSE; }

	return QP_SUCCESS(qp_status);
#endif
	return FALSE;
}

BYTE DD0D84BB34264335874009D864B98B9C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77 )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	if( pDevice->m_pCodecLib == QP_NULL ) { return 0x00; }

	QPCODEC_DIAG_I2C_WRITE_THEN_READ_STRUCT s_i2c_get;

	EQP_Errors qp_status = QPERR_SUCCESS;

	DWORD size_get = sizeof(QPCODEC_DIAG_I2C_WRITE_THEN_READ_STRUCT);

	s_i2c_get.chip_address = F3E85D87 >> 1;

	s_i2c_get.num_write_bytes = 1;

	s_i2c_get.write_bytes[ 0 ] = F6B106280018F45d7A077070B88512C77;

	s_i2c_get.num_read_bytes = 1;

	s_i2c_get.read_bytes[ 0 ] = 0x00;

	qp_status = pDevice->m_pCodecLib->Get( pDevice->m_pCodecLib, 

										  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

										   TQP_NULL_HANDLE,

										   QPCODEC_DIAG_I2C_WRITE_THEN_READ,

										  (TQP_PVOID)(&s_i2c_get),

										  (TQP_PVOID)(&s_i2c_get),

										  (PTQP_UINT32)(&size_get) );

	if( QP_SUCCESS(qp_status) == FALSE ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "DD0D84BB34264335874009D864B98B9C( 1 ): GET REGISTER %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77); return 0x00; }

	return s_i2c_get.read_bytes[ 0 ];

	#endif

	return 0x00;
}

BYTE DD0D84BB34264335874009D864B98B9CEx( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BOOL * p_returns  )
{
#if defined(AME_PL330B) || defined(AME_PL330A)

	if( pDevice->m_pCodecLib == QP_NULL ) { return 0x0000; }

	{	QPCODEC_DIAG_I2C_STRUCT s_i2c_set;

		EQP_Errors qp_status = QPERR_SUCCESS;

		s_i2c_set.chip_address = F3E85D87 >> 1;

		s_i2c_set.num_bytes = 1;

		s_i2c_set.bytes[ 0 ] = F6B106280018F45d7A077070B88512C77;

		qp_status = pDevice->m_pCodecLib->Set( pDevice->m_pCodecLib, 

											  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

											   TQP_NULL_HANDLE,

											   QPCODEC_DIAG_I2C_WRITE,

											  (TQP_PVOID)(&s_i2c_set),

											   QP_NULL,

											   sizeof(QPCODEC_DIAG_I2C_STRUCT) );

		if( QP_SUCCESS(qp_status) == FALSE ) { 
			
			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_GetMcuRegister( 1 ): GET REGISTER %04X ERROR!!\n", F6B106280018F45d7A077070B88512C77); 
		
			if( p_returns ) { *p_returns = FALSE; }
			
			return 0x0000; 
		}
	}
	F6B9E557A4BA24ffd926B820B836289C8_100NS( 10000 );

	{	QPCODEC_DIAG_I2C_STRUCT s_i2c_get;

		EQP_Errors qp_status = QPERR_SUCCESS;

		DWORD size_get = sizeof(QPCODEC_DIAG_I2C_STRUCT);

		s_i2c_get.chip_address = F3E85D87 >> 1;

		s_i2c_get.num_bytes = 1;

		s_i2c_get.bytes[ 0 ] = 0x00;

		qp_status = pDevice->m_pCodecLib->Get( pDevice->m_pCodecLib, 

											  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

											   TQP_NULL_HANDLE,

											   QPCODEC_DIAG_I2C_READ,

											  (TQP_PVOID)(&s_i2c_get),

											  (TQP_PVOID)(&s_i2c_get),

											  (PTQP_UINT32)(&size_get) );

		if( QP_SUCCESS(qp_status) == FALSE ) { 
			
			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_GetMcuRegister( 2 ): GET REGISTER %04X ERROR!!\n", F6B106280018F45d7A077070B88512C77); 
		
			if( p_returns ) { *p_returns = FALSE; } 
			
			return 0x0000; 
		}
		BYTE R = s_i2c_get.bytes[ 0 ];

		if( p_returns ) { *p_returns = TRUE; }

		return R;
	}
	#endif

	if( p_returns ) { *p_returns = FALSE; }

	return 0x0000;
}

BOOLEAN E057E022AA684160B92E903D99235927( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE bValue )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	if( pDevice->m_pCodecLib == QP_NULL ) { return FALSE; }

	QPCODEC_DIAG_I2C_STRUCT s_i2c_set;

	EQP_Errors qp_status = QPERR_SUCCESS;

	s_i2c_set.chip_address = F3E85D87 >> 1;

	s_i2c_set.num_bytes = 2;

	s_i2c_set.bytes[ 0 ] = F6B106280018F45d7A077070B88512C77;

	s_i2c_set.bytes[ 1 ] = bValue;

	qp_status = pDevice->m_pCodecLib->Set( pDevice->m_pCodecLib, 

										  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

										   TQP_NULL_HANDLE,

										   QPCODEC_DIAG_I2C_WRITE,

										  (TQP_PVOID)(&s_i2c_set),

										   QP_NULL,

										   sizeof(QPCODEC_DIAG_I2C_STRUCT) );

	if( QP_SUCCESS(qp_status) == FALSE ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "E057E022AA684160B92E903D99235927( 1 ): SET REGISTER %02X.%02X ERROR!!\n", F6B106280018F45d7A077070B88512C77, bValue); return FALSE; }

	return QP_SUCCESS(qp_status);

	#endif

	return FALSE;
}

BYTE F7B4503FC4AA4710AEC20FC4C587ACB8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77 )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	if( pDevice->m_pCodecLib == QP_NULL ) { return 0x00; }

	QPCODEC_DIAG_I2C_WRITE_THEN_READ_STRUCT s_i2c_get;

	EQP_Errors qp_status = QPERR_SUCCESS;

	DWORD size_get = sizeof(QPCODEC_DIAG_I2C_WRITE_THEN_READ_STRUCT);

	s_i2c_get.chip_address = F3E85D87 >> 1;

	s_i2c_get.num_write_bytes = 1;

	s_i2c_get.write_bytes[ 0 ] = F6B106280018F45d7A077070B88512C77;

	s_i2c_get.num_read_bytes = 1;

	s_i2c_get.read_bytes[ 0 ] = 0x00;

	qp_status = pDevice->m_pCodecLib->Get( pDevice->m_pCodecLib, 

										  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

										   TQP_NULL_HANDLE,

										   QPCODEC_DIAG_I2C_WRITE_THEN_READ,

										  (TQP_PVOID)(&s_i2c_get),

										  (TQP_PVOID)(&s_i2c_get),

										  (PTQP_UINT32)(&size_get) );

	if( QP_SUCCESS(qp_status) == FALSE ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_GetAnalogVideoDecoderRegister( 1 ): GET REGISTER %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77); return 0x00; }

	return s_i2c_get.read_bytes[ 0 ];

	#endif

	return 0x00;
}

BOOLEAN FC5FCF2C4E50436EA8A2A8C98E4C1AC2( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE bValue )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	if( pDevice->m_pCodecLib == QP_NULL ) { return FALSE; }

	QPCODEC_DIAG_I2C_STRUCT s_i2c_set;

	EQP_Errors qp_status = QPERR_SUCCESS;

	s_i2c_set.chip_address = F3E85D87 >> 1;

	s_i2c_set.num_bytes = 2;

	s_i2c_set.bytes[ 0 ] = F6B106280018F45d7A077070B88512C77;

	s_i2c_set.bytes[ 1 ] = bValue;

	qp_status = pDevice->m_pCodecLib->Set( pDevice->m_pCodecLib, 

										  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

										   TQP_NULL_HANDLE,

										   QPCODEC_DIAG_I2C_WRITE,

										  (TQP_PVOID)(&s_i2c_set),

										   QP_NULL,

										   sizeof(QPCODEC_DIAG_I2C_STRUCT) );

	if( QP_SUCCESS(qp_status) == FALSE ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "FC5FCF2C4E50436EA8A2A8C98E4C1AC2( 1 ): SET REGISTER %02X.%02X ERROR!!\n", F6B106280018F45d7A077070B88512C77, bValue); return FALSE; }

	return QP_SUCCESS(qp_status);

	#endif

	return FALSE;
}

BYTE FD553E100FEF42A09291CAE5868EE78F( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex )
{
	return DD0D84BB34264335874009D864B98B9C( pDevice, 0x00, 0x90, nIndex );
}

BOOLEAN FC8E5418A20E4E708DA4529778160F9B( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, BYTE bValue )
{
	return E057E022AA684160B92E903D99235927( pDevice, 0x00, 0x90, nIndex, bValue );
}

BOOL D81BC288B4DA4C9F969C93D4AFA639EA( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, ULONG bBytes, BYTE * pValue ) 
{
	ULONG i = 0;
	for( i = 0 ; i < bBytes ; i++ ) {

		pValue[ i ] = DD0D84BB34264335874009D864B98B9C( pDevice, 0x00, 0x90, (BYTE)(nIndex + i) );
	}
	return TRUE;
}

BOOLEAN FFD1BB8E56E243D3AC39C9882F27BD4F( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, ULONG bBytes, BYTE * pValue )
{
	ULONG i = 0;
	for( i = 0 ; i < bBytes ; i++ ) { 

		E057E022AA684160B92E903D99235927( pDevice, 0x00, 0x90, (BYTE)(nIndex + i), pValue[ i ] );
	}
	return TRUE;
}

USHORT C00DF1D7428943A5A947C729729E597F( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, USHORT wIndex, BOOLEAN* p_returns )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	if( pDevice->m_pCodecLib == QP_NULL ) { return 0x0000; }

	{	QPCODEC_DIAG_I2C_STRUCT s_i2c_set;

		EQP_Errors qp_status = QPERR_SUCCESS;

		s_i2c_set.chip_address = F3E85D87 >> 1;

		s_i2c_set.num_bytes = 4;

		s_i2c_set.bytes[ 0 ] = 0x27;

		s_i2c_set.bytes[ 1 ] = 0x02;

		s_i2c_set.bytes[ 2 ] = ((wIndex & 0x00FF) >> 0);

		s_i2c_set.bytes[ 3 ] = ((wIndex & 0xFF00) >> 8);

		qp_status = pDevice->m_pCodecLib->Set( pDevice->m_pCodecLib, 

											  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

											   TQP_NULL_HANDLE,

											   QPCODEC_DIAG_I2C_WRITE,

											  (TQP_PVOID)(&s_i2c_set),

											   QP_NULL,

											   sizeof(QPCODEC_DIAG_I2C_STRUCT) );

		if( QP_SUCCESS(qp_status) == FALSE ) { 
			
			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_GetMcuRegister( 1 ): GET REGISTER %04X ERROR!!\n", wIndex); 
		
			if( p_returns ) { *p_returns = FALSE; }
			
			return 0x0000; 
		}
	}
	F6B9E557A4BA24ffd926B820B836289C8_100NS( 10000 );

	{	QPCODEC_DIAG_I2C_STRUCT s_i2c_get;

		EQP_Errors qp_status = QPERR_SUCCESS;

		DWORD size_get = sizeof(QPCODEC_DIAG_I2C_STRUCT);

		s_i2c_get.chip_address = F3E85D87 >> 1;

		s_i2c_get.num_bytes = 3;

		s_i2c_get.bytes[ 0 ] = 0x00;

		s_i2c_get.bytes[ 1 ] = 0x00;

		s_i2c_get.bytes[ 2 ] = 0x00;

		qp_status = pDevice->m_pCodecLib->Get( pDevice->m_pCodecLib, 

											  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

											   TQP_NULL_HANDLE,

											   QPCODEC_DIAG_I2C_READ,

											  (TQP_PVOID)(&s_i2c_get),

											  (TQP_PVOID)(&s_i2c_get),

											  (PTQP_UINT32)(&size_get) );

		if( QP_SUCCESS(qp_status) == FALSE ) { 
			
			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_GetMcuRegister( 2 ): GET REGISTER %04X ERROR!!\n", wIndex); 
		
			if( p_returns ) { *p_returns = FALSE; } 
			
			return 0x0000; 
		}
		USHORT R = s_i2c_get.bytes[ 1 ];

		R <<= 8;

		R |= s_i2c_get.bytes[ 0 ];

		if( p_returns ) { *p_returns = TRUE; }

		return R;
	}
	#endif

	if( p_returns ) { *p_returns = FALSE; }

	return 0x0000;
}

USHORT C12B7BD9B5134F53981EE3E7702A7E44( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, USHORT wIndex )
{
#if defined(AME_PL330B) || defined(AME_PL330A)

	{	QPCODEC_DIAG_I2C_STRUCT s_i2c_set;

		EQP_Errors qp_status = QPERR_SUCCESS;

		s_i2c_set.chip_address = F3E85D87 >> 1;

		s_i2c_set.num_bytes = 4;

		s_i2c_set.bytes[ 0 ] = 0x27;

		s_i2c_set.bytes[ 1 ] = 0x02;

		s_i2c_set.bytes[ 2 ] = ((wIndex & 0x00FF) >> 0);

		s_i2c_set.bytes[ 3 ] = ((wIndex & 0xFF00) >> 8);

		qp_status = pDevice->m_pCodecLib->Set( pDevice->m_pCodecLib, 

											  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

											   TQP_NULL_HANDLE,

											   QPCODEC_DIAG_I2C_WRITE,

											  (TQP_PVOID)(&s_i2c_set),

											   QP_NULL,

											   sizeof(QPCODEC_DIAG_I2C_STRUCT) );

		if( QP_SUCCESS(qp_status) == FALSE ) { 
			
			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_GetMcuRegister( 1 ): GET REGISTER %04X ERROR!!\n", wIndex); 
		
			//if( p_returns ) { *p_returns = FALSE; }
			
			return 0x0000; 
		}
	}
	F6B9E557A4BA24ffd926B820B836289C8_100NS( 10000 );

	{	QPCODEC_DIAG_I2C_STRUCT s_i2c_get;

		EQP_Errors qp_status = QPERR_SUCCESS;

		DWORD size_get = sizeof(QPCODEC_DIAG_I2C_STRUCT);

		s_i2c_get.chip_address = F3E85D87 >> 1;

		s_i2c_get.num_bytes = 3;

		s_i2c_get.bytes[ 0 ] = 0x00;

		s_i2c_get.bytes[ 1 ] = 0x00;

		s_i2c_get.bytes[ 2 ] = 0x00;

		qp_status = pDevice->m_pCodecLib->Get( pDevice->m_pCodecLib, 

											  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

											   TQP_NULL_HANDLE,

											   QPCODEC_DIAG_I2C_READ,

											  (TQP_PVOID)(&s_i2c_get),

											  (TQP_PVOID)(&s_i2c_get),

											  (PTQP_UINT32)(&size_get) );

		if( QP_SUCCESS(qp_status) == FALSE ) { 
			
			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_GetMcuRegister( 2 ): GET REGISTER %04X ERROR!!\n", wIndex); 
		
			//if( p_returns ) { *p_returns = FALSE; } 
			
			return 0x0000; 
		}
		USHORT R = s_i2c_get.bytes[ 1 ];

		R <<= 8;

		R |= s_i2c_get.bytes[ 0 ];

		//if( p_returns ) { *p_returns = TRUE; }

		return R;
	}
#endif

	//if( p_returns ) { *p_returns = FALSE; }

	return 0x0000;
}

BOOLEAN F163E0DBD4F44FD18730544917C904D1( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, USHORT wIndex, USHORT wValue )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	if( pDevice->m_pCodecLib == QP_NULL ) { return FALSE; }

	QPCODEC_DIAG_I2C_STRUCT s_i2c_set;

	EQP_Errors qp_status = QPERR_SUCCESS;

	s_i2c_set.chip_address = F3E85D87 >> 1;

	s_i2c_set.num_bytes = 5;

	s_i2c_set.bytes[ 0 ] = 0x26;

	s_i2c_set.bytes[ 1 ] = ((wIndex & 0x00FF) >> 0);

	s_i2c_set.bytes[ 2 ] = ((wIndex & 0xFF00) >> 8);

	s_i2c_set.bytes[ 3 ] = ((wValue & 0x00FF) >> 0);

	s_i2c_set.bytes[ 4 ] = ((wValue & 0xFF00) >> 8);

	qp_status = pDevice->m_pCodecLib->Set( pDevice->m_pCodecLib, 

										  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

										   TQP_NULL_HANDLE,

										   QPCODEC_DIAG_I2C_WRITE,

										  (TQP_PVOID)(&s_i2c_set),

										   QP_NULL,

										   sizeof(QPCODEC_DIAG_I2C_STRUCT) );

	if( QP_SUCCESS(qp_status) == FALSE ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_SetMcuRegister( 1 ): SET REGISTER %04X.%04X ERROR!!\n", wIndex, wValue); return FALSE; }

	return QP_SUCCESS(qp_status);

	#endif

	return FALSE;
}

DWORD F9EAF79B03A148CA8238A894135B8327( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77 )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	if( pDevice->m_pCodecLib == QP_NULL ) { return 0x00000000; }

	QPCODEC_DIAG_I2C_WRITE_THEN_READ_STRUCT s_i2c_get;

	EQP_Errors qp_status = QPERR_SUCCESS;

	DWORD size_get = sizeof(QPCODEC_DIAG_I2C_WRITE_THEN_READ_STRUCT);

	s_i2c_get.chip_address = F3E85D87 >> 1;

	s_i2c_get.num_write_bytes = 1;

	s_i2c_get.write_bytes[ 0 ] = F6B106280018F45d7A077070B88512C77;

	s_i2c_get.num_read_bytes = 4;

	s_i2c_get.read_bytes[ 0 ] = 0x00;

	s_i2c_get.read_bytes[ 1 ] = 0x00;

	s_i2c_get.read_bytes[ 2 ] = 0x00;

	s_i2c_get.read_bytes[ 3 ] = 0x00;

	qp_status = pDevice->m_pCodecLib->Get( pDevice->m_pCodecLib, 

										  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

										   TQP_NULL_HANDLE,

										   QPCODEC_DIAG_I2C_WRITE_THEN_READ,

										  (TQP_PVOID)(&s_i2c_get),

										  (TQP_PVOID)(&s_i2c_get),

										  (PTQP_UINT32)(&size_get) );

	if( QP_SUCCESS(qp_status) == FALSE ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_GetEepromRegister( 1 ): GET REGISTER %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77); return 0x00000000; }

	return (s_i2c_get.read_bytes[ 0 ] <<  0) |
		
		   (s_i2c_get.read_bytes[ 1 ] <<  8) |
		
		   (s_i2c_get.read_bytes[ 2 ] << 16) |
		
		   (s_i2c_get.read_bytes[ 3 ] << 24);

	#endif

	return 0x00000000;
}

BOOLEAN B7348427B3AB4369914C8A1ED8C306B5( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, DWORD F09894BF114FE4ee592C232BC39730E91 )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	if( pDevice->m_pCodecLib == QP_NULL ) { return FALSE; }

	QPCODEC_DIAG_I2C_STRUCT s_i2c_set;

	EQP_Errors qp_status = QPERR_SUCCESS;

	s_i2c_set.chip_address = F3E85D87 >> 1;

	s_i2c_set.num_bytes = 5;

	s_i2c_set.bytes[ 0 ] = F6B106280018F45d7A077070B88512C77;

	s_i2c_set.bytes[ 1 ] = (BYTE)((F09894BF114FE4ee592C232BC39730E91 >>  0) & 0x000000FF);

	s_i2c_set.bytes[ 2 ] = (BYTE)((F09894BF114FE4ee592C232BC39730E91 >>  8) & 0x000000FF);

	s_i2c_set.bytes[ 3 ] = (BYTE)((F09894BF114FE4ee592C232BC39730E91 >> 16) & 0x000000FF);

	s_i2c_set.bytes[ 4 ] = (BYTE)((F09894BF114FE4ee592C232BC39730E91 >> 24) & 0x000000FF);

	qp_status = pDevice->m_pCodecLib->Set( pDevice->m_pCodecLib, 

										  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

										   TQP_NULL_HANDLE,

										   QPCODEC_DIAG_I2C_WRITE,

										  (TQP_PVOID)(&s_i2c_set),

										   QP_NULL,

										   sizeof(QPCODEC_DIAG_I2C_STRUCT) );

	if( QP_SUCCESS(qp_status) == FALSE ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_SetEepromRegister( 1 ): SET REGISTER %02X.%08X ERROR!!\n", F6B106280018F45d7A077070B88512C77, F09894BF114FE4ee592C232BC39730E91); return FALSE; }

	return QP_SUCCESS(qp_status);

	#endif

	return FALSE;
}

DWORD D4ACCD3D32D3402FB664E19B41D40A2D( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87 )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	if( pDevice->m_pCodecLib == QP_NULL ) { return 0x00000000; }

	QPCODEC_DIAG_I2C_WRITE_THEN_READ_STRUCT s_i2c_get;

	EQP_Errors qp_status = QPERR_SUCCESS;

	DWORD size_get = sizeof(QPCODEC_DIAG_I2C_WRITE_THEN_READ_STRUCT);

	s_i2c_get.chip_address = F3E85D87 >> 1;

	s_i2c_get.num_write_bytes = 0;

	s_i2c_get.num_read_bytes = 4;

	s_i2c_get.read_bytes[ 0 ] = 0x00;

	s_i2c_get.read_bytes[ 1 ] = 0x00;

	s_i2c_get.read_bytes[ 2 ] = 0x00;

	s_i2c_get.read_bytes[ 3 ] = 0x00;

	qp_status = pDevice->m_pCodecLib->Get( pDevice->m_pCodecLib, 

										  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

										   TQP_NULL_HANDLE,

										   QPCODEC_DIAG_I2C_WRITE_THEN_READ_EX,

										  (TQP_PVOID)(&s_i2c_get),

										  (TQP_PVOID)(&s_i2c_get),

										  (PTQP_UINT32)(&size_get) );

	if( QP_SUCCESS(qp_status) == FALSE ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "D4ACCD3D32D3402FB664E19B41D40A2D( 1 ): GET REGISTER ERROR!!\n"); return 0x00000000; }

	return (s_i2c_get.read_bytes[ 0 ] <<  0) |
		
		   (s_i2c_get.read_bytes[ 1 ] <<  8) |
		
		   (s_i2c_get.read_bytes[ 2 ] << 16) |
		
		   (s_i2c_get.read_bytes[ 3 ] << 24);

	#endif

	return 0x00000000;
}

BOOLEAN A96F4DD4D6014261A17107E06CD0CCA1( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE pValue[ 4 ] )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	if( pDevice->m_pCodecLib == QP_NULL ) { return FALSE; }

	QPCODEC_DIAG_I2C_STRUCT s_i2c_set;

	EQP_Errors qp_status = QPERR_SUCCESS;

	s_i2c_set.chip_address = F3E85D87 >> 1;

	s_i2c_set.num_bytes = 5;

	s_i2c_set.bytes[ 0 ] = F6B106280018F45d7A077070B88512C77;

	s_i2c_set.bytes[ 1 ] = pValue[ 0 ];

	s_i2c_set.bytes[ 2 ] = pValue[ 1 ];

	s_i2c_set.bytes[ 3 ] = pValue[ 2 ];

	s_i2c_set.bytes[ 4 ] = pValue[ 3 ];

	qp_status = pDevice->m_pCodecLib->Set( pDevice->m_pCodecLib, 

										  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

										   TQP_NULL_HANDLE,

										   QPCODEC_DIAG_I2C_WRITE_EX,

										  (TQP_PVOID)(&s_i2c_set),

										   QP_NULL,

										   sizeof(QPCODEC_DIAG_I2C_STRUCT) );

	if( QP_SUCCESS(qp_status) == FALSE ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "A96F4DD4D6014261A17107E06CD0CCA1( 1 ): SET REGISTER ERROR!!\n" ); return FALSE; }

	return QP_SUCCESS(qp_status);

	#endif

	return FALSE;
}

BOOLEAN PL330B_SetWatchDogRegister( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE bValue )
{
#if defined(AME_PL330B) || defined(AME_PL330A)

	if( pDevice->m_pCodecLib == QP_NULL ) { return FALSE; }

	QPCODEC_DIAG_I2C_STRUCT s_i2c_set;

	EQP_Errors qp_status = QPERR_SUCCESS;

	s_i2c_set.chip_address = F3E85D87 >> 1;

	s_i2c_set.num_bytes = 2;

	s_i2c_set.bytes[ 0 ] = F6B106280018F45d7A077070B88512C77;

	s_i2c_set.bytes[ 1 ] = bValue;

	qp_status = pDevice->m_pCodecLib->Set( pDevice->m_pCodecLib, 

										  (TQP_REFGUID)(&PROPSETID_QPCODEC_DIAG),

										   TQP_NULL_HANDLE,

										   QPCODEC_DIAG_I2C_WRITE_EX,

										  (TQP_PVOID)(&s_i2c_set),

										   QP_NULL,

										   sizeof(QPCODEC_DIAG_I2C_STRUCT) );

	if( QP_SUCCESS(qp_status) == FALSE ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "A96F4DD4D6014261A17107E06CD0CCA1( 1 ): SET REGISTER ERROR!!\n" ); return FALSE; }

	return QP_SUCCESS(qp_status);

	#endif

	return FALSE;
}

BOOLEAN B98859FFE32A4FC2A1A6B33CBCB91945( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bBitNum, BYTE bDirection )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	if( pDevice->m_pMpegCodec == QP_NULL ) { return FALSE; }

	GPIO_BIT_DIRECTION s_gpio;

	EQP_Errors qp_status = QPERR_SUCCESS;

	s_gpio.bBitNumber = bBitNum;

	s_gpio.Direction = (GPIO_DIRECTION)(bDirection);

	qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, 

										   (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL),

										    pDevice->BA3E1E68758F40848036F186E1A9DF05,

										    QPCODEC_GPIO_BIT_DIRECTION,

										   (TQP_PVOID)(&s_gpio),

										    NULL,

										    sizeof(GPIO_BIT_DIRECTION) );
	return QP_SUCCESS(qp_status);

	#endif

	return FALSE;
}

BYTE PL330B_GetGpioValue( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bBitNum )
{
#if defined(AME_PL330B) || defined(AME_PL330A)

	if( pDevice->m_pMpegCodec == QP_NULL ) { return FALSE; }

	GPIO_BIT_VALUE s_gpio;
	
	TQP_UINT32 size = 0;

	EQP_Errors qp_status = QPERR_SUCCESS;

	s_gpio.bBitNumber = bBitNum;

	s_gpio.bValue = 0x00;

	qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, 

										   (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL),

										    pDevice->BA3E1E68758F40848036F186E1A9DF05,

										    QPCODEC_GPIO_BIT_VALUE,

										   (TQP_PVOID)(&s_gpio),

										   (TQP_PVOID)(&s_gpio),

										   &size );
	return (s_gpio.bValue) ? 1 : 0;

	#endif

	return 0;
}

BOOLEAN CBFDDC6395144862ACEDAD3C092FC9A6( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bBitNum, BYTE bValue )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	if( pDevice->m_pMpegCodec == QP_NULL ) { return FALSE; }

	GPIO_BIT_VALUE s_gpio;

	EQP_Errors qp_status = QPERR_SUCCESS;

	s_gpio.bBitNumber = bBitNum;

	s_gpio.bValue = bValue;

	qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, 

										   (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL),

										    pDevice->BA3E1E68758F40848036F186E1A9DF05,

										    QPCODEC_GPIO_BIT_VALUE,

										   (TQP_PVOID)(&s_gpio),

										    QP_NULL,

										    sizeof(GPIO_BIT_VALUE) );
	return QP_SUCCESS(qp_status);

	#endif

	return FALSE;
}

BOOLEAN B6DA6D73E4484C36B5A7CF9DFE4BBFB0( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG dwOldLockStatus, ULONG dwNewLockStatus ) 
{
#if defined(AME_PL330B) || defined(AME_PL330A)	
	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xA0 ) {

		if( dwOldLockStatus == 0 && dwNewLockStatus == 1 ) {

			if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

				p_sys_cfg->n_it1412_register_value &= 0x3000;

				p_sys_cfg->n_it1412_register_value |= 0x8000;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 0 ) {
				
				p_sys_cfg->n_it1412_register_value &= 0x0300;

				p_sys_cfg->n_it1412_register_value |= 0x0800;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 1 ) {
				
				p_sys_cfg->n_it1412_register_value &= 0x0000;

				p_sys_cfg->n_it1412_register_value |= 0x0080;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 2 ) {
				
				p_sys_cfg->n_it1412_register_value &= 0x0000;

				p_sys_cfg->n_it1412_register_value |= 0x0008;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 3 ) {
				
				p_sys_cfg->n_it1412_register_value &= 0x0000;

				p_sys_cfg->n_it1412_register_value |= 0x0020;
			}
			else {
				
				p_sys_cfg->n_it1412_register_value &= 0x0000;

				p_sys_cfg->n_it1412_register_value |= 0x0002;
			}
			E01264421F8C4AB6AD3359477448A41D( pDevice, p_sys_cfg->n_it1412_register_value );
		}
		if( dwOldLockStatus == 1 && dwNewLockStatus == 0 ) {

			if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {
				
				p_sys_cfg->n_it1412_register_value &= 0x3000;

				p_sys_cfg->n_it1412_register_value |= 0x4000;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 0 ) {
				
				p_sys_cfg->n_it1412_register_value &= 0x0300;

				p_sys_cfg->n_it1412_register_value |= 0x0400;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 1 ) {
				
				p_sys_cfg->n_it1412_register_value &= 0x0000;

				p_sys_cfg->n_it1412_register_value |= 0x0040;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 2 ) {
				
				p_sys_cfg->n_it1412_register_value &= 0x0000;

				p_sys_cfg->n_it1412_register_value |= 0x0004;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 3 ) {
				
				p_sys_cfg->n_it1412_register_value &= 0x0000;

				p_sys_cfg->n_it1412_register_value |= 0x0010;
			}
			else {
				
				p_sys_cfg->n_it1412_register_value &= 0x0000;

				p_sys_cfg->n_it1412_register_value |= 0x0001;
			}
			E01264421F8C4AB6AD3359477448A41D( pDevice, p_sys_cfg->n_it1412_register_value );
		}
		if( dwOldLockStatus == -1 && dwNewLockStatus == -1 ) {

			p_sys_cfg->n_it1412_register_value = 0x0000;

			E01264421F8C4AB6AD3359477448A41D( pDevice, p_sys_cfg->n_it1412_register_value );

			F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000000 );
		}
	}
	if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAE ) {

		if( dwOldLockStatus == 0 && dwNewLockStatus == 1 ) {
			
			if( pDevice->m_nAnalogCrossbarVideoInputProperty == 0 ) {
				
				p_sys_cfg->n_it1412_register_value = 0x0020;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 1 ) {
		
				p_sys_cfg->n_it1412_register_value = 0x0080;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 3 ) {

				p_sys_cfg->n_it1412_register_value = 0x0200;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 2 ) {
				
				p_sys_cfg->n_it1412_register_value = 0x0800;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4  ) {
				
				p_sys_cfg->n_it1412_register_value = 0x0000;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ) {
				
				p_sys_cfg->n_it1412_register_value = 0x2000;
			}
			else {

				p_sys_cfg->n_it1412_register_value = 0x8000;
			}
			E01264421F8C4AB6AD3359477448A41D( pDevice, p_sys_cfg->n_it1412_register_value );
		}
		if( dwOldLockStatus == 1 && dwNewLockStatus == 0 ) {

			if( pDevice->m_nAnalogCrossbarVideoInputProperty == 0 ) {
				
				p_sys_cfg->n_it1412_register_value = 0x0010;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 1 ) {
				
				p_sys_cfg->n_it1412_register_value = 0x0040;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 3 ) {
				
				p_sys_cfg->n_it1412_register_value = 0x0100;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 2 ) {
				
				p_sys_cfg->n_it1412_register_value = 0x0400;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {
				
				p_sys_cfg->n_it1412_register_value = 0x0000;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ) {
				
				p_sys_cfg->n_it1412_register_value = 0x1000;
			}
			else {

				p_sys_cfg->n_it1412_register_value = 0x4000;
			}
			E01264421F8C4AB6AD3359477448A41D( pDevice, p_sys_cfg->n_it1412_register_value );
		}
		if( dwOldLockStatus == -1 && dwNewLockStatus == -1 ) {

			p_sys_cfg->n_it1412_register_value = 0x0000;

			E01264421F8C4AB6AD3359477448A41D( pDevice, p_sys_cfg->n_it1412_register_value );

			F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000000 );
		}
	}
	if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAF ) {

		if( dwOldLockStatus == 0 && dwNewLockStatus == 1 ) {
			
			if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

				p_sys_cfg->n_it1412_register_value = 0x0020;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 0 ) {
				
				p_sys_cfg->n_it1412_register_value = 0x0080;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 1 ) {
		
				p_sys_cfg->n_it1412_register_value = 0x0200;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 3 ) {

				p_sys_cfg->n_it1412_register_value = 0x0800;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 2 ) {
				
				p_sys_cfg->n_it1412_register_value = 0x2000;
			}
			else {

				p_sys_cfg->n_it1412_register_value = 0x8000;
			}
			E01264421F8C4AB6AD3359477448A41D( pDevice, p_sys_cfg->n_it1412_register_value );
		}
		if( dwOldLockStatus == 1 && dwNewLockStatus == 0 ) {

			if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

				p_sys_cfg->n_it1412_register_value = 0x0010;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 0 ) {
				
				p_sys_cfg->n_it1412_register_value = 0x0040;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 1 ) {
		
				p_sys_cfg->n_it1412_register_value = 0x0100;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 3 ) {

				p_sys_cfg->n_it1412_register_value = 0x0400;
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 2 ) {
				
				p_sys_cfg->n_it1412_register_value = 0x1000;
			}
			else {

				p_sys_cfg->n_it1412_register_value = 0x4000;
			}
			E01264421F8C4AB6AD3359477448A41D( pDevice, p_sys_cfg->n_it1412_register_value );
		}
		if( dwOldLockStatus == -1 && dwNewLockStatus == -1 ) {

			p_sys_cfg->n_it1412_register_value = 0x0000;

			E01264421F8C4AB6AD3359477448A41D( pDevice, p_sys_cfg->n_it1412_register_value );

			F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000000 );
		}
	}
	if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAB) ||
		
		(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAD) ) {

		if( dwOldLockStatus == 0 && dwNewLockStatus == 1 ) {

			if( C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF902 ) == 0xAA01 ) {

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB00, 0x01AA ); // LED.SEL

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB01, 0x00AA ); // LED.SEL
			}
			else {

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB09, 0x01AA ); // LED.SEL

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB0A, 0x00AA ); // LED.SEL
			}
		}
		if( dwOldLockStatus == 1 && dwNewLockStatus == 0 ) {

			if( C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF902 ) == 0xAA01 ) {

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB00, 0x00AA ); // LED.SEL

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB01, 0x01AA ); // LED.SEL
			}
			else {

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB09, 0x00AA ); // LED.SEL

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB0A, 0x01AA ); // LED.SEL
			}
		}
		if( dwOldLockStatus == -1 && dwNewLockStatus == -1 ) {

			if( C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF902 ) == 0xAA01 ) {

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB00, 0x00AA ); // LED.SEL

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB01, 0x00AA ); // LED.SEL
			}
			else {

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB09, 0x00AA ); // LED.SEL

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB0A, 0x00AA ); // LED.SEL
			}
			F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000000 );
		}
	}
	#endif

	return TRUE;
}


BOOL BD39B0FC664743FD9D0E785C21FC080E( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"[%02d] BD39B0FC664743FD9D0E785C21FC080E()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);
	
	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
	
	CBFDDC6395144862ACEDAD3C092FC9A6( pDevice, 11, 0 ); // HPD

	p_sys_cfg->n_input_video_resolution_cx = 0;

	p_sys_cfg->n_input_video_resolution_cy = 0;

	p_sys_cfg->n_input_video_resolution_fps = 0;

	p_sys_cfg->n_input_video_resolution_fps_m = 0;

	p_sys_cfg->n_input_video_resolution_interleaved = 0;

	p_sys_cfg->b_input_video_signal_changed = FALSE;

	p_sys_cfg->n_input_audio_sampling_frequency = 0;

	InitCAT6023(pDevice);
#endif	
 	return TRUE;
}

BOOL E8BC10F6757E49B086F83454E6F1A876( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
	
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"[%02d] E8BC10F6757E49B086F83454E6F1A876()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

	if( pDevice->iManufacturer == 0xAE ||
		
		pDevice->iManufacturer == 0xAF ) { // POWER.ON/OFF
			
		E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x06, 0x0E );

		E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1A, 0x40 );

		F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB0F, 0x01AA );

		CBFDDC6395144862ACEDAD3C092FC9A6( pDevice, 2, 0 );
		
		F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );
	}
	F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0x0009, (11 << 10) | (4 << 5) | (11 << 0) );

	F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0x0000, (1 << 6) | (1 << 7) );

	USHORT R0200 = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x0200 ) & 0xF0FF; R0200 |= 0x0A00;

	F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0x0200, R0200 );

	USHORT R0408 = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x0408 ) & 0x00FF; R0408 |= 0xAA00;
	
	F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0x0408, R0408 );

	if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAD) || 
		
		(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAE) || 
		
		(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAF) || 

		(pDevice->iManufacturer == 0x21) || // DARIM.48.SC542N1-L HDV
		
		(pDevice->iManufacturer == 0x29) || // DARIM.43.SC542N2 HDV

		(pDevice->iManufacturer == 0x2D) || // DARIM.49.SC542N4 HYBRID.1ST
		
		(pDevice->iManufacturer == 0x26) || // DARIM.48.SC542N6 HYBRID.1ST
		
		(pDevice->iManufacturer == 0x40) ||
		
		(pDevice->iManufacturer == 0x42) ||
		
		(pDevice->iManufacturer == 0x43) ||
		
		(pDevice->iManufacturer == 0x48) ||
		
		(pDevice->iManufacturer == 0x49) ||
		
		(pDevice->iManufacturer == 0xA0) ||
		
		(pDevice->iManufacturer == 0xA2) ||
		
		(pDevice->iManufacturer == 0xA3) ||
		
		(pDevice->iManufacturer == 0xA8) ||
		
		(pDevice->iManufacturer == 0xA9) ) {

		F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA06, 0x01AA ); // VID.SEL

		F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA07, 0x01AA ); // I2S.SEL
	
		F3442C8F4E5244B4852C27C401ED415E( pDevice, 0x00, 0x9C, 0x00, 0xB3, 0xFF ); // TRI-STATE [2016.08.29]

		F3442C8F4E5244B4852C27C401ED415E( pDevice, 0x00, 0x9C, 0x02, 0x27, 0xFF ); // TRI-STATE	[2016.08.29]
	}
	B6DA6D73E4484C36B5A7CF9DFE4BBFB0( pDevice, 1, 0 );

	p_sys_cfg->n_input_video_resolution_cx = 0;

	p_sys_cfg->n_input_video_resolution_cy = 0;

	p_sys_cfg->n_input_video_resolution_fps = 0;

	p_sys_cfg->n_input_video_resolution_fps_m = 0;

	p_sys_cfg->n_input_video_resolution_interleaved = 0;

	p_sys_cfg->b_input_video_signal_changed = FALSE;

	p_sys_cfg->n_input_audio_sampling_frequency = 0;
#endif
	return TRUE;
}

BOOL PL330B_ZULLAVISION_FPGA_HwInitialize( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	p_sys_cfg->n_input_video_resolution_cx = 0;

	p_sys_cfg->n_input_video_resolution_cy = 0;

	p_sys_cfg->n_input_video_resolution_fps = 0;

	p_sys_cfg->n_input_video_resolution_fps_m = 0;

	p_sys_cfg->n_input_video_resolution_interleaved = 0;

	p_sys_cfg->b_input_video_signal_changed = FALSE;

	p_sys_cfg->n_input_audio_sampling_frequency = 0;

	return TRUE;
}

BOOL PL330B_TW9910_HwInitialize( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
#if defined(AME_PL330B) || defined(AME_PL330A)

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"[%02d] PL330B_TW9910_HwInitialize()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

	if( pDevice->iManufacturer == 0x21 || // DARIM.48.SC542N1-L HDV
		
		pDevice->iManufacturer == 0x29 || // DARIM.43.SC542N2 HDV
		
		pDevice->iManufacturer == 0x2D || // DARIM.49.SC542N4 HYBRID.1ST
		
		pDevice->iManufacturer == 0x26 || // DARIM.48.SC542N6 HYBRID.1ST
		
		pDevice->iManufacturer == 0x40 ||
		
		pDevice->iManufacturer == 0x41 ||
		
		pDevice->iManufacturer == 0x42 ||
		
		pDevice->iManufacturer == 0x43 ||
		
		pDevice->iManufacturer == 0x48 ||

		pDevice->iManufacturer == 0x49 ||

		pDevice->iManufacturer == 0xA0 ||
		
		pDevice->iManufacturer == 0xA1 ||
		
		pDevice->iManufacturer == 0xA2 ||
		
		pDevice->iManufacturer == 0xA3 ||
		
		pDevice->iManufacturer == 0xA8 ||
		
		pDevice->iManufacturer == 0xA9 ||
		
		pDevice->iManufacturer == 0xAE ||
		
		pDevice->iManufacturer == 0xAF ) {

		if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||  // COMPOSITE

			pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) { // SVIDEO

			F3442C8F4E5244B4852C27C401ED415E( pDevice, 0x00, 0x9C, 0x00, 0xB3, 0xFF ); // TRI-STATE [2016.08.29]

			if( pDevice->iManufacturer == 0xAE ||
		
				pDevice->iManufacturer == 0xAF ) { // POWER.ON/OFF

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB0F, 0x00AA );

				CBFDDC6395144862ACEDAD3C092FC9A6( pDevice, 2, 0 );
			}
			if( pDevice->iManufacturer == 0x21 || // DARIM.48.SC542N1-L HDV
				
				pDevice->iManufacturer == 0x26 || // DARIM.48.SC542N6 HYBRID.1ST
				
				pDevice->iManufacturer == 0x42 ||
				
				pDevice->iManufacturer == 0x48 ||
				
				pDevice->iManufacturer == 0xA2 ||
				
				pDevice->iManufacturer == 0xA8 ) { // POWER.ON/OFF

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFC06, 0x00AA ); // 27.00 MHZ
			}
			if( pDevice->iManufacturer == 0x29 || // DARIM.43.SC542N2 HDV
				
				pDevice->iManufacturer == 0x43 ||
				
				pDevice->iManufacturer == 0xA3 ) { // POWER.ON/OFF

				if( C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF902 ) == 0xAA01 ) {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFC07, 0x00AA ); // 27.00 MHZ
				}
				else {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFC06, 0x00AA ); // 27.00 MHZ
				}
			}
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x06, 0x00 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x03, 0xA2 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x05, 0x01 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x08, 0x14 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x09, 0xF2 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0A, 0x0B );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0B, 0xD2 );
		//	E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x19, 0x57 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x19, 0xDE );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1A, 0x0F );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1B, 0x00 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x28, 0x0E );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x29, 0x03 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x2D, 0x07 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x2F, 0x06 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x4C, 0x0D );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x55, 0x00 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6B, 0x26 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6C, 0x36 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6D, 0xF0 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6E, 0x28 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x06, 0x80 );

			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6F, 0x98 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x64, 0x55 );
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x06, 0x80 );

			PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

			p_sys_cfg->n_input_video_resolution_cx = 0;

			p_sys_cfg->n_input_video_resolution_cy = 0;

			p_sys_cfg->n_input_video_resolution_fps = 0;

			p_sys_cfg->n_input_video_resolution_fps_m = 0;

			p_sys_cfg->n_input_video_resolution_interleaved = 0;

			p_sys_cfg->b_input_video_signal_changed = FALSE;

			p_sys_cfg->n_input_audio_sampling_frequency = 0;	

			B6DA6D73E4484C36B5A7CF9DFE4BBFB0( pDevice, 1, 0 );
		}
	}
#endif
 	return TRUE;
}

NTSTATUS D585A1C8DE8349C5A903B8F61B5E0A9F( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nStandard, BOOL THREAD )
{
	if( pDevice->iManufacturer == 0x21 || // DARIM.48.SC542N1-L HDV
		
		pDevice->iManufacturer == 0x29 || // DARIM.43.SC542N2 HDV
		
		pDevice->iManufacturer == 0x2D || // DARIM.49.SC542N4 HYBRID.1ST
		
		pDevice->iManufacturer == 0x26 || // DARIM.48.SC542N6 HYBRID.1ST
				
		pDevice->iManufacturer == 0x40 ||
		
		pDevice->iManufacturer == 0x41 ||
		
		pDevice->iManufacturer == 0x42 ||
		
		pDevice->iManufacturer == 0x43 ||
		
		pDevice->iManufacturer == 0x48 ||

		pDevice->iManufacturer == 0x49 ||

		pDevice->iManufacturer == 0xA0 ||
		
		pDevice->iManufacturer == 0xA1 ||
		
		pDevice->iManufacturer == 0xA2 ||
		
		pDevice->iManufacturer == 0xA3 ||

		pDevice->iManufacturer == 0xA8 ||
		
		pDevice->iManufacturer == 0xA9 ||
		
		pDevice->iManufacturer == 0xAE ||
		
		pDevice->iManufacturer == 0xAF ) {
		
		if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||  // COMPOSITE

			pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) { // SVIDEO

			if( THREAD == FALSE ) { PL330B_CLOSE_THREAD(); }

			PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

			BYTE R0C = (BYTE)(DD0D84BB34264335874009D864B98B9C( pDevice, 0, 0x88, 0x0C )) & 0xEF;

			switch( pDevice->FD314ADAD9404496b842EBFC396E875CB ) {
			
			case V4L2_STD_NTSC_M:      E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x00 );  break;
			case V4L2_STD_NTSC_M_JP:    E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x00 );  break;
			case V4L2_STD_NTSC_443:    E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x03 );  break;
			case V4L2_STD_PAL_60:      E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x07 );  break;
			case V4L2_STD_PAL_M:       E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x04 );  break;
			case V4L2_STD_PAL_B:       E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x01 );  break;
			case V4L2_STD_PAL_D:       E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x01 );  break;
			case V4L2_STD_PAL_G:       E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x01 );  break;
			case V4L2_STD_PAL_H:       E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x01 );  break;
			case V4L2_STD_PAL_I:       E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x01 );  break;
			case V4L2_STD_PAL_N:       E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x05 );  break;
			case V4L2_STD_PAL_Nc:	   E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
			case V4L2_STD_SECAM_B:     E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
			case V4L2_STD_SECAM_G:     E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
			case V4L2_STD_SECAM_H:     E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
			case V4L2_STD_SECAM_D:     E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
			case V4L2_STD_SECAM_K:     E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
			case V4L2_STD_SECAM_K1:    E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
			case V4L2_STD_SECAM_L:     E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
			case V4L2_STD_SECAM_LC:    E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
			}
			switch( pDevice->FD314ADAD9404496b842EBFC396E875CB ) {
			
			case V4L2_STD_NTSC_M:      E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x10 );  break;
			case V4L2_STD_NTSC_M_JP:    E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_NTSC_443:    E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x10 );  break;
			case V4L2_STD_PAL_60:      E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_PAL_M:       E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x10 );  break;
			case V4L2_STD_PAL_B:       E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_PAL_D:       E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_PAL_G:       E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_PAL_H:       E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_PAL_I:       E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_PAL_N:       E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x10 );  break;
			case V4L2_STD_PAL_Nc:	   E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_SECAM_B:     E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_SECAM_G:     E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_SECAM_H:     E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_SECAM_D:     E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_SECAM_K:     E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_SECAM_K1:    E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_SECAM_L:     E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			case V4L2_STD_SECAM_LC:    E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
			}
			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_60HZ ) {

				BYTE R07 = (BYTE)(DD0D84BB34264335874009D864B98B9C( pDevice, 0, 0x88, 0x07 )) & 0x0F;
				
				BYTE R55 = (BYTE)(DD0D84BB34264335874009D864B98B9C( pDevice, 0, 0x88, 0x55 )) & 0xEF;

				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x07, 0x00 | R07 );
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x08, 0x14       );
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x09, 0xF2       );
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0A, 0x0B       );
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0B, 0xD2       );
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x55, 0x10 | R55 );
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0D, 0x00       );
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0E, 0x11       );
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0F, 0x00       );

				///////////////////////////////////////////////////////////////////////////

				if( pDevice->iManufacturer == 0x21 || // DARIM.48.SC542N1-L HDV
					
					pDevice->iManufacturer == 0x29 || // DARIM.43.SC542N2 HDV
					
					pDevice->iManufacturer == 0x26 || // DARIM.48.SC542N6 HYBRID.1ST
				
					pDevice->iManufacturer == 0x42 ||
				
					pDevice->iManufacturer == 0x43 ||
				
					pDevice->iManufacturer == 0x48 ||
				
					pDevice->iManufacturer == 0xA2 ||
				
					pDevice->iManufacturer == 0xA3 ||
				
					pDevice->iManufacturer == 0xA8 ) { // POWER.ON/OFF

					;
				}
				else {

					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x06, 0x00 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1A, 0x4F );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x03, 0xA2 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x05, 0x01 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x08, 0x13 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x09, 0xF2 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x19, 0x57 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1A, 0x0F );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1B, 0xC0 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x29, 0x03 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x55, 0x00 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6B, 0x26 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6C, 0x36 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6D, 0xF0 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6E, 0x28 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1A, 0x0F );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x06, 0x80 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x10, 0x00 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x11, 0x5C );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x13, 0x80 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x14, 0x80 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x2D, 0x16 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x06, 0x00 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1A, 0x4F );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x03, 0xA2 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x05, 0x01 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x08, 0x13 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x09, 0xF2 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x19, 0x57 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1A, 0x0F );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1B, 0xC0 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x29, 0x03 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x55, 0x00 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6B, 0x26 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6C, 0x36 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6D, 0xF0 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6E, 0x28 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1A, 0x0F );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x06, 0x80 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x00 );
				}
				p_sys_cfg->n_input_video_resolution_cx = 720;

				p_sys_cfg->n_input_video_resolution_cy = 240;

				p_sys_cfg->n_input_video_resolution_fps = 60;

				p_sys_cfg->n_input_video_resolution_fps_m = 1;

				p_sys_cfg->n_input_video_resolution_interleaved = 1;

				p_sys_cfg->b_input_video_signal_changed = TRUE;

				p_sys_cfg->n_input_audio_sampling_frequency = 48000;

				pDevice->m_nCustomAnalogVideoResolutionProperty = (p_sys_cfg->n_input_video_resolution_cx << 16) | 

																	(p_sys_cfg->n_input_video_resolution_cy <<  0);

				pDevice->m_nCustomAnalogVideoFrameRateProperty = (p_sys_cfg->n_input_video_resolution_fps);

				pDevice->m_nCustomAnalogVideoInterleavedProperty = (p_sys_cfg->n_input_video_resolution_interleaved);

				pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 48000;
			}
			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_50HZ ) {

				BYTE R07 = (BYTE)(DD0D84BB34264335874009D864B98B9C( pDevice, 0, 0x88, 0x07 )) & 0x0F;
				
				BYTE R55 = (BYTE)(DD0D84BB34264335874009D864B98B9C( pDevice, 0, 0x88, 0x55 )) & 0xEF;

				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x07, 0x10 | R07 );
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x08, 0x19 +   0 );
				//E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x09, 0x20       );
				//peter modify
				BYTE R00 = (BYTE)(DD0D84BB34264335874009D864B98B9C( pDevice, 0, 0x88, 0x00 ));
				
				if( R00 == 0x59)//TW9910
				{
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x09, 0x20       );
				}
				else
				{
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x09, 0x1f       );
				}
				
				
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0A, 0x0A       );
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0B, 0xD2       );
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x55, 0x00 | R55 );
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0D, 0x00       );
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0E, 0x11       );
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x0F, 0x00       );	

				///////////////////////////////////////////////////////////////////////////

				if( pDevice->iManufacturer == 0x21 || // DARIM.48.SC542N1-L HDV
					
					pDevice->iManufacturer == 0x29 || // DARIM.43.SC542N2 HDV
					
					pDevice->iManufacturer == 0x26 || // DARIM.48.SC542N6 HYBRID.1ST
				
					pDevice->iManufacturer == 0x42 ||
				
					pDevice->iManufacturer == 0x43 ||
				
					pDevice->iManufacturer == 0x48 ||
				
					pDevice->iManufacturer == 0xA2 ||
				
					pDevice->iManufacturer == 0xA3 ||
				
					pDevice->iManufacturer == 0xA8 ) { // POWER.ON/OFF

					;
				}
				else {

					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x06, 0x00 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1A, 0x4F );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x03, 0xA2 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x05, 0x01 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x08, 0x13 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x09, 0xF2 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x19, 0x57 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1A, 0x0F );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1B, 0xC0 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x29, 0x03 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x55, 0x00 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6B, 0x26 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6C, 0x36 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6D, 0xF0 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6E, 0x28 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1A, 0x0F );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x06, 0x80 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x10, 0x00 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x11, 0x5C );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x13, 0x80 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x14, 0x80 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x2D, 0x16 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x06, 0x00 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1A, 0x4F );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x03, 0xA2 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x05, 0x01 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x08, 0x19 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x09, 0x1F );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x19, 0x57 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1A, 0x0F );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1B, 0xC0 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x29, 0x03 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x55, 0x00 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6B, 0x26 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6C, 0x36 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6D, 0xF0 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x6E, 0x28 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1A, 0x0F );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x06, 0x80 );
					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x1C, 0x01 );
				}
				p_sys_cfg->n_input_video_resolution_cx = 720;

				p_sys_cfg->n_input_video_resolution_cy = 288;

				p_sys_cfg->n_input_video_resolution_fps = 50;

				p_sys_cfg->n_input_video_resolution_fps_m = 0;

				p_sys_cfg->n_input_video_resolution_interleaved = 1;

				p_sys_cfg->b_input_video_signal_changed = TRUE;

				p_sys_cfg->n_input_audio_sampling_frequency = 48000;

				pDevice->m_nCustomAnalogVideoResolutionProperty = (p_sys_cfg->n_input_video_resolution_cx << 16) | 

																	(p_sys_cfg->n_input_video_resolution_cy <<  0);

				pDevice->m_nCustomAnalogVideoFrameRateProperty = (p_sys_cfg->n_input_video_resolution_fps);

				pDevice->m_nCustomAnalogVideoInterleavedProperty = (p_sys_cfg->n_input_video_resolution_interleaved);

				pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 48000;
			}
			F6B9E557A4BA24ffd926B820B836289C8_100NS( 2000000 ); // 不加延遲會導致後面第一次 LOCK 判斷失效

			if( THREAD == FALSE ) { PL330B_START_THREAD(); }
		}
	}
	return STATUS_SUCCESS; 
}

NTSTATUS E9D4315DBD2D4358B221B0E3A1963008( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nVideoInput, ULONG nVideoOutput, ULONG nAudioInput, ULONG nAudioOutput, BOOL THREAD )
{	
	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] E9D4315DBD2D4358B221B0E3A1963008() nVideoInput(%d) nAudioInput(%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, nVideoInput, nAudioInput);

#if defined(AME_PL330B) || defined(AME_PL330A)


	pDevice->m_pl330b_control_thread_stop = 1;

	if( THREAD == FALSE ) { PL330B_CLOSE_THREAD(); }

	if( nVideoInput != -1 ) {
		
		if( pDevice->iManufacturer == 0x22 ||  // DARIM.4A.SC542N2-L HDMI
	
			pDevice->iManufacturer == 0x24 ||  // DARIM.4A.SC542N4 HDMI
	
			pDevice->iManufacturer == 0x4A ||  // SC540N4 HDMI
	
			pDevice->iManufacturer == 0xAA ) { // SC5A0N4 HDMI

			BD39B0FC664743FD9D0E785C21FC080E( pDevice );
		}
		else if( pDevice->iManufacturer == 0x46 ||  // SC540N1 ZULLAVISION FPGA
			
				 pDevice->iManufacturer == 0xA6 ) { // SC540N1 ZULLAVISION FPGA

			PL330B_ZULLAVISION_FPGA_HwInitialize( pDevice );
		}
		else if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAD) || // PD5A0N1 SDI
					
				 (pDevice->iManufacturer == 0x2A) || // DARIM.4B.SC542N2-L SDI

				 (pDevice->iManufacturer == 0x2C) || // DARIM.4B.SC542N4 SDI

				 (pDevice->iManufacturer == 0x2E) || // DARIM.4B.SC542N4 HYBRID.2ND

				 (pDevice->iManufacturer == 0x27) || // DARIM.4B.SC542N6 HYBRID.2ND

				 (pDevice->iManufacturer == 0x44) || // SC540N1 MC SDI

				 (pDevice->iManufacturer == 0x4B) || // SC540N4 SDI

				 (pDevice->iManufacturer == 0xA4) || // SC5A0N1 MC SDI

				 (pDevice->iManufacturer == 0xAB) || // XX5A0N4 SDI

				 (pDevice->m_nAnalogCrossbarVideoInputProperty == 4) ) {

			E8BC10F6757E49B086F83454E6F1A876( pDevice );

			if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xA7) ) { // PD5A0N1 HDMI
				
				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x03, 0xA7 ); // TRI-STATE
			}
			if( (pDevice->iManufacturer == 0x21) ||  // DARIM.48.SC542N1-L HDV
				
				(pDevice->iManufacturer == 0x29) ||  // DARIM.43.SC542N2 HDV
				
				(pDevice->iManufacturer == 0x2D) ||  // DARIM.49.SC542N4 HYBRID.1ST
				
				(pDevice->iManufacturer == 0x26) ||  // DARIM.48.SC542N6 HYBRID.1ST
				
				(pDevice->iManufacturer == 0x40) ||  // SC540N1 HDV
						
				(pDevice->iManufacturer == 0x41) ||  // SC540N1 HDV
						
				(pDevice->iManufacturer == 0x42) ||  // SC542N1 HDV
						
				(pDevice->iManufacturer == 0x43) ||  // SC542N2 HDV
						
				(pDevice->iManufacturer == 0x48) ||  // SC542N1 HDV
						
				(pDevice->iManufacturer == 0x49) ||  // SC542N4 HDV
						
				(pDevice->iManufacturer == 0xA0) ||  // XX5A0N1 HDV
						
				(pDevice->iManufacturer == 0xA1) ||  // XX5A0N1 HDV
						
				(pDevice->iManufacturer == 0xA2) ||  // SC5A2N1 HDV
						
				(pDevice->iManufacturer == 0xA3) ||  // SC5A2N2 HDV
						
				(pDevice->iManufacturer == 0xA8) ||  // SC5A2N1 HDV
				
				(pDevice->iManufacturer == 0xA9) ||  // SC5A2N4 HDV
				
				(pDevice->iManufacturer == 0xAE) ||  // UB5A0N1 
				
				(pDevice->iManufacturer == 0xAF) ) { // UB5A0N1 

				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x03, 0xA7 ); // TRI-STATE
			}
		}
		else if( pDevice->iManufacturer == 0x21 ||  // DARIM.48.SC542N1-L HDV
			
				 pDevice->iManufacturer == 0x29 ||  // DARIM.43.SC542N2 HDV
			
				 pDevice->iManufacturer == 0x2D ||  // DARIM.49.SC542N4 HYBRID.1ST
			
				 pDevice->iManufacturer == 0x26 ||  // DARIM.48.SC542N6 HYBRID.1ST
				
				 pDevice->iManufacturer == 0x40 ||  // SC540N1 HDV
			
				 pDevice->iManufacturer == 0x41 ||  // SC540N1 HDV
			
				 pDevice->iManufacturer == 0x42 ||  // SC540N1 HDV
			
				 pDevice->iManufacturer == 0x43 ||  // SC542N2 HDV
			
				 pDevice->iManufacturer == 0x48 ||  // SC542N1 HDV
			
				 pDevice->iManufacturer == 0x49 ||  // SC542N4 HDV
			
				 pDevice->iManufacturer == 0xA0 ||  // XX5A0N4 HDV
				
				 pDevice->iManufacturer == 0xA1 ||  // XX5A0N1 HDV
				
				 pDevice->iManufacturer == 0xA2 ||  // SC5A2N1 HDV
				
				 pDevice->iManufacturer == 0xA3 ||  // SC5A2N1 HDV
				
				 pDevice->iManufacturer == 0xA8 ||  // SC5A2N1 HDV
				
				 pDevice->iManufacturer == 0xA9 ||  // SC5A2N4 HDV
				
				 pDevice->iManufacturer == 0xAE ||  // UB5A0N1
				
				 pDevice->iManufacturer == 0xAF ) { // UB5A0N1

			if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||

				pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) {

				if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x21) || // DARIM.48.SC542N1-L HDV
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x29) || // DARIM.43.SC542N2 HDV
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x2D) || // DARIM.49.SC542N4 HYBRID.1ST
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x26) || // DARIM.48.SC542N6 HYBRID.1ST
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x40) ||
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x41) ||
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x42) ||
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x43) ||
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x48) ||
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x49) ||
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA0) ||
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA1) ||
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA2) ||
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA3) ||
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA8) ||
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA9) ||
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xA0) ||
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAE) ||
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAF) ) {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA06, 0x00AA ); // VID.SEL

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA07, 0x00AA ); // I2S.SEL
				}
				CBFDDC6395144862ACEDAD3C092FC9A6( pDevice, 2, 0 ); // TRI-STATE

				PL330B_TW9910_HwInitialize( pDevice );

				if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ) { // COMPOSITE

					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x02, 0x0040 );	

					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x06, 0x0042 );	
				}
				if( pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) { // SVIDEO

					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x02, 0x0054 );	

					E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x06, 0x0040 );	
				}
			}
			else {

				MST3367_HwInitialize( pDevice );

				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x03, 0xA7 ); // TRI-STATE
			}
		}
		else { // PD5A0N1 HDMI

			MST3367_HwInitialize( pDevice );

			if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xA7) ) { // PD5A0N1 HDMI

				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x03, 0xA7 ); // TRI-STATE
			}
			if( pDevice->iManufacturer == 0x21 ||  // DARIM.48.SC542N1-L HDV
								
				pDevice->iManufacturer == 0x29 ||  // DARIM.43.SC542N2 HDV
								
				pDevice->iManufacturer == 0x2D ||  // DARIM.49.SC542N4 HYBRID.1ST
								
				pDevice->iManufacturer == 0x26 ||  // DARIM.48.SC542N6 HYBRID.1ST

				pDevice->iManufacturer == 0x40 ||  // SC5A0N1 HDV
								
				pDevice->iManufacturer == 0x41 ||  // SC5A0N1 HDV
								
				pDevice->iManufacturer == 0x42 ||  // SC5A2N1 HDV
								
				pDevice->iManufacturer == 0x43 ||  // SC5A2N2 HDV
								
				pDevice->iManufacturer == 0x48 ||  // SC5A2N1 HDV
								
				pDevice->iManufacturer == 0x49 ||  // SC5A2N4 HDV
								
				pDevice->iManufacturer == 0xA0 ||  // XX5A0N1 HDV
								
				pDevice->iManufacturer == 0xA1 ||  // XX5A0N1 HDV
								
				pDevice->iManufacturer == 0xA2 ||  // SC5A2N1 HDV
								
				pDevice->iManufacturer == 0xA3 ||  // SC5A2N2 HDV
								
				pDevice->iManufacturer == 0xA8 ||  // XX5A2N1 HDV
								
				pDevice->iManufacturer == 0xA9 ||  // XX5A2N4 HDV
				
				pDevice->iManufacturer == 0xAE ||  // UB5A0N1
				
				pDevice->iManufacturer == 0xAF ) { // UB5A0N1

				E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x03, 0xA7 ); // TRI-STATE
			}
		}
		pDevice->m_nCustomAnalogVideoResolutionProperty = 0;

		pDevice->m_nCustomAnalogVideoFrameRateProperty = 0;

		pDevice->m_nCustomAnalogVideoInterleavedProperty = 0;

		pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 0;

		pDevice->m_nAnalogVideoDecoderStatusProperty = 0;

		pDevice->m_nAnalogCopyProtMacrovisionProperty = 0;	
		
		if( pDevice->iManufacturer == 0x21 ||  // DARIM.48.SC542N1-L HDV
			
			pDevice->iManufacturer == 0x29 ||  // DARIM.43.SC542N2 HDV
			
			pDevice->iManufacturer == 0x2D ||  // DARIM.49.SC542N4 HYBRID.1ST
			
			pDevice->iManufacturer == 0x26 ||  // DARIM.48.SC542N6 HYBRID.1ST
			
			pDevice->iManufacturer == 0x40 ||  // SC540N1 HDV
			
			pDevice->iManufacturer == 0x41 ||  // SC540N1 HDV
			
			pDevice->iManufacturer == 0x42 ||  // SC542N1 HDV
			
			pDevice->iManufacturer == 0x43 ||  // SC542N2 HDV
			
			pDevice->iManufacturer == 0x48 ||  // SC542N1 HDV
			
			pDevice->iManufacturer == 0x49 ||  // SC542N4 HDV
			
			pDevice->iManufacturer == 0xA0 ||  // XX5A0N1 HDV
			
			pDevice->iManufacturer == 0xA1 ||  // XX5A0N1 HDV
			
			pDevice->iManufacturer == 0xA2 ||  // SC5A2N1 HDV
			
			pDevice->iManufacturer == 0xA3 ||  // SC5A2N2 HDV
			
			pDevice->iManufacturer == 0xA8 ||  // SC5A2N1 HDV
			
			pDevice->iManufacturer == 0xA9 ||  // SC5A2N4 HDV
			
			pDevice->iManufacturer == 0xAE ||  // UB5A0N1
			
			pDevice->iManufacturer == 0xAF ) { // UB5A0N1

			if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||

				pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) {

				D585A1C8DE8349C5A903B8F61B5E0A9F( pDevice, NULL, TRUE );

				AC2EB3596394401F99E0E3A4946A9436( pDevice, TRUE );
			}
		}
	}
	if( nAudioInput != -1 ) {

		ULONG R00700000 = PL330B_GetRegister( pDevice, 1, 0x00700000 + 0x00000000, 4 );

		BYTE  I2S_SEL = 0;

		if( pDevice->m_nAnalogCrossbarVideoInputProperty == 0 ||  // HDMI (TMDS.B)

			pDevice->m_nAnalogCrossbarVideoInputProperty == 1 ||  // DVI.DIGITAL (TMDS.A)

			pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) { // SDI

			if( pDevice->m_nAnalogCrossbarAudioInputProperty == 0 ) {

				I2S_SEL = 0;
			}
			if( pDevice->m_nAnalogCrossbarAudioInputProperty == 1 ) {

				I2S_SEL = 1;
			}
			if( pDevice->m_nAnalogCrossbarAudioInputProperty >= 2 ) {

				I2S_SEL = 2;
			}
		}
		if( pDevice->m_nAnalogCrossbarVideoInputProperty == 2 ||  // COMPONENT

			pDevice->m_nAnalogCrossbarVideoInputProperty == 3 ||  // DVI.ANALOG

			pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||  // CMOPOSITE

			pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) { // SVIDEO

			if( pDevice->m_nAnalogCrossbarAudioInputProperty == 0 ) {

				I2S_SEL = 1;
			}
			if( pDevice->m_nAnalogCrossbarAudioInputProperty == 1 ) {

				I2S_SEL = 1;
			}
			if( pDevice->m_nAnalogCrossbarAudioInputProperty >= 2 ) {

				I2S_SEL = 2;
			}
		}
		if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAD) || // PD5A0N1 SDI
			
			(pDevice->iManufacturer == 0x22) ||  // DARIM.4A.SC542N2-L HDMI
	
			(pDevice->iManufacturer == 0x24) ||  // DARIM.4A.SC542N4 HDMI
	
			(pDevice->iManufacturer == 0x2A) ||  // DARIM.4B.SC542N2-L SDI

			(pDevice->iManufacturer == 0x2C) ||  // DARIM.4B.SC542N4 SDI

			(pDevice->iManufacturer == 0x2E) ||  // DARIM.4B.SC542N4 HYBRID.2ND

			(pDevice->iManufacturer == 0x27) ||  // DARIM.4B.SC542N6 HYBRID.2ND

			(pDevice->iManufacturer == 0x44) ||  // SC540N1 MC SDI

			(pDevice->iManufacturer == 0x4A) ||  // SC540N4 HDMI

			(pDevice->iManufacturer == 0x4B) ||  // SC540N4 SDI

			(pDevice->iManufacturer == 0x4D) ||  // SC540N4 HDMI

			(pDevice->iManufacturer == 0xA4) ||  // SC5A0N1 MC SDI

			(pDevice->iManufacturer == 0xAA) ||  // SC5A0N4 HDMI

			(pDevice->iManufacturer == 0xAB) ||  // SC5A0N4 SDI

			(pDevice->iManufacturer == 0xAD) ) { // SC5A0N4 HDMI

			if( pDevice->m_nAnalogCrossbarAudioInputProperty == 0 ) {

				I2S_SEL = 0;
			}
			if( pDevice->m_nAnalogCrossbarAudioInputProperty == 1 ) {

				I2S_SEL = 1;
			}
			if( pDevice->m_nAnalogCrossbarAudioInputProperty >= 2 ) {

				I2S_SEL = 2;
			}
		}
		static BYTE CS42L51_REG_TABLE[ ] = { 

			0x02, 0x18, // POWER CONTROL 1 DISABLE POWER DOWN FUNCTION
			0x03, 0xA0, // MIC POWER CONTROL & SPEED CONTROL, POWER DOWN MIC
			0x04, 0x0F, // INTERFACE CTL, ADC I2S, SLAVE, DISABLE SDOUT CONNECT SDIN
			0x05, 0x00, // MIC CTL, ALL 0
			0x06, 0xA0, // ADC CONTROL,
			0x07, 0x00, // ADC INPUT SELECT, NOW AIN1X->PGAX
			0x08, 0x60, // DAC OUTPUT CONTROL, MUTE ENABLE
			0x09, 0x46, // DAC CONTROL, ENABLE MIXER
			0x0A, 0x00, // ALCA & PGAA CONTROL
			0x0B, 0x00, // ALCB & PGAB CONTROL
			0x0C, 0x00, // ADCA ATTENUATOR, FOR VOLUME CONTROL
			0x0D, 0x00, // ADCB ATTENUATOR, FOR VOLUME CONTROL
			0x0E, 0x00, // ADCA MIXER VOLUME CONTROL
			0x0F, 0x00, // ADCB MIXER VOLUME CONTROL
			0x10, 0x00, // PCMA MIXER VOLUME CONTROL
			0x11, 0x00, // PCMB MIXER VOLUME CONTROL
			0x12, 0x00, // BEEP FREQUENCY & TIMING CONFIGURATION
			0x13, 0x00, // BEEP OFF TIME & VOLUME
			0x14, 0x00, // BEEP CONFIGURATON & TONE CONFIGURATION
			0x15, 0x88, // TONE CONTROL
			0x16, 0x00, // AOUTA VOLUME CONTROL
			0x17, 0x00, // AOUTB VOLUME CONTROL
			0x18, 0x00, // PCM CHANNEL MIXER
			0x19, 0x00, // LIMITER THRESHOLD SZC DISABLE
			0x1A, 0x7F, // LIMITER RELEASE RATE
			0x1B, 0x00, // LIMITER ATTACK RATE
			0x1C, 0x00, // ALC ENABLE & ATTACH RATE
			0x1D, 0x3F, // ALC RELEASE RATE
			0x1E, 0x00, // ALC THRESHOLD
			0x1F, 0x00, // NOISE GATE CONFIG
			0x21, 0x50, // CHARGE PUMP FREQUENCY
			0x22, 0x00,
			0x23, 0x00, 0x24, 0x08, 0x25, 0xD8, 0x26, 0x00, 0x27, 0x07, 0x28, 0x00,
			0x29, 0x11, 0x2A, 0xD8, 0x2B, 0x84, 0x2C, 0x7C, 0x2D, 0xFE, 0x2E, 0xFC,
			0x2F, 0x1C, 0x30, 0xEC, 0x31, 0x6E, 0x32, 0x7F, 0x33, 0xFF, 0x34, 0xFD,
			0x35, 0xB5, 0x36, 0x02, 0x37, 0x08, 0x38, 0x55, 0x39, 0x94, 0x3A, 0x00,
			0x02, 0x00,
			0xFF, 0xFF
		};
		if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x21) ||  // DARIM.48.SC542N1-L HDV
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x29) ||  // DARIM.43.SC542N2 HDV
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x2D) ||  // DARIM.49.SC542N4 HYBRID.1ST
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x26) ||  // DARIM.48.SC542N6 HYBRID.1ST
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x40) ||  // SC540N1 HDV
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x41) ||  // SC540N1 HDV
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x42) ||  // SC542N1 HDV
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x43) ||  // SC542N2 HDV
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x44) ||  // SC540N1 MC SDI
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x48) ||  // SC542N1 HDV
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x49) ||  // SC542N4 HDV

			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA0) ||  // SC5A0N1 HDV

			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA1) ||  // SC5A0N1 HDV

			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA2) ||  // SC5A2N1 HDV

			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA3) ||  // SC5A2N2 HDV
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA4) ||  // SC5A0N1 MC SDI
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA8) ||  // SC542N1 HDV
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA9) ||  // SC542N4 HDV

			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xA0) ||  // UB5A0N4 HDV
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAB) ||  // UB5A0N4 SDI
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAD) ||  // PD5A0N1 SDI
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAE) ||  // UB5A0N1
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAF) ) { // UB5A0N1

			if( I2S_SEL >= 1 ) {

				USHORT R00200 = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x0200 ) & 0xDFFF; R00200 |= 0x2000;

				USHORT R00400 = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x0400 ) & 0xEFFF; R00400 |= 0x1000;

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0x0200, R00200 ); // TRI-STATE

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0x0400, R00400 ); // TRI-STATE

				if( C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF902 ) == 0xAA01 ) {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA05, 0x01AA ); // I2C.SEL
				}
				else {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA04, 0x01AA ); // I2C.SEL
				}
				ULONG i = 0;
				for( i = 0 ; i < sizeof(CS42L51_REG_TABLE) ; i += 2 ) { 
					
					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, CS42L51_REG_TABLE[ i ], CS42L51_REG_TABLE[ i + 1 ] ); 
				}	
				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x03, 0x4E ); // DISABLE AUTO + X1/2

				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x04, 0x4C ); // MASTER MODE

				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0x00 );

				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x09, 0x46 );

				if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xA0 ||  // UB5A0N4 HDV
					
					pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAE ||  // UB5A0N1
					
					pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAF ) { // UB5A0N1

					if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

						FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0xA0 ); // PHONE JECK
					}
					else {

						FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0x00 ); // CABLE
					}
				}
				if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAB) ||  // UB5A0N4 SDI
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAD) ) { // PD5A0N1 SDI

					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0xA0 ); // PHONE JECK
				}
				if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x21) ||  // DARIM.48.SC542N1-L HDV

					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x29) ||  // DARIM.43.SC542N2 HDV

					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x2D) ||  // DARIM.49.SC542N4 HYBRID.1ST

					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x26) ||  // DARIM.48.SC542N6 HYBRID.1ST

					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x40) ||  // SC540N1 HDV

					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x41) ||  // SC540N1 HDV

					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x43) ||  // SC542N2 HDV

					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x48) ||  // SC542N1 HDV

					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x49) ||  // SC542N4 HDV

					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA0) ||  // SC5A0N1 HDV

					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA1) ||  // SC5A0N1 HDV

					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA3) ||  // SC5A2N2 HDV

					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA8) ||  // SC5A2N1 HDV

					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA9) ) { // SC5A2N4 HDV

					if( pDevice->m_nAnalogCrossbarVideoInputProperty == 0 ||
						
						pDevice->m_nAnalogCrossbarVideoInputProperty == 1 ||
						
						pDevice->m_nAnalogCrossbarVideoInputProperty == 3 ||
						
						pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

						if( I2S_SEL >= 2 ) {

							FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0x00 ); // PIN (STEREO)
						}
						else {

							FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0xA0 ); // PHONE JECK (MONO)
						}
					}
					else {

						if( I2S_SEL >= 2 ) {

							FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0x00 ); // PIN (STEREO)
						}
						else {

							FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0x50 ); // CABLE (STEREO)
						}
					}
				}
				if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x42) ||  // SC542N1 HDV

					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA2) ) { // SC5A2N1 HDV

					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0x50 ); // CABLE (STEREO)
				}
				if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA8) ||  // SC5A2N1 L HDV
					
					(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x48) ) { // SC5A2N1 L HDV

					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0x50 ); // CABLE (STEREO)
				}
			}
			else {

				USHORT R00200 = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x0200 ) & 0xDFFF;

				USHORT R00400 = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x0400 ) & 0xEFFF;

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0x0200, R00200 );

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0x0400, R00400 );

				if( C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF902 ) == 0xAA01 ) {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA05, 0x00AA ); // I2C.SEL
				}
				else {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA04, 0x00AA ); // I2C.SEL
				}
				ULONG i = 0;
				for( i = 0 ; i < sizeof(CS42L51_REG_TABLE) ; i += 2 ) { 
					
					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, CS42L51_REG_TABLE[ i ], CS42L51_REG_TABLE[ i + 1 ] ); 
				}
				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x04, 0x0E );

				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0x00 );

				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x09, 0x06 );
			}
		}
		else if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x22) ||  // DARIM.4A.SC542N2-L HDMI
			
				 (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x24) ||  // DARIM.4A.SC542N4 HDMI
			
				 (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x4A) ||  // SC540N4 HDMI
			
				 (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xAA) ||  // SC5A0N4 HDMI
			
				 (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x4D) ||  // SC540N4 HDMI MST3363
			
				 (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xAD) ) { // SC5A0N4 HDMI MST3363

			if( I2S_SEL >= 1 ) {

				if( C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF902 ) == 0xAA01 ) {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA05, 0x01AA ); // I2C.SEL
				}
				else {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA04, 0x01AA ); // I2C.SEL
				}
				CBFDDC6395144862ACEDAD3C092FC9A6( pDevice, 8, 1 ); // I2C.SEL

				ULONG i = 0;
				for( i = 0 ; i < sizeof(CS42L51_REG_TABLE) ; i += 2 ) { 
						
					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, CS42L51_REG_TABLE[ i ], CS42L51_REG_TABLE[ i + 1 ] ); 
				}	
				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x03, 0x4E ); // DISABLE AUTO + X1/2

				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x04, 0x4C ); // MASTER MODE

				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0x00 );

				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x09, 0x46 );

				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0x00 ); // STEREO
			}
			else {
					
				if( C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF902 ) == 0xAA01 ) {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA05, 0x00AA ); // I2C.SEL
				}
				else {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA04, 0x00AA ); // I2C.SEL
				}
				CBFDDC6395144862ACEDAD3C092FC9A6( pDevice, 8, 0 ); // I2C.SEL

				ULONG i = 0;
				for( i = 0 ; i < sizeof(CS42L51_REG_TABLE) ; i += 2 ) { 
						
					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, CS42L51_REG_TABLE[ i ], CS42L51_REG_TABLE[ i + 1 ] ); 
				}
				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x04, 0x0E );

				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0x00 );

				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x09, 0x06 );
			}
		}
		else if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x2A) ||  // DARIM.4B.SC542N2-L SDI
			
				 (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x2C) ||  // DARIM.4B.SC542N4 SDI
			
				 (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x2E) ||  // DARIM.4B.SC542N4 HYBRID.2ND
			
				 (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x27) ||  // DARIM.4B.SC542N6 HYBRID.2ND
			
				 (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x4B) ||  // SC540N4 SDI (新 + 舊)
			
				 (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xAB) ) { // SC5A0N4 SDI (新 + 舊)

			BYTE R01 = F7B4503FC4AA4710AEC20FC4C587ACB8( pDevice, 0, 0x94, 0x01 ); // CHECK CS42L51

			if( R01 == 0xD8 ||  // CS42L51 A (新版本硬體)

				R01 == 0xD9 ) { // CS42L51 B (新版本硬體)

				if( I2S_SEL >= 1 ) {

					USHORT R00200 = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x0200 ) & 0xDFFF; R00200 |= 0x2000;

					USHORT R00400 = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x0400 ) & 0xEFFF; R00400 |= 0x1000;

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0x0200, R00200 ); // TRI-STATE

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0x0400, R00400 ); // TRI-STATE

					if( C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF902 ) == 0xAA01 ) {

						F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA05, 0x01AA ); // I2C.SEL
					}
					else {

						F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA04, 0x01AA ); // I2C.SEL
					}
					ULONG i = 0;
					for( i = 0 ; i < sizeof(CS42L51_REG_TABLE) ; i += 2 ) { 
						
						FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, CS42L51_REG_TABLE[ i ], CS42L51_REG_TABLE[ i + 1 ] ); 
					}	
					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x03, 0x4E ); // DISABLE AUTO + X1/2

					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x04, 0x4C ); // MASTER MODE

					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0x00 );

					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x09, 0x46 );

					if( I2S_SEL >= 2 ) {

						FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0x00 ); // STEREO
					}
					else {

						FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0xA0 ); // MONO
					}
				}
				else {

					USHORT R00200 = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x0200 ) & 0xDFFF;

					USHORT R00400 = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x0400 ) & 0xEFFF;

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0x0200, R00200 );

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0x0400, R00400 );

					if( C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF902 ) == 0xAA01 ) {

						F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA05, 0x00AA ); // I2C.SEL
					}
					else {

						F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFA04, 0x00AA ); // I2C.SEL
					}
					ULONG i = 0;
					for( i = 0 ; i < sizeof(CS42L51_REG_TABLE) ; i += 2 ) { 
						
						FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, CS42L51_REG_TABLE[ i ], CS42L51_REG_TABLE[ i + 1 ] ); 
					}
					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x04, 0x0E );

					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x07, 0x00 );

					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x09, 0x06 );
				}
			}
			else {

				if( I2S_SEL == 1 ) {

					F9094564DAE648AA9FB47CCDCC1D6CE1( pDevice, 0 );

					F20F06778F21457A885285EEF4132695( pDevice, 0, 0x01, 0x00 ); // PORT#01 (MONO)
				}
				if( I2S_SEL >= 2 ) {

					F9094564DAE648AA9FB47CCDCC1D6CE1( pDevice, 0 );

					F20F06778F21457A885285EEF4132695( pDevice, 0, 0x00, 0x00 ); // PORT#00 (STEREO)
				}
				if( I2S_SEL == 0 ) {

					CBFDDC6395144862ACEDAD3C092FC9A6( pDevice, 3, 0 );
				}
				else {

					CBFDDC6395144862ACEDAD3C092FC9A6( pDevice, 3, 1 );
				}
			}
		}
		else if( pDevice->iManufacturer == 0x45 ||  // SC542N1 MC HDV

				 pDevice->iManufacturer == 0x47 ||  // SC540N1 M2 HDMI

				 pDevice->iManufacturer == 0x4C ||  // SC540N1 MC HDV

				 pDevice->iManufacturer == 0xA1 ||  // PD5A0N1 HD

				 pDevice->iManufacturer == 0xA5 ||  // SC5A2N1 MC HDV

				 pDevice->iManufacturer == 0xA7 ||  // PD5A0N1 HDMI

				 pDevice->iManufacturer == 0xA7 ||  // SC5A0N1 M2 HDMI

				 pDevice->iManufacturer == 0xAC ) { // SC5A0N1 MC HDV
			
			if( I2S_SEL >= 1 ) {

				static BYTE CS53L21_REG_TABLE[ ] = { 0x03, 0x4E,
													 0x04, 0x44,
													 0x07, 0x00,
													 0x0A, 0x00,
													 0x0B, 0x00,
													 0x0C, 0x00,
													 0x0D, 0x00,
													 0x1C, 0xC0,
													 0x04, 0x46,
													 0x09, 0x42,
													 0x0E, 0x05, // DEFAULT = 0x18
													 0x0F, 0x05, // DEFAULT = 0x18
													 0x18, 0x00,
													 0xFF, 0xFF 
				};
				F3442C8F4E5244B4852C27C401ED415E( pDevice, 0x00, 0x9C, 0x02, 0x27, 0xFF ); // TRI-STATE
				ULONG i = 0;
				for( i = 0 ; i < sizeof(CS53L21_REG_TABLE) ; i += 2 ) { 
					
					FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, CS53L21_REG_TABLE[ i ], CS53L21_REG_TABLE[ i + 1 ] ); 
				}
			}
			else {

				FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x03, 0x5E ); // TRI-STATE

				F3442C8F4E5244B4852C27C401ED415E( pDevice, 0x00, 0x9C, 0x02, 0x27, 0x00 );
			}
		}

		if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xA0 ) {

			if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB04, 0x00AA ); // LED.SEL

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB05, 0x00AA ); // LED.SEL

				if( I2S_SEL == 0 ) {

					p_sys_cfg->n_it1412_register_value &= 0xC000;

					p_sys_cfg->n_it1412_register_value |= 0x2000;
				}
				if( I2S_SEL >= 1 ) {
					
					p_sys_cfg->n_it1412_register_value &= 0xC000;

					p_sys_cfg->n_it1412_register_value |= 0x1000;
				}
				E01264421F8C4AB6AD3359477448A41D( pDevice, p_sys_cfg->n_it1412_register_value );
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 0 ) {
						 
				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB04, 0x00AA ); // LED.SEL

				F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB05, 0x00AA ); // LED.SEL

				if( I2S_SEL == 0 ) {

					p_sys_cfg->n_it1412_register_value &= 0x0C00;

					p_sys_cfg->n_it1412_register_value |= 0x0200;
				}
				if( I2S_SEL >= 1 ) {
					
					p_sys_cfg->n_it1412_register_value &= 0x0C00;

					p_sys_cfg->n_it1412_register_value |= 0x0100;
				}
				E01264421F8C4AB6AD3359477448A41D( pDevice, p_sys_cfg->n_it1412_register_value );
			}
			else {

				if( I2S_SEL == 0 ) {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB04, 0x01AA ); // LED.SEL

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB05, 0x00AA ); // LED.SEL
				}
				if( I2S_SEL >= 1 ) {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB04, 0x00AA ); // LED.SEL

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB05, 0x01AA ); // LED.SEL
				}
				p_sys_cfg->n_it1412_register_value &= 0x00FF;

				p_sys_cfg->n_it1412_register_value |= 0x0000;
	
				E01264421F8C4AB6AD3359477448A41D( pDevice, p_sys_cfg->n_it1412_register_value );
			}
		}	
		if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAE ||
			
			pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAF ) {

			;
		}
		if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAB) ||
			
			(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAD) ) {

			if( I2S_SEL == 0 ) {

				if( C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF902 ) == 0xAA01 ) {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB02, 0x01AA ); // LED.SEL

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB03, 0x00AA ); // LED.SEL
				}
				else {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB0B, 0x01AA ); // LED.SEL

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFE05, 0x00AA ); // LED.SEL
				}
			}
			if( I2S_SEL >= 1 ) {

				if( C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF902 ) == 0xAA01 ) {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB02, 0x00AA ); // LED.SEL

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB03, 0x01AA ); // LED.SEL
				}
				else {

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFB0B, 0x00AA ); // LED.SEL

					F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xFE05, 0x01AA ); // LED.SEL
				}
			}
		}
	}
	if( THREAD == FALSE ) { PL330B_START_THREAD(); }

	pDevice->m_pl330b_control_thread_stop = 0;

#endif

	return STATUS_SUCCESS;
}

NTSTATUS E9D4315DBD2D4358B221B0E3A1963008EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice)
{
	E9D4315DBD2D4358B221B0E3A1963008( pDevice, pDevice->m_nAnalogCrossbarVideoInputProperty, pDevice->m_nAnalogCrossbarVideoOutputProperty, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE );

	AC2EB3596394401F99E0E3A4946A9436( pDevice, TRUE );

	return STATUS_SUCCESS;

}

void convertYV12_YUY2( BYTE* pe_y, BYTE* po_y, struct videobuf_buffer F6A821C5E7AA043f999FB3C51DB94DD2B)
{
	BYTE* pe_y_original = pe_y;

	int luma = 0;

	int u_data = 0;
	int u_line = 0;

	int v_data = 0;
	int v_line = 0;

	//copy Y
	for( luma = 0; luma < F6A821C5E7AA043f999FB3C51DB94DD2B.width * F6A821C5E7AA043f999FB3C51DB94DD2B.height; luma++)
	{
		*pe_y++ = *po_y++;

		pe_y++;
	}

	//copy U, line even and line odd use the same U data

	//reset pe_y to first byte
	pe_y = pe_y_original;

	//move to first U
	pe_y += 3;

	for( u_line = 0; u_line < F6A821C5E7AA043f999FB3C51DB94DD2B.height; u_line += 2)
	{
		//handle two line
		for( u_data = 0; u_data < F6A821C5E7AA043f999FB3C51DB94DD2B.width >> 1; u_data++)
		{
			*pe_y = *po_y++;

			pe_y += 4;
		}

		//reset po_y to beginning of U
		po_y -= F6A821C5E7AA043f999FB3C51DB94DD2B.width >>1;

		for( u_data = 0; u_data < F6A821C5E7AA043f999FB3C51DB94DD2B.width >> 1; u_data++)
		{
			*pe_y = *po_y++;

			pe_y += 4;
		}
	}

	//copy V, line even and line odd use the same V data

	//reset pe_y to first byte
	pe_y = pe_y_original;

	//move to first V
	pe_y++;

	for( v_line = 0; v_line < F6A821C5E7AA043f999FB3C51DB94DD2B.height; v_line += 2)
	{
		//handle two line
		for( v_data = 0; v_data < F6A821C5E7AA043f999FB3C51DB94DD2B.width >> 1; v_data++)
		{
			*pe_y = *po_y++;

			pe_y += 4;
		}

		//reset po_y to beginning of U
		po_y -= F6A821C5E7AA043f999FB3C51DB94DD2B.width >>1;

		for( v_data = 0; v_data < F6A821C5E7AA043f999FB3C51DB94DD2B.width >> 1; v_data++)
		{
			*pe_y = *po_y++;

			pe_y += 4;
		}
	}

}
 

#if defined(AME_PL330B) || defined(AME_PL330A)

#define MAX_WAIT 3 //12ms

#define PL330B_multichip_interrupt_time_gap MAX_WAIT*4000 //us

NTSTATUS PL330B_rawcpy( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice)
{
	PQP_BUFFER_DESCRIPTOR pBufDesc = (PQP_BUFFER_DESCRIPTOR)(pDevice->F9D066B94377B4a9aB14E37D504955651);

	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] PL330B_rawcpy() pBufDesc(lx%lx)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pBufDesc );
			
	int k = 0;
	for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
	{
		if( pDevice->FA12AAA3D283C4cf0BF02ACD3957899B0[ 0 ] & ( 1 << k ) ) {
		
			if( (pDevice->m_pVideo[ 0 ][ k ] == NULL) && (pDevice->m_pl330b_combine_4_chip == FALSE) ) { continue ; }
			
			// no pVideo for m_pl330b_combine_4_chip for ch2,3,4
			F301FA49098CE4d9eB95F22BBD388E837* pVideo = pDevice->m_pVideo[ 0 ][ k ];

			F170997530C6943659ECE8DEC21301F66* F523C1268E9B24a96876472B09F4D9EA4 = NULL;

			unsigned long flags = 0x00000000;

			BOOLEAN FDFC345768E394d138EA574DEB55B7949s = FALSE;

			//must for every device
			if( pDevice->m_pl330b_combine_4_chip )
			{
				if( g_pDevice[ 0 ]->m_previewbuffer[ k ] == NULL )
				{			
					if( g_pDevice[ 0 ]->m_pVideo[ 0 ][ k ])
					{
						if( wrapper_list_empty( &g_pDevice[ 0 ]->m_pVideo[ 0 ][ k ]->F0EA6D27495A14af1A9607DE7C222A3B1 ) == 0 ) {

							g_pDevice[ 0 ]->m_previewbuffer[ k ] = F523C1268E9B24a96876472B09F4D9EA4 = wrapper_list_first_entry( &g_pDevice[ 0 ]->m_pVideo[ 0 ][ k ]->F0EA6D27495A14af1A9607DE7C222A3B1, F170997530C6943659ECE8DEC21301F66, F6A821C5E7AA043f999FB3C51DB94DD2B.queue ); //
			
							if( F523C1268E9B24a96876472B09F4D9EA4 )
							{
								if( F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED )
								{
									NULL;
								}
								else
								{
									F523C1268E9B24a96876472B09F4D9EA4 = NULL;

									F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F523C1268E9B24a96876472B09F4D9EA4[ 0d%d ] error, not VIDEOBUF_QUEUED --\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), 0 );
								}
							}
						}
						else {

							F523C1268E9B24a96876472B09F4D9EA4 = NULL;

							//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] error F523C1268E9B24a96876472B09F4D9EA4[ 0d%d ](0x%x)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), 0, F523C1268E9B24a96876472B09F4D9EA4 );
						}
					}
				}
			}
			else
			{
				if( pVideo )
				{
					//Note: list_empty on entry does not return true after list_del, the entry is in an undefined state.
					if( wrapper_list_empty( &pVideo->F0EA6D27495A14af1A9607DE7C222A3B1 ) == 0 ) {

						F523C1268E9B24a96876472B09F4D9EA4 = wrapper_list_first_entry( &pVideo->F0EA6D27495A14af1A9607DE7C222A3B1, F170997530C6943659ECE8DEC21301F66, F6A821C5E7AA043f999FB3C51DB94DD2B.queue ); //
			
						if( F523C1268E9B24a96876472B09F4D9EA4 )
						{
							if( F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED )
							{
								NULL;
							}
							else
							{
								F523C1268E9B24a96876472B09F4D9EA4 = NULL;

								F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F523C1268E9B24a96876472B09F4D9EA4[ 0d%d ] error, not VIDEOBUF_QUEUED --\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), 0 );
							}
						}
					}
					else {

						F523C1268E9B24a96876472B09F4D9EA4 = NULL;

						//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] error F523C1268E9B24a96876472B09F4D9EA4[ 0d%d ](0x%x)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), 0, F523C1268E9B24a96876472B09F4D9EA4 );
					}
				}
			}
			ULONG counts = 1;

			F170997530C6943659ECE8DEC21301F66 * pVideoBuffer = NULL;

			if( (pDevice->m_pl330b_combine_4_chip && g_pDevice[ 0 ]->m_previewbuffer[ k ]) || ( !pDevice->m_pl330b_combine_4_chip && F523C1268E9B24a96876472B09F4D9EA4)  ) {

				if( pDevice->m_pl330b_combine_4_chip )
				{
					pVideoBuffer = g_pDevice[ 0 ]->m_previewbuffer[ k ];
				}
				else
				{
					pVideoBuffer = F523C1268E9B24a96876472B09F4D9EA4;
				}
				
				BYTE * pe = wrapper_videobuf_to_vmalloc( &pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B );

				if( pe == NULL ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] PL330B_rawcpy() pe == NULL \n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ); continue; }

				ULONG  cxe = pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.width;

				ULONG  cwe = pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.width;

				ULONG  cye = pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.height;

				BYTE * po = NULL;
			
				if( pBufDesc )
				{
					if(pBufDesc->DataBufferArray)
					{
						po = (BYTE *)(pBufDesc->DataBufferArray->Data);
						
						//strange, pBufDesc->DataBufferArray->Data is correct, pBufDesc->DataBufferArray->DataUsed is 0 if using thread ??

						//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] PL330B_rawcpy() DataUsed(%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pBufDesc->DataBufferArray->DataUsed );
						//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] PL330B_rawcpy() Data(lx%lx)--\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pBufDesc->DataBufferArray->Data);
					}
				}

				BYTE j = 0;

				if( po )
				{
					j = *(po - 4);

					if(j > 8)
					{
						F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] PL330B_rawcpy() j(0d%d) error ?????????\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, j);
	
						continue;
					}

					//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] PL330B_rawcpy() po(lx%lx) j(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, po, j);

					po[ -3 ] = 0x00; // 已經做過了, 不要再一次

					ULONG i = 0;
					for( i = 0 ; i < counts ; i++ ) {

						PL330B_SYS_CFG *  p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

						ULONG  cxo = p_sys_cfg->n_output_video_resolution_cx;

						ULONG  cwo = p_sys_cfg->n_output_video_resolution_cx;

						ULONG  cyo = p_sys_cfg->n_output_video_resolution_cy;

						ULONG size = (cxo * cyo * 12) >> 3;

						if( pDevice->m_nAnalogCopyProtMacrovisionProperty == 1 )//HDCP
						{
							if( (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
							{
								memset( pe, 0x80, cxe * cye / 2);
								memset( pe + cxo * cye , 0x00, cxe * cye / 8);
								memset( pe + cxo * cye + cxe * cye / 4, 0x00, cxe * cye / 8);

								FDFC345768E394d138EA574DEB55B7949s = TRUE;
							}
							else
							{
								FDFC345768E394d138EA574DEB55B7949s = FALSE;
							}
							//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] HDCP\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);
						}
						else
						{
							BYTE * po_y = p_sys_cfg->o_output_dma_buffers[ 0 ][ j ].image + (4);
	
							BYTE * po_u = po_y + ((cxo * cyo));
	
							BYTE * po_v = po_u + ((cxo * cyo) >> 2);

							BYTE * pe_y = pe;
	
							BYTE * pe_u = pe + (cxe * cye);
	
							BYTE * pe_v = pe_u + ((cxe * cye) >> 2);

							if( pDevice->m_pl330b_combine_4_chip )
							{
								pe_y = pe + (pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE / 2) * (1920 * 1080 * 2) + (pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE % 2) * 1920;
								
								pe_u = pe + 4 * 1920 * 1080 + (pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE / 2) * (960 * 540 * 2) +  (pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE % 2) * 960;
								
								pe_v = pe + 4 * 1920 * 1080 + 4 * 960 * 540 +  (pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE / 2) * (960 * 540 * 2) +  (pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE % 2) * 960;
								
								//fill Y data
								ULONG vertical = 0;

								for( vertical = 0; vertical < 1080; vertical++)
								{
									memcpy( pe_y, po_y, 1920);
									
									pe_y += 1920*2;//move to next line
									po_y += 1920;
								}

								//fill U data
								for( vertical = 0; vertical < 540; vertical++)
								{
									memcpy( pe_u, po_u, 960);
									
									pe_u += 960*2;//move to next line
									po_u += 960;
								}
								
								//fill V data
								for( vertical = 0; vertical < 540; vertical++)
								{
									memcpy( pe_v, po_v, 960);
									
									pe_v += 960*2;//move to next line
									po_v += 960;
								}

								struct timeval ts;

								wrapper_do_gettimeofday( &ts );
			
								//fill Interrupt_Container
								g_pDevice[ 0 ]->m_intrrupt_array[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ].ts.tv_sec = ts.tv_sec;
								g_pDevice[ 0 ]->m_intrrupt_array[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ].ts.tv_usec = ts.tv_usec;

								//must afer time registered
								g_pDevice[ 0 ]->m_intrrupt_array[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ].interrupt_arrived = 1;

								if( (pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE % 4) == 0 )
								{
									//check if 4 interrupt are arrived and on time
									struct timeval ts;

									wrapper_do_gettimeofday( &ts );

									LONGLONG base_time = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);

									LONGLONG diff_1 = 0;
									LONGLONG diff_2 = 0;
									LONGLONG diff_3 = 0;

									BYTE wait = 0;
									for( wait = 0; wait < MAX_WAIT; wait++ )
									{
										if( pDevice->m_intrrupt_array[ 1 ].interrupt_arrived && pDevice->m_intrrupt_array[ 2 ].interrupt_arrived && pDevice->m_intrrupt_array[ 3 ].interrupt_arrived )
										{

											LONGLONG device1_time = (LONGLONG)(pDevice->m_intrrupt_array[ 1 ].ts.tv_sec * 1000000) + (LONGLONG)(pDevice->m_intrrupt_array[ 1 ].ts.tv_usec);
											LONGLONG device2_time = (LONGLONG)(pDevice->m_intrrupt_array[ 2 ].ts.tv_sec * 1000000) + (LONGLONG)(pDevice->m_intrrupt_array[ 2 ].ts.tv_usec);
											LONGLONG device3_time = (LONGLONG)(pDevice->m_intrrupt_array[ 3 ].ts.tv_sec * 1000000) + (LONGLONG)(pDevice->m_intrrupt_array[ 3 ].ts.tv_usec);
				
											diff_1 = device1_time - base_time;
											diff_2 = device2_time - base_time;
											diff_3 = device3_time - base_time;

											if( (ABS(diff_1) < PL330B_multichip_interrupt_time_gap) &&  (ABS(diff_2) < PL330B_multichip_interrupt_time_gap) && (ABS(diff_3) < PL330B_multichip_interrupt_time_gap) ) 
											{
												FDFC345768E394d138EA574DEB55B7949s = TRUE;

												//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FDFC345768E394d138EA574DEB55B7949s = TRUE --\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

												break;
											}
											else
											{
												F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] time inconsistence, diff_1(%d) diff_2(%d) diff_3(%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), diff_1, diff_2, diff_3 );
											
												schedule_timeout_interruptible( msecs_to_jiffies( 1 ) );//4ms
											}
										}
										else
										{
											schedule_timeout_interruptible( msecs_to_jiffies( 1 ) );//4ms
										}
									}
									if( FDFC345768E394d138EA574DEB55B7949s == FALSE )
									{
										//discard all data
										memset( pDevice->m_intrrupt_array, 0x00, sizeof( struct Interrupt_Container) * 4);

										//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] drop due to time inconsistence or not received, diff_1(%d) diff_2(%d) diff_3(%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), diff_1, diff_2, diff_3 );
									}
								}
							}
							else
							{
								if( pVideoBuffer )
								{
									if( (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
									{
										if( size == pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.size )
										{
											if( pDevice->m_Invert_UV )
											{
												memcpy( pe_y, po_y, cxo * cyo );
	
												memcpy( pe_u, po_v, cxo * cyo / 4);
	
												memcpy( pe_v, po_u, cxo * cyo / 4);
											}
											else
											{
												#ifdef CUEBI_WEBRTC
												
													convertYV12_YUY2(pe_y, po_y, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B);

												#else
													memcpy( pe_y, po_y, size );

													if( (pDevice->m_nAnalogCrossbarVideoInputProperty == 5) || (pDevice->m_nAnalogCrossbarVideoInputProperty == 6) )
													{
														//set first 2 line black
														memset(pe_y, 16, cxo * 2);
														memset(pe_y + cxo * cyo, 128, cxo);
														memset(pe_y + cxo * cyo + cxo * cyo / 4, 128, cxo);
													}
												#endif
												
											}
											//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] PL330B_rawcpy() video copy to AP \n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);
										}
										else
										{
											#ifdef CUEBI_WEBRTC
												convertYV12_YUY2(pe_y, po_y, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B);
											#else
												BYTE * po_u = po_y + ((cxo * cyo));
	
												BYTE * po_v = po_u + ((cxo * cyo) >> 2);

												BYTE * pe_u = pe + (cxe * cye);
	
												BYTE * pe_v = pe_u + ((cxe * cye) >> 2);

												ULONG min_width = MIN( cxe, cxo);
	
												ULONG min_height = MIN( cye, cyo);
	
												memcpy( pe_y, po_y, min_width * min_height );
	
												if( pDevice->m_Invert_UV )
												{
													memcpy( pe_u, po_v, min_width * min_height / 4);
	
													memcpy( pe_v, po_u, min_width * min_height / 4);
												}
												else
												{
													memcpy( pe_u, po_u, min_width * min_height / 4);
	
													memcpy( pe_v, po_v, min_width * min_height / 4);
												}
											#endif
										}
										FDFC345768E394d138EA574DEB55B7949s = TRUE;

										//?? not acurate
										//update_video_time_stamp( pDevice, pVideos[ 0 ][ k ], pVideoBuffer);
									}
									else
									{
										FDFC345768E394d138EA574DEB55B7949s = FALSE;

										F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] pe(0x%x) po(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pe, po );
									}
								}
							}
							
						}//end of HDCP
					}//end of for
				}
				else //no signal
				{
					if( pDevice->m_nAnalogVideoDecoderStatusProperty == 0 )
					{
						//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] no signal\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);
					
						if( (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
						{
							if( pDevice->m_pl330b_combine_4_chip )
							{
							}
							else
							{
								if( pDevice->m_No_Signal_yuv_pattern_property )
								{
									BYTE * pe_y = pe;
		
									BYTE * pe_u = pe + (cxe * cye);
		
									BYTE * pe_v = pe_u + ((cxe * cye) >> 2);
	
									memset( pe_y, (BYTE)( (pDevice->m_No_Signal_yuv_pattern_property & 0xFF0000) >> 16), cxe * cye );
		
									memset( pe_u, (BYTE)( (pDevice->m_No_Signal_yuv_pattern_property & 0xFF00) >> 8), cxe * cye / 4);
		
									memset( pe_v, (BYTE)(pDevice->m_No_Signal_yuv_pattern_property), cxe * cye / 4);

									//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] blue\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

								}
								else
								{
									if( colorbar_image_1920_1080 && colorbar_image_1280_720 && colorbar_image_720_576 )
									{
										if( cxe == 1920 && cye == 1080)
										{
											memcpy( pe, colorbar_image_1920_1080, cxe * cye * 12 >> 3);
										}
										else if( cxe == 1280 && cye == 720)
										{
											memcpy( pe, colorbar_image_1280_720, cxe * cye * 12 >> 3);
										}
										else if( cxe == 720 && cye == 576)
										{
											memcpy( pe, colorbar_image_720_576, cxe * cye * 12 >> 3);
										}
										else if( cxe == 720 && cye == 480)
										{
											memcpy( pe, colorbar_image_720_576, cxe * cye);
											memcpy( pe + cxe * cye, colorbar_image_720_576 + 720*576 , cxe * cye /4);
											memcpy( pe + cxe * cye + cxe * cye /4, colorbar_image_720_576 + 720*576 + 720*576/4, cxe * cye /4);
										}
										else
										{
											memcpy( pe, colorbar_image_1920_1080, cxe * cye * 12 >> 3);
										}
									}
									else
									{
										memset( pe, 0x80, cxe * cye * 12 >> 3);
									}
								}
								FDFC345768E394d138EA574DEB55B7949s = TRUE;
							}
						}
						else
						{
							FDFC345768E394d138EA574DEB55B7949s = FALSE;
						}
					}
				}//end of po

				if( FDFC345768E394d138EA574DEB55B7949s && pVideoBuffer )
				{
					//use killall -9 vlc will change buffer state long before any driver function
					//I do not know how this be done, I can only check here
				
					if( pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED )
					{
						if( pDevice->m_pl330b_combine_4_chip )
						{
							pDevice->m_previewbuffer[ k ] = NULL;

							memset( pDevice->m_intrrupt_array, 0x00, sizeof( struct Interrupt_Container) * 4);
						}

						pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input = 0xFFFFFFFF; //

						if( pVideo )
						{
							wrapper_spin_lock_irqsave( &pVideo->FE0A97B802F3C400aBD7CD5D313825C31, flags );//must be the same as F3A12A0E868554cb0AFE2F5789D55B19F

							//must inside spin_lock
							//can not find how 0xdead000000000000 is added
							if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next == LIST_POISON1) || (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev == LIST_POISON2) || (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next == 0xdead000000000100) || (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev == 0xdead000000000200) )
							{
								wrapper_spin_unlock_irqrestore( &pVideo->FE0A97B802F3C400aBD7CD5D313825C31, flags );

								//skip this time
								F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue error, next(%p) prev(%p)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev );
							}
							else
							{
								wrapper_list_del( &pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue );
						
								wrapper_spin_unlock_irqrestore( &pVideo->FE0A97B802F3C400aBD7CD5D313825C31, flags );

								struct timeval ts;
	
								wrapper_do_gettimeofday( &ts );

								pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts = ts;

								//s_v4l2_buffer.sequence in AP is b->sequence  = vb->field_count >> 1
								pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.field_count = (++pVideo->F6578ACFCB40E44819A12FD3E27A48085) * 2;
						
								#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25)

								pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state = VIDEOBUF_DONE;

								#else

								pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state = STATE_DONE;

								#endif

								wrapper_wake_up( &pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.done );
							}
						}
					}
					else
					{
						F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] pe state error, k(0d%d) (%x) next(0x%x) prev(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, k, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev );
					}
				}
			}//end of if pVideo pVideobuffer 
			else
			{
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] no buffer\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );
			}
		}// end of if( pDevice->FA12AAA3D283C4cf0BF02ACD3957899B0[ 0 ] & ( 1 << k ) ) {
		else
		{
			//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] not running\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );
		}
	}//end of for
	
	return STATUS_SUCCESS;
}
#endif

NTSTATUS C03EDD59F4A64C2084BB2C70FC794214( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nVolume, BOOL THREAD )
{
	LONG volume = nVolume;

#if defined(AME_PL330B) || defined(AME_PL330A)

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 == 0 ) return STATUS_SUCCESS;

	if( THREAD == FALSE ) { PL330B_CLOSE_THREAD(); }

	BYTE R01 = F7B4503FC4AA4710AEC20FC4C587ACB8( pDevice, 0, 0x94, 0x01 ); // CHECK CS42L51

	if( R01 == 0xD8 ||  // CS42L51 A (新版本硬體)

		R01 == 0xD9 ) { // CS42L51 B (新版本硬體)

		if( nVolume >= 128 ) {

			ULONG v = (nVolume - 128) * (24) / (128 - 1);
			
			FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x0A, (BYTE)(v) ); 

			FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x0B, (BYTE)(v) ); 
			
			FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x0C, 0x00 ); 

			FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x0D, 0x00 ); 
		}
		else {

			LONG v = (LONG)(128 - nVolume) * (96) / (128);
			
			v = -v;

			FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x0A, 0 ); 

			FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x0B, 0 ); 
			
			FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x0C, (BYTE)(v & 0xFF) ); 

			FC5FCF2C4E50436EA8A2A8C98E4C1AC2( pDevice, 0, 0x94, 0x0D, (BYTE)(v & 0xFF) ); 
		}
	}
	if( THREAD == FALSE ) { PL330B_START_THREAD(); }

#endif

	return STATUS_SUCCESS;
}
extern void MST3367_ADJUST_CSC_TABLE( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bright, BYTE contrast, BYTE saturation, BYTE hue, BYTE sharpness );

NTSTATUS AC2EB3596394401F99E0E3A4946A9436( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BOOL THREAD )
{
	if( 0 == pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 ) return STATUS_SUCCESS;

	if( THREAD == FALSE ) { PL330B_CLOSE_THREAD(); }

	if( pDevice->m_nAnalogCrossbarVideoInputProperty <= 3 ) {

		MST3367_ADJUST_CSC_TABLE( pDevice, (BYTE)(FADD02C9C13B14f83989880EFACB8D8DC[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF), 
			
										   (BYTE)(F3A66BD0F0BCB4afcAD006E378E671B9A[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF), 
										   
										   (BYTE)(F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF), 
										   
										   (BYTE)(F42BAA55A84E847faA4D0C0565699845E[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF), 

										  ((BYTE)(F1D56E1ED762E4b99BB2BD370DFE317D1[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) >> 5) );
	}
	else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||
			
			 pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) {

			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x10, (BYTE)(((FADD02C9C13B14f83989880EFACB8D8DC[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) >> 0) - 128 - 19) | 0x00 );
			
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x11, (BYTE)(((F3A66BD0F0BCB4afcAD006E378E671B9A[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]   & 0xFF) >> 0) -        7) | 0x00 );
			
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x13, (BYTE)(((F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) >> 0) -        0) | 0x00 );
			
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x14, (BYTE)(((F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) >> 0) -        0) | 0x00 );
			
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x15, (BYTE)(((F42BAA55A84E847faA4D0C0565699845E[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]        & 0xFF) >> 0) -      128) | 0x00 );
			
			E057E022AA684160B92E903D99235927( pDevice, 0, 0x88, 0x12, (BYTE)(((F1D56E1ED762E4b99BB2BD370DFE317D1[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]  & 0xFF) >> 4) -        0) | 0x50 ); 
	}
	if( THREAD == FALSE ) { PL330B_START_THREAD(); }

	return STATUS_SUCCESS;
}

BOOLEAN F11AE4E46EF0410486665CDBF2F1128F( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE* pwszFileName, BYTE * * ppFW, ULONG * pFWSize )
{

	const struct firmware *fw;
	int ret = 1;
	BYTE* pFileBuffer = NULL;
	ULONG             nFileSize = 0;
	BOOLEAN			  returns = TRUE;
	struct timeval ts;
	ULONGLONG start_times = 0;

	ULONGLONG stop_times = 0;

	// 1.0 OPEN FONT LIBRARY *.DAT FILE
	// 
#ifdef AME_PL330B
	#ifdef NEVRON
	if(pDevice->F590A429DF6D145f288A92DDF1547AC46[ 0 ])
	{
		ret = request_firmware(&fw, pwszFileName, &(pDevice->F590A429DF6D145f288A92DDF1547AC46[ 0 ]->dev));
	}
	#else
	if(pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ 0 ])
	{
		ret = request_firmware(&fw, pwszFileName, &(pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ 0 ]->dev));
	}
	#endif
#endif

#ifdef AME_PL330A
	if(pDevice->F590A429DF6D145f288A92DDF1547AC46[ 0 ])
	{
		ret = request_firmware(&fw, pwszFileName, &(pDevice->F590A429DF6D145f288A92DDF1547AC46[ 0 ]->dev));
	}
#endif

	if (ret) {

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"[%02d] F11AE4E46EF0410486665CDBF2F1128F() Upload failed. (file %s not found?)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pwszFileName );

		return false;

	} else {

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] F11AE4E46EF0410486665CDBF2F1128F() firmware read %d bytes\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, fw->size);

		if(fw->size > 0)
		{
			nFileSize = fw->size;
			
			pFileBuffer = wrapper_vmalloc( fw->size);

			if(pFileBuffer)
			{
				memset( pFileBuffer, 0x00, fw->size);

				memcpy(pFileBuffer, fw->data, fw->size);
			}
			else
			{
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"[%d]F11AE4E46EF0410486665CDBF2F1128F() no buffer\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

				release_firmware(fw);

				return false;
			}

		}
	}
	// 2.0 DOWNLOAD FONT CONTENT
	// 
	wrapper_do_gettimeofday( &ts );

	start_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);


	BYTE * po = (BYTE *)(pFileBuffer);

	BYTE * pe = (BYTE *)(wrapper_vmalloc( nFileSize ) );

	if( ppFW ) {

	   *ppFW = pe;
	}
	if( pFWSize ) {

	   *pFWSize = nFileSize;
	}
	if( po &&
		
		pe ) { 
		
		memcpy( pe, po, nFileSize ); 
	}
	wrapper_do_gettimeofday( &ts );

	stop_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);


	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "- TOTAL DOWNLOAD TIMES = %08d (%d BYTES)\n", (ULONG)(stop_times - start_times), nFileSize);

	// 3.0 FREE WORKING BUFFER
	//
	if(pFileBuffer)
	{
		vfree( pFileBuffer );
	}	
	//pe is freed in hw_uninit
	release_firmware(fw);

	return TRUE;

/*
	WCHAR			  wszPathName[ 255 ];

	OBJECT_ATTRIBUTES oObjectAttributes;

	UNICODE_STRING    oFileName;

	IO_STATUS_BLOCK   oIoStatus;

	HANDLE            hFileHandle = NULL;

	BYTE *            pFileBuffer = NULL;

	ULONG             nFileSize = 0;

	NTSTATUS          status = STATUS_SUCCESS;

	swprintf( wszPathName, L"%s%s", pDevice->m_pCustomDeviceInfoDirectoryProperty, pwszFileName );

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_DOWNLOAD_FIRMWARE( \"%ws\" )\n", wszPathName) );

	// 1.0 OPEN FONT LIBRARY *.DAT FILE
	// 
	oFileName.MaximumLength = wcslen(wszPathName) * 2 + sizeof(UNICODE_NULL);

	oFileName.Buffer = (PWSTR)(ExAllocatePool( NonPagedPool, oFileName.MaximumLength ));

	oFileName.Length = 0;

    if( oFileName.Buffer == NULL ) {

        return FALSE;
    }
	else {

		RtlZeroMemory( oFileName.Buffer, oFileName.MaximumLength );
	}
	status = RtlAppendUnicodeToString( &oFileName, wszPathName );

	InitializeObjectAttributes( (POBJECT_ATTRIBUTES)(&oObjectAttributes), (PUNICODE_STRING)(&oFileName), OBJ_KERNEL_HANDLE | OBJ_CASE_INSENSITIVE, NULL, NULL );

	status = ZwCreateFile( &hFileHandle, FILE_READ_DATA, &oObjectAttributes, &oIoStatus, 0, FILE_ATTRIBUTE_NORMAL, FILE_SHARE_READ, FILE_OPEN, FILE_SYNCHRONOUS_IO_NONALERT, NULL, 0 );

	FREE_MEMORY( oFileName.Buffer );

	if( NT_SUCCESS(status) ) {

		FILE_STANDARD_INFORMATION oFileStandardInfomation;

		ZwQueryInformationFile( hFileHandle, &oIoStatus, &oFileStandardInfomation, sizeof(FILE_STANDARD_INFORMATION), FileStandardInformation );

		nFileSize = (ULONG)(oFileStandardInfomation.EndOfFile.QuadPart);

		pFileBuffer = (BYTE *)(ExAllocatePool( NonPagedPool, nFileSize ));

		if( pFileBuffer ) {

			ZwReadFile( hFileHandle, NULL, NULL, NULL, &oIoStatus, pFileBuffer, nFileSize, NULL, NULL );

			ZwClose( hFileHandle );
		}
		else {

			ZwClose( hFileHandle );

			return FALSE;
		}
	}
	else {

		return FALSE;
	}

	// 2.0 DOWNLOAD FONT CONTENT
	// 
	ULONGLONG start_times = KeQueryInterruptTime();

	ULONGLONG stop_times = 0;

	BYTE * po = (BYTE *)(pFileBuffer);

	BYTE * pe = (BYTE *)(ExAllocatePool( NonPagedPoolCacheAligned, nFileSize ) );

	if( ppFW ) {

	   *ppFW = pe;
	}
	if( pFWSize ) {

	   *pFWSize = nFileSize;
	}
	if( po &&
		
		pe ) { 
		
		RtlCopyMemory( pe, po, nFileSize ); 
	}
	stop_times = KeQueryInterruptTime();

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "- TOTAL DOWNLOAD TIMES = %08d (%d BYTES)\n", (ULONG)(stop_times - start_times), nFileSize) );

	// 3.0 FREE WORKING BUFFER
	//
	FREE_MEMORY( pFileBuffer );

	return TRUE;
*/
}

BOOL AA1D4E10781F45AF92A5792997D7623C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
#if defined(AME_PL330B) || defined(AME_PL330A)

	TQP_UINT32 size = 0;

	EQP_Errors qp_status = QPERR_SUCCESS;

	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	ULONG  cx =  p_sys_cfg->n_input_video_resolution_cx;

	ULONG  cy =  p_sys_cfg->n_input_video_resolution_cy;

	ULONG fps = p_sys_cfg->n_input_video_resolution_fps;
	
	ULONG interleaved = p_sys_cfg->n_input_video_resolution_interleaved;

	if( interleaved == 1 ) {

		cy <<= 1;

		fps >>= 1;
	}
	if( cx == 0 ||

		cy == 0 ||

		fps == 0 ) {

		interleaved = 0;
	}
	if( pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ 2 ] == TQP_NULL_HANDLE ) {

		return FALSE;
	}
	if( pDevice->m_nCustomEncoderVideoBitRateModeProperty[ 0 ] & 0x88000000 ||

		pDevice->m_nAnalogVideoCompressionQualityProperty[ 0 ] & 0x88000000 ||
		
		pDevice->m_nCustomEncoderVideoBitRateProperty[ 0 ] & 0x88000000 ||
		
		pDevice->m_nCustomEncoderVideoPeakBitRateProperty[ 0 ] & 0x88000000 ||
		
		pDevice->m_nCustomEncoderVideoTroughQualityProperty[ 0 ] & 0x88000000 ) {

		pDevice->m_nCustomEncoderVideoBitRateModeProperty[ 0 ] &= 0x77FFFFFF;

		pDevice->m_nAnalogVideoCompressionQualityProperty[ 0 ] &= 0x77FFFFFF;

		pDevice->m_nCustomEncoderVideoBitRateProperty[ 0 ] &= 0x77FFFFFF;

		pDevice->m_nCustomEncoderVideoPeakBitRateProperty[ 0 ] &= 0x77FFFFFF;

		pDevice->m_nCustomEncoderVideoTroughQualityProperty[ 0 ] &= 0x77FFFFFF;

		ULONG mode = pDevice->m_nCustomEncoderVideoBitRateModeProperty[ 0 ] & 0x77FFFFFF;

		ULONG quality = pDevice->m_nAnalogVideoCompressionQualityProperty[ 0 ] & 0x77FFFFFF;

		ULONG bitrate = pDevice->m_nCustomEncoderVideoBitRateProperty[ 0 ] & 0x77FFFFFF;

		ULONG bitrate_max = pDevice->m_nCustomEncoderVideoPeakBitRateProperty[ 0 ] & 0x77FFFFFF;

		ULONG bitrate_min= pDevice->m_nCustomEncoderVideoTroughQualityProperty[ 0 ] & 0x77FFFFFF;

		bitrate /= 1024; bitrate *= 1000; bitrate /= 1024;

		bitrate_max /= 1024; bitrate_max *= 1000; bitrate_max /= 1024;

		bitrate_min /= 1024; bitrate_min *= 1000; bitrate_min /= 1024;

		quality /= 1000;

		if( quality > 10 ) { quality = 10; }

		QPCODEC_RATE_CONTROL s_rate_control; RtlFillMemory( (BYTE*)&s_rate_control, sizeof(s_rate_control), 0x00 );
					
		QPCODEC_VBR_BIT_RATE s_vbr_bit_rate; RtlFillMemory( (BYTE*)&s_vbr_bit_rate, sizeof(s_vbr_bit_rate), 0x00 );
					
		qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ 2 ], QPCODEC_PROP_RATE_CONTROL, (TQP_PVOID)(&s_rate_control), (TQP_PVOID)(&s_rate_control), &size );
			
		qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ 2 ], QPCODEC_PROP_VBR_BIT_RATE, (TQP_PVOID)(&s_vbr_bit_rate), (TQP_PVOID)(&s_vbr_bit_rate), &size );

		if( mode == 0 ) {

			ULONG idx = 0;

			if( cx <=  720 ) { idx = 0; } else 

			if( cx <= 1360 ) { idx = 1; } else 

							 { idx = 2; } 

			static ULONG VBR_BITRATE_TABLE[ 3 ][ 11 ] = { {  500, 1000, 1500, 2000, 2500, 3000, 4000,  5000,  6000,  7000,  8000 }, 

														  { 1000, 2000, 3000, 4000, 5000, 6000, 7000,  8000,  9000, 10000, 12000 }, 

														  { 1000, 2000, 3000, 4000, 5000, 6000, 8000, 10000, 12000, 14000, 16000 } };

			s_rate_control.Artesa.vbr = 1; // CBR = 0, VBR = 1

			s_rate_control.Artesa.fixed = 0; // RATE_CONTROL_NORMAL = 0, RATE_CONTROL_FIXED = 1

			s_rate_control.Artesa.avg_bit_rate = VBR_BITRATE_TABLE[ idx ][ quality ];

			s_vbr_bit_rate.min_bit_rate = VBR_BITRATE_TABLE[ idx ][ quality ];

			s_vbr_bit_rate.max_bit_rate = VBR_BITRATE_TABLE[ idx ][ quality ];
		}
		if( mode == 1 ) {

			s_rate_control.Artesa.vbr = 0; // CBR = 0, VBR = 1

			s_rate_control.Artesa.fixed = 0; // RATE_CONTROL_NORMAL = 0, RATE_CONTROL_FIXED = 1

			s_rate_control.Artesa.avg_bit_rate = bitrate;

			s_vbr_bit_rate.min_bit_rate = bitrate;

			s_vbr_bit_rate.max_bit_rate = bitrate;
		}
		if( mode >= 2 ) {

			s_rate_control.Artesa.vbr = 1; // CBR = 0, VBR = 1

			s_rate_control.Artesa.fixed = 0; // RATE_CONTROL_NORMAL = 0, RATE_CONTROL_FIXED = 1

			s_rate_control.Artesa.avg_bit_rate = bitrate;

			s_vbr_bit_rate.min_bit_rate = (bitrate_min == 0) ? bitrate : bitrate_min;

			s_vbr_bit_rate.max_bit_rate = (bitrate_max == 0) ? bitrate : bitrate_max;
		}
		qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ 2 ], QPCODEC_PROP_RATE_CONTROL, (TQP_PVOID)(&s_rate_control), (TQP_PVOID)(&s_rate_control), 0 );
			
		qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ 2 ], QPCODEC_PROP_VBR_BIT_RATE, (TQP_PVOID)(&s_vbr_bit_rate), (TQP_PVOID)(&s_vbr_bit_rate), 0 );
		
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "RC = %d, QUALITY = %d, BITRATE = %d/%d/%d\n", mode, quality, s_rate_control.Artesa.avg_bit_rate, s_vbr_bit_rate.min_bit_rate, s_vbr_bit_rate.max_bit_rate);
	}
	if( pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ 0 ] & 0x88000000 ) {

		pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ 0 ] &= 0x77FFFFFF;

		ULONG gop = pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ 0 ] & 0x77FFFFFF;

		QPCODEC_GOP_LOOP_FILTER s_gop_loop_filter;
		
		RtlFillMemory( (BYTE*)&s_gop_loop_filter, sizeof(s_gop_loop_filter), 0x00 );

		qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ 2 ], QPCODEC_PROP_GOP_LOOP_FILTER, (TQP_PVOID)(&s_gop_loop_filter), (TQP_PVOID)(&s_gop_loop_filter), &size );
				
		s_gop_loop_filter.Artesa.intra_period = gop;

		s_gop_loop_filter.Artesa.B_num = 0;

		s_gop_loop_filter.Artesa.IDR = 1; // IDR_OPEN_GOP = 0, IDR_CLOSED_GOP = 1

		qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ 2 ], QPCODEC_PROP_GOP_LOOP_FILTER, (TQP_PVOID)(&s_gop_loop_filter), (TQP_PVOID)(&s_gop_loop_filter), 0 );
	
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "GOP = %d\n", s_gop_loop_filter.Artesa.intra_period);
	}
	if( pDevice->m_nAnalogVideoCompressionOverrideKeyframeProperty[ 0 ] == 0x00000001 ) {

		pDevice->m_nAnalogVideoCompressionOverrideKeyframeProperty[ 0 ] = 0x00000000;

		qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ 2 ], QPCODEC_PROP_INSERT_I_FRAME, NULL, NULL, 0 );

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "INSERT I\n");
	}
					
#endif

	return TRUE;
}

EQP_Errors E0E368BED109411F91924286A3FCCC1A( TQP_PVOID pContext, TQP_UINT32 dwCode, TQP_PVOID pParam );

EQP_Errors B193E8EB198B4259AED0BEB981811492( TQP_PVOID pContext, TQP_UINT32 dwCode, TQP_PVOID pParam );

EQP_Errors BC207F1D29F24ECBB93020F959BBA5EA( TQP_PVOID pContext, TQP_UINT32 dwCode, TQP_PVOID pParam );

BOOL AFE6193A7F444538885DA2E6AE62BF0E( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BOOL RESET, ULONG F6B9E557A4BA24ffd926B820B836289C8 )
{
#if defined(AME_PL330B) || defined(AME_PL330A)

	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] AFE6193A7F444538885DA2E6AE62BF0E()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

	ULONG cx = p_sys_cfg->n_input_video_resolution_cx;

	ULONG cy = p_sys_cfg->n_input_video_resolution_cy;

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 0 ] = 0;

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] = 0;

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ] = 0;

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 3 ] = 0;

	// [FIXED SIGMADESIGN BUG]
	//
	{	ULONG tmp = pDevice->m_nAnalogCrossbarAudioInputProperty;

		pDevice->m_nAnalogCrossbarAudioInputProperty = 1;

		E9D4315DBD2D4358B221B0E3A1963008( pDevice, -1, -1, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE );
	
		pDevice->m_nAnalogCrossbarAudioInputProperty = tmp;
		
		F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000000 );
	}
	ULONG i = 0;
	
	#ifdef NEVRON
	for( i = 1 ; i < 3 ; i++ ) {
	#else
	for( i = 0 ; i < 3 ; i++ ) {
	#endif

		if( pDevice->E23A0EAB120B4C609DC336EB8B99BE11[ i ]  != TQP_NULL_HANDLE ) {

			pDevice->m_pMpegCodec->Stop( pDevice->m_pMpegCodec, 

										 pDevice->E23A0EAB120B4C609DC336EB8B99BE11[ i ] );

			pDevice->m_pMpegCodec->Close( pDevice->m_pMpegCodec, 

										  pDevice->E23A0EAB120B4C609DC336EB8B99BE11[ i ]  );

			pDevice->E23A0EAB120B4C609DC336EB8B99BE11[ i ] = TQP_NULL_HANDLE;
		}
		if( pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ] != TQP_NULL_HANDLE ) {

			pDevice->m_pMpegCodec->ReleaseTask( pDevice->m_pMpegCodec, 

												pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ] );

			pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ] = TQP_NULL_HANDLE;
		}
	}
	B98859FFE32A4FC2A1A6B33CBCB91945( pDevice,  2, GPIO_OUTPUT );

	B98859FFE32A4FC2A1A6B33CBCB91945( pDevice,  3, GPIO_OUTPUT );

	B98859FFE32A4FC2A1A6B33CBCB91945( pDevice,  8, GPIO_OUTPUT );

	B98859FFE32A4FC2A1A6B33CBCB91945( pDevice, 11, GPIO_OUTPUT );
	
	if( ((pDevice->iProduct & 0xFF) == 0x15 && (pDevice->iManufacturer & 0xFF) == 0x4C) ||
		
		((pDevice->iProduct & 0xFF) == 0x15 && (pDevice->iManufacturer & 0xFF) == 0xAC) ) {

		E9D4315DBD2D4358B221B0E3A1963008( pDevice, -1, -1, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE );
	}
	else if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAD) ||
		
			 (pDevice->iManufacturer == 0x22) ||  // DARIM.4A.SC542N2-L HDMI
	
			 (pDevice->iManufacturer == 0x24) ||  // DARIM.4A.SC542N4 HDMI
	
			 (pDevice->iManufacturer == 0x2A) ||  // DARIM.4B.SC542N2-L SDI
	
			 (pDevice->iManufacturer == 0x2C) ||  // DARIM.4B.SC542N4 SDI
	
			 (pDevice->iManufacturer == 0x2E) ||  // DARIM.4B.SC542N4 HYBRID.2ND
	
			 (pDevice->iManufacturer == 0x27) ||  // DARIM.4B.SC542N6 HYBRID.2ND
	
			 (pDevice->iManufacturer == 0x44) ||
		
			 (pDevice->iManufacturer == 0x46) ||
		
			 (pDevice->iManufacturer == 0x4A) ||
		
			 (pDevice->iManufacturer == 0x4B) ||
		
			 (pDevice->iManufacturer == 0xA4) ||
		
			 (pDevice->iManufacturer == 0xA6) ||
		
			 (pDevice->iManufacturer == 0xAA) ||
		
			 (pDevice->iManufacturer == 0xAB) ) {

		E9D4315DBD2D4358B221B0E3A1963008( pDevice, -1, -1, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE );
	}
	else {
		//this will delay thread, so use another thread
		//E9D4315DBD2D4358B221B0E3A1963008( pDevice, pDevice->m_nAnalogCrossbarVideoInputProperty, pDevice->m_nAnalogCrossbarVideoOutputProperty, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE );
		/*
		struct task_struct * crossbar_thread = kthread_run( (INT)E9D4315DBD2D4358B221B0E3A1963008EX, pDevice, "E9D4315DBD2D4358B221B0E3A1963008EX" );

		if( IS_ERR( crossbar_thread ) ) {
		
			F966EAAB748564259849CBD3F3D6C48A7( KERN_ERR, "crossbar_thread() - kthread_run() - [FAIL]\n" ); 
		
			pDevice->m_nAnalogCrossbarVideoInputProperty = 0xFF;
		}
		*/
		PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		if( p_sys_cfg->m_b_is_old_mst3367_circuit == FALSE ) {

			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[2016 DESIGN]\n");
				
			E9D4315DBD2D4358B221B0E3A1963008( pDevice, -1, -1, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE );
		}
		else {

			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[2015 DESIGN+]\n");

		//	E9D4315DBD2D4358B221B0E3A1963008( pDevice, -1, -1, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE ); // QPCODEC_ERROR_RECOVERY_ON_ERROR

			E9D4315DBD2D4358B221B0E3A1963008( pDevice, pDevice->m_nAnalogCrossbarVideoInputProperty, pDevice->m_nAnalogCrossbarVideoOutputProperty, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE );
		}
		
	}
//	D585A1C8DE8349C5A903B8F61B5E0A9F( pDevice, NULL, TRUE );

	//move to E9D4315DBD2D4358B221B0E3A1963008EX
	AC2EB3596394401F99E0E3A4946A9436( pDevice, TRUE );
	
	if( RESET ) { 
		
		p_sys_cfg->b_input_video_signal_changed = TRUE; 
	
		return TRUE; 
	}
	if( F6B9E557A4BA24ffd926B820B836289C8 > 0 ) {

		F6B9E557A4BA24ffd926B820B836289C8_100NS( F6B9E557A4BA24ffd926B820B836289C8 );
	}
	//do not free preview buffer
	#ifdef NEVRON
	for( i = 1 ; i < 3 ; i++ ) {
	#else
	for( i = 0 ; i < 3 ; i++ ) {
	#endif		

		ULONG j = 0;
		for( j = 0 ; j < 16 ; j++ ) {
			
			//p_sys_cfg->o_output_dma_buffers[ i ][ j ].safeFree();
			
			if(p_sys_cfg->o_output_dma_buffers[ i ][ j ].image && (p_sys_cfg->o_output_dma_buffers[ i ][ j ].size != 0) )
			{
				vfree(p_sys_cfg->o_output_dma_buffers[ i ][ j ].image);

				p_sys_cfg->o_output_dma_buffers[ i ][ j ].image = NULL;

				p_sys_cfg->o_output_dma_buffers[ i ][ j ].size = 0;
			}
		}
	}


#endif

	return TRUE;
}

BOOL E395C7330A814EB6BB761D5A76D9E4B3( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

#if defined(AME_PL330B) || defined(AME_PL330A)

	if( pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] == 0 ) {

		ULONG  cx =  p_sys_cfg->n_input_video_resolution_cx;

		ULONG  cy =  p_sys_cfg->n_input_video_resolution_cy;

		ULONG fps = p_sys_cfg->n_input_video_resolution_fps;

		ULONG frq = p_sys_cfg->n_input_audio_sampling_frequency;

		ULONG interleaved = p_sys_cfg->n_input_video_resolution_interleaved;

//		ULONG cxe = (pDevice->m_nCustomPreviewVideoResolutionProperty[ 0 ] >> 12) & 0x00000FFF;
//
//		ULONG cye = (pDevice->m_nCustomPreviewVideoResolutionProperty[ 0 ] >> 0) & 0x00000FFF;

		ULONG cxe = 0;

		ULONG cye = 0;
		
		/*
		if( pDevice->m_pAnalogCaptureVideoStreamPin[ 0 ] == NULL ) { // VIDEO

			cxe = 0;

			cye = 0;
		}
		*/
		if( interleaved == 1 ) {

			cy <<= 1;

			fps >>= 1;
		}
		p_sys_cfg->n_output_video_resolution_lock = 1;

		if( cx == 0 ||

			cy == 0 ||

			fps == 0 ) {

		//	cx = 1920;
		//
		//	cy = 1080;
		//
		//	fps = 30;
		//
		//	interleaved = 0;

			cx = p_sys_cfg->n_output_video_resolution_cx;
		
			cy = p_sys_cfg->n_output_video_resolution_cy;
		
			fps = p_sys_cfg->n_output_video_resolution_fps;
		
			interleaved = p_sys_cfg->n_output_video_resolution_interleaved;

			p_sys_cfg->n_output_video_resolution_lock = 0;
		}
		if( cx == 0 ||

			cy == 0 ||

			fps == 0 ) {

			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"[%02d] E395C7330A814EB6BB761D5A76D9E4B3() no resolution\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);
	
			cx = 1920;

			cy = 1080;

			fps = 30;

			interleaved = 0;

			p_sys_cfg->n_output_video_resolution_lock = 0;
		}
		if( frq == 0 ) {

			frq = 48000;
		}

		if(pDevice->m_pVideo[ 0 ][ 0 ])
		{
			cxe = pDevice->m_pVideo[ 0 ][ 0 ]->FD1832F8D382F4e91914C0048CC5A9DD8;

			cye = pDevice->m_pVideo[ 0 ][ 0 ]->F5B8891B732954fc2B26B7BFFCB15B596;
		}
		//??
		//h264 no signal maybe error here

		if( cxe == 0 ) { cxe = cx; }

		if( cye == 0 ) { cye = cy; }

		if( cxe > cx ) { cxe = cx; }

		if( cye > cy ) { cye = cy; }

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] E395C7330A814EB6BB761D5A76D9E4B3() cxe(%d) cye(%d) fps(%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, cxe, cye, fps);

		p_sys_cfg->n_output_video_resolution_cx = cxe;

		p_sys_cfg->n_output_video_resolution_cy = cye;

		p_sys_cfg->n_output_video_resolution_fps = fps;

		p_sys_cfg->n_output_video_resolution_fps_m = p_sys_cfg->n_input_video_resolution_fps_m;

		p_sys_cfg->n_output_video_resolution_fps_yv12 = fps;

		p_sys_cfg->n_output_video_resolution_fps_h264 = fps;

		p_sys_cfg->n_output_video_resolution_interleaved = interleaved;

		p_sys_cfg->n_output_audio_sampling_frequency = frq;
		
		//?? can not set false 
		p_sys_cfg->b_input_video_signal_changed = FALSE;

		p_sys_cfg->n_output_firmware_reset = 0; 

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 0 ] = 0;

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] = 0;

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ] = 0;

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 3 ] = 0;

		ULONG n_stream_mask = 0x00000000;

#if 0
		if( pDevice->m_nAnalogCrossbarAudioInputProperty == 0 ) {

			ULONG temp = pDevice->m_nAnalogCrossbarAudioInputProperty;

			pDevice->m_nAnalogCrossbarAudioInputProperty = 1;

			E9D4315DBD2D4358B221B0E3A1963008( pDevice, -1, -1, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE );

			pDevice->m_nAnalogCrossbarAudioInputProperty = temp;

			E9D4315DBD2D4358B221B0E3A1963008( pDevice, -1, -1, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE );
		}
		else {

			ULONG temp = pDevice->m_nAnalogCrossbarAudioInputProperty;

			pDevice->m_nAnalogCrossbarAudioInputProperty = 0;

			E9D4315DBD2D4358B221B0E3A1963008( pDevice, -1, -1, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE );
			
			pDevice->m_nAnalogCrossbarAudioInputProperty = temp;

			E9D4315DBD2D4358B221B0E3A1963008( pDevice, -1, -1, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE );
		}
#endif
		ULONG i = 0;

		#ifdef NEVRON
		for( i = 1 ; i < 3 ; i++ ) {
		#else
		for( i = 0 ; i < 3 ; i++ ) {
		#endif
			if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB ) {

				if( i == 0 ) {

					continue ;
				}
			}
			if( (pDevice->iManufacturer & 0xF0) == (0x40) ) {
				
				//RAM speed must be over 1800MHz to suport audio with latency care customer			
				if(pDevice->F987A77560CED4a97977C18B30809471E == 0)
				{
					if( i == 1 ) {
						continue ;
					}
				}

				if( i == 2 ) {

					continue ;
				}
			}
#ifdef PL330B_ENABLE_60FPS

			if( i == 2 ) { continue ; }
#endif

//			if( pDevice->m_pAnalogCaptureVideoStreamPin[ 0 ] == NULL &&
//				
//				pDevice->m_pAnalogCaptureVideoStreamPin[ 1 ] == NULL && 
//				
//				pDevice->m_pAnalogCaptureVideoStreamPin[ 2 ] == NULL &&
//				
//				pDevice->m_pAnalogCaptureVideoStreamPin[ 3 ] == NULL ) { // VIDEO
//
//				if( i == 0 ) { continue ; }
//			}
//			if( pDevice->m_pAnalogCaptureAudioStreamPin[ 0 ] == NULL &&
//				
//				pDevice->m_pAnalogCaptureAudioStreamPin[ 1 ] == NULL &&
//				
//				pDevice->m_pAnalogCaptureAudioStreamPin[ 2 ] == NULL &&
//				
//				pDevice->m_pAnalogCaptureAudioStreamPin[ 3 ] == NULL ) { // AUDIO
//
//				if( i == 1 ) { continue ; }
//			}
//			if( pDevice->m_pAnalogCaptureVideoStreamPin[ 4 ] == NULL &&
//				
//				pDevice->m_pAnalogCaptureVideoStreamPin[ 5 ] == NULL && 
//				
//				pDevice->m_pAnalogCaptureVideoStreamPin[ 6 ] == NULL &&
//				
//				pDevice->m_pAnalogCaptureVideoStreamPin[ 7 ] == NULL ) { // H.264
//
//				if( i == 2 ) { continue ; }
//			}
			{	ULONG lengths = 8;

				if( i == 1 ) { lengths = 16; }

				ULONG j = 0;
				for( j = 0 ; j < lengths ; j++ ) {
					
					/*
					p_sys_cfg->o_output_dma_buffers[ i ][ j ].safeFree();

					if( i == 0 ) { p_sys_cfg->o_output_dma_buffers[ i ][ j ].image = ippiMalloc_8u_C1(  cxe, ((cye * 3) / 2) + 2, &(p_sys_cfg->o_output_dma_buffers[ i ][ j ].step) ); }

					if( i == 1 ) { p_sys_cfg->o_output_dma_buffers[ i ][ j ].image = ippiMalloc_8u_C1( 4096,                   2, &(p_sys_cfg->o_output_dma_buffers[ i ][ j ].step) ); }

					if( i == 2 ) { p_sys_cfg->o_output_dma_buffers[ i ][ j ].image = ippiMalloc_8u_C1(  cxe, ((cye * 3) / 2) + 2, &(p_sys_cfg->o_output_dma_buffers[ i ][ j ].step) ); }
					*/
				
					if(p_sys_cfg->o_output_dma_buffers[ i ][ j ].image && (p_sys_cfg->o_output_dma_buffers[ i ][ j ].size != 0) )
					{
						vfree(p_sys_cfg->o_output_dma_buffers[ i ][ j ].image);

						p_sys_cfg->o_output_dma_buffers[ i ][ j ].image = NULL;

						p_sys_cfg->o_output_dma_buffers[ i ][ j ].size = 0;
					}

					if( i == 0 ) { p_sys_cfg->o_output_dma_buffers[ i ][ j ].image = vmalloc_32(  cxe * (((cye * 3) / 2) + 2) ); }

					if( i == 1 ) { p_sys_cfg->o_output_dma_buffers[ i ][ j ].image = vmalloc_32( 4096 * 2 ); }

					if( i == 2 ) { p_sys_cfg->o_output_dma_buffers[ i ][ j ].image = vmalloc_32(  cxe * (((cye * 3) / 4) + 2) ); }
					

					if( i == 0 ) { p_sys_cfg->o_output_dma_buffers[ i ][ j ].size = ( cxe) * (((cye * 3) / 2) + 2); }

					if( i == 1 ) { p_sys_cfg->o_output_dma_buffers[ i ][ j ].size = (4096) * (                  2); }

					if( i == 2 ) { p_sys_cfg->o_output_dma_buffers[ i ][ j ].size = ( cxe) * (((cye * 3) / 4) + 2); }

					if( p_sys_cfg->o_output_dma_buffers[ i ][ j ].image ) {
						
						p_sys_cfg->o_output_dma_buffers[ i ][ j ].image[ 0 ] = (BYTE)(j);

						p_sys_cfg->o_output_dma_buffers[ i ][ j ].image[ 1 ] = 0x00;
						
						p_sys_cfg->o_output_dma_buffers[ i ][ j ].image[ 2 ] = 0x00;
						
						p_sys_cfg->o_output_dma_buffers[ i ][ j ].image[ 3 ] = 0x00;

						p_sys_cfg->o_output_dma_buffers[ i ][ j ].enable = FALSE;
					}
				}
			}
			
			n_stream_mask |= (1 << i);

			EQP_Errors qp_status = pDevice->m_pMpegCodec->AllocEncodeTask( pDevice->m_pMpegCodec, 
				
																		  &pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ] );
			if( QP_SUCCESS(qp_status) ) { 

				QPCODEC_ENC_ALL_SETTINGS s_enc_all_settings; RtlFillMemory( (BYTE*)&s_enc_all_settings, sizeof(s_enc_all_settings), 0x00 );

				QPCODEC_SYS_FUNCTION	 s_sys_function;     RtlFillMemory( (BYTE*)&s_sys_function, sizeof(s_sys_function), 0x00 );

				QPCODEC_SYS_LINK		 s_sys_link;         RtlFillMemory( (BYTE*)&s_sys_link, sizeof(s_sys_link), 0x00 );

				TQP_UINT32				 size = 0;

				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, 

													   (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL),

														pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ],

														QPCODEC_PROP_ENC_ALL_SETTINGS,

													   (TQP_PVOID)(&s_enc_all_settings),

													   (TQP_PVOID)(&s_enc_all_settings),
														
													   &size );

				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, 

													   (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL),

														pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ],

														QPCODEC_PROP_SYS_FUNCTION,

													   (TQP_PVOID)(&s_sys_function),

													   (TQP_PVOID)(&s_sys_function),
														
													   &size );

				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, 

													   (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL),

														pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ],

														QPCODEC_PROP_SYS_LINK,

													   (TQP_PVOID)(&s_sys_link),

													   (TQP_PVOID)(&s_sys_link),
														
													   &size );
#if 0 // DEBUG

				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncSystemControl = %08X\n",                s_enc_all_settings.EncSystemControl);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncPictureResolution = %08X\n",            s_enc_all_settings.EncPictureResolution);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncInputControl = %08X\n",                 s_enc_all_settings.EncInputControl);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncSyncMode = %08X\n",                     s_enc_all_settings.EncSyncMode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncRateControl = %08X\n",                  s_enc_all_settings.EncRateControl);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncRateControlEx = %08X\n",                s_enc_all_settings.EncRateControlEx);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncBitRate = %08X\n",                      s_enc_all_settings.EncBitRate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncFilterControl = %08X\n",                s_enc_all_settings.EncFilterControl);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncGopLoopFilter = %08X\n",                s_enc_all_settings.EncGopLoopFilter);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncEtControl = %08X\n",                    s_enc_all_settings.EncEtControl);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncOutPictureResolution = %08X\n",         s_enc_all_settings.EncOutPictureResolution);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncBlockXferSize = %08X\n",                s_enc_all_settings.EncBlockXferSize);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncAudioControlParam = %08X\n",            s_enc_all_settings.EncAudioControlParam);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncAudioControlExAAC = %08X\n",            s_enc_all_settings.EncAudioControlExAAC);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncAudioControlExG711 = %08X\n",           s_enc_all_settings.EncAudioControlExG711);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncAudioControlExLPCM = %08X\n",           s_enc_all_settings.EncAudioControlExLPCM);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncIndexCapFreq = %08X\n",                 s_enc_all_settings.EncIndexCapFreq);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncMP4VideoBlockNumber = %08X\n",          s_enc_all_settings.EncMP4VideoBlockNumber);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncStopMode = %08X\n",                     s_enc_all_settings.EncStopMode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncEnableVidPadding = %08X\n",             s_enc_all_settings.EncEnableVidPadding);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncMjpegQuality = %08X\n",                 s_enc_all_settings.EncMjpegQuality);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncMjpegFrameBuffer = %08X\n",             s_enc_all_settings.EncMjpegFrameBuffer);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncDecimationInputFormat = %08X\n",        s_enc_all_settings.EncDecimationInputFormat);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncDecimationOutputFormat = %08X\n",       s_enc_all_settings.EncDecimationOutputFormat);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncDecimationScaleFactor = %08X\n",        s_enc_all_settings.EncDecimationScaleFactor);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.DeinterlaceMode = %08X\n",                 s_enc_all_settings.DeinterlaceMode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncExternalTriggerToSyncEnable = %08X\n",  s_enc_all_settings.EncExternalTriggerToSyncEnable);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncExternalTriggerToSyncGpioPin = %08X\n", s_enc_all_settings.EncExternalTriggerToSyncGpioPin);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncPTSResetByTriggerEnable = %08X\n",      s_enc_all_settings.EncPTSResetByTriggerEnable);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncPTSResetByTriggerGpioPin = %08X\n",     s_enc_all_settings.EncPTSResetByTriggerGpioPin);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncPTSResetByTriggerImmediate = %08X\n",   s_enc_all_settings.EncPTSResetByTriggerImmediate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncAudioControlExSILK = %08X\n",           s_enc_all_settings.EncAudioControlExSILK);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.LargeCompressBufferControl = %08X\n",      s_enc_all_settings.LargeCompressBufferControl);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EnableLowBitrateMode = %08X\n",            s_enc_all_settings.EnableLowBitrateMode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EnableAVDiscardControl = %08X\n",          s_enc_all_settings.EnableAVDiscardControl);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.UseSWPTS = %08X\n",                        s_enc_all_settings.UseSWPTS);

				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_FUNCTION.function = %08X\n",                 s_sys_function.function);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_FUNCTION.functionEx.video = %08X\n",         s_sys_function.functionEx.video);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_FUNCTION.functionEx.audio = %08X\n",         s_sys_function.functionEx.audio);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_FUNCTION.functionEx.function = %08X\n",      s_sys_function.functionEx.function);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_FUNCTION.functionEx.version = %08X\n",       s_sys_function.functionEx.version);

				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.video_input = %08X\n",                  s_sys_link.video_input);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.video_in_ch = %08X\n",                  s_sys_link.video_in_ch);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.video_output = %08X\n",                 s_sys_link.video_output);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.video_out_ch = %08X\n",                 s_sys_link.video_out_ch);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.audio_input = %08X\n",                  s_sys_link.audio_input);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.audio_in_ch = %08X\n",                  s_sys_link.audio_in_ch);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.audio_output = %08X\n",                 s_sys_link.audio_output);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.audio_out_ch = %08X\n",                 s_sys_link.audio_out_ch);

				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "#############################################################################\n");
#endif
				{	s_enc_all_settings.EncSystemControl = 0x2101B20B; // SYSTEM_CONTROL

					s_enc_all_settings.EncPictureResolution = (cx << 0) | (cy << 16); // PICTURE_RESOLUTION

					s_enc_all_settings.EncInputControl = 0x0F5E0611; // INPUT_CONTROL

					s_enc_all_settings.EncSyncMode = 0x00000005; // TQP_UINT32

					s_enc_all_settings.EncRateControl = 0x00500FA0; // RATE_CONTROL

					s_enc_all_settings.EncRateControlEx; // RATE_CONTROL_EX

					s_enc_all_settings.EncBitRate = 0x1F4007D0; // BIT_RATE

					s_enc_all_settings.EncFilterControl = 0x80002000; // FILTER_CONTROL

					s_enc_all_settings.EncGopLoopFilter = 0x6001001E; // GOP_LOOP_FILTER

					s_enc_all_settings.EncEtControl = 0x00000000; // ET_CONTROL

					s_enc_all_settings.EncOutPictureResolution = (cx << 0) | (cy << 16); // OUT_PICTURE_RESOLUTION

					s_enc_all_settings.EncBlockXferSize = 0x00000010; // BLOCK_XFER_SIZE

					s_enc_all_settings.EncAudioControlParam = 0x21121080; // AUDIO_CONTROL_PARAM

					s_enc_all_settings.EncAudioControlExAAC = 0x465000F2; // AUDIO_CONTROL_EX_AAC

					s_enc_all_settings.EncAudioControlExG711 = 0x00000000; // AUDIO_CONTROL_EX_G711

					s_enc_all_settings.EncAudioControlExLPCM = 0x00000200; // AUDIO_CONTROL_EX_LPCM

					s_enc_all_settings.EncAudioControlExSILK; // AUDIO_CONTROL_EX_SILK

					s_enc_all_settings.EncIndexCapFreq = 0x00000020; // TQP_UINT32

					s_enc_all_settings.EncMP4VideoBlockNumber = 0x00000005; // TQP_UINT32

					s_enc_all_settings.EncStopMode = 0x00000000; // TQP_UINT32

					s_enc_all_settings.EncEnableVidPadding = 0x00000001; // TQP_BOOL

					s_enc_all_settings.EncMjpegQuality; // TQP_UINT32

					s_enc_all_settings.EncMjpegFrameBuffer; // TQP_UINT32

					s_enc_all_settings.EncDecimationInputFormat; // QPCODEC_DECIMATION_FACTOR.INPUT_FORMAT

					s_enc_all_settings.EncDecimationOutputFormat; // QPCODEC_DECIMATION_FACTOR.OUTPUT_FORMAT

					s_enc_all_settings.EncDecimationScaleFactor; // QPCODEC_DECIMATION_FACTOR.SCALE_FACTOR

					s_enc_all_settings.DeinterlaceMode; // TQP_UINT32

					s_enc_all_settings.EncExternalTriggerToSyncEnable; // QPCODEC_EXTERNAL_TRIGGER_MODEE.ENABLE

					s_enc_all_settings.EncExternalTriggerToSyncGpioPin; // QPCODEC_EXTERNAL_TRIGGER_MODE.GPIOPIN

					s_enc_all_settings.EncPTSResetByTriggerEnable; // QPCODEC_PTS_COUNTER_RESET.ENABLE

					s_enc_all_settings.EncPTSResetByTriggerGpioPin; // QPCODEC_PTS_COUNTER_RESET.GPIOPIN

					s_enc_all_settings.EncPTSResetByTriggerImmediate; // QPCODEC_PTS_COUNTER_RESET.IMMEDIATE

					s_enc_all_settings.LargeCompressBufferControl; // TQP_UINT32

					s_enc_all_settings.EnableLowBitrateMode; // TQP_UINT32

					s_enc_all_settings.EnableAVDiscardControl; // TQP_UINT32

					s_enc_all_settings.UseSWPTS; // TQP_UINT32

					s_sys_function.functionEx.video = 1; // CODEC_OPEN_EX_VID_NONE = 0, CODEC_OPEN_EX_VID_H264 = 1

					s_sys_function.functionEx.audio = 1; // CODEC_OPEN_EX_AUD_NONE = 0, CODEC_OPEN_EX_AUD = 1

					s_sys_function.functionEx.function = 0; // CODEC_OPEN_EX_ENCODE = 0, CODEC_OPEN_EX_DECODE = 1

					s_sys_function.functionEx.version = 1;

					s_sys_link.video_input = 0; // SYS_LINK_VID_IN_VIU = 0, SYS_LINK_VID_IN_HOST = 1

					s_sys_link.video_in_ch = 0;

					s_sys_link.video_output = 1; // SYS_LINK_VID_OUT_VOU = 0, SYS_LINK_VID_OUT_HOST = 1

					s_sys_link.video_out_ch = 0;

					s_sys_link.audio_input = 0; // SYS_LINK_AUD_IN_AIU = 0, SYS_LINK_AUD_IN_HOST = 1

					s_sys_link.audio_in_ch = 0;

					s_sys_link.audio_output = 1; // SYS_LINK_AUD_OUT_AOU = 0, SYS_LINK_AUD_OUT_HOST = 1

					s_sys_link.audio_out_ch = 0;
				}
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, 

													   (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL),

														pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ],

														QPCODEC_PROP_ENC_ALL_SETTINGS,

													   (TQP_PVOID)(&s_enc_all_settings),

													   (TQP_PVOID)(&s_enc_all_settings),
														
														0 );

				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, 

													   (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL),

														pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ],

														QPCODEC_PROP_SYS_FUNCTION,

													   (TQP_PVOID)(&s_sys_function),

													   (TQP_PVOID)(&s_sys_function),
														
														0 );

				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, 

													   (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL),

														pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ],

														QPCODEC_PROP_SYS_LINK,

													   (TQP_PVOID)(&s_sys_link),

													   (TQP_PVOID)(&s_sys_link),
														
														0 );
#if 0 // DEBUG [IMPORTANT]

				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_ENC_ALL_SETTINGS, (TQP_PVOID)(&s_enc_all_settings), (TQP_PVOID)(&s_enc_all_settings), &size );

				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_SYS_FUNCTION,     (TQP_PVOID)(&s_sys_function),     (TQP_PVOID)(&s_sys_function),     &size );

				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_SYS_LINK,         (TQP_PVOID)(&s_sys_link),         (TQP_PVOID)(&s_sys_link),         &size );

				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncSystemControl = %08X\n",                s_enc_all_settings.EncSystemControl);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncPictureResolution = %08X\n",            s_enc_all_settings.EncPictureResolution);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncInputControl = %08X\n",                 s_enc_all_settings.EncInputControl);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncSyncMode = %08X\n",                     s_enc_all_settings.EncSyncMode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncRateControl = %08X\n",                  s_enc_all_settings.EncRateControl);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncRateControlEx = %08X\n",                s_enc_all_settings.EncRateControlEx);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncBitRate = %08X\n",                      s_enc_all_settings.EncBitRate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncFilterControl = %08X\n",                s_enc_all_settings.EncFilterControl);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncGopLoopFilter = %08X\n",                s_enc_all_settings.EncGopLoopFilter);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncEtControl = %08X\n",                    s_enc_all_settings.EncEtControl);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncOutPictureResolution = %08X\n",         s_enc_all_settings.EncOutPictureResolution);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncBlockXferSize = %08X\n",                s_enc_all_settings.EncBlockXferSize);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncAudioControlParam = %08X\n",            s_enc_all_settings.EncAudioControlParam);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncAudioControlExAAC = %08X\n",            s_enc_all_settings.EncAudioControlExAAC);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncAudioControlExG711 = %08X\n",           s_enc_all_settings.EncAudioControlExG711);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncAudioControlExLPCM = %08X\n",           s_enc_all_settings.EncAudioControlExLPCM);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncIndexCapFreq = %08X\n",                 s_enc_all_settings.EncIndexCapFreq);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncMP4VideoBlockNumber = %08X\n",          s_enc_all_settings.EncMP4VideoBlockNumber);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncStopMode = %08X\n",                     s_enc_all_settings.EncStopMode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncEnableVidPadding = %08X\n",             s_enc_all_settings.EncEnableVidPadding);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncMjpegQuality = %08X\n",                 s_enc_all_settings.EncMjpegQuality);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncMjpegFrameBuffer = %08X\n",             s_enc_all_settings.EncMjpegFrameBuffer);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncDecimationInputFormat = %08X\n",        s_enc_all_settings.EncDecimationInputFormat);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncDecimationOutputFormat = %08X\n",       s_enc_all_settings.EncDecimationOutputFormat);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncDecimationScaleFactor = %08X\n",        s_enc_all_settings.EncDecimationScaleFactor);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.DeinterlaceMode = %08X\n",                 s_enc_all_settings.DeinterlaceMode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncExternalTriggerToSyncEnable = %08X\n",  s_enc_all_settings.EncExternalTriggerToSyncEnable);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncExternalTriggerToSyncGpioPin = %08X\n", s_enc_all_settings.EncExternalTriggerToSyncGpioPin);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncPTSResetByTriggerEnable = %08X\n",      s_enc_all_settings.EncPTSResetByTriggerEnable);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncPTSResetByTriggerGpioPin = %08X\n",     s_enc_all_settings.EncPTSResetByTriggerGpioPin);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncPTSResetByTriggerImmediate = %08X\n",   s_enc_all_settings.EncPTSResetByTriggerImmediate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EncAudioControlExSILK = %08X\n",           s_enc_all_settings.EncAudioControlExSILK);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.LargeCompressBufferControl = %08X\n",      s_enc_all_settings.LargeCompressBufferControl);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EnableLowBitrateMode = %08X\n",            s_enc_all_settings.EnableLowBitrateMode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.EnableAVDiscardControl = %08X\n",          s_enc_all_settings.EnableAVDiscardControl);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_ALL_SETTINGS.UseSWPTS = %08X\n",                        s_enc_all_settings.UseSWPTS);

				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_FUNCTION.function = %08X\n",                 s_sys_function.function);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_FUNCTION.functionEx.video = %08X\n",         s_sys_function.functionEx.video);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_FUNCTION.functionEx.audio = %08X\n",         s_sys_function.functionEx.audio);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_FUNCTION.functionEx.function = %08X\n",      s_sys_function.functionEx.function);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_FUNCTION.functionEx.version = %08X\n",       s_sys_function.functionEx.version);

				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.video_input = %08X\n",                  s_sys_link.video_input);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.video_in_ch = %08X\n",                  s_sys_link.video_in_ch);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.video_output = %08X\n",                 s_sys_link.video_output);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.video_out_ch = %08X\n",                 s_sys_link.video_out_ch);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.audio_input = %08X\n",                  s_sys_link.audio_input);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.audio_in_ch = %08X\n",                  s_sys_link.audio_in_ch);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.audio_output = %08X\n",                 s_sys_link.audio_output);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.audio_out_ch = %08X\n",                 s_sys_link.audio_out_ch);

				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "#############################################################################\n");
#endif
				QPCODEC_SYS_CONFIG             s_sys_config;             RtlFillMemory( (BYTE*)&s_sys_config, sizeof(s_sys_config), 0x00 );
				QPCODEC_SYSTEM_CONTROL         s_system_control;         RtlFillMemory( (BYTE*)&s_system_control, sizeof(s_system_control), 0x00 );
				QPCODEC_PICTURE_RESOLUTION     s_picture_resolution;     RtlFillMemory( (BYTE*)&s_picture_resolution, sizeof(s_picture_resolution), 0x00 );
				QPCODEC_OUT_PICTURE_RESOLUTION s_out_picture_resolution; RtlFillMemory( (BYTE*)&s_out_picture_resolution, sizeof(s_out_picture_resolution), 0x00 );
				QPCODEC_ENC_CAP_MODE           s_enc_cap_mode;           RtlFillMemory( (BYTE*)&s_enc_cap_mode, sizeof(s_enc_cap_mode), 0x00 );
				QPCODEC_INPUT_CONTROL          s_input_control;          RtlFillMemory( (BYTE*)&s_input_control, sizeof(s_input_control), 0x00 );
				QPCODEC_RATE_CONTROL           s_rate_control;           RtlFillMemory( (BYTE*)&s_rate_control, sizeof(s_rate_control), 0x00 );
				QPCODEC_VBR_BIT_RATE           s_vbr_bit_rate;           RtlFillMemory( (BYTE*)&s_vbr_bit_rate, sizeof(s_vbr_bit_rate), 0x00 );
				QPCODEC_GOP_LOOP_FILTER        s_gop_loop_filter;        RtlFillMemory( (BYTE*)&s_gop_loop_filter, sizeof(s_gop_loop_filter), 0x00 );
				QPCODEC_FILTER_CONTROL         s_filter_control;         RtlFillMemory( (BYTE*)&s_filter_control, sizeof(s_filter_control), 0x00 );
				QPCODEC_ET_CONTROL			   s_et_control;			 RtlFillMemory( (BYTE*)&s_et_control, sizeof(s_et_control), 0x00 );
				QPCODEC_AUDIO_CONTROL_PARAM    s_audio_control_param;    RtlFillMemory( (BYTE*)&s_audio_control_param, sizeof(s_audio_control_param), 0x00 );
				QPCODEC_AUDIO_CONTROL_EX       s_audio_control_ex;       RtlFillMemory( (BYTE*)&s_audio_control_ex, sizeof(s_audio_control_ex), 0x00 );
				TQP_UINT32					   n_prop_large_compress_buffer_control = 0;
				TQP_UINT32					   n_prop_deinterlace = 0;
				TQP_UINT32					   n_prop_viu_sync_code_1 = 0xF1F1F1DA;
				TQP_UINT32					   n_prop_viu_sync_code_2 = 0xB6F1F1B6;

				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_SYS_CONFIG,                    (TQP_PVOID)(&s_sys_config),                         (TQP_PVOID)(&s_sys_config),                         &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_SYSTEM_CONTROL,                (TQP_PVOID)(&s_system_control),                     (TQP_PVOID)(&s_system_control),                     &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_PICTURE_RESOLUTION,            (TQP_PVOID)(&s_picture_resolution),                 (TQP_PVOID)(&s_picture_resolution),                 &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_OUT_PICTURE_RESOLUTION,        (TQP_PVOID)(&s_out_picture_resolution),             (TQP_PVOID)(&s_out_picture_resolution),             &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_ENC_CAP_MODE,                  (TQP_PVOID)(&s_enc_cap_mode),                       (TQP_PVOID)(&s_enc_cap_mode),                       &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_INPUT_CONTROL,                 (TQP_PVOID)(&s_input_control),                      (TQP_PVOID)(&s_input_control),                      &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_RATE_CONTROL,                  (TQP_PVOID)(&s_rate_control),                       (TQP_PVOID)(&s_rate_control),                       &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_VBR_BIT_RATE,                  (TQP_PVOID)(&s_vbr_bit_rate),                       (TQP_PVOID)(&s_vbr_bit_rate),                       &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_GOP_LOOP_FILTER,               (TQP_PVOID)(&s_gop_loop_filter),                    (TQP_PVOID)(&s_gop_loop_filter),                    &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_FILTER_CONTROL,                (TQP_PVOID)(&s_filter_control),                     (TQP_PVOID)(&s_filter_control),                     &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_ET_CONTROL,                    (TQP_PVOID)(&s_et_control),                         (TQP_PVOID)(&s_et_control),                         &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_AUDIO_CONTROL_PARAM,           (TQP_PVOID)(&s_audio_control_param),                (TQP_PVOID)(&s_audio_control_param),                &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_AUDIO_CONTROL_EX,              (TQP_PVOID)(&s_audio_control_ex),                   (TQP_PVOID)(&s_audio_control_ex),                   &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_SYS_FUNCTION,                  (TQP_PVOID)(&s_sys_function),                       (TQP_PVOID)(&s_sys_function),                       &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_SYS_LINK,                      (TQP_PVOID)(&s_sys_link),                           (TQP_PVOID)(&s_sys_link),                           &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_LARGE_COMPRESS_BUFFER_CONTROL, (TQP_PVOID)(&n_prop_large_compress_buffer_control), (TQP_PVOID)(&n_prop_large_compress_buffer_control), &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_DEINTERLACE,                   (TQP_PVOID)(&n_prop_deinterlace),                   (TQP_PVOID)(&n_prop_deinterlace),                   &size );

#if 0 // DEBUG

				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_CONFIG.version = %08X\n",                         s_sys_config.version);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_CONFIG.fixedMode = %08X\n",                       s_sys_config.fixedMode);
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.stream_type = %08X\n",          s_system_control.Artesa.stream_type);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.stream_data = %08X\n",          s_system_control.Artesa.stream_data);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.profile = %08X\n",              s_system_control.Artesa.profile);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.level = %08X\n",                s_system_control.Artesa.level);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.ff_mode = %08X\n",              s_system_control.Artesa.ff_mode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.spsr_freq = %08X\n",            s_system_control.Artesa.spsr_freq);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.v_mode = %08X\n",               s_system_control.Artesa.v_mode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.cabac_init_idc = %08X\n",       s_system_control.Artesa.cabac_init_idc);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.version = %08X\n",              s_system_control.Artesa.version);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.xfer_mode = %08X\n",            s_system_control.Artesa.xfer_mode);
				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_PICTURE_RESOLUTION.Artesa.in_pic_width = %08X\n",     s_picture_resolution.Artesa.in_pic_width);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_PICTURE_RESOLUTION.Artesa.in_pic_height = %08X\n",    s_picture_resolution.Artesa.in_pic_height);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_OUT_PICTURE_RESOLUTION.out_pic_width = %08X\n",       s_out_picture_resolution.out_pic_width);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_OUT_PICTURE_RESOLUTION.out_pic_height = %08X\n",      s_out_picture_resolution.out_pic_height);
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_CAP_MODE.capMode = %08X\n",                       s_enc_cap_mode.capMode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_CAP_MODE.trigMode = %08X\n",                      s_enc_cap_mode.trigMode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_CAP_MODE.gpioPin = %08X\n",                       s_enc_cap_mode.gpioPin);
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.scan_format = %08X\n",           s_input_control.Artesa.scan_format);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.src_mode = %08X\n",              s_input_control.Artesa.src_mode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.sync_mode = %08X\n",             s_input_control.Artesa.sync_mode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.data_type = %08X\n",             s_input_control.Artesa.data_type);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.bytes_swap = %08X\n",            s_input_control.Artesa.bytes_swap);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.in_frame_rate = %08X\n",         s_input_control.Artesa.in_frame_rate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.out_frame_rate = %08X\n",        s_input_control.Artesa.out_frame_rate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.fmt = %08X\n",                   s_input_control.Artesa.fmt);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.pd_en = %08X\n",                 s_input_control.Artesa.pd_en);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.ck_edge = %08X\n",               s_input_control.Artesa.ck_edge);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.force_60p_in = %08X\n",          s_input_control.Artesa.force_60p_in);
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_RATE_CONTROL.Artesa.avg_bit_rate = %08X\n",           s_rate_control.Artesa.avg_bit_rate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_RATE_CONTROL.Artesa.qp_update_freq = %08X\n",         s_rate_control.Artesa.qp_update_freq);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_RATE_CONTROL.Artesa.mode = %08X\n",                   s_rate_control.Artesa.mode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_RATE_CONTROL.Artesa.fixed = %08X\n",                  s_rate_control.Artesa.fixed);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_RATE_CONTROL.Artesa.vbr = %08X\n",                    s_rate_control.Artesa.vbr);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_VBR_BIT_RATE.min_bit_rate = %08X\n",                  s_vbr_bit_rate.min_bit_rate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_VBR_BIT_RATE.max_bit_rate = %08X\n",                  s_vbr_bit_rate.max_bit_rate);
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.intra_period = %08X\n",        s_gop_loop_filter.Artesa.intra_period);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.lp_filter = %08X\n",           s_gop_loop_filter.Artesa.lp_filter);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.dis_lf_idc = %08X\n",          s_gop_loop_filter.Artesa.dis_lf_idc);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.alpha_offset = %08X\n",        s_gop_loop_filter.Artesa.alpha_offset);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.beta_offset = %08X\n",         s_gop_loop_filter.Artesa.beta_offset);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.B_num = %08X\n",               s_gop_loop_filter.Artesa.B_num);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.ref_n = %08X\n",               s_gop_loop_filter.Artesa.ref_n);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.t8x8 = %08X\n",                s_gop_loop_filter.Artesa.t8x8);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.ref_p = %08X\n",               s_gop_loop_filter.Artesa.ref_p);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.IDR = %08X\n",                 s_gop_loop_filter.Artesa.IDR);
				///////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_FILTER_CONTROL.start_pixel = %08X\n",                 s_filter_control.start_pixel);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_FILTER_CONTROL.fl_en = %08X\n",                       s_filter_control.fl_en);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_FILTER_CONTROL.filter_strength = %08X\n",             s_filter_control.filter_strength);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_FILTER_CONTROL.start_line = %08X\n",                  s_filter_control.start_line);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_FILTER_CONTROL.dis_skp = %08X\n",                     s_filter_control.dis_skp);
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.bit_rate = %08X\n",               s_audio_control_param.bit_rate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.ch_sel = %08X\n",                 s_audio_control_param.ch_sel);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.sample_rate = %08X\n",            s_audio_control_param.sample_rate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.aou_pass_en = %08X\n",            s_audio_control_param.aou_pass_en);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.ai_msb = %08X\n",                 s_audio_control_param.ai_msb);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.lrclk_i = %08X\n",                s_audio_control_param.lrclk_i);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.bclk_i = %08X\n",                 s_audio_control_param.bclk_i);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.ai_i2s = %08X\n",                 s_audio_control_param.ai_i2s);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.ai_rj = %08X\n",                  s_audio_control_param.ai_rj);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.ai_m = %08X\n",                   s_audio_control_param.ai_m);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.ch_num = %08X\n",                 s_audio_control_param.ch_num);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.pts = %08X\n",                    s_audio_control_param.pts);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.disAi = %08X\n",                  s_audio_control_param.disAi);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.raw = %08X\n",                    s_audio_control_param.raw);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.audio_type = %08X\n",             s_audio_control_param.audio_type);
				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_FUNCTION.functionEx.video = %08X\n",              s_sys_function.functionEx.video);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_FUNCTION.functionEx.audio = %08X\n",              s_sys_function.functionEx.audio);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_FUNCTION.functionEx.function = %08X\n",           s_sys_function.functionEx.function);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_FUNCTION.functionEx.version = %08X\n",            s_sys_function.functionEx.version);
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.video_input = %08X\n",                       s_sys_link.video_input);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.video_in_ch = %08X\n",                       s_sys_link.video_in_ch);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.video_output = %08X\n",                      s_sys_link.video_output);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.video_out_ch = %08X\n",                      s_sys_link.video_out_ch);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.audio_input = %08X\n",                       s_sys_link.audio_input);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.audio_in_ch = %08X\n",                       s_sys_link.audio_in_ch);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.audio_output = %08X\n",                      s_sys_link.audio_output);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_LINK.audio_out_ch = %08X\n",                      s_sys_link.audio_out_ch);
				//////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "#############################################################################\n");
#endif

				{	s_sys_config.fixedMode = 1; // DYNAMIC
					
				//	s_system_control.Artesa.stream_type = 1; // ARTESA_STREAM_TYPE_PROGRAM = 0, ARTESA_STREAM_TYPE_TRANSPORT = 1, ARTESA_STREAM_TYPE_ELEMENTARY = 3

				//	s_system_control.Artesa.stream_data = 0x01 | 0x02; // ARTESA_STREAM_DATA_VIDEO = 1, ARTESA_STREAM_DATA_AUDIO = 2, ARTESA_STREAM_DATA_VBI = 4

					if( i == 0 ) { s_system_control.Artesa.stream_type = 0x04; } // ARTESA_STREAM_TYPE_PROGRAM = 0, ARTESA_STREAM_TYPE_TRANSPORT = 1, ARTESA_STREAM_TYPE_ELEMENTARY = 3, ARTESA_STREAM_TYPE_RAW = 4
				
					if( i == 1 ) { s_system_control.Artesa.stream_type = 0x04; } // ARTESA_STREAM_TYPE_PROGRAM = 0, ARTESA_STREAM_TYPE_TRANSPORT = 1, ARTESA_STREAM_TYPE_ELEMENTARY = 3, ARTESA_STREAM_TYPE_RAW = 4
					
					if( i == 2 ) { s_system_control.Artesa.stream_type = 0x03; } // ARTESA_STREAM_TYPE_PROGRAM = 0, ARTESA_STREAM_TYPE_TRANSPORT = 1, ARTESA_STREAM_TYPE_ELEMENTARY = 3, ARTESA_STREAM_TYPE_RAW = 4

					if( i == 0 ) { s_system_control.Artesa.stream_data = 0x01; } // ARTESA_STREAM_DATA_VIDEO = 1, ARTESA_STREAM_DATA_AUDIO = 2, ARTESA_STREAM_DATA_VBI = 4
				
					if( i == 1 ) { s_system_control.Artesa.stream_data = 0x02; } // ARTESA_STREAM_DATA_VIDEO = 1, ARTESA_STREAM_DATA_AUDIO = 2, ARTESA_STREAM_DATA_VBI = 4
					
					if( i == 2 ) { s_system_control.Artesa.stream_data = 0x01; } // ARTESA_STREAM_DATA_VIDEO = 1, ARTESA_STREAM_DATA_AUDIO = 2, ARTESA_STREAM_DATA_VBI = 4
			
					ULONG avgs[ 2 ] = { pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] & 0x77FFFFFF,
					
										pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ 0 ] & 0x77FFFFFF };

					ULONG skips[ 2 ] = { (pDevice->m_nCustomAnalogVideoSkipFrameRateProperty[ 0 ] & 0x77FFFFFF) + (1), 
					
										 (pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ 0 ] & 0x77FFFFFF) + (1) };

					ULONG profile = pDevice->m_nCustomEncoderVideoProfileProperty[ 0 ] & 0x77FFFFFF; // 0 = HIGH PROFILE / 1 = BASELINE / 2 = MAIN PROFILE / 3 = HIGH PROFILE

					ULONG level = pDevice->m_nCustomEncoderVideoLevelProperty[ 0 ] & 0x77FFFFFF; // 0 = 41

					ULONG entropy = pDevice->m_nCustomEncoderVideoEntropyProperty[ 0 ] & 0x77FFFFFF; // 0 = CABAC / 1 = CAVLC / 2 = CABAC

					ULONG deinterlace = pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ 0 ] & 0x77FFFFFF; // 0 = OFF / 1 = ON

					ULONG mode = pDevice->m_nCustomEncoderVideoBitRateModeProperty[ 0 ] & 0x77FFFFFF;

					ULONG quality = pDevice->m_nAnalogVideoCompressionQualityProperty[ 0 ] & 0x77FFFFFF;

					ULONG quality_qp = pDevice->m_nAnalogVideoCompressionQualityProperty[ 0 ] & 0x77FFFFFF;

					ULONG bitrate = pDevice->m_nCustomEncoderVideoBitRateProperty[ 0 ] & 0x77FFFFFF;

					ULONG bitrate_max = pDevice->m_nCustomEncoderVideoPeakBitRateProperty[ 0 ] & 0x77FFFFFF;

					ULONG bitrate_min= pDevice->m_nCustomEncoderVideoTroughQualityProperty[ 0 ] & 0x77FFFFFF;

					ULONG gop = pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ 0 ] & 0x77FFFFFF;

					ULONG bframes = pDevice->m_nCustomEncoderVideoBframesPerKeyframeProperty[ 0 ] & 0x77FFFFFF;

					ULONG denoise = pDevice->m_nCustomAnalogVideoDenoiseTypeProperty[ 0 ] & 0x77FFFFFF;

					pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nCustomAnalogVideoSkipFrameRateProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nCustomEncoderVideoProfileProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nCustomEncoderVideoLevelProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nCustomEncoderVideoEntropyProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nCustomEncoderVideoBitRateModeProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nAnalogVideoCompressionQualityProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nCustomEncoderVideoBitRateProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nCustomEncoderVideoPeakBitRateProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nCustomEncoderVideoTroughQualityProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nCustomEncoderVideoBframesPerKeyframeProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nAnalogVideoCompressionOverrideKeyframeProperty[ 0 ] = 0x00000000;

					pDevice->m_nCustomPreviewVideoResolutionProperty[ 0 ] &= 0x77FFFFFF;

					pDevice->m_nCustomAnalogVideoDenoiseTypeProperty[ 0 ] &= 0x77FFFFFF;
							
					if( skips[ 0 ] == 1 ) {
						
						skips[ 0 ] = 0;
					}		
					if( avgs[ 0 ] > 0 ) {

						skips[ 0 ] = 0;
					}
					if( skips[ 1 ] == 1 ) {
						
						skips[ 1 ] = 0;
					}		
					if( avgs[ 1 ] > 0 ) {

						skips[ 1 ] = 0;
					}
					bitrate /= 1024; bitrate *= 1000; bitrate /= 1024;

					bitrate_max /= 1024; bitrate_max *= 1000; bitrate_max /= 1024;

					bitrate_min /= 1024; bitrate_min *= 1000; bitrate_min /= 1024;

					quality /= 1000;

					quality_qp *= (quality_qp * 51) / 10000;

					if( quality > 10 ) { quality = 10; }

					if( quality_qp > 51 ) { quality_qp = 51; }

					if( profile == 0 ) { s_system_control.Artesa.profile = 2; } // PROFILE_BASELINE = 0, PROFILE_MAIN = 1, PROFILE_EXTENDED = 2

					if( profile == 1 ) { s_system_control.Artesa.profile = 0; } // PROFILE_BASELINE = 0, PROFILE_MAIN = 1, PROFILE_EXTENDED = 2
					
					if( profile == 2 ) { s_system_control.Artesa.profile = 1; } // PROFILE_BASELINE = 0, PROFILE_MAIN = 1, PROFILE_EXTENDED = 2
					
					if( profile >= 3 ) { s_system_control.Artesa.profile = 2; } // PROFILE_BASELINE = 0, PROFILE_MAIN = 1, PROFILE_EXTENDED = 2
					
					if( entropy == 0 ) { s_system_control.Artesa.v_mode = 1; } // V_MODE_CAVLC = 0, V_MODE_CABAC = 1

					if( entropy == 1 ) { s_system_control.Artesa.v_mode = 0; } // V_MODE_CAVLC = 0, V_MODE_CABAC = 1

					if( entropy >= 2 ) { s_system_control.Artesa.v_mode = 1; } // V_MODE_CAVLC = 0, V_MODE_CABAC = 1

					if( level == 10 ) { s_system_control.Artesa.level =  0; } else // LEVEL_1
					if( level ==  9 ) { s_system_control.Artesa.level =  1; } else // LEVEL_1_B
					if( level == 11 ) { s_system_control.Artesa.level =  2; } else // LEVEL_1_1
					if( level == 12 ) { s_system_control.Artesa.level =  3; } else // LEVEL_1_2
					if( level == 13 ) { s_system_control.Artesa.level =  4; } else // LEVEL_1_3
					if( level == 20 ) { s_system_control.Artesa.level =  5; } else // LEVEL_2
					if( level == 21 ) { s_system_control.Artesa.level =  6; } else // LEVEL_2_1
					if( level == 22 ) { s_system_control.Artesa.level =  7; } else // LEVEL_2_2
					if( level == 30 ) { s_system_control.Artesa.level =  8; } else // LEVEL_3
					if( level == 31 ) { s_system_control.Artesa.level =  9; } else // LEVEL_3_1
					if( level == 32 ) { s_system_control.Artesa.level = 10; } else // LEVEL_3_2
					if( level == 40 ) { s_system_control.Artesa.level = 11; } else // LEVEL_4
					if( level == 41 ) { s_system_control.Artesa.level = 12; } else // LEVEL_4_1
					if( level == 42 ) { s_system_control.Artesa.level = 13; } else // LEVEL_4_2
					if( level == 50 ) { s_system_control.Artesa.level = 14; } else // LEVEL_5
					if( level == 51 ) { s_system_control.Artesa.level = 15; } else // LEVEL_5_1
									  { s_system_control.Artesa.level = 12; }      // LEVEL_4_1 (DEFAULT)

					if( cx != cxe || cy != cye ) {

						s_system_control.Artesa.ff_mode = 1; // FF_MODE_AUTO = 0, FF_MODE_FRAME_ONLY = 1, FF_MODE_FIELD_ONLY = 2
					}
					else {

						if( cx == 1920 &&
					
							cy == 1080 &&

							fps >= 30 &&
					
							interleaved == TRUE ) {

							if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB ) {

								s_system_control.Artesa.ff_mode = (interleaved >= 1 && deinterlace == 0) ? 2 : 1; // FF_MODE_AUTO = 0, FF_MODE_FRAME_ONLY = 1, FF_MODE_FIELD_ONLY = 2
							}
							else if( (pDevice->iManufacturer & 0xF0) == (0x40) ) {

								s_system_control.Artesa.ff_mode = (interleaved >= 1 && deinterlace != 1) ? 2 : 1; // FF_MODE_AUTO = 0, FF_MODE_FRAME_ONLY = 1, FF_MODE_FIELD_ONLY = 2
							}
							else {

								s_system_control.Artesa.ff_mode = 1; // [效能不足無法交錯式編碼], FF_MODE_AUTO = 0, FF_MODE_FRAME_ONLY = 1, FF_MODE_FIELD_ONLY = 2
							}
						}
						else {

							if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB ) {

								s_system_control.Artesa.ff_mode = (interleaved >= 1 && deinterlace == 0) ? 2 : 1; // FF_MODE_AUTO = 0, FF_MODE_FRAME_ONLY = 1, FF_MODE_FIELD_ONLY = 2
							}
							else {

								s_system_control.Artesa.ff_mode = (interleaved >= 1 && deinterlace != 1) ? 2 : 1; // FF_MODE_AUTO = 0, FF_MODE_FRAME_ONLY = 1, FF_MODE_FIELD_ONLY = 2
							}
						}
					}
					s_system_control.Artesa.spsr_freq = 1;

					s_picture_resolution.Artesa.in_pic_width = cx;

					s_picture_resolution.Artesa.in_pic_height = cy;
					
					s_out_picture_resolution.out_pic_width = cxe;

					s_out_picture_resolution.out_pic_height = cye;
					
					s_enc_cap_mode.capMode = 0; // QPCODEC_ENC_CAP_MODE_CONTINUOUS = 0, QPCODEC_ENC_CAP_MODE_ON_DEMAND = 1

					s_input_control.Artesa.scan_format = (interleaved) ? 0 : 1; // SCAN_FORMAT_INTERLACE = 0, SCAN_FORMAT_PROG = 1

					s_input_control.Artesa.src_mode = 1; //_MODE_ITU656 = 0, SRC_MODE_HDMI = 1

					s_input_control.Artesa.sync_mode = 17; // SYNC_MODE_NEG_POS = 15, SYNC_MODE_NEG_NEG = 16, SYNC_MODE_POS_POS = 17, SYNC_MODE_POS_NEG = 18

					s_input_control.Artesa.in_frame_rate = fps | 0x40; // IN_FRAME_RATE_ABSOLUTE = 0x80

					s_input_control.Artesa.out_frame_rate = fps;

					if( (pDevice->iManufacturer & 0xF0) == (0x40) ) {
				
						if( pDevice->iManufacturer == 0x21 ||  // DARIM.48.SC542N1-L HDV

								 pDevice->iManufacturer == 0x29 ||  // DARIM.43.SC542N2 HDV

								 pDevice->iManufacturer == 0x22 ||  // DARIM.4A.SC542N2-L HDMI
	
								 pDevice->iManufacturer == 0x24 ||  // DARIM.4A.SC542N4 HDMI
	
								 pDevice->iManufacturer == 0x2A ||  // DARIM.4B.SC542N2-L SDI

								 pDevice->iManufacturer == 0x2C ||  // DARIM.4B.SC542N4 SDI
	
								 pDevice->iManufacturer == 0x2D ||  // DARIM.49.SC542N4 HYBRID.1ST
	
								 pDevice->iManufacturer == 0x2E ||  // DARIM.4B.SC542N4 HYBRID.2ND
	
								 pDevice->iManufacturer == 0x26 ||  // DARIM.48.SC542N6 HYBRID.1ST
	
								 pDevice->iManufacturer == 0x27 ||  // DARIM.4B.SC542N6 HYBRID.2ND

								 pDevice->iManufacturer == 0x42 ||

								 pDevice->iManufacturer == 0x43 ||

								 pDevice->iManufacturer == 0x45 ||

								 pDevice->iManufacturer == 0x48 ||

								 pDevice->iManufacturer == 0x49 ||

								 pDevice->iManufacturer == 0x4A ||

								 pDevice->iManufacturer == 0x4B ||

								 pDevice->iManufacturer == 0x4D ) { // SC542NX

							PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

							p_sys_cfg->n_output_video_resolution_fps_1_2 = 0;
						}
						else { // SC540N1

							if( // (cx == 1280 && cy == 800 && fps >= 60) ||
						
								(cx * cy * fps) > (1920 * 1200 * 30) ) { 

								s_input_control.Artesa.out_frame_rate = fps >> 1;

								p_sys_cfg->n_output_video_resolution_fps_1_2 = 1;
							}
							else {
								
								p_sys_cfg->n_output_video_resolution_fps_1_2 = 0;
							}
						}
					}
					else {

						if( // (cx == 1280 && cy == 800 && fps >= 60) ||
						
							(cx * cy * fps) > (1920 * 1200 * 30) ) { 
#ifdef PL330B_ENABLE_60FPS
							s_input_control.Artesa.out_frame_rate = fps;
#else
							s_input_control.Artesa.out_frame_rate = fps >> 1;

							p_sys_cfg->n_output_video_resolution_fps_1_2 = 1;
#endif
						}
						else {
								
							p_sys_cfg->n_output_video_resolution_fps_1_2 = 0;
						}
					}
					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] n_output_video_resolution_fps_1_2(%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_sys_cfg->n_output_video_resolution_fps_1_2);

					if( p_sys_cfg->n_output_video_resolution_fps_1_2 == 1 ) {

						if( i == 0 ) { 	
							
							if( skips[ 0 ] > 0 ) {

								s_input_control.Artesa.out_frame_rate = (fps >> 1) / (skips[ 0 ]);
							}
							else if( avgs[ 0 ] > 0 ) {

								s_input_control.Artesa.out_frame_rate = (avgs[ 0 ] < (fps >> 1)) ? (avgs[ 0 ]) : (fps >> 1);
							}
						}
						if( i == 2 ) { 	
							
							if( skips[ 1 ] > 0 ) {

								s_input_control.Artesa.out_frame_rate = (fps >> 1) / (skips[ 1 ]);
							}
							else if( avgs[ 1 ] > 0 ) {

								s_input_control.Artesa.out_frame_rate = (avgs[ 1 ] < (fps >> 1)) ? (avgs[ 1 ]) : (fps >> 1);
							}
						}
					}
					else {
										
						if( i == 0 ) { 

							if( skips[ 0 ] > 0 ) {

								s_input_control.Artesa.out_frame_rate = (fps) / (skips[ 0 ]);
							}
							else if( avgs[ 0 ] > 0 ) {

								s_input_control.Artesa.out_frame_rate = (avgs[ 0 ] < (fps)) ? (avgs[ 0 ]) : (fps); (avgs[ 0 ]);
							}
						}
						if( i == 2 ) { 

							if( skips[ 1 ] > 0 ) {

								s_input_control.Artesa.out_frame_rate = (fps) / (skips[ 1 ]);
							}
							else if( avgs[ 1 ] > 0 ) {

								s_input_control.Artesa.out_frame_rate = (avgs[ 1 ] < (fps)) ? (avgs[ 1 ]) : (fps); (avgs[ 1 ]);
							}
						}
					}
					if( i == 0 ) { 

						p_sys_cfg->n_output_video_resolution_fps_yv12 = s_input_control.Artesa.out_frame_rate;
					}
					if( i == 2 ) { 

						p_sys_cfg->n_output_video_resolution_fps_h264 = s_input_control.Artesa.out_frame_rate;
					}
					if( mode == 0 ) {

						ULONG idx = 0;

						if( cx <=  720 ) { idx = 0; } else 

						if( cx <= 1360 ) { idx = 1; } else 

										 { idx = 2; } 

						static ULONG VBR_BITRATE_TABLE[ 3 ][ 11 ] = { {  500, 1000, 1500, 2000, 2500, 3000, 4000,  5000,  6000,  7000,  8000 }, 

																	  { 1000, 2000, 3000, 4000, 5000, 6000, 7000,  8000,  9000, 10000, 12000 }, 

																	  { 1000, 2000, 3000, 4000, 5000, 6000, 8000, 10000, 12000, 14000, 16000 } };

						s_rate_control.Artesa.vbr = 1; // CBR = 0, VBR = 1

						s_rate_control.Artesa.fixed = 0; // RATE_CONTROL_NORMAL = 0, RATE_CONTROL_FIXED = 1

						s_rate_control.Artesa.avg_bit_rate = VBR_BITRATE_TABLE[ idx ][ quality ];

						s_vbr_bit_rate.min_bit_rate = VBR_BITRATE_TABLE[ idx ][ quality ];

						s_vbr_bit_rate.max_bit_rate = VBR_BITRATE_TABLE[ idx ][ quality ];
					}
					if( mode == 1 ) {

						s_rate_control.Artesa.vbr = 0; // CBR = 0, VBR = 1

						s_rate_control.Artesa.fixed = 0; // RATE_CONTROL_NORMAL = 0, RATE_CONTROL_FIXED = 1

						s_rate_control.Artesa.avg_bit_rate = bitrate;

						s_vbr_bit_rate.min_bit_rate = bitrate;

						s_vbr_bit_rate.max_bit_rate = bitrate;
					}
					if( mode >= 2 ) {

						s_rate_control.Artesa.vbr = 1; // CBR = 0, VBR = 1

						s_rate_control.Artesa.fixed = 0; // RATE_CONTROL_NORMAL = 0, RATE_CONTROL_FIXED = 1

						s_rate_control.Artesa.avg_bit_rate = bitrate;

						s_vbr_bit_rate.min_bit_rate = (bitrate_min == 0) ? bitrate : bitrate_min;

						s_vbr_bit_rate.max_bit_rate = (bitrate_max == 0) ? bitrate : bitrate_max;
					}
					s_rate_control.Artesa.qp_update_freq = 1280 / 16;

					s_gop_loop_filter.Artesa.intra_period = gop;

					s_gop_loop_filter.Artesa.B_num = bframes;

					s_gop_loop_filter.Artesa.IDR = 1; // IDR_OPEN_GOP = 0, IDR_CLOSED_GOP = 1
					
					s_gop_loop_filter.Artesa.ref_n = (s_system_control.Artesa.ff_mode == 2) ? 0 : 1; // [INTERLEAVED] [2015.12.07] [修正 1080I 錯誤] [要確認延遲]

					s_gop_loop_filter.Artesa.ref_p = 1;

					s_gop_loop_filter.Artesa.t8x8 = 1;

					s_filter_control.start_line = 0;

					s_filter_control.start_pixel = 0;

					if( denoise >= 1 ) {

						s_filter_control.fl_en = 1;

						s_filter_control.filter_strength = denoise;
					}
					else {

						s_filter_control.fl_en = 0;

						s_filter_control.filter_strength = 0;
					}
				//	s_et_control.ref_num = 1; // REF_NUM_1_FRAMES = 1, REF_NUM_2_FRAMES = 2, REF_NUM_3_FRAMES = 0

					if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAD) ||
		
						(pDevice->iManufacturer == 0x21) || // DARIM.48.SC542N1-L HDV
						
						(pDevice->iManufacturer == 0x29) || // DARIM.43.SC542N2 HDV
						
						(pDevice->iManufacturer == 0x2A) || // DARIM.4B.SC542N2-L SDI
						
						(pDevice->iManufacturer == 0x2C) || // DARIM.4B.SC542N4 SDI
						
						(pDevice->iManufacturer == 0x2D) || // DARIM.49.SC542N4 HYBRID.1ST
						
						(pDevice->iManufacturer == 0x2E) || // DARIM.4B.SC542N4 HYBRID.2ND
						
						(pDevice->iManufacturer == 0x26) || // DARIM.48.SC542N6 HYBRID.1ST
						
						(pDevice->iManufacturer == 0x27) || // DARIM.4B.SC542N6 HYBRID.2ND
						
						(pDevice->iManufacturer == 0x40) ||
						
						(pDevice->iManufacturer == 0x41) ||
						
						(pDevice->iManufacturer == 0x42) ||
						
						(pDevice->iManufacturer == 0x43) ||
						
						(pDevice->iManufacturer == 0x44) ||
						
						(pDevice->iManufacturer == 0x48) ||
						
						(pDevice->iManufacturer == 0x49) ||
						
						(pDevice->iManufacturer == 0x4B) ||
						
						(pDevice->iManufacturer == 0xA0) ||
						
						(pDevice->iManufacturer == 0xA1) ||
						
						(pDevice->iManufacturer == 0xA2) ||
						
						(pDevice->iManufacturer == 0xA3) ||
						
						(pDevice->iManufacturer == 0xA4) ||
						
						(pDevice->iManufacturer == 0xA8) ||
						
						(pDevice->iManufacturer == 0xA9) ||
						
						(pDevice->iManufacturer == 0xAB) ||
						
						(pDevice->iManufacturer == 0xAE) ||
						
						(pDevice->iManufacturer == 0xAF) ) {
						
						BOOL is_sdi_only = FALSE;

						if(	(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAD) ||
		
							(pDevice->iManufacturer == 0x2A) || // DARIM.4B.SC542N2-L SDI

							(pDevice->iManufacturer == 0x2C) || // DARIM.4B.SC542N4 SDI
	
							(pDevice->iManufacturer == 0x2E) || // DARIM.4B.SC542N4 HYBRID.2ND
	
							(pDevice->iManufacturer == 0x27) || // DARIM.4B.SC542N6 HYBRID.2ND

							(pDevice->iManufacturer == 0x44) ||
						
							(pDevice->iManufacturer == 0x4B) ||
						
							(pDevice->iManufacturer == 0xA4) ||

							(pDevice->iManufacturer == 0xAB) ) {

							is_sdi_only = TRUE;
						}
						if( (is_sdi_only == TRUE && cx == 720) ||
							
							(pDevice->m_nAnalogCrossbarVideoInputProperty == 4 && cx == 720) ||
							
							(pDevice->m_nAnalogCrossbarVideoInputProperty == 5) ||

							(pDevice->m_nAnalogCrossbarVideoInputProperty == 6) ) {

							s_input_control.Artesa.scan_format = 0; // SCAN_FORMAT_INTERLACE = 0, SCAN_FORMAT_PROG = 1
							
							s_input_control.Artesa.src_mode = 0; //_MODE_ITU656 = 0, SRC_MODE_HDMI = 1

							if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_60HZ ) {

								n_prop_viu_sync_code_1 = 0xF1F1F1DA; // [僅支援 BT656] DA F1 F1 F1 B6

								n_prop_viu_sync_code_2 = 0xB6F1F1B6; // [僅支援 BT656]

								s_filter_control.start_pixel = 1; // 1ST 有 BUG 以後改

								s_filter_control.start_line = 19;
							}
							if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_50HZ ) {

								n_prop_viu_sync_code_1 = 0x000000DA; // [僅支援 BT656] F1 F1 F1 B6

								n_prop_viu_sync_code_2 = 0xB6F1F100; // [僅支援 BT656]

								s_filter_control.start_pixel = 1;

								//s_filter_control.start_line = 24;
								//peter add
								s_filter_control.start_line = 23;

							}
						}
					}
					s_audio_control_param.audio_type = 0; // AUDIO_TYPE_LPCM = 0, AUDIO_TYPE_AAC = 2, AUDIO_TYPE_RAW = 9

					s_audio_control_param.sample_rate = 1; // SAMPLE_RATE_32K = 2, SAMPLE_RATE_44_1K = 0, SAMPLE_RATE_48K = 1

					if( frq == 32000 ) { s_audio_control_param.sample_rate = 2; } // SAMPLE_RATE_32K = 2, SAMPLE_RATE_44_1K = 0, SAMPLE_RATE_48K = 1

					if( frq == 44100 ) { s_audio_control_param.sample_rate = 0; } // SAMPLE_RATE_32K = 2, SAMPLE_RATE_44_1K = 0, SAMPLE_RATE_48K = 1
				
					if( frq == 48000 ) { s_audio_control_param.sample_rate = 1; } // SAMPLE_RATE_32K = 2, SAMPLE_RATE_44_1K = 0, SAMPLE_RATE_48K = 1
					
					s_audio_control_param.bit_rate = 128;

					s_audio_control_param.ch_num = 2;

					s_audio_control_param.ch_sel = 0;

					s_audio_control_param.aou_pass_en = 0;

					s_audio_control_param.ai_msb = 1; // AI_MSB_LSB = 0, AI_MSB_MSB = 1

					s_audio_control_param.lrclk_i = 0; // LRCLK_I_LEFT_LOW = 0, LRCLK_I_LEFT_HIGH = 1

					s_audio_control_param.bclk_i = 0; // BCLK_I_RISING_EDGE = 0, BCLK_I_FALLING_EDGE = 1

					s_audio_control_param.ai_i2s = 1; // AI_I2S_NORMAL = 0, AI_I2S_PROGRAM = 1

					s_audio_control_param.ai_rj = 0; // AI_RJ_LEFT_JUSTIFIED = 0, AI_RJ_RIGHT_JUSTIFIED = 0

					s_audio_control_param.ai_m = 0; // AI_M_SLAVE = 0, AI_M_MASTER = 1

					s_audio_control_param.pts = 0;

					s_audio_control_param.disAi = 0;

					s_audio_control_param.raw = 0;

					s_audio_control_ex.sample_cnt = 4096 / 4;

					ULONG pcm_size = 1920; // 期望輸出大小

					if( p_sys_cfg->n_output_audio_sampling_frequency == 48000 ) { pcm_size = 1920; } // 期望輸出大小

					if( p_sys_cfg->n_output_audio_sampling_frequency == 44100 ) { pcm_size = 1280; } // 期望輸出大小

					if( p_sys_cfg->n_output_audio_sampling_frequency == 32000 ) { pcm_size = 1280; } // 期望輸出大小

					if( pDevice->m_nCustomAnalogAudioDirectSoundPatchProperty > 0 ) {

						s_audio_control_ex.sample_cnt = pcm_size / 4;
					}
					else {

						s_audio_control_ex.sample_cnt = 4096 / 4;

						#ifdef CUEBI_WEBRTC
						if(p_sys_cfg->n_output_audio_sampling_frequency == 48000)
						{
							s_audio_control_ex.sample_cnt = 4096 / 4;
						}
						else
						{
							s_audio_control_ex.sample_cnt = 2048 / 4;
						}
						#endif
					}
					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] sample_cnt(0d%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), s_audio_control_ex.sample_cnt );

					s_sys_function.functionEx.function = 0; // CODEC_OPEN_EX_ENCODE = 0, CODEC_OPEN_EX_DECODE = 1

					s_sys_function.functionEx.version = 1;

					if( i == 0 ) { s_sys_function.functionEx.video = 4; } // CODEC_OPEN_EX_VID_NONE = 0, CODEC_OPEN_EX_VID_H264 = 1, CODEC_OPEN_EX_VID_PASSTHROUGH = 4

					if( i == 1 ) { s_sys_function.functionEx.video = 0; } // CODEC_OPEN_EX_VID_NONE = 0, CODEC_OPEN_EX_VID_H264 = 1, CODEC_OPEN_EX_VID_PASSTHROUGH = 4
					
					if( i == 2 ) { s_sys_function.functionEx.video = 1; } // CODEC_OPEN_EX_VID_NONE = 0, CODEC_OPEN_EX_VID_H264 = 1, CODEC_OPEN_EX_VID_PASSTHROUGH = 4

					if( i == 0 ) { s_sys_function.functionEx.audio = 0; } // CODEC_OPEN_EX_AUD_NONE = 0, CODEC_OPEN_EX_AUD = 1, CODEC_OPEN_EX_AUD_PASSTHROUGH = 4

					if( i == 1 ) { s_sys_function.functionEx.audio = 4; } // CODEC_OPEN_EX_AUD_NONE = 0, CODEC_OPEN_EX_AUD = 1, CODEC_OPEN_EX_AUD_PASSTHROUGH = 4

					if( i == 2 ) { s_sys_function.functionEx.audio = 0; } // CODEC_OPEN_EX_AUD_NONE = 0, CODEC_OPEN_EX_AUD = 1, CODEC_OPEN_EX_AUD_PASSTHROUGH = 4

					if( i == 0 ) { s_sys_link.video_input = 0; } // SYS_LINK_VID_IN_VIU = 0, SYS_LINK_VID_IN_HOST = 1

					if( i == 1 ) { s_sys_link.video_input = 1; } // SYS_LINK_VID_IN_VIU = 0, SYS_LINK_VID_IN_HOST = 1

					if( i == 2 ) { s_sys_link.video_input = 0; } // SYS_LINK_VID_IN_VIU = 0, SYS_LINK_VID_IN_HOST = 1

					s_sys_link.video_in_ch = 0;

					s_sys_link.video_output = 1; // SYS_LINK_VID_OUT_VOU = 0, SYS_LINK_VID_OUT_HOST = 1

					s_sys_link.video_out_ch = 0;

					if( i == 0 ) { s_sys_link.audio_input = 1; } // SYS_LINK_AUD_IN_AIU = 0, SYS_LINK_AUD_IN_HOST = 1

					if( i == 1 ) { s_sys_link.audio_input = 0; } // SYS_LINK_AUD_IN_AIU = 0, SYS_LINK_AUD_IN_HOST = 1

					if( i == 2 ) { s_sys_link.audio_input = 1; } // SYS_LINK_AUD_IN_AIU = 0, SYS_LINK_AUD_IN_HOST = 1

					s_sys_link.audio_in_ch = 0;

					s_sys_link.audio_output = 1; // SYS_LINK_AUD_OUT_AOU = 0, SYS_LINK_AUD_OUT_HOST = 1

					s_sys_link.audio_out_ch = 0;

					n_prop_large_compress_buffer_control = 0x80000000 | 32000;

					if( cx != cxe || cy != cye ) {
									
						if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB ) {

							n_prop_deinterlace = ((interleaved) && (deinterlace >= 1)) ? 1 : 0; // QPCODEC_DEINTERLACE_NONE = 0, QPCODEC_DEINTERLACE_TOP_FIELD_MODE = 1, QPCODEC_DEINTERLACE_TWO_FIELD_MODE	= 2 [INTERLEAVED]
						}
						else {

							n_prop_deinterlace = ((interleaved) && (deinterlace == 1)) ? 1 : 0; // QPCODEC_DEINTERLACE_NONE = 0, QPCODEC_DEINTERLACE_TOP_FIELD_MODE = 1, QPCODEC_DEINTERLACE_TWO_FIELD_MODE	= 2 [INTERLEAVED]
						}
					}
					else {

						if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB ) {

							n_prop_deinterlace = (interleaved && (deinterlace >= 1)) ? 2 : 0; // QPCODEC_DEINTERLACE_NONE = 0, QPCODEC_DEINTERLACE_TOP_FIELD_MODE = 1, QPCODEC_DEINTERLACE_TWO_FIELD_MODE	= 2 [INTERLEAVED]
						}
						else {

							n_prop_deinterlace = (interleaved && (deinterlace == 1)) ? 2 : 0; // QPCODEC_DEINTERLACE_NONE = 0, QPCODEC_DEINTERLACE_TOP_FIELD_MODE = 1, QPCODEC_DEINTERLACE_TWO_FIELD_MODE	= 2 [INTERLEAVED]
						}
					}
					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "PROFILE = %d, ENTROPY = %d, DI = %d, GOP = %d, B = %d, RC = %d, QUALITY = %d, BITRATE = %d/%d/%d, SKIPS = %d/%d, AVGS = %d/%d (NATIVE.FPS = %d), DENOISE = %d/%d\n", 

						s_system_control.Artesa.profile, 
						
						s_system_control.Artesa.v_mode, 
						
						n_prop_deinterlace, 
						
						s_gop_loop_filter.Artesa.intra_period,
						
						s_gop_loop_filter.Artesa.B_num,
						
						mode,

						quality,
						
						s_rate_control.Artesa.avg_bit_rate, s_vbr_bit_rate.min_bit_rate, s_vbr_bit_rate.max_bit_rate,
						
						skips[ 0 ],
						
						skips[ 1 ],
						
						avgs[ 0 ],

						avgs[ 1 ],
						
						s_input_control.Artesa.out_frame_rate,

						s_filter_control.fl_en,

						s_filter_control.filter_strength );
				}
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_SYS_CONFIG,                    (TQP_PVOID)(&s_sys_config),                         (TQP_PVOID)(&s_sys_config),                         0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_SYSTEM_CONTROL,                (TQP_PVOID)(&s_system_control),                     (TQP_PVOID)(&s_system_control),                     0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_PICTURE_RESOLUTION,            (TQP_PVOID)(&s_picture_resolution),                 (TQP_PVOID)(&s_picture_resolution),                 0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_OUT_PICTURE_RESOLUTION,        (TQP_PVOID)(&s_out_picture_resolution),             (TQP_PVOID)(&s_out_picture_resolution),             0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_ENC_CAP_MODE,                  (TQP_PVOID)(&s_enc_cap_mode),                       (TQP_PVOID)(&s_enc_cap_mode),                       0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_INPUT_CONTROL,                 (TQP_PVOID)(&s_input_control),                      (TQP_PVOID)(&s_input_control),                      0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_RATE_CONTROL,                  (TQP_PVOID)(&s_rate_control),                       (TQP_PVOID)(&s_rate_control),                       0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_VBR_BIT_RATE,                  (TQP_PVOID)(&s_vbr_bit_rate),                       (TQP_PVOID)(&s_vbr_bit_rate),                       0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_GOP_LOOP_FILTER,               (TQP_PVOID)(&s_gop_loop_filter),                    (TQP_PVOID)(&s_gop_loop_filter),                    0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_FILTER_CONTROL,                (TQP_PVOID)(&s_filter_control),                     (TQP_PVOID)(&s_filter_control),                     0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_ET_CONTROL,                    (TQP_PVOID)(&s_et_control),                         (TQP_PVOID)(&s_et_control),                         0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_AUDIO_CONTROL_PARAM,           (TQP_PVOID)(&s_audio_control_param),                (TQP_PVOID)(&s_audio_control_param),                0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_AUDIO_CONTROL_EX,              (TQP_PVOID)(&s_audio_control_ex),                   (TQP_PVOID)(&s_audio_control_ex),                   0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_SYS_FUNCTION,                  (TQP_PVOID)(&s_sys_function),                       (TQP_PVOID)(&s_sys_function),                       0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_SYS_LINK,                      (TQP_PVOID)(&s_sys_link),                           (TQP_PVOID)(&s_sys_link),                           0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_LARGE_COMPRESS_BUFFER_CONTROL, (TQP_PVOID)(&n_prop_large_compress_buffer_control), (TQP_PVOID)(&n_prop_large_compress_buffer_control), 0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_DEINTERLACE,                   (TQP_PVOID)(&n_prop_deinterlace),                   (TQP_PVOID)(&n_prop_deinterlace),                   0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_VIU_SYN_CCODE_1,               (TQP_PVOID)(&n_prop_viu_sync_code_1),               (TQP_PVOID)(&n_prop_viu_sync_code_1),               0 );
				qp_status = pDevice->m_pMpegCodec->Set( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_VIU_SYN_CCODE_2,               (TQP_PVOID)(&n_prop_viu_sync_code_2),               (TQP_PVOID)(&n_prop_viu_sync_code_2),               0 );

#if 0 // DEBUG [IMPORTANT]

				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_SYS_CONFIG,             (TQP_PVOID)(&s_sys_config),             (TQP_PVOID)(&s_sys_config),             &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_SYSTEM_CONTROL,         (TQP_PVOID)(&s_system_control),         (TQP_PVOID)(&s_system_control),         &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_PICTURE_RESOLUTION,     (TQP_PVOID)(&s_picture_resolution),     (TQP_PVOID)(&s_picture_resolution),     &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_OUT_PICTURE_RESOLUTION, (TQP_PVOID)(&s_out_picture_resolution), (TQP_PVOID)(&s_out_picture_resolution), &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_ENC_CAP_MODE,           (TQP_PVOID)(&s_enc_cap_mode),           (TQP_PVOID)(&s_enc_cap_mode),           &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_INPUT_CONTROL,          (TQP_PVOID)(&s_input_control),          (TQP_PVOID)(&s_input_control),          &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_RATE_CONTROL,           (TQP_PVOID)(&s_rate_control),           (TQP_PVOID)(&s_rate_control),           &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_VBR_BIT_RATE,           (TQP_PVOID)(&s_vbr_bit_rate),           (TQP_PVOID)(&s_vbr_bit_rate),           &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_GOP_LOOP_FILTER,        (TQP_PVOID)(&s_gop_loop_filter),        (TQP_PVOID)(&s_gop_loop_filter),        &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_FILTER_CONTROL,         (TQP_PVOID)(&s_filter_control),         (TQP_PVOID)(&s_filter_control),         &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_AUDIO_CONTROL_PARAM,    (TQP_PVOID)(&s_audio_control_param),    (TQP_PVOID)(&s_audio_control_param),    &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_AUDIO_CONTROL_EX,       (TQP_PVOID)(&s_audio_control_ex),       (TQP_PVOID)(&s_audio_control_ex),       &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_SYS_FUNCTION,           (TQP_PVOID)(&s_sys_function),           (TQP_PVOID)(&s_sys_function),           &size );
				qp_status = pDevice->m_pMpegCodec->Get( pDevice->m_pMpegCodec, (TQP_REFGUID)(&PROPSETID_QPCODEC_CONTROL), pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], QPCODEC_PROP_SYS_LINK,               (TQP_PVOID)(&s_sys_link),               (TQP_PVOID)(&s_sys_link),               &size );

				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_CONFIG.version = %08X\n",                         s_sys_config.version);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYS_CONFIG.fixedMode = %08X\n",                       s_sys_config.fixedMode);
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.stream_type = %08X\n",          s_system_control.Artesa.stream_type);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.stream_data = %08X\n",          s_system_control.Artesa.stream_data);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.profile = %08X\n",              s_system_control.Artesa.profile);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.level = %08X\n",                s_system_control.Artesa.level);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.ff_mode = %08X\n",              s_system_control.Artesa.ff_mode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.spsr_freq = %08X\n",            s_system_control.Artesa.spsr_freq);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.v_mode = %08X\n",               s_system_control.Artesa.v_mode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.cabac_init_idc = %08X\n",       s_system_control.Artesa.cabac_init_idc);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.version = %08X\n",              s_system_control.Artesa.version);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_SYSTEM_CONTROL.Artesa.xfer_mode = %08X\n",            s_system_control.Artesa.xfer_mode);
				///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_PICTURE_RESOLUTION.Artesa.in_pic_width = %08X\n",     s_picture_resolution.Artesa.in_pic_width);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_PICTURE_RESOLUTION.Artesa.in_pic_height = %08X\n",    s_picture_resolution.Artesa.in_pic_height);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_OUT_PICTURE_RESOLUTION.out_pic_width = %08X\n",       s_out_picture_resolution.out_pic_width);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_OUT_PICTURE_RESOLUTION.out_pic_height = %08X\n",      s_out_picture_resolution.out_pic_height);
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_CAP_MODE.capMode = %08X\n",                       s_enc_cap_mode.capMode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_CAP_MODE.trigMode = %08X\n",                      s_enc_cap_mode.trigMode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_ENC_CAP_MODE.gpioPin = %08X\n",                       s_enc_cap_mode.gpioPin);
				/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.scan_format = %08X\n",           s_input_control.Artesa.scan_format);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.src_mode = %08X\n",              s_input_control.Artesa.src_mode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.sync_mode = %08X\n",             s_input_control.Artesa.sync_mode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.data_type = %08X\n",             s_input_control.Artesa.data_type);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.bytes_swap = %08X\n",            s_input_control.Artesa.bytes_swap);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.in_frame_rate = %08X\n",         s_input_control.Artesa.in_frame_rate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.out_frame_rate = %08X\n",        s_input_control.Artesa.out_frame_rate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.fmt = %08X\n",                   s_input_control.Artesa.fmt);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.pd_en = %08X\n",                 s_input_control.Artesa.pd_en);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.ck_edge = %08X\n",               s_input_control.Artesa.ck_edge);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_INPUT_CONTROL.Artesa.force_60p_in = %08X\n",          s_input_control.Artesa.force_60p_in);
				//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_RATE_CONTROL.Artesa.avg_bit_rate = %08X\n",           s_rate_control.Artesa.avg_bit_rate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_RATE_CONTROL.Artesa.qp_update_freq = %08X\n",         s_rate_control.Artesa.qp_update_freq);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_RATE_CONTROL.Artesa.mode = %08X\n",                   s_rate_control.Artesa.mode);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_RATE_CONTROL.Artesa.fixed = %08X\n",                  s_rate_control.Artesa.fixed);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_RATE_CONTROL.Artesa.vbr = %08X\n",                    s_rate_control.Artesa.vbr);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_VBR_BIT_RATE.min_bit_rate = %08X\n",                  s_vbr_bit_rate.min_bit_rate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_VBR_BIT_RATE.max_bit_rate = %08X\n",                  s_vbr_bit_rate.max_bit_rate);
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.intra_period = %08X\n",        s_gop_loop_filter.Artesa.intra_period);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.lp_filter = %08X\n",           s_gop_loop_filter.Artesa.lp_filter);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.dis_lf_idc = %08X\n",          s_gop_loop_filter.Artesa.dis_lf_idc);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.alpha_offset = %08X\n",        s_gop_loop_filter.Artesa.alpha_offset);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.beta_offset = %08X\n",         s_gop_loop_filter.Artesa.beta_offset);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.B_num = %08X\n",               s_gop_loop_filter.Artesa.B_num);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.ref_n = %08X\n",               s_gop_loop_filter.Artesa.ref_n);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.t8x8 = %08X\n",                s_gop_loop_filter.Artesa.t8x8);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.ref_p = %08X\n",               s_gop_loop_filter.Artesa.ref_p);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_GOP_LOOP_FILTER.Artesa.IDR = %08X\n",                 s_gop_loop_filter.Artesa.IDR);
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.bit_rate = %08X\n",               s_audio_control_param.bit_rate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.ch_sel = %08X\n",                 s_audio_control_param.ch_sel);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.sample_rate = %08X\n",            s_audio_control_param.sample_rate);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.aou_pass_en = %08X\n",            s_audio_control_param.aou_pass_en);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.ai_msb = %08X\n",                 s_audio_control_param.ai_msb);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.lrclk_i = %08X\n",                s_audio_control_param.lrclk_i);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.bclk_i = %08X\n",                 s_audio_control_param.bclk_i);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.ai_i2s = %08X\n",                 s_audio_control_param.ai_i2s);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.ai_rj = %08X\n",                  s_audio_control_param.ai_rj);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.ai_m = %08X\n",                   s_audio_control_param.ai_m);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.ch_num = %08X\n",                 s_audio_control_param.ch_num);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.pts = %08X\n",                    s_audio_control_param.pts);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.disAi = %08X\n",                  s_audio_control_param.disAi);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.raw = %08X\n",                    s_audio_control_param.raw);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_AUDIO_CONTROL_PARAM.audio_type = %08X\n",             s_audio_control_param.audio_type);
		//		jack.lee@janustech.com
				////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_FILTER_CONTROL.start_pixel = %08X\n",                 s_filter_control.start_pixel);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_FILTER_CONTROL.fl_en = %08X\n",                       s_filter_control.fl_en);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_FILTER_CONTROL.filter_strength = %08X\n",             s_filter_control.filter_strength);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_FILTER_CONTROL.start_line = %08X\n",                  s_filter_control.start_line);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QPCODEC_FILTER_CONTROL.dis_skp = %08X\n",                     s_filter_control.dis_skp);
				///////////////////////////////////////////////////////////////////////////////////////////////////////////
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "#############################################################################\n");
#endif
				if( i == 0 ) {

					QP_YUV_DATAFORMAT s_yuv_data_format;

					s_yuv_data_format.nWidth = cxe;

					s_yuv_data_format.nHeight = cye;

					s_yuv_data_format.nFrameRate = fps;

					s_yuv_data_format.nBitCount = 12;

					s_yuv_data_format.nDataType = 1; // QP_YUV_DATA_TYPE_QYUV = 0, QP_YUV_DATA_TYPE_YV12 = 1, QP_YUV_DATA_TYPE_I420 = 2, QP_YUV_DATA_TYPE_YUYV = 3
					
					qp_status = pDevice->m_pMpegCodec->Open( pDevice->m_pMpegCodec, 

															 pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ],

															 7, // QPMPGCODEC_ENC_MPEG_OUT = 0, QPMPGCODEC_ENC_PCM_OUT = 6,  QPMPGCODEC_ENC_YUV_OUT = 7

															&s_yuv_data_format,

															&pDevice->E23A0EAB120B4C609DC336EB8B99BE11[ i ],

															 E0E368BED109411F91924286A3FCCC1A,
															
															(TQP_PVOID)(pDevice) );
				}
				if( i == 1 ) {

					QP_PCM_DATAFORMAT s_pcm_data_format;

					s_pcm_data_format.nChannels = 2;

					s_pcm_data_format.nSamplesPerSec = (frq == 0) ? 48000 : frq;

					s_pcm_data_format.nAvgBytesPerSec = s_pcm_data_format.nSamplesPerSec * 4;

					s_pcm_data_format.nBlockAlign = 4;

					s_pcm_data_format.nBitsPerSample = 16;

					qp_status = pDevice->m_pMpegCodec->Open( pDevice->m_pMpegCodec, 

															 pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ],

															 6, // QPMPGCODEC_ENC_MPEG_OUT = 0, QPMPGCODEC_ENC_PCM_OUT = 6,  QPMPGCODEC_ENC_YUV_OUT = 7

															&s_pcm_data_format,

															&pDevice->E23A0EAB120B4C609DC336EB8B99BE11[ i ],

															 B193E8EB198B4259AED0BEB981811492,
															
															(TQP_PVOID)(pDevice) );
				}
				if( i == 2 ) {

					qp_status = pDevice->m_pMpegCodec->Open( pDevice->m_pMpegCodec, 

															 pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ],

															 0, // QPMPGCODEC_ENC_MPEG_OUT = 0, QPMPGCODEC_ENC_PCM_OUT = 6,  QPMPGCODEC_ENC_YUV_OUT = 7

															 QP_NULL,

															&pDevice->E23A0EAB120B4C609DC336EB8B99BE11[ i ],

															 BC207F1D29F24ECBB93020F959BBA5EA,
															
															(TQP_PVOID)(pDevice) );
				}
				if( pDevice->m_initData.mpgCodecInitData.bDontInitHW == QP_FALSE ) {

					F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000000 ); // [DANIEL, ADD F6B9E557A4BA24ffd926B820B836289C8 HERE]
				}
				qp_status = pDevice->m_pMpegCodec->Acquire( pDevice->m_pMpegCodec, 

															pDevice->E23A0EAB120B4C609DC336EB8B99BE11[ i ] );

				if( pDevice->m_initData.mpgCodecInitData.bDontInitHW == QP_FALSE ) {

					F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000000 ); // [DANIEL, ADD F6B9E557A4BA24ffd926B820B836289C8 HERE]
				}
				qp_status = pDevice->m_pMpegCodec->Start( pDevice->m_pMpegCodec, 

														  pDevice->E23A0EAB120B4C609DC336EB8B99BE11[ i ] );

				if( pDevice->m_initData.mpgCodecInitData.bDontInitHW == QP_FALSE ) {

					F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000000 ); // [DANIEL, ADD F6B9E557A4BA24ffd926B820B836289C8 HERE]
				}
			}
		}
		if( n_stream_mask == 0x00000002 ) { // AUDIO.ONLY

			pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] = 1;
							
			pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 1;
		}
		pDevice->m_initData.mpgCodecInitData.bDontInitHW = QP_TRUE; // [DANIEL, ADD F6B9E557A4BA24ffd926B820B836289C8 HERE]

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] = 1; // FIRMWARE DOWNLOAD SUCCESSFUL
		
		#ifdef NEVRON
		for( i = 1 ; i < 3 ; i++ ) {
		#else
		for( i = 0 ; i < 3 ; i++ ) { // 要在 FIRMWARE DOWNLOAD SUCCESSFUL 之後才安全
		#endif
			if( n_stream_mask & (1 << i) ) {

				ULONG lengths = 8;

				if( i == 1 ) { lengths = 16; }

				ULONG j = 0;
				for( j = 0 ; j < lengths ; j++ ) {
						
					ULONG s = pDevice->B9F485FBC2EE44B287E5FA879D64F1F7[ i ]++;

					pDevice->B9F485FBC2EE44B287E5FA879D64F1F7[ i ] %= lengths;

					s %= lengths;
					
					AC2AF440EE544A07939115ECB1E826B8( pDevice, i, s, &pDevice->CDA0E8191AB44A53A0F640EDE8B8F70C[ i ][ s ], NULL, &(p_sys_cfg->o_output_dma_buffers[ i ][ s ]) );

					if( pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ] != TQP_NULL_HANDLE &&
				
						pDevice->m_pMpegCodec != QP_NULL ) {

						EQP_Errors qp_status = pDevice->m_pMpegCodec->AddBuffer( pDevice->m_pMpegCodec, 
					
																				 pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ], 
																		 
																			   &(pDevice->CDA0E8191AB44A53A0F640EDE8B8F70C[ i ][ s ]) );
					}
				}
			}
		}
	}
#endif

	return TRUE;
}

// ##############################################################################################################################################################################
// 
NTSTATUS B2FA3948CEE84C26A7E4AE5AF5AB51C0( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{	
#if defined(AME_PL330B) || defined(AME_PL330A)
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B2FA3948CEE84C26A7E4AE5AF5AB51C0(%d)\n",  pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2);

	struct timeval ts;
	
	wrapper_do_gettimeofday( &ts );

	LONGLONG now = (ULONGLONG)(ts.tv_sec);

	#ifdef AUDIO_STAND_ALONE
	if(pDevice->possible_booting)
	{
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B2FA3948CEE84C26A7E4AE5AF5AB51C0() possible_booting\n",  pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

		if( (now - pDevice->m_booting_time) < F6B9E557A4BA24ffd926B820B836289C8_to_PLAY )
		{
			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B2FA3948CEE84C26A7E4AE5AF5AB51C0() booting(0d%d)\n",  pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, now - pDevice->m_booting_time);
	
			return STATUS_SUCCESS;
		}
	}
	#endif

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0 ) {

		pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2++;

	//	return STATUS_SUCCESS;
	}
	else {

		//neglect video change before this function
		PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
	
		p_sys_cfg->b_input_video_signal_changed = FALSE;
		
		pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 = 1;
	}

	pDevice->m_nAnalogCopyProtMacrovisionEnableProperty = 0;

#ifdef PL330B_COPYPORTECT_ARCHITECTURE

	if( FD0AC55FE0C0B45a788FEC199C5758F1E[ 0 ] == 0 ) { return STATUS_SUCCESS; }

	if( F6053D464C87D41c1B8CBE8A39FCDF2D2[ 0 ] == 0 ) { return STATUS_SUCCESS; }

#endif

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 == 1 ) {

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B2FA3948CEE84C26A7E4AE5AF5AB51C0() enter == 1\n",  pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

		PL330B_CLOSE_THREAD();
				
		PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		ULONG cx = p_sys_cfg->n_input_video_resolution_cx;

		ULONG cy = p_sys_cfg->n_input_video_resolution_cy;
	
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B2FA3948CEE84C26A7E4AE5AF5AB51C0( %d %d ) ----->\n",  pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, cx, cy);

		E395C7330A814EB6BB761D5A76D9E4B3( pDevice );

		p_sys_cfg->m_b_is_firmware_started = TRUE;

		PL330B_START_VIDEO_LOSS_THREAD();

		PL330B_START_AUDIO_LOSS_THREAD();

		PL330B_START_THREAD();
	
		if( pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE == 0 )
		{
			if( pDevice->m_pVideo[ 0 ][ 0 ] )
			{
				if( (pDevice->m_pVideo[ 0 ][ 0 ]->FD1832F8D382F4e91914C0048CC5A9DD8 == 3840) && (pDevice->m_pVideo[ 0 ][ 0 ]->F5B8891B732954fc2B26B7BFFCB15B596 == 2160) )
				{
					pDevice->m_pl330b_combine_4_chip = TRUE;

					BYTE i = 1;
					for( i = 1; i < 4; i++ )
					{
						if( g_pDevice[ i ] )
						{
							g_pDevice[ i ]->m_pl330b_combine_4_chip = TRUE;
	
							B2FA3948CEE84C26A7E4AE5AF5AB51C0( g_pDevice[ i ] );
						}
					}
				}
			}
		}
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B2FA3948CEE84C26A7E4AE5AF5AB51C0() end == 1\n",  pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

	}
	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 1 ) {

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B2FA3948CEE84C26A7E4AE5AF5AB51C0() enter > 1\n",  pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

		PL330B_CLOSE_THREAD();

		AA1D4E10781F45AF92A5792997D7623C( pDevice );

		PL330B_START_THREAD();

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B2FA3948CEE84C26A7E4AE5AF5AB51C0() end > 1\n",  pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);
	}
	// ...

	// ...

	// ...

#endif

	return STATUS_SUCCESS;
}

NTSTATUS F1D8A4353DCB40E3AC555846B3DD656A( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
#if defined(AME_PL330B) || defined(AME_PL330A)

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] F1D8A4353DCB40E3AC555846B3DD656A(%d) \n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2);

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 == 0 ) return STATUS_SUCCESS;
	
	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 1 ) {

		pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2--;

		return STATUS_SUCCESS;
	}
	pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 = 0;

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] F1D8A4353DCB40E3AC555846B3DD656A() enter\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

	PL330B_CLOSE_THREAD();

	PL330B_CLOSE_VIDEO_LOSS_THREAD();

	PL330B_CLOSE_AUDIO_LOSS_THREAD();

	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	ULONG cx = p_sys_cfg->n_input_video_resolution_cx;

	ULONG cy = p_sys_cfg->n_input_video_resolution_cy;

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] F1D8A4353DCB40E3AC555846B3DD656A( %d %d ) <-----", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, cx, cy);

	AFE6193A7F444538885DA2E6AE62BF0E( pDevice, FALSE, 0 );

	p_sys_cfg->n_output_firmware_reset = 0; 

	p_sys_cfg->m_b_is_firmware_started = FALSE;

	PL330B_START_THREAD();
	
	if( cx > 0 &&

		cy > 0 ) {

		ULONG j = 0;
		for( j = 0 ; j < 30 ; j++ ) {

			if( p_sys_cfg->n_input_video_resolution_cx > 0 &&

				p_sys_cfg->n_input_video_resolution_cy > 0 ) {

				p_sys_cfg->b_input_video_signal_changed = FALSE;

				break ;
			}
			F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000000 );
		}
	}
	
	if( pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE == 0 )
	{
		if( pDevice->m_pVideo[ 0 ][ 0 ] )
		{
			if( (pDevice->m_pVideo[ 0 ][ 0 ]->FD1832F8D382F4e91914C0048CC5A9DD8 == 3840) && (pDevice->m_pVideo[ 0 ][ 0 ]->F5B8891B732954fc2B26B7BFFCB15B596 == 2160) )
			{
				BYTE i = 1;
				for( i = 1; i < 4; i++ )
				{
					if( g_pDevice[ i ] )
					{
						F1D8A4353DCB40E3AC555846B3DD656A( g_pDevice[ i ] );
					}
				}
			}
		}
	}
	pDevice->m_pl330b_combine_4_chip = FALSE;

	// ...

	// ...
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] F1D8A4353DCB40E3AC555846B3DD656A() end\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

#endif

	return FBDC25F28F4A496BBEC83A29B30FB46F( pDevice );
}

NTSTATUS FBDC25F28F4A496BBEC83A29B30FB46F( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"FBDC25F28F4A496BBEC83A29B30FB46F()\n");

	return STATUS_SUCCESS;
}

#if defined(AME_PL330B) || defined(AME_PL330A)
/*
extern "C" TQP_DbgMCompID g_QPAVStrmDBGCompID;
extern "C" TQP_DbgMCompID g_QPCodecDBGCompID;
extern "C" TQP_DbgMCompID g_QPUsbDBGCompID;
extern "C" TQP_DbgMCompID g_QPPCIeDBGCompID;
extern "C" TQP_DbgMCompID g_QPPeripheralDBGCompID;
*/
extern TQP_DbgMCompID g_QPAVStrmDBGCompID;
extern TQP_DbgMCompID g_QPCodecDBGCompID;
extern TQP_DbgMCompID g_QPUsbDBGCompID;
extern TQP_DbgMCompID g_QPPCIeDBGCompID;
extern TQP_DbgMCompID g_QPPeripheralDBGCompID;

TQP_DbgMCompID			g_PLV4LDevDBGCompID = 0;

#endif

NTSTATUS B0D1CA46CA50499F8C9856675F0D1590( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	PL330B_CLOSE_THREAD();

	E9D4315DBD2D4358B221B0E3A1963008( pDevice, pDevice->m_nAnalogCrossbarVideoInputProperty, pDevice->m_nAnalogCrossbarVideoOutputProperty, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE );

	D585A1C8DE8349C5A903B8F61B5E0A9F( pDevice, NULL, TRUE );

	AC2EB3596394401F99E0E3A4946A9436( pDevice, TRUE );

	PL330B_START_THREAD();

	return STATUS_SUCCESS;
}
extern ULONG g_n_bus_number[ 32 ];

NTSTATUS E9E5F4C253CB4ED4B2950234390A6409( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	NTSTATUS status = STATUS_SUCCESS;

	if( (pDevice->idVendor == 0x1AF2 && (pDevice->idProduct & 0xFFFF) == 0xA001) ||  // |SIGMA.DESIGN|1AF2|A001|SIGMA.DESIGN PL330B|
		
		(pDevice->idVendor == 0x1164 && (pDevice->idProduct & 0x0FF0) == 0x05A0) ) { // |SIGMA.DESIGN|1164|X5AX|SIGMA.DESIGN PL330B|

		;
	}
	else { 

		PL330B_START_THREAD();

		return STATUS_UNSUCCESSFUL;
	}
	
	if(pDevice)
	{
		g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ] = pDevice;

		pDevice->m_pCustomSystemConfigProperty = (PL330B_SYS_CFG *)wrapper_vmalloc( sizeof(PL330B_SYS_CFG) );
	}
	else
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"E9E5F4C253CB4ED4B2950234390A6409() no  pDevice, error\n" );
		return false;
	}

	if(pDevice->m_pCustomSystemConfigProperty)
	{
		memset( pDevice->m_pCustomSystemConfigProperty, 0, sizeof(PL330B_SYS_CFG) );
	}
	else
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"E9E5F4C253CB4ED4B2950234390A6409() can not allocate m_pCustomSystemConfigProperty, error\n" );
		return false;
	}

	ULONG nDevicePropertyBusNumber = 0;

	ULONG nBufferLength;

	//IoGetDeviceProperty( pDevice->m_pPDO, DevicePropertyAddress, sizeof(ULONG), &nDevicePropertyBusNumber, &nBufferLength );

	//pDevice->FF362AA37F7D046bf90568AC1600626D9 = nDevicePropertyBusNumber % 16;

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_HwInitialize( %d, %d )\n", pDevice->FF362AA37F7D046bf90568AC1600626D9, pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_HwInitialize( %d, %04X%02X%02X )\n", pDevice->FF362AA37F7D046bf90568AC1600626D9, pDevice->bcdDevice, pDevice->iProduct, pDevice->iManufacturer);

	#if defined(AME_PL330B) || defined(AME_PL330A)

#if 1 // DEBUG

	if( g_n_debug_instances == 0 ) {

		g_n_debug_instances = 1;

		QPMgrsInit();
		
		//peter add
		QPDbgMRegComp(&g_PLV4LDevDBGCompID,
					  "QP V4LDev"
					  );


		QPDbgMRegComp( &g_QPCodecDBGCompID, "QP CodecLib" );

		QPDbgMRegComp(&g_QPUsbDBGCompID, "QP Usb" );

		QPDbgMRegComp( &g_QPPCIeDBGCompID, "QP PCIe" );

		QPDbgMRegComp( &g_QPPeripheralDBGCompID, "QP Peripheral" );
		
		/*
		QPDbgMSetCompLevel( g_QPUsbDBGCompID, QPDBGM_LEVEL_NONE );

		QPDbgMSetCompLevel( g_QPCodecDBGCompID, QPDBGM_LEVEL_NONE );

		QPDbgMSetCompLevel( g_QPUsbDBGCompID, QPDBGM_LEVEL_NONE );

		QPDbgMSetCompLevel( g_QPPCIeDBGCompID, QPDBGM_LEVEL_NONE );

		QPDbgMSetCompLevel( g_QPPeripheralDBGCompID, QPDBGM_LEVEL_NONE );
		*/
		//peter, highest
		/*

		QPDbgMSetCompLevel( g_QPUsbDBGCompID, QPDBGM_LEVEL_EXTRACE );

		QPDbgMSetCompLevel(g_PLV4LDevDBGCompID,
						   QPDBGM_LEVEL_EXTRACE
						   );
		QPDbgMSetCompLevel(g_QPCodecDBGCompID,
						   QPDBGM_LEVEL_EXTRACE
						   );
		QPDbgMSetCompLevel(g_QPPCIeDBGCompID,
						   QPDBGM_LEVEL_EXTRACE
						   );
		QPDbgMSetCompLevel(g_QPPeripheralDBGCompID,
						   QPDBGM_LEVEL_EXTRACE
						   );
		*/
		
		QPDbgMSetCompLevel( g_QPUsbDBGCompID, QPDBGM_LEVEL_ERROR );

		QPDbgMSetCompLevel(g_PLV4LDevDBGCompID, QPDBGM_LEVEL_ERROR);

		QPDbgMSetCompLevel(g_QPCodecDBGCompID, QPDBGM_LEVEL_ERROR);

		QPDbgMSetCompLevel(g_QPPCIeDBGCompID, QPDBGM_LEVEL_ERROR);

		QPDbgMSetCompLevel(g_QPPeripheralDBGCompID, QPDBGM_LEVEL_ERROR);
		
	}
	else {

		g_n_debug_instances++;
	}
#endif 

	//below is form windows "CPCIBaseDevice::OnDeviceStart()
	pDevice->m_pCodecLib = QP_NULL;

	pDevice->m_pMpegCodec = QP_NULL;

	pDevice->BA3E1E68758F40848036F186E1A9DF05 = TQP_NULL_HANDLE;

	RtlZeroMemory( (BYTE*)&pDevice->m_initData, sizeof(QPCODECLIB_INITDATA) );

	RtlZeroMemory( (BYTE*)&pDevice->m_sUsbBusData, sizeof(QPCODEC_USB_BUS_DATA) );

	pDevice->m_sUsbBusData.dwPipeCmdWrite = 1;

	pDevice->m_sUsbBusData.dwPipeCmdRead = 3;

	pDevice->m_sUsbBusData.dwPipeDataWrite = 0;

	pDevice->m_sUsbBusData.dwPipeDataRead = 2;
	
	//pDevice->m_initData.mpgCodecInitData.BusData = pTranslatedResourceList;

	pDevice->m_initData.mpgCodecInitData.BusDataSize = 0;
	
	ULONG i = 0;
	for( i = 0 ; i < 4 ; i++ ) {

		ULONG j = 0;
		for( j = 0 ; j < 32 ; j++ ) {

			RtlZeroMemory( (BYTE*)&(pDevice->CDA0E8191AB44A53A0F640EDE8B8F70C[ i ][ j ]), sizeof(QP_BUFFER_DESCRIPTOR) );

			RtlZeroMemory( (BYTE*)&(pDevice->BFAB79E4FD214756B9AF4B16FC78A0C5[ i ][ j ]), sizeof(QP_KSSTREAM_HEADER) );

			pDevice->CDA0E8191AB44A53A0F640EDE8B8F70C[ i ][ j ].DataBufferArray = &(pDevice->BFAB79E4FD214756B9AF4B16FC78A0C5[ i ][ j ]);
		}
		pDevice->B9F485FBC2EE44B287E5FA879D64F1F7[ i ] = 0;

		pDevice->E23A0EAB120B4C609DC336EB8B99BE11[ i ] = TQP_NULL_HANDLE;

		pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ i ] = TQP_NULL_HANDLE;
	}

	pDevice->m_initData.bDownloadFW = QP_TRUE;

	pDevice->m_initData.mpgCodecInitData.bDontInitHW = QP_FALSE;

	pDevice->m_initData.mpgCodecInitData.AccessMode = QPHCI_MODE_DIRECT; // QPPF_MODE_INDIRECT = 0, QPPF_MODE_DIRECT = 1, QPPF_MODE_MASTER = 2
	//peter enable
#ifdef AME_PL330B
	pDevice->m_initData.mpgCodecInitData.BusType = QPHCI_BUS_PCI; // QPHCI_BUS_USB = 0, QPHCI_BUS_PCI = 1
#else
	pDevice->m_initData.mpgCodecInitData.BusType = QPHCI_BUS_USB; // QPHCI_BUS_USB = 0, QPHCI_BUS_PCI = 1

	pDevice->m_initData.mpgCodecInitData.BusData = &pDevice->m_sUsbBusData;

	pDevice->m_initData.mpgCodecInitData.BusDataSize = sizeof(QPCODEC_USB_BUS_DATA);

#endif

	pDevice->m_initData.mpgCodecInitData.MemType = (QPCODEC_MEM_TYPE)(QPPF_MEM_TYPE_MDDR); // QPPF_MEM_TYPE_DDR = 0, QPPF_MEM_TYPE_MDDR = 1

	pDevice->m_initData.mpgCodecInitData.MemSize = 512;

	pDevice->m_initData.mpgCodecInitData.ChipType = QPCODEC_CHIP_ARTESA; // QPCODEC_CHIP_ARTESA = 8

	pDevice->m_initData.mpgCodecInitData.RegisterBase = (TQP_PVOID)(0x00100000);

	pDevice->m_initData.mpgCodecInitData.MemoryBase = (TQP_PVOID)(0x00000000);

	pDevice->m_initData.mpgCodecInitData.PageSize = 0x00100000;

	pDevice->m_initData.mpgCodecInitData.InterruptNumber = 0;

	pDevice->m_initData.mpgCodecInitData.VIUMode = QPPF_VINMODE_INTERLACE; // QPPF_VINMODE_PROG = 0 (BT656), = 1 (BT1120), QPPF_VINMODE_INTERLACE = 2 (HIU) [THE VIUMODE IN INF'S PLATFORM GROUP WILL OVERWRITE BY ENCODER GROUP'S ENCINPUTCONTROL.]

	pDevice->m_initData.mpgCodecInitData.VIUFormat = QPPF_VINFORMAT_PROGRESSIVE; // QPPF_VINFORMAT_PROGRESSIVE = 0, QPPF_VINFORMAT_INTERLACE = 1

	pDevice->m_initData.mpgCodecInitData.VIUStartPixel = 0;

	pDevice->m_initData.mpgCodecInitData.VIUStartLine = 0;

	pDevice->m_initData.mpgCodecInitData.ClkEdge = QPPF_VINCLKEDGE_POSITIVE; // QPPF_VINCLKEDGE_POSITIVE = 0, QPPF_VINCLKEDGE_NEGATIVE = 1

//	pDevice->m_initData.mpgCodecInitData.VIUSyncCode1 = 0xF1F1F1DA; // [僅支援 BT656]

//	pDevice->m_initData.mpgCodecInitData.VIUSyncCode2 = 0xB6F1F1B6; // [僅支援 BT656]
	
	pDevice->m_initData.mpgCodecInitData.VIUSyncCode1 = 0x000000F1; // [僅支援 BT656]

	pDevice->m_initData.mpgCodecInitData.VIUSyncCode2 = 0xB6F1F100; // [僅支援 BT656]

	pDevice->m_initData.mpgCodecInitData.AIControls_ai_msb = 1; // AI_MSB_LSB = 0, AI_MSB_MSB = 1

	pDevice->m_initData.mpgCodecInitData.AIControls_lrclk_i = 1; // LRCLK_I_LEFT_LOW = 0, LRCLK_I_LEFT_HIGH = 1

	pDevice->m_initData.mpgCodecInitData.AIControls_bclk_i = 0; // BCLK_I_RISING_EDGE = 0, BCLK_I_FALLING_EDGE = 1

	pDevice->m_initData.mpgCodecInitData.AIControls_ai_i2s = 1; // AI_I2S_NORMAL = 0, AI_I2S_PROGRAM = 1

	pDevice->m_initData.mpgCodecInitData.AIControls_ai_rj = 0; // AI_RJ_LEFT_JUSTIFIED = 0, AI_RJ_RIGHT_JUSTIFIED = 0

	pDevice->m_initData.mpgCodecInitData.AIControls_ai_m = 0; // AI_M_SLAVE = 0, AI_M_MASTER = 1

	pDevice->m_initData.mpgCodecInitData.VOEnable = QP_FALSE; // [不建議用]

	pDevice->m_initData.mpgCodecInitData.VOUMode = 0; // QPPF_VOUMODE_NTSC_INTERLACED = 0, QPPF_VOUMODE_PAL_INTERLACED = 1, QPPF_VOUMODE_PROGRESS = 2 

	pDevice->m_initData.mpgCodecInitData.VOUStartPixel = 1;

	pDevice->m_initData.mpgCodecInitData.VOUStartLine = 0;

	pDevice->m_initData.mpgCodecInitData.AOControls_ao_msb = 1; // AO_MSB_LSB = 0, AO_MSB_MSB = 1 [不建議用]

	pDevice->m_initData.mpgCodecInitData.AOControls_lrclk_i = 1; // AO_LRCLK_I_LEFT_HIGH = 0, AO_LRCLK_I_LEFT_LOW = 1

	pDevice->m_initData.mpgCodecInitData.AOControls_bclk_i = 0; // AO_BCLK_I_FALLING_EDGE = 0, AO_BCLK_I_RISING_EDGE = 1

	pDevice->m_initData.mpgCodecInitData.AOControls_ao_i2s = 1; // AO_I2S_NORMAL = 0, AO_I2S_PROGRAM = 1

	pDevice->m_initData.mpgCodecInitData.AOControls_ao_rj = 1; // AO_RJ_LEFT_JUSTIFIED = 0, AO_RJ_RIGHT_JUSTIFIED = 1

	pDevice->m_initData.mpgCodecInitData.AOControls_ao_s = 0; // AO_MODE_MASTER = 0, AO_MODE_SLAVE = 1

//	pDevice->m_initData.mpgCodecInitData.BusData = pTranslatedResourceList;
//
//	pDevice->m_initData.mpgCodecInitData.BusDataSize = 0;

	pDevice->m_initData.mpgCodecInitData.VerFwAPI = 1;

	pDevice->m_initData.mpgCodecInitData.FwIntMode = 0; // QPPF_CODECLIBINTMODE_HIU_ISR = 0, QPPF_CODECLIBINTMODE_SW1_ISR = 1

	pDevice->m_initData.mpgCodecInitData.FwFixedMode = 1; // QPPF_CODECLIBMEMMODE_STATIC = 0, QPPF_CODECLIBMEMMODE_DYNAMIC = 1

	pDevice->m_initData.mpgCodecInitData.GPIODirections = 0x00000000;

	pDevice->m_initData.mpgCodecInitData.GPIOValues = 0x00000000;

	pDevice->m_initData.mpgCodecInitData.ErrorRecovery = QPCODEC_ERROR_RECOVERY_ALWAYS; // QPCODEC_ERROR_RECOVERY_MANUAL = 0, QPCODEC_ERROR_RECOVERY_ON_ERROR = 1, QPCODEC_ERROR_RECOVERY_ALWAYS = 2

	pDevice->m_initData.mpgCodecInitData.bUseExtFW = QP_TRUE;

	pDevice->m_initData.mpgCodecInitData.pVideoFW = QP_NULL;

	pDevice->m_initData.mpgCodecInitData.pAudioFW = QP_NULL;

	pDevice->m_initData.mpgCodecInitData.VidFWSize = 0;

	pDevice->m_initData.mpgCodecInitData.AudFWSize = 0;

	pDevice->m_initData.mpgCodecInitData.bRestoreUSBMode = QP_TRUE;

	if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB ) {

		pDevice->m_initData.mpgCodecInitData.Pll4 = 0x0002012A; // 193.50MHZ (DEFAULT IS 0x00030130 165.50MHZ)
	}
	else {

#ifdef PL330B_ENABLE_60FPS

	//	pDevice->m_initData.mpgCodecInitData.Pll4 = 0x0002012C; // 202.50MHZ (DEFAULT IS 0x00030130 165.50MHZ)

		pDevice->m_initData.mpgCodecInitData.Pll4 = 0x0002012D; // 202.50MHZ (DEFAULT IS 0x00030130 165.50MHZ)
#else

	//	pDevice->m_initData.mpgCodecInitData.Pll4 = 0x0002012C; // 202.50MHZ (DEFAULT IS 0x00030130 165.50MHZ)

		pDevice->m_initData.mpgCodecInitData.Pll4 = 0x0002012D; // 202.50MHZ (DEFAULT IS 0x00030130 165.50MHZ)
#endif
	}

	pDevice->m_initData.mpgCodecInitData.Pll5 = 0;

	pDevice->m_initData.mpgCodecInitData.UseArtesaExt340 = 0;

	pDevice->m_initData.mpgCodecInitData.FilterOutHDCPContent = 0;

	pDevice->m_initData.vidDecoderInitData.type = VIDDECODER_DUMMY; // VIDDECODER_DUMMY = 0
	
	pDevice->m_initData.vidDecoderInitData.channel = VIDEO_SOURCE_DIGITAL1; // VIDEO_SOURCE_DIGITAL1 = AUTO

	pDevice->m_initData.vidDecoderInitData.multiType = MULTIPLE_VIDDECODER_NONE; // MULTIPLE_VIDDECODER_NONE = 0

	pDevice->m_initData.vidEncoderInitData.type = VIDENCODER_DUMMY; // VIDENCODER_DUMMY = 0

	pDevice->m_initData.vidEncoderInitData.standard = VIDEO_STANDARD_PAL; // VIDEO_STANDARD_NTSC = 0x01, VIDEO_STANDARD_PAL = 0x02, VIDEO_STANDARD_SECAM = 0x04, VIDEO_STANDARD_720P = 0x08, VIDEO_STANDARD_1080I = 0x10

	pDevice->m_initData.tunerInitData.type = TUNER_DUMMY; // TUNER_DUMMY = 0

	pDevice->m_initData.tvAudioInitData.type = TVAUDIO_DUMMY; // TVAUDIO_DUMMY = 0

	pDevice->m_initData.audCodecInitData.type = AUDCODEC_DUMMY; // AUDCODEC_DUMMY = 0

	pDevice->m_initData.i2cInitData.type = QPI2C_TYPE_USE_QLCODEC; // QPI2C_TYPE_USE_USB = 1, QPI2C_TYPE_USE_QLCODEC = 2, QPI2C_TYPE_SOC_INTERNAL_GPIO = 5, QPI2C_TYPE_USE_USB_SWI2C = 6

	pDevice->m_initData.i2cInitData.clk = 14; // GPIO#14 (GPIO#0, GPIO#1, GPIO#2, GPIO#4 ARE FREE)

	pDevice->m_initData.i2cInitData.data = 15; // GPIO#15

	//pDevice->m_initData.i2cInitDataEx.type = QPI2C_TYPE_SOC_INTERNAL_GPIO; // QPI2C_TYPE_USE_USB = 1, QPI2C_TYPE_USE_QLCODEC = 2, QPI2C_TYPE_SOC_INTERNAL_GPIO = 5, QPI2C_TYPE_USE_USB_SWI2C = 6
	//peter, linux do not support above
	pDevice->m_initData.i2cInitDataEx.type = QPI2C_TYPE_USE_QLCODEC; // QPI2C_TYPE_USE_USB = 1, QPI2C_TYPE_USE_QLCODEC = 2, QPI2C_TYPE_SOC_INTERNAL_GPIO = 5, QPI2C_TYPE_USE_USB_SWI2C = 6
	
	pDevice->m_initData.i2cInitDataEx.clk = 14; // GPIO#14

	pDevice->m_initData.i2cInitDataEx.data = 15; // GPIO#15

	if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI ) {
		
		F11AE4E46EF0410486665CDBF2F1128F( pDevice, "QP0203.VIDFW.BIN", &pDevice->m_initData.mpgCodecInitData.pVideoFW, (ULONG *)(&pDevice->m_initData.mpgCodecInitData.VidFWSize) );

		F11AE4E46EF0410486665CDBF2F1128F( pDevice, "QP0203.AUDFW.BIN", &pDevice->m_initData.mpgCodecInitData.pAudioFW, (ULONG *)(&pDevice->m_initData.mpgCodecInitData.AudFWSize) );

	}
	else {
		
		F11AE4E46EF0410486665CDBF2F1128F( pDevice, "QP0204.VIDFW.BIN", &pDevice->m_initData.mpgCodecInitData.pVideoFW, (ULONG *)(&pDevice->m_initData.mpgCodecInitData.VidFWSize) );

		F11AE4E46EF0410486665CDBF2F1128F( pDevice, "QP0204.AUDFW.BIN", &pDevice->m_initData.mpgCodecInitData.pAudioFW, (ULONG *)(&pDevice->m_initData.mpgCodecInitData.AudFWSize) );
	}
	
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_HwInitialize( %d ) start to  QPCodecInitLibrary()\n", pDevice->FF362AA37F7D046bf90568AC1600626D9);

	#ifdef AME_PL330A
	EQP_Errors qp_status = QPCodecInitLibrary( pDevice->parent_dev.read,//pDevice->F9D9594A095F0463193B7588374CF8310, //&(pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ 0 ]->dev), //pDevice->m_pPDO,
	#else
	EQP_Errors qp_status = QPCodecInitLibrary( pDevice->F9D9594A095F0463193B7588374CF8310, //&(pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ 0 ]->dev), //pDevice->m_pPDO,
	#endif
												QP_NULL, //pDevice->m_pFDO,

												&pDevice->m_initData, 

												&pDevice->m_pCodecLib );

	if( QP_NULL == pDevice->m_pCodecLib ) { status = STATUS_INSUFFICIENT_RESOURCES; goto RETURN_ERROR; }

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_HwInitialize( %d ) finish  QPCodecInitLibrary()-----------------\n", pDevice->FF362AA37F7D046bf90568AC1600626D9);

	F6B9E557A4BA24ffd926B820B836289C8_100NS(  1000000 ); // [DANIEL, ADD F6B9E557A4BA24ffd926B820B836289C8 HERE]

	qp_status = pDevice->m_pCodecLib->GetMpegCodec( pDevice->m_pCodecLib, 
		
													&pDevice->m_pMpegCodec );

	if( QP_NULL == pDevice->m_pMpegCodec ) { status = STATUS_INSUFFICIENT_RESOURCES; goto RETURN_ERROR; }

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_HwInitialize( %d ) finish  GetMpegCodec()<<<<<<<<<<<<<\n", pDevice->FF362AA37F7D046bf90568AC1600626D9);

	qp_status = pDevice->m_pCodecLib->InitDevice( pDevice->m_pCodecLib, QP_NULL, QP_NULL, QP_NULL );

	if( QP_SUCCESS(qp_status) == FALSE ) { status = STATUS_UNSUCCESSFUL; goto RETURN_ERROR; }	

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_HwInitialize( %d ) finish  m_pCodecLib->InitDevice()$$$$$$$$$$$$$\n", pDevice->FF362AA37F7D046bf90568AC1600626D9);

	F6B9E557A4BA24ffd926B820B836289C8_100NS(  1000000 ); // [DANIEL, ADD F6B9E557A4BA24ffd926B820B836289C8 HERE]

	qp_status = pDevice->m_pMpegCodec->AllocEncodeTask( pDevice->m_pMpegCodec, &pDevice->BA3E1E68758F40848036F186E1A9DF05 );

	if( QP_SUCCESS(qp_status) == FALSE ) { status = STATUS_UNSUCCESSFUL; goto RETURN_ERROR; }	

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_HwInitialize( %d ) finish  m_pMpegCodec->AllocEncodeTask():::::::::::::::\n", pDevice->FF362AA37F7D046bf90568AC1600626D9);

	F6B9E557A4BA24ffd926B820B836289C8_100NS(  1000000 ); // [DANIEL, ADD F6B9E557A4BA24ffd926B820B836289C8 HERE]

	B98859FFE32A4FC2A1A6B33CBCB91945( pDevice,  2, GPIO_OUTPUT );

	B98859FFE32A4FC2A1A6B33CBCB91945( pDevice,  3, GPIO_OUTPUT );

	B98859FFE32A4FC2A1A6B33CBCB91945( pDevice,  8, GPIO_OUTPUT );

	B98859FFE32A4FC2A1A6B33CBCB91945( pDevice, 11, GPIO_OUTPUT );

	if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI ) {

	//	B7348427B3AB4369914C8A1ED8C306B5( pDevice, 0, 0xA0, 0x00, 0x12ABF5AA );

		DWORD R00000000 = F9EAF79B03A148CA8238A894135B8327( pDevice, 0, 0xA0, 0x00 );

		if( R00000000 == 0x00000000 ) {
			
		//	F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xF900, 0x12AB );
			
		//	F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xF901, 0x45AB );

			R00000000 = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF900 );

			R00000000 <<= 16;

			R00000000 &= 0xFFFF0000;

			R00000000 += C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF901 );

			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_HwInitialize( %d, %d, R00000000 = %08X )\n", pDevice->FF362AA37F7D046bf90568AC1600626D9, pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, R00000000);

			if( (R00000000 & 0xFFFF0000) != 0x12AB0000 ) {

				DWORD R00009 =  C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x0009 );

				if( R00009 == (( 6 << 10) | (4 << 5) | ( 3 << 0)) ||
					
					R00009 == ((11 << 10) | (4 << 5) | (11 << 0)) ) {

					R00000000 = 0x12ABF5AB; // SC510N4 SDI
				}
			}
		}
		pDevice->bcdDevice = (USHORT)((R00000000 & 0xFFFF0000) >> 16);

		pDevice->iManufacturer = (BYTE)((R00000000 & 0x000000FF) >> 0);

		pDevice->iProduct = (BYTE)((R00000000 & 0x0000FF00) >> 8);

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_HwInitialize( %d, %04X%02X%02X )\n", pDevice->FF362AA37F7D046bf90568AC1600626D9, pDevice->bcdDevice, pDevice->iProduct, pDevice->iManufacturer);
	}
	else {

		pDevice->bcdDevice = (USHORT)(pDevice->idVendor);

		pDevice->iManufacturer = (BYTE)((pDevice->idProduct & 0x000000FF));

		pDevice->iProduct = (BYTE)((pDevice->idProduct & 0x0000FF00) >> 8);

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "QP020X_HwInitialize( %d, %04X%02X%02X )\n", pDevice->FF362AA37F7D046bf90568AC1600626D9, pDevice->bcdDevice, pDevice->iProduct, pDevice->iManufacturer);
	}
	if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAB ) {

		if( C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF902 ) == 0xAA01 ) {

			pDevice->FF362AA37F7D046bf90568AC1600626D9 += 1;
		}
	}
	if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && 
		
		 pDevice->iProduct == 0x85 &&
		
		 pDevice->iManufacturer == 0xA1) ) {

		 g_n_bus_number[ 0 ] = 1;

		 g_n_bus_number[ 1 ] = 2;

		 g_n_bus_number[ 2 ] = 3;

		 g_n_bus_number[ 3 ] = 4;

		 g_n_bus_number[ 4 ] = 5;

		USHORT id = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0xF800 );

		pDevice->FF362AA37F7D046bf90568AC1600626D9 = id;
	}
	B6DA6D73E4484C36B5A7CF9DFE4BBFB0( pDevice, -1, -1 );

//	if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0x44) ||	
//
//		(pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI && pDevice->iManufacturer == 0xA4) ) {
//
//		F163E0DBD4F44FD18730544917C904D1( pDevice, 0, 0x66, 0xF902, 0xAA01 );
//	}

	if( ((pDevice->iProduct & 0xFF) == 0x15 && (pDevice->iManufacturer & 0xFF) == 0x4C) ||
		
		((pDevice->iProduct & 0xFF) == 0x15 && (pDevice->iManufacturer & 0xFF) == 0xAC) ) {

		;
	}
	else if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAD) ||
		
			 (pDevice->iManufacturer == 0x22) ||  // DARIM.4A.SC542N2-L HDMI
	
			 (pDevice->iManufacturer == 0x24) ||  // DARIM.4A.SC542N4 HDMI
	
			 (pDevice->iManufacturer == 0x2A) ||  // DARIM.4B.SC542N2-L SDI

			 (pDevice->iManufacturer == 0x2C) ||  // DARIM.4B.SC542N4 SDI
	
			 (pDevice->iManufacturer == 0x2E) ||  // DARIM.4B.SC542N4 HYBRID.2ND
	
			 (pDevice->iManufacturer == 0x27) ||  // DARIM.4B.SC542N6 HYBRID.2ND

			 (pDevice->iManufacturer == 0x44) ||
		
			 (pDevice->iManufacturer == 0x46) ||
		
			 (pDevice->iManufacturer == 0x4A) ||
		
			 (pDevice->iManufacturer == 0x4B) ||
		
			 (pDevice->iManufacturer == 0xA4) ||
		
			 (pDevice->iManufacturer == 0xA6) ||
		
			 (pDevice->iManufacturer == 0xAA) ||
		
			 (pDevice->iManufacturer == 0xAB) ) {
		;
	}
	else {

		B98859FFE32A4FC2A1A6B33CBCB91945( pDevice, 2, GPIO_OUTPUT ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 10000 );

		CBFDDC6395144862ACEDAD3C092FC9A6( pDevice, 2, 0 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 10000 );

		BYTE R50A = C6F39DAE1CE54F0D873113FD657C7FA3( pDevice, 0x00, 0x9C, 0x00, 0x50 );

		CBFDDC6395144862ACEDAD3C092FC9A6( pDevice, 2, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 10000 );

		BYTE R50B = C6F39DAE1CE54F0D873113FD657C7FA3( pDevice, 0x00, 0x9C, 0x00, 0x50 );

		PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		if( R50A == R50B ) { // 新線路

			p_sys_cfg->m_b_is_old_mst3367_circuit = FALSE;
		}
		else { // 舊線路

			p_sys_cfg->m_b_is_old_mst3367_circuit = TRUE;
		}
	}

	if( (pDevice->iManufacturer & 0x0F) == 0x0B || (pDevice->iManufacturer & 0x0F) == 0x04 )//SDI
	{
		pDevice->m_nAnalogCrossbarVideoInputProperty = 4;
	}

	if( pDevice->iManufacturer == 0x4A || pDevice->iManufacturer == 0xAA )// 6603 HDMI
	{
		pDevice->m_nAnalogCrossbarVideoInputProperty = 0;
	}

	if( pDevice->iManufacturer == 0xAD || pDevice->iManufacturer == 0x4D )// MST3363 4 ch
	{
		pDevice->m_nAnalogCrossbarVideoInputProperty = 0;
	}

	if( (pDevice->iManufacturer & 0x0F) == 0x05 || (pDevice->iManufacturer & 0x0F) == 0x03 )
	{
		pDevice->m_nAnalogCrossbarVideoInputProperty = 0;
	}

	if( (pDevice->iManufacturer & 0x0F) == 0x08 || (pDevice->iManufacturer & 0x0F) == 0x0C || (pDevice->iManufacturer & 0x0F) == 0x01 )// all but SDI
	{
		pDevice->m_nAnalogCrossbarVideoInputProperty = 0;
	}

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"[%02d] E9E5F4C253CB4ED4B2950234390A6409() m_nAnalogCrossbarVideoInputProperty(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->m_nAnalogCrossbarVideoInputProperty);

	E9D4315DBD2D4358B221B0E3A1963008( pDevice, pDevice->m_nAnalogCrossbarVideoInputProperty, pDevice->m_nAnalogCrossbarVideoOutputProperty, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE );

	D585A1C8DE8349C5A903B8F61B5E0A9F( pDevice, NULL, TRUE );

	AC2EB3596394401F99E0E3A4946A9436( pDevice, TRUE );

	for( i = 0 ; i < 3 ; i++ ) {

		ULONG j = 0;
		for( j = 0 ; j < 16 ; j++ ) {
			
			PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
			
			//p_sys_cfg->o_output_dma_buffers[ i ][ j ].safeFree();
			
			//if(p_sys_cfg->o_output_dma_buffers[ i ][ j ].image && (p_sys_cfg->o_output_dma_buffers[ i ][ j ].size != 0) )
			{
				//vfree(p_sys_cfg->o_output_dma_buffers[ i ][ j ].image);

				p_sys_cfg->o_output_dma_buffers[ i ][ j ].image = NULL;

				p_sys_cfg->o_output_dma_buffers[ i ][ j ].size = 0;
			}

		}
	}
	for( i = 0; i < 32; i++)
	{
		pDevice->m_nCustomEncoderVideoProfileProperty[ i ] = V4L2_MPEG_VIDEO_H264_PROFILE_HIGH;//must >=3

		pDevice->m_nCustomEncoderVideoEntropyProperty[ i ] = 1;// 0 = CABAC / 1 = CAVLC / 2 = CABAC

		pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i ] = 0;

		pDevice->m_nCustomEncoderVideoResolutionProperty[ i ] = 0;

		pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ i ] = 60;
		
		pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ i ] = 0;

		pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ i ] = 0;

		//V4L2_MPEG_VIDEO_BITRATE_MODE_VBR = 0, V4L2_MPEG_VIDEO_BITRATE_MODE_CBR = 1
		
		pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i ] = V4L2_MPEG_VIDEO_BITRATE_MODE_CBR;

		pDevice->m_nAnalogVideoCompressionQualityProperty[ i ] = 6000; 

		pDevice->m_nCustomEncoderVideoBitRateProperty[ i ] = 12000000; 

		pDevice->m_nCustomEncoderVideoLevelProperty[ i ] = 41;

		pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ i ] = 30;

		pDevice->m_nCustomEncoderVideoBframesPerKeyframeProperty[ i ] = 0;
	}

	for( i = 0; i < 16; i++)
	{
		pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ i ] = 1;

		pDevice->m_nCustomAnalogVideoDenoiseTypeProperty[ i ] = 1;
	}

	struct timeval ts;

	wrapper_do_gettimeofday( &ts );

	pDevice->m_booting_time = (ULONGLONG)(ts.tv_sec);

	#endif


	#if defined(AME_PL330B) || defined(AME_PL330A)

RETURN_ERROR:

	PL330B_START_THREAD();

	#endif

	return status;
}

NTSTATUS E8588277E602465EAFD7A57A276FEDF7( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"E8588277E602465EAFD7A57A276FEDF7()\n");

	PL330B_CLOSE_THREAD();

#if defined(AME_PL330B) || defined(AME_PL330A)

	g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ] = NULL;

	if( pDevice->m_pMpegCodec != QP_NULL ) {

		if( pDevice->BA3E1E68758F40848036F186E1A9DF05 != TQP_NULL_HANDLE ) {

			pDevice->m_pMpegCodec->ReleaseTask( pDevice->m_pMpegCodec, 
				
													   pDevice->BA3E1E68758F40848036F186E1A9DF05 );

			pDevice->BA3E1E68758F40848036F186E1A9DF05 = TQP_NULL_HANDLE;
		}
		pDevice->m_pMpegCodec->Release( pDevice->m_pMpegCodec );

		pDevice->m_pMpegCodec = QP_NULL;
	}
	if( pDevice->m_pCodecLib != QP_NULL ) {

		pDevice->m_pCodecLib->Release( pDevice->m_pCodecLib );

		QPCodecDoneLibrary( pDevice->m_pCodecLib );

		pDevice->m_pCodecLib = QP_NULL;
	}

/*	if( pDevice->m_pMpegCodec != QP_NULL ) {

		if( pDevice->BA3E1E68758F40848036F186E1A9DF05 != TQP_NULL_HANDLE ) {

			pDevice->m_pMpegCodec->ReleaseTask( pDevice->m_pMpegCodec, 
				
												pDevice->BA3E1E68758F40848036F186E1A9DF05 );

			pDevice->BA3E1E68758F40848036F186E1A9DF05 = TQP_NULL_HANDLE;
		}
		pDevice->m_pMpegCodec->Release( pDevice->m_pMpegCodec );

		pDevice->m_pMpegCodec = QP_NULL;
	}
	pDevice->m_pCodecLib->Reset( pDevice->m_pCodecLib );
*/
#if 1 // DEBUG

	if( g_n_debug_instances <= 1 ) {

		g_n_debug_instances = 0;

		if( g_QPCodecDBGCompID ) {

			QPDbgMUnregComp( g_QPCodecDBGCompID );

			g_QPCodecDBGCompID = 0;
		}
		if( g_QPUsbDBGCompID ) {

			QPDbgMUnregComp( g_QPUsbDBGCompID );

			g_QPUsbDBGCompID = 0;
		}
		if( g_QPPCIeDBGCompID ) {

			QPDbgMUnregComp( g_QPPCIeDBGCompID );

			g_QPPCIeDBGCompID = 0;
		}
		if( g_QPPeripheralDBGCompID ) {

			QPDbgMUnregComp( g_QPPeripheralDBGCompID );

			g_QPPeripheralDBGCompID = 0;
		}
		QPMgrsTerm();
	}
	else {

		g_n_debug_instances--;
	}

#endif

	//must put behind release lib
	ULONG i = 0;	
	#ifdef NEVRON
	for( i = 1 ; i < 3 ; i++ ) {
	#else
	for( i = 0 ; i < 3 ; i++ ) {
	#endif

		ULONG j = 0;
		for( j = 0 ; j < 16 ; j++ ) {
			
			PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
			
			//p_sys_cfg->o_output_dma_buffers[ i ][ j ].safeFree();
			
			if(p_sys_cfg->o_output_dma_buffers[ i ][ j ].image && (p_sys_cfg->o_output_dma_buffers[ i ][ j ].size != 0) )
			{
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"[%02d] E8588277E602465EAFD7A57A276FEDF7() should not come here ??????????\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);				
				
				vfree(p_sys_cfg->o_output_dma_buffers[ i ][ j ].image);

				p_sys_cfg->o_output_dma_buffers[ i ][ j ].image = NULL;

				p_sys_cfg->o_output_dma_buffers[ i ][ j ].size = 0;
			}

		}
	}
	FREE_MEMORY( pDevice->m_initData.mpgCodecInitData.pVideoFW );

	FREE_MEMORY( pDevice->m_initData.mpgCodecInitData.pAudioFW );

#endif

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] E8588277E602465EAFD7A57A276FEDF7() end\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

	return STATUS_SUCCESS;
}
#if defined(AME_PL330B) || defined(AME_PL330A)
BOOL AC2AF440EE544A07939115ECB1E826B8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, ULONG j, PQP_BUFFER_DESCRIPTOR pBufDesc, BYTE* pStreamPointer, IppImage8u * pCloneStreamBuffer ) // -----> buildBufferDescriptor

// BOOL AC2AF440EE544A07939115ECB1E826B8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, ULONG j, PQP_BUFFER_DESCRIPTOR pBufDesc, PKSSTREAM_POINTER pStreamPointer, BYTE * pCloneStreamBuffer ) // -----> buildBufferDescriptor
{
	//pBufDesc->ulFlags = 0;
	//peter modify for linux DMA_BUFFER_MODE_KERNEL
	//pBufDesc->ulFlags = QP_BUFDESC_FLAG_BUFFER_DRIVER;

	//peter modify for linux DMA_BUFFER_MODE_COMMON
	pBufDesc->ulFlags = 0;

	pBufDesc->ulPTS = 0;
	//peter, pStreamPointer is NULL , so I disable below
	/*
	if( pStreamPointer ) {

		if( pStreamPointer->StreamHeader->OptionsFlags & KSSTREAM_HEADER_OPTIONSF_ENDOFSTREAM ) {

			pBufDesc->ulFlags = QP_BUFDESC_FLAG_EOS;
		}
		if( pStreamPointer->StreamHeader->OptionsFlags & KSSTREAM_HEADER_OPTIONSF_TIMEVALID ) {

			pBufDesc->DataBufferArray->PresentationTime.Time = pStreamPointer->StreamHeader->PresentationTime.Time;
		
			pBufDesc->DataBufferArray->PresentationTime.Numerator = pStreamPointer->StreamHeader->PresentationTime.Numerator;
		
			pBufDesc->DataBufferArray->PresentationTime.Denominator = pStreamPointer->StreamHeader->PresentationTime.Denominator;

			pBufDesc->ulFlags |= QP_BUFDESC_FLAG_PTS;
		
			pBufDesc->ulPTS = PL330B_KSPTS_TO_PTS( &pStreamPointer->StreamHeader->PresentationTime );
		
			pBufDesc->ulPTS = pBufDesc->ulPTS % 0x1FFFFFFFF;
		}
		else {

			pBufDesc->ulPTS = 0;
		}
	}
	*/
	if( pCloneStreamBuffer ) {
		
		pBufDesc->DataBufferArray->Duration = 0;
		
		pBufDesc->DataBufferArray->FrameExtent = pCloneStreamBuffer->size;
		
		pBufDesc->DataBufferArray->DataUsed = 0;
	
		pBufDesc->DataBufferArray->Data = pCloneStreamBuffer->image + (4);
		
		pBufDesc->DataBufferArray->OptionsFlags = 0;

//		pBufDesc->DataBufferArray->Duration = pStreamPointer->StreamHeader->Duration;
//		
//		pBufDesc->DataBufferArray->FrameExtent = pStreamPointer->StreamHeader->FrameExtent;
//		
//		pBufDesc->DataBufferArray->DataUsed = pStreamPointer->StreamHeader->DataUsed;
//	
//		pBufDesc->DataBufferArray->Data = pCloneStreamBuffer;
//		
//		pBufDesc->DataBufferArray->OptionsFlags = pStreamPointer->StreamHeader->OptionsFlags;
//
//		BYTE * po = (BYTE *)(pStreamPointer->StreamHeader->Data);
//
//		if( po ) {
//
//		   *po = (BYTE)(j);
//		}
	}
	//peter, this pointer is NULL from caller
	/*
	else if( pStreamPointer ) {

		pBufDesc->DataBufferArray->Duration = pStreamPointer->StreamHeader->Duration;
		
		pBufDesc->DataBufferArray->FrameExtent = pStreamPointer->StreamHeader->FrameExtent;
		
		pBufDesc->DataBufferArray->DataUsed = pStreamPointer->StreamHeader->DataUsed;
		
		pBufDesc->DataBufferArray->Data = pStreamPointer->StreamHeader->Data;
		
		pBufDesc->DataBufferArray->OptionsFlags = pStreamPointer->StreamHeader->OptionsFlags;
	}
	*/
	pBufDesc->NumberOfBuffers = 1;
	
	pBufDesc->ulBufferIndex = 0;
	
	pBufDesc->ulBufferOffset = 0;
	
	pBufDesc->ulBufferSize = pBufDesc->DataBufferArray->FrameExtent;
	
	pBufDesc->ulDMABufferIndex = 0;
	
	pBufDesc->ulDMABufferOffset = 0;
	
	pBufDesc->ulTotalUsed = 0;
	
	if( i == 2 ) {

		if( TRUE ) {

	//	if( m_bBufferPartialFill ) { // ???????

			pBufDesc->ulFlags |= QP_BUFDESC_FLAG_PARTIAL_FILL_OK;
		}
		if( TRUE ) {

	//	if( m_bBufferFrameAligned ) { // ???????

			pBufDesc->ulFlags |= QP_BUFDESC_FLAG_FRAME_ALIGNED;
		}
	}
	else if( i == 0 ) {

		if( TRUE ) {

	//	if( m_bBufferPartialFill ) { // ???????

			pBufDesc->ulFlags |= QP_BUFDESC_FLAG_PARTIAL_FILL_OK;
		}
		if( TRUE ) {

	//	if( m_bBufferFrameAligned ) { // ???????

			pBufDesc->ulFlags |= QP_BUFDESC_FLAG_FRAME_ALIGNED;
		}
	}
	else {

		if( TRUE ) {

	//	if( m_bBufferPartialFill ) { // ???????

			pBufDesc->ulFlags |= QP_BUFDESC_FLAG_PARTIAL_FILL_OK;
		}
		if( TRUE ) {

	//	if( m_bBufferFrameAligned ) { // ???????

			pBufDesc->ulFlags |= QP_BUFDESC_FLAG_FRAME_ALIGNED;
		}
	}
	pBufDesc->Status = QPERR_PENDING;

	pBufDesc->pBuffer = QP_NULL;

	pBufDesc->unAlignedNumberBytes = 0;

	//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "AC2AF440EE544A07939115ECB1E826B8( %08X.%08X.%08X.%08X )\n", i, pBufDesc->DataBufferArray->Data, pBufDesc->DataBufferArray->FrameExtent, pBufDesc->DataBufferArray->DataUsed);

	return TRUE;
}
#endif

EQP_Errors E0E368BED109411F91924286A3FCCC1A( TQP_PVOID pContext, TQP_UINT32 dwCode, TQP_PVOID pParam )
{
#if defined(AME_PL330B) || defined(AME_PL330A)
	//F1838C0176E054c129B7F2BF440D1236E( KERN_ERR, "E0E368BED109411F91924286A3FCCC1A\n" ); 

	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(pContext);

	if( dwCode == QPMPGCODEC_CMD_DONE_DATA ) {

		//pDevice->F69679D3D75724cd281AAC93AE8DFDF35 = (ULONG)dwCode;

		pDevice->F9D066B94377B4a9aB14E37D504955651 = pParam;

		if( pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] == 0 ) { 
			
			//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] PL330B_rawcpy() F03D1DD650AC64c28B04687338F970D0E[ 3 ] == 0\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

			goto VIDEO_SKIP;
		}
		
		//avoid conflict with no video thread
		if (pDevice->m_nAnalogVideoDecoderStatusProperty == 0 )
		{
			//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] PL330B_rawcpy() m_nAnalogVideoDecoderStatusProperty still 0\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

			goto VIDEO_SKIP;
		}

		//possible error interrupt, DataUsed is 0
		
		PQP_BUFFER_DESCRIPTOR pBufDesc = (PQP_BUFFER_DESCRIPTOR)(pDevice->F9D066B94377B4a9aB14E37D504955651);

		if( pBufDesc )
		{
			if(pBufDesc->DataBufferArray)
			{
				if( pBufDesc->DataBufferArray->DataUsed >= (320 * 240 * 12 >> 3) )	 	
				{
					//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] E0E368BED109411F91924286A3FCCC1A() DataUsed(%d)--\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pBufDesc->DataBufferArray->DataUsed);
					//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] E0E368BED109411F91924286A3FCCC1A() Data(lx%lx)--\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pBufDesc->DataBufferArray->Data);
					
					struct task_struct * rawcpy_thread = kthread_run( (INT)PL330B_rawcpy, pDevice, "PL330B_rawcpy" );

					if( IS_ERR( rawcpy_thread ) ) {
		
						F1838C0176E054c129B7F2BF440D1236E( KERN_ERR, "rawcpy_thread() - kthread_run() - [FAIL]\n" ); 
					}
				}
				else
				{
					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] E0E368BED109411F91924286A3FCCC1A() DataUsed(%d) error\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pBufDesc->DataBufferArray->DataUsed);
				}
			}
		}

VIDEO_SKIP:
		{	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
				
			ULONG s = pDevice->B9F485FBC2EE44B287E5FA879D64F1F7[ 0 ]++;

			pDevice->B9F485FBC2EE44B287E5FA879D64F1F7[ 0 ] %= 8;

			s %= 8;

			AC2AF440EE544A07939115ECB1E826B8( pDevice, 0, s, &pDevice->CDA0E8191AB44A53A0F640EDE8B8F70C[ 0 ][ s ], NULL, &(p_sys_cfg->o_output_dma_buffers[ 0 ][ s ]) );

			if( pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ 0 ] != TQP_NULL_HANDLE &&
				
				pDevice->m_pMpegCodec != QP_NULL ) {

				EQP_Errors qp_status = pDevice->m_pMpegCodec->AddBuffer( pDevice->m_pMpegCodec, 
					
																		 pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ 0 ], 
																		 
																		&(pDevice->CDA0E8191AB44A53A0F640EDE8B8F70C[ 0 ][ s ]) );
			}
		}
		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 0 ]++;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] = 1;

	}
#endif
	//F1838C0176E054c129B7F2BF440D1236E( KERN_ERR, "E0E368BED109411F91924286A3FCCC1A() end\n" ); 

	return QPERR_SUCCESS;
}

EQP_Errors BC207F1D29F24ECBB93020F959BBA5EA( TQP_PVOID pContext, TQP_UINT32 dwCode, TQP_PVOID pParam )
{
#if defined(AME_PL330B) || defined(AME_PL330A)

	// #define QPMPGCODEC_CMD_BUFFER_OVERFLOW			0x00000100
	// #define QPMPGCODEC_CMD_STOP_COMPLETED			0x00000200
	// #define QPMPGCODEC_CMD_SCHEDULE_TIMER			0x00000400
	// #define QPMPGCODEC_CMD_DONE_DATA					0x00010000
	// #define QPMPGCODEC_CMD_END_OF_STREAM				0x00020000
	// #define QPMPGCODEC_CMD_GET_STRM_TIME				0x00040000
	// #define QPMPGCODEC_CMD_MORE_DATA					0x00080000
	// #define QPMPGCODEC_CMD_THREAD					0x10000000
	// #define QPMPGCODEC_CMD_CAP_START					0x20000000
	// #define QPMPGCODEC_CMD_CAP_STOP					0x40000000
	// #define QPMPGCODEC_CMD_START_TIMEOUT				0x00100000
	// #define QPMPGCODEC_CMD_DEC_VID_ERR				0x00000001
	// #define QPMPGCODEC_CMD_DEC_AUD_ERR				0x00000002
	// #define QPMPGCODEC_CMD_DEC_SEQ_PARAM_CHANGED		0x00000004
	// #define QPMPGCODEC_CMD_DEC_RDY_TO_DISP			0x00000008
	// #define QPMPGCODEC_CMD_DEC_COMPLETE				0x00000010
	// 

	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(pContext);

	if( dwCode == QPMPGCODEC_CMD_DONE_DATA ) {

		PQP_BUFFER_DESCRIPTOR pBufDesc = (PQP_BUFFER_DESCRIPTOR)(pParam);

		//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "BC207F1D29F24ECBB93020F959BBA5EA( %d.%08X.%08X.%08X.%d -> )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pContext, dwCode, pParam, pBufDesc->DataBufferArray->DataUsed);
			
		if( pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] == 0 ) { 
			
		//	pBufDesc->DataBufferArray->DataUsed = 0; 

		//	return QPERR_SUCCESS;
			//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] BC207F1D29F24ECBB93020F959BBA5EA() F03D1DD650AC64c28B04687338F970D0E[ 3 ] == 0\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

			goto CODEC_SKIP;
		}
					
		if( pDevice->m_nAnalogCopyProtMacrovisionProperty == 1 )//HDCP
		{
			goto CODEC_SKIP;
		}

		ULONG counts = 1;

		BYTE * po = (BYTE *)(pBufDesc->DataBufferArray->Data);

		BYTE j = 0;

		unsigned long flags = 0x00000000;

		int k = 0;
		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			if( po ) {

				j = *(po - 4);

				if(j > 8)
				{
					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] BC207F1D29F24ECBB93020F959BBA5EA() j(0d%d) error ?????????\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, j);

					goto CODEC_SKIP;
				}
				ULONG i = 0;
				for( i = 0 ; i < counts ; i++ ) {

					if( pDevice->FDB274CD437614fec94859748411FE56A[ 0 ] & ( 1 << k ) ) {

						if( pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ 0 ][ k ] == NULL ) { continue ; }
		
						F301FA49098CE4d9eB95F22BBD388E837* pVideo = pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ 0 ][ k ];

						if( !pVideo->m_nCustomEncoderKeyFrameArrived )
						{
							if( *( po + 4 ) == 0x67 )
							{
								F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] I frame arrived\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

								pVideo->m_nCustomEncoderKeyFrameArrived = 1;
							}
							else
							{
								//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] drop P frame\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

								goto CODEC_SKIP;
							}
						}

						F170997530C6943659ECE8DEC21301F66* F523C1268E9B24a96876472B09F4D9EA4 = NULL;

						unsigned long flags = 0x00000000;

						if( wrapper_list_empty( &pVideo->F0EA6D27495A14af1A9607DE7C222A3B1 ) == 0 ) {

							wrapper_spin_lock_irqsave( &pVideo->FE0A97B802F3C400aBD7CD5D313825C31, flags );

							F523C1268E9B24a96876472B09F4D9EA4 = wrapper_list_first_entry( &pVideo->F0EA6D27495A14af1A9607DE7C222A3B1, F170997530C6943659ECE8DEC21301F66, F6A821C5E7AA043f999FB3C51DB94DD2B.queue ); //
				
							wrapper_spin_unlock_irqrestore( &pVideo->FE0A97B802F3C400aBD7CD5D313825C31, flags );

							if( F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED )
							{
								NULL;
							}
							else
							{
								F523C1268E9B24a96876472B09F4D9EA4 = NULL;

								F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F523C1268E9B24a96876472B09F4D9EA4[ 0d%d ] error, not VIDEOBUF_QUEUED --\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), 0 );
							}
						}
						else {

							F523C1268E9B24a96876472B09F4D9EA4 = NULL;

							//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] error F523C1268E9B24a96876472B09F4D9EA4[ 0d%d ](0x%x)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), 0, F523C1268E9B24a96876472B09F4D9EA4 );
						}

						if( pVideo && F523C1268E9B24a96876472B09F4D9EA4) {

							BYTE * pe = wrapper_videobuf_to_vmalloc( &F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B );

							if( pe == NULL ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] () pe == NULL \n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ); goto CODEC_SKIP; }

							if( pe && po && (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
							{
								struct timeval ts;

								BOOLEAN p_FDFC345768E394d138EA574DEB55B7949s = TRUE;
		
								int size = pBufDesc->DataBufferArray->DataUsed;

								if( !pVideo->m_nCustomEncoderSlice)
								{
									if( size > F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize)
									{
										size = F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize;
									}
									memcpy( pe, po, size);
								}
								else
								{
									//add a header
									H264_STREAM_HEADER hdr;
										
									memset( &hdr, 0x00, sizeof(H264_STREAM_HEADER) );

									if( size > (F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize - 4) )
									{
										size = F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize - 4;
									}

									hdr.nFrameBufferSize = size;

									//if( hdr.nFrameBufferSize > PL330B_MAX_H264_SIZE )
									//{
									//	hdr.nFrameBufferSize = F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize -4;
									//}

									hdr.nFrameType = (*( po + 4 ) == 0x67) ? (0) : (1);

									memcpy( pe, &hdr, sizeof(H264_STREAM_HEADER) );

									memcpy( pe + 4, po, size);

									//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] copy h264 to AP (0d%d) nFrameType(0x%x) with header\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), pBufDesc->DataBufferArray->DataUsed, hdr.nFrameType );
								}

								if( p_FDFC345768E394d138EA574DEB55B7949s )
								{
									//use killall -9 vlc will change buffer state long before any driver function
									//I do not know how this be done, I can only check here
						
									if( F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED )
									{
										wrapper_spin_lock_irqsave( &pVideo->FE0A97B802F3C400aBD7CD5D313825C31, flags );

										//must inside spin_lock
										//can not find how 0xdead000000000000 is added
										if( (F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next == LIST_POISON1) || (F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev == LIST_POISON2) || (F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next == 0xdead000000000100) || (F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev == 0xdead000000000200) )
										{
											wrapper_spin_unlock_irqrestore( &pVideo->FE0A97B802F3C400aBD7CD5D313825C31, flags );

											//skip this time
											F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] H264 pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue error, next(%p) prev(%p)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next, F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev );
										}
										else
										{
											wrapper_list_del( &F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.queue );

											wrapper_spin_unlock_irqrestore( &pVideo->FE0A97B802F3C400aBD7CD5D313825C31, flags );

											wrapper_do_gettimeofday( &ts );
		
											F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.ts = ts;

											//still cannot find a way to output I, P frame flags
											//magic can not set to 0, otherwise crash
											//F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.magic = (*( po + 4 ) == 0x67) ? (0) : (1);
											//F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.privsize &= (~(V4L2_BUF_FLAG_KEYFRAME | V4L2_BUF_FLAG_PFRAME));

											if( pVideo->m_nCustomEncoderSlice)
											{
												F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.size = size + 4;//for s_v4l2_buffer.bytesused in application
											}
											else
											{
												F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.size = size;//for s_v4l2_buffer.bytesused in application
											}
			
											update_video_time_stamp( pDevice, pVideo, F523C1268E9B24a96876472B09F4D9EA4);

											F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.field_count = (++pVideo->F6578ACFCB40E44819A12FD3E27A48085) * 2;

											#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25)

											F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.state = VIDEOBUF_DONE;

											#else

											F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.state = STATE_DONE;

											#endif

											wrapper_wake_up( &F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.done );
										}
									}
									else
									{
										F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] pe state error, i(0d%d) (%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.state );
									}
								}
							}
						}//if F523C1268E9B24a96876472B09F4D9EA4
					}// if FDB274CD437614fec94859748411FE56A
				}// for
			}// if po
		}//end of for
		
CODEC_SKIP:

		{	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
				
			ULONG s = pDevice->B9F485FBC2EE44B287E5FA879D64F1F7[ 2 ]++;

			pDevice->B9F485FBC2EE44B287E5FA879D64F1F7[ 2 ] %= 8;

			s %= 8;

			AC2AF440EE544A07939115ECB1E826B8( pDevice, 2, s, &pDevice->CDA0E8191AB44A53A0F640EDE8B8F70C[ 2 ][ s ], NULL, &(p_sys_cfg->o_output_dma_buffers[ 2 ][ s ]) );

			if( pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ 2 ] != TQP_NULL_HANDLE &&
				
				pDevice->m_pMpegCodec != QP_NULL ) {

				EQP_Errors qp_status = pDevice->m_pMpegCodec->AddBuffer( pDevice->m_pMpegCodec, 
					
																			pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ 2 ], 
																		 
																		&(pDevice->CDA0E8191AB44A53A0F640EDE8B8F70C[ 2 ][ s ]) );
			}
		}
		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ]++;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 1;
	}

#endif

	return QPERR_SUCCESS;
}


EQP_Errors B193E8EB198B4259AED0BEB981811492( TQP_PVOID pContext, TQP_UINT32 dwCode, TQP_PVOID pParam )
{
#if defined(AME_PL330B) || defined(AME_PL330A)

	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(pContext);

	FE8EB18A4C9984f9789EFF7C05EE073A0* pAudio = NULL;

	BYTE* pout = NULL;

	if( dwCode == QPMPGCODEC_CMD_DONE_DATA ) {

		PQP_BUFFER_DESCRIPTOR pBufDesc = (PQP_BUFFER_DESCRIPTOR)(pParam);

		//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "B193E8EB198B4259AED0BEB981811492( %d.%08X.%08X.%08X -> )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pContext, dwCode, pParam);
		
		if( pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] == 0 ) { 
			
			//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B193E8EB198B4259AED0BEB981811492() F03D1DD650AC64c28B04687338F970D0E[ 3 ] == 0\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

			goto AUDIO_SKIP;
		}

		if( pDevice->m_nAnalogCopyProtMacrovisionProperty == 1 )//HDCP
		{
			//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B193E8EB198B4259AED0BEB981811492() HDCP\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

			goto AUDIO_SKIP;
		}

		BYTE * po = NULL;
		int k = 0;
		for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
		{
			pAudio = pDevice->FF6347EA309EF49519F7F07D0B6B28662[ 0 ];

			if( pAudio ) {

				ULONG counts = 1;

				/*
				if( pDevice->m_nCustomCloneFiltersProperty >= 2 ) {

					counts = (pDevice->m_nCustomCloneFiltersProperty >= 4) ? (4) : (pDevice->m_nCustomCloneFiltersProperty); // 最多四組
				}
				else if( pDevice->m_nCustomInstancesPossibleProperty >= 1 ) {

					counts = 4; // 最多四組
				}
				else {

					counts = 1;
				}
				*/
			
				if( pBufDesc )
				{
					if(pBufDesc->DataBufferArray)
					{
						po = (BYTE *)(pBufDesc->DataBufferArray->Data);
						
						//if(pBufDesc->DataBufferArray->DataUsed != 2048)
						{
							//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B193E8EB198B4259AED0BEB981811492() po(lx%lx) pParam(lx%lx) DataUsed(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, po, pParam, pBufDesc->DataBufferArray->DataUsed);
						}
					}
				}

				BYTE j = 0;

				PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

				if( po ) {

					j = *(po - 4);

					//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B193E8EB198B4259AED0BEB981811492() j(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, j);

					if(j > 16)
					{
						F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B193E8EB198B4259AED0BEB981811492() j(0d%d) error ?????????\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, j);
	
						goto AUDIO_SKIP;
					}

					BOOL FDFC345768E394d138EA574DEB55B7949 = TRUE;
				
					BYTE * p_src = p_sys_cfg->o_output_dma_buffers[ 1 ][ j ].image + (4);

					ULONG i = 0;
					for( i = 0 ; i < counts ; i++ ) {

						if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F13A906F1479D4245B9F207A09C70BCE6[ pAudio->F0DD7393CD1494e27A72652C7D1A97893 ] & ( 1 << k ) ) {

							if( FDFC345768E394d138EA574DEB55B7949 ) {

								if( pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] == 0 &&

									pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] == 0 ) { // VIDEO 出來後再送出 AUDIO

									//pRC->nRawFrameLength = 0;
								}
								else {

									//pRC->nRawFrameLength = pBufDesc->DataBufferArray->DataUsed;

									if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k])
									{
										if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k]->runtime)
										{
											if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k]->runtime->dma_area)
											{
												pout = (BYTE*) (pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k]->runtime->dma_area);

												pout += pAudio->F6578ACFCB40E44819A12FD3E27A48085[k] * pAudio->F1461B75D9C644717A130B5C10D966CF0;

												if( pout <= ((BYTE*) (pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k]->runtime->dma_area) + FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.period_bytes_min * (FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.periods_min - 1) ) )
												{
													#ifdef CUEBI_WEBRTC

													int audio_size = 0;

													if( pDevice->m_nCustomAnalogAudioSampleFrequencyProperty == 48000)
													{
														audio_size = ((pAudio->m_nFrameDMANumber[k] % 5) == 4) ? FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.period_bytes_min - 4 : FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.period_bytes_min; //(4*3763 + 3760)/5 = 3763.2

														resampleAudioBuffer2(p_src, 4096, pAudio->m_audio_temp, audio_size);

														p_src = pAudio->m_audio_temp;
													}
													else if( pDevice->m_nCustomAnalogAudioSampleFrequencyProperty == 32000)
													{
														// 2048 * 176400 /128000 = 2822.4
														// 2824, 2820, 2824, 2820, 2824 avg is 2822.4
														
														audio_size = (((pAudio->m_nFrameDMANumber[k] % 5) == 1) || ((pAudio->m_nFrameDMANumber[k] % 5) == 3)) ?  2824 - 4 : 2824;

														resampleAudioBuffer2(p_src, 2048, pAudio->m_audio_temp, audio_size);

														p_src = pAudio->m_audio_temp;
													}
													else
													{
														audio_size = pBufDesc->DataBufferArray->DataUsed; // not constant
													}
							
													//copy to temp buffer
													if( pAudio->m_audio_data_residue[k] + audio_size < FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.period_bytes_min * 2)
													{
														memcpy( pAudio->m_audio_residue_buffer[k] + pAudio->m_audio_data_residue[k], p_src, audio_size);

														pAudio->m_audio_data_residue[k] += audio_size;
													}

													//retrieve from temp buffer
													if( pAudio->m_audio_data_residue[k] >= FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.period_bytes_min)
													{
														//copy data from buffer
														memcpy( pout, pAudio->m_audio_residue_buffer[k], FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.period_bytes_min);

														//delete removed data
														memcpy( pAudio->m_audio_residue_buffer[k], pAudio->m_audio_residue_buffer[k]+FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.period_bytes_min, pAudio->m_audio_data_residue[k]-FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.period_bytes_min);

														pAudio->m_audio_data_residue[k] -= FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.period_bytes_min;
													
														//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] complete one audio (%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), pAudio->F6578ACFCB40E44819A12FD3E27A48085[k] );

														pAudio->F6578ACFCB40E44819A12FD3E27A48085[k] = (pAudio->F6578ACFCB40E44819A12FD3E27A48085[k] + 1) % (pAudio->FD9C8A1F986EF488a8883B3CAD736747F);
	
														wrapper_snd_pcm_period_elapsed( pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k] );
													}
													
													pAudio->m_nFrameDMANumber[k] = (pAudio->m_nFrameDMANumber[k] + 1) % (pAudio->FD9C8A1F986EF488a8883B3CAD736747F);

													#else

													memcpy( pout, p_src, 4096);

													//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B193E8EB198B4259AED0BEB981811492() audio copy to AP, F6578ACFCB40E44819A12FD3E27A48085(0d%d) pout(lx%lx) buffer_size(0d%d) k(%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pAudio->F6578ACFCB40E44819A12FD3E27A48085[k], pout, pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k]->runtime->buffer_size, k );

													pAudio->F6578ACFCB40E44819A12FD3E27A48085[k] = (pAudio->F6578ACFCB40E44819A12FD3E27A48085[k] + 1) % (pAudio->FD9C8A1F986EF488a8883B3CAD736747F);
				
													wrapper_snd_pcm_period_elapsed( pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k] );

													#endif
												}

											}
											else
											{
												goto AUDIO_SKIP;
											}
										}
										else
										{
											goto AUDIO_SKIP;
										}
									}
									else
									{
										goto AUDIO_SKIP;
									}
								}
							}//if complete
						}// if state
					}//for
				}// if po
				else
				{
					if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F13A906F1479D4245B9F207A09C70BCE6[ pAudio->F0DD7393CD1494e27A72652C7D1A97893 ] & ( 1 << k ) ) {

						//send silent audio anyway
						/*
						if( pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] == 0 &&

							pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] == 0 ) { // VIDEO 出來後再送出 AUDIO

							NULL;
						}
						else
						*/
						{

							if( pDevice->m_nAnalogVideoDecoderStatusProperty == 0 )
							{
								if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k])
								{
									if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k]->runtime)
									{
										if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k]->runtime->dma_area)
										{
											pout = (BYTE*) (pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k]->runtime->dma_area);

											pout += pAudio->F6578ACFCB40E44819A12FD3E27A48085[k] * pAudio->F1461B75D9C644717A130B5C10D966CF0;

											if( pout <= ((BYTE*) (pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k]->runtime->dma_area) + FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.period_bytes_min * (FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.periods_min - 1) ) )
											{
												memset(pout, 0x00, FEAF4AC49BEDE45c48099A8E9544363A3_PL330B.period_bytes_min);

												//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] B193E8EB198B4259AED0BEB981811492() audio silence copy to AP, F6578ACFCB40E44819A12FD3E27A48085(0d%d) pout(lx%lx) buffer_size(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pAudio->F6578ACFCB40E44819A12FD3E27A48085[k], pout, pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k]->runtime->buffer_size);
												
												pAudio->F6578ACFCB40E44819A12FD3E27A48085[k] = (pAudio->F6578ACFCB40E44819A12FD3E27A48085[k] + 1) % (pAudio->FD9C8A1F986EF488a8883B3CAD736747F);
			
												wrapper_snd_pcm_period_elapsed( pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[k] );
											}

										}
										else
										{
											goto AUDIO_SKIP;
										}
									}
									else
									{
										goto AUDIO_SKIP;
									}
								}
								else
								{
									goto AUDIO_SKIP;
								}
							}
						}
					}
				}// if state
			}//if paudio
		}//end of for
AUDIO_SKIP:
		
		{	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
				
			ULONG s = pDevice->B9F485FBC2EE44B287E5FA879D64F1F7[ 1 ]++;

			pDevice->B9F485FBC2EE44B287E5FA879D64F1F7[ 1 ] %= 16;

			s %= 16;

			AC2AF440EE544A07939115ECB1E826B8( pDevice, 1, s, &pDevice->CDA0E8191AB44A53A0F640EDE8B8F70C[ 1 ][ s ], NULL, &(p_sys_cfg->o_output_dma_buffers[ 1 ][ s ]) );

			if( pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ 1 ] != TQP_NULL_HANDLE &&
				
				pDevice->m_pMpegCodec != QP_NULL ) {

				EQP_Errors qp_status = pDevice->m_pMpegCodec->AddBuffer( pDevice->m_pMpegCodec, 
					
																			pDevice->BE6018DEEC2C4BFAA101248A9C6F312F[ 1 ], 
																		 
																		&(pDevice->CDA0E8191AB44A53A0F640EDE8B8F70C[ 1 ][ s ]) );
			}
		}
		//if no video, this parameter do not increase, otherwise , silent audio will not occur
		if( po && pDevice->m_nAnalogVideoDecoderStatusProperty ) //real audio interrupt
		{
			pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ]++;
		}

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 1;
	}

#endif

	return QPERR_SUCCESS;
}

NTSTATUS C46ED33BB5514DE9B78DCDFF16BAC52E( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	wrapper_down( &(pDevice->m_pControlSemaphore) ); 

	if( pDevice->m_pControlThread == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] C46ED33BB5514DE9B78DCDFF16BAC52E( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

		pDevice->m_pControlThread = wrapper_kthread_run( (INT)A7C0450F9E8E4C14975C2EC9EF06A513, pDevice, "A7C0450F9E8E4C14975C2EC9EF06A513" );

		if( wrapper_IS_ERR( pDevice->m_pControlThread ) ) {

			int ret = wrapper_PTR_ERR( pDevice->m_pControlThread );

			pDevice->m_pControlThread = NULL;

			return ret;
		}
	}
	wrapper_up( &(pDevice->m_pControlSemaphore) );

	return STATUS_SUCCESS;
}

NTSTATUS E0DDF28968D942EAB74C3DD59AD1E41B( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	int thread_stop_counter = 0;

	wrapper_down( &(pDevice->m_pControlSemaphore) ); 

	if( pDevice->m_pControlThread ) {

		if( pDevice->m_ReadyToStopControlThread == 0 )
		{
			pDevice->m_ReadyToStopControlThread = 1;

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] E0DDF28968D942EAB74C3DD59AD1E41B( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );
		
			wrapper_kthread_stop( pDevice->m_pControlThread ); // GOOD NEWS!! LINUX HAD ALREADY HELPED TO FINISH THE "STOP" SYNC.

			while( pDevice->m_pControlThread_already_stop == FALSE )
			{
				wrapper_schedule_timeout_interruptible( wrapper_msecs_to_jiffies(200) );

				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] E0DDF28968D942EAB74C3DD59AD1E41B( ) ---\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

				thread_stop_counter++;

				if(thread_stop_counter > 5)
				{
					break;
				}
			}

			pDevice->m_pControlThread = NULL;

			pDevice->m_ReadyToStopControlThread = 0;
		
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] E0DDF28968D942EAB74C3DD59AD1E41B( ) end\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );
		}
	}
	wrapper_up( &(pDevice->m_pControlSemaphore) );

	return STATUS_SUCCESS;
}

void CheckAllSettingParameters( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG* status )
{
	#ifdef AME_PL330B

	PL330B_SYS_CFG * pSysCfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	if( pDevice->m_size_not_match_no_signal_blue_pattern )
	{
		ULONG height = ( pDevice->m_nCustomAnalogVideoResolutionProperty  & 0xFFFF );

		ULONG fps = pSysCfg->n_input_video_resolution_fps;

		if( pDevice->m_nCustomAnalogVideoInterleavedProperty == 1 )
		{
			height = ( pDevice->m_nCustomAnalogVideoResolutionProperty  & 0xFFFF ) * 2;

			fps /= 2;
		}

		if(pDevice->m_pVideo[ 0 ][ 0 ])
		{
			//size
			if( (pDevice->m_pVideo[ 0 ][ 0 ]->FD1832F8D382F4e91914C0048CC5A9DD8 != (( pDevice->m_nCustomAnalogVideoResolutionProperty >> 16 ) & 0xFFFF )) || ( pDevice->m_pVideo[ 0 ][ 0 ]->F5B8891B732954fc2B26B7BFFCB15B596 != height ) )
			{
				*status = 0;

				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] m_nAnalogVideoDecoderStatusProperty(0x%x) size\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), pDevice->m_nAnalogVideoDecoderStatusProperty );
			}
			//type
			if( pDevice->m_pVideo[ 0 ][ 0 ]->FEDE037FA62F943829C230928859309D9 == V4L2_FIELD_INTERLACED )
			{
				if( pDevice->m_nCustomAnalogVideoInterleavedProperty == 0 )
				{
					*status = 0;

					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] m_nAnalogVideoDecoderStatusProperty(0x%x) type interlace\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), pDevice->m_nAnalogVideoDecoderStatusProperty );
				}
			}
			else
			{
				if( pDevice->m_nCustomAnalogVideoInterleavedProperty == 1 )
				{
					*status = 0;

					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] m_nAnalogVideoDecoderStatusProperty(0x%x) type progressive\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), pDevice->m_nAnalogVideoDecoderStatusProperty );
				}
			}
		}
		//frame rate
		if( ( pDevice->m_timeperframe_denominator != ( fps * 1000) ) || ( pDevice->m_timeperframe_numerator != ( pSysCfg->n_input_video_resolution_fps_m | 1000 ) ) )
		{
			*status = 0;

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] m_nAnalogVideoDecoderStatusProperty(0x%x) frame rate\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), pDevice->m_nAnalogVideoDecoderStatusProperty );
		}
	}
	#endif
}

VOID A7C0450F9E8E4C14975C2EC9EF06A513( void * FD51B2B4E0CAC4359A9EFA429A9E16157 )
{	
#if defined(AME_PL330B) || defined(AME_PL330A)

	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)FD51B2B4E0CAC4359A9EFA429A9E16157;

	pDevice->m_pControlThread_already_stop = FALSE;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] A7C0450F9E8E4C14975C2EC9EF06A513( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	ULONG status_backup = pDevice->m_nAnalogVideoDecoderStatusProperty;

	ULONG no_signals = 0;

	ULONG counts = 0;

	while( wrapper_kthread_should_stop() == FALSE ) {

		PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		//this is ugly but necesary
		//in stopfirmware, setcrossbar in one new thread, stopfirmware in another thread, two thread can access GV7610, mst3367 .. at same time
		if( pDevice->m_pl330b_control_thread_stop )
		{
			wrapper_schedule_timeout_interruptible( wrapper_msecs_to_jiffies(100) );
	
			continue;
		}
		
		if( (counts % 10) == 0 ) { 
			
			if( pDevice->iManufacturer == 0x4A ||

				pDevice->iManufacturer == 0xAA ) {
				
				CheckHDMIRX(pDevice );
			}
			else if( (pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_USB && pDevice->iManufacturer == 0xAD) ||
		
					 (pDevice->iManufacturer == 0x2A) || // DARIM.4B.SC542N2-L SDI

					 (pDevice->iManufacturer == 0x2C) || // DARIM.4B.SC542N4 SDI
	
					 (pDevice->iManufacturer == 0x2E) || // DARIM.4B.SC542N4 HYBRID.2ND
	
					 (pDevice->iManufacturer == 0x27) || // DARIM.4B.SC542N6 HYBRID.2ND

					 (pDevice->iManufacturer == 0x44) ||

					 pDevice->iManufacturer == 0x4B ||

					 pDevice->iManufacturer == 0xA4 ||

					 pDevice->iManufacturer == 0xAB ||

					 //pDevice->iManufacturer == 0xAD ||

					 pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

				// VIDEO FORAMT DETECTION
				// 
				BOOL   b_i2c_returns = FALSE;

				USHORT R00006 = 0x0000;

				USHORT R0001F = 0x0000;

				USHORT R00022 = 0x0000;

				USHORT R00023 = 0x0000;

			//	R00006 = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x0006 ) & 0x3F00; R00006 >>= 8; // VD_STD
			//
			//	R0001F = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x001F ) & 0x3FFF; // WORDS PER ACTIVE LINE
			//
			//	R00022 = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x22 ) & 0x2000; // M

				R00006 = C00DF1D7428943A5A947C729729E597F( pDevice, 0, 0x66, 0x0006, &b_i2c_returns ) & 0x3F00; R00006 >>= 8; // VD_STD

				if( b_i2c_returns == FALSE ) { counts++; F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 ); continue; }
				
				R0001F = C00DF1D7428943A5A947C729729E597F( pDevice, 0, 0x66, 0x001F, &b_i2c_returns ) & 0x3FFF; // WORDS PER ACTIVE LINE

				if( b_i2c_returns == FALSE ) { counts++; F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 ); continue; }

				R00022 = C00DF1D7428943A5A947C729729E597F( pDevice, 0, 0x66, 0x22, &b_i2c_returns ); // M

				if( b_i2c_returns == FALSE ) { counts++; F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 ); continue; }

				R00023 = C00DF1D7428943A5A947C729729E597F( pDevice, 0, 0x66, 0x23, &b_i2c_returns );

				if( b_i2c_returns == FALSE ) { counts++; F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 ); continue; }

				ULONG x = 0;

				ULONG y = 0;

				ULONG fps = 0;

				ULONG m = 0;

				//chech if lock
				if( ((R00022 & 0x1000) == 0x1000) && ((R00023 & 0x3) == 0x3) )// video standard lock, H, V lock
				{
					m = (R00022 & 0x2000) ? 1 : 0; // EX: 29.97 / 30.00

					if( R00006 == 0x16 || R00006 == 0x17 ) 
					{ 
						if( (R0001F == 1440) )
						{
							x =  720; y =  240; fps = 60; m = 1; /*can not detected*/
						}
					}

					if( R00006 == 0x19 || R00006 == 0x1B )
					{ 
						if( (R0001F == 1440) )
						{
							x =  720; y =  240; fps = 60; m = 1; /*can not detected*/
						}
					}

					if( R00006 == 0x18 || R00006 == 0x1A ) 
					{ 
						if( (R0001F == 1440) )
						{
							x =  720; y =  288; fps = 50;
						}
					}

					if( R00006 == 0x1E ) { 
					
						USHORT R00021 = C12B7BD9B5134F53981EE3E7702A7E44( pDevice, 0, 0x66, 0x0021 )  & 0x07FF; // LINES PER FRAME 

						if( R0001F == 1440 )
						{
							if( R00021 == 525 ) {

								x = 720; y = 288; fps = 50; 
							}
							else {

								x = 720; y = 240; fps = 60; m = 1; /*can not detected*/ 
							}
						}
					}
					if( R00006 == 0x20 || R00006 == 0x00 )
					{ 
						if( (R0001F == 1280) && ((R00022 & 0x7FF) == 720) )
						{
							x = 1280; y =  720; fps = 60;
						}
					}

					if( R00006 == 0x24 || R00006 == 0x04 )
					{ 
						if( (R0001F == 1280) && ((R00022 & 0x7FF) == 720) )
						{
							x = 1280; y =  720; fps = 50;
						}
					}

				//	if( R00006 == 0x22 || R00006 == 0x02 ) { x = 1280; y =  720; fps = 30; } // 不支援

				//	if( R00006 == 0x26 || R00006 == 0x06 ) { x = 1280; y =  720; fps = 25; } // 不支援

				//	if( R00006 == 0x28 || R00006 == 0x08 ) { x = 1280; y =  720; fps = 24; } // 不支援

					if( R00006 == 0x2A || R00006 == 0x0A ) 
					{ 
						if( (R0001F == 1920) && ((R00022 & 0x7FF) == 540) )
						{
							x = 1920; y =  540; fps = 60;
						}
					}

					if( R00006 == 0x2C || R00006 == 0x0C ) 
					{ 
						if( (R0001F == 1920) && ((R00022 & 0x7FF) == 540) )
						{
							x = 1920; y =  540; fps = 50;
						}
					}

					if( R00006 == 0x11                   )
					{ 
						if( (R0001F == 1920) && ((R00022 & 0x7FF) == 540) )
						{
							x = 1920; y =  540; fps = 48;
						}
					}

					if( R00006 == 0x2B || R00006 == 0x0B )
					{ 
						if( (R0001F == 1920) && ((R00022 & 0x7FF) == 1080) )
						{
							x = 1920; y = 1080; fps = 30;
						}
					}

					if( R00006 == 0x2D || R00006 == 0x0D ) 
					{ 
						if( (R0001F == 1920) && ((R00022 & 0x7FF) == 1080) )
						{
							x = 1920; y = 1080; fps = 25;
						}
					}

					if( R00006 == 0x30 || R00006 == 0x10 )
					{ 
						if( (R0001F == 1920) && ((R00022 & 0x7FF) == 1080) )
						{
							x = 1920; y = 1080; fps = 24;
						}
					}

					if( R00006 == 0x2B && R0001F == 1920 )
					{ 
						if( (R0001F == 1920) && ((R00022 & 0x7FF) == 1080) )
						{
							x = 1920; y = 1080; fps = 60;
						}
					}

					if( R00006 == 0x2D && R0001F == 1920 )
					{ 
						if( (R0001F == 1920) && ((R00022 & 0x7FF) == 1080) )
						{
							x = 1920; y = 1080; fps = 50;
						}
					}
				}
				
				//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] GV7601_ NO SDI R00006( 0x%x ) H_active(%d) V_active(%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, R00006, R0001F, R00022 & 0x7FF );

				if( x != 0 && y != 0 ) {

					B6DA6D73E4484C36B5A7CF9DFE4BBFB0( pDevice, pDevice->m_nAnalogVideoDecoderStatusProperty, 1 );

					if( p_sys_cfg->n_input_video_resolution_cx != x ||

						p_sys_cfg->n_input_video_resolution_cy != y ||

						p_sys_cfg->n_input_video_resolution_fps != fps ||

						p_sys_cfg->n_input_video_resolution_fps_m != m ) {

						p_sys_cfg->n_input_video_resolution_cx = x;

						p_sys_cfg->n_input_video_resolution_cy = y;

						p_sys_cfg->n_input_video_resolution_fps = fps;

						p_sys_cfg->n_input_video_resolution_fps_m = m;

						if( p_sys_cfg->n_input_video_resolution_cy == 240 ||

							p_sys_cfg->n_input_video_resolution_cy == 288 ||

							p_sys_cfg->n_input_video_resolution_cy == 540 ) {

							p_sys_cfg->n_input_video_resolution_interleaved = 1;
						}
						else {

							p_sys_cfg->n_input_video_resolution_interleaved = 0;
						}
						p_sys_cfg->b_input_video_signal_changed = TRUE;
						
						p_sys_cfg->n_input_audio_sampling_frequency = 48000;
					}

					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] GV7601_SDI_MODE_DETECT( %d x %d x %d ) m(%d) H_active(%d) V_active(%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, (ULONG)(x), (ULONG)(y), fps, m, R0001F, R00022 & 0x7FF );

					if( p_sys_cfg->n_input_video_resolution_fps > 50 ) {

						pDevice->FD314ADAD9404496b842EBFC396E875CB = V4L2_STD_NTSC_M;
					}
					else if( p_sys_cfg->n_input_video_resolution_fps > 30 ) {

						pDevice->FD314ADAD9404496b842EBFC396E875CB = V4L2_STD_PAL_B;
					}
					else if( p_sys_cfg->n_input_video_resolution_fps > 25 ) {

						pDevice->FD314ADAD9404496b842EBFC396E875CB = V4L2_STD_NTSC_M;
					}
					else {

						pDevice->FD314ADAD9404496b842EBFC396E875CB = V4L2_STD_PAL_B;
					}
					pDevice->m_nCustomAnalogVideoResolutionProperty = (p_sys_cfg->n_input_video_resolution_cx << 16) |

																	  (p_sys_cfg->n_input_video_resolution_cy <<  0);

					pDevice->m_nCustomAnalogVideoFrameRateProperty = (p_sys_cfg->n_input_video_resolution_fps);

					pDevice->m_nCustomAnalogVideoInterleavedProperty = (p_sys_cfg->n_input_video_resolution_interleaved);
					
					pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 48000;

					pDevice->m_nAnalogVideoDecoderStatusProperty = 1;

					if( pDevice->m_size_not_match_no_signal_blue_pattern )
					{
						CheckAllSettingParameters( pDevice, &pDevice->m_nAnalogVideoDecoderStatusProperty );
					}

					pDevice->m_nAnalogCopyProtMacrovisionProperty = 0;
				}
				else {

					B6DA6D73E4484C36B5A7CF9DFE4BBFB0( pDevice, pDevice->m_nAnalogVideoDecoderStatusProperty, 0 );

					pDevice->m_nCustomAnalogVideoResolutionProperty = 0;

					pDevice->m_nCustomAnalogVideoFrameRateProperty = 0;

					pDevice->m_nCustomAnalogVideoInterleavedProperty = 0;

					pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 0;

					pDevice->m_nAnalogVideoDecoderStatusProperty = 0;
					
					pDevice->m_nAnalogCopyProtMacrovisionProperty = 0;

					//keep it at 48000
					//p_sys_cfg->n_input_audio_sampling_frequency = 0;

					/*
					BOOL   b_i2c_returns = FALSE;
					F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "\n" );
					F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00006(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, R00006 );
					F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R0001F(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, R0001F );
					F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00020(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, C00DF1D7428943A5A947C729729E597F( pDevice, 0, 0x66, 0x0020, &b_i2c_returns ) );
					F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00021(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, C00DF1D7428943A5A947C729729E597F( pDevice, 0, 0x66, 0x0021, &b_i2c_returns ) );
					F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00022(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, C00DF1D7428943A5A947C729729E597F( pDevice, 0, 0x66, 0x0022, &b_i2c_returns ) );
					F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00023(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, C00DF1D7428943A5A947C729729E597F( pDevice, 0, 0x66, 0x0023, &b_i2c_returns ) );
					F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00024(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, C00DF1D7428943A5A947C729729E597F( pDevice, 0, 0x66, 0x0024, &b_i2c_returns ) );
					F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00025(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, C00DF1D7428943A5A947C729729E597F( pDevice, 0, 0x66, 0x0025, &b_i2c_returns ) );
					F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00026(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, C00DF1D7428943A5A947C729729E597F( pDevice, 0, 0x66, 0x0026, &b_i2c_returns ) );
					F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "\n" );
					*/
				}
			}
			else {

				if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 || 
					
					pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) {
					
					ULONG status_backup = pDevice->m_nAnalogVideoDecoderStatusProperty;

					if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_60HZ ) {

						pDevice->m_nAnalogVideoDecoderStatusProperty = ( ((BYTE)(DD0D84BB34264335874009D864B98B9C( pDevice, 0, 0x88, 0x01 )) & 0xC9) == 0x48 ) ? 1 : 0; F6B9E557A4BA24ffd926B820B836289C8_100NS( 1 );
					}
					if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_50HZ ) {

						pDevice->m_nAnalogVideoDecoderStatusProperty = ( ((BYTE)(DD0D84BB34264335874009D864B98B9C( pDevice, 0, 0x88, 0x01 )) & 0xC9) == 0x49 ) ? 1 : 0; F6B9E557A4BA24ffd926B820B836289C8_100NS( 1 );
					}
					B6DA6D73E4484C36B5A7CF9DFE4BBFB0( pDevice, status_backup, pDevice->m_nAnalogVideoDecoderStatusProperty );

					pDevice->m_nAnalogCopyProtMacrovisionProperty = 0;
				}
				else {

					MST3367_VideoFormatDetection( pDevice );
				}
			}
		}

		if( pDevice->m_nAnalogVideoDecoderStatusProperty == 0 ) {
			
			no_signals++;
		}
		else {

			no_signals = 0;
		}

		if( (pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] & 0x88000000) || (pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ 0 ] & 0x88000000) )
		{
			NULL;
		}
		else
		{
			if( p_sys_cfg->b_input_video_signal_changed )//reset frame rate, low priority than 0x88...
			{
				
				if( (pDevice->iManufacturer & 0xF0) == (0x40) ) { // SC540

					if(p_sys_cfg->n_input_video_resolution_interleaved == 1)
					{
						pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] = p_sys_cfg->n_input_video_resolution_fps / 2;
					}
					else
					{
						pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] = p_sys_cfg->n_input_video_resolution_fps;
					}
		
				}
				else
				{
					if(p_sys_cfg->n_input_video_resolution_interleaved == 1)
					{
						pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] = p_sys_cfg->n_input_video_resolution_fps / 2;

						pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ 0 ] = p_sys_cfg->n_input_video_resolution_fps / 2;
					}
					else
					{
						pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] = p_sys_cfg->n_input_video_resolution_fps;

						pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ 0 ] = p_sys_cfg->n_input_video_resolution_fps;

						int cx = p_sys_cfg->n_input_video_resolution_cx;
						int cy = p_sys_cfg->n_input_video_resolution_cy;
						int fps = p_sys_cfg->n_input_video_resolution_fps;

						if( (cx == 1280 && cy == 800 && fps >= 60) || (cx * cy * fps) > (1920 * 1200 * 30) )
						{ 
							pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] = p_sys_cfg->n_input_video_resolution_fps/2;

							pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ 0 ] = p_sys_cfg->n_input_video_resolution_fps/2;
						}

					}

				}
				//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ](%d) m_nCustomEncoderVideoAvgFrameRateProperty[ 0 ](%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ], pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ 0 ]);
			}
		}


#if 1 // [XXXXX]

		if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 0 ) {

			PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

#if defined(AME_PL330B) || defined(AME_PL330A)

			if( (p_sys_cfg->n_input_video_resolution_cx > 0 && p_sys_cfg->n_input_video_resolution_cy > 0) ) { // [2016.12.20] 加入 SOFTWARE WATCHDOG 機制

				if( pDevice->m_initData.mpgCodecInitData.BusType == QPHCI_BUS_PCI ) {

					if( pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 3 ] > 100 ) {

						pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 3 ] = 0;

						F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[SOFTWARE.WATCHDOG.RESET]\n");

						p_sys_cfg->b_input_video_signal_changed = TRUE;
					}
				}
			}
			if( pDevice->m_nCustomAnalogAudioDirectSoundPatchProperty == 0 ) {

				if( pDevice->m_nCustomEncoderVideoProfileProperty[ 0 ] & 0x88000000 ||

					pDevice->m_nCustomEncoderVideoLevelProperty[ 0 ] & 0x88000000 ||

					pDevice->m_nCustomEncoderVideoEntropyProperty[ 0 ] & 0x88000000 ||

					pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ] & 0x88000000 ||

					pDevice->m_nCustomAnalogVideoSkipFrameRateProperty[ 0 ] & 0x88000000 ||

					pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ 0 ] & 0x88000000 ||

					pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ 0 ] & 0x88000000 ||

					pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ 0 ] & 0x88000000 ) {

					p_sys_cfg->b_input_video_signal_changed = TRUE;
	
					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "video parameters changed, m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ](0x%x)\n", pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ 0 ]);
				}
			}
			if( p_sys_cfg->b_input_video_signal_changed && 

				p_sys_cfg->n_input_video_resolution_cx > 0 &&
				
				p_sys_cfg->n_input_video_resolution_cy > 0 ) {

/*				ULONG cx = p_sys_cfg->n_input_video_resolution_cx;

				ULONG cy = p_sys_cfg->n_input_video_resolution_cy;

				ULONG fps = p_sys_cfg->n_input_video_resolution_fps;

				ULONG m = p_sys_cfg->n_input_video_resolution_fps_m;

				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[RESET] ------------------------------------------------------->\n") );

				AFE6193A7F444538885DA2E6AE62BF0E( pDevice, TRUE, 0 );

				E395C7330A814EB6BB761D5A76D9E4B3( pDevice );

				p_sys_cfg->n_input_video_resolution_cx = cx;

				p_sys_cfg->n_input_video_resolution_cy = cy;

				p_sys_cfg->n_input_video_resolution_fps = fps;

				p_sys_cfg->n_input_video_resolution_fps_m = m;

				p_sys_cfg->b_input_video_signal_changed = FALSE;

				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[RESET] <-------------------------------------------------------\n") );
*/
				p_sys_cfg->b_input_video_signal_changed = FALSE;

				if( p_sys_cfg->n_output_firmware_reset == 1 ) { 

					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[RESET] <-------------------------------------------------------\n");

					E395C7330A814EB6BB761D5A76D9E4B3( pDevice );

					p_sys_cfg->n_output_firmware_reset = 0;
				}
				else {

					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[RESET] ------------------------------------------------------->\n");

					AFE6193A7F444538885DA2E6AE62BF0E( pDevice, TRUE, 1000000 );

					//make setcrossbar thread finish
					wrapper_schedule_timeout_interruptible( wrapper_msecs_to_jiffies(1200) );

					p_sys_cfg->n_output_firmware_reset = 1;
				}
			}
			else {
				
				AA1D4E10781F45AF92A5792997D7623C( pDevice );
			}
#endif
		}
#endif
		status_backup = pDevice->m_nAnalogVideoDecoderStatusProperty;

		counts++;

		//wrapper_schedule_timeout_interruptible( wrapper_msecs_to_jiffies(100) );
		wrapper_schedule_timeout_interruptible( wrapper_msecs_to_jiffies(5) );

		//F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000000 );
	}
	pDevice->m_pControlThread_already_stop = TRUE;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] A7C0450F9E8E4C14975C2EC9EF06A513( exit ) - %08X\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(pDevice->m_pControlThread) );
#endif
	return 0;	

}
NTSTATUS PL330B_StartVideoLossThread( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
#if 1
	if( pDevice->m_pVideoLossThread == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] PL330B_StartVideoLossThread( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

		pDevice->m_pVideoLossThread = wrapper_kthread_run( (INT)PL330B_OnVideoLossThread, pDevice, "PL330B_OnVideoLossThread" );

		if( wrapper_IS_ERR( pDevice->m_pVideoLossThread ) ) {

			int ret = wrapper_PTR_ERR( pDevice->m_pVideoLossThread );

			pDevice->m_pVideoLossThread = NULL;

			return ret;
		}
	}
#endif
	return STATUS_SUCCESS;
}

NTSTATUS PL330B_StopVideoLossThread( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
#if 1
	int thread_stop_counter = 0;

	if( pDevice->m_pVideoLossThread ) {

		if( pDevice->m_ReadyToStopVideoLossThread == 0 )
		{
			pDevice->m_ReadyToStopVideoLossThread = 1;

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] PL330B_StopVideoLossThread( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );
		
			wrapper_kthread_stop( pDevice->m_pVideoLossThread ); // GOOD NEWS!! LINUX HAD ALREADY HELPED TO FINISH THE "STOP" SYNC.

			while( pDevice->m_pVideoLosslThread_already_stop == FALSE )
			{
				wrapper_schedule_timeout_interruptible( wrapper_msecs_to_jiffies(200) );

				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] PL330B_StopVideoLossThread( ) ---\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

				thread_stop_counter++;

				if(thread_stop_counter > 5)
				{
					break;
				}
			}

			pDevice->m_pVideoLossThread = NULL;

			pDevice->m_ReadyToStopVideoLossThread = 0;
		
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] PL330B_StopVideoLossThread( ) end\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );
		}
	}
#endif
	return STATUS_SUCCESS;
}
VOID PL330B_OnVideoLossThread( void * FD51B2B4E0CAC4359A9EFA429A9E16157 )
{
#if 1
	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)FD51B2B4E0CAC4359A9EFA429A9E16157;

	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"PL330B_OnVideoLossThread()\n");

	ULONGLONG n_start_time = 0;

	ULONGLONG n_delta_sum = 0;

	ULONGLONG n_delta_sum_FF7E121E5F6A1461dA967001C1404EB52 = 0;

	ULONGLONG pictures_yv12 = 0;

	ULONGLONG pictures_h264 = 0;

	ULONG     timeouts_yv12 = 0;

	ULONG     timeouts_h264 = 0;

	pDevice->m_pVideoLosslThread_already_stop = FALSE;

	while( wrapper_kthread_should_stop() == FALSE ) {

		BOOL n_signal_loss = FALSE;

		BOOL n_stream_loss_yv12 = FALSE;

		BOOL n_stream_loss_h264 = FALSE;

		if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 0 &&
			
			pDevice->m_nAnalogVideoDecoderStatusProperty == 0 ) {
			
			if( pDevice->iManufacturer == 0x21 || // DARIM.48.SC542N1-L HDV
		
				pDevice->iManufacturer == 0x29 || // DARIM.43.SC542N2 HDV
		
				pDevice->iManufacturer == 0x2D || // DARIM.49.SC542N4 HYBRID.1ST

				pDevice->iManufacturer == 0x26 || // DARIM.48.SC542N6 HYBRID.1ST
		
				pDevice->iManufacturer == 0x40 ||
		
				pDevice->iManufacturer == 0x41 ||
		
				pDevice->iManufacturer == 0x42 ||
		
				pDevice->iManufacturer == 0x43 ||

				pDevice->iManufacturer == 0x48 ||
		
				pDevice->iManufacturer == 0x49 ||

				pDevice->iManufacturer == 0xA0 ||
		
				pDevice->iManufacturer == 0xA1 ||
		
				pDevice->iManufacturer == 0xA2 ||
		
				pDevice->iManufacturer == 0xA3 ||

				pDevice->iManufacturer == 0xA8 ||
		
				pDevice->iManufacturer == 0xA9 ||
		
				pDevice->iManufacturer == 0xAE ||
		
				pDevice->iManufacturer == 0xAF ) {

				if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||  // COMPOSITE

					pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) { // SVIDEO

					n_signal_loss = FALSE;
				}
				else {

					n_signal_loss = TRUE;
				}
			}
			else { 

				n_signal_loss = TRUE;
			}
		}

		if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 0 &&
			
			pDevice->m_nAnalogVideoDecoderStatusProperty == 1 ) {

			if( pDevice->F03D1DD650AC64c28B04687338F970D0E[ 0 ] > 0 ) {

				pDevice->F03D1DD650AC64c28B04687338F970D0E[ 0 ] = 0;

				timeouts_yv12 = 0;
			}
			else {

				timeouts_yv12++;
			}
			if( timeouts_yv12 >= 250 ) {

				//below customer without YV12
				#ifndef NEVRON
				n_stream_loss_yv12 = TRUE;
				#endif
			}
		}
		
		if( (pDevice->iManufacturer & 0xF0) != (0x40) ) {

			if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 0 &&
			
				pDevice->m_nAnalogVideoDecoderStatusProperty == 1 ) {

				if( pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ] > 0 ) {

					pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ] = 0;

					timeouts_h264 = 0;
				}
				else {

					timeouts_h264++;
				}
				if( timeouts_h264 >= 250 ) {

					n_stream_loss_h264 = TRUE;
				}
			}
		}

		if( n_signal_loss ||
			
			n_stream_loss_yv12 ||

			n_stream_loss_h264 ) {

#if defined(AME_PL330B) || defined(AME_PL330A)
			struct timeval ts;

			wrapper_do_gettimeofday( &ts );
			
			ULONGLONG n_current_time = ts.tv_sec * 10000000 + ts.tv_usec * 10;

			if( n_start_time == 0 ) { 
				
				n_start_time = n_current_time; 
				
				n_delta_sum = 0; 
				
				n_delta_sum_FF7E121E5F6A1461dA967001C1404EB52 = 0; 

				pictures_yv12 = 0;

				pictures_h264 = 0;
			}
			BOOL is_on = FALSE;

			ULONGLONG duration = 333333;

			ULONG fps = p_sys_cfg->n_output_video_resolution_fps * 1000;

			ULONG fps_yv12 = p_sys_cfg->n_output_video_resolution_fps_yv12 * 1000;

			if( pDevice->m_size_not_match_no_signal_blue_pattern )
			{
				fps = pDevice->m_timeperframe_denominator;

				fps_yv12 = pDevice->m_timeperframe_denominator;
			}


			ULONG fps_h264 = p_sys_cfg->n_output_video_resolution_fps_h264 * 1000;


			if( pDevice->m_size_not_match_no_signal_blue_pattern )
			{
				if( pDevice->m_timeperframe_numerator != 0 ) {

					fps *= 1000;

					fps /= pDevice->m_timeperframe_numerator; 
				}
			}
			else
			{
				if( p_sys_cfg->n_output_video_resolution_fps_1_2 >= 1 ) {

					fps >>= 1;
				}
				if( p_sys_cfg->n_output_video_resolution_fps_m >= 1 ) {

					fps *= 1000;

					fps /= 1001; 
				}
			}
			if( fps == 0 ) {

				fps = 30000;
			}
			//duration = 10000000000 / fps;

			//LONGLONG FF7E121E5F6A1461dA967001C1404EB52 = (1000000000000000000 / fps) - (duration * 100000000); // 小數點位

			LONGLONG a_temp = 10000000000;
			LONGLONG b_temp = 1000000000000000000;
		
			do_div(a_temp, fps);
			
			duration = a_temp;
		
			do_div( b_temp, fps);

			LONGLONG FF7E121E5F6A1461dA967001C1404EB52 = b_temp - (duration * 100000000); // 小數點位

			if( (n_current_time - n_start_time) - (n_delta_sum) >= duration ) {

				n_delta_sum += duration;

				n_delta_sum_FF7E121E5F6A1461dA967001C1404EB52 += FF7E121E5F6A1461dA967001C1404EB52;

				if( n_delta_sum_FF7E121E5F6A1461dA967001C1404EB52 >= 100000000 ) {

					n_delta_sum_FF7E121E5F6A1461dA967001C1404EB52 -= 100000000;

					n_delta_sum++; // +1
				}
				is_on = TRUE;
			}

			if( is_on == TRUE ) {

				BOOL is_yv12_on = FALSE;

				BOOL is_h264_on = FALSE;

				pictures_yv12 += fps_yv12;

				pictures_h264 += fps_h264;

				if( pictures_yv12 >= fps ) { pictures_yv12 -= fps; is_yv12_on = TRUE; }

				if( pictures_h264 >= fps ) { pictures_h264 -= fps; is_h264_on = TRUE; }

				if( n_stream_loss_yv12 ) { pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 3 ]++; } // TIMEOUT 計數器

				{
					
					if( is_yv12_on && (n_signal_loss || n_stream_loss_yv12) ) {

						if( pDevice->FA12AAA3D283C4cf0BF02ACD3957899B0[ 0 ] >=  0x00000001 &&
					
							pDevice->E23A0EAB120B4C609DC336EB8B99BE11[ 0 ] != TQP_NULL_HANDLE ) {
							
							//E0E368BED109411F91924286A3FCCC1A( pDevice, QPMPGCODEC_CMD_DONE_DATA, NULL);
							
							pDevice->F9D066B94377B4a9aB14E37D504955651 = NULL;

							if( !pDevice->m_No_Signal_no_output_property )
							{
								PL330B_rawcpy( pDevice );
							}

						}
					}
					if( is_h264_on && (n_signal_loss || n_stream_loss_h264) ) {

						if( pDevice->FDB274CD437614fec94859748411FE56A[ 0 ] ==  0x00000001 &&
					
							pDevice->E23A0EAB120B4C609DC336EB8B99BE11[ 2 ] != TQP_NULL_HANDLE ) {

						}
					}
				}
			}
#endif

		}
		if( n_signal_loss ||
			
			n_stream_loss_yv12 ||

			n_stream_loss_h264 ) {

			F6B9E557A4BA24ffd926B820B836289C8_100NS(  10000 );
		}
		else {

			F6B9E557A4BA24ffd926B820B836289C8_100NS( 100000 );

			n_start_time = 0;

			n_delta_sum = 0;

			n_delta_sum_FF7E121E5F6A1461dA967001C1404EB52 = 0;

			pictures_yv12 = 0;

			pictures_h264 = 0;
		}

		timeouts_yv12++;

		timeouts_h264++;
	}

	pDevice->m_pVideoLosslThread_already_stop = TRUE;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] PL330B_OnVideoLossThread( exit ) - %08X\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(pDevice->m_pVideoLossThread) );
#endif //0
	return 0;	
}

NTSTATUS PL330B_StartAudioLossThread( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
#if 1
	if( pDevice->FF6347EA309EF49519F7F07D0B6B28662LossThread == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] PL330B_StartAudioLossThread( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

		pDevice->FF6347EA309EF49519F7F07D0B6B28662LossThread = wrapper_kthread_run( (INT)PL330B_OnAudioLossThread, pDevice, "PL330B_OnAudioLossThread" );

		if( wrapper_IS_ERR( pDevice->FF6347EA309EF49519F7F07D0B6B28662LossThread ) ) {

			int ret = wrapper_PTR_ERR( pDevice->FF6347EA309EF49519F7F07D0B6B28662LossThread );

			pDevice->FF6347EA309EF49519F7F07D0B6B28662LossThread = NULL;

			return ret;
		}
	}
#endif
	return STATUS_SUCCESS;
}

NTSTATUS PL330B_StopAudioLossThread( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
#if 1
	int thread_stop_counter = 0;

	if( pDevice->FF6347EA309EF49519F7F07D0B6B28662LossThread ) {

		if( pDevice->m_ReadyToStopAudioLossThread == 0 )
		{
			pDevice->m_ReadyToStopAudioLossThread = 1;

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] PL330B_StopAudioLossThread( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );
		
			wrapper_kthread_stop( pDevice->FF6347EA309EF49519F7F07D0B6B28662LossThread ); // GOOD NEWS!! LINUX HAD ALREADY HELPED TO FINISH THE "STOP" SYNC.

			while( pDevice->FF6347EA309EF49519F7F07D0B6B28662LosslThread_already_stop == FALSE )
			{
				wrapper_schedule_timeout_interruptible( wrapper_msecs_to_jiffies(200) );

				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] PL330B_StopAudioLossThread( ) ---\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

				thread_stop_counter++;

				if(thread_stop_counter > 5)
				{
					break;
				}
			}

			pDevice->FF6347EA309EF49519F7F07D0B6B28662LossThread = NULL;

			pDevice->m_ReadyToStopAudioLossThread = 0;
		
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] PL330B_StopVideoLossThread( ) end\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );
		}
	}
#endif
	return STATUS_SUCCESS;
}
VOID PL330B_OnAudioLossThread( void * FD51B2B4E0CAC4359A9EFA429A9E16157 )
{
#if 1
	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)FD51B2B4E0CAC4359A9EFA429A9E16157;

	PL330B_SYS_CFG * p_sys_cfg = (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"PL330B_OnAudioLossThread()\n");

	struct timeval ts;

	wrapper_do_gettimeofday( &ts );
			
	ULONGLONG n_start_time = ts.tv_sec * 10000000 + ts.tv_usec * 10;

	ULONGLONG n_delta_sum = 0;

	ULONGLONG n_delta_sum_FF7E121E5F6A1461dA967001C1404EB52 = 0;

	ULONG counts = 0;

	ULONG timeouts = 0;

	pDevice->FF6347EA309EF49519F7F07D0B6B28662LosslThread_already_stop = FALSE;

	while( wrapper_kthread_should_stop() == FALSE ) {

		BOOL n_signal_loss = FALSE;

		BOOL n_stream_loss = FALSE;

		if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 0 &&
			
			pDevice->m_nAnalogVideoDecoderStatusProperty == 0 &&
			
			pDevice->m_nAnalogCrossbarAudioInputProperty == 0 ) {
			
			n_signal_loss = TRUE;
			/*
			if( pDevice->iManufacturer == 0x4A ||

				pDevice->iManufacturer == 0xAA ) {

				n_signal_loss = TRUE;
			}
			else if( pDevice->iManufacturer == 0x44 ||

					 pDevice->iManufacturer == 0x4B ||

					 pDevice->iManufacturer == 0xA4 ||

					 pDevice->iManufacturer == 0xAB ||

					 pDevice->iManufacturer == 0xAD ||

					 pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

				n_signal_loss = TRUE;
			}
			else {

				;
			}
			*/
		}
		if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 0 &&
			
			pDevice->m_nAnalogVideoDecoderStatusProperty == 1 &&
			
			pDevice->m_nAnalogCrossbarAudioInputProperty == 0 ) {

			if( pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] > 0 ) {

				pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] = 0;

				timeouts = 0;
			}
			else {

				timeouts++;
			}
			if( timeouts >= 100 ) {

				n_stream_loss = TRUE;
			}
		}

		if( n_signal_loss ) {

			if( pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] > 0 ) {
			
				pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] = 0;

				n_signal_loss = FALSE;

				counts = 0;
			}
			else {

				counts++;
			}
			if( counts < 100 ) {

				n_signal_loss = FALSE;
			}
		}

		if( n_signal_loss ||
			
			n_stream_loss ) {

#if defined(AME_PL330B) || defined(AME_PL330A)

			wrapper_do_gettimeofday( &ts );
			
			ULONGLONG n_current_time = ts.tv_sec * 10000000 + ts.tv_usec * 10;

			if( n_start_time == 0 ) { 
				
				n_start_time = n_current_time; 
				
				n_delta_sum = 0; 
			
				n_delta_sum_FF7E121E5F6A1461dA967001C1404EB52 = 0;
			}
			BOOL is_on = FALSE;

			ULONG duration = 213333;

			ULONG frq = 48000;

			if( p_sys_cfg->n_output_audio_sampling_frequency == 48000 ) { duration = 213333; frq = 48000; }

			if( p_sys_cfg->n_output_audio_sampling_frequency == 44100 ) { duration = 232199; frq = 44100; }

			if( p_sys_cfg->n_output_audio_sampling_frequency == 32000 ) { duration = 320000; frq = 32000; }

			//LONGLONG FF7E121E5F6A1461dA967001C1404EB52 = (1024000000000000000 / frq) - (duration * 100000000); // 小數點位
			LONGLONG a_temp = 1024000000000000000;
		
			do_div(a_temp, frq);
			
			LONGLONG FF7E121E5F6A1461dA967001C1404EB52 = a_temp - (duration * 100000000); // 小數點位

			if( (n_current_time - n_start_time) - (n_delta_sum) >= duration ) {

				n_delta_sum += duration;

				n_delta_sum_FF7E121E5F6A1461dA967001C1404EB52 += FF7E121E5F6A1461dA967001C1404EB52;

				if( n_delta_sum_FF7E121E5F6A1461dA967001C1404EB52 >= 100000000 ) {

					n_delta_sum_FF7E121E5F6A1461dA967001C1404EB52 -= 100000000;

					n_delta_sum++; // +1
				}
				is_on = TRUE;
			}
			if( is_on == TRUE ) {
				
				if( pDevice->F13A906F1479D4245B9F207A09C70BCE6[ 0 ] >= 0x00000001 &&
					
					pDevice->E23A0EAB120B4C609DC336EB8B99BE11[ 1 ] != TQP_NULL_HANDLE ) {

					B193E8EB198B4259AED0BEB981811492( pDevice, QPMPGCODEC_CMD_DONE_DATA, NULL);

				}
			}
#endif
		}
		if( n_signal_loss ||
			
			n_stream_loss ) {

			F6B9E557A4BA24ffd926B820B836289C8_100NS(  10000 );
		}
		else {

			F6B9E557A4BA24ffd926B820B836289C8_100NS( 100000 );

			n_start_time = 0;

			n_delta_sum = 0;
		}

		timeouts++;
	}

	pDevice->FF6347EA309EF49519F7F07D0B6B28662LosslThread_already_stop = TRUE;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] PL330B_OnAudioLossThread( exit ) - %08X\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(pDevice->FF6347EA309EF49519F7F07D0B6B28662LossThread) );
#endif //0
	return 0;	
}
int C46ED33BB5514DE9B78DCDFF16BAC52EEX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	C46ED33BB5514DE9B78DCDFF16BAC52E( pDevice );
}

int E0DDF28968D942EAB74C3DD59AD1E41BEX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	E0DDF28968D942EAB74C3DD59AD1E41B( pDevice );
}
