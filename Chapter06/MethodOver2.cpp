//
// Created by Changjoon Lee on 2024. 10. 21..
//

#include "bits/stdc++.h"
using namespace std;

class CMyData
{
public:
    CMyData() { cout << "CMyData()" << endl; }

    int GetData() { return m_nData; }

    void SetData(int nParam) { m_nData = nParam; }

protected:
    void PrintData() { cout << "CMyData::PrintData()" << endl; }

private:
    int m_nData{0};
};

class CMyDataEx : public CMyData
{
public:
    void SetData(int nParam)
    {
        if (nParam < 0)
            CMyData::SetData(0);

        if (nParam > 10)
            CMyData::SetData(10);
    }
};

int main()
{
    CMyDataEx a;
    CMyData& rData = a;
    rData.SetData(15);
    cout << rData.GetData() << endl;

    // 할당은 CMyDataEx로 하지만 컴파일러는 이를 CMyData로 읽는다.
    CMyData* pData = new CMyDataEx;
    pData->SetData(5);
    delete pData;


}
