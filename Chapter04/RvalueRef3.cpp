//
// Created by Changjoon Lee on 7/30/24.
//
#include "bits/stdc++.h"
using namespace std;

void TestFunc(int&& rParam)
{
    cout << "TestFunc(int&&)" << endl;
}
#if 0
void TestFunc(int rParam)
{
    cout << "TestFunc(int)" << endl;
}
#endif

int main()
{
    TestFunc(3 + 4); // error: call to 'TestFunc' is ambiguous
}