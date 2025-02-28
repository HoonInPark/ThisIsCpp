//
// Created by Changjoon Lee on 2024. 11. 26..
//
#include "bits/stdc++.h"
using namespace std;

template<typename T>
class CMyArray
{
public:
    explicit CMyArray(int nSize) : m_nSize(nSize)
    {
        m_pData = new T[nSize];
    }

    ~CMyArray() { delete[] m_pData; }

    CMyArray(const CMyArray& rhs)
    {
        m_pData = new T[rhs.m_nSize];
        memcpy(m_pData, rhs.m_pData, sizeof(T) * rhs.m_nSize);
        m_nSize = rhs.m_nSize;
    }

    CMyArray& operator=(const CMyArray& rhs)
    {
        if (this == &rhs)
            return *this;

        delete m_pData;
        // 깊은 복사 수행
        m_pData = new T[rhs.m_nSize];
        memcpy(m_pData, rhs.m_pData, sizeof(T) * rhs.m_nSize);
        m_nSize = rhs.m_nSize;

        return *this;
    }

    CMyArray(CMyArray&& rhs)
    {
        operator=(rhs);
    }

    // 이동대입 연산자
    CMyArray& operator=(const CMyArray&& rhs)
    {
        m_pData = rhs.m_pData;
        m_nSize = rhs.m_nSize;
        rhs.m_pData = nullptr;

        return *this;
    }

    T& operator[](int nIndex)
    {
        if (nIndex < 0 || nIndex >= m_nSize)
        {
            cout << "ERROR : out of valid range." << endl;
            exit(1);
        }

        return m_pData[nIndex];
    }

    T& operator[](int nIndex) const
    {
        return operator[](nIndex);
    }

    int GetSize() { return m_nSize; }

private:
    T* m_pData{nullptr};
    int m_nSize{0};
};

int main()
{
    CMyArray<int> arr(5);
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    for (int i = 0; i < 5; ++i)
        cout << arr[i] << ' ';

    cout << endl;

    CMyArray<int> arr2(3);
    arr2 = arr;
    for (int i = 0; i < 5; ++i)
        cout << arr2[i] << ' ';

    cout << endl;
}
