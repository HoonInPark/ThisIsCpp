//
// Created by Changjoon Lee on 2024. 10. 12..
//
#include "bits/stdc++.h"
using namespace std;

class CIntArray
{
public:
    CIntArray(int nSize)
    {
        m_pnData = new int[nSize];
        // 배열의 각 메모리 주소를 0이라는 값으로 초기화
        memset(m_pnData, 0, sizeof(int) * nSize);
    }

    ~CIntArray() { delete m_pnData; }

    int operator[](int nIndex) const // lval
    {
        cout << "operator[] const" << endl;
        return m_pnData[nIndex];
    }
    int& operator[](int nIndex) // rval
    {
        cout << "operator[]" << endl;
        return m_pnData[nIndex];
    }

private:
    int *m_pnData;
    int m_nSize;
};

void TestFunc(const CIntArray& arParam)
{
    cout << "TestFunc()" << endl;
    cout << arParam[3] << endl;
}

int main()
{
    CIntArray arr(5);
    for (int i = 0; i < 5; ++i)
        arr[i] = i * 10;

    TestFunc(arr);
}
