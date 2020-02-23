//
//  screenOut.c ver 1.3
//  DVDLending
//
//  Created by 김건영 on 2020/02/07.
//  Copyright © 2020 김건영. All rights reserved.
//

#include "common.h"
#include "cusInfo.h"
#include "dvdInfo.h"

void ShowMenu(void)
{
    system("clear");
    
    printf("--------- MENU -------------- \n");
    printf("1. 신규가입 \n");
    printf("2. 고객검색 \n");
    printf("----------------------------- \n");
    printf("3. DVD 등록 \n");
    printf("4. DVD 검색 \n");
    printf("----------------------------- \n");
    printf("5. DVD 대여 \n");
    printf("6. DVD 반납 \n");
    printf("----------------------------- \n");
    printf("7. DVD 대여고객 전체 조회 \n");
    printf("8. 고객 대여 DVD 전체 조회 \n");
    printf("----------------------------- \n");
    printf("9. 종료 \n");
    printf("----------------------------- \n");
    printf("선택>> ");
}

void ShowCustomerInfo (cusInfo * pCus)
{
    system("clear");
    
    printf("⎾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ \n"  );
    printf("ㅣ ▶︎ ID : %s \n", pCus->ID);
    printf("ㅣ ▶︎ 이름 : %s \n", pCus->name);
    printf("ㅣ ▶︎ 전화번호 : %s \n", pCus->phoneNum);
    printf("⎿⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽ \n\n ");
    
    puts("");
}

void ShowDvdInfo (const dvdInfo * pDvd)
{
    system("clear");
       
    printf("⎾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾ \n"  );
    printf("ㅣ ▶︎ ISBN : %s \n", pDvd->ISBN);
    printf("ㅣ ▶︎ 타이틀 : %s \n",pDvd->title);
    switch(pDvd->genre)
    {
        case ACTION:
            puts("ㅣ ▶︎ 쟝르 : 액션");
            break;
        case COMIC:
            puts("ㅣ ▶︎ 쟝르 : 코믹");
            break;
        case SF:
            puts("ㅣ ▶︎ 쟝르 : 공상과학");
        case ROMANTIC:
            puts("ㅣ ▶︎ 쟝르 : 로맨틱");
    }
    printf("⎿⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽ \n\n ");
    
    getchar();
}
