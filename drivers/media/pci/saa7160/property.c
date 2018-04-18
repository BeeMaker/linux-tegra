#include "LINUXV4L2.h"
#include "property.h"
#include "wrapper.h"
#include "tw6805.h"
#include "cx2581.h"
#include "sa7160.h"
#include "sl6010.h"
#include "tw5864.h"
#include "fh8735.h"
#include "mz0380.h"
#include "pl330b.h"

#ifndef AME_PL330A

static void FF6E02BBAFF114b048DA9EFBDC06CA997( unsigned long FD51B2B4E0CAC4359A9EFA429A9E16157 )
{
	F42A18AF66EFF459eA332CA253FFF8A65 * pDevice = (F42A18AF66EFF459eA332CA253FFF8A65 *)(FD51B2B4E0CAC4359A9EFA429A9E16157);

	ULONGLONG FDA01864545BC42d7BB09ECE078605249 = pDevice->F69679D3D75724cd281AAC93AE8DFDF35;

	ULONGLONG interrupt_params = pDevice->F9D066B94377B4a9aB14E37D504955651;

	ULONG i = 0;

	unsigned long flags = 0x00000000;

//	F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] FF6E02BBAFF114b048DA9EFBDC06CA997( S:%08X, M:%08X )\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), (unsigned int)(FDA01864545BC42d7BB09ECE078605249), (unsigned int)(interrupt_params) );

	wrapper_spin_lock_irqsave( &pDevice->FFCB115F553804bc7A991C2C6B50FDDFC, flags );

	//
	//
	{	F301FA49098CE4d9eB95F22BBD388E837*       pVideo[ F03706E45925547d799BA016E4F0F6D6B ] [ MAX_DEVICE_OPEN_NUM ] = { NULL };

		F170997530C6943659ECE8DEC21301F66* F523C1268E9B24a96876472B09F4D9EA4[ F03706E45925547d799BA016E4F0F6D6B ] [ MAX_DEVICE_OPEN_NUM ] = { NULL };

		F170997530C6943659ECE8DEC21301F66* F1C3C2F05235C46f2875E3D84A32F6E50[ F03706E45925547d799BA016E4F0F6D6B ] [ MAX_DEVICE_OPEN_NUM ] = { NULL };

		BOOLEAN        FDFC345768E394d138EA574DEB55B7949[ F03706E45925547d799BA016E4F0F6D6B ] [ MAX_DEVICE_OPEN_NUM ] = { FALSE };

		BOOLEAN        FCF11A4E4EB484774A29F23746BAB99DD[ F03706E45925547d799BA016E4F0F6D6B ] [ MAX_DEVICE_OPEN_NUM ] = { FALSE };

		BOOLEAN        F6004E32A4CDF474796AFBF0A9A29578F = FALSE;

		for( i = 0; i < F03706E45925547d799BA016E4F0F6D6B; i++ )
		{
			int j = 0;
			for( j = 0 ; j < MAX_DEVICE_OPEN_NUM ; j++ )
			{
				pVideo[ i ] [ j ] = NULL;

				F523C1268E9B24a96876472B09F4D9EA4[ i ] [ j ] = NULL;

				F1C3C2F05235C46f2875E3D84A32F6E50[ i ] [ j ] = NULL;

				FDFC345768E394d138EA574DEB55B7949[ i ] [ j ] = FALSE;

				FCF11A4E4EB484774A29F23746BAB99DD[ i ] [ j ] = FALSE;
			}
		}

		//check every pvideo
		for( i = 0 ; i < F91863BEB45D34624A724F2D29823D9E3 ; i++ ) {

			int j = 0;
			for( j = 0 ; j < MAX_DEVICE_OPEN_NUM ; j++ ) {

				if( (pDevice->FA12AAA3D283C4cf0BF02ACD3957899B0[ i ] & ( 1 << j) ) == 0x00000000 ) { continue ; } //, check if j bit is 0

				if( pDevice->m_pVideo[ i ][ j ] == NULL ) { continue ; }

				pVideo[ i ][ j ] = pDevice->m_pVideo[ i ][ j ];

				//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] pVideo[ %d ][ %d ] (0x%x) FA12AAA3D283C4cf0BF02ACD3957899B0[ i ](0x%x)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), i, j , pVideo[ i ][ j ], pDevice->FA12AAA3D283C4cf0BF02ACD3957899B0[ i ]);

				//
				// 
				if( wrapper_list_empty( &pVideo[ i ][ j ]->F0EA6D27495A14af1A9607DE7C222A3B1 ) == 0 ) { //not empty
			
					unsigned long flags = 0x00000000;

					wrapper_spin_lock_irqsave( &pVideo[ i ][ j ]->FE0A97B802F3C400aBD7CD5D313825C31, flags );
					
					F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ] = wrapper_list_first_entry( &pVideo[ i ][ j ]->F0EA6D27495A14af1A9607DE7C222A3B1, F170997530C6943659ECE8DEC21301F66, F6A821C5E7AA043f999FB3C51DB94DD2B.queue ); //
				
					F1C3C2F05235C46f2875E3D84A32F6E50[ i ][ j ] = wrapper_list_first_entry( &pVideo[ i ][ j ]->F0EA6D27495A14af1A9607DE7C222A3B1, F170997530C6943659ECE8DEC21301F66, F6A821C5E7AA043f999FB3C51DB94DD2B.queue ); //

					wrapper_spin_unlock_irqrestore( &pVideo[ i ][ j ]->FE0A97B802F3C400aBD7CD5D313825C31, flags );

					if( F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED )
					{
						NULL;
					}
					else
					{
						F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ] = NULL;

						F1C3C2F05235C46f2875E3D84A32F6E50[ i ][ j ] = NULL;

						F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F523C1268E9B24a96876472B09F4D9EA4[ 0d%d ] error, not VIDEOBUF_QUEUED, j(%d) \n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), i, j );

					}
					//	waitqueue_active( &F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.done ); // GOOD NEWS!! LINUX HAD ALREADY HELPED TO FINISH THE "RELEASE" SYNC.

					; //
				}
				else {

					F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ] = NULL;

					F1C3C2F05235C46f2875E3D84A32F6E50[ i ][ j ] = NULL;

					//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] list empty, i(0x%x), j(%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), i, j );
				}
			}
		}
		for( i = 0 ; i < F91863BEB45D34624A724F2D29823D9E3 ; i++ ) {

			int j = 0;
			for( j = 0 ; j < MAX_DEVICE_OPEN_NUM ; j++ ) {

				if( (pDevice->FDB274CD437614fec94859748411FE56A[ i ] & (1 << j ) ) == 0x00000000 ) { continue ; } //

				if( pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ i ][ j ] == NULL ) { continue ; }

				pVideo[ i + 16 ][ j ] = pDevice->F7E9FB3BB25C34ddd9C2E2E73E181A1F8[ i ][ j ];

				//
				// 
				if( wrapper_list_empty( &pVideo[ i + 16 ][ j ]->F0EA6D27495A14af1A9607DE7C222A3B1 ) == 0 ) {
			
					unsigned long flags = 0x00000000;

					wrapper_spin_lock_irqsave( &pVideo[ i + 16 ][ j ]->FE0A97B802F3C400aBD7CD5D313825C31, flags );

					F523C1268E9B24a96876472B09F4D9EA4[ i + 16 ][ j ] = wrapper_list_first_entry( &pVideo[ i + 16 ][ j ]->F0EA6D27495A14af1A9607DE7C222A3B1, F170997530C6943659ECE8DEC21301F66, F6A821C5E7AA043f999FB3C51DB94DD2B.queue ); //
				
					F1C3C2F05235C46f2875E3D84A32F6E50[ i + 16 ][ j ] = wrapper_list_first_entry( &pVideo[ i + 16 ][ j ]->F0EA6D27495A14af1A9607DE7C222A3B1, F170997530C6943659ECE8DEC21301F66, F6A821C5E7AA043f999FB3C51DB94DD2B.queue ); //

					wrapper_spin_unlock_irqrestore( &pVideo[ i + 16 ][ j ]->FE0A97B802F3C400aBD7CD5D313825C31, flags );

					if( F523C1268E9B24a96876472B09F4D9EA4[ i + 16 ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED )
					{
						NULL;
					}
					else
					{
						F523C1268E9B24a96876472B09F4D9EA4[ i + 16 ][ j ] = NULL;

						F1C3C2F05235C46f2875E3D84A32F6E50[ i + 16 ][ j ] = NULL;

						F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F523C1268E9B24a96876472B09F4D9EA4[ 0d%d ] error, not VIDEOBUF_QUEUED --\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), i + 16 );

					}

				
					//	waitqueue_active( &F523C1268E9B24a96876472B09F4D9EA4->F6A821C5E7AA043f999FB3C51DB94DD2B.done ); // GOOD NEWS!! LINUX HAD ALREADY HELPED TO FINISH THE "RELEASE" SYNC.

					; //

	//				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] F1C3C2F05235C46f2875E3D84A32F6E50[ 0d%d ](0x%x)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), i + 16, F1C3C2F05235C46f2875E3D84A32F6E50[ i + 16 ] );

				}
				else {

					F523C1268E9B24a96876472B09F4D9EA4[ i + 16 ][ j ] = NULL;

					F1C3C2F05235C46f2875E3D84A32F6E50[ i + 16 ][ j ] = NULL;
				
					//F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] error F1C3C2F05235C46f2875E3D84A32F6E50[ 0d%d ](0x%x)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), i + 16, F1C3C2F05235C46f2875E3D84A32F6E50[ i + 16 ] );
				}
			}
		}

		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6801) ||
			(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6804) ||
			(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6810) ||
			(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6811) ||
			(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6812) ||
			(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6813) ) {
			
			FC036F260F5D849c9AC2C506AC1EA96D7( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pVideo, F1C3C2F05235C46f2875E3D84A32F6E50, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD ); 
			
			#ifdef TW6805_64bit		
				F6004E32A4CDF474796AFBF0A9A29578F = FALSE;
			#else
				F6004E32A4CDF474796AFBF0A9A29578F = TRUE;
			#endif
		}
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) {
			
			F3B8EDF5AA60D4a499B98ABE768EB3BE0( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pVideo, F1C3C2F05235C46f2875E3D84A32F6E50, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD ); 
			
			#ifdef CX2581_64bit		
				F6004E32A4CDF474796AFBF0A9A29578F = FALSE;
			#else
				F6004E32A4CDF474796AFBF0A9A29578F = TRUE;
			#endif
		}
		//shawn 2010.07.12
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x7160) ) {
			
			AF6D1A686DC84B949B3B1770AC209112( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pVideo, F1C3C2F05235C46f2875E3D84A32F6E50, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD ); F6004E32A4CDF474796AFBF0A9A29578F = FALSE;
		}
		//
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x9413 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6010) ) {

		//	F7421A70ABA6E46c3A970EA410EAE6872( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pVideo, F1C3C2F05235C46f2875E3D84A32F6E50, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD ); F6004E32A4CDF474796AFBF0A9A29578F = FALSE;
		}
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) {

			a17141c0224e4e82a01dd2dc46f8ba6b( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pVideo, F1C3C2F05235C46f2875E3D84A32F6E50, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD ); F6004E32A4CDF474796AFBF0A9A29578F = FALSE;
		}

		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) {

			D42B60001E4E4D24824451225E3B14AF( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pVideo, F1C3C2F05235C46f2875E3D84A32F6E50, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD ); F6004E32A4CDF474796AFBF0A9A29578F = FALSE;
		}

		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ) {

			B3F2D4647EDD4CEB87D04AC6E9463337( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pVideo, F1C3C2F05235C46f2875E3D84A32F6E50, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD ); F6004E32A4CDF474796AFBF0A9A29578F = FALSE;
		}
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ) {

			B3F2D4647EDD4CEB87D04AC6E9463337( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pVideo, F1C3C2F05235C46f2875E3D84A32F6E50, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD ); F6004E32A4CDF474796AFBF0A9A29578F = FALSE;
		}
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0380) ) {

			B3F2D4647EDD4CEB87D04AC6E9463337( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pVideo, F1C3C2F05235C46f2875E3D84A32F6E50, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD ); F6004E32A4CDF474796AFBF0A9A29578F = FALSE;
		}

		for( i = 0 ; i < F03706E45925547d799BA016E4F0F6D6B ; i++ ) {

			int j = 0;
			for( j = 0 ; j < MAX_DEVICE_OPEN_NUM ; j++ ) {

				if( pVideo[ i ][ j ] == NULL ) { continue ; }

				if( FDFC345768E394d138EA574DEB55B7949[ i ][ j ] == FALSE ) { continue ; }

				if( F6004E32A4CDF474796AFBF0A9A29578F ) { //

					int F590126702D96413b9717EDBEA8F7706F = wrapper_list_empty( &pVideo[ i ][ j ]->FDA1F8237E2D04e5a8737CF587701D54D ); 

					if( F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ] ) { //

						if( FCF11A4E4EB484774A29F23746BAB99DD[ i ][ j ] == FALSE ) {
						
							unsigned long flags = 0x00000000;

							wrapper_spin_lock_irqsave( &pVideo[ i ][ j ]->FE0A97B802F3C400aBD7CD5D313825C31, flags );
					
							if( F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED )
							{
								//must inside spin_lock
								//can not find how 0xdead000000000000 is added
								if( (F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next == LIST_POISON1) || (F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev == LIST_POISON2) || (F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next == 0xdead000000000100) || (F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev == 0xdead000000000200) )
								{
									//skip this time
									F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue error, next(%p) prev(%p)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next, F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev );
								}
								else
								{
									wrapper_list_del( &F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue );

									wrapper_list_add_tail( &F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue, &pVideo[ i ][ j ]->FDA1F8237E2D04e5a8737CF587701D54D );
						
								}
							}
							else
							{
								F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] pe state error, i(0d%d) (%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.state );
							}

							wrapper_spin_unlock_irqrestore( &pVideo[ i ][ j ]->FE0A97B802F3C400aBD7CD5D313825C31, flags );
						}
					}
					if( F590126702D96413b9717EDBEA8F7706F == 0 ) { //

						struct timeval ts;

						F170997530C6943659ECE8DEC21301F66 * pVideoBuffer = wrapper_list_first_entry( &pVideo[ i ][ j ]->FDA1F8237E2D04e5a8737CF587701D54D, F170997530C6943659ECE8DEC21301F66, F6A821C5E7AA043f999FB3C51DB94DD2B.queue ); //

						if( pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED )
						{
							wrapper_spin_lock_irqsave( &pVideo[ i ][ j ]->FE0A97B802F3C400aBD7CD5D313825C31, flags );
	
							//must inside spin_lock
							//can not find how 0xdead000000000000 is added
							if( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next == LIST_POISON1) || (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev == LIST_POISON2) || (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next == 0xdead000000000100) || (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev == 0xdead000000000200) )
							{
								wrapper_spin_unlock_irqrestore( &pVideo[ i ][ j ]->FE0A97B802F3C400aBD7CD5D313825C31, flags );
								//skip this time
								F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue error, next(%p) prev(%p)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev );
							}
							else
							{
								wrapper_list_del( &pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.queue );

								wrapper_spin_unlock_irqrestore( &pVideo[ i ][ j ]->FE0A97B802F3C400aBD7CD5D313825C31, flags );

								wrapper_do_gettimeofday( &ts );

								pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts = ts;

								pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.field_count = pVideo[ i ][ j ]->F6578ACFCB40E44819A12FD3E27A48085++ * 2;

								#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25)

								pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state = VIDEOBUF_DONE;

								#else

								pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state = STATE_DONE;

								#endif

								wrapper_wake_up( &pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.done );
							}
						}
						else
						{
							F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] pe state error, i(0d%d) (%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.state );
						}
					}
				}
				else { //

					if( F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ] ) {

						if( FCF11A4E4EB484774A29F23746BAB99DD[ i ][ j ] == FALSE ) {

							struct timeval ts;
		
							//use killall -9 vlc will change buffer state long before any driver function
							//I do not know how this be done, I can only check here
						
							if( F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.state == VIDEOBUF_QUEUED )
							{
								wrapper_spin_lock_irqsave( &pVideo[ i ][ j ]->FE0A97B802F3C400aBD7CD5D313825C31, flags );

								//must inside spin_lock
								//can not find how 0xdead000000000000 is added
								if( (F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next == LIST_POISON1) || (F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev == LIST_POISON2) || (F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next == 0xdead000000000100) || (F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev == 0xdead000000000200) )
								{
									wrapper_spin_unlock_irqrestore( &pVideo[ i ][ j ]->FE0A97B802F3C400aBD7CD5D313825C31, flags );

									//skip this time
									F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue error, next(%p) prev(%p)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.next, F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue.prev );
								}
								else
								{
									wrapper_list_del( &F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.queue );

									wrapper_spin_unlock_irqrestore( &pVideo[ i ][ j ]->FE0A97B802F3C400aBD7CD5D313825C31, flags );

									wrapper_do_gettimeofday( &ts );
		
									F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.ts = ts;

									if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) {
		
										if( pVideo[ i ][ j ]->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001 ) { e3893c33768249bf80049109b1ca7e11( pDevice, pVideo[ i ][ j ], F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ] ); }
		
										if( pVideo[ i ][ j ]->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002 ) { ef27344a3deb4785b7467dc69926a0f8( pDevice, pVideo[ i ][ j ], F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ] ); }
									}

									if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) {

										if( pVideo[ i ][ j ]->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001 ) { D6EC03FA3D894ADE915EEAE8351E5E6B( pDevice, pVideo[ i ][ j ], F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ] ); }

										if( pVideo[ i ][ j ]->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002 ) { E45C67902CED4668A47EA0F22253C74A( pDevice, pVideo[ i ][ j ], F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ] ); }
									}

									if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

										(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
							
										(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0380) ) {

										if( pVideo[ i ][ j ]->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000001 ) { BC50A3FAA8804CF3AE611AFFE6606AA2( pDevice, pVideo[ i ][ j ], F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ] ); }

										if( pVideo[ i ][ j ]->F03DD48A54B1D4ffeB64170AA03AEFC6E == 0x00000002 ) { B7D0BE55F4E84F7A8DDDDACB6072D4D8( pDevice, pVideo[ i ][ j ], F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ] ); }
									}
						
									F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.field_count = pVideo[ i ][ j ]->F6578ACFCB40E44819A12FD3E27A48085++ * 2;

									#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,25)

									F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.state = VIDEOBUF_DONE;

									#else

									F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.state = STATE_DONE;
	
									#endif

									wrapper_wake_up( &F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.done );
								}
							}
							else
							{
								F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "[%02d] pe state error, i(0d%d) (%x)\n", pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE, i, F523C1268E9B24a96876472B09F4D9EA4[ i ][ j ]->F6A821C5E7AA043f999FB3C51DB94DD2B.state );
							}

						}
					}
				}
			}
		}
	}

	//
	//
	{	FE8EB18A4C9984f9789EFF7C05EE073A0 * pAudio[ F03706E45925547d799BA016E4F0F6D6B ] = { NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL };
	
		BOOLEAN  FDFC345768E394d138EA574DEB55B7949[ F03706E45925547d799BA016E4F0F6D6B ] [ MAX_DEVICE_OPEN_NUM ] = { FALSE };

		BOOLEAN  FCF11A4E4EB484774A29F23746BAB99DD[ F03706E45925547d799BA016E4F0F6D6B ] [ MAX_DEVICE_OPEN_NUM ] = { FALSE };

		memset( pAudio, 0x00, F03706E45925547d799BA016E4F0F6D6B * sizeof(FE8EB18A4C9984f9789EFF7C05EE073A0*) );

		memset( FDFC345768E394d138EA574DEB55B7949, 0x00, F03706E45925547d799BA016E4F0F6D6B * MAX_DEVICE_OPEN_NUM * sizeof(BOOLEAN) );

		memset( FCF11A4E4EB484774A29F23746BAB99DD, 0x00, F03706E45925547d799BA016E4F0F6D6B * MAX_DEVICE_OPEN_NUM * sizeof(BOOLEAN) );

		for( i = 0 ; i < F91863BEB45D34624A724F2D29823D9E3 ; i++ ) {

			if( pDevice->F13A906F1479D4245B9F207A09C70BCE6[ i ] == 0x00000000 ) { continue ; } //

			if( pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ] == NULL ) { continue ; }

			pAudio[ i ] = pDevice->FF6347EA309EF49519F7F07D0B6B28662[ i ];
		}
		for( i = 0 ; i < F91863BEB45D34624A724F2D29823D9E3 ; i++ ) {

			if( pDevice->FC1FFB6B00E034c0993BE8A598C730AA4[ i ] == 0x00000000 ) { continue ; } //

			if( pDevice->FCD654CA89AC34227BE068F80A85776C6[ i ] == NULL ) { continue ; }

			pAudio[ i + 16 ] = pDevice->FCD654CA89AC34227BE068F80A85776C6[ i ];
		}
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6802) ||
			(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6805) ||
			(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6814) ||
			(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6815) ||
			(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6816) ||
			(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6817) ) {

			if( FC14CCE1A5C124c92B5D2064F205ABC78( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pAudio, NULL, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD ) ) {
				/*
				if( FDFC345768E394d138EA574DEB55B7949[ 0 ] ) {

					if( pAudio[ 0 ] ) {

						pAudio[ 0 ]->F6578ACFCB40E44819A12FD3E27A48085[ 0 ] = (pAudio[ 0 ]->F6578ACFCB40E44819A12FD3E27A48085[ 0 ] + 1) % (pAudio[ 0 ]->FD9C8A1F986EF488a8883B3CAD736747F);

						wrapper_snd_pcm_period_elapsed( pAudio[ 0 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ 0 ] );
					}
				}
				*/
			}
		}
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) {

			FB80A44AF630F431eBC8A7B0E64510AC0( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pAudio, NULL, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD );
		}
		//shawn 2010.07.12
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x7160) ) {

			if( EBCFB2FF0E5F46BAB89C2DCB6DC14419( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pAudio, NULL, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD ) )
			{			
				/*
				int k = 0;
				for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
				{
					if( FDFC345768E394d138EA574DEB55B7949[ 0 ][ k ] )
					{
						if( pAudio[ 0 ] ) {

							pAudio[ 0 ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] = (pAudio[ 0 ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] + 1) % (pAudio[ 0 ]->FD9C8A1F986EF488a8883B3CAD736747F);

							wrapper_snd_pcm_period_elapsed( pAudio[ 0 ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] );
						}
					}
				}
				*/
			}

		}
		//
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x9413 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6010) ) {
		}
//peter [2011.07.15]
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) {

			if( e08691f8c8594763a7fbd04765388c57( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pAudio, NULL, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD ) ) {
	
				for(i = 0 ; i < 4 ; i++ )
				{
					if( FDFC345768E394d138EA574DEB55B7949[ i ][ 0 ] ) {

						if( pAudio[ i ] ) {

							pAudio[ i ]->F6578ACFCB40E44819A12FD3E27A48085[ 0 ] = (pAudio[ i ]->F6578ACFCB40E44819A12FD3E27A48085[ 0 ] + 1) % (pAudio[ i ]->FD9C8A1F986EF488a8883B3CAD736747F);
				
							wrapper_snd_pcm_period_elapsed( pAudio[ i ]->F823E5E1F924443f8AD2BC9CBED4CE613[ 0 ] );
						}
					}
				}
			}
		}

		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) {

			if( ADFF4A64A2784A628D9295677E4E03CF( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pAudio, NULL, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD ) ) {
	
				int num = 1;

				if( (pDevice->iProduct & 0x0F) == (0x03) ||	(pDevice->iManufacturer == 0x85) )
				{
					num = 4;
				}
				else if( (pDevice->iProduct & 0x0F) == (0x05) || (pDevice->iProduct & 0x0F) == (0x07) )
				{
					num = 1;
				}
				else
				{
					num = 4;
				}
				
				for(i = 0 ; i < num ; i++ )
				{
					int k = 0;
					for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
					{
						if( FDFC345768E394d138EA574DEB55B7949[ i ][ k ] ) {

							if( pAudio[ i ] ) {

								pAudio[ i ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] = (pAudio[ i ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] + 1) % (pAudio[ i ]->FD9C8A1F986EF488a8883B3CAD736747F);
				
								wrapper_snd_pcm_period_elapsed( pAudio[ i ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k ] );
							}
						}
					}
				}

			}
		}

		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ||

			(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ||
			
			(pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0380)) {

			if( A3D659176692446A99A673EE21731E20( pDevice, FDA01864545BC42d7BB09ECE078605249, interrupt_params, pAudio, NULL, FDFC345768E394d138EA574DEB55B7949, FCF11A4E4EB484774A29F23746BAB99DD ) ) {

				int num = 1;

				if( ((pDevice->iProduct & 0x0F) == (0x02)) || ((pDevice->iProduct & 0x0F) == (0x03)))
				{
					if( (pDevice->iManufacturer & 0x0F) == 0x0B	|| (pDevice->iManufacturer & 0x0F) == 0x0C )
					{
						num = 4;
					}
					else
					{
						num = 8;
					}

				}
				else
				{
					num = 1;
				}
				
				for(i = 0 ; i < num ; i++ )
				{
					int k = 0;
					for(k = 0; k < MAX_DEVICE_OPEN_NUM; k++ )
					{
						if( FDFC345768E394d138EA574DEB55B7949[ i ][ k ] ) {

							if( pAudio[ i ] ) {

								pAudio[ i ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] = (pAudio[ i ]->F6578ACFCB40E44819A12FD3E27A48085[ k ] + 1) % (pAudio[ i ]->FD9C8A1F986EF488a8883B3CAD736747F);
				
								wrapper_snd_pcm_period_elapsed( pAudio[ i ]->F823E5E1F924443f8AD2BC9CBED4CE613[ k] );
							}
						}
					}
				}

			}
		}


	}

	// ...
	//
	pDevice->F5C8C1DAFA2D74241A96FE41ED93197F8 = TRUE;

	if( pDevice->FC3FEC90DD3E6414c83437752D6A0B4B2 > 0 ) 
	
	{

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

			writel( 0x00000022, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00000020 );
		}
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x14F1 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x8210) ) {
			
			for( i = 0 ; i < 8 ; i++ ) {
				
				writel( 0x00000001, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00040020 + (0x00000010 * i) );
			}
			for( i = 0 ; i < 4 ; i++ ) {
				
				writel( 0x00000001, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x000400C0 + (0x00000010 * i) );
			}
		}
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1131 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x7160) ) {
			
		}
		//
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x9413 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x6010) ) {

			//writel( 0x001E4409, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00000014 ); { USHORT val = 0x0000; pci_read_config_word( pDevice->F9D9594A095F0463193B7588374CF8310, PCI_STATUS, &val ); }
		}
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x1797 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x5864) ) {
			
			writel( 0x0000FF77, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 0 ] + 0x00018004 );
		}
//peter [2011.06.29]
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) {
//already done at the end of ISR			
//			writel( 0x00000000, pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 1 ] + 0x0040001C );

//			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "FH8735() clear interrupt -------- 3 %08X\n", pDevice->F760673FD1F8F4f22914515A9DC68C7C9[ 1 ] );
		}

		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x0907 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0100) ) {
		}

		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0370) ) {
		}
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x12AB && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0380) ) {
		}
	}
	
	wrapper_spin_unlock_irqrestore( &pDevice->FFCB115F553804bc7A991C2C6B50FDDFC, flags );
}

void FF6E02BBAFF114b048DA9EFBDC06CA997_EX( unsigned long FD51B2B4E0CAC4359A9EFA429A9E16157 )
{
	FF6E02BBAFF114b048DA9EFBDC06CA997( FD51B2B4E0CAC4359A9EFA429A9E16157 );
}
#endif

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
static LONGLONG xxxxx[ 4 ] = { 0, 0, 0, 0 };

static LONGLONG ooooo[ 4 ] = { 0, 0, 0, 0 };

BOOLEAN update_video_time_stamp( F42A18AF66EFF459eA332CA253FFF8A65 * pDevice, F301FA49098CE4d9eB95F22BBD388E837 * pVideo, F170997530C6943659ECE8DEC21301F66 * pVideoBuffer )
{
	//FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);

		#ifdef AME_SA7160
		SA7160_SYS_CFG * p_sys_cfg = (SA7160_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
		#endif

		#ifdef AME_FH8735
		FH8735_SYS_CFG * p_sys_cfg = (FH8735_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
		#endif

		#ifdef AME_MZ0380
		MZ0380_SYS_CFG * p_sys_cfg = (MZ0380_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
		#endif

		#if defined(AME_PL330B) || defined(AME_PL330A)
		PL330B_SYS_CFG * p_sys_cfg= (PL330B_SYS_CFG *)(pDevice->m_pCustomSystemConfigProperty);
		#endif

		LONGLONG o_ts = pVideo->m_nLastReferenceClockTime; // 上次真實時間

		//LONGLONG e_ts = pDevice->m_pKsMasterReferenceClock->GetTime(); // 本次真實時間 //100ns
		struct timeval e_ts_temp;
		wrapper_do_gettimeofday( &e_ts_temp );// 本次真實時間
		LONGLONG e_ts = e_ts_temp.tv_sec * 10000000 + e_ts_temp.tv_usec * 10; // 本次真實時間

		LONGLONG d_ts  = e_ts - o_ts;

		ULONG base_fps = 0;

		LONGLONG input_fps = 0;

		BOOL     is_1st = FALSE;

		ULONG    m = p_sys_cfg->n_input_video_resolution_fps_m;

		if( d_ts >= ( 166666 - 5000) && d_ts <= ( 166666 +   84) && m == 0 ) { base_fps = 60000; } // 60.000FPS (166666)

		if( d_ts >= ( 166833 -   83) && d_ts <= ( 166833 + 5000) && m == 1 ) { base_fps = 59940; } // 59.940FPS (166833)

		if( d_ts >= ( 200000 - 5000) && d_ts <= ( 200000 + 5000) && m == 0 ) { base_fps = 50000; } // 50.000FPS (200000)

		if( d_ts >= ( 208333 - 4166) && d_ts <= ( 208333 +  105) && m == 0 ) { base_fps = 48000; } // 48.000FPS (208333)

		if( d_ts >= ( 208542 -  104) && d_ts <= ( 208542 + 5000) && m == 1 ) { base_fps = 47952; } // 47.952FPS (208542)

		if( d_ts >= ( 333333 - 5000) && d_ts <= ( 333333 +  167) && m == 0 ) { base_fps = 30000; } // 30.000FPS (333333)

		if( d_ts >= ( 333667 -  166) && d_ts <= ( 333667 + 5000) && m == 1 ) { base_fps = 29970; } // 29.970FPS (333667)

		if( d_ts >= ( 400000 - 5000) && d_ts <= ( 400000 + 5000) && m == 0 ) { base_fps = 25000; } // 25.000FPS (400000)

	//	if( d_ts >= ( 416666 - 5000) && d_ts <= ( 416666 +  208) && m == 0 ) { base_fps = 24000; } // 24.000FPS (416666)

	//	if( d_ts >= ( 417083 -  208) && d_ts <= ( 417083 + 5000) && m == 1 ) { base_fps = 23976; } // 23.976FPS (417083)

		if( d_ts >= ( 500000 - 5000) && d_ts <= ( 500000 +  250) && m == 0 ) { base_fps = 20000; } // 20.000FPS (500000)

		if( d_ts >= ( 500500 -  250) && d_ts <= ( 500500 + 5000) && m == 1 ) { base_fps = 19980; } // 19.980FPS (500500)

		if( d_ts >= ( 600000 - 5000) && d_ts <= ( 600000 + 5000) && m == 0 ) { base_fps = 16666; } // 16.666FPS (600000)

		if( d_ts >= ( 666666 - 5000) && d_ts <= ( 666666 +  446) && m == 0 ) { base_fps = 15000; } // 15.000FPS (666666)

		if( d_ts >= ( 667557 -  445) && d_ts <= ( 667557 + 5000) && m == 1 ) { base_fps = 14985; } // 14.980FPS (667557)

		if( d_ts >= ( 800000 - 5000) && d_ts <= ( 800000 + 5000) && m == 0 ) { base_fps = 12500; } // 12.500FPS (800000)

		if( d_ts >= (1333333 - 5000) && d_ts <= (1333333 +  667) && m == 0 ) { base_fps =  7500; } // 7.500FPS (1333333)

		if( d_ts >= (1334668 -  668) && d_ts <= (1334668 + 5000) && m == 1 ) { base_fps =  7492; } // 7.492FPS (1334668)

		if( d_ts >= (1600000 - 5000) && d_ts <= (1600000 + 5000) && m == 0 ) { base_fps =  6250; } // 6.250FPS (1600000)

		{	if( pDevice->m_nCustomAnalogVideoInterleavedProperty == 1 ) {

				input_fps = (pDevice->m_nCustomAnalogVideoFrameRateProperty / 2) * 1000;
			}
			else {

				input_fps = (pDevice->m_nCustomAnalogVideoFrameRateProperty / 1) * 1000;
			}
			if( p_sys_cfg->n_output_video_resolution_fps_1_2 == 1 ) {

				input_fps >>= 1;
			}
			if( input_fps > 0 ) {

				if( base_fps > input_fps ) {

					base_fps = 0;
				}
			}
		}
		if( base_fps != 0 ) {

			if( pVideo->m_nLastPresentationTimeFps == 0 ) {

				pVideo->m_nLastPresentationTimeFps = base_fps;

				pVideo->m_nLastPresentationTimeFpsCounts = 1;
			}
			else if( pVideo->m_nLastPresentationTimeFps != base_fps ) {
				
				if( pVideo->m_nLastPresentationTimeFpsCounts == 1 ) {

					pVideo->m_nLastPresentationTimeFps = base_fps;

					pVideo->m_nLastPresentationTimeFpsCounts = 1;
				}
				else {

					base_fps = pVideo->m_nLastPresentationTimeFps;

					if( pVideo->m_nLastPresentationTimeFpsCounts > 1 ) {

						pVideo->m_nLastPresentationTimeFpsCounts--;
					}
				}
			}
			else {

				if( pVideo->m_nLastPresentationTimeFpsCounts < 5 ) {

					pVideo->m_nLastPresentationTimeFpsCounts++;
				}
			}
		}
		if( base_fps == 0 && 
			
			pVideo->m_nLastPresentationTimeFpsCounts >= 2 ) {

			base_fps = pVideo->m_nLastPresentationTimeFps;

			if( base_fps != 0 ) {

				if( pVideo->m_nLastPresentationTimeFpsCounts < 5 ) {

					pVideo->m_nLastPresentationTimeFpsCounts++;
				}
			}
		}	
		if( base_fps == 0 ) {

			if( pDevice->m_nCustomAnalogVideoInterleavedProperty == 1 ) {

				base_fps = (pDevice->m_nCustomAnalogVideoFrameRateProperty / 2) * 1000;
			}
			else {

				base_fps = (pDevice->m_nCustomAnalogVideoFrameRateProperty / 1) * 1000;
			}
			if( p_sys_cfg->n_output_video_resolution_fps_1_2 == 1 ) {

				base_fps >>= 1;
			}
			if( m == 1 ) {

				base_fps *= 1000;

				//base_fps /= 1001;
				LONGLONG base_fps_temp = base_fps;
				do_div(base_fps_temp, 1001);
				base_fps = base_fps_temp;
			}
		}
		if( base_fps == 0 ) {

			if( pDevice->FD314ADAD9404496b842EBFC396E875CB & SUPPORTED_ANALOG_VIDEO_STANDARDS_60HZ ) {

				if( pDevice->m_nCustomAnalogVideoInterleavedProperty == 1 ) {

					base_fps = 30000;
				}
				else {

					base_fps = 60000;
				}
			}
			else {

				if( pDevice->m_nCustomAnalogVideoInterleavedProperty == 1 ) {

					base_fps = 25000;
				}
				else {

					base_fps = 50000;
				}
			}
			if( p_sys_cfg->n_output_video_resolution_fps_1_2 == 1 ) {

				base_fps >>= 1;
			}
			if( m == 1 ) {

				base_fps *= 1000;

				//base_fps /= 1001; 
				LONGLONG base_fps_temp = base_fps;
				do_div(base_fps_temp, 1001);
				base_fps = base_fps_temp;
			}
		}

#ifdef FH8735_DEBUG_TIMESTAMP

//		if( TRUE ) {
//
//			static LONGLONG old = 0;
//
//			AMEBDAD_PRINT( ("%lld %lld (%lld) (%lld) (%lld) (%lld)\n", old, e_ts, e_ts - old, base_fps, pDevice->m_nLastPresentationTimeFps, pDevice->m_nLastPresentationTimeFpsCounts) );
//
//			old = e_ts;
//		}
#endif
		//LONGLONG base = 10000000000 / base_fps; // 整數位

		//LONGLONG FF7E121E5F6A1461dA967001C1404EB52 = (1000000000000000000 / base_fps) - (base * 100000000); // 小數點位
		
		//get time period(100ns) per frame

		LONGLONG a_temp = 10000000000;
		LONGLONG b_temp = 1000000000000000000;
		
		do_div(a_temp, base_fps);

		LONGLONG base = a_temp;
		
		do_div( b_temp, base_fps);

		LONGLONG FF7E121E5F6A1461dA967001C1404EB52 = b_temp - (base * 100000000); // 小數點位


		d_ts = base;

		if( o_ts == 0 ) { // 第一偵

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] o_ts == 0\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE));

			o_ts = e_ts; 

			d_ts = 0;
		
			FF7E121E5F6A1461dA967001C1404EB52 = 0;

			is_1st = TRUE;

			pVideo->m_nLastPresentationTime = e_ts;

			pVideo->m_nLastPresentationTimeMultipler = 0;
		}
		else {

			pVideo->m_nLastPresentationTimeMultipler += (LONG)(FF7E121E5F6A1461dA967001C1404EB52);

			if( pVideo->m_nLastPresentationTimeMultipler >= 100000000 ) {

				pVideo->m_nLastPresentationTimeMultipler -= 100000000;

				d_ts += 1;
			}
		}
		//pDevice->PresentationTime.Time = pDevice->m_nLastPresentationTime + d_ts; // 計算出理想值

		pVideo->m_nNowPresentationTime = pVideo->m_nLastPresentationTime + d_ts; // 計算出理想值

		//pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_sec = (pVideo->m_nNowPresentationTime) / 10000000;
		//pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec = (pVideo->m_nNowPresentationTime) % 10000000;
		
		LONGLONG m_nNowPresentationTime_temp = pVideo->m_nNowPresentationTime;
		pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec = do_div(m_nNowPresentationTime_temp, 10000000);
		pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_sec = m_nNowPresentationTime_temp;

		pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec /= 10;
		
		//LONGLONG d_o = (pDevice->PresentationTime.Time > e_ts) ?
		//
		//			   (pDevice->PresentationTime.Time - e_ts) :
		//
		//			   (e_ts - pDevice->PresentationTime.Time); // 計算出誤差值
		
		LONGLONG d_o = (pVideo->m_nNowPresentationTime > e_ts) ?
		
					   (pVideo->m_nNowPresentationTime - e_ts) :
		
					   (e_ts - pVideo->m_nNowPresentationTime); // 計算出誤差值


		if( d_o > (base >> 1) ) { 

			if( pVideo->m_nLastPresentationTimeFpsErrors >= 100 ||
				
				d_o > 1000000 ) {

				pVideo->m_nLastPresentationTimeFpsErrors = 0;	

#ifdef FH8735_DEBUG_TIMESTAMP
				
				F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "[%02d] base(0d%d)\n", (int)(pDevice->F0C7DF8CDF1004a6eB97071CBDF459ECE), base);

				//F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "TS.DEBUG.VIDEO.%d( RESET#1, d_o = %lld, last.ts = %lld, calc.ts = %lld, e_ts = %lld, errors = %lld )", 0, d_o, pDevice->m_nLastPresentationTime, pDevice->PresentationTime.Time, e_ts, pDevice->m_nLastPresentationTimeFpsErrors);
				F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "TS.DEBUG.VIDEO.%d( RESET#1, d_o = %lld, last.ts = %lld, calc.ts = %lld, e_ts = %lld, errors = %lld )\n", 0, d_o, pVideo->m_nLastPresentationTime, pVideo->m_nNowPresentationTime, e_ts, pVideo->m_nLastPresentationTimeFpsErrors);
#endif
				//pDevice->PresentationTime.Time = e_ts;
				//pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_sec = (e_ts) / 10000000;
				//pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec = (e_ts) % 10000000;
				LONGLONG e_ts_temp = e_ts;
				pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec = do_div(e_ts_temp, 10000000);
				pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_sec = (e_ts_temp);
				
				pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec /= 10;

				pVideo->m_nLastPresentationTimeMultipler = 0;
			}
			else {

				pVideo->m_nLastPresentationTimeFpsErrors++;
			}
		}
		else {

			pVideo->m_nLastPresentationTimeFpsErrors = 0;
		}
				
		if( pDevice->m_nAnalogVideoDecoderStatusProperty == 0 ) {

			//pVideo->PresentationTime.Time = e_ts;
			//pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_sec = (e_ts) / 10000000;
			//pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec = (e_ts) % 10000000;

			LONGLONG e_ts_temp = e_ts;
			pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec = do_div(e_ts_temp, 10000000);
			pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_sec = (e_ts_temp);
			
			pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec /= 10;

			pVideo->m_nLastPresentationTimeMultipler = 0;

			pVideo->m_nLastPresentationTimeFpsErrors = 0;
		}

		#ifndef AME_PL330A
		if( (pDevice->F9D9594A095F0463193B7588374CF8310->vendor == 0x3086 && pDevice->F9D9594A095F0463193B7588374CF8310->device == 0x0101) ) {

			if( pDevice->iManufacturer == 0x8A ||
				
				pDevice->iManufacturer == 0xA8 ||
				
				pDevice->iManufacturer == 0x85 ) {
	
				//pVideo->PresentationTime.Time = e_ts;
				//pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_sec = (e_ts) / 10000000;
				//pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec = (e_ts) % 10000000;
				
				LONGLONG e_ts_temp = e_ts;
				pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec = do_div(e_ts_temp, 10000000);
				pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_sec = (e_ts_temp);
				pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec /= 10;
	
				pVideo->m_nLastPresentationTimeMultipler = 0;
	
				pVideo->m_nLastPresentationTimeFpsErrors = 0;
			}
		}
		#endif

		//if( pDevice->PresentationTime.Time <= pDevice->m_nLastPresentationTime &&
		if( ( (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_sec * 10000000) + (pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec * 10) ) <= pVideo->m_nLastPresentationTime &&
			
			is_1st == FALSE ) {

#ifdef FH8735_DEBUG_TIMESTAMP

			F1838C0176E054c129B7F2BF440D1236E( KERN_INFO, "TS.DEBUG.VIDEO.%d( RESET#2, last.ts = %lld, calc.ts = %lld )\n", 0, pVideo->m_nLastPresentationTime, pVideo->m_nNowPresentationTime);
#endif
			if( e_ts > pVideo->m_nLastPresentationTime ) {

				//pDevice->PresentationTime.Time = e_ts;
				//pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_sec = (e_ts) / 10000000;
				//pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec = (e_ts) % 10000000;
				
				LONGLONG e_ts_temp = e_ts;
				pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec = do_div(e_ts_temp, 10000000);
				pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_sec = (e_ts_temp);
				pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec /= 10;
			}
			else {

				//pDevice->PresentationTime.Time = pDevice->m_nLastPresentationTime + 10000;
				//pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_sec = (pVideo->m_nLastPresentationTime + 10000) / 10000000;
				//pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec = (pVideo->m_nLastPresentationTime + 10000) % 10000000;
				
				LONGLONG m_nLastPresentationTime_temp = pVideo->m_nLastPresentationTime + 10000;
				pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec = do_div(m_nLastPresentationTime_temp, 10000000);
				pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_sec = (m_nLastPresentationTime_temp);

				pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec /= 10;
			}
			pVideo->m_nLastPresentationTimeMultipler = 0;

			pVideo->m_nLastPresentationTimeFpsErrors = 0;
		}
		//pDevice->m_nLastPresentationTime = pDevice->PresentationTime.Time;
		pVideo->m_nLastPresentationTime = pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_sec * 10000000 + pVideoBuffer->F6A821C5E7AA043f999FB3C51DB94DD2B.ts.tv_usec * 10;

		pVideo->m_nLastReferenceClockTime = e_ts;

		//pDevice->Duration = 10000000000 / base_fps;

#ifdef FH8735_DEBUG_TIMESTAMP

		if( is_1st ) {

			ooooo[ 0 ] = e_ts;

			xxxxx[ 0 ] = 0;
		}
		if( (xxxxx[ 0 ]++ % 500) == 0 ) {

			LONGLONG ttttt = e_ts - ooooo[ 0 ];

			ttttt /= xxxxx[ 0 ];

			F966EAAB748564259849CBD3F3D6C48A7( KERN_INFO, "video.%d %lld | (%lld) (%lld) (%lld) (%lld) | ----> (%lld) | (m = %d)\n", 0,
				
				(pVideo->m_nNowPresentationTime), // 計算時間
				
				(xxxxx[ 0 ] * 10000000000) / base_fps,  // 理想時間
				
				(e_ts),  // 實際時間
				
				(pVideo->m_nNowPresentationTime - ((xxxxx[ 0 ] * 10000000000) / base_fps)), // 理想誤差
				
				(pVideo->m_nNowPresentationTime - e_ts), // 實際誤差
				
				//(pDevice->Duration),
				
				ttttt, 
				
				m  );
		}
#endif
	return TRUE;
}

