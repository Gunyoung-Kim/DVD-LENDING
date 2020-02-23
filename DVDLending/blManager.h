//
//  blManager.h ver 1.0
//  DVDLending
//
//  Created by 김건영 on 2020/02/09.
//  Copyright © 2020 김건영. All rights reserved.
//

#ifndef blManager_h
#define blManager_h

/* From cusmanager.h */
void RegistCustomer (void);
void SearchCusInfo(void);

/* From dvdManager.h */
void RegistDvd (void);
void SearchDvdInfo(void);

void RentDvd(void);
void ReturnDvd(void);

void ShowAllRentCus (void);
void ShowAllRentDvd (void);

void StoreDataToFile(void);
void LoadDataFromFile(void);

#endif /* blManager_h */
