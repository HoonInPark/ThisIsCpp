//
// Created by Changjoon Lee on 2024. 10. 21..
//

#ifndef STRINGCTRLSAMPLE_MYSTRINGEX_H
#define STRINGCTRLSAMPLE_MYSTRINGEX_H


#include "MyString.h"

class CMyStringEx : public CMyString
{
public:
    int Find(const char* pszParam);
};


#endif //STRINGCTRLSAMPLE_MYSTRINGEX_H
