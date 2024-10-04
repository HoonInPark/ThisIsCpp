//
// Created by Changjoon Lee on 2/4/24.
//
#include "MyString.h"
#include <bits/stdc++.h>

using namespace std;

#define MY_CODE_MUST_BE_CORRECTED 0
#define DANGER_FOR_DEL_ORIGIN_WHEN_CMYSTRING_CLASS_FREED 0
#define RETURN_THIS_AS_R_VAL 0

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

    m_nLength = strlen(_str);
    m_pszData = new char[m_nLength + 1];
    strcpy(m_pszData, _str);
}

CMyString::CMyString(const CMyString& rhs)
{
    m_nLength = rhs.m_nLength;
    m_pszData = new char[m_nLength + 1];
    strcpy(m_pszData, rhs.m_pszData);
}

CMyString::CMyString(CMyString&& rhs)
{
    cout << "CMyString(CMyString&&)" << endl;

    m_nLength = rhs.m_nLength;
    m_pszData = new char[m_nLength + 1];
    strcpy(m_pszData, rhs.m_pszData);
}

CMyString::~CMyString()
{
    cout << "~CMyString()" << endl;

    delete[] m_pszData;
    m_pszData = nullptr;
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

int CMyString::GetLenth() const
{
    return m_nLength;
}

void CMyString::Release()
{
    delete[] m_pszData;

    m_pszData = nullptr;
    m_nLength = 0;
}

int CMyString::Append(const char* pszParam)
{
    if (!pszParam)
        return 0;

    int nLenParam = strlen(pszParam);
    if (!nLenParam)
        return 0;

    if (!m_pszData)
    {
        SetString(pszParam);
        return m_nLength;
    }

    auto pszResult = new char[m_nLength + nLenParam + 1];
    strcpy(pszResult, m_pszData);
    strcpy(pszResult + (sizeof(char) * m_nLength), pszParam); // 이미 있는 위치에 채워지지 않은 부분부터 메모리를 찾아서 복사.

    Release();
    m_pszData = pszResult;
    m_nLength += nLenParam;

    return m_nLength;
}

CMyString& CMyString::operator=(const CMyString& rhs)
{
    m_nLength = rhs.GetLenth();
    if (!m_pszData)
        m_pszData = new char[m_nLength + 1];

    strcpy(m_pszData, rhs.m_pszData);

    return *this;
}

CMyString CMyString::operator+(const CMyString& rhs)
{
#if RETURN_THIS_AS_R_VAL
    Append(rhs.m_pszData);
    return std::move(*this);
#else
    CMyString result(*this);
    result.Append(rhs.m_pszData);
    return std::move(result);
#endif
}

CMyString& CMyString::operator+=(const CMyString& rhs)
{
    Append(rhs.m_pszData);
    return *this;
}
