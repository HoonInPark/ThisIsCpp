//
// Created by Changjoon Lee on 2024. 10. 26..
//
#include "bits/stdc++.h"
using namespace std;

#define BEFORE_ABBREVIATED 0

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
#if BEFORE_ABBREVIATED
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
#else
    /*
     * 이렇게 하면 부모 클래스의 생성자를 그대로 쓸 수 있다.
     * 즉, CMyDataEx를 생성하면 부모 클래스의 생성자가 그 인수에 맞게 호출됨.
     * */
    using CMyData::CMyData;
#endif
};

int main()
{
    CMyDataEx a;
    cout << "**********" << endl;
    CMyDataEx b(5);
    cout << "**********" << endl;
    CMyDataEx c(3.3);
}