//
// Created by Changjoon Lee on 7/15/24.
//
#include "bits/stdc++.h"

class CTest
{
public:
    CTest(int nParam) : m_nData(nParam) { m_nCount++; }

    int GetData() { return m_nData; }
    void ResetCount() { m_nCount = 0; }

    static int GetCount()
    {
        //this; // error: invalid use of 'this' outside of a non-static member function
        return m_nCount;
    };

private:
    int m_nData;

    // declaring static var, not an defining
    static int m_nCount;
};

// defining static var
int CTest::m_nCount = 0;

int main()
{
    CTest a(5), b(10);

    cout << a.GetCount() << endl;
    b.ResetCount();

    cout << CTest::GetCount() << endl;
}
