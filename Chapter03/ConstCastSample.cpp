//
// Created by Changjoon Lee on 7/15/24.
//

#include "bits/stdc++.h"

void TestFunc(const int& nParam)
{
    int& nNewParam = const_cast<int&>(nParam);
    nNewParam = 20;
}

int main()
{
    int nData = 10;
    TestFunc(nData);

    cout << nData << endl;
}