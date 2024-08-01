//
// Created by Changjoon Lee on 7/29/24.
//
#define MAKE_TEMP_OBJ_PERM 1

#include "bits/stdc++.h"

class CTestData
{
public:
    CTestData(int nParam, char* pszName)
            : m_nData(nParam),
              m_pszName(pszName)
    {
        cout << "CTestData(int) : " << m_pszName << endl;
    }

    ~CTestData()
    {
        cout << "~CTestData() : " << m_pszName << endl;
    }

    CTestData(const CTestData& rhs)
            : m_nData(rhs.m_nData),
              m_pszName(rhs.m_pszName)
    {
        cout << "CTestData(const CTestData&) : " << m_pszName << endl;
    }

    CTestData& operator=(const CTestData& rhs)
    {
        cout << "operator=" << endl;
        m_nData = rhs.m_nData;

        return *this;
    }

    int GetData() const { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

private:
    int m_nData{0};
    char* m_pszName{nullptr};
};

CTestData TestFunc(int nParam)
{
    CTestData a(nParam, "a");

    return a;
}

int main()
{
#if !MAKE_TEMP_OBJ_PERM
    CTestData b(5, "b");
#endif
    cout << "********* Before *********" << endl;

#if MAKE_TEMP_OBJ_PERM
    /*
     * error: non-const lvalue reference to type 'CTestData' cannot bind to a temporary of type 'CTestData'
     * lval가 const가 아니면 이름없는 임시 객체(anonymous temporary object)를 참조하도록 할 수 없다는 뜻.
     */
//    CTestData& rData = TestFunc(10);
    const CTestData& rData = TestFunc(10);
#else
    b = TestFunc(10);
//    TestFunc(10);
#endif

    cout << "********* After **********" << endl;
//    cout << b.GetData() << endl;
}
