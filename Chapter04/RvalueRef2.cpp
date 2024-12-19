//
// Created by Changjoon Lee on 7/30/24.
//
#include "bits/stdc++.h"
using namespace std;

#define USING_R_VAL_REF 1 // if 0, it makes error cause TestFunc doesn't support rval ref

void TestFunc(int& rParam) // 변수가 아닌 대상에 참조를 걸 수 없는 경우.
{
    cout << "TestFunc(int&)" << endl;
}

#if USING_R_VAL_REF
void TestFunc(int&& rParam) // 변수가 아닌 대상에 참조를 걸 수 있는 경우.
{
    cout << "TestFunc(int&&)" << endl;
}
#endif

int main()
{
    /*
     * 아래 같이 호출하면 TestFunc(int) 함수를 호출할 수도 있다.
     * 이럴 경우 rvalue는 인수(lvalue)에 값을 복사하고 소멸된다.
     * 함수 스코프 내에선 이 lvalue가 쓰이는 것.
     * 근데 이럴 경우 함수가 실행되는 동안 두개의 동일한 역할을 하는 객체가 생성/파괴된다.
     * 이런 비효율을 막고자 TestFunc(int&&)가 있는 것임.
     */
    TestFunc(3 + 4);
}
