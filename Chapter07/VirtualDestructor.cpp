//
// Created by Changjoon Lee on 2024. 10. 27..
//
#include "bits/stdc++.h"
using namespace std;

class CMyData
{
public:
    CMyData() { m_pszData = new char[32]; }
    virtual ~CMyData()
    {
        cout << "~CMyData()" << endl;
        delete[] m_pszData;
    }

private:
    char* m_pszData;
};

class CMyDataEx : public CMyData
{
public:
    CMyDataEx() { m_pnData = new int; }
    ~CMyDataEx()
    {
        cout << "~CMyDataEx()" << endl;
        delete m_pnData;
    }

private:
    int* m_pnData;
};

int main()
{
    /*
    * 일반적인 함수의 호출은 참조형식의 함수를 따른다.
    * 즉, new로 객체화될 때 우항에서 CMyDataEx의 생성자가 호출되지만
    * main()의 스코프를 벗어날 때는 참조형식인 CMyData의 소멸자가 호출됨.
    * */
    CMyData* pData = new CMyDataEx;

    /*
     * 그러면 CMyDataEx의 소멸자가 호출되지 않기에
     * 우항에서 CMyDataEx을 생성하면서 할당한 부모 클래스CMyDataEx의 멤버인  m_pnData가
     * delete pData로는 해제되지 않는 문제가 생김.
     *
     * 다만 CMyDataEx 클래스에서 소멸자를 virtual로 선언하면
     * 자동으로 자식 형식인 CMyData로 참조된 객체가 해제될 때 같이 호출됨.
     * */
    delete pData;
}
