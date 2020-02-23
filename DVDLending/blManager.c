//
//  blManager.c ver 1.0
//  DVDLending
//
//  Created by 김건영 on 2020/02/09.
//  Copyright © 2020 김건영. All rights reserved.
//

#include "common.h"

#include "cusInfo.h"
#include "cusInfoAccess.h"

#include "dvdInfo.h"
#include "dvdInfoAccess.h"

#include "rentInfo.h"
#include "rentInfoAccess.h"

#include "screenOut.h"
#include "blManager.h"

#define DVD_BACKUP_FILE "DVDLending_data.dat"

/* From cusManager.c */
void RegistCustomer (void)
{
    char ID[ID_LEN];
    char name[NAME_LEN];
    char phonenum[PHONE_LEN];
    
    fputs("ID 입력: ", stdout);
    fgets(ID, ID_LEN, stdin);
    ID[strlen(ID)-1]=0;
    
    if(IsRegistID(ID))
    {
        puts("해당 ID는 사용 중에 있습니다. 다른 ID를 선택해주십시오.");
        getchar();
        return;
    }
    
    fputs("이름 입력: ", stdout);
    fgets(name, NAME_LEN, stdin);
    name[strlen(name)-1]=0;
    
    fputs("전화번호 입력: ", stdout);
    fgets(phonenum, PHONE_LEN, stdin);
    phonenum[strlen(phonenum)-1]=0;
    
    if(!AddCusInfo(ID, name, phonenum))
    {
        puts("더 이상 신규가입을 할 수 없습니다.");
        getchar();
        return;
    }
    
    puts("가입이 완료되었습니다. ");
    StoreDataToFile();
    getchar();
}

void SearchCusInfo(void)
{
    char ID[ID_LEN];
    cusInfo * pCus;
    
    fputs("찾는 ID 입력: ",stdout);
    fgets(ID, ID_LEN, stdin);
    ID[strlen(ID)-1]=0;
    
    if(!IsRegistID(ID))
    {
        puts("해당 ID는 존재하지 않습니다.");
        getchar();
        return;
    }
    
    pCus=GetCusPtrByID(ID);
    ShowCustomerInfo(pCus);
}

/* From dvdManager.c */
void RegistDvd (void)
{
    char isbn[ISBN_LEN];
    char title[TITLE_LEN];
    int genre;
    
    fputs("ISBN 입력: ", stdout);
    fgets(isbn, ISBN_LEN, stdin);
    isbn[strlen(isbn)-1]=0;
    
    if(IsRegistISBN(isbn))
    {
        puts("해당 ISBN는 이미 등록되었습니다.");
        getchar();
        return;
    }
    
    fputs("제목 입력: ", stdout);
    fgets(title, TITLE_LEN, stdin);
    title[strlen(title)-1]=0;
    
    fputs("장르 입력(액션 1, 코믹 2, SF 3, 로맨틱 4) : ", stdout);
    scanf("%d",&genre);
    fflush(stdin);
    
    if(!AddDvdInfo(isbn, title, genre))
    {
        puts("정상적인 데이터 저장에 실패하였습니다.");
        getchar();
        return;
    }
    
    puts("등록이 완료되었습니다. ");
    StoreDataToFile();
    getchar();
}

void SearchDvdInfo(void)
{
    char ISBN[ISBN_LEN];
    dvdInfo * pDvd;
    
    fputs("찾는 ISBN 입력: ",stdout);
    fgets(ISBN, ISBN_LEN, stdin);
    ISBN[strlen(ISBN)-1]=0;
    
    if(!IsRegistISBN(ISBN))
    {
        puts("해당 ISBN는 존재하지 않습니다.");
        getchar();
        return;
    }
    
    pDvd=GetDvdPtrByISBN(ISBN);
    ShowDvdInfo(pDvd);
}

void RentDvd (void)
{
    char ISBN[ISBN_LEN];
    char cus_ID[NAME_LEN];
    unsigned int rent_day;
    dvdInfo * pDvd;
    
    fputs("대여 ISBN 입력: ", stdout);
    gets(ISBN);
    
    if(!IsRegistISBN(ISBN))
    {
        puts("해당 DVD는 등록되어있지 않습니다. ");
        return;
    }
    
    pDvd=IsDvdRentPossible(ISBN);
    
    if(pDvd==0)
    {
        puts("대여 중이라 대여가 불가능합니다. ");
        return;
    }
    else
        puts("대여가 가능합니다. 대여 과정을 진행합니다. ");
    
    fputs("대여 고객 ID 입력: ", stdout);
    gets(cus_ID);
    
    if(!IsRegistID(cus_ID))
    {
        puts("가입 고객이 아닙니다. ");
        return;
    }
    
    fputs("대여 날짜 입력: ", stdout);
    scanf("%d",&rent_day);
    fflush(stdin);
    
    pDvd->rentState=RENTED;
    
    AddRentList(ISBN, cus_ID, rent_day);
    StoreDataToFile();
    puts("대여가 완료되었습니다. ");
}

void ReturnDvd (void)
{
    char ISBN[ISBN_LEN];
    dvdInfo * pDvd;
    
    fputs("반납 DVD ISBN 입력: ", stdout);
    gets(ISBN);
    
    if(!IsRegistISBN(ISBN))
    {
        puts("등록되지 않은 ISBN 입니다.");
        return;
    }
    
    if(IsDvdRentPossible(ISBN)!=0)
    {
        puts("대여되지 않은 DVD 입니다.");
        return;
    }
    
    pDvd=GetDvdPtrByISBN(ISBN);
    
    pDvd->rentState=RETURNED;
    
    StoreDataToFile();
    puts("반납이 완료되었습니다. ");
}

void ShowAllRentCus (void)
{
    char ISBN[ISBN_LEN];
    
    fputs("찾는 ISBN 입력: ", stdout);
    gets(ISBN);
    
    if(!IsRegistISBN(ISBN))
    {
        puts("등록되지 않은 ISBN 입니다.");
        return;
    }
    
    PrintOutRentAllCusInfo(ISBN);
    
    puts("조회를 완료하였습니다.");
}

void ShowAllRentDvd (void)
{
    char cusID[ID_LEN];
    unsigned int start, end;
    
    fputs("찾는 ID 입력: ", stdout);
    gets(cusID);
    
    fputs("대여 기간 입력: ", stdout);
    scanf("%d %d",&start,&end);
    fflush(stdin);
        
    PrintOutCusAllRentInfo(cusID,start,end);
    
    puts("조회를 완료하였습니다. ");
}

void StoreDataToFile(void)
{
    FILE * fp_store=fopen(DVD_BACKUP_FILE, "wb");
    int i;
    
    fprintf(fp_store,"%d ",returnNumOfCustomer());
    for(i=0;i<returnNumOfCustomer();i++)
        fwrite(GetCusPtrByNum(i), sizeof(cusInfo), 1, fp_store);
    
    fprintf(fp_store, "%d ",returnNumOfDvd());
    for(i=0;i<returnNumOfDvd();i++)
        fwrite(GetDvdPtrByNum(i), sizeof(dvdInfo), 1, fp_store);
    
    fprintf(fp_store, "%d ",returnNumOfRentCus());
    for(i=0;i<returnNumOfRentCus();i++)
        fwrite(returnDvdRentInfoPtrByNum(i), sizeof(dvdRentInfo), 1, fp_store);
    
    fclose(fp_store);
}

void LoadDataFromFile(void)
{
    FILE * fp_load=fopen(DVD_BACKUP_FILE, "rb");
    int numOfCustomer, numOfDvd, numOfRentCus;
    cusInfo cus;
    dvdInfo dvd;
    dvdRentInfo dvdrent;
    int i;
    
    if(fp_load==NULL)
        return;
    
    fscanf(fp_load, "%d ",&numOfCustomer);
    for(i=0;i<numOfCustomer;i++)
    {
        fread(&cus, sizeof(cusInfo), 1, fp_load);
        AddCusInfo(cus.ID, cus.name, cus.phoneNum);
    }
    
    fscanf(fp_load, "%d ",&numOfDvd);
    for(i=0;i<numOfDvd;i++)
    {
        fread(&dvd, sizeof(dvdInfo), 1, fp_load);
        AddDvdInfo(dvd.ISBN, dvd.title, dvd.genre);
    }
        
    fscanf(fp_load, "%d ",&numOfRentCus);
    for(i=0;i<numOfRentCus;i++)
    {
        fread(&dvdrent, sizeof(dvdRentInfo), 1, fp_load);
        AddRentList(dvdrent.ISBN, dvdrent.cusID, dvdrent.rentDay);
    }
    
    
    fclose(fp_load);
}

