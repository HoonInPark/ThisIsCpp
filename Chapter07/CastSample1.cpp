//
// Created by Changjoon Lee on 2024. 11. 4..
//
#include "bits/stdc++.h"

using namespace std;

class CMyData
{
public:
    CMyData() {}

    virtual ~CMyData() {}

    void SetData(int nParam) { m_nData = nParam; }
    int GetData() { return m_nData; }

private:
    int m_nData{0};
};

class CMyDataEx : public CMyData
{
public:
    void SetData(int nParam)
    {
        if (nParam > 10)
            nParam = 10;

        CMyData::SetData(nParam);
    }

    void PrintData()
    {
        cout << "PrintData : " << GetData() << endl;
    }
};

int main()
{
    CMyData* pData = new CMyDataEx;
    CMyDataEx* pNewData = nullptr;

    pData->SetData(15);
    pNewData = static_cast<CMyDataEx*>(pData);
    pNewData->PrintData();

    delete pData;
}
