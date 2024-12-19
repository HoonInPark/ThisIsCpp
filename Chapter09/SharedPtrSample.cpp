//
// Created by Changjoon Lee on 2024. 12. 3..
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
    cout << "********Begin********" << endl;
    shared_ptr<CTest> ptr1(new CTest);
    cout << "Counter : " << ptr1.use_count() << endl;
    {
        shared_ptr<CTest> ptr2(ptr1);
        cout << "Counter : " << ptr1.use_count() << endl;
        ptr2->TestFunc();
    }

    cout << "Counter : " << ptr1.use_count() << endl;
    ptr1->TestFunc();
    cout << "*********End*********" << endl;
}
