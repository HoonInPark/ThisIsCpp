//
// Created by Changjoon Lee on 2024. 10. 7..
//
#include "bits/stdc++.h"

using namespace std;

class CMyData
{
public:
    explicit CMyData(int nParam)
    {
        cout << "CMyData(int)" << endl;
        m_pnData = new int(nParam);
    }

    CMyData(const CMyData& rhs)
    {
        cout << "CMyData(const CMyData&)" << endl;
        m_pnData = new int(*rhs.m_pnData);
    }

    CMyData(const CMyData&& rhs) // 이동생성자에선 멤버 포인터는 깊은 복사를 해야 댕글링 문제가 안생김.
    {
        cout << "CMyData(const CMyData&&)" << endl;
        m_pnData = new int(*rhs.m_pnData);
    }

    ~CMyData() { delete m_pnData; }

    operator int() { return *m_pnData; }

    CMyData operator+(const CMyData& rhs)
    {
        return std::move(CMyData(*m_pnData + *rhs.m_pnData));
    }

    CMyData& operator=(const CMyData& rhs)
    {
        cout << "operator=" << endl;
        if (this == &rhs)
            return *this;

        delete m_pnData;
        m_pnData = new int(*rhs.m_pnData);

        return *this;
    }

    CMyData& operator=(CMyData&& rhs)
    {
        cout << "operator=(Move)" << endl;

        delete m_pnData;

        /*
         * 얕은 복사를 수행하여 우측값 rhs의 멤버엔 nullptr 대입.
         * 그렇게 하면 rhs가 해제되는 과정을 거쳐도 새로 업데이트된 m_pnData는 해제되지 않음.
         * */
        m_pnData = rhs.m_pnData;
        rhs.m_pnData = nullptr;

        return *this;
    }

private:
    int* m_pnData{nullptr};
};

int main()
{
    CMyData a(0), b(3), c(4);

    cout << "******** Before ********" << endl;
    a = b + c;
    cout << "********* After ********" << endl;
    cout << a << endl;
    a = b;
    cout << a << endl;
}
