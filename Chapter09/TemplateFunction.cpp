//
// Created by Changjoon Lee on 2024. 12. 1..
//
#include "bits/stdc++.h"
using namespace std;

template<typename T>
T Add(T a, T b) { return a + b; }

/*
 * 아래와 같이 template으로 함수를 선언하고 위의 함수와 동일한 이름을 쓴다면,
 * 위 함수의 T에 들어갔을 내용이 char*라는 뜻임.
 * 많은 타입 중 char*를 넣었을 경우는 아래와 같이 하라는 뜻.
 * 특수한 한 타입에 대한 정의만 따로 만든 것임.
 * */
template<>
char* Add(char* pszLeft, char* pszRight)
{
    int nLenLeft = strlen(pszLeft);
    int nLenRight = strlen(pszRight);
    char* pszResult = new char[nLenLeft + nLenRight + 1];

    strcpy(pszResult, pszLeft);
    strcpy(pszResult + nLenLeft, pszRight);

    return pszResult;
}

int main()
{
    int nResult = Add<int>(3, 4);
    cout << nResult << endl;

    char* pszResult = Add<char*>("Hello", "World");
    cout << pszResult << endl;
    delete[] pszResult;
}
