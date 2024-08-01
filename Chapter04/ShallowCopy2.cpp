//
// Created by Changjoon Lee on 7/21/24.
//
#include "bits/stdc++.h"
#include <iostream>
using namespace std;

class CMyData
{
public:
    CMyData(int nParam)
    {
        m_pnData = new int;
        *m_pnData = nParam;
    }
    CMyData(const CMyData& rhs)
    {
        cout << "CMyData(const CMyData&)" << endl;
        if (!rhs.m_pnData) return;

        this->m_pnData = new int;
        *(this->m_pnData) = *(rhs.m_pnData);
    }

    int GetData(void) const
    {
        if (!m_pnData) return 0;
        return *m_pnData;
    }

    CMyData& operator=(const CMyData& rhs)
    {
        *(this->m_pnData) = *(rhs.m_pnData);
        return *this;
    }

    ~CMyData()
    {
        if (!m_pnData) return;
        delete m_pnData;
    }

private:
    int* m_pnData{nullptr};
};

int main()
{
    CMyData a(10);
    CMyData b(20);

    a = b;
    cout << a.GetData() << endl;
}
