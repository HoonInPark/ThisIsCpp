//
// Created by Changjoon Lee on 7/31/24.
//
#include "bits/stdc++.h"
using namespace std;

#define FORCE_TO_CALL_MOVE_CONSTRUCTOR 1
#define IDENTIFY_INST_BY_CHAR_DATA 0

class CTestData
{
public:
    CTestData() { cout << "CTestData()" << endl; }
    ~CTestData() { cout << "~CTestData()" << endl; }

#if IDENTIFY_INST_BY_CHAR_DATA
    CTestData(const char* sParam)
    {
        // 멤버 포인터는 안에 할당을 하고 값을 넣어야 한다.
        m_sName_of_inst = new char();
        strcpy(this->m_sName_of_inst, sParam);
        cout << "CTestData(const char*) : " << sParam << endl;
    }
#endif

    CTestData(const CTestData& rhs)
            : m_nData(rhs.m_nData)
    {
        cout << "CTestData(const CTestData&)" << endl;
    }

    // 이동 생성자
    CTestData(const CTestData&& rhs)
            : m_nData(rhs.m_nData)
    {
        cout << "CTestData(const CTestData&&)" << endl;
    }

    CTestData& operator=(const CTestData& rhs)
    {
        if (this != &rhs) { this->m_nData = rhs.m_nData; }

        return *this;
    }

    [[nodiscard]] int GetData() const { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData{0};
#if IDENTIFY_INST_BY_CHAR_DATA
    char* m_sName_of_inst;
#endif
};

CTestData TestFunc(int nParam)
{
    cout << "** TestFunc() : Begin ****" << endl;

#if !IDENTIFY_INST_BY_CHAR_DATA
    CTestData a;
#else
    CTestData a("a");
#endif
    a.SetData(nParam);

    cout << "** TestFunc(int) : End ****" << endl;

#if FORCE_TO_CALL_MOVE_CONSTRUCTOR // 다음과 같이 std::move를 해주지 않으면 이동 생성자 없이 리턴된 자원을 그대로
    return std::move(a);
#else
    return a;
#endif
}

int main()
{
#if !IDENTIFY_INST_BY_CHAR_DATA
    CTestData b;
#else
    CTestData b("b");
#endif
    cout << "* Before ******************" << endl;
    b = TestFunc(20);
    cout << "* After  ******************" << endl;
    CTestData c(b);
}
