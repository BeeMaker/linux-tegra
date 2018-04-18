#include "LINUXV4L2.h"
#include "property.h"
#include "wrapper.h"
#include "mz0380.h"
#include "mst3367.h"
#include "NVP6124.c"
#include "video_eq.c"

extern F42A18AF66EFF459eA332CA253FFF8A65 * g_pDevice[ 128 ];

//#define MZ0380_COPYPORTECT_ARCHITECTURE

#ifdef MZ0380_COPYPORTECT_ARCHITECTURE

extern ULONG FD0AC55FE0C0B45a788FEC199C5758F1E[ 16 ];

extern ULONG F6053D464C87D41c1B8CBE8A39FCDF2D2[ 16 ];

#endif

extern void RtlCopyMemory( BYTE* pe, BYTE* po, int nFileSize );

ULONG SC2CC_VIN_MAP[ 8 ] = { 0, 2, 1, 3, 4, 6, 5, 7 };

ULONG A350149D4A8740248A2A95D637054F72( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F919EED126B2940ce99A1F7F66A333338, ULONG F0FAB4549F1C3407aACDBD483D0D23C86 )
{
/*
	if( F02179B6B95CB43eeB160478D8CF83778 == 4 ) { return READ_REGISTER_ULONG( (ULONG *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); }

	if( F02179B6B95CB43eeB160478D8CF83778 == 1 ) { return READ_REGISTER_UCHAR( (UCHAR *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); }
*/
	if(F919EED126B2940ce99A1F7F66A333338 != 0)
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] A350149D4A8740248A2A95D637054F72() F919EED126B2940ce99A1F7F66A333338(%d) out of ramge, error\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, F919EED126B2940ce99A1F7F66A333338 );
		return 0x00000000;
	}

	{ return readl( (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ) & 0xFFFFFFFF; }

	return 0x00000000;
}
ULONG A350149D4A8740248A2A95D637054F72_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F919EED126B2940ce99A1F7F66A333338, ULONG F0FAB4549F1C3407aACDBD483D0D23C86,  ULONG F02179B6B95CB43eeB160478D8CF83778)
{
/*
	if( F02179B6B95CB43eeB160478D8CF83778 == 4 ) { return READ_REGISTER_ULONG( (ULONG *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); }

	if( F02179B6B95CB43eeB160478D8CF83778 == 1 ) { return READ_REGISTER_UCHAR( (UCHAR *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); }
*/
	if(F919EED126B2940ce99A1F7F66A333338 != 0)
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] A350149D4A8740248A2A95D637054F72() F919EED126B2940ce99A1F7F66A333338(%d) out of ramge, error\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, F919EED126B2940ce99A1F7F66A333338 );
		return 0x00000000;
	}
	if( F02179B6B95CB43eeB160478D8CF83778 == 4 )
	{
		return readl( (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ) & 0xFFFFFFFF;
	}
	if( F02179B6B95CB43eeB160478D8CF83778 == 1 )
	{
		return readb( (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ) & 0xFF;
	}
	return 0x00000000;
}

BOOLEAN BCAF0A9A9C414EDE9F39B78A1F1FDF37( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F919EED126B2940ce99A1F7F66A333338, ULONG F0FAB4549F1C3407aACDBD483D0D23C86, ULONG F09894BF114FE4ee592C232BC39730E91 )
{
/*
	if( F02179B6B95CB43eeB160478D8CF83778 == 4 ) { WRITE_REGISTER_ULONG( (ULONG *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86), (DWORD)(F09894BF114FE4ee592C232BC39730E91) ); }
	
	if( F02179B6B95CB43eeB160478D8CF83778 == 1 ) { WRITE_REGISTER_UCHAR( (UCHAR *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86), (UCHAR)(F09894BF114FE4ee592C232BC39730E91) ); }
*/

	if(F919EED126B2940ce99A1F7F66A333338 == 1)
	{
		writel( (F09894BF114FE4ee592C232BC39730E91 & 0xFFFFFFFF), (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 5 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); 
	}
	else if(F919EED126B2940ce99A1F7F66A333338 == 0)
	{
		writel( (F09894BF114FE4ee592C232BC39730E91 & 0xFFFFFFFF), (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); 
	}
	else
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] BCAF0A9A9C414EDE9F39B78A1F1FDF37() F919EED126B2940ce99A1F7F66A333338(%d) out of ramge, error\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, F919EED126B2940ce99A1F7F66A333338 );
		return 0x00000000;
	}

	return TRUE;
}

BOOLEAN BCAF0A9A9C414EDE9F39B78A1F1FDF37_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F919EED126B2940ce99A1F7F66A333338, ULONG F0FAB4549F1C3407aACDBD483D0D23C86, ULONG F09894BF114FE4ee592C232BC39730E91, ULONG F02179B6B95CB43eeB160478D8CF83778 )
{
/*
	if( F02179B6B95CB43eeB160478D8CF83778 == 4 ) { WRITE_REGISTER_ULONG( (ULONG *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86), (DWORD)(F09894BF114FE4ee592C232BC39730E91) ); }
	
	if( F02179B6B95CB43eeB160478D8CF83778 == 1 ) { WRITE_REGISTER_UCHAR( (UCHAR *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86), (UCHAR)(F09894BF114FE4ee592C232BC39730E91) ); }
*/

	if(F919EED126B2940ce99A1F7F66A333338 == 1)
	{
		if( F02179B6B95CB43eeB160478D8CF83778 == 4 )
		{
			writel( (F09894BF114FE4ee592C232BC39730E91 & 0xFFFFFFFF), (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 5 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); 
		}
		if( F02179B6B95CB43eeB160478D8CF83778 == 1 )
		{
			writeb( (F09894BF114FE4ee592C232BC39730E91 & 0xFF), (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 5 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); 
		}
	}
	else if(F919EED126B2940ce99A1F7F66A333338 == 0)
	{
		if( F02179B6B95CB43eeB160478D8CF83778 == 4 )
		{
			writel( (F09894BF114FE4ee592C232BC39730E91 & 0xFFFFFFFF), (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); 
		}
		if( F02179B6B95CB43eeB160478D8CF83778 == 1 )
		{
			writeb( (F09894BF114FE4ee592C232BC39730E91 & 0xFF), (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); 
		}
	}
	else
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] BCAF0A9A9C414EDE9F39B78A1F1FDF37() F919EED126B2940ce99A1F7F66A333338(%d) out of ramge, error\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, F919EED126B2940ce99A1F7F66A333338 );
		return 0x00000000;
	}

	return TRUE;
}

ULONGLONG CE445878BCC049BB881864C2A753B0DA( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{ 
	return 0;
}

BOOLEAN MZ0380_F6B9E557A4BA24ffd926B820B836289C8_100NS( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F6B9E557A4BA24ffd926B820B836289C8 )
{
//	wrapper_ndelay( F6B9E557A4BA24ffd926B820B836289C8 * 100 );

	//do not use busy delay
	
	wrapper_schedule_timeout_interruptible( wrapper_msecs_to_jiffies( F6B9E557A4BA24ffd926B820B836289C8/10000 ) );

	return TRUE;
}

extern BOOLEAN F6B9E557A4BA24ffd926B820B836289C8_100NS( ULONG F6B9E557A4BA24ffd926B820B836289C8 );

/*
BOOLEAN F6B9E557A4BA24ffd926B820B836289C8_100NS( ULONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	//wrapper_ndelay( F6B9E557A4BA24ffd926B820B836289C8 * 100 );

	//do not use busy delay
	
	wrapper_schedule_timeout_interruptible( wrapper_msecs_to_jiffies( F6B9E557A4BA24ffd926B820B836289C8/10000 ) );
	
	return TRUE;
}
*/
//BOOLEAN C9E4CF93B97A408B8A8BA64FEC4E18EA( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, DWORD command, LONGLONG F6B9E557A4BA24ffd926B820B836289C8 = 50000000 );

BOOLEAN C9E4CF93B97A408B8A8BA64FEC4E18EA( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, DWORD command, ULONG F6B9E557A4BA24ffd926B820B836289C8 ) 
{
	
	long ret = 0;

	ret = wait_event_interruptible_timeout( pDevice->m_wait_queue_head, pDevice->E92EA7106EDE415589FC494AF89F85E0 == 1, wrapper_msecs_to_jiffies( F6B9E557A4BA24ffd926B820B836289C8/10000 ));
	
	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] C9E4CF93B97A408B8A8BA64FEC4E18EA() E92EA7106EDE415589FC494AF89F85E0(0x%x) ret(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->E92EA7106EDE415589FC494AF89F85E0, ret );

	if( ret <= 0 ){

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] C9E4CF93B97A408B8A8BA64FEC4E18EA() command(0x%x) time out, ret(0d%d)---------------------------\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, command, ret );
		
		return FALSE;
	} 
	else { 
		
		if(pDevice->E92EA7106EDE415589FC494AF89F85E0 == 0)
		{
			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] C9E4CF93B97A408B8A8BA64FEC4E18EA() E92EA7106EDE415589FC494AF89F85E0(0x%x), error----------------------\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );
		}
		else
		{
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] C9E4CF93B97A408B8A8BA64FEC4E18EA() success, E92EA7106EDE415589FC494AF89F85E0(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->E92EA7106EDE415589FC494AF89F85E0 );
		}
		
		wrapper_down( &(pDevice->m_MZ0380AccessSemaphore) ); 

		pDevice->E92EA7106EDE415589FC494AF89F85E0 = 0;

		wrapper_up( &(pDevice->m_MZ0380AccessSemaphore) ); 

		return TRUE;
	} 

/*
	LARGE_INTEGER wait_time; wait_time.QuadPart = -F6B9E557A4BA24ffd926B820B836289C8; // 5S

	if( STATUS_TIMEOUT == KeWaitForSingleObject( &pDevice->m_hIRQAccessSemaphore, Executive, KernelMode, FALSE, &wait_time ) ) { 
	
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "MZ0380 COMMAND TIMEOUT( %d × %08X )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, command);

		return FALSE;
	} 
	else { 
		
		return TRUE;
	} 
*/
//	return TRUE;

}

BOOLEAN E7E90BC718B74429BB9234213955A126( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, DWORD config[ 12 ], ULONG length )
{
	return B601B66F1570418A9F5091D6133C37B8( pDevice, config, length, TRUE, 50000000 );
}

BOOLEAN MZ0380_SendVendorCommand( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, DWORD config[ 12 ], ULONG length, BOOL wait_semaphore )
{
	return B601B66F1570418A9F5091D6133C37B8( pDevice, config, length, wait_semaphore, 50000000 );
}


BOOLEAN B601B66F1570418A9F5091D6133C37B8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, DWORD config[ 12 ], ULONG length, BOOL wait_semaphore, LONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	if( length <= 1 ) { return FALSE; }

	if( p_sys_cfg->n_firmware_timeouts >= 10 ) { // 避免無法進入系統
		
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "MZ0380_SEND_COMMAND( %08X, %d ) TIMEOUT!!\n", config[ 1 ], p_sys_cfg->n_firmware_timeouts);

		return FALSE;
	}

	if( wait_semaphore ) {
		//use m_MZ0380AccessSemaphore, already done in modinit
		/*
		KeInitializeSemaphore( &(pDevice->m_hIRQAccessSemaphore), 0, 0x7FFFFFFF );
		*/
	}
	else {

		BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 0, (0x00000004 * 11), 0x00000000 );
	}
	ULONG i = 1;
	for( i = 1 ; i < length ; i++ ) {

		BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 0, (0x00000004 * i), config[ i ] );
	}
	BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 0, 0x00000000, 0x00000800 );

	if( (config[ 1 ] != 0x00000018) && (config[ 1 ] != 0x0000001A) && (config[ 1 ] != 0x0000001B) )// MZ0380_CMD_GET_SPI_DATA,  MZ0380_CMD_GET_I2C_DATA, MZ0380_CMD_SET_I2C_DATA
	{
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] MZ0380_SendVendorCommand( 0x%08X ) \n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, config[ 1 ]);
	}

	if( wait_semaphore ) {

		if(config[ 1 ] == 0x00000007) // MZ0380_CMD_STOP_DMA
		{
			int wait_stop_dma_counter = 0;

			while(pDevice->E92EA7106EDE415589FC494AF89F85E0 == 0)
			{
				//F6B9E557A4BA24ffd926B820B836289C8_100NS(1000000);//some interrupt occur
				wrapper_schedule_timeout_uninterruptible( wrapper_msecs_to_jiffies( 10 ) );

				//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "wait MZ0380_CMD_STOP_DMA(%d)--\n", wait_stop_dma_counter);
				
				wait_stop_dma_counter ++;
				
				if(wait_stop_dma_counter > 1000)
				{
					break;
				}
			}
		}
		

		return C9E4CF93B97A408B8A8BA64FEC4E18EA( pDevice, config[ 1 ], F6B9E557A4BA24ffd926B820B836289C8 );
	}
	else { // FOR GOIP/I2C/SPI

		if( F6B9E557A4BA24ffd926B820B836289C8 == 0 ) { return TRUE; }

		ULONG counts = 500;
		ULONG i = 0;
		for( i = 0 ; i < counts ; i++ ) {

	//	for( ULONG i = 0 ; i < 100 ; i++ ) {

			ULONG R = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 11) );

			if( R & 0x01 ) {

				p_sys_cfg->n_firmware_timeouts = 0;

				return TRUE;
			}
			F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000 );
		}
	}
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "MZ0380_SEND_COMMAND( %08X, %d ) ERROR!!\n", config[ 1 ], p_sys_cfg->n_firmware_timeouts++);

	return FALSE;
}

BYTE C27FC32EA272493DB6DBE2D3BFE340AF( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77 )
{	
	BOOLEAN returns = TRUE;

	if( returns ) {

		DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
		
		command[ 1 ] = 0x0000001A; // MZ0380_CMD_GET_I2C_DATA

		command[ 2 ] = F3E85D87;

		command[ 3 ] = F6B106280018F45d7A077070B88512C77;

		command[ 4 ] = 0x00000000;

		if( MZ0380_SendVendorCommand( pDevice, command, 5, FALSE ) ) {

			ULONG R = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 4) );

			return (BYTE)(R);
		}
	}
	return 0x00;
}

BOOLEAN F43E046161B14BCBA21980D4E1F9465B( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE bValue )
{
	BOOLEAN returns = TRUE;

	if( returns ) {
		
		DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	
		command[ 1 ] = 0x0000001B; // MZ0380_CMD_SET_I2C_DATA

		command[ 2 ] = F3E85D87;

		command[ 3 ] = F6B106280018F45d7A077070B88512C77;

		command[ 4 ] = bValue;

		return MZ0380_SendVendorCommand( pDevice, command, 5, FALSE );
	}
	return returns;
}

BYTE E6FB1249C1F642A38BC0228741149CD8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77 )
{	
	BOOLEAN returns = TRUE;

	if( returns ) {

		DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
		
		command[ 1 ] = 0x0000001A; // MZ0380_CMD_GET_I2C_DATA

		command[ 2 ] = F3E85D87;

		command[ 3 ] = F6B106280018F45d7A077070B88512C77;

		command[ 4 ] = 0x00000000;

		if( MZ0380_SendVendorCommand( pDevice, command, 5, FALSE ) ) {

			ULONG R = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 4) );

			return (BYTE)(R);
		}
	}
	return 0x00;
}

BOOLEAN DBF051EEA3B648B49859145F02FA268C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE bValue )
{
	BOOLEAN returns = TRUE;

	if( returns ) {
		
		DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	
		command[ 1 ] = 0x0000001B; // MZ0380_CMD_SET_I2C_DATA

		command[ 2 ] = F3E85D87;

		command[ 3 ] = F6B106280018F45d7A077070B88512C77;

		command[ 4 ] = bValue;

		return MZ0380_SendVendorCommand( pDevice, command, 5, FALSE );
	}
	return returns;
}

BOOLEAN E6FB1249C1F642A38BC0228741149CD8S( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE * pValue, ULONG F02179B6B95CB43eeB160478D8CF83778 )
{
	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	BOOLEAN returns = TRUE;

	if( F02179B6B95CB43eeB160478D8CF83778 > 32 ) { return FALSE; }

	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

	command[ 1 ] = 0x0000001E; // MZ0380_CMD_GET_I2C_DATA_GROUP

	command[ 2 ] = (F02179B6B95CB43eeB160478D8CF83778 << 16) | (F6B106280018F45d7A077070B88512C77 << 8) | (F3E85D87 << 0);

	returns = MZ0380_SendVendorCommand( pDevice, command, 3, FALSE );

	if( returns ) {

		BYTE * po = (BYTE *)(&(command[ 3 ]));

		command[  3 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 *  3) );

		command[  4 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 *  4) );

		command[  5 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 *  5) );

		command[  6 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 *  6) );

		command[  7 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 *  7) );

		command[  8 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 *  8) );

		command[  9 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 *  9) );

		command[ 10 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 10) );

		RtlCopyMemory( pValue, po, F02179B6B95CB43eeB160478D8CF83778 );
	}
	return returns;
}

BOOLEAN DBF051EEA3B648B49859145F02FA268CS( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE * pValue, ULONG F02179B6B95CB43eeB160478D8CF83778 )
{
	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	BOOLEAN returns = TRUE;

	if( F02179B6B95CB43eeB160478D8CF83778 > 32 ) { return FALSE; }
	
	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

	command[ 1 ] = 0x0000001F; // MZ0380_CMD_SET_I2C_DATA_GROUP

	command[ 2 ] = (F02179B6B95CB43eeB160478D8CF83778 << 16) | (F6B106280018F45d7A077070B88512C77 << 8) | (F3E85D87 << 0);

	BYTE * pe = (BYTE *)(&(command[ 3 ]));
	
	RtlCopyMemory( pe, pValue, F02179B6B95CB43eeB160478D8CF83778 );

	returns = MZ0380_SendVendorCommand( pDevice, command, 11, FALSE );

	return returns;
}
BYTE E6FB1249C1F642A38BC0228741149CD8_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE nBank, BYTE F6B106280018F45d7A077070B88512C77 )
{	
	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	BOOLEAN returns = TRUE;

	if( p_sys_cfg->n_bank_reg != nBank ) {

		p_sys_cfg->n_bank_reg = nBank;

		if( returns ) {

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
			
			command[ 1 ] = 0x0000001B; // MZ0380_CMD_SET_I2C_DATA

			command[ 2 ] = F3E85D87;

			command[ 3 ] = 0x00;

			command[ 4 ] = nBank;

			returns = MZ0380_SendVendorCommand( pDevice, command, 5, FALSE );
		}
	}
	if( returns ) {

		DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
		
		command[ 1 ] = 0x0000001A; // MZ0380_CMD_GET_I2C_DATA

		command[ 2 ] = F3E85D87;

		command[ 3 ] = F6B106280018F45d7A077070B88512C77;

		command[ 4 ] = 0x00000000;

		if( MZ0380_SendVendorCommand( pDevice, command, 5, FALSE ) ) {

			ULONG R = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 4) );

			return (BYTE)(R);
		}
	}
	return 0x00;
}

BOOLEAN DBF051EEA3B648B49859145F02FA268C_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE nBank, BYTE F6B106280018F45d7A077070B88512C77, BYTE bValue )
{
	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	BOOLEAN returns = TRUE;

	if( p_sys_cfg->n_bank_reg != nBank ) {

		p_sys_cfg->n_bank_reg = nBank;

		if( returns ) {

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
			
			command[ 1 ] = 0x0000001B; // MZ0380_CMD_SET_I2C_DATA

			command[ 2 ] = F3E85D87;

			command[ 3 ] = 0x00;

			command[ 4 ] = nBank;

			returns = MZ0380_SendVendorCommand( pDevice, command, 5, FALSE );
		}
	}
	if( returns ) {
		
		DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	
		command[ 1 ] = 0x0000001B; // MZ0380_CMD_SET_I2C_DATA

		command[ 2 ] = F3E85D87;

		command[ 3 ] = F6B106280018F45d7A077070B88512C77;

		command[ 4 ] = bValue;

		return MZ0380_SendVendorCommand( pDevice, command, 5, FALSE );
	}
	return returns;
}
BOOLEAN E6FB1249C1F642A38BC0228741149CD8S_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE nBank, BYTE F6B106280018F45d7A077070B88512C77, BYTE * pValue, ULONG F02179B6B95CB43eeB160478D8CF83778 )
{
	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	BOOLEAN returns = TRUE;

	if( F02179B6B95CB43eeB160478D8CF83778 > 32 ) { return FALSE; }
	
	if( p_sys_cfg->n_bank_reg != nBank ) {

		p_sys_cfg->n_bank_reg = nBank;

		if( returns ) {

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
			
			command[ 1 ] = 0x0000001B; // MZ0380_CMD_SET_I2C_DATA

			command[ 2 ] = F3E85D87;

			command[ 3 ] = 0x00;

			command[ 4 ] = nBank;

			returns = MZ0380_SendVendorCommand( pDevice, command, 5, FALSE );
		}
	}
	if( returns ) {

		DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		command[ 1 ] = 0x0000001E; // MZ0380_CMD_GET_I2C_DATA_GROUP

		command[ 2 ] = (F02179B6B95CB43eeB160478D8CF83778 << 16) | (F6B106280018F45d7A077070B88512C77 << 8) | (F3E85D87 << 0);

		returns = MZ0380_SendVendorCommand( pDevice, command, 3, FALSE );

		if( returns ) {

			BYTE * po = (BYTE *)(&(command[ 3 ]));

			command[  3 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 *  3) );

			command[  4 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 *  4) );

			command[  5 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 *  5) );

			command[  6 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 *  6) );

			command[  7 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 *  7) );

			command[  8 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 *  8) );

			command[  9 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 *  9) );

			command[ 10 ] = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 10) );

			RtlCopyMemory( pValue, po, F02179B6B95CB43eeB160478D8CF83778 );
		}
	}
	return returns;
}

BOOLEAN DBF051EEA3B648B49859145F02FA268CS_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE nBank, BYTE F6B106280018F45d7A077070B88512C77, BYTE * pValue, ULONG F02179B6B95CB43eeB160478D8CF83778 )
{
	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	BOOLEAN returns = TRUE;

	if( F02179B6B95CB43eeB160478D8CF83778 > 32 ) { return FALSE; }
	
	if( p_sys_cfg->n_bank_reg != nBank ) {

		p_sys_cfg->n_bank_reg = nBank;

		if( returns ) {

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
			
			command[ 1 ] = 0x0000001B; // MZ0380_CMD_SET_I2C_DATA

			command[ 2 ] = F3E85D87;

			command[ 3 ] = 0x00;

			command[ 4 ] = nBank;

			returns = MZ0380_SendVendorCommand( pDevice, command, 5, FALSE );
		}
	}
	if( returns ) {

		DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		command[ 1 ] = 0x0000001F; // MZ0380_CMD_SET_I2C_DATA_GROUP

		command[ 2 ] = (F02179B6B95CB43eeB160478D8CF83778 << 16) | (F6B106280018F45d7A077070B88512C77 << 8) | (F3E85D87 << 0);

		BYTE * pe = (BYTE *)(&(command[ 3 ]));

		RtlCopyMemory( pe, pValue, F02179B6B95CB43eeB160478D8CF83778 );

		returns = MZ0380_SendVendorCommand( pDevice, command, 11, FALSE );
	}
	return returns;
}

BYTE MZ0380_GetITE6603Register( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex )
{
	return E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x90, nIndex );
}

BOOL MZ0380_GetITE6603Register_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, ULONG bBytes, BYTE * pValue )
{
	return E6FB1249C1F642A38BC0228741149CD8S( pDevice, 0, 0x90, nIndex, pValue, bBytes );
}

BOOLEAN MZ0380_SetITE6603Register( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, BYTE bValue )
{
	return DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x90, nIndex, bValue );
}

BOOLEAN MZ0380_SetITE6603Register_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, ULONG bBytes, BYTE * pValue )
{
	return DBF051EEA3B648B49859145F02FA268CS( pDevice, 0, 0x90, nIndex, pValue, bBytes );
}

USHORT D792350EAF024850BDEDF910AE232FD8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, USHORT wIndex )
{
	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	
	command[ 1 ] = 0x00000018; // MZ0380_CMD_GET_SPI_DATA

	command[ 2 ] = wIndex;

	command[ 3 ] = 0x00000000;

	if( MZ0380_SendVendorCommand( pDevice, command, 4, FALSE ) ) {

		ULONG R = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 3) );

		return (USHORT)(R);
	}
	return 0x0000;
}

BOOLEAN C38D9336DFA64B4C8C0AD9DDE94EE013( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, USHORT wIndex, USHORT wValue )
{
	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	
	command[ 1 ] = 0x00000019; // MZ0380_CMD_SET_SPI_DATA

	command[ 2 ] = wIndex;

	command[ 3 ] = wValue;

	return MZ0380_SendVendorCommand( pDevice, command, 4, FALSE );
}

DWORD MZ0380_GetEncryptRegister( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87 )
{
	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
		
	command[ 1 ] = 0x0000001C; // MZ0380_CMD_GET_I2C_DATA_ENCRYPT

	command[ 2 ] = F3E85D87;

	if( MZ0380_SendVendorCommand( pDevice, command, 3, FALSE ) ) {

		ULONG R = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 4) );

		return R;
	}
	return 0x00000000;
}

BOOLEAN D6FA0C681E3A4066A99846121EDF7ABE( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE pValue[ 4 ] )
{
	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	
	command[ 1 ] = 0x0000001D; // MZ0380_CMD_SET_I2C_DATA_ENCRYPT

	command[ 2 ] = F3E85D87;

	command[ 3 ] = F6B106280018F45d7A077070B88512C77;

	command[ 4 ] = sizeof(pValue); // SIZE

	command[ 5 ] = ((DWORD)(pValue[ 0 ]) <<  0) |
		
				   ((DWORD)(pValue[ 1 ]) <<  8) |
		
				   ((DWORD)(pValue[ 2 ]) << 16) |
		
				   ((DWORD)(pValue[ 3 ]) << 24);

	return MZ0380_SendVendorCommand( pDevice, command, 6, FALSE );
}

BYTE E6C9EBA914124FC394536744C5A0DA8C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bBitNum )
{
	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	
	command[ 1 ] = 0x00000014; // MZ0380_CMD_GET_GPIO_PIN_DATA

	command[ 2 ] = 1 << bBitNum;

	command[ 3 ] = 0x00000000;

	if( MZ0380_SendVendorCommand( pDevice, command, 4, FALSE ) ) {

		ULONG R = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 3) );

		return (BYTE)((R >> bBitNum) & 0x01);
	}
	return 0x00;
}

BOOLEAN D8735A9140EC43B888E108661E19175A( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bBitNum, BYTE bValue )
{
	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	
	command[ 1 ] = 0x00000015; // MZ0380_CMD_SET_GPIO_PIN_DATA

	command[ 2 ] = 1 << bBitNum;

	command[ 3 ] = bValue << bBitNum;

	return MZ0380_SendVendorCommand( pDevice, command, 4, FALSE );
}

BYTE E0F67604297A4CE5A8921272CF92A6AD( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bBitNum )
{
	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	
	command[ 1 ] = 0x00000016; // MZ0380_CMD_GET_GPIO_PIN_DIRECTION

	command[ 2 ] = 1 << bBitNum;

	command[ 3 ] = 0x00000000;

	if( MZ0380_SendVendorCommand( pDevice, command, 4, FALSE ) ) {

		ULONG R = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 3) );

		return (BYTE)((R >> bBitNum) & 0x01);
	}
	return 0x00;
}

BOOLEAN F67AC086BDA7447FB39DC135EB20D85D( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bBitNum, BYTE bDirection )
{
	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	
	command[ 1 ] = 0x00000017; // MZ0380_CMD_SET_GPIO_PIN_DIRECTION

	command[ 2 ] = 1 << bBitNum;

	command[ 3 ] = bDirection << bBitNum; // 0 : OUTPUT, 1 : INPUT

	return MZ0380_SendVendorCommand( pDevice, command, 4, FALSE );
}

BOOLEAN MZ0380_SetOsdString( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, ULONG line, ULONG x, ULONG y, CHAR * psz, ULONG font_size, ULONG font_style )
{
	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

	BOOLEAN returns = FALSE;

	ULONG strlens = strlen( psz );

	{	command[ 1 ] = 0x00000050; // MZ0380_CMD_SET_OSD_STRING

		command[ 2 ] = (font_size << 24) | (font_style << 16) | (strlens << 8) | (0 << 7) | (line << 3) | (i << 0);

		command[ 3 ] = (y << 16) | (x << 0);

		BYTE * pe = (BYTE *)(&(command[ 4 ]));

		RtlCopyMemory( pe, psz, 32 );

		returns = E7E90BC718B74429BB9234213955A126( pDevice, command, 12 );
	}
	{	command[ 1 ] = 0x00000050; // MZ0380_CMD_SET_OSD_STRING

		command[ 2 ] = (font_size << 24) | (font_style << 16) | (strlens << 8) | (1 << 7) | (line << 3) | (i << 0);

		command[ 3 ] = (y << 16) | (x << 0);

		BYTE * pe = (BYTE *)(&(command[ 4 ]));

		RtlCopyMemory( pe, psz + 32, 32 );

		returns = E7E90BC718B74429BB9234213955A126( pDevice, command, 12 );
	}
	return returns;
}

BOOLEAN AB1E68ACD056481BB880D29E744FB86E( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE* pwszFileName, BYTE * pMajorVersion, BYTE * pMinorVersion )
{
/*
	WCHAR			  wszPathName[ 255 ];

	OBJECT_ATTRIBUTES oObjectAttributes;

	UNICODE_STRING    oFileName;

	IO_STATUS_BLOCK   oIoStatus;

	HANDLE            hFileHandle = NULL;

	BYTE *            pFileBuffer = NULL;

	ULONG             nFileSize = 0;

	NTSTATUS          status = STATUS_SUCCESS;

	BYTE			  parms[ 64 ];

	BOOLEAN			  returns = TRUE;

	swprintf( wszPathName, L"%s%s", pDevice->m_pCustomDeviceInfoDirectoryProperty, pwszFileName );

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "AB1E68ACD056481BB880D29E744FB86E( \"%ws\" )\n", wszPathName);

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

		if( oFileStandardInfomation.Directory == TRUE ) {

			ZwClose( hFileHandle );

			return FALSE;
		}
		nFileSize = (ULONG)(oFileStandardInfomation.EndOfFile.QuadPart);

		pFileBuffer = (BYTE *)(ExAllocatePool( NonPagedPool, nFileSize ));

		if( pFileBuffer ) {

			RtlZeroMemory( pFileBuffer, nFileSize );

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
	ULONGLONG start_times = KeQueryInterruptTime();

	ULONGLONG stop_times = 0;

	if( nFileSize >= 5 ) {

		*pMajorVersion  = (pFileBuffer[ 0 ] - '0') * 10;

		*pMajorVersion += (pFileBuffer[ 1 ] - '0') *  1;

		*pMinorVersion  = (pFileBuffer[ 3 ] - '0') * 10;

		*pMinorVersion += (pFileBuffer[ 4 ] - '0') *  1;
	}
	stop_times = KeQueryInterruptTime();

	if( returns ) {

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "TOTAL DOWNLOAD TIMES = %08d (%d BYTES) (SUCCESS) (%d.%d)\n", (ULONG)(stop_times - start_times), nFileSize, *pMajorVersion, *pMinorVersion);
	}
	else {

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "TOTAL DOWNLOAD TIMES = %08d (%d BYTES) (FAIL)\n", (ULONG)(stop_times - start_times), nFileSize);
	}

	// 3.0 FREE WORKING BUFFER
	//
	FREE_MEMORY( pFileBuffer );

	return returns;
*/
	const struct firmware *fw;
	int ret;

	ret = request_firmware(&fw, pwszFileName, &(pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ 0 ]->dev));

	if (ret) {
		//printk(KERN_ERR "xc5000: Upload failed. (file not found?)\n");

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"[%d]AB1E68ACD056481BB880D29E744FB86E() Upload failed. (file not found?)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

		return false;

	} else {
		//printk(KERN_DEBUG "xc5000: firmware read %d bytes.\n", fw->size);

		//printk(KERN_DEBUG " %x %x %x %x\n", *(fw->data + 0), *(fw->data + 1), *(fw->data + 3), *(fw->data + 4));

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] AB1E68ACD056481BB880D29E744FB86E() firmware read %d bytes\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, fw->size);
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] AB1E68ACD056481BB880D29E744FB86E()  %x %x %x %x\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, *(fw->data + 0), *(fw->data + 1), *(fw->data + 3), *(fw->data + 4) );


		if( fw->size >= 5 ) {

			//*pMajorVersion  = (pFileBuffer[ 0 ] - '0') * 10;

			//*pMajorVersion += (pFileBuffer[ 1 ] - '0') *  1;

			//*pMinorVersion  = (pFileBuffer[ 3 ] - '0') * 10;

			//*pMinorVersion += (pFileBuffer[ 4 ] - '0') *  1;

			*pMajorVersion  = (*(fw->data + 0) - '0') * 10;
			*pMajorVersion += (*(fw->data + 1) - '0') *  1;
			*pMinorVersion  = (*(fw->data + 3) - '0') * 10;
			*pMinorVersion += (*(fw->data + 4) - '0') *  1;

		}
		release_firmware(fw);

		return true;
	
	}

}

BOOLEAN MZ0380_DownloadBaseFirmware( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE* pwszFileName, ULONG nFwType ) // 0 : BOOTLOADER, 1: KERNEL
{
/*
	WCHAR			  wszPathName[ 255 ];

	OBJECT_ATTRIBUTES oObjectAttributes;

	UNICODE_STRING    oFileName;

	IO_STATUS_BLOCK   oIoStatus;

	HANDLE            hFileHandle = NULL;

	BYTE *            pFileBuffer = NULL;

	ULONG             nFileSize = 0;

	NTSTATUS          status = STATUS_SUCCESS;

	BYTE			  parms[ 64 ];

	BOOLEAN			  returns = TRUE;

	swprintf( wszPathName, L"%s%s", pDevice->m_pCustomDeviceInfoDirectoryProperty, pwszFileName );

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "MZ0380_DownloadBaseFirmware( \"%ws\" )\n", wszPathName) );

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

		if( oFileStandardInfomation.Directory == TRUE ) {

			ZwClose( hFileHandle );

			return FALSE;
		}
		nFileSize = (ULONG)(oFileStandardInfomation.EndOfFile.QuadPart);

		pFileBuffer = (BYTE *)(ExAllocatePool( NonPagedPool, nFileSize + 4 ));

		if( pFileBuffer ) {

			RtlZeroMemory( pFileBuffer, nFileSize + 4 );

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
	ULONGLONG start_times = KeQueryInterruptTime();

	ULONGLONG stop_times = 0;

	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

	command[ 1 ] = 0x0000000E; // MZ0380_CMD_BEGIN_BASE_FIRMWARE_DOWNLOAD

	command[ 2 ] = nFwType; // 0 : BOOTLOADER, 1: KERNEL

	command[ 3 ] = nFileSize;

	if( MZ0380_SendVendorCommand( pDevice, command, 4 ) == TRUE ) {

		{	ULONGLONG start_times = KeQueryInterruptTime();

			ULONGLONG stop_times = 0;

			WRITE_REGISTER_BUFFER_ULONG( (ULONG *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00000060), (PULONG)(pFileBuffer), (nFileSize + 3) / (4) );

			stop_times = KeQueryInterruptTime();

			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "TOTAL DOWNLOAD TIMES (BUFFER) = %08d (%d BYTES)\n", (ULONG)(stop_times - start_times), nFileSize) );
		}
		DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		command[ 1 ] = 0x0000000F; // MZ0380_CMD_END_BASE_FIRMWARE_DOWNLOAD

		command[ 2 ] = 0x00000001;

		if( MZ0380_SendVendorCommand( pDevice, command, 3, TRUE, 600000000 ) == TRUE ) {

			F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000000 );

			if( A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 2) ) == 0 ) {
				
				returns = TRUE;
			}
			else {

				returns = FALSE;
			}
		}
		else {

			returns = FALSE;
		}
	}
	else {

		returns = FALSE;
	}
	stop_times = KeQueryInterruptTime();

	if( returns ) {

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[jim]TOTAL DOWNLOAD TIMES = %08d (%d BYTES) (SUCCESS)\n", (ULONG)(stop_times - start_times), nFileSize) );
	}
	else {

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[jim]TOTAL DOWNLOAD TIMES = %08d (%d BYTES) (FAIL)\n", (ULONG)(stop_times - start_times), nFileSize) );
	}

	// 3.0 FREE WORKING BUFFER
	//
	FREE_MEMORY( pFileBuffer );

	return returns;
*/
	return TRUE;
}

BOOLEAN D6ED2B9CD102472FA9C3586A7F21613D( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE* pwszFileName )
{

	const struct firmware *fw;
	int ret;
	BYTE* pFileBuffer = NULL;
	ULONG             nFileSize = 0;
	BOOLEAN			  returns = FALSE;
	struct timeval ts;
	ULONGLONG start_times = 0;

	ULONGLONG stop_times = 0;

	ret = request_firmware(&fw, pwszFileName, &(pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ 0 ]->dev));

	if (ret) {

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"[%02d] D6ED2B9CD102472FA9C3586A7F21613D() Upload failed. (file not found?)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

		return false;

	} else {

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] D6ED2B9CD102472FA9C3586A7F21613D() firmware read %d bytes\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, fw->size);

		if(fw->size > 0)
		{
			nFileSize = fw->size;
			
			pFileBuffer = wrapper_vmalloc( fw->size + 4);//?? +4 ??

			if(pFileBuffer)
			{
				memset( pFileBuffer, 0x00, fw->size + 4);

				memcpy(pFileBuffer, fw->data, fw->size);
			}
			else
			{
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"[%d]D6ED2B9CD102472FA9C3586A7F21613D() no buffer\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

				release_firmware(fw);

				return false;
			}

		}
	}


	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

	command[ 1 ] = 0x0000000B; // MZ0380_CMD_BEGIN_FIRMWARE_DOWNLOAD

	command[ 2 ] = nFileSize;

	if( E7E90BC718B74429BB9234213955A126( pDevice, command, 3 ) == TRUE ) {

		{	
			do_gettimeofday( &ts );

			start_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);

			//WRITE_REGISTER_BUFFER_ULONG( (ULONG *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00000060), (PULONG)(pFileBuffer), (nFileSize + 3) / (4) );
			memcpy( (UINT *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00000060), (UINT *)(pFileBuffer), (nFileSize + 3) );

			do_gettimeofday( &ts );

			stop_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);

			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%d] TOTAL DOWNLOAD TIMES (BUFFER) = %08d (%d BYTES)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, (ULONG)(stop_times - start_times), nFileSize);
		}
		DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		command[ 1 ] = 0x0000000C; // MZ0380_CMD_END_FIRMWARE_DOWNLOAD

		command[ 2 ] = 0x00000001;

		if( B601B66F1570418A9F5091D6133C37B8( pDevice, command, 3, TRUE, 600000000 ) == TRUE ) {

			F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000000 );

			if( A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 2) ) == 0 ) {
				
				returns = TRUE;
			}
			else {

				returns = FALSE;
			}
		}
		else {

			returns = FALSE;
		}
	}
	else {

		returns = FALSE;
	}
	do_gettimeofday( &ts );

	stop_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);

	if( returns ) {

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] TOTAL DOWNLOAD TIMES = %08d (%d BYTES) (SUCCESS)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, (ULONG)(stop_times - start_times), nFileSize);

	}
	else {

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] TOTAL DOWNLOAD TIMES = %08d (%d BYTES) (FAIL)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, (ULONG)(stop_times - start_times), nFileSize);
	}
	
	if(pFileBuffer)
	{
		vfree( pFileBuffer );
	}	
	release_firmware(fw);

	return returns;


/*
	WCHAR			  wszPathName[ 255 ];

	OBJECT_ATTRIBUTES oObjectAttributes;

	UNICODE_STRING    oFileName;

	IO_STATUS_BLOCK   oIoStatus;

	HANDLE            hFileHandle = NULL;

	BYTE *            pFileBuffer = NULL;

	ULONG             nFileSize = 0;

	NTSTATUS          status = STATUS_SUCCESS;

	BYTE			  parms[ 64 ];

	BOOLEAN			  returns = TRUE;

	swprintf( wszPathName, L"%s%s", pDevice->m_pCustomDeviceInfoDirectoryProperty, pwszFileName );

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "D6ED2B9CD102472FA9C3586A7F21613D( \"%ws\" )\n", wszPathName);

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

		if( oFileStandardInfomation.Directory == TRUE ) {

			ZwClose( hFileHandle );

			return FALSE;
		}
		nFileSize = (ULONG)(oFileStandardInfomation.EndOfFile.QuadPart);

		pFileBuffer = (BYTE *)(ExAllocatePool( NonPagedPool, nFileSize + 4 ));

		if( pFileBuffer ) {

			RtlZeroMemory( pFileBuffer, nFileSize + 4 );

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
	ULONGLONG start_times = KeQueryInterruptTime();

	ULONGLONG stop_times = 0;

	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

	command[ 1 ] = 0x0000000B; // MZ0380_CMD_BEGIN_FIRMWARE_DOWNLOAD

	command[ 2 ] = nFileSize;

	if( MZ0380_SendVendorCommand( pDevice, command, 3 ) == TRUE ) {

		{	ULONGLONG start_times = KeQueryInterruptTime();

			ULONGLONG stop_times = 0;

			WRITE_REGISTER_BUFFER_ULONG( (ULONG *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00000060), (PULONG)(pFileBuffer), (nFileSize + 3) / (4) );

			stop_times = KeQueryInterruptTime();

			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "TOTAL DOWNLOAD TIMES (BUFFER) = %08d (%d BYTES)\n", (ULONG)(stop_times - start_times), nFileSize);
		}
		DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		command[ 1 ] = 0x0000000C; // MZ0380_CMD_END_FIRMWARE_DOWNLOAD

		command[ 2 ] = 0x00000001;

		if( MZ0380_SendVendorCommand( pDevice, command, 3, TRUE, 600000000 ) == TRUE ) {

			F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000000 );

			if( A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 2) ) == 0 ) {
				
				returns = TRUE;
			}
			else {

				returns = FALSE;
			}
		}
		else {

			returns = FALSE;
		}
	}
	else {

		returns = FALSE;
	}
	stop_times = KeQueryInterruptTime();

	if( returns ) {

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "TOTAL DOWNLOAD TIMES = %08d (%d BYTES) (SUCCESS)\n", (ULONG)(stop_times - start_times), nFileSize);
	}
	else {

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "TOTAL DOWNLOAD TIMES = %08d (%d BYTES) (FAIL)\n", (ULONG)(stop_times - start_times), nFileSize);
	}

	// 3.0 FREE WORKING BUFFER
	//
	FREE_MEMORY( pFileBuffer );

	return returns;
*/
}

BOOL MZ0380_ITE6603_HwInitialize( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] MZ0380_ITE6603_HwInitialize()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	D8735A9140EC43B888E108661E19175A( pDevice, 1, 0 ); // HPD
	
	D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

	D8735A9140EC43B888E108661E19175A( pDevice, 9, 0 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

	D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

	p_sys_cfg->n_input_video_resolution_cx = 0;

	p_sys_cfg->n_input_video_resolution_cy = 0;

	p_sys_cfg->n_input_video_resolution_fps = 0;

	p_sys_cfg->n_input_video_resolution_fps_m = 0;

	p_sys_cfg->n_input_video_resolution_interleaved = 0;

	p_sys_cfg->b_input_video_signal_changed = FALSE;

	p_sys_cfg->n_input_audio_sampling_frequency = 0;

	p_sys_cfg->n_input_video_resolution_color_colorimetry = 0;

	p_sys_cfg->n_input_video_resolution_color_range = 0;

	p_sys_cfg->b_input_video_resolution_external_sync = FALSE;

	InitCAT6023(pDevice);	

 	return TRUE;
}
BOOL CD97BE2AFB28486185CDB258932E710F( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CD97BE2AFB28486185CDB258932E710F()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

	D8735A9140EC43B888E108661E19175A( pDevice, 9, 0 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

	D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

	if( pDevice->iManufacturer == 0x55 ||
	
		pDevice->iManufacturer == 0xC5 ) { // SC5C0N1.MC.FULL	

		D8735A9140EC43B888E108661E19175A( pDevice, 2, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );
	}
	else {

		D8735A9140EC43B888E108661E19175A( pDevice, 8, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );
	}

	C38D9336DFA64B4C8C0AD9DDE94EE013( pDevice, 0x0009, (11 << 10) | (4 << 5) | (11 << 0) );

	C38D9336DFA64B4C8C0AD9DDE94EE013( pDevice, 0x0000, (1 << 6) | (1 << 7) );

	C38D9336DFA64B4C8C0AD9DDE94EE013( pDevice, 0x0026, 0x0006 ); // EXTERNAL HVSYNC INVERT

	if( pDevice->m_nCustomAnalogVideoVbiLinesEnableProperty == TRUE ) {

		C38D9336DFA64B4C8C0AD9DDE94EE013( pDevice, 0x000A, 0x0000 ); // TURN  ON VANC
	}
	else {

		C38D9336DFA64B4C8C0AD9DDE94EE013( pDevice, 0x000A, 0x0004 ); // TURN OFF VANC
	}

	USHORT R0200 = D792350EAF024850BDEDF910AE232FD8( pDevice, 0x0200 ) & 0xF0FF; R0200 |= 0x0A00;

	C38D9336DFA64B4C8C0AD9DDE94EE013( pDevice, 0x0200, R0200 );

	USHORT R0408 = D792350EAF024850BDEDF910AE232FD8( pDevice, 0x0408 ) & 0x00FF; R0408 |= 0xAA00;
	
	C38D9336DFA64B4C8C0AD9DDE94EE013( pDevice, 0x0408, R0408 );

	if( pDevice->iManufacturer == 0xC4 ||  // SC5C0N1.MC.SDI
		
		pDevice->iManufacturer == 0x55 ||  // SC550N1.MC.FULL
	
		pDevice->iManufacturer == 0xC5 ) { // SC5C0N1.MC.FULL

		C38D9336DFA64B4C8C0AD9DDE94EE013( pDevice, 0x006D, 0x0008 );
	}
	p_sys_cfg->n_input_video_resolution_cx = 0;

	p_sys_cfg->n_input_video_resolution_cy = 0;

	p_sys_cfg->n_input_video_resolution_fps = 0;

	p_sys_cfg->n_input_video_resolution_fps_m = 0;

	p_sys_cfg->n_input_video_resolution_interleaved = 0;

	p_sys_cfg->b_input_video_signal_changed = FALSE;

	p_sys_cfg->n_input_audio_sampling_frequency = 0;

	p_sys_cfg->n_input_video_resolution_color_colorimetry = 0;

	p_sys_cfg->n_input_video_resolution_color_range = 0;

	p_sys_cfg->b_input_video_resolution_external_sync = FALSE;

	return TRUE;
}

BOOL F3169EC0056F4C22A66FA8C4A782FAAF( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

	D8735A9140EC43B888E108661E19175A( pDevice, 9, 0 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

	D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

	BYTE page = 0;
	for( page = 0 ; page < 2 ; page++ ) {

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x40, page );

		// STANDARD DETECT
		//
		BYTE i = 0;
		{	for( i = 0 ; i < 4 ; i++ ) {
		
				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x08 + 0x10 * i, 0x14 );

				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x0E + 0x10 * i, 0x07 );

				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x0F + 0x10 * i, 0x7F );
			}
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x97, 0x85 | 0x10 );
		}
//		// STANDARD
//		//
//		{	for( BYTE i = 0 ; i < 4 ; i++ ) {
//		
//				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x08 + 0x10 * i, 0x14 );
//
//				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x0E + 0x10 * i, 0x00 );
//
//				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x0F + 0x10 * i, 0x01 );
//			}
//			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x97, 0x85 | 0x10 );
//		}
//		// STANDARD
//		//
//		{	for( BYTE i = 0 ; i < 4 ; i++ ) {
//		
//				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x08 + 0x10 * i, 0x18 );
//
//				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x0E + 0x10 * i, 0x01 );
//
//				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x0F + 0x10 * i, 0x02 );
//			}
//			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x97, 0xC5 | 0x10 );
//		}
		for( i = 0 ; i < 4 ; i++ ) {
			/*
			ULONG j = page * 2 + i;
			
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * i) + 0x01), ((BYTE)(pDevice->m_nAnalogVideoProcAmpBrightnessProperty[ j ] & 0xFF) - 128) | 0x00 );

			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * i) + 0x02), ((BYTE)(pDevice->m_nAnalogVideoProcAmpContrastProperty[ j ]   & 0xFF) -  28) | 0x00 );

			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * i) + 0x06), ((BYTE)(pDevice->m_nAnalogVideoProcAmpHueProperty[ j ]        & 0xFF) - 128) | 0x00 );

			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * i) + 0x04), ((BYTE)(pDevice->m_nAnalogVideoProcAmpSaturationProperty[ j ] & 0xFF) -   0) | 0x00 );

			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * i) + 0x05), ((BYTE)(pDevice->m_nAnalogVideoProcAmpSaturationProperty[ j ] & 0xFF) -   0) | 0x00 );

			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * i) + 0x03), ((BYTE)(pDevice->m_nAnalogVideoProcAmpSharpnessProperty[ j ]  & 0xFF) >>  4) | 0x20 );
			*/
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * i) + 0x01), ((BYTE)(FADD02C9C13B14f83989880EFACB8D8DC[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) - 128) | 0x00 );

			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * i) + 0x02), ((BYTE)(F3A66BD0F0BCB4afcAD006E378E671B9A[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]   & 0xFF) -  28) | 0x00 );

			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * i) + 0x06), ((BYTE)(F42BAA55A84E847faA4D0C0565699845E[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]        & 0xFF) - 128) | 0x00 );

			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * i) + 0x04), ((BYTE)(F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) -   0) | 0x00 );

			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * i) + 0x05), ((BYTE)(F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) -   0) | 0x00 );

			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * i) + 0x03), ((BYTE)(F1D56E1ED762E4b99BB2BD370DFE317D1[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]  & 0xFF) >>  4) | 0x20 );

		}
		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xAF, 0x00 ); // VSHP

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xB0, 0x00 ); // VSHP
	}
	DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x40, 0x00 );

	DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x8A, 0xD8 ); // 消除水波紋 (WHITE PEAK) (原設定 0x00 會造成白色不為純白，為灰色)

	DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x96, 0xE6 ); // ENABLE BLUE COLOR

	BYTE RFB = E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x50, 0xFB );

	RFB = (RFB & (~0x30)) | 0x2F;

	DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xFB, RFB );

	BYTE RFC = E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x50, 0xFC );

	RFC = (RFC & (~0x0F)) | 0x0F;

	DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xFC, RFC );

	DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x40, 0x00 );

	DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xFB, 0x2F ); // VIDEO AND AUDIO DETECTION MODE, ENABLE IRQ

	DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x9E, 0x52 ); // ENABLE CHANNEL ID

	DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xCD, 0xE4 );

	DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x5B, 0x00 ); // CLOCK DRIVE [2016.09.23] 修正 SC3C0N16 生產不良問題 0x03 -> 0x00 

	BOOL is_wd1_mode = TRUE;

	if( (pDevice->iManufacturer & 0x0F) == 0x0C ) {

		is_wd1_mode = FALSE;
	}
	else {
		if( pDevice->m_nCustomAnalogVideo720OutputProperty == 1 ) { // 720 OUTPUT

			is_wd1_mode = FALSE;
		}
		else {

			is_wd1_mode = TRUE;
		}
	}
	if( is_wd1_mode ) {

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x40, 0x00 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x6F, 0xF0 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x40, 0x00 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xE7, 0xAA );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xE8, 0x10 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xE9, 0x32 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xEA, 0x54 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xEB, 0x76 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xCC, 0xFF );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xCD, 0xFF );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xF9, 0x03 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xFA, 0x4A );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xFB, 0x2F );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x9F, 0x33 );
	}
	else {

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x40, 0x00 ) ;

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x6F, 0x00 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x40, 0x00 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xE7, 0xAA );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xE8, 0x10 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xE9, 0x32 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xEA, 0x54 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xEB, 0x76 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xCC, 0x00 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xCD, 0x00 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xF9, 0x00 );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xFA, 0x4A );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0xFB, 0x2F );

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x9F, 0x00 );
	}

	BYTE i = 0;
	for( i = 0 ; i < 4 ; i++ ) {

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x00, 0x00 ); // SWITCH TO PAGE@0

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x01, 0x01 ); //

		if( (pDevice->iManufacturer & 0x0F) == 0x0C ) {
			
			F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x12, 0x83 ); // NADC        =  3.072 MHZ

			F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x13, 0x82 ); // MADC /   2  =   2048 KHZ

			F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x14, 0x80 ); // AOSR / 128  =     16 KHZ

			F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x1E, 0x84 ); // ADC_CLK     =  3.072 MHZ = 16K X STEREO X 16BIT
		}
		else {

			F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x12, 0x81 ); // NADC        = 12.288 MHZ
	
			F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x13, 0x82 ); // MADC /   2  =   6144 KHZ
	
			F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x14, 0x80 ); // AOSR / 128  =     48 KHZ
	
			F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x1E, 0x88 ); // ADC_CLK     =  1.536 MHZ = 48K X STEREO X 16BIT
		}
		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x1B, 0x0C ); // [4:5] 0: 16 BITS, 1: 20 BITS, 2: 24BITS, 3: 36BITS

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x00, 0x00 );

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x00, 0x01 ); // SWITCH TO PAGE@1

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x00, 0x01 );

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x33, 0x00 ); // MICBIAS1, MICBIAS2 IS POWERED DOWN

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x34, 0xFC ); // LEFT ADC INPUT SELECTION FOR LEFT PGA, LCH_SEL1; USED FOR THE IN1L(P) PIN, WHICH IS SINGLE-ENDED
		
		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x37, 0xFC ); // RIGHT ADC INPUT SELECTION FOR RIGHT PGA, RCH_SEL1; USED FOR THE IN1R(M) PIN, WHICH IS SINGLE-ENDED

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x3B, 0x00 );

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x3C, 0x00 );

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x00, 0x00 ); // SWITCH TO PAGE@0

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x3D, 0x02 );

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x51, 0x00 );

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x00, 0x00 ); // SWITCH TO PAGE@0

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x51, 0xC2 );

		F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x52, 0x00 );

		if( (pDevice->iManufacturer & 0x0F) == 0x0C ) {

			if( i == 0 ||
			
				i == 2 ) {
			
				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x26, 0x08 ); // LEFT

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x1B, 0x0D );
			}
			else {
			
				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x26, 0x04 ); // RIGHT

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x1B, 0x01 );
			}
		}
	}
	return TRUE;
}

BOOL FF380D83230F420BA1D5EF3C8F5D7EE4( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
	if( (pDevice->iProduct & 0x0F) == 0x02 ||  // 960H & D1
	
	 	(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1

		;
	}
	else if( (pDevice->iProduct == 0x1C && pDevice->iManufacturer == 0xFA) ||  // ELGATO BOARD
			 (pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x03) ||  // ELGATO BOARD
			 (pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x05) ) { // ELGATO BOARD

		;
	}
	else if( pDevice->iManufacturer == 0x5E ||  // ELGATO BOARD
	
			 pDevice->iManufacturer == 0xCE ) { // ELGATO BOARD
		;
	}
	else if( pDevice->iManufacturer == 0x5F ||  // SC550N1 M2 HDMI
	
			 pDevice->iManufacturer == 0xCF ) { // SC5C0N1 M2 HDMI
		;
	}
	else if( (pDevice->iManufacturer == 0x50) ||  // HD	

			 (pDevice->iManufacturer == 0xC0) ||  // HD
		
			 (pDevice->iManufacturer == 0x53) ||  // HD	

			 (pDevice->iManufacturer == 0xC3) ||  // HD
		
			 (pDevice->iManufacturer == 0x5D) ||  // HD	

			 (pDevice->iManufacturer == 0xCD) ||  // HD

			 (pDevice->iManufacturer == 0xC6) ) { // AEROCOM.SDI (CH03)

		if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||  // COMPOSITE

			pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) { // SVIDEO

			D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

			D8735A9140EC43B888E108661E19175A( pDevice, 9, 0 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

			D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

			D8735A9140EC43B888E108661E19175A( pDevice, 8, 0 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x06, 0x00 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x03, 0xA2 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x05, 0x01 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x08, 0x14 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x09, 0xF2 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0A, 0x0B );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0B, 0xD0 );
		//	DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x19, 0x57 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x19, 0xDE );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1A, 0x0F );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1B, 0x00 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x28, 0x0E );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x29, 0x03 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x2D, 0x07 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x2F, 0x06 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x4C, 0x0D );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x55, 0x00 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x6B, 0x26 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x6C, 0x36 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x6D, 0xF0 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x6E, 0x28 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x06, 0x80 );

			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x6F, 0x98 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x64, 0x55 );
			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x06, 0x80 );

			MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

			p_sys_cfg->n_input_video_resolution_cx = 0;

			p_sys_cfg->n_input_video_resolution_cy = 0;

			p_sys_cfg->n_input_video_resolution_fps = 0;

			p_sys_cfg->n_input_video_resolution_fps_m = 0;

			p_sys_cfg->n_input_video_resolution_interleaved = 0;

			p_sys_cfg->b_input_video_signal_changed = FALSE;

			p_sys_cfg->n_input_audio_sampling_frequency = 0;	

			p_sys_cfg->n_input_video_resolution_color_colorimetry = 1;

			p_sys_cfg->n_input_video_resolution_color_range = 1;

			p_sys_cfg->b_input_video_resolution_external_sync = FALSE;
		}
	}
 	return TRUE;
}

BOOL D681E06D64D342E8A7C86B12E08C9B19( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
	D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

	D8735A9140EC43B888E108661E19175A( pDevice, 9, 0 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 ); // ACTIVE LOW

	D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );
	
	#ifdef AME_MZ0380
	DA74E1188CA14BBDBC150CE97DAB3620( pDevice );
	#endif

	ULONG i = 0;
	for( i = 0 ; i < 4 ; i++ ) {
		
		if( g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ] ) {
		
			MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_pCustomSystemConfigProperty);//change pDevice here

			if( p_sys_cfg ) {

				p_sys_cfg->n_input_video_resolution_cx = 0;

				p_sys_cfg->n_input_video_resolution_cy = 0;

				p_sys_cfg->n_input_video_resolution_fps = 0;

				p_sys_cfg->n_input_video_resolution_fps_m = 0;

				p_sys_cfg->n_input_video_resolution_interleaved = 0;

				p_sys_cfg->b_input_video_signal_changed = FALSE;

				p_sys_cfg->n_input_audio_sampling_frequency = 0;	

				p_sys_cfg->n_input_video_resolution_color_colorimetry = 1;

				p_sys_cfg->n_input_video_resolution_color_range = 1;

				p_sys_cfg->b_input_video_resolution_external_sync = FALSE;
			}
		}
	}
	return TRUE;
}

BOOL MZ0380_NVP6124_HwInitialize( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
	D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

	D8735A9140EC43B888E108661E19175A( pDevice, 9, 0 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 ); // ACTIVE LOW

	D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );
		
	ULONG CHIPID = check_id( pDevice );

	ULONG REVID = check_rev( pDevice );

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] NVP6124_HwInitialize( %08X, %08X )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, CHIPID, REVID);

	nvp6124_common_init( pDevice );

	BYTE ch = 0;
	
	for( ch = 0 ; ch < 4 ; ch++ ) {

		// 1080P30
		nvp6124_set_chnmode( pDevice, ch, NTSC, NVP6124_VI_1080P_2530 );
	}

	{	nvp6124_set_portmode( pDevice, 0, 0, NVP6124_OUTMODE_1MUX_FHD, 0 );

		nvp6124_set_portmode( pDevice, 0, 1, NVP6124_OUTMODE_1MUX_FHD, 1 );

		nvp6124_set_portmode( pDevice, 0, 2, NVP6124_OUTMODE_1MUX_FHD, 2 );

		nvp6124_set_portmode( pDevice, 0, 3, NVP6124_OUTMODE_1MUX_FHD, 3 );
	}
	{	audio_init( pDevice, 1, 0, 16, 0, 0 );
	}
	ULONG i = 0;
	for( i = 0 ; i < 4 ; i++ ) {
		
		if( g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ] )
		{
			MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_pCustomSystemConfigProperty);//change pDevice here

			if( p_sys_cfg ) {

				p_sys_cfg->n_input_video_resolution_cx = 0;

				p_sys_cfg->n_input_video_resolution_cy = 0;

				p_sys_cfg->n_input_video_resolution_fps = 0;

				p_sys_cfg->n_input_video_resolution_fps_m = 0;

				p_sys_cfg->n_input_video_resolution_interleaved = 0;

				p_sys_cfg->b_input_video_signal_changed = FALSE;

				p_sys_cfg->n_input_audio_sampling_frequency = 0;	

				p_sys_cfg->n_input_video_resolution_color_colorimetry = 1;

				p_sys_cfg->n_input_video_resolution_color_range = 1;

				p_sys_cfg->b_input_video_resolution_external_sync = FALSE;
			}
		}
	}
	return TRUE;
}

NTSTATUS ADF0B0E919E0488A9DECD29D67A7F9A8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nStandard, BOOL THREAD )
{
	if( ((pDevice->iProduct & 0x0F) == 0x02 && (pDevice->iManufacturer & 0x0F) >= 0x0A ) ||	// 960H
	
		((pDevice->iProduct & 0x0F) == 0x03 && (pDevice->iManufacturer & 0x0F) >= 0x0A ) ) { // 960H

		if( THREAD == FALSE ) { MZ0380_CLOSE_THREAD(); }

		MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		ULONG counts = 2;

		if( (pDevice->iManufacturer & 0x0F) == 0x0B	||
		
		 	(pDevice->iManufacturer & 0x0F) == 0x0C ) {

			counts = 1;
		}
		else {

			counts = 2;
		}
		BYTE page = 0;
		for( page = 0 ; page < counts ; page++ ) {

			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x40, page );

			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_60HZ ) { // STANDARD

				BYTE i = 0;
				for( i = 0 ; i < 4 ; i++ ) {

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x0E + 0x10 * i, 0x00 );

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x0F + 0x10 * i, 0x01 );

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x08 + 0x10 * i, 0x14 );

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x0A + 0x10 * i, 0x09 ); // HORIZONTAL F6B9E557A4BA24ffd926B820B836289C8
				}
				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x97, 0x85 | 0x10 );

				if( (pDevice->iManufacturer & 0x0F) == 0x0A ||  // 960H
					
					(pDevice->iManufacturer & 0x0F) == 0x0B ) { // 960H

					if( pDevice->m_nCustomAnalogVideo720OutputProperty == 1 ) { // 720 OUTPUT

						p_sys_cfg->n_input_video_resolution_cx = 720;
					}
					else {

						p_sys_cfg->n_input_video_resolution_cx = 960;
					}
				}
				else if( (pDevice->iManufacturer & 0x0F) == 0x0C ) { // 960H -> D1

					p_sys_cfg->n_input_video_resolution_cx = 720;
				}
				else { //

					p_sys_cfg->n_input_video_resolution_cx = 720;
				}
				p_sys_cfg->n_input_video_resolution_cy = 240;

				p_sys_cfg->n_input_video_resolution_fps = 60;

				p_sys_cfg->n_input_video_resolution_fps_m = 1;

				p_sys_cfg->n_input_video_resolution_interleaved = 1;

				p_sys_cfg->b_input_video_signal_changed = TRUE;

				p_sys_cfg->n_input_audio_sampling_frequency = 48000;

				p_sys_cfg->n_input_video_resolution_color_colorimetry = 1;

				p_sys_cfg->n_input_video_resolution_color_range = 1;

				p_sys_cfg->b_input_video_resolution_external_sync = FALSE;

				pDevice->m_nCustomAnalogVideoResolutionProperty = (p_sys_cfg->n_input_video_resolution_cx << 16) | 

																  (p_sys_cfg->n_input_video_resolution_cy <<  0);

				pDevice->m_nCustomAnalogVideoFrameRateProperty = (p_sys_cfg->n_input_video_resolution_fps);

				pDevice->m_nCustomAnalogVideoInterleavedProperty = (p_sys_cfg->n_input_video_resolution_interleaved);

				pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 48000;
			}
			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_50HZ ) { // STANDARD

				BYTE i = 0;
				for( i = 0 ; i < 4 ; i++ ) {

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x0E + 0x10 * i, 0x01 );

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x0F + 0x10 * i, 0x02 );

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x08 + 0x10 * i, 0x18 );

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x0A + 0x10 * i, 0x04 ); // HORIZONTAL F6B9E557A4BA24ffd926B820B836289C8
				}
				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x97, 0xC5 | 0x10 );

				if( (pDevice->iManufacturer & 0x0F) == 0x0A ||  // 960H
					
					(pDevice->iManufacturer & 0x0F) == 0x0B ) { // 960H

					if( pDevice->m_nCustomAnalogVideo720OutputProperty == 1 ) { // 720 OUTPUT

						p_sys_cfg->n_input_video_resolution_cx = 720;
					}
					else {

						p_sys_cfg->n_input_video_resolution_cx = 960;
					}
				}
				else if( (pDevice->iManufacturer & 0x0F) == 0x0C ) { // 960H -> D1

					p_sys_cfg->n_input_video_resolution_cx = 720;
				}
				else { //

					p_sys_cfg->n_input_video_resolution_cx = 720;
				}
				p_sys_cfg->n_input_video_resolution_cy = 288;

				p_sys_cfg->n_input_video_resolution_fps = 50;

				p_sys_cfg->n_input_video_resolution_fps_m = 0;

				p_sys_cfg->n_input_video_resolution_interleaved = 1;

				p_sys_cfg->b_input_video_signal_changed = TRUE;

				p_sys_cfg->n_input_audio_sampling_frequency = 48000;

				p_sys_cfg->n_input_video_resolution_color_colorimetry = 1;

				p_sys_cfg->n_input_video_resolution_color_range = 1;

				p_sys_cfg->b_input_video_resolution_external_sync = FALSE;

				pDevice->m_nCustomAnalogVideoResolutionProperty = (p_sys_cfg->n_input_video_resolution_cx << 16) | 

																  (p_sys_cfg->n_input_video_resolution_cy <<  0);

				pDevice->m_nCustomAnalogVideoFrameRateProperty = (p_sys_cfg->n_input_video_resolution_fps);

				pDevice->m_nCustomAnalogVideoInterleavedProperty = (p_sys_cfg->n_input_video_resolution_interleaved);

				pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 48000;
			}
		}
		if( THREAD == FALSE ) { MZ0380_START_THREAD(); }
	}
	else if( (pDevice->iProduct & 0x0F) == 0x02 ||  //
		
			 (pDevice->iProduct & 0x0F) == 0x03 ) { //

		;
	}
	else if( (pDevice->iProduct == 0x1C && pDevice->iManufacturer == 0xFA) ||  // ELGATO BOARD
			 (pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x03) ||  // ELGATO BOARD
			 (pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x05) ) { // ELGATO BOARD

		;
	}
	else if( pDevice->iManufacturer == 0x5E ||  // ELGATO BOARD
	
			 pDevice->iManufacturer == 0xCE ) { // ELGATO BOARD
		;
	}
	else if( pDevice->iManufacturer == 0x5F ||  // SC550N1 M2 HDMI
			
			 pDevice->iManufacturer == 0xCF ) { // SC5C0N1 M2 HDMI

		;
	}
	else if( pDevice->iManufacturer == 0x51 ||  // AHD
	
			 pDevice->iManufacturer == 0xC1 ||  // AHD
	
			 pDevice->iManufacturer == 0x52 ||  // AHD
	
			 pDevice->iManufacturer == 0xC2 ) { // AHD
		;
	}
	else { // HD
		
		if( pDevice->iManufacturer == 0x50 ||  // HD

			pDevice->iManufacturer == 0xC0 ||  // HD

			pDevice->iManufacturer == 0x53 ||  // HD

			pDevice->iManufacturer == 0xC3 ||  // HD

			pDevice->iManufacturer == 0x5D ||  // HD

			pDevice->iManufacturer == 0xCD ||  // HD

			pDevice->iManufacturer == 0xC6 ) { // AEROCOM.SDI (CH03)

			if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||  // COMPOSITE
	
				pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) { // SVIDEO
	
				if( THREAD == FALSE ) { MZ0380_CLOSE_THREAD(); }
	
				MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
	
				BYTE R0C = (BYTE)(E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x88, 0x0C )) & 0xEF;
	
				switch( pDevice->FD314ADAD9404496b842EBFC396E875CB ) {
				
				case V4L2_STD_NTSC_M:      DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x00 );  break;
				case V4L2_STD_NTSC_M_JP:   DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x00 );  break;
				case V4L2_STD_NTSC_443:    DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x03 );  break;
				case V4L2_STD_PAL_60:      DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x07 );  break;
				case V4L2_STD_PAL_M:       DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x04 );  break;
				case V4L2_STD_PAL_B:       DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x01 );  break;
				case V4L2_STD_PAL_D:       DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x01 );  break;
				case V4L2_STD_PAL_G:       DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x01 );  break;
				case V4L2_STD_PAL_H:       DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x01 );  break;
				case V4L2_STD_PAL_I:       DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x01 );  break;
				case V4L2_STD_PAL_N:       DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x05 );  break;
				case V4L2_STD_PAL_Nc: 	   DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
				case V4L2_STD_SECAM_B:     DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
				case V4L2_STD_SECAM_G:     DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
				case V4L2_STD_SECAM_H:     DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
				case V4L2_STD_SECAM_D:     DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
				case V4L2_STD_SECAM_K:     DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
				case V4L2_STD_SECAM_K1:    DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
				case V4L2_STD_SECAM_L:     DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
				case V4L2_STD_SECAM_LC:    DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x1C, 0x02 );  break;
				}
				switch( pDevice->FD314ADAD9404496b842EBFC396E875CB ) {
				
				case V4L2_STD_NTSC_M:      DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x10 );  break;
				case V4L2_STD_NTSC_M_JP:   DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_NTSC_443:    DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x10 );  break;
				case V4L2_STD_PAL_60:      DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_PAL_M:       DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x10 );  break;
				case V4L2_STD_PAL_B:       DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_PAL_D:       DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_PAL_G:       DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_PAL_H:       DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_PAL_I:       DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_PAL_N:       DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x10 );  break;
				case V4L2_STD_PAL_Nc:	   DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_SECAM_B:     DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_SECAM_G:     DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_SECAM_H:     DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_SECAM_D:     DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_SECAM_K:     DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_SECAM_K1:    DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_SECAM_L:     DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				case V4L2_STD_SECAM_LC:    DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0C, R0C | 0x00 );  break;
				}
				if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_60HZ ) {
	
					BYTE R07 = (BYTE)(E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x88, 0x07 )) & 0x0F;
					
					BYTE R55 = (BYTE)(E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x88, 0x55 )) & 0xEF;
	
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x07, 0x00 | R07 );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x08, 0x14       );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x09, 0xF4       );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0A, 0x0B       );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0B, 0xD0       );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x55, 0x10 | R55 );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0D, 0x00       );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0E, 0x11       );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0F, 0x00       );
	
					p_sys_cfg->n_input_video_resolution_cx = 720;
	
					p_sys_cfg->n_input_video_resolution_cy = 240;
	
					p_sys_cfg->n_input_video_resolution_fps = 60;
	
					p_sys_cfg->n_input_video_resolution_fps_m = 1;
	
					p_sys_cfg->n_input_video_resolution_interleaved = 1;
	
					p_sys_cfg->b_input_video_signal_changed = TRUE;
	
					p_sys_cfg->n_input_audio_sampling_frequency = 48000;
	
					p_sys_cfg->n_input_video_resolution_color_colorimetry = 1;

					p_sys_cfg->n_input_video_resolution_color_range = 1;

					p_sys_cfg->b_input_video_resolution_external_sync = FALSE;

					pDevice->m_nCustomAnalogVideoResolutionProperty = (p_sys_cfg->n_input_video_resolution_cx << 16) | 
	
																	  (p_sys_cfg->n_input_video_resolution_cy <<  0);
	
					pDevice->m_nCustomAnalogVideoFrameRateProperty = (p_sys_cfg->n_input_video_resolution_fps);
	
					pDevice->m_nCustomAnalogVideoInterleavedProperty = (p_sys_cfg->n_input_video_resolution_interleaved);
	
					pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 48000;
				}
				if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_50HZ ) {
	
					BYTE R07 = (BYTE)(E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x88, 0x07 )) & 0x0F;
					
					BYTE R55 = (BYTE)(E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x88, 0x55 )) & 0xEF;
	
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x07, 0x10 | R07 );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x08, 0x19 +   0 );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x09, 0x20       );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0A, 0x0A       );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0B, 0xD0       );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x55, 0x00 | R55 );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0D, 0x00       );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0E, 0x11       );
					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x0F, 0x00       );	
	
					p_sys_cfg->n_input_video_resolution_cx = 720;
	
					p_sys_cfg->n_input_video_resolution_cy = 288;
	
					p_sys_cfg->n_input_video_resolution_fps = 50;
	
					p_sys_cfg->n_input_video_resolution_fps_m = 0;
	
					p_sys_cfg->n_input_video_resolution_interleaved = 1;
	
					p_sys_cfg->b_input_video_signal_changed = TRUE;
	
					p_sys_cfg->n_input_audio_sampling_frequency = 48000;
	
					p_sys_cfg->n_input_video_resolution_color_colorimetry = 1;

					p_sys_cfg->n_input_video_resolution_color_range = 1;

					p_sys_cfg->b_input_video_resolution_external_sync = FALSE;

					pDevice->m_nCustomAnalogVideoResolutionProperty = (p_sys_cfg->n_input_video_resolution_cx << 16) | 
	
																	  (p_sys_cfg->n_input_video_resolution_cy <<  0);
	
					pDevice->m_nCustomAnalogVideoFrameRateProperty = (p_sys_cfg->n_input_video_resolution_fps);
	
					pDevice->m_nCustomAnalogVideoInterleavedProperty = (p_sys_cfg->n_input_video_resolution_interleaved);
	
					pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 48000;
				}
				if( THREAD == FALSE ) { MZ0380_START_THREAD(); }
			}
		}
	}
	return STATUS_SUCCESS; 
}

NTSTATUS E8FFA7FBB87647EDA2877C2FAC2B2F1C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nVideoInput, ULONG nVideoOutput, ULONG nAudioInput, ULONG nAudioOutput, BOOL THREAD )
{
	if( THREAD == FALSE ) { MZ0380_CLOSE_THREAD(); }

	if( nVideoInput != -1 ) {

		if( (pDevice->iProduct & 0x0F) == 0x02 ||   // 960H & D1
			
			(pDevice->iProduct & 0x0F) == 0x03  ) { // 960H & D1

			if( (pDevice->iManufacturer & 0x0F) >= 0x0A ) {

				F3169EC0056F4C22A66FA8C4A782FAAF( pDevice );
			}
			else {

				;
			}
		}
		else if( pDevice->iManufacturer == 0x58 ||  // SC550N1 4K60P

				 pDevice->iManufacturer == 0x68 ||  // SC550N1 4K60P

				 pDevice->iManufacturer == 0xC8 ) { // SC5C0N1 4K60P

			;
		}
		else if( pDevice->iManufacturer == 0x59 ||  // SC550N1 4K60P

				 pDevice->iManufacturer == 0x69 ||  // SC550N1 4K60P

				 pDevice->iManufacturer == 0xC9 ) { // SC5C0N1 4K60P

			;
		}
		else if( pDevice->iManufacturer == 0x54 ||  // SC550N1 MC SDI
			
				 pDevice->iManufacturer == 0x5B ||  // SC550N4 SDI

				 pDevice->iManufacturer == 0xC4 ||  // SC5C0N1 MC SDI
			
				 pDevice->iManufacturer == 0xCB ) { // SC5C0N4 SDI

			CD97BE2AFB28486185CDB258932E710F( pDevice );

			if( pDevice->m_nCustomAnalogVideoVbiLinesEnableProperty == TRUE ) {

				DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, 0x9A, 0x00, 0x01 );// AERO.F5CB VANC
						
				DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, 0x9A, 0x01, (BYTE)pDevice->m_nCustomAnalogVideoVbiLinesProperty );
			}
			else {

				DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, 0x9A, 0x00, 0x00 );// AERO.F5CB BYPASS

				DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, 0x9A, 0x01, 0 );
			}
		}
		else if( pDevice->iManufacturer == 0x5A ||  // SC550N4 HDMI
			
				 pDevice->iManufacturer == 0xCA ) { // SC5C0N4 HDMI

			MZ0380_ITE6603_HwInitialize( pDevice );
		}
		else if( pDevice->iManufacturer == 0x5C ||  // SC550N1 MC HDV
			
				 pDevice->iManufacturer == 0x5F ||  // SC550N1 M2 HDMI
			
				 pDevice->iManufacturer == 0xCC ||  // SC5C0N1 MC HDV
			
				 pDevice->iManufacturer == 0xCF ) { // SC5C0N1 M2 HDMI

			MST3367_HwInitialize( pDevice );
		}
		else if( (pDevice->iProduct == 0x1C && pDevice->iManufacturer == 0xFA) ||  // ELGATO BOARD
				 (pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x03) ||  // ELGATO BOARD
				 (pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x05) ) { // ELGATO BOARD

			MST3367_HwInitialize( pDevice );

			//CIT6612_HwInitialize( pDevice );
		}
		else if( pDevice->iManufacturer == 0x5E ||  // ELGATO BOARD

				 pDevice->iManufacturer == 0xCE ) { // ELGATO BOARD

			MST3367_HwInitialize( pDevice );

			//CIT6612_HwInitialize( pDevice );
		}
		else if( pDevice->iManufacturer == 0x51 ||  // AHD
		
				 pDevice->iManufacturer == 0xC1 ||  // AHD
		
				 pDevice->iManufacturer == 0x52 ||  // AHD
		
				 pDevice->iManufacturer == 0xC2 ) { // AHD

			if( pDevice->iManufacturer == 0x51 ||
				
				pDevice->iManufacturer == 0xC1 ) {
			
				MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

				if( p_sys_cfg->b_is_techpoint_support ) {

					D681E06D64D342E8A7C86B12E08C9B19( pDevice );
				}
				else {

					MZ0380_NVP6124_HwInitialize( pDevice );
				}
			}
			else {
				
				D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

				D8735A9140EC43B888E108661E19175A( pDevice, 9, 0 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 ); // ACTIVE LOW

				D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );
			}
		}
		else if( pDevice->iManufacturer == 0xC6 ) {

			if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||

				pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) {

				FF380D83230F420BA1D5EF3C8F5D7EE4( pDevice );

				if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ) { // AERO.COMPOSITE

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x02, 0x0040 );	

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x06, 0x0042 );	
				}
				if( pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) { // AERO.SVIDEO

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x02, 0x0054 );	

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x06, 0x0040 );	
				}
				DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, 0x9A, 0x00, 0x04 );// AERO.CH05 COMPOSITE
			}
			else { // HD

				if( pDevice->m_nCustomAnalogVideoPinTopologyProperty >= 1 ) { // CH04

					D8735A9140EC43B888E108661E19175A( pDevice, 3, 0x01 );

					CD97BE2AFB28486185CDB258932E710F( pDevice );

					C38D9336DFA64B4C8C0AD9DDE94EE013( pDevice, 0x006C, 0x001C ); // SET F6B9E557A4BA24ffd926B820B836289C8 LINE FOR SDI AERO.CH04 ONLY (RANGE 0x19 ~ 0x1F)

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x03, 0xA7 ); // TRI-STATE

					if( pDevice->m_nCustomAnalogVideoVbiLinesEnableProperty == TRUE ) {

						DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, 0x9A, 0x00, 0x03 ); // CPLD CH04 VANC
						
						DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, 0x9A, 0x01, (BYTE)(pDevice->m_nCustomAnalogVideoVbiLinesProperty) );
					}
					else {

						DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, 0x9A, 0x00, 0x02 ); // CPLD CH04 BYPASS

						DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, 0x9A, 0x01, 0 );
					}
				}
				else { // CH03

					D8735A9140EC43B888E108661E19175A( pDevice, 3, 0x00 );

					CD97BE2AFB28486185CDB258932E710F( pDevice );

					C38D9336DFA64B4C8C0AD9DDE94EE013( pDevice, 0x006C, 0x001C ); // SET F6B9E557A4BA24ffd926B820B836289C8 LINE FOR SDI AERO.CH04 ONLY (RANGE 0x19 ~ 0x1F)

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x03, 0xA7 ); // TRI-STATE

					if( pDevice->m_nCustomAnalogVideoVbiLinesEnableProperty == TRUE ) {

						DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, 0x9A, 0x00, 0x01 ); // CPLD CH03 VANC

						DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, 0x9A, 0x01, (BYTE)(pDevice->m_nCustomAnalogVideoVbiLinesProperty) );
					}
					else {

						DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, 0x9A, 0x00, 0x00 ); // CPLD CH03 BYPASS

						DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, 0x9A, 0x01, 0 );
					}
				}
			}
		}
		else { // HD

			if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||

				pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) {

				FF380D83230F420BA1D5EF3C8F5D7EE4( pDevice );

				DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x00, 0xB3, 0xFF ); // TRI-STATE

				if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ) { // COMPOSITE

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x02, 0x0040 );	

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x06, 0x0042 );	
				}
				if( pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) { // SVIDEO

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x02, 0x0054 );	

					DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x06, 0x0040 );	
				}
			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) { // HD
				
				CD97BE2AFB28486185CDB258932E710F( pDevice );

				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x03, 0xA7 ); // TRI-STATE
			}
			else {

				MST3367_HwInitialize( pDevice );

				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x03, 0xA7 ); // TRI-STATE
			}
		}
		pDevice->m_nCustomAnalogVideoResolutionProperty = 0;

		pDevice->m_nCustomAnalogVideoFrameRateProperty = 0;

		pDevice->m_nCustomAnalogVideoInterleavedProperty = 0;

		pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 0;

		pDevice->m_nAnalogVideoDecoderStatusProperty = 0;

		pDevice->m_nAnalogCopyProtMacrovisionProperty = 0;	
		
		if( pDevice->iManufacturer == 0x50 ||
			
			pDevice->iManufacturer == 0xC0 ||
			
			pDevice->iManufacturer == 0x53 ||
			
			pDevice->iManufacturer == 0xC3 ||
			
			pDevice->iManufacturer == 0x5D ||
			
			pDevice->iManufacturer == 0xCD ||
			
			pDevice->iManufacturer == 0xC6 ) {

			if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||

				pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) {

				ADF0B0E919E0488A9DECD29D67A7F9A8( pDevice, NULL, TRUE );
			}
		}
	}
	if( nAudioInput != -1 ) {

		MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

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
		if( pDevice->iManufacturer == 0x51 ||  // AHD
	
			pDevice->iManufacturer == 0xC1 ||  // AHD
	
			pDevice->iManufacturer == 0x52 ||  // AHD
	
			pDevice->iManufacturer == 0xC2 ) { // AHD

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
		if( (pDevice->iProduct & 0x0F) == 0x02 ||
			
			(pDevice->iProduct & 0x0F) == 0x03 ) {

			;
		}
		else if( (pDevice->iProduct == 0x1C && pDevice->iManufacturer == 0xFA) ||  // ELGATO BOARD
				 (pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x03) ||  // ELGATO BOARD
				 (pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x05) ) { // ELGATO BOARD

			;
		}
		else if( pDevice->iManufacturer == 0x5E ||  // ELGATO BOARD
			
				 pDevice->iManufacturer == 0xCE ) { // ELGATO BOARD

			;
		}
		else if( pDevice->iManufacturer == 0x5F ||  // SC550N1 M2 HDMI
			
				 pDevice->iManufacturer == 0xCF ) { // SC5C0N1 M2 HDMI

			;
		}
		else if( pDevice->iManufacturer == 0x51 ||  // AHD
	
				 pDevice->iManufacturer == 0x52 ) { // AHD
				
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
			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[CH%02X.%02d CS53L21]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, I2S_SEL);
			
			ULONG i = 0;
			for( i = 0 ; i < sizeof(CS53L21_REG_TABLE) ; i += 2 ) { 
					
				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x94, CS53L21_REG_TABLE[ i ], CS53L21_REG_TABLE[ i + 1 ] ); 
			}				
			if( I2S_SEL >= 2 ) {

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x94, 0x07, 0x00 ); // PIN (STEREO)
			}
			else {

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x94, 0x07, 0x50 ); // PHONE JECK (MONO)
			}
		}
		else {

			if( I2S_SEL == 0 ) {

				if( pDevice->iManufacturer == 0x54 ||
					
					pDevice->iManufacturer == 0x5B ||
					
					pDevice->iManufacturer == 0xC4 ||
					
					pDevice->iManufacturer == 0xCB ||
					
					pDevice->iManufacturer == 0xC6 ) { // AEROCOM SDI (CH03)
					
					D8735A9140EC43B888E108661E19175A( pDevice, 10, 1 ); // I2S.SEL

					D8735A9140EC43B888E108661E19175A( pDevice, 11, 0 ); // I2S.TRI
				}
				else if( pDevice->iManufacturer == 0x5C ||
					
						 pDevice->iManufacturer == 0xCC ) {
					
					DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x02, 0x27, 0x00 );

					D8735A9140EC43B888E108661E19175A( pDevice, 10, 1 ); // I2S.SEL

					D8735A9140EC43B888E108661E19175A( pDevice, 11, 1 ); // I2S.TRI
				}
				else if( pDevice->iManufacturer == 0x5A ||
					
						 pDevice->iManufacturer == 0xCA ) {
					
					F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x00, 0x00 ); // SWITCH TO PAGE@0

					F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x1B, 0x01 ); // TRI-STATE

					F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x01, 0x01 ); //

					MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

					//p_sys_cfg->o_input_ite6603.SetAudioMute( pDevice, FALSE );

					SetAudioMute( pDevice, FALSE );

					D8735A9140EC43B888E108661E19175A( pDevice, 10, 1 ); // I2S.SEL

					D8735A9140EC43B888E108661E19175A( pDevice, 11, 1 ); // I2S.TRI
				}
				else if( pDevice->iManufacturer == 0x55 ||
				
						 pDevice->iManufacturer == 0xC5 ) {
		
					if( pDevice->m_nAnalogCrossbarVideoInputProperty == 0 ||  // HDMI (TMDS.B)

						pDevice->m_nAnalogCrossbarVideoInputProperty == 1 ) { // DVI.DIGITAL (TMDS.A)
					
						F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x00, 0x00 ); // SWITCH TO PAGE@0

						F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x1B, 0x01 ); // TRI-STATE

						F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x01, 0x01 ); //

						D8735A9140EC43B888E108661E19175A( pDevice, 10, 0 ); // I2S.SEL

						D8735A9140EC43B888E108661E19175A( pDevice, 11, 0 ); // I2S.TRI

						DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x02, 0x27, 0x00 );
					}
					else {

						D8735A9140EC43B888E108661E19175A( pDevice, 10, 1 ); // I2S.SEL

						D8735A9140EC43B888E108661E19175A( pDevice, 11, 0 ); // I2S.TRI
					}
				}
				else {
				
					if( pDevice->m_nAnalogCrossbarVideoInputProperty == 0 ||  // HDMI (TMDS.B)

						pDevice->m_nAnalogCrossbarVideoInputProperty == 1 ) { // DVI.DIGITAL (TMDS.A)

						DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x02, 0x27, 0x00 );

						D8735A9140EC43B888E108661E19175A( pDevice, 10, 1 ); // I2S.SEL

						D8735A9140EC43B888E108661E19175A( pDevice, 11, 1 ); // I2S.TRI
					}
					else { // SDI
			
						D8735A9140EC43B888E108661E19175A( pDevice, 10, 1 ); // I2S.SEL

						D8735A9140EC43B888E108661E19175A( pDevice, 11, 0 ); // I2S.TRI
					}
				}
			}
			else {

				if( pDevice->iManufacturer == 0x54 ||
					
					pDevice->iManufacturer == 0x5B ||
					
					pDevice->iManufacturer == 0xC4 ||
					
					pDevice->iManufacturer == 0xCB ||
					
					pDevice->iManufacturer == 0xC6 ) { // AEROCOM SDI (CH03)
					
					D8735A9140EC43B888E108661E19175A( pDevice, 10, 0 ); // I2S.SEL

					D8735A9140EC43B888E108661E19175A( pDevice, 11, 0 ); // I2S.TRI
				}
				else if( pDevice->iManufacturer == 0x55 ||
					
						 pDevice->iManufacturer == 0x5C ||
					
						 pDevice->iManufacturer == 0xC5 ||
						 
						 pDevice->iManufacturer == 0xCC ) {
						 	
					DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x02, 0x27, 0xFF ); // TRI-STATE

					D8735A9140EC43B888E108661E19175A( pDevice, 10, 0 ); // I2S.SEL

					D8735A9140EC43B888E108661E19175A( pDevice, 11, 0 ); // I2S.TRI
				}	
				else if( pDevice->iManufacturer == 0x5A ||
					
						 pDevice->iManufacturer == 0xCA ) {
					
					MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

					//p_sys_cfg->o_input_ite6603.SetAudioMute( pDevice, TRUE ); // TRI-STATE

					SetAudioMute( pDevice, TRUE ); // TRI-STATE

					D8735A9140EC43B888E108661E19175A( pDevice, 10, 0 ); // I2S.SEL

					D8735A9140EC43B888E108661E19175A( pDevice, 11, 0 ); // I2S.TRI
				}
				else {

					DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x02, 0x27, 0xFF ); // TRI-STATE
				
					D8735A9140EC43B888E108661E19175A( pDevice, 10, 0 ); // I2S.SEL

					D8735A9140EC43B888E108661E19175A( pDevice, 11, 0 ); // I2S.TRI
				}
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[CH%02X.%02d TLV320ADC3101]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, I2S_SEL);

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x00, 0x00 ); // SWITCH TO PAGE@0

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x01, 0x01 ); //

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x12, 0x81 ); // NADC        = 12.288 MHZ

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x13, 0x82 ); // MADC /   2  =   6144 KHZ

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x14, 0x80 ); // AOSR / 128  =     48 KHZ

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x1E, 0x84 ); // ADC_CLK     =  1.536 MHZ = 48K X STEREO X 16BIT

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x1B, 0x2C ); // [4:5] 0: 16 BITS, 1: 20 BITS, 2: 24BITS, 3: 36BITS

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x00, 0x00 );

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x00, 0x01 ); // SWITCH TO PAGE@1

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x00, 0x01 );

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x33, 0x00 ); // MICBIAS1, MICBIAS2 IS POWERED DOWN

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x34, 0xFC ); // LEFT ADC INPUT SELECTION FOR LEFT PGA, LCH_SEL1; USED FOR THE IN1L(P) PIN, WHICH IS SINGLE-ENDED

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x37, 0xFC ); // RIGHT ADC INPUT SELECTION FOR RIGHT PGA, RCH_SEL1; USED FOR THE IN1R(M) PIN, WHICH IS SINGLE-ENDED

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x3B, 0x00 );

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x3C, 0x00 );

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x00, 0x00 ); // SWITCH TO PAGE@0

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x3D, 0x02 );

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x51, 0x00 );

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x00, 0x00 ); // SWITCH TO PAGE@0

//				DbgPrint( "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 0x57 = %02X\n", C27FC32EA272493DB6DBE2D3BFE340AF( pDevice, 0, 0x30, 0x57 ) );
//				
//				DbgPrint( "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx 0x5F = %02X\n", C27FC32EA272493DB6DBE2D3BFE340AF( pDevice, 0, 0x30, 0x5F ) );
//				
//				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x57, 0x3E );
//
//				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x5F, 0x3E );

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x56, 0x00 );

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x5E, 0x00 );

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x51, 0xC2 );

				if( pDevice->iManufacturer == 0x5B ||  // SDI

					pDevice->iManufacturer == 0xCB ||  // SDI

					pDevice->iManufacturer == 0x51 ||  // AHD

					pDevice->iManufacturer == 0x52 ||  // AHD

					pDevice->iManufacturer == 0xC1 ||  // AHD

					pDevice->iManufacturer == 0xC2 ||  // AHD

					pDevice->iManufacturer == 0xC6 ) { // AEROCOM SDI (CH03)

					if( I2S_SEL == 1 ) {

						BYTE RTEMP = 0x00;

						if( pDevice->iManufacturer == 0x51 ||  // AHD
	
							pDevice->iManufacturer == 0xC1 ||  // AHD
	
							pDevice->iManufacturer == 0x52 ||  // AHD

							pDevice->iManufacturer == 0xC2 ) { // AHD

							RTEMP = ((0x00 << 2) | 0xF3); // ADC3101_SIGNAL_IN2
						}
						else {

							RTEMP = ((0x00 << 4) | 0xCF); // ADC3101_SIGNAL_IN3
						}
						F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x00, 0x01 ); // SWITCH TO PAGE@1

						F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x34, RTEMP );

						F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x37, RTEMP );
					}
					else {

						BYTE RTEMP = ((0x00 << 0) | 0xFC); // ADC3101_SINGLE_IN1

						F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x00, 0x01 ); // SWITCH TO PAGE@1

						F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x34, RTEMP );

						F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x37, RTEMP );
					}
				}
				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x00, 0x00 ); // SWITCH TO PAGE@0

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30, 0x52, 0x00 );
			}
		}
	}
	if( THREAD == FALSE ) { MZ0380_START_THREAD(); }

	return STATUS_SUCCESS;
}
extern void MST3367_ADJUST_CSC_TABLE( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bright, BYTE contrast, BYTE saturation, BYTE hue, BYTE sharpness );

NTSTATUS CC7AF56407504E059A58F55D48A142C1( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BOOL THREAD )
{
	if( THREAD == FALSE ) { MZ0380_CLOSE_THREAD(); }

	if( (pDevice->iProduct & 0x0F) == 0x02 ||
		
		(pDevice->iProduct & 0x0F) == 0x03 ) {
		ULONG counts = 0;

		if( (pDevice->iManufacturer & 0x0F) == 0x0B ||
			
			(pDevice->iManufacturer & 0x0F) == 0x0C ) {

			counts = 1;
		}
		else {

			counts = 2;
		}
		BYTE page = 0;
		for( page = 0 ; page < counts ; page++ ) {

			DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x40, page );

			ULONG i = 0;
			for( i = 0 ; i < 4 ; i++ ) {

				ULONG j = page * 4 + i;

				ULONG s = j; if( (pDevice->iProduct & 0x0F) == 0x02 && (pDevice->iManufacturer & 0x0F) == 0x0C ) { s = SC2CC_VIN_MAP[ j ]; }

				s = s % 4;

				if( FADD02C9C13B14f83989880EFACB8D8DC[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0x08000000 ) { DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * s) + 0x01), ((BYTE)(FADD02C9C13B14f83989880EFACB8D8DC[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) - 128) | 0x00 );  }

				if( F3A66BD0F0BCB4afcAD006E378E671B9A[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]   & 0x08000000 ) { DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * s) + 0x02), ((BYTE)(F3A66BD0F0BCB4afcAD006E378E671B9A[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]   & 0xFF) -  28) | 0x00 );  }

				if( F42BAA55A84E847faA4D0C0565699845E[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]        & 0x08000000 ) { DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * s) + 0x06), ((BYTE)(F42BAA55A84E847faA4D0C0565699845E[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]        & 0xFF) - 128) | 0x00 );  }

				if( F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0x08000000 ) { DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * s) + 0x04), ((BYTE)(F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) -   0) | 0x00 );  }

				if( F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0x08000000 ) { DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * s) + 0x05), ((BYTE)(F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) -   0) | 0x00 );  }

				if( F1D56E1ED762E4b99BB2BD370DFE317D1[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]  & 0x08000000 ) { DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, (BYTE)((0x10 * s) + 0x03), ((BYTE)(F1D56E1ED762E4b99BB2BD370DFE317D1[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]  & 0xFF) >>  4) | 0x20 );  }

				FADD02C9C13B14f83989880EFACB8D8DC[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] &= 0xF7FFFFFF;

				F3A66BD0F0BCB4afcAD006E378E671B9A[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] &= 0xF7FFFFFF;

				F42BAA55A84E847faA4D0C0565699845E[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] &= 0xF7FFFFFF;

				F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] &= 0xF7FFFFFF;

				F1D56E1ED762E4b99BB2BD370DFE317D1[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] &= 0xF7FFFFFF;
			}
		}
		DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x40, 0x00 );
	}
	else if( (pDevice->iProduct == 0x1C && pDevice->iManufacturer == 0xFA) || // ELGATO BOARD

			 (pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x03) || // ELGATO BOARD

			 (pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x05) || // ELGATO BOARD

			 (pDevice->iManufacturer == 0x5E) ||  // ELGATO BOARD

			 (pDevice->iManufacturer == 0x5F) ||  // SC550N1 M2 HDMI

			 (pDevice->iManufacturer == 0xCE) ||  // ELGATO BOARD

			 (pDevice->iManufacturer == 0xCF) ) { // SC5C0N1 M2 HDMI

		MST3367_ADJUST_CSC_TABLE( pDevice, (BYTE)(FADD02C9C13B14f83989880EFACB8D8DC[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF), 
		
										   (BYTE)(F3A66BD0F0BCB4afcAD006E378E671B9A[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF), 
									   
										   (BYTE)(F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF), 
									   
										   (BYTE)(F42BAA55A84E847faA4D0C0565699845E[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF), 

										  ((BYTE)(F1D56E1ED762E4b99BB2BD370DFE317D1[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) >> 5) );
	}
	else {
		
		if( pDevice->iManufacturer == 0x54 ||
			
			pDevice->iManufacturer == 0x5B ||
			
			pDevice->iManufacturer == 0xC4 ||
			
			pDevice->iManufacturer == 0xCB || 

			pDevice->iManufacturer == 0xC6 ) { // AEROCOM SDI (CH03)

			;
		}
		else if( pDevice->iManufacturer == 0x58 ||  // SC550N1 4K60P
			
				 pDevice->iManufacturer == 0x68 ||  // SC550N1 4K60P
			
				 pDevice->iManufacturer == 0xC8 ) { // SC5C0N1 4K60P
			;
		}
		else if( pDevice->iManufacturer == 0x59 ||  // SC550N1 4K60P
			
				 pDevice->iManufacturer == 0x69 ||  // SC550N1 4K60P
			
				 pDevice->iManufacturer == 0xC9 ) { // SC5C0N1 4K60P
			;
		}
		else if( pDevice->iManufacturer == 0x52 ||  // AHD.MAIN
			
				 pDevice->iManufacturer == 0xC2 ) { // AHD.MAIN
		}
		else if( pDevice->iManufacturer == 0x51 ||  // AHD.MAIN
			
				 pDevice->iManufacturer == 0xC1 ) { // AHD.MAIN
			
			MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

			if( p_sys_cfg->b_is_techpoint_support ) {

				;
			}
			else {

				DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, NVP6124_ADDR, 0xFF, 0x00 );
				
				#if 0
				BYTE i = 0;
				for( i = 0 ; i < 4 ; i++ ) {
				
					F42A18AF66EFF459eA332CA253FFF8A65 * p_device = g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ];
				
					if( p_device ) {

						if( p_device->m_nAnalogVideoProcAmpBrightnessProperty[ 0 ] & 0x08000000 ) { p_device->m_nAnalogVideoProcAmpBrightnessProperty[ 0 ] &= 0x77FFFFFF; INT bri = (p_device->m_nAnalogVideoProcAmpBrightnessProperty[ 0 ] - 128) + (p_sys_cfg->n_nvp6124_bri_def); /*DbgPrint( ">>>>>>> %d %d %d", p_sys_cfg->n_nvp6124_bri_def, (p_device->m_nAnalogVideoProcAmpBrightnessProperty[ 0 ] - 128), bri );*/ DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, NVP6124_ADDR, 0x0C + i, (BYTE)(bri) ); }
																																											  
						if( p_device->m_nAnalogVideoProcAmpContrastProperty[ 0 ]   & 0x08000000 ) { p_device->m_nAnalogVideoProcAmpContrastProperty[ 0 ] &= 0x77FFFFFF;   INT con = (p_device->m_nAnalogVideoProcAmpContrastProperty[ 0 ]   - 128) + (p_sys_cfg->n_nvp6124_con_def); /*DbgPrint( ">>>>>>> %d %d %d", p_sys_cfg->n_nvp6124_con_def, (p_device->m_nAnalogVideoProcAmpContrastProperty[ 0 ]   - 128), con );*/ DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, NVP6124_ADDR, 0x10 + i, (BYTE)(con) ); }
																																											  
						if( p_device->m_nAnalogVideoProcAmpHueProperty[ 0 ]        & 0x08000000 ) { p_device->m_nAnalogVideoProcAmpHueProperty[ 0 ] &= 0x77FFFFFF;        INT hue = (p_device->m_nAnalogVideoProcAmpHueProperty[ 0 ]        - 128) + (p_sys_cfg->n_nvp6124_hue_def); /*DbgPrint( ">>>>>>> %d %d %d", p_sys_cfg->n_nvp6124_hue_def, (p_device->m_nAnalogVideoProcAmpHueProperty[ 0 ]        - 128), hue );*/ DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, NVP6124_ADDR, 0x40 + i, (BYTE)(hue) ); }

						if( i == 0 ) {

							if( p_device->m_nAnalogVideoProcAmpSaturationProperty[ 0 ] & 0x08000000 ) { p_device->m_nAnalogVideoProcAmpSaturationProperty[ 0 ] &= 0x77FFFFFF; INT sat = (p_device->m_nAnalogVideoProcAmpSaturationProperty[ 0 ] - 128) + (p_sys_cfg->n_nvp6124_sat_def) - (48); /*DbgPrint( ">>>>>>> %d %d %d", p_sys_cfg->n_nvp6124_sat_def, (p_device->m_nAnalogVideoProcAmpSaturationProperty[ 0 ] - 128), sat );*/ DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, NVP6124_ADDR, 0x3C + i, (BYTE)(sat) ); }
						}
						else {

							if( p_device->m_nAnalogVideoProcAmpSaturationProperty[ 0 ] & 0x08000000 ) { p_device->m_nAnalogVideoProcAmpSaturationProperty[ 0 ] &= 0x77FFFFFF; INT sat = (p_device->m_nAnalogVideoProcAmpSaturationProperty[ 0 ] - 128) + (p_sys_cfg->n_nvp6124_sat_def) - ( 0); /*DbgPrint( ">>>>>>> %d %d %d", p_sys_cfg->n_nvp6124_sat_def, (p_device->m_nAnalogVideoProcAmpSaturationProperty[ 0 ] - 128), sat );*/ DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, NVP6124_ADDR, 0x3C + i, (BYTE)(sat) ); }
						}
					}
				}
				#endif //0
			}
		}
		else {

			if( pDevice->m_nAnalogCrossbarVideoInputProperty <= 3 ) {
/*
			MST3367_ADJUST_CSC_TABLE( pDevice, (BYTE)(pDevice->m_nAnalogVideoProcAmpBrightnessProperty[ 0 ] & 0xFF), 
				
											   (BYTE)(pDevice->m_nAnalogVideoProcAmpContrastProperty[ 0 ] & 0xFF), 
											   
											   (BYTE)(pDevice->m_nAnalogVideoProcAmpSaturationProperty[ 0 ] & 0xFF), 
											   
											   (BYTE)(pDevice->m_nAnalogVideoProcAmpHueProperty[ 0 ] & 0xFF), 

											  ((BYTE)(pDevice->m_nAnalogVideoProcAmpSharpnessProperty[ 0 ] & 0xFF) >> 5) );
*/
			MST3367_ADJUST_CSC_TABLE( pDevice, (BYTE)(FADD02C9C13B14f83989880EFACB8D8DC[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF), 
				
											   (BYTE)(F3A66BD0F0BCB4afcAD006E378E671B9A[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF), 
											   
											   (BYTE)(F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF), 
											   
											   (BYTE)(F42BAA55A84E847faA4D0C0565699845E[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]  & 0xFF), 
												   
											  ((BYTE)(F1D56E1ED762E4b99BB2BD370DFE317D1[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) >> 5) );

			}
			else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||
			
					 pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) {

				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x10, (BYTE)(((FADD02C9C13B14f83989880EFACB8D8DC[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]  & 0xFF) >> 0) - 128 - 19) | 0x00 );
			
				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x11, (BYTE)(((F3A66BD0F0BCB4afcAD006E378E671B9A[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]   & 0xFF) >> 0) -        7) | 0x00 );
			
				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x13, (BYTE)(((F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) >> 0) -        0) | 0x00 );
			
				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x14, (BYTE)(((F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) >> 0) -        0) | 0x00 );
			
				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x15, (BYTE)(((F42BAA55A84E847faA4D0C0565699845E[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]        & 0xFF) >> 0) -      128) | 0x00 );
			
				DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, 0x12, (BYTE)(((F1D56E1ED762E4b99BB2BD370DFE317D1[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]  & 0xFF) >> 4) -        0) | 0x50 ); 
			}
		}
	}
	MZ0380_START_THREAD();

	return STATUS_SUCCESS;
}

NTSTATUS MZ0380_SetAnalogAudioVoulmeProperty( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nVolume )
{
	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 < 1 )
	{
		return STATUS_SUCCESS;
	}

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "MZ0380_SetAnalogAudioVoulmeProperty( %08X )\n", nVolume);

	MZ0380_CLOSE_THREAD();

	if( (nVolume & 0x0000FF00) == (0x0000FF00) ) { // FOR TOTAL

		BYTE n_volume = (BYTE)(nVolume & 0x000000FF);

		n_volume >>= 2;

		ULONG counts = 0;
			
		if( (pDevice->iProduct & 0x0F) == 0x02 ||
						
			(pDevice->iProduct & 0x0F) == 0x03 ) {

			counts = 4;
		}
		else {

			counts = 1;
		}
		BYTE i = 0;
		for( i = 0 ; i < counts ; i++ ) {

			if( n_volume == 0 ) {

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x00, 0x00 ); // SWITCH TO PAGE@0

				BYTE R052 = C27FC32EA272493DB6DBE2D3BFE340AF( pDevice, 0, 0x30 + i * 0x02, 0x52 ); 
				
				R052 |= 0x88;

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x52, R052 );
			}
			else {

				CHAR R = -24;
			
				R += (BYTE)(n_volume);

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x00, 0x00 ); // SWITCH TO PAGE@0

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x53, R );

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x54, R );
				
				BYTE R052 = C27FC32EA272493DB6DBE2D3BFE340AF( pDevice, 0, 0x30 + i * 0x02, 0x52 );

				R052 &= 0x77;

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x52, R052 );
			}
		}
	}
	else { // BY CHANNEL

		ULONG n_channel = (nVolume >> 8) & (0x000000FF); n_channel %= 16;

		ULONG n_volume = (nVolume) & (0x000000FF);

		ULONG counts = 0;

		n_volume >>= 2;

		BYTE i = (BYTE)(n_channel);
		
		if( (pDevice->iProduct & 0x0F) == 0x02 ||
						
			(pDevice->iProduct & 0x0F) == 0x03 ) {

			counts = 4;
		}
		else {

			counts = 1;
		}
		if( i < counts ) {

			if( n_volume == 0 ) {

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x00, 0x00 ); // SWITCH TO PAGE@0

				BYTE R052 = C27FC32EA272493DB6DBE2D3BFE340AF( pDevice, 0, 0x30 + i * 0x02, 0x52 ); 
				
				R052 |= 0x88;

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x52, R052 );
			}
			else {

				CHAR R = -24;
			
				R += (BYTE)(n_volume);

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x00, 0x00 ); // SWITCH TO PAGE@0

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x53, R );

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x54, R );
				
				BYTE R052 = C27FC32EA272493DB6DBE2D3BFE340AF( pDevice, 0, 0x30 + i * 0x02, 0x52 );

				R052 &= 0x77;

				F43E046161B14BCBA21980D4E1F9465B( pDevice, 0, 0x30 + i * 0x02, 0x52, R052 );
			}
		}
	}
	MZ0380_START_THREAD();

	return STATUS_SUCCESS;
}

NTSTATUS BCBB6F46096343FA8AD2A9FF89F84A73( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

	command[ 1 ] = 0x00000007; // MZ0380_CMD_STOP_DMA

	command[ 2 ] = 0xFFFFFFFF;

	E7E90BC718B74429BB9234213955A126( pDevice, command, 3 );

	p_sys_cfg->n_is_firmware_ready &= 0x000000FF;

	return STATUS_SUCCESS;
}

NTSTATUS F640A7ABBB894EFBA34BA5C6FC719D34( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F640A7ABBB894EFBA34BA5C6FC719D34( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	ULONG counts = 1;

	if( (pDevice->iProduct & 0x0F) == 0x02 ||
		
		(pDevice->iProduct & 0x0F) == 0x03 ) {

		if( (pDevice->iManufacturer & 0x0F) == 0x01 ||
			
			(pDevice->iManufacturer & 0x0F) == 0x0B ||
			
			(pDevice->iManufacturer & 0x0F) == 0x0C ) {

			counts = 4;
		}
		else {

			counts = 8;
		}
	}

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"------------------------------------ n_is_firmware_ready(%08X) %d\n", p_sys_cfg->n_is_firmware_ready, counts );

	if( (p_sys_cfg->n_is_firmware_ready & 0x0001FFF) == (0x000000F1) ) {

		BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 0, 0x00000050, 0x00000000 );

		BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 0, 0x00000054, 0x00000000 );

		BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 0, 0x00000058, 0x00000000 );

		BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 0, 0x0000005C, 0x00000000 );

		ULONG i = 0;
		for( i = 0 ; i < counts ; i++ ) {

			ULONG deinterlaces[ 2 ] = { pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ i + 0 ] & 0x77FFFFFF,   // 0 = OFF / 1 = ON
					
										pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ i + 8 ] & 0x77FFFFFF }; // 0 = OFF / 1 = ON
	
			ULONG profiles[ 2 ] = { pDevice->m_nCustomEncoderVideoProfileProperty[ i + 0 ] & 0x77FFFFFF,   // 0 = HIGH PROFILE / 1 = BASELINE / 2 = MAIN PROFILE / 3 = HIGH PROFILE
					
									pDevice->m_nCustomEncoderVideoProfileProperty[ i + 8 ] & 0x77FFFFFF }; // 0 = HIGH PROFILE / 1 = BASELINE / 2 = MAIN PROFILE / 3 = HIGH PROFILE
	
			ULONG entropys[ 2 ] = { pDevice->m_nCustomEncoderVideoEntropyProperty[ i + 0 ] & 0x77FFFFFF,   // 0 = CABAC / 1 = CAVLC / 2 = CABAC
					
									pDevice->m_nCustomEncoderVideoEntropyProperty[ i + 8 ] & 0x77FFFFFF }; // 0 = CABAC / 1 = CAVLC / 2 = CABAC
	
			ULONG aspect_ratios_x[ 2 ] = { (pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i + 0 ] & 0x00FFF000) >> 12, 
					
											(pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i + 8 ] & 0x00FFF000) >> 12 }; 
	
			ULONG aspect_ratios_y[ 2 ] = { (pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i + 0 ] & 0x00000FFF) >> 0, 
				
										(pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i + 8 ] & 0x00000FFF) >> 0 }; 

			ULONG resolutions_x[ 2 ] = { (pDevice->m_nCustomEncoderVideoResolutionProperty[ i + 0 ] & 0x00FFF000) >> 12,
					
									     (pDevice->m_nCustomEncoderVideoResolutionProperty[ i + 8 ] & 0x00FFF000) >> 12 };

			ULONG resolutions_y[ 2 ] = { (pDevice->m_nCustomEncoderVideoResolutionProperty[ i + 0 ] & 0x00000FFF) >> 0,
					
									     (pDevice->m_nCustomEncoderVideoResolutionProperty[ i + 8 ] & 0x00000FFF) >> 0 };

			ULONG avgs[ 4 ] = { pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ i + 0 ] & 0x77FFFFFF,
					
								pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ i + 8 ] & 0x77FFFFFF,
					
								pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ i + 0 ] & 0x77FFFFFF,
					
								pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ i + 8 ] & 0x77FFFFFF };

			ULONG skips[ 4 ] = { (pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ i + 0 ] & 0x77FFFFFF) + (1), 
					
								 (pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ i + 8 ] & 0x77FFFFFF) + (1), 
					
								 (pDevice->m_nCustomAnalogVideoSkipFrameRateProperty[ i + 0 ] & 0x77FFFFFF) + (1), 
					
								 (pDevice->m_nCustomAnalogVideoSkipFrameRateProperty[ i + 8 ] & 0x77FFFFFF) + (1) };
	
			ULONG modes[ 2 ] = { pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + 0 ] & 0x77FFFFFF,
					
									pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + 8 ] & 0x77FFFFFF };
	
			ULONG qualitys[ 2 ] = { pDevice->m_nAnalogVideoCompressionQualityProperty[ i + 0 ] & 0x77FFFFFF,
	
									pDevice->m_nAnalogVideoCompressionQualityProperty[ i + 8 ] & 0x77FFFFFF };
	
			ULONG bitrates[ 2 ] = { pDevice->m_nCustomEncoderVideoBitRateProperty[ i + 0 ] & 0x77FFFFFF,
					
									pDevice->m_nCustomEncoderVideoBitRateProperty[ i + 8 ] & 0x77FFFFFF };
	
			ULONG gops[ 2 ] = { pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ i + 0 ] & 0x77FFFFFF,
					
								pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ i + 8 ] & 0x77FFFFFF };
	
			ULONG nals[ 2 ] = { 0x00, 0x00 }; // BIT00: PRIMARY_PIC_TYPE / BIT01: VUI_NAL / BIT02: VUI_VCL

			ULONG crop_x[ 2 ] = { pDevice->m_nCustomEncoderVideoCropProperty[ 0 ][ i + 0 ] & 0x77FFFFFF,
					
								  pDevice->m_nCustomEncoderVideoCropProperty[ 0 ][ i + 8 ] & 0x77FFFFFF };

			ULONG crop_y[ 2 ] = { pDevice->m_nCustomEncoderVideoCropProperty[ 1 ][ i + 0 ] & 0x77FFFFFF,
					
								  pDevice->m_nCustomEncoderVideoCropProperty[ 1 ][ i + 8 ] & 0x77FFFFFF };

			ULONG crop_w[ 2 ] = { pDevice->m_nCustomEncoderVideoCropProperty[ 2 ][ i + 0 ] & 0x77FFFFFF,
					
								  pDevice->m_nCustomEncoderVideoCropProperty[ 2 ][ i + 8 ] & 0x77FFFFFF };

			ULONG crop_h[ 2 ] = { pDevice->m_nCustomEncoderVideoCropProperty[ 3 ][ i + 0 ] & 0x77FFFFFF,
					
								  pDevice->m_nCustomEncoderVideoCropProperty[ 3 ][ i + 8 ] & 0x77FFFFFF };

			ULONG cx = p_sys_cfg->n_input_video_resolution_cx;
	
			ULONG cy = p_sys_cfg->n_input_video_resolution_cy;
	
			ULONG fps = p_sys_cfg->n_input_video_resolution_fps;
	
			ULONG m = p_sys_cfg->n_input_video_resolution_fps_m;

			ULONG interleaved = p_sys_cfg->n_input_video_resolution_interleaved;

			ULONG freq = p_sys_cfg->n_input_audio_sampling_frequency;
	
			BOOL  is_nosg = FALSE;

			ULONG color_colorimetrys[ 3 ] = { 0, 0, 0 };

			ULONG color_range = p_sys_cfg->n_input_video_resolution_color_range; // 0: UNKNOWN / 1: LIMITED / 2: FULL

			BOOL  is_down_scaling = FALSE;
			
			ULONG is_dual_streams = (pDevice->m_nCustomAnalogVideoSubEncoderEnableProperty && pDevice->m_nCustomAnalogVideo720OutputProperty) ? 2 : 1;
	
			ULONG s = i; if( (pDevice->iProduct & 0x0F) == 0x02 && (pDevice->iManufacturer & 0x0F) == 0x0C ) { s = SC2CC_VIN_MAP[ i ]; }

			pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ i + 0 ] &= 0x77FFFFFF;
	
			pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ i + 8 ] &= 0x77FFFFFF;

			pDevice->m_nCustomAnalogVideoSkipFrameRateProperty[ i + 0 ] &= 0x77FFFFFF;

			pDevice->m_nCustomAnalogVideoSkipFrameRateProperty[ i + 8 ] &= 0x77FFFFFF;

			pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ i + 0 ] &= 0x77FFFFFF;

			pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ i + 8 ] &= 0x77FFFFFF;

			pDevice->m_nCustomEncoderVideoProfileProperty[ i + 0 ] &= 0x77FFFFFF;
	
			pDevice->m_nCustomEncoderVideoProfileProperty[ i + 8 ] &= 0x77FFFFFF;
	
			pDevice->m_nCustomEncoderVideoEntropyProperty[ i + 0 ] &= 0x77FFFFFF;
	
			pDevice->m_nCustomEncoderVideoEntropyProperty[ i + 8 ] &= 0x77FFFFFF;
	
			pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i + 0 ] &= 0x77FFFFFF;
	
			pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i + 8 ] &= 0x77FFFFFF;

			pDevice->m_nCustomEncoderVideoResolutionProperty[ i + 0 ] &= 0x77FFFFFF;

			pDevice->m_nCustomEncoderVideoResolutionProperty[ i + 8 ] &= 0x77FFFFFF;

			pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ i + 0 ] &= 0x77FFFFFF;
	
			pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ i + 8 ] &= 0x77FFFFFF;
	
			pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ i + 0 ] &= 0x77FFFFFF;
	
			pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ i + 8 ] &= 0x77FFFFFF;
	
			pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + 0 ] &= 0x77FFFFFF;
	
			pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + 8 ] &= 0x77FFFFFF;
	
			pDevice->m_nCustomEncoderVideoBitRateProperty[ i + 0 ] &= 0x77FFFFFF;
	
			pDevice->m_nCustomEncoderVideoBitRateProperty[ i + 8 ] &= 0x77FFFFFF;
	
			pDevice->m_nAnalogVideoCompressionQualityProperty[ i + 0 ] &= 0x77FFFFFF;
	
			pDevice->m_nAnalogVideoCompressionQualityProperty[ i + 8 ] &= 0x77FFFFFF;
	
			pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ i + 0 ] &= 0x77FFFFFF;
	
			pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ i + 8 ] &= 0x77FFFFFF;
	
			pDevice->m_nAnalogVideoCompressionOverrideKeyframeProperty[ i + 0 ] = 0;
	
			pDevice->m_nAnalogVideoCompressionOverrideKeyframeProperty[ i + 8 ] = 0;
	
			ULONG j = 0;
			for( j = 0 ; j < 2 ; j++ ) {
	
				if( skips[ j ] == 1 ) {
						
					skips[ j ] = 0;
				}		
				if( avgs[ j ] > 0 ) {
	
					skips[ j ] = 0;
				}
		//		{	qualitys[ j ] *= 51;
		//
		//			qualitys[ j ] /= 10000;
		//
		//			if( qualitys[ j ] > 51 ) { qualitys[ j ] = 51; }
		//
		//			qualitys[ j ] = 51 - qualitys[ j ];
		//		}
				{	qualitys[ j ] /= 250; // QP RANGE: 8 ~ 48
	
					if( qualitys[ j ] > 40 ) { qualitys[ j ] = 40; }
	
					qualitys[ j ] = (40 - qualitys[ j ]) + 8;
				}
			}
			for( j = 2 ; j < 4 ; j++ ) {

				if( skips[ j ] == 1 ) {
						
					skips[ j ] = 0;
				}		
				if( avgs[ j ] > 0 ) {

					skips[ j ] = 0;
				}
			}
			if( (cx == 1440 && cy == 240) ||  // [720X240@60P]
				
				(cx == 1440 && cy == 288) ) { // [720X288@60P]

				cx = 720;
			}
			if( interleaved ) {
	
				cy <<= 1;
	
				fps >>= 1;
			}
			if( cx == 0 ||

				cy == 0 ||

				fps == 0 ) {

				is_nosg = TRUE;

				cx = p_sys_cfg->n_output_video_resolution_cx;
		
				cy = p_sys_cfg->n_output_video_resolution_cy;
		
				fps = p_sys_cfg->n_output_video_resolution_fps;

				m = p_sys_cfg->n_output_video_resolution_fps_m;

				interleaved = p_sys_cfg->n_output_video_resolution_interleaved;
			}		
			if( freq == 0 ) {

				freq = p_sys_cfg->n_output_audio_sampling_frequency;
			}
			if( freq == 0 ) {

				freq = 48000;

			//	freq = 0;
			}
			if( cx == 0 ||
	
				cy == 0 ||
	
				fps == 0 ) {
					
				if( pDevice->iManufacturer == 0x51 ||  // AHD
						
					pDevice->iManufacturer == 0xC1 ||  // AHD
						
					pDevice->iManufacturer == 0x52 ||  // AHD
						
					pDevice->iManufacturer == 0xC2 ) { // AHD
						
					cx = 1920; cy = 1080; fps = 30; m = 0; interleaved = 0;

				//	cx = 0; cy = 0; fps = 0; m = 0; interleaved = 0;
				}
				else {
						
					cx = 1920; cy = 1080; fps = 60; m = 0; interleaved = 0;

				//	cx = 0; cy = 0; fps = 0; m = 0; interleaved = 0;
				}
			}
//			if( (pDevice->iProduct == 0x1C && pDevice->iManufacturer == 0xFA) ||  // ELGATO BOARD
//				(pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x03) ||  // ELGATO BOARD
//				(pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x05) ) { // ELGATO BOARD
//
//				if( pDevice->m_nAnalogVideoDecoderStatusProperty == 0 ) {
//
//					cx = 0; cy = 0; fps = 0; m = 0; freq = 0;
//				}
//			}
//			if( (pDevice->iProduct & 0x0F) == 0x05 ) {
//
///				if( pDevice->iManufacturer == 0xCA ) {
//	
//					;
//				}
//				else {
//
//					if( pDevice->m_nAnalogVideoDecoderStatusProperty == 0 ) {
//
//						cx = 0; cy = 0; fps = 0; m = 0; freq = 0;
//					}
//				}
//			}
			if( pDevice->m_nCustomAnalogVideoMultiSyncChannels >= 1 ) {

				is_dual_streams = 0;
			
				resolutions_x[ 0 ] = 0;

				resolutions_y[ 0 ] = 0;
			
				resolutions_x[ 1 ] = 0;

				resolutions_y[ 1 ] = 0;

				skips[ 0 ] = 0;

				skips[ 1 ] = 0;

				skips[ 2 ] = 0;

				skips[ 3 ] = 0;

				avgs[ 0 ] = 0;

				avgs[ 1 ] = 0;

				avgs[ 2 ] = 0;

				avgs[ 3 ] = 0;
			}
			if( is_dual_streams == 2 ) { // [2015.12.31] [HUENGPEI] 增加雙碼流規格限制

				if( (cx * cy * fps) > (1920 * 1200 * 30) && (interleaved == 0) ) { 
					
					ULONG j = 0;
					for( j = 0 ; j < 4 ; j++ ) {

						if( avgs[ j ] > 0 ) { 
						
							if( avgs[ j ] > (fps >> 1) ) {

								avgs[ j ] = (fps >> 1); 
							} 
						}
						else { 
						
							if( skips[ j ] < 2 ) { 
								
								skips[ j ] = 2; 
							} 
						}
					}
				}
//				resolutions_x[ 0 ] = 0;
//
//				resolutions_y[ 0 ] = 0;
			}
			else {

				if( resolutions_x[ 0 ] > 0 &&
					
					resolutions_y[ 0 ] > 0 ) {
	
					if( resolutions_x[ 0 ] <= cx &&
					
						resolutions_y[ 0 ] <= cy ) {
	
						is_down_scaling = TRUE;
					}
					if( resolutions_x[ 0 ] == cx &&
					
						resolutions_y[ 0 ] == cy ) {
	
						is_down_scaling = FALSE;
					}
				}
				if( is_down_scaling == FALSE ) {
	
					resolutions_x[ 0 ] = 0;
	
					resolutions_y[ 0 ] = 0;
	
					resolutions_x[ 1 ] = 0;
	
					resolutions_y[ 1 ] = 0;
				}
			}
			if( resolutions_x[ 0 ] == cx &&
				
				resolutions_y[ 0 ] == cy ) {

				resolutions_x[ 0 ] = 0;

				resolutions_y[ 0 ] = 0;
			}
			if( resolutions_x[ 1 ] == cx &&
				
				resolutions_y[ 1 ] == cy ) {

				resolutions_x[ 1 ] = 0;

				resolutions_y[ 1 ] = 0;
			}

			ULONG t = 0;
			for( t = 0 ; t < 2 ; t++ ) {

				{	crop_x[ t ] &= 0xFFFFFFF0;

					crop_w[ t ] &= 0xFFFFFFFE;

					if( crop_w[ t ] > 0 && crop_w[ t ] < 128 ) { crop_w[ t ] = 128; }

					if( crop_h[ t ] > 0 && crop_h[ t ] <  64 ) { crop_h[ t ] =  64; }
				}
				if( (crop_x[ t ] >= cx) || 
				
				    (crop_y[ t ] >= cy) ) {

					crop_x[ t ] = 0;
					
					crop_y[ t ] = 0;
					
					crop_w[ t ] = 0;
					
					crop_h[ t ] = 0;
				}
				else if( ((crop_x[ t ] + crop_w[ t ]) > cx) ||
				
						 ((crop_y[ t ] + crop_h[ t ]) > cy) ) {

					crop_x[ t ] = 0;
					
					crop_y[ t ] = 0;						
					
					crop_w[ t ] = 0;
					
					crop_h[ t ] = 0;
				}
				else if( (crop_w[ t ] == 0) ||
				
						 (crop_h[ t ] == 0) ) {

					crop_x[ t ] = 0;
					
					crop_y[ t ] = 0;						
					
					crop_w[ t ] = 0;
					
					crop_h[ t ] = 0;
				}
				else{

					;
				}
				if( resolutions_x[ t ] > 0 &&

					resolutions_y[ t ] > 0 &&

					cx > 0 &&

					cy > 0 ) {

					crop_x[ t ] *= resolutions_x[ t ]; crop_x[ t ] /= cx;

					crop_y[ t ] *= resolutions_y[ t ]; crop_y[ t ] /= cy;

					crop_w[ t ] *= resolutions_x[ t ]; crop_w[ t ] /= cx;

					crop_h[ t ] *= resolutions_y[ t ]; crop_h[ t ] /= cy;
				}
			}
			if( pDevice->iManufacturer == 0x58 ||  // 4K@60P
						
				pDevice->iManufacturer == 0x68 ||  // 4K@60P
						
				pDevice->iManufacturer == 0xC8 ) { // 4K@60P

				if( pDevice->m_nCustomAnalogVideoMultiSyncChannels > 0 ) {

					cx /= pDevice->m_nCustomAnalogVideoMultiSyncChannels;
				}
			}
			if( pDevice->iManufacturer == 0x59 ||  // 4K@60P
						
				pDevice->iManufacturer == 0x69 ||  // 4K@60P
						
				pDevice->iManufacturer == 0xC9 ) { // 4K@60P

				if( p_sys_cfg->n_output_multi_sync_channels > 0 ) {

					cx /= p_sys_cfg->n_output_multi_sync_channels;
				}
			}
			if( cx > 0 &&
	
				cy > 0 ) {
	
				{	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	
					ULONG fw = 0;
	
					ULONG vi = 6; // 1:8-BITS RAW, 2:CCIR656I, 3:CCIR656P, 4: BAYER, 5:16-BITS RAW, 6: BT1120P, 7: BT1120I
	
					if( (pDevice->iProduct & 0x0F) == 0x02 ||
						
						(pDevice->iProduct & 0x0F) == 0x03 ) {

						if( (pDevice->iManufacturer & 0x0F) == 0x0C ) {
	
							fw = 4;
	
							vi = 2;
						}
						else {
	
							fw = 5;

							vi = 2;
						}
						nals[ 0 ] = 0x00;

						nals[ 1 ] = 0x00;

						if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_60HZ ) {
								
							color_colorimetrys[ 0 ] = 6; // BT.601 525

							color_colorimetrys[ 1 ] = 6; // BT.601 525

							color_colorimetrys[ 2 ] = 6; // BT.601 525

							color_range = 1;
						}
						if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_50HZ ) {
								
							color_colorimetrys[ 0 ] = 5; // BT.601 625

							color_colorimetrys[ 1 ] = 6; // BT.601 625

							color_colorimetrys[ 2 ] = 5; // BT.601 625

							color_range = 1;
						}
					}
					else {

						if( (cx * cy * fps) > (1920 * 1200 * 30) && (interleaved == 0) ) { 

							if( is_dual_streams == 2 ) {

								fw = 5;
							}
							else {
	
								fw = (is_down_scaling) ? 5 : 7;
							}
						}
						else {
	
							fw = 5;
						}
			
						if( pDevice->iManufacturer == 0x58 ||  // 4K@60P
						
							pDevice->iManufacturer == 0x68 ||  // 4K@60P
						
							pDevice->iManufacturer == 0xC8 ||  // 4K@60P
						
							pDevice->iManufacturer == 0x59 ||  // 4K@60P
						
							pDevice->iManufacturer == 0x69 ||  // 4K@60P
						
							pDevice->iManufacturer == 0xC9 ) { // 4K@60P

							vi = 6;
						}
						else if( pDevice->iManufacturer == 0x51 ||  // AHD
						
								 pDevice->iManufacturer == 0xC1 ||  // AHD
						
								 pDevice->iManufacturer == 0x52 ||  // AHD
						
								 pDevice->iManufacturer == 0xC2 ) { // AHD
						
							if( cx <= 960 ) {
							
								vi = 2; // AHD.SD
							}
							else {

								if( p_sys_cfg->b_is_techpoint_support ) {

									vi = 3; // AHD.HD (8BITS)
								}
								else {

									vi = 3; // AHD.HD (8BITS)
								}
							}
						}
						else if( ((pDevice->iManufacturer == 0x54 ||  // SC550N1 MC SDI
			
								   pDevice->iManufacturer == 0x5B ||  // SC550N4 SDI

								   pDevice->iManufacturer == 0xC4 ||  // SC5C0N1 MC SDI
			
								   pDevice->iManufacturer == 0xCB ||  // SC5C0N4 SDI

								   pDevice->iManufacturer == 0xC6 ||  // AEROCOM SDI (CH03)
				 
								   pDevice->m_nAnalogCrossbarVideoInputProperty == 4) && 

								   cx == 720 &&
								
								   interleaved == 1) ) { // SDI.SD
	
							vi = 2;
						}
						else if( (pDevice->m_nAnalogCrossbarVideoInputProperty == 5 && interleaved == 1) ||

								 (pDevice->m_nAnalogCrossbarVideoInputProperty == 6 && interleaved == 1) ) {

							vi = 2;
						}
						else if( p_sys_cfg->b_input_video_resolution_external_sync == TRUE ) {
						
							vi = 5;
						}
						else if( interleaved == 1 ) {

							vi = 7;
						}
						else {
	
							vi = 6;
						}
						nals[ 0 ] = 0x00;//vlc

						nals[ 1 ] = 0x00;//vlc

						if( p_sys_cfg->n_input_video_resolution_color_colorimetry == 0 ) {
							
//							color_colorimetrys[ 0 ] = 2; // UNKNOWN 
//							
//							color_colorimetrys[ 1 ] = 2; // UNKNOWN 
//
//							color_colorimetrys[ 2 ] = 2; // UNKNOWN 

							if( (cx * cy) >= (800 * 600) ) {

								color_colorimetrys[ 0 ] = 1; // BT.709 

								color_colorimetrys[ 1 ] = 1; // BT.709 

								color_colorimetrys[ 2 ] = 1; // BT.709 
							}
							else {

								if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_60HZ ) {
								
									color_colorimetrys[ 0 ] = 6; // BT.601 525

									color_colorimetrys[ 1 ] = 6; // BT.601 525

									color_colorimetrys[ 2 ] = 6; // BT.601 525
								}
								if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_50HZ ) {
								
									color_colorimetrys[ 0 ] = 5; // BT.601 625

									color_colorimetrys[ 1 ] = 6; // BT.601 625

									color_colorimetrys[ 2 ] = 5; // BT.601 625
								}
							}
							color_range = 1;
						}
						else if( p_sys_cfg->n_input_video_resolution_color_colorimetry >= 2 ) {

							color_colorimetrys[ 0 ] = 1; // BT.709 

							color_colorimetrys[ 1 ] = 1; // BT.709 

							color_colorimetrys[ 2 ] = 1; // BT.709 
						}
						else {

							if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_60HZ ) {
								
								color_colorimetrys[ 0 ] = 6; // BT.601 525

								color_colorimetrys[ 1 ] = 6; // BT.601 525

								color_colorimetrys[ 2 ] = 6; // BT.601 525

								color_range = 1;
							}
							if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_50HZ ) {
								
								color_colorimetrys[ 0 ] = 5; // BT.601 625

								color_colorimetrys[ 1 ] = 6; // BT.601 625

								color_colorimetrys[ 2 ] = 5; // BT.601 625

								color_range = 1;
							}
						}
					}
					p_sys_cfg->n_output_video_resolution_vi_fw = fw;
					
					p_sys_cfg->n_output_video_resolution_cx = cx;

					p_sys_cfg->n_output_video_resolution_cy = cy;

					p_sys_cfg->n_output_video_resolution_fps = fps;
					
					p_sys_cfg->n_output_video_resolution_fps_m = m;

					p_sys_cfg->n_output_video_resolution_interleaved = interleaved;

					p_sys_cfg->n_output_video_resolution_is_nosg = is_nosg;

					p_sys_cfg->n_output_audio_sampling_frequency = freq;

					ULONG n_h_start = 0;

					ULONG n_v_start = 0;

					ULONG n_h_total = cx;

					ULONG n_v_total = cy;

					ULONG n_vbi_F3B543EB6D1C348648C2947A125F64000 = 0;
					
					if( p_sys_cfg->b_input_video_resolution_external_sync == TRUE ||
					
					    pDevice->m_nCustomAnalogVideoVbiLinesEnableProperty == TRUE ) {

						if( cx == 1920 && cy == 1080 && fps == 60 && interleaved == 0 ) { n_h_start = 148; n_v_start = 36; n_h_total = 2200 - 44; n_v_total = 1125 - 5; } else

						if( cx == 1920 && cy == 1080 && fps == 60 && interleaved == 1 ) { n_h_start = 148; n_v_start = 15; n_h_total = 2200 - 44; n_v_total = 1125 - 5; } else

						if( cx == 1920 && cy == 1080 && fps == 50 && interleaved == 0 ) { n_h_start = 148; n_v_start = 36; n_h_total = 2640 - 44; n_v_total = 1125 - 5; } else

						if( cx == 1920 && cy == 1080 && fps == 50 && interleaved == 1 ) { n_h_start = 148; n_v_start = 15; n_h_total = 2640 - 44; n_v_total = 1125 - 5; } else

						if( cx == 1920 && cy == 1080 && fps == 30 && interleaved == 0 ) { n_h_start = 148; n_v_start = 36; n_h_total = 2200 - 44; n_v_total = 1125 - 5; } else

						if( cx == 1920 && cy == 1080 && fps == 25 )                     { n_h_start = 148; n_v_start = 36; n_h_total = 2640 - 44; n_v_total = 1125 - 5; } else

						if( cx == 1920 && cy == 1080 && fps == 24 )                     { n_h_start = 148; n_v_start = 36; n_h_total = 2750 - 44; n_v_total = 1125 - 5; } else

						if( cx == 1280 && cy == 720  && fps == 60 )                     { n_h_start = 220; n_v_start = 20; n_h_total = 1650 - 40; n_v_total =  750 - 5; } else

						if( cx == 1280 && cy == 720  && fps == 50 )                     { n_h_start = 220; n_v_start = 20; n_h_total = 1980 - 40; n_v_total =  750 - 5; } else

						if( cx == 1400 && cy == 1050 && fps >   0 )                     { n_h_start = 232; n_v_start = 32; n_h_total = 1720 -  0; n_v_total = 1085 - 0; } else
						
						if( cx == 1280 && cy ==  720 && fps == 24 )                     { n_h_start = 220; n_v_start = 20; n_h_total = 3300 - 40; n_v_total =  750 - 5; } else
						
						if( cx == 1280 && cy ==  720 && fps == 30 )                     { n_h_start = 220; n_v_start = 20; n_h_total = 3300 - 40; n_v_total =  750 - 5; } else
						
						if( cx == 1280 && cy ==  720 && fps == 25 )                     { n_h_start = 220; n_v_start = 20; n_h_total = 3960 - 40; n_v_total =  750 - 5; } else 
						
						if( cx ==  720 && cy ==  240 && fps >   0 )                     { n_h_start = 114; n_v_start = 16; n_h_total = 1592 -  0; n_v_total =  260 - 0; } else 

						if( pDevice->m_nCustomAnalogVideoVbiLinesEnableProperty == TRUE ) {

							if( pDevice->m_nCustomAnalogVideoVbiLinesProperty <= n_v_start ) {
							
								n_vbi_F3B543EB6D1C348648C2947A125F64000 = pDevice->m_nCustomAnalogVideoVbiLinesProperty;
							}
							else {

								n_vbi_F3B543EB6D1C348648C2947A125F64000 = n_v_start;
							}
							p_sys_cfg->n_output_video_resolution_vbi_F3B543EB6D1C348648C2947A125F64000 = n_vbi_F3B543EB6D1C348648C2947A125F64000;
						}
						else {
						
							p_sys_cfg->n_output_video_resolution_vbi_F3B543EB6D1C348648C2947A125F64000 = 0;	
							
							n_vbi_F3B543EB6D1C348648C2947A125F64000 = 0;
						}
					}
					else {

						p_sys_cfg->n_output_video_resolution_vbi_F3B543EB6D1C348648C2947A125F64000 = 0;

						n_vbi_F3B543EB6D1C348648C2947A125F64000 = 0;
					}

					ULONG n_osd_enabled = 0;

					ULONG n_osd_size = 10;

					ULONG line = 0;
					for( line = 0 ; line < 16 ; line++ ) {

						CHAR * psz = (CHAR *)(pDevice->m_pCustomOsdTextStringProperty[ i ][ line ]);

						if( psz[ 0 ] != 0x00 ) {

							n_osd_enabled = 1;

							n_osd_size = pDevice->m_nCustomOsdTextFontSizeProperty[ i ][ line ];
						}
						/*
						if( pDevice->m_nCustomCompanyHDSightProperty > 0 ) {

							n_osd_enabled = 1;

							n_osd_size = 12;
						}
						*/
					}
					command[ 1 ] = 0x00000029; // MZ0380_CMD_SET_VIC_PARAMS
	
					command[ 2 ] = (vi << 24) | (fw << 16) | (fps << 8) | (s << 0);
	
					command[ 3 ] = ((cy + n_vbi_F3B543EB6D1C348648C2947A125F64000) << 16) | (cx << 0);
	
					command[ 4 ] = (m << 0);

					command[ 5 ] = (color_range << 24) | (color_colorimetrys[ 2 ] << 16) | (color_colorimetrys[ 1 ] << 8) | (color_colorimetrys[ 0 ] << 0);

					command[ 6 ] = ((n_v_start - n_vbi_F3B543EB6D1C348648C2947A125F64000) << 16) | (n_h_start << 0);

					command[ 7 ] = (n_v_total << 16) | (n_h_total << 0);

					command[ 8 ] = (is_nosg << 24) | (n_osd_size << 16) | (n_osd_enabled << 8) | (is_dual_streams << 0);

					command[ 9 ] = (n_vbi_F3B543EB6D1C348648C2947A125F64000 << 0);

					if( E7E90BC718B74429BB9234213955A126( pDevice, command, 10 ) ) {
	
						p_sys_cfg->n_is_firmware_ready |= 0x00000100;
					}
					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "vi = %d, cx = %d, cy = %d, fps = %d, m = %d, vbi=%d\n", vi, cx, cy, fps, m, n_vbi_F3B543EB6D1C348648C2947A125F64000);
				}
				if( (p_sys_cfg->n_is_firmware_ready & 0x00000100) == 0x00000100 ) {

					{	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
		
						ULONG chs = 2;
		
						ULONG bits = 16;
		
						if( (pDevice->iProduct & 0x0F) == 0x02 ||
							
							(pDevice->iProduct & 0x0F) == 0x03 ) {
		
							chs = 1;
						}
						else {
		
							chs = 2;
						}
						command[ 1 ] = 0x0000002A; // MZ0380_CMD_SET_AIC_PARAMS
		
					//	command[ 2 ] = (bits << 16) | (chs << 8) | (s << 0);
						
						command[ 2 ] = (bits << 16) | (chs << 8) | (i << 0);
		
						command[ 3 ] = (freq << 0);
		
						if( E7E90BC718B74429BB9234213955A126( pDevice, command, 4 ) ) {
		
							p_sys_cfg->n_is_firmware_ready |= 0x00000200;
						}
					}

					if( (pDevice->iProduct & 0x0F) == 0x02 && (pDevice->iManufacturer & 0x0F) == 0x0C ) { 
	
						DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	
						ULONG chs = 1;
	
						ULONG bits = 16;
	
						command[ 1 ] = 0x0000002A; // MZ0380_CMD_SET_AIC_PARAMS
		
						command[ 2 ] = (bits << 16) | (chs << 8) | ((i + 4) << 0);
	
						command[ 3 ] = (freq << 0);
	
						if( E7E90BC718B74429BB9234213955A126( pDevice, command, 4 ) ) {
	
							p_sys_cfg->n_is_firmware_ready |= 0x00000200;
						}
					}
				}
				if( (p_sys_cfg->n_is_firmware_ready & 0x00000300) == 0x00000300 ) {

					DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	
					ULONG main_or_sub = 0;
	
					ULONG sar_x = aspect_ratios_x[ 0 ] * ((resolutions_y[ 0 ] > 0) ? resolutions_y[ 0 ] : cy);
	
					ULONG sar_y = aspect_ratios_y[ 0 ] * ((resolutions_x[ 0 ] > 0) ? resolutions_x[ 0 ] : cx);
	
					if( ((sar_x % 4) == 0) && ((sar_y % 4) == 0) ) { sar_x /= 4; sar_y /= 4; }
	
					if( ((sar_x % 2) == 0) && ((sar_y % 2) == 0) ) { sar_x /= 2; sar_y /= 2; }
	
					if( ((sar_x % 3) == 0) && ((sar_y % 3) == 0) ) { sar_x /= 3; sar_y /= 3; }
	
					if( ((sar_x % 5) == 0) && ((sar_y % 5) == 0) ) { sar_x /= 5; sar_y /= 5; }
	
					command[ 1 ] = 0x0000002D; // MZ0380_CMD_SET_ENC_PARAMS
	
					command[  2 ] = 0x00003FFF;
	
					command[ 3 ] = (gops[ 0 ] << 24) | (fps << 16) | (main_or_sub << 8) | (s << 0);
	
					command[ 4 ] = (1 << 24) | (modes[ 0 ] << 16) | (profiles[ 0 ] << 8) | (qualitys[ 0 ] << 0);
	
					command[ 5 ] = (bitrates[ 0 ] << 0);
	
					command[  6 ] = (nals[ 0 ] << 24) | (entropys[ 0 ] << 16) | (avgs[ 0 ] << 8) | (skips[ 0 ] << 0);
	
					command[ 7 ] = (sar_x << 16) | (sar_y << 0);
	
					command[ 8 ] = (resolutions_x[ 0 ] << 16) | (resolutions_y[ 0 ] << 0);

					command[  9 ] = (crop_x[ 0 ] << 16) | (crop_y[ 0 ] << 0);

					command[ 10 ] = (crop_w[ 0 ] << 16) | (crop_h[ 0 ] << 0);

					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "mask = %08X, i = %d, main_or_sub = %d, fps = %d, gop = %d, quality = %d, profile = %d, entropy = %d, mode = %d, bitrate = %d, skip = %d, avg = %d, aspect_ratio = %d.%d.%d.%d, res = %d.%d, crop = %d.%d.%d.%d\n", command[ 2 ], s, main_or_sub, fps, gops[ 0 ], qualitys[ 0 ], profiles[ 0 ], entropys[ 0 ], modes[ 0 ], bitrates[ 0 ], skips[ 0 ], avgs[ 0 ], aspect_ratios_x[ 0 ], aspect_ratios_y[ 0 ], sar_x, sar_y, resolutions_x[ 0 ], resolutions_y[ 0 ], crop_x[ 0 ], crop_y[ 0 ], crop_w[ 0 ], crop_h[ 0 ]);

					if( E7E90BC718B74429BB9234213955A126( pDevice, command, 11 ) ) {

						p_sys_cfg->n_is_firmware_ready |= 0x00000400;
					}
				}
				if( (p_sys_cfg->n_is_firmware_ready & 0x00000700) == 0x00000700 ) {

					DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };
	
					ULONG main_or_sub = 1;
										
					ULONG sar_x = aspect_ratios_x[ 1 ] * ((resolutions_y[ 1 ] > 0) ? resolutions_y[ 1 ] : cy);
	
					ULONG sar_y = aspect_ratios_y[ 1 ] * ((resolutions_x[ 1 ] > 0) ? resolutions_x[ 1 ] : cx);
	
					if( ((sar_x % 4) == 0) && ((sar_y % 4) == 0) ) { sar_x /= 4; sar_y /= 4; }
	
					if( ((sar_x % 2) == 0) && ((sar_y % 2) == 0) ) { sar_x /= 2; sar_y /= 2; }
	
					if( ((sar_x % 3) == 0) && ((sar_y % 3) == 0) ) { sar_x /= 3; sar_y /= 3; }
	
					if( ((sar_x % 5) == 0) && ((sar_y % 5) == 0) ) { sar_x /= 5; sar_y /= 5; }
	
					command[ 1 ] = 0x0000002D; // MZ0380_CMD_SET_ENC_PARAMS

					command[  2 ] = 0x00003FFF;

					command[ 3 ] = (gops[ 1 ] << 24) | (fps << 16) | (main_or_sub << 8) | (s << 0);
	
					command[ 4 ] = (1 << 24) | (modes[ 1 ] << 16) | (profiles[ 1 ] << 8) | (qualitys[ 1 ] << 0);
	
					command[ 5 ] = (bitrates[ 1 ] << 0);
	
					command[  6 ] = (nals[ 1 ] << 24) | (entropys[ 1 ] << 16) | (avgs[ 1 ] << 8) | (skips[ 1 ] << 0);
	
					command[ 7 ] = (sar_x << 16) | (sar_y << 0);
	
					command[ 8 ] = (resolutions_x[ 1 ] << 16) | (resolutions_y[ 1 ] << 0);

					command[  9 ] = (crop_x[ 1 ] << 16) | (crop_y[ 1 ] << 0);

					command[ 10 ] = (crop_w[ 1 ] << 16) | (crop_h[ 1 ] << 0);

					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "mask = %08X, i = %d, main_or_sub = %d, fps = %d, gop = %d, quality = %d, profile = %d, entropy = %d, mode = %d, bitrate = %d, skip = %d, avg = %d, aspect_ratio = %d.%d.%d.%d, res = %d.%d, crop = %d.%d.%d.%d\n", command[ 2 ], s, main_or_sub, fps, gops[ 1 ], qualitys[ 1 ], profiles[ 1 ], entropys[ 1 ], modes[ 1 ], bitrates[ 1 ], skips[ 1 ], avgs[ 1 ], aspect_ratios_x[ 1 ], aspect_ratios_y[ 1 ], sar_x, sar_y, resolutions_x[ 1 ], resolutions_y[ 1 ], crop_x[ 1 ], crop_y[ 1 ], crop_w[ 1 ], crop_h[ 1 ]);

					if( E7E90BC718B74429BB9234213955A126( pDevice, command, 11 ) ) {
	
						p_sys_cfg->n_is_firmware_ready |= 0x00000800;
					}
				}
				if( (p_sys_cfg->n_is_firmware_ready & 0x00000f00) == 0x00000f00 ) {

					DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

					command[ 1 ] = 0x00000031; // MZ0380_CMD_SET_PRE_PARAMS

					command[ 2 ] = 0x00000003;

					command[ 3 ] = (avgs[ 2 ] << 24) | (skips[ 2 ] << 16) | (fps << 8) | (s << 0);

					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "mask = %08X, i = %d, fps = %d, skip = %d, avg = %d\n", command[ 2 ], s, fps, skips[ 2 ], avgs[ 2 ]);

					if( E7E90BC718B74429BB9234213955A126( pDevice, command, 4 ) ) {

						p_sys_cfg->n_is_firmware_ready |= 0x00001000;
					}
				}
				if( (p_sys_cfg->n_is_firmware_ready & 0x00001f00) == 0x00001f00 ) {

					ULONG line = 0;
					for( line = 0 ; line < 16 ; line++ ) {
	
						pDevice->m_bCustomOsdTextStringRefreshProperty[ i ][ line ] = FALSE;
	
					//	sprintf( (CHAR *)(pDevice->m_pCustomOsdTextStringProperty[ i ][ line ]), "CH%02d $YYY.$M.$D $H:$m:$S.$ss", s + 1 );
					
						ULONG xo =  0;
	
						ULONG yo =  0;
	
						ULONG sz = 10;
	
						if(  pDevice->m_nCustomOsdTextFontSizeProperty[ i ][ line ] != 0xFFFFFFFF ) { sz = pDevice->m_nCustomOsdTextFontSizeProperty[ i ][ line ]; }
	
						if( pDevice->m_nCustomOsdTextPositionXProperty[ i ][ line ] != 0xFFFFFFFF ) { xo = pDevice->m_nCustomOsdTextPositionXProperty[ i ][ line ]; }
	
						if( pDevice->m_nCustomOsdTextPositionYProperty[ i ][ line ] != 0xFFFFFFFF ) { yo = pDevice->m_nCustomOsdTextPositionYProperty[ i ][ line ]; }
	
						BOOL returns = MZ0380_SetOsdString( pDevice, s, line, xo, yo, (CHAR *)(pDevice->m_pCustomOsdTextStringProperty[ i ][ line ]), sz, pDevice->m_nCustomOsdTextColorProperty[ i ][ line ] % 3 );
	
						F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "osd = %d.%d, xo = %d, yo = %d, text = %s, lens = %d, font.size = %d, color = %d (returns = %d)\n", s, line, xo, yo, (CHAR *)(pDevice->m_pCustomOsdTextStringProperty[ i ][ line ]), strlen( (CHAR *)(pDevice->m_pCustomOsdTextStringProperty[ i ][ line ]) ), sz, pDevice->m_nCustomOsdTextColorProperty[ i ][ line ] % 3, returns);
	
						if( returns == FALSE ) {
	
							break ;
						}
					}
				}
			}
			else
			{
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] F640A7ABBB894EFBA34BA5C6FC719D34( ) cx(%d) cy(%d), error !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), cx, cy );
			}
		}
	}
	if( p_sys_cfg->n_is_firmware_ready & 0x0000300 ) {

		DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		command[ 1 ] = 0x00000006; // MZ0380_CMD_START_DMA

		command[ 2 ] = 0xFFFFFFFF;
			
		if( E7E90BC718B74429BB9234213955A126( pDevice, command, 3 ) ) {
			
			p_sys_cfg->b_input_video_signal_changed = FALSE;

			p_sys_cfg->n_is_firmware_ready |= 0x00010000;

			p_sys_cfg->n_is_firmware_just_begin = 1;
		}
	}
	return STATUS_SUCCESS;
}

NTSTATUS A9667F33F6B047908C7FEBD405F891F9( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BOOL THREAD )
{
	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	if( p_sys_cfg->n_is_firmware_ready & 0x00010000 ) {

		if( THREAD == FALSE ) { MZ0380_CLOSE_THREAD(); } 

		ULONG cx = p_sys_cfg->n_input_video_resolution_cx;

		ULONG cy = p_sys_cfg->n_input_video_resolution_cy;

		ULONG fps = p_sys_cfg->n_input_video_resolution_fps;

		ULONG interleaved = p_sys_cfg->n_input_video_resolution_interleaved;

		ULONG is_dual_streams = (pDevice->m_nCustomAnalogVideoSubEncoderEnableProperty && pDevice->m_nCustomAnalogVideo720OutputProperty) ? 2 : 1;
	
		ULONG counts = 1;

		if( (pDevice->iProduct & 0x0F) == 0x02 ||
			
			(pDevice->iProduct & 0x0F) == 0x03 ) {

			if( (pDevice->iManufacturer & 0x0F) == 0x01 ||
				
				(pDevice->iManufacturer & 0x0F) == 0x0B ||
				
				(pDevice->iManufacturer & 0x0F) == 0x0C ) {

				counts = 4;
			}
			else {

				counts = 8;
			}
		}
		if( interleaved ) {

			cy <<= 1;

			fps >>= 1;
		}
		ULONG i = 0;
		for( i = 0 ; i < counts ; i++ ) {

			ULONG line = 0;
			for( line = 0 ; line < 16 ; line++ ) {

				if( pDevice->m_bCustomOsdTextStringRefreshProperty[ i ][ line ] == TRUE ) {

					pDevice->m_bCustomOsdTextStringRefreshProperty[ i ][ line ] = FALSE;

					ULONG  s =  i; if( (pDevice->iProduct & 0x0F) == 0x02 && (pDevice->iManufacturer & 0x0F) == 0x0C ) { s = SC2CC_VIN_MAP[ i ]; }

					ULONG xo =  0;

					ULONG yo =  0;

					ULONG sz = 10;

					if(  pDevice->m_nCustomOsdTextFontSizeProperty[ i ][ line ] != 0xFFFFFFFF ) { sz = pDevice->m_nCustomOsdTextFontSizeProperty[ i ][ line ]; }

					if( pDevice->m_nCustomOsdTextPositionXProperty[ i ][ line ] != 0xFFFFFFFF ) { xo = pDevice->m_nCustomOsdTextPositionXProperty[ i ][ line ]; }

					if( pDevice->m_nCustomOsdTextPositionYProperty[ i ][ line ] != 0xFFFFFFFF ) { yo = pDevice->m_nCustomOsdTextPositionYProperty[ i ][ line ]; }

					BOOL returns = MZ0380_SetOsdString( pDevice, s, line, xo, yo, (CHAR *)(pDevice->m_pCustomOsdTextStringProperty[ i ][ line ]), sz, pDevice->m_nCustomOsdTextColorProperty[ i ][ line ] % 3 );

					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, ">>>>> osd = %d.%d, xo = %d, yo = %d, text = %s, lens = %d, font.size = %d, color = %d (returns = %d) >>>>>\n", s, line, xo, yo, (CHAR *)(pDevice->m_pCustomOsdTextStringProperty[ i ][ line ]), strlen( (CHAR *)(pDevice->m_pCustomOsdTextStringProperty[ i ][ line ]) ), sz, pDevice->m_nCustomOsdTextColorProperty[ i ][ line ] % 3, returns);

					if( returns == FALSE ) {

						break;
					}
				}
			}
		}
		for( i = 0 ; i < counts ; i++ ) { // PREVIEW

			{	ULONG mask = 0x00000000;
					
				if( pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ i + 0 ] & 0x88000000 )      { mask |= 0x00000002; pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ i + 0 ] &= 0x77FFFFFF; }
					
				if( pDevice->m_nCustomAnalogVideoSkipFrameRateProperty[ i + 0 ] & 0x88000000 )     { mask |= 0x00000001; pDevice->m_nCustomAnalogVideoSkipFrameRateProperty[ i + 0 ] &= 0x77FFFFFF; }
					
				if( mask != 0x00000000 ) {

					ULONG avg = (pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ i + 0 ] & 0x77FFFFFF);

					ULONG skip = (pDevice->m_nCustomAnalogVideoSkipFrameRateProperty[ i + 0 ] & 0x77FFFFFF) + (1);

					ULONG s = i; if( (pDevice->iProduct & 0x0F) == 0x02 && (pDevice->iManufacturer & 0x0F) == 0x0C ) { s = SC2CC_VIN_MAP[ i ]; }

					if( skip == 1 ) {
						
						skip = 0;
					}
					if( avg > 0 ) {

						skip = 0;
					}
					if( is_dual_streams == 2 ) {
								
						if( (cx * cy * fps) > (1920 * 1200 * 30) && (interleaved == 0) ) { 

							if( avg > 0 ) { 
						
								if( avg > (fps >> 1) ) {

									avg = (fps >> 1); 
								} 
							}
							else { 
						
								if( skip < 2 ) { 
								
									skip = 2; 
								} 
							}
						}
					}
					{	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

						command[ 1 ] = 0x00000031; // MZ0380_CMD_SET_PRE_PARAMS

						command[ 2 ] = (mask);

						command[ 3 ] = (avg << 24) | (skip << 16) | (fps << 8) | (s << 0);

						F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, ">>>>> mask = %08X, i = %d, fps = %d, skip = %d, avg = %d >>>>>\n", mask, s, fps, skip, avg);

						if( E7E90BC718B74429BB9234213955A126( pDevice, command, 4 ) ) {

							;
						}
						F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "<<<<< mask = %08X, i = %d, fps = %d, skip = %d, avg = %d <<<<<\n", mask, s, fps, skip, avg);
					}
				}
			}
		}

		for( i = 0 ; i < counts ; i++ ) {

			ULONG j = 0;
			for( j = 0 ; j < 16 ; j += 8 ) {

				ULONG mask = 0x00000000;
		
				if( pDevice->m_nCustomEncoderVideoProfileProperty[ i + j ] & 0x88000000 )          { mask |= 0x00000008; pDevice->m_nCustomEncoderVideoProfileProperty[ i + j ] &= 0x77FFFFFF; }
					
				if( pDevice->m_nCustomEncoderVideoEntropyProperty[ i + j ] & 0x88000000 )          { mask |= 0x00000200; pDevice->m_nCustomEncoderVideoEntropyProperty[ i + j ] &= 0x77FFFFFF; }
					
				if( pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i + j ] & 0x88000000 )      { mask |= 0x00000400; pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i + j ] &= 0x77FFFFFF; }

				if( pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ i + j ] & 0x88000000 )     { mask |= 0x00000100; pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ i + j ] &= 0x77FFFFFF; }
					
				if( pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ i + j ] & 0x88000000 )    { mask |= 0x00000080; pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ i + j ] &= 0x77FFFFFF; }
					
				if( pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + j ] & 0x88000000 )      { mask |= 0x00000010; pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + j ] &= 0x77FFFFFF; }
					
				if( pDevice->m_nCustomEncoderVideoBitRateProperty[ i + j ] & 0x88000000 )          { mask |= 0x00000040; pDevice->m_nCustomEncoderVideoBitRateProperty[ i + j ] &= 0x77FFFFFF; }
					
				if( pDevice->m_nAnalogVideoCompressionQualityProperty[ i + j ] & 0x88000000 )      { mask |= 0x00000004; pDevice->m_nAnalogVideoCompressionQualityProperty[ i + j ] &= 0x77FFFFFF; }
					
				if( pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ i + j ] & 0x88000000 ) { mask |= 0x00000002; pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ i + j ] &= 0x77FFFFFF; }
					
				if( pDevice->m_nAnalogVideoCompressionOverrideKeyframeProperty[ i + j ] > 0 )      { mask |= 0x00000020; pDevice->m_nAnalogVideoCompressionOverrideKeyframeProperty[ i + j ] = 0; }

				if( pDevice->m_nCustomEncoderVideoResolutionProperty[ i + j ] & 0x88000000 )	   { mask |= 0x00002800; pDevice->m_nCustomEncoderVideoResolutionProperty[ i + j ] &= 0x77FFFFFF; }

				if( pDevice->m_nCustomEncoderVideoCropProperty[ 0 ][ i + j ] & 0x88000000 )		   { mask |= 0x00002800; pDevice->m_nCustomEncoderVideoCropProperty[ 0 ][ i + j ] &= 0x77FFFFFF; }

				if( pDevice->m_nCustomEncoderVideoCropProperty[ 1 ][ i + j ] & 0x88000000 )		   { mask |= 0x00002800; pDevice->m_nCustomEncoderVideoCropProperty[ 1 ][ i + j ] &= 0x77FFFFFF; }

				if( pDevice->m_nCustomEncoderVideoCropProperty[ 2 ][ i + j ] & 0x88000000 )		   { mask |= 0x00002800; pDevice->m_nCustomEncoderVideoCropProperty[ 2 ][ i + j ] &= 0x77FFFFFF; }

				if( pDevice->m_nCustomEncoderVideoCropProperty[ 3 ][ i + j ] & 0x88000000 )		   { mask |= 0x00002800; pDevice->m_nCustomEncoderVideoCropProperty[ 3 ][ i + j ] &= 0x77FFFFFF; }

				if( mask != 0x00000000 ) {
					
					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] A9667F33F6B047908C7FEBD405F891F9( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

					ULONG deinterlace = pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ i + j ] & 0x77FFFFFF; // 0 = OFF / 1 = ON

					ULONG profile = pDevice->m_nCustomEncoderVideoProfileProperty[ i + j ] & 0x77FFFFFF; // 0 = HIGH PROFILE / 1 = BASELINE / 2 = MAIN PROFILE / 3 = HIGH PROFILE

					ULONG entropy = pDevice->m_nCustomEncoderVideoEntropyProperty[ i + j ] & 0x77FFFFFF; // 0 = CABAC / 1 = CAVLC / 2 = CABAC

					ULONG resolutions_x = (pDevice->m_nCustomEncoderVideoResolutionProperty[ i + j ] & 0x00FFF000) >> 12;

					ULONG resolutions_y = (pDevice->m_nCustomEncoderVideoResolutionProperty[ i + j ] & 0x00000FFF) >> 0;

					ULONG aspect_ratios_x = (pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i + j ] & 0x00FFF000) >> 12; 

					ULONG aspect_ratios_y = (pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i + j ] & 0x00000FFF) >> 0; 

					ULONG avg = pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ i + j ] & 0x77FFFFFF;

					ULONG skip = (pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ i + j ] & 0x77FFFFFF) + (1);

					ULONG mode = pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + j ] & 0x77FFFFFF;

					ULONG bitrate = pDevice->m_nCustomEncoderVideoBitRateProperty[ i + j ] & 0x77FFFFFF;

					ULONG quality = pDevice->m_nAnalogVideoCompressionQualityProperty[ i + j ] & 0x77FFFFFF;

					ULONG gop = pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ i + j ] & 0x77FFFFFF;

					ULONG crop_x = pDevice->m_nCustomEncoderVideoCropProperty[ 0 ][ i + j ] & 0x77FFFFFF;

					ULONG crop_y = pDevice->m_nCustomEncoderVideoCropProperty[ 1 ][ i + j ] & 0x77FFFFFF;

					ULONG crop_w = pDevice->m_nCustomEncoderVideoCropProperty[ 2 ][ i + j ] & 0x77FFFFFF;

					ULONG crop_h = pDevice->m_nCustomEncoderVideoCropProperty[ 3 ][ i + j ] & 0x77FFFFFF;

					ULONG force_key_frame = (mask & 0x00000020) ? 1 : 0;

					ULONG main_or_sub = j / 8;
															
					BOOL is_down_scaling = FALSE;

					ULONG s = i; if( (pDevice->iProduct & 0x0F) == 0x02 && (pDevice->iManufacturer & 0x0F) == 0x0C ) { s = SC2CC_VIN_MAP[ i ]; }

					if( resolutions_x > 0 &&
				
						resolutions_y > 0 ) {

						if( resolutions_x <= cx &&
				
							resolutions_y <= cy ) {

							is_down_scaling = TRUE;
						}
						if( resolutions_x == cx &&
				
							resolutions_y == cy ) {

							is_down_scaling = FALSE;
						}
					}
					if( is_down_scaling == FALSE ) {

						resolutions_x = 0;

						resolutions_y = 0;
					}
					if( resolutions_x == cx &&

						resolutions_y == cy ) {

						resolutions_x = 0;

						resolutions_y = 0;
					}
					{	crop_x &= 0xFFFFFFF0;

						crop_w &= 0xFFFFFFFE;

						if( crop_w > 0 && crop_w < 128 ) { crop_w = 128; }

						if( crop_h > 0 && crop_h <  64 ) { crop_h =  64; }
					}
					if( (crop_x >= cx) || 
					
					    (crop_y >= cy) ) {
	
						crop_x = 0;
						
						crop_y = 0;
						
						crop_w = 0;
						
						crop_h = 0;
					}
					else if( ((crop_x + crop_w) > cx) ||
					
							 ((crop_y + crop_h) > cy) ) {
	
						crop_x = 0;
						
						crop_y = 0;						
						
						crop_w = 0;
						
						crop_h = 0;
					}
					else if( (crop_w == 0) ||
				
							 (crop_h == 0) ) {

						crop_x = 0;
					
						crop_y = 0;						
					
						crop_w = 0;
					
						crop_h = 0;
					}
					else{
	
						;
					}
					if( resolutions_x > 0 &&

						resolutions_y > 0 &&

						cx > 0 &&

						cy > 0 ) {

						crop_x *= resolutions_x; crop_x /= cx;

						crop_y *= resolutions_y; crop_y /= cy;

						crop_w *= resolutions_x; crop_w /= cx;

						crop_h *= resolutions_y; crop_h /= cy;
					}
					if( skip == 1 ) {
						
						skip = 0;
					}
					if( avg > 0 ) {

						skip = 0;
					}
					if( is_dual_streams == 2 ) {

						if( (cx * cy * fps) > (1920 * 1200 * 30) && (interleaved == 0) ) { 

							if( avg > 0 ) { 
						
								if( avg > (fps >> 1) ) {

									avg = (fps >> 1); 
								} 
							}
							else { 
						
								if( skip < 2 ) { 
								
									skip = 2; 
								} 
							}
						}
//						if( main_or_sub == 0 ) {
//
//							resolutions_x = 0;
//
//							resolutions_y = 0;
//						}
					}
//					{	quality *= 51;
//
//						quality /= 10000;
//
//						if( quality > 51 ) { quality = 51; }
//
//						quality = 51 - quality;
//					}
					{	quality /= 250; // QP RANGE: 8 ~ 48

						if( quality > 40 ) { quality = 40; }

						quality = (40 - quality) + 8;
					}
					{	DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

						ULONG sar_x = aspect_ratios_x * ((resolutions_y > 0) ? resolutions_y : cy);

						ULONG sar_y = aspect_ratios_y * ((resolutions_x > 0) ? resolutions_x : cx);

						if( ((sar_x % 4) == 0) && ((sar_y % 4) == 0) ) { sar_x /= 4; sar_y /= 4; }

						if( ((sar_x % 2) == 0) && ((sar_y % 2) == 0) ) { sar_x /= 2; sar_y /= 2; }

						if( ((sar_x % 3) == 0) && ((sar_y % 3) == 0) ) { sar_x /= 3; sar_y /= 3; }

						if( ((sar_x % 5) == 0) && ((sar_y % 5) == 0) ) { sar_x /= 5; sar_y /= 5; }

						command[ 1 ] = 0x0000002D; // MZ0380_CMD_SET_ENC_PARAMS

						command[ 2 ] = (mask);

						command[ 3 ] = (gop << 24) | (fps << 16) | (main_or_sub << 8) | (s << 0);

						command[ 4 ] = (force_key_frame << 24) | (mode << 16) | (profile << 8) | (quality << 0);

						command[ 5 ] = (bitrate << 0);

						command[  6 ] = (0 << 24) | (entropy << 16) | (avg << 8) | (skip << 0); // NAL 參數暫時不支持動態開關

						command[ 7 ] = (sar_x << 16) | (sar_y << 0);

					//	command[ 8 ] = (0 << 16) | (0 << 0);

						command[ 8 ] = (resolutions_x << 16) | (resolutions_y << 0);

						command[  9 ] = (crop_x << 16) | (crop_y << 0);

						command[ 10 ] = (crop_w << 16) | (crop_h << 0);

//						if( (pDevice->iProduct & 0x0F) == 0x02 && (pDevice->iManufacturer & 0x0F) == 0x0C ) {
//								
//							command[ 8 ] = (resolutions_x << 16) | (resolutions_y << 0);
//						}
//						else {
//							
//							command[ 8 ] = (0 << 16) | (0 << 0);
//						}
						F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, ">>>>> mask = %08X, i = %d, main_or_sub = %d, fps = %d, gop = %d, quality = %d, profile = %d, entropy = %d, mode = %d, force_key_frame = %d, bitrate = %d, skip = %d, avg = %d, aspect_ratio = %d.%d.%d.%d, res = %d.%d, crop = %d.%d.%d.%d >>>>>\n", mask, s, main_or_sub, fps, gop, quality, profile, entropy, mode, force_key_frame, bitrate, skip, avg, aspect_ratios_x, aspect_ratios_y, sar_x, sar_y, resolutions_x, resolutions_y, crop_x, crop_y, crop_w, crop_h);

						if( E7E90BC718B74429BB9234213955A126( pDevice, command, 11 ) ) {

							;
						}
						F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "<<<<< mask = %08X, i = %d, main_or_sub = %d, fps = %d, gop = %d, quality = %d, profile = %d, entropy = %d, mode = %d, force_key_frame = %d, bitrate = %d, skip = %d, avg = %d, aspect_ratio = %d.%d.%d.%d, res = %d.%d, crop = %d.%d.%d.%d <<<<<\n", mask, s, main_or_sub, fps, gop, quality, profile, entropy, mode, force_key_frame, bitrate, skip, avg, aspect_ratios_x, aspect_ratios_y, sar_x, sar_y, resolutions_x, resolutions_y, crop_x, crop_y, crop_w, crop_h);
					}
				}
			}
		}
		if( THREAD == FALSE ) { MZ0380_START_THREAD(); }
	}
	return STATUS_SUCCESS;
}

NTSTATUS D443ECD5E9B94AC5B04BB7489B656CAD( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{	
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] D443ECD5E9B94AC5B04BB7489B656CAD() Reference(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 );

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0 ) {

		pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2++;

	}
	else { 
		
		pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 = 1;
	}

	pDevice->m_nAnalogCopyProtMacrovisionEnableProperty = 0;

#ifdef MZ0380_COPYPORTECT_ARCHITECTURE

	if( FD0AC55FE0C0B45a788FEC199C5758F1E[ 0 ] == 0 ) { return STATUS_SUCCESS; }

	if( F6053D464C87D41c1B8CBE8A39FCDF2D2[ 0 ] == 0 ) { return STATUS_SUCCESS; }

#endif

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 == 1 ) {

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] D443ECD5E9B94AC5B04BB7489B656CAD()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

		MZ0380_CLOSE_THREAD();

		pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = 0x00000001;//enable ISR

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 0 ] = 0;

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] = 0;

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ] = 0;

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 3 ] = 0;

		ULONG status = pDevice->m_nAnalogVideoDecoderStatusProperty;

		ULONG hdcp = pDevice->m_nAnalogCopyProtMacrovisionProperty;

		if( (pDevice->iProduct == 0x1C && pDevice->iManufacturer == 0xFA) ||  // ELGATO BOARD
			(pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x03) ||  // ELGATO BOARD
			(pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x05) ) { // ELGATO BOARD

#ifdef AME_MZ0380

			MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

			//p_sys_cfg->o_input_ite6612.HDMITxTimer( RES_NO_SIGNAL );

			BYTE R00AB = E6FB1249C1F642A38BC0228741149CD8_EX( pDevice, 0x00, 0x9C, 0x00, 0xAB ) & 0x7F;

			DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x00, 0xAB, R00AB | 0x80 ); // BLANK.OUTPUT

			DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x02, 0x27, 0xFF ); // MUTE AUDIO

			DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x00, 0xB3, 0xFF ); // TRI-STATE

			DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x01, 0x24, 0x41 ); // DISABLE HDCP

			DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x01, 0x25, 0x00 );

			DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x01, 0x26, 0x00 );

			int i = 0;
			for( i = 0 ; i < 5 ; i++ ) {

				DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x01, 0x27, 0x00 );
			}
			DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x00, 0xAB, R00AB ); // NORMAL.OUTPUT

			DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x02, 0x27, 0x00 ); // UNMUTE AUDIO

			DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x00, 0xB3, 0x00 ); // NORMAL-STATE

#if 1 // DANIEL, MOZART, WAIT UNTIL HDMI SIGNAL STABLE

			for( i = 0 ; i < 10 ; i++ ) {
			
				BYTE hdmi_err1;

				hdmi_err1 = E6FB1249C1F642A38BC0228741149CD8_EX( pDevice, 0x00, 0x9C, 0x02, 0x0E );
				
				if( (hdmi_err1 & 0x07) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[A] [%d]\n", i ); break; } 

				F6B9E557A4BA24ffd926B820B836289C8_100NS( 50000 );
			}
			for( i = 0 ; i < 500 ; i++ ) {

				BYTE hdmi_err1 = E6FB1249C1F642A38BC0228741149CD8_EX( pDevice, 0x00, 0x9C, 0x02, 0x0E );
		
				DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x02, 0x0E, hdmi_err1 );
				
				if( (hdmi_err1 & 0x07) == 0x00 ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[B] [%d]\n", i ); break; }

				F6B9E557A4BA24ffd926B820B836289C8_100NS( 50000 );
			}
#endif
//			p_sys_cfg->o_input_ite6612.HDMITxTimer( p_sys_cfg->n_TvMode ); // SPEED UP
#endif
		}
		MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		F640A7ABBB894EFBA34BA5C6FC719D34( pDevice );

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 3 ] = 1;

		MZ0380_START_THREAD();
	}
	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 1 ) {

		A9667F33F6B047908C7FEBD405F891F9( pDevice, FALSE );
	}
	// ...

	// ...

	// ...

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "<-------------------------------------------------------------------------------------- START [%d]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

	return STATUS_SUCCESS;
}
extern BYTE MST3367_HDCP_KEY[ 6 ];

NTSTATUS C823B90222FD455CB0C3A8BA17ADF490( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "--------------------------------------------------------------------------------------> STOP [%d] Reference(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 );

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 == 0 ) return STATUS_SUCCESS;
	
	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 1 ) {

		pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2--;

		return STATUS_SUCCESS;
	}
	pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 = 0;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] C823B90222FD455CB0C3A8BA17ADF490()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

	MZ0380_CLOSE_THREAD();

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 0 ] = 0;

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] = 0;

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ] = 0;

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 3 ] = 0;

	BCBB6F46096343FA8AD2A9FF89F84A73( pDevice );

	pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = 0x00000000;//disable ISR

	if( (pDevice->iProduct == 0x1C && pDevice->iManufacturer == 0xFA) ||  // ELGATO BOARD
		(pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x03) ||  // ELGATO BOARD
		(pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x05) ) { // ELGATO BOARD
				
#ifdef AME_MZ0380

		MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		//p_sys_cfg->o_input_ite6612.HDMITxTimer( RES_NO_SIGNAL );

		BYTE R00AB = E6FB1249C1F642A38BC0228741149CD8_EX( pDevice, 0x00, 0x9C, 0x00, 0xAB ) & 0x7F;

		DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x00, 0xAB, R00AB | 0x80 ); // BLANK.OUTPUT

		DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x02, 0x27, 0xFF ); // MUTE AUDIO

		DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x00, 0xB3, 0xFF ); // TRI-STATE

		DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x01, 0x24, 0x40 ); // ENABLE HDCP

		DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x01, 0x25, 0x00 );

		DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x01, 0x26, 0x00 );

		int i = 0;
		for( i = 0 ; i < 5 ; i++ ) {

			DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x01, 0x27, MST3367_HDCP_KEY[ i ] );
		}
		DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x00, 0xAB, R00AB ); // NORMAL.OUTPUT

		DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x02, 0x27, 0x00 ); // UNMUTE AUDIO

		DBF051EEA3B648B49859145F02FA268C_EX( pDevice, 0x00, 0x9C, 0x00, 0xB3, 0x00 ); // NORMAL-STATE

	//	p_sys_cfg->o_input_ite6612.HDMITxTimer( p_sys_cfg->n_TvMode ); // SPEED UP
#endif
	}

/*	if( pDevice->iManufacturer == 0x51 ||
						
		pDevice->iManufacturer == 0xC1 ) {

		DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, NVP6124_ADDR, 0xFF, 0x00 );

		for( ULONG i = 0 ; i < 256 ; i++ ) {
				
			DbgPrint( "F7F93DF8A9ECE49c1884C75ADC18648B7#0: REG%02X = %02X\n", i, E6FB1249C1F642A38BC0228741149CD8( pDevice, 0x00, NVP6124_ADDR, (BYTE)(i) ) );
	}
		DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, NVP6124_ADDR, 0xFF, 0x05 );

		for( ULONG i = 0 ; i < 256 ; i++ ) {
				
			DbgPrint( "F7F93DF8A9ECE49c1884C75ADC18648B7#5: REG%02X = %02X\n", i, E6FB1249C1F642A38BC0228741149CD8( pDevice, 0x00, NVP6124_ADDR, (BYTE)(i) ) );
		}
	}
*/
	MZ0380_START_THREAD();

	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

//	if( pDevice->m_nCustomAnalogVideoMultiSyncChannels > 1 && p_brother_sys_cfg == NULL ) { // 主頻道
//		
//		ULONG nums = pDevice->m_nCustomAnalogVideoMultiSyncChannels - 1;
	/*
	if( p_sys_cfg->n_output_multi_sync_channels > 1 && p_brother_sys_cfg == NULL ) { // 主頻道
		
		ULONG nums = p_sys_cfg->n_output_multi_sync_channels - 1;

		p_sys_cfg->n_output_multi_sync_channels = 0;

		for( ULONG n = 0 ; n < nums ; n++ ) {

			F42A18AF66EFF459eA332CA253FFF8A65 * p_brother_device = g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + n + 1 ];

			if( p_brother_device ) {

				C823B90222FD455CB0C3A8BA17ADF490( p_brother_device, p_sys_cfg );
			}
		}
	}
	*/
	// ...

	// ...

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "<-------------------------------------------------------------------------------------- STOP [%d]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

	return MZ0380_PowerDownPeripherals( pDevice );
}

NTSTATUS MZ0380_PowerDownPeripherals( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "MZ0380_PowerDownPeripherals()\n");

	return true;
}

NTSTATUS B3D587196B7142738A7C4142C2E5459C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	NTSTATUS status = STATUS_SUCCESS;

	if( (pDevice->idVendor == 0x0907 && (pDevice->idProduct & 0xFFFF) == 0x0100) ||
		(pDevice->idVendor == 0x12AB && (pDevice->idProduct & 0xFFFF) == 0x0370) ||
		(pDevice->idVendor == 0x12AB && (pDevice->idProduct & 0xFFFF) == 0x0380) ) {

		;
	}
	else { 
		
		MZ0380_START_THREAD();

		return STATUS_UNSUCCESSFUL;
	}
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] B3D587196B7142738A7C4142C2E5459C()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

	pDevice->m_pCustomSystemConfigProperty = (MZ0380_SYS_CFG *)wrapper_kmalloc( sizeof(MZ0380_SYS_CFG), GFP_KERNEL );

	memset( pDevice->m_pCustomSystemConfigProperty, 0, sizeof(MZ0380_SYS_CFG) );

	MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	ULONG nBufferLength;

	//IoGetDeviceProperty( pDevice->m_pPDO, DevicePropertyBusNumber, sizeof(ULONG), &nDevicePropertyBusNumber, &nBufferLength );

	//pDevice->FF362AA37F7D046bf90568AC1600626D9 = nDevicePropertyBusNumber % 16;

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "B3D587196B7142738A7C4142C2E5459C( %d, %d )\n", pDevice->FF362AA37F7D046bf90568AC1600626D9, pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "B3D587196B7142738A7C4142C2E5459C( %d, %04X%02X%02X )\n", pDevice->FF362AA37F7D046bf90568AC1600626D9, pDevice->bcdDevice, pDevice->iProduct, pDevice->iManufacturer);

	g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ] = pDevice;

	BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 1, 0x000000DC, 0x00000002 ); // CLR INTERRUT

	BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 0, 0x00000030, 0x00000000 ); // CLR INTERRUT

	BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 0, 0x00000000, 0x00000400 ); // CLR INTERRUT 

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] B3D587196B7142738A7C4142C2E5459C() 1\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

	wrapper_init_waitqueue_head( &pDevice->m_wait_queue_head );

	pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = 0x00000001;//ready for ISR

	p_sys_cfg->n_is_firmware_ready = 0x00000000;

	p_sys_cfg->n_firmware_timeouts = 0;


	ULONG i = 0;
	for( i = 0 ; i < 100 ; i++ ) {

		DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		command[ 1 ] = 0x00000001; // MZ0380_CMD_GET_FIRMWARE_READY (EP)

		if( B601B66F1570418A9F5091D6133C37B8( pDevice, command, 2, TRUE, 5000000 ) == TRUE ) {

			p_sys_cfg->n_is_firmware_ready |= 0x00000001;

			break ;
		}
	}
	BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 1, 0x000000DC, 0x00000002 ); // CLR INTERRUT

	BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 0, 0x00000030, 0x00000000 ); // CLR INTERRUT

	BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 0, 0x00000000, 0x00000400 ); // CLR INTERRUT 

	if( p_sys_cfg->n_is_firmware_ready == 0x00000000 ) {
		
		MZ0380_START_THREAD();

		return MZ0380_PowerDownPeripherals( pDevice );
	}

	// ... MZ0380_CMD_GET_FIRMWARE_READY (AP)


	// FIRMWARE UPDATE
	//
	BYTE bMajorVersion = 0;

	BYTE bMinorVersion = 0;

	BOOL returns = FALSE;

	if( (pDevice->idVendor == 0x12AB && (pDevice->idProduct & 0xFFFF) == 0x0370) ) {

		returns = AB1E68ACD056481BB880D29E744FB86E( pDevice, "MZ0370.FW.TXT", &bMajorVersion, &bMinorVersion );
	}
	else {

		returns = AB1E68ACD056481BB880D29E744FB86E( pDevice, "MZ0380.FW.TXT", &bMajorVersion, &bMinorVersion );
	}
	if( returns ) {
		
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "FIRMWARE VERSION: %d.%d\n", bMajorVersion, bMinorVersion);

		DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		command[ 1 ] = 0x0000000A; // MZ0380_CMD_GET_FIRMWARE_VERSION

		command[ 2 ] = 0x00000000;

		command[ 3 ] = 0x00000000;

		p_sys_cfg->n_firmware_major_version = bMajorVersion;

		p_sys_cfg->n_firmware_minor_version = bMinorVersion;
		
		BOOL returns = FALSE;
		
		ULONG i = 0;
		for( i = 0 ; i < 100 ; i++ ) {

			returns = E7E90BC718B74429BB9234213955A126( pDevice, command, 4 );

			if( returns == TRUE ) {

				ULONG R = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 11) );
	
				if( R == 0xAAAAAAAA ) {

					break ;
				}
				F6B9E557A4BA24ffd926B820B836289C8_100NS( 100000 );
			}
		}
		if( returns ) {

			F6B9E557A4BA24ffd926B820B836289C8_100NS( 1000000 );

			ULONG R00000008 = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 2) );

			ULONG R0000000C = A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 3) );

			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "BOARD VERSION: %d.%d / %d.%d", A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 2) ), A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 3) ), R00000008, R0000000C);

			
			p_sys_cfg->n_board_major_version = R00000008;

			p_sys_cfg->n_board_minor_version = R0000000C;

			if( A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 2) ) != bMajorVersion ||

				A350149D4A8740248A2A95D637054F72( pDevice, 0, (0x00000004 * 3) ) != bMinorVersion ) {

				BOOL is_sd_product = FALSE;

				if( (pDevice->iProduct & 0x0F) == 0x02 ||  // 960H & D1
		
					(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1

					is_sd_product = TRUE;
				}	
				if( (pDevice->iProduct == 0x1C && pDevice->iManufacturer == 0xFA) ||  // ELGATO BOARD
					(pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x03) ||  // ELGATO BOARD
					(pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x05) ) { // ELGATO BOARD

					is_sd_product = FALSE;
				}
				BOOL returns = FALSE;

				if( (pDevice->idVendor == 0x12AB && (pDevice->idProduct & 0xFFFF) == 0x0370) ) {

					returns = D6ED2B9CD102472FA9C3586A7F21613D( pDevice, (is_sd_product) ? "MZ0370.SD.HEX" : "MZ0370.HD.HEX" );
				}
				else {
					
					returns = D6ED2B9CD102472FA9C3586A7F21613D( pDevice, (is_sd_product) ? "MZ0380.SD.HEX" : "MZ0380.HD.HEX" );
				}
				if( returns ) {

					MZ0380_START_THREAD(); // 需要重新開機
					
					return MZ0380_PowerDownPeripherals( pDevice );
				}
			}
		}
	}

	BOOL is_sc550_product = FALSE;

	if( pDevice->idProduct == 0x0370 ) {

		is_sc550_product = TRUE;
	}
	if( ((pDevice->iProduct & 0x0F) == 0x02 && (pDevice->iManufacturer & 0x0F) == 0x0A) ||	// 960H
	
		((pDevice->iProduct & 0x0F) == 0x03 && (pDevice->iManufacturer & 0x0F) == 0x0A) ) { // 960H

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] B3D587196B7142738A7C4142C2E5459C() is_sc550_product(%d)  iProduct &0x0F) == 0x02, 0x03 iManufacturer & 0x0F) == 0x0A\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, is_sc550_product );
		
		//PHYSICAL_ADDRESS memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D;
		ULONG i = 0;
		for( i = 0 ; i < 8 ; i++ ) {

			UINT memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i ];
		
			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000002; // MZ0380_CMD_SET_PREVIEW_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 4 ] =0; 

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 6 ] = 0; 

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 8 ] = 0; 

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 10 ] = 0; 

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000010;
			}
		}

		UINT memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 8 ];

		for( i = 0 ; i < 8 ; i++ ) {

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000003; // MZ0380_CMD_SET_AUDIO_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = 4096;

			command[ 4 ] = 0; 

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			command[ 6 ] = 0; 

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			command[ 8 ] = 0; 

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			command[ 10 ] = 0; 

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000020;
			}
		}

		for( i = 0 ; i < 8 ; i++ ) {

			UINT memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i + 16 ];

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000004; // MZ0380_CMD_SET_MAIN_ENCODER_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = (is_sc550_product) ? 0x00000000 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 4 ] = 0; 

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0x00000000 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 6 ] = 0; 

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0x00000000 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 8 ] = 0; 

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0x00000000 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 10 ] = 0; 

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000040;
			}
		}

		//this is a fake, correct way is to enable below 
		p_sys_cfg->n_is_firmware_ready |= 0x00000080;
		/*
		for( i = 0 ; i < 8 ; i++ ) {

			UINT memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i + 24 ];

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000005; // MZ0380_CMD_SET_SUB_ENCODER_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = (is_sc550_product) ? 0x00000000 : 0x00032B00;

			command[ 4 ] = 0; 

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0x00000000 : 0x00032B00;

			command[ 6 ] = 0; 

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0x00000000 : 0x00032B00;

			command[ 8 ] = 0; 

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0x00000000 : 0x00032B00;

			command[ 10 ] = 0; 

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000080;
			}
		}
		*/
	}

	else if( ((pDevice->iProduct & 0x0F) == 0x02 && (pDevice->iManufacturer & 0x0F) == 0x0C) ||	// 960H
	
			((pDevice->iProduct & 0x0F) == 0x03 && (pDevice->iManufacturer & 0x0F) == 0x0B) ) { // 960H
		
		//PHYSICAL_ADDRESS memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D;
		ULONG i = 0;
		for( i = 0 ; i < 4 ; i++ ) {

			UINT memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i ];
		
			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000002; // MZ0380_CMD_SET_PREVIEW_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 4 ] =0; 

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 6 ] = 0; 

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 8 ] = 0; 

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 10 ] = 0; 

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000010;
			}
		}

		UINT memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 8 ];

		for( i = 0 ; i < 4 ; i++ ) {

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000003; // MZ0380_CMD_SET_AUDIO_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = 4096;

			command[ 4 ] = 0; 

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			command[ 6 ] = 0; 

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			command[ 8 ] = 0; 

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			command[ 10 ] = 0; 

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000020;
			}
		}

		for( i = 0 ; i < 4 ; i++ ) {

			UINT memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i + 16 ];

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000004; // MZ0380_CMD_SET_MAIN_ENCODER_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 4 ] = 0; 

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 6 ] = 0; 

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 8 ] = 0; 

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0 : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

			command[ 10 ] = 0; 

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000040;
			}
		}

		//this is a fake, correct way is to enable below 
		p_sys_cfg->n_is_firmware_ready |= 0x00000080;

		/*
		for( i = 0 ; i < 4 ; i++ ) {

			UINT memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i + 24 ];

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000005; // MZ0380_CMD_SET_SUB_ENCODER_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = 0x00032B00;

			command[ 4 ] = 0; 

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 0x00032B00;

			command[ 6 ] = 0; 

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 0x00032B00;

			command[ 8 ] = 0; 

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 0x00032B00;

			command[ 10 ] = 0; 

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000080;
			}
		}
		*/
	}
	else if( (pDevice->iProduct & 0x0F) == 0x02 ||  //
		
			 (pDevice->iProduct & 0x0F) == 0x03 ) { //

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "should never enter here ??????? \n" );

		ULONG i = 0;
		for( i = 0 ; i < 8 ; i++ ) {

			UINT memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i ];

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000002; // MZ0380_CMD_SET_PREVIEW_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = 0x000CA900; 

			command[ 4 ] = 0; 

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 0x000CA900;

			command[ 6 ] = 0; 

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 0x000CA900;

			command[ 8 ] = 0; 

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 0x000CA900;

			command[ 10 ] = 0; 

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000010;
			}
		}

		UINT memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 8 ];

		for( i = 0 ; i < 8 ; i++ ) {

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000003; // MZ0380_CMD_SET_AUDIO_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = 4096; 

			command[ 4 ] = 0; 

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;
	
			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			command[ 6 ] = 0; 

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;
	
			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			command[ 8 ] = 0; 

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;
	
			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			command[ 10 ] = 0; 

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000020;
			}

		}

		for( i = 0 ; i < 8 ; i++ ) {

			UINT memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i + 16 ];

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000004; // MZ0380_CMD_SET_MAIN_ENCODER_BUFFER

			command[ 2 ] = i;

			command[ 3 ] =(is_sc550_product) ? 0x00000000 : 0x000CA900; 

			command[ 4 ] = 0;

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0x00000000 : 0x000CA900;

			command[ 6 ] = 0;

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0x00000000 : 0x000CA900;

			command[ 8 ] = 0;

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0x00000000 : 0x000CA900;

			command[ 10 ] = 0;

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000040;
			}
		}

		for( i = 0 ; i < 8 ; i++ ) {

			UINT memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i + 24 ];

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000005; // MZ0380_CMD_SET_SUB_ENCODER_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = (is_sc550_product) ? 0x00000000 : 0x00026100; 

			command[ 4 ] = 0; 

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0x00000000 : 0x00026100;

			command[ 6 ] = 0; 

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0x00000000 : 0x00026100;

			command[ 8 ] = 0; 

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += (is_sc550_product) ? 0x00000000 : 0x00026100;

			command[ 10 ] = 0; 

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000080;
			}
		}

	}
	else { // HD

		dma_addr_t memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 0 ];

		ULONG i = 0;
		for( i = 0 ; i < 1 ; i++ ) {

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000002; // MZ0380_CMD_SET_PREVIEW_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = (is_sc550_product) ? MZ0380_MAX_VIDEO_DMA_BUFFER_SIZE : MZ0380_HD_VIDEO_DMA_BUFFER_SIZE; 

			command[ 4 ] = 0;

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 1 ];

			command[ 6 ] = 0;

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 2 ];

			command[ 8 ] = 0;

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 3 ];

			command[ 10 ] = 0;

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000010;
			}
		}

		memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 4 ];

		for( i = 0 ; i < 1 ; i++ ) {

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000003; // MZ0380_CMD_SET_AUDIO_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = 4096;

			command[ 4 ] = 0;

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			command[ 6 ] = 0;

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			command[ 8 ] = 0;

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 += 4096;

			command[ 10 ] = 0;

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000020;
			}
		}

		memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 5 ];
			
		for( i = 0 ; i < 1 ; i++ ) {

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000004; // MZ0380_CMD_SET_MAIN_ENCODER_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = (is_sc550_product) ? 0x00000000 : MZ0380_HD_VIDEO_DMA_BUFFER_SIZE;

			command[ 4 ] = 0;

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 6 ];
	
			command[ 6 ] = 0;

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 7 ];

			command[ 8 ] = 0;

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 8 ];

			command[ 10 ] = 0;

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000040;
			}
		}
		//this is a fake, correct way is to enable below 
		p_sys_cfg->n_is_firmware_ready |= 0x00000080;

		/*
		memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 9 ];
			
		for( i = 0 ; i < 1 ; i++ ) {

			DWORD command[ 12 ] = { 0x00000800, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

			command[ 1 ] = 0x00000005; // MZ0380_CMD_SET_SUB_ENCODER_BUFFER

			command[ 2 ] = i;

			command[ 3 ] = 0x000D3000;

			command[ 4 ] = 0;

			command[ 5 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 10 ];

			command[ 6 ] = 0;

			command[ 7 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 11 ];

			command[ 8 ] = 0;

			command[ 9 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 12 ];

			command[ 10 ] = 0;

			command[ 11 ] = memory_F6F32B5439E4C42f095E08326DFA73107;

			if( E7E90BC718B74429BB9234213955A126( pDevice, command, 12 ) ) {

				p_sys_cfg->n_is_firmware_ready |= 0x00000080;
			}
		}
		*/
	}
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "B3D587196B7142738A7C4142C2E5459C( %04X%02X%02X )\n", pDevice->bcdDevice, pDevice->iProduct, pDevice->iManufacturer);

	if( (pDevice->iProduct & 0x0F) == 0x02 ||  // 960H & D1 
		
		(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1 

		F67AC086BDA7447FB39DC135EB20D85D( pDevice,  9, 0 ); //
	}
	else { // HD

		F67AC086BDA7447FB39DC135EB20D85D( pDevice,  1, 0 ); // HPD0.CTRL

		F67AC086BDA7447FB39DC135EB20D85D( pDevice,  2, 0 ); // HDMI.MPU.WE

		F67AC086BDA7447FB39DC135EB20D85D( pDevice,  8, 0 ); // VID.SEL

		F67AC086BDA7447FB39DC135EB20D85D( pDevice,  9, 0 ); //

		F67AC086BDA7447FB39DC135EB20D85D( pDevice, 10, 0 ); // I2S.SEL

		F67AC086BDA7447FB39DC135EB20D85D( pDevice, 11, 0 ); // I2S.TRI

		if( pDevice->iManufacturer == 0xC6 ) { // AERO.SDI (CH03)
			
			F67AC086BDA7447FB39DC135EB20D85D( pDevice,  3, 0 ); // INPUT SWITCH
		}
	}
	if( pDevice->iManufacturer == 0x51 ||
		
		pDevice->iManufacturer == 0xC1 ) {

		D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

		D8735A9140EC43B888E108661E19175A( pDevice, 9, 0 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 ); // ACTIVE LOW

		D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

		p_sys_cfg->b_is_techpoint_support = FALSE;
			
		BYTE RFE = E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x88, 0xFE );
	
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[TECHPOINT] [RFE = %02X]\n", RFE);

		if( RFE == 0x28 ) {

			BYTE RFF = E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x88, 0xFF );

			BYTE RFD = E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x88, 0xFD );
			
			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[TECHPOINT] [RFF = %02X, RFD = %02X]\n", RFF, RFD);

			if( RFF == 0x24 && 
				
				RFD == 0x00 ) { // TP2834 = 0x2400
					
				p_sys_cfg->b_is_techpoint_support = TRUE;
			}
		}
		/*
		pDevice->m_nAnalogVideoProcAmpBrightnessProperty[ 0 ] |= 0x08000000;
	
		pDevice->m_nAnalogVideoProcAmpContrastProperty[ 0 ] |= 0x08000000;
	
		pDevice->m_nAnalogVideoProcAmpHueProperty[ 0 ] |= 0x08000000;
	
		pDevice->m_nAnalogVideoProcAmpSaturationProperty[ 0 ] |= 0x08000000;
	
		pDevice->m_nAnalogVideoProcAmpSharpnessProperty[ 0 ] |= 0x08000000;
		*/
	}
	if( pDevice->iManufacturer == 0x52 ||
		
		pDevice->iManufacturer == 0xC2 ) {
		/*
		pDevice->m_nAnalogVideoProcAmpBrightnessProperty[ 0 ] |= 0x08000000;
	
		pDevice->m_nAnalogVideoProcAmpContrastProperty[ 0 ] |= 0x08000000;
	
		pDevice->m_nAnalogVideoProcAmpHueProperty[ 0 ] |= 0x08000000;
	
		pDevice->m_nAnalogVideoProcAmpSaturationProperty[ 0 ] |= 0x08000000;
	
		pDevice->m_nAnalogVideoProcAmpSharpnessProperty[ 0 ] |= 0x08000000;
		*/
	}
	if( pDevice->iManufacturer == 0xCB ||

		pDevice->iManufacturer == 0xC6 ) {

		D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

		D8735A9140EC43B888E108661E19175A( pDevice, 9, 0 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 ); // ACTIVE LOW

		D8735A9140EC43B888E108661E19175A( pDevice, 9, 1 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 );

		BYTE CPLD_R02 = E6FB1249C1F642A38BC0228741149CD8( pDevice, 0x00, 0x9A, 0x02 );

		if( (CPLD_R02 & 0xFF) == 0x12 ) {

			p_sys_cfg->m_b_is_vbi_fpga_support = TRUE;
		}
		else if( (CPLD_R02 & 0xFF) == 0x11 ) {

			p_sys_cfg->m_b_is_vbi_fpga_support = TRUE;
		}
		else {
			
			p_sys_cfg->m_b_is_vbi_fpga_support = FALSE;
		}
	}

	//E8FFA7FBB87647EDA2877C2FAC2B2F1C( pDevice, pDevice->m_nAnalogCrossbarVideoInputProperty, pDevice->m_nAnalogCrossbarVideoOutputProperty, pDevice->m_nAnalogCrossbarAudioInputProperty, pDevice->m_nAnalogCrossbarAudioOutputProperty, TRUE );
	
	//must before crossbar
	pDevice->m_nCustomAnalogVideo720OutputProperty = 1;

	E8FFA7FBB87647EDA2877C2FAC2B2F1C( pDevice, pDevice->m_nAnalogCrossbarVideoInputProperty, 0, pDevice->m_nAnalogCrossbarAudioInputProperty, 0, TRUE );

	ADF0B0E919E0488A9DECD29D67A7F9A8( pDevice, NULL, TRUE );

	//init all parameter here
	for( i = 0; i < 16; i++)
	{
		pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ i ] = 1;

		pDevice->m_nCustomAnalogVideoSkipFrameRateProperty[ i ] = 0;
		pDevice->m_nCustomAnalogVideoAvgFrameRateProperty[ i ] = 0;
	}

	for( i = 0; i < 32; i++)
	{
		pDevice->m_nCustomEncoderVideoProfileProperty[ i ] = V4L2_MPEG_VIDEO_H264_PROFILE_MAIN;

		pDevice->m_nCustomEncoderVideoEntropyProperty[ i ] = 0;

		pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i ] = 0;

		pDevice->m_nCustomEncoderVideoResolutionProperty[ i ] = 0;

		pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ i ] = 0;

		pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ i ] = 0;

		pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i ] = 0;

		pDevice->m_nAnalogVideoCompressionQualityProperty[ i ] = 6000; 

		pDevice->m_nCustomEncoderVideoBitRateProperty[ i ] = 4000000; 

		pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ i ] = 30; 

	}

	for( i = 0; i < 32; i++)
	{
		int j = 0;
		for( j = 0; j < 16; j++)
		{
			pDevice->m_bCustomOsdTextStringRefreshProperty[ i ][ j ] = 0;

			pDevice->m_nCustomOsdTextColorProperty[ i ][ j ] = 1;

			pDevice->m_nCustomOsdTextFontSizeProperty[ i ][ j ] = 10;
		}
	}

	
	MZ0380_START_THREAD();

	pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = 0x00000000;//disable ISR

	return MZ0380_PowerDownPeripherals( pDevice );

//RETURN_ERROR:

//	MZ0380_START_THREAD();

//	return status;
}

NTSTATUS B16CE70E9F854A62A76BD6F2B7781E3E( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] B16CE70E9F854A62A76BD6F2B7781E3E()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

	//
	//
	BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 1, 0x000000DC, 0x00000002 ); // CLR INTERRUT

	BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 0, 0x00000030, 0x00000000 ); // CLR INTERRUT

	BCAF0A9A9C414EDE9F39B78A1F1FDF37( pDevice, 0, 0x00000000, 0x00000400 ); // CLR INTERRUT 

	MZ0380_CLOSE_THREAD();

	FREE( pDevice->m_pCustomSystemConfigProperty );

	g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ] = NULL;

	return STATUS_SUCCESS;
}

NTSTATUS B3F2D4647EDD4CEB87D04AC6E9463337( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG status, ULONG mask, F301FA49098CE4d9eB95F22BBD388E837 * pVideos[ F03706E45925547d799BA016E4F0F6D6B ][ MAX_DEVICE_OPEN_NUM ], F170997530C6943659ECE8DEC21301F66 * pVideoBuffers[ F03706E45925547d799BA016E4F0F6D6B ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN p_FDFC345768E394d138EA574DEB55B7949s[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN F6E2E659AAB8C4494A193C313276DAA65[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ] )
{

	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%d] B3F2D4647EDD4CEB87D04AC6E9463337() \n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );
	int k = 0;

	BOOL is_sc550_product = FALSE;

	if( pDevice->idProduct == 0x0370 ) {

		is_sc550_product = TRUE;
	}

	if( status & 0x000000FF ) { // VIDEO STREAMS

		ULONG R00000040 = A350149D4A8740248A2A95D637054F72( pDevice, 0, 0x00000040 );

		ULONG R00000044 = A350149D4A8740248A2A95D637054F72( pDevice, 0, 0x00000044 );

		ULONG R00000048 = A350149D4A8740248A2A95D637054F72( pDevice, 0, 0x00000048 );

		//preview + H264 is status(0x1) R00000040(0x1010101)
		//audio is status(0x1) R00000040(0x1010000)

		ULONG counts = 1;

		if( (pDevice->iProduct & 0x0F) == 0x02 ||  // 960H & D1
			
			(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1

			if( (pDevice->iManufacturer & 0x0F) == 0x01 ||
				
				(pDevice->iManufacturer & 0x0F) == 0x0B ||
				
				(pDevice->iManufacturer & 0x0F) == 0x0C ) {

				counts = 4;
			}
			else {

				counts = 8;
			}
		}
		else { // HD

			//if( pDevice->m_nCustomCloneFiltersProperty >= 2 ) {

			//	counts = (pDevice->m_nCustomCloneFiltersProperty >= 4) ? (4) : (pDevice->m_nCustomCloneFiltersProperty); // 最多四組
			//}
			//else {

				counts = 1;
			//}
		}
		ULONG i = 0;
		
		for( i = 0 ; i < counts ; i++ ) {
			
			BOOL  is_ready = 0;

			ULONG s = i;

			if( (pDevice->iProduct & 0x0F) == 0x02  || // 960H & D1

				(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1

				is_ready = (status & (1 << (i + 0))) ? TRUE : FALSE;

				s = i;
			}
			else { // HD

				is_ready = (status & (1 << (0 + 0))) ? TRUE : FALSE;

				s = 0;
			}
			if( is_ready ) {

				ULONG j = 0;

				if( (pDevice->iProduct & 0x0F) == 0x02  || // 960H & D1 (RING.BUFFER) ||

					(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1 (RING.BUFFER)

					j = (R00000040 >> (i * 4)) & 0x03;
				}
				else { // HD (RING.BUFFER)

					j = (R00000040 >> (0 * 4)) & 0x03;
				}
			
				for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
				{
					F170997530C6943659ECE8DEC21301F66 * pVideoBuffer = pVideoBuffers[ i ][ k ];

					F301FA49098CE4d9eB95F22BBD388E837* pVideo = pVideos[ i ][ k ];
	
					if( pVideo && pVideoBuffer ) {

						pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input = j;

						BYTE * po = NULL;

						BYTE * pe = wrapper_videobuf_to_vmalloc( &pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B );

						if( pe == NULL ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] B3F2D4647EDD4CEB87D04AC6E9463337() pe == NULL \n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ); continue; }

						if( pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state != VIDEOBUF_QUEUED ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "pe state error(%x)\n", pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state ); continue; }

						F6E2E659AAB8C4494A193C313276DAA65[ i ][ k ] = FALSE;
					
						p_FDFC345768E394d138EA574DEB55B7949s[ i ][ k ] = TRUE;

						//if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 2) == (0) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 0 ]; }  

						//if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 2) == (1) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 2 ]; } 

						if( (pDevice->iProduct & 0x0F) == 0x02  || // 960H & D1

							(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1
							/*
							switch( j % 2 ) {

							case 0: po = pDevice->F41F19BDAA144449fA254B8E3282D1425 + (0x000CA900 * 2 * s) + (0x000CA900 * 0); break;

							case 1: po = pDevice->F41F19BDAA144449fA254B8E3282D1425 + (0x000CA900 * 2 * s) + (0x000CA900 * 1); break;
							}
							*/
							ULONG offset = (is_sc550_product) ? MZ0380_MAX_VIDEO_960H_DMA_BUFFER_SIZE : MZ0380_MAX_VIDEO_D1_DMA_BUFFER_SIZE;

							if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 4) == (0) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ s ]; }  
							if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 4) == (1) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ s ] + (offset * 1); } 
							if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 4) == (2) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ s ] + (offset * 2); } 
							if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 4) == (3) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ s ] + (offset * 3); } 

						}
						else { // HD
							/*
							switch( j % 2 ) {

							case 0: po = pDevice->F41F19BDAA144449fA254B8E3282D1425 + (0x0034BD00 * 2 * s) + (0x0034BD00 * 0); break;

							case 1: po = pDevice->F41F19BDAA144449fA254B8E3282D1425 + (0x0034BD00 * 2 * s) + (0x0034BD00 * 1); break;
							}
							*/

							if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 4) == (0) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 0 ]; }  

							if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 4) == (1) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 1 ]; } 

							if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 4) == (2) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 2 ]; } 

							if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 4) == (3) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 3 ]; } 
						}
						UINT * p_size = (UINT *)(po);

						ULONG size = *p_size;

						MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

						if( pDevice->idProduct == 0x0370 ) {
					
							size = po[ 4 ] & 0x01;
						}
						if( p_sys_cfg->n_output_video_resolution_vi_fw == 7 ) {

							size = po[ 4 ] & 0x01;
						}
	
						if( size > 0 ) {
						
							F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] preview size(%d) i(0d%d) ring(%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, size, i, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input );

							ULONG  cxo = p_sys_cfg->n_input_video_resolution_cx;

							ULONG  cwo = ((cxo + 15) / 16) * 16;

							ULONG  cyo = p_sys_cfg->n_input_video_resolution_cy;

							if( p_sys_cfg->n_input_video_resolution_interleaved ) {

								cyo <<= 1;
							}

							ULONG  cxe = pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.width;

							ULONG  cwe = pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.width;

							ULONG  cye = pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.height;

							if( (pDevice->iProduct & 0x0F) == 0x02 ||  // 960H & D1
				
								(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1

								if( (pDevice->iManufacturer & 0x0F) == 0x0C ) { // 960H -> D1

									cxo = ((cxo /  2) / 16) * 16;//360

									cwo = ((cxo + 15) / 16) * 16;//368

									cyo >>= 1;//240
								}
							}

							if( pe && po && (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) ) {

								if( pDevice->m_nAnalogCopyProtMacrovisionProperty == 1 )//HDCP
								{
									memset( pe, 0x80, cxo * cyo / 2);
									memset( pe + cxo * cyo , 0x00, cxo * cyo / 8);
									memset( pe + cxo * cyo + cxo * cyo / 4, 0x00, cxo * cyo / 8);
								}
								else
								{
									BYTE * po_y = po + (4);//??
	
									BYTE * po_u = po_y + (cwo * cyo);
	
									BYTE * po_v = po_u + ((cwo * cyo) >> 2);
	
									BYTE * pe_y = pe;
	
									BYTE * pe_u = pe + (cwe * cye);
	
									BYTE * pe_v = pe_u + ((cwe * cye) >> 2);
	
									memcpy( pe_y, po_y, cxe * cye );
	
									memcpy(pe_u, po_v, cxe * cye / 4);
	
									memcpy(pe_v, po_u, cxe * cye / 4);
								}

							}
							else
							{
								F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] pe(0x%x) po(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pe, po );
							}

							pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input = 0xFFFFFFFF; //
						}//size
						else
						{
						
							//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] preview size(%d) i(0d%d)---------------------\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, size, i );

							F6E2E659AAB8C4494A193C313276DAA65[ i ][ k ] = TRUE;
						}
					}//bufer
					else
					{
						//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] i(0d%d) pVideos[ i ](0x%x)  pVideoBuffers[ i ](0x%x) \n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, pVideos[ i ], pVideoBuffers[ i ] );
					}
				}//end of for
			}//ready
		}//end of for
		
		if( pDevice->idProduct == 0x0370 ) {

			counts = 0; // PREVIEW ONLY
		}
		for( i = 0 ; i < counts ; i++ ) { // H264 STREAM

			BYTE * po = NULL;

			BOOL  is_ready = 0;

			ULONG s = 0;

			if( (pDevice->iProduct & 0x0F) == 0x02  || // 960H & D1
				
				(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1

				is_ready = (status & (1 << (i + 0))) ? TRUE : FALSE;

				s = i;
			}
			else {

				is_ready = (status & (1 << (0 + 0))) ? TRUE : FALSE;

				s = 0;
			}
			if( is_ready ) {

				ULONG j = 0;

				if( (pDevice->iProduct & 0x0F) == 0x02 ||  // 960H & D1 (RING.BUFFER)

					(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1 (RING.BUFFER)

					j = (R00000044 >> (i * 4)) & 0x03;
				}
				else { // HD (RING.BUFFER)

					j = (R00000044 >> (0 * 4)) & 0x03;
				}
	
				if( (pDevice->iProduct & 0x0F) == 0x02 ||  // 960H & D1

					(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1

					ULONG offset = (is_sc550_product) ? 0x0010F000 : 0x000CA900;

					switch( j % 4 ) {
				
					case 0: po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ s + 16 ]; break;
				
					case 1: po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ s + 16 ] + (offset * 1); break;
					case 2: po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ s + 16 ] + (offset * 2); break;
					case 3: po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ s + 16 ] + (offset * 3); break;
					}
				}
				else { // HD

					switch( j % 4 ) {
				
					case 0: po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 5 ]; break;
					case 1: po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 6 ]; break;
					case 2: po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 7 ]; break;
					case 3: po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 8 ]; break;
					}
				}

				for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
				{
					F170997530C6943659ECE8DEC21301F66* pVideoBuffer = pVideoBuffers[ 16 + i ][ k ];
			
					F301FA49098CE4d9eB95F22BBD388E837* pVideo = pVideos[ 16 + i ][ k ];

					if( pVideo && pVideoBuffer ) {

						BYTE* pe = wrapper_videobuf_to_vmalloc( &pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B );

						if( pe == NULL ) { 	
						
							F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] MZ0380_HwProcessAnalogPCIVideoPacket() no dest buffer\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ); 

							//move to end of for
							//ULONG R50 = A350149D4A8740248A2A95D637054F72_EX( pDevice, 0, 0x00000050 + i, 1 );

							//if( R50 == 0x01 ) {

							//	BCAF0A9A9C414EDE9F39B78A1F1FDF37_EX( pDevice, 0, 0x00000050 + i, 0x02, 1 ); // 告知韌體上面很忙, 不要傻傻等待
							//}
						
							F6E2E659AAB8C4494A193C313276DAA65[ 16 + i ][ k ] = TRUE;

							continue; 
						}

						if( pDevice->m_nAnalogCopyProtMacrovisionProperty == 1 )//HDCP
						{
							F6E2E659AAB8C4494A193C313276DAA65[ 16 + i ][ k ] = TRUE;

							continue; 
						}

						if( pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state != VIDEOBUF_QUEUED ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "pe state error(%x)\n", pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state ); continue; }

						//there are 8 bytes headers in H264 stream form MZ0380
						//byte 0~3 is size, byte 4 is I/P

						UINT * p_size = (UINT *)(po);

						ULONG size = *(p_size + 0);

						ULONG info = *(p_size + 1); //??

						if( !pVideo->m_nCustomEncoderKeyFrameArrived )
						{
							if( *( po + 4 ) & 0x1 )
							{
								F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] I frame arrived\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

								pVideo->m_nCustomEncoderKeyFrameArrived = 1;
							}
							else
							{
								//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] drop P frame\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);
	
								continue;
							}
						}

						if( size > pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize)
						{
							size = pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize - 4;
						}

						if(size > 0)
						{
							//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] H264 size(%d) i(0d%d) ring(%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, size, i, j );

							//move to end of for
							//{  
							//	*p_size = 0; // 避免重複抓取
							//
							//	BCAF0A9A9C414EDE9F39B78A1F1FDF37_EX( pDevice, 0, 0x00000050 + i, 0x00, 1 ); // 可以進行下一張
							//}

							if( !pVideo->m_nCustomEncoderSlice)
							{				
								if(pDevice->m_nAnalogCopyProtMacrovisionProperty == 0 )
								{
									if( (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
									{
										if( size > pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize)
										{
											size = pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize;
										}
										memcpy( pe, po + 8, size );
									}
								}
							}
							else
							{
								H264_STREAM_HEADER hdr;
											
								memset( &hdr, 0x00, sizeof(H264_STREAM_HEADER) );

								if( size > (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize - 4) )
								{
									size = pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize - 4;
								}
								
								if(pDevice->m_nAnalogCopyProtMacrovisionProperty == 0 )
								{
									hdr.nFrameBufferSize = size;
								}
								else
								{
									hdr.nFrameBufferSize = 0;
								}

								hdr.nFrameType = (*( po + 4 ) & 0x1) ? (0) : (1);

								hdr.nReserved = 0x00;

								if(pDevice->m_nAnalogCopyProtMacrovisionProperty == 0 )
								{
									if( (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
									{
										memcpy( pe + 4, po + 8, size );
									}
								}

								if( (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
								{
									memcpy( pe, &hdr, sizeof(H264_STREAM_HEADER) );
								}

								//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] p_FDFC345768E394d138EA574DEB55B7949s[ 16 + %d ][ %d ](0x%x) F6E2E659AAB8C4494A193C313276DAA65[ 16 + %d ][ %d ](0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, k, p_FDFC345768E394d138EA574DEB55B7949s[ 16 + i ][ k ], i, k, F6E2E659AAB8C4494A193C313276DAA65[ 16 + i ][ k ]);
							}

							F6E2E659AAB8C4494A193C313276DAA65[ 16 + i ][ k ] = FALSE;
						
							p_FDFC345768E394d138EA574DEB55B7949s[ 16 + i ][ k ] = TRUE;

							if( pVideo->m_nCustomEncoderSlice)
							{
								pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.size = size + 4;//for s_v4l2_buffer.bytesused in application
							}
							else
							{
								pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.size = size;//for s_v4l2_buffer.bytesused in application
							}
							
						}//size
						else
						{
							//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "H264 size 0, i (0d%d)!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n", i );

							//move to end of for
							//if( (BYTE)(A350149D4A8740248A2A95D637054F72_EX( pDevice, 0, 0x00000050 + i, 1 )) != 0 ) {

							//	BCAF0A9A9C414EDE9F39B78A1F1FDF37_EX( pDevice, 0, 0x00000050 + i, 0x00, 1 ); // 容錯, 可以進行下一張
							
							//}

							F6E2E659AAB8C4494A193C313276DAA65[ 16 + i ][ k ] = TRUE;
						}

					}
					else { // 沒有開編碼
						//move to end of for
						//BCAF0A9A9C414EDE9F39B78A1F1FDF37_EX( pDevice, 0, 0x00000050 + i, 0x00, 1 ); // 可以進行下一張

						//if( k != 0 )
						//{
						//	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "i(%d) k(%d) pVideo(0x%x) pVideoBuffer(0x%x)\n", i, k, pVideo, pVideoBuffer );
						//}
					}
				}//end of for
				{  
					UINT * p_size = (UINT *)(po);
					
					*p_size = 0; // 避免重複抓取

					BCAF0A9A9C414EDE9F39B78A1F1FDF37_EX( pDevice, 0, 0x00000050 + i, 0x00, 1 ); // 可以進行下一張
				}

			}
		}
	}
	// X264 STREAM

	if( status & 0x00000800 ) {

		//KeReleaseSemaphore( &(pPCIBaseDevice->m_hIRQAccessSemaphore), 0, 1, FALSE );

		wrapper_down( &(pDevice->m_MZ0380AccessSemaphore) ); 

		pDevice->E92EA7106EDE415589FC494AF89F85E0 = 1;

		wrapper_up( &(pDevice->m_MZ0380AccessSemaphore) ); 

		wrapper_wake_up( &(pDevice->m_wait_queue_head) ); 
	}

	return STATUS_SUCCESS;
}


NTSTATUS BC50A3FAA8804CF3AE611AFFE6606AA2( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, F170997530C6943659ECE8DEC21301F66 * pVideoBuffer )
{
	return STATUS_SUCCESS;
}

NTSTATUS B7D0BE55F4E84F7A8DDDDACB6072D4D8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, F170997530C6943659ECE8DEC21301F66 * pVideoBuffers )
{
	return STATUS_SUCCESS;
}

NTSTATUS A3D659176692446A99A673EE21731E20( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG status, ULONG mask, FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudios[ F03706E45925547d799BA016E4F0F6D6B ], FFE3034C8E38D40dbAF3D2CD6E461C55C * pAudioBuffers[ F03706E45925547d799BA016E4F0F6D6B ], BOOLEAN p_FDFC345768E394d138EA574DEB55B7949s[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN F6E2E659AAB8C4494A193C313276DAA65[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ] )
{

	FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio = NULL;

	BYTE * po  = NULL;

	BYTE * pe  = NULL;

	int k = 0;

	if( status & 0x00FF0000 ) { // AUDIO STREAMS

		//if( pDevice->m_nAnalogCopyProtMacrovisionProperty == 1 )//HDCP
		//{
		//	goto EXIT;
		//}

		ULONG R0000004C = A350149D4A8740248A2A95D637054F72( pDevice, 0, 0x0000004C );

		ULONG counts = 1;

		if( (pDevice->iProduct & 0x0F) == 0x02  || // 960H & D1

			(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1

			if( (pDevice->iManufacturer & 0x0F) == 0x01 ||
				
				(pDevice->iManufacturer & 0x0F) == 0x0B ||
				
				(pDevice->iManufacturer & 0x0F) == 0x0C ) {

				counts = 4;
			}
			else {

				counts = 8;
			}
		}
		else { // HD
			/*
			if( pDevice->m_nCustomCloneFiltersProperty >= 2 ) {

				counts = (pDevice->m_nCustomCloneFiltersProperty >= 4) ? (4) : (pDevice->m_nCustomCloneFiltersProperty); // 最多四組
			}
			else {

				counts = 1;
			}
			*/
			counts = 1;

		}
		ULONG i = 0;
		for( i = 0 ; i < counts ; i++ ) {

			BOOL  is_ready = FALSE;

			ULONG m = i >> 1;

			ULONG s = 0;

			if( (pDevice->iProduct & 0x0F) == 0x02  || // 960H & D1
				
				(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1

				is_ready = (status & (1 << ((m * 2) + 16))) ? TRUE : FALSE;

				s = i;
			}
			else {

				is_ready = (status & (1 << ((0 * 2) + 16))) ? TRUE : FALSE;

				s = 0;
			}
			if( is_ready ) {

				ULONG j = 0;

				if( (pDevice->iProduct & 0x0F) == 0x02  || // 960H & D1 (RING.BUFFER)
					
					(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1 (RING.BUFFER)

					j = (R0000004C >> ((m * 2) * 4)) & 0x03;
				}
				else { // HD (RING.BUFFER)

					j = (R0000004C >> ((0 * 2) * 4)) & 0x03;
				}

				pAudio = pAudios[ i ];

				if( pAudio == NULL )
				{
					continue;
				}
				
				for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
				{
					if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F13A906F1479D4245B9F207A09C70BCE6[ pAudio->F0DD7393CD1494e27A72652C7D1A97893 ] & ( 1 << k ) )
					{
						if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ])
						{
							if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime)
							{
								if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area)
								{
									pe = pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area;				
	
									pe += pAudio->F6578ACFCB40E44819A12FD3E27A48085[ k ] * pAudio->F1461B75D9C644717A130B5C10D966CF0; 

								}				
								else
								{
									continue;
								}
							}		
							else
							{
								continue;
							}
						}
						else
						{
							continue;
						}

						if( ((pDevice->iProduct & 0x0F) == 0x02) || ((pDevice->iProduct & 0x0F) == 0x03)  ) { // 960H & D1
					
							switch( j % 4 ) {

							case 0: po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 8 ] + 8192 * ((m << 2) + 0); break;
							
							case 1: po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 8 ] + 8192 * ((m << 2) + 1); break;
							
							case 2: po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 8 ] + 8192 * ((m << 2) + 2); break;
							
							case 3: po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 8 ] + 8192 * ((m << 2) + 3); break;

							}
					
							SHORT * po_s = (SHORT *)(po);
					
							SHORT * pe_s = (SHORT *)(pe);

							if( s & 0x01 ) { po_s++; }

							if( pDevice->m_nAnalogCopyProtMacrovisionProperty == 1 )//HDCP
							{
								memset(pe, 0x00, 4096);
							}
							else
							{
								ULONG j = 0;
								for( j = 0 ; j < 2048 ; j++ ) {

								   *pe_s = *po_s++;

									po_s++;

									pe_s++;
								}
							}
					
							p_FDFC345768E394d138EA574DEB55B7949s[ i ][ k ] = TRUE;

							//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] audio complete(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i);

						}
						else {

							switch( j % 4 ) {

							case 0: po = (BYTE*) pDevice->F41F19BDAA144449fA254B8E3282D1425[ 4 ] + (4096 * 0); break;
							case 1: po = (BYTE*) pDevice->F41F19BDAA144449fA254B8E3282D1425[ 4 ] + (4096 * 1); break;
							case 2: po = (BYTE*) pDevice->F41F19BDAA144449fA254B8E3282D1425[ 4 ] + (4096 * 2); break;
							case 3: po = (BYTE*) pDevice->F41F19BDAA144449fA254B8E3282D1425[ 4 ] + (4096 * 3); break;
					
							}
							
							if( pDevice->m_nAnalogCopyProtMacrovisionProperty == 1 )//HDCP
							{
								memset(pe, 0x00, 4096);
							}
							else
							{
								memcpy(pe, po, 4096);
							}

							p_FDFC345768E394d138EA574DEB55B7949s[ 0 ][ k ] = TRUE;
						}
					}//end of if
				}//end of for
			}// end of if ready
		}//end of for
	}

	return STATUS_SUCCESS;
}

int B61F92BFB9094377AA7CFF54EC29E79D( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	wrapper_down( &(pDevice->m_pControlSemaphore) ); 

	if( pDevice->m_pControlThread == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] B61F92BFB9094377AA7CFF54EC29E79D( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

		pDevice->m_pControlThread = wrapper_kthread_run( E3FC26436F414315AA1D019E5B2BF5C3, pDevice, "E3FC26436F414315AA1D019E5B2BF5C3" );

		if( wrapper_IS_ERR( pDevice->m_pControlThread ) ) {

			int ret = wrapper_PTR_ERR( pDevice->m_pControlThread );

			pDevice->m_pControlThread = NULL;

			return ret;
		}
	}
	wrapper_up( &(pDevice->m_pControlSemaphore) );

	return STATUS_SUCCESS;
}

int ADD5FE824A3C48E6B58F402E38497D21( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	int thread_stop_counter = 0;

	wrapper_down( &(pDevice->m_pControlSemaphore) ); 

	if( pDevice->m_pControlThread ) {

		if( pDevice->m_ReadyToStopControlThread == 0 )
		{
			pDevice->m_ReadyToStopControlThread = 1;

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] ADD5FE824A3C48E6B58F402E38497D21( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );
		
			wrapper_kthread_stop( pDevice->m_pControlThread ); // GOOD NEWS!! LINUX HAD ALREADY HELPED TO FINISH THE "STOP" SYNC.

			while( pDevice->m_pControlThread_already_stop == FALSE )
			{
				wrapper_schedule_timeout_interruptible( wrapper_msecs_to_jiffies(200) );

				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] ADD5FE824A3C48E6B58F402E38497D21( ) ---\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

				thread_stop_counter++;

				if(thread_stop_counter > 5)
				{
					break;
				}
			}

			pDevice->m_pControlThread = NULL;

			pDevice->m_ReadyToStopControlThread = 0;
		
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] ADD5FE824A3C48E6B58F402E38497D21( ) end\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );
		}
	}
	wrapper_up( &(pDevice->m_pControlSemaphore) );

	return STATUS_SUCCESS;
}

int E3FC26436F414315AA1D019E5B2BF5C3( void * FD51B2B4E0CAC4359A9EFA429A9E16157 )
{	
	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)FD51B2B4E0CAC4359A9EFA429A9E16157;

	ULONG counts = 0;

	BYTE i = 0;

	pDevice->m_pControlThread_already_stop = FALSE;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] E3FC26436F414315AA1D019E5B2BF5C3( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );


	while( wrapper_kthread_should_stop() == FALSE ) {

		MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		if( p_sys_cfg->n_is_firmware_just_begin > 10 ) {

			if( (p_sys_cfg->n_is_firmware_ready & 0x000000FF) == 0x000000F1 ) {

				if( (counts % 10) == 0 ) { 

					if( (pDevice->iProduct & 0x0F) == 0x02 ||  // 960H & D1
					
						(pDevice->iProduct & 0x0F) == 0x03 ) { // 960H & D1

						ULONG chs = 8;

						if( (pDevice->iManufacturer & 0x0F) == 0x01 ||
						
							(pDevice->iManufacturer & 0x0F) == 0x0B ||
						
							(pDevice->iManufacturer & 0x0F) == 0x0C ) {
	
							chs = 4;
						}
						else {
	
							chs = 8;
						}
						for( i = 0 ; i < chs ; i++ ) {

							BYTE R00 = 0x00;

							if( i < 4 ) {

								DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x40, 0x00 );

								R00 = E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x50, 0x00 + 0x10 * (i - 0) );
							}
							else {

								DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x50, 0x40, 0x01 );

								R00 = E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x50, 0x00 + 0x10 * (i - 4) );
							}
							ULONG j = i;
			
							if( (pDevice->iProduct & 0x0F) == 0x02 && (pDevice->iManufacturer & 0x0F) == 0x0C ) { j = SC2CC_VIN_MAP[ i ]; }

							if( (R00 & 0x88) == 0x08 ) {

								pDevice->m_nAnalogVideoDecoderStatusProperty |=  (1 << j);
							}
							else {

								pDevice->m_nAnalogVideoDecoderStatusProperty &= ~(1 << j);
							}
						}
						F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "TW2968_ADC_MODE_DETECT( %d × %08X )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->m_nAnalogVideoDecoderStatusProperty);
					}
					else if( (pDevice->iProduct == 0x1C && pDevice->iManufacturer == 0xFA) ||  // ELGATO BOARD
							 (pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x03) ||  // ELGATO BOARD
							 (pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x05) ) { // ELGATO BOARD
	
						MST3367_VideoFormatDetection( pDevice );
					}
					else if( pDevice->iManufacturer == 0x5E ||  // ELGATO BOARD

							 pDevice->iManufacturer == 0x5F ||  // SC550N1 M2 HDMI

							 pDevice->iManufacturer == 0xCE ||  // ELGATO BOARD

							 pDevice->iManufacturer == 0xCF ) { // SC5C0N1 M2 HDMI

						MST3367_VideoFormatDetection( pDevice );
					}
					else if( pDevice->iManufacturer == 0x5A ||
					
							 pDevice->iManufacturer == 0xCA ) {
	
						CheckHDMIRX(pDevice);
					}
					else if( pDevice->iManufacturer == 0x51 || 
				
							 pDevice->iManufacturer == 0xC1 || 
				
							 pDevice->iManufacturer == 0x52 || 
				
							 pDevice->iManufacturer == 0xC2 ) {
						 	
						if( pDevice->iManufacturer == 0x51 ||
						
							pDevice->iManufacturer == 0xC1 ) {
						
							if( p_sys_cfg->b_is_techpoint_support ) {

								#ifdef AME_MZ0380
								TP2834_FORMAT_DETECTION( pDevice );
								#endif
							}
							else {

								CC7AF56407504E059A58F55D48A142C1( pDevice, TRUE );
							
								nvp6124_set_equalizer( pDevice );
						
								BYTE i = 0;
								for( i = 0 ; i < 4; i++ ) {
								
									DBF051EEA3B648B49859145F02FA268C( pDevice, 0x00, NVP6124_ADDR, 0xFF, 0x00 );
							
									ULONG std = E6FB1249C1F642A38BC0228741149CD8( pDevice, 0x00, NVP6124_ADDR, 0xD0 + i );
						
									ULONG x = 0;
	
									ULONG y = 0;
	
									ULONG fps = 0;
	
									if( std == 0x01 ) {      //  SD@NTSC
								
										x = 960; y = 240; fps = 60; 
									}
									else if( std == 0x02 ) { //  SD@PAL
								
										x = 960; y = 288; fps = 50; 
									}
									else if( std == 0x04 ) { //  720P30
								
										x = 1280; y = 720; fps = 30; 
									}
									else if( std == 0x08 ) { //  720P25
								
										x = 1280; y = 720; fps = 25; 
									}
									else if( std == 0x10 ) { //  720P60
								
										x = 1280; y = 720; fps = 60; 
									}
									else if( std == 0x20 ) { //  720P50
								
										x = 1280; y = 720; fps = 50; 
									}
									else if( std == 0x40 ) { // 1080P30
								
										x = 1920; y = 1080; fps = 30; 
									}
									else if( std == 0x80 ) { // 1080P25
								
										x = 1920; y = 1080; fps = 25; 
									}
									else {
									
										x = 0; y = 0; fps = 0; 
									}
									F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] CH(%d) x(%d) y(%d) fps(%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, x, y, fps );
	
									if( x != 0 && y != 0 ) {
	
										if( g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ] ) {
										
											p_sys_cfg = (MZ0380_SYS_CFG *)(g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_pCustomSystemConfigProperty);

											if( p_sys_cfg->n_input_video_resolution_cx != x ||
	
												p_sys_cfg->n_input_video_resolution_cy != y ||
	
												p_sys_cfg->n_input_video_resolution_fps != fps ) {
												
												p_sys_cfg->n_input_video_resolution_cx = x;
	
												p_sys_cfg->n_input_video_resolution_cy = y;
	
												p_sys_cfg->n_input_video_resolution_fps = fps;

												BYTE vfmt = (fps == 30 || fps == 60) ? NTSC : PAL;

												BYTE chnmode = NVP6124_VI_1080P_2530;
	
												BYTE portmode = NVP6124_OUTMODE_1MUX_FHD;

												if( x == 960 && y == 240 ) {
											
													chnmode = NVP6124_VI_SD;
	
													portmode = NVP6124_OUTMODE_1MUX_SD;
	
													p_sys_cfg->n_input_video_resolution_fps_m = 1;
							
													p_sys_cfg->n_input_video_resolution_interleaved = 1;
												}
												else if( x == 960 && y == 288 ) {
												
													chnmode = NVP6124_VI_SD;
	
													portmode = NVP6124_OUTMODE_1MUX_SD;
												
													p_sys_cfg->n_input_video_resolution_fps_m = 0;
							
													p_sys_cfg->n_input_video_resolution_interleaved = 1;
												}
												else if( x == 1280 && fps < 50 ) {
												
													chnmode = NVP6124_VI_720P_2530;
	
													portmode = NVP6124_OUTMODE_1MUX_HD;
	
													p_sys_cfg->n_input_video_resolution_fps_m = 0;
							
													p_sys_cfg->n_input_video_resolution_interleaved = 0;
												}
												else if( x == 1280 && fps >= 50 ) {
												
													chnmode = NVP6124_VI_720P_5060;
	
													portmode = NVP6124_OUTMODE_1MUX_HD5060;
	
													p_sys_cfg->n_input_video_resolution_fps_m = 0;
							
													p_sys_cfg->n_input_video_resolution_interleaved = 0;
												}
												else if( x == 1920 ) {
												
													chnmode = NVP6124_VI_1080P_2530;
	
													portmode = NVP6124_OUTMODE_1MUX_FHD;
	
													p_sys_cfg->n_input_video_resolution_fps_m = 0;
							
													p_sys_cfg->n_input_video_resolution_interleaved = 0;
												}
												else {
												
													p_sys_cfg->n_input_video_resolution_fps_m = 0;
							
													p_sys_cfg->n_input_video_resolution_interleaved = 0;
												}
												nvp6124_set_chnmode( pDevice, i, vfmt, chnmode );
	
												nvp6124_set_portmode( pDevice, 0, i, portmode, i );
						
												{	switch( chnmode ) {
													case NVP6124_VI_SD:
													case NVP6124_VI_720H:
													case NVP6124_VI_1280H:
													case NVP6124_VI_1440H:
													case NVP6124_VI_1920H: {												
														p_sys_cfg->n_nvp6124_bri_def = (CHAR)(nvp6124_bri_tbl_960H[ vfmt % 2 ]);
														p_sys_cfg->n_nvp6124_con_def = (CHAR)(nvp6124_con_tbl_960H[ vfmt % 2 ]);
														p_sys_cfg->n_nvp6124_sat_def = (CHAR)(nvp6124_sat_tbl_960H[ vfmt % 2 ]);
														p_sys_cfg->n_nvp6124_hue_def = (CHAR)(nvp6124_hue_tbl_960H[ vfmt % 2 ]); break;
														break ;
													}
													case NVP6124_VI_720P_2530:
													case NVP6124_VI_720P_5060: {		
														p_sys_cfg->n_nvp6124_bri_def = (CHAR)(nvp6124_bri_tbl_720P[ vfmt % 2 ]);
														p_sys_cfg->n_nvp6124_con_def = (CHAR)(nvp6124_con_tbl_720P[ vfmt % 2 ]);
														p_sys_cfg->n_nvp6124_sat_def = (CHAR)(nvp6124_sat_tbl_720P[ vfmt % 2 ]);
														p_sys_cfg->n_nvp6124_hue_def = (CHAR)(nvp6124_hue_tbl_720P[ vfmt % 2 ]); break;
													}
													case NVP6124_VI_1080P_2530: {
														p_sys_cfg->n_nvp6124_bri_def = (CHAR)(nvp6124_bri_tbl[ vfmt % 2 ]);
														p_sys_cfg->n_nvp6124_con_def = (CHAR)(nvp6124_con_tbl[ vfmt % 2 ]);
														p_sys_cfg->n_nvp6124_sat_def = (CHAR)(nvp6124_sat_tbl[ vfmt % 2 ]);
														p_sys_cfg->n_nvp6124_hue_def = (CHAR)(nvp6124_hue_tbl[ vfmt % 2 ]); break;
													}
													default: break;
													}
													/*
													g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nAnalogVideoProcAmpBrightnessProperty[ 0 ] |= 0x08000000;
	
													g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nAnalogVideoProcAmpContrastProperty[ 0 ] |= 0x08000000;
	
													g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nAnalogVideoProcAmpHueProperty[ 0 ] |= 0x08000000;
	
													g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nAnalogVideoProcAmpSaturationProperty[ 0 ] |= 0x08000000;

													CC7AF56407504E059A58F55D48A142C1( pDevice, TRUE );
													*/
												}
												p_sys_cfg->b_input_video_signal_changed = TRUE;
					
												p_sys_cfg->n_input_audio_sampling_frequency = 48000;
					
												p_sys_cfg->n_input_video_resolution_color_colorimetry = (x == 960) ? 1 : 2;
					
												p_sys_cfg->n_input_video_resolution_color_range = 1;

												p_sys_cfg->b_input_video_resolution_external_sync = FALSE;
											}
											if( p_sys_cfg->n_input_video_resolution_fps > 50 ) {

												g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->FD314ADAD9404496b842EBFC396E875CB = V4L2_STD_NTSC_M;
											}
											else if( p_sys_cfg->n_input_video_resolution_fps > 30 ) {
					
												g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->FD314ADAD9404496b842EBFC396E875CB = V4L2_STD_PAL_B;
											}
											else if( p_sys_cfg->n_input_video_resolution_fps > 25 ) {
					
												g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->FD314ADAD9404496b842EBFC396E875CB = V4L2_STD_NTSC_M;
											}
											else {
					
												g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->FD314ADAD9404496b842EBFC396E875CB = V4L2_STD_PAL_B;
											}
											g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nCustomAnalogVideoResolutionProperty = (p_sys_cfg->n_input_video_resolution_cx << 16) |
					
																																  (p_sys_cfg->n_input_video_resolution_cy <<  0);
					
											g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nCustomAnalogVideoFrameRateProperty = (p_sys_cfg->n_input_video_resolution_fps);					
		
											g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nCustomAnalogVideoInterleavedProperty = (p_sys_cfg->n_input_video_resolution_interleaved);
	
											g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nCustomAnalogAudioSampleFrequencyProperty = 48000;
					
											g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nAnalogVideoDecoderStatusProperty = 1;
					
											g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nAnalogCopyProtMacrovisionProperty = 0;
										}
									}
									else {
								
										if( g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ] ) {

											p_sys_cfg = (MZ0380_SYS_CFG *)(g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_pCustomSystemConfigProperty);//change pDevice here
	
											p_sys_cfg->n_input_video_resolution_cx = 0;
					
											p_sys_cfg->n_input_video_resolution_cy = 0;
					
											p_sys_cfg->n_input_video_resolution_fps = 0;
					
											p_sys_cfg->n_input_video_resolution_fps_m = 0;
					
											p_sys_cfg->n_input_video_resolution_color_colorimetry = 0;
					
											p_sys_cfg->n_input_video_resolution_color_range = 0;

											p_sys_cfg->b_input_video_resolution_external_sync = FALSE;
					
											g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nCustomAnalogVideoResolutionProperty = 0;

											g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nCustomAnalogVideoFrameRateProperty = 0;

											g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nCustomAnalogVideoInterleavedProperty = 0;

											g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nCustomAnalogAudioSampleFrequencyProperty = 0;
					
											g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nAnalogVideoDecoderStatusProperty = 0;
										
											g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_nAnalogCopyProtMacrovisionProperty = 0;									
										}
									}
								}
								p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
							}
						}
					}
					else if( pDevice->iManufacturer == 0x58 ||  // SC550N1 4K60P
			
							 pDevice->iManufacturer == 0x68 ||  // SC550N1 4K60P
			
							 pDevice->iManufacturer == 0xC8 ) { // SC5C0N1 4K60P

						ULONG x = 3840;

						ULONG y = 2160;

						ULONG fps = 60;

						ULONG m = 0;

						ULONG frq = 48000;
					
						if( x != 0 && y != 0 ) {

							if( p_sys_cfg->n_input_video_resolution_cx != x ||

								p_sys_cfg->n_input_video_resolution_cy != y ||

								p_sys_cfg->n_input_video_resolution_fps != fps ||

								p_sys_cfg->n_input_video_resolution_fps_m != m ) {

								pDevice->m_nCustomAnalogVideoMultiSyncChannels = (4);

								pDevice->m_nCustomAnalogVideoMultiSyncPositionX = (0);

								pDevice->m_nCustomAnalogVideoMultiSyncPositionY = (0);

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

								p_sys_cfg->n_input_video_resolution_color_colorimetry = (x == 720) ? 1 : 2;

								p_sys_cfg->n_input_video_resolution_color_range = 1;

								p_sys_cfg->b_input_video_resolution_external_sync = FALSE;

								p_sys_cfg->n_input_audio_sampling_frequency = frq;
							}
							F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "GV7601_SDI_MODE_DETECT( %d × %d × %d × %d )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, (ULONG)(x), (ULONG)(y), fps);

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
					
							pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = (p_sys_cfg->n_input_audio_sampling_frequency);

							pDevice->m_nAnalogVideoDecoderStatusProperty = 1;

							pDevice->m_nAnalogCopyProtMacrovisionProperty = 0;
						
							pDevice->m_nCustomAnalogVideoSdiSingalStatusProperty = 0;
						}
						else {
				
							p_sys_cfg->n_input_video_resolution_cx = 0;

							p_sys_cfg->n_input_video_resolution_cy = 0;

							p_sys_cfg->n_input_video_resolution_fps = 0;

							p_sys_cfg->n_input_video_resolution_fps_m = 0;

							p_sys_cfg->n_input_video_resolution_color_colorimetry = 0;

							p_sys_cfg->n_input_video_resolution_color_range = 0;

							p_sys_cfg->b_input_video_resolution_external_sync = FALSE;

							p_sys_cfg->n_input_audio_sampling_frequency = 0;

						//	pDevice->m_nCustomAnalogVideoMultiSyncChannels = (4);
							
						//	pDevice->m_nCustomAnalogVideoMultiSyncPositionX = (0);

						//	pDevice->m_nCustomAnalogVideoMultiSyncPositionY = (0);

							pDevice->m_nCustomAnalogVideoResolutionProperty = 0;

							pDevice->m_nCustomAnalogVideoFrameRateProperty = 0;

							pDevice->m_nCustomAnalogVideoInterleavedProperty = 0;

							pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 0;

							pDevice->m_nAnalogVideoDecoderStatusProperty = 0;
					
							pDevice->m_nAnalogCopyProtMacrovisionProperty = 0;

							pDevice->m_nCustomAnalogVideoSdiSingalStatusProperty = 0x00000000;
						}
						{	ULONG nums = pDevice->m_nCustomAnalogVideoMultiSyncChannels - 1;

							ULONG n = 0;	
							for( n = 0 ; n < nums ; n++ ) {

								F42A18AF66EFF459eA332CA253FFF8A65 * p_brother_device = g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + n + 1 ];

								if( p_brother_device ) {
							
									MZ0380_SYS_CFG * p_brother_sys_cfg = (MZ0380_SYS_CFG *)(p_brother_device->m_pCustomSystemConfigProperty);

									p_brother_sys_cfg->n_input_video_resolution_cx = p_sys_cfg->n_input_video_resolution_cx;

									p_brother_sys_cfg->n_input_video_resolution_cy = p_sys_cfg->n_input_video_resolution_cy;

									p_brother_sys_cfg->n_input_video_resolution_fps = p_sys_cfg->n_input_video_resolution_fps;

									p_brother_sys_cfg->n_input_video_resolution_fps_m = p_sys_cfg->n_input_video_resolution_fps_m;

									p_brother_sys_cfg->n_input_audio_sampling_frequency = p_sys_cfg->n_input_audio_sampling_frequency;

									p_brother_device->m_nCustomAnalogVideoMultiSyncChannels = 1;

									p_brother_device->m_nCustomAnalogVideoMultiSyncPositionX = (n) * (p_brother_sys_cfg->n_input_video_resolution_cx / 4);

									p_brother_device->m_nCustomAnalogVideoMultiSyncPositionY = (0);
								}
							}
						}
					}
					else if( pDevice->iManufacturer == 0x59 ||  // SC550N1 4K60P
			
							 pDevice->iManufacturer == 0x69 ||  // SC550N1 4K60P
			
							 pDevice->iManufacturer == 0xC9 ) { // SC5C0N1 4K60P
						;
					}
					else if( pDevice->iManufacturer == 0x54 || // SC550N1 MC SDI
			
							 pDevice->iManufacturer == 0x5B || // SC550N4 SDI

							 pDevice->iManufacturer == 0xC4 || // SC5C0N1 MC SDI
			
							 pDevice->iManufacturer == 0xCB || // SC5C0N4 SDI

							 pDevice->iManufacturer == 0xC6 || // AEROCOM SDI (CH03)
						 
							 pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {  // HD

						if( (pDevice->iManufacturer == 0xC6) &&
					
							(pDevice->m_nAnalogCrossbarVideoInputProperty == 5 || 
					
							 pDevice->m_nAnalogCrossbarVideoInputProperty == 6) ) {
						
							if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_60HZ ) {

								pDevice->m_nAnalogVideoDecoderStatusProperty = ( ((BYTE)(E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x88, 0x01 )) & 0xC9) == 0x48 ) ? 1 : 0; F6B9E557A4BA24ffd926B820B836289C8_100NS( 1 );
							}
							if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_50HZ ) {

								pDevice->m_nAnalogVideoDecoderStatusProperty = ( ((BYTE)(E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x88, 0x01 )) & 0xC9) == 0x49 ) ? 1 : 0; F6B9E557A4BA24ffd926B820B836289C8_100NS( 1 );
							}
							pDevice->m_nAnalogCopyProtMacrovisionProperty = 0;
						
							goto END_DETECTION;
						}
						// VIDEO FORAMT DETECTION
						// 
						USHORT R00006 = 0x0000;

						USHORT R0001F = 0x0000;

						USHORT R00022 = 0x0000;
					
						USHORT R00002 = 0x0000;

						R00006 = D792350EAF024850BDEDF910AE232FD8( pDevice, 0x0006 ) & 0x3F00; R00006 >>= 8; // VD_STD

						R0001F = D792350EAF024850BDEDF910AE232FD8( pDevice, 0x001F ) & 0x3FFF; // WORDS PER ACTIVE LINE

						R00022 = D792350EAF024850BDEDF910AE232FD8( pDevice, 0x0022 ) & 0x2000; // M

						R00002 = D792350EAF024850BDEDF910AE232FD8( pDevice, 0x0002 ) & 0x07FF; // ERROR STATUS

						ULONG x = 0;

						ULONG y = 0;

						ULONG fps = 0;

						ULONG m = (R00022 & 0x2000) ? 1 : 0; // EX: 29.97 / 30.00

						if( R00006 == 0x16 || R00006 == 0x17 ) { x =  720; y =  240; fps = 60; }

						if( R00006 == 0x19 || R00006 == 0x1B ) { x =  720; y =  240; fps = 60; }

						if( R00006 == 0x18 || R00006 == 0x1A ) { x =  720; y =  288; fps = 50; }

						if( R00006 == 0x1E ) { 
					
							USHORT R00021 = D792350EAF024850BDEDF910AE232FD8( pDevice, 0x0021 )  & 0x07FF; // LINES PER FRAME 

							if( R00021 > 600 ) { // 625

								x = 720; y = 288; fps = 50; 
							}
							else { // 525

								x = 720; y = 240; fps = 60; 
							}
						}
						if( R00006 == 0x20                   ) { x = 1280; y =  720; fps = 60; }

						if( R00006 == 0x00 && R0001F == 1280 ) { x = 1280; y =  720; fps = 60; }

						if( R00006 == 0x24 || R00006 == 0x04 ) { x = 1280; y =  720; fps = 50; }

						if( R00006 == 0x22 || R00006 == 0x02 ) { x = 1280; y =  720; fps = 30; }

						if( R00006 == 0x26 || R00006 == 0x06 ) { x = 1280; y =  720; fps = 25; }

						if( R00006 == 0x28 || R00006 == 0x08 ) { x = 1280; y =  720; fps = 24; }

						if( R00006 == 0x2A || R00006 == 0x0A ) { x = 1920; y =  540; fps = 60; }

						if( R00006 == 0x2C || R00006 == 0x0C ) { x = 1920; y =  540; fps = 50; }

						if( R00006 == 0x11                   ) { x = 1920; y =  540; fps = 48; }

						if( R00006 == 0x2B || R00006 == 0x0B ) { x = 1920; y = 1080; fps = 30; }

						if( R00006 == 0x2D || R00006 == 0x0D ) { x = 1920; y = 1080; fps = 25; }

						if( R00006 == 0x30 || R00006 == 0x10 ) { x = 1920; y = 1080; fps = 24; }

						if( R00006 == 0x2B && R0001F == 1920 ) { x = 1920; y = 1080; fps = 60; }

						if( R00006 == 0x2D && R0001F == 1920 ) { x = 1920; y = 1080; fps = 50; }

						if( x != 0 && y != 0 ) {

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

								p_sys_cfg->n_input_video_resolution_color_colorimetry = (x == 720) ? 1 : 2;

								p_sys_cfg->n_input_video_resolution_color_range = 1;

								p_sys_cfg->b_input_video_resolution_external_sync = FALSE;
							}
							F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "GV7601_SDI_MODE_DETECT( %d × %d × %d × %d )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, (ULONG)(x), (ULONG)(y), fps);

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

							pDevice->m_nAnalogCopyProtMacrovisionProperty = 0;
						
							pDevice->m_nCustomAnalogVideoSdiSingalStatusProperty = R00002;
						}
						else {

							p_sys_cfg->n_input_video_resolution_cx = 0;

							p_sys_cfg->n_input_video_resolution_cy = 0;

							p_sys_cfg->n_input_video_resolution_fps = 0;

							p_sys_cfg->n_input_video_resolution_fps_m = 0;

							p_sys_cfg->n_input_video_resolution_color_colorimetry = 0;

							p_sys_cfg->n_input_video_resolution_color_range = 0;

							p_sys_cfg->b_input_video_resolution_external_sync = FALSE;

							pDevice->m_nCustomAnalogVideoResolutionProperty = 0;

							pDevice->m_nCustomAnalogVideoFrameRateProperty = 0;

							pDevice->m_nCustomAnalogVideoInterleavedProperty = 0;

							pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 0;

							pDevice->m_nAnalogVideoDecoderStatusProperty = 0;
					
							pDevice->m_nAnalogCopyProtMacrovisionProperty = 0;

							pDevice->m_nCustomAnalogVideoSdiSingalStatusProperty = 0x00000000;
						}
					}
					else {	// HD

						if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 || 
						
							pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) {
							
							if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_60HZ ) {

								pDevice->m_nAnalogVideoDecoderStatusProperty = ( ((BYTE)(E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x88, 0x01 )) & 0xC9) == 0x48 ) ? 1 : 0; F6B9E557A4BA24ffd926B820B836289C8_100NS( 1 );
							}
							if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_50HZ ) {

								pDevice->m_nAnalogVideoDecoderStatusProperty = ( ((BYTE)(E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x88, 0x01 )) & 0xC9) == 0x49 ) ? 1 : 0; F6B9E557A4BA24ffd926B820B836289C8_100NS( 1 );
							}
							pDevice->m_nAnalogCopyProtMacrovisionProperty = 0;
						}
						else {

							MST3367_VideoFormatDetection( pDevice );
						}
					}
END_DETECTION:
					;
				}
			}
			else
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] n_is_firmware_ready(0x%x) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_sys_cfg->n_is_firmware_ready );
			}//end of if( (counts % 10) == 0 ) 

			BOOL F39960DFE03274b0cAC415171F8CD5711 = FALSE;

			if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 0 ) {

				if( pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 3 ] == 1 ) {

					if( (pDevice->iProduct == 0x1C && pDevice->iManufacturer == 0xFA) || // ELGATO BOARD

						(pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x03) || // ELGATO BOARD

						(pDevice->iProduct == 0x00 && pDevice->iManufacturer == 0x05) || // ELGATO BOARD

						(pDevice->iManufacturer == 0x5E) ||  // ELGATO BOARD

						(pDevice->iManufacturer == 0xCE) ) { // ELGATO BOARD

						if( p_sys_cfg->b_input_video_signal_changed == TRUE || F39960DFE03274b0cAC415171F8CD5711 == TRUE ) {

							p_sys_cfg->b_input_video_signal_changed = FALSE;

							F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[FIRMWARE RESET]\n");

							BCBB6F46096343FA8AD2A9FF89F84A73( pDevice );

							F640A7ABBB894EFBA34BA5C6FC719D34( pDevice );
						}
					}
					else if( (pDevice->iProduct & 0x0F) == 0x05 ) { // HD PRODUCTS

						ULONG cx_in = p_sys_cfg->n_input_video_resolution_cx;

						ULONG cy_in = p_sys_cfg->n_input_video_resolution_cy;

						ULONG fps_in = p_sys_cfg->n_input_video_resolution_fps;

						if( p_sys_cfg->n_input_video_resolution_interleaved ) {

							cy_in <<= 1;

							fps_in >>= 1;
						}
						if( pDevice->iManufacturer == 0x58 ||  // SC550N1 4K60P

							pDevice->iManufacturer == 0x68 ||  // SC550N1 4K60P

							pDevice->iManufacturer == 0xC8 ||  // SC550N1 4K60P
							 
							pDevice->iManufacturer == 0x59 ||  // SC550N1 4K60P

							pDevice->iManufacturer == 0x69 ||  // SC550N1 4K60P

							pDevice->iManufacturer == 0xC9 ) { // SC5C0N1 4K60P

							cx_in >>= 2;
						}
						if( (p_sys_cfg->n_input_video_resolution_cx > 0) &&
		
							(p_sys_cfg->n_input_video_resolution_cy > 0) &&
		
							(p_sys_cfg->n_output_video_resolution_cx != cx_in || 

							 p_sys_cfg->n_output_video_resolution_cy != cy_in || 

							 p_sys_cfg->n_output_video_resolution_fps != fps_in || 

							 p_sys_cfg->n_output_video_resolution_fps_m != p_sys_cfg->n_input_video_resolution_fps_m || 

							 p_sys_cfg->n_output_video_resolution_interleaved != p_sys_cfg->n_input_video_resolution_interleaved || 

							 p_sys_cfg->n_output_audio_sampling_frequency != p_sys_cfg->n_input_audio_sampling_frequency ||

							 p_sys_cfg->n_output_video_resolution_is_nosg == TRUE ||
							 
							 F39960DFE03274b0cAC415171F8CD5711 == TRUE) ) {
		
							p_sys_cfg->b_input_video_signal_changed = FALSE;
		
							F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[FIRMWARE RESET, cx = %d/%d, cy = %d/%d, fps = %d/%d, m = %d/%d, interleaved = %d/%d, frq = %d/%d, nosg = %d, reset = %d]\n", 
								
								p_sys_cfg->n_output_video_resolution_cx, p_sys_cfg->n_input_video_resolution_cx, 

								p_sys_cfg->n_output_video_resolution_cy, p_sys_cfg->n_input_video_resolution_cy, 

								p_sys_cfg->n_output_video_resolution_fps, p_sys_cfg->n_input_video_resolution_fps, 

								p_sys_cfg->n_output_video_resolution_fps_m, p_sys_cfg->n_input_video_resolution_fps_m, 

								p_sys_cfg->n_output_video_resolution_interleaved, p_sys_cfg->n_input_video_resolution_interleaved, 

								p_sys_cfg->n_output_audio_sampling_frequency, p_sys_cfg->n_input_audio_sampling_frequency,
								
								p_sys_cfg->n_output_video_resolution_is_nosg, 
								
								F39960DFE03274b0cAC415171F8CD5711 );

							BCBB6F46096343FA8AD2A9FF89F84A73( pDevice );
		
							F640A7ABBB894EFBA34BA5C6FC719D34( pDevice );
						}
					}
					A9667F33F6B047908C7FEBD405F891F9( pDevice, TRUE );
				}

			} //if( (p_sys_cfg->n_is_firmware_ready & 0x000000FF) == 0x000000F1 )

		}//end of if( p_sys_cfg->n_is_firmware_just_begin > 10 )

		if( (counts % 1000) == 0 ) { 

			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "CH%02d, BOARD VERSION: %d.%d, FIRMWARE VERSION: %d.%d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_sys_cfg->n_board_major_version, p_sys_cfg->n_board_minor_version, p_sys_cfg->n_firmware_major_version, p_sys_cfg->n_firmware_minor_version);
		}
		p_sys_cfg->n_is_firmware_just_begin++;

		counts++;
	
		for( i = 0 ; i < 10 ; i++ ) {

			if( wrapper_kthread_should_stop() ) {

				break;
			}
			if( pDevice->iManufacturer == 0x5A ||

				pDevice->iManufacturer == 0xCA ) {

				if( pDevice->m_nAnalogVideoDecoderStatusProperty == 0 ) {
				
					F6B9E557A4BA24ffd926B820B836289C8_100NS( 10000 );
				}
				else {
			
					F6B9E557A4BA24ffd926B820B836289C8_100NS( 100000 );	
				}
			}
			else {
			
				F6B9E557A4BA24ffd926B820B836289C8_100NS( 100000 );
			}
		}//end of for

	}//end of while

	pDevice->m_pControlThread_already_stop = TRUE;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] E3FC26436F414315AA1D019E5B2BF5C3( exit ) - %08X\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(pDevice->m_pControlThread) );

	return 0;	

}