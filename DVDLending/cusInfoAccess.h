//
//  cusInfoAccess.h ver 1.1
//  DVDLending
//
//  Created by 김건영 on 2020/02/07.
//  Copyright © 2020 김건영. All rights reserved.
//

#ifndef cusInfoAccess_h
#define cusInfoAccess_h

#include "cusInfo.h"

int AddCusInfo(char * ID,char * name,char * num);
cusInfo * GetCusPtrByID(char * ID);
int IsRegistID(char *ID);

int returnNumOfCustomer(void);
cusInfo * GetCusPtrByNum(int i);

#endif /* cusInfoAccess_h */
