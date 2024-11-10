//
// Created by Changjoon Lee on 2024. 11. 3..
//
#include "bits/stdc++.h"

using namespace std;

#define DEFAULT_FARE 1000

class CPerson
{
public:
    CPerson() {}

    virtual ~CPerson()
    {
        cout << "virtual ~CPerson()" << endl;
    }

    virtual void CalcFare() = 0;

    virtual unsigned int GetFare() { return m_nFare; }

protected:
    unsigned int m_nFare{0};
};

class CBaby : public CPerson
{
public:
    virtual void CalcFare() { m_nFare = 0; }
};

class CChild : public CPerson
{
public:
    virtual void CalcFare()
    {
        m_nFare = DEFAULT_FARE * 50 / 100;
    }
};

class CTeen : public CPerson
{
public:
    virtual void CalcFare()
    {
        m_nFare = DEFAULT_FARE * 75 / 100;
    }
};

class CAdult : public CPerson
{
public:
    virtual void CalcFare()
    {
        m_nFare = DEFAULT_FARE;
    }
};


int main()
{
    CPerson* arList[3] = {0};
    int nAge = 0;

    for (auto& person : arList)
    {
        cout << "나이를 입력하세요 : ";
        cin >> nAge;

        if (nAge < 8)
            person = new CBaby;
        else if (nAge < 14)
            person = new CChild;
        else if (nAge < 20)
            person = new CTeen;
        else
            person = new CAdult;

        person->CalcFare();
    }

    for (auto person : arList)
        cout << person->GetFare() << "원" << endl;

    for (auto person : arList)
        delete person;
}
