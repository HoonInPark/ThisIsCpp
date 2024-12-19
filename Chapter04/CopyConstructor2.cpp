//
// Created by Changjoon Lee on 7/21/24.
//
#include "bits/stdc++.h"
using namespace std;

class CMyData
{
public:
    CMyData() { cout << "CMyData()" << endl; }

    int GetData(void) const { return m_pnData; }
    void SetData(int nParam) { m_pnData = nParam; }

private:
    int m_pnData{0};
};

int main()
{
    CMyData a;

    a.SetData(10);
    CMyData b(a);
    cout << b.GetData() << endl;
}
