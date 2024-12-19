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
//    CMyData* pData = new CMyData;
    CMyData* pData = new CMyDataEx;
    CMyDataEx* pNewData = nullptr;

    pData->SetData(15);
    /*
     * 아래와 같이 static_cast를 쓰면 메모리 상의 저장된 값은 그대로 있고
     * 포인터의 타입만 바뀐다.
     * */
    pNewData = static_cast<CMyDataEx*>(pData);
    pNewData->PrintData();

    delete pData;
}
