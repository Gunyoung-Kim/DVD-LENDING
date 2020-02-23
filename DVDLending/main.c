//
//  main.c ver 1.4
//  DVDLending
//
//  Created by 김건영 on 2020/02/06.
//  Copyright © 2020 김건영. All rights reserved.
//

#include "common.h"
#include "blManager.h"
#include "screenOut.h"

enum{CUS_REGIST=1, CUS_RESEARCH, DVD_REGIST, DVD_RESEARCH, DVD_RENT, DVD_RETURN,
     DVD_RENT_ALLCUS, DVD_RENT_ALLDVD, QUIT};

int main (void)
{
    int inputMenu =0;
    
    LoadDataFromFile();
    
    while(1)
    {
        ShowMenu();
        scanf("%d",&inputMenu);
        fflush(stdin);
        
        switch(inputMenu)
        {
            case CUS_REGIST:
                RegistCustomer();
                break;
            case CUS_RESEARCH:
                SearchCusInfo();
                break;
            case DVD_REGIST:
                RegistDvd();
                break;
            case DVD_RESEARCH:
                SearchDvdInfo();
                break;
            case DVD_RENT:
                RentDvd();
                break;
            case DVD_RETURN:
                ReturnDvd();
                break;
            case DVD_RENT_ALLCUS:
                ShowAllRentCus();
                break;
            case DVD_RENT_ALLDVD:
                ShowAllRentDvd();
                break;
        }
        
        if(inputMenu==QUIT)
        {
            puts("이용해 주셔서 고마워요~");
            break;
        }
    }
    return 0;
}
