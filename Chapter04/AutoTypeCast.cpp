//
// Created by Changjoon Lee on 7/24/24.
//
#include "bits/stdc++.h"

#define ADDING_EXPLICIT_TO_TYPE_CAST 1

class CTestData
{
public:
    explicit CTestData(int nParam) : m_nData(nParam) {}

#if ADDING_EXPLICIT_TO_TYPE_CAST
    // 묵시적 형변환을 막는 explicit
    explicit operator int(void) { return m_nData; }
#else
    operator int(void) { return m_nData; }
#endif
    int GetData() const { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData{0};
};

int main()
{
    CTestData a(10);

    cout << a.GetData() << endl;

#if !ADDING_EXPLICIT_TO_TYPE_CAST
    cout << a << endl; // error: invalid operands to binary expression ('ostream' (aka 'basic_ostream<char>') and 'CTestData')
#endif

    // c언어 스타일의 형변환. 강제로 형변환 시킨다. 그래서 비추.
    cout << int(a) << endl;

    // c++ 스타일 형변환. 해당 객체가 형변환 연산을 제공하지 않으면 성립되지 않는 연산자이기 때문이다.
    cout << static_cast<int>(a) << endl;
}
