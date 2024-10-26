//
// Created by Changjoon Lee on 2024. 10. 26..
//
#include "bits/stdc++.h"
using namespace std;

class CMyData
{
public:
    CMyData() { cout << "CMyData()" << endl; }
    CMyData(int nParam) { cout << "CMyData(int)" << endl; }
    CMyData(double dParam) { cout << "CMyData(double)" << endl; }
};

class CMyDataEx : public CMyData
{
public:
    CMyDataEx() { cout << "CMyDataEx()" << endl; }

    /*
     * 에이 뭐야 언리얼에서 쓰는 Super랑 똑같네...
     * */
    CMyDataEx(int nParam) : CMyData(nParam)
    {
        cout << "CMyData(int)" << endl;
    }

    CMyDataEx(double dParam) : CMyData()
    {
        cout << "CMyData(double)" << endl;
    }
};

int main()
{
    CMyDataEx a;
    cout << "**********" << endl;
    CMyDataEx b(5);
    cout << "**********" << endl;
    CMyDataEx c(3.3);
}