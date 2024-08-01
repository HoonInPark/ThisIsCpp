//
// Created by Changjoon Lee on 7/15/24.
//
#include "bits/stdc++.h"

class CMyData
{
public:
    CMyData() : m_nData(0) {};

    int GetData(void) { return m_nData; }

    void SetData(int nParam) { m_nData = nParam; }
    void SetData(double nParam) { m_nData = 0; }

private:
    int m_nData;
};

int main()
{
    CMyData a;
    a.SetData(10);
    cout << a.GetData() << endl;

    CMyData b;
    b.SetData(5.5);
    cout << b.GetData() << endl;
}