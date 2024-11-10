//
// Created by Changjoon Lee on 2024. 10. 30..
//
#include "bits/stdc++.h"
using namespace std;

class CMyInterface
{
public:
    CMyInterface()
    {
        cout << "CMyInterface()" << endl;
    }

    virtual int GetData() const = 0;
    virtual void SetData(int nParam) = 0;
};

class CMyData : public CMyInterface
{
public:
    CMyData()
    {
        cout << "CMyData()" << endl;
    }

    virtual int GetData() const
    {
        return m_nData;
    }

    /*
     * 순수가상함수 SetData(int)를 주석처리하면 main()에서 다음과 같이 컴파일에러가 난다.
     * Variable type 'CMyData' is an abstract class
     * 추상클래스를 상속받았는데 SetData(int) 구현부가 없으므로 CMyData를 추상클래스로 간주하는 듯.
     * */
    virtual void SetData(int nParam)
    {
        m_nData = nParam;
    }

private:
    int m_nData{0};
};

int main ()
{
    CMyData a;
    a.SetData(5);
    cout << a.GetData() << endl;
}
