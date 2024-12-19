#include "bits/stdc++.h"
using namespace std;

class CMyData
{
public:
    CMyData(int nParam) : m_nData(nParam) {}
    int GetData() const { return m_nData; }
    void SetData(int nParam) { m_nData = nParam; }

    // 접근 당하는 쪽에서 접근을 허용해주는 friend 예약어가 있어야 한다.
    friend void PrintData(const CMyData&);

private:
    int m_nData{0};
};

void PrintData(const CMyData& rData)
{
    cout << "PrintData() : " << rData.m_nData << endl;
}

int main()
{
    CMyData a(5);
    PrintData(a);
}
