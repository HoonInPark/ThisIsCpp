//
// Created by Changjoon Lee on 2024. 10. 27..
//
#include "bits/stdc++.h"

using namespace std;

class CMyData
{
public:
    CMyData()
    {
        cout << "CMyData()" << endl;
    }

    virtual ~CMyData() {}

    virtual void TestFunc1() {}

    virtual void TestFunc2() {}
};

class CMyDataEx : public CMyData
{
public:
    CMyDataEx()
    {
        cout << "CMyDataEx()" << endl;
    }

    virtual ~CMyDataEx() {}

    virtual void TestFunc1() {}

    virtual void TestFunc2() { cout << "TestFunc2()" << endl; }
};

int main()
{
    // 가상함수인 TestFunc2()는 참조형식 보다 실형식이 우선한다.
    CMyData* pData = new CMyDataEx;
    // Cannot initialize a variable of type 'CMyDataEx *' with an rvalue of type 'CMyData *'
    //CMyDataEx* pData = new CMyData;
    // 그래서 실형식인 CMyDataEx의 TestFunc2()가 호출된다.
    pData->TestFunc2();
    delete pData;
}
