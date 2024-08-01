//
// Created by Changjoon Lee on 7/20/24.
//

#include "bits/stdc++.h"

#define HOW_TO_MAKE_SETDATA_VALID 0
#define HOW_TO_PREVENT_FROM_UNINTENDED_COPY 0

class CTestData
{
public:
    CTestData(int nParam) : m_nData(nParam) { cout << "CTestData(int)" << endl; }

#if HOW_TO_PREVENT_FROM_UNINTENDED_COPY
    CTestData(const CTestData& rhs) = delete;
#else
    CTestData(const CTestData& rhs) : m_nData(rhs.m_nData) { cout << "CTestData(const CTestData&)" << endl; }
#endif
    int GetData() const { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData{0};
};

void TestFunc(
#if HOW_TO_MAKE_SETDATA_VALID
        CTestData& param
#else
        /*
         * 아래와 같이 인수를 설정하면 인수로 호출 당시의 변수 값이 복사돼서 들어간다.
         * 인수는 자동으로 스택 메모리에 할당되고 스코프가 끝나면 해제된다.
         * 복사한거에 아무리 Set해도 원본에는 영향을 미치지 않음.
         */
        CTestData param
#endif
        )
{
    cout << "TestFunc()" << endl;
    param.SetData(20);
}

int main()
{
    cout << "************ Begin ************" << endl;
    CTestData a(10);
    TestFunc(a);

    cout << "a : " << a.GetData() << endl;
    cout << "************* End *************" << endl;
}
