//
// Created by Changjoon Lee on 2024. 12. 28..
//
#include "bits/stdc++.h"
using namespace std;

class CTest
{
public:
    CTest(int nSize)
    {
        m_pszData = new char[nSize];
    }

    ~CTest()
    {
        delete[] m_pszData;
        cout << "successfully deleted" << endl;
    }

private:
    char* m_pszData;
};

int main()
{
    try
    {
        int nSize;
        cout << "Input Size : ";
        cin >> nSize;
        CTest a(nSize);
    }
    catch (bad_alloc& exp)
    {
        cout << exp.what() << endl;
        cout << "ERROR : CTest()" << endl;
    }
}
