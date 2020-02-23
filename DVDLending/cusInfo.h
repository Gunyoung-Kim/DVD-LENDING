//
//  cusInfo.h ver 1.0
//  DVDLending
//
//  Created by 김건영 on 2020/02/07.
//  Copyright © 2020 김건영. All rights reserved.
//

#ifndef cusInfo_h
#define cusInfo_h

#define ID_LEN 10
#define NAME_LEN 30
#define PHONE_LEN 30

typedef struct _cusInfo
{
    char ID[ID_LEN];
    char name[NAME_LEN];
    char phoneNum[PHONE_LEN];
}cusInfo;


#endif /* cusInfo_h */
