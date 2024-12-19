//
// Created by Changjoon Lee on 2024. 11. 30..
//
#include "bits/stdc++.h"
using namespace std;

template<typename T = int, int nSize = 3>
class CMyArray
{
public:
    explicit CMyArray() { m_pData = new T[nSize]; }
    ~CMyArray() { delete[] m_pData; }
    int GetSize() { return nSize; }

    T& operator[](int nIndex)
    {
        if (nIndex < 0 || nIndex >= nSize)
        {
            cout << "ERROR : index out of range" << endl;
            exit(1);
        }

        return m_pData[nIndex];
    }
    T& operator[](int nIndex) const { return m_pData[nIndex]; }

private:
    T* m_pData{nullptr};
};

int main()
{
    CMyArray<int, 3> arr;
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    for (int i = 0; i < 3; ++i)
    {
        cout << arr[i] << endl;
    }
}
