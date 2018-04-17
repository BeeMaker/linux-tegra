#include "LINUXV4L2.h"
#include "tp2834.h"
#include "mz0380.h"

// #1 0x35, 0x36 <-> format exchange???

// half??

extern F42A18AF66EFF459eA332CA253FFF8A65 * g_pDevice[ 128 ];

VOID E805C3C2C1EE4BB5A7B9FB984AE9A893( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );     // TVI.NTSC
VOID E3E73C5B263E44A49538C0F5CC087474( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );      // TVI.PAL
VOID E2FF27BDFED74FF28B27580A274B5954( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );       // TVI.V1       .1.2.3.4.5.6
VOID EAB107EAE6114B51BD3F0FB4DA2AC69F( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );       // TVI.V2
VOID EE19446D035244E483A5E46A97E5D59F( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ); // CVI.1080P@30 .2
VOID D8DCD1F9AD064027A10452C04868A97C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ); // CVI.1080P@25 .1
VOID C08CDE54992346DBA2DE442475D38661( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );  // CVI.720P@60  .6
VOID C01CF1A557124A2DBA1A07DE30F643BB( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );  // CVI.720P@50  .5
VOID DF4D6828C6594BFAAC9003C3922B6FEA( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );  // CVI.720P@30  .4
VOID EC79937CD24E45669B4577A220279B39( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );  // CVI.720P@25  .3
VOID EC1A6FEC82B94C82B77E0C402F0AEDAD( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );   // AHD.1080P@30 .2
VOID F3239D73625F40B781275AB950E90D2A( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );   // AHD.1080P@25 .1
VOID ADF318917EFF4756BA46113402285685( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );    // AHD.720P@30
VOID A4A06B2DEF35482E9369B8A444050AE9( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );    // AHD.720P@25

VOID E5173B4FF7234042AA60D2AC7273536E( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE chs );
VOID E53B0F47531845E59FCB35008578C3ED( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE chs );

static const unsigned char TP2834_CLK_ADDR[ 4 ] = { 0xFA, 0xFA, 0xFB, 0xFB }; // { CH.01, CH.02, CH.03, CH.04 }
static const unsigned char TP2834_CLK_AND [ 4 ] = { 0xF8, 0x8F, 0xF8, 0x8F };
static const unsigned char TP2834_CLK_MODE[ 4 ] = { 0x01, 0x10, 0x01, 0x10 };

static const unsigned char TP2834_SYS_MODE[ 5 ] = { 0x01, 0x02, 0x04, 0x08, 0x0F }; // { CH.01, CH.02, CH.03, CH.04, CH.ALL }
static const unsigned char TP2834_SYS_AND [ 5 ] = { 0xFE, 0xFD, 0xFB, 0xF7, 0xF0 };

unsigned char TP2834_TBL_5M_RASTER     [ ] = { 0x13, 0x1F, 0x20, 0x34, 0x98, 0x7A, 0x00, 0x0B, 0x9A };

unsigned char TP2834_TBL_4M_RASTER     [ ] = { 0x13, 0x1F, 0x80, 0x7D, 0xF0, 0x5A, 0x00, 0x0B, 0xB8 };

unsigned char TP2834_TBL_3M_RASTER     [ ] = { 0x13, 0x6C, 0x00, 0x2C, 0x00, 0x68, 0x00, 0x09, 0xC4 };

unsigned char TP2834_TBL_1080P30_RASTER[ ] = { 0x03, 0xD3, 0x80, 0x29, 0x38, 0x47, 0x00, 0x08, 0x98 }; // .2

unsigned char TP2834_TBL_1080P25_RASTER[ ] = { 0x03, 0xD3, 0x80, 0x29, 0x38, 0x47, 0x00, 0x0A, 0x50 }; // .1

unsigned char TP2834_TBL_720P60_RASTER [ ] = { 0x13, 0x16, 0x00, 0x19, 0xD0, 0x25, 0x00, 0x06, 0x72 }; // .6

unsigned char TP2834_TBL_720P50_RASTER [ ] = { 0x13, 0x16, 0x00, 0x19, 0xD0, 0x25, 0x00, 0x07, 0xBC }; // .5

unsigned char TP2834_TBL_720P30_RASTER [ ] = { 0x13, 0x16, 0x00, 0x19, 0xD0, 0x25, 0x00, 0x0C, 0xE4 }; // .4

unsigned char TP2834_TBL_720P25_RASTER [ ] = { 0x13, 0x16, 0x00, 0x19, 0xD0, 0x25, 0x00, 0x0F, 0x78 }; // .3

unsigned char TP2834_TBL_NTSC_RASTER   [ ] = { 0x13, 0x4E, 0xBC, 0x15, 0xF0, 0x07, 0x00, 0x09, 0x38 };

unsigned char TP2834_TBL_PAL_RASTER    [ ] = { 0x13, 0x5F, 0xBC, 0x17, 0x20, 0x17, 0x00, 0x09, 0x48 };

BYTE E337333B92284BE3A3A414AA44ED9827( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex )
{
	#ifdef AME_MZ0380

		return E6FB1249C1F642A38BC0228741149CD8( pDevice, 0, 0x88, nIndex );

	#endif

	return 0x00;
}

BOOL E2AC4F78FF95428CA3FD05CF4E898465( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, BYTE nValue )
{
	#ifdef AME_MZ0380

		return DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, nIndex, nValue );

	#endif

	return TRUE;
}

BOOL E2AC4F78FF95428CA3FD05CF4E898465s( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE nIndex, BYTE * pValues, ULONG nSize )
{
	BOOL returns = TRUE;

	#ifdef AME_MZ0380

	BYTE i = 0;
	for( i = 0 ; i < nSize ; i++ ) {

		returns = DBF051EEA3B648B49859145F02FA268C( pDevice, 0, 0x88, nIndex + i, pValues[ i ] );

		if( returns == FALSE ) {

			break;
		}
	}
	#endif

	return returns;
}

VOID TP2834_SET_REG_PAGE( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE chs ) // [HUENGPEI] [2016.09.27.V60] 
{
	switch( chs ) {

	case TP2834_REG_PAGE_VIN_01:  E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x40, 0x00 ); break; // VIN.1

	case TP2834_REG_PAGE_VIN_02:  E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x40, 0x01 ); break; // VIN.2

	case TP2834_REG_PAGE_VIN_03:  E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x40, 0x02 ); break; // VIN.3

	case TP2834_REG_PAGE_VIN_04:  E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x40, 0x03 ); break; // VIN.4

	case TP2834_REG_PAGE_VIN_ALL: E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x40, 0x04 ); break; // VIN.ALL

	case TP2834_REG_PAGE_AIN:     E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x40, 0x40 ); break; // AIN

	case TP2834_REG_PAGE_DATA:    E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x40, 0x10 ); break; // DATA ( PTZ )

	default:                      E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x40, 0x04 ); break;
	}
}

VOID TP2834_MANUAL_AGC( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2F, 0x02 );

	ULONG agc = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x04 );

	agc +=  E337333B92284BE3A3A414AA44ED9827( pDevice, 0x04 );

	agc +=  E337333B92284BE3A3A414AA44ED9827( pDevice, 0x04 );

	agc +=  E337333B92284BE3A3A414AA44ED9827( pDevice, 0x04 );

	agc &=  0x03F0;

	agc >>= 1;

	if( agc > 0x01FF ) { agc = 0x01FF;  }

	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x08, (BYTE)(agc & 0xFF) );

	ULONG tmp = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x06 );

    tmp &= 0xF9;

    tmp |= (agc >> 7) & (0x02);

    tmp |= 0x04;

	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x06, (BYTE)(tmp) );
}

VOID TP2834_EGAIN( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG CGAIN_STD )
{
    unsigned int tmp;

    unsigned int retry = 30;

	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2F, 0x06 );

	ULONG cgain = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x04 );

    if( cgain < CGAIN_STD ) {

        while( retry ) {

            retry--;

			tmp =  E337333B92284BE3A3A414AA44ED9827( pDevice, 0x07 );

            tmp &= 0x3F;

			ULONG diff = (CGAIN_STD > cgain) ? (CGAIN_STD - cgain) :(cgain - CGAIN_STD);

            while( diff ) {

                if( tmp ) {
				
					tmp--;
				}
                else {
				
					break;
				}
                cgain++;
            }
			E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0x80 | tmp );

            if( 0 == tmp ) {
			
				break;
			}
			F6B9E557A4BA24ffd926B820B836289C8_100NS( 400000 );

			E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2F, 0x06 );

			cgain = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x04 );

            if( cgain > (CGAIN_STD + 1) ) {

				tmp =  E337333B92284BE3A3A414AA44ED9827( pDevice, 0x07 );

				tmp &= 0x3F;

				tmp += 0x02;

                if( tmp > 0x3F ) { 
				
					tmp = 0x3F;
				}
				E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0x80 | tmp );

                if( 0x3F == tmp ) {
				
					break;
				}
                F6B9E557A4BA24ffd926B820B836289C8_100NS( 400000 );

                cgain = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x04 );
            }
			diff = (CGAIN_STD > cgain) ? (CGAIN_STD - cgain) :(cgain - CGAIN_STD);

            if( diff < 2 ) { 
			
				break; 
			}
        }
    }
}

LONG TP2834_SET_VIDEO_MODE( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE mode, BYTE chs, BYTE std )
{
	LONG returns = 0;

	if( TP2834_STD_HDA_DEFAULT == std ) { std = TP2834_STD_HDA; }

    TP2834_SET_REG_PAGE( pDevice, chs );

	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x35, 0x05 );

    switch( mode ) {

	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    case TP2834_HALF1080P25: { // [HUENGPEI] [2016.09.27.V60] 
	
		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_HALF1080P25 )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);
	
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x35, 0x45 );
	}
    case TP2834_1080P25: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_1080P25 )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465s( pDevice, 0x15, TP2834_TBL_1080P25_RASTER, 9 );

		BYTE R02 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x02 ); R02 &= 0xF8;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x02, R02 );

		BYTE RF5 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xF5 ); RF5 &= TP2834_SYS_AND[ chs ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF5, RF5 );

        E2FF27BDFED74FF28B27580A274B5954( pDevice );

		if( TP2834_STD_HDA == std || TP2834_STD_HDA_DEFAULT == std ) {

			F3239D73625F40B781275AB950E90D2A( pDevice );
		}
		else if( TP2834_STD_HDC == std || TP2834_STD_HDC_DEFAULT == std ) {

			D8DCD1F9AD064027A10452C04868A97C( pDevice );

			if( TP2834_STD_HDC == std ) { // POSITION ADJUST
            
				E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x15, 0x13 );

				E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x16, 0x84 );
			}
		}
        E5173B4FF7234042AA60D2AC7273536E( pDevice, chs );

        break;
	}

    case TP2834_HALF1080P30: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_HALF1080P30 )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x35, 0x45 );
	}  
	case TP2834_1080P30: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_1080P30 )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465s( pDevice, 0x15, TP2834_TBL_1080P30_RASTER, 9 );

		BYTE R02 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x02 ); R02 &= 0xF8;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x02, R02 );

		BYTE RF5 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xF5 ); RF5 &= TP2834_SYS_AND[ chs ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF5, RF5 );

        E2FF27BDFED74FF28B27580A274B5954( pDevice );

		if( TP2834_STD_HDA == std || TP2834_STD_HDA_DEFAULT == std ) {

			EC1A6FEC82B94C82B77E0C402F0AEDAD( pDevice );
		}
		else if( TP2834_STD_HDC == std || TP2834_STD_HDC_DEFAULT == std ) {

			EE19446D035244E483A5E46A97E5D59F( pDevice );

			if( TP2834_STD_HDC == std ) { // POSITION ADJUST
            
				E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x15, 0x13 );

				E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x16, 0x44 );
			}
		}
        E5173B4FF7234042AA60D2AC7273536E( pDevice, chs );

        break;
	}
 	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    case TP2834_HALF720P25: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_HALF720P25 )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x35, 0x45 );
	}  
	case TP2834_720P25: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_720P25 )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465s( pDevice, 0x15, TP2834_TBL_720P25_RASTER, 9 );
			
		BYTE R02 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x02 ); R02 &= 0xF8; R02 |= 0x02;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x02, R02 );

		BYTE RF5 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xF5 ); RF5 &= TP2834_SYS_AND[ chs ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF5, RF5 );

        E2FF27BDFED74FF28B27580A274B5954( pDevice );

        E5173B4FF7234042AA60D2AC7273536E( pDevice, chs );

        break;
	}

    case TP2834_HALF720P30: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_HALF720P30 )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x35, 0x45 );
	}  
	case TP2834_720P30: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_720P30 )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465s( pDevice, 0x15, TP2834_TBL_720P30_RASTER, 9 );
			
		BYTE R02 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x02 ); R02 &= 0xF8; R02 |= 0x02;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x02, R02 );

		BYTE RF5 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xF5 ); RF5 &= TP2834_SYS_AND[ chs ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF5, RF5 );

        E2FF27BDFED74FF28B27580A274B5954( pDevice );

        E5173B4FF7234042AA60D2AC7273536E( pDevice, chs );

        break;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    case TP2834_HALF720P50: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_HALF720P50 )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x35, 0x45 );
	}  
	case TP2834_720P50: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_720P50 )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465s( pDevice, 0x15, TP2834_TBL_720P50_RASTER, 9 );

		BYTE R02 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x02 ); R02 &= 0xF8; R02 |= 0x02;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x02, R02 );

		BYTE RF5 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xF5 ); RF5 &= TP2834_SYS_AND[ chs ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF5, RF5 );

        E2FF27BDFED74FF28B27580A274B5954( pDevice );	
		
		if( TP2834_STD_HDA == std || TP2834_STD_HDA_DEFAULT == std ) {

			;
		}
		else if( TP2834_STD_HDC == std || TP2834_STD_HDC_DEFAULT == std ) {

			C01CF1A557124A2DBA1A07DE30F643BB( pDevice );

			if( TP2834_STD_HDC == std ) { // POSITION ADJUST
            
				E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x16, 0x40 );
			}
		}
        E5173B4FF7234042AA60D2AC7273536E( pDevice, chs );

        break;
	}

    case TP2834_HALF720P60: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_HALF720P60 )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x35, 0x45 );
	}  
	case TP2834_720P60: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_720P60 )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465s( pDevice, 0x15, TP2834_TBL_720P60_RASTER, 9 );

		BYTE R02 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x02 ); R02 &= 0xF8; R02 |= 0x02;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x02, R02 );

		BYTE RF5 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xF5 ); RF5 &= TP2834_SYS_AND[ chs ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF5, RF5 );

        E2FF27BDFED74FF28B27580A274B5954( pDevice );	
		
		if( TP2834_STD_HDA == std || TP2834_STD_HDA_DEFAULT == std ) {

			;
		}
		else if( TP2834_STD_HDC == std || TP2834_STD_HDC_DEFAULT == std ) {

			C08CDE54992346DBA2DE442475D38661( pDevice );

			if( TP2834_STD_HDC == std ) { // POSITION ADJUST
            
				E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x16, 0x02 );
			}
		}
        E5173B4FF7234042AA60D2AC7273536E( pDevice, chs );

        break;
	}
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    case TP2834_720P25V2: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_720P25V2 )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x35, 0x25 );

		E2AC4F78FF95428CA3FD05CF4E898465s( pDevice, 0x15, TP2834_TBL_720P50_RASTER, 9 );
		
		BYTE R02 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x02 ); R02 &= 0xF8; R02 |= 0x02;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x02, R02 );

		BYTE RF5 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xF5 ); RF5 |= TP2834_SYS_MODE[ chs ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF5, RF5 );
		
        EAB107EAE6114B51BD3F0FB4DA2AC69F( pDevice );

		if( TP2834_STD_HDA == std || TP2834_STD_HDA_DEFAULT == std ) {

			A4A06B2DEF35482E9369B8A444050AE9( pDevice );
		}
		else if( TP2834_STD_HDC == std || TP2834_STD_HDC_DEFAULT == std ) {

			EC79937CD24E45669B4577A220279B39( pDevice );

			if( TP2834_STD_HDC == std ) { // POSITION ADJUST
            
				E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x16, 0x40 );
			}
		}
        E53B0F47531845E59FCB35008578C3ED( pDevice, chs );

        break;
	}
    case TP2834_720P30V2: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_720P30V2 )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x35, 0x25 );

		E2AC4F78FF95428CA3FD05CF4E898465s( pDevice, 0x15, TP2834_TBL_720P60_RASTER, 9 );
		
		BYTE R02 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x02 ); R02 &= 0xF8; R02 |= 0x02;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x02, R02 );

		BYTE RF5 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xF5 ); RF5 |= TP2834_SYS_MODE[ chs ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF5, RF5 );

        EAB107EAE6114B51BD3F0FB4DA2AC69F( pDevice );

		if( TP2834_STD_HDA == std || TP2834_STD_HDA_DEFAULT == std ) {

			ADF318917EFF4756BA46113402285685( pDevice );
		}
		else if( TP2834_STD_HDC == std || TP2834_STD_HDC_DEFAULT == std ) {

			DF4D6828C6594BFAAC9003C3922B6FEA( pDevice );

			if( TP2834_STD_HDC == std ) { // POSITION ADJUST
            
				E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x16, 0x02 );
			}
		}
        E53B0F47531845E59FCB35008578C3ED( pDevice, chs );

        break;
	}
    case TP2834_PAL: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_PAL )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x35, 0x25 );

		E2AC4F78FF95428CA3FD05CF4E898465s( pDevice, 0x15, TP2834_TBL_PAL_RASTER, 9 );
		
		BYTE R02 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x02 ); R02 &= 0xF8; R02 |= 0x07;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x02, R02 );

		BYTE RF5 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xF5 ); RF5 |= TP2834_SYS_MODE[ chs ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF5, RF5 );

        EAB107EAE6114B51BD3F0FB4DA2AC69F( pDevice );
	   
        E53B0F47531845E59FCB35008578C3ED( pDevice, chs );

        break;
	}
    case TP2834_NTSC: { // [HUENGPEI] [2016.09.27.V60] 

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_NTSC )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x35, 0x25 );

		E2AC4F78FF95428CA3FD05CF4E898465s( pDevice, 0x15, TP2834_TBL_NTSC_RASTER, 9 );
		
		BYTE R02 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x02 ); R02 &= 0xF8; R02 |= 0x07;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x02, R02 );

		BYTE RF5 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xF5 ); RF5 |= TP2834_SYS_MODE[ chs ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF5, RF5 );
		
        EAB107EAE6114B51BD3F0FB4DA2AC69F( pDevice );
			
        E53B0F47531845E59FCB35008578C3ED( pDevice, chs );

        break;
    }
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    case TP2834_3M: { // [HUENGPEI] [2016.09.27.V60]

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_3M )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);
		
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x35, 0x16 );

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x36, 0x30 );
		
		E2AC4F78FF95428CA3FD05CF4E898465s( pDevice, 0x15, TP2834_TBL_3M_RASTER, 9 );

		BYTE R02 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x02 ); R02 &= 0xF8;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x02, R02 );

		BYTE RF5 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xF5 ); RF5 &= TP2834_SYS_AND[ chs ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF5, RF5 );

        E2FF27BDFED74FF28B27580A274B5954( pDevice );	

        E5173B4FF7234042AA60D2AC7273536E( pDevice, chs );

        break;
	}
    case TP2834_4M: { // [HUENGPEI] [2016.09.27.V60]

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_4M )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);
		
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x35, 0x16 );

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x36, 0x72 );
		
		E2AC4F78FF95428CA3FD05CF4E898465s( pDevice, 0x15, TP2834_TBL_4M_RASTER, 9 );

		BYTE R02 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x02 ); R02 &= 0xF8;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x02, R02 );

		BYTE RF5 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xF5 ); RF5 &= TP2834_SYS_AND[ chs ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF5, RF5 );

        E2FF27BDFED74FF28B27580A274B5954( pDevice );	

        E5173B4FF7234042AA60D2AC7273536E( pDevice, chs );

        break;
	}
    case TP2834_5M: { // [HUENGPEI] [2016.09.27.V60]

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_SET_VIDEO_MODE( STD = %02X, MODE = TP2834_5M )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, chs, std);

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x35, 0x17 );

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x36, 0xD0 );
		
		E2AC4F78FF95428CA3FD05CF4E898465s( pDevice, 0x15, TP2834_TBL_5M_RASTER, 9 );

		BYTE R02 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x02 ); R02 &= 0xF8;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x02, R02 );

		BYTE RF5 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xF5 ); RF5 &= TP2834_SYS_AND[ chs ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF5, RF5 );

        E2FF27BDFED74FF28B27580A274B5954( pDevice );	

        E5173B4FF7234042AA60D2AC7273536E( pDevice, chs );

        break;
	}

    default: {

        returns = -1;
    
		break;
	}
	}
    return returns;
}

VOID TP2834_RESET_DEFAULT( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i ) // [HUENGPEI] [2016.09.27.V60] 
{
	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: TP2834_RESET_DEFAULT()\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i);
	
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x26, 0x01 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0xC0 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x0B, 0xC0 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x22, 0x35 );

	BYTE R06 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x06 ); R06 &= 0xFB;
    
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x06, R06 );
}

VOID TP2834_OUTPUT( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, DWORD mode ) // [HUENGPEI] [2016.09.27.V60] 
{
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xFA, 0x88 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xFB, 0x88 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF6, 0x00 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF7, 0x11 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF8, 0x22 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xF9, 0x33 );

	if( TP2834_720P25V2 == mode || 
		
		TP2834_720P30V2 == mode || 
		
		TP2834_PAL == mode || 
		
		TP2834_NTSC == mode ) {

		BYTE RFA = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xFA ); RFA &= 0x88; RFA |= 0x11;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xFA, RFA );

		BYTE RFB = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xFB ); RFB &= 0x88; RFB |= 0x11;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xFB, RFB );
    }
    else if( mode & TP2834_FLAG_HALF_MODE ) {

		BYTE RFA = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xFA ); RFA &= 0x88; RFA |= 0x43;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xFA, RFA );

		BYTE RFB = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xFB ); RFB &= 0x88; RFB |= 0x65;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xFB, RFB );
    }
	else {

		;
	}
}

VOID TP2834_CHANNELID( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // [HUENGPEI] [2016.09.27.V60] 
{
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x40, 0x00 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x34, 0x10 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x40, 0x01 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x34, 0x11 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x40, 0x02 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x34, 0x10 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x40, 0x03 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x34, 0x11 );
}

VOID DA74E1188CA14BBDBC150CE97DAB3620( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // [HUENGPEI] [2016.09.27.V60] 
{
	TP2834_SET_REG_PAGE( pDevice, TP2834_REG_PAGE_VIN_ALL );

	TP2834_RESET_DEFAULT( pDevice, TP2834_REG_PAGE_VIN_ALL );

	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x02, 0xC8 ); // BT1120/BT656 

	if( pDevice->m_nCustomAnalogVideoPinTopologyProperty == 0 ) { TP2834_SET_VIDEO_MODE( pDevice, TP2834_1080P25, TP2834_REG_PAGE_VIN_ALL, TP2834_STD_TVI ); }

	if( pDevice->m_nCustomAnalogVideoPinTopologyProperty == 1 ) { TP2834_SET_VIDEO_MODE( pDevice, TP2834_1080P25, TP2834_REG_PAGE_VIN_ALL, TP2834_STD_HDA ); }

	if( pDevice->m_nCustomAnalogVideoPinTopologyProperty >= 2 ) { TP2834_SET_VIDEO_MODE( pDevice, TP2834_1080P25, TP2834_REG_PAGE_VIN_ALL, TP2834_STD_HDC ); }

	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x4D, 0x0F );

	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x4E, 0x0F );

	TP2834_OUTPUT( pDevice, TP2834_1080P25 ); // MUX OUTPUT, DEFAULT = TP2834_1080P25

	TP2834_CHANNELID( pDevice ); // CHANNEL ID

	// ADC RESET
	//
	{	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x40, TP2834_REG_PAGE_VIN_ALL );

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x3B, 0x33 );

		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x3B, 0x03 );
	}

	// SOFT RESET
	// 
	{	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x40, TP2834_REG_PAGE_VIN_ALL );

		BYTE R06 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x06 ); R06 |= 0x80;
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x06, R06 );
	}
}

VOID TP2834_FORMAT_DETECTION( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	#define TP2834_INCREASE_COUNT( v ) { if( (v) < 0xFFFFFFFF ) { (v)++; } }

	BYTE i = 0;
	for( i = 0 ; i < 4 ; i++ ) {

		if( g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ] ) {

			#ifdef AME_MZ0380

			MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ]->m_pCustomSystemConfigProperty);
			
			F42A18AF66EFF459eA332CA253FFF8A65 * g_p_device = g_pDevice[ pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE + i ];

			if( p_sys_cfg ) {
			
				TP2834_SIGNAL_INFO * p_sg_info = &(p_sys_cfg->m_s_tp2834_sg_info);

				BYTE  R01 = 0x00;

				BYTE  R03 = 0x00;
				
				ULONG x = 0;

				ULONG y = 0;

				ULONG fps = 0;

				ULONG m = 0;

				ULONG interleaved = 0;

				TP2834_SET_REG_PAGE( pDevice, i );

				R01 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x01 );

				R03 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x03 );

				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: R01 = %02X, R03 = %02X\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, R01, R03);
	
				if( TP2834_FLAG_LOSS & R01 ) {
			
					if( p_sg_info->state[ i ] != TP2834_SIGNAL_UNPLUG ) {

						p_sg_info->state[ i ] = TP2834_SIGNAL_UNPLUG;

						p_sg_info->mode[ i ] = TP2834_INVALID_FORMAT;

						p_sg_info->count[ i ] = 0;
					}
					else {

						p_sg_info->mode[ i ] = TP2834_INVALID_FORMAT;
					}
					if( p_sg_info->count[ i ] == 0 ) { //

						if( g_p_device->m_nCustomAnalogVideoPinTopologyProperty == 0 ) { TP2834_SET_VIDEO_MODE( pDevice, TP2834_1080P25, i, TP2834_STD_TVI ); }

						if( g_p_device->m_nCustomAnalogVideoPinTopologyProperty == 1 ) { TP2834_SET_VIDEO_MODE( pDevice, TP2834_1080P25, i, TP2834_STD_HDA ); }

						if( g_p_device->m_nCustomAnalogVideoPinTopologyProperty >= 2 ) { TP2834_SET_VIDEO_MODE( pDevice, TP2834_1080P25, i, TP2834_STD_HDC ); }

						TP2834_RESET_DEFAULT( pDevice, i );
					}
					TP2834_INCREASE_COUNT( p_sg_info->count[ i ] );
				}
				else {
					
					if( (TP2834_FLAG_H_LOCKED & R01) && 

						(TP2834_FLAG_V_LOCKED & R01) ) {

						if( p_sg_info->state[ i ] != TP2834_SIGNAL_LOCKED ) {

							p_sg_info->state[ i ] = TP2834_SIGNAL_LOCKED;

							p_sg_info->mode[ i ] = TP2834_INVALID_FORMAT;

							p_sg_info->count[ i ] = 0;
						}
						TP2834_INCREASE_COUNT( p_sg_info->count[ i ] );
					}
					else {

						if( p_sg_info->state[ i ] != TP2834_SIGNAL_UNLOCK ) {

							p_sg_info->state[ i ] = TP2834_SIGNAL_UNLOCK;

							p_sg_info->mode[ i ] = TP2834_INVALID_FORMAT;

							p_sg_info->count[ i ] = 0;
						}
						if( p_sg_info->count[ i ] == 0 ) { //
							
							TP2834_RESET_DEFAULT( pDevice, i );
						}
						TP2834_INCREASE_COUNT( p_sg_info->count[ i ] );
					}
					if( p_sg_info->state[ i ] == TP2834_SIGNAL_LOCKED ||
						
						p_sg_info->state[ i ] == TP2834_SIGNAL_UNLOCK ) {

						ULONG n_tvi_version = (R03 & 0x08) ? 2 : 1;

						switch( R03 & 0x07 ) {

						case 0: x = 1280; y =  720; fps = 60; m = 1; p_sg_info->mode[ i ] = TP2834_720P60;  break;

						case 1: x = 1280; y =  720; fps = 50; m = 0; p_sg_info->mode[ i ] = TP2834_720P50;  break;

						case 2: x = 1920; y = 1080; fps = 30; m = 1; p_sg_info->mode[ i ] = TP2834_1080P30; break;

						case 3: x = 1920; y = 1080; fps = 25; m = 0; p_sg_info->mode[ i ] = TP2834_1080P25; break;

						case 4: x = 1280; y =  720; fps = 30; m = 1; p_sg_info->mode[ i ] = TP2834_720P30;  break;

						case 5: x = 1280; y =  720; fps = 25; m = 0; p_sg_info->mode[ i ] = TP2834_720P25;  break;

						case 6: if( R01 & 0x04 ) {
							
									x = 960; y = 576; fps = 25; m = 0; p_sg_info->mode[ i ] = TP2834_PAL;
								}
								else {

									x = 960; y = 480; fps = 30; m = 1; p_sg_info->mode[ i ] = TP2834_NTSC;
								}
								break ;
						default: 
							
							p_sg_info->mode[ i ] = TP2834_INVALID_FORMAT;
								
							break ;
						}
						if( (R01 & 0x02) == 0x00 ) { // INTERLEAVED

							interleaved = 1;

							y >>= 1;

							fps <<= 1;
						}
						if( (p_sg_info->mode[ i ] == TP2834_720P25) && (n_tvi_version == 2) ) { p_sg_info->mode[ i ] = TP2834_720P25V2; }

						if( (p_sg_info->mode[ i ] == TP2834_720P30) && (n_tvi_version == 2) ) { p_sg_info->mode[ i ] = TP2834_720P30V2; }

						if( (p_sg_info->mode[ i ] == TP2834_720P25) && (p_sg_info->std[ i ] != TP2834_STD_TVI) ) { p_sg_info->mode[ i ] = TP2834_720P25V2; }

						if( (p_sg_info->mode[ i ] == TP2834_720P30) && (p_sg_info->std[ i ] != TP2834_STD_TVI) ) { p_sg_info->mode[ i ] = TP2834_720P30V2; }

						if( (p_sg_info->count[ i ] == 1) && (p_sg_info->mode[ i ] != TP2834_INVALID_FORMAT) ) {

							if( g_p_device->m_nCustomAnalogVideoPinTopologyProperty == 0 ) { TP2834_SET_VIDEO_MODE( pDevice, (BYTE)(p_sg_info->mode[ i ]), (BYTE)(i), TP2834_STD_TVI ); }

							if( g_p_device->m_nCustomAnalogVideoPinTopologyProperty == 1 ) { TP2834_SET_VIDEO_MODE( pDevice, (BYTE)(p_sg_info->mode[ i ]), (BYTE)(i), TP2834_STD_HDA ); }

							if( g_p_device->m_nCustomAnalogVideoPinTopologyProperty >= 2 ) { TP2834_SET_VIDEO_MODE( pDevice, (BYTE)(p_sg_info->mode[ i ]), (BYTE)(i), TP2834_STD_HDC ); }

                            {   BYTE R35 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x35 );
							
								BYTE RB9 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0xB9 );

								E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xB9, RB9 & TP2834_SYS_AND[ i ] );

								E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0xB9, RB9 | TP2834_SYS_MODE[ i ] );
                            }
						}
						else if( (p_sg_info->count[ i ] < 10) && (p_sg_info->mode[ i ] != TP2834_INVALID_FORMAT) ) {
							
							if( g_p_device->m_nCustomAnalogVideoPinTopologyProperty == 1 ||
								
								g_p_device->m_nCustomAnalogVideoPinTopologyProperty >= 2 ) { 
								
								E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2F, 0x00 );

								BYTE R04 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x04 );
							}
							else {

								;
							}
						}
						else if( (p_sg_info->count[ i ] < 20) && (p_sg_info->mode[ i ] != TP2834_INVALID_FORMAT) ) {
							
							if( g_p_device->m_nCustomAnalogVideoPinTopologyProperty == 1 ||
								
								g_p_device->m_nCustomAnalogVideoPinTopologyProperty >= 2 ) { 
								
								E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2F, 0x00 );

								BYTE R04 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x04 );
							}
							else {

								;
							}
						}
						else if( (p_sg_info->count[ i ] == 20) && (p_sg_info->mode[ i ] != TP2834_INVALID_FORMAT) ) {
							
							if( g_p_device->m_nCustomAnalogVideoPinTopologyProperty == 1 ||
								
								g_p_device->m_nCustomAnalogVideoPinTopologyProperty >= 2 ) { 
								
								E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2F, 0x00 );

								BYTE R04 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x04 );

								E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0x80 | (R04 / 4) ); // MODE
							}
							else if( p_sg_info->mode[ i ] == TP2834_3M ||

									 p_sg_info->mode[ i ] == TP2834_4M ||

									 p_sg_info->mode[ i ] == TP2834_5M ) {
								
								E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2F, 0x00 );

								BYTE R04 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x04 );

								E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0x80 | (R04 / 3) ); // MODE
							}
						}
						else if( (p_sg_info->count[ i ] == 21) && (p_sg_info->mode[ i ] != TP2834_INVALID_FORMAT) ) {
							
							if( g_p_device->m_nCustomAnalogVideoPinTopologyProperty == 1 ||  // TP2834_STD_HDA
								
								g_p_device->m_nCustomAnalogVideoPinTopologyProperty >= 2 ) { // TP2834_STD_HDC
			
								TP2834_MANUAL_AGC( pDevice );

								TP2834_EGAIN( pDevice, 0x0C );
							}
							else if( p_sg_info->mode[ i ] == TP2834_3M ||

									 p_sg_info->mode[ i ] == TP2834_4M ||

									 p_sg_info->mode[ i ] == TP2834_5M ) {

								TP2834_EGAIN( pDevice, 0x16 );
							}
						}
					}
				//	F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] CH%02d: STATE = %02X, COUNT = %02X\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, p_sg_info->state[ i ], p_sg_info->count[ i ]);
				}

				if( x != 0 && y != 0 && p_sg_info->state[ i ] == TP2834_SIGNAL_LOCKED ) {

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

						p_sys_cfg->n_input_video_resolution_color_colorimetry = (x <= 960) ? 1 : 2;

						p_sys_cfg->n_input_video_resolution_color_range = 1;

						p_sys_cfg->b_input_video_resolution_external_sync = FALSE;
					}
					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "TP2834_TVI_MODE_DETECT( %d x CH%d x %d x %d x %d )\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, (ULONG)(x), (ULONG)(y), fps);

					if( p_sys_cfg->n_input_video_resolution_fps > 50 ) {

						g_p_device->FD314ADAD9404496b842EBFC396E875CB = V4L2_STD_NTSC_M;
					}
					else if( p_sys_cfg->n_input_video_resolution_fps > 30 ) {

						g_p_device->FD314ADAD9404496b842EBFC396E875CB = V4L2_STD_PAL_B;
					}
					else if( p_sys_cfg->n_input_video_resolution_fps > 25 ) {

						g_p_device->FD314ADAD9404496b842EBFC396E875CB = V4L2_STD_NTSC_M;
					}
					else {

						g_p_device->FD314ADAD9404496b842EBFC396E875CB = V4L2_STD_PAL_B;
					}
					g_p_device->m_nCustomAnalogVideoResolutionProperty = (p_sys_cfg->n_input_video_resolution_cx << 16) |

																		    (p_sys_cfg->n_input_video_resolution_cy <<  0);

					g_p_device->m_nCustomAnalogVideoFrameRateProperty = (p_sys_cfg->n_input_video_resolution_fps);

					g_p_device->m_nCustomAnalogVideoInterleavedProperty = (p_sys_cfg->n_input_video_resolution_interleaved);
					
					g_p_device->m_nCustomAnalogAudioSampleFrequencyProperty = 48000;

					g_p_device->m_nAnalogVideoDecoderStatusProperty = 1;

					g_p_device->m_nAnalogCopyProtMacrovisionProperty = 0;
						
					g_p_device->m_nCustomAnalogVideoSdiSingalStatusProperty = 0x00000000;
				}
				else {

					p_sys_cfg->n_input_video_resolution_cx = 0;

					p_sys_cfg->n_input_video_resolution_cy = 0;

					p_sys_cfg->n_input_video_resolution_fps = 0;

					p_sys_cfg->n_input_video_resolution_fps_m = 0;

					p_sys_cfg->n_input_video_resolution_color_colorimetry = 0;

					p_sys_cfg->n_input_video_resolution_color_range = 0;

					p_sys_cfg->b_input_video_resolution_external_sync = FALSE;

					g_p_device->m_nCustomAnalogVideoResolutionProperty = 0;

					g_p_device->m_nCustomAnalogVideoFrameRateProperty = 0;

					g_p_device->m_nCustomAnalogVideoInterleavedProperty = 0;

					g_p_device->m_nCustomAnalogAudioSampleFrequencyProperty = 0;

					g_p_device->m_nAnalogVideoDecoderStatusProperty = 0;
					
					g_p_device->m_nAnalogCopyProtMacrovisionProperty = 0;

					g_p_device->m_nCustomAnalogVideoSdiSingalStatusProperty = 0x00000000;
				}
			}
			#endif
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TVI
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
VOID E805C3C2C1EE4BB5A7B9FB984AE9A893( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // TVI.NTSC // [HUENGPEI] [2016.09.27.V60]
{
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x0C, 0x43 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x0D, 0x10 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x20, 0xA0 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x26, 0x12 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2B, 0x50 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2D, 0x68 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2E, 0x5E );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x30, 0x62 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x31, 0xBB );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x32, 0x96 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x33, 0xC0 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x39, 0x84 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2C, 0x2A );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x27, 0x2D );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x28, 0x00 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x13, 0x00 );
    
	BYTE R14 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x14 ); R14 &= 0x9F;
    
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x14, R14 );
}

VOID E3E73C5B263E44A49538C0F5CC087474( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // TVI.PAL // [HUENGPEI] [2016.09.27.V60]
{
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x0C, 0x53 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x0D, 0x11 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x20, 0xB0 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x26, 0x02 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2B, 0x50 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2D, 0x60 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2E, 0x5E );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x30, 0x7A );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x31, 0x4A );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x32, 0x4D );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x33, 0xF0 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x39, 0x84 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2C, 0x2A );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x27, 0x2D );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x28, 0x00 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x13, 0x00 );
    
	BYTE R14 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x14 ); R14 &= 0x9F;
    
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x14, R14 );
}

VOID E2FF27BDFED74FF28B27580A274B5954( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // TVI.V1 // [HUENGPEI] [2016.09.27.V60]
{
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x0C, 0x03 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x0D, 0x10 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x20, 0x60 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x26, 0x02 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2B, 0x58 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2D, 0x30 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2E, 0x70 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x30, 0x48 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x31, 0xBB );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x32, 0x2E );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x33, 0x90 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x39, 0x8C );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2C, 0x0A );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x27, 0x2D );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x28, 0x00 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x13, 0x00 );
    
	BYTE R14 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x14 ); R14 &= 0x9F;
    
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x14, R14 );
}

VOID EAB107EAE6114B51BD3F0FB4DA2AC69F( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // TVI.V2 // [HUENGPEI] [2016.09.27.V60]
{
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x0C, 0x03 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x0D, 0x10 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x20, 0x60 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x26, 0x02 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2B, 0x58 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2D, 0x30 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2E, 0x70 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x30, 0x48 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x31, 0xBB );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x32, 0x2E );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x33, 0x90 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x39, 0x88 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2C, 0x0A );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x27, 0x2D );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x28, 0x00 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x13, 0x00 );

	BYTE R14 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x14 ); R14 &= 0x9F;
    
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x14, R14 );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CVI
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
VOID EE19446D035244E483A5E46A97E5D59F( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // CVI.1080P@30 // [HUENGPEI] [2016.09.27.V60]
{
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x13, 0x40 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x20, 0x80 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2B, 0x60 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2D, 0x47 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2E, 0x40 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x30, 0x41 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x31, 0x82 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x32, 0x27 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x33, 0xA6 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x28, 0x04 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0x80 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x27, 0x5A );
}

VOID D8DCD1F9AD064027A10452C04868A97C( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // CVI.1080P@25 // [HUENGPEI] [2016.09.27.V60]
{
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x13, 0x40 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x20, 0xA0 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2B, 0x60 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2D, 0x54 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2E, 0x40 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x30, 0x41 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x31, 0x82 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x32, 0x27 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x33, 0xA6 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x28, 0x04 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0x80 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x27, 0x5A );
}

VOID C08CDE54992346DBA2DE442475D38661( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // CVI.720P@60 // [HUENGPEI] [2016.09.27.V60]
{
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x13, 0x40 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x20, 0x60 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2B, 0x60 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2D, 0x37 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2E, 0x40 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x30, 0x41 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x31, 0x82 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x32, 0x27 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x33, 0xA6 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x28, 0x04 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0x80 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x27, 0x5A );
}

VOID C01CF1A557124A2DBA1A07DE30F643BB( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // CVI.720P@50 // [HUENGPEI] [2016.09.27.V60]
{
    E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x13, 0x40 );
    E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x20, 0x74 );
    E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2B, 0x60 );
    E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2D, 0x42 );
    E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2E, 0x40 );
    E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x30, 0x41 );
    E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x31, 0x82 );
    E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x32, 0x27 );
    E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x33, 0xA6 );
    E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x28, 0x04 );
    E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0x80 );
    E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x27, 0x5A );
}

VOID DF4D6828C6594BFAAC9003C3922B6FEA( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // CVI.720P@30 // [HUENGPEI] [2016.09.27.V60]
{
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x13, 0x40 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x20, 0x60 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2B, 0x60 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2D, 0x37 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2E, 0x40 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x30, 0x48 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x31, 0x67 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x32, 0x6F );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x33, 0x31 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x28, 0x04 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0x80 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x27, 0x5A );
}

VOID EC79937CD24E45669B4577A220279B39( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // CVI.720P@25 // [HUENGPEI] [2016.09.27.V60]
{
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x13, 0x40 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x20, 0x74 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2B, 0x60 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2D, 0x42 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2E, 0x40 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x30, 0x48 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x31, 0x67 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x32, 0x6F );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x33, 0x31 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x28, 0x04 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0x80 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x27, 0x5A );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// AHD
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
VOID EC1A6FEC82B94C82B77E0C402F0AEDAD( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // AHD.1080P@30 // [HUENGPEI] [2016.09.27.V60]
{
	BYTE R14 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x14 ); R14 |= 0x60;
    
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x14, R14 );

	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2D, 0x45 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2E, 0x50 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x30, 0x29 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x31, 0x65 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x32, 0x78 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x33, 0x16 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0x80 );
}

VOID F3239D73625F40B781275AB950E90D2A( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // AHD.1080P@25 // [HUENGPEI] [2016.09.27.V60]
{
	BYTE R14 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x14 ); R14 |= 0x60;
    
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x14, R14 );

	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2D, 0x45 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2E, 0x40 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x30, 0x29 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x31, 0x61 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x32, 0x78 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x33, 0x16 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0x80 );
}

VOID ADF318917EFF4756BA46113402285685( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // AHD.720P@30 // [HUENGPEI] [2016.09.27.V60]
{
	BYTE R14 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x14 ); R14 |= 0x40;
    
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x14, R14 );

	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2D, 0x48 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2E, 0x5E );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x30, 0x27 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x31, 0x72 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x32, 0x80 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x33, 0x77 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0x80 );
}

VOID A4A06B2DEF35482E9369B8A444050AE9( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice ) // AHD.720P@25 // [HUENGPEI] [2016.09.27.V60]
{
	BYTE R14 = E337333B92284BE3A3A414AA44ED9827( pDevice, 0x14 ); R14 |= 0x40;
    
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x14, R14 );

	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2D, 0x48 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x2E, 0x5E );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x30, 0x27 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x31, 0x88 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x32, 0x04 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x33, 0x23 );
	E2AC4F78FF95428CA3FD05CF4E898465( pDevice, 0x07, 0x80 );
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
// 
//
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
VOID E5173B4FF7234042AA60D2AC7273536E( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE chs ) // [HUENGPEI] [2016.09.27.V60] 
{
	// SDR_1CH
	// 
	if( chs >= 4 ) { 
            
		ULONG i = 0;
		for( i = 0 ; i < 4 ; i++ ) {
			
			BYTE R = E337333B92284BE3A3A414AA44ED9827( pDevice, TP2834_CLK_ADDR[ i ] ); 
				
			R &= TP2834_CLK_AND[ i ];
    
			E2AC4F78FF95428CA3FD05CF4E898465( pDevice, TP2834_CLK_ADDR[ i ], R );
		}
	}
	else {
			
		ULONG i = chs;
			
		BYTE R = E337333B92284BE3A3A414AA44ED9827( pDevice, TP2834_CLK_ADDR[ i ] ); 
				
		R &= TP2834_CLK_AND[ i ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, TP2834_CLK_ADDR[ i ], R );
	}
}

VOID E53B0F47531845E59FCB35008578C3ED( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE chs ) // [HUENGPEI] [2016.09.27.V60] 
{
	// SDR_1CH
	// 
	if( chs >= 4 ) {
            
		ULONG i = 0;
		for( i = 0 ; i < 4 ; i++ ) {
			
			BYTE R = E337333B92284BE3A3A414AA44ED9827( pDevice, TP2834_CLK_ADDR[ i ] ); 
				
			R &= TP2834_CLK_AND[ i ];

			R |= TP2834_CLK_MODE[ i ];
    
			E2AC4F78FF95428CA3FD05CF4E898465( pDevice, TP2834_CLK_ADDR[ i ], R );
		}
	}
	else {
			
		ULONG i = chs;
			
		BYTE R = E337333B92284BE3A3A414AA44ED9827( pDevice, TP2834_CLK_ADDR[ i ] ); 
				
		R &= TP2834_CLK_AND[ i ];

		R |= TP2834_CLK_MODE[ i ];
    
		E2AC4F78FF95428CA3FD05CF4E898465( pDevice, TP2834_CLK_ADDR[ i ], R );
	}
}
