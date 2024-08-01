//
// Created by Changjoon Lee on 2/4/24.
//
#define TEST_0 0
#define TEST_1 0

#include <iostream>

using namespace std;

class CMyData
{
public:
    CMyData(int nParam) : m_nData(nParam) {};


#if TEST_1

    void PrintData()
    {
        cout << m_nData << endl;
        cout << CMyData::m_nData << endl;
        cout << this->m_nData << endl;
        cout << this->CMyData::m_nData << endl;
    }

#else

    void PrintData(CMyData* pData)
    {
//        CMyData* this = pData; // 컴파일러가 우리의 코드를 인식할 때 이렇게 보인다.

        cout << m_nData << endl;
        cout << CMyData::m_nData << endl;
        cout << this->m_nData << endl;
        cout << this->CMyData::m_nData << endl;
    }

#endif

private:
    int m_nData;
};

#if TEST_0

class CMyDataEx : CMyData
{
public:
    CMyDataEx(int nParam) : CMyData(nParam) { cout << "CMyDataEx" << endl; }
    void TestFunc()
    {
        PrintData();
    }
};

#endif


int main()
{
#if TEST_1

    CMyData a(5), b(10);

    a.PrintData();
    b.PrintData();

#else

    CMyData a(5);
    a.PrintData(&a);

#endif

//    CMyData a(5);
//
//    a.PrintData(&a);

    return 0;
}
