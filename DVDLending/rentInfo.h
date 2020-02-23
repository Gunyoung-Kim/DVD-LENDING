//
//  rentInfo.h ver 1.0
//  DVDLending
//
//  Created by 김건영 on 2020/02/09.
//  Copyright © 2020 김건영. All rights reserved.
//

#ifndef rentInfo_h
#define rentInfo_h

#include "dvdInfo.h"
#include "cusInfo.h"

typedef struct _dvdRentInfo
{
    char cusID[ID_LEN];
    char ISBN[ISBN_LEN];
    unsigned int rentDay;
}dvdRentInfo;

#endif /* rentInfo_h */
