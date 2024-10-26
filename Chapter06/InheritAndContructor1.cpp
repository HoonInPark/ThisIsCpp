//
// Created by Changjoon Lee on 2024. 10. 22..
//
#include "bits/stdc++.h"
using namespace std;

class CMyDataA
{
public:
    CMyDataA()
    {
        cout << "CMyDataA()" << endl;
    }
    ~CMyDataA()
    {
        cout << "~CMyDataA()" << endl;
    }
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
    }
    ~CMyDataC()
    {
        cout << "~CMyDataC()" << endl;
    }
};

int main()
{
    cout << "*****Begin*****" << endl;
    CMyDataC data;
    cout << "******End******" << endl;
}