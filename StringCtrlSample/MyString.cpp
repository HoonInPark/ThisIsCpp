//
// Created by Changjoon Lee on 2/4/24.
//
#include <bits/stdc++.h>
#include "MyString.h"

#define MY_CODE_MUST_BE_CORRECTED 0
#define DANGER_FOR_DEL_ORIGIN_WHEN_CMYSTRING_CLASS_FREED 0

/*
 * TODO : 1. const char*에 대한 변환생성자 만들기
 * TODO : 2. char*로의 형변환 연산자 만들기
 *
 */

CMyString::CMyString()
{

}

CMyString::CMyString(const char* _str)
{
    cout << "CMyString(const char*)" << endl;
}

CMyString::CMyString(const CMyString& rhs)
{
    strcpy(this->m_pszData, rhs.m_pszData);
}

CMyString::CMyString(CMyString&& rhs)
        : m_pszData(nullptr),
          m_nLength(0)
{
    cout << "CMyString 이동생성자 호출" << endl;

    m_pszData = rhs.m_pszData;
    m_nLength = rhs.m_nLength;

    rhs.m_pszData = nullptr;
    rhs.m_nLength = 0;
}

CMyString::~CMyString()
{

}

int CMyString::SetString(const char* pszParam)
{
#if MY_CODE_MUST_BE_CORRECTED
    m_nLength = strlen(pszParam);

    char* psTemp = new char();
    if (!pszParam)
    {
        m_pszData = (char*)("");
        return 0;
    }
    *psTemp = *pszParam;
    m_pszData = psTemp;

    return 1;
#endif

    if (m_pszData)
        Release();

    if (!pszParam) return 0;

    int nLength = strlen(pszParam);
    if (!nLength) return 0;

    m_pszData = new char[nLength + 1];
#if DANGER_FOR_DEL_ORIGIN_WHEN_CMYSTRING_CLASS_FREED
    m_pszData = (char*)pszParam;
#endif
    strcpy(m_pszData, pszParam);

    m_nLength = nLength; // Set할 떄 이외의 상황에선 m_nLenth는 읽는 등의 행위를 하지 않고 있다.
    return nLength;
}

const char* CMyString::GetString() const
{
    return m_pszData;
}

void CMyString::Release()
{
    delete[] m_pszData;

    m_pszData = nullptr;
    m_nLength = 0;
}

CMyString& CMyString::operator=(const CMyString& rhs)
{
    strcpy(this->m_pszData, rhs.m_pszData);
    return *this;
}


