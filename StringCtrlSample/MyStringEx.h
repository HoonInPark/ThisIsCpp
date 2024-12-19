//
// Created by Changjoon Lee on 2024. 10. 21..
//

#ifndef STRINGCTRLSAMPLE_MYSTRINGEX_H
#define STRINGCTRLSAMPLE_MYSTRINGEX_H


#include "MyString.h"

#define IS_PRACTICE_10 0

class CMyStringEx : public CMyString
{
public:
    using CMyString::CMyString;

    int Find(const char* pszParam);
    virtual void OnSetString(char* pszData, int nLength);

#if IS_PRACTICE_10
    int SetString(const char* pszParam = "");
#endif
};


#endif //STRINGCTRLSAMPLE_MYSTRINGEX_H
