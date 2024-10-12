//
// Created by Changjoon Lee on 2024. 10. 7..
//
#include "bits/stdc++.h"
using namespace std;

#define TEAR_DOWN_OPER 1

class CMyData
{
public:
    explicit CMyData(int nParam)
    {
        m_pnData = new int(nParam);
    }

    ~CMyData() { delete m_pnData; }

    // 자동형변환을 explicit으로 막고 명시적 형변환을 정의한다.
    operator int() { return *m_pnData; }

    CMyData& operator=(const CMyData& rhs)
    {
        if (this == &rhs) return *this;

        delete m_pnData;
        m_pnData = new int(*rhs.m_pnData);
        return *this;
    }
    CMyData& operator+=(const CMyData& rhs)
    {
        int *pnNewData = new int(*m_pnData);
        *pnNewData += *rhs.m_pnData;

        delete m_pnData;
        m_pnData = pnNewData;

        return *this;
    }

private:
    int* m_pnData{nullptr};
};

int main()
{
    CMyData a(0), b(5), c(10);
    a += b;
    a += c;

    cout << a << endl;
}
