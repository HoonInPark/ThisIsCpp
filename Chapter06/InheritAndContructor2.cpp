//
// Created by Changjoon Lee on 2024. 10. 23..
//
#include "bits/stdc++.h"

using namespace std;

class CMyDataA
{
public:
    CMyDataA()
    {
        cout << "CMyDataA()" << endl;
        m_pszData = new char[32];
    }
    ~CMyDataA()
    {
        cout << "~CMyDataA()" << endl;
        delete[] m_pszData;
    }

protected:
    char* m_pszData;
};

class CMyDataB : public CMyDataA
{
public:
    CMyDataB()
    {
        cout << "CMyDataB()" << endl;
    }
    ~CMyDataB()
    {
        cout << "~CMyDataB()" << endl;
    }
};

class CMyDataC : CMyDataB
{
public:
    CMyDataC()
    {
        cout << "CMyDataC()" << endl;

        for (int i = 0; i < 32; ++i)
        {
            m_pszData[i] = 'a';
        }
    }
    ~CMyDataC()
    {
        cout << "~CMyDataC()" << endl;
    }
};

int main()
{
    CMyDataC data;
}
