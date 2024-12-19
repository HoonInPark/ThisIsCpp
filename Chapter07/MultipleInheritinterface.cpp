//
// Created by Changjoon Lee on 2024. 11. 22..
//
#include "bits/stdc++.h"
using namespace std;

class CMyUSB
{
public:
    virtual int GetUsbVersion() = 0;
    virtual int GetTrasferRate() = 0;
};

class CMySerial
{
public:
    virtual int GetSerial() = 0;
    virtual int GetRate() = 0;
};

class CMyDevice : public CMyUSB, public CMySerial
{
public:
    virtual int GetUsbVersion() { return 0; }
    virtual int GetTrasferRate() { return 0; }
    virtual int GetSerial() { return 0 ;}
    virtual int GetRate() { return 0 ;}
};

int main()
{
    CMyDevice dev;
}
