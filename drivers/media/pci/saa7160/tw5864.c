#include "LINUXV4L2.h"
#include "property.h"
#include "pci5864win7OSDZK.h"
#include "tw5864.h"
#include "linux/time.h"


//TW5864 encode
#define TW5864_DROP_H264	10 //OK


static int a0c563aa017e45aa898479fcd6f672e2( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );
static int f74f60e6b0814257af133a93b451d6b1( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice );


//peter [2011.07.11] from OSD.cpp

#define OSD_TIMER_MAX_LEN	 OSD_TIMER_MAX_ADDR_NUM<<5

#define OSD_TIMER_MAX_ADDR_NUM 44

struct OSD_CNTL_REG_0
{
	unsigned x_coordinate_start:7;
	unsigned y_coordinate_start:7;
	unsigned x_mb_num:7;
	unsigned y_mb_num:7;
	unsigned data_base_addr_hbit:1;
	unsigned merge_mode:2;
	unsigned merge_enable:1;
};

struct OSD_CNTL_REG_1
{
	unsigned mask_color_fv:8;
	unsigned mask_color_fu:8;
	unsigned mask_color_fy:8;
	unsigned data_base_addr_lbit:8;
};

struct OSD_CNTL_REG_2
{
	unsigned mask_color_bv:8;
	unsigned mask_color_bu:8;
	unsigned mask_color_by:8;
	unsigned data_addr_map_mode:2;
	unsigned data_addr_offset:3;
	unsigned reserved:3;
};

struct OSD_REG_CACHE
{
	struct OSD_CNTL_REG_0 reg0;
	struct OSD_CNTL_REG_1 reg1;
	struct OSD_CNTL_REG_2 reg2;
};

struct ISIL_OSD_REG_PARAM
{
	unsigned int reg_ddr_offset;
	unsigned int  reg_page_index;
	struct OSD_REG_CACHE rect_reg_cache;
};

struct ISIL_OSD_MB_PARAM
{
	unsigned int  ddr_offset;
	unsigned int  page_index;
};

struct ISIL_OSD_TIMER_PARAM
{
	struct ISIL_OSD_REG_PARAM rect_regs;
	struct ISIL_OSD_MB_PARAM mb_param[OSD_TIMER_MAX_ADDR_NUM];
	unsigned char data[OSD_TIMER_MAX_LEN];
	unsigned int datalen;
};

#define SPECIAL_CHAR_MAP_NUM 9
/*osd table*/
unsigned short special_map_tbl[SPECIAL_CHAR_MAP_NUM]=
{
	0x18d,0x1b4,0x1c5,
		0x18f,0x1b3,0x1ba,
		0x19d,0x197,0x1a0
};

void get_osd_char_data(unsigned char *txt,unsigned char *unchanged_osdbuf,unsigned short xmb_num,unsigned short scale,unsigned int char_num)
{
	unsigned int offset,i,j;
	unsigned int qh,wh;
	unsigned int *pascii_addr,*pchar_addr;
	unsigned int  *posdbuf,*psingleosdbuf;
	unsigned int h_byte_number=0;
	unsigned int index;
	unsigned int char_num_temp = 0;

	posdbuf = (unsigned int*)unchanged_osdbuf;
	h_byte_number = xmb_num << 2;
	if(scale == 2)
	{
		unsigned short  *tpascii_addr,*tpsingleosdbuf,*tposdbuf;
		unsigned int first_flag=1;
		unsigned int  continueasc =0;
		while((*txt) && (char_num_temp<char_num))
		{
			psingleosdbuf = posdbuf; 
			if(*(txt)&0x80)
			{
				first_flag=0;
				qh=(unsigned char)(*txt-0xa1);  
				wh=(unsigned char)(*(txt+1)-0xa1);
				offset = (qh*94+wh)*24;
				pchar_addr =(unsigned int*) (special_12_char_tbl+offset);		
				for(i=0;i<2;i++)
				{
					for(j=0;j<3;j++)
					{
						psingleosdbuf[j] = *pchar_addr++;
					}
					psingleosdbuf +=  h_byte_number;
				}
				txt += 2;
				posdbuf+=3;
				char_num_temp+=2;
			}
			else
			{
				if(((*(txt-1)&0x80)&&(!first_flag))||(first_flag))
					continueasc=0;
				else
					continueasc++;
				first_flag=0;
				if(!(continueasc&0x1))
				{
					offset=(*txt)*16;
					txt += 1;
					pascii_addr =  (unsigned int*)(ascii12_6_tbl +offset);
					psingleosdbuf = posdbuf; 
					for(i=0;i<2;i++)
					{
						for(j=0;j<2;j++)
						{
							psingleosdbuf[j] = *pascii_addr++;
						}
						psingleosdbuf += h_byte_number;
					}
					posdbuf+=2;	
				}
				else 
				{
					offset=(*txt)*16;
					txt += 1;
					tpascii_addr =  (unsigned short*)(ascii12_6_tbl +offset);
					tpsingleosdbuf = (unsigned short*)posdbuf;
					for(i=0;i<2;i++)
					{	
						tpsingleosdbuf[1] = *tpascii_addr++;
						tpsingleosdbuf[-2] = *tpascii_addr++;
						tpascii_addr++;
						tpsingleosdbuf[0] = *tpascii_addr++;
						tpsingleosdbuf += (h_byte_number<<1);
					}
					posdbuf+=1;		
				}
				char_num_temp++;
			}
		}
	}
	else if((scale == 4) || (scale == 8))
	{
		while((*txt) && (char_num_temp<char_num))
		{
			psingleosdbuf = posdbuf;
			if(*(txt)&0x80)
			{ 
				qh=(unsigned char)(*txt-0xa1);  
				wh=(unsigned char)(*(txt+1)-0xa1);
				offset = (qh*94+wh)*8;
				pchar_addr =(unsigned int*) (special_8_char_tbl+offset); 
				for(i=0;i<2;i++)
				{
					psingleosdbuf[i] = *pchar_addr++;
				}
				txt += 2;
				posdbuf+=2;
				char_num_temp+=2;
			}
			else
			{
				offset=(*txt)*4;
				txt += 1;
				pascii_addr =  (unsigned int*)(ascii8_4_tbl +offset);
				psingleosdbuf = posdbuf; 
				*psingleosdbuf = *pascii_addr++;
				posdbuf+=1; 
				char_num_temp++;
			}
		}
	}
	else
	{
		while((*txt) && (char_num_temp<char_num))
		{
			psingleosdbuf = posdbuf;
			if(*(txt)&0x80)
			{
				index = (unsigned)( *txt+*(txt+1));
				for(i=0;i<SPECIAL_CHAR_MAP_NUM;i++)
				{
					if(index == special_map_tbl[i])
					{
						offset = i;
						break;
					}
				}
				pchar_addr =(unsigned int*) (special_char_tbl+offset*72);
				for( i=0; i<3; i++)
				{
					for( j=0; j<6; j++)
					{
						psingleosdbuf[j] = *pchar_addr++;
					}
					psingleosdbuf +=  h_byte_number;
				}
				txt += 2;
				posdbuf += 6;
				char_num_temp+=2;
			}
			else
			{
				offset = (*txt)*36;
				txt += 1;
				pascii_addr =  (unsigned int*)(ascii24_12_tbl +offset);
				for( i=0; i<3; i++)
				{
					for( j=0; j<(3); j++)
					{
						psingleosdbuf[j] = *pascii_addr++;
					}
					psingleosdbuf += h_byte_number;
				}
				posdbuf += 3;
				char_num_temp++;
			}
		}
	}
}

void osd_char_data_changed(unsigned char *unchanged_osdbuf,unsigned char*changed_osdbuf,unsigned short xmb_num,unsigned short ymb_num)
{
	unsigned int i,j;
	unsigned int *pinbuf1,*pinbuf2,*poutbuf;

	pinbuf1 = (unsigned int*)unchanged_osdbuf;
	pinbuf2 = pinbuf1+ (xmb_num<<2);

	poutbuf = (unsigned int*)changed_osdbuf;
	for(i=0;i<ymb_num;i++)
	{
		for(j=0;j<xmb_num;j++)
		{
			*poutbuf++ = *pinbuf1++;
			*poutbuf++ = *pinbuf1++;
			*poutbuf++ = *pinbuf1++;
			*poutbuf++ = *pinbuf1++;
			*poutbuf++ = *pinbuf2++;
			*poutbuf++ = *pinbuf2++;
			*poutbuf++ = *pinbuf2++;
			*poutbuf++ = *pinbuf2++;
		}
		pinbuf1 = pinbuf2;
		pinbuf2 = pinbuf1+ (xmb_num<<2);
	}
}

int  get_osd_timer_data(unsigned char *data,unsigned char *unchanged_osdbuf,unsigned char  *changed_osdbuf,unsigned short xmb_num,unsigned short ymb_num,unsigned short scale,unsigned int char_num)
{
	get_osd_char_data(data,unchanged_osdbuf,xmb_num,scale,char_num);
	osd_char_data_changed(unchanged_osdbuf,changed_osdbuf,xmb_num,ymb_num);
	return TRUE;
}

unsigned int cal_cif_osd_data_addr_base(unsigned short chid,unsigned short osd_num)
{
	unsigned int  num_osd_data_base=0;
	unsigned int  chan_osd_data_base=0;
	unsigned int  osd_data_addr_base=0;
	num_osd_data_base = (osd_num<<17)+(1<<16);
	chan_osd_data_base = ((((chid>>2)<<3)+(chid&0x3))<<20);
	osd_data_addr_base = chan_osd_data_base + num_osd_data_base;
	return (osd_data_addr_base>>2);
}

unsigned int cal_cif_osd_data_base(unsigned short chid,unsigned short osd_num)
{
	unsigned int  osd_data_addr=0;
	unsigned int osd_data_base=0;
	osd_data_addr = cal_cif_osd_data_addr_base(chid,osd_num);
	osd_data_base = (osd_data_addr>>14);
	return osd_data_base;
}

unsigned int cal_d1_osd_data_base(unsigned short chid,unsigned short osd_num)
{
	unsigned int osd_data_base=0;
	unsigned int  num_osd_data_base=0;
	unsigned int  chan_osd_data_base=0;
	unsigned int  osd_data_addr_base=0;
	if(osd_num<3)
		num_osd_data_base = (3<<16)+(osd_num<<18);
	else
		num_osd_data_base = (3<<18)+((osd_num-3)<<16);
	chan_osd_data_base = (((chid>>2)<<3)+(((chid&0x3))<<20)); 
	osd_data_addr_base = num_osd_data_base + chan_osd_data_base;
	osd_data_base = osd_data_addr_base>>(2+14);
	return osd_data_base;
}
///end of OSD.cpp////////////////////////////////////////////////////////////////////////////////////////////////////////

// #define TW5864_COPYPORTECT_ARCHITECTURE

#ifdef TW5864_COPYPORTECT_ARCHITECTURE

static ULONG FD0AC55FE0C0B45a788FEC199C5758F1E[ 16 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

static ULONG F6053D464C87D41c1B8CBE8A39FCDF2D2[ 16 ] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

#endif


ULONG c3c09a67df944bec9b42209724048dc4( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F0FAB4549F1C3407aACDBD483D0D23C86 )
{
//	if( F02179B6B95CB43eeB160478D8CF83778 == 4 ) 
		{ return readl( (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ) & 0xFFFFFFFF; }

//	if( F02179B6B95CB43eeB160478D8CF83778 == 2 ) { return readw( (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ) & 0x0000FFFF; }

//	if( F02179B6B95CB43eeB160478D8CF83778 == 1 ) { return readb( (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ) & 0x000000FF; }

	return 0x00000000;
}

BOOLEAN b13825e2dd0b4ba4a5c7741536f21277( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F0FAB4549F1C3407aACDBD483D0D23C86, ULONG F09894BF114FE4ee592C232BC39730E91 )
{
//	if( F02179B6B95CB43eeB160478D8CF83778 == 4 ) 
		{ writel( (F09894BF114FE4ee592C232BC39730E91 & 0xFFFFFFFF), (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); }

//	if( F02179B6B95CB43eeB160478D8CF83778 == 2 ) { writew( (F09894BF114FE4ee592C232BC39730E91 & 0x0000FFFF), (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); }

//	if( F02179B6B95CB43eeB160478D8CF83778 == 1 ) { writeb( (F09894BF114FE4ee592C232BC39730E91 & 0x000000FF), (pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + F0FAB4549F1C3407aACDBD483D0D23C86) ); }

	return TRUE;
}

ULONG c18095576e1242d39e06f837c6599bee( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F0FAB4549F1C3407aACDBD483D0D23C86 )
{
	ULONG i = 0 ;
	ULONG j = 0 ;

	for( i = 0 ; i < 3000 ; i++ ) {

		ULONG R0000B800 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000B800 );

		if( (R0000B800 & 0x80000000) == 0x00000000 ) {

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000B800, (F0FAB4549F1C3407aACDBD483D0D23C86) | (1 << 25) );

			for( j = 0 ; j < 3000 ; j++ ) {

				ULONG R0000B800 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000B800 );

				if( (R0000B800 & 0x80000000) == 0x00000000 ) {

					return c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000B804 );
				}
			}
			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "c18095576e1242d39e06f837c6599bee( 1 ): GET REGISTER %08X ERROR!!\n", F0FAB4549F1C3407aACDBD483D0D23C86);

			return 0x00000000;
		}
	}
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "c18095576e1242d39e06f837c6599bee( 2 ): GET REGISTER %08X ERROR!!\n", F0FAB4549F1C3407aACDBD483D0D23C86);

	return 0x00000000;
}

BOOLEAN c08e773e16fb4ac7a4a5ed488cd4b12c( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG F0FAB4549F1C3407aACDBD483D0D23C86, ULONG F09894BF114FE4ee592C232BC39730E91 )
{
	ULONG i = 0;
	for( i = 0 ; i < 3000 ; i++ ) {

		ULONG R0000B800 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000B800 );

		if( (R0000B800 & 0x80000000) == 0x00000000 ) {

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000B804, (F09894BF114FE4ee592C232BC39730E91) );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000B800, (F0FAB4549F1C3407aACDBD483D0D23C86) | (1 << 25) | (1 << 24) );

			return TRUE;
		}
	}
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] c08e773e16fb4ac7a4a5ed488cd4b12c(): SET REGISTER %08X × %08X ERROR!!\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), F0FAB4549F1C3407aACDBD483D0D23C86, F09894BF114FE4ee592C232BC39730E91);

	return FALSE;
}

BOOLEAN d0e203938933403cb29557bc86e87ce1( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nSlaveAddr, ULONG nIndex, BYTE * pData, ULONG F02179B6B95CB43eeB160478D8CF83778 )
{
	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018048, c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018048 ) | 0x00000001 );

	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000800C, c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000800C ) | 0x00000001 );

	ULONG i = 0;

	for( i = 0 ; i < F02179B6B95CB43eeB160478D8CF83778 ; i++ ) {
		
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018014, (1 << 24) + (nSlaveAddr << 16) + ((nIndex + i) << 8) );

		ULONG j = 0;

		for( j = 0 ; j < 3000 ; j++ ) {

			if( c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018014 ) & (1 << 24) ) { 
				
				break ;
			}
		}
		pData[ i ] = (BYTE)(c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018014 ));
	}
	return TRUE;
}

/*
BOOLEAN TW5864_SetSlaveDeviceByte( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG nSlaveAddr, ULONG nIndex, BYTE * pData, ULONG F02179B6B95CB43eeB160478D8CF83778 )
{
	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018048, c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018048 ) | 0x00000001 );

	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000800C, c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000800C ) | 0x00000001 );

	for( ULONG i = 0 ; i < F02179B6B95CB43eeB160478D8CF83778 ; i++ ) {
		
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018014, (1 << 24) + (nSlaveAddr << 16) + ((nIndex + i) << 8) + pData[ i ] );

		for( ULONG j = 0 ; j < 3000 ; j++ ) {

			if( c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018014 ) & (1 << 24) ) { 
				
				break ;
			}
		}
	}
	return TRUE;
}
*/

ULONG TW5864_KsQueryCopyProtectNumber(  F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE p[ 4 ] )
{
	UINT eKey = 0x12345678;

	ULONG i = 0;

	if( pDevice->iProduct == 0x53 && 
		
		pDevice->iManufacturer == 0xB1 ) {

		eKey = 0x20E4A207;

		for( i = 0 ; i < 4 ; i++ ) { switch( p[ 0 ] % 4 ) { case 0: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0x47AA9ACB; eKey ^= (eKey >> 8) | (eKey << 24); break;

																  case 1: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0x83DCA300; eKey ^= (eKey >> 8) | (eKey << 24); break;

																  case 2: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0xF59EB3C9; eKey ^= (eKey >> 8) | (eKey << 24); break;

																  case 3: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0x412E4E2F; eKey ^= (eKey >> 8) | (eKey << 24); break;
										   }
		}
	}
	else {

		eKey = 0x12345678;

		for( i = 0 ; i < 4 ; i++ ) { switch( p[ 0 ] % 4 ) { case 0: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0xA539C75A; eKey ^= (eKey >> 8) | (eKey << 24); break;

																  case 1: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0x9F28A543; eKey ^= (eKey >> 8) | (eKey << 24); break;

																  case 2: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0x7B6324C5; eKey ^= (eKey >> 8) | (eKey << 24); break;

																  case 3: eKey <<= 8; eKey ^= p[ i ]; eKey ^= 0xF1029554; eKey ^= (eKey >> 8) | (eKey << 24); break;
										   }
		}
	}
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "CODE = %08X | KEY = %08X\n", *((ULONG *)(p)), eKey);

	return eKey;
}

//note
//register 0x9801 can not remember its value
//any get will return 0
// 
VOID TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE DATA, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	ULONG R00009800 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x9800 ) & 0x00FF;

	R00009800 |= p_sys_cfg->R00009801;

	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x9800, (R00009800 & (~0x0001)) | (DATA << 0) );

	ndelay( F6B9E557A4BA24ffd926B820B836289C8 * 100 );
}

VOID TW5864_F17905ED7D5754d2f948B78DE2E19357B( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE DATA, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	ULONG R00009800 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x9800 ) & 0x00FF;

	R00009800 |= p_sys_cfg->R00009801;

	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x9800, (R00009800 & (~0x0002)) | (DATA << 1) );

	ndelay( F6B9E557A4BA24ffd926B820B836289C8 * 100 );
}

VOID TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE DATA, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	ULONG R00009800 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x9800 ) & 0x00FF;

	R00009800 |= p_sys_cfg->R00009801;

	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x9800, (R00009800 & (~0x0003)) | (DATA << 0) );

	ndelay( F6B9E557A4BA24ffd926B820B836289C8 * 100 );
}

BYTE TW5864_F8B11D4E6664C424dA74D592AB89DC1CA( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 ) 
{
	TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	ULONG R00009800 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x9800 ) & 0x00FF;

	R00009800 |= p_sys_cfg->R00009801;

	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x9800, R00009800 & (~0x0200) );

	BYTE DATA = (((BYTE)(c3c09a67df944bec9b42209724048dc4( pDevice, 0x9800 ))) & 0x02) >> 1;

	ndelay( F6B9E557A4BA24ffd926B820B836289C8 * 100 );

	return DATA;
}

BOOLEAN TW5864_F8B7FB94CF24D4152842C9743714CDAA9( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	TW5864_F17905ED7D5754d2f948B78DE2E19357B( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );						 // TW5864_F17905ED7D5754d2f948B78DE2E19357B( pDC, 1 ); // TW5864_I2C INITIAL STAGE (SCL.H) (SDA.H):

	TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 3, F6B9E557A4BA24ffd926B820B836289C8 );						 // TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( pDC, 1 );

	TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );						 // TW5864_F17905ED7D5754d2f948B78DE2E19357B( pDC, 0 ); // TW5864_I2C START STAGE (SDA.L):

	TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );						 // TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( pDC, 0 );

	return TRUE;
}

BOOLEAN TW5864_F1C002401C7AE4334A36AC1B1E338AD75( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );						 // TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( pDC, 0 );

	TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );						 // TW5864_F17905ED7D5754d2f948B78DE2E19357B( pDC, 0 ); // TW5864_I2C STOP STAGE (SDA.H):

	TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );						 // TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( pDC, 1 );

	TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 3, F6B9E557A4BA24ffd926B820B836289C8 );						 // TW5864_F17905ED7D5754d2f948B78DE2E19357B( pDC, 1 );

	return TRUE;
}

BOOLEAN TW5864_F2E93DF3F52A04c9dACD486D8609988F3( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{	
//	TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 1, F6B9E557A4BA24ffd926B820B836289C8 );					     // TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( 1 ); 

	TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 3, F6B9E557A4BA24ffd926B820B836289C8 );					     // TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( 1 ); (WITH ERROR CHECK)

	BYTE ACK = TW5864_F8B11D4E6664C424dA74D592AB89DC1CA( pDevice, F6B9E557A4BA24ffd926B820B836289C8 );				 // ACK = TW5864_F8B11D4E6664C424dA74D592AB89DC1CA();

	TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );						 // TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( 0 );

	return (ACK == 0) ? TRUE : FALSE;								 //
}

BOOLEAN TW5864_F76CEC38463124e7790A43B09F0D38227( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE ACK, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, (ACK) ? 2 : 0, F6B9E557A4BA24ffd926B820B836289C8 );			 // TW5864_F17905ED7D5754d2f948B78DE2E19357B( ACK );

	TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, (ACK) ? 3 : 1, F6B9E557A4BA24ffd926B820B836289C8 );			 // TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( 1 );

	TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, (ACK) ? 2 : 0, F6B9E557A4BA24ffd926B820B836289C8 );			 // TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( 0 );

	return TRUE;
}

BOOLEAN TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE DATA, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{
	UINT i = 0 ;
	for( i = 0 ; i < 8 ; i++, DATA <<= 1 ) {					 //

		TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, (DATA & 0x80) ? 2 : 0, F6B9E557A4BA24ffd926B820B836289C8 ); // TW5864_F17905ED7D5754d2f948B78DE2E19357B( (DATA & 0x80) ? 1 : 0 );

		TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, (DATA & 0x80) ? 3 : 1, F6B9E557A4BA24ffd926B820B836289C8 ); // TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( 1 );

		TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, (DATA & 0x80) ? 2 : 0, F6B9E557A4BA24ffd926B820B836289C8 ); // TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( 0 );
	}
	return TW5864_F2E93DF3F52A04c9dACD486D8609988F3( pDevice, F6B9E557A4BA24ffd926B820B836289C8 );                    // TW5864_F2E93DF3F52A04c9dACD486D8609988F3()
}

BYTE TW5864_F6E9556EF6B7D45fbB367C7EF7BF65BFB( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, BYTE ACK, ULONGLONG F6B9E557A4BA24ffd926B820B836289C8 )
{	
	BYTE DATA = 0x00;

	UINT i = 0 ;
	for( i = 0 ; i < 8 ; i++ ) {								//

		TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 2, F6B9E557A4BA24ffd926B820B836289C8 );					// TW5864_F17905ED7D5754d2f948B78DE2E19357B( 1 );

		TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 3, F6B9E557A4BA24ffd926B820B836289C8 );					// TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( 1 );

		DATA = (DATA << 1) | TW5864_F8B11D4E6664C424dA74D592AB89DC1CA( pDevice, F6B9E557A4BA24ffd926B820B836289C8 );	// DATA = (DATA << 1) | TW5864_F8B11D4E6664C424dA74D592AB89DC1CA();

		TW5864_F5ACEE342A88D4e1eB9CD9B730F11DE15( pDevice, 0, F6B9E557A4BA24ffd926B820B836289C8 );					// TW5864_F69DBADFDE7C4448fA5C5E95F4DC00E1E( 0 );
	}
	TW5864_F76CEC38463124e7790A43B09F0D38227( pDevice, ACK, F6B9E557A4BA24ffd926B820B836289C8 );					// TW5864_F76CEC38463124e7790A43B09F0D38227( ACK )

	return DATA;
}

DWORD cf82fa7a8b1b4a99b0abe8f7a59774e8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG fps )
{
	ULONG frames = 0;

	if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) {

		frames = 30;
	}

	if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) {

		frames = 25;
	}
	ULONG R = 0x00000000;

	ULONG counts = 0;

	ULONG i = 0;

	for( i = 0 ; i < frames ; i++ ) {

		counts += fps;

		if( counts >= frames ) {

			counts -= frames;

			R |= (1 << i);
		}
	}
	return R;
}

//#define MAX_PATH 260
//peter: sometimes CMOS_READ will read at updating CMOS, so I keep the latest value for using
//struct rtc_time currenttime;

BOOLEAN b2937aa152e245fe820cf833fa6d3b40( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG i )
{
	// -----> OnEncodeFinished() -----> UpdateOSD() [2010.12.05]
	//
	TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

//	CHAR psz[ MAX_PATH ] = "0000-00-00 00:00:00";

	ULONG flags = 0;

	BYTE sec = 0;
	BYTE min = 0;
	BYTE hour = 0;
	BYTE day = 0;
	BYTE month = 0;
	BYTE year = 0;

	//spin_lock_irqsave(&rtc_lock, flags);
	/*
	BYTE uip = (CMOS_READ(RTC_FREQ_SELECT) & RTC_UIP);//  read RTC exactly on falling edge of update flag 
	
	if(uip != 0x80)
	{
		sec = CMOS_READ(RTC_SECONDS);
		min = CMOS_READ(RTC_MINUTES);
		hour = CMOS_READ(RTC_HOURS);
		day = CMOS_READ(RTC_DAY_OF_MONTH);
		month = CMOS_READ(RTC_MONTH);
		year = CMOS_READ(RTC_YEAR);

		currenttime.tm_sec = BCD_TO_BINARY(sec);
		
		currenttime.tm_min = BCD_TO_BINARY(min);
		
		currenttime.tm_hour = BCD_TO_BINARY(hour);
		
		currenttime.tm_mday = BCD_TO_BINARY(day);
		
		currenttime.tm_mon = BCD_TO_BINARY(month);
		
		currenttime.tm_year = BCD_TO_BINARY(year);

		currenttime.tm_year += 1900;

		if( currenttime.tm_year < 1970 ) { currenttime.tm_year += 100; }
	}
	*/

	//spin_unlock_irqrestore( &rtc_lock, flags );

	ULONG n_osd_num = 0;

//current, main and sub stream will have same OSD ???

	for( n_osd_num = 0 ; n_osd_num < 7 ; n_osd_num++ ) {

		BOOLEAN is_update = FALSE;
			
		CHAR psz[ MAX_PATH ] = "";
		CHAR timer_psz[ MAX_PATH ] = "";
			


		if( pDevice->m_bCustomOsdTextStringRefreshProperty[ i ][ n_osd_num ] == TRUE ) {

			pDevice->m_bCustomOsdTextStringRefreshProperty[ i ][ n_osd_num ] = FALSE;

			if( strlen( pDevice->m_pCustomOsdTextStringProperty[ i % 8 ][ n_osd_num ] ) != 0 ) {
			
				sprintf( psz, "%s", pDevice->m_pCustomOsdTextStringProperty[ i % 8 ][ n_osd_num ] );

//				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "b2937aa152e245fe820cf833fa6d3b40() i(%d) n_osd_num(%d) string(%s) psz(%s)\n", i, n_osd_num, pDevice->m_pCustomOsdTextStringProperty[ i % 8 ][ n_osd_num ], psz );

				if( strcmp( psz, " " ) == 0 )
				{
					ULONG j = 0;

					for( j = 0 ; j < 2 ; j++ ) {

						ULONG dw_osd_attribute_address = ((0x0000047F << 10) | (j << 9) | (i << 5) | (n_osd_num * 3)) << (2);

						b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000030,  (dw_osd_attribute_address & 0xFFF80000) >> 19 );

						b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + (dw_osd_attribute_address & 0x0007FFFF) + 0x00000000, 0x00000000 );

						b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + (dw_osd_attribute_address & 0x0007FFFF) + 0x00000004, 0x00000000 );

						b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + (dw_osd_attribute_address & 0x0007FFFF) + 0x00000008, 0x00000000 );
					}

					is_update = FALSE;
					
					continue;
				}

				is_update = TRUE;
			}

		}

		if( n_osd_num == 0 ) {

			if(	strlen( pDevice->m_pCustomOsdTextStringProperty[ i % 8 ][ n_osd_num ] ) == 0 ) {
				/*
				if( p_sys_cfg->s_video_encoder_osd_timer[ i ].Second != currenttime.tm_sec ) { 

					p_sys_cfg->s_video_encoder_osd_timer[ i ].Second = currenttime.tm_sec;
					p_sys_cfg->s_video_encoder_osd_timer[ i ].Minute = currenttime.tm_min;
					p_sys_cfg->s_video_encoder_osd_timer[ i ].Hour = currenttime.tm_hour;
					p_sys_cfg->s_video_encoder_osd_timer[ i ].Day = currenttime.tm_mday;
					p_sys_cfg->s_video_encoder_osd_timer[ i ].Month = currenttime.tm_mon;
					p_sys_cfg->s_video_encoder_osd_timer[ i ].Year = currenttime.tm_year;

					sprintf( psz, "%04d-%02d-%02d %02d:%02d:%02d", p_sys_cfg->s_video_encoder_osd_timer[ i ].Year, p_sys_cfg->s_video_encoder_osd_timer[ i ].Month, p_sys_cfg->s_video_encoder_osd_timer[ i ].Day, p_sys_cfg->s_video_encoder_osd_timer[ i ].Hour, p_sys_cfg->s_video_encoder_osd_timer[ i ].Minute, p_sys_cfg->s_video_encoder_osd_timer[ i ].Second );

					is_update = TRUE; 
				}
				*/
			}
			else //add string before timer
			{

				sprintf( psz, "%s", pDevice->m_pCustomOsdTextStringProperty[ i % 8 ][ n_osd_num ] );

				if( strcmp( psz, " " ) == 0 )//previous clear command
				{
					//already clear by above
					
					is_update = FALSE;
					
					continue;
				}
				/*
				if( p_sys_cfg->s_video_encoder_osd_timer[ i ].Second != currenttime.tm_sec ) { 

					p_sys_cfg->s_video_encoder_osd_timer[ i ].Second = currenttime.tm_sec;
					p_sys_cfg->s_video_encoder_osd_timer[ i ].Minute = currenttime.tm_min;
					p_sys_cfg->s_video_encoder_osd_timer[ i ].Hour = currenttime.tm_hour;
					p_sys_cfg->s_video_encoder_osd_timer[ i ].Day = currenttime.tm_mday;
					p_sys_cfg->s_video_encoder_osd_timer[ i ].Month = currenttime.tm_mon;
					p_sys_cfg->s_video_encoder_osd_timer[ i ].Year = currenttime.tm_year;

					sprintf( timer_psz, " %04d-%02d-%02d %02d:%02d:%02d", p_sys_cfg->s_video_encoder_osd_timer[ i ].Year, p_sys_cfg->s_video_encoder_osd_timer[ i ].Month, p_sys_cfg->s_video_encoder_osd_timer[ i ].Day, p_sys_cfg->s_video_encoder_osd_timer[ i ].Hour, p_sys_cfg->s_video_encoder_osd_timer[ i ].Minute, p_sys_cfg->s_video_encoder_osd_timer[ i ].Second );

					sprintf( psz, "%s", pDevice->m_pCustomOsdTextStringProperty[ i % 8 ][ 0 ] );

					strcat( psz, timer_psz );

//					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "b2937aa152e245fe820cf833fa6d3b40(time) i(%d) n_osd_num(%d) psz(%s)\n", i, n_osd_num, psz );

					is_update = TRUE; 
				}
				*/
			}
		}


		if( is_update == FALSE ) { continue ; }

		ULONG is_sub_stream = 0;

		for( is_sub_stream = 0 ; is_sub_stream < 2 ; is_sub_stream++ ) {

			struct ISIL_OSD_TIMER_PARAM param;

			ULONG x_mb_num = (is_sub_stream) ? (strlen(psz) * 3 + 7) / (8) : (strlen(psz) * 3 + 3) / (4);

			ULONG y_mb_num = (is_sub_stream) ? 1 : 2;

			ULONG dw_osd_attribute_address = ((0x0000047F << 10) | ((is_sub_stream) << 9) | ((i % 8) << 5) | (n_osd_num * 3)) << (2);

			ULONG dw_osd_data_base_address = cal_d1_osd_data_base( (USHORT)(i % 8), (USHORT)(n_osd_num) );

			param.rect_regs.reg_page_index = (dw_osd_attribute_address & 0xFFF80000) >> (19);

			param.rect_regs.reg_ddr_offset = (dw_osd_attribute_address);

			param.rect_regs.rect_reg_cache.reg0.x_coordinate_start = 1;

			param.rect_regs.rect_reg_cache.reg0.y_coordinate_start = 1 + (n_osd_num * y_mb_num);

			param.rect_regs.rect_reg_cache.reg0.x_mb_num = x_mb_num - 1;

			param.rect_regs.rect_reg_cache.reg0.y_mb_num = y_mb_num - 1;

			param.rect_regs.rect_reg_cache.reg0.data_base_addr_hbit = (dw_osd_data_base_address >> 8) & 0xFF;

			param.rect_regs.rect_reg_cache.reg0.merge_mode = 0;

			param.rect_regs.rect_reg_cache.reg0.merge_enable = 1;

			param.rect_regs.rect_reg_cache.reg1.data_base_addr_lbit = (dw_osd_data_base_address >> 0) & 0xFF;

			param.rect_regs.rect_reg_cache.reg1.mask_color_fv = 0;

			param.rect_regs.rect_reg_cache.reg1.mask_color_fu = 0;

			param.rect_regs.rect_reg_cache.reg1.mask_color_fy = 0;

			param.rect_regs.rect_reg_cache.reg2.mask_color_bv = 0;

			param.rect_regs.rect_reg_cache.reg2.mask_color_bu = 0;

			param.rect_regs.rect_reg_cache.reg2.mask_color_by = 0;

			param.rect_regs.rect_reg_cache.reg2.data_addr_map_mode = 0;

			param.rect_regs.rect_reg_cache.reg2.data_addr_offset = (is_sub_stream) ? 4 : 0;

			param.rect_regs.rect_reg_cache.reg2.reserved = 0;

			ULONG y = 0;

			for( y = 0 ; y < y_mb_num ; y++ ) {

				ULONG x = 0;

				for( x = 0 ; x < x_mb_num ; x++ ) {

					ULONG dw_osd_data_address = ((dw_osd_data_base_address << 14) | (y << 11) | (x << 4)) + ((is_sub_stream) << 13);

					dw_osd_data_address <<= 2;

					param.mb_param[ x_mb_num * y + x ].page_index = (dw_osd_data_address & 0xFFF80000) >> (19);

					param.mb_param[ x_mb_num * y + x ].ddr_offset = (dw_osd_data_address);
				}
			}
			memset( p_sys_cfg->p_video_encoder_osd_punchanged_buf, 0x00, 88 * 32 );

			if( is_sub_stream ) {

				get_osd_timer_data( (UCHAR *)(psz), (BYTE *)(p_sys_cfg->p_video_encoder_osd_punchanged_buf), (BYTE *)(p_sys_cfg->p_video_encoder_osd_pchanged_buf), (USHORT)(x_mb_num), (USHORT)(y_mb_num), 2, strlen(psz) );
			}
			else {

				get_osd_timer_data( (UCHAR *)(psz), (BYTE *)(p_sys_cfg->p_video_encoder_osd_punchanged_buf), (BYTE *)(p_sys_cfg->p_video_encoder_osd_pchanged_buf), (USHORT)(x_mb_num), (USHORT)(y_mb_num), 1, strlen(psz) );
			}
			param.datalen = (y_mb_num * x_mb_num) * 32;

			memcpy( param.data, p_sys_cfg->p_video_encoder_osd_pchanged_buf, param.datalen );

			////////////////////////////////////////////////////////////////////////////////////////

			ULONG R00000030 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000030 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000030, R00000030 | 0x00008000 );

			ULONG j = 0;

			for( j = 0 ; j < 1000 ; j++ ) {

				if( (c3c09a67df944bec9b42209724048dc4( pDevice, 0x00080000 + 0x00000000 ) & 0x80000000) == 0x00000000 ) {

					break;
				}
			}
			if( j < 1000 ) {

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000030, param.rect_regs.reg_page_index | 0x00008000 );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + 0x00000008, 0x00000000 );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + 0x00004000, *((DWORD *)(&param.rect_regs.rect_reg_cache.reg0)) );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + 0x00004004, *((DWORD *)(&param.rect_regs.rect_reg_cache.reg1)) );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + 0x00004008, *((DWORD *)(&param.rect_regs.rect_reg_cache.reg2)) );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + 0x00000004, param.rect_regs.reg_ddr_offset );

				ULONG R00080000 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00080000 + 0x00000000 );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + 0x00000000, R00080000 | 0x0003000C );

				ULONG j = 0;

				for( j = 0 ; j < 1000 ; j++ ) {

					R00080000 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00080000 + 0x00000000 );

					if( R00080000 & 0x01000000 ) {

						b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + 0x00000000, R00080000 | 0x01000000 );

						break;
					}
				}
			}
			R00000030 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000030 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000030, R00000030 | 0x00008000 );

			ULONG counts = 0;

			for( counts = 0 ; counts < (param.datalen / 32) ; counts++ ) {

				ULONG j = 0;

				for( j = 0 ; j < 1000 ; j++ ) {

					if( (c3c09a67df944bec9b42209724048dc4( pDevice, 0x00080000 + 0x00000000 ) & 0x80000000) == 0x00000000 ) {

						break;
					}
				}
				if( j < 1000 ) {

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000030, param.mb_param[ counts ].page_index | 0x00008000 );

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + 0x00000008, 0x00000000 );

//					WRITE_REGISTER_BUFFER_ULONG( (ULONG *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00080000 + 0x00004000), (ULONG *)(param.data + 32 * counts), 8 );
//peter [2011.07.11]
					memcpy( (UINT *)(pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00080000 + 0x00004000), (UINT *)(param.data + 32 * counts), 8 * 4 );

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + 0x00000004, param.mb_param[ counts ].ddr_offset );

					ULONG R00080000 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00080000 + 0x00000000 );

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + 0x00000000, R00080000 | 0x00030020 );

					for( j = 0 ; j < 1000 ; j++ ) {

						R00080000 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00080000 + 0x00000000 );

						if( R00080000 & 0x01000000 ) {

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + 0x00000000, R00080000 | 0x01000000 );

							break;
						}
					}
				}
			}
		}
	}
	return TRUE;
}





void CBR_to_VBR( F301FA49098CE4d9eB95F22BBD388E837 * pVideo, ULONG F0DD7393CD1494e27A72652C7D1A97893 )
{
		F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = pVideo->FB6E79A0780E64bb28A3308666E67881C;

		TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		ULONG i = F0DD7393CD1494e27A72652C7D1A97893;

		{

			p_sys_cfg->n_video_encoder_reference_buffer_index[ i + 0 ] = 0;

			p_sys_cfg->n_video_encoder_reference_buffer_index[ i + 8 ] = 0;

			p_sys_cfg->n_video_encoder_input_buffer_index[ i + 0 ] = -1; // NON READY

			p_sys_cfg->n_video_encoder_input_buffer_index[ i + 8 ] = -1; // NON READY

			p_sys_cfg->n_video_encoder_selected_channel = 0;

//			if( pDevice->m_nAnalogVideoDecoderStandardProperty & SUPPORTED_ANALOG_VIDEO_STANDARDS_60HZ ) { 

			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) {

				p_sys_cfg->n_video_encoder_frame_cx[ i + 0 ] = 704;

				p_sys_cfg->n_video_encoder_frame_cx[ i + 8 ] = 352;

				p_sys_cfg->n_video_encoder_frame_cy[ i + 0 ] = 480;

				p_sys_cfg->n_video_encoder_frame_cy[ i + 8 ] = 240;

				p_sys_cfg->n_video_encoder_gop[ i + 0 ] = pVideo->F1CA927B5918D436c9F5839C9727D620E;

				p_sys_cfg->n_video_encoder_gop[ i + 8 ] = pVideo->F1CA927B5918D436c9F5839C9727D620E;

				p_sys_cfg->n_video_encoder_bitrate[ i + 0 ] = (4 * 1024 * 1024) / 30;

				p_sys_cfg->n_video_encoder_bitrate[ i + 8 ] = (512 * 1024) / 30;
			}
//			if( pDevice->m_nAnalogVideoDecoderStandardProperty & SUPPORTED_ANALOG_VIDEO_STANDARDS_50HZ ) { 

			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) {

				p_sys_cfg->n_video_encoder_frame_cx[ i + 0 ] = 704;

				p_sys_cfg->n_video_encoder_frame_cx[ i + 8 ] = 352;

				p_sys_cfg->n_video_encoder_frame_cy[ i + 0 ] = 576;

				p_sys_cfg->n_video_encoder_frame_cy[ i + 8 ] = 288;

				p_sys_cfg->n_video_encoder_gop[ i + 0 ] = pVideo->F1CA927B5918D436c9F5839C9727D620E;

				p_sys_cfg->n_video_encoder_gop[ i + 8 ] = pVideo->F1CA927B5918D436c9F5839C9727D620E;

				p_sys_cfg->n_video_encoder_bitrate[ i + 0 ] = (4 * 1024 * 1024) / 25;

				p_sys_cfg->n_video_encoder_bitrate[ i + 8 ] = (512 * 1024) / 25;
			}
			p_sys_cfg->n_video_encoder_frame_fps_mask[ i + 0 ] = 1;

			p_sys_cfg->n_video_encoder_frame_fps_mask[ i + 8 ] = 1;

			p_sys_cfg->n_video_encoder_frame_fps_mask_length[ i + 0 ] = 1;

			p_sys_cfg->n_video_encoder_frame_fps_mask_length[ i + 8 ] = 1;

			p_sys_cfg->n_video_encoder_frame_number[ i + 0 ] = 0;

			p_sys_cfg->n_video_encoder_frame_number[ i + 8 ] = 0;

//??
			p_sys_cfg->n_picture_number_to_user[ i + 0 ] = 0;

			p_sys_cfg->n_picture_number_to_user[ i + 8 ] = 0;



			p_sys_cfg->n_video_encoder_gop_step[ i + 0 ] = 0;

			p_sys_cfg->n_video_encoder_gop_step[ i + 8 ] = 0;

			p_sys_cfg->n_video_encoder_record_mode[ i + 0 ] = 0;

			p_sys_cfg->n_video_encoder_record_mode[ i + 8 ] = 0;

			p_sys_cfg->n_video_encoder_init_qp[ i + 0 ] = 26;

			p_sys_cfg->n_video_encoder_init_qp[ i + 8 ] = 26;

			p_sys_cfg->n_video_encoder_qp[ i + 0 ] = 26;

			p_sys_cfg->n_video_encoder_qp[ i + 8 ] = 26;

			ULONG j = 0;

			for( j = 0 ; j < 256 ; j++ ) { // CBR.WINDOW.SIZE = 256
				
				p_sys_cfg->n_viode_encoder_cbr_frame_size_window[ i + 0 ][ j ] = 0; 

				p_sys_cfg->n_viode_encoder_cbr_frame_size_window[ i + 8 ][ j ] = 0; 
			}

			p_sys_cfg->n_viode_encoder_cbr_frame_size_window_step[ i + 0 ] = 0;

			p_sys_cfg->n_viode_encoder_cbr_frame_size_window_step[ i + 8 ] = 0;

			p_sys_cfg->n_viode_encoder_cbr_frame_size_sum[ i + 0 ] = 0;

			p_sys_cfg->n_viode_encoder_cbr_frame_size_sum[ i + 8 ] = 0;

			p_sys_cfg->n_viode_encoder_cbr_qp_base[ i + 0 ] = 26;

			p_sys_cfg->n_viode_encoder_cbr_qp_base[ i + 8 ] = 26;

			p_sys_cfg->n_viode_encoder_cbr_qp_base_updated_damping[ i + 0 ] = 0;

			p_sys_cfg->n_viode_encoder_cbr_qp_base_updated_damping[ i + 8 ] = 0;

			p_sys_cfg->n_audio_encoder_reference_buffer_index[ i + 0 ] = 0;
		}
}


BOOLEAN daab48e1fab545a880ab7abf60648829( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] daab48e1fab545a880ab7abf60648829()\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

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

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 0;

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 3 ] = 0;
	}

#ifdef TW5864_COPYPORTECT_ARCHITECTURE

	if( FD0AC55FE0C0B45a788FEC199C5758F1E[ pDevice->FF362AA37F7D046bf90568AC1600626D9 ] == 0 ) { return TRUE; }

	if( F6053D464C87D41c1B8CBE8A39FCDF2D2[ pDevice->FF362AA37F7D046bf90568AC1600626D9 ] == 0 ) { return TRUE; }
#endif

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 == 1 ) {

		f74f60e6b0814257af133a93b451d6b1( pDevice );// com init

		// -----> SetNTSCReg() [2011.08.11]
		// 
		if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) {

			ULONG R00000260 = c18095576e1242d39e06f837c6599bee( pDevice, (0x00000260 << 2) );

			R00000260 &= ~0x01;

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000260 << 2), R00000260 );

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000201 << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000203 << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000205 << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000207 << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000209 << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000020B << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000020D << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000020F << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000211 << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000213 << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000215 << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000217 << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000219 << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000021B << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000021D << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000021F << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000221 << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000223 << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000225 << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000227 << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000229 << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000022B << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000022D << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000022F << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000231 << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000233 << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000235 << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000237 << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000239 << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000023B << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000023D << 2), 0x0000003C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000023F << 2), 0x0000001E );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000075 << 2), 0x000000E4 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000076 << 2), 0x00000022 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000077 << 2), 0x0000000C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000078 << 2), 0x000000D5 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000079 << 2), 0x000000A6 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000007A << 2), 0x00000000 );
		}
		// -----> SetPALReg() [2011.08.11]
		// 
		if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) {

			ULONG R00000260 = c18095576e1242d39e06f837c6599bee( pDevice, (0x00000260 << 2) );

			R00000260 |= 0x01;

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000260 << 2), R00000260 );

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000201 << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000203 << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000205 << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000207 << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000209 << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000020B << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000020D << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000020F << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000211 << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000213 << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000215 << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000217 << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000219 << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000021B << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000021D << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000021F << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000221 << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000223 << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000225 << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000227 << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000229 << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000022B << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000022D << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000022F << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000231 << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000233 << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000235 << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000237 << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000239 << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000023B << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000023D << 2), 0x00000048 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000023F << 2), 0x00000024 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000075 << 2), 0x000000E4 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000076 << 2), 0x00000022 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000077 << 2), 0x0000000C );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000078 << 2), 0x00000000 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000079 << 2), 0x000000C8 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000007A << 2), 0x00000000 );
		}

		// -----> SetISIL5864AD() [2011.08.11]
		//
		ULONG i = 0 ;

		for( i = 0 ; i < 4 ; i++ ) {

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000007 + i * 0x10) << (2), 0x00 ); // HUE

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000000B + i * 0x10) << (2), 0x80 ); // SATURATION

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000000C + i * 0x10) << (2), 0x80 ); // SATURATION

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000009 + i * 0x10) << (2), 0x64 ); // CONTRAST

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000000A + i * 0x10) << (2), 0x00 ); // BRIGHTNESS

			ULONG R000000F3 = c18095576e1242d39e06f837c6599bee( pDevice, (0x000000F3 << 2) );

			R000000F3 |= 0x02; // BLUE

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000000F3 << 2), R000000F3 );
		}

		// -----> StartFPGA() -----> UpdatePreviewParam() -----> ISILH264FpgaDisableAllPreview() [2011.08.11]
		//
		{	ULONG R00018004 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018004 ); 

		//	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018004, R00018004 & ~(1 << 4) ); // H.P.LIN: 0x00000010 -> 0x00000000

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C004, 0x00000000 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C008, 0x00000000 );

			for( i = 0 ; i < 3000 ; i++ ) { 

				if( c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000C000 ) == 0x00000000 ) {

					break;
				}
			}
			for( i = 0 ; i < 4 ; i++ ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C200 + (i * 4), 0x00000000 ); }

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C020, 0x00000000 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C024, 0x00000000 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C02C, 0x00000000 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018044, 0x00000000 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018040, 0x00000000 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C014, 0x00000000 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C018, 0x00000000 );
		}

		
		// -----> StartFPGA() -----> UpdatePreviewParam() -----> ISILH264PreviewSet() [2011.03.04]
		//
		{	ULONG cx[ 16 ] = { 352, 352, 352, 352, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

			ULONG cy[ 16 ] = { 240, 240, 240, 240, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
			
			{

				ULONG i = 0 ;
				for( i = 0 ; i < 4 ; i++ ) {

					ULONG cx_e = 704;

					ULONG cy_e = 480;

					if( pVideo )
					{
						cx_e = pVideo->FD1832F8D382F4e91914C0048CC5A9DD8;

						cy_e = pVideo->F5B8891B732954fc2B26B7BFFCB15B596;
					
						F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] daab48e1fab545a880ab7abf60648829() cx_e(0d%d) cy_e(0d%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), cx_e, cy_e );
					}
		
					if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) {

						if( cx_e == 704 && cy_e == 576 ) { cx[ i ] = 704; cy[ i ] = 480; } else

						if( cx_e == 704 && cy_e == 480 ) { cx[ i ] = 704; cy[ i ] = 480; } else

						if( cx_e == 704 && cy_e == 288 ) { cx[ i ] = 704; cy[ i ] = 240; } else

						if( cx_e == 704 && cy_e == 240 ) { cx[ i ] = 704; cy[ i ] = 240; } else

						if( cx_e == 352 && cy_e == 288 ) { cx[ i ] = 352; cy[ i ] = 240; } else

						if( cx_e == 352 && cy_e == 240 ) { cx[ i ] = 352; cy[ i ] = 240; } else

														 { cx[ i ] = 352; cy[ i ] = 240; }
					}
					if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) {

						if( cx_e == 704 && cy_e == 576 ) { cx[ i ] = 704; cy[ i ] = 576; } else

						if( cx_e == 704 && cy_e == 480 ) { cx[ i ] = 704; cy[ i ] = 576; } else

						if( cx_e == 704 && cy_e == 288 ) { cx[ i ] = 704; cy[ i ] = 288; } else

						if( cx_e == 704 && cy_e == 240 ) { cx[ i ] = 704; cy[ i ] = 288; } else

						if( cx_e == 352 && cy_e == 288 ) { cx[ i ] = 352; cy[ i ] = 288; } else

						if( cx_e == 352 && cy_e == 240 ) { cx[ i ] = 352; cy[ i ] = 288; } else

														 { cx[ i ] = 352; cy[ i ] = 288; }
					}

				}
			}
			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C00C, 0x00000000 );
		
			for( i = 0 ; i < 16 ; i++ ) {

				ULONG R0000C008 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000C008 );

				ULONG R0000C020 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000C020 );

				ULONG R0000C024 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000C024 );

				if( cx[ i ] == 720 || cx[ i ] == 704 ) {

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C008, R0000C008 & ~(1 << i) );

					if( i < 8 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C020, R0000C020 & ~(3 << ((i - 0) * 2)) ); }

					if( i > 7 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C024, R0000C024 & ~(3 << ((i - 8) * 2)) ); }
				}
				if( cx[ i ] == 360 || cx[ i ] == 352 ) {

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C008, R0000C008 | (1 << i) );

					if( i < 8 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C020, R0000C020 | (3 << ((i - 0) * 2)) ); }

					if( i > 7 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C024, R0000C024 | (3 << ((i - 8) * 2)) ); }
				}
				if( cx[ i ] == 180 || cx[ i ] == 176 ) {

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C008, R0000C008 | (1 << i) );

					if( i < 8 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C020, R0000C020 | (1 << ((i - 0) * 2)) ); }

					if( i > 7 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C024, R0000C024 | (1 << ((i - 8) * 2)) ); }
				}
			}
			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) {
				
				ULONG R00018044 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018044 );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C014, 0x000003BD );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C018, 0x000003BD );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018044, R00018044 |  (0x00001000) );
			}
			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) {

				ULONG R00018044 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018044 );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C014, 0x00000318 );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C018, 0x00000318 );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018044, R00018044 & ~(0x00001000) );
			}

			static UINT TW5864_IN_SELECT_REG_TABLE_08CH[ 16 ] = { 0x00000002, 0x00000003, 0x00000000, 0x00000001, 0x00000004, 0x00000005, 0x00000008, 0x00000009, 0x00000006, 0x00000007, 0x0000000A, 0x0000000B, 0x0000000C, 0x0000000D, 0x0000000E, 0x0000000F };

			static UINT TW5864_IN_MAP_REG_TABLE_08CH[ 16 ]    = { 0x3FFFFFFF, 0x3FFFFFFF, 0x3FFFFFFF, 0x3FFFFFFF, 0x3FFFFFFF, 0x3FFFFFFF, 0x00000000, 0x00000000, 0x3FFFFFFF, 0x3FFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		//	static UINT TW5864_IN_FMT_REG_TABLE_08CH[ 16 ]    = { 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000003, 0x00000005, 0x00000005, 0x00000003, 0x00000003, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005, 0x00000005 };

			static UINT TW5864_IN_FMT_REG_TABLE_08CH[ 16 ]    = {        352,        352,        352,        352,        352,        352,        176,        176,        352,        352,        176,        176,        176,        176,        176,        176 };

			static UINT TW5864_IN_SELECT_REG_TABLE_04CH[ 16 ] = { 0x00000004, 0x00000005, 0x00000000, 0x00000006, 0x00000001, 0x00000007, 0x00000008, 0x00000009, 0x00000002, 0x0000000A, 0x0000000B, 0x0000000C, 0x00000003, 0x0000000D, 0x0000000E, 0x0000000F };

			static UINT TW5864_IN_MAP_REG_TABLE_04CH[ 16 ]    = { 0x00000000, 0x00000000, 0x3FFFFFFF, 0x00000000, 0x3FFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x3FFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x3FFFFFFF, 0x00000000, 0x00000000, 0x00000000 };

		//	static UINT TW5864_IN_FMT_REG_TABLE_04CH[ 16 ]    = { 0x00000005, 0x00000005, 0x00000001, 0x00000005, 0x00000001, 0x00000005, 0x00000005, 0x00000005, 0x00000001, 0x00000005, 0x00000005, 0x00000005, 0x00000001, 0x00000005, 0x00000005, 0x00000005 };

			static UINT TW5864_IN_FMT_REG_TABLE_04CH[ 16 ]    = {        176,        176,        704,        176,        704,        176,        176,        176,        704,        176,        176,        176,        704,        176,        176,        176 };

			static UINT TW5864_IN_SELECT_REG_TABLE[ 16 ];

			static UINT TW5864_IN_MAP_REG_TABLE[ 16 ];

			static UINT TW5864_IN_FMT_REG_TABLE[ 16 ];

			memcpy( TW5864_IN_SELECT_REG_TABLE, TW5864_IN_SELECT_REG_TABLE_04CH, sizeof(UINT) * 16 );

			memcpy( TW5864_IN_MAP_REG_TABLE, TW5864_IN_MAP_REG_TABLE_04CH, sizeof(UINT) * 16 );

			memcpy( TW5864_IN_FMT_REG_TABLE, TW5864_IN_FMT_REG_TABLE_04CH, sizeof(UINT) * 16 );

			for( i = 0 ; i < 4 ; i++ ) {

				ULONG R0000C010 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000C010 );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C010, R0000C010 & ~(1 << i) );

				ULONG j = 0 ;
				for( j = 0 ; j < 4 ; j++ ) {

					ULONG R0000C200 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000C200 + (i * 4) );

					R0000C200 |= (TW5864_IN_SELECT_REG_TABLE[ i * 4 + j ] & 0x0000000F) << (j * 4);

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C200 + (i * 4), R0000C200 );

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C100 + (i * 8 + j * 2 + 0) * (4), (TW5864_IN_MAP_REG_TABLE[ i * 4 + j ] >>  0) & 0x0000FFFF );

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C100 + (i * 8 + j * 2 + 1) * (4), (TW5864_IN_MAP_REG_TABLE[ i * 4 + j ] >> 16) & 0x0000FFFF );
				}
				ULONG R00018044 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018044 );

				if( cx[ TW5864_IN_SELECT_REG_TABLE[ i * 4 + 0 ] ] == 720 ) { R00018044 |=  (3 << (i * 2)); R00018044 &= ~(1 << (i + 8)); }

				if( cx[ TW5864_IN_SELECT_REG_TABLE[ i * 4 + 0 ] ] == 704 ) { R00018044 |=  (2 << (i * 2)); R00018044 &= ~(1 << (i + 8)); }

				if( cx[ TW5864_IN_SELECT_REG_TABLE[ i * 4 + 0 ] ] == 360 ) { R00018044 &= ~(3 << (i * 2)); R00018044 |=  (1 << (i + 8)); }

				if( cx[ TW5864_IN_SELECT_REG_TABLE[ i * 4 + 0 ] ] == 352 ) { R00018044 &= ~(3 << (i * 2)); R00018044 |=  (1 << (i + 8)); }

				if( cx[ TW5864_IN_SELECT_REG_TABLE[ i * 4 + 0 ] ] == 180 ) { R00018044 |=  (1 << (i * 2)); R00018044 |=  (1 << (i + 8)); }

				if( cx[ TW5864_IN_SELECT_REG_TABLE[ i * 4 + 0 ] ] == 176 ) { R00018044 |=  (1 << (i * 2)); R00018044 |=  (1 << (i + 8)); }

				if( cx[ TW5864_IN_SELECT_REG_TABLE[ i * 4 + 0 ] ] ==   0 ) { R00018044 |=  (1 << (i * 2)); R00018044 |=  (1 << (i + 8)); }

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018044, R00018044 );
			}
			{	ULONG R00018040 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018040 );

				R00018040 |= 0x00000001;

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018040, R00018040 );

				if( cx[ 0 ] == 704 ) {

					ULONG R00018044 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018044 );

					R00018044 |=  (2 << 13); // 這段程式有縮簡 
					
					R00018044 &= ~(1 << 15); // 這段程式有縮簡

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018044, R00018044 );
				}
				if( cx[ 0 ] == 352 ) {

					ULONG R00018044 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018044 );

					R00018044 &= ~(3 << 13); // 這段程式有縮簡 
					
					R00018044 |=  (1 << 15); // 這段程式有縮簡

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018044, R00018044 );
				}
			}
		}

		// -----> StartFPGA() -----> UpdatePreviewParam() -----> UpdateAudio() -----> ISILH264FpgaAudioDataType() [2011.08.11]
		//
		{	ULONG R0000404C = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000404C );

			R0000404C &= 0xFFFDFFFF;

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000404C, R0000404C | 0x00020000 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000404C, R0000404C );

			ULONG RE0 = c18095576e1242d39e06f837c6599bee( pDevice, (0x000000E0 << 2) ) & 0xEF;

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000000E0 << 2), RE0 | 0x10 );

		}
		{	ULONG R0000404C = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000404C );

		//	R0000404C |= 0x0000FFFF; // 1 = ADPCM

			R0000404C &= 0xFFFF0000; // 0 = PCM

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000404C, R0000404C );
		}

		// -----> StartFPGA() -----> UpdatePreviewParam() -----> UpdateAudio() -----> ISILH264FpgaEnableAudio() [2011.08.11]
		//
		{	ULONG R0000400C = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000400C );

			R0000400C |= 0x0000000F;

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000400C, R0000400C );
		}

		// -----> StartFPGA() -----> UpdatePreviewParam() -----> ISILH264FpgaSetPreviewParam() [2011.06.24]
		//

		for( i = 0 ; i < 4 ; i++ ) {

			ULONG memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i ]; // 12345
	
			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018100 + (i * 2 + 0) * 4, memory_F6F32B5439E4C42f095E08326DFA73107 );

//			memory_F6F32B5439E4C42f095E08326DFA73107 += 704 * 576 * 3 / 2;

			memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ i + 5 ]; // 12345;
			
			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018100 + (i * 2 + 1) * 4, memory_F6F32B5439E4C42f095E08326DFA73107 );

		}

		// -----> StartFPGA() -----> UpdatePreviewParam() -----> ISILH264FpgaEnableAllPreview() [2011.08.11]
		//
		{	ULONG R00018004 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018004 ); 
		//
		//	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018004, R00018004 | (1 << 4) ); // [移除]
			
#ifdef APLUS
			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C004, 0x00000000 );

			ULONG i = 0 ;
			for( i = 0 ; i < 3000 ; i++ ) {

				if( c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000C000 ) == 0x00000000 ) {

					break;
				}
			}
#else
			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C004, 0x0000000F );

			ULONG i = 0 ;
			for( i = 0 ; i < 3000 ; i++ ) {

				if( c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000C000 ) == 0x0000000F ) {

					break;
				}
			}
#endif
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		for( i = 0 ; i < 8 ; i++ ) {

			p_sys_cfg->n_video_encoder_reference_buffer_index[ i + 0 ] = 0;

			p_sys_cfg->n_video_encoder_reference_buffer_index[ i + 8 ] = 0;

			p_sys_cfg->n_video_encoder_input_buffer_index[ i + 0 ] = -1; // NON READY

			p_sys_cfg->n_video_encoder_input_buffer_index[ i + 8 ] = -1; // NON READY

			p_sys_cfg->n_video_encoder_selected_channel = 0;

			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) {

				p_sys_cfg->n_video_encoder_frame_cx[ i + 0 ] = 704;

				p_sys_cfg->n_video_encoder_frame_cx[ i + 8 ] = 352;

				p_sys_cfg->n_video_encoder_frame_cy[ i + 0 ] = 480;

				p_sys_cfg->n_video_encoder_frame_cy[ i + 8 ] = 240;

				p_sys_cfg->n_video_encoder_gop[ i + 0 ] = pVideo->F1CA927B5918D436c9F5839C9727D620E;

				p_sys_cfg->n_video_encoder_gop[ i + 8 ] = pVideo->F1CA927B5918D436c9F5839C9727D620E;

				p_sys_cfg->n_video_encoder_bitrate[ i + 0 ] = (4 * 1024 * 1024) / 30;

				p_sys_cfg->n_video_encoder_bitrate[ i + 8 ] = (512 * 1024) / 30;
			}
			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) {

				p_sys_cfg->n_video_encoder_frame_cx[ i + 0 ] = 704;

				p_sys_cfg->n_video_encoder_frame_cx[ i + 8 ] = 352;

				p_sys_cfg->n_video_encoder_frame_cy[ i + 0 ] = 576;

				p_sys_cfg->n_video_encoder_frame_cy[ i + 8 ] = 288;

				p_sys_cfg->n_video_encoder_gop[ i + 0 ] = pVideo->F1CA927B5918D436c9F5839C9727D620E;

				p_sys_cfg->n_video_encoder_gop[ i + 8 ] = pVideo->F1CA927B5918D436c9F5839C9727D620E;

				p_sys_cfg->n_video_encoder_bitrate[ i + 0 ] = (4 * 1024 * 1024) / 25;

				p_sys_cfg->n_video_encoder_bitrate[ i + 8 ] = (512 * 1024) / 25;
			}
			p_sys_cfg->n_video_encoder_frame_fps_mask[ i + 0 ] = 1;

			p_sys_cfg->n_video_encoder_frame_fps_mask[ i + 8 ] = 1;

			p_sys_cfg->n_video_encoder_frame_fps_mask_length[ i + 0 ] = 1;

			p_sys_cfg->n_video_encoder_frame_fps_mask_length[ i + 8 ] = 1;

			p_sys_cfg->n_video_encoder_frame_number[ i + 0 ] = 0;

			p_sys_cfg->n_video_encoder_frame_number[ i + 8 ] = 0;








			p_sys_cfg->n_video_encoder_gop_step[ i + 0 ] = 0;

			p_sys_cfg->n_video_encoder_gop_step[ i + 8 ] = 0;

			p_sys_cfg->n_video_encoder_record_mode[ i + 0 ] = 0;

			p_sys_cfg->n_video_encoder_record_mode[ i + 8 ] = 0;

			p_sys_cfg->n_video_encoder_init_qp[ i + 0 ] = 26;

			p_sys_cfg->n_video_encoder_init_qp[ i + 8 ] = 26;

			p_sys_cfg->n_video_encoder_qp[ i + 0 ] = 26;

			p_sys_cfg->n_video_encoder_qp[ i + 8 ] = 26;

			ULONG j = 0;

			for( j = 0 ; j < 256 ; j++ ) { // CBR.WINDOW.SIZE = 256
				
				p_sys_cfg->n_viode_encoder_cbr_frame_size_window[ i + 0 ][ j ] = 0; 

				p_sys_cfg->n_viode_encoder_cbr_frame_size_window[ i + 8 ][ j ] = 0; 
			}
			p_sys_cfg->n_viode_encoder_cbr_frame_size_window_step[ i + 0 ] = 0;

			p_sys_cfg->n_viode_encoder_cbr_frame_size_window_step[ i + 8 ] = 0;

			p_sys_cfg->n_viode_encoder_cbr_frame_size_sum[ i + 0 ] = 0;

			p_sys_cfg->n_viode_encoder_cbr_frame_size_sum[ i + 8 ] = 0;

			p_sys_cfg->n_viode_encoder_cbr_qp_base[ i + 0 ] = 26;

			p_sys_cfg->n_viode_encoder_cbr_qp_base[ i + 8 ] = 26;

			p_sys_cfg->n_viode_encoder_cbr_qp_base_updated_damping[ i + 0 ] = 0;

			p_sys_cfg->n_viode_encoder_cbr_qp_base_updated_damping[ i + 8 ] = 0;

			p_sys_cfg->n_audio_encoder_reference_buffer_index[ i + 0 ] = 0;
		}


//TW5864 encode
		p_sys_cfg->n_preview_video_satrt = 0;
		p_sys_cfg->n_H264_output_enable = 1;

		// -----> UpdateEncodeParam() -----> DisableAllEncode() [2011.06.24]

		//
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000028, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009004, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009000, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009020, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009024, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009008, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009010, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009014, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009024, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000D00, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000D04, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009018, 0x00000000 );
		
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000D50, 0x0000FFFF );

		for( i = 0 ; i < 4 ; i++ ) {

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009200 + (i * 4), 0x00000000 );
		}

		// -----> UpdateEncodeParam() [2011.06.24]
		//
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000900C, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000001C, 0x00000000 );

		for( i = 0 ; i < 16 ; i++ ) {

			ULONG cx[ 16 ] = { 704, 704, 704, 704, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

			ULONG cy[ 16 ] = { 480, 480, 480, 480, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

			if( i < 4 ) { cx[ i ] = 704; cy[ i ] = 480; }

			ULONG R00009008 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00009008 );

			ULONG R00009020 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00009020 );

			ULONG R00009024 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00009024 );

			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) {

				if( cy[ i ] == 576 ) { cy[ i ] = 480; }

				if( cy[ i ] == 288 ) { cy[ i ] = 240; }
			}

			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) {

				if( cy[ i ] == 480 ) { cy[ i ] = 576; }

				if( cy[ i ] == 240 ) { cy[ i ] = 288; }
			}
			if( (cx[ i ] == 720) ||
				
				(cx[ i ] == 704) ) { 

				R00009008 &= ~(0x01 << i);
				
				if( i <  8 ) { R00009020 &= ~(0x03 << ((i - 0) * 2)); }

				if( i >= 8 ) { R00009024 &= ~(0x03 << ((i - 8) * 2)); }

				if( i <  8 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009008, R00009008 ); }

				if( i >= 8 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009008, R00009008 ); }

				if( i <  8 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009020, R00009020 ); }

				if( i >= 8 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009024, R00009024 ); }
			}
			if( (cx[ i ] == 352) ) { 

				R00009008 |= (0x01 << i);

				if( i <  8 ) { R00009020 |=  (0x03 << ((i - 0) * 2)); }

				if( i >= 8 ) { R00009024 |=  (0x03 << ((i - 8) * 2)); }

				if( i <  8 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009008, R00009008 ); }

				if( i >= 8 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009008, R00009008 ); }

				if( i <  8 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009020, R00009020 ); }

				if( i >= 8 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009024, R00009024 ); }
			}
		}

		if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) {
			
			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009014, 0x000003BD );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009018, 0x000003BD );
		}

		if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) {
			
			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009014, 0x00000318 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009018, 0x00000318 );
		}
		for( i = 0 ; i < 4 ; i++ ) {

			ULONG R00009010 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00009010 ); 
			
			R00009010 &= ~(0x00000001 << i);

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009010, R00009010 );

			ULONG j = 0 ;
			for( j = 0 ; j < 4 ; j++ ) {

				static UINT TW5864_IN_SELECT_REG_TABLE_08CH[ 16 ] = { 0x00000004, 0x00000003, 0x00000008, 0x00000009, 0x00000005, 0x00000002, 0x0000000A, 0x0000000B, 0x00000006, 0x00000001, 0x0000000C, 0x0000000D, 0x00000007, 0x00000000, 0x0000000E, 0x0000000F };

				static UINT TW5864_IN_MAP_REG_TABLE_08CH[ 16 ]    = { 0x2AAAAAAA, 0x15555555, 0x00000000, 0x00000000, 0x2AAAAAAA, 0x15555555, 0x00000000, 0x00000000, 0x2AAAAAAA, 0x15555555, 0x00000000, 0x00000000, 0x2AAAAAAA, 0x15555555, 0x00000000, 0x00000000 }; // 釣線問題

				static UINT TW5864_IN_SELECT_REG_TABLE_04CH[ 16 ] = { 0x00000000, 0x00000004, 0x00000005, 0x00000006, 0x00000001, 0x00000007, 0x00000008, 0x00000009, 0x00000002, 0x0000000A, 0x0000000B, 0x0000000C, 0x00000003, 0x0000000D, 0x0000000E, 0x0000000F };

				static UINT TW5864_IN_MAP_REG_TABLE_04CH[ 16 ]    = { 0x3FFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x3FFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x3FFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x3FFFFFFF, 0x00000000, 0x00000000, 0x00000000 };
				
				static UINT TW5864_IN_SELECT_REG_TABLE[ 16 ];

				static UINT TW5864_IN_MAP_REG_TABLE[ 16 ];

				memcpy( TW5864_IN_SELECT_REG_TABLE, TW5864_IN_SELECT_REG_TABLE_04CH, sizeof(UINT) * 16 );

				memcpy( TW5864_IN_MAP_REG_TABLE, TW5864_IN_MAP_REG_TABLE_04CH, sizeof(UINT) * 16 );

				ULONG R00009200 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00009200 + (i * 4) );

				R00009200 |= (TW5864_IN_SELECT_REG_TABLE[ i * 4 + j ] & 0x0000000F) << (j * 4);

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009200 + (i * 4), R00009200 );

				UINT R00009100 = TW5864_IN_MAP_REG_TABLE[ i * 4 + j ];

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009100 + (i * 8 + j * 2 + 0) * (4), (R00009100 >>  0) & 0x0000FFFF );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009100 + (i * 8 + j * 2 + 1) * (4), (R00009100 >> 16) & 0x0000FFFF );
			}
			if( i < 2 ) { 
				
				ULONG R00000D00 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000D00 );

				R00000D00 |= 0x3C << ((i - 0) * 8); 
	
				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000D00, R00000D00 );
			}
			else { 
				
				ULONG R00000D04 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000D04 );

				R00000D04 |= 0x3C << ((i - 2) * 8);

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000D04, R00000D04 );
			}
			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) {

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000D10 + (i * 4) * 4, 720 - 1 );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000D14 + (i * 4) * 4, 720 - 1 );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000D18 + (i * 4) * 4, 480 - 1 );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000D1C + (i * 4) * 4, 480 - 1 );
			}
			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) {

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000D10 + (i * 4) * 4, 720 - 1 );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000D14 + (i * 4) * 4, 720 - 1 );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000D18 + (i * 4) * 4, 576 - 1 );

				b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000D1C + (i * 4) * 4, 576 - 1 );
			}
		}
		ULONG R00000D50 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000D50 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000D54, R00000D50 );

		// -----> UpdateEncodeParam() -----> EnableAllEncode() [2011.06.24]
		//
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000028, 0x0000FFFF );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009004, 0x0000000F );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00009000, 0x0000000F );

		a0c563aa017e45aa898479fcd6f672e2( pDevice );//com init

	}
	
	if( pVideo ) {

		c6c3937b81f94efaa887c881fbb5fb63( pDevice, pVideo );
	}

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 == 1 ) { 

		// ...
		pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = FALSE;
		
		writel( 0x0000FF77, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018004 );

		pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = TRUE;
		// ...
	}
	return TRUE;
}

BOOLEAN fae68fd0b91c4995ba7b2f17b5913633( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] fae68fd0b91c4995ba7b2f17b5913633()\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 == 0 ) return TRUE;
	
	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 1 ) {

		pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2--;

		return TRUE;
	}
//??
	writel( 0x00000000, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018004 );

	pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = FALSE;


	pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 = 0;

	f74f60e6b0814257af133a93b451d6b1( pDevice );//com uninit

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 0 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 2 ] = 0;

	pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 3 ] = 0;

	// -----> StopFPGA() -----> ISILH264FpgaEncoderEnableAD( DISABLE ) [2011.08.11]
	//
	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000028, 0x00000000 );

	// -----> StopFPGA() -----> ISILH264FpgaDisableAllPreview() [2011.08.11]
	//
	{	ULONG R00018004 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018004 ); 

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C004, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C008, 0x00000000 );

		ULONG i = 0 ;
		for( i = 0 ; i < 3000 ; i++ ) { 

			if( c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000C000 ) == 0x00000000 ) {

				break;
			}
		}
		for( i = 0 ; i < 4 ; i++ ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C200 + (i * 4), 0x00000000 ); }

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C020, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C024, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C02C, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018044, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018040, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C014, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C018, 0x00000000 );
	}

	// ...

	// ...
//	pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = FALSE;

//	writel( 0x00000000, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018004 );

//	pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = FALSE;

	a0c563aa017e45aa898479fcd6f672e2( pDevice );//com uninit

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] fae68fd0b91c4995ba7b2f17b5913633() real finish\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	return TW5864_PowerDownPeripherals( pDevice );
}


BOOLEAN e03518d16ae44460b3a1694ed56877f5( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] e03518d16ae44460b3a1694ed56877f5()  physical F760673FD1F8F4f22914515A9DC68C7C9(0x%x)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), virt_to_phys( pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ]) );


	pDevice->m_pCustomSystemConfigProperty = (TW5864_SYS_CFG *)kmalloc( sizeof(TW5864_SYS_CFG), GFP_KERNEL );

	if(pDevice->m_pCustomSystemConfigProperty == NULL)
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "e03518d16ae44460b3a1694ed56877f5() can not allocate TW5864_SYS_CFG, error\n" );

		return TRUE;
	}

	memset( pDevice->m_pCustomSystemConfigProperty, 0, sizeof(TW5864_SYS_CFG) );

	ULONG R0000A01C = 0x00000000;

	// -----> PCI5864_DDRSizeAutoDetect() [2011.03.28]
	//
	//watson
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000801C, 0x0000000D );
		
		schedule_timeout_interruptible( msecs_to_jiffies( 20 ) );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000801C, 0x00000000 );
		
		schedule_timeout_interruptible( msecs_to_jiffies( 20 ) );

	{	ULONG R00000004 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000004 );

		ULONG R0000880C = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000880C );

		ULONG R00000008 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000008 );

		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, 0x00003B98, 0x00000001 );

		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, 0x00003B9C, 0x00000001 );

		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, 0x00003BA0, 0x00000001 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000880C, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000008, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000004, 0x00000001 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00008808, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000A01C, 0x00000005 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000030, (0x00000000) | (0x00004000 * 0) );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + 0x00000000, 0x53B927A6 ); // DDR_PAGE_OFFSET = 0x00080000

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + 0x00000400, 0xC6A37E4B ); // DDR_PAGE_OFFSET = 0x00080000

		schedule_timeout_interruptible( msecs_to_jiffies( 20 ) );

		ULONG DDR = (c3c09a67df944bec9b42209724048dc4( pDevice, 0x00080000 + 0x00000000 ) == 0xC6A37E4B) ? 256 : 512; // DDR_PAGE_OFFSET = 0x00080000

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000004, R00000004 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00008808, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000880C, R0000880C );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000008, R00000008 );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO,"e03518d16ae44460b3a1694ed56877f5( %d, DDR.MEMORY.%dMB )\n", pDevice->FF362AA37F7D046bf90568AC1600626D9, DDR);

//		if( DDR == 256 ) {
//
		if( 1 ) {

			R0000A01C = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000A01C );

			R0000A01C &= ~3;

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000A01C, R0000A01C );

			R0000A01C = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000A01C );

			R0000A01C &= ~3;

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000A01C, R0000A01C );
		}
		else {

			R0000A01C = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000A01C );

			R0000A01C &= ~3;

			R0000A01C |=  1;

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000A01C, R0000A01C );

			R0000A01C = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000A01C );

			R0000A01C &= ~3;

			R0000A01C |=  1;

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000A01C, R0000A01C );
		}
	}

	// -----> InitISIL5864() [2011.08.11]
	// 
	{	ULONG R0000B004 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000B004 );

		if( R0000B004 >= 0x0000C012 ) {
			
			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00008018, 0x0000D000 + (175 << 1) - (1) );
		}
		else {

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00008018, 0x0000D000 + (185 << 1) - (1) );
		}
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00008020, 0x00000284 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00008024, 0x00000020 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000801C, 0x0000000D );

		schedule_timeout_interruptible( msecs_to_jiffies( 20 ) );
	}

	// -----> InitFPGA() -----> ISILH264FpgaEncoderOpen() [2011.08.11]
	// 
	{	ULONG R0000B004 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000B004 );

		if( R0000B004 >= 0x0000C012 ) {

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018004, 0x00000000 ); // H.P.LIN: 0x000000F7 -> 0x00000000

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0001800C, 0x000003B2 ); // H.P.LIN: 0x000003A2 -> 0x000003B2

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000604, 0x00000020 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018054, 0x00000003 );

		//	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018064, 0x0300016F ); // ????? (TO SOLVE PREVIEW DROP FRAME ISSUE)

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018020, ba98f190f54d44ba894e79c3bc107b50 - 64 ); // ENCODE_IO_BUF_SIZE

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00020000, 0x00FF03FF );
		}
		else {

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018004, 0x00000000 ); // H.P.LIN: 0x00000077 -> 0x00000000

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000604, 0x00000000 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0001800C, 0x00000132 ); // H.P.LIN: 0x00000122 -> 0x00000132

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00020000, 0x00C003CF );
		}
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000A000, 0x000000C5 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000A800, 0x000000C5 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00008028, 0x00000015 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000801C, 0x00000018 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000801C, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00008000, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000014, (1 << 3) + (1) );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000028, 0x0000FFFF );

		static const UINT TW5864_FORWARD_QUANTIZATION_TABLE[ 96 ] = {

			0x3333, 0x1f82, 0x3333, 0x1F82, 0x1F82, 0x147B, 0x1F82, 0x147B, 0x3333, 0x1F82, 
			0x3333, 0x1F82, 0x1F82, 0x147B, 0x1F82, 0x147B, 0x2E8C, 0x1D42, 0x2E8C, 0x1D42,
			0x1D42, 0x1234, 0x1D42, 0x1234, 0x2E8C, 0x1D42, 0x2E8C, 0x1D42, 0x1D42, 0x1234,
			0x1D42, 0x1234, 0x2762, 0x199A, 0x2762, 0x199A, 0x199A, 0x1062, 0x199A, 0x1062,
			0x2762, 0x199A, 0x2762, 0x199A, 0x199A, 0x1062, 0x199A, 0x1062, 0x2492, 0x16C1,
			0x2492, 0x16C1, 0x16C1, 0x0E3F, 0x16C1, 0x0E3F, 0x2492, 0x16C1, 0x2492, 0x16C1,
			0x16C1, 0x0E3F, 0x16C1, 0x0E3F, 0x2000, 0x147B, 0x2000, 0x147B, 0x147B, 0x0D1B,
			0x147B, 0x0D1B, 0x2000, 0x147B, 0x2000, 0x147B, 0x147B, 0x0D1B, 0x147B, 0x0D1B,
			0x1C72, 0x11CF, 0x1C72, 0x11CF, 0x11CF, 0x0B4D, 0x11CF, 0x0B4D, 0x1C72, 0x11CF,
			0x1C72, 0x11CF, 0x11CF, 0x0B4D, 0x11CF, 0x0B4D 
		};
		static const UINT TW5864_INVERSE_QUANTIZATION_TABLE[ 96 ] =
		{
			0x800A, 0x800D, 0x800A, 0x800D, 0x800D, 0x8010, 0x800D, 0x8010, 0x800A, 0x800D, 
			0x800A, 0x800D, 0x800D, 0x8010, 0x800D, 0x8010, 0x800B, 0x800E, 0x800B, 0x800E,
			0x800E, 0x8012, 0x800E, 0x8012, 0x800B, 0x800E, 0x800B, 0x800E, 0x800E, 0x8012,
			0x800E, 0x8012, 0x800D, 0x8010, 0x800D, 0x8010, 0x8010, 0x8014, 0x8010, 0x8014,
			0x800D, 0x8010, 0x800D, 0x8010, 0x8010, 0x8014, 0x8010, 0x8014, 0x800E, 0x8012,
			0x800E, 0x8012, 0x8012, 0x8017, 0x8012, 0x8017, 0x800E, 0x8012, 0x800E, 0x8012,
			0x8012, 0x8017, 0x8012, 0x8017, 0x8010, 0x8014, 0x8010, 0x8014, 0x8014, 0x8019,
			0x8014, 0x8019, 0x8010, 0x8014, 0x8010, 0x8014, 0x8014, 0x8019, 0x8014, 0x8019,
			0x8012, 0x8017, 0x8012, 0x8017, 0x8017, 0x801D, 0x8017, 0x801D, 0x8012, 0x8017,
			0x8012, 0x8017, 0x8017, 0x801D, 0x8017, 0x801D
		};
		ULONG i = 0 ;

		for( i = 0 ; i < 96 ; i++ ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000800 + i * 4, TW5864_FORWARD_QUANTIZATION_TABLE[ i ] ); }

		for( i = 0 ; i < 96 ; i++ ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000800 + i * 4, TW5864_INVERSE_QUANTIZATION_TABLE[ i ] ); }

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000040C, 0x00000018 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000020, 0x00000440 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000024, 0x00000440 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000020C, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000204, 0x00000189 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000001C, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000410, 0x00000060 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000002C, 0x00000320 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000208, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000A008, 0x00000003 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000A808, 0x00000003 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0001804C, 0x00000000 ); // H.P.LIN: 0x02 (4MS) -> 0x00 (1MS)

//		ULONG memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 1 ]; // 56789
//peter[2011.06.03]
		ULONG memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 4 ]; // 56789

		for( i = 0 ; i < 32 ; i++ ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018080 + i * 4, memory_F6F32B5439E4C42f095E08326DFA73107 ); }

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000004, 0x00000040 | 0x00000010 | 0x00000008 | 0x00000004 | 0x00000002 | 0x00000001 );

		ULONG R00000004 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000004 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000004, R00000004 | 0x00000005 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000200, 0x00000006 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000040, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018084, memory_F6F32B5439E4C42f095E08326DFA73107 + (ba98f190f54d44ba894e79c3bc107b50) - (64 * 1024) ); // MOTION_VECTOR_BUF_OFFSET

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000018, 26 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00008808, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000880C, 0x0000FFFF );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00008820, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00004000, 0x00006978 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00004004, 0x00000006 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00004008, 0x800CFFFF );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000404C, 0x00010000 );
	}

	// -----> InitFPGA() -----> ISILH264FpgaInitAudio() [2011.03.04]
	// 
	{	ULONG memory_size = 2048 * 4 * 2; // WHOLE_AUDIO_PREVIEW_BUF_SIZE

		ULONG memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D[ 4 ] + ba98f190f54d44ba894e79c3bc107b50 - (memory_size) - (4096); // 56789

		ULONG i = 0 ;
		for( i = 0 ; i < 4 ; i++ ) {

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x000180A0 + (i * 2 + 0) * 4, memory_F6F32B5439E4C42f095E08326DFA73107 +               (0) );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x000180A0 + (i * 2 + 1) * 4, memory_F6F32B5439E4C42f095E08326DFA73107 + (memory_size / 2) );

			memory_F6F32B5439E4C42f095E08326DFA73107 += ((memory_size / 2) / 4);
		}
	}
	// -----> InitISIL2864() [2011.08.11]
	// 
	{	c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000062 << 2), 0x00000003 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000064 << 2), 0x00000031 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000065 << 2), 0x00000075 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000066 << 2), 0x000000B9 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000067 << 2), 0x000000FD );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000068 << 2), 0x00000020 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000069 << 2), 0x00000064 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000006A << 2), 0x000000A8 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000006B << 2), 0x000000EC );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000000DF << 2), 0x00000004 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000000DD << 2), 0x000000C0 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000006C << 2), 0x000000F1 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000071 << 2), 0x00000010 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000000E3 << 2), 0x00000040 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000075 << 2), 0x000000E4 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000076 << 2), 0x00000022 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000077 << 2), 0x0000000C );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000078 << 2), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000079 << 2), 0x000000C8 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000007A << 2), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000060 << 2), 0x00000033 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000061 << 2), 0x00000033 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000004 << 2), 0x00000005 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000014 << 2), 0x00000005 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000024 << 2), 0x00000005 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000034 << 2), 0x00000005 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000000F3 << 2), 0x000000E4 );
	}

	// -----> techwell_config() [2011.08.11]
	// 
	{	ULONG R0000B004 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000B004 );

		if( R0000B004 >= 0x0000C012 ) {
	
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003B98 << 0), 0x00000002 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003B9C << 0), 0x00000002 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003BA0 << 0), 0x00000002 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003BAC << 0), 0x00000002 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003BB0 << 0), 0x00000002 );
			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003BB4 << 0), 0x00000002 );
		}
		else {

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003B98 << 0), 0x00000001 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003B9C << 0), 0x00000001 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003BA0 << 0), 0x00000001 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003BAC << 0), 0x00000001 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003BB0 << 0), 0x00000001 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003BB4 << 0), 0x00000001 );
		}
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000EEC << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000EE8 << 0), 0x00000003 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003BC0 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003BC0 << 0), 0x000000E0 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003BF0 << 0), 0x000000F0 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000900 << 0), 0x00000020 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000904 << 0), 0x00000021 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000908 << 0), 0x00000022 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000090C << 0), 0x00000023 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000910 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000914 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000918 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0000091C << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000920 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000980 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000E00 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000E04 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FF8 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000F80 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000F84 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000F88 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000F8C << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000F90 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000F94 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000F98 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000F9C << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FA0 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FA4 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FA8 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FAC << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FB0 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FB4 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FB8 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FBC << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FC0 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FC4 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FC8 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FCC << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FD0 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FD4 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FD8 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FDC << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000FF8 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00003BF4 << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000EEC << 0), 0x00000000 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x00000EE8 << 0), 0x00000005 );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000002D8 << 2), 0x000000FF );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000002D9 << 2), 0x000000FF );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000002DA << 2), 0x000000FF );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000002DB << 2), 0x000000FF );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000002DC << 2), 0x000000FF );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000002DD << 2), 0x000000FF );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000002DE << 2), 0x000000FF );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000002DF << 2), 0x000000FF );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000002E8 << 2), 0x000000FF );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000002E9 << 2), 0x000000FF );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000002EA << 2), 0x000000FF );
		c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000002EB << 2), 0x000000FF );
	}

	// -----> InitRam() [2011.08.11]
	// 
	{	ULONG R0000B004 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000B004 );

	//	if( R0000B004 >= 0x0000C012 ) { [移除]
	//
	//		ULONG memory_F6F32B5439E4C42f095E08326DFA73107 = pDevice->FA81F93DB0A8D49bdBC3753334A5D581D.LowPart + AMEBDAD_MAX_VIDEO_DMA_BUFFER_SIZE + AMEBDAD_MAX_AUDIO_DMA_BUFFER_SIZE;
	//	
	//		memory_F6F32B5439E4C42f095E08326DFA73107 += 62280; // GRAB_BUF_SIZE
	//
	//		memory_F6F32B5439E4C42f095E08326DFA73107 += 1638400; // MJPEG_BUF_SIZE
	//
	//		for( ULONG i = 0 ; i < 32 ; i++ ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018180 + i * 4, memory_F6F32B5439E4C42f095E08326DFA73107 + (i * 64 * 4) ); } // MVFLAG_BUF_SIZE
	//	}

		static const USHORT TW5864_VLC_INIT_DATA[ 1024 ] = {

			0x0011, 0x0000, 0x0000, 0x0000, 0x0065, 0x0021, 0x0000, 0x0000, 0x0087, 0x0064, 0x0031, 0x0000,
			0x0097, 0x0086, 0x0075, 0x0053, 0x00A7, 0x0096, 0x0085, 0x0063, 0x00B7, 0x00A6, 0x0095, 0x0074,
			0x00DF, 0x00B6, 0x00A5, 0x0084, 0x00DB, 0x00DE, 0x00B5, 0x0094, 0x00D8, 0x00DA, 0x00DD, 0x00A4,
			0x00EF, 0x00EE, 0x00D9, 0x00B4, 0x00EB, 0x00EA, 0x00ED, 0x00DC, 0x00FF, 0x00FE, 0x00E9, 0x00EC,
			0x00FB, 0x00FA, 0x00FD, 0x00E8, 0x010F, 0x00F1, 0x00F9, 0x00FC, 0x010B, 0x010E, 0x010D, 0x00F8,
			0x0107, 0x010A, 0x0109, 0x010C, 0x0104, 0x0106, 0x0105, 0x0108, 0x0023, 0x0000, 0x0000, 0x0000,
			0x006B, 0x0022, 0x0000, 0x0000, 0x0067, 0x0057, 0x0033, 0x0000, 0x0077, 0x006A, 0x0069, 0x0045,
			0x0087, 0x0066, 0x0065, 0x0044, 0x0084, 0x0076, 0x0075, 0x0056, 0x0097, 0x0086, 0x0085, 0x0068,
			0x00BF, 0x0096, 0x0095, 0x0064, 0x00BB, 0x00BE, 0x00BD, 0x0074, 0x00CF, 0x00BA, 0x00B9, 0x0094,
			0x00CB, 0x00CE, 0x00CD, 0x00BC, 0x00C8, 0x00CA, 0x00C9, 0x00B8, 0x00DF, 0x00DE, 0x00DD, 0x00CC,
			0x00DB, 0x00DA, 0x00D9, 0x00DC, 0x00D7, 0x00EB, 0x00D6, 0x00D8, 0x00E9, 0x00E8, 0x00EA, 0x00D1,
			0x00E7, 0x00E6, 0x00E5, 0x00E4, 0x004F, 0x0000, 0x0000, 0x0000, 0x006F, 0x004E, 0x0000, 0x0000,
			0x006B, 0x005F, 0x004D, 0x0000, 0x0068, 0x005C, 0x005E, 0x004C, 0x007F, 0x005A, 0x005B, 0x004B,
			0x007B, 0x0058, 0x0059, 0x004A, 0x0079, 0x006E, 0x006D, 0x0049, 0x0078, 0x006A, 0x0069, 0x0048,
			0x008F, 0x007E, 0x007D, 0x005D, 0x008B, 0x008E, 0x007A, 0x006C, 0x009F, 0x008A, 0x008D, 0x007C,
			0x009B, 0x009E, 0x0089, 0x008C, 0x0098, 0x009A, 0x009D, 0x0088, 0x00AD, 0x0097, 0x0099, 0x009C,
			0x00A9, 0x00AC, 0x00AB, 0x00AA, 0x00A5, 0x00A8, 0x00A7, 0x00A6, 0x00A1, 0x00A4, 0x00A3, 0x00A2,
			0x0021, 0x0000, 0x0000, 0x0000, 0x0067, 0x0011, 0x0000, 0x0000, 0x0064, 0x0066, 0x0031, 0x0000,
			0x0063, 0x0073, 0x0072, 0x0065, 0x0062, 0x0083, 0x0082, 0x0070, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0011, 0x0010, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0011, 0x0021, 0x0020, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0022, 0x0021, 0x0020,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0023, 0x0022, 0x0021, 0x0031, 0x0030, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0022, 0x0033, 0x0032, 0x0031, 0x0030, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0023, 0x0030, 0x0031, 0x0033,
			0x0032, 0x0035, 0x0034, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0037, 0x0036, 0x0035, 0x0034, 0x0033, 0x0032, 0x0031, 0x0041, 0x0051, 0x0061, 0x0071, 0x0081,
			0x0091, 0x00A1, 0x00B1, 0x0000, 0x0002, 0x0000, 0x00E4, 0x0011, 0x00F4, 0x0002, 0x0024, 0x0003,
			0x0005, 0x0012, 0x0034, 0x0013, 0x0065, 0x0024, 0x0013, 0x0063, 0x0015, 0x0022, 0x0075, 0x0034,
			0x0044, 0x0023, 0x0023, 0x0073, 0x0054, 0x0033, 0x0033, 0x0004, 0x0043, 0x0014, 0x0011, 0x0043,
			0x0014, 0x0001, 0x0025, 0x0015, 0x0035, 0x0025, 0x0064, 0x0055, 0x0045, 0x0035, 0x0074, 0x0065,
			0x0085, 0x00D5, 0x0012, 0x0095, 0x0055, 0x0045, 0x0095, 0x00E5, 0x0084, 0x0075, 0x0022, 0x00A5,
			0x0094, 0x0085, 0x0032, 0x00B5, 0x0003, 0x00C5, 0x0001, 0x0044, 0x00A5, 0x0032, 0x00B5, 0x0094,
			0x00C5, 0x00A4, 0x00A4, 0x0054, 0x00D5, 0x00B4, 0x00B4, 0x0064, 0x00F5, 0x00F5, 0x0053, 0x00D4,
			0x00E5, 0x00C4, 0x0105, 0x0105, 0x00C4, 0x0074, 0x0063, 0x00E4, 0x00D4, 0x0084, 0x0073, 0x00F4,
			0x0004, 0x0005, 0x0000, 0x0053, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0011, 0x0021, 0x0031, 0x0030, 0x0011, 0x0021, 0x0020, 0x0000,
			0x0011, 0x0010, 0x0000, 0x0000, 0x0011, 0x0033, 0x0032, 0x0043, 0x0042, 0x0053, 0x0052, 0x0063,
			0x0062, 0x0073, 0x0072, 0x0083, 0x0082, 0x0093, 0x0092, 0x0091, 0x0037, 0x0036, 0x0035, 0x0034,
			0x0033, 0x0045, 0x0044, 0x0043, 0x0042, 0x0053, 0x0052, 0x0063, 0x0062, 0x0061, 0x0060, 0x0000,
			0x0045, 0x0037, 0x0036, 0x0035, 0x0044, 0x0043, 0x0034, 0x0033, 0x0042, 0x0053, 0x0052, 0x0061,
			0x0051, 0x0060, 0x0000, 0x0000, 0x0053, 0x0037, 0x0045, 0x0044, 0x0036, 0x0035, 0x0034, 0x0043,
			0x0033, 0x0042, 0x0052, 0x0051, 0x0050, 0x0000, 0x0000, 0x0000, 0x0045, 0x0044, 0x0043, 0x0037,
			0x0036, 0x0035, 0x0034, 0x0033, 0x0042, 0x0051, 0x0041, 0x0050, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0061, 0x0051, 0x0037, 0x0036, 0x0035, 0x0034, 0x0033, 0x0032, 0x0041, 0x0031, 0x0060, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0061, 0x0051, 0x0035, 0x0034, 0x0033, 0x0023, 0x0032, 0x0041,
			0x0031, 0x0060, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0061, 0x0041, 0x0051, 0x0033,
			0x0023, 0x0022, 0x0032, 0x0031, 0x0060, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0061, 0x0060, 0x0041, 0x0023, 0x0022, 0x0031, 0x0021, 0x0051, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0051, 0x0050, 0x0031, 0x0023, 0x0022, 0x0021, 0x0041, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0040, 0x0041, 0x0031, 0x0032,
			0x0011, 0x0033, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0040, 0x0041, 0x0021, 0x0011, 0x0031, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0030, 0x0031, 0x0011, 0x0021, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0020, 0x0021, 0x0011, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0010, 0x0011, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000,        
		};
		static const USHORT TW5864_RAM_CONB_CONVERT[ 2048 ] = {

			0x0197, 0x0162, 0x0000, 0x001F, 0x0004, 0x013F, 0x0002, 0x011F, 0x0002, 0x003F, 0x0103, 0x0154,
			0x0002, 0x011F, 0x0002, 0x003F, 0x0106, 0x0150, 0x0197, 0x0162, 0x013A, 0x0162, 0x01F8, 0x003F,
			0x0113, 0x0154, 0x0170, 0x0161, 0x01F8, 0x003F, 0x0113, 0x0154, 0x0001, 0x001F, 0x0004, 0x013F,
			0x0103, 0x0140, 0x0000, 0x001F, 0x0004, 0x013F, 0x0103, 0x0140, 0x0001, 0x0003, 0x0023, 0x0002,
			0x0045, 0x0001, 0x0067, 0x0000, 0x0089, 0x0007, 0x00AB, 0x0006, 0x00CD, 0x0005, 0x00EF, 0x0004,
			0x00FE, 0x000B, 0x00DC, 0x000A, 0x00BA, 0x0009, 0x0098, 0x0008, 0x0076, 0x000F, 0x0054, 0x000E,
			0x0032, 0x000D, 0x0010, 0x000C, 0x00F0, 0x0013, 0x00E1, 0x0012, 0x00D2, 0x0011, 0x00C3, 0x0010,
			0x0014, 0x001D, 0x0138, 0x001F, 0x00FF, 0x007F, 0x0178, 0x003F, 0x0138, 0x0017, 0x0158, 0x0037,
			0x01F8, 0x0057, 0x0130, 0x001F, 0x00FF, 0x007F, 0x0170, 0x003F, 0x0130, 0x0016, 0x0150, 0x0036,
			0x01F8, 0x0056, 0x0128, 0x001F, 0x00FF, 0x007F, 0x0168, 0x003F, 0x0128, 0x0015, 0x0148, 0x0035,
			0x01F8, 0x0055, 0x0120, 0x001F, 0x00FF, 0x007F, 0x0160, 0x003F, 0x0120, 0x0014, 0x0140, 0x0034,
			0x01F8, 0x0054, 0x0099, 0x0097, 0x0079, 0x00B6, 0x0082, 0x00B5, 0x005A, 0x00B4, 0x019B, 0x0160,
			0x0001, 0x00DD, 0x012B, 0x0154, 0x0014, 0x001D, 0x0138, 0x0017, 0x0158, 0x0077, 0x0178, 0x0077,
			0x0130, 0x0016, 0x0150, 0x0076, 0x0170, 0x0076, 0x0128, 0x0015, 0x0148, 0x0075, 0x0168, 0x0075,
			0x0120, 0x0014, 0x0140, 0x0074, 0x0160, 0x0074, 0x00A1, 0x0097, 0x00EB, 0x00B6, 0x00D9, 0x00B5,
			0x006E, 0x00B4, 0x019B, 0x0160, 0x0001, 0x00DD, 0x014B, 0x0154, 0x0014, 0x001D, 0x0138, 0x0017,
			0x0158, 0x0037, 0x0138, 0x001F, 0x0178, 0x003F, 0x01F8, 0x0057, 0x0158, 0x001F, 0x0178, 0x003F,
			0x01F8, 0x0057, 0x0130, 0x0016, 0x0150, 0x0036, 0x0130, 0x001F, 0x0170, 0x003F, 0x01F8, 0x0056,
			0x0150, 0x001F, 0x0170, 0x003F, 0x01F8, 0x0056, 0x0128, 0x0015, 0x0148, 0x0035, 0x0128, 0x001F,
			0x0168, 0x003F, 0x01F8, 0x0055, 0x0148, 0x001F, 0x0168, 0x003F, 0x01F8, 0x0055, 0x0120, 0x0014,
			0x0140, 0x0034, 0x0120, 0x001F, 0x0160, 0x003F, 0x01F8, 0x0054, 0x0140, 0x001F, 0x0160, 0x003F,
			0x01F8, 0x0054, 0x00DC, 0x0097, 0x00BC, 0x00B6, 0x001B, 0x00B5, 0x008F, 0x00B4, 0x019B, 0x0160,
			0x0001, 0x00DD, 0x015F, 0x0154, 0x0014, 0x001D, 0x0138, 0x0017, 0x0158, 0x0077, 0x0178, 0x0077,
			0x0130, 0x0016, 0x0150, 0x0076, 0x0170, 0x0076, 0x0128, 0x0015, 0x0148, 0x0075, 0x0168, 0x0075,
			0x0120, 0x0014, 0x0140, 0x0074, 0x0160, 0x0074, 0x00D6, 0x0097, 0x00C1, 0x00B6, 0x0062, 0x00B5,
			0x00CA, 0x00B4, 0x019B, 0x0160, 0x0001, 0x00DD, 0x0187, 0x0154, 0x0000, 0x0140, 0x0198, 0x0097,
			0x0190, 0x00B6, 0x0188, 0x00B5, 0x0180, 0x00B4, 0x0178, 0x0013, 0x0170, 0x0012, 0x0168, 0x0011,
			0x0160, 0x0010, 0x0158, 0x000F, 0x0150, 0x000E, 0x0148, 0x000D, 0x0140, 0x000C, 0x0002, 0x001E,
			0x000C, 0x0187, 0x0002, 0x0187, 0x0008, 0x0184, 0x0008, 0x0185, 0x0008, 0x0186, 0x0008, 0x0187,
			0x0001, 0x00DE, 0x01A8, 0x0154, 0x0138, 0x000B, 0x0130, 0x000A, 0x0128, 0x0009, 0x0120, 0x0008,
			0x0118, 0x0007, 0x0110, 0x0006, 0x0108, 0x0005, 0x0100, 0x0004, 0x0005, 0x001E, 0x0006, 0x0183,
			0x0000, 0x0182, 0x0000, 0x0181, 0x0000, 0x0180, 0x0000, 0x00A3, 0x0001, 0x00DE, 0x01B9, 0x0154,
			0x01B8, 0x0083, 0x01B0, 0x00A2, 0x01A8, 0x00A1, 0x01A0, 0x00A0, 0x0083, 0x0117, 0x0082, 0x0116,
			0x0081, 0x0115, 0x0080, 0x0114, 0x01B8, 0x0083, 0x01B0, 0x00A2, 0x01A8, 0x00A1, 0x01A0, 0x00A0,
			0x008B, 0x011F, 0x01F8, 0x0077, 0x008A, 0x011F, 0x01F8, 0x0076, 0x0089, 0x011F, 0x01F8, 0x0075,
			0x0088, 0x011F, 0x01F8, 0x0074, 0x00A3, 0x011F, 0x01F8, 0x0077, 0x00A2, 0x011F, 0x01F8, 0x0076,
			0x00A1, 0x011F, 0x01F8, 0x0075, 0x00A0, 0x011F, 0x01F8, 0x0074, 0x00B7, 0x011F, 0x01F8, 0x0077,
			0x00B6, 0x011F, 0x01F8, 0x0076, 0x00B5, 0x011F, 0x01F8, 0x0075, 0x00B4, 0x011F, 0x01F8, 0x0074,
			0x0006, 0x0197, 0x0000, 0x0196, 0x0000, 0x0195, 0x0000, 0x0194, 0x0000, 0x00B7, 0x00C4, 0x001E,
			0x00C0, 0x009E, 0x01F0, 0x011F, 0x0004, 0x00DE, 0x01F0, 0x013F, 0x00BB, 0x00DE, 0x01EA, 0x0154,
			0x00BF, 0x0137, 0x00BE, 0x0136, 0x00BD, 0x0135, 0x00BC, 0x0134, 0x0000, 0x0140, 0x0033, 0x001F,
			0x016C, 0x0162, 0x0000, 0x0017, 0x00F8, 0x001D, 0x00C8, 0x009D, 0x0162, 0x0162, 0x01E8, 0x013F,
			0x0008, 0x001E, 0x000C, 0x019F, 0x0100, 0x015D, 0x0080, 0x0077, 0x0006, 0x0197, 0x0103, 0x015D,
			0x0031, 0x0077, 0x0001, 0x00DE, 0x01FD, 0x0154, 0x00C7, 0x00DD, 0x01F9, 0x0154, 0x0000, 0x0140,
			0x016B, 0x0162, 0x000F, 0x001F, 0x0163, 0x0162, 0x0002, 0x0016, 0x0020, 0x0017, 0x00D2, 0x011F,
			0x0131, 0x0161, 0x0163, 0x0162, 0x00D3, 0x011F, 0x0131, 0x0161, 0x0163, 0x0162, 0x00F8, 0x001D,
			0x00D0, 0x009D, 0x01E8, 0x011F, 0x0131, 0x0161, 0x0163, 0x0162, 0x00CF, 0x00DD, 0x0114, 0x0155,
			0x0162, 0x0162, 0x00FF, 0x007F, 0x0131, 0x0161, 0x0162, 0x0162, 0x00FF, 0x007F, 0x0131, 0x0141,
			0x016B, 0x0162, 0x00AA, 0x001F, 0x0163, 0x0162, 0x0001, 0x0016, 0x00FE, 0x0017, 0x00F5, 0x001D,
			0x00E0, 0x009D, 0x0162, 0x0162, 0x01E8, 0x013F, 0x0131, 0x0161, 0x00DF, 0x00DD, 0x0126, 0x0155,
			0x0162, 0x0162, 0x00FF, 0x007F, 0x0131, 0x0161, 0x0162, 0x0162, 0x00FF, 0x007F, 0x0008, 0x001E,
			0x000C, 0x019F, 0x0135, 0x015D, 0x0080, 0x0076, 0x0006, 0x0197, 0x0000, 0x0196, 0x013A, 0x015D,
			0x0080, 0x0076, 0x0005, 0x0077, 0x0001, 0x00DE, 0x0132, 0x0155, 0x0000, 0x0140, 0x016B, 0x0162,
			0x00A5, 0x001F, 0x0163, 0x0162, 0x0003, 0x0016, 0x00DE, 0x0017, 0x00D5, 0x011F, 0x0131, 0x0161,
			0x0163, 0x0162, 0x00D6, 0x011F, 0x0131, 0x0161, 0x0163, 0x0162, 0x0021, 0x001D, 0x0162, 0x0162,
			0x0131, 0x0161, 0x0001, 0x00DD, 0x0149, 0x0155, 0x0162, 0x0162, 0x00FF, 0x007F, 0x0131, 0x0161,
			0x0162, 0x0162, 0x00FF, 0x007F, 0x0131, 0x0161, 0x00D0, 0x0137, 0x00D1, 0x0136, 0x0000, 0x0016,
			0x0000, 0x0017, 0x0008, 0x001D, 0x00FA, 0x001B, 0x019F, 0x0162, 0x0001, 0x00DD, 0x0158, 0x0155,
			0x00EC, 0x001D, 0x0094, 0x009D, 0x0162, 0x0162, 0x0131, 0x0161, 0x01E8, 0x013F, 0x0093, 0x00DD,
			0x015D, 0x0155, 0x0162, 0x0162, 0x00FF, 0x007F, 0x0131, 0x0161, 0x0162, 0x0162, 0x00FF, 0x007F,
			0x0131, 0x0161, 0x0094, 0x0137, 0x0095, 0x0136, 0x0162, 0x0162, 0x0096, 0x013F, 0x0162, 0x0162,
			0x0097, 0x013F, 0x0000, 0x0140, 0x01F5, 0x0160, 0x0103, 0x0162, 0x0008, 0x011F, 0x0080, 0x013F,
			0x0009, 0x011F, 0x0081, 0x013F, 0x000A, 0x011F, 0x0082, 0x013F, 0x000B, 0x011F, 0x0083, 0x013F,
			0x000C, 0x011F, 0x00B0, 0x013F, 0x000D, 0x011F, 0x00B1, 0x013F, 0x000E, 0x011F, 0x00B2, 0x013F,
			0x000F, 0x011F, 0x00B3, 0x013F, 0x0118, 0x0162, 0x00C0, 0x011F, 0x003F, 0x003F, 0x00A8, 0x013F,
			0x00C1, 0x011F, 0x00A9, 0x013F, 0x00C2, 0x011F, 0x00AA, 0x013F, 0x00C3, 0x011F, 0x00AB, 0x013F,
			0x00C4, 0x011F, 0x00AC, 0x013F, 0x00C5, 0x011F, 0x00AD, 0x013F, 0x00C6, 0x011F, 0x00AE, 0x013F,
			0x00C7, 0x011F, 0x00AF, 0x013F, 0x0116, 0x0160, 0x0080, 0x001F, 0x00D2, 0x013F, 0x0000, 0x001F,
			0x00D3, 0x013F, 0x00F8, 0x001D, 0x00D0, 0x009D, 0x0003, 0x011F, 0x01E8, 0x013F, 0x00CF, 0x00DD,
			0x019A, 0x0155, 0x0108, 0x0161, 0x01F5, 0x0160, 0x0103, 0x0162, 0x0080, 0x0133, 0x0081, 0x0132,
			0x0082, 0x0131, 0x0083, 0x0130, 0x00B0, 0x012F, 0x00B1, 0x012E, 0x00B2, 0x012D, 0x00B3, 0x012C,
			0x0040, 0x001F, 0x00A8, 0x013F, 0x00C0, 0x011F, 0x00A9, 0x013F, 0x00C1, 0x011F, 0x00AA, 0x013F,
			0x00C2, 0x011F, 0x00AB, 0x013F, 0x00C3, 0x011F, 0x00AC, 0x013F, 0x00C4, 0x011F, 0x00AD, 0x013F,
			0x00C5, 0x011F, 0x00AE, 0x013F, 0x00C6, 0x011F, 0x00AF, 0x013F, 0x00CA, 0x011F, 0x00A4, 0x013F,
			0x00CB, 0x011F, 0x00A5, 0x013F, 0x00CC, 0x011F, 0x00B4, 0x013F, 0x00CD, 0x011F, 0x00B5, 0x013F,
			0x00CE, 0x011F, 0x00B6, 0x013F, 0x0116, 0x0160, 0x013D, 0x0161, 0x0093, 0x011F, 0x0100, 0x007F,
			0x01F8, 0x0017, 0x0092, 0x011F, 0x0108, 0x007F, 0x01F8, 0x0057, 0x0091, 0x011F, 0x0110, 0x007F,
			0x01F8, 0x0057, 0x0090, 0x011F, 0x0118, 0x007F, 0x01F8, 0x0057, 0x008F, 0x011F, 0x0120, 0x007F,
			0x01F8, 0x0057, 0x008E, 0x011F, 0x0128, 0x007F, 0x01F8, 0x0057, 0x008D, 0x011F, 0x0130, 0x007F,
			0x01F8, 0x0057, 0x008C, 0x011F, 0x0138, 0x007F, 0x01F8, 0x0057, 0x008B, 0x011F, 0x0140, 0x007F,
			0x01F8, 0x0057, 0x008A, 0x011F, 0x0148, 0x007F, 0x01F8, 0x0057, 0x0089, 0x011F, 0x0150, 0x007F,
			0x01F8, 0x0057, 0x0088, 0x011F, 0x0158, 0x007F, 0x01F8, 0x0057, 0x0087, 0x011F, 0x0160, 0x007F,
			0x01F8, 0x0057, 0x0086, 0x011F, 0x0168, 0x007F, 0x01F8, 0x0057, 0x0085, 0x011F, 0x0170, 0x007F,
			0x01F8, 0x0057, 0x0084, 0x011F, 0x0178, 0x007F, 0x01F8, 0x0057, 0x0083, 0x011F, 0x0180, 0x007F,
			0x01F8, 0x0057, 0x0082, 0x011F, 0x0188, 0x007F, 0x01F8, 0x0057, 0x0081, 0x011F, 0x0190, 0x007F,
			0x01F8, 0x0057, 0x0080, 0x011F, 0x0198, 0x007F, 0x01B8, 0x005F, 0x0000, 0x0140, 0x0000, 0x001F,
			0x00C0, 0x001E, 0x00C0, 0x009E, 0x01F0, 0x013F, 0x00BF, 0x00DE, 0x0105, 0x0156, 0x00FF, 0x001F,
			0x00A4, 0x013F, 0x00A5, 0x013F, 0x00A6, 0x013F, 0x00A7, 0x013F, 0x00B4, 0x013F, 0x00B5, 0x013F,
			0x00B6, 0x013F, 0x0080, 0x001F, 0x00B7, 0x013F, 0x0001, 0x001F, 0x00BE, 0x013F, 0x00B8, 0x001F,
			0x00BF, 0x013F, 0x0000, 0x0140, 0x00C0, 0x011F, 0x0025, 0x007F, 0x00C0, 0x013F, 0x00C1, 0x011F,
			0x0042, 0x007F, 0x00C1, 0x013F, 0x00C2, 0x011F, 0x00AE, 0x007F, 0x00C2, 0x013F, 0x00C3, 0x011F,
			0x0043, 0x007F, 0x00C3, 0x013F, 0x00C4, 0x011F, 0x009D, 0x007F, 0x00C4, 0x013F, 0x00C5, 0x011F,
			0x0077, 0x007F, 0x00C5, 0x013F, 0x00C6, 0x011F, 0x008C, 0x007F, 0x00C6, 0x013F, 0x00C7, 0x011F,
			0x0056, 0x007F, 0x00C7, 0x013F, 0x0000, 0x0140, 0x00FF, 0x001F, 0x014D, 0x0162, 0x014D, 0x0162,
			0x014D, 0x0162, 0x014D, 0x0162, 0x014D, 0x0162, 0x014D, 0x0162, 0x014D, 0x0162, 0x014D, 0x0142,
			0x000A, 0x001B, 0x019F, 0x0162, 0x019D, 0x0162, 0x019E, 0x0162, 0x0197, 0x0162, 0x000F, 0x001B,
			0x019F, 0x0162, 0x0001, 0x0017, 0x00F0, 0x001B, 0x0101, 0x01C0, 0x0002, 0x011F, 0x01F8, 0x0037,
			0x01D8, 0x003B, 0x0144, 0x0156, 0x019E, 0x0162, 0x003C, 0x001F, 0x0132, 0x0162, 0x01B8, 0x001F,
			0x0000, 0x0140, 0x000A, 0x001B, 0x019F, 0x0162, 0x000C, 0x019F, 0x0002, 0x019F, 0x015D, 0x015E,
			0x01A4, 0x0162, 0x0006, 0x001B, 0x019F, 0x0162, 0x0197, 0x0162, 0x0009, 0x001B, 0x019F, 0x0162,
			0x0002, 0x0114, 0x000C, 0x0194, 0x0008, 0x019F, 0x002D, 0x001B, 0x019F, 0x0142, 0x01A4, 0x0162,
			0x003C, 0x001B, 0x019F, 0x0162, 0x000E, 0x019F, 0x0197, 0x0142, 0x00FF, 0x001F, 0x0180, 0x0162,
			0x0180, 0x0162, 0x0180, 0x0162, 0x0180, 0x0162, 0x0180, 0x0162, 0x0180, 0x0162, 0x0180, 0x0162,
			0x0180, 0x0142, 0x00CC, 0x001F, 0x0005, 0x001B, 0x019F, 0x0162, 0x01A4, 0x0162, 0x0046, 0x001B,
			0x019F, 0x0162, 0x0197, 0x0162, 0x0002, 0x001B, 0x019F, 0x0162, 0x0001, 0x0017, 0x0018, 0x001B,
			0x0101, 0x01C0, 0x0002, 0x0116, 0x01B0, 0x0037, 0x01D8, 0x003B, 0x0177, 0x0156, 0x0018, 0x001B,
			0x019F, 0x0162, 0x0163, 0x0162, 0x01B8, 0x001F, 0x0000, 0x0140, 0x0003, 0x001B, 0x019F, 0x0162,
			0x000C, 0x019F, 0x0002, 0x019F, 0x0193, 0x015E, 0x0001, 0x001B, 0x0101, 0x01C0, 0x01D8, 0x003B,
			0x0187, 0x0156, 0x01A4, 0x0162, 0x01D8, 0x003B, 0x018A, 0x0152, 0x0197, 0x0162, 0x019B, 0x0162,
			0x0002, 0x0114, 0x000C, 0x0194, 0x0008, 0x019F, 0x0004, 0x001B, 0x019F, 0x0142, 0x01A4, 0x0162,
			0x0006, 0x001B, 0x019F, 0x0162, 0x000E, 0x019F, 0x0001, 0x0015, 0x0002, 0x0135, 0x0000, 0x0140,
			0x0197, 0x0162, 0x0001, 0x001B, 0x019F, 0x0142, 0x01A4, 0x0162, 0x00F0, 0x001B, 0x0101, 0x01C0,
			0x01D8, 0x003B, 0x01A0, 0x0156, 0x0100, 0x01C0, 0x0000, 0x0140, 0x0000, 0x0015, 0x0002, 0x0135,
			0x0000, 0x0140, 0x0001, 0x00DB, 0x0001, 0x01C0, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
			0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x01A7, 0x0142,    
		}; 
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000101C, 0x00000001 );

		ULONG i = 0 ;
		for( i = 0 ; i < 1024 ; i++ ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00002000 + i * 4, TW5864_VLC_INIT_DATA[ i ] ); }

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000101C, 0x00000000 );

		ULONG R00000004 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000004 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000004, R00000004 | 0x00000001 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000030, 0x00000080 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080044, 0x00000002 );

		for( i = 0 ; i < 2048 ; i++ ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00082000 + i * 4, TW5864_RAM_CONB_CONVERT[ i ] ); }

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080044, 0x00000000 );

		ULONG R00000030 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000030 );
			
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000030, R00000030 & ~0x00000080 );
	
		ULONG R00000014 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000014 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000014, R00000014 & ~0x00000008 );

		R00000014 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000014 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000014, R00000014 | 0x00000008 );

		//////////////////////////////////////////////////////////////////

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000A01C, R0000A01C ); // H.P.LIN: DDR 256MB/512MB DETECTION

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000A81C, R0000A01C ); // H.P.LIN: DDR 256MB/512MB DETECTION
	}

	// -----> InitOSDBuf() [2011.08.11]
	// 
	{	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000220, 0x0000047F );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000228, 0x0000007F ); // H.P.LIN: 0x00000000 -> 0x0000007F (7 LINES)

		ULONG i = 0 ;
		ULONG j = 0 ;
		ULONG line = 0 ;

		for( i = 0 ; i < 16 ; i++ ) {

			for( j = 0 ; j < 2 ; j++ ) {

				for( line = 0 ; line < 8 ; line++ ) {

					ULONG dw_osd_attribute_address = ((0x0000047F << 10) | (j << 9) | (i << 5) | (line * 3)) << (2);

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000030,  (dw_osd_attribute_address & 0xFFF80000) >> 19 );

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + (dw_osd_attribute_address & 0x0007FFFF) + 0x00000000, 0x00000000 );

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + (dw_osd_attribute_address & 0x0007FFFF) + 0x00000004, 0x00000000 );

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00080000 + (dw_osd_attribute_address & 0x0007FFFF) + 0x00000008, 0x00000000 );
				}
			}
		}
	}

	// -----> InitVP() [2011.08.11]
	// 
	{	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C010, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C014, 0x00000318 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C018, 0x00000318 );

		ULONG i = 0 ;
		for( i = 0 ; i < 32 ; i++ ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C100 + i * 4, 0x0000FFFF ); }

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C028, 0x00000000 );
	}
//peter [2011.07.11]
	ULONG index = 0;	
		
	for( index = 0 ; index < 32 ; index++ ) {

		pDevice->m_nCustomOsdTextColorProperty[ index ][ 0 ] = 0;

		pDevice->m_nCustomOsdTextLineProperty[ index ] = 0;

		ULONG y = 0;

		for( y = 0 ; y < 16 ; y++ ) {
		
			memset( pDevice->m_pCustomOsdTextStringProperty[ index ][ y ], 0x00, 64 + 1 );

			pDevice->m_bCustomOsdTextStringRefreshProperty[ index ][ y ] = FALSE;
		}
	}

	TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
		
	p_sys_cfg->R00009801 = 0xF00;


	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "e03518d16ae44460b3a1694ed56877f5() before TW5864_COPYPORTECT_ARCHITECTURE\n" );


#ifdef TW5864_COPYPORTECT_ARCHITECTURE

	{	
		
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00700000 + 0x00000008, 0x0000000C ); // GPIO
//???
//		srand( (ULONG)(TW5864_KsQuerySystemTime( pDevice )) );

//		BYTE F12C7345F5F5944bd9BF6C72DBEF85387[ 4 ] = { (rand() % 0xFF), (rand() % 0xFF), (rand() % 0xFF), (rand() % 0xFF) };


		BYTE F12C7345F5F5944bd9BF6C72DBEF85387[ 4 ] = { 1, 2, 3, 4 };

		BYTE F2F581730428B430cBF3FD8EC8D409BC0[ 4 ] = { 0x00, 0x00, 0x00, 0x00 };

		ULONGLONG delay = 125; // 100NS

		TW5864_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, delay ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, delay ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x13, delay ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 0 ], delay ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 1 ], delay ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 2 ], delay ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387[ 3 ], delay ); TW5864_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, delay ); schedule_timeout_interruptible( msecs_to_jiffies( 100 ) );

		TW5864_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, delay ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA3, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 0 ] = TW5864_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 1 ] = TW5864_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 2 ] = TW5864_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); F2F581730428B430cBF3FD8EC8D409BC0[ 3 ] = TW5864_F6E9556EF6B7D45fbB367C7EF7BF65BFB( pDevice, 0, delay ); TW5864_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, delay ); schedule_timeout_interruptible( msecs_to_jiffies( 100 ) );

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "CODE = %08X | KEY = %08X\n", *((DWORD *)(F12C7345F5F5944bd9BF6C72DBEF85387)), *((DWORD *)(F2F581730428B430cBF3FD8EC8D409BC0)) );

		if( TW5864_KsQueryCopyProtectNumber( pDevice, F12C7345F5F5944bd9BF6C72DBEF85387 ) == *((DWORD *)(F2F581730428B430cBF3FD8EC8D409BC0)) ) {

			FD0AC55FE0C0B45a788FEC199C5758F1E[ pDevice->FF362AA37F7D046bf90568AC1600626D9 ] = 1;

			F6053D464C87D41c1B8CBE8A39FCDF2D2[ pDevice->FF362AA37F7D046bf90568AC1600626D9 ] = 1;
		}
	}

#endif
	//
	// 
	{	BYTE R11 = (BYTE)(pDevice->m_nCustomSoftwareWatchdogDurationProperty);
		
		TW5864_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x11, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice,  R11, 125 ); TW5864_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 ); //

		TW5864_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x12, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x5A, 125 ); TW5864_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 );

		TW5864_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x10, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x5A, 125 ); TW5864_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 );
	}

	// EEPROM ACCESS
	//
	BYTE EEPROM[ 4 ] = { 0x00, 0x00, 0x00, 0x00 };

	d0e203938933403cb29557bc86e87ce1( pDevice, 0xA1, 0x00, EEPROM, 4 );

	pDevice->bcdDevice = (EEPROM[ 3 ] << 8) | (EEPROM[ 2 ] << 0);

	pDevice->iManufacturer = (EEPROM[ 0 ]);

	pDevice->iProduct = (EEPROM[ 1 ]);

	// INIT MOTION DETECTION
	// 
	{
		LONG i = 0;

		for( i = 0 ; i < 16 ; i++ ) {

			if( i >= 4 ) { continue ; }

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x000003FE << 2), i );//CH1 ~ CH4 all turn on detection

			ULONG j = 0x03E0;

			for( j = 0x03E0; j < 0x03F8 ; j++ ) { // 192 CELL

				c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (j << 2), 0x00000000 ); // 0 = TURN ON / 1 = TURN OFF
			}

			// MOTION DETECTION PARAMETER
			// 
			ULONG MD_TMPSENS = pDevice->m_nCustomMotionTemporalSensitivityProperty[ i ] & 0x77FFFFFF; // TEMPORAL SENSITIVITY

			ULONG MD_PIXEL_OS = 0; // X

			ULONG MD_LVSENS = pDevice->m_nCustomMotionLevelSensitivityProperty[ i ] & 0x77FFFFFF; // LEVEL SENSITIVITY

			ULONG MD_FIELD = 0; // X

			ULONG MD_REFFLD = 0; // X

			ULONG MD_SPEED = pDevice->m_nCustomMotionSpeedProperty[ i ] & 0x77FFFFFF; // SPPED

			ULONG MD_CELSENS = 0; // X

			ULONG MD_SPSENS = pDevice->m_nCustomMotionSpatialSensitivityProperty[ i ] & 0x77FFFFFF; // SPATIAL SENSITIVITY

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0301 + i * 8) << 2, (MD_TMPSENS << 4) | (MD_PIXEL_OS << 0)                    );

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0302 + i * 8) << 2, (MD_REFFLD  << 7) | (MD_FIELD    << 5) | (MD_LVSENS << 0) );

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0303 + i * 8) << 2, (MD_CELSENS << 6) | (MD_SPEED    << 0)                    );

			c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0304 + i * 8) << 2, (MD_SPSENS  << 4)                                         );
		}

	}

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] e03518d16ae44460b3a1694ed56877f5() end \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

	a0c563aa017e45aa898479fcd6f672e2( pDevice );//HW init

	return TRUE;
}

BOOLEAN c3575033ae26421c8cee90cc36197e5c( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "c3575033ae26421c8cee90cc36197e5c()\n" );

	f74f60e6b0814257af133a93b451d6b1( pDevice );//HW uninit

	// -----> StopFPGA() -----> ISILH264FpgaEncoderEnableAD( DISABLE ) [2011.08.11]
	//
	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000028, 0x00000000 );

	// -----> StopFPGA() -----> ISILH264FpgaDisableAllPreview() [2011.08.11]
	//
	{	ULONG R00018004 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018004 ); 
		
	//	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018004, R00018004 & ~(1 << 4) ); // H.P.LIN: 0x00000010 -> 0x00000000

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C004, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C008, 0x00000000 );

		ULONG i = 0 ;

		for( i = 0 ; i < 3000 ; i++ ) { 

			if( c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000C000 ) == 0x00000000 ) {

				break;
			}
		}
		for( i = 0 ; i < 4 ; i++ ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C200 + (i * 4), 0x00000000 ); }

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C020, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C024, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C02C, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018044, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018040, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C014, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C018, 0x00000000 );
	}
	// -----> FreeFPGA() -----> ISILH264FpgaEncoderClose() [2011.08.11]
	//
	{	b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00008000, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000014, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018004, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000028, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000020, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000024, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000020C, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000204, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000410, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000002C, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000208, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000004, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000200, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000040, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00008808, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000880C, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00008820, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00004004, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00004008, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C020, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C024, 0x00000000 );
														   
		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C00C, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018044, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018040, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C004, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000001C, 0x00000000 );

		b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018020, 0x00000000 );
	}
	FREE( pDevice->m_pCustomSystemConfigProperty );


	return TRUE;
}

BOOLEAN TW5864_PowerDownPeripherals( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TW5864_PowerDownPeripherals()\n" );

	return TRUE;
}

void bibInit(bitbuffer_s *bitbuf , int size , unsigned char * bufAddr)
{
	bitbuf->bufSize = size;
	bitbuf->bufAddr = bufAddr;
	bitbuf->bytePos = 0;
	bitbuf->currentBits = 0;
	bitbuf->bitpos = 32;
}

int bibPutByte(bitbuffer_s *bitbuf, unsigned char byte)
{
	BIT_PUT_BYTE(bitbuf , byte);
	return 8;
}

int bibPutBits(bitbuffer_s *bitbuf, unsigned bits, unsigned len)
{
	bits &= ~((unsigned)-1 << len);
	if (bitbuf->bitpos > len)
	{
		// make this path fast
		bitbuf->bitpos -= len;
		bitbuf->currentBits |= bits << bitbuf->bitpos;
	}
	else
	{
		unsigned remLen;
		// fill the remaing bits in the buffer
		remLen = len - bitbuf->bitpos;
		bitbuf->currentBits |= bits >> remLen;

		// send 4 bytes
		BIT_PUT_BYTE(bitbuf, bitbuf->currentBits >> 24);
		bitbuf->currentBits <<= 8;

		BIT_PUT_BYTE(bitbuf, bitbuf->currentBits >> 24);
		bitbuf->currentBits <<= 8;

		BIT_PUT_BYTE(bitbuf, bitbuf->currentBits >> 24);
		bitbuf->currentBits <<= 8;

		BIT_PUT_BYTE(bitbuf, bitbuf->currentBits >> 24);

		// put the remaining bits in the buffer
		bitbuf->bitpos = 32 - remLen;
		if (remLen)
			bitbuf->currentBits = bits << bitbuf->bitpos;
		else 
			bitbuf->currentBits = 0;
	}
	return len;
}


int bibByteAlign(bitbuffer_s *bitbuf)
{
	int bitsSkipped;

	while (bitbuf->bitpos < 32)
	{
		BIT_PUT_BYTE(bitbuf, bitbuf->currentBits >> 24);
		bitbuf->currentBits <<= 8;
		bitbuf->bitpos += 8;
	}

	bitsSkipped = bitbuf->bitpos - 32;
	bitbuf->bitpos = 32;
	return bitsSkipped;
}


int bibTrailingBits(bitbuffer_s *bitbuf)
{
	int bits = 0;
	bibPutBits(bitbuf, 1, 1);         // rbsp_stop_one_bit  
	bits+=1;
	bits+=bibByteAlign(bitbuf);
	return bits;
}




int vlcuSendUVLC(bitbuffer_s *bitbuf, unsigned int codeNum)
{
	int tmp;
	int info;
	int len;
	int i;

	tmp = (codeNum+1)>>1;

	/* Find len/2 = i */
	for (i = 0; tmp != 0 ; i++)
		tmp >>= 1;

	/* Compute length. Length is always odd number */
	len  = 2*i + 1;

	/* info = codeNum + 1 - 2^(len/2) */
	info = codeNum + 1 - (1<<i);

	bibPutBits(bitbuf, info | (1 << (len >> 1)), len);

	return len;
}



int vlcuSendNalUnitStartCodePrefix(bitbuffer_s *bitbuf, int zeroByte)
{
	int bits = 0;

	// write 1 zero byte if requested
	if (zeroByte != 0)
	{
		bibPutByte( bitbuf, 0 );
		bits += 8;
	}

	// write the start_code_prefix_one_3bytes 0x00 0x00 0x01 / 0x00 0x00 0x00 0x01
	bibPutByte( bitbuf, 0 );
	bibPutByte( bitbuf, 0 );
	bibPutByte( bitbuf, 0 );
	bibPutByte( bitbuf, 1 );
	//bits += 24;
	bits += 32;
	return bits;
}


int vlcuSendNalHead(bitbuffer_s *bitbuf, int nal_ref_idc, int nal_type)
{
	int nalHeaderByte = 0;
	nalHeaderByte |= 0 << 7;              // forbidden bit (1 bit)
	nalHeaderByte |= nal_ref_idc << 5;    // nal_ref_idc   (2 bits)
	nalHeaderByte |= nal_type;            // nal_ref_idc   (5 bits)
	return bibPutByte(bitbuf, (unsigned char)nalHeaderByte);
}



unsigned int vldGetUVLC(bitbuffer_s *bitbuf)
{
	unsigned c;
	unsigned prefixLen;
	int bit;

	bibGetBit(bitbuf, &bit);

	if (bit == 1)
		return 0;

	prefixLen = 0;

	do {
		bibGetBit(bitbuf, &bit);
		prefixLen += 1;

		/* Maximum prefix length is VLD_MAX_CW_LEN/2 */
		if (prefixLen == VLD_MAX_CW_LEN/2) 
		{
			bibGetMax16bits(bitbuf, VLD_MAX_CW_LEN/2, &c);
			if (bit != 1 || c != 0) 
			{
				/* We encoutered overlong codeword or we encoutered too big code */
				return 0;
			}
			else
				return VLD_MAX_UVLC_CODE_NUM;  /* Otherwise, return maximum 16-bit code number */
		}

	} while (bit == 0);

	bibGetMax16bits(bitbuf, prefixLen, &c);

	return (unsigned int)(c + (1<<prefixLen)-1);

}

// ##############################################################################################################################################################################
// 
int psSendSeqParameterSet(unsigned char * buf, unsigned picWidth , unsigned picHeight)
{
	int bits = 0;
	bitbuffer_s bitbuf[1];
	bibInit(bitbuf , 16 , buf);
	bits += vlcuSendNalUnitStartCodePrefix(bitbuf, 0);
	bits += vlcuSendNalHead(bitbuf, 1, 7); // NAL_TYPE_SPS = 7

	bits += u_n(bitbuf, 66 , 8); // PS_BASELINE_PROFILE_IDC = 66
	bits += u_n(bitbuf, 0, 1);
	bits += u_n(bitbuf, 0, 1);
	bits += u_n(bitbuf, 0, 1);
	bits += u_n(bitbuf, 0, 5);
	bits += u_n(bitbuf, 30 , 8);
	bits += ue_v(bitbuf, 0);
	bits += ue_v(bitbuf, 11); // LOG2_MAX_FRAME_NUM_MINUS4 == 11
	bits += ue_v(bitbuf, 0);
	bits += ue_v(bitbuf, 11 ); // LOG2_MAX_FRAME_NUM_MINUS4 == 11
	bits += ue_v(bitbuf, 1); // MAX_REF_FRAME = 1
	bits += u_n(bitbuf, 0 , 1);
	bits += ue_v(bitbuf, (picWidth/16) -1);
	bits += ue_v(bitbuf, (picHeight/16) - 1);
	bits += u_n(bitbuf, 1, 1);
	bits += u_n(bitbuf, 0 , 1);
	bits += u_n( bitbuf, 0 , 1 );
	bits += u_n(bitbuf, 0 , 1);
	bits += bibTrailingBits(bitbuf);

	return bits;
}

int psSendPicParameterSet(unsigned char * buf , unsigned qpBase)
{
	int bits = 0;
	bitbuffer_s bitbuf[1];
	bibInit(bitbuf , 16 , buf);
	bits += vlcuSendNalUnitStartCodePrefix(bitbuf, 0);
	bits += vlcuSendNalHead(bitbuf, 1, 8); // NAL_TYPE_PPS = 8

	bits += ue_v( bitbuf, 0);
	bits += ue_v( bitbuf, 0);
	bits += u_n( bitbuf, 0 , 1 );
	bits += u_n( bitbuf, 0 , 1 );
	bits += ue_v( bitbuf, 0 );
	bits += ue_v( bitbuf, 0 );
	bits += ue_v( bitbuf, 0);
	bits += u_n( bitbuf, 0 , 1);
	bits += u_n( bitbuf, 0, 2);
	bits += se_v( bitbuf, (int)qpBase - 26 );
	bits += se_v( bitbuf, (int)qpBase - 26);
	bits += se_v( bitbuf, 0 );
	bits += u_n( bitbuf, 0 , 1 );
	bits += u_n( bitbuf, 0 , 1 );
	bits += u_n( bitbuf, 0 , 1 );

	bits += bibTrailingBits(bitbuf);

	return bits;
}

int psSendSlice(unsigned char * buf , int frameNum , int poc , int deltaQp , unsigned frameType , unsigned isIDR)
{
	int bits = 0;
	bitbuffer_s bitbuf[1];
	int sliceType = (frameType == 0 ? 2 : 0);
	bibInit(bitbuf , 16 , buf);
	bits += vlcuSendNalUnitStartCodePrefix(bitbuf, 0);
	if (isIDR == 1)
		bits += vlcuSendNalHead(bitbuf, 1 , 5);
	else 
		bits += vlcuSendNalHead(bitbuf, 1 , 1);
	/* first_mb_in_slice */
	bits += ue_v(bitbuf, 0);

	/* slice_type */

	bits += ue_v(bitbuf, sliceType);

	/* pps id */
	bits += ue_v(bitbuf, 0);

	/* frame_num */
	bits += u_n(bitbuf, frameNum, 11+4);

	/* idr pic id */
	if (isIDR) {
		bits += ue_v(bitbuf, 1);
	}

	/* pic_order_cnt_lsb */
	bits += u_n(bitbuf, poc, 11+4);


	/* reference picture management */
	if (sliceType == 0) 
	{
		bits += u_n(bitbuf, 0 , 1);
	}

	/* send reference frame reordering syntax elements */
	if (sliceType != 2) 
	{
		bits += u_n(bitbuf, 0, 1);
	}

	/* ref pic marking, including writing MMCO commands if any. */
	if (isIDR) 
	{
		bits += u_n(bitbuf, 0, 1);
		bits += u_n(bitbuf, 0, 1);
	}
	else 
	{ /* non-IDR */
		bits += u_n(bitbuf, 0, 1);
	}

	/* slice_qp_delta */
	bits += se_v(bitbuf, deltaQp);
	bibByteAlign(bitbuf);

	return bits;
}

ULONG TW5864_COPY_NAL( BYTE * pe , BYTE * po, LONG bytes, BYTE * pe_end )
{
	ULONG counts = 0;

	LONG i = 0;

	for( i = 0 ; i < bytes - 2 ; i++ ) {

		ULONG v = (po[ 0 ] << 16) + 
			
				  (po[ 1 ] <<  8) + 
				  
				  (po[ 2 ] <<  0);

		if( v <= 3 ) {

		   *pe++ = *po++; if( pe == pe_end ) { break ; } i++; 

		   *pe++ = *po++; if( pe == pe_end ) { break ; } i++; 

		   *pe++ =     3; if( pe == pe_end ) { break ; }

		   *pe++ =   *po; if( pe == pe_end ) { break ; }

			counts += 4;
		}
		else {

		   *pe++ = *po; if( pe == pe_end ) { break ; }

		    counts++;

			if( i == bytes - 3 ) {

			   *pe++ = po[ 1 ]; if( pe == pe_end ) { break ; }

			   *pe++ = po[ 2 ]; if( pe == pe_end ) { break ; }

			    counts += 2;
			}
		}
		po++;
	}
	return counts;
}

typedef struct _TW5864_H264_STREAM_HEADER
{
	DWORD nFrameBufferSize : 24; //

	DWORD nFrameType       :  1; //

	DWORD nMotionStatus    :  1; //

	DWORD nLockStatus      :  1; //

	DWORD nReserved        :  5;
		
} TW5864_H264_STREAM_HEADER;

BOOLEAN a17141c0224e4e82a01dd2dc46f8ba6b( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG status, ULONG mask, F301FA49098CE4d9eB95F22BBD388E837 * pVideos[ F03706E45925547d799BA016E4F0F6D6B ][ MAX_DEVICE_OPEN_NUM ], F170997530C6943659ECE8DEC21301F66 * pVideoBuffers[ F03706E45925547d799BA016E4F0F6D6B ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN p_FDFC345768E394d138EA574DEB55B7949s[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN F6E2E659AAB8C4494A193C313276DAA65[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ] )
{
//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "a17141c0224e4e82a01dd2dc46f8ba6b() status(0x%x) mask(0x%x)\n" , status, mask );

	if( status & 0x00000010 ) { //

//TW5864 encode
		TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		if(p_sys_cfg->n_preview_video_satrt < TW5864_DROP_H264 + 5)
		{
			p_sys_cfg->n_preview_video_satrt++;
		}

		ULONG R00018008 = (mask >>  0) & 0x0000FFFF;

		ULONG R00018010 = (mask >> 16) & 0x0000FFFF;

		ULONG i = 0;

		for( i = 0 ; i < 4 ; i ++ ) {
						
			if( (R00018008 >> i) & 0x01 ) {

				ULONG j = (R00018010 >> i) & 0x01;

				if( pVideos[ i ][ 0 ] && pVideoBuffers[ i ][ 0 ] ) {

					pVideoBuffers[ i ][ 0 ]->F6A821C5E7AA043f999FB3C51DB94DD2B.input = j;

					p_FDFC345768E394d138EA574DEB55B7949s[ i ][ 0 ] = TRUE;

					F6E2E659AAB8C4494A193C313276DAA65[ i ][ 0 ] = FALSE;
				}
			}
		}
	}
	if( status & 0x00000002 ) {

		TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		ULONG  R00001004 = mask;

		ULONG  i = pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] & 0x7FFFFFFF;

//TW5864 encode
		if(p_sys_cfg->n_H264_output_enable)
		{
			BYTE * pe = NULL;

			ULONG  n_stream_buffer_length = (((R00001004 + 1 + 31) >> 5) * 4) & (a66316d33603423597a516a5c20b4353 - 1);

			if( (i >= 1) && (i <= 8) ) {

				if( pVideos[ 16 + i - 1 ][ 0 ] && pVideoBuffers[ 16 + i - 1 ][ 0 ] ) {

					pVideoBuffers[ 16 + i - 1 ][ 0 ]->F6A821C5E7AA043f999FB3C51DB94DD2B.input = (pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] & 0x80000000); 

	//add size
					pVideoBuffers[ 16 + i - 1 ][ 0 ]->F6A821C5E7AA043f999FB3C51DB94DD2B.input |= n_stream_buffer_length;


					p_FDFC345768E394d138EA574DEB55B7949s[ 16 + i - 1 ][ 0 ] = TRUE;

					F6E2E659AAB8C4494A193C313276DAA65[ 16 + i - 1 ][ 0 ] = FALSE;
				
	//				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TW5864() encoder complete, pVideoBuffers[ 16 + %d - 1 ]->F6A821C5E7AA043f999FB3C51DB94DD2B.input(0x%x)\n", i, pVideoBuffers[ 16 + i - 1 ][ 0 ]->F6A821C5E7AA043f999FB3C51DB94DD2B.input );
	//				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TW5864() encoder complete, n_stream_buffer_length(0x%x)\n", n_stream_buffer_length );


				}
				else
				{
					F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] TW5864() (%d) encoder drop due to no buffer pVideos(0x%x) pVideoBuffers(0x%x)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), i - 1, pVideos[ 16 + i - 1 ][ 0 ] , pVideoBuffers[ 16 + i - 1 ][ 0 ] );

					if(pDevice->m_pCustomSystemConfigProperty != NULL)
					{
						p_sys_cfg->n_video_encoder_gop_step[ i - 1 ] = 0;//force I frame
					}
				}
			}

			if( i >= 1 && 
				
				i <= 8 ) {

				p_sys_cfg->n_video_encoder_input_buffer_index[ i - 1 ] = -1;
			}
			pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] = 0; // UNLOCK ENCODER

		}
		else
		{
			if( i >= 1 && i <= 8 )
			{
				p_sys_cfg->n_video_encoder_input_buffer_index[ i - 1 ] = -1;
			}
			pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] = 0; // UNLOCK ENCODER

		}

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;

		//?????
		//return TRUE;
	}

	if( pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] >= 60 ) {

		TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		ULONG i = pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] & 0x7FFFFFFF;

		F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] [CH%x] [H264] [HARDWARE.RESET]\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i ); 

		if( i >=  1 && 
			
			i <= 16 ) {

			p_sys_cfg->n_video_encoder_input_buffer_index[ i - 1 ] = -1;

			p_sys_cfg->n_video_encoder_gop_step[ i - 1 ] = 0;
		}
		pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] = 0; // UNLOCK ENCODER

		pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;
	}

	if( status & 0x00000040 ) {

		//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%d] TW5864 enter 0x00000040 TRUE\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

		TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		static const USHORT TW5864_INTRA4X4_LAMBDA_TABLE[ 52 ] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 6, 6, 7, 8, 9, 10, 11, 13, 14, 16, 18, 20, 23, 25, 29, 32, 36, 40, 45, 51, 57, 64, 72, 81, 91 };

		static const USHORT TW5864_LAMBDA_TABLE[ 52 ] = { 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0020, 0x0040, 0x0040, 0x0040, 0x0040, 0x0060, 0x0060, 0x0060, 0x0080, 0x0080, 0x0080, 0x00A0, 0x00C0, 0x00C0, 0x00E0, 0x0100, 0x0120, 0x0140, 0x0160, 0x01A0, 0x01C0, 0x0200, 0x0240, 0x0280, 0x02E0, 0x0320, 0x03A0, 0x0400, 0x0480, 0x0500, 0x05A0, 0x0660, 0x0720, 0x0800, 0x0900, 0x0A20, 0x0B60 };

		ULONG R00000010 = 0x00000000;

		ULONG R00000038 = 0x00000000;

		BOOLEAN  is_ready = FALSE;

		ULONG i = 0;

//		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TW5864 F03D1DD650AC64c28B04687338F970D0E[ 1 ](0x%x)\n", pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] );

		if( pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] == 0 ) {

			if( (pVideos[ 16 ][ 0 ] == NULL) ) { p_sys_cfg->n_video_encoder_input_buffer_index[ 0 ] = -1; }

			if( (pVideos[ 17 ][ 0 ] == NULL) ) { p_sys_cfg->n_video_encoder_input_buffer_index[ 1 ] = -1; }

			if( (pVideos[ 18 ][ 0 ] == NULL) ) { p_sys_cfg->n_video_encoder_input_buffer_index[ 2 ] = -1; }

			if( (pVideos[ 19 ][ 0 ] == NULL) ) { p_sys_cfg->n_video_encoder_input_buffer_index[ 3 ] = -1; }

			if( (pVideos[ 20 ][ 0 ] == NULL) ) { p_sys_cfg->n_video_encoder_input_buffer_index[ 4 ] = -1; }

			if( (pVideos[ 21 ][ 0 ] == NULL) ) { p_sys_cfg->n_video_encoder_input_buffer_index[ 5 ] = -1; }

			if( (pVideos[ 22 ][ 0 ] == NULL) ) { p_sys_cfg->n_video_encoder_input_buffer_index[ 6 ] = -1; }

			if( (pVideos[ 23 ][ 0 ] == NULL) ) { p_sys_cfg->n_video_encoder_input_buffer_index[ 7 ] = -1; }

			if( (p_sys_cfg->n_video_encoder_input_buffer_index[ 0 ] == -1) &&

				(p_sys_cfg->n_video_encoder_input_buffer_index[ 1 ] == -1) &&

				(p_sys_cfg->n_video_encoder_input_buffer_index[ 2 ] == -1) &&

				(p_sys_cfg->n_video_encoder_input_buffer_index[ 3 ] == -1) &&

				(p_sys_cfg->n_video_encoder_input_buffer_index[ 4 ] == -1) &&

				(p_sys_cfg->n_video_encoder_input_buffer_index[ 5 ] == -1) &&

				(p_sys_cfg->n_video_encoder_input_buffer_index[ 6 ] == -1) &&

				(p_sys_cfg->n_video_encoder_input_buffer_index[ 7 ] == -1) ) {

				R00000010 = ((c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000004C ) & 0x0000FFFF) << 16) | // CUR_ENCODE_PTR

							((c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000010 ) & 0x0000FFFF) <<  0);  // CUR_ENCODE_PTR

				R00000038 = ((c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000003C ) & 0x0000FFFF) << 16) | 
					
							((c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000038 ) & 0x0000FFFF) <<  0);

				ULONG j = 0;

				for( j = 0 ; j < 4 ; j++ ) {

					ULONG ch = (p_sys_cfg->n_video_encoder_selected_channel + j) % 4;

					ULONG x = (R00000010 >> (ch * 2)) & 0x00000003;

					ULONG y = (R00000038 >> (ch * 2)) & 0x00000003;

					x += 1;

					x %= 4;

					if( x != y ) { 

						p_sys_cfg->n_video_encoder_input_buffer_index[ ch + 0 ] = (R00000010 >> (ch * 2)) & 0x00000003;
						
						p_sys_cfg->n_video_encoder_input_buffer_index[ ch + 4 ] = (R00000010 >> (ch * 2)) & 0x00000003;

						p_sys_cfg->n_video_encoder_selected_channel = (ch + 1) % 4;

					
						break;
					}
				}
			}
			if( pVideos[ 16 ][ 0 ] && p_sys_cfg->n_video_encoder_input_buffer_index[ 0 ] != -1 ) { i = 0; is_ready = TRUE; } else
				
			if( pVideos[ 17 ][ 0 ] && p_sys_cfg->n_video_encoder_input_buffer_index[ 1 ] != -1 ) { i = 1; is_ready = TRUE; } else
				
			if( pVideos[ 18 ][ 0 ] && p_sys_cfg->n_video_encoder_input_buffer_index[ 2 ] != -1 ) { i = 2; is_ready = TRUE; } else
				
			if( pVideos[ 19 ][ 0 ] && p_sys_cfg->n_video_encoder_input_buffer_index[ 3 ] != -1 ) { i = 3; is_ready = TRUE; } else
				
			if( pVideos[ 20 ][ 0 ] && p_sys_cfg->n_video_encoder_input_buffer_index[ 4 ] != -1 ) { i = 4; is_ready = TRUE; } else
				
			if( pVideos[ 21 ][ 0 ] && p_sys_cfg->n_video_encoder_input_buffer_index[ 5 ] != -1 ) { i = 5; is_ready = TRUE; } else
				
			if( pVideos[ 22 ][ 0 ] && p_sys_cfg->n_video_encoder_input_buffer_index[ 6 ] != -1 ) { i = 6; is_ready = TRUE; } else
				
			if( pVideos[ 23 ][ 0 ] && p_sys_cfg->n_video_encoder_input_buffer_index[ 7 ] != -1 ) { i = 7; is_ready = TRUE; }

		}
		else
		{
			if( status & 0x00000040 ) {

				pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ]++;

				//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%d] TW5864(%d) enter 0x00000040 F66FD293166B14f93A084AE0E6BD0F196[ 1 ](0d%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), i, pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] );
			}
		}

//		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TW5864 is_ready(0x%x) i(0x%x)\n", is_ready, i );
		
		if( is_ready ) {
/*
			if((i == 0) && (pVideoBuffers[ 16 ]  == NULL))		
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TW5864 i(0x%x) pVideoBuffers[ 16 ] is NULL\n", i );
			}
			if((i == 1) && (pVideoBuffers[ 17 ]  == NULL))		
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TW5864 i(0x%x) pVideoBuffers[ 17 ] is NULL\n", i );
			}
			if((i == 2) && (pVideoBuffers[ 18 ]  == NULL))		
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TW5864 i(0x%x) pVideoBuffers[ 18 ] is NULL\n", i );
			}
			if((i == 3) && (pVideoBuffers[ 19 ]  == NULL))		
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TW5864 i(0x%x) pVideoBuffers[ 19 ] is NULL\n", i );
			}
			if((i == 4) && (pVideoBuffers[ 20 ]  == NULL))		
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TW5864 i(0x%x) pVideoBuffers[ 20 ] is NULL\n", i );
			}
			if((i == 5) && (pVideoBuffers[ 21 ]  == NULL))		
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TW5864 i(0x%x) pVideoBuffers[ 21 ] is NULL\n", i );
			}
			if((i == 6) && (pVideoBuffers[ 22 ]  == NULL))		
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TW5864 i(0x%x) pVideoBuffers[ 22 ] is NULL\n", i );
			}
			if((i == 7) && (pVideoBuffers[ 23 ]  == NULL))		
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "TW5864 i(0x%x) pVideoBuffers[ 23 ] is NULL\n", i );
			}
*/

/*
			if( (pVideos[ 16 ] && pVideoBuffers[ 16 ] && i == 0) ||
				 
				(pVideos[ 17 ] && pVideoBuffers[ 17 ] && i == 1) ||
											   
				(pVideos[ 18 ] && pVideoBuffers[ 18 ] && i == 2) ||
											   
				(pVideos[ 19 ] && pVideoBuffers[ 19 ] && i == 3) ||
											   
				(pVideos[ 20 ] && pVideoBuffers[ 20 ] && i == 4) ||
											   
				(pVideos[ 21 ] && pVideoBuffers[ 21 ] && i == 5) ||
											   
				(pVideos[ 22 ] && pVideoBuffers[ 22 ] && i == 6) ||
											   
				(pVideos[ 23 ] && pVideoBuffers[ 23 ] && i == 7) ) {
*/
			if( (pVideos[ 16 ][ 0 ] && i == 0) ||
				 
				(pVideos[ 17 ][ 0 ] &&  i == 1) ||
											   
				(pVideos[ 18 ][ 0 ] &&  i == 2) ||
											   
				(pVideos[ 19 ][ 0 ] &&  i == 3) ||
											   
				(pVideos[ 20 ][ 0 ] &&  i == 4) ||
											   
				(pVideos[ 21 ][ 0 ] &&  i == 5) ||
											   
				(pVideos[ 22 ][ 0 ] &&  i == 6) ||
											   
				(pVideos[ 23 ][ 0 ] &&  i == 7) ) {

					p_sys_cfg->n_video_encoder_record_mode[ i ] = pVideos[ i + 16 ][ 0 ]->F3D935AFB5C164dac97F5A7CA0150BC60;

					if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 )
					{  
						p_sys_cfg->n_video_encoder_bitrate[ i ] = (pVideos[ i + 16 ][ 0 ]->F65C8BF3BAA2D4fbb876EE33F491F1931)/30;
					}
					else
					{
						p_sys_cfg->n_video_encoder_bitrate[ i ] = (pVideos[ i + 16 ][ 0 ]->F65C8BF3BAA2D4fbb876EE33F491F1931)/25;
					}

					// CALCULATE OUTPUT FPS 
					//
					if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) {

						p_sys_cfg->n_video_encoder_frame_fps_mask[ i ] = cf82fa7a8b1b4a99b0abe8f7a59774e8( pDevice, pVideos[ i + 16 ][ 0 ]->FB4E9A11D151C4d93B0C750EC1BE4C7C5/1000 );

						p_sys_cfg->n_video_encoder_frame_fps_mask_length[ i ] = 30;
					}

					if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) {

						p_sys_cfg->n_video_encoder_frame_fps_mask[ i ] = cf82fa7a8b1b4a99b0abe8f7a59774e8( pDevice, pVideos[ i + 16 ][ 0 ]->FB4E9A11D151C4d93B0C750EC1BE4C7C5/1000 );

						p_sys_cfg->n_video_encoder_frame_fps_mask_length[ i ] = 25;
					}

					ULONG is_skip = FALSE;

					ULONG bit = (ULONG)(p_sys_cfg->n_video_encoder_frame_number[ i ] ) % (p_sys_cfg->n_video_encoder_frame_fps_mask_length[ i ]);

					is_skip = (((1 << bit) & (p_sys_cfg->n_video_encoder_frame_fps_mask[ i ])) == 0) ? TRUE : FALSE;
			
					p_sys_cfg->n_video_encoder_frame_number[ i ]++;

				if( is_skip ) {

					ULONG R00000010 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000010 );

					ULONG j = i & 0x00000003;

					ULONG x = (p_sys_cfg->n_video_encoder_input_buffer_index[ i ] + 1) & 0x00000003;

					R00000010 &= ~((3) << (j * 2)); 
						
					R00000010 |=  ((x) << (j * 2));
						
					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000010, R00000010 ); 

					p_sys_cfg->n_video_encoder_input_buffer_index[ i ] = -1;
				}
				else {

					// [2011.07.12] [HUENGPEI] CBR ALGORITHM BLOCK
					//

//					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "start encode i(0x%x) \n", i );

					//peter
					p_sys_cfg->n_video_encoder_frame_cx[ i ] = pVideos[ i + 16 ][ 0 ]->FD1832F8D382F4e91914C0048CC5A9DD8;
					p_sys_cfg->n_video_encoder_frame_cy[ i ] = pVideos[ i + 16 ][ 0 ]->F5B8891B732954fc2B26B7BFFCB15B596;

					if( p_sys_cfg->n_video_encoder_record_mode[ i ] == 1 ) {//CBR

	//					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "CBR i(0x%x) n_video_encoder_bitrate(0d%d)\n", i, p_sys_cfg->n_video_encoder_bitrate[ i ] );

						ULONG counts = 256; // CBR.WINDOW.SIZE = 256

						ULONG bitrate = 0;

						ULONG j = p_sys_cfg->n_viode_encoder_cbr_frame_size_window_step[ i ];

						if( p_sys_cfg->n_viode_encoder_cbr_frame_size_window[ i ][ j ] == 0 ) {

							counts = j;

							if( counts > 0 ) { bitrate = (ULONG)((ULONG)(p_sys_cfg->n_viode_encoder_cbr_frame_size_sum[ i ] << 3) / (counts)); }
						}
						else {

							bitrate = (ULONG)((p_sys_cfg->n_viode_encoder_cbr_frame_size_sum[ i ] << 3) >> 8); // CBR.WINDOW.SIZE = 256
						}
						if( bitrate > 0 ) {

							if( p_sys_cfg->n_video_encoder_bitrate[ i ] > (bitrate + 1024) ) {

								if( p_sys_cfg->n_video_encoder_qp[ i ] > (p_sys_cfg->n_viode_encoder_cbr_qp_base[ i ] - 4) ) {

									p_sys_cfg->n_video_encoder_qp[ i ]--;

									p_sys_cfg->n_viode_encoder_cbr_qp_base_updated_damping[ i ] = 0;
								}
								else {

									p_sys_cfg->n_viode_encoder_cbr_qp_base_updated_damping[ i ]++;

									if( p_sys_cfg->n_viode_encoder_cbr_qp_base_updated_damping[ i ] > 30 ) {

										p_sys_cfg->n_viode_encoder_cbr_qp_base_updated_damping[ i ] = 0;

										if( (p_sys_cfg->n_viode_encoder_cbr_qp_base[ i ] - 4) > 12 ) {

											p_sys_cfg->n_viode_encoder_cbr_qp_base[ i ]--;
										}
									}
								}
							}
							if( p_sys_cfg->n_video_encoder_bitrate[ i ] < (bitrate - 1024) ) {

								if( p_sys_cfg->n_video_encoder_qp[ i ] < (p_sys_cfg->n_viode_encoder_cbr_qp_base[ i ] + 4) ) {

									p_sys_cfg->n_video_encoder_qp[ i ]++;

									p_sys_cfg->n_viode_encoder_cbr_qp_base_updated_damping[ i ] = 0;
								}
								else {

									p_sys_cfg->n_viode_encoder_cbr_qp_base_updated_damping[ i ]++;

									if( p_sys_cfg->n_viode_encoder_cbr_qp_base_updated_damping[ i ] > 30 ) {

										p_sys_cfg->n_viode_encoder_cbr_qp_base_updated_damping[ i ] = 0;

										if( (p_sys_cfg->n_viode_encoder_cbr_qp_base[ i ] + 4) < 42 ) {

											p_sys_cfg->n_viode_encoder_cbr_qp_base[ i ]++;
										}
									}
								}
							}
	//						if( i == 0 ) { F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "STREAM#%d: BIT.RATE = %d, QP = %d, QP.BASE = %d\n", i, (bitrate * 30), p_sys_cfg->n_video_encoder_qp[ i ], p_sys_cfg->n_viode_encoder_cbr_qp_base[ i ] ); }
						}
					}
				
					ULONG cx = p_sys_cfg->n_video_encoder_frame_cx[ i ] / 16;

					ULONG cy = p_sys_cfg->n_video_encoder_frame_cy[ i ] / 16;

					ULONG qp = p_sys_cfg->n_video_encoder_qp[ i ];

					ULONG ft = (p_sys_cfg->n_video_encoder_gop_step[ i ] == 0) ? 0 : 1;

					ULONG bf = (p_sys_cfg->n_video_encoder_reference_buffer_index[ i ]);

					BOOLEAN  is_sub_stream = (i < 4) ? FALSE : TRUE;

					// -----> OnEncodeFinished() -----> UpdateOSD() [2010.12.05]
					//
					//??????????
					//sprintf crash at kernel 2.6.18, do not know why
					#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)
					b2937aa152e245fe820cf833fa6d3b40( pDevice, i % 8 );
					#endif

					// -----> StartMainEncode() + StartSubEncode() -----> StartFPGAEncode() + StartSubFPGAEncode() -----> ISILH264FpgaSetDeinterlace() [2011.06.24]
					//
					{	ULONG R00000200 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00000200 );

						R00000200 &= ~(0x1F << 4);

						R00000200 &= ~(0x02);

						if( cy >= (480 / 16) ) {

	//						if( pDevice->m_nCustomAnalogVideoDeinterlaceTypeProperty[ i % 8 ] & 0x77FFFFFF ) { R00000200 |= 0x00000002; }
							
							{ R00000200 |= 0x00000002; }//enable de-interlace

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000004, 0x0000005F );

							R00000200 |= 0x00000000;

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000200, R00000200 );
						}
						else if( cx >= (640 / 16) ) {

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000004, 0x0000005F );

							R00000200 |= 0x00000140;

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000200, R00000200 );
						}
						else {

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000004, 0x0000005F );

							R00000200 |= 0x00000150;

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000200, R00000200 );
						}
					}
				
					// -----> StartMainEncode() + StartSubEncode() -----> StartFPGAEncode() + StartSubFPGAEncode() -----> psSendSlice() [2010.12.05]
					//
					UINT p_stream_header[ 4 ] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

					ULONG n_dword_bit_offset = 0;


					if( ft == 0 ) { p_sys_cfg->n_video_encoder_init_qp[ i ] = p_sys_cfg->n_video_encoder_qp[ i ]; }

					if( ft == 0 ) {

						n_dword_bit_offset = psSendSlice( (BYTE *)(p_stream_header), 0, 0, (int)(p_sys_cfg->n_video_encoder_qp[ i ]) - (int)(p_sys_cfg->n_video_encoder_init_qp[ i ]), 0, 1 ) & 31;
					}
					else {

						n_dword_bit_offset = psSendSlice( (BYTE *)(p_stream_header), 0, 0, (int)(p_sys_cfg->n_video_encoder_qp[ i ]) - (int)(p_sys_cfg->n_video_encoder_init_qp[ i ]), 1, 0 ) & 31;
					}

					// -----> StartMainEncode() + StartSubEncode() -----> StartFPGAEncode() + StartSubFPGAEncode() -----> ISILH264FpgaEncoderStartSlice() [2010.12.05]
					//
					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000002C, (i % 4) | 0x00000320 );

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000218, (cx << 8) | (cy << 0) );

					{	ULONG x = (bf);

						ULONG y = (x + 1) % 2;
						
						if( is_sub_stream == TRUE ) { x += 2; }

						if( is_sub_stream == TRUE ) { y += 2; }

						b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000210, (y << 12) | (x << 0) ); // REC.BUF / ENC.REF
					}
					{	ULONG j = p_sys_cfg->n_video_encoder_input_buffer_index[ i ];

						j += 1;

						j %= 4;

						b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000021C, (j << 12) ); // ENC.ORG
					}

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00001000, (n_dword_bit_offset << 8) | (qp) | (0x00008000) );

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000214, TW5864_LAMBDA_TABLE[ qp ] );

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000018, qp );

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000208, 0x00000000 );

					ULONG R00020000 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00020000 );

					if( is_sub_stream == TRUE ) {

						if( R00020000 & (1 << 22) ) {

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000410, 0x00000070 ); // BOTH 16X16 & 4X4

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000414, TW5864_INTRA4X4_LAMBDA_TABLE[ qp ] );
						}
						else {

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000410, 0x00000060 ); // ONLY 16X16
						}
					}
					else {

						if( R00020000 & (1 << 6) ) {

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000410, 0x00000070 ); // BOTH 16X16 & 4X4

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000414, TW5864_INTRA4X4_LAMBDA_TABLE[ qp ] );
						}
						else {

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000410, 0x00000060 ); // ONLY 16X16
						}
					}
					ULONG R0000020C = 0x00000008;

					if( ft == 1 ) {

						R0000020C |= 0x000000A4;

						if( is_sub_stream == TRUE ) {

							if( R00020000 & (1 << 23) ) {

								b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000410, 0x00000070 ); // BOTH 16X16 & 4X4

								b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000414, TW5864_INTRA4X4_LAMBDA_TABLE[ qp ] );
							}
							else {

								b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000410, 0x00000060 ); // ONLY 16X16
							}
							if( R00020000 & (1 << 17) ) { R0000020C |= (1 << 1); } else { R0000020C &= ~(1 << 1); }

							if( R00020000 & (1 << 19) ) { R0000020C |= (1 << 0); } else { R0000020C &= ~(1 << 0); }

							if( R00020000 & (1 << 21) ) { R0000020C |= (1 << 4); } else { R0000020C &= ~(1 << 4); }
						}
						else {

							if( R00020000 & (1 << 7) ) {

								b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000410, 0x00000070 ); // BOTH 16X16 & 4X4

								b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000414, TW5864_INTRA4X4_LAMBDA_TABLE[ qp ] );
							}
							else {

								b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00000410, 0x00000060 ); // ONLY 16X16
							}
							if( R00020000 & (1 << 1) ) { R0000020C |= (1 << 1); } else { R0000020C &= ~(1 << 1); }

							if( R00020000 & (1 << 3) ) { R0000020C |= (1 << 0); } else { R0000020C &= ~(1 << 0); }

							if( R00020000 & (1 << 5) ) { R0000020C |= (1 << 4); } else { R0000020C &= ~(1 << 4); }
						}
					}
					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000020C,  R0000020C );

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000000C, 0x00008000 );

					b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000000C, 0x00000000 );

//TW5864 encode
					//if(p_sys_cfg->n_preview_video_satrt > TW5864_DROP_H264)
					{
						p_sys_cfg->n_video_encoder_gop_step[ i ]++;

						p_sys_cfg->n_H264_output_enable = 1;

					}

					p_sys_cfg->n_video_encoder_reference_buffer_index[ i ]++;

					p_sys_cfg->n_video_encoder_reference_buffer_index[ i ] %= 2;

					if( p_sys_cfg->n_video_encoder_gop_step[ i ] >= p_sys_cfg->n_video_encoder_gop[ i ] ) {

						p_sys_cfg->n_video_encoder_gop_step[ i ] = 0;
					}
					pDevice->F03D1DD650AC64c28B04687338F970D0E[ 1 ] = (ft == 0) ? (0x80000000 + i + 1) : (i + 1); // LOCK ENCODER

					pDevice->F66FD293166B14f93A084AE0E6BD0F196[ 1 ] = 0;
			
				}
			}
		}
	}
	return TRUE;
}

BOOLEAN e3893c33768249bf80049109b1ca7e11( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, F170997530C6943659ECE8DEC21301F66 * pVideoBuffer )
{
//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "e3893c33768249bf80049109b1ca7e11() bsize(0d%d) \n", pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize );

	BYTE * po = NULL;

	#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

	BYTE * pe = videobuf_to_vmalloc( &pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B );

	if( pe == NULL ) { return TRUE; }

	// COPY VIDEO FRAME TO VIDEO BUFFER 
	//
	{	

//[1][1]  [2][2]  [3][3]  [4][4]
//[352*288*3/2][352*288*3/2]  [352*288*3/2][352*288*3/2]  [352*288*3/2][352*288*3/2]  [352*288*3/2][352*288*3/2]

//     CH0A           CH0B    
// [704*576*3/2] [704*576*3/2]  
//     CH1A           CH1B
// [704*576*3/2] [704*576*3/2]

//peter [2011.06.03]
		ULONG cxe = 704;

		ULONG cye = 480;

		if( pVideo->FD1832F8D382F4e91914C0048CC5A9DD8 == 704 )
		{
//			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) { cye = 480; }

//			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) { cye = 576; }

			if( pVideo->F5B8891B732954fc2B26B7BFFCB15B596 >= 240 ) { cye = pVideo->F5B8891B732954fc2B26B7BFFCB15B596;}
		}
		else
		{
			cxe = 352;

			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) { cye = 240; }

			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) { cye = 288; }

		}

		if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 2) == (0) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 5 ]; } //12345

		if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 2) == (1) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ]; }  //12345

		if( pe && po ) {

			if( (cxe * cye * 3 / 2) <= pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize)
			{
				memcpy( pe, po, (cxe * cye) ); 

				po += (cxe * cye);

				BYTE * pe_v = pe + (cxe * cye);

				BYTE * pe_u = pe + (cxe * cye) + (cxe * cye / 4);

				ULONG  size = (cxe * cye) / 4;

				ULONG j = 0 ;
				for( j = 0 ; j < size ; j++ ) {

					*pe_u++ = *po++;

					*pe_v++ = *po++;
				}
			}
			else
			{
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] e3893c33768249bf80049109b1ca7e11() buffer size error, need (0d%d) got(0d%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) , (cxe * cye * 3 / 2), pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.bsize);
			}
		}
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	#else

	struct videobuf_dmabuf * F9FF98D32C15242b8979B2F47C7F951BE = &(pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.dma);

	struct scatterlist * F1A9C3A4F207F456cAFB0163C5F30C91D = (struct scatterlist *)(F9FF98D32C15242b8979B2F47C7F951BE->sglist);

	ULONG  F08220F0B4E654ce48460AA8A5F049BFB = F9FF98D32C15242b8979B2F47C7F951BE->sglen;

	ULONG  pages = 0;

	ULONG  F2B6709824D504332834A012BCBE1945D = sg_dma_len( F1A9C3A4F207F456cAFB0163C5F30C91D );

	ULONG  FF7E121E5F6A1461dA967001C1404EB52 = pVideo->FD1832F8D382F4e91914C0048CC5A9DD8 * pVideo->F5B8891B732954fc2B26B7BFFCB15B596 * 12 >> 3;

	ULONG cxe = 704;

	ULONG cye = 480;

	if( pVideo->FD1832F8D382F4e91914C0048CC5A9DD8 == 704 )
	{
		if( pVideo->F5B8891B732954fc2B26B7BFFCB15B596 >= 240 ) { cye = pVideo->F5B8891B732954fc2B26B7BFFCB15B596;}
	}
	else
	{
		cxe = 352;

		if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) { cye = 240; }

		if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) { cye = 288; }

	}

	if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 2) == (0) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 5 ]; } //12345

	if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input % 2) == (1) ) { po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 ]; }  //12345

	//original data is (cxe * cye) Y, then uvuvuv
	if(	pDevice->F41F19BDAA144449fA254B8E3282D1425[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 9 ] )
	{
		memcpy( pDevice->F41F19BDAA144449fA254B8E3282D1425[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 9 ] , po, (cxe * cye) ); 

		po += (cxe * cye);

		BYTE * pe_v = pDevice->F41F19BDAA144449fA254B8E3282D1425[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 9 ] + (cxe * cye);

		BYTE * pe_u = pDevice->F41F19BDAA144449fA254B8E3282D1425[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 9 ] + (cxe * cye) + (cxe * cye / 4);
		
		ULONG  size = (cxe * cye) / 4;

		ULONG j = 0 ;
		for( j = 0 ; j < size ; j++ ) {

			*pe_u++ = *po++;

			*pe_v++ = *po++;
		}
		po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ pVideo->F0DD7393CD1494e27A72652C7D1A97893 + 9 ];
	}

	BYTE * pe = kmap_atomic( F1A9C3A4F207F456cAFB0163C5F30C91D->page, KM_USER0 ); //

	if( pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state != VIDEOBUF_QUEUED ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "pe state error(%x)\n", pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state ); return TRUE; }

	while( FF7E121E5F6A1461dA967001C1404EB52 > 0 ) {

		if( (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
		{	
			memcpy( pe, po + pages * 4096, F2B6709824D504332834A012BCBE1945D ); 
		}

		kunmap_atomic( F1A9C3A4F207F456cAFB0163C5F30C91D->page, KM_USER0 );

		pages++;

		FF7E121E5F6A1461dA967001C1404EB52 -= F2B6709824D504332834A012BCBE1945D;

		F1A9C3A4F207F456cAFB0163C5F30C91D++;
		
		if( pages < F08220F0B4E654ce48460AA8A5F049BFB ) {

			pe = kmap_atomic( F1A9C3A4F207F456cAFB0163C5F30C91D->page, KM_USER0 );

			F2B6709824D504332834A012BCBE1945D = sg_dma_len( F1A9C3A4F207F456cAFB0163C5F30C91D );
		}
		else
		{
			break;
		}
	}

	#endif

	pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input = 0xFFFFFFFF; //

	return TRUE;
}

BOOLEAN e08691f8c8594763a7fbd04765388c57( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, ULONG status, ULONG mask, FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudios[ F03706E45925547d799BA016E4F0F6D6B ], FFE3034C8E38D40dbAF3D2CD6E461C55C * pAudioBuffers[ F03706E45925547d799BA016E4F0F6D6B ], BOOLEAN p_FDFC345768E394d138EA574DEB55B7949s[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ], BOOLEAN F6E2E659AAB8C4494A193C313276DAA65[ F91863BEB45D34624A724F2D29823D9E3 ][ MAX_DEVICE_OPEN_NUM ] )
{
	if( status & 0x00000100 ) {

//		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "e08691f8c8594763a7fbd04765388c57() status(0x%x) mask(0x%x)\n" , status, mask );

		TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		ULONG R00018008 = (mask >>  0) & 0x0000FFFF;

		ULONG R00018010 = (mask >> 16) & 0x0000FFFF;
	
		BYTE * memory_address = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 4 ] + ba98f190f54d44ba894e79c3bc107b50 - (2048 * 4 * 2) - (4096); // 56789

		ULONG i = 0;

		BOOLEAN FDFC345768E394d138EA574DEB55B7949 = FALSE;

		BOOLEAN F59CB3A66AD1E4f97AF28A84D74E460D3 = FALSE;

		BYTE *  po = NULL;

		BYTE *  pe = NULL;

		FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio = NULL;

		for( i = 0 ; i < 4 ; i++ ) {

			if( (R00018008 >> i) & 0x01 ) {
				
				pAudio = pAudios[ i ];

				ULONG j = (R00018010 >> i) & 0x01;

				po = memory_address + 512 * i + 2048 * 4 * j; 
				
				F59CB3A66AD1E4f97AF28A84D74E460D3 = TRUE; 
				
				FDFC345768E394d138EA574DEB55B7949 = TRUE;

				if(pAudio == NULL)
				{

					goto EXIT;
				}

				if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[0])
				{
					if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[0]->runtime)
					{
						if(pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[0]->runtime->dma_area)
						{
							pe = pAudio->F823E5E1F924443f8AD2BC9CBED4CE613[0]->runtime->dma_area;				
						}				
						else
						{
							goto EXIT;
						}
					}		
					else
					{
						goto EXIT;
					}
				}
				else
				{
					goto EXIT;
				}
							

				ULONG   sz = 498;

				if( F59CB3A66AD1E4f97AF28A84D74E460D3 ) {

					if( pe ) {

						pe += pAudio->F6578ACFCB40E44819A12FD3E27A48085[0] * pAudio->F1461B75D9C644717A130B5C10D966CF0;
								
						memcpy( pe, po, sz );

						//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "e08691f8c8594763a7fbd04765388c57() R00018008(0x%x) sz(0d%d)  ----- %d ----- %d, i(%d)\n" , R00018008, sz, pAudio->F6578ACFCB40E44819A12FD3E27A48085, pAudio->F1461B75D9C644717A130B5C10D966CF0, i );
					}
				}

				p_FDFC345768E394d138EA574DEB55B7949s[ i ][ 0 ] = FDFC345768E394d138EA574DEB55B7949;

			}
			else
			{
				//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "R00018008() >> i(0x%x) is not 1\n" , i );
			}
		}

		if( R00018008 == 0x00000000 ) {

			ULONG R0000404C = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000404C );

			R0000404C &= 0xFFFDFFFF;

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000404C, R0000404C | 0x00020000 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000404C, R0000404C );
		}

		return TRUE;

EXIT:


		if( R00018008 == 0x00000000 ) {

			ULONG R0000404C = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000404C );

			R0000404C &= 0xFFFDFFFF;

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000404C, R0000404C | 0x00020000 );

			b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000404C, R0000404C );
		}
	}

	return FALSE;
}



BOOLEAN ef27344a3deb4785b7467dc69926a0f8( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, F170997530C6943659ECE8DEC21301F66 * pVideoBuffer )
{
	//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "ef27344a3deb4785b7467dc69926a0f8() size(0d%d)\n", pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.size ); 

	BOOLEAN status = STATUS_UNSUCCESSFUL;

	#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,24)

	BYTE * po = NULL;

	BYTE * pe = videobuf_to_vmalloc( &pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B );

//	ULONG  co = pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.size;

//	ULONG  ce = pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.bytesperline * pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.height;

	if( pe == NULL ) { 	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "ef27344a3deb4785b7467dc69926a0f8() no dest buffer\n" ); return TRUE; }

	TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	ULONG  i = pVideo->F0DD7393CD1494e27A72652C7D1A97893;


	ULONG  n_picture_number = (p_sys_cfg->n_video_encoder_gop[ i ] + p_sys_cfg->n_video_encoder_gop_step[ i ] - 1) % p_sys_cfg->n_video_encoder_gop[ i ];

//check frame loss 
/*
	if( p_sys_cfg->n_picture_number_to_user[ i ] == 0 )//first time
	{
		p_sys_cfg->n_picture_number_to_user[ i ] = n_picture_number;
	}
	else
	{
		p_sys_cfg->n_picture_number_to_user[ i ]++;
	}
	

	if( n_picture_number != ( p_sys_cfg->n_picture_number_to_user[ i ] % p_sys_cfg->n_video_encoder_gop[ i ]) )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%d] EncoderFrame(%d) error, previous(%d) now(%d)\n" ,(int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), i, p_sys_cfg->n_picture_number_to_user[i],  n_picture_number);
		p_sys_cfg->n_picture_number_to_user[ i ] = n_picture_number;
	}
*/


//	BYTE * p_stream_buffer = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 1 ]; // 56789
//peter[2011.06.03]
	BYTE * p_stream_buffer = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 4 ]; // 56789

	ULONG  counts = 0;

	if( pe ) { 

		UINT  p_sps_stream_header[ 4 ] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		UINT  p_pps_stream_header[ 4 ] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		UINT  p_stream_header[ 4 ] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		UINT  F12C7345F5F5944bd9BF6C72DBEF85387 = *(UINT *)(p_stream_buffer);

		UINT  bits = 0;

		UINT  init_qp = p_sys_cfg->n_video_encoder_init_qp[ i ];
	
		UINT  qp = p_sys_cfg->n_video_encoder_qp[ i ];

		UINT  n_dword_bit_offset = 0;

		if( pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input & 0x80000000 ) {

			bits = psSendSeqParameterSet( (BYTE *)(p_sps_stream_header), p_sys_cfg->n_video_encoder_frame_cx[ i ], p_sys_cfg->n_video_encoder_frame_cy[ i ] );

			memcpy( pe + counts + 4, p_sps_stream_header, (((bits + 31) >> 5) * 4) );

			counts += (((bits + 31) >> 5) * 4);

			bits = psSendPicParameterSet( (BYTE *)(p_pps_stream_header),init_qp );

			memcpy( pe + counts + 4, p_pps_stream_header, (((bits + 31) >> 5) * 4) );

			counts += (((bits + 31) >> 5) * 4);

			bits = psSendSlice( (BYTE *)(p_stream_header), n_picture_number, n_picture_number * 2, (int)(qp) - (int)(init_qp), 0, 1 );

			n_dword_bit_offset = bits & 31;

			F12C7345F5F5944bd9BF6C72DBEF85387 = _byteswap_ulong(F12C7345F5F5944bd9BF6C72DBEF85387);

			F12C7345F5F5944bd9BF6C72DBEF85387 &= ((UINT)-1) >> n_dword_bit_offset;

			F12C7345F5F5944bd9BF6C72DBEF85387 = _byteswap_ulong(F12C7345F5F5944bd9BF6C72DBEF85387);

			p_stream_header[ (bits >> 5) ] |= F12C7345F5F5944bd9BF6C72DBEF85387;

			memcpy( pe + counts + 4, p_stream_header, ((bits >> 5) + 1) * sizeof(UINT) );

			counts += ((bits >> 5) + 1) * sizeof(UINT);

//			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "ef27344a3deb4785b7467dc69926a0f8() copy key header,i(0x%x)\n", i );

		}
		else {

			bits = psSendSlice( (BYTE *)(p_stream_header), n_picture_number, n_picture_number * 2, (int)(qp) - (int)(init_qp), 1, 0 );

			n_dword_bit_offset = bits & 31;

			F12C7345F5F5944bd9BF6C72DBEF85387 = _byteswap_ulong(F12C7345F5F5944bd9BF6C72DBEF85387);

			F12C7345F5F5944bd9BF6C72DBEF85387 &= ((UINT)-1) >> n_dword_bit_offset;

			F12C7345F5F5944bd9BF6C72DBEF85387 = _byteswap_ulong(F12C7345F5F5944bd9BF6C72DBEF85387);

			p_stream_header[ (bits >> 5) ] |= F12C7345F5F5944bd9BF6C72DBEF85387;

			memcpy( pe + counts + 4, p_stream_header, ((bits >> 5) + 1) * sizeof(UINT) );

			counts += ((bits >> 5) + 1) * sizeof(UINT);

//			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "ef27344a3deb4785b7467dc69926a0f8() copy non key header, i(%d) n_picture_number(0d%d)\n", i, n_picture_number );

		}

	}


	if( pe && pVideo && pVideoBuffer ) { 

//		co = (counts) + TW5864_COPY_NAL( pe + counts, p_stream_buffer + 4, n_stream_buffer_length - 4 );

//		TW5864_COPY_NAL( pe + counts + 4, p_stream_buffer + 4 , (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input & 0x7FFFFFFF) - 4 );//chip spec
//peter [2011.08.03]
		counts += TW5864_COPY_NAL( pe + counts + 4, p_stream_buffer  + 4, (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input & 0x7FFFFFFF) - 4, p_stream_buffer + (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input & 0x7FFFFFFF));//chip spec
		
//		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "ef27344a3deb4785b7467dc69926a0f8() copy stream, counts(0x%x) size(0x%x)\n", counts, (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input & 0x7FFFFFFF) - 4 );

	}

	//
	//
	{	
		TW5864_H264_STREAM_HEADER hdr;
	
//		hdr.nFrameBufferSize = (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input & 0x7FFFFFFF) - 4 + counts;
		hdr.nFrameBufferSize = counts;

		hdr.nFrameType = (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input & 0x80000000) ? (0) : (1);

//		hdr.nMotionStatus = F5DCAF3AAB0BA4f659145B0B8C7EB74F6[ i ];

//		hdr.nLockStatus = FC9D92723A8E44565883875F77CA4E561[ i ];
	
		hdr.nReserved = 0x00;

		memcpy( pe, &hdr, 4 );

	}
	
//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "finish copy\n" );

	// [2011.07.12] CBR ALGORITHM BLOCK
	//
	{
		ULONG j = p_sys_cfg->n_viode_encoder_cbr_frame_size_window_step[ i ];

		p_sys_cfg->n_viode_encoder_cbr_frame_size_sum[ i ] -= p_sys_cfg->n_viode_encoder_cbr_frame_size_window[ i ][ j ];

		p_sys_cfg->n_viode_encoder_cbr_frame_size_sum[ i ] += counts;

		p_sys_cfg->n_viode_encoder_cbr_frame_size_window[ i ][ j ] = counts;

		p_sys_cfg->n_viode_encoder_cbr_frame_size_window_step[ i ] = (p_sys_cfg->n_viode_encoder_cbr_frame_size_window_step[ i ] + 1) & 0x000000FF; // CBR.WINDOW.SIZE = 256

		{	ULONG _counts = 256; // CBR.WINDOW.SIZE = 256

			j = p_sys_cfg->n_viode_encoder_cbr_frame_size_window_step[ i ];

			if( p_sys_cfg->n_viode_encoder_cbr_frame_size_window[ i ][ j ] == 0 ) {

				_counts = j;

			//	if( i == 0 && _counts > 0 ) { AMEBDAD_PRINT( ("STREAM#%d: BIT.RATE = %d\n", i, (ULONG)((p_sys_cfg->n_viode_encoder_cbr_frame_size_sum[ i ] * 8 * 30) / _counts)) ); }
			}
			else {

			//	if( i == 0 ) { AMEBDAD_PRINT( ("STREAM#%d: BIT.RATE = %d\n", i, (ULONG)((p_sys_cfg->n_viode_encoder_cbr_frame_size_sum[ i ] * 8 * 30) >> 8)) ); } // CBR.WINDOW.SIZE = 256
			}
		}
	}

	pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input = 0xFFFFFFFF;

	pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.size = counts + 4; //header, later will be stripped by AP

	#else

	BYTE * po = NULL;

	BYTE * pe = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 13 ];

	if( pe == NULL ) { 	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "ef27344a3deb4785b7467dc69926a0f8() no dest buffer\n" ); return TRUE; }

	TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

	ULONG  i = pVideo->F0DD7393CD1494e27A72652C7D1A97893;

	ULONG  n_picture_number = (p_sys_cfg->n_video_encoder_gop[ i ] + p_sys_cfg->n_video_encoder_gop_step[ i ] - 1) % p_sys_cfg->n_video_encoder_gop[ i ];

	BYTE * p_stream_buffer = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 4 ]; // 56789

	ULONG  counts = 0;

	if( pe ) { 

		UINT  p_sps_stream_header[ 4 ] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		UINT  p_pps_stream_header[ 4 ] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		UINT  p_stream_header[ 4 ] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

		UINT  F12C7345F5F5944bd9BF6C72DBEF85387 = *(UINT *)(p_stream_buffer);

		UINT  bits = 0;

		UINT  init_qp = p_sys_cfg->n_video_encoder_init_qp[ i ];
	
		UINT  qp = p_sys_cfg->n_video_encoder_qp[ i ];

		UINT  n_dword_bit_offset = 0;

		if( pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input & 0x80000000 ) {

			bits = psSendSeqParameterSet( (BYTE *)(p_sps_stream_header), p_sys_cfg->n_video_encoder_frame_cx[ i ], p_sys_cfg->n_video_encoder_frame_cy[ i ] );

			memcpy( pe + counts + 4, p_sps_stream_header, (((bits + 31) >> 5) * 4) );

			counts += (((bits + 31) >> 5) * 4);

			bits = psSendPicParameterSet( (BYTE *)(p_pps_stream_header),init_qp );

			memcpy( pe + counts + 4, p_pps_stream_header, (((bits + 31) >> 5) * 4) );

			counts += (((bits + 31) >> 5) * 4);

			bits = psSendSlice( (BYTE *)(p_stream_header), n_picture_number, n_picture_number * 2, (int)(qp) - (int)(init_qp), 0, 1 );

			n_dword_bit_offset = bits & 31;

			F12C7345F5F5944bd9BF6C72DBEF85387 = _byteswap_ulong(F12C7345F5F5944bd9BF6C72DBEF85387);

			F12C7345F5F5944bd9BF6C72DBEF85387 &= ((UINT)-1) >> n_dword_bit_offset;

			F12C7345F5F5944bd9BF6C72DBEF85387 = _byteswap_ulong(F12C7345F5F5944bd9BF6C72DBEF85387);

			p_stream_header[ (bits >> 5) ] |= F12C7345F5F5944bd9BF6C72DBEF85387;

			memcpy( pe + counts + 4, p_stream_header, ((bits >> 5) + 1) * sizeof(UINT) );

			counts += ((bits >> 5) + 1) * sizeof(UINT);

//			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "ef27344a3deb4785b7467dc69926a0f8() copy key header,i(0x%x)\n", i );

		}
		else {

			bits = psSendSlice( (BYTE *)(p_stream_header), n_picture_number, n_picture_number * 2, (int)(qp) - (int)(init_qp), 1, 0 );

			n_dword_bit_offset = bits & 31;

			F12C7345F5F5944bd9BF6C72DBEF85387 = _byteswap_ulong(F12C7345F5F5944bd9BF6C72DBEF85387);

			F12C7345F5F5944bd9BF6C72DBEF85387 &= ((UINT)-1) >> n_dword_bit_offset;

			F12C7345F5F5944bd9BF6C72DBEF85387 = _byteswap_ulong(F12C7345F5F5944bd9BF6C72DBEF85387);

			p_stream_header[ (bits >> 5) ] |= F12C7345F5F5944bd9BF6C72DBEF85387;

			memcpy( pe + counts + 4, p_stream_header, ((bits >> 5) + 1) * sizeof(UINT) );

			counts += ((bits >> 5) + 1) * sizeof(UINT);

//			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "ef27344a3deb4785b7467dc69926a0f8() copy non key header, i(%d) n_picture_number(0d%d)\n", i, n_picture_number );

		}

	}


	if( pe && pVideo && pVideoBuffer ) { 

//		co = (counts) + TW5864_COPY_NAL( pe + counts, p_stream_buffer + 4, n_stream_buffer_length - 4 );

//		TW5864_COPY_NAL( pe + counts + 4, p_stream_buffer + 4 , (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input & 0x7FFFFFFF) - 4 );//chip spec
//peter [2011.08.03]
		counts += TW5864_COPY_NAL( pe + counts + 4, p_stream_buffer  + 4, (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input & 0x7FFFFFFF) - 4, p_stream_buffer + (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input & 0x7FFFFFFF));//chip spec
		
//		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "ef27344a3deb4785b7467dc69926a0f8() copy stream, counts(0x%x) size(0x%x)\n", counts, (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input & 0x7FFFFFFF) - 4 );

	}

	//
	//
	{	
		TW5864_H264_STREAM_HEADER hdr;
	
//		hdr.nFrameBufferSize = (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input & 0x7FFFFFFF) - 4 + counts;
		hdr.nFrameBufferSize = counts;

		hdr.nFrameType = (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input & 0x80000000) ? (0) : (1);

//		hdr.nMotionStatus = F5DCAF3AAB0BA4f659145B0B8C7EB74F6[ i ];

//		hdr.nLockStatus = FC9D92723A8E44565883875F77CA4E561[ i ];
	
		hdr.nReserved = 0x00;

		memcpy( pe, &hdr, 4 );

	}

	struct videobuf_dmabuf * F9FF98D32C15242b8979B2F47C7F951BE = &(pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.dma);

	struct scatterlist * F1A9C3A4F207F456cAFB0163C5F30C91D = (struct scatterlist *)(F9FF98D32C15242b8979B2F47C7F951BE->sglist);

	ULONG  F08220F0B4E654ce48460AA8A5F049BFB = F9FF98D32C15242b8979B2F47C7F951BE->sglen;

	ULONG  pages = 0;

	ULONG  F2B6709824D504332834A012BCBE1945D = sg_dma_len( F1A9C3A4F207F456cAFB0163C5F30C91D );

	ULONG  FF7E121E5F6A1461dA967001C1404EB52 = counts + 4;

	//reset po, pe
	po = pDevice->F41F19BDAA144449fA254B8E3282D1425[ 13 ];

	pe = kmap_atomic( F1A9C3A4F207F456cAFB0163C5F30C91D->page, KM_USER0 ); //

	if( pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state != VIDEOBUF_QUEUED ) { F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "pe state error(%x)\n", pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state ); return TRUE; }

	while( FF7E121E5F6A1461dA967001C1404EB52 > 0 ) {

		if( (pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 != 0) && (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED) )
		{	
			memcpy( pe, po + pages * 4096, F2B6709824D504332834A012BCBE1945D ); 
		}

		kunmap_atomic( F1A9C3A4F207F456cAFB0163C5F30C91D->page, KM_USER0 );

		pages++;

		FF7E121E5F6A1461dA967001C1404EB52 -= F2B6709824D504332834A012BCBE1945D;

		F1A9C3A4F207F456cAFB0163C5F30C91D++;
		
		if( pages < F08220F0B4E654ce48460AA8A5F049BFB ) {

			pe = kmap_atomic( F1A9C3A4F207F456cAFB0163C5F30C91D->page, KM_USER0 );

			F2B6709824D504332834A012BCBE1945D = sg_dma_len( F1A9C3A4F207F456cAFB0163C5F30C91D );
		}
		else
		{
			break;
		}
	}

//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "finish copy\n" );

	// [2011.07.12] CBR ALGORITHM BLOCK
	//
	{
		ULONG j = p_sys_cfg->n_viode_encoder_cbr_frame_size_window_step[ i ];

		p_sys_cfg->n_viode_encoder_cbr_frame_size_sum[ i ] -= p_sys_cfg->n_viode_encoder_cbr_frame_size_window[ i ][ j ];

		p_sys_cfg->n_viode_encoder_cbr_frame_size_sum[ i ] += counts;

		p_sys_cfg->n_viode_encoder_cbr_frame_size_window[ i ][ j ] = counts;

		p_sys_cfg->n_viode_encoder_cbr_frame_size_window_step[ i ] = (p_sys_cfg->n_viode_encoder_cbr_frame_size_window_step[ i ] + 1) & 0x000000FF; // CBR.WINDOW.SIZE = 256

		{	ULONG _counts = 256; // CBR.WINDOW.SIZE = 256

			j = p_sys_cfg->n_viode_encoder_cbr_frame_size_window_step[ i ];

			if( p_sys_cfg->n_viode_encoder_cbr_frame_size_window[ i ][ j ] == 0 ) {

				_counts = j;

			//	if( i == 0 && _counts > 0 ) { AMEBDAD_PRINT( ("STREAM#%d: BIT.RATE = %d\n", i, (ULONG)((p_sys_cfg->n_viode_encoder_cbr_frame_size_sum[ i ] * 8 * 30) / _counts)) ); }
			}
			else {

			//	if( i == 0 ) { AMEBDAD_PRINT( ("STREAM#%d: BIT.RATE = %d\n", i, (ULONG)((p_sys_cfg->n_viode_encoder_cbr_frame_size_sum[ i ] * 8 * 30) >> 8)) ); } // CBR.WINDOW.SIZE = 256
			}
		}
	}

	pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.input = 0xFFFFFFFF;

	pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.size = counts + 4; //header, later will be stripped by AP
	#endif



	return TRUE;
}

void c6c3937b81f94efaa887c881fbb5fb63( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo )
{

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "c6c3937b81f94efaa887c881fbb5fb63()\n" );

	if( 1 ) {

		if( pDevice->iManufacturer != 0xB8 ) {

			ULONG i = pVideo->F0DD7393CD1494e27A72652C7D1A97893;

			{
//??				
				if( (i < 4) && (pVideo->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001) ) { // YV12

					ULONG cx_e = pVideo->FD1832F8D382F4e91914C0048CC5A9DD8;

					ULONG cy_e = pVideo->F5B8891B732954fc2B26B7BFFCB15B596;

					ULONG cx = 0;

					ULONG cy = 0;

					if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_525_60 ) {

						if( cx_e == 704 && cy_e == 576 ) { cx = 704; cy = 480; } else

						if( cx_e == 704 && cy_e == 480 ) { cx = 704; cy = 480; } else

						if( cx_e == 704 && cy_e == 288 ) { cx = 704; cy = 240; } else

						if( cx_e == 704 && cy_e == 240 ) { cx = 704; cy = 240; } else

						if( cx_e == 352 && cy_e == 288 ) { cx = 352; cy = 240; } else

						if( cx_e == 352 && cy_e == 240 ) { cx = 352; cy = 240; } else

														 { cx = 352; cy = 240; }
					}
			
					if( pDevice->FD314ADAD9404496b842EBFC396E875CB & V4L2_STD_625_50 ) {
	
						if( cx_e == 704 && cy_e == 576 ) { cx = 704; cy = 576; } else

						if( cx_e == 704 && cy_e == 480 ) { cx = 704; cy = 576; } else

						if( cx_e == 704 && cy_e == 288 ) { cx = 704; cy = 288; } else

						if( cx_e == 704 && cy_e == 240 ) { cx = 704; cy = 288; } else

						if( cx_e == 352 && cy_e == 288 ) { cx = 352; cy = 288; } else

						if( cx_e == 352 && cy_e == 240 ) { cx = 352; cy = 288; } else

														 { cx = 352; cy = 288; }
					}
					F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "%d PREVIEW: RESOLUTION = %d x %d\n", i, cx, cy );

					ULONG R0000C008 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000C008 );

					ULONG R0000C020 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000C020 );

					ULONG R0000C024 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x0000C024 );

					if( cx == 720 || cx == 704 ) {

						b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C008, R0000C008 & ~(1 << i) );

						if( i < 8 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C020, R0000C020 & ~(3 << ((i - 0) * 2)) ); }

						if( i > 7 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C024, R0000C024 & ~(3 << ((i - 8) * 2)) ); }
					}
					if( cx == 360 || cx == 352 ) {

						b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C008, R0000C008 | (1 << i) );

						if( i < 8 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C020, R0000C020 | (3 << ((i - 0) * 2)) ); }

						if( i > 7 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C024, R0000C024 | (3 << ((i - 8) * 2)) ); }
					}
					if( cx == 180 || cx == 176 ) {

						b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C008, R0000C008 | (1 << i) );

						if( i < 8 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C020, R0000C020 | (1 << ((i - 0) * 2)) ); }

						if( i > 7 ) { b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x0000C024, R0000C024 | (1 << ((i - 8) * 2)) ); }
					}
					static UINT TW5864_IN_SELECT_REG_TABLE_04CH[ 16 ] = { 0x00000004, 0x00000005, 0x00000000, 0x00000006, 0x00000001, 0x00000007, 0x00000008, 0x00000009, 0x00000002, 0x0000000A, 0x0000000B, 0x0000000C, 0x00000003, 0x0000000D, 0x0000000E, 0x0000000F };

					static UINT TW5864_IN_MAP_REG_TABLE_04CH[ 16 ]    = { 0x00000000, 0x00000000, 0x3FFFFFFF, 0x00000000, 0x3FFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x3FFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0x3FFFFFFF, 0x00000000, 0x00000000, 0x00000000 };

				//	static UINT TW5864_IN_FMT_REG_TABLE_04CH[ 16 ]    = { 0x00000005, 0x00000005, 0x00000001, 0x00000005, 0x00000001, 0x00000005, 0x00000005, 0x00000005, 0x00000001, 0x00000005, 0x00000005, 0x00000005, 0x00000001, 0x00000005, 0x00000005, 0x00000005 };

					static UINT TW5864_IN_FMT_REG_TABLE_04CH[ 16 ]    = {        176,        176,        704,        176,        704,        176,        176,        176,        704,        176,        176,        176,        704,        176,        176,        176 };

					{	ULONG R00018044 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018044 );

						if( cx == 720 ) { R00018044 |=  (3 << (i * 2)); R00018044 &= ~(1 << (i + 8)); }

						if( cx == 704 ) { R00018044 |=  (2 << (i * 2)); R00018044 &= ~(1 << (i + 8)); }

						if( cx == 360 ) { R00018044 &= ~(3 << (i * 2)); R00018044 |=  (1 << (i + 8)); }

						if( cx == 352 ) { R00018044 &= ~(3 << (i * 2)); R00018044 |=  (1 << (i + 8)); }

						if( cx == 180 ) { R00018044 |=  (1 << (i * 2)); R00018044 |=  (1 << (i + 8)); }

						if( cx == 176 ) { R00018044 |=  (1 << (i * 2)); R00018044 |=  (1 << (i + 8)); }

						if( cx ==   0 ) { R00018044 |=  (1 << (i * 2)); R00018044 |=  (1 << (i + 8)); }

						b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018044, R00018044 );
					}

					{	if( cx == 704 && i == 0 ) {

							ULONG R00018044 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018044 );

							R00018044 |=  (2 << 13); // 這段程式有縮簡 

							R00018044 &= ~(1 << 15); // 這段程式有縮簡

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018044, R00018044 );
						}
						if( cx == 352 && i == 0 ) {

							ULONG R00018044 = c3c09a67df944bec9b42209724048dc4( pDevice, 0x00018044 );

							R00018044 &= ~(3 << 13); // 這段程式有縮簡 

							R00018044 |=  (1 << 15); // 這段程式有縮簡

							b13825e2dd0b4ba4a5c7741536f21277( pDevice, 0x00018044, R00018044 );
						}
					}



				}
			}
		}
	}

}
static int d0bd7a0449e54c36b37ec614ee17f971( void * FD51B2B4E0CAC4359A9EFA429A9E16157 )
{
	ULONG counts = 0;

	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)FD51B2B4E0CAC4359A9EFA429A9E16157;

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] d0bd7a0449e54c36b37ec614ee17f971( enter ) - %08X\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(pDevice->m_pControlThread) );

	while( kthread_should_stop() == FALSE ) {

		if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 0 ) {


			TW5864_SYS_CFG * p_sys_cfg = (TW5864_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

			ULONG R00000388 = c18095576e1242d39e06f837c6599bee( pDevice, (0x00000388 << 2) );

			pDevice->m_nAnalogVideoDecoderStatusProperty = (~R00000388) & 0x0000000F;

			// MOTION DETECTION STATUS
			//
			ULONG i = 0;

			for( i = 0 ; i < 4 ; i++ ) {

				ULONG status[ 6 ] = { 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000 };

				c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, 0x00000382 << 2, i );

				ULONG j = 0;

				for( j = 0 ; j < 24 ; j++ ) {

					status[ j / 4 ] |= (c18095576e1242d39e06f837c6599bee( pDevice, (0x03A0 + j) << 2 ) & 0x000000FF) << ((j % 4) * 8);
				}

				for( j = 0 ; j < 6 ; j++ ) {

					pDevice->m_nCustomMotionStatusProperty[ i ][ j ] = status[ j ];
					
				}
			
				// MOTION DETECTION PARAMETER
				// 
				if( (pDevice->m_nCustomMotionTemporalSensitivityProperty[ i ] & 0x88000000) != 0x00000000 ) {

					pDevice->m_nCustomMotionTemporalSensitivityProperty[ i ] &= 0x77FFFFFF;

					ULONG MD_TMPSENS = pDevice->m_nCustomMotionTemporalSensitivityProperty[ i ] & 0x77FFFFFF; // TEMPORAL SENSITIVITY

					ULONG MD_PIXEL_OS = 0; // X

					c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0301 + i * 8) << 2, (MD_TMPSENS << 4) | (MD_PIXEL_OS << 0) );
				}
				if( (pDevice->m_nCustomMotionLevelSensitivityProperty[ i ] & 0x88000000) != 0x00000000 ) {

					pDevice->m_nCustomMotionLevelSensitivityProperty[ i ] &= 0x77FFFFFF;

					ULONG MD_LVSENS = pDevice->m_nCustomMotionLevelSensitivityProperty[ i ] & 0x77FFFFFF; // LEVEL SENSITIVITY

					ULONG MD_FIELD = 0; // X

					ULONG MD_REFFLD = 0; // X

					c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0302 + i * 8) << 2, (MD_REFFLD << 7) | (MD_FIELD << 5) | (MD_LVSENS << 0) );
				}
				if( (pDevice->m_nCustomMotionSpeedProperty[ i ] & 0x88000000) != 0x00000000 ) {

					pDevice->m_nCustomMotionSpeedProperty[ i ] &= 0x77FFFFFF;

					ULONG MD_SPEED = pDevice->m_nCustomMotionSpeedProperty[ i ] & 0x77FFFFFF; // SPPED

					ULONG MD_CELSENS = 0; // X

					c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0303 + i * 8) << 2, (MD_CELSENS << 6) | (MD_SPEED << 0) );
				}
				if( (pDevice->m_nCustomMotionSpatialSensitivityProperty[ i ] & 0x88000000) != 0x00000000 ) {

					pDevice->m_nCustomMotionSpatialSensitivityProperty[ i ] &= 0x77FFFFFF;

					ULONG MD_SPSENS = pDevice->m_nCustomMotionSpatialSensitivityProperty[ i ] & 0x77FFFFFF; // SPATIAL SENSITIVITY

					c08e773e16fb4ac7a4a5ed488cd4b12c( pDevice, (0x0304 + i * 8) << 2, (MD_SPSENS  << 4) );
				}

			}//end of for

		}
		if( pDevice->m_nCustomSoftwareWatchdogDurationProperty & 0x80000000 ) { // MODIFY WATCHDOG DURATION

			BYTE R11 = (BYTE)(pDevice->m_nCustomSoftwareWatchdogDurationProperty);
		
			TW5864_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x11, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice,  R11, 125 ); TW5864_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 ); //

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] reset DOG period(0d%d)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, R11 );

			pDevice->m_nCustomSoftwareWatchdogDurationProperty &= 0x7FFFFFFF;
		}
		if( pDevice->m_nCustomSoftwareWatchdogResetProperty & 0x00000001 ) {
		
			if( pDevice->m_nCustomSoftwareWatchdogResetProperty & 0x80000000 ) { // WATCHDOG
		
				TW5864_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x12, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x5A, 125 ); TW5864_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 );

				pDevice->m_nCustomSoftwareWatchdogResetProperty = 0x00000001;

				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] DOG set \n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );
			}
		}
		else {
			if( (counts++ % 5) == 0 ) { // HARDWARE RESET WATCHDOG

				TW5864_F8B7FB94CF24D4152842C9743714CDAA9( pDevice, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0xA2, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x12, 125 ); TW5864_F1FF06F06D32B4c0aB2C20D3FB71281B5( pDevice, 0x5A, 125 ); TW5864_F1C002401C7AE4334A36AC1B1E338AD75( pDevice, 125 );
				
				//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] DOG auto\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE );

			}
		}


		schedule_timeout_interruptible( msecs_to_jiffies( 1000 ) ); //

	}//while

	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] d0bd7a0449e54c36b37ec614ee17f971( exit ) - %08X\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(pDevice->m_pControlThread) );

	return 0;	
}

static int a0c563aa017e45aa898479fcd6f672e2( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{
	if( pDevice->m_pControlThread == NULL )
	{
		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] a0c563aa017e45aa898479fcd6f672e2()\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

		pDevice->m_pControlThread = kthread_run( d0bd7a0449e54c36b37ec614ee17f971, pDevice, "d0bd7a0449e54c36b37ec614ee17f971" );

		if( IS_ERR( pDevice->m_pControlThread ) ) {

			int ret = PTR_ERR( pDevice->m_pControlThread );

			pDevice->m_pControlThread = NULL;

			return ret;
		}
	}
	return 0;
}

static int f74f60e6b0814257af133a93b451d6b1( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice )
{

	if( pDevice->m_pControlThread ) {

		F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] f74f60e6b0814257af133a93b451d6b1()\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE) );

		kthread_stop( pDevice->m_pControlThread ); // GOOD NEWS!! LINUX HAD ALREADY HELPED TO FINISH THE "STOP" SYNC.

		pDevice->m_pControlThread = NULL;
	}
	return 0;
}

