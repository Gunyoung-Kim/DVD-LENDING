//
//  screenOut.h ver 1.3
//  DVDLending
//
//  Created by 김건영 on 2020/02/07.
//  Copyright © 2020 김건영. All rights reserved.
//

#ifndef screenOut_h
#define screenOut_h

#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu(void);
void ShowCustomerInfo (cusInfo * pCus);
void ShowDvdInfo (dvdInfo * pDvd);

#endif /* screenOut_h */
