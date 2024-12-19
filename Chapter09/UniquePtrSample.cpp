//
// Created by Changjoon Lee on 2024. 12. 8..
//
#include "bits/stdc++.h"
using namespace std;

class CTest
{
public:
    CTest() { cout << "CMyData()" << endl; }
    ~CTest() { cout << "~CMyData()" << endl; }
    void TestFunc() { cout << "TestFunc()" << endl; }
};

int main()
{
    unique_ptr<CTest> ptr1(new CTest);
//    unique_ptr<CTest> ptr2(ptr1); // 컴파일 에러 발생, 컴파일 타임에서부터 얕은 복사 불가하도록 만듦.

}
