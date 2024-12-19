//
// Created by Changjoon Lee on 7/23/24.
//
#include "bits/stdc++.h"
using namespace std;

#define ADDING_DISTRUCTOR 0
#define MODIFY_TEST_FUNC_PARAM 0
#define PREVENT_IMPLICIT_CONV_CONSTRUCTOR 0

class CTestData
{
public:
#if PREVENT_IMPLICIT_CONV_CONSTRUCTOR
    explicit CTestData(int nParam) : m_nData(nParam) { cout << "CTestData(int)" << endl; }
#else
    CTestData(int nParam) : m_nData(nParam) { cout << "CTestData(int)" << endl; }
#endif
    CTestData(const CTestData& rhs) : m_nData(rhs.m_nData) { cout << "CTestData(const CTestData&)" << endl; }

    int GetData() const { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

#if ADDING_DISTRUCTOR
    ~CTestData()
    {
        cout << "~CTestData()" << endl;
    }
#endif

private:
    int m_nData{0};
};

void TestFunc(
#if !MODIFY_TEST_FUNC_PARAM
        CTestData param
#else
        const CTestData& param
#endif
        )
{
    cout << "TestFunc() : " << param.GetData() << endl;
}

int main()
{
#if ADDING_DISTRUCTOR
    cout << "************ Begin ************" << endl;
#endif

    /*
     * 변환생성을 할 수 있는 조건들
     * 1. 함수에서 해당 클래스를 인수로 쓰고 있다.
     * 2. 변환생성자의 인수가 하나다.
     * 3. 멤버변수로 변환생성 시 넣는 인수 타입을 가지고 있다. ex) int
     *
     */
#if !PREVENT_IMPLICIT_CONV_CONSTRUCTOR
    TestFunc(5);
#endif

#if ADDING_DISTRUCTOR
    cout << "************* End *************" << endl;
#endif
}
