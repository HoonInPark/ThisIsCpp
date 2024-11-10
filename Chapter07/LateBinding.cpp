//
// Created by Changjoon Lee on 2024. 10. 30..
//
#include "bits/stdc++.h"
using namespace std;

void TestFunc1(int nParam) {}
void TestFunc2(int nParam) {}

int main()
{
    int nInput = 0;
    cin >> nInput;
    void(*pfTest)(int) = nullptr;

    if (nInput > 10)
        pfTest = TestFunc1;
    else
        pfTest = TestFunc2;

    pfTest(10);
}