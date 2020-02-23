//
//  dvdInfo.h ver 1.2
//  DVDLending
//
//  Created by 김건영 on 2020/02/07.
//  Copyright © 2020 김건영. All rights reserved.
//

#ifndef dvdInfo_h
#define dvdInfo_h

#include "cusInfo.h"

#define ISBN_LEN 30
#define TITLE_LEN 30

enum {ACTION=1, COMIC, SF, ROMANTIC};
enum {RENTED, RETURNED};

typedef struct _dvdInfo
{
    char ISBN[ISBN_LEN];
    char title[TITLE_LEN];
    int genre;
    int rentState;
}dvdInfo;

#endif /* dvdInfo_h */
