//
//  rentInfoAccess.c ver 1.2
//  DVDLending
//
//  Created by 김건영 on 2020/02/09.
//  Copyright © 2020 김건영. All rights reserved.
//

#include "common.h"
#include "rentInfo.h"
#include "cusInfo.h"
#include "cusInfoAccess.h"
#include "screenOut.h"

#define RENT_LEN 100

static dvdRentInfo rentList[RENT_LEN];
static int numOfRentCus=0;

void AddRentList(char * ISBN, char * cusID, int rentDay)
{
    strcpy(rentList[numOfRentCus].ISBN, ISBN);
    strcpy(rentList[numOfRentCus].cusID, cusID);
    rentList[numOfRentCus++].rentDay=rentDay;
}

void PrintOutRentAllCusInfo(char * ISBN)
{
    int i;
    
    for(i=0;i<numOfRentCus;i++)
    {
        if(!strcmp(rentList[i].ISBN, ISBN))
        {
            printf("대여일: %d \n",rentList[i].rentDay);
            ShowCustomerInfo(GetCusPtrByID(rentList[i].cusID));
        }
    }
}

void PrintOutCusAllRentInfo(char * ID,unsigned int start, unsigned int end)
{
    int i;
    
    for(i=0;i<numOfRentCus;i++)
    {
        if(!strcmp(rentList[i].cusID, ID))
        {
            if(rentList[i].rentDay>=start && rentList[i].rentDay<=end)
            {
                printf("⎾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ \n");
                printf("ㅣ ▶︎ ISBN : %s \n", rentList[i].ISBN);
                printf("ㅣ ▶︎ 대여일 : %d \n",rentList[i].rentDay);
                printf("⎿⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽ \n\n ");
            }
        }
    }
}

int returnNumOfRentCus(void)
{
    return numOfRentCus;
}

dvdRentInfo * returnDvdRentInfoPtrByNum(int i)
{
    return &rentList[i];
}
