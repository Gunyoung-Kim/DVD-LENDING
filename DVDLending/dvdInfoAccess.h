//
//  dvdInfoAccess.h ver 1.3
//  DVDLending
//
//  Created by 김건영 on 2020/02/07.
//  Copyright © 2020 김건영. All rights reserved.
//

#ifndef dvdInfoAccess_h
#define dvdInfoAccess_h

#include "dvdInfo.h"

int AddDvdInfo(char * ISBN,char * title,int genre);
dvdInfo * GetDvdPtrByISBN(char * ISBN);
int IsRegistISBN(char * ISBN);
dvdInfo * IsDvdRentPossible(char * ISBN);

int returnNumOfDvd (void);
dvdInfo * GetDvdPtrByNum(int i);

#endif /* dvdInfoAccess_h */
