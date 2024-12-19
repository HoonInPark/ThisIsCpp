//
// Created by Changjoon Lee on 2024. 12. 7..
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

void RemoveTest(CTest* pTest)
{
    cout << "RemoveTest(Test*)" << endl;
    delete[] pTest;
}

int main()
{
    cout << "*****Begin*****" << endl;
    shared_ptr<CTest> ptr(new CTest[3], RemoveTest);
    cout << "******End******" << endl;
}
