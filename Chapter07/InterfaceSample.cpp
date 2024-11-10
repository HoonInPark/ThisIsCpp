//
// Created by Changjoon Lee on 2024. 11. 3..
//
#include "bits/stdc++.h"

using namespace std;

class CMyObject
{
public:
    CMyObject() {}

    virtual ~CMyObject() {}

    virtual int GetDeviceID() = 0;

protected:
    int m_nDeviceID;
};

void PrintData(CMyObject* pObj)
{
    cout << "Device ID : " << pObj->GetDeviceID() << endl;
}

class CMyTV : public CMyObject
{
public:
    CMyTV(int nID) { m_nDeviceID = nID; }
    virtual int GetDeviceID()
    {
        cout << "CMyTV::GetDeviceID()" << endl;
        return m_nDeviceID;
    }
};

class CMyPhone : public CMyObject
{
public:
    CMyPhone(int nID) { m_nDeviceID = nID; }
    virtual int GetDeviceID()
    {
        cout << "CMyPhone::GetDeviceID()" << endl;
        return m_nDeviceID;
    }
};

int main()
{
    CMyTV a(5);
    CMyPhone b(10);

    ::PrintData(&a);
    ::PrintData(&b);
}