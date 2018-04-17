#include "LINUXV4L2.h"
#include "property.h"
#include "wrapper.h"
#include "fh8735.h"
#include "FH8735_SD.h"
#include "FH8735_HZK32.h"
#include "FH8735_ASC32.h"
#include "mst3367.h"

// 002-86-21-61121558 #578 (MAX)

// 86-18901883118

// 002-86-21-61121558 #858 (WILLIAM)

// 002-86-21-61121558 #853 (GUIMIN)

// #define FH8735_JTAG_DEBUG

static int EBE5DCE0DB554397A79605FEA343FE27( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
static int AD96690602C7413AAC57A6B84A1747FE( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );

extern struct timeval previous_ts[16];

int EBE5DCE0DB554397A79605FEA343FE27EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	EBE5DCE0DB554397A79605FEA343FE27( pDevice );
}

int AD96690602C7413AAC57A6B84A1747FEEX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	AD96690602C7413AAC57A6B84A1747FE( pDevice );
}


#define FH8735_JTAG_HYBRID 0

//#define MAX_PATH 260

//#define FH8735_COPYPORTECT_ARCHITECTURE

#ifdef FH8735_COPYPORTECT_ARCHITECTURE

static ULONG FD0AC55FE0C0B45a788FEC199C5758F1E[ 16 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

static ULONG F6053D464C87D41c1B8CBE8A39FCDF2D2[ 16 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

#endif
; //necessary for compiler

ULONG FH8735_KsQueryCopyProtectNumber(  F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE p[ 4 ] )
{
	ULONG eKey = 0x12345678;

	if( pDevice->iProduct == 0x65 ) {

		eKey = 0x04D439B8;

		ULONG i = 0;
		for( i = 0 ; i < 4 ; i++ ) { switch( p[ 0 ] % 4 ) { case 0: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0x1118A004; eKey ^= (eKey >> 8) | (eKey << 24); break;
																  case 1: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0x540EF2F3; eKey ^= (eKey >> 8) | (eKey << 24); break;
																  case 2: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0xCE720AEE; eKey ^= (eKey >> 8) | (eKey << 24); break;
																  case 3: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0xE05C8633; eKey ^= (eKey >> 8) | (eKey << 24); break;
										   }
		}
	}
	else {

		eKey = 0x12345678;

		ULONG i = 0;
		for( i = 0 ; i < 4 ; i++ ) { switch( p[ 0 ] % 4 ) { case 0: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0xA539C75A; eKey ^= (eKey >> 8) | (eKey << 24); break;
																  case 1: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0x9F28A543; eKey ^= (eKey >> 8) | (eKey << 24); break;
																  case 2: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0x7B6324C5; eKey ^= (eKey >> 8) | (eKey << 24); break;
																  case 3: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0xF1029554; eKey ^= (eKey >> 8) | (eKey << 24); break;
										   }
		}
	}
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735_KsQueryCopyProtectNumber() CODE = %08X | KEY = %08X\n", *((ULONG *)(p)), eKey );

	return eKey;
}

NTSTATUS FH8735_SetAnalogAudioVoulmeProperty( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nVolume, ULONG channel )
{
//must be done after HwAnalogComponentsInitialize

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 < 1 )
	{
		return STATUS_SUCCESS;
	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FH8735_SetAnalogAudioVoulmeProperty() channel(0d%d) nVolume(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, channel, nVolume );

	if( pDevice->iManufacturer == 0xA4 ||
		
		pDevice->iManufacturer == 0xA5 ) {
		/*
		FH8735_CLOSE_THREAD();

		if( (nVolume & 0x0000FF00) == (0x0000FF00) ) { // FOR TOTAL

			ULONG n_volume = nVolume & 0x000000FF;
			
			n_volume >>= 2;

			B8BDE883169F4F829632A862C9FD62DE( pDevice, 0, (BYTE)(n_volume) );

			B8BDE883169F4F829632A862C9FD62DE( pDevice, 1, (BYTE)(n_volume) );

			B8BDE883169F4F829632A862C9FD62DE( pDevice, 2, (BYTE)(n_volume) );

			B8BDE883169F4F829632A862C9FD62DE( pDevice, 3, (BYTE)(n_volume) );
		}
		else { // BY CHANNEL

			ULONG n_channel = (nVolume >> 8) & (0x000000FF); n_channel %= 16;

			ULONG n_volume = (nVolume) & (0x000000FF);

			n_volume >>= 2;

			if( n_channel < 4 ) {

				if( n_channel == 0 ) { B8BDE883169F4F829632A862C9FD62DE( pDevice, 0, (BYTE)(n_volume) ); }

				if( n_channel == 1 ) { B8BDE883169F4F829632A862C9FD62DE( pDevice, 1, (BYTE)(n_volume) ); }

				if( n_channel == 2 ) { B8BDE883169F4F829632A862C9FD62DE( pDevice, 2, (BYTE)(n_volume) ); }

				if( n_channel == 3 ) { B8BDE883169F4F829632A862C9FD62DE( pDevice, 3, (BYTE)(n_volume) ); }
			}
		}
		FH8735_START_THREAD();
		*/
	}
	else if( pDevice->iManufacturer == 0xA0 ||
		
			 pDevice->iManufacturer == 0xA1 ||
			
			 pDevice->iManufacturer == 0xA2 ) {

		//FH8735_CLOSE_THREAD();
		AD96690602C7413AAC57A6B84A1747FE( pDevice );

		if( (nVolume & 0x0000FF00) == (0x0000FF00) ) { // FOR TOTAL

			ULONG n_volume = nVolume & 0x000000FF; 
			
			n_volume >>= 4;

			c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, 0xD0, (BYTE)((n_volume << 4) | (n_volume << 0)) );

			c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, 0xD1, (BYTE)((n_volume << 4) | (n_volume << 0)) );
		}
		else { // BY CHANNEL

			//ULONG n_channel = (nVolume >> 8) & (0x000000FF); n_channel %= 16;
			ULONG n_channel = channel;

			ULONG n_volume = (nVolume) & (0x000000FF);

			n_volume >>= 4;

			if( n_channel < 4 ) {

				if( n_channel == 0 ) { BYTE RD1 = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50, 0xD1 ); RD1 &= 0x0F; RD1 |= (n_volume << 4); c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, 0xD1, RD1 ); }

				if( n_channel == 1 ) { BYTE RD0 = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50, 0xD0 ); RD0 &= 0xF0; RD0 |= (n_volume << 0); c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, 0xD0, RD0 ); }

				if( n_channel == 2 ) { BYTE RD0 = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50, 0xD0 ); RD0 &= 0x0F; RD0 |= (n_volume << 4); c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, 0xD0, RD0 ); }

				if( n_channel == 3 ) { BYTE RD1 = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50, 0xD1 ); RD1 &= 0xF0; RD1 |= (n_volume << 0); c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, 0xD1, RD1 ); }
			}
		}
		//FH8735_START_THREAD();
		EBE5DCE0DB554397A79605FEA343FE27( pDevice );

	}
	return STATUS_SUCCESS;
}


ULONG d439bfca9ec846ea956d1bf0aa3adc45( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F919EED126B2940ce99A1F7F66A333338, ULONG F0FAB4549F1C3407aACDBD483D0D23C86 )
{
	if(F919EED126B2940ce99A1F7F66A333338 > 3)
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "d439bfca9ec846ea956d1bf0aa3adc45() F919EED126B2940ce99A1F7F66A333338(%d) out of ramge, error\n", F919EED126B2940ce99A1F7F66A333338 );
		return 0x00000000;
	}

	{ return readl( (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ) & 0xFFFFFFFF; }

/*
	if( F02179B6B95CB43eeB160478D8CF83778 == 4 ) { return READ_REGISTER_ULONG( (ULONG *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); }

	if( F02179B6B95CB43eeB160478D8CF83778 == 1 ) { return READ_REGISTER_UCHAR( (UCHAR *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); }
*/
	return 0x00000000;
}

BOOLEAN de288df0e76e4990be34b3bea95ca349( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F919EED126B2940ce99A1F7F66A333338, ULONG F0FAB4549F1C3407aACDBD483D0D23C86, ULONG F09894BF114FE4ee592C232BC39730E91 )
{
	if(F919EED126B2940ce99A1F7F66A333338 > 3)
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "d439bfca9ec846ea956d1bf0aa3adc45() F919EED126B2940ce99A1F7F66A333338(%d) out of ramge, error\n", F919EED126B2940ce99A1F7F66A333338 );
		return 0x00000000;
	}

	{ writel( (F09894BF114FE4ee592C232BC39730E91 & 0xFFFFFFFF), (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); }

/*
	if( F02179B6B95CB43eeB160478D8CF83778 == 4 ) { WRITE_REGISTER_ULONG( (ULONG *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86), (DWORD)(F09894BF114FE4ee592C232BC39730E91) ); }
	
	if( F02179B6B95CB43eeB160478D8CF83778 == 1 ) { WRITE_REGISTER_UCHAR( (UCHAR *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ F919EED126B2940ce99A1F7F66A333338 ] + F0FAB4549F1C3407aACDBD483D0D23C86), (UCHAR)(F09894BF114FE4ee592C232BC39730E91) ); }
*/
	return TRUE;
}

BOOLEAN FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
/*
	ULONG delay = (ULONG)(F6B9E557A4BA24ffd926B820B836289C8);

	ULONG _delay = ((delay / 10000) == 0) ? (1) : (delay / 10000);

	schedule_timeout_interruptible( msecs_to_jiffies( _delay ) );
*/

	wrapper_ndelay( F6B9E557A4BA24ffd926B820B836289C8 * 100 );
/*
	ULONGLONG start_times = FH8735_KsQuerySystemTime( pDevice );

	ULONGLONG stop_times = start_times;

	while( TRUE ) {

		if( stop_times - start_times > F6B9E557A4BA24ffd926B820B836289C8 ) { break; }

		stop_times = FH8735_KsQuerySystemTime( pDevice );
	}
*/
	return TRUE;
}


BYTE d9cfcb6942714b3291d4a65a75ba7691( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77 )
{
	// -----> fh35_api_i2c_read() -----> fh_i2c_read() -----> i2c_read() [2011.05.10]
	//
	ULONG OFFSET = (nDevNum == 0) ? 0x00000000 : 0x00100000;

	ULONG R04 = 0x00000000;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C + OFFSET, F3E85D87 & 0xFE );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 | 0x10 );

	ULONG i = 0;
	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%x d9cfcb6942714b3291d4a65a75ba7691( 1 ): GET REGISTER %02X ERROR!!\n", F3E85D87, F6B106280018F45d7A077070B88512C77); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C + OFFSET, F6B106280018F45d7A077070B88512C77 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 | 0x20 );

   	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%x d9cfcb6942714b3291d4a65a75ba7691( 2 ): GET REGISTER %02X ERROR!!\n", F3E85D87, F6B106280018F45d7A077070B88512C77); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C + OFFSET, F3E85D87 | 0x01 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 | 0x10 );

	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%x d9cfcb6942714b3291d4a65a75ba7691( 3 ): GET REGISTER %02X ERROR!!\n", F3E85D87, F6B106280018F45d7A077070B88512C77); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 | 0x40 | 0x20 );

   	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x20 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x20) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%x d9cfcb6942714b3291d4a65a75ba7691( 4 ): GET REGISTER %02X ERROR!!\n", F3E85D87, F6B106280018F45d7A077070B88512C77); return FALSE; }

	BYTE R = (BYTE)(d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x0020000C + OFFSET ));

	return R;
}

BYTE d9cfcb6942714b3291d4a65a75ba7691Ex( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BOOL * p_returns )
{
	// -----> fh35_api_i2c_read() -----> fh_i2c_read() -----> i2c_read() [2011.05.10]
	//
	ULONG OFFSET = (nDevNum == 0) ? 0x00000000 : 0x00100000;

	ULONG R04 = 0x00000000;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C + OFFSET, F3E85D87 & 0xFE );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 | 0x10 );
	
	ULONG i = 0 ;
	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "d9cfcb6942714b3291d4a65a75ba7691( 1 ): GET REGISTER %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77); if( p_returns ) { *p_returns = FALSE; } return 0x00; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C + OFFSET, F6B106280018F45d7A077070B88512C77 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 | 0x20 );

   	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "d9cfcb6942714b3291d4a65a75ba7691( 2 ): GET REGISTER %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77);  if( p_returns ) { *p_returns = FALSE; } return 0x00; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C + OFFSET, F3E85D87 | 0x01 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 | 0x10 );

	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "d9cfcb6942714b3291d4a65a75ba7691( 3 ): GET REGISTER %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77); if( p_returns ) { *p_returns = FALSE; } return 0x00; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 | 0x40 | 0x20 );

   	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x20 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x20) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "d9cfcb6942714b3291d4a65a75ba7691( 4 ): GET REGISTER %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77 ); if( p_returns ) { *p_returns = FALSE; } return 0x00; }

	BYTE R = (BYTE)(d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x0020000C + OFFSET ));

	if( p_returns ) { *p_returns = TRUE; } 

	return R;
}

BOOLEAN c944c15a33e6405babe73920d58a1fba( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, BYTE bValue )
{
	// -----> fh35_api_i2c_write() -----> fh_i2c_write() -----> i2c_write() [2011.05.10]
	//
	ULONG OFFSET = (nDevNum == 0) ? 0x00000000 : 0x00100000;

	ULONG R04 = 0x00000000;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C + OFFSET, F3E85D87 & 0xFE );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 | 0x10 );

	ULONG i = 0;
	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "c944c15a33e6405babe73920d58a1fba( 1 ): SET REGISTER %02X x %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77, bValue); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C + OFFSET, F6B106280018F45d7A077070B88512C77 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 );

	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x10 ) { break; } 

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "c944c15a33e6405babe73920d58a1fba( 2 ): SET REGISTER %02X x %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77, bValue); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C + OFFSET, bValue );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 | 0x20 );

   	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "c944c15a33e6405babe73920d58a1fba( 3 ): SET REGISTER %02X x %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77, bValue); return FALSE; }

	return TRUE;
}

BYTE d9cfcb6942714b3291d4a65a75ba7691_EX2( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE nBank, BYTE F6B106280018F45d7A077070B88512C77 )
{
	c944c15a33e6405babe73920d58a1fba( pDevice, nDevNum, F3E85D87, 0x00, nBank );

	return d9cfcb6942714b3291d4a65a75ba7691( pDevice, nDevNum, F3E85D87, F6B106280018F45d7A077070B88512C77 );
}


BOOLEAN c944c15a33e6405babe73920d58a1fba_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE nBank, BYTE F6B106280018F45d7A077070B88512C77, BYTE nValue )
{
	c944c15a33e6405babe73920d58a1fba( pDevice, nDevNum, F3E85D87, 0x00, nBank );

	return c944c15a33e6405babe73920d58a1fba( pDevice, nDevNum, F3E85D87, F6B106280018F45d7A077070B88512C77, nValue );
}

BYTE d836abc2d864435a9642168ecb38d9d1( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex )
{
	if( pDevice )
	{
		return d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x90, nIndex );
	}
	return 0;
}

BOOLEAN b3feca2851a644ada8021e7f3a60a61d( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, BYTE bValue )
{
	if( pDevice )
	{
		return c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x90, nIndex, bValue );
	}
	return 0;
}
BOOL d836abc2d864435a9642168ecb38d9d1_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, ULONG bBytes, BYTE * pValue ) 
{
	if( pDevice )
	{
		ULONG i = 0;
		for( i = 0 ; i < bBytes ; i++ ) {

			pValue[ i ] = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x90, (BYTE)(nIndex + i) );
		}
	}
	return TRUE;
}

BOOLEAN b3feca2851a644ada8021e7f3a60a61d_EX( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, ULONG bBytes, BYTE * pValue )
{
	if( pDevice )
	{
		ULONG i = 0;
		for( i = 0 ; i < bBytes ; i++ ) { 

			c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x90, (BYTE)(nIndex + i), pValue[ i ] );
		}
	}
	return TRUE;
}

USHORT FH8735_GetMcuRegister( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE F3E85D87, USHORT wIndex )
{
	ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 & ~(3 << 9) );

	// -----> fh35_api_i2c_read() -----> fh_i2c_read() -----> i2c_read() [2011.05.10]
	//
	ULONG R04 = 0x00000000;

	USHORT R = 0x00000000;

	ULONG i = 0;

	{	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, F3E85D87 & 0xFE );

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 | 0x10 );

		for( i = 0 ; i < 100 ; i++ ) {

			R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

			if( R04 & 0x10 ) { break; }

			FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 1 );
		}
		if( (R04 & 0x10) == (0x00) ) {F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735_GetMcuRegister( 1 ): GET REGISTER %04X ERROR!!\n", wIndex ); goto GET_ERROR; }
	}
	{	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, 0x27 );

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 );

   		for( i = 0 ; i < 100 ; i++ ) {

			R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

			if( R04 & 0x10 ) { break; }

			FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 1 );
		}
		if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735_GetMcuRegister( 2 ): GET REGISTER %04X ERROR!!\n", wIndex ); goto GET_ERROR; }
	}
	{	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, 0x02 );

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 );

   		for( i = 0 ; i < 100 ; i++ ) {

			R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

			if( R04 & 0x10 ) { break; }

			FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 1 );
		}
		if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735_GetMcuRegister( 3 ): GET REGISTER %04X ERROR!!\n", wIndex ); goto GET_ERROR; }
	}
	{	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, (BYTE)((wIndex & 0x00FF) >> 0) );

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 );

   		for( i = 0 ; i < 100 ; i++ ) {

			R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

			if( R04 & 0x10 ) { break; }

			FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 1 );
		}
		if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735_GetMcuRegister( 4 ): GET REGISTER %04X ERROR!!\n", wIndex ); goto GET_ERROR; }
	}
	{	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, (BYTE)((wIndex & 0xFF00) >> 8) );

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 | 0x20 );

   		for( i = 0 ; i < 100 ; i++ ) {

			R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

			if( R04 & 0x10 ) { break; }

			FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 1 );
		}
		if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735_GetMcuRegister( 5 ): GET REGISTER %04X ERROR!!\n", wIndex ); goto GET_ERROR; }
	}
	//////////////////////////////////////////////////////////////////

	{	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, F3E85D87 | 0x01 );

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 | 0x10 );

		for( i = 0 ; i < 100 ; i++ ) {

			R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

			if( R04 & 0x10 ) { break; }

			FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 1 );
		}
		if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735_GetMcuRegister( 6 ): GET REGISTER %04X ERROR!!\n", wIndex ); goto GET_ERROR; }
	}
	{	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 );

   		for( i = 0 ; i < 100 ; i++ ) {

			R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

			if( R04 & 0x20 ) { break; }

			FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 1 );
		}
		if( (R04 & 0x20) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735_GetMcuRegister( 7 ): GET REGISTER %04X ERROR!!\n", wIndex ); goto GET_ERROR; }

		R  = (USHORT)((d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x0020000C ) & 0x00FF) << 0);
	}
	{	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 | 0x40 | 0x20 );

   		for( i = 0 ; i < 100 ; i++ ) {

			R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

			if( R04 & 0x20 ) { break; }

			FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 1 );
		}
		if( (R04 & 0x20) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735_GetMcuRegister( 8 ): GET REGISTER %04X ERROR!!\n", wIndex ); goto GET_ERROR; }

		R |= (USHORT)((d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x0020000C ) & 0x00FF) << 8);
	}
	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );

	return R;

GET_ERROR:

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );

	return 0x0000;
}

DWORD FH8735_SetMcuRegister( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE F3E85D87, USHORT wIndex, USHORT wValue )
{
	ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 & ~(3 << 9) );

	// -----> fh35_api_i2c_write() -----> fh_i2c_write() -----> i2c_write() [2011.05.10]
	//
	ULONG R04 = 0x00000000;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, F3E85D87 & 0xFE );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 | 0x10 );

	ULONG i = 0;
	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735_SetMcuRegister( 1 ): SET REGISTER %04X × %04X ERROR!!\n", wIndex, wValue ); goto SET_ERROR; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, (BYTE)((wIndex & 0xFF00) >> 0) );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 );

	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x10 ) { break; } 

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735_SetMcuRegister( 2 ): SET REGISTER %04X × %04X ERROR!!\n", wIndex, wValue ); goto SET_ERROR; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, (BYTE)((wIndex & 0xFF00) >> 8) );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 );

	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x10 ) { break; } 

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735_SetMcuRegister( 3 ): SET REGISTER %04X × %04X ERROR!!\n", wIndex, wValue ); goto SET_ERROR; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, (BYTE)((wValue & 0x00FF) >> 0) );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 );

   	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735_SetMcuRegister( 4 ): SET REGISTER %04X × %04X ERROR!!\n", wIndex, wValue ); goto SET_ERROR; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, (BYTE)((wValue & 0xFF00) >> 8) );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 | 0x20 );

   	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735_SetMcuRegister( 5 ): SET REGISTER %04X × %04X ERROR!!\n", wIndex, wValue ); goto SET_ERROR; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );

	return TRUE;

SET_ERROR:

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );

	return FALSE;
}

BYTE FH8735_GetTW9910Register( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex )
{
	return d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x88 , nIndex );
}

BOOLEAN FH8735_SetTW9910Register( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, BYTE bValue )
{
	return c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x88, nIndex, bValue );
}

DWORD d1160c83c26f4172bd37a04937ca2f52( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77 )
{
	ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 & ~(3 << 9) );

	// -----> fh35_api_i2c_read() -----> fh_i2c_read() -----> i2c_read() [2011.05.10]
	//
	ULONG R04 = 0x00000000;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, F3E85D87 & 0xFE );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 | 0x10 );

	ULONG i = 0;
	for( i = 0 ; i < 100 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice,  1 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "d1160c83c26f4172bd37a04937ca2f52( 1 ): GET REGISTER %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, F6B106280018F45d7A077070B88512C77 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 | 0x20 );

   	for( i = 0 ; i < 100 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice,  1 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "d1160c83c26f4172bd37a04937ca2f52( 2 ): GET REGISTER %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, F3E85D87 | 0x01 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 | 0x10 );

	for( i = 0 ; i < 100 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice,  1 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "d1160c83c26f4172bd37a04937ca2f52( 3 ): GET REGISTER %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 );

   	for( i = 0 ; i < 100 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x20 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice,  1 );
	}
	if( (R04 & 0x20) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "d1160c83c26f4172bd37a04937ca2f52( 4 ): GET REGISTER %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77); return FALSE; }

	DWORD R = (d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x0020000C ) & 0x000000FF) << 24;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 );

   	for( i = 0 ; i < 100 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x20 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice,  1 );
	}
	if( (R04 & 0x20) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "d1160c83c26f4172bd37a04937ca2f52( 5 ): GET REGISTER %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77); return FALSE; }

	R |= (d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x0020000C ) & 0x000000FF) << 16;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 );

   	for( i = 0 ; i < 100 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x20 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice,  1 );
	}
	if( (R04 & 0x20) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "d1160c83c26f4172bd37a04937ca2f52( 6 ): GET REGISTER %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77); return FALSE; }

	R |= (d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x0020000C ) & 0x000000FF) << 8;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 | 0x40 | 0x20 );

   	for( i = 0 ; i < 100 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x20 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice,  1 );
	}
	if( (R04 & 0x20) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "d1160c83c26f4172bd37a04937ca2f52( 7 ): GET REGISTER %02X ERROR!!\n", F6B106280018F45d7A077070B88512C77); return FALSE; }

	R |= (d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x0020000C ) & 0x000000FF) << 0;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );

	return R;

GET_ERROR:

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );

	return 0x00000000;
}

DWORD efe5167da2ce4bc19feed78640f21063( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE F3E85D87, BYTE F6B106280018F45d7A077070B88512C77, DWORD F09894BF114FE4ee592C232BC39730E91 )
{
	ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 & ~(3 << 9) );

	// -----> fh35_api_i2c_write() -----> fh_i2c_write() -----> i2c_write() [2011.05.10]
	//
	ULONG R04 = 0x00000000;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, F3E85D87 & 0xFE );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 | 0x10 );

	ULONG i = 0;
	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "efe5167da2ce4bc19feed78640f21063( 1 ): SET REGISTER %02X x %08X ERROR!!\n", F6B106280018F45d7A077070B88512C77, F09894BF114FE4ee592C232BC39730E91); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, F6B106280018F45d7A077070B88512C77 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 );

	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x10 ) { break; } 

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "efe5167da2ce4bc19feed78640f21063( 2 ): SET REGISTER %02X x %08X ERROR!!\n", F6B106280018F45d7A077070B88512C77, F09894BF114FE4ee592C232BC39730E91); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, (BYTE)((F09894BF114FE4ee592C232BC39730E91 & 0x000000FF) >> 0) );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 );

   	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "efe5167da2ce4bc19feed78640f21063( 3 ): SET REGISTER %02X x %08X ERROR!!\n", F6B106280018F45d7A077070B88512C77, F09894BF114FE4ee592C232BC39730E91); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, (BYTE)((F09894BF114FE4ee592C232BC39730E91 & 0x0000FF00) >> 8) );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 );

   	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "efe5167da2ce4bc19feed78640f21063( 4 ): SET REGISTER %02X x %08X ERROR!!\n", F6B106280018F45d7A077070B88512C77, F09894BF114FE4ee592C232BC39730E91); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, (BYTE)((F09894BF114FE4ee592C232BC39730E91 & 0x00FF0000) >> 16) );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 );

   	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "efe5167da2ce4bc19feed78640f21063( 5 ): SET REGISTER %02X x %08X ERROR!!\n", F6B106280018F45d7A077070B88512C77, F09894BF114FE4ee592C232BC39730E91); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C, (BYTE)((F09894BF114FE4ee592C232BC39730E91 & 0xFF000000) >> 24) );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x02 | 0x04 | 0x80 | 0x20 );

   	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "efe5167da2ce4bc19feed78640f21063( 6 ): SET REGISTER %02X x %08X ERROR!!\n", F6B106280018F45d7A077070B88512C77, F09894BF114FE4ee592C232BC39730E91); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );

	return TRUE;

SET_ERROR:

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );

	return FALSE;
}

BYTE f385217a66354b98bbcf13b193cb54d6( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87 )
{
	// -----> fh35_api_i2c_read() -----> fh_i2c_read() -----> i2c_read() [2011.05.10]
	//
	ULONG OFFSET = (nDevNum == 0) ? 0x00000000 : 0x00100000;

	ULONG R04 = 0x00000000;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C + OFFSET, F3E85D87 | 0x01 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 | 0x10 );

	ULONG i = 0;
	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "f385217a66354b98bbcf13b193cb54d6( 1 ): GET REGISTER ERROR!!\n"); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 | 0x40 | 0x20 );

   	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x20 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x20) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "f385217a66354b98bbcf13b193cb54d6( 2 ): GET REGISTER ERROR!!\n"); return FALSE; }

	BYTE R = (BYTE)(d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x0020000C + OFFSET ));

	return R;
}

BOOLEAN bde2191b41de49a5bdd64acc79f9ea2c( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nDevNum, BYTE F3E85D87, BYTE bValue )
{
	// -----> fh35_api_i2c_write() -----> fh_i2c_write() -----> i2c_write() [2011.05.10]
	//
	ULONG OFFSET = (nDevNum == 0) ? 0x00000000 : 0x00100000;

	ULONG R04 = 0x00000000;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C + OFFSET, F3E85D87 & 0xFE );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 | 0x10 );

	ULONG i = 0 ;
	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "bde2191b41de49a5bdd64acc79f9ea2c( 1 ): SET REGISTER %02X ERROR!!\n", bValue); return FALSE; }

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0020000C + OFFSET, bValue );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000 + OFFSET, 0x02 | 0x04 | 0x80 | 0x20 );

   	for( i = 0 ; i < 1000 ; i++ ) {

		R04 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00200004 + OFFSET );

		if( R04 & 0x10 ) { break; }

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 125 );
	}
	if( (R04 & 0x10) == (0x00) ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "bde2191b41de49a5bdd64acc79f9ea2c( 2 ): SET REGISTER %02X ERROR!!\n", bValue); return FALSE; }

	return TRUE;
}

VOID FH8735_F69DBADFDE7C4448fA5C5E95F4DC00E1E( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE DATA, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 ); R00700000 &= 0xFFFFFFFB;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 | (DATA << 2) );
	
	FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, F6B9E557A4BA24ffd926B820B836289C8 );	
/*
	ULONGLONG start_times = FH8735_KsQuerySystemTime( pDevice );

	ULONGLONG stop_times = start_times;

	while( TRUE ) {

		if( stop_times - start_times > F6B9E557A4BA24ffd926B820B836289C8 ) { break; }

		stop_times = FH8735_KsQuerySystemTime( pDevice );
	}
*/
}

VOID FH8735_F17905ED7D5754d2f948B78DE2E19357B( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE DATA, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 ); R00700000 &= 0xFFFFFFF7;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 | (DATA << 3) );

	FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, F6B9E557A4BA24ffd926B820B836289C8 );	

/*
	ULONGLONG start_times = FH8735_KsQuerySystemTime( pDevice );

	ULONGLONG stop_times = start_times;

	while( TRUE ) {

		if( stop_times - start_times > F6B9E557A4BA24ffd926B820B836289C8 ) { break; }

		stop_times = FH8735_KsQuerySystemTime( pDevice );
	}
*/
}

VOID FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE DATA, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 ) 
{
	BYTE SCL = (DATA >> 0) & (0x01);

	BYTE SDA = (DATA >> 1) & (0x01);

	ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 ); R00700000 &= 0xFFFFFFF3;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 | (SDA << 3) | (SCL << 2) );

	FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, F6B9E557A4BA24ffd926B820B836289C8 );	
/*
	ULONGLONG start_times = FH8735_KsQuerySystemTime( pDevice );

	ULONGLONG stop_times = start_times;

	while( TRUE ) {

		if( stop_times - start_times > F6B9E557A4BA24ffd926B820B836289C8 ) { break; }

		stop_times = FH8735_KsQuerySystemTime( pDevice );
	}
*/
}

BYTE FH8735_F8B11D4E6664C424dA74D592AB89DC1CA( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 ) 
{
	BYTE DATA = 0x00;

	FH8735_F17905ED7D5754d2f948B78DE2E19357B( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );

	ULONG R00700008 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000008 ); R00700008 &= 0xFFFFFFF7;

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000008, R00700008 );

	FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, F6B9E557A4BA24ffd926B820B836289C8 );	
/*
	{	ULONGLONG start_times = FH8735_KsQuerySystemTime( pDevice );

		ULONGLONG stop_times = start_times;

		while( TRUE ) {

			if( stop_times - start_times > F6B9E557A4BA24ffd926B820B836289C8 ) { break; }

			stop_times = FH8735_KsQuerySystemTime( pDevice );
		}
	}
*/
	ULONG R00700004 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000004 ); R00700004 >>= 3; R00700004 &= 0x00000001; DATA = (BYTE)(R00700004);

	FH8735_F69DBADFDE7C4448fA5C5E95F4DC00E1E( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );

	FH8735_F69DBADFDE7C4448fA5C5E95F4DC00E1E( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000008, R00700008 | 0x00000008 );

	FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, F6B9E557A4BA24ffd926B820B836289C8 );	

	return DATA;
}

BOOL FH8735_F8B7FB94CF24D4152842C9743714CDAA9( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	FH8735_F17905ED7D5754d2f948B78DE2E19357B( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 ); // //

	FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 3, F6B9E557A4BA24ffd926B820B836289C8 ); //

	FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 ); // //

	FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 ); //

	return TRUE;
}

BOOL FH8735_F1C002401C7AE4334A36AC1B1E338AD75( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	FH8735_F69DBADFDE7C4448fA5C5E95F4DC00E1E( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 ); //

	FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 ); // //

	FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 ); //

	FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 3, F6B9E557A4BA24ffd926B820B836289C8 ); //

	return TRUE;
}

BOOL FH8735_F2E93DF3F52A04c9dACD486D8609988F3( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{	
#if 1

	BYTE ACK = FH8735_F8B11D4E6664C424dA74D592AB89DC1CA( pDevice, F6B9E557A4BA24ffd926B820B836289C8 ); //

#else

//	FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );         // 

	FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 3, F6B9E557A4BA24ffd926B820B836289C8 );         //

	BYTE ACK = FH8735_F8B11D4E6664C424dA74D592AB89DC1CA( pDevice, F6B9E557A4BA24ffd926B820B836289C8 ); //

	FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );         //

#endif

	return (ACK == 0) ? TRUE : FALSE;                //
}

BOOL FH8735_F76CEC38463124e7790A43B09F0D38227( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE ACK, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, (ACK) ? 2 : 0, F6B9E557A4BA24ffd926B820B836289C8 ); //

	FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, (ACK) ? 3 : 1, F6B9E557A4BA24ffd926B820B836289C8 ); //

	FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, (ACK) ? 2 : 0, F6B9E557A4BA24ffd926B820B836289C8 ); //

	return TRUE;
}

BOOL FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE DATA, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	UINT i = 0;
	for( i = 0 ; i < 8 ; i++, DATA <<= 1 ) {                    //

		FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, (DATA & 0x80) ? 2 : 0, F6B9E557A4BA24ffd926B820B836289C8 ); //

		FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, (DATA & 0x80) ? 3 : 1, F6B9E557A4BA24ffd926B820B836289C8 ); //

		FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, (DATA & 0x80) ? 2 : 0, F6B9E557A4BA24ffd926B820B836289C8 ); //
	}
	return FH8735_F2E93DF3F52A04c9dACD486D8609988F3( pDevice, F6B9E557A4BA24ffd926B820B836289C8 );                    //
}

BYTE FH8735_F6E9556EF6B7D45fbB367C7EF7BF65BFB( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE ACK, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{	
	BYTE DATA = 0x00;

#if 1
	UINT i = 0;

	for( i = 0 ; i < 8 ; i++ ) {                              //

		DATA = (DATA << 1) | FH8735_F8B11D4E6664C424dA74D592AB89DC1CA( pDevice, F6B9E557A4BA24ffd926B820B836289C8 ); //
	}
#else
	UINT i = 0;
	for( i = 0 ; i < 8 ; i++ ) {                              //

		FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );				   //

		DATA = (DATA << 1) | FH8735_F8B11D4E6664C424dA74D592AB89DC1CA( pDevice, F6B9E557A4BA24ffd926B820B836289C8 ); //

		FH8735_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );				   //
	}
#endif

	FH8735_F76CEC38463124e7790A43B09F0D38227( pDevice, ACK, F6B9E557A4BA24ffd926B820B836289C8 );                   //

	return DATA;
}

VOID FH8735_GSPI_SET_SCLK( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE DATA, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 ); R00700000 &= ~0x00008000; R00700000 |= (DATA << 15);

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );

	FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, F6B9E557A4BA24ffd926B820B836289C8 );	

/*
	ULONGLONG start_times = FH8735_KsQuerySystemTime( pDevice );

	ULONGLONG stop_times = start_times;

	while( TRUE ) {

		if( stop_times - start_times > F6B9E557A4BA24ffd926B820B836289C8 ) { break; }

		stop_times = FH8735_KsQuerySystemTime( pDevice );
	}
*/
}

VOID FH8735_GSPI_SET_CS( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE DATA, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 ); R00700000 &= ~0x00000800; R00700000 |= (DATA << 11);

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );

	FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, F6B9E557A4BA24ffd926B820B836289C8 );	

/*
	ULONGLONG start_times = FH8735_KsQuerySystemTime( pDevice );

	ULONGLONG stop_times = start_times;

	while( TRUE ) {

		if( stop_times - start_times > F6B9E557A4BA24ffd926B820B836289C8 ) { break; }

		stop_times = FH8735_KsQuerySystemTime( pDevice );
	}
*/
}

VOID FH8735_GSPI_SET_SDIN( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE DATA, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 ); R00700000 &= ~0x00004000; R00700000 |= (DATA << 14);

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );

	FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, F6B9E557A4BA24ffd926B820B836289C8 );	

/*
	ULONGLONG start_times = FH8735_KsQuerySystemTime( pDevice );

	ULONGLONG stop_times = start_times;

	while( TRUE ) {

		if( stop_times - start_times > F6B9E557A4BA24ffd926B820B836289C8 ) { break; }

		stop_times = FH8735_KsQuerySystemTime( pDevice );
	}
*/
}

BYTE FH8735_GSPI_GET_SDOUT( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	ULONG R00700004 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000004 ); R00700004 >>= 13; // GPIO.RD

	FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, F6B9E557A4BA24ffd926B820B836289C8 );	

/*
	ULONGLONG start_times = FH8735_KsQuerySystemTime( pDevice );

	ULONGLONG stop_times = start_times;

	while( TRUE ) {

		if( stop_times - start_times > F6B9E557A4BA24ffd926B820B836289C8 ) { break; }

		stop_times = FH8735_KsQuerySystemTime( pDevice );
	}
*/
	return (BYTE)(R00700004 & 0x00000001);
}

BOOL FH8735_GSPI_WRITE_WORD( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, USHORT wAddress, USHORT wValue, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	wAddress &= 0x0FFF;

	FH8735_GSPI_SET_SCLK( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );

	FH8735_GSPI_SET_CS( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );

	FH8735_GSPI_SET_CS( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );

	ULONG i = 0;
	for( i = 0 ; i < 16 ; i++ ) {

		BYTE DATA = (wAddress >> (15 - i)) & (0x01);

		FH8735_GSPI_SET_SDIN( pDevice, DATA, F6B9E557A4BA24ffd926B820B836289C8 );

		FH8735_GSPI_SET_SCLK( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );

		FH8735_GSPI_SET_SCLK( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );
	}
	FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice,  1 ); // 50NS

	for( i = 0 ; i < 16 ; i++ ) {

		BYTE DATA = (wValue >> (15 - i)) & (0x01);

		FH8735_GSPI_SET_SDIN( pDevice, DATA, F6B9E557A4BA24ffd926B820B836289C8 );

		FH8735_GSPI_SET_SCLK( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );

		FH8735_GSPI_SET_SCLK( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );
	}
	FH8735_GSPI_SET_SCLK( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );

	FH8735_GSPI_SET_CS( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );

	return TRUE;
}

USHORT FH8735_GSPI_READ_WORD( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, USHORT wAddress, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	USHORT wValue = 0x0000;

	wAddress &= 0x0FFF;

	wAddress |= 0x8000;

	FH8735_GSPI_SET_SCLK( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );

	FH8735_GSPI_SET_CS( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );

	FH8735_GSPI_SET_CS( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );

	ULONG i = 0;
	for( i = 0 ; i < 16 ; i++ ) {

		BYTE DATA = (wAddress >> (15 - i)) & (0x01);

		FH8735_GSPI_SET_SDIN( pDevice, DATA, F6B9E557A4BA24ffd926B820B836289C8 );

		FH8735_GSPI_SET_SCLK( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );

		FH8735_GSPI_SET_SCLK( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );
	}
	FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice,  2 ); // 200NS

	for( i = 0 ; i < 16 ; i++ ) {

		FH8735_GSPI_SET_SCLK( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );

		USHORT DATA = FH8735_GSPI_GET_SDOUT( pDevice, F6B9E557A4BA24ffd926B820B836289C8 );

		wValue |= DATA << (15 - i);

		FH8735_GSPI_SET_SCLK( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );
	}
	FH8735_GSPI_SET_SCLK( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );

	FH8735_GSPI_SET_CS( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );

	return wValue;
}

// ##############################################################################################################################################################################
//
BOOLEAN a3f0127f4f5a4c1a9eabc48e449787e4( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
	
	#ifndef FH8735_JTAG_DEBUG
	
	if( 0 == wait_event_interruptible_timeout( pDevice->m_wait_queue_head, pDevice->EA72172D8A27470AA2580EC509460D34 == 1, wrapper_msecs_to_jiffies( 2000 ) )){
	
	#else
	
	if( 0 == wait_event_interruptible_timeout( pDevice>m_wait_queue_head, pDevice->EA72172D8A27470AA2580EC509460D34 == 1, wrapper_msecs_to_jiffies( 60000 ) )){
	
	#endif

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%d]a3f0127f4f5a4c1a9eabc48e449787e4() time out\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );
		
		return FALSE;
	} 
	else { 
		
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%d]a3f0127f4f5a4c1a9eabc48e449787e4() success\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );
		
		wrapper_down( &(pDevice->B170D6CC53FA433DB899522A0B0325FC) ); 

		pDevice->EA72172D8A27470AA2580EC509460D34 = 0;

		wrapper_up( &(pDevice->B170D6CC53FA433DB899522A0B0325FC) ); 

		return TRUE;
	} 
}

BOOLEAN aafd0c9462784a14a89d8308fa9ca1cb( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nCommand, ULONG nParameter )
{
	// -----> fh35_api_do_cmd() [2012.03.29]
	//
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%d]aafd0c9462784a14a89d8308fa9ca1cb() nCommand(0x%x) nParameter(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, nCommand, nParameter );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400004, nParameter );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400000, nCommand );

	return a3f0127f4f5a4c1a9eabc48e449787e4( pDevice );
}

unsigned int d6c33b6bbb4747f88d57cbd62a9ff0f8( unsigned int cksum, unsigned int * p, unsigned int size )
{
	unsigned int csum = cksum;
	
	unsigned int i = 0;
	for( i = 0; i < size ; i++ ) {

		csum ^= *(p++);
	}
	return csum;
}

BOOLEAN bced4c8b1fb3402f943441f7756c19c7( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, char* pwszFileName, ULONG nFileType, ULONG * pFileSize )
{
	FH8735_SYS_CFG *  p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	BYTE *            pFileBuffer = NULL;

	ULONG             nFileSize = 0;

	if(nFileType == 0)
	{
		pFileBuffer = FH8735_ASC32;
		nFileSize = sizeof(FH8735_ASC32);
	}
	else
	{
		pFileBuffer = FH8735_HZK32;
		nFileSize = sizeof(FH8735_HZK32);
	}

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

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "bdf43d878de74697b7ecfc1897feff4f( \"%ws\" )\n", wszPathName) );

	// 1.0 OPEN FONT LIBRARY *.DAT FILE
	// 
	oFileName.MaximumLength = wcslen(wszPathName) * 2 + sizeof(UNICODE_NULL);

	oFileName.Buffer = (PWSTR)(ExAllocatePool( PagedPool, oFileName.MaximumLength ));

	oFileName.Length = 0;

    if( oFileName.Buffer == NULL ) {

        return FALSE;
    }
	else {

		RtlZeroMemory( oFileName.Buffer, oFileName.MaximumLength );
	}
	status = RtlAppendUnicodeToString( &oFileName, wszPathName );

	InitializeObjectAttributes( (POBJECT_ATTRIBUTES)(&oObjectAttributes), (PUNICODE_STRING)(&oFileName), OBJ_CASE_INSENSITIVE, NULL, NULL );

	status = ZwCreateFile( &hFileHandle, FILE_READ_DATA, &oObjectAttributes, &oIoStatus, 0, FILE_ATTRIBUTE_NORMAL, FILE_SHARE_READ, FILE_OPEN, FILE_SYNCHRONOUS_IO_NONALERT, NULL, 0 );

	FREE_MEMORY( oFileName.Buffer );

	if( NT_SUCCESS(status) ) {

		FILE_STANDARD_INFORMATION oFileStandardInfomation;

		ZwQueryInformationFile( hFileHandle, &oIoStatus, &oFileStandardInfomation, sizeof(FILE_STANDARD_INFORMATION), FileStandardInformation );

		nFileSize = (ULONG)(oFileStandardInfomation.EndOfFile.QuadPart);

		pFileBuffer = (BYTE *)(ExAllocatePool( PagedPool, nFileSize ));

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
*/
	struct timeval ts;

	ULONGLONG stop_times = 0;

	// 2.0 DOWNLOAD FONT CONTENT
	// 
	wrapper_do_gettimeofday( &ts );

	ULONGLONG start_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);

	if( nFileType == 0x00000000 ) { memcpy( p_sys_cfg->chip_cfg.ASC, pFileBuffer, nFileSize ); }

	if( nFileType == 0x00000001 ) { memcpy( p_sys_cfg->chip_cfg.CHN, pFileBuffer, nFileSize ); }
	
	wrapper_do_gettimeofday( &ts );

	stop_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] - TOTAL FONT DOWNLOAD TIMES = %08d (%d BYTES)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, (ULONG)(stop_times - start_times), nFileSize );

	// 3.0 FREE WORKING BUFFER
	//
	
//	FREE( pFileBuffer );

   *pFileSize = nFileSize;

	return TRUE;
}
BYTE font_lib[ (sizeof(req_font_lib) + 1046790 + 3 ) & (~3) ];

BOOLEAN bdf43d878de74697b7ecfc1897feff4f( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	ULONG asc_len = 0;

	ULONG chn_len = 0;

	if( FALSE == bced4c8b1fb3402f943441f7756c19c7( pDevice, (char*)L"FH8735.ASC32.DAT", 0, &asc_len ) ) { asc_len = 0; }

	if( FALSE == bced4c8b1fb3402f943441f7756c19c7( pDevice, (char*)L"FH8735.HZK32.DAT", 1, &chn_len ) ) { chn_len = 0; }

	// -----> fh35_api_set_font_lib() [2012.03.29]
	//
	BOOLEAN returns = TRUE;

	{	FH8735_SYS_CFG *  p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		//req_font_lib * p_font_lib = (req_font_lib *)(wrapper_kmalloc( (sizeof(req_font_lib) + chn_len + 3) & (~3), GFP_KERNEL ));
		
		req_font_lib * p_font_lib = (req_font_lib *)(font_lib);

		p_font_lib->cmd = 0x0000002D;

		memcpy( p_font_lib->ASC, p_sys_cfg->chip_cfg.ASC, asc_len ); 

		memcpy( p_font_lib->CHN, p_sys_cfg->chip_cfg.CHN, chn_len ); 
	
		p_font_lib->asc_len = asc_len;

		p_font_lib->chn_len = chn_len;

		UINT * po = (UINT *)(p_font_lib);

		UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

		ULONG counts = (sizeof(req_font_lib) + chn_len + 3) & (~3);

		ULONG c = 0;
		for( c = 0 ; c < counts ; c += 4 ) {

			de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

			pe += 4;

			po++;
		}
		returns = aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000002D, 0 ); // HCMD_SET_FONT_LIB

		//FREE( p_font_lib );
	}
	return returns;
}


BOOLEAN c170e8e0c7a7462e87430cd552fc6e11( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG j )
{
	FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

	// -----> fh35_api_vi_config_apply() -----> ch_vi_config_apply() [2012.03.29]
	//
	BOOLEAN returns = TRUE;

	{	req_channel_vi_config s_req_channel_vi_config;

		s_req_channel_vi_config.channel = j;

		s_req_channel_vi_config.cmd = 0x00000031;

//		RtlCopyMemory( &(s_req_channel_vi_config.viu_cfg), &(p_ch_cfg->viu_cfg), sizeof(viu_ch_cfg_t) );

		memcpy( &(s_req_channel_vi_config.viu_cfg), &(p_ch_cfg->viu_cfg), sizeof(viu_ch_cfg_t) );

		UINT * po = (UINT *)(&s_req_channel_vi_config);

		UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

		ULONG c = 0;
		for( c = 0 ; c < sizeof(req_channel_vi_config) ; c += 4 ) {

			de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

			pe += 4;

			po++;
		}
		returns = aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000031, j ); // HCMD_SET_CHANNEL_VI_CONFIG
	}
	return returns;
}

BOOLEAN E156F44F113047C9A305A00A4AE8D4DA( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	if( pDevice->iManufacturer == 0x85 ) {

		if( FH8735_JTAG_HYBRID == 0 ) { p_sys_cfg->chip_cfg.vi_input_mode[ 0 ] = 0x0000; } // SD

		if( FH8735_JTAG_HYBRID == 1 ) { p_sys_cfg->chip_cfg.vi_input_mode[ 0 ] = 0x0000; } // SD

		if( FH8735_JTAG_HYBRID == 2 ) { p_sys_cfg->chip_cfg.vi_input_mode[ 0 ] = 0xFFFF; } // NONE

		if( FH8735_JTAG_HYBRID == 0 ) { p_sys_cfg->chip_cfg.vi_input_mode[ 1 ] = 0x0002; } // HD

		if( FH8735_JTAG_HYBRID == 1 ) { p_sys_cfg->chip_cfg.vi_input_mode[ 1 ] = 0xFFFF; } // NONE

		if( FH8735_JTAG_HYBRID == 2 ) { p_sys_cfg->chip_cfg.vi_input_mode[ 1 ] = 0x0002; } // HD

		if( pDevice->m_nCustomAnalogVideoResolutionProperty == 0 ) {

			p_sys_cfg->chip_cfg.vi_input_mode[ 1 ] = 0xFFFF;
		}
		p_sys_cfg->chip_cfg.hd_attr[ 1 ].sync_mode = 0;

		p_sys_cfg->chip_cfg.hd_attr[ 1 ].crin_mode = 1; // VI_CRIN_BT656 = 0 / VI_HD_16BIT_YCBCR = 1 / VI_HD_24BIT_YCBCR = 2 / VI_HD_24BIT_RGB = 3

		p_sys_cfg->chip_cfg.hd_attr[ 1 ].sample_mode = 0;

		p_sys_cfg->chip_cfg.hd_attr[ 1 ].rgb_mode = 1;

		p_sys_cfg->chip_cfg.hd_attr[ 1 ].rgb_range = 1;
	}
	else if( (pDevice->iProduct & 0x0F) == (0x05) || (pDevice->iProduct & 0x0F) == (0x07) ) {

		p_sys_cfg->chip_cfg.vi_input_mode[ 0 ] = 0xFFFF;

		p_sys_cfg->chip_cfg.hd_attr[ 0 ].sync_mode = 0;

		p_sys_cfg->chip_cfg.hd_attr[ 0 ].crin_mode = 1; // VI_CRIN_BT656 = 0 / VI_HD_16BIT_YCBCR = 1 / VI_HD_24BIT_YCBCR = 2 / VI_HD_24BIT_RGB = 3

		p_sys_cfg->chip_cfg.hd_attr[ 0 ].sample_mode = 0;

		p_sys_cfg->chip_cfg.hd_attr[ 0 ].rgb_mode = 1;

		p_sys_cfg->chip_cfg.hd_attr[ 0 ].rgb_range = 1;

		p_sys_cfg->chip_cfg.vi_input_mode[ 1 ] = 0xFFFF;

		if(pDevice->iManufacturer == 0x8A)
		{
			p_sys_cfg->chip_cfg.hd_attr[ 0 ].sync_mode = 0;

			p_sys_cfg->chip_cfg.hd_attr[ 1 ].sync_mode = 0;
		}
		else
		{
			if( p_sys_cfg->n_input_video_resolution_cy == 240 ||

				p_sys_cfg->n_input_video_resolution_cy == 288 ) {

				p_sys_cfg->chip_cfg.hd_attr[ 1 ].sync_mode = 1;
			}
			else {

				p_sys_cfg->chip_cfg.hd_attr[ 1 ].sync_mode = 0;
			}
		}
		p_sys_cfg->chip_cfg.hd_attr[ 1 ].crin_mode = 1; // VI_CRIN_BT656 = 0 / VI_HD_16BIT_YCBCR = 1 / VI_HD_24BIT_YCBCR = 2 / VI_HD_24BIT_RGB = 3

		p_sys_cfg->chip_cfg.hd_attr[ 1 ].sample_mode = 0;

		p_sys_cfg->chip_cfg.hd_attr[ 1 ].rgb_mode = 1;

		p_sys_cfg->chip_cfg.hd_attr[ 1 ].rgb_range = 1;

		if( pDevice->iManufacturer == 0x8A ||
			
			pDevice->iManufacturer == 0x8B ) {

			p_sys_cfg->chip_cfg.vi_input_mode[ 0 ] = 0xFFFF;

			p_sys_cfg->chip_cfg.vi_input_mode[ 1 ] = 2;
		}
		else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

			p_sys_cfg->chip_cfg.vi_input_mode[ 0 ] = 0xFFFF;

			p_sys_cfg->chip_cfg.vi_input_mode[ 1 ] = 2;
		}
		else {

			p_sys_cfg->chip_cfg.vi_input_mode[ 0 ] = 2;

			p_sys_cfg->chip_cfg.vi_input_mode[ 1 ] = 0xFFFF;
		}
	}
	else {

		p_sys_cfg->chip_cfg.vi_input_mode[ 0 ] = 0;

		p_sys_cfg->chip_cfg.vi_input_mode[ 1 ] = 0;
	}

	// -----> fh35_api_vi_set_input_mode() -----> chip_vi_set_input_mode() [2012.03.29]
	//
	{	req_input_mode s_input_mode;

		s_input_mode.cmd = 0x0000002F;

		s_input_mode.groupAmode = p_sys_cfg->chip_cfg.vi_input_mode[ 0 ];

		s_input_mode.groupBmode = p_sys_cfg->chip_cfg.vi_input_mode[ 1 ];

		UINT * po = (UINT *)(&s_input_mode);

		UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

		ULONG c = 0;
		for( c = 0 ; c < sizeof(req_input_mode) ; c += 4 ) {

			de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

			pe += 4;

			po++;
		}
		aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000002F, 0 ); // HCMD_SET_CHIP_VI_INPUT_MODE
	}

	// -----> fh35_api_vi_set_hd_mode() -----> chip_vi_set_hd_mode() [2012.03.29]
	//
	ULONG i = 0;
	for( i = 0 ; i < 2 ; i++ ) {

		if( p_sys_cfg->chip_cfg.vi_input_mode[ i ] != 2 ) { continue ; }

		req_hd_mode s_hd_mode;

		s_hd_mode.group = i;

		s_hd_mode.cmd = 0x00000030;
		
		s_hd_mode.hd_attr.crin_mode = p_sys_cfg->chip_cfg.hd_attr[ i ].crin_mode;

		s_hd_mode.hd_attr.rgb_mode = p_sys_cfg->chip_cfg.hd_attr[ i ].rgb_mode;

		s_hd_mode.hd_attr.rgb_range = p_sys_cfg->chip_cfg.hd_attr[ i ].rgb_range;

		s_hd_mode.hd_attr.sample_mode = p_sys_cfg->chip_cfg.hd_attr[ i ].sample_mode;

		s_hd_mode.hd_attr.sync_mode = p_sys_cfg->chip_cfg.hd_attr[ i ].sync_mode;

		UINT * po = (UINT *)(&s_hd_mode);

		UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

		ULONG c = 0;
		for( c = 0 ; c < sizeof(req_hd_mode) ; c += 4 ) {

			de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

			pe += 4;

			po++;
		}
		aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000030, 0 ); // HCMD_SET_CHIP_VI_HD_MODE
	}

	// -----> fh35_api_vi_set_drop_mask() -----> ch_vi_set_drop_mask()  [2012.03.29] + 
	// 
	// -----> fh35_api_vi_set_crop() -----> ch_vi_set_crop()  [2012.03.29] + 
	//
	// -----> fh35_api_vi_set_pic_outmode -----> ch_vi_set_pic_outmode()  [2012.03.29] + 
	//
	// -----> fh35_api_vi_config_apply() [2012.03.29]
	//
	if( (pDevice->iManufacturer) == 0x85 ||
		
		(pDevice->iProduct & 0x0F) == 0x03 ) {

		ULONG j = 0;
		for( j = 0 ; j < 8 ; j += 2 ) {

			FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

			p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_crop_en    = 1;

			p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_size_in_mb = 704 / 16;

			p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_start      = 8;

			p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_crop_en    = 1;

			p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_size_in_mb = 480 / 16;

			p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_start      = 0;

			p_ch_cfg->viu_cfg.drop.drop_mask         = 1;

			p_ch_cfg->viu_cfg.drop.drop_mask_len     = 1;

			p_ch_cfg->viu_cfg.max_pic_width          = 704;

			p_ch_cfg->viu_cfg.max_pic_height         = 480;

			p_ch_cfg->viu_cfg.av_verify              = 0;

			p_ch_cfg->viu_cfg.mode_check             = 1;

			p_ch_cfg->viu_cfg.size_check             = 0;

			p_ch_cfg->viu_cfg.pic_out_mode           = 0;

			p_ch_cfg->viu_cfg.reserved[ 0 ]          = 0;

			p_ch_cfg->viu_cfg.reserved[ 1 ]          = 0;

			BYTE R0E = (BYTE)(d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50, (BYTE)(0x0E + 0x10 * (j / 2)) ) & 0xF0);

			ULONG standard = 0x00000000;

			if( R0E & 0x80 ) {

				standard = pDevice->FD314ADAD9404496b842EBFC396E875CB;
			}
			else {

				if( R0E == 0x00 ) { standard = V4L2_STD_NTSC_M; } else

				if( R0E == 0x10 ) { standard = V4L2_STD_PAL_B; } else

			//	if( R0E == 0x20 ) { standard = V4L2_STD_SECAM_B; } else

				if( R0E == 0x30 ) { standard = V4L2_STD_NTSC_443; } else

				if( R0E == 0x40 ) { standard = V4L2_STD_PAL_M; } else

				if( R0E == 0x50 ) { standard = V4L2_STD_PAL_Nc; } else

				if( R0E == 0x60 ) { standard = V4L2_STD_PAL_60; } else

								  { standard = pDevice->FD314ADAD9404496b842EBFC396E875CB; }
			}
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "STD#%02d = %02X x %08X\n", j, R0E, standard);

			if( standard & V4L2_STD_525_60 ) { //

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_size_in_mb = 480 / 16;
				
				p_sys_cfg->n_input_video_resolution_cx = 720;
				p_sys_cfg->n_input_video_resolution_cy = 480;
				p_sys_cfg->n_input_video_resolution_fps = 30;

				p_ch_cfg->viu_cfg.reserved[ 0 ] = 704;

				p_ch_cfg->viu_cfg.reserved[ 1 ] = 480;
			}
			if( standard& V4L2_STD_625_50 ) { //

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_size_in_mb = 576 / 16;

				p_sys_cfg->n_input_video_resolution_cx = 720;
				p_sys_cfg->n_input_video_resolution_cy = 576;
				p_sys_cfg->n_input_video_resolution_fps = 25;

				p_ch_cfg->viu_cfg.reserved[ 0 ] = 704;

				p_ch_cfg->viu_cfg.reserved[ 1 ] = 576;
			}
			if( pDevice->m_nCustomAnalogVideo720OutputProperty == 1 ) { // 720 OUTPUT

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_size_in_mb = 720 / 16;
			
				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_start = 0;

				p_ch_cfg->viu_cfg.max_pic_width = 720;

				p_ch_cfg->viu_cfg.reserved[ 0 ] = 720;
			}
			if( FALSE == c170e8e0c7a7462e87430cd552fc6e11( pDevice, j ) ) { return FALSE; }
		}
	}
	if( (pDevice->iManufacturer) == 0x85 ||
	
		(pDevice->iProduct & 0x0F) == 0x05 ||
		
		(pDevice->iProduct & 0x0F) == 0x07 ) {

		ULONG j = 0;
		for( j = 0 ; j < 10 ; j += 8 ) {

			FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

			if( pDevice->iManufacturer == 0x85 ) {
				
				if( j == 0 ) { continue ; }
			}
			p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_crop_en    = 0;

			p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_size_in_mb = 1920 / 16;

			p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_start      = 0;

			p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_crop_en    = 0;

			p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_size_in_mb = 1088 / 16;

			p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_start      = 0;

			p_ch_cfg->viu_cfg.drop.drop_mask         = 1;

			p_ch_cfg->viu_cfg.drop.drop_mask_len     = 1;

			p_ch_cfg->viu_cfg.max_pic_width          = 1920;

			p_ch_cfg->viu_cfg.max_pic_height         = 1088;

			p_ch_cfg->viu_cfg.av_verify              = 0;

			p_ch_cfg->viu_cfg.mode_check             = 1;

			p_ch_cfg->viu_cfg.size_check             = 0;

			p_ch_cfg->viu_cfg.pic_out_mode           = 0;

			if( p_sys_cfg->n_input_video_resolution_interleaved == 1 ) {

				p_ch_cfg->viu_cfg.reserved[ 0 ] = p_sys_cfg->n_input_video_resolution_cx << 0;

				p_ch_cfg->viu_cfg.reserved[ 1 ] = p_sys_cfg->n_input_video_resolution_cy << 1;
			}
			else {

				p_ch_cfg->viu_cfg.reserved[ 0 ] = p_sys_cfg->n_input_video_resolution_cx << 0;

				p_ch_cfg->viu_cfg.reserved[ 1 ] = p_sys_cfg->n_input_video_resolution_cy << 0;
			}


			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] n_input_video_resolution_cx(0d%d) n_input_video_resolution_cy(0d%d) n_input_video_resolution_fps(0d%d) n_input_video_resolution_interleaved(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_sys_cfg->n_input_video_resolution_cx, p_sys_cfg->n_input_video_resolution_cy, p_sys_cfg->n_input_video_resolution_fps, p_sys_cfg->n_input_video_resolution_interleaved );

			if( p_sys_cfg->n_input_video_resolution_cx == 0 ||

				p_sys_cfg->n_input_video_resolution_cy == 0 ) {

				;
			}
			else if( p_sys_cfg->n_input_video_resolution_cx == 1920 &&
				
					 p_sys_cfg->n_input_video_resolution_cy == 1200 ) {

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_size_in_mb = p_sys_cfg->n_input_video_resolution_cx / 16;

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_size_in_mb = p_sys_cfg->n_input_video_resolution_cy / 16;

				p_ch_cfg->viu_cfg.max_pic_width = 1920;

				p_ch_cfg->viu_cfg.max_pic_height = 1200;

				if( (p_sys_cfg->n_input_video_resolution_cy == 1200 && p_sys_cfg->n_input_video_resolution_fps >= 60) ||  // 1920 X 1200P @ 60 FPS
					
					(p_sys_cfg->n_input_video_resolution_cy == 1200 && p_sys_cfg->n_input_video_resolution_fps >= 50) ) { // 1920 X 1200P @ 50 FPS

					p_ch_cfg->viu_cfg.drop.drop_mask = 2;

					p_ch_cfg->viu_cfg.drop.drop_mask_len = 2;
				}
			}
			else if( (p_sys_cfg->n_input_video_resolution_cx == 1920) &&
				
					 (p_sys_cfg->n_input_video_resolution_cy == 1080 ||

					  p_sys_cfg->n_input_video_resolution_cy == 540) ) {

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_size_in_mb = p_sys_cfg->n_input_video_resolution_cx / 16;

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_size_in_mb = 1088 / 16;

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_crop_en = 1;

				if( (p_sys_cfg->n_input_video_resolution_cy == 1080 && p_sys_cfg->n_input_video_resolution_fps >= 60) ||  // 1920 X 1080P @ 60 FPS
					
					(p_sys_cfg->n_input_video_resolution_cy == 1080 && p_sys_cfg->n_input_video_resolution_fps >= 50) ) { // 1920 X 1080P @ 50 FPS

					p_ch_cfg->viu_cfg.drop.drop_mask = 2;

					p_ch_cfg->viu_cfg.drop.drop_mask_len = 2;
				}
			}
			else if( (p_sys_cfg->n_input_video_resolution_cx == 1280) &&
				
					 (p_sys_cfg->n_input_video_resolution_cy == 720) ) {

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_size_in_mb = p_sys_cfg->n_input_video_resolution_cx / 16;

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_size_in_mb = 736 / 16;

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_crop_en = 1;

				if( (pDevice->iManufacturer) == 0x85 ) {

					p_ch_cfg->viu_cfg.drop.drop_mask = 2;

					p_ch_cfg->viu_cfg.drop.drop_mask_len = 2;
				}
			}
			else if( (p_sys_cfg->n_input_video_resolution_cx == 1440 && p_sys_cfg->n_input_video_resolution_cy == 240) ||

					 (p_sys_cfg->n_input_video_resolution_cx == 1440 && p_sys_cfg->n_input_video_resolution_cy == 288) ) {

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_size_in_mb = p_sys_cfg->n_input_video_resolution_cx / 32;

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_size_in_mb = p_sys_cfg->n_input_video_resolution_cy / 16;

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_crop_en = 1;
			}
			else if( (p_sys_cfg->n_input_video_resolution_cx == 720) &&
				
					 (p_sys_cfg->n_input_video_resolution_cy == 240 ||

					  p_sys_cfg->n_input_video_resolution_cy == 288) ) {

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_size_in_mb = p_sys_cfg->n_input_video_resolution_cx / 16;

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_size_in_mb = p_sys_cfg->n_input_video_resolution_cy / 8;

				if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) { // [SDI.SD] [720 × 496 -> 720 × 480]

					p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_crop_en = 1;
				}
				if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 || 
					
					pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) {

					p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_crop_en = 1;
	
					p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_crop_en = 1;
				}
			}
			else {

				ULONG mod = (p_sys_cfg->n_input_video_resolution_interleaved) ? 8 : 16;

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_size_in_mb = p_sys_cfg->n_input_video_resolution_cx / 16;

				p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_size_in_mb = p_sys_cfg->n_input_video_resolution_cy / mod;

				if( p_sys_cfg->n_input_video_resolution_cx % 16 ) {

					p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_size_in_mb = (p_sys_cfg->n_input_video_resolution_cx + 15) / 16;

					p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_crop_en = 1;
				}
				if( p_sys_cfg->n_input_video_resolution_cy % mod ) {

					p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_size_in_mb = (p_sys_cfg->n_input_video_resolution_cy + (mod - 1)) / mod;

					p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_crop_en = 1;
				}
				if( p_sys_cfg->n_input_video_resolution_cx *

					p_sys_cfg->n_input_video_resolution_cy * 

					p_sys_cfg->n_input_video_resolution_fps > 1920 * 1200 * 30 ) {

					p_ch_cfg->viu_cfg.drop.drop_mask = 2;

					p_ch_cfg->viu_cfg.drop.drop_mask_len = 2;
				}
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "VI = %d × %d, %d × %d", p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_crop_en, p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_crop_en, p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.x_size_in_mb, p_ch_cfg->viu_cfg.croFB9478A2460F34931B3461172D5275F1E.y_size_in_mb );
			}
			if( FALSE == c170e8e0c7a7462e87430cd552fc6e11( pDevice, j ) ) { return FALSE; }
		}
		if( p_sys_cfg->n_input_video_resolution_cx > 0 &&

			p_sys_cfg->n_input_video_resolution_cy > 0 &&
			
			p_sys_cfg->n_input_video_resolution_fps > 0 ) {

			p_sys_cfg->n_output_video_resolution_cx = p_sys_cfg->n_input_video_resolution_cx;
		
			p_sys_cfg->n_output_video_resolution_fps_m = p_sys_cfg->n_input_video_resolution_fps_m;

			if( p_sys_cfg->n_input_video_resolution_interleaved == 1 ) {

				p_sys_cfg->n_output_video_resolution_cy = p_sys_cfg->n_input_video_resolution_cy * 2;

				p_sys_cfg->n_output_video_resolution_fps = p_sys_cfg->n_input_video_resolution_fps / 2;
			}
			else {
			
				p_sys_cfg->n_output_video_resolution_cy = p_sys_cfg->n_input_video_resolution_cy;

				p_sys_cfg->n_output_video_resolution_fps = p_sys_cfg->n_input_video_resolution_fps;
			}
			if( p_sys_cfg->n_input_video_resolution_cx *

				p_sys_cfg->n_input_video_resolution_cy * 

				p_sys_cfg->n_input_video_resolution_fps > 1920 * 1200 * 30 ) {

				p_sys_cfg->n_output_video_resolution_fps_1_2 = 1;
			}
			else {

				p_sys_cfg->n_output_video_resolution_fps_1_2 = 0;
			}
			p_sys_cfg->n_output_audio_sampling_frequency = p_sys_cfg->n_input_audio_sampling_frequency;
		}
	}

	// -----> fh35_api_vi_config_apply() [2012.03.29]
	// 
	if( FALSE == aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000001E, 0x00000000 ) ) { // HCMD_CONFIG_VI

		return FALSE;
	}

	// -----> fh35_api_vi_config_apply() -----> ch_refresh_pic_size() [2012.03.29]
	// 
	BOOLEAN is_success = FALSE;

	p_sys_cfg->n_input_video_resolution_ch_info = 0x00000000;

	ULONG j = 0;
	for( j = 0 ; j < 10 ; j += 2 ) {

		if( FALSE == aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000001C, j ) ) { // HCMD_GET_CH_INFO

			return FALSE;
		}
		ULONG R00400018 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00400000 + 0x18 );

		UINT cx = (R00400018 >> 16) & 0x0000FFFF;

		UINT cy = (R00400018 >>  0) & 0x0000FFFF;

		if( cx != 0 && cy != 0 ) { 
			
			if(	(pDevice->iProduct & 0x0F) == 0x05 ||
		
				(pDevice->iProduct & 0x0F) == 0x07 ) {
			
				if( (cx == 1280 && cy == 368) ||  // ERROR.VI
					
					(cx == 1872 && cy ==  368) ||  // ERROR.VI
					
					(cx == 1920 && cy == 1072) ||  // ERROR.VI
					
					(cx == 1920 && cy ==  544) ) { // ERROR.VI

					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "ERROR PATH#%02d = %d × %d\n", j, cx, cy );

					return FALSE;
				}
			}
			p_sys_cfg->n_input_video_resolution_ch_info |= (1 << j);

			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "PATH#%02d = %d x %d\n", j, cx, cy);

			is_success = TRUE;
		}
	}
	return is_success;
}

BOOLEAN E1E42361E0D6470A89E96B732B9BCB0D( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	if( pDevice->iManufacturer == 0x85 ||
		
		pDevice->iManufacturer == 0xA8 ) {

		p_sys_cfg->i2s_cfg.sync_mode = 1;

		p_sys_cfg->i2s_cfg.frame_len = 2048;

		p_sys_cfg->i2s_cfg.is_stereo = 0;

		p_sys_cfg->i2s_cfg.bitwidth = 32;

		p_sys_cfg->i2s_cfg.fs_mode = 64;

		p_sys_cfg->i2s_cfg.rx_en[ 0 ] = 1; // I2S#0

		p_sys_cfg->i2s_cfg.rx_en[ 1 ] = 1; // I2S#1

		p_sys_cfg->i2s_cfg.rx_en[ 2 ] = 1; // I2S#2

		p_sys_cfg->i2s_cfg.rx_en[ 3 ] = 1; // I2S#3

		p_sys_cfg->i2s_cfg.rx_en[ 4 ] = 1; // I2S#4

		p_sys_cfg->i2s_cfg.rx_en[ 5 ] = 1; // I2S#5

		p_sys_cfg->i2s_cfg.rx_en[ 6 ] = 1; // I2S#6

		p_sys_cfg->i2s_cfg.rx_en[ 7 ] = 1; // I2S#7

		p_sys_cfg->i2s_cfg.polarity[ 0 ] = 0; // LEFT

		p_sys_cfg->i2s_cfg.polarity[ 1 ] = 1; // RIGHT

		p_sys_cfg->i2s_cfg.polarity[ 2 ] = 0; // LEFT

		p_sys_cfg->i2s_cfg.polarity[ 3 ] = 1; // RIGHT

		p_sys_cfg->i2s_cfg.polarity[ 4 ] = 0; // LEFT

		p_sys_cfg->i2s_cfg.polarity[ 5 ] = 1; // RIGHT

		p_sys_cfg->i2s_cfg.polarity[ 6 ] = 0; // LEFT

		p_sys_cfg->i2s_cfg.polarity[ 7 ] = 1; // RIGHT
	}
	else if( (pDevice->iProduct & 0x0F) == 0x05 ||
			 (pDevice->iProduct & 0x0F) == 0x07 ) {

		if( pDevice->iManufacturer == 0x8A ||
			
			pDevice->iManufacturer == 0x8B ) {

			p_sys_cfg->i2s_cfg.rx_en[ 0 ] = 0; // I2S#0

			p_sys_cfg->i2s_cfg.rx_en[ 1 ] = 0; // I2S#1

			p_sys_cfg->i2s_cfg.rx_en[ 2 ] = 1; // I2S#2

			p_sys_cfg->i2s_cfg.rx_en[ 3 ] = 1; // I2S#3

			p_sys_cfg->i2s_cfg.polarity[ 0 ] = 0; // LEFT

			p_sys_cfg->i2s_cfg.polarity[ 1 ] = 1; // RIGHT

			p_sys_cfg->i2s_cfg.polarity[ 2 ] = 0; // LEFT

			p_sys_cfg->i2s_cfg.polarity[ 3 ] = 1; // RIGHT
		}
		else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 &&
			
				 pDevice->m_nAnalogCrossbarAudioInputProperty == 0 ) {

			p_sys_cfg->i2s_cfg.rx_en[ 0 ] = 0; // I2S#0

			p_sys_cfg->i2s_cfg.rx_en[ 1 ] = 0; // I2S#1

			p_sys_cfg->i2s_cfg.rx_en[ 2 ] = 1; // I2S#2

			p_sys_cfg->i2s_cfg.rx_en[ 3 ] = 1; // I2S#3

			p_sys_cfg->i2s_cfg.polarity[ 0 ] = 0; // LEFT

			p_sys_cfg->i2s_cfg.polarity[ 1 ] = 1; // RIGHT

			p_sys_cfg->i2s_cfg.polarity[ 2 ] = 0; // LEFT

			p_sys_cfg->i2s_cfg.polarity[ 3 ] = 1; // RIGHT
		}
		else if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 &&
			
				 pDevice->m_nAnalogCrossbarAudioInputProperty >= 1 ) {

			p_sys_cfg->i2s_cfg.rx_en[ 0 ] = 1; // I2S#0

			p_sys_cfg->i2s_cfg.rx_en[ 1 ] = 1; // I2S#1

			p_sys_cfg->i2s_cfg.rx_en[ 2 ] = 0; // I2S#2

			p_sys_cfg->i2s_cfg.rx_en[ 3 ] = 0; // I2S#3

			p_sys_cfg->i2s_cfg.polarity[ 0 ] = 0; // LEFT

			p_sys_cfg->i2s_cfg.polarity[ 1 ] = 1; // RIGHT

			p_sys_cfg->i2s_cfg.polarity[ 2 ] = 0; // LEFT

			p_sys_cfg->i2s_cfg.polarity[ 3 ] = 1; // RIGHT
		}
		else {

			p_sys_cfg->i2s_cfg.rx_en[ 0 ] = 1; // I2S#0

			p_sys_cfg->i2s_cfg.rx_en[ 1 ] = 1; // I2S#1

			p_sys_cfg->i2s_cfg.rx_en[ 2 ] = 0; // I2S#2

			p_sys_cfg->i2s_cfg.rx_en[ 3 ] = 0; // I2S#3

			p_sys_cfg->i2s_cfg.polarity[ 0 ] = 0; // LEFT

			p_sys_cfg->i2s_cfg.polarity[ 1 ] = 1; // RIGHT

			p_sys_cfg->i2s_cfg.polarity[ 2 ] = 0; // LEFT

			p_sys_cfg->i2s_cfg.polarity[ 3 ] = 1; // RIGHT
		}
		p_sys_cfg->i2s_cfg.sync_mode = 1;

		p_sys_cfg->i2s_cfg.frame_len = 2048;

		p_sys_cfg->i2s_cfg.is_stereo = 0;

		p_sys_cfg->i2s_cfg.bitwidth = 32;

		p_sys_cfg->i2s_cfg.fs_mode = 64;
	}
	else {

		p_sys_cfg->i2s_cfg.sync_mode = 1;

		p_sys_cfg->i2s_cfg.frame_len = 2048;

		p_sys_cfg->i2s_cfg.is_stereo = 1;

		p_sys_cfg->i2s_cfg.bitwidth = 32;

		p_sys_cfg->i2s_cfg.fs_mode = 256;

		p_sys_cfg->i2s_cfg.rx_en[ 0 ] = 1; // I2S#0

		p_sys_cfg->i2s_cfg.rx_en[ 1 ] = 0; // I2S#1

		p_sys_cfg->i2s_cfg.rx_en[ 2 ] = 0; // I2S#2

		p_sys_cfg->i2s_cfg.rx_en[ 3 ] = 0; // I2S#3

		p_sys_cfg->i2s_cfg.polarity[ 0 ] = 0; // LEFT

		p_sys_cfg->i2s_cfg.polarity[ 1 ] = 0; // LEFT

		p_sys_cfg->i2s_cfg.polarity[ 2 ] = 0; // LEFT

		p_sys_cfg->i2s_cfg.polarity[ 3 ] = 0; // LEFT
	}

	// -----> fh35_api_set_audio_config() -----> chip_set_audio_config() -----> para_write_audio_config() [2012.03.29]
	// 
	ULONG cksum = 0;

	p_sys_cfg->cfg_hdr.type = 3; // IRU_CONFIG_OTHER

	p_sys_cfg->cfg_hdr.size = sizeof(FH8735_USR_CFG_HEAD) + sizeof(FH8735_I2S_CFG);

	p_sys_cfg->cfg_hdr.cksum = 0x00000000;

	cksum = d6c33b6bbb4747f88d57cbd62a9ff0f8( 0, (UINT *)(&(p_sys_cfg->cfg_hdr)), sizeof(FH8735_USR_CFG_HEAD) / 4 );

	cksum = d6c33b6bbb4747f88d57cbd62a9ff0f8( cksum, (UINT *)(&(p_sys_cfg->i2s_cfg)), sizeof(FH8735_I2S_CFG) / 4 );

	p_sys_cfg->cfg_hdr.cksum = cksum;

	UINT * po = (UINT *)(&(p_sys_cfg->cfg_hdr));

	UINT pe = (UINT)(p_sys_cfg->para_addr);

	ULONG i = 0;
	for( i = 0 ; i < sizeof(FH8735_USR_CFG_HEAD) ; i += 4 ) { // DOWNLOAD FH8735_USR_CFG_HEAD

		de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

		pe += 4;

		po++;
	}
	po = (UINT *)(&(p_sys_cfg->i2s_cfg));

	for( i = 0 ; i < sizeof(FH8735_I2S_CFG) ; i += 4 ) { // DOWNLOAD FH8735_I2S_CFG

		de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

		pe += 4;

		po++;
	}
	return aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000022, 0 ); // HCMD_CONFIG_AUDIO
}

BOOLEAN AE31AEF7E63D495FA568A37A9C1EC5B3( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "AE31AEF7E63D495FA568A37A9C1EC5B3() \n" );

	FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	// -----> fh35_api_set_prv_size() -----> ch_set_prv_size() [2012.03.29]
	//
	BOOLEAN returns = TRUE;

	{	req_prv_size s_req_prv_size;

		s_req_prv_size.cmd = 0x00000004;

		s_req_prv_size.channel = 0;

		s_req_prv_size.Prv_H_N = 1;

		s_req_prv_size.Prv_H_M = 1;

		s_req_prv_size.Prv_V_N = 1;

		s_req_prv_size.Prv_V_M = 1;

		s_req_prv_size.PrvScalerMode = 1;

		UINT * po = (UINT *)(&s_req_prv_size);

		UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

		ULONG c = 0;
		for( c = 0 ; c < sizeof(s_req_prv_size) ; c += 4 ) {

			de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

			pe += 4;

			po++;
		}
		returns = aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000004, 0x0000FFFF ); // HCMD_CONFIG_ALL_PREVIEW
	}
	if( (pDevice->iManufacturer == 0xA0) || (pDevice->iManufacturer == 0x85) ) {

		ULONG i = 0 ;
		for( i = 0 ; i < 4 ; i++ ) {

			req_prv_size s_req_prv_size;

			s_req_prv_size.cmd = 0x00000004;

			s_req_prv_size.channel = i << 1;

			s_req_prv_size.Prv_H_N = 1;

			s_req_prv_size.Prv_H_M = 1;

			s_req_prv_size.Prv_V_N = 1;

			s_req_prv_size.Prv_V_M = 1;

			s_req_prv_size.PrvScalerMode = 1;

			ULONG cx_e = (pDevice->m_nCustomPreviewVideoResolutionProperty[ i ] & 0x00FFF000) >> 12;

			ULONG cy_e = (pDevice->m_nCustomPreviewVideoResolutionProperty[ i ] & 0x00000FFF) >> 0;

			pDevice->m_nCustomPreviewVideoResolutionProperty[ i ] &= 0x77FFFFFF;

			if( cx_e == 720 && cy_e == 576 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 1; } else

			if( cx_e == 720 && cy_e == 480 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 1; } else

			if( cx_e == 704 && cy_e == 576 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 1; } else

			if( cx_e == 704 && cy_e == 480 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 1; } else

			if( cx_e == 720 && cy_e == 288 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 2; } else

			if( cx_e == 720 && cy_e == 240 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 2; } else

			if( cx_e == 704 && cy_e == 288 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 2; } else

			if( cx_e == 704 && cy_e == 240 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 2; } else

			if( cx_e == 360 && cy_e == 288 ) { s_req_prv_size.Prv_H_M = 2; s_req_prv_size.Prv_V_M = 2; } else

			if( cx_e == 360 && cy_e == 240 ) { s_req_prv_size.Prv_H_M = 2; s_req_prv_size.Prv_V_M = 2; } else

			if( cx_e == 352 && cy_e == 288 ) { s_req_prv_size.Prv_H_M = 2; s_req_prv_size.Prv_V_M = 2; } else

			if( cx_e == 352 && cy_e == 240 ) { s_req_prv_size.Prv_H_M = 2; s_req_prv_size.Prv_V_M = 2; } else

											 { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 1; }

			p_sys_cfg->ch_cfg[ i << 1 ].vpu_cfg.Prv_H_M = s_req_prv_size.Prv_H_M;

			p_sys_cfg->ch_cfg[ i << 1 ].vpu_cfg.Prv_V_M = s_req_prv_size.Prv_V_M;

			UINT * po = (UINT *)(&s_req_prv_size);

			UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

			ULONG c = 0;
			for( c = 0 ; c < sizeof(s_req_prv_size) ; c += 4 ) {

				de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

				pe += 4;

				po++;
			}
			returns = aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000004, 1 << (i << 1) ); // HCMD_CONFIG_ALL_PREVIEW
		}
	}
	if( pDevice->iManufacturer == 0x85 ) {

		req_prv_size s_req_prv_size;

		s_req_prv_size.cmd = 0x00000004;

		s_req_prv_size.channel = 8;

		s_req_prv_size.Prv_H_N = 1;

		s_req_prv_size.Prv_H_M = 2;	

		s_req_prv_size.Prv_V_N = 1;

		s_req_prv_size.Prv_V_M = 2;

		s_req_prv_size.PrvScalerMode = 1;

		p_sys_cfg->ch_cfg[ 8 ].vpu_cfg.Prv_H_M = s_req_prv_size.Prv_H_M;

		p_sys_cfg->ch_cfg[ 8 ].vpu_cfg.Prv_V_M = s_req_prv_size.Prv_V_M;

		UINT * po = (ULONG *)(&s_req_prv_size);

		UINT pe = (ULONG)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

		UINT c = 0;
		for(  c = 0 ; c < sizeof(s_req_prv_size) ; c += 4 ) {

			de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

			pe += 4;

			po++;
		}
		returns = aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000004, 0x00000100 ); // HCMD_CONFIG_ALL_PREVIEW
	}

	else if( (pDevice->iProduct & 0x0F) == 0x05  ||
	
			 (pDevice->iProduct & 0x0F) == 0x07 ) {
		
		if( pDevice->m_nCustomPreviewVideoResolutionProperty[ 0 ] == 0 ) //can not be 0
		{
			pDevice->m_nCustomPreviewVideoResolutionProperty[ 0 ] = pDevice->m_nCustomAnalogVideoResolutionProperty;
		}
		
		ULONG cx_e = (pDevice->m_nCustomPreviewVideoResolutionProperty[ 0 ] & 0x00FFF000) >> 12;

		ULONG cy_e = (pDevice->m_nCustomPreviewVideoResolutionProperty[ 0 ] & 0x00000FFF) >> 0;

		ULONG sx = p_sys_cfg->n_input_video_resolution_cx >> 1;

		ULONG sy = p_sys_cfg->n_input_video_resolution_cy >> 1;

		if( p_sys_cfg->n_input_video_resolution_interleaved == 1 ) {

			sy <<= 1;
		}	
		ULONG dx = sx >> 1;

		ULONG dy = sy >> 1;

		ULONG ex = sx >> 2;

		ULONG ey = sy >> 2;

		pDevice->m_nCustomPreviewVideoResolutionProperty[ 0 ] &= 0x77FFFFFF;

		req_prv_size s_req_prv_size;

		s_req_prv_size.cmd = 0x00000004;

		s_req_prv_size.channel = 0;

		s_req_prv_size.Prv_H_N = 1;

		s_req_prv_size.Prv_H_M = 1;

		s_req_prv_size.Prv_V_N = 1;

		s_req_prv_size.Prv_V_M = 1;

		s_req_prv_size.PrvScalerMode = 1;

		if( cx_e <= ex && 
			
			cy_e <= ey ) { 
			
			s_req_prv_size.Prv_H_M = 8; s_req_prv_size.Prv_V_M = 8; 
		} 
		else if( cx_e <= dx && 
			
				 cy_e <= dy ) { 
			
			s_req_prv_size.Prv_H_M = 4; s_req_prv_size.Prv_V_M = 4; 
		} 
		else if( cx_e <= sx && 
			
				 cy_e <= sy ) { 
			
			s_req_prv_size.Prv_H_M = 2; s_req_prv_size.Prv_V_M = 2; 
		} 
		else { 

			s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 1; 
		}
		p_sys_cfg->ch_cfg[ 0 ].vpu_cfg.Prv_H_M = s_req_prv_size.Prv_H_M;

		p_sys_cfg->ch_cfg[ 0 ].vpu_cfg.Prv_V_M = s_req_prv_size.Prv_V_M;

		p_sys_cfg->ch_cfg[ 8 ].vpu_cfg.Prv_H_M = s_req_prv_size.Prv_H_M;

		p_sys_cfg->ch_cfg[ 8 ].vpu_cfg.Prv_V_M = s_req_prv_size.Prv_V_M;



		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "AE31AEF7E63D495FA568A37A9C1EC5B3() Prv_H_M(%d) Prv_V_M(%d)\n", s_req_prv_size.Prv_H_M, s_req_prv_size.Prv_V_M );

		UINT * po = (UINT *)(&s_req_prv_size);

		UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

		ULONG c = 0;
		for( c = 0 ; c < sizeof(s_req_prv_size) ; c += 4 ) {

			de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

			pe += 4;

			po++;
		}
		returns = aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000004, 0x00000100 ); // HCMD_CONFIG_ALL_PREVIEW
	}
	if( returns ) { 

		returns = aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000E, 0x00000000 ); // HCMD_START_ALL_AVG

		returns = aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000E, 0x0000FFFF ); // HCMD_START_ALL_AVG
	}
	return returns;
}

ULONG FC2D5CAC8CF445D7859E0FC2E3700A46( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i )
{
	if( (pDevice->iManufacturer) == 0x85 ) { return i << 1; } // SC585

	if( (pDevice->iManufacturer) == 0x8A ) { return 8; } // SC580N4.HDMI.ITE6603

	if( (pDevice->iManufacturer) == 0x8B ) { return 8; } // SC580N4.SDI

	if( (pDevice->iProduct & 0x0F) == 0x05 || 
	
		(pDevice->iProduct & 0x0F) == 0x07	) { // SC580

		if( pDevice->m_nAnalogCrossbarVideoInputProperty <= 3 ) { return 0; } // HDMI / DVI / RGB / YCBCR

		if( pDevice->m_nAnalogCrossbarVideoInputProperty >= 4 ) { return 8; } // SDI
	}
	return i << 1; // SC3A0
}

BOOLEAN CCC08FAB4DA74DB0BEF260E7E6A213AF( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i )
{
	FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	BOOLEAN is_update = FALSE;

	if( pDevice->m_nCustomPreviewVideoResolutionProperty[ i ] &  0x88000000 ) {

		pDevice->m_nCustomPreviewVideoResolutionProperty[ i ] &= 0x77FFFFFF;

		is_update = TRUE;
	}
	if( is_update ) {

		ULONG j = FC2D5CAC8CF445D7859E0FC2E3700A46( pDevice, i );

		FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

		req_prv_size s_req_prv_size;

		s_req_prv_size.cmd = 0x00000004;

		s_req_prv_size.channel = j;

		s_req_prv_size.Prv_H_N = 1;

		s_req_prv_size.Prv_H_M = 1;

		s_req_prv_size.Prv_V_N = 1;

		s_req_prv_size.Prv_V_M = 1;

		s_req_prv_size.PrvScalerMode = 1;

		ULONG cx_e = (pDevice->m_nCustomPreviewVideoResolutionProperty[ i ] & 0x00FFF000) >> 12;

		ULONG cy_e = (pDevice->m_nCustomPreviewVideoResolutionProperty[ i ] & 0x00000FFF) >> 0;

		ULONG sx = p_sys_cfg->n_input_video_resolution_cx >> 1;

		ULONG sy = p_sys_cfg->n_input_video_resolution_cy >> 1;

		if( p_sys_cfg->n_input_video_resolution_interleaved == 1 ) {

			sy <<= 1;
		}
		ULONG dx = sx >> 1;

		ULONG dy = sy >> 1;

		ULONG ex = sx >> 2;

		ULONG ey = sy >> 2;

		pDevice->m_nCustomPreviewVideoResolutionProperty[ i ] &= 0x77FFFFFF;

		if( (pDevice->iManufacturer == 0xA0) ||
			
			(pDevice->iManufacturer == 0xA1) ||
			
			(pDevice->iManufacturer == 0xA2) ||
			
			(pDevice->iManufacturer == 0xA4) ||
			
			(pDevice->iManufacturer == 0xA5) ||
			
			(pDevice->iManufacturer == 0xA6) ||

			(pDevice->iManufacturer == 0x85) ) {

			if( cx_e == 720 && cy_e == 576 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 1; } else
	
			if( cx_e == 720 && cy_e == 480 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 1; } else
	
			if( cx_e == 704 && cy_e == 576 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 1; } else
	
			if( cx_e == 704 && cy_e == 480 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 1; } else
	
			if( cx_e == 720 && cy_e == 288 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 2; } else
	
			if( cx_e == 720 && cy_e == 240 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 2; } else
	
			if( cx_e == 704 && cy_e == 288 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 2; } else
	
			if( cx_e == 704 && cy_e == 240 ) { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 2; } else

			if( cx_e == 360 && cy_e == 288 ) { s_req_prv_size.Prv_H_M = 2; s_req_prv_size.Prv_V_M = 2; } else

			if( cx_e == 360 && cy_e == 240 ) { s_req_prv_size.Prv_H_M = 2; s_req_prv_size.Prv_V_M = 2; } else

			if( cx_e == 352 && cy_e == 288 ) { s_req_prv_size.Prv_H_M = 2; s_req_prv_size.Prv_V_M = 2; } else
	
			if( cx_e == 352 && cy_e == 240 ) { s_req_prv_size.Prv_H_M = 2; s_req_prv_size.Prv_V_M = 2; } else

			if( cx_e ==  sx && cy_e ==  sy ) { s_req_prv_size.Prv_H_M = 2; s_req_prv_size.Prv_V_M = 2; } else

											 { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 1; }
		}
		else {

			if( cx_e <=  ex && cy_e <=  ey ) { s_req_prv_size.Prv_H_M = 8; s_req_prv_size.Prv_V_M = 8; } else

			if( cx_e <=  dx && cy_e <=  dy ) { s_req_prv_size.Prv_H_M = 4; s_req_prv_size.Prv_V_M = 4; } else

			if( cx_e <=  sx && cy_e <=  sy ) { s_req_prv_size.Prv_H_M = 2; s_req_prv_size.Prv_V_M = 2; } else

											 { s_req_prv_size.Prv_H_M = 1; s_req_prv_size.Prv_V_M = 1; }
		}
		if( pDevice->iManufacturer == 0x85 ) { // SC585

			p_ch_cfg->vpu_cfg.Prv_H_M = s_req_prv_size.Prv_H_M;

			p_ch_cfg->vpu_cfg.Prv_V_M = s_req_prv_size.Prv_V_M;
		}
		else if( (pDevice->iProduct & 0x0F) == 0x05 ||  // SC580

				 (pDevice->iProduct & 0x0F) == 0x07 ) { // SC580

			p_sys_cfg->ch_cfg[ 0 ].vpu_cfg.Prv_H_M = s_req_prv_size.Prv_H_M;

			p_sys_cfg->ch_cfg[ 0 ].vpu_cfg.Prv_V_M = s_req_prv_size.Prv_V_M;

			p_sys_cfg->ch_cfg[ 8 ].vpu_cfg.Prv_H_M = s_req_prv_size.Prv_H_M;

			p_sys_cfg->ch_cfg[ 8 ].vpu_cfg.Prv_V_M = s_req_prv_size.Prv_V_M;
		}
		else {

			p_ch_cfg->vpu_cfg.Prv_H_M = s_req_prv_size.Prv_H_M;

			p_ch_cfg->vpu_cfg.Prv_V_M = s_req_prv_size.Prv_V_M;
		}
		UINT * po = (UINT *)(&s_req_prv_size);

		UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

		ULONG c = 0;
		for( c = 0 ; c < sizeof(s_req_prv_size) ; c += 4 ) {

			de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

			pe += 4;

			po++;
		}
		BOOLEAN returns = aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000004, 1 << (i << 1) ); // HCMD_CONFIG_ALL_PREVIEW

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d PREVIEW = %d x %d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, s_req_prv_size.Prv_H_M, s_req_prv_size.Prv_V_M);

		if( returns ) {

			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000E, 0x00000000 ); // HCMD_START_ALL_AVG

			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000E, 0x0000FFFF ); // HCMD_START_ALL_AVG
		}
	}
	return TRUE;
}

BOOLEAN D7A9F02797E148C3B4E81FAA8455FABC( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, BOOL is_init )
{
	BOOL is_update = is_init;

	if( pDevice->m_nCustomRegionMaskParamsProperty[ i ][ 0 ][ 0 ] &  0x80000000 ) {

		pDevice->m_nCustomRegionMaskParamsProperty[ i ][ 0 ][ 0 ] &= 0x7FFFFFFF;

		is_update = TRUE;
	}
	if( pDevice->m_nCustomRegionMaskParamsProperty[ i ][ 1 ][ 0 ] &  0x80000000 ) {

		pDevice->m_nCustomRegionMaskParamsProperty[ i ][ 1 ][ 0 ] &= 0x7FFFFFFF;

		is_update = TRUE;
	}
	if( is_update ) {

		ULONG j = FC2D5CAC8CF445D7859E0FC2E3700A46( pDevice, i );

		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

		{	req_region_mask s_region_mask;

			s_region_mask.channel = j;

			s_region_mask.cmd = 0x00000032;

			s_region_mask.RegionCoverMode = p_ch_cfg->vpu_cfg.RegionCoverMode = 0;

			s_region_mask.cover_top_left_x0 = pDevice->m_nCustomRegionMaskParamsProperty[ i ][ 0 ][ 1 ] >> 16;

			s_region_mask.cover_top_left_y0 = pDevice->m_nCustomRegionMaskParamsProperty[ i ][ 0 ][ 1 ] & 0x0000FFFF;

			s_region_mask.cover_width0 = pDevice->m_nCustomRegionMaskParamsProperty[ i ][ 0 ][ 2 ];

			s_region_mask.cover_height0 = pDevice->m_nCustomRegionMaskParamsProperty[ i ][ 0 ][ 3 ];

			s_region_mask.cover_top_left_x1 = pDevice->m_nCustomRegionMaskParamsProperty[ i ][ 1 ][ 1 ] >> 16;

			s_region_mask.cover_top_left_y1 = pDevice->m_nCustomRegionMaskParamsProperty[ i ][ 1 ][ 1 ] & 0x0000FFFF;

			s_region_mask.cover_width1 = pDevice->m_nCustomRegionMaskParamsProperty[ i ][ 1 ][ 2 ];

			s_region_mask.cover_height1 = pDevice->m_nCustomRegionMaskParamsProperty[ i ][ 1 ][ 3 ];

			if( s_region_mask.cover_width0 != 0 ||

				s_region_mask.cover_width1 != 0 ||
				
				s_region_mask.cover_height0 != 0 || 
				
				s_region_mask.cover_height1 != 0 ) {

				s_region_mask.OSDRegionCover = p_ch_cfg->vpu_cfg.OSDRegionCover = 1;
			}
			else {

				s_region_mask.OSDRegionCover = p_ch_cfg->vpu_cfg.OSDRegionCover = 0;
			}
			UINT * po = (UINT *)(&s_region_mask);

			UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

			ULONG c = 0;
			for( c = 0 ; c < sizeof(s_region_mask) ; c += 4 ) {

				de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

				pe += 4;

				po++;
			}
			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000032, j ); // HCMD_SET_REGION_MASK
		}
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d REGION.MASK = %d x %d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, p_ch_cfg->vpu_cfg.OSDRegionCover, p_ch_cfg->vpu_cfg.RegionCoverMode);
	}
	return TRUE;
}

BOOLEAN EB57E76A6D474FCAA2769C8E53FD5081( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, BOOL is_init )
{
	BOOL is_update = is_init;

	if( pDevice->iManufacturer == 0xA8 ) { return TRUE; } // SC3A0.3D

	if( pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ i ] &  0x88000000 ) {

		pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ i ] &= 0x77FFFFFF;

		is_update = TRUE;
	}
	if( is_update ) { // -----> ch_set_deinterlace() [2012.03.29]

		ULONG j = FC2D5CAC8CF445D7859E0FC2E3700A46( pDevice, i );

		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

		ULONG deinterlace = pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ i ] & 0x77FFFFFF;

		if( deinterlace == 0 ) { p_ch_cfg->vpu_cfg.Deinterlace_mode = 0; p_ch_cfg->vpu_cfg.DeintlaceMDThr = ( 0); }

		if( deinterlace == 1 ) { p_ch_cfg->vpu_cfg.Deinterlace_mode = 1; p_ch_cfg->vpu_cfg.DeintlaceMDThr = (-4 & 0xFF) | ( 8 << 8) | (24 << 16) | (32 << 24); } 

		if( deinterlace == 2 ) { p_ch_cfg->vpu_cfg.Deinterlace_mode = 1; p_ch_cfg->vpu_cfg.DeintlaceMDThr = (-8 & 0xFF) | (12 << 8) | (24 << 16) | (32 << 24); }

		if( deinterlace == 3 ) { p_ch_cfg->vpu_cfg.Deinterlace_mode = 1; p_ch_cfg->vpu_cfg.DeintlaceMDThr = (-8 & 0xFF) | (14 << 8) | (20 << 16) | (32 << 24); }

		if( deinterlace == 4 ) { p_ch_cfg->vpu_cfg.Deinterlace_mode = 1; p_ch_cfg->vpu_cfg.DeintlaceMDThr = (-8 & 0xFF) | (16 << 8) | (16 << 16) | (32 << 24); }

		if( deinterlace == 5 ) { p_ch_cfg->vpu_cfg.Deinterlace_mode = 2; p_ch_cfg->vpu_cfg.DeintlaceMDThr = (30); }

		if( deinterlace == 6 ) { p_ch_cfg->vpu_cfg.Deinterlace_mode = 2; p_ch_cfg->vpu_cfg.DeintlaceMDThr = (20); }

		if( deinterlace == 7 ) { p_ch_cfg->vpu_cfg.Deinterlace_mode = 2; p_ch_cfg->vpu_cfg.DeintlaceMDThr = (10); }

		if( deinterlace >= 8 ) { p_ch_cfg->vpu_cfg.Deinterlace_mode = 2; p_ch_cfg->vpu_cfg.DeintlaceMDThr = (0);  }

		{	req_deinterlace s_deinterlace;

			s_deinterlace.channel = j;

			s_deinterlace.cmd = 0x0000002A;

			s_deinterlace.Deinterlace_mode = p_ch_cfg->vpu_cfg.Deinterlace_mode;

			s_deinterlace.DeintlaceMDThr = p_ch_cfg->vpu_cfg.DeintlaceMDThr;

			UINT * po = (UINT *)(&s_deinterlace);

			UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

			ULONG c = 0;
			for( c = 0 ; c < sizeof(s_deinterlace) ; c += 4 ) {

				de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

				pe += 4;

				po++;
			}
			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000002A, j ); // HCMD_SET_DEINTERLACE
		}
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d DI = %d x %08X\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, p_ch_cfg->vpu_cfg.Deinterlace_mode, p_ch_cfg->vpu_cfg.DeintlaceMDThr);
	}
	return TRUE;
}

BOOLEAN E164895E8C494B179A8ADE287DDFCEA8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, BOOL is_init )
{
	BOOLEAN is_update = is_init ? TRUE : FALSE;

	if( pDevice->iManufacturer == 0xA8 ) { return TRUE; } // SC3A0.3D

	if( pDevice->m_nCustomAnalogVideoDenoiseTypeProperty[ i ] &  0x88000000 ) {

		pDevice->m_nCustomAnalogVideoDenoiseTypeProperty[ i ] &= 0x77FFFFFF;

		is_update = TRUE;
	}
	if( is_update ) { // -----> ch_set_denoise() [2012.03.29]

		ULONG j = FC2D5CAC8CF445D7859E0FC2E3700A46( pDevice, i );

		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

		ULONG denoise = pDevice->m_nCustomAnalogVideoDenoiseTypeProperty[ i ] & 0x77FFFFFF;

		if( denoise == 0 ) { p_ch_cfg->vpu_cfg.DenoiseL_Coeff = p_ch_cfg->vpu_cfg.DenoiseC_Coeff = 0; }

		if( denoise == 1 ) { p_ch_cfg->vpu_cfg.DenoiseL_Coeff = p_ch_cfg->vpu_cfg.DenoiseC_Coeff = 1; } 

		if( denoise == 2 ) { p_ch_cfg->vpu_cfg.DenoiseL_Coeff = p_ch_cfg->vpu_cfg.DenoiseC_Coeff = 2; }

		if( denoise >= 3 ) { p_ch_cfg->vpu_cfg.DenoiseL_Coeff = p_ch_cfg->vpu_cfg.DenoiseC_Coeff = 3; }

		{	req_denoise s_denoise;

			s_denoise.channel = j;

			s_denoise.cmd = 0x00000029;

			s_denoise.DenoiseL_Coeff = p_ch_cfg->vpu_cfg.DenoiseL_Coeff;

			s_denoise.DenoiseC_Coeff = p_ch_cfg->vpu_cfg.DenoiseC_Coeff;

			UINT * po = (UINT *)(&s_denoise);

			UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

			ULONG c = 0;
			for( c = 0 ; c < sizeof(s_denoise) ; c += 4 ) {

				de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

				pe += 4;

				po++;
			}
			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000029, j ); // HCMD_SET_DENOISE
		}
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d DN = %d x %d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, p_ch_cfg->vpu_cfg.DenoiseL_Coeff, p_ch_cfg->vpu_cfg.DenoiseC_Coeff);
	}
	return TRUE;
}

BOOLEAN D1A4965F8D614345A6A1ACD04B201680( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, BOOL is_init )
{
	BOOLEAN is_update = is_init ? TRUE : FALSE;

	if( pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i ] &  0x88000000 ) {

		pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i ] &= 0x77FFFFFF;

		is_update = TRUE;
	}
	if( is_update ) { // -----> fh35_api_venc_set_UVI() [2012.03.29]

		ULONG j = FC2D5CAC8CF445D7859E0FC2E3700A46( pDevice, i );

		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

		ULONG cx = (pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i ] & 0x00FFF000) >> 12;

		ULONG cy = (pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i ] & 0x00000FFF) >>  0;

		{	req_UVI s_uvi_req;

			s_uvi_req.channel = j;

			s_uvi_req.cmd = 0x00000033;

			ULONG sx = p_sys_cfg->n_input_video_resolution_cx;

			ULONG sy = p_sys_cfg->n_input_video_resolution_cy;

			if( p_sys_cfg->n_input_video_resolution_interleaved == 1 ) {

				sy <<= 1;
			}
			cx *= sy;

			cy *= sx;

			if( ((cx % 4) == 0) && ((cy % 4) == 0) ) { cx /= 4; cy /= 4; }

			if( ((cx % 2) == 0) && ((cy % 2) == 0) ) { cx /= 2; cy /= 2; }

			if( ((cx % 3) == 0) && ((cy % 3) == 0) ) { cx /= 3; cy /= 3; }

			if( ((cx % 5) == 0) && ((cy % 5) == 0) ) { cx /= 5; cy /= 5; }

			if( cx > 0 && 
				
				cy > 0 ) {

				s_uvi_req.Generate_VUI = p_ch_cfg->enc_cfg.Generate_VUI = 1; // TS EDIUS OK

				s_uvi_req.sar_width = p_ch_cfg->enc_cfg.sar_width = cx; // TS EDIUS OK

				s_uvi_req.sar_height = p_ch_cfg->enc_cfg.sar_height = cy; // TS EDIUS OK
			}
			else {

				s_uvi_req.Generate_VUI = p_ch_cfg->enc_cfg.Generate_VUI = 0; // MP4 EDIUS OK
			  
				s_uvi_req.sar_width = p_ch_cfg->enc_cfg.sar_width = 0; // MP4 EDIUS OK
			  
				s_uvi_req.sar_height = p_ch_cfg->enc_cfg.sar_height = 0; // MP4 EDIUS OK

			}
			UINT * po = (UINT *)(&s_uvi_req);

			UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

			ULONG c = 0;
			for( c = 0 ; c < sizeof(req_UVI) ; c += 4 ) {

				de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

				pe += 4;

				po++;
			}
			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000033, j ); // HCMD_SET_UVI
		}
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d ASPECT.RATIO = %d x %d x %d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, p_ch_cfg->enc_cfg.Generate_VUI, p_ch_cfg->enc_cfg.sar_width, p_ch_cfg->enc_cfg.sar_height);
	}
	return TRUE;
}

BOOLEAN E14B419B180144FA905B3F38192704C7( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, BOOL is_init )
{
	BOOLEAN is_update = is_init ? TRUE : FALSE;

	if( pDevice->m_nCustomEncoderVideoProfileProperty[ i ] &  0x88000000 ) {

		pDevice->m_nCustomEncoderVideoProfileProperty[ i ] &= 0x77FFFFFF;

		is_update = TRUE;
	}
	if( pDevice->m_nCustomEncoderVideoBframesPerKeyframeProperty[ i ] &  0x88000000 ) {

		pDevice->m_nCustomEncoderVideoBframesPerKeyframeProperty[ i ] &= 0x77FFFFFF;

		is_update = TRUE;
	}

	if( pDevice->m_nCustom_H264_Level_Property &  0x88000000 ) {

		pDevice->m_nCustom_H264_Level_Property &= 0x77FFFFFF;

		is_update = TRUE;
	}


	if( is_update ) { // -----> fh35_api_venc_set_config() [2012.03.29]

		ULONG j = FC2D5CAC8CF445D7859E0FC2E3700A46( pDevice, i );

		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

		//p_ch_cfg->enc_cfg.profile = pDevice->m_nCustomEncoderVideoProfileProperty[ i ] & 0x77FFFFFF; // 0 = MAINPROFILE / 1 = BASELINE

		if( (pDevice->m_nCustomEncoderVideoProfileProperty[ i ] & 0x77FFFFFF) == V4L2_MPEG_VIDEO_H264_PROFILE_MAIN)
		{
			p_ch_cfg->enc_cfg.profile = 0;
		}
		else
		{
			p_ch_cfg->enc_cfg.profile = 1;
		}

		if( p_ch_cfg->enc_cfg.profile == 0 ) { p_ch_cfg->enc_cfg.entropy_mode = 1; } // 1 = CABAC

		if( p_ch_cfg->enc_cfg.profile == 1 ) { p_ch_cfg->enc_cfg.entropy_mode = 0; } // 0 = CAVLC

/*
		if( (pDevice->iProduct & 0x0F) == 0x05 ||
			
			(pDevice->iProduct & 0x0F) == 0x07	) { // HD

			 p_ch_cfg->enc_cfg.level_idc = 41;
		}
		else { // SD

			 p_ch_cfg->enc_cfg.level_idc = 31;
		}
*/
	
		if( pDevice->m_nCustom_H264_Level_Property == V4L2_MPEG_VIDEO_H264_LEVEL_4_1 )
		{
			 p_ch_cfg->enc_cfg.level_idc = 41;
		}
		else if( pDevice->m_nCustom_H264_Level_Property == V4L2_MPEG_VIDEO_H264_LEVEL_4_0 )
		{
			 p_ch_cfg->enc_cfg.level_idc = 40;
		}
		else if( pDevice->m_nCustom_H264_Level_Property == V4L2_MPEG_VIDEO_H264_LEVEL_3_2 )
		{
			 p_ch_cfg->enc_cfg.level_idc = 32;
		}
		else if( pDevice->m_nCustom_H264_Level_Property == V4L2_MPEG_VIDEO_H264_LEVEL_3_1 )
		{
			 p_ch_cfg->enc_cfg.level_idc = 31;
		}
		else if( pDevice->m_nCustom_H264_Level_Property == V4L2_MPEG_VIDEO_H264_LEVEL_3_0 )
		{
			 p_ch_cfg->enc_cfg.level_idc = 30;
		}
		else if( pDevice->m_nCustom_H264_Level_Property == V4L2_MPEG_VIDEO_H264_LEVEL_2_2 )
		{
			 p_ch_cfg->enc_cfg.level_idc = 22;
		}
		else if( pDevice->m_nCustom_H264_Level_Property == V4L2_MPEG_VIDEO_H264_LEVEL_2_1 )
		{
			 p_ch_cfg->enc_cfg.level_idc = 21;
		}
		else if( pDevice->m_nCustom_H264_Level_Property == V4L2_MPEG_VIDEO_H264_LEVEL_2_0 )
		{
			 p_ch_cfg->enc_cfg.level_idc = 20;
		}
		else if( pDevice->m_nCustom_H264_Level_Property == V4L2_MPEG_VIDEO_H264_LEVEL_1_3 )
		{
			 p_ch_cfg->enc_cfg.level_idc = 13;
		}
		else if( pDevice->m_nCustom_H264_Level_Property == V4L2_MPEG_VIDEO_H264_LEVEL_1_2 )
		{
			 p_ch_cfg->enc_cfg.level_idc = 12;
		}
		else if( pDevice->m_nCustom_H264_Level_Property == V4L2_MPEG_VIDEO_H264_LEVEL_1_1 )
		{
			 p_ch_cfg->enc_cfg.level_idc = 11;
		}
		else if( pDevice->m_nCustom_H264_Level_Property == V4L2_MPEG_VIDEO_H264_LEVEL_1_0 )
		{
			 p_ch_cfg->enc_cfg.level_idc = 10;
		}
		else
		{
			 p_ch_cfg->enc_cfg.level_idc = 41;
		}
		
		p_ch_cfg->enc_cfg.b_frame = pDevice->m_nCustomEncoderVideoBframesPerKeyframeProperty[ i ] & 0x77FFFFFF;

		{	req_set_enc_config s_req_set_enc_config;

			s_req_set_enc_config.channel = j;

			s_req_set_enc_config.cmd = 0x00000035;

			s_req_set_enc_config.profile = p_ch_cfg->enc_cfg.profile;

			s_req_set_enc_config.level_idc = p_ch_cfg->enc_cfg.level_idc;

			s_req_set_enc_config.entropy_mode = p_ch_cfg->enc_cfg.entropy_mode;

			s_req_set_enc_config.b_frame = p_ch_cfg->enc_cfg.b_frame;

			UINT * po = (UINT *)(&s_req_set_enc_config);

			UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

			ULONG c = 0;
			for( c = 0 ; c < sizeof(req_set_enc_config) ; c += 4 ) {

				de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

				pe += 4;

				po++;
			}
			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000035, j ); // HCMD_SET_ENCODE_CONFIG
		}
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d PROFILE = %d x %d x %d x %d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, p_ch_cfg->enc_cfg.profile, p_ch_cfg->enc_cfg.level_idc, p_ch_cfg->enc_cfg.entropy_mode, p_ch_cfg->enc_cfg.b_frame);
	}
	return TRUE;
}


BOOLEAN F553794FC37E402F98F04D85EB1CD9FA( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG j, char* pwszFileName, req_tosd * p_tosd_req )
{

	FH8735_SYS_CFG *  p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	FH8735_CH_CFG *   p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d F553794FC37E402F98F04D85EB1CD9FA() j(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, j);


/*
	WCHAR			  wszPathName[ 255 ];

	OBJECT_ATTRIBUTES oObjectAttributes;

	UNICODE_STRING    oFileName;

	IO_STATUS_BLOCK   oIoStatus;

	HANDLE            hFileHandle = NULL;

	BYTE *            pFileBuffer = NULL;

	ULONG             nFileSize = 0;

	NTSTATUS          status = STATUS_SUCCESS;

	swprintf( wszPathName, L"%s%ws", L"\\??\\", pwszFileName );

	AMEBDAD_PRINT( ("F553794FC37E402F98F04D85EB1CD9FA( \"%ws\" )\n", wszPathName) );

	// 1.0 OPEN TEXT FILE
	// 
	oFileName.MaximumLength = wcslen(wszPathName) * 2 + sizeof(UNICODE_NULL);

	oFileName.Buffer = (PWSTR)(ExAllocatePool( PagedPool, oFileName.MaximumLength ));

	oFileName.Length = 0;

    if( oFileName.Buffer == NULL ) {

        return FALSE;
    }
	else {

		RtlZeroMemory( oFileName.Buffer, oFileName.MaximumLength );
	}
	status = RtlAppendUnicodeToString( &oFileName, wszPathName );

	InitializeObjectAttributes( (POBJECT_ATTRIBUTES)(&oObjectAttributes), (PUNICODE_STRING)(&oFileName), OBJ_CASE_INSENSITIVE, NULL, NULL );

	status = ZwCreateFile( &hFileHandle, FILE_READ_DATA, &oObjectAttributes, &oIoStatus, 0, FILE_ATTRIBUTE_NORMAL, FILE_SHARE_READ, FILE_OPEN, FILE_SYNCHRONOUS_IO_NONALERT, NULL, 0 );

	FREE_MEMORY( oFileName.Buffer );

	if( NT_SUCCESS(status) ) {

		FILE_STANDARD_INFORMATION oFileStandardInfomation;

		ZwQueryInformationFile( hFileHandle, &oIoStatus, &oFileStandardInfomation, sizeof(FILE_STANDARD_INFORMATION), FileStandardInformation );

		if( oFileStandardInfomation.Directory == TRUE ) {

			ZwClose( hFileHandle );

			return FALSE;
		}
		nFileSize = (ULONG)(oFileStandardInfomation.EndOfFile.QuadPart) + (2);

		pFileBuffer = (BYTE *)(ExAllocatePool( PagedPool, nFileSize ));

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
	if( nFileSize > 0 ) {

		pFileBuffer[ nFileSize - 2 ] = 0x00;

		pFileBuffer[ nFileSize - 1 ] = 0x00;
	}
	// 2.0 DOWNLOAD TEXT CONTENT
	// 
	ULONGLONG start_times = KeQueryInterruptTime();

	ULONGLONG stop_times = 0;

	RtlCopyMemory( p_ch_cfg->osd_cfg.osd_txt.data, pFileBuffer, nFileSize );

	p_ch_cfg->osd_cfg.osd_txt.text_line = 1;

	p_ch_cfg->osd_cfg.osd_txt.text_length = nFileSize;

	if( p_tosd_req ) {

		RtlCopyMemory( p_tosd_req->osd_txt, pFileBuffer, nFileSize );

		p_tosd_req->len = nFileSize;
	}
	stop_times = KeQueryInterruptTime();

	AMEBDAD_PRINT( ("- TOTAL DOWNLOAD TIMES = %08d (%d BYTES)\n", (ULONG)(stop_times - start_times), nFileSize) );

	// 3.0 FREE WORKING BUFFER
	//
	FREE_MEMORY( pFileBuffer );

	return TRUE;
*/

//windows driver read OSD.txt, linux driver use property set

	BYTE *            pFileBuffer = NULL;
	ULONG             nFileSize = 0;
	
	nFileSize = strlen( pDevice->m_pCustomOsdTextStringProperty[ j/2 ][ 0 ] ) + 1;
	
	pFileBuffer = pDevice->m_pCustomOsdTextStringProperty[ j/2 ][ 0 ];

	if(  nFileSize == 0 )
	{
		return false;
	}
	else if( nFileSize < 1 )
	{
		return false;
	}
	else
	{
		pDevice->m_pCustomOsdTextStringProperty[ j/2 ][ 0 ][ nFileSize -1 ] = 0x00;
	}

	memcpy( p_ch_cfg->osd_cfg.osd_txt.data, pFileBuffer, nFileSize );

	p_ch_cfg->osd_cfg.osd_txt.text_line = 1;

	p_ch_cfg->osd_cfg.osd_txt.text_length = nFileSize;

	if( p_tosd_req ) {

		memcpy( p_tosd_req->osd_txt, pFileBuffer, nFileSize );

		p_tosd_req->len = nFileSize;
	}

	return TRUE;

}

//simplified chinese use GB18030

BOOLEAN CBAA449B6EB840758260682DA8444D8C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, BOOL is_init )
{
	BOOLEAN is_update = is_init ? TRUE : FALSE;

	if( pDevice->m_bCustomOsdTextStringRefreshProperty[ i ][ 0 ] ) {

		pDevice->m_bCustomOsdTextStringRefreshProperty[ i ][ 0 ] = FALSE;

		is_update = TRUE;
	}
	if( is_update ) { // -----> ch_set_tosd() [2012.03.29]

		ULONG j = FC2D5CAC8CF445D7859E0FC2E3700A46( pDevice, i );

		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

		switch( pDevice->m_nCustomOsdTextColorProperty[ i ][ 0 ] % 6 ) {

		case 0: p_ch_cfg->osd_cfg.osd_txt.brightness = 1; p_ch_cfg->osd_cfg.osd_txt.osd_txt_transparency = 0; break;

		case 1: p_ch_cfg->osd_cfg.osd_txt.brightness = 1; p_ch_cfg->osd_cfg.osd_txt.osd_txt_transparency = 1; break;

		case 2: p_ch_cfg->osd_cfg.osd_txt.brightness = 0; p_ch_cfg->osd_cfg.osd_txt.osd_txt_transparency = 0; break;

		case 3: p_ch_cfg->osd_cfg.osd_txt.brightness = 0; p_ch_cfg->osd_cfg.osd_txt.osd_txt_transparency = 1; break;

		case 4: p_ch_cfg->osd_cfg.osd_txt.brightness = 2; p_ch_cfg->osd_cfg.osd_txt.osd_txt_transparency = 0; break;

		case 5: p_ch_cfg->osd_cfg.osd_txt.brightness = 2; p_ch_cfg->osd_cfg.osd_txt.osd_txt_transparency = 1; break;
		}
//		ANSI_STRING s_ansi_string;

//		UNICODE_STRING s_unicode_string;

//		RtlInitAnsiString( &s_ansi_string, pDevice->m_pCustomOsdTextStringProperty[ i ][ 0 ] ); // IT IS OSD FILE PATH

//		RtlAnsiStringToUnicodeString( &s_unicode_string, &s_ansi_string, TRUE );


//		WCHAR pwsz[ MAX_PATH ];

//		wcscpy( pwsz, s_unicode_string.Buffer );

		CHAR pwsz[ MAX_PATH ] = "";

		sprintf( pwsz, "%s", pDevice->m_pCustomOsdTextStringProperty[ i ][ 0 ] );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%d]OSD i(%d) length(%d) %s\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, strlen( pDevice->m_pCustomOsdTextStringProperty[ i ][ 0 ] ), pwsz);


		{	req_tosd s_tosd_req;

			s_tosd_req.channel = j;

			s_tosd_req.cmd = 0x0000002B;

			s_tosd_req.osd_txt_en = 1;

			s_tosd_req.brightness = p_ch_cfg->osd_cfg.osd_txt.brightness;

			s_tosd_req.osd_txt_transparency = p_ch_cfg->osd_cfg.osd_txt.osd_txt_transparency;

			s_tosd_req.len = 0;
	
			if( pDevice->m_bCustomOsdTextEnableProperty == FALSE ) {

				s_tosd_req.osd_txt_en = 0;

				s_tosd_req.len = 0;
			}
			else if( strlen( pDevice->m_pCustomOsdTextStringProperty[ i ][ 0 ] ) == 0 ) { // DEFAULT TIMER

				s_tosd_req.osd_txt_en = 1;

				s_tosd_req.len = 26;

				s_tosd_req.osd_txt[  0 ]  =  ' ';
				s_tosd_req.osd_txt[  1 ]  =  '$';
				s_tosd_req.osd_txt[  2 ]  =  '$';
				s_tosd_req.osd_txt[  3 ]  =  '$';
				s_tosd_req.osd_txt[  4 ]  =  'Y';
				s_tosd_req.osd_txt[  5 ]  =  '.';
				s_tosd_req.osd_txt[  6 ]  =  '$';
				s_tosd_req.osd_txt[  7 ]  =  'M';
				s_tosd_req.osd_txt[  8 ]  =  '.';
				s_tosd_req.osd_txt[  9 ]  =  '$';
				s_tosd_req.osd_txt[ 10 ]  =  'd';
				s_tosd_req.osd_txt[ 11 ]  =  ' ';
				s_tosd_req.osd_txt[ 12 ]  =  '$';
				s_tosd_req.osd_txt[ 13 ]  =  'h';
				s_tosd_req.osd_txt[ 14 ]  =  '.';
				s_tosd_req.osd_txt[ 15 ]  =  '$';
				s_tosd_req.osd_txt[ 16 ]  =  'n';
				s_tosd_req.osd_txt[ 17 ]  =  '.';
				s_tosd_req.osd_txt[ 18 ]  =  '$';
				s_tosd_req.osd_txt[ 19 ]  =  's';
				s_tosd_req.osd_txt[ 20 ]  =  ' ';
				s_tosd_req.osd_txt[ 21 ]  =  '$';
				s_tosd_req.osd_txt[ 22 ]  =  '$';
				s_tosd_req.osd_txt[ 23 ]  =  '$';
				s_tosd_req.osd_txt[ 24 ]  =  'f';
				s_tosd_req.osd_txt[ 25 ]  = 0x00;
			}
			else if( FALSE == F553794FC37E402F98F04D85EB1CD9FA( pDevice, j, pwsz, &s_tosd_req ) ) {

				s_tosd_req.osd_txt_en = 0;

				s_tosd_req.len = 0;
			}
			ULONG counts = (sizeof(req_tosd) - TOSD_LEN) + ((s_tosd_req.len + 3) & (~3));

			UINT * po = (UINT *)(&s_tosd_req);

			UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

			ULONG c = 0;
			for( c = 0 ; c < counts ; c += 4 ) {

				de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

				pe += 4;

				po++;
			}
			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000002B, j ); // HCMD_SET_TOSD
		}
//		RtlFreeUnicodeString( &s_unicode_string );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d OSD.PATH = %s, ENABLE = %d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, pDevice->m_pCustomOsdTextStringProperty[ i ][ 0 ], pDevice->m_bCustomOsdTextEnableProperty);
	}
	return TRUE;
}
/*
BOOLEAN CBAA449B6EB840758260682DA8444D8C_PICTURE( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, BOOL is_init )
{
	BOOLEAN is_update = is_init ? TRUE : FALSE;

	if( pDevice->m_bCustomOsdPicturePathRefreshProperty[ i ][ 0 ] ||
		
		pDevice->m_bCustomOsdPicturePathRefreshProperty[ i ][ 1 ] ) {

		pDevice->m_bCustomOsdPicturePathRefreshProperty[ i ][ 0 ] = FALSE;

		pDevice->m_bCustomOsdPicturePathRefreshProperty[ i ][ 1 ] = FALSE;

		is_update = TRUE;
	}
	if( is_update ) { // -----> ch_set_gosd() [2012.03.29]

		ULONG j = FC2D5CAC8CF445D7859E0FC2E3700A46( pDevice, i );

		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

		req_gosd * p_gosd_req = (req_gosd *)(ExAllocatePool( NonPagedPoolCacheAligned, sizeof(req_gosd) ) );

		if( p_gosd_req ) {

			p_gosd_req->channel = j;

			p_gosd_req->cmd = 0x0000002C;

			{	ANSI_STRING s_ansi_string;

				UNICODE_STRING s_unicode_string;

				RtlInitAnsiString( &s_ansi_string, pDevice->m_pCustomOsdPicturePathProperty[ i ][ 0 ] ); // IT IS OSD FILE PATH

				RtlAnsiStringToUnicodeString( &s_unicode_string, &s_ansi_string, TRUE );

				WCHAR pwsz[ MAX_PATH ];

				wcscpy( pwsz, s_unicode_string.Buffer );

				if( strlen( pDevice->m_pCustomOsdPicturePathProperty[ i ][ 0 ] ) == 0 ) {

					p_gosd_req->osd_graph[ 0 ].osd_graphic_en = 0;
				}
				else if( FALSE == F553794FC37E402F98F04D85EB1CD9FA_PICTURE( pDevice, j, 0, pwsz, p_gosd_req, pDevice->m_nCustomOsdPictureParamsProperty[ i ][ 0 ] ) ) {

					p_gosd_req->osd_graph[ 0 ].osd_graphic_en = 0;
				}
				RtlFreeUnicodeString( &s_unicode_string );
			}
			{	ANSI_STRING s_ansi_string;

				UNICODE_STRING s_unicode_string;

				RtlInitAnsiString( &s_ansi_string, pDevice->m_pCustomOsdPicturePathProperty[ i ][ 1 ] ); // IT IS OSD FILE PATH

				RtlAnsiStringToUnicodeString( &s_unicode_string, &s_ansi_string, TRUE );

				WCHAR pwsz[ MAX_PATH ];

				wcscpy( pwsz, s_unicode_string.Buffer );

				if( strlen( pDevice->m_pCustomOsdPicturePathProperty[ i ][ 1 ] ) == 0 ) {

					p_gosd_req->osd_graph[ 1 ].osd_graphic_en = 0;
				}
				else if( FALSE == F553794FC37E402F98F04D85EB1CD9FA_PICTURE( pDevice, j, 1, pwsz, p_gosd_req, pDevice->m_nCustomOsdPictureParamsProperty[ i ][ 1 ] ) ) {

					p_gosd_req->osd_graph[ 1 ].osd_graphic_en = 0;
				}
				RtlFreeUnicodeString( &s_unicode_string );
			}
			ULONG * po = (ULONG *)(p_gosd_req);

			ULONG pe = (ULONG)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

			for( ULONG c = 0 ; c < sizeof(req_gosd) ; c += 4 ) {

				de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

				pe += 4;

				po++;
			}
			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000002C, j ); // HCMD_SET_GOSD
		}
		FREE_MEMORY( p_gosd_req );

		AMEBDAD_PRINT( ("%02d - CH%02d GOSD.PATH = %s\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, pDevice->m_pCustomOsdPicturePathProperty[ i ][ 0 ]) );
		
		AMEBDAD_PRINT( ("%02d - CH%02d GOSD.PATH = %s\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, pDevice->m_pCustomOsdPicturePathProperty[ i ][ 1 ]) );
	}
	return TRUE;
}
*/

BOOLEAN B653E6D9D1D64726B7FC24A32A88B17C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, BOOLEAN is_main, BOOL is_init )
{
	BOOLEAN is_update = is_init ? TRUE : FALSE;

	ULONG offsets = (is_main) ? 0 : 8;

	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d B653E6D9D1D64726B7FC24A32A88B17C() i(%d) F0DD7393CD1494e27A72652C7D1A97893(0x%x) F03DD48A54B1D4ffeB64170AA03AEFC6E(0x%x) \n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, pVideo->F0DD7393CD1494e27A72652C7D1A97893, pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E );

	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d B653E6D9D1D64726B7FC24A32A88B17C() is_main(0x%x) is_init(0x%x) FD1832F8D382F4e91914C0048CC5A9DD8(0x%x) F5B8891B732954fc2B26B7BFFCB15B596(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, is_main, is_init, pVideo->FD1832F8D382F4e91914C0048CC5A9DD8, pVideo->F5B8891B732954fc2B26B7BFFCB15B596 );

	//check dummy
	/*
	int j = 0;
	for(j = 0; j < 8; j++)
	{
		if( pDevice->m_nDummy3[ j ] )
		{
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] m_nDummy3[%d](0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, j, pDevice->m_nDummy3[ j ] );

			pDevice->m_nDummy3[ j ] = 0;
		}
	}
	*/

	if( pDevice->m_nCustomEncoderVideoResolutionProperty[ i + offsets ] &  0x88000000 ) {

		pDevice->m_nCustomEncoderVideoResolutionProperty[ i + offsets ] &= 0x77FFFFFF;

		is_update = TRUE;
	}

	if( pDevice->m_nH264HVScaleFactor &  0x88000000 )
	{
		pDevice->m_nH264HVScaleFactor &= 0x77FFFFFF;

		is_update = TRUE;
	}
	
	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d B653E6D9D1D64726B7FC24A32A88B17C()  m_nH264HVScaleFactor(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->m_nH264HVScaleFactor );


	if( is_update ) { // -----> ch_set_venc_resolution() [2012.03.29]

		ULONG j = FC2D5CAC8CF445D7859E0FC2E3700A46( pDevice, i );

		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

		ULONG cx = (pDevice->m_nCustomEncoderVideoResolutionProperty[ i + offsets ] & 0x00FFF000) >> 12;

		ULONG cy = (pDevice->m_nCustomEncoderVideoResolutionProperty[ i + offsets ] & 0x00000FFF) >>  0;

		//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d B653E6D9D1D64726B7FC24A32A88B17C()-- is_main(0x%x) cx(0d%d) cy(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, is_main, cx, cy );

		if( is_main ) { 

			if( cx == 720 && cy == 480 ) { p_ch_cfg->vpu_cfg.HCoeff = 0; p_ch_cfg->vpu_cfg.VCoeff = 0; } else

			if( cx == 720 && cy == 576 ) { p_ch_cfg->vpu_cfg.HCoeff = 0; p_ch_cfg->vpu_cfg.VCoeff = 0; } else

			if( cx == 704 && cy == 480 ) { p_ch_cfg->vpu_cfg.HCoeff = 0; p_ch_cfg->vpu_cfg.VCoeff = 0; } else

			if( cx == 704 && cy == 576 ) { p_ch_cfg->vpu_cfg.HCoeff = 0; p_ch_cfg->vpu_cfg.VCoeff = 0; } else

			if( cx == 720 && cy == 240 ) { p_ch_cfg->vpu_cfg.HCoeff = 0; p_ch_cfg->vpu_cfg.VCoeff = 2; } else

			if( cx == 720 && cy == 288 ) { p_ch_cfg->vpu_cfg.HCoeff = 0; p_ch_cfg->vpu_cfg.VCoeff = 2; } else

			if( cx == 704 && cy == 240 ) { p_ch_cfg->vpu_cfg.HCoeff = 0; p_ch_cfg->vpu_cfg.VCoeff = 2; } else

			if( cx == 704 && cy == 288 ) { p_ch_cfg->vpu_cfg.HCoeff = 0; p_ch_cfg->vpu_cfg.VCoeff = 2; } else

			if( cx == 352 && cy == 240 ) { p_ch_cfg->vpu_cfg.HCoeff = 2; p_ch_cfg->vpu_cfg.VCoeff = 2; } else

			if( cx == 352 && cy == 288 ) { p_ch_cfg->vpu_cfg.HCoeff = 2; p_ch_cfg->vpu_cfg.VCoeff = 2; } else

			if( cx == 176 && cy == 120 ) { p_ch_cfg->vpu_cfg.HCoeff = 3; p_ch_cfg->vpu_cfg.VCoeff = 3; } else

			if( cx == 176 && cy == 144 ) { p_ch_cfg->vpu_cfg.HCoeff = 3; p_ch_cfg->vpu_cfg.VCoeff = 3; } else

										 { p_ch_cfg->vpu_cfg.HCoeff = 0; p_ch_cfg->vpu_cfg.VCoeff = 0; }

		
			if( (pDevice->m_nH264HVScaleFactor >> 16) != 0x00000000 )
			{
				if( ((pDevice->m_nH264HVScaleFactor >> 24) & 0x3) == 2 )
				{
					p_ch_cfg->vpu_cfg.HCoeff = 2;
				}
				else if( ((pDevice->m_nH264HVScaleFactor >> 24) & 0x3) == 3 )
				{
					p_ch_cfg->vpu_cfg.HCoeff = 3;
				}
				else
				{
					p_ch_cfg->vpu_cfg.HCoeff = 0;
				}

				if( ((pDevice->m_nH264HVScaleFactor >> 16) & 0x3) == 2 )
				{
					p_ch_cfg->vpu_cfg.VCoeff = 2;
				}
				else if( ((pDevice->m_nH264HVScaleFactor >> 16) & 0x3) == 3 )
				{
					p_ch_cfg->vpu_cfg.VCoeff = 3;
				}
				else
				{
					p_ch_cfg->vpu_cfg.VCoeff = 0;
				}
			}
	
			//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d B653E6D9D1D64726B7FC24A32A88B17C()  main HCoeff(0x%x) VCoeff(0x%x) \n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_ch_cfg->vpu_cfg.HCoeff, p_ch_cfg->vpu_cfg.VCoeff );

		}
		else {

			if( cx == 352 && cy == 240 ) { p_ch_cfg->vpu_cfg.Aux_HCoeff = 2; p_ch_cfg->vpu_cfg.Aux_VCoeff = 2; } else

			if( cx == 352 && cy == 288 ) { p_ch_cfg->vpu_cfg.Aux_HCoeff = 2; p_ch_cfg->vpu_cfg.Aux_VCoeff = 2; } else

			if( cx == 176 && cy == 120 ) { p_ch_cfg->vpu_cfg.Aux_HCoeff = 3; p_ch_cfg->vpu_cfg.Aux_VCoeff = 3; } else

			if( cx == 176 && cy == 144 ) { p_ch_cfg->vpu_cfg.Aux_HCoeff = 3; p_ch_cfg->vpu_cfg.Aux_VCoeff = 3; } else

										 { p_ch_cfg->vpu_cfg.Aux_HCoeff = 2; p_ch_cfg->vpu_cfg.Aux_VCoeff = 2; }

			if( (pDevice->m_nH264HVScaleFactor & 0xFFFF ) != 0x00000202 )
			{
				if( ((pDevice->m_nH264HVScaleFactor >> 8) & 0x3) == 2 )
				{
					p_ch_cfg->vpu_cfg.Aux_HCoeff = 2;
				}
				else if( ((pDevice->m_nH264HVScaleFactor >> 8) & 0x3) == 3 )
				{
					p_ch_cfg->vpu_cfg.Aux_HCoeff = 3;
				}
				else
				{
					p_ch_cfg->vpu_cfg.Aux_HCoeff = 0;
				}

				if( ((pDevice->m_nH264HVScaleFactor) & 0x3) == 2 )
				{
					p_ch_cfg->vpu_cfg.Aux_VCoeff = 2;
				}
				else if( ((pDevice->m_nH264HVScaleFactor) & 0x3) == 3 )
				{
					p_ch_cfg->vpu_cfg.Aux_VCoeff = 3;
				}
				else
				{
					p_ch_cfg->vpu_cfg.Aux_VCoeff = 0;
				}
			}
			//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d B653E6D9D1D64726B7FC24A32A88B17C()  sub  Aux_HCoeff(0x%x) Aux_VCoeff(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_ch_cfg->vpu_cfg.Aux_HCoeff, p_ch_cfg->vpu_cfg.Aux_VCoeff );
		}

	
		{	req_enc_coeff s_enc_coeff_req;

			s_enc_coeff_req.channel = j;

			s_enc_coeff_req.cmd = 0x00000025;

			if( is_main ) { 

				s_enc_coeff_req.enc_type = 1;

				s_enc_coeff_req.hcoeff = p_ch_cfg->vpu_cfg.HCoeff;

				s_enc_coeff_req.vcoeff = p_ch_cfg->vpu_cfg.VCoeff;
			}
			else {

				s_enc_coeff_req.enc_type = 2;

				s_enc_coeff_req.hcoeff = p_ch_cfg->vpu_cfg.Aux_HCoeff;

				s_enc_coeff_req.vcoeff = p_ch_cfg->vpu_cfg.Aux_VCoeff;
			}
			UINT * po = (UINT *)(&s_enc_coeff_req);

			UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

			ULONG c = 0;
			for( c = 0 ; c < sizeof(s_enc_coeff_req) ; c += 4 ) {

				de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

				pe += 4;

				po++;
			}
			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000025, j ); // HCMD_SET_ENC_COEFF
		}
		if( is_main ) {

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d MAIN.RESOLUTION = %d x %d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, p_ch_cfg->vpu_cfg.HCoeff, p_ch_cfg->vpu_cfg.VCoeff);
		}
		else {

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d SUB.RESOLUTION = %d x %d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, p_ch_cfg->vpu_cfg.Aux_HCoeff, p_ch_cfg->vpu_cfg.Aux_VCoeff);
		}
	}
	return TRUE;
}

BOOLEAN D8BFF5C85D4F45299903992DFA9C3704( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, BOOLEAN is_main, BOOL is_init )
{
	BOOLEAN is_update = is_init ? TRUE : FALSE;

	ULONG offsets = (is_main) ? 0 : 8;

	if( pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ i + offsets ] &  0x88000000 ) {

		pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ i + offsets ] &= 0x77FFFFFF;

		is_update = TRUE;
	}
	if( pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ i + offsets ] &  0x88000000 ) {

		pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ i + offsets ] &= 0x77FFFFFF;

		is_update = TRUE;
	}
	if( is_update ) { // -----> fh35_api_venc_set_drop_mask() + ch_set_frame_rate() [2012.03.29]

		ULONG j = FC2D5CAC8CF445D7859E0FC2E3700A46( pDevice, i );

		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

		ULONG avg = (pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ i + offsets ] & 0x77FFFFFF);

		ULONG skip = (pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ i + offsets ] & 0x77FFFFFF) + (1);

		if( skip == 1 ) {
			
			skip = 0;
		}
		if( avg > 0 ) {

			skip = 0;
		}
		// -----> fh35_api_venc_set_drop_mask() [2012.03.29]
		//
		{	req_enc_drop_mask s_enc_drop_mask_req;

			s_enc_drop_mask_req.channel = j;

			s_enc_drop_mask_req.cmd = 0x00000024;

			s_enc_drop_mask_req.enc_type = (is_main) ? 1 : 2;

			s_enc_drop_mask_req.mask = 0x00000001;

			s_enc_drop_mask_req.mask_len = skip;

			UINT * po = (UINT *)(&s_enc_drop_mask_req);

			UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

			ULONG c = 0;
			for( c = 0 ; c < sizeof(req_enc_drop_mask) ; c += 4 ) {

				de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

				pe += 4;

				po++;
			}
			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000024, j ); // HCMD_SET_ENC_DROP_MASK

			if( is_main ) {

				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d MAIN.FPS = 1 / %d (SKIP)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, s_enc_drop_mask_req.mask_len);
			}
			else {

				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d SUB.FPS = 1 / %d (SKIP)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, s_enc_drop_mask_req.mask_len);
			}
		}
		// -----> ch_set_frame_rate() [2012.03.29]
		//
		{	req_enc_frame_rate s_enc_frame_rate_req;

			s_enc_frame_rate_req.channel = j;

			s_enc_frame_rate_req.cmd = 0x00000026;

			s_enc_frame_rate_req.enc_type = (is_main) ? 1 : 2;

			s_enc_frame_rate_req.frame_rate = (avg == 0) ? (85) : (avg); 

			UINT * po = (UINT *)(&s_enc_frame_rate_req);

			UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

			ULONG c = 0;
			for( c = 0 ; c < sizeof(req_enc_frame_rate) ; c += 4 ) {

				de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

				pe += 4;

				po++;
			}
			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000026, j ); // HCMD_SET_ENC_FRAME_RATE

			if( is_main ) {

				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d MAIN.FPS = %d (AVG)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, s_enc_frame_rate_req.frame_rate);
			}
			else {

				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d SUB.FPS = %d (AVG)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, s_enc_frame_rate_req.frame_rate);
			}
		}
	}
	return TRUE;
}

BOOLEAN ADDCFCA61FB243418097E0666FCEABE5( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, BOOLEAN is_main, BOOL is_init )
{
	BOOLEAN is_update = is_init ? TRUE : FALSE;

	ULONG offsets = (is_main) ? 0 : 8;
	
	if( pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + offsets ] &  0x88000000 ) {

		pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + offsets ] &= 0x77FFFFFF;
		
		is_update = TRUE;
	}
	if( pDevice->m_nCustomEncoderVideoBitRateProperty[ i + offsets ] &  0x88000000 ) {

		pDevice->m_nCustomEncoderVideoBitRateProperty[ i + offsets ] &= 0x77FFFFFF;

		is_update = TRUE;
	}
	if( pDevice->m_nAnalogVideoCompressionQualityProperty[ i + offsets ] &  0x88000000 ) {

		pDevice->m_nAnalogVideoCompressionQualityProperty[ i + offsets ] &= 0x77FFFFFF;

		is_update = TRUE;
	}
	if( is_update ) { // -----> ch_set_bitrate() [2012.03.29]

		ULONG j = FC2D5CAC8CF445D7859E0FC2E3700A46( pDevice, i );

		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

		ULONG quality = pDevice->m_nAnalogVideoCompressionQualityProperty[ i + offsets ] & 0x77FFFFFF;

		quality /= 454; // QP RANGE: 16 ~ 38

		if( quality > 22 ) { quality = 22; }

		if( is_main ) { 
			// In AP, V is 0, C is 1
			//in V4L2, constant is 1, variable is 2
			//for FH8735 , 1 is constant, 0 is variable
			
			//p_ch_cfg->enc_cfg.rc_mode = (pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + offsets ] & 0x77FFFFFF);

			if( (pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + offsets ] & 0x77FFFFFF) == V4L2_MPEG_VIDEO_BITRATE_MODE_VBR )
			{
				p_ch_cfg->enc_cfg.rc_mode = 0;
			}
			else if( (pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + offsets ] & 0x77FFFFFF) == V4L2_MPEG_VIDEO_BITRATE_MODE_CBR )
			{
				p_ch_cfg->enc_cfg.rc_mode = 1;
			}
			else
			{
				p_ch_cfg->enc_cfg.rc_mode = 1;
			}

			//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "ADDCFCA61FB243418097E0666FCEABE5()  is_main rc_mode(0x%x)\n", p_ch_cfg->enc_cfg.rc_mode );

			p_ch_cfg->enc_cfg.target_bitrate = (pDevice->m_nCustomEncoderVideoBitRateProperty[ i + offsets ] & 0x77FFFFFF) / (1024);

			p_ch_cfg->enc_cfg.init_qp = (22 - quality) + 16;

			p_ch_cfg->enc_cfg.i_qp = (22 - quality) + 16 + 2;

			p_ch_cfg->enc_cfg.p_qp = (22 - quality) + 16;

			p_ch_cfg->enc_cfg.b_qp = (22 - quality) + 16;
		}
		else {

			//p_ch_cfg->enc_cfg.sub_rc_mode = (pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + offsets ] & 0x77FFFFFF);

			if( (pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + offsets ] & 0x77FFFFFF) == V4L2_MPEG_VIDEO_BITRATE_MODE_VBR )
			{
				p_ch_cfg->enc_cfg.sub_rc_mode = 0;
			}
			else if( (pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i + offsets ] & 0x77FFFFFF) == V4L2_MPEG_VIDEO_BITRATE_MODE_CBR )
			{
				p_ch_cfg->enc_cfg.sub_rc_mode = 1;
			}
			else
			{
				p_ch_cfg->enc_cfg.sub_rc_mode = 1;
			}

			//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "ADDCFCA61FB243418097E0666FCEABE5()  is_sub rc_mode(0x%x)\n", p_ch_cfg->enc_cfg.rc_mode );

			p_ch_cfg->enc_cfg.sub_target_bitrate = (pDevice->m_nCustomEncoderVideoBitRateProperty[ i + offsets ] & 0x77FFFFFF) / (1024);

			p_ch_cfg->enc_cfg.sub_init_qp = (22 - quality) + 16;

			p_ch_cfg->enc_cfg.sub_i_qp = (22 - quality) + 16 + 2;

			p_ch_cfg->enc_cfg.sub_p_qp = (22 - quality) + 16;

			p_ch_cfg->enc_cfg.sub_b_qp = (22 - quality) + 16;
		}
		{	req_enc_bitrate s_enc_bitrate_req;

			s_enc_bitrate_req.channel = j;

			s_enc_bitrate_req.cmd = 0x00000027;

			if( is_main ) { 

				s_enc_bitrate_req.enc_type = 1;

				s_enc_bitrate_req.rc_mode = p_ch_cfg->enc_cfg.rc_mode;

				s_enc_bitrate_req.bitrate = p_ch_cfg->enc_cfg.target_bitrate;

				s_enc_bitrate_req.init_qp = p_ch_cfg->enc_cfg.init_qp;

				s_enc_bitrate_req.i_qp = p_ch_cfg->enc_cfg.i_qp;

				s_enc_bitrate_req.p_qp = p_ch_cfg->enc_cfg.p_qp;

				s_enc_bitrate_req.b_qp = p_ch_cfg->enc_cfg.b_qp;
			}
			else {

				s_enc_bitrate_req.enc_type = 2;

				s_enc_bitrate_req.rc_mode = p_ch_cfg->enc_cfg.sub_rc_mode;

				s_enc_bitrate_req.bitrate = p_ch_cfg->enc_cfg.sub_target_bitrate;

				s_enc_bitrate_req.init_qp = p_ch_cfg->enc_cfg.sub_init_qp;

				s_enc_bitrate_req.i_qp = p_ch_cfg->enc_cfg.sub_i_qp;

				s_enc_bitrate_req.p_qp = p_ch_cfg->enc_cfg.sub_p_qp;

				s_enc_bitrate_req.b_qp = p_ch_cfg->enc_cfg.sub_b_qp;
			}
			UINT * po = (UINT *)(&s_enc_bitrate_req);

			UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

			ULONG c = 0;
			for( c = 0 ; c < sizeof(req_enc_bitrate) ; c += 4 ) {

				de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

				pe += 4;

				po++;
			}
			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000027, j ); // HCMD_SET_ENC_BITRATE
		}
		if( is_main ) {

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d MAIN.RC = %d, MAIN.BPS = %d, MAIN.QP = %d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, p_ch_cfg->enc_cfg.rc_mode, p_ch_cfg->enc_cfg.target_bitrate, p_ch_cfg->enc_cfg.init_qp);
		}
		else {

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d SUB.RC = %d, SUB.BPS = %d, SUB.QP = %d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, p_ch_cfg->enc_cfg.sub_rc_mode, p_ch_cfg->enc_cfg.sub_target_bitrate, p_ch_cfg->enc_cfg.sub_init_qp);
		}
	//	p_ch_cfg->enc_cfg.rc_mode = 1;
	//
	//	p_ch_cfg->enc_cfg.target_bitrate = 17000; // 電視台標準
	//
	//	p_ch_cfg->enc_cfg.target_bitrate = 23000; // 電視台標準
	//
	//	p_ch_cfg->enc_cfg.init_qp = 10;
	//
	//	p_ch_cfg->enc_cfg.i_qp = 10;
	//
	//	p_ch_cfg->enc_cfg.p_qp = 10;
	//
	//	p_ch_cfg->enc_cfg.b_qp = 10;
	}
	return TRUE;
}

BOOLEAN E232E37AE6C0482C934B1086B56E8110( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, BOOLEAN is_main, BOOL is_init )
{
	BOOLEAN is_update = is_init ? TRUE : FALSE;

	ULONG offsets = (is_main) ? 0 : 8;
	
	if( pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ i + offsets ] &  0x88000000 ) {

		pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ i + offsets ] &= 0x77FFFFFF;

		is_update = TRUE;
	}
	if( is_update ) { // -----> ch_set_keyframe() [2012.03.29]

		ULONG j = FC2D5CAC8CF445D7859E0FC2E3700A46( pDevice, i );

		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

		ULONG gop = pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ i + offsets ] & 0x77FFFFFF;

		if( gop ==   0 ) { gop =   1; }
	
		if( gop >= 255 ) { gop = 255; }

		if( is_main ) { 
			
			p_ch_cfg->enc_cfg.GOP_length = gop; 
		}
		else {

			p_ch_cfg->enc_cfg.sub_gop_length = gop;
		}
		{	req_enc_gop s_enc_gop_req;

			s_enc_gop_req.channel = j;

			s_enc_gop_req.cmd = 0x00000028;

			if( is_main ) { 

				s_enc_gop_req.enc_type = 1;

				s_enc_gop_req.gop = p_ch_cfg->enc_cfg.GOP_length;
			}
			else {

				s_enc_gop_req.enc_type = 2;

				s_enc_gop_req.gop = p_ch_cfg->enc_cfg.sub_gop_length;
			}
			UINT * po = (UINT *)(&s_enc_gop_req);

			UINT pe = (UINT)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

			ULONG c = 0;
			for( c = 0 ; c < sizeof(req_enc_gop) ; c += 4 ) {

				de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

				pe += 4;

				po++;
			}
			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000028, j ); // HCMD_SET_ENC_GOP
		}
		if( is_main ) {
			
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d MAIN.GOP = %d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, p_ch_cfg->enc_cfg.GOP_length);
		}
		else {

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%02d - CH%02d SUB.GOP = %d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, p_ch_cfg->enc_cfg.sub_gop_length);
		}
	}
	return TRUE;
}
//???????
/*
BOOLEAN FH8735_CH_SET_ENC_CROP( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, BOOLEAN is_main, BOOL is_init )
{
	BOOLEAN is_update = is_init ? TRUE : FALSE;

	ULONG offsets = (is_main) ? 0 : 8;

	if( (pDevice->m_nCustomEncoderVideoCropProperty[ 0 ][ i + offsets ] &  0x88000000) ||
		
		(pDevice->m_nCustomEncoderVideoCropProperty[ 1 ][ i + offsets ] &  0x88000000) ||
		
		(pDevice->m_nCustomEncoderVideoCropProperty[ 2 ][ i + offsets ] &  0x88000000) ||
		
		(pDevice->m_nCustomEncoderVideoCropProperty[ 3 ][ i + offsets ] &  0x88000000) ) {

		 pDevice->m_nCustomEncoderVideoCropProperty[ 0 ][ i + offsets ] &= 0x77FFFFFF;

		 pDevice->m_nCustomEncoderVideoCropProperty[ 1 ][ i + offsets ] &= 0x77FFFFFF;

		 pDevice->m_nCustomEncoderVideoCropProperty[ 2 ][ i + offsets ] &= 0x77FFFFFF;

		 pDevice->m_nCustomEncoderVideoCropProperty[ 3 ][ i + offsets ] &= 0x77FFFFFF;

		 is_update = TRUE;
	}
	if( is_update ) { // -----> ch_set_venc_crop() [2012.03.29]

		ULONG j = FC2D5CAC8CF445D7859E0FC2E3700A46( pDevice, i );

		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		FH8735_CH_CFG * p_ch_cfg = (FH8735_CH_CFG *)(&(p_sys_cfg->ch_cfg[ j ]));

		req_enc_crop s_req_enc_crop;

		s_req_enc_crop.channel = j;

		s_req_enc_crop.cmd = 0x00000036;

		if( is_main ) { 

			if( (pDevice->m_nCustomEncoderVideoCropProperty[ 2 ][ i + offsets ] & 0x77FFFFFF) > 0 &&

				(pDevice->m_nCustomEncoderVideoCropProperty[ 3 ][ i + offsets ] & 0x77FFFFFF) > 0 ) {

				s_req_enc_crop.crop_enable = 1;
			}
			else {

				s_req_enc_crop.crop_enable = 0;
			}
			s_req_enc_crop.enc_type = 1;

			s_req_enc_crop.Enc_img_leftup_x = pDevice->m_nCustomEncoderVideoCropProperty[ 0 ][ i + offsets ] & 0x77FFFFFF;

			s_req_enc_crop.Enc_img_leftup_y = pDevice->m_nCustomEncoderVideoCropProperty[ 1 ][ i + offsets ] & 0x77FFFFFF;

			s_req_enc_crop.Enc_img_width    = pDevice->m_nCustomEncoderVideoCropProperty[ 2 ][ i + offsets ] & 0x77FFFFFF;

			s_req_enc_crop.Enc_img_height   = pDevice->m_nCustomEncoderVideoCropProperty[ 3 ][ i + offsets ] & 0x77FFFFFF;
		}
		else {

			if( (pDevice->m_nCustomEncoderVideoCropProperty[ 2 ][ i + offsets ] & 0x77FFFFFF) > 0 &&

				(pDevice->m_nCustomEncoderVideoCropProperty[ 3 ][ i + offsets ] & 0x77FFFFFF) > 0 ) {

				s_req_enc_crop.crop_enable = 1;
			}
			else {

				s_req_enc_crop.crop_enable = 0;
			}
			s_req_enc_crop.enc_type = 2;

			s_req_enc_crop.Enc_img_leftup_x = pDevice->m_nCustomEncoderVideoCropProperty[ 0 ][ i + offsets ] & 0x77FFFFFF;

			s_req_enc_crop.Enc_img_leftup_y = pDevice->m_nCustomEncoderVideoCropProperty[ 1 ][ i + offsets ] & 0x77FFFFFF;

			s_req_enc_crop.Enc_img_width    = pDevice->m_nCustomEncoderVideoCropProperty[ 2 ][ i + offsets ] & 0x77FFFFFF;

			s_req_enc_crop.Enc_img_height   = pDevice->m_nCustomEncoderVideoCropProperty[ 3 ][ i + offsets ] & 0x77FFFFFF;
		}
		if( s_req_enc_crop.crop_enable == 1 ) {

			ULONG * po = (ULONG *)(&s_req_enc_crop);

			ULONG pe = (ULONG)(p_sys_cfg->para_addr + sizeof(usr_cfg_head_t));

			for( ULONG c = 0 ; c < sizeof(s_req_enc_crop) ; c += 4 ) {

				de288df0e76e4990be34b3bea95ca349( pDevice, 3, pe, po[ 0 ] );

				pe += 4;

				po++;
			}
			aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000036, j ); // HCMD_SET_ENC_CROP
			
			ADDCFCA61FB243418097E0666FCEABE5( pDevice, i, is_main, TRUE );
		}
		if( is_main ) {

			AMEBDAD_PRINT( ("%02d - CH%02d MAIN.CROP = %d × %d × %d × %d × %d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, s_req_enc_crop.crop_enable, s_req_enc_crop.Enc_img_leftup_x, s_req_enc_crop.Enc_img_leftup_y, s_req_enc_crop.Enc_img_width, s_req_enc_crop.Enc_img_height) );
		}
		else {

			AMEBDAD_PRINT( ("%02d - CH%02d SUB.CROP = %d × %d × %d × %d × %d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, s_req_enc_crop.crop_enable, s_req_enc_crop.Enc_img_leftup_x, s_req_enc_crop.Enc_img_leftup_y, s_req_enc_crop.Enc_img_width, s_req_enc_crop.Enc_img_height) );
		}
	}
	return TRUE;
}
*/

BOOLEAN EF45D08A9BB74090B11C410FFCC75E04( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] EF45D08A9BB74090B11C410FFCC75E04()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

	// -----> fh35_reset_firmware() [2012.03.29]
	//
	ULONG R00400000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00400000 ); // CLEAR IRU INTERRPUT

	ULONG i = 0;
	for( i = 0 ; i < 5 ; i++ ) {

		#ifndef FH8735_JTAG_DEBUG

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400000, 0x00000000 ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 10000 );

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00100028, 0x0000039F ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 10000 ); // ALL

		#else

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400000, 0x00000001 ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 10000 );

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00100028, 0x0000019F ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 10000 ); //_ALL_BUTCPU

		#endif
	}	
	R00400000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00400000 ); // CLEAR IRU INTERRPUT

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00500030, 0x00000000 ); // CLEAR TIMER INTERRPUT

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00500034, 0xFFFFFFFF );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00A00004, 0x00000000 ); // CLEAR UART INTERRUPT AND RX/TX FIFO

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00A00008, 0x00000006 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700030, 0x0000000F ); // GPIO AND DISABLE GPIO INT_32

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700020, 0x00000000 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00100008, 0x1E011E01 ); // CONFIG PMU CPU FREQUENCY

	// -----> fh35_reset_firmware() -----> fh35_config_ddrc() [2012.03.29]
	//
	de288df0e76e4990be34b3bea95ca349( pDevice, 2, 0x00200000, 0x0E53C600 ); // CONFIG DDRC (DDR#0)

	de288df0e76e4990be34b3bea95ca349( pDevice, 2, 0x00200004, 0x200E3434 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 2, 0x00200008, 0x00000033 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 2, 0x0020000C, 0x00000000 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 2, 0x00300000, 0x0E53C600 ); // CONFIG DDRC (DDR#1)

	de288df0e76e4990be34b3bea95ca349( pDevice, 2, 0x00300004, 0x200E3434 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 2, 0x00300008, 0x00000033 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 2, 0x0030000C, 0x00000000 );

	FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 10000 );

#if 0 // DEBUGING

	// -----> fh35_api_ddr_test() [2011.05.10]
	//
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "BEGIN DDR TEST\n");

	ULONG i = 0;
	for( i = 0 ; i < 0x100000 ; i++ ) {

		de288df0e76e4990be34b3bea95ca349( pDevice, 3, i * 4, i );

		ULONG R = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 3, i * 4 );

		if( R != i ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TEST ERROR %08X -> %08X ERROR\n", i * 4, R); break ; }

		de288df0e76e4990be34b3bea95ca349( pDevice, 3, i * 4, 0xA5A55A5A );

		R = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 3, i * 4 );

		if( R != 0xA5A55A5A ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TEST ERROR %08X -> %08X (A5A55A5A) ERROR\n", i * 4, R); break ; }
	}
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "END DDR TEST\n");

#endif

	return TRUE;
}

BOOLEAN D20D6BFCE0DB426E8618426CE804DB32( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BOOL is_init )
{
	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "D20D6BFCE0DB426E8618426CE804DB32() is_init(0x%x)\n", is_init);

	ULONG channels = 0;

	if( (pDevice->iManufacturer) == 0x85 ) { 
		
		channels = 5; // 5 CHANNELS
	}
	else if( (pDevice->iProduct & 0x0F) == 0x05 ||
	
			 (pDevice->iProduct & 0x0F) == 0x07 ) { 
		
		channels = 1; // 1 CHANNEL ONLY
	}
	else {

		channels = 4; // 4 CHANNELS
	}
	ULONG i = 0;
	for( i = 0 ; i < channels ; i++ ) { // DYNAMICALLY HARDWARE PARAMETER UPDATE

		CCC08FAB4DA74DB0BEF260E7E6A213AF( pDevice, i );

		E14B419B180144FA905B3F38192704C7( pDevice, i, is_init );

		D1A4965F8D614345A6A1ACD04B201680( pDevice, i, is_init );

		EB57E76A6D474FCAA2769C8E53FD5081( pDevice, i, is_init );

		E164895E8C494B179A8ADE287DDFCEA8( pDevice, i, is_init );

		D7A9F02797E148C3B4E81FAA8455FABC( pDevice, i, is_init );

		CBAA449B6EB840758260682DA8444D8C( pDevice, i, is_init );

		B653E6D9D1D64726B7FC24A32A88B17C( pDevice, i, TRUE, is_init );

		B653E6D9D1D64726B7FC24A32A88B17C( pDevice, i, FALSE, is_init );

		D8BFF5C85D4F45299903992DFA9C3704( pDevice, i, TRUE, is_init );

		D8BFF5C85D4F45299903992DFA9C3704( pDevice, i, FALSE, is_init );

		ADDCFCA61FB243418097E0666FCEABE5( pDevice, i, TRUE, is_init );

		ADDCFCA61FB243418097E0666FCEABE5( pDevice, i, FALSE, is_init );

		E232E37AE6C0482C934B1086B56E8110( pDevice, i, TRUE, is_init );

		E232E37AE6C0482C934B1086B56E8110( pDevice, i, FALSE, is_init );
/*
		FH8735_CH_SET_ENC_CROP( pDevice, i, TRUE, is_init );

		FH8735_CH_SET_ENC_CROP( pDevice, i, FALSE, is_init );
*/
	}

	return TRUE;
}

BOOLEAN F7067684D2E34E8E8D3A9D12F6FEFF62( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE* pwszFileName )
{
	FH8735_SYS_CFG *  p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

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

	ULONG			  n_init_ch_cfg_viu_cfg_drop_drop_mask = 1;

	ULONG			  n_init_ch_cfg_viu_cfg_drop_drop_mask_len = 1;

	ULONG			  n_try_error_counts = 0;

	BOOL              b_is_sync_success = FALSE;

	swprintf( wszPathName, L"%s%s", pDevice->m_pCustomDeviceInfoDirectoryProperty, pwszFileName );

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "F7067684D2E34E8E8D3A9D12F6FEFF62( %d x \"%ws\" )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, wszPathName);

	// 1.0 OPEN FIRMWARE FH8735.HEX FILE
	// 
	oFileName.MaximumLength = wcslen(wszPathName) * 2 + sizeof(UNICODE_NULL);

	oFileName.Buffer = (PWSTR)(ExAllocatePool( PagedPool, oFileName.MaximumLength ));

	oFileName.Length = 0;

	if( oFileName.Buffer == NULL ) {

		return FALSE;
	}
	else {

		RtlZeroMemory( oFileName.Buffer, oFileName.MaximumLength );
	}
	status = RtlAppendUnicodeToString( &oFileName, wszPathName );

	InitializeObjectAttributes( (POBJECT_ATTRIBUTES)(&oObjectAttributes), (PUNICODE_STRING)(&oFileName), OBJ_CASE_INSENSITIVE, NULL, NULL );

	status = ZwCreateFile( &hFileHandle, FILE_READ_DATA, &oObjectAttributes, &oIoStatus, 0, FILE_ATTRIBUTE_NORMAL, FILE_SHARE_READ, FILE_OPEN, FILE_SYNCHRONOUS_IO_NONALERT, NULL, 0 );

	FREE_MEMORY( oFileName.Buffer );

	if( NT_SUCCESS(status) ) {

		FILE_STANDARD_INFORMATION oFileStandardInfomation;

		ZwQueryInformationFile( hFileHandle, &oIoStatus, &oFileStandardInfomation, sizeof(FILE_STANDARD_INFORMATION), FileStandardInformation );

		nFileSize = (ULONG)(oFileStandardInfomation.EndOfFile.QuadPart);

		pFileBuffer = (BYTE *)(ExAllocatePool( PagedPool, nFileSize ));

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
*/

	ULONG			  n_init_ch_cfg_viu_cfg_drop_drop_mask = 1;

	ULONG			  n_init_ch_cfg_viu_cfg_drop_drop_mask_len = 1;

	//BYTE *            pFileBuffer = FH8735_SD;
	ULONG             nFileSize = 0;
	
	BYTE *            pFileBuffer = NULL;
	const struct firmware *fw;
	int ret;

	ret = request_firmware(&fw, pwszFileName, &(pDevice->FF0CEC78D40C5466a849834697C6AE8A8[ 0 ]->dev));

	if(ret)
	{
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"[%d]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"[%d]F7067684D2E34E8E8D3A9D12F6FEFF62() Upload FH8735.HD.HEX failed. (please copy FH8735.HD.HEX to /lib/firmware then reboot)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"[%d]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

		return false;
	}
	else
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] F7067684D2E34E8E8D3A9D12F6FEFF62() firmware read %d bytes\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, fw->size);
		
		pFileBuffer = fw->data;

		nFileSize = fw->size;

		if( nFileSize < 1)
		{
			return false;
		}
	}

	
	
	BOOL              b_is_sync_success = FALSE;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F7067684D2E34E8E8D3A9D12F6FEFF62() FH8735_SD(%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, nFileSize);

	struct timeval ts;

	wrapper_do_gettimeofday( &ts );

// DOWNLOAD_START:

	// 2.0 PARSER & DOWNLOAD FIRMWARE CONTENT -----> fh35_api_download_firmware() [2010.08.02]
	// 

//	ULONGLONG start_times = KeQueryInterruptTime();

//	struct timeval ts;

	wrapper_do_gettimeofday( &ts );

	ULONGLONG start_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);

	ULONGLONG stop_times = 0;

#ifndef FH8735_JTAG_DEBUG

	UINT * po = (UINT *)(pFileBuffer);

	ULONG i = 0;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F7067684D2E34E8E8D3A9D12F6FEFF62() begin download\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

	for( i = 0 ; i < nFileSize ; i += 4 ) { // DOWNLOADING
		
		de288df0e76e4990be34b3bea95ca349( pDevice, 3, 0x00000000 + (i), *po );  //F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%08d / %08d] [%08X]\n", i, nFileSize, *po);

		po++;
	}
	po = (UINT *)(pFileBuffer);

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F7067684D2E34E8E8D3A9D12F6FEFF62() begin test\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);
	
	for( i = 0 ; i < nFileSize ; i += 4 ) { // DOUBLE.CHECKING

		ULONG R = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 3, 0x00000000 + (i) );  //F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%08d / %08d] [%08X:%08X]\n", i, nFileSize, *po, R);

		if( R != *po ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%08d / %08d] [%08X:%08X] error\n", i, nFileSize, *po, R); goto DOWNLOAD_FAIL; }

		po++;
	}
	
	// -----> fh35_api_download_firmware()  -----> fh35_api_do_cmd() [2010.10.08]
	//
	if( aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000001, 0x00000000 ) == FALSE ) { // HCMD_DOWNLOAD_FIRMWARE

		goto DOWNLOAD_FAIL;
	}
#else 

	if( a3f0127f4f5a4c1a9eabc48e449787e4( pDevice ) == FALSE ) { // HCMD_DOWNLOAD_FIRMWARE

	//	goto DOWNLOAD_FAIL;
	}

#endif

//	stop_times = KeQueryInterruptTime();

	wrapper_do_gettimeofday( &ts );

	stop_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] TOTAL DOWNLOAD TIMES = %08d (%d BYTES)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, (ULONG)(stop_times - start_times), nFileSize);

	// -----> fh35_api_download_firmware() -> para_init() [2012.03.29]
	// 
	p_sys_cfg->para_addr = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00400020 );

	p_sys_cfg->para_len = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00400024 );

	// -----> fh35_api_download_firmware() -> chip_init() + ch_init() [2012.03.29]
	// 
	
	//RtlZeroMemory( &(p_sys_cfg->chip_cfg), sizeof(FH8735_CHIP_CFG) );
	memset( &(p_sys_cfg->chip_cfg), 0x00, sizeof(FH8735_CHIP_CFG) );

	// -----> fh35_api_set_font_lib() [2012.03.29] 
	//
	bdf43d878de74697b7ecfc1897feff4f( pDevice );

	// -----> fh35_api_set_audio_config() [2012.03.29]
	//
	if( FALSE == E1E42361E0D6470A89E96B732B9BCB0D( pDevice ) ) { goto DOWNLOAD_FAIL; }

	// -----> fh35_api_vi_*() [2012.03.29]
	//
	if( FALSE == E156F44F113047C9A305A00A4AE8D4DA( pDevice ) ) { goto DOWNLOAD_FAIL; }

	// -----> fh35_api_start_system() [2012.03.29]
	//
	if( FALSE == aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000017, 0x00000000 ) ) { goto DOWNLOAD_FAIL; } // HCMD_START_SYSTEM

	if( FALSE == aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000E, 0x0000FFFF ) ) { goto DOWNLOAD_FAIL; } // HCMD_START_ALL_AVG

	// -----> fh35_api_set_prv_size() [2012.03.29]
	// 
	if( FALSE == AE31AEF7E63D495FA568A37A9C1EC5B3( pDevice ) ) { goto DOWNLOAD_FAIL; }

	// -----> fh35_api_* [2012.03.29]
	//
	D20D6BFCE0DB426E8618426CE804DB32( pDevice, TRUE );

	// 3.0 FREE WORKING BUFFER
	//
	//use array, need not free
	//FREE_MEMORY( pFileBuffer );

	release_firmware(fw);

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F7067684D2E34E8E8D3A9D12F6FEFF62() success\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

	return TRUE;

DOWNLOAD_FAIL:

	EF45D08A9BB74090B11C410FFCC75E04( pDevice );

	//use array, need not free
	//FREE_MEMORY( pFileBuffer );

	release_firmware(fw);

	return FALSE;
}

BOOL DC57BDFBE7A54730BDFAAF6C28159F72( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
	FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 |  0x00000100 ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 100000 ); // GPIO.WR (HARDWARE.RESET)

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 & ~0x00000100 ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 100000 ); // GPIO.WR (HARDWARE.RESET)

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 |  0x00000100 ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 100000 ); // GPIO.WR (HARDWARE.RESET)

	p_sys_cfg->n_input_video_resolution_cx = 0;

	p_sys_cfg->n_input_video_resolution_cy = 0;

	p_sys_cfg->n_input_video_resolution_fps = 0;

	p_sys_cfg->n_input_video_resolution_fps_m = 0;

	p_sys_cfg->n_input_video_resolution_interleaved = 0;

	p_sys_cfg->b_input_video_signal_changed = FALSE;

	p_sys_cfg->n_input_audio_sampling_frequency = 0;

	InitCAT6023(pDevice);	

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "DC57BDFBE7A54730BDFAAF6C28159F72() success" );

 	return TRUE;
}

BOOL A70CE5C6E92F4F669EDD8330C5A90447( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "A70CE5C6E92F4F669EDD8330C5A90447" );

	FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 |  0x00000100 ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 100000 ); // GPIO.WR (HARDWARE.RESET)

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 & ~0x00000100 ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 100000 ); // GPIO.WR (HARDWARE.RESET)

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 |  0x00000100 ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 100000 ); // GPIO.WR (HARDWARE.RESET)

	p_sys_cfg->n_input_video_resolution_cx = 0;

	p_sys_cfg->n_input_video_resolution_cy = 0;

	p_sys_cfg->n_input_video_resolution_fps = 0;

	p_sys_cfg->n_input_video_resolution_fps_m = 0;

	p_sys_cfg->n_input_video_resolution_interleaved = 0;

	p_sys_cfg->b_input_video_signal_changed = FALSE;

	p_sys_cfg->n_input_audio_sampling_frequency = 0;

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "A70CE5C6E92F4F669EDD8330C5A90447() success\n" );

	return TRUE;
}
/*
BOOL FH8735_TW9910_HwInitialize( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) 
{
	if( pDevice->iManufacturer == 0x87 ) {

		if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||  // COMPOSITE

			pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) { // SVIDEO
			
			FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

			ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 );
		
			de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, (R00700000 & ~0x00000100) ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 500000 ); // GPIO.WR (HARDWARE.RESET)

			de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, (R00700000 |  0x00000080) & ~0x00000100 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 100000 ); // GPIO.WR (HARDWARE.RESET)

			de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, (R00700000 & ~0x00000080) |  0x00000100 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 100000 ); // GPIO.WR (HARDWARE.RESET)

			de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 |  0x00000080 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 100000 ); // GPIO.WR (HARDWARE.RESET)

			FH8735_SetTW9910Register( pDevice, 0x06, 0x00 );
			FH8735_SetTW9910Register( pDevice, 0x03, 0xA2 );
			FH8735_SetTW9910Register( pDevice, 0x05, 0x01 );
			FH8735_SetTW9910Register( pDevice, 0x08, 0x14 );
			FH8735_SetTW9910Register( pDevice, 0x09, 0xF2 );
			FH8735_SetTW9910Register( pDevice, 0x0A, 0x0B );
			FH8735_SetTW9910Register( pDevice, 0x0B, 0xD2 );
			FH8735_SetTW9910Register( pDevice, 0x19, 0x57 );
			FH8735_SetTW9910Register( pDevice, 0x1A, 0x0F );
			FH8735_SetTW9910Register( pDevice, 0x1B, 0x00 );
			FH8735_SetTW9910Register( pDevice, 0x28, 0x0E );
			FH8735_SetTW9910Register( pDevice, 0x29, 0x03 );
			FH8735_SetTW9910Register( pDevice, 0x2D, 0x07 );
			FH8735_SetTW9910Register( pDevice, 0x2F, 0x06 );
			FH8735_SetTW9910Register( pDevice, 0x4C, 0x0D );
			FH8735_SetTW9910Register( pDevice, 0x55, 0x00 );
			FH8735_SetTW9910Register( pDevice, 0x6B, 0x26 );
			FH8735_SetTW9910Register( pDevice, 0x6C, 0x36 );
			FH8735_SetTW9910Register( pDevice, 0x6D, 0xF0 );
			FH8735_SetTW9910Register( pDevice, 0x6E, 0x28 );
			FH8735_SetTW9910Register( pDevice, 0x06, 0x80 );

			p_sys_cfg->n_input_video_resolution_cx = 0;

			p_sys_cfg->n_input_video_resolution_cy = 0;

			p_sys_cfg->n_input_video_resolution_fps = 0;

			p_sys_cfg->n_input_video_resolution_fps_m = 0;

			p_sys_cfg->n_input_video_resolution_interleaved = 0;

			p_sys_cfg->b_input_video_signal_changed = FALSE;

			p_sys_cfg->n_input_audio_sampling_frequency = 0;
		}
	}
	return TRUE;
}
*/
VOID CB8D834EAADB4F738906FA2A5C8A8A98( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i, ULONG * pStandard )
{
	if( (pDevice->iProduct & 0x0F) == 0x03 ) {

		//FH8735_CLOSE_THREAD();
		AD96690602C7413AAC57A6B84A1747FE( pDevice );


		BYTE R0E = (BYTE)(d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50, (BYTE)(0x0E + 0x10 * i) ) & 0xF0);

		ULONG standard = 0x00000000;

		if( R0E & 0x80 ) {

			standard = pDevice->FD314ADAD9404496b842EBFC396E875CB;
		}
		else {

			if( R0E == 0x00 ) { standard = V4L2_STD_NTSC_M; } else

			if( R0E == 0x10 ) { standard = V4L2_STD_PAL_B; } else

		//	if( R0E == 0x20 ) { standard = V4L2_STD_SECAM_B; } else

			if( R0E == 0x30 ) { standard = V4L2_STD_NTSC_443; } else

			if( R0E == 0x40 ) { standard = V4L2_STD_PAL_M; } else

			if( R0E == 0x50 ) { standard = V4L2_STD_PAL_Nc; } else

			if( R0E == 0x60 ) { standard = V4L2_STD_PAL_60; } else

							  { standard = pDevice->FD314ADAD9404496b842EBFC396E875CB; }
		}
		//FH8735_START_THREAD();
		EBE5DCE0DB554397A79605FEA343FE27( pDevice );

	   *pStandard = standard;
	}
}

VOID E00CC1590A6D4C3FB115D1D67C891FE3( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	if( pDevice->iManufacturer == 0x85 ) { 		
		
		return; 
	}

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] E00CC1590A6D4C3FB115D1D67C891FE3() nVideoInput(0x%x) nAudioInput(0x%x)", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->m_nAnalogCrossbarVideoInputProperty, pDevice->m_nAnalogCrossbarAudioInputProperty );

	//FH8735_CLOSE_THREAD();
	AD96690602C7413AAC57A6B84A1747FE( pDevice );

	if( pDevice->m_nAnalogCrossbarVideoInputProperty != -1 ) {

		if( (pDevice->iProduct & 0x0F) == (0x05) ||
		
			(pDevice->iProduct & 0x0F) == (0x07) ) {

			if( pDevice->iManufacturer == 0x8A ) {
				
				DC57BDFBE7A54730BDFAAF6C28159F72( pDevice );
			}
			else if( pDevice->iManufacturer == 0x8B ||

					 pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

				A70CE5C6E92F4F669EDD8330C5A90447( pDevice );

				ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 );

				R00700000 |=  (1 << 12); // I2S.SEL = 1

				de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );
			}
			else {

				MST3367_HwInitialize( pDevice );
			}
		}
		pDevice->m_nCustomAnalogVideoResolutionProperty = 0;

		pDevice->m_nCustomAnalogVideoFrameRateProperty = 0;

		pDevice->m_nCustomAnalogVideoInterleavedProperty = 0;

		pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 0;

		pDevice->m_nAnalogVideoDecoderStatusProperty = 0;

		pDevice->m_nAnalogCopyProtMacrovisionProperty = 0;
	}
	if( pDevice->m_nAnalogCrossbarAudioInputProperty != -1 ) {

		if( (pDevice->iProduct & 0x0F) == (0x05) ||
		
			(pDevice->iProduct & 0x0F) == (0x07) ) {

			if( pDevice->iManufacturer == 0x8A ||

				pDevice->iManufacturer == 0x8B ||
				
				pDevice->iManufacturer == 0x8C ) {

				;
			}
			else {

				ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 );

				if( pDevice->m_nAnalogCrossbarVideoInputProperty == 0 ||  // HDMI (TMDS.B)

					pDevice->m_nAnalogCrossbarVideoInputProperty == 1 ) { // DVI.DIGITAL (TMDS.A)

					if( pDevice->m_nAnalogCrossbarAudioInputProperty == 0 ) {

						R00700000 &= ~(1 << 12); // I2S.SEL = 0
					}
					if( pDevice->m_nAnalogCrossbarAudioInputProperty == 1 ) {

						R00700000 |=  (1 << 12); // I2S.SEL = 1
					}
				}
				if( pDevice->m_nAnalogCrossbarVideoInputProperty == 2 ||  // COMPONENT

					pDevice->m_nAnalogCrossbarVideoInputProperty == 3 ||  // DVI.ANALOG

					pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) { // SDI

					R00700000 |=  (1 << 12); // I2S.SEL = 1
				}
				de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );
			}
		}
	}
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] E00CC1590A6D4C3FB115D1D67C891FE3() nVideoInput(0x%x) nAudioInput(0x%x) end", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->m_nAnalogCrossbarVideoInputProperty, pDevice->m_nAnalogCrossbarAudioInputProperty );

	//FH8735_START_THREAD();
	EBE5DCE0DB554397A79605FEA343FE27( pDevice );

}
extern void MST3367_ADJUST_CSC_TABLE( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE bright, BYTE contrast, BYTE saturation, BYTE hue, BYTE sharpness );

VOID B12F437EF90146B0802BBBAD0AA3AD24( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{

	if( 0 == pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 ) return TRUE;

	//FH8735_CLOSE_THREAD();
	AD96690602C7413AAC57A6B84A1747FE( pDevice );

	if( pDevice->iManufacturer == 0x85 ) {

		ULONG j = 0;
		for( j = 0 ; j < 4 ; j++ ) {

			{ c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, (BYTE)((0x10 * j) + 0x01), ((BYTE)(FADD02C9C13B14f83989880EFACB8D8DC[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][ j ] & 0xFF) - 128) | 0x00 ); }

			{ c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, (BYTE)((0x10 * j) + 0x02), ((BYTE)(F3A66BD0F0BCB4afcAD006E378E671B9A[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][ j ]  & 0xFF) -  28) | 0x00 ); }

			{ c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, (BYTE)((0x10 * j) + 0x06), ((BYTE)(F42BAA55A84E847faA4D0C0565699845E[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][ j ]  & 0xFF) - 128) | 0x00 ); }

			{ c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, (BYTE)((0x10 * j) + 0x04), ((BYTE)(F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][ j ] & 0xFF) -   0) | 0x00 ); }

			{ c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, (BYTE)((0x10 * j) + 0x05), ((BYTE)(F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][ j ] & 0xFF) -   0) | 0x00 ); }

			{ c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, (BYTE)((0x10 * j) + 0x03), ((BYTE)(F1D56E1ED762E4b99BB2BD370DFE317D1[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][ j ] & 0xFF) >>  4) | 0x10 ); }

		}
	}
	else if( pDevice->iManufacturer == 0x8A ||
		
			 pDevice->iManufacturer == 0x8B ||
		
			 pDevice->iManufacturer == 0x8C ) {
	}
	else if( (pDevice->iProduct & 0x0F) == (0x05) ||
			
			 (pDevice->iProduct & 0x0F) == (0x07) ) {

		if( pDevice->m_nAnalogCrossbarVideoInputProperty <= 3 ) {

			MST3367_ADJUST_CSC_TABLE( pDevice, (BYTE)(FADD02C9C13B14f83989880EFACB8D8DC[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF), 
				
											   (BYTE)(F3A66BD0F0BCB4afcAD006E378E671B9A[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF), 
											   
											   (BYTE)(F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF), 
											   
											   (BYTE)(F42BAA55A84E847faA4D0C0565699845E[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ]  & 0xFF), 
												   
											  ((BYTE)(F1D56E1ED762E4b99BB2BD370DFE317D1[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE * 1 ][ 0 ] & 0xFF) >> 5) );
		}
		if( pDevice->m_nAnalogCrossbarVideoInputProperty == 5 ||
			
			pDevice->m_nAnalogCrossbarVideoInputProperty == 6 ) {

		}
	}
	else if( pDevice->iManufacturer == 0xA8 ) {

	}
	else {

		ULONG j = 0;
		for( j = 0 ; j < 4 ; j++ ) {

			{ c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, (BYTE)((0x10 * j) + 0x01), ((BYTE)(FADD02C9C13B14f83989880EFACB8D8DC[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][ j ] & 0xFF) - 128) | 0x00 ); }

			{ c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, (BYTE)((0x10 * j) + 0x02), ((BYTE)(F3A66BD0F0BCB4afcAD006E378E671B9A[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][ j ]  & 0xFF) -  28) | 0x00 ); }

			{ c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, (BYTE)((0x10 * j) + 0x06), ((BYTE)(F42BAA55A84E847faA4D0C0565699845E[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][ j ]  & 0xFF) - 128) | 0x00 ); }

			{ c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, (BYTE)((0x10 * j) + 0x04), ((BYTE)(F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][ j ] & 0xFF) -   0) | 0x00 ); }

			{ c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, (BYTE)((0x10 * j) + 0x05), ((BYTE)(F925442591E22492f9239C6028CE3DD94[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][ j ] & 0xFF) -   0) | 0x00 ); }

			{ c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50, (BYTE)((0x10 * j) + 0x03), ((BYTE)(F1D56E1ED762E4b99BB2BD370DFE317D1[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][ j ] & 0xFF) >>  4) | 0x10 ); }

			//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] brightness(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, (FADD02C9C13B14f83989880EFACB8D8DC[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][ j ] & 0xFF)  );

			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] brightness, FADD02C9C13B14f83989880EFACB8D8DC[ %d ][ %d ](0x%x) ----\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, j, FADD02C9C13B14f83989880EFACB8D8DC[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ][ j ] & 0xFF );


		}

	}
	//FH8735_START_THREAD();
	EBE5DCE0DB554397A79605FEA343FE27( pDevice );

}


// ##############################################################################################################################################################################
// 
BOOLEAN E055660A74D541D98AED7EB16E515E32( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] E055660A74D541D98AED7EB16E515E32()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0 ) {

		pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2++;

	}
	else { 
		
		pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 = 1;
	}

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 == 1 ) {

		

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 0 ] = 0;

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] = 0;

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ] = 0;

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] = 0;

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 4 ] = 0;

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 5 ] = 0;

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 6 ] = 0;

		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 7 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 3 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 4 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 5 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 6 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 7 ] = 0;
	}
	// ENABLE COPY PROTECTION
	//
	pDevice->m_nAnalogCopyProtMacrovisionEnableProperty = 0;

#ifdef FH8735_COPYPORTECT_ARCHITECTURE

	if( FD0AC55FE0C0B45a788FEC199C5758F1E[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] == 0 ) { return TRUE; }

	if( F6053D464C87D41c1B8CBE8A39FCDF2D2[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] == 0 ) { return TRUE; }

#endif

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 == 1 ) {

		//FH8735_CLOSE_THREAD();
		AD96690602C7413AAC57A6B84A1747FE( pDevice );

//		ULONGLONG start_times = KeQueryInterruptTime();
		struct timeval ts;

		wrapper_do_gettimeofday( &ts );

		ULONGLONG start_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);

		ULONGLONG stop_times = 0;

		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		ULONG tmp[ 9 ] = { p_sys_cfg->n_input_video_resolution_cx,
			
						   p_sys_cfg->n_input_video_resolution_cy,
						   
						   p_sys_cfg->n_input_video_resolution_fps,
						   
						   p_sys_cfg->n_input_video_resolution_fps_m,
						   
						   p_sys_cfg->n_input_video_resolution_interleaved,
						   
						   p_sys_cfg->n_input_video_colorspace,
						   
						   p_sys_cfg->b_input_video_signal_changed,
						   
						   p_sys_cfg->n_input_video_good_adc_phase,
						   
						   p_sys_cfg->n_input_audio_sampling_frequency };

		//RtlZeroMemory( pDevice->m_pCustomSystemConfigProperty, sizeof(FH8735_SYS_CFG_EX) );

		memset( pDevice->m_pCustomSystemConfigProperty, 0x00, sizeof(FH8735_SYS_CFG_EX) );

		p_sys_cfg->n_input_video_resolution_cx = tmp[ 0 ];

		p_sys_cfg->n_input_video_resolution_cy = tmp[ 1 ];

		p_sys_cfg->n_input_video_resolution_fps = tmp[ 2 ];

		p_sys_cfg->n_input_video_resolution_fps_m = tmp[ 3 ];

		p_sys_cfg->n_input_video_resolution_interleaved = tmp[ 4 ];

		p_sys_cfg->n_input_video_colorspace = tmp[ 5 ];

		p_sys_cfg->b_input_video_signal_changed = FALSE;

		p_sys_cfg->n_input_video_good_adc_phase = tmp[ 7 ];

		p_sys_cfg->n_input_audio_sampling_frequency = tmp[ 8 ];

		// -----> FullhanPciDevice::SetFirmWarePreviewAddress()
		//
		{	ULONG i = 0;
			for( i = 0 ; i < 16 ; i++ ) { 

				if( pDevice->iManufacturer == 0x85 )
				{
				}
				else if( (pDevice->iProduct & 0x0F) == (0x05) ||
				
						 (pDevice->iProduct & 0x0F) == (0x07)	)
				{
					if( i == 0 ) { de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 0 ] ); continue ; }

					if( i == 8 ) { de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 0 ] ); continue ; }
				}
				else
				{
					if( i == 0 ) { de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 0 ] ); continue ; }

					if( i == 2 ) { de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 1 ] ); continue ; }

					if( i == 4 ) { de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 2 ] ); continue ; }

					if( i == 6 ) { de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 3 ] ); continue ; }
				}

				de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, 0x00000000 );
			}
		}
		// -----> FullhanPciDevice::SetFirmWareEncodeAddress()
		//
		{	
			ULONG memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 4 ];

			de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400070, memory_F6F32B5439E4C42f095E08326DFA73107 );

//			de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400074, 0x00200000 ); // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
			de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400074, 0x00100000 ); // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
		}
		// -----> fh35_api_open()
		//
		EF45D08A9BB74090B11C410FFCC75E04( pDevice );

		// -----> fh35_api_i2c_init()
		//
		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x00000001 ); // I2C.CONTROL (I2C_I2CRST)

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200008, ( 60750 / 100 - 1 ) / 2 - 2 ); // I2C.CLOCK.DIV

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00300000, 0x00000001 ); // I2C.CONTROL (I2C_I2CRST)

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00300008, (400000 / 100 - 1 ) / 2 - 2 ); // I2C.CLOCK.DIV

		if( ((pDevice->iProduct & 0x0F) == (0x05) && (pDevice->iManufacturer != 0x85)) ||

			 (pDevice->iProduct & 0x0F) == (0x07) ) {

			;
		}
		else if( pDevice->iManufacturer == 0xA8 ) {
/*
			ULONG R00700008 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000008 ); R00700008 |= 0x00000010; // GPIO4 OUTPUT 

			de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000008, R00700008 );

			ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 ); R00700000 &= 0xFFFFFFEF;

			de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 2000000 ); // GPIO4 LOW

			R00700000 |= 0x00000010;

			de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 2000000 ); // GPIO4 HIGH

			TS2713_HwInitialize( pDevice );

			USHORT i = 0;
			for( i = 0 ; i < 2 ; i++ ) {

				TS2713_SetAnalogVideoDecoder3DCombFilterProperty( pDevice, i, 0 );

				TS2713_SetAnalogVideoDecoderDemistDynamicRangeCorrectionProperty( pDevice, i, ((pDevice->m_nCustomAnalogVideoDemiseTypeProperty[ i ] & 0x77FFFFFF) == 0) ? 3 : 0 );

				TS2713_SetAnalogVideoDecoder3DNoiseReductionProperty( pDevice, i, ((pDevice->m_nCustomAnalogVideoDenoiseTypeProperty[ i ] & 0x77FFFFFF) == 0) ? 3 : 0 );

				TS2713_SetAnalogVideoDecoder3DDeinterlaceProperty( pDevice, i, 3 - (pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ i ] & 0x77FFFFFF) );
			}
*/
		}
		else {

			// -----> video_InitTw2864()
			//
			BYTE j = 0;

			for( j = 0 ; j < 4 ; j++ ) {

				BYTE RFE = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50 + j * 0x02, 0xFE );

				BYTE RFF = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50 + j * 0x02, 0xFF );

				if( RFE != 0x00 ) { continue ; }

				if( RFF != 0x63 && RFF != 0x6B ) { continue ; }

				BYTE i = 0;

				for( i = 0 ; i < 4 ; i++ ) {

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0x08 + i * 0x10, 0x18 ) ) { continue ; }

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0x0A + i * 0x10, 0x07 ) ) { continue ; }
				}
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xF8, 0x64 ) ) { continue ; }
				
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xF9, 0x03 ) ) { continue ; }
				
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xFA, 0x60 ) ) { continue ; }
				
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xFB, 0x00 ) ) { continue ; }
				
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xAA, 0x00 ) ) { continue ; }
				
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0x94, 0x14 ) ) { continue ; }
				
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0x9C, 0xA0 ) ) { continue ; }
				
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0x9E, 0x62 ) ) { continue ; }
				
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xCA, 0x00 ) ) { continue ; }
				
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xCB, 0x00 ) ) { continue ; }
				
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0x89, 0x01 ) ) { continue ; }
				
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0x9F, 0x01 ) ) { continue ; }
				
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xFC, 0xFF ) ) { continue ; }
				
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0x86, 0x45 ) ) { continue ; }
				
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0x8F, 0xF0 ) ) { continue ; }
			}
			// -----> audio_InitTw2864()
			//
			for( j = 0 ; j < 4 ; j++ ) {

				static const BYTE TW2864_AUDIO_COMMON_16K[ 16 ] = { 0x88, 0x88, 0x09, 0x10, 0x32, 0x10, 0x32, 0x32, 0x32, 0x10, 0x32, 0xE1, 0x00, 0x00, 0x00, 0x80 };

				static const BYTE TW2864_AUDIO_FREQ_16K[ 6 ] = { 0x00, 0x00, 0x00, 0x07, 0x6B, 0x13 };

				static const BYTE TW2864_AUDIO_FREQ_48K_PAL[ 6 ] = { 0x15, 0x41, 0x3A, 0x00, 0xC0, 0x03 };

				static const BYTE TW2864_AUDIO_FREQ_48K_NTSC[ 6 ] = { 0x15, 0x41, 0x3A, 0xCD, 0x20, 0x03 };
		
				BYTE RFE = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50 + j * 0x02, 0xFE );

				BYTE RFF = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50 + j * 0x02, 0xFF );

				if( RFE != 0x00 ) { continue ; }

				if( RFF != 0x63 && RFF != 0x6B ) { continue ; }

				BYTE i = 0;

				for( i = 0 ; i < 16 ; i++ ) {

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xD0 + i, TW2864_AUDIO_COMMON_16K[ i ] ) ) { continue ; }
				}
				/*
				for( i = 0 ; i < 3 ; i++ ) {

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xE1 + i, TW2864_AUDIO_FREQ_16K[ i + 0 ] ) ) { continue ; }

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xF0 + i, TW2864_AUDIO_FREQ_16K[ i + 3 ] ) ) { continue ; }
				}
				*/
				if(pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50)
				{
					for( i = 0 ; i < 6 ; i++ ) {

						if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xF0 + i, TW2864_AUDIO_FREQ_48K_PAL[ i ] ) ) { continue ; }
					}
				}
				else
				{
					for( i = 0 ; i < 6 ; i++ ) {

						if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xF0 + i, TW2864_AUDIO_FREQ_48K_NTSC[ i ] ) ) { continue ; }
					}
				}
				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xE0, 0x10 ) ) { continue ; }

				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xCE, 0x40 ) ) { continue ; }

				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xF8, 0x64 ) ) { continue ; }

				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xFC, 0xFF ) ) { continue ; }

				if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0x93, 0x3E ) ) { continue ; }

				{	BYTE RDB = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50 + j * 0x02, 0xDB );

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xDB, RDB & 0xBF ) ) { continue ; } // ADC DISABLE

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xB3, 0x00 ) ) { continue ; }

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xB4, 0x00 ) ) { continue ; }

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xB5, 0x00 ) ) { continue ; }

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xB6, 0x00 ) ) { continue ; }

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xB7, 0x00 ) ) { continue ; }

					FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS(  pDevice, 1000000 );

					ULONG RBD = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50 + j * 0x02, 0xBD );

					ULONG RBE = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50 + j * 0x02, 0xBE );

					ULONG RBF = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50 + j * 0x02, 0xBF );

					ULONG RC0 = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50 + j * 0x02, 0xC0 );

					ULONG RC1 = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50 + j * 0x02, 0xC1 );
					
				//	DbgPrint( "----------------------------> 1. BD = %02X, BE = %02X, BF = %02X, C0 = %02X, C1 = %02X\n", RBD, RBE, RBF, RC0, RC1 );

					RBE |= (RBD & 0x03) << 8;

					RBF |= (RBD & 0x0C) << 6;

					RC0 |= (RBD & 0x30) << 4;

					RC1 |= (RBD & 0xC0) << 2;

				//	DbgPrint( "----------------------------> 2. 10BITS = %04X %04X %04X %04X\n", RBE, RBF, RC0, RC1 );
						
					RBE = ~RBE; RBE += 1; RBE += 8;
					
					RBF = ~RBF; RBF += 1; RBF += 8;

					RC0 = ~RC0; RC0 += 1; RC0 += 8;
					
					RC1 = ~RC1; RC1 += 1; RC1 += 8;
					
				//	DbgPrint( "----------------------------> 3. 2'S + 8 = %04X %04X %04X %04X\n", RBE, RBF, RC0, RC1 );

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xB3, (BYTE)(((RBE & 0x0300) >> 8) |

																													((RBF & 0x0300) >> 6) | 

																													((RC0 & 0x0300) >> 4) |

																													((RC1 & 0x0300) >> 2)) ) ) { continue ; }

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xB4, (BYTE)(RBE & 0xFF) ) ) { continue ; }

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xB5, (BYTE)(RBF & 0xFF) ) ) { continue ; }

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xB6, (BYTE)(RC0 & 0xFF) ) ) { continue ; }

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xB7, (BYTE)(RC1 & 0xFF) ) ) { continue ; }

					if( FALSE == c944c15a33e6405babe73920d58a1fba( pDevice, 0x00, 0x50 + j * 0x02, 0xDB, (BYTE)(RDB | 0x40) ) ) { continue ; } // ADC ENABLE
				}
			}
		}
//		stop_times = KeQueryInterruptTime();

		wrapper_do_gettimeofday( &ts );

		stop_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] TOTAL RUNNING TIMES = %08d (1)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, (ULONG)(stop_times - start_times));

		BOOL returns = FALSE;

		if( (pDevice->iProduct & 0x0F) == (0x05) || (pDevice->iProduct & 0x0F) == (0x07)) {

			returns = F7067684D2E34E8E8D3A9D12F6FEFF62( pDevice, "FH8735.HD.HEX" );
		} 
		else {

			returns = F7067684D2E34E8E8D3A9D12F6FEFF62( pDevice, "FH8735.SD.HEX" );
		}
		if( returns ) {

			pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] = 1; // DOWNLOAD SUCCESS

			pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;

			pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 0;

			if( pDevice->iManufacturer == 0x85 ) {

				if( FH8735_JTAG_HYBRID == 0 ) { 
								
					if( p_sys_cfg->n_input_video_resolution_ch_info & 0x00000100 ) {

						aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000005 ); // HCMD_START_ALL_PREVIEW_TRANS

						aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000B, 0x00000155 ); // HCMD_START_ALL_ENCODE

						aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000C, 0x00000105 ); // HCMD_START_ALL_SUBENCODE
					}
					else {

						aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000055 ); // HCMD_START_ALL_PREVIEW_TRANS

						aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000B, 0x00000055 ); // HCMD_START_ALL_ENCODE

						aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000C, 0x00000055 ); // HCMD_START_ALL_SUBENCODE
					}
				}
				if( FH8735_JTAG_HYBRID == 1 ) { 

					aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000055 ); // HCMD_START_ALL_PREVIEW_TRANS

					aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000B, 0x00000055 ); // HCMD_START_ALL_ENCODE

					aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000C, 0x00000055 ); // HCMD_START_ALL_SUBENCODE
				}
				if( FH8735_JTAG_HYBRID == 2 ) { 

					aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000100 ); // HCMD_START_ALL_PREVIEW_TRANS

					aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000007, 0x00000008 ); // HCMD_START_ENCODE

					aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000009, 0x00000008 ); // HCMD_START_SUBENCODE
				}
				aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000010, 0x00000000 ); // HCMD_START_AUDIO
			}
			else if( pDevice->iManufacturer == 0x8A ||
				
					 pDevice->iManufacturer == 0x8B ) {

				aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000100 ); // HCMD_START_ALL_PREVIEW_TRANS

				aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000007, 0x00000008 ); // HCMD_START_ENCODE

				aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000009, 0x00000008 ); // HCMD_START_SUBENCODE

				aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000010, 0x00000000 ); // HCMD_START_AUDIO
			}
			else if( (pDevice->iProduct & 0x0F) == (0x05) ||
			
					 (pDevice->iProduct & 0x0F) == (0x07) ) {

				if( pDevice->m_nAnalogCrossbarVideoInputProperty <= 3 ) {

					aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000001 ); // HCMD_START_ALL_PREVIEW_TRANS

					aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000007, 0x00000000 ); // HCMD_START_ENCODE

					aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000009, 0x00000000 ); // HCMD_START_SUBENCODE
				}
				if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

					aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000100 ); // HCMD_START_ALL_PREVIEW_TRANS

					aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000007, 0x00000008 ); // HCMD_START_ENCODE

					aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000009, 0x00000008 ); // HCMD_START_SUBENCODE
				}
				aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000010, 0x00000000 ); // HCMD_START_AUDIO
			}
			else if( pDevice->iManufacturer == 0xA8 ) {

				aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000005 ); // HCMD_START_ALL_PREVIEW_TRANS

				aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000B, 0x00000055 ); // HCMD_START_ALL_ENCODE
			
				aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000C, 0x00000055 ); // HCMD_START_ALL_SUBENCODE

				aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000010, 0x00000000 ); // HCMD_START_AUDIO
			}
			else {

				aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000055 ); // HCMD_START_ALL_PREVIEW_TRANS

				aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000B, 0x00000055 ); // HCMD_START_ALL_ENCODE
			
				aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000C, 0x00000055 ); // HCMD_START_ALL_SUBENCODE

			//	aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000007, 0x00000000 ); // HCMD_START_ENCODE

			//	aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000007, 0x00000002 );

			//	aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000007, 0x00000004 );

			//	aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000007, 0x00000006 );

			//	aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000009, 0x00000000 ); // HCMD_START_SUBENCODE
			
			//	aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000009, 0x00000002 );
			
			//	aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000009, 0x00000004 );
			
			//	aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000009, 0x00000006 );

				aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000010, 0x00000000 ); // HCMD_START_AUDIO
			}
		}
		else {

			pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] = 2;

			pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;

			pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 0;
		}
//		stop_times = KeQueryInterruptTime();

		wrapper_do_gettimeofday( &ts );

		stop_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] TOTAL RUNNING TIMES (2) = %08d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, (ULONG)(stop_times - start_times));

//		FH8735_START_THREAD();
		EBE5DCE0DB554397A79605FEA343FE27( pDevice );

		B12F437EF90146B0802BBBAD0AA3AD24( pDevice );
	}
	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 1 ) {

		if(	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] == 1 ) { // DOWNLOAD SUCCESS

			//FH8735_CLOSE_THREAD();
			AD96690602C7413AAC57A6B84A1747FE( pDevice );

			D20D6BFCE0DB426E8618426CE804DB32( pDevice, FALSE );

			//FH8735_START_THREAD();
			EBE5DCE0DB554397A79605FEA343FE27( pDevice );
		}
	}

	// ...

	// ...

	// ...
	
	pDevice->H264_main_frame_count = pDevice->audio_F2B6709824D504332834A012BCBE1945D = 0;

	return true;
}

BOOLEAN F80DB77E35D0448E838D583A1BE0B96E( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] F80DB77E35D0448E838D583A1BE0B96E()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 == 0 ) return TRUE;
	
	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 1 ) {

		pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2--;

		return TRUE;
	}
	pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 = 0;

	//FH8735_CLOSE_THREAD();
	AD96690602C7413AAC57A6B84A1747FE( pDevice );

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 0 ] = 0;

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] = 0;

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ] = 0;

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] = 0;

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 4 ] = 0;

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 5 ] = 0;

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 6 ] = 0;

	pDevice->F03D1DD650AC64c28B04687338F970D0E[ 7 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 3 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 4 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 5 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 7 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 8 ] = 0;

	FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 330000 );

//	aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000011, 0x00000000 ); // HCMD_STOP_AUDIO
//
//	aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000C, 0x00000000 ); // HCMD_START_ALL_SUBENCODE
//
//	aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000B, 0x00000000 ); // HCMD_START_ALL_ENCODE
//
//	aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000000 ); // HCMD_START_ALL_PREVIEW_TRANS
//
	// -----> fh35_api_close() [2010.07.07]
	//
	EF45D08A9BB74090B11C410FFCC75E04( pDevice );

	ULONG i = 0;
	
	for( i = 0 ; i < 16 ; i++ ) { 

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + (i * 4), 0x00000000 );
	}
	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400078, 0x00000000 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400070, 0x00000000 );

//	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400074, 0x00200000 ); // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400074, 0x00100000 ); // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE

	//FH8735_START_THREAD();
	EBE5DCE0DB554397A79605FEA343FE27( pDevice );

	// ...

	// ...

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] F80DB77E35D0448E838D583A1BE0B96E() end\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

	return FH8735_PowerDownPeripherals( pDevice );
}
BOOLEAN FH8735_PowerDownPeripherals( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	return true;
}


BOOLEAN A71303C43B8D4D109536D359889BD0EC( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "A71303C43B8D4D109536D359889BD0EC( %d )\n", sizeof(FH8735_SYS_CFG) );
/*
	int k = 0;
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "begin test ndelay 1\n" );
	for(k= 0; k < 1000; k++) wrapper_ndelay( 1 ); //30
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "end test ndelay 1\n" );
	for(k= 0; k < 1000; k++) wrapper_ndelay( 10 ); //40
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "end test ndelay 10\n" );
	for(k= 0; k < 1000; k++) wrapper_ndelay( 100 ); //130
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "end test ndelay 100\n" );
	for(k= 0; k < 1000; k++) wrapper_ndelay( 1000 );//1200ns
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "end test ndelay 1000\n" );
*/

	FH8735_SYS_CFG * p_sys_cfg = NULL ;

	if(pDevice)
	{
		pDevice->m_pCustomSystemConfigProperty = (FH8735_SYS_CFG *)wrapper_vmalloc( sizeof(FH8735_SYS_CFG) );
	}
	else
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"A71303C43B8D4D109536D359889BD0EC() no  pDevice, error\n" );
		return false;
	}

	if(pDevice->m_pCustomSystemConfigProperty)
	{
		memset( pDevice->m_pCustomSystemConfigProperty, 0, sizeof(FH8735_SYS_CFG) );
	}
	else
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"A71303C43B8D4D109536D359889BD0EC() can not allocate m_pCustomSystemConfigProperty, error\n" );
		return false;
	}

	pDevice->EA72172D8A27470AA2580EC509460D34 = 0;

	wrapper_init_waitqueue_head( &pDevice->m_wait_queue_head );

	p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x00000000 ); // I2C.CONTROL (I2C_I2CRST)

	FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 100 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x00000001 ); // I2C.CONTROL (I2C_I2CRST)

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200008, ( 60750 / 100 - 1 ) / 2 - 2 ); // I2C.CLOCK.DIV

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00300000, 0x00000001 ); // I2C.CONTROL (I2C_I2CRST)

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00300008, (400000 / 100 - 1 ) / 2 - 2 ); // I2C.CLOCK.DIV

	DWORD R00000000 = d1160c83c26f4172bd37a04937ca2f52( pDevice, 0xA0, 0x00 );

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"A71303C43B8D4D109536D359889BD0EC( %08X )\n", R00000000 );

	pDevice->bcdDevice = (USHORT)((R00000000 & 0x000000FF) << 8) |
	
											 (USHORT)((R00000000 & 0x0000FF00) >> 8);

	pDevice->iManufacturer = (BYTE)((R00000000 & 0xFF000000) >> 24);

	pDevice->iProduct = (BYTE)((R00000000 & 0x00FF0000) >> 16);

	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO,"A71303C43B8D4D109536D359889BD0EC() bcdDevice(0x%x) iManufacturer(0x%x) iProduct(0x%x)\n", pDevice->bcdDevice, pDevice->iManufacturer, pDevice->iProduct );

	// -----> fh35_api_close() [2010.07.07]
	//
	EF45D08A9BB74090B11C410FFCC75E04( pDevice );

	ULONG i = 0;

	for( i = 0 ; i < 16 ; i++ ) { 

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + (i * 4), 0x00000000 );
	}
	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400078, 0x00000000 );

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400070, 0x00000000 );

//	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400074, 0x00200000 ); // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400074, 0x00100000 ); // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
	BOOL is_main_chip = FALSE;

#ifdef FH8735_COPYPORTECT_ARCHITECTURE

	if( FD0AC55FE0C0B45a788FEC199C5758F1E[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] == 0 &&

		F6053D464C87D41c1B8CBE8A39FCDF2D2[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] == 0 ) {

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000008, 0x0000000C ); // GPIO

		//srand( (ULONG)(FH8735_KsQuerySystemTime( pDevice )) );

		//BYTE F12C7345F5F5944bd9BF6C72DBEF85387[ 4 ] = { (rand() % 0xFF), (rand() % 0xFF), (rand() % 0xFF), (rand() % 0xFF) };
		
		BYTE F12C7345F5F5944bd9BF6C72DBEF85387[ 4 ] = { 0x01, 0x02, 0x03, 0x04 };

		BYTE F2F581730428B430cBF3FD8EC8D409BC0[ 4 ] = { 0x00, 0x00, 0x00, 0x00 };

		ULONGLONG delay = 125; // 100NS

		FH8735_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x13, delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 0 ], delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 1 ], delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 2 ], delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 3 ], delay ); FH8735_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, delay ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 1000000 );

		FH8735_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA3, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 0 ] = FH8735_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 1 ] = FH8735_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 2 ] = FH8735_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 3 ] = FH8735_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); FH8735_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, delay ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 1000000 );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"CODE = %08X | KEY = %08X\n", *((DWORD *)(F12C7345F5F5944bd9BF6C72DBEF85387)), *((DWORD *)(F2F581730428B430cBF3FD8EC8D409BC0)));

		if( FH8735_KsQueryCopyProtectNumber( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387 ) == *((DWORD *)(F2F581730428B430cBF3FD8EC8D409BC0)) ) {

			FD0AC55FE0C0B45a788FEC199C5758F1E[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] = 1;

			F6053D464C87D41c1B8CBE8A39FCDF2D2[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] = 1;

			is_main_chip = TRUE;
		}
	}
	if( FD0AC55FE0C0B45a788FEC199C5758F1E[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] == 0 &&

		F6053D464C87D41c1B8CBE8A39FCDF2D2[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] == 0 ) {

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000008, 0x0000000C ); // GPIO

		//srand( (ULONG)(FH8735_KsQuerySystemTime( pDevice )) );

		//BYTE F12C7345F5F5944bd9BF6C72DBEF85387[ 4 ] = { (rand() % 0xFF), (rand() % 0xFF), (rand() % 0xFF), (rand() % 0xFF) };
		BYTE F12C7345F5F5944bd9BF6C72DBEF85387[ 4 ] = { 0x01, 0x02, 0x03, 0x04 };

		BYTE F2F581730428B430cBF3FD8EC8D409BC0[ 4 ] = { 0x00, 0x00, 0x00, 0x00 };

		ULONGLONG delay = 75; // 100NS

		FH8735_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x13, delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 0 ], delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 1 ], delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 2 ], delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 3 ], delay ); FH8735_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, delay ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 1000000 );

		FH8735_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA3, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 0 ] = FH8735_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 1 ] = FH8735_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 2 ] = FH8735_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 3 ] = FH8735_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); FH8735_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, delay ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 1000000 );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "CODE = %08X | KEY = %08X\n", *((DWORD *)(F12C7345F5F5944bd9BF6C72DBEF85387)), *((DWORD *)(F2F581730428B430cBF3FD8EC8D409BC0)) );

		if( FH8735_KsQueryCopyProtectNumber( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387 ) == *((DWORD *)(F2F581730428B430cBF3FD8EC8D409BC0)) ) {

			FD0AC55FE0C0B45a788FEC199C5758F1E[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] = 1;

			F6053D464C87D41c1B8CBE8A39FCDF2D2[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] = 1;

			is_main_chip = TRUE;
		}
	}
	if( FD0AC55FE0C0B45a788FEC199C5758F1E[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] == 0 &&

		F6053D464C87D41c1B8CBE8A39FCDF2D2[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] == 0 ) {

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000008, 0x0000000C ); // GPIO

		//srand( (ULONG)(FH8735_KsQuerySystemTime( pDevice )) );

		//BYTE F12C7345F5F5944bd9BF6C72DBEF85387[ 4 ] = { (rand() % 0xFF), (rand() % 0xFF), (rand() % 0xFF), (rand() % 0xFF) };
		BYTE F12C7345F5F5944bd9BF6C72DBEF85387[ 4 ] = { 0x01, 0x02, 0x03, 0x04 };

		BYTE F2F581730428B430cBF3FD8EC8D409BC0[ 4 ] = { 0x00, 0x00, 0x00, 0x00 };

		ULONGLONG delay = 175; // 100NS

		FH8735_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x13, delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 0 ], delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 1 ], delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 2 ], delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 3 ], delay ); FH8735_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, delay ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 1000000 );

		FH8735_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, delay ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA3, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 0 ] = FH8735_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 1 ] = FH8735_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 2 ] = FH8735_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 3 ] = FH8735_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); FH8735_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, delay ); FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS( pDevice, 1000000 );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "CODE = %08X | KEY = %08X\n", *((DWORD *)(F12C7345F5F5944bd9BF6C72DBEF85387)), *((DWORD *)(F2F581730428B430cBF3FD8EC8D409BC0)) );

		if( FH8735_KsQueryCopyProtectNumber( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387 ) == *((DWORD *)(F2F581730428B430cBF3FD8EC8D409BC0)) ) {

			FD0AC55FE0C0B45a788FEC199C5758F1E[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] = 1;

			F6053D464C87D41c1B8CBE8A39FCDF2D2[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] = 1;

			is_main_chip = TRUE;
		}
	}
#endif

	if( pDevice->iManufacturer == 0x85 ||
		
		pDevice->iManufacturer == 0xA8 ) {

#ifdef FH8735_COPYPORTECT_ARCHITECTURE

		FD0AC55FE0C0B45a788FEC199C5758F1E[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] = 1;

		F6053D464C87D41c1B8CBE8A39FCDF2D2[ 0 /*pDevice->FF362AA37F7D046bf90568AC1600626D9*/ ] = 1;
#endif
	}

	// GPIO ACCESS
	//
	if( pDevice->iManufacturer != 0x85 &&
		
		pDevice->iManufacturer != 0xA8 ) {

		ULONG R = pDevice->m_nCustomGpioDirectionProperty & 0xFFFF;
		
		R = ~R; // INPUT PIN IS ALWAYS HIGH

//		R |= pDevice->m_nCustomGpioDataProperty & 0xFFFF;

		bde2191b41de49a5bdd64acc79f9ea2c( pDevice, 0x00, 0x40, (BYTE)(R >> 0) );

		bde2191b41de49a5bdd64acc79f9ea2c( pDevice, 0x00, 0x42, (BYTE)(R >> 8) );

		FH8735_F6B9E557A4BA24ffd926B820B836289C8_100NS(  pDevice, 1250000 );
	}

	if( (pDevice->iProduct & 0x0F) == (0x05) ||	(pDevice->iProduct & 0x0F) == (0x07) )
	{
		if( pDevice->iManufacturer == 0x8A )
		{
			pDevice->m_nAnalogCrossbarVideoInputProperty = 0;
		}

		if( pDevice->iManufacturer == 0x8B )
		{
			pDevice->m_nAnalogCrossbarVideoInputProperty = 4;
		}
	}
	if( (pDevice->iManufacturer & 0xF0) == 0xA0 ) 
	{
		pDevice->m_nAnalogCrossbarVideoInputProperty = 0;
	}

	if( pDevice->iManufacturer == 0x85 ) {

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000008, 0x0000DF4D ); // GPIO

		A70CE5C6E92F4F669EDD8330C5A90447( pDevice );

		ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 );

		R00700000 |=  (1 << 12); // I2S.SEL = 1

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );
	}
	else if( (pDevice->iProduct & 0x0F) == (0x05) ||
	
				(pDevice->iProduct & 0x0F) == (0x07) ) {

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000008, 0x0000DF0C ); // GPIO

		if( pDevice->iManufacturer == 0x8A ) {

			DC57BDFBE7A54730BDFAAF6C28159F72( pDevice );
		}
		else if( pDevice->iManufacturer == 0x8B ||
				 
				 pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

			A70CE5C6E92F4F669EDD8330C5A90447( pDevice );

			ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 );

			R00700000 |=  (1 << 12); // I2S.SEL = 1

			de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 );
		}
		else {

			MST3367_HwInitialize( pDevice );
		}
	}
	else if( pDevice->iManufacturer == 0xA8 ) {
/*
		ULONG R00700008 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000008 ); R00700008 |= 0x00000010; // GPIO4 OUTPUT 

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000008, R00700008 );

		ULONG R00700000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00700000 + 0x00000000 ); R00700000 &= 0xFFFFFFEF;

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 2000000 ); // GPIO4 LOW

		R00700000 |= 0x00000010;

		de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00700000 + 0x00000000, R00700000 ); F6B9E557A4BA24ffd926B820B836289C8_100NS( 2000000 ); // GPIO4 HIGH

		TS2713_HwInitialize( pDevice );
*/
	}
	else {

	}

//peter add 

	pDevice->m_nCustomAnalogVideo720OutputProperty = 1;
	pDevice->m_bCustomOsdTextEnableProperty = 0;

	for(i = 0; i < 32; i++)
	{
		pDevice->m_nCustomEncoderVideoProfileProperty[ i ] = V4L2_MPEG_VIDEO_H264_PROFILE_MAIN;
		pDevice->m_nCustomEncoderVideoResolutionProperty[ i ] = 0;
		pDevice->m_nAnalogVideoCompressionKeyframeRateProperty[ i ] = 30; 
		pDevice->m_nCustomEncoderVideoBitRateModeProperty[ i ] = V4L2_MPEG_VIDEO_BITRATE_MODE_CBR;
		pDevice->m_nCustomEncoderVideoBitRateProperty[ i ] = 4000000; 
		pDevice->m_nAnalogVideoCompressionQualityProperty[ i ] = 5000; 
		pDevice->m_nAnalogVideoCompressionOverrideKeyframeProperty[ i ] = 0; 
		pDevice->m_nCustomEncoderVideoBframesPerKeyframeProperty[ i ] = 0;

	    pDevice->m_nCustomPreviewVideoResolutionProperty[ i ] = 0;
		pDevice->m_nCustomEncoderVideoAspectRatioProperty[ i ] = 0;
		pDevice->m_nCustomEncoderVideoAvgFrameRateProperty[ i ] = 0;
		pDevice->m_nCustomEncoderVideoSkipFrameRateProperty[ i ] = 0;

	}

	for(i = 0; i < 16; i++)
	{
		pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ i ] = 1;
		pDevice->m_nCustomAnalogVideoDenoiseTypeProperty[ i ] = 1;
		pDevice->m_nCustomAnalogVideoDemiseTypeProperty[ i ] = 1;
		pDevice->m_nCustomAnalogVideoAutoPhaseTypeProperty[ i ] = 0x80000000;
	}

	for( i = 0 ; i < 32 ; i++ ) {

		pDevice->m_nCustomOsdTextColorProperty[ i ][ 0 ] = 0;

		pDevice->m_nCustomOsdTextLineProperty[ i ] = 0;

		ULONG y = 0;

		for( y = 0 ; y < 16 ; y++ ) {

			memset( pDevice->m_pCustomOsdTextStringProperty[ i ][ y ], 0x00, 64 + 1 );

			pDevice->m_bCustomOsdTextStringRefreshProperty[ i ][ y ] = FALSE;
		}
	}

	pDevice->m_nCustom_H264_Level_Property = V4L2_MPEG_VIDEO_H264_LEVEL_4_1;
	
	pDevice->m_nCustomSoftwareWatchdogEnableProperty = 0;

/*
	//
	// 
	{	BYTE R11 = (BYTE)(pDevice->m_nCustomSoftwareWatchdogDurationProperty);
		
		FH8735_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x11, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice,  R11, 125 ); FH8735_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 ); //

		FH8735_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x12, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x5A, 125 ); FH8735_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 );

		FH8735_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x10, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x5A, 125 ); FH8735_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 );
	}
*/

//	FH8735_START_THREAD();
	EBE5DCE0DB554397A79605FEA343FE27( pDevice );

	return FH8735_PowerDownPeripherals( pDevice );
}

BOOLEAN A6BB52FABC024195927059E4CF9B9ADA( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"A6BB52FABC024195927059E4CF9B9ADA()\n");

//	FH8735_CLOSE_THREAD();
	AD96690602C7413AAC57A6B84A1747FE( pDevice );

	pDevice->EA72172D8A27470AA2580EC509460D34 = 0;

	EF45D08A9BB74090B11C410FFCC75E04( pDevice );
//below will caused reinit  device error
/*
	// -----> FullhanPciDevice::ResetFirmwareOnRemove() [2010.07.24]
	// 
	ULONG R00400000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00400000 ); // CLEAR IRU INTERRPUT

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400000, 0x00000000 );

	R00400000 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00400000 ); // CLEAR IRU INTERRPUT

	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00100028, 0x0000037F );
*/

	if(pDevice->m_pCustomSystemConfigProperty)
	{
		vfree( pDevice->m_pCustomSystemConfigProperty );
		
		pDevice->m_pCustomSystemConfigProperty = NULL;

	}
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"A6BB52FABC024195927059E4CF9B9ADA() end\n");

	return true;
}

// ##############################################################################################################################################################################
// 
typedef struct _FH8735_PACKET_PREVIEW_HEADER // pack_prv_t
{
	DWORD	nWidth;

	DWORD	nHeight;

	DWORD	nFrameNumber;

	DWORD	nCover;

	DWORD	nMDLen;

	DWORD	nPrvLen;

	DWORD	nReserved;

} FH8735_PACKET_PREVIEW_HEADER;

typedef struct _FH8735_PACKET_HEADER // pack_header_t
{
	USHORT	wBufferFlag;

	USHORT	wStartingCode;

	DWORD	nAddress;

	DWORD	nTotalLength;

	BYTE    pSubPacketHeader[ 0 ];

} FH8735_PACKET_HEADER;

typedef struct _FH8735_SUBPACKET_HEADER // sub_pack_t
{
	DWORD	nChannelNumber;

	DWORD	nType;

	DWORD   nLength;

	BYTE	pSubPacketPtsHeader[ 0 ];

} FH8735_SUBPACKET_HEADER;

typedef struct _FH8735_SUBPACKET_PTS_HEADER // sub_pack_pts_t
{
	DWORD	nPts;

	BYTE	pStreamBuffer[ 0 ];

} FH8735_SUBPACKET_PTS_HEADER;
/////////////////////////////////////////////////////////////////////////////////////////
BOOLEAN D42B60001E4E4D24824451225E3B14AF( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG status, ULONG mask, F301FA49098CE4d9eB95F22BBD388E837 * pVideos[ F03706E45925547d799BA016E4F0F6D6B ][ MAX_DEVICE_OPEN_NUM ], F170997530C6943659ECE8DEC21301F66 * pVideoBuffers[ F03706E45925547d799BA016E4F0F6D6B ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN p_FDFC345768E394d138EA574DEB55B7949s[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN F6E2E659AAB8C4494A193C313276DAA65[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ] )
{

	FH8735_SYS_CFG *  p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	ULONG status1 = status;

	ULONG status2 = mask;

	if( status1 == 0xFFFFFFFF )
	{
		if( ((pDevice->iProduct & 0x0F) == (0x05)) || ((pDevice->iProduct & 0x0F) == (0x07)) )
		{
			int k = 0;
			for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
			{
				if( pVideos[ 0 ][ k ] && pVideoBuffers[ 0 ][ k ] ) {

					p_FDFC345768E394d138EA574DEB55B7949s[ 0 ][ k ] = TRUE;

					F6E2E659AAB8C4494A193C313276DAA65[ 0 ][ k ] = FALSE;

					pVideoBuffers[ 0 ][ k ]->F6A821C5E7AA043f999FB3C51DB94DD2B.input = 0xFFFFFFFF; //
				}
			}
			return TRUE;
		}
	}

	if( status1 == 0x00000013 ||  // HCMD_REQ_DATA

		status1 == 0x00000014 ||  // HCMD_PRV_DATA

		status1 == 0x00000015 ) { // HCMD_AVG_DATA


		if( status1 == 0x00000014 ) { // HCMD_PRV_DATA

			pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 1;

			BYTE * p_j = (BYTE *)(&(pDevice->F03D1DD650AC64c28B04687338F970D0E[ 0 ]));

			ULONG i = 0;

			for( i = 0 ; i < 10 ; i += 2 ) {

				ULONG x = 0;

				if( pDevice->iManufacturer == 0x85 ) {

					x = (i >> 1);
				}
				else if( (pDevice->iProduct & 0x0F) == (0x05) ||
					
						 (pDevice->iProduct & 0x0F) == (0x07) ) {

					if( i == 2 ) { continue ; }

					if( i == 4 ) { continue ; }

					if( i == 6 ) { continue ; }

					x = (0);
				}
				else {

					if( i == 8 ) { continue ; }

					x = (i >> 1);
				}
				ULONG R00400030 = d439bfca9ec846ea956d1bf0aa3adc45( pDevice, 1, 0x00400030 + i * 4 );

//				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%d]D42B60001E4E4D24824451225E3B14AF() i(0x%x) R00400030(0x%x) pVideos[ 0 ](0x%x) pVideoBuffers[ 0 ](0x%x)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), i, R00400030, pVideos[ 0 ], pVideoBuffers[ 0 ] );

				if( R00400030 == 0x00000000 ) {

					ULONG j = p_j[ x ] % 2;

					p_j[ x ]++;

					p_j[ x ] %= 2;

					int k = 0;//device opened serial number

					for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
					{
						if( pVideos[ x ][ k ] && pVideoBuffers[ x ][ k ] ) {

							pVideoBuffers[ x ][ k ]->F6A821C5E7AA043f999FB3C51DB94DD2B.input = j;

							p_FDFC345768E394d138EA574DEB55B7949s[ x ][ k ] = TRUE;

							F6E2E659AAB8C4494A193C313276DAA65[ x ][ k ] = FALSE;
			
	//						F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%d]D42B60001E4E4D24824451225E3B14AF() complete, x(0d%d) j(0d%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), x, j );
						}
						else
						{
							//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [CH%02d] [preview] [NULL.STREAM.BUFFER]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, x );
						}

						j = p_j[ x ];

						if( pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] == 1 ) // DOWNLOAD SUCCESS
						{

							if( pDevice->iManufacturer == 0x85 ) {


							}		
							else if( ((pDevice->iProduct & 0x0F) == (0x05)) || ((pDevice->iProduct & 0x0F) == (0x07)) ) {

								ULONG memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ j * 5 ];//j=0 use 0, j=1 use 5

								de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, memory_F6F32B5439E4C42f095E08326DFA73107 );

							}
							else
							{
						
								ULONG memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ x ];

								de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, memory_F6F32B5439E4C42f095E08326DFA73107 + j * 0x00097E20 );//720*576*3/2 + 32(4 + 28)
							}
					
						}
						else
						{
							if( pDevice->iManufacturer == 0x85 ) {


							}		
							else if( ((pDevice->iProduct & 0x0F) == (0x05)) || ((pDevice->iProduct & 0x0F) == (0x07)) ) {

								ULONG memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 0 ];

								de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, memory_F6F32B5439E4C42f095E08326DFA73107 );

							}
							else
							{
								ULONG memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ x ];

								de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, memory_F6F32B5439E4C42f095E08326DFA73107 );
							}
						}
					}
				}

			}//for


		}//0x14

	
		if( status1 == 0x00000013 ) { // HCMD_REQ_DATA

			int sub_encoder_base_number = 20;

			if( (pDevice->iProduct & 0x0F) == (0x03) ||	(pDevice->iManufacturer == 0x85) )
			{
				sub_encoder_base_number = 20;
			}
			else if( ((pDevice->iProduct & 0x0F) == (0x05)) || ((pDevice->iProduct & 0x0F) == (0x07)) )
			{
				sub_encoder_base_number = 17;
			}
			else
			{
				sub_encoder_base_number = 20;
			}

			pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 1;//receive H264

			ULONG j = pDevice->F03D1DD650AC64c28B04687338F970D0E[ 5 ] % 3; // NOW.FRAME

			pDevice->F03D1DD650AC64c28B04687338F970D0E[ 5 ]++;

			pDevice->F03D1DD650AC64c28B04687338F970D0E[ 5 ] %= 3;

			ULONG memory_buffer_size = status2;

			#define STREAM_BUFFER_SIZE_CHECKING( max_buf_size ) {		\
																					\
				if( n_stream_buffer_length > ((max_buf_size / 2) - (4)) ) {			\
																					\
					n_stream_buffer_length = ((max_buf_size / 2) - (4));			\
				}																	\
			}

			// -----> fh_save_stream() [2010.07.07]
			//
			if( memory_buffer_size >= sizeof(FH8735_PACKET_HEADER) && 
				
//				memory_buffer_size <= 0x00200000 ) { // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
				memory_buffer_size <= 0x00100000 ) { // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE

				BYTE * p_memory_buffer = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 4 ];
				
//				p_memory_buffer += 0x00200000 * j; // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
				p_memory_buffer += 0x00100000 * j; // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE

				if( p_memory_buffer == NULL ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "D42B60001E4E4D24824451225E3B14AF() no src buffer\n" ); return true; }

				FH8735_PACKET_HEADER * p_packet_header = (FH8735_PACKET_HEADER *)(p_memory_buffer);

//				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%d]D42B60001E4E4D24824451225E3B14AF() wStartingCode(0x%x)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_packet_header->wStartingCode );
//				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%d]D42B60001E4E4D24824451225E3B14AF() nTotalLength(0d%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_packet_header->nTotalLength );

				if( p_packet_header->wStartingCode == 0x5F5F &&
					
//					p_packet_header->nTotalLength <= (0x00200000 - 4) && // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
					p_packet_header->nTotalLength <= (0x00100000 - 4) && // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
					
					p_packet_header->nTotalLength > 0 ) {

					memset( p_memory_buffer + p_packet_header->nTotalLength, 0x00, 4 ); // FOR SAFE !!!!!

					LONG   FF7E121E5F6A1461dA967001C1404EB52 = p_packet_header->nTotalLength - sizeof(FH8735_PACKET_HEADER);

					BYTE * po = p_memory_buffer + sizeof(FH8735_PACKET_HEADER);

					H264_STREAM_HEADER hdr;
										
					memset( &hdr, 0x00, sizeof(H264_STREAM_HEADER) );

					while( FF7E121E5F6A1461dA967001C1404EB52 > (sizeof(FH8735_SUBPACKET_HEADER) + sizeof(FH8735_SUBPACKET_PTS_HEADER)) ) {

						FH8735_SUBPACKET_HEADER *     p_subpacket_header = (FH8735_SUBPACKET_HEADER *)(po);

						FH8735_SUBPACKET_PTS_HEADER * p_subpacket_pts_header = (FH8735_SUBPACKET_PTS_HEADER *)&(p_subpacket_header->pSubPacketPtsHeader[ 0 ]);

//						if( p_subpacket_header->nLength >= 0x00200000 || // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
						if( p_subpacket_header->nLength >= 0x00100000 || // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
							
							p_subpacket_header->nLength <= 0 ) {

							F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [CH0X] [REQ] [BAD.SUBPACKET.HEADER %08X]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_subpacket_header->nLength );
							F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [CH0X] p_packet_header->nTotalLength(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_packet_header->nTotalLength );

							break;
						}
//						F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "CHANNEL = %d, TYPE = %08X (%d BYTES)\n", p_subpacket_header->nChannelNumber, p_subpacket_header->nType, p_subpacket_header->nLength );

						if( p_subpacket_header->nType == 0x00000000 ||  // SUB_PACKETS_P_FRAME

							p_subpacket_header->nType == 0x00000001 ||  // SUB_PACKETS_B_FRAME

							p_subpacket_header->nType == 0x00000002 ) {  // SUB_PACKETS_I_FRAME


							pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ]++; // HCMD_REQ_DATA / SOFTWARE.WATCHDOG

							pDevice->H264_main_frame_count++;

							/*
							//check frame interval
							struct timeval now_ts;
							
							wrapper_do_gettimeofday( &now_ts );

							ULONG diff = 0;
							
							if( now_ts.tv_sec == previous_ts[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ].tv_sec)
							{
								diff = now_ts.tv_usec - previous_ts[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ].tv_usec;
							}
							else
							{
								diff = (now_ts.tv_sec - previous_ts[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ].tv_sec) * 1000000  + now_ts.tv_usec - previous_ts[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ].tv_usec;
							}

							previous_ts[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ].tv_sec = now_ts.tv_sec;

							previous_ts[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ].tv_usec = now_ts.tv_usec;

							if( (diff > 80000) )
							{
								F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%d]diff(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, diff );
							}
							*/

						}

						if(	p_subpacket_header->nType == 0x00000010 ||  // SUB_PACKETS_SUB_ENC_P

							p_subpacket_header->nType == 0x00000011 ||  // SUB_PACKETS_SUB_ENC_B

							p_subpacket_header->nType == 0x00000012 ) { // SUB_PACKETS_SUB_ENC_I

							pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ]++; // HCMD_REQ_DATA / SOFTWARE.WATCHDOG
						}

						if( p_subpacket_header->nType == 0x00000000 ||  // SUB_PACKETS_P_FRAME
							
							p_subpacket_header->nType == 0x00000001 ||  // SUB_PACKETS_B_FRAME
							
							p_subpacket_header->nType == 0x00000002 ) { // SUB_PACKETS_I_FRAME

							ULONG  n_stream_buffer_length = p_subpacket_header->nLength - sizeof(FH8735_SUBPACKET_PTS_HEADER);

							BYTE * p_stream_buffer = p_subpacket_pts_header->pStreamBuffer;

							static ULONG pts = 0;

							pts = p_subpacket_pts_header->nPts;

							ULONG i = (p_subpacket_header->nChannelNumber >> 1) + 1;

							if( p_subpacket_header->nChannelNumber == 8 ) { i = 1; } //convert 0, 8 to 1, 2 to 2, 4 to 3, 6 to 4

							int k = 0;//device opened serial number

							for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
							{
								F301FA49098CE4d9eB95F22BBD388E837 * pVideo = pVideos[ 16 + i - 1 ][ k ];

								F170997530C6943659ECE8DEC21301F66 * pVideoBuffer = pVideoBuffers[ 16 + i - 1 ][ k ];
								
								if( pVideo )//make sure pVideo->F0DD7393CD1494e27A72652C7D1A97893 exists
								{
									if( pDevice->FDB274CD437614fec94859748411FE56A[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] & ( 1 << k ) ) //can not use pVideo->F0DD7393CD1494e27A72652C7D1A97893 since pVideo might be NULL
									{
										if( pVideo && pVideoBuffer ) {

											STREAM_BUFFER_SIZE_CHECKING( 2 * pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize );

											#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

											BYTE * pe = wrapper_videobuf_to_vmalloc( &pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B );

											if( pe == NULL ) { 	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "D42B60001E4E4D24824451225E3B14AF() no dest buffer\n" ); return TRUE; }

											if( pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state != VIDEOBUF_QUEUED ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "pe state error(%x)\n", pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state ); return TRUE; }
							
											if( !pVideo->m_nCustomEncoderKeyFrameArrived )
											{
												if( (p_subpacket_header->nType == 0x00000002) )
												{	
													F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] I frame arrived\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

													pVideo->m_nCustomEncoderKeyFrameArrived = 1;
												}
												else
												{
													return TRUE;
												}
											}

											if( !pVideo->m_nCustomEncoderSlice)
											{
												//p_custom_header = pe + n_stream_buffer_length; //4 is sizeof H264_STREAM_HEADER, it is for AP

												//n_stream_buffer_length is checked by STREAM_BUFFER_SIZE_CHECKING
												if(pDevice->m_nAnalogCopyProtMacrovisionProperty == 0 )
												{
													memcpy( pe, p_stream_buffer, n_stream_buffer_length );
												}

												//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [MAIN.H264] ffmpeg copy (0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, n_stream_buffer_length );
											}
											else
											{
												//p_custom_header = pe + 4 + n_stream_buffer_length; //4 is sizeof H264_STREAM_HEADER, it is for AP

												if(pDevice->m_nAnalogCopyProtMacrovisionProperty == 0 )
												{
													if( (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
													{
														memcpy( pe + 4, p_stream_buffer, n_stream_buffer_length );
													}
												}
												//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [MAIN.H264] copy (0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, n_stream_buffer_length );

												//
												//

												if(pDevice->m_nAnalogCopyProtMacrovisionProperty == 0 )
												{
													hdr.nFrameBufferSize = n_stream_buffer_length;
												}
												else
												{
													hdr.nFrameBufferSize = 0;
												}

												hdr.nFrameType = (p_subpacket_header->nType == 0x00000002) ? (0) : (1);

											//	hdr.nMotionStatus = F5DCAF3AAB0BA4f659145B0B8C7EB74F6[ i ];

											//	hdr.nLockStatus = FC9D92723A8E44565883875F77CA4E561[ i ];
									
												hdr.nReserved = 0x00;

												if( (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
												{
													memcpy( pe, &hdr, 4 );
												}
											}
											p_FDFC345768E394d138EA574DEB55B7949s[ 16 + i - 1 ][ k ] = TRUE;

											F6E2E659AAB8C4494A193C313276DAA65[ 16 + i - 1 ][ k ] = FALSE;

											if( pVideo->m_nCustomEncoderSlice)
											{
												pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.size = n_stream_buffer_length + 4;//for s_v4l2_buffer.bytesused in application
											}
											else
											{
												pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.size = n_stream_buffer_length;//for s_v4l2_buffer.bytesused in application
											}
											#endif
										}
										else if( pVideo ) {

											de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400004, p_subpacket_header->nChannelNumber );

											de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400000, 0x0000000D ); // HCMD_ENFOREC_IFRM

											//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [CH%02d] [MAIN.H264] [NULL.STREAM.BUFFER]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_subpacket_header->nChannelNumber );
										}
										else
										{
												//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [CH%02d] [MAIN.H264] [NULL.STREAM.BUFFER] and null pVideos\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_subpacket_header->nChannelNumber );
										}// end of if( pVideo && pVideoBuffer )
									}
								}
							}//end of for

							if( pDevice->m_nAnalogVideoCompressionOverrideKeyframeProperty[ 0 ] > 0 ) {

								//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] OverrideKeyframeProperty[ 0 ] (0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->m_nAnalogVideoCompressionOverrideKeyframeProperty[ 0 ] );

								pDevice->m_nAnalogVideoCompressionOverrideKeyframeProperty[ 0 ] = 0;

								de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400004, p_subpacket_header->nChannelNumber );
								
								de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400000, 0x0000000D ); // HCMD_ENFOREC_IFRM
							}

							/*
							if( p_custom_header ) {
							
								if( p_subpacket_header->nType == 0x00000002 ) { p_custom_header[ 2 ] = 0x00; }

								if( p_subpacket_header->nType == 0x00000000 ) { p_custom_header[ 2 ] = 0x40; }

								if( p_subpacket_header->nType == 0x00000001 ) { p_custom_header[ 2 ] = 0x80; }
							
							}
							*/

						}//end of 0, 1, 2
////////////////

						if( p_subpacket_header->nType == 0x00000010 ||  // SUB_PACKETS_SUB_ENC_P
							
							p_subpacket_header->nType == 0x00000011 ||  // SUB_PACKETS_SUB_ENC_B
							
							p_subpacket_header->nType == 0x00000012 ) { // SUB_PACKETS_SUB_ENC_I

							ULONG  n_stream_buffer_length = p_subpacket_header->nLength - sizeof(FH8735_SUBPACKET_PTS_HEADER);

							BYTE * p_stream_buffer = p_subpacket_pts_header->pStreamBuffer;

							ULONG i = (p_subpacket_header->nChannelNumber >> 1) + 1;
							
							if( p_subpacket_header->nChannelNumber == 8 ) { i = 1; } //convert 0, 8 to 1,   2 to 2, 4 to 3, 6 to 4

							int k = 0;
							for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
							{
								F301FA49098CE4d9eB95F22BBD388E837 * pVideo = pVideos[ sub_encoder_base_number + i - 1 ][ k ];

								F170997530C6943659ECE8DEC21301F66 * pVideoBuffer = pVideoBuffers[ sub_encoder_base_number + i - 1 ][ k ];

								if( pVideo )
								{
									if( pDevice->FDB274CD437614fec94859748411FE56A[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] & ( 1 << k ) )
									{
										if( pVideo && pVideoBuffer ) { 

											STREAM_BUFFER_SIZE_CHECKING( 2 * pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize );

											#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)
								
											BYTE * pe = wrapper_videobuf_to_vmalloc( &pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B );

											if( pe == NULL ) { 	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "D42B60001E4E4D24824451225E3B14AF() no dest buffer---\n" ); return TRUE; }

											if( pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state != VIDEOBUF_QUEUED ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "pe state error(%x)\n", pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state ); return TRUE; }

											if( !pVideo->m_nCustomSubEncoderKeyFrameArrived )
											{
												if( (p_subpacket_header->nType == 0x00000012) )
												{	
													F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] sub H264 I frame arrived\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE);

													pVideo->m_nCustomSubEncoderKeyFrameArrived = 1;
												}
												else
												{
													return TRUE;
												}
											}

											if( !pVideo->m_nCustomEncoderSlice)
											{
												//p_custom_header = pe + 4 + n_stream_buffer_length; //4 is sizeof H264_STREAM_HEADER, it is for AP
												
												if(pDevice->m_nAnalogCopyProtMacrovisionProperty == 0 )
												{
													memcpy( pe, p_stream_buffer, n_stream_buffer_length );
												}

												//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [MAIN.H264] ffmpeg copy (0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, n_stream_buffer_length );
											}
											else
											{
												if( (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
												{
													memcpy( pe + 4, p_stream_buffer, n_stream_buffer_length );
												}
													//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [SUB.H264] copy (0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, n_stream_buffer_length );

												//
												//
												{	
										
													if(pDevice->m_nAnalogCopyProtMacrovisionProperty == 0 )
													{
														hdr.nFrameBufferSize = n_stream_buffer_length;
													}
													else
													{
														hdr.nFrameBufferSize = 0;
													}


													hdr.nFrameType = (p_subpacket_header->nType == 0x00000012) ? (0) : (1);

											//		hdr.nMotionStatus = F5DCAF3AAB0BA4f659145B0B8C7EB74F6[ i ];

											//		hdr.nLockStatus = FC9D92723A8E44565883875F77CA4E561[ i ];
										
													hdr.nReserved = 0x00;

													if( (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
													{
														memcpy( pe, &hdr, 4 );
													}
												}
											}
											p_FDFC345768E394d138EA574DEB55B7949s[ sub_encoder_base_number + i - 1 ][ k ] = TRUE;

											F6E2E659AAB8C4494A193C313276DAA65[ sub_encoder_base_number + i - 1 ][ k ] = FALSE;

											if( pVideo->m_nCustomEncoderSlice)
											{
												pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.size = n_stream_buffer_length + 4;//for s_v4l2_buffer.bytesused in application
											}
											else
											{
												pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.size = n_stream_buffer_length;//for s_v4l2_buffer.bytesused in application
											}
											#endif
										}
										else if( pVideos[ sub_encoder_base_number + i - 1 ] ) {

											de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400004, p_subpacket_header->nChannelNumber + 16 );

											de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400000, 0x0000000D ); // HCMD_ENFOREC_IFRM

											//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [CH%02d] [SUB.H264] [NULL.STREAM.BUFFER]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_subpacket_header->nChannelNumber );
										}
										else
										{
											//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [CH%02d] [SUB.H264] [NULL.STREAM.BUFFER] and null pVideos\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_subpacket_header->nChannelNumber );
										}
									}
								}
							}//end of for
								
							if( pDevice->m_nAnalogVideoCompressionOverrideKeyframeProperty[ 8 ] > 0 ) {

								//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] OverrideKeyframeProperty[ 8 ] (0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->m_nAnalogVideoCompressionOverrideKeyframeProperty[ 8 ] );

								pDevice->m_nAnalogVideoCompressionOverrideKeyframeProperty[ 8 ] = 0;

								de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400004, p_subpacket_header->nChannelNumber + 16 );

								de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400000, 0x0000000D ); // HCMD_ENFOREC_IFRM
							}
							/*
							if( p_custom_header ) {

								if( p_subpacket_header->nType == 0x00000012 ) { p_custom_header[ 2 ] = 0x00; }

								if( p_subpacket_header->nType == 0x00000010 ) { p_custom_header[ 2 ] = 0x40; }

								if( p_subpacket_header->nType == 0x00000011 ) { p_custom_header[ 2 ] = 0x80; }
							}
							*/
						}//end of if 10, 11, 12

						po += (p_subpacket_header->nLength + 3) & ~3;

						FF7E121E5F6A1461dA967001C1404EB52 -= (p_subpacket_header->nLength + 3) & ~3;

					}//while

				}
				else {

					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [CH0X] [REQ] [BAD.PACKET.HEADER %08X]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_packet_header->nTotalLength );
				}

			}
			else {

				if( memory_buffer_size > 0 ) {

					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [CH0X] [REQ] [PRE.FRAMESIZE.OVERFLOW %08X]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, memory_buffer_size );
				}
			}

			j = pDevice->F03D1DD650AC64c28B04687338F970D0E[ 5 ] % 3; // NEXT.FRAME

			if( pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] == 1 ) // DOWNLOAD SUCCESS
			{
				ULONG memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 4 ];

//				memory_F6F32B5439E4C42f095E08326DFA73107 += 0x00200000 * j; // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
				memory_F6F32B5439E4C42f095E08326DFA73107 += 0x00100000 * j; // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE

				de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400070, memory_F6F32B5439E4C42f095E08326DFA73107 );

//				de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400074, 0x00200000 ); // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
				de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400074, 0x00100000 ); // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE

			}
			else
			{
				ULONG memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 4 ];

				de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400070, memory_F6F32B5439E4C42f095E08326DFA73107 );

//				de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400074, 0x00200000 ); // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
				de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400074, 0x00100000 ); // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE

			}

			//pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ]++; // HCMD_REQ_DATA / SOFTWARE.WATCHDOG

			//pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ]++; // HCMD_REQ_DATA / SOFTWARE.WATCHDOG


		}//0x13

	}
	else {

		if( status1 == 0x00000001 ) { // HCMD_DOWNLOAD_FIRMWARE

			ULONG R0040000C = readl( (UINT *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 1 ] + 0x0040000C) );

			if( R0040000C != 0x00005A5A ) {

				wrapper_down( &(pDevice->B170D6CC53FA433DB899522A0B0325FC) ); 
		
				pDevice->EA72172D8A27470AA2580EC509460D34 = 1;

				wrapper_up( &(pDevice->B170D6CC53FA433DB899522A0B0325FC) ); 

				wrapper_wake_up( &(pDevice->m_wait_queue_head) ); 
			}
			else
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] R0040000C == 0x00005A5A()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );
			}
		}
		else if( status1 == 0xFFFFFFFF ) {

			;
		}
		else if( status1 == 0x0000000D ) { // HCMD_ENFOREC_IFRM

			;
		}
		else if( status1 == 0x00000023 ) { // HCMD_RESTART_I2S

			wrapper_down( &(pDevice->B170D6CC53FA433DB899522A0B0325FC) ); 

			pDevice->EA72172D8A27470AA2580EC509460D34 = 1;

			wrapper_up( &(pDevice->B170D6CC53FA433DB899522A0B0325FC) ); 

			wrapper_wake_up( &(pDevice->m_wait_queue_head) ); 
		}
		else {

			wrapper_down( &(pDevice->B170D6CC53FA433DB899522A0B0325FC) ); 

			pDevice->EA72172D8A27470AA2580EC509460D34 = 1;

			wrapper_up( &(pDevice->B170D6CC53FA433DB899522A0B0325FC) ); 

			wrapper_wake_up( &(pDevice->m_wait_queue_head) ); 
		}
	}

	if( status1 == 0x00000014 ) { pDevice->F03D1DD650AC64c28B04687338F970D0E[ 4 ]++; } // HCMD_PRV_DATA / SOFTWARE.WATCHDOG

	if( status1 != 0xFFFFFFFF ) { 

		writel( 0x00000000, (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 1 ] + 0x0040001C) ); 

	}
	
	return true;
}

static LONGLONG xxxxx[ 4 ] = { 0, 0, 0, 0 };

static LONGLONG ooooo[ 4 ] = { 0, 0, 0, 0 };

extern BOOLEAN update_video_time_stamp( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, F170997530C6943659ECE8DEC21301F66 * pVideoBuffer );

BOOLEAN D6EC03FA3D894ADE915EEAE8351E5E6B( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, F170997530C6943659ECE8DEC21301F66 * pVideoBuffer )
{
//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%d]D6EC03FA3D894ADE915EEAE8351E5E6B() bsize(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize );

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

	BYTE * po = NULL;

	if( pVideoBuffer == NULL )	{ return TRUE; }
	if( pVideo == NULL )		{ return TRUE; }

	#ifdef LINUXV4L2_VMALLOC_MODULE

	BYTE * pe = wrapper_videobuf_to_vmalloc( &pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B );

	#else

	BYTE * pe = NULL;

	#endif

	if( pe == NULL ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%d]D6EC03FA3D894ADE915EEAE8351E5E6B() pe == NULL \n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ); return TRUE; }

	if( pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state != VIDEOBUF_QUEUED ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "pe state error(%x)\n", pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state ); return TRUE; }


	ULONG cxe = 720;

	ULONG cye = 480;

	{
		if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) { cye = 480; }

		if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) { cye = 576; }
	}

//	if(pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize != cxe * cye * 3/2) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%d]D6EC03FA3D894ADE915EEAE8351E5E6B() bsize != cxe * cye * 3/2,  \n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE ); return TRUE; }

	if( ( (pDevice->iProduct & 0x0F) == (0x05) || (pDevice->iProduct & 0x0F) == (0x07) )  && (pDevice->iManufacturer != 0x85) )
	{
		if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 2) == (0) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 0 ] + (4) + sizeof(FH8735_PACKET_PREVIEW_HEADER); }  

		if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 2) == (1) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 5 ] + (4) + sizeof(FH8735_PACKET_PREVIEW_HEADER); } 

		if( pDevice->m_nAnalogVideoDecoderStatusProperty == 0 )
		{
			//memset( pe, 0x80, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.width * pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.height * (3) / (2)  );
			
			if( (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
			{
				memset( pe, 0x00, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.width * pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.height );

				memset( pe + pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.width * pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.height, 0x80, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.width * pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.height / 2 );
			
				pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input = 0xFFFFFFFF; //
			}
			return TRUE;
		}
		if( pDevice->m_nAnalogCopyProtMacrovisionProperty == 1 )
		{
			
			if( (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
			{
				memset( pe, 0x80, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.width * pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.height );

				memset( pe + pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.width * pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.height, 0x00, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.width * pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.height / 2 );//green
			
				pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input = 0xFFFFFFFF; //
			}
			return TRUE;
		}
	}
	else
	{
		if( pDevice->iManufacturer == 0x85 )
		{
		}
		else
		{

			if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 2) == (0) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] + (4) + sizeof(FH8735_PACKET_PREVIEW_HEADER); }  

			if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 2) == (1) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ] + (4) + sizeof(FH8735_PACKET_PREVIEW_HEADER) + 0x00097E20; } 
		}
	}

	cxe = pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.width;
	cye = pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.height;

	if( pe && po && (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) ) {

		if( (cxe == 1920) ) { // 1920 × 1088 -> 1920 × 1080
			
			memcpy( pe + (0), po, (1920) * (1080) ); po += (1920) * (1088);

			memcpy( pe + (1920 * 1080), po, (960) * (540) ); po += (960) * (544);

			memcpy( pe + (1920 * 1080) + (960 * 540), po, (960) * (540) ); po += (960) * (544);
	
		}
		else if( (cxe == 1280) && (cye == 720) ) { // 1280 × 736 -> 1280 × 720
				
			memcpy( pe + (0), po, (1280) * (720) ); po += (1280) * (736);

			memcpy( pe + (1280 * 720), po, (640) * (360) ); po += (640) * (368);

			memcpy( pe + (1280 * 720) + (640 * 360), po, (640) * (360) ); po += (640) * (368);
		}
		else if( (cxe == 640) && (cye == 360) ) { // 640 × 368 -> 640 × 360
				
			memcpy( pe + (0), po, (640) * (360) ); po += (640) * (368);

			memcpy( pe + (640 * 360), po, (320) * (180) ); po += (320) * (184);

			memcpy( pe + (640 * 360) + (320 * 180), po, (320) * (180) ); po += (320) * (184);
		}
		else if(  (cxe == 1440) && (cye == 900)  ) { // 1440 × 928 -> 1440 × 900
				
			memcpy( pe + (0), po, (1440) * (900) ); po += (1440) * (928);
	
			memcpy( pe + (1440 * 900), po, (720) * (450) ); po += (720) * (464);
	
			memcpy( pe + (1440 * 900) + (720 * 450), po, (720) * (450) ); po += (720) * (464);
		}
		else if(  (cxe == 1440) && (cye == 480)  ) { // 1440 × 480
				
			memcpy( pe + (0), po, (1440) * (480) ); po += (1440) * (480);
	
			memcpy( pe + (1440 * 480), po, (720) * (240) ); po += (720) * (240);
	
			memcpy( pe + (1440 * 480) + (720 * 240), po, (720) * (240) ); po += (720) * (240);
		}
		else if( (cxe == 800) ) { // 800 × 608 -> 800 × 600
				
			memcpy( pe + (0), po, (800) * (600) ); po += (800) * (608);
	
			memcpy( pe + (800 * 600), po, (400) * (300) ); po += (400) * (304);
	
			memcpy( pe + (800 * 600) + (400 * 300), po, (400) * (300) ); po += (400) * (304);
		}
		else if( (cxe == 960) ) { // 960 × 544 -> 960 × 540
				
			memcpy( pe + (0), po, (960) * (540) ); po += (960) * (544);
	
			memcpy( pe + (960 * 540), po, (480) * (270) ); po += (480) * (272);
	
			memcpy( pe + (960 * 540) + (480 * 270), po, (480) * (270) ); po += (480) * (272);
		}
		else if( (cxe == 480) ) { // 480 × 272 -> 480 × 270
				
			memcpy( pe + (0), po, (480) * (270) ); po += (480) * (272);
	
			memcpy( pe + (480 * 270), po, (240) * (135) ); po += (240) * (136);
	
			memcpy( pe + (480 * 270) + (240 * 135), po, (240) * (135) ); po += (240) * (136);
		}
		else
		{

			memcpy( pe, po, (cxe) * (cye) * (3) / (2) );
		}
		//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] complete one buffer\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );
	}
	else
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%02d] D6EC03FA3D894ADE915EEAE8351E5E6B() pe(0x%x) po(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pe, po );
	}

#else


#endif

	pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input = 0xFFFFFFFF; //

	update_video_time_stamp( pDevice, pVideo, pVideoBuffer);

	return TRUE;
}


BOOLEAN E45C67902CED4668A47EA0F22253C74A( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, F170997530C6943659ECE8DEC21301F66 * pVideoBuffer )
{
	update_video_time_stamp( pDevice, pVideo, pVideoBuffer);

	return true;
}

BOOLEAN ADFF4A64A2784A628D9295677E4E03CF( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG status, ULONG mask, FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudios[ F03706E45925547d799BA016E4F0F6D6B ], FFE3034C8E38D40dbAF3D2CD6E461C55C * pAudioBuffers[ F03706E45925547d799BA016E4F0F6D6B ], BOOLEAN p_FDFC345768E394d138EA574DEB55B7949s[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN F6E2E659AAB8C4494A193C313276DAA65[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ] )
{
	BOOLEAN FDFC345768E394d138EA574DEB55B7949 = FALSE;

	FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio = NULL;

	int k = 0;

//	if( pAudio )
	{
		if( status == 0x00000013 )
		{
			ULONG memory_buffer_size = mask;

			// -----> fh_save_stream() [2010.07.07]
			//
			if( memory_buffer_size >= sizeof(FH8735_PACKET_HEADER) && 
				
	//			memory_buffer_size <= 0x00200000 ) { // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
				memory_buffer_size <= 0x00100000 ) { // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE

				ULONG j = (pDevice->F03D1DD650AC64c28B04687338F970D0E[ 5 ] + 2) % 3; //bak to correct value in H264 ISR

				BYTE * p_memory_buffer = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 4 ];
				
	//			p_memory_buffer += 0x00200000 * j; // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
				p_memory_buffer += 0x00100000 * j; // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE

				if( p_memory_buffer == NULL ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "ADFF4A64A2784A628D9295677E4E03CF() no src buffer\n" ); return true; }

				FH8735_PACKET_HEADER * p_packet_header = (FH8735_PACKET_HEADER *)(p_memory_buffer);

	//			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%d]D42B60001E4E4D24824451225E3B14AF() wStartingCode(0x%x)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_packet_header->wStartingCode );
	//			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"[%d]D42B60001E4E4D24824451225E3B14AF() nTotalLength(0d%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), p_packet_header->nTotalLength );

				if( p_packet_header->wStartingCode == 0x5F5F &&
					
	//				p_packet_header->nTotalLength <= (0x00200000 - 4) && // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
					p_packet_header->nTotalLength <= (0x00100000 - 4) && // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
					
					p_packet_header->nTotalLength > 0 ) {

					memset( p_memory_buffer + p_packet_header->nTotalLength, 0x00, 4 ); // FOR SAFE !!!!!

					LONG   FF7E121E5F6A1461dA967001C1404EB52 = p_packet_header->nTotalLength - sizeof(FH8735_PACKET_HEADER);

					BYTE * po = p_memory_buffer + sizeof(FH8735_PACKET_HEADER);

					H264_STREAM_HEADER hdr;
										
					memset( &hdr, 0x00, sizeof(H264_STREAM_HEADER) );

					while( FF7E121E5F6A1461dA967001C1404EB52 > (sizeof(FH8735_SUBPACKET_HEADER) + sizeof(FH8735_SUBPACKET_PTS_HEADER)) ) {

						FH8735_SUBPACKET_HEADER *     p_subpacket_header = (FH8735_SUBPACKET_HEADER *)(po);

						FH8735_SUBPACKET_PTS_HEADER * p_subpacket_pts_header = (FH8735_SUBPACKET_PTS_HEADER *)&(p_subpacket_header->pSubPacketPtsHeader[ 0 ]);

	//					if( p_subpacket_header->nLength >= 0x00200000 || // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
						if( p_subpacket_header->nLength >= 0x00100000 || // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
							
							p_subpacket_header->nLength <= 0 ) {

							F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [CH0X] [REQ] [BAD.SUBPACKET.HEADER %08X]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_subpacket_header->nLength );
							F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [CH0X] p_packet_header->nTotalLength(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_packet_header->nTotalLength );

							break;
						}
	//					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "CHANNEL = %d, TYPE = %08X (%d BYTES)\n", p_subpacket_header->nChannelNumber, p_subpacket_header->nType, p_subpacket_header->nLength );

						if( p_subpacket_header->nType == 0x00000016 ) { // SUB_PACKETS_AUDIO_PCM

							for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
							{
								USHORT * pe = NULL;

								USHORT * pe_01 = NULL;
								USHORT * pe_02 = NULL;
								USHORT * pe_03 = NULL;
								USHORT * pe_04 = NULL;

								ULONG    n_stream_buffer_length = p_subpacket_header->nLength - sizeof(FH8735_SUBPACKET_PTS_HEADER);
						
								BYTE *   p_stream_buffer = p_subpacket_pts_header->pStreamBuffer;

								USHORT * po_00 = (USHORT *)(p_stream_buffer);

								if( ((pDevice->iProduct & 0x0F) == (0x05) && (pDevice->iManufacturer != 0x85)) ||

									((pDevice->iProduct & 0x0F) == (0x07)) )
								{

									ULONG i = 0;
								
									pAudio = pAudios[ 0 ];

									if( pAudio == NULL )
									{
										goto EXIT;
									}
								
									if( pAudio->FB6E79A0780E64bb28A3308666E67881C->F13A906F1479D4245B9F207A09C70BCE6[ pAudio->F0DD7393CD1494e27A72652C7D1A97893 ] & ( 1 << k ) ) 
									{
										if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ])
										{
											if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime)
											{
												if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area)
												{
													pe = (USHORT*)pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area;				
					
													pe += pAudio->F6578ACFCB40E44819A12FD3E27A48085[ k ] * pAudio->F1461B75D9C644717A130B5C10D966CF0 /2; // pe is USHORT *

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
								
										// for 48K, one packet is 16384 bytes
										// 16384/64 = 256, for loop will do 256 times
										// 256*16 short = 4096 short = 8192 byte
										for( i = 0 ; i < n_stream_buffer_length ; i += (2 * 32) )
										{

											USHORT * pR = (USHORT *)(po_00 + 8 * 0 * 2);

											USHORT * pL = (USHORT *)(po_00 + 8 * 1 * 2);

											pL++;

											pR++;
					
											ULONG j = 0;

											//arrange 16 short
											for( j = 0 ; j < 8 ; j++ ) {

											   *pe++ = *pL++;

											   *pe++ = *pR++;

												pL++;

												pR++;

											}
											pDevice->audio_F2B6709824D504332834A012BCBE1945D += 32;


											po_00 += (2 * 16);

										}//end of for

										FDFC345768E394d138EA574DEB55B7949 = TRUE;

										p_FDFC345768E394d138EA574DEB55B7949s[ 0 ][ k ] = FDFC345768E394d138EA574DEB55B7949;
									}
								}//
								else if( pDevice->iManufacturer == 0xA4 ||
								
										 pDevice->iManufacturer == 0xA5 ||
								
										 pDevice->iManufacturer == 0xA6 ||
								
										 pDevice->iManufacturer == 0xA8 ||
								
										 pDevice->iManufacturer == 0x85 ) {

									ULONG i = 0;
									//16384 byte/256 = 64 times
									// 64 * 16 short = 1024 short = 2048 bytes
									// not test yet ??
									for( i = 0 ; i < n_stream_buffer_length ; i += (4 * 64) ) {

										{	USHORT * pL = (USHORT *)(po_00 + 8 * 1 * 2 +      0);

											USHORT * pR = (USHORT *)(po_00 + 8 * 1 * 2 + 2 * 16);

											pL++;

											pR++;

											ULONG j = 0;

											for( j = 0 ; j < 8 ; j++ ) {

												if( pAudios[ 0 ] ) {
									
													pe_01 = (USHORT*)pAudios[ 0 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area;				

													pe_01 += pAudios[ 0 ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] * pAudios[ 0 ]->F1461B75D9C644717A130B5C10D966CF0 /2; // pe is USHORT *

													//if( pCaptureAudioStreamPin01->F7C7B28D613E845b48C2F9701EFF42227 == 2 ) 

													{ *pe_01++ = *pL; *pe_01++ = *pR; }
												}
												if( pAudios[ 1 ] ) {
									
													pe_02 = (USHORT*)pAudios[ 1 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area;				

													pe_02 += pAudios[ 1 ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] * pAudios[ 1 ]->F1461B75D9C644717A130B5C10D966CF0 /2; // pe is USHORT *

													//if( pCaptureAudioStreamPin02->F7C7B28D613E845b48C2F9701EFF42227 == 2 ) 
										
													{ *pe_02++ = *pL; *pe_02++ = *pR; }
												}
												pL += 2;

												pR += 2;
											}
										}

										po_00 += (4 * 16);

										{	USHORT * pL = (USHORT *)(po_00 + 8 * 1 * 2 +      0);

											USHORT * pR = (USHORT *)(po_00 + 8 * 1 * 2 + 2 * 16);

											pL++;

											pR++;

											ULONG j = 0;

											for( j = 0 ; j < 8 ; j++ ) {

												if( pAudios[ 2 ] ) {

													pe_03 = (USHORT*)pAudios[ 2 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area;				

													pe_03 += pAudios[ 2 ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] * pAudios[ 2 ]->F1461B75D9C644717A130B5C10D966CF0 /2; // pe is USHORT *

													//if( pCaptureAudioStreamPin03->F7C7B28D613E845b48C2F9701EFF42227 == 2 ) 
										
													{ *pe_03++ = *pL; *pe_03++ = *pR; }
												}
												if( pAudios[ 3 ] ) {

													pe_04 = (USHORT*)pAudios[ 3 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area;				

													pe_04 += pAudios[ 3 ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] * pAudios[ 3 ]->F1461B75D9C644717A130B5C10D966CF0 /2; // pe is USHORT *

													//if( pCaptureAudioStreamPin04->F7C7B28D613E845b48C2F9701EFF42227 == 2 ) 
										
													{ *pe_04++ = *pL; *pe_04++ = *pR; }
												}
												pL += 2;

												pR += 2;
											}//end of for

										}

										po_00 += (4 * 16);

									}//end of for


									if( pAudios[ 0 ] ) {

										p_FDFC345768E394d138EA574DEB55B7949s[ 0 ][ k ] = TRUE;

									}

									if( pAudios[ 1 ] ) {

										p_FDFC345768E394d138EA574DEB55B7949s[ 1 ][ k ] = TRUE;

									}
									if( pAudios[ 2 ] ) {

										p_FDFC345768E394d138EA574DEB55B7949s[ 2 ][ k ] = TRUE;

									}

									if( pAudios[ 3 ] ) {

										p_FDFC345768E394d138EA574DEB55B7949s[ 3 ][ k ] = TRUE;

									}
								}//
								else
								{
									ULONG i = 0;

									if( pAudios[ 0 ] )
									{
										if( pAudios[ 0 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] )
										{
											if( pAudios[ 0 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime )
											{
												if( pAudios[ 0 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area )
												{
													pe_01 = (USHORT*)pAudios[ 0 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area;
								
													pe_01 += pAudios[ 0 ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] * pAudios[ 0 ]->F1461B75D9C644717A130B5C10D966CF0 /2;

													p_FDFC345768E394d138EA574DEB55B7949s[ 0 ][ k ] = TRUE;
												}
											}
										}
									}

									if( pAudios[ 1 ] )
									{
										if( pAudios[ 1 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] )
										{
											if( pAudios[ 1]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime )
											{
												if( pAudios[ 1 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area )
												{
													pe_02 = (USHORT*)pAudios[ 1 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area;
								
													pe_02 += pAudios[ 1 ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] * pAudios[ 1 ]->F1461B75D9C644717A130B5C10D966CF0 /2;

													p_FDFC345768E394d138EA574DEB55B7949s[ 1 ][ k ] = TRUE;
												}
											}
										}
									}
									if( pAudios[ 2 ] )
									{
										if( pAudios[ 2 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] )
										{
											if( pAudios[ 2 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime )
											{
												if( pAudios[ 2 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area )
												{
													pe_03 = (USHORT*)pAudios[ 2 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area;
								
													pe_03 += pAudios[ 2 ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] * pAudios[ 2 ]->F1461B75D9C644717A130B5C10D966CF0 /2;

													p_FDFC345768E394d138EA574DEB55B7949s[ 2 ][ k ] = TRUE;
												}
											}
										}
									}

									if( pAudios[ 3 ] )
									{
										if( pAudios[ 3 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] )
										{
											if( pAudios[ 3 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime )
											{
												if( pAudios[ 3 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area )
												{
													pe_04 = (USHORT*)pAudios[ 3 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ]->runtime->dma_area;
								
													pe_04 += pAudios[ 3 ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] * pAudios[ 3 ]->F1461B75D9C644717A130B5C10D966CF0 /2;

													p_FDFC345768E394d138EA574DEB55B7949s[ 3 ][ k ] = TRUE;
												}
											}
										}
									}

									// one packet is 8192 bytes
									// 8192/32 = 256
									//256 * 1 * 4 short = 1024 short = 2048 bytes
									//?????????
									
									for( i = 0 ; i < n_stream_buffer_length ; i += (1 * 32) ) { 
										#ifdef SC3A0_STEREO 
										if( pAudios[ 0 ] ) { if(pe_01){ *pe_01++ = po_00[  0 ]; *pe_01++ = po_00[  3 ];} } po_00++;
													
										if( pAudios[ 3 ] ) { if(pe_04){ *pe_04++ = po_00[  1 ]; *pe_04++ = po_00[  0 ];} } po_00++;
													
										if( pAudios[ 2 ] ) { if(pe_03){ *pe_03++ = po_00[  0 ]; *pe_03++ = po_00[ -1 ];} } po_00++;
													
										if( pAudios[ 1 ] ) { if(pe_02){ *pe_02++ = po_00[ -3 ]; *pe_02++ = po_00[  0 ];} } po_00++;
													
										if( pAudios[ 0 ] ) { if(pe_01){ *pe_01++ = po_00[  0 ]; *pe_01++ = po_00[  3 ];} } po_00++;
													
										if( pAudios[ 3 ] ) { if(pe_04){ *pe_04++ = po_00[  1 ]; *pe_04++ = po_00[  0 ];} } po_00++;
													
										if( pAudios[ 2 ] ) { if(pe_03){ *pe_03++ = po_00[  0 ]; *pe_03++ = po_00[ -1 ];} } po_00++;
													
										if( pAudios[ 1 ] ) { if(pe_02){ *pe_02++ = po_00[ -3 ]; *pe_02++ = po_00[  0 ];} } po_00++;
													
										if( pAudios[ 0 ] ) { if(pe_01){ *pe_01++ = po_00[  0 ]; *pe_01++ = po_00[  3 ];} } po_00++;
													
										if( pAudios[ 3 ] ) { if(pe_04){ *pe_04++ = po_00[  1 ]; *pe_04++ = po_00[  0 ];} } po_00++;
													
										if( pAudios[ 2 ] ) { if(pe_03){ *pe_03++ = po_00[  0 ]; *pe_03++ = po_00[ -1 ];} } po_00++;
													
										if( pAudios[ 1 ] ) { if(pe_02){ *pe_02++ = po_00[ -3 ]; *pe_02++ = po_00[  0 ];} } po_00++;
													
										if( pAudios[ 0 ] ) { if(pe_01){ *pe_01++ = po_00[  0 ]; *pe_01++ = po_00[  3 ];} } po_00++;
													
										if( pAudios[ 3 ] ) { if(pe_04){ *pe_04++ = po_00[  1 ]; *pe_04++ = po_00[  0 ];} } po_00++;
													
										if( pAudios[ 2 ] ) { if(pe_03){ *pe_03++ = po_00[  0 ]; *pe_03++ = po_00[ -1 ];} } po_00++;
													
										if( pAudios[ 1 ] ) { if(pe_02){ *pe_02++ = po_00[ -3 ]; *pe_02++ = po_00[  0 ];} } po_00++;
										#else
										if( pAudios[ 0 ] ) { if(pe_01){ *pe_01++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 3 ] ) { if(pe_04){ *pe_04++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 2 ] ) { if(pe_03){ *pe_03++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 1 ] ) { if(pe_02){ *pe_02++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 0 ] ) { if(pe_01){ *pe_01++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 3 ] ) { if(pe_04){ *pe_04++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 2 ] ) { if(pe_03){ *pe_03++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 1 ] ) { if(pe_02){ *pe_02++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 0 ] ) { if(pe_01){ *pe_01++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 3 ] ) { if(pe_04){ *pe_04++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 2 ] ) { if(pe_03){ *pe_03++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 1 ] ) { if(pe_02){ *pe_02++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 0 ] ) { if(pe_01){ *pe_01++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 3 ] ) { if(pe_04){ *pe_04++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 2 ] ) { if(pe_03){ *pe_03++ = po_00[ 0 ]; } } po_00++;
													
										if( pAudios[ 1 ] ) { if(pe_02){ *pe_02++ = po_00[ 0 ]; } } po_00++;
										#endif
									}//end of for																																						   
									
								}//end of else

							}//end of for
						}//end of 0x00000016

						po += (p_subpacket_header->nLength + 3) & ~3;

						FF7E121E5F6A1461dA967001C1404EB52 -= (p_subpacket_header->nLength + 3) & ~3;

					}//end of while

					
					//compare H264 main and audio
					
					// H264_main_frame_count/25 = audio_F2B6709824D504332834A012BCBE1945D/192000 (1080P50, actually P25, 48K)
					/*
					if( (pDevice->H264_main_frame_count % 25) == 0 )
					{
						F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] check AV, H264_main_frame_count(0d%d) audio_F2B6709824D504332834A012BCBE1945D(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->H264_main_frame_count, pDevice->audio_F2B6709824D504332834A012BCBE1945D );
					}

					long diff = pDevice->H264_main_frame_count * 7680 - pDevice->audio_F2B6709824D504332834A012BCBE1945D;

					if( ABS( diff ) > 192000 ) // 1 second
					{

						F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] AV not sync, H264_main_frame_count_to_audio(0d%d) audio_F2B6709824D504332834A012BCBE1945D(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pDevice->H264_main_frame_count * 7680, pDevice->audio_F2B6709824D504332834A012BCBE1945D );
						
						//reset
						//pDevice->H264_main_frame_count = pDevice->audio_F2B6709824D504332834A012BCBE1945D = 0;
					
					}
					*/

					return TRUE;

				}// end of p_packet_header
				else {

					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] [CH0X] [REQ] [BAD.PACKET.HEADER %08X]--\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, p_packet_header->nTotalLength );
				}

			}//end of memory_buffer_size


		}// end of 0x00000013
	
	}
	return FALSE;


EXIT:

	return FALSE;
}


static int DB74E20D26254BC18B987C8739234CE4( void * FD51B2B4E0CAC4359A9EFA429A9E16157 )
{

	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)FD51B2B4E0CAC4359A9EFA429A9E16157;

	struct timeval ts;

	ULONG counts = 0;

	pDevice->m_pControlThread_already_stop = FALSE;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] DB74E20D26254BC18B987C8739234CE4( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );


	while( wrapper_kthread_should_stop() == FALSE ) {

		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		if( p_sys_cfg == NULL ) {  wrapper_schedule_timeout_interruptible( wrapper_msecs_to_jiffies(100) ); continue;}

		ULONG status_backup = pDevice->m_nAnalogVideoDecoderStatusProperty;

		if( (counts % 5) == 0 ) { 

			if( (pDevice->iProduct & 0x0F) == (0x03) ||
				
				(pDevice->iManufacturer == 0x85) ) {

				ULONG lock_status = 0x00000000;

				BYTE R00 = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50, (BYTE)((0x10 * 0) + 0x00) );

				BYTE R10 = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50, (BYTE)((0x10 * 1) + 0x00) );

				BYTE R20 = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50, (BYTE)((0x10 * 2) + 0x00) );

				BYTE R30 = d9cfcb6942714b3291d4a65a75ba7691( pDevice, 0x00, 0x50, (BYTE)((0x10 * 3) + 0x00) );

				lock_status |= ((R00 & 0xC0) == 0x40) ? (0x01) : (0);

				lock_status |= ((R10 & 0xC0) == 0x40) ? (0x02) : (0);

				lock_status |= ((R20 & 0xC0) == 0x40) ? (0x04) : (0);

				lock_status |= ((R30 & 0xC0) == 0x40) ? (0x08) : (0);

				pDevice->m_nAnalogVideoDecoderStatusProperty = lock_status;

				pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 16000;


			}

			if( (pDevice->iProduct & 0x0F) == (0x05)  || 
				
				(pDevice->iProduct & 0x0F) == (0x07)) {

				if( pDevice->iManufacturer == 0x8A ) {

					CheckHDMIRX( pDevice );//6603
				}
				else if( pDevice->iManufacturer == 0x85 ||
					
						 pDevice->iManufacturer == 0x8B ||

						 pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

					// VIDEO FORAMT DETECTION
					// 
					USHORT R00006 = FH8735_GSPI_READ_WORD( pDevice, 0x0006, 10 ) & 0x3F00; R00006 >>= 8; // VD_STD

					USHORT R0001F = FH8735_GSPI_READ_WORD( pDevice, 0x001F, 10 ) & 0x3FFF; // WORDS PER ACTIVE LINE

					ULONG x = 0;

					ULONG y = 0;

					ULONG fps = 0;

					if( R00006 == 0x16 || R00006 == 0x17 ) { x =  720; y =  240; fps = 60; }

					if( R00006 == 0x19 || R00006 == 0x1B ) { x =  720; y =  240; fps = 60; }

					if( R00006 == 0x18 || R00006 == 0x1A ) { x =  720; y =  288; fps = 50; }

					if( R00006 == 0x20 || R00006 == 0x00 ) { x = 1280; y =  720; fps = 60; }

					if( R00006 == 0x24 || R00006 == 0x04 ) { x = 1280; y =  720; fps = 50; }

					if( R00006 == 0x22 || R00006 == 0x02 ) { x = 1280; y =  720; fps = 30; }

					if( R00006 == 0x26 || R00006 == 0x06 ) { x = 1280; y =  720; fps = 25; }

					if( R00006 == 0x28 || R00006 == 0x08 ) { x = 1280; y =  720; fps = 24; }

					if( R00006 == 0x2A || R00006 == 0x0A ) { x = 1920; y =  540; fps = 60; }

					if( R00006 == 0x2C || R00006 == 0x0C ) { x = 1920; y =  540; fps = 50; }

					if( R00006 == 0x2B || R00006 == 0x0B ) { x = 1920; y = 1080; fps = 30; }

					if( R00006 == 0x2D || R00006 == 0x0D ) { x = 1920; y = 1080; fps = 25; }

					if( R00006 == 0x30 || R00006 == 0x10 ) { x = 1920; y = 1080; fps = 24; }

					if( R00006 == 0x2B && R0001F == 1920 ) { x = 1920; y = 1080; fps = 60; }

					if( R00006 == 0x2D && R0001F == 1920 ) { x = 1920; y = 1080; fps = 50; }

					if( x != 0 && y != 0 ) {

						if( p_sys_cfg->n_input_video_resolution_cx != x ||

							p_sys_cfg->n_input_video_resolution_cy != y ||

							p_sys_cfg->n_input_video_resolution_fps != fps ) {

							p_sys_cfg->n_input_video_resolution_cx = x;

							p_sys_cfg->n_input_video_resolution_cy = y;

							p_sys_cfg->n_input_video_resolution_fps = fps;

							p_sys_cfg->b_input_video_signal_changed = TRUE;

							p_sys_cfg->n_input_audio_sampling_frequency = 48000;
						}
						F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT( %d x %d x %d )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, (ULONG)(x), (ULONG)(y), (ULONG)(fps)  );

						pDevice->m_nCustomAnalogVideoResolutionProperty = (p_sys_cfg->n_input_video_resolution_cx << 16) |

																		  (p_sys_cfg->n_input_video_resolution_cy <<  0);

						pDevice->m_nCustomAnalogVideoFrameRateProperty = (p_sys_cfg->n_input_video_resolution_fps);

						if( p_sys_cfg->n_input_video_resolution_cy == 240 ||

							p_sys_cfg->n_input_video_resolution_cy == 288 ||

							p_sys_cfg->n_input_video_resolution_cy == 540 ) {

							p_sys_cfg->n_input_video_resolution_interleaved = pDevice->m_nCustomAnalogVideoInterleavedProperty = 1;
						}
						else {

							pDevice->m_nCustomAnalogVideoInterleavedProperty = 0;
						}

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

						pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 48000;

						if( pDevice->iManufacturer == 0x85 ) {

							pDevice->m_nAnalogVideoDecoderStatusProperty |= 0x00000010;
						}
						else {

							pDevice->m_nAnalogVideoDecoderStatusProperty = 1;
						}
						pDevice->m_nAnalogCopyProtMacrovisionProperty = 0;
					}
					else {

						F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00006(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, R00006 );
						F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R0001F(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, R0001F );
						F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00020(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, FH8735_GSPI_READ_WORD( pDevice, 0x0020, 10 ) );
						F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00021(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, FH8735_GSPI_READ_WORD( pDevice, 0x0021, 10 ) );
						F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00022(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, FH8735_GSPI_READ_WORD( pDevice, 0x0022, 10 ) );
						F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00023(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, FH8735_GSPI_READ_WORD( pDevice, 0x0023, 10 ) );
						F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00024(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, FH8735_GSPI_READ_WORD( pDevice, 0x0024, 10 ) );
						F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00025(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, FH8735_GSPI_READ_WORD( pDevice, 0x0025, 10 ) );
						F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]GV7601_SDI_MODE_DETECT() R00026(0x%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, FH8735_GSPI_READ_WORD( pDevice, 0x0026, 10 ) );

						pDevice->m_nCustomAnalogVideoResolutionProperty = 0;

						pDevice->m_nCustomAnalogVideoFrameRateProperty = 0;

						pDevice->m_nCustomAnalogVideoInterleavedProperty = 0;

						pDevice->m_nCustomAnalogAudioSampleFrequencyProperty = 0;

						if( pDevice->iManufacturer == 0x85 ) {

							pDevice->m_nAnalogVideoDecoderStatusProperty &= 0xFFFFFFEF;
						}
						else {
						
							pDevice->m_nAnalogVideoDecoderStatusProperty = 0;
						}
						pDevice->m_nAnalogCopyProtMacrovisionProperty = 0;
					}
				}
				else {

					MST3367_VideoFormatDetection( pDevice );
				}
			}
		}// if count % 5 == 0


		if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 0 && 
			
			( pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] == 1 ||  pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] == 2 ) ) {

				D20D6BFCE0DB426E8618426CE804DB32( pDevice, FALSE );

			if( pDevice->m_nAnalogVideoDecoderStatusProperty == 0 

				)
//				&&	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] > 0 &&  // 收到第一個畫面

//				pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] > 0 ) // 收到第一個畫面
			
			{ 
				//SC3A0 will ouput black screen auto

				if( pDevice->iManufacturer == 0x85 ) {

					;
				}

				else if( (pDevice->iProduct & 0x0F) == (0x05) ||
						 (pDevice->iProduct & 0x0F) == (0x07) ) {

					pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = 0x00000000;

					pDevice->F9D066B94377B4a9aB14E37D504955651 = 0xFFFFFFFF;

					pDevice->F69679D3D75724cd281AAC93AE8DFDF35 = 0xFFFFFFFF; 

					wrapper_tasklet_hi_schedule( &(pDevice->FB12FC3D237104676BD149F25E3D08571) );

					//F966EAAB748564259849CBD3F3D6C48A7(  KERN_INFO, "[%d]throw a black screen\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

				}
			}
			if( pDevice->iManufacturer == 0x85 ) {

				if( ((pDevice->m_nAnalogVideoDecoderStatusProperty & 0x00000010) == 0x00000010) &&

					((status_backup & 0x00000010) == 0x00000000) ) {

					aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000001F, 0x00000008 ); // HCMD_VI_RESYNC

					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] [FH8735.HCMD.VI.RESYNC] [2012.03.29]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );
				}

			}
			else if( (pDevice->iProduct & 0x0F) == (0x05) ||
				
					 (pDevice->iProduct & 0x0F) == (0x07) ) {

				if( pDevice->m_nAnalogVideoDecoderStatusProperty == 1 &&
					
					status_backup == 0 ) {

					if( pDevice->m_nAnalogCrossbarVideoInputProperty <= 3 ) {

						aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000001F, 0x00000000 ); // HCMD_VI_RESYNC
					}
					if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

						aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000001F, 0x00000008 ); // HCMD_VI_RESYNC
					}
					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] [FH8735.HCMD.VI.RESYNC] [2012.03.29]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );
 
				//	{	aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000023, 0x00000000 ); // HCMD_RESTART_I2S
				//  
				//	//	AMEBDAD_PRINT( ("[FH8735.HCMD.RESTART.I2S]\n") );
				//	}
				}
			}
		}

#if 1

		if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 0 && 
			
			pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] > 0 ) { // SOFTWARE.WATCHDOG

			FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
	
			if( p_sys_cfg == NULL ) {  wrapper_schedule_timeout_interruptible( wrapper_msecs_to_jiffies(100) ); continue;}
			
			if( (counts % 30) == 0 || // 3.0 SEC
				
				(p_sys_cfg->b_input_video_signal_changed == TRUE) ) { 

				BOOL is_firmware_reset = FALSE;

				if( pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] == 1 ) { // 下載成功

					if( pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] > 0 &&  // 收到第一個畫面, preview

						pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] > 0 ) { // 收到第一個畫面, H264

						if( pDevice->iManufacturer == 0x85 ) { 

							if( pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ] == 0 || 

								pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] == 0 || 

								pDevice->F03D1DD650AC64c28B04687338F970D0E[ 4 ] == 0 ) { // 無資料

								is_firmware_reset = TRUE;
							}
						}
						else {

							if( (((pDevice->iProduct & 0x0F) == (0x05)) && (pDevice->m_nAnalogVideoDecoderStatusProperty == 1)) ||

								(((pDevice->iProduct & 0x0F) == (0x07)) && (pDevice->m_nAnalogVideoDecoderStatusProperty == 1)) ||

								(((pDevice->iProduct & 0x0F) != (0x05))) ) { // 有訊號

								if( pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ] == 0 || 

									pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] == 0 || 

									pDevice->F03D1DD650AC64c28B04687338F970D0E[ 4 ] == 0 ) { // 無資料

									is_firmware_reset = TRUE;
								}
							}
						}
					}
					else {

						// 唯一風險, 但應該不存在
					}
				}
				else if( pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] == 2 ) { // 下載失敗

					if( pDevice->m_nAnalogVideoDecoderStatusProperty > 0 ) {

						is_firmware_reset = TRUE;
	
						F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] [FH8735.HCMD.RESET.FIRMWARE] F66FD293166B14f93A084AE0E6BD0F196[ 0 ] == 2\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

					}
				}

				if(p_sys_cfg)
				{
					if( p_sys_cfg->b_input_video_signal_changed ) {

						p_sys_cfg->b_input_video_signal_changed = FALSE;

						is_firmware_reset = TRUE;
					}
				}

				if( is_firmware_reset ) {

					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] [FH8735.HCMD.RESET.FIRMWARE]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

					ULONGLONG start_times = 0;
					
					ULONGLONG stop_times = 0;

					wrapper_do_gettimeofday( &ts );

					start_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);


					// -----> FullhanPciDevice::SetFirmWarePreviewAddress()
					//
					{	ULONG i = 0;
						for( i = 0 ; i < 16 ; i++ ) { 

								if( pDevice->iManufacturer == 0x85 )
								{
								}
								else if( (pDevice->iProduct & 0x0F) == (0x05) || (pDevice->iProduct & 0x0F) == (0x07) )
								{
									if( i == 0 ) { de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 0 ] ); continue ; }

									if( i == 8 ) { de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 0 ] ); continue ; }
								}
								else
								{
									if( i == 0 ) { de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 0 ] ); continue ; }

									if( i == 2 ) { de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 1 ] ); continue ; }

									if( i == 4 ) { de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 2 ] ); continue ; }

									if( i == 6 ) { de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 3 ] ); continue ; }
								}

								de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400030 + i * 4, 0x00000000 );
							}
					}

					// -----> FullhanPciDevice::SetFirmWareEncodeAddress()
					//
					{	ULONG memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 4 ];

						de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400070, memory_F6F32B5439E4C42f095E08326DFA73107 );

						de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00400074, 0x00100000  ); // AMEBDAD_MAX_MPEG_DMA_BUFFER_SIZE
					}

					// -----> fh35_api_open()
					//
					EF45D08A9BB74090B11C410FFCC75E04( pDevice );

					// -----> fh35_api_i2c_init()
					//
					de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200000, 0x00000001 ); // I2C.CONTROL (I2C_I2CRST)

					de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200008, ( 60750 / 100 - 1 ) / 2 - 2 ); // I2C.CLOCK.DIV

				//	de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00200008, (400000 / 100 - 1 ) / 2 - 2 ); // I2C.CLOCK.DIV

					de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00300000, 0x00000001 ); // I2C.CONTROL (I2C_I2CRST)

					de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x00300008, (400000 / 100 - 1 ) / 2 - 2 ); // I2C.CLOCK.DIV

//					stop_times = KeQueryInterruptTime();
					wrapper_do_gettimeofday( &ts );

					stop_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);

					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] TOTAL RUNNING TIMES = %08d (1)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, (ULONG)(stop_times - start_times) );

					BOOL returns = FALSE;

					if( (pDevice->iProduct & 0x0F) == (0x05) ||
							
						(pDevice->iProduct & 0x0F) == (0x07) ) {

						returns = F7067684D2E34E8E8D3A9D12F6FEFF62( pDevice, "FH8735.HD.HEX" );
					} 
					else {

						returns = F7067684D2E34E8E8D3A9D12F6FEFF62( pDevice, "FH8735.SD.HEX" );
					}
					if( returns ) {

						pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] = 1;

						pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;

						pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 0;

						if( pDevice->iManufacturer == 0x85 ) {

							if( p_sys_cfg->n_input_video_resolution_ch_info & 0x00000100 ) {

								aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000005 ); // HCMD_START_ALL_PREVIEW_TRANS

								aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000B, 0x00000155 ); // HCMD_START_ALL_ENCODE
							
								aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000C, 0x00000105 ); // HCMD_START_ALL_SUBENCODE
							}
							else {

								aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000055 ); // HCMD_START_ALL_PREVIEW_TRANS

								aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000B, 0x00000055 ); // HCMD_START_ALL_ENCODE
							
								aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000C, 0x00000055 ); // HCMD_START_ALL_SUBENCODE
							}
							aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000010, 0x00000000 ); // HCMD_START_AUDIO
						}
						else if( pDevice->iManufacturer == 0x8A ||
							
								 pDevice->iManufacturer == 0x8B ) {

							aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000100 ); // HCMD_START_ALL_PREVIEW_TRANS

							aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000007, 0x00000008 ); // HCMD_START_ENCODE

							aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000009, 0x00000008 ); // HCMD_START_SUBENCODE

							aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000010, 0x00000000 ); // HCMD_START_AUDIO
						}
						else if( (pDevice->iProduct & 0x0F) == (0x05) ||
							
								 (pDevice->iProduct & 0x0F) == (0x07) ) {

							if( pDevice->m_nAnalogCrossbarVideoInputProperty <= 3 ) {

								aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000001 ); // HCMD_START_ALL_PREVIEW_TRANS

								aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000007, 0x00000000 ); // HCMD_START_ENCODE

								aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000009, 0x00000000 ); // HCMD_START_SUBENCODE
							}
							if( pDevice->m_nAnalogCrossbarVideoInputProperty == 4 ) {

								aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000100 ); // HCMD_START_ALL_PREVIEW_TRANS

								aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000007, 0x00000008 ); // HCMD_START_ENCODE

								aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000009, 0x00000008 ); // HCMD_START_SUBENCODE
							}
							aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000010, 0x00000000 ); // HCMD_START_AUDIO
						}
						else if( pDevice->iManufacturer == 0xA8 ) {

							aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000005 ); // HCMD_START_ALL_PREVIEW_TRANS

							aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000B, 0x00000055 ); // HCMD_START_ALL_ENCODE
						
							aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000C, 0x00000055 ); // HCMD_START_ALL_SUBENCODE

							aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000010, 0x00000000 ); // HCMD_START_AUDIO
						}
						else {

							aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000F, 0x00000055 ); // HCMD_START_ALL_PREVIEW_TRANS

							aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000B, 0x00000055 ); // HCMD_START_ALL_ENCODE
						  
							aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x0000000C, 0x00000055 ); // HCMD_START_ALL_SUBENCODE

							aafd0c9462784a14a89d8308fa9ca1cb( pDevice, 0x00000010, 0x00000000 ); // HCMD_START_AUDIO
						}
					}
					else {

						pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] = 2;

						pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;

						pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 0;
					}
//					stop_times = KeQueryInterruptTime();
					wrapper_do_gettimeofday( &ts );

					stop_times = (ULONGLONG)(ts.tv_sec * 1000000) + (ULONGLONG)(ts.tv_usec);

					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] TOTAL RUNNING TIMES (2) = %08d\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, (ULONG)(stop_times - start_times) );

					pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ] = 0;

					pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] = 0;

					pDevice->F03D1DD650AC64c28B04687338F970D0E[ 4 ] = 0;
				}
				else {
					//clear counter
					pDevice->F03D1DD650AC64c28B04687338F970D0E[ 2 ] = 0;

					pDevice->F03D1DD650AC64c28B04687338F970D0E[ 3 ] = 0;

					pDevice->F03D1DD650AC64c28B04687338F970D0E[ 4 ] = 0;
				}
			}
		}
#endif

		if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 0 && 
			
			pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] == 1 ) {
/*
			LARGE_INTEGER nSystemTime = { 0x00000000, 0x00000000 }; // 1601

			LARGE_INTEGER nLocalTime = { 0x00000000, 0x00000000 };

			TIME_FIELDS sSystemTime = { 0 };

			TIME_FIELDS sLocalTime = { 0 };

			KeQuerySystemTime( &nSystemTime );

			ExSystemTimeToLocalTime( &nSystemTime, &nLocalTime );

			RtlTimeToTimeFields( &nLocalTime, &sLocalTime );

			UINT times = ((sLocalTime.Year - 2008 - 4) << 26) | (sLocalTime.Month << 22) | (sLocalTime.Day << 17) | (sLocalTime.Hour << 12) | (sLocalTime.Minute << 6) | (sLocalTime.Second << 0);
*/

			//get system time
			
			#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

			struct timeval ts;
			
			struct tm tmvalue;

			wrapper_do_gettimeofday( &ts );

			time_to_tm(ts.tv_sec, -sys_tz.tz_minuteswest * 60, &tmvalue);

			//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "tm_year(%d) tm_mon(%d) tm_mday(%d) tm_hour(%d) tm_min(%d) tm_sec(%d)\n",  tmvalue.tm_year+ 1900, tmvalue.tm_mon+1, tmvalue.tm_mday, tmvalue.tm_hour, tmvalue.tm_min, tmvalue.tm_sec);

			UINT times = ((tmvalue.tm_year + 1900 - 2008 - 4) << 26) | (tmvalue.tm_mon + 1 << 22) | (tmvalue.tm_mday << 17) | (tmvalue.tm_hour << 12) | (tmvalue.tm_min << 6) | (tmvalue.tm_sec << 0);

			de288df0e76e4990be34b3bea95ca349( pDevice, 1, 0x0040002C, times );

			#endif
		}

	
		if( pDevice->m_nCustomSoftwareWatchdogEnableProperty & 0x80000000 )
		{
		//
		// 
			BYTE R11 = (BYTE)(pDevice->m_nCustomSoftwareWatchdogDurationProperty);
			
			FH8735_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x11, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice,  R11, 125 ); FH8735_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 ); //

			FH8735_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x12, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x5A, 125 ); FH8735_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 );

			FH8735_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x10, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x5A, 125 ); FH8735_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 );

			pDevice->m_nCustomSoftwareWatchdogEnableProperty &= 0x7FFFFFFF;

		}

		if( pDevice->m_nCustomSoftwareWatchdogDurationProperty & 0x80000000 ) { // MODIFY WATCHDOG DURATION

			BYTE R11 = (BYTE)(pDevice->m_nCustomSoftwareWatchdogDurationProperty);
		
			FH8735_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x11, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice,  R11, 125 ); FH8735_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 ); //

			pDevice->m_nCustomSoftwareWatchdogDurationProperty &= 0x7FFFFFFF;
		}
		if( pDevice->m_nCustomSoftwareWatchdogResetProperty & 0x00000001 ) {

			if( pDevice->m_nCustomSoftwareWatchdogResetProperty & 0x80000000 ) { // WATCHDOG

				FH8735_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x12, 125 ); FH8735_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x5A, 125 ); FH8735_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 );
			
				pDevice->m_nCustomSoftwareWatchdogResetProperty = 0x00000001;
			}
		}

		counts++;
		
		wrapper_schedule_timeout_interruptible( wrapper_msecs_to_jiffies(100) );

	}//end of while

	pDevice->m_pControlThread_already_stop = TRUE;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] DB74E20D26254BC18B987C8739234CE4( exit ) - %08X\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(pDevice->m_pControlThread) );

	return 0;	
}

static int EBE5DCE0DB554397A79605FEA343FE27( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	wrapper_down( &(pDevice->m_pControlSemaphore) ); 

	if( pDevice->m_pControlThread == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] EBE5DCE0DB554397A79605FEA343FE27( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

		pDevice->m_pControlThread = wrapper_kthread_run( DB74E20D26254BC18B987C8739234CE4, pDevice, "DB74E20D26254BC18B987C8739234CE4" );

		if( wrapper_IS_ERR( pDevice->m_pControlThread ) ) {

			int ret = wrapper_PTR_ERR( pDevice->m_pControlThread );

			pDevice->m_pControlThread = NULL;

			return ret;
		}
	}
	wrapper_up( &(pDevice->m_pControlSemaphore) );

	return 0;
}

static int AD96690602C7413AAC57A6B84A1747FE( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	int thread_stop_counter = 0;

	wrapper_down( &(pDevice->m_pControlSemaphore) ); 

	if( pDevice->m_pControlThread ) {

		if( pDevice->m_ReadyToStopControlThread == 0 )
		{
			pDevice->m_ReadyToStopControlThread = 1;

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] AD96690602C7413AAC57A6B84A1747FE( ) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );
		
			wrapper_kthread_stop( pDevice->m_pControlThread ); // GOOD NEWS!! LINUX HAD ALREADY HELPED TO FINISH THE "STOP" SYNC.

			while( pDevice->m_pControlThread_already_stop == FALSE )
			{
				wrapper_schedule_timeout_interruptible( wrapper_msecs_to_jiffies(200) );

				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] AD96690602C7413AAC57A6B84A1747FE( ) ---\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

				thread_stop_counter++;

				if(thread_stop_counter > 5)
				{
					break;
				}
			}

			pDevice->m_pControlThread = NULL;

			pDevice->m_ReadyToStopControlThread = 0;
		
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] AD96690602C7413AAC57A6B84A1747FE( ) end\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );
		}
	}
	wrapper_up( &(pDevice->m_pControlSemaphore) );

	return 0;
}



