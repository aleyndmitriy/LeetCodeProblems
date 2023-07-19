//
//  CUserProfileData.h
//  LeetCodeProblems
//
//  Created by Dmitriy Aleynikov on 4.05.23.
//

#ifndef CUserProfileData_h
#define CUserProfileData_h
#include "ServicesConsts.h"
struct CUserProfileData
{
    char userID[MAX_LENGTH];
    char givenName[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char email[MAX_LENGTH];
    char name[MAX_LENGTH];
    char familyName[MAX_LENGTH];
    char accessToken[MAX_LENGTH];
    int serviceType;
};

#endif /* CUserProfileData_h */
