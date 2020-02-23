//
//  dvdInfoAccess.c ver 1.3
//  DVDLending
//
//  Created by 김건영 on 2020/02/07.
//  Copyright © 2020 김건영. All rights reserved.
//

#include "common.h"
#include "screenOut.h"
#include "dvdInfoAccess.h"
#include "dvdInfo.h"

#define MAX_DVD 100

static dvdInfo * dvdList[MAX_DVD];
static int numOfDvd=0;

int AddDvdInfo(char * ISBN,char * title,int genre)
{
    dvdInfo * pDvd;
    
    if(numOfDvd>=MAX_DVD)
        return 0;
    
    pDvd=(dvdInfo *)malloc(sizeof(dvdInfo));
    
    strcpy(pDvd->ISBN,ISBN);
    strcpy(pDvd->title, title);
    pDvd->genre=genre;
    
    dvdList[numOfDvd]=pDvd;
    dvdList[numOfDvd++]->rentState=1;
    
    return numOfDvd;
}

dvdInfo * GetDvdPtrByISBN(char * ISBN)
{
    int i;
    
    for(i=0;i<numOfDvd;i++)
        if(!strcmp(dvdList[i]->ISBN, ISBN))
            return dvdList[i];
    
    return (dvdInfo*)0;
}

int IsRegistISBN(char *ISBN)
{
    dvdInfo * pDvd =GetDvdPtrByISBN(ISBN);
    
    if(pDvd==0)
        return 0;
    else
        return 1;
}

dvdInfo * IsDvdRentPossible(char * ISBN)
{
    dvdInfo * pDvd;
    
    pDvd=GetDvdPtrByISBN(ISBN);
    
    if((pDvd->rentState)==RENTED)
        return (dvdInfo *)0;
    else
        return pDvd;
}

int returnNumOfDvd (void)
{
    return numOfDvd;
}

dvdInfo * GetDvdPtrByNum(int i)
{
    return dvdList[i];
}
