#include "bits/stdc++.h"

using namespace std;

class CMyData
{
public:
    virtual void PrintData()
    {
        cout << "CMyData : " << m_nData << endl;
    }

    void TestFunc()
    {
        cout << "*** TestFunc() ***" << endl;
        PrintData();
        cout << "******************" << endl;
    }

protected:
    int m_nData{10};
};

class CMyDataEx : public CMyData
{
public:
    virtual void PrintData()
    {
        cout << "CMyDataEx : " << m_nData * 2 << endl;
    }
};

int main()
{
    CMyDataEx a;
    a.PrintData();

    CMyData &b = a;
    b.PrintData(); // 가상함수는 일반 메서드와는 반대로 실형식의 메서드가 호출된다.

    // 이 TestFunc 안에서 호출하는 PrintData는 CMyDataEx에서 재정의된 가상함수이다.
    // 그래서 출력값이 20이 나오는 것.
    a.TestFunc();
}
