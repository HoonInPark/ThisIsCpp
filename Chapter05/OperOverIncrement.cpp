//
// Created by Changjoon Lee on 2024. 10. 19..
//
#include "bits/stdc++.h"

using namespace std;

class CMyData
{
public:
    CMyData(int nParam) : m_nData(nParam) {}
    operator int() { return m_nData; }

    int operator++()
    {
        cout << "operator++()" << endl;
        return ++m_nData;
    }
    int operator++(int)
    {
        cout << "operator++(int)" << endl;
        int nData = m_nData;
        m_nData++;

        return nData;
    }

private:
    int m_nData{0};

};

int main()
{
    CMyData a(10);

    cout << ++a << endl;
    cout << a++ << endl;
    cout << a << endl;
}
