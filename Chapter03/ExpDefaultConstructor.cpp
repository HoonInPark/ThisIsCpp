//
// Created by Changjoon Lee on 1/11/24.
//
#include <iostream>

using namespace std;

class CTest
{
public:
//    CTest(void);
//    CTest(void) = default; // default는 키워드이다!
//    CTest(void) = delete;

    int m_nData = 5;
};

//CTest::CTest(void) {}

int main()
{
    CTest a;
    cout << a.m_nData << endl;

    return 0;
}
