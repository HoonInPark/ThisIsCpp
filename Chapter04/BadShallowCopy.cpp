//
// Created by Changjoon Lee on 7/21/24.
//
#include "bits/stdc++.h"
using namespace std;

int main()
{
    int* pA,* pB;
    pA = new int;
    *pA = 10;

    pB = new int;

    // 이렇게 하면 가장 처음 pB에 할당됐던 메모리 위치는 그 누구도 해제할 수 없게 된다.
    pB = pA;

    cout << *pA << endl;
    cout << *pB << endl;

    delete pA;
    // 또, 이미 해제된 메모리 주소를 또 해제하려는 문제가 생긴다.
    delete pB;
}
