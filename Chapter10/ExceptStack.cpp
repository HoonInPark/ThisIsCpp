//
// Created by Changjoon Lee on 2024. 12. 28..
//
#include "bits/stdc++.h"

using namespace std;

void TestFunc1()
{
    cout << "****TestFunc1() - Begin****" << endl;
    throw 0; // 여기서 예외가 터지면?
    cout << "****TestFunc1() - End******" << endl;
}

void TestFunc2()
{
    cout << "****TestFunc2() - Begin****" << endl;
    TestFunc1();
    cout << "****TestFunc2() - End******" << endl;
}

void TestFunc3()
{
    try
    {
        cout << "****TestFunc3() - Begin****" << endl;
        TestFunc2();
        cout << "****TestFunc3() - End******" << endl;
    }
    catch (...)
    {
        cout << "Exception Handling" << endl;
    }
}

int main()
{
    TestFunc3();
}
