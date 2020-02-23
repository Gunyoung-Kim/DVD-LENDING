//
//  rentInfoAccess.h ver 1.1
//  DVDLending
//
//  Created by 김건영 on 2020/02/09.
//  Copyright © 2020 김건영. All rights reserved.
//

#ifndef rentInfoAccess_h
#define rentInfoAccess_h

void AddRentList(char * ISBN, char * cusID, int rentDay);
void PrintOutRentAllCusInfo(char * ISBN);
void PrintOutCusAllRentInfo(char * ID,unsigned int start, unsigned int end);

int returnNumOfRentCus(void);
dvdRentInfo * returnDvdRentInfoPtrByNum(int i);

#endif /* rentInfoAccess_h */
