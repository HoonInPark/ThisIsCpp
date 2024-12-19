//
// Created by Changjoon Lee on 2024. 11. 11..
//
#include "bits/stdc++.h"

using namespace std;

#define COMPILER_COMPREHEND_USING_STATEMENT_LIKE_THIS 0

class CMyData
{
public:
    CMyData(int nParam) : m_nData(nParam) {}

    // 리턴은 int지만 리턴타입은 CMyData여서 생성자 CMyData(int)가 호출된다. 즉, 객체를 생성.
    CMyData operator+(const CMyData& rhs)
    {
        return m_nData + rhs.m_nData;
    }

    CMyData& operator=(const CMyData& rhs)
    {
        m_nData = rhs.m_nData;
        return *this;
    }

    operator int() { return m_nData; }

protected:
    int m_nData{0};
};

/*
 * 모든 연산자는 파생형식에 자동으로 상속된다. 하지만 단순대입 연산자는 그렇지 않다.
 * CMyData::operator+는 반환타입이 CMyData이므로 r-val이 CMyData인데 l-val은 CMyDataEx여서 컴파일 에러가 생김.
 * */
class CMyDataEx : public CMyData
{
public:
    CMyDataEx(int nParam) : CMyData(nParam) {}
//    CMyDataEx operator+(const CMyDataEx& rhs) { return CMyDataEx(static_cast<int>(CMyData::operator+(rhs))); }
//    CMyDataEx operator+(const CMyDataEx& rhs) { return CMyDataEx(m_nData + rhs.m_nData); }

#if COMPILER_COMPREHEND_USING_STATEMENT_LIKE_THIS
    CMyDataEx operator+(const CMyDataEx& rhs)
    {
        return m_nData + rhs.m_nData;
    }
    CMyDataEx& operator=(const CMyDataEx& rhs)
    {
        m_nData = rhs.m_nData;
        return *this;
    }
#endif

    using CMyData::operator+;
    using CMyData::operator=;
};

int main()
{
//    CMyData a(3), b(4);
//    cout << a + b << endl;

    CMyDataEx c(3), d(4), e(0);

    e = c + d; // error: no viable overloaded '='
    cout << e << endl;
}
