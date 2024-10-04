#include "bits/stdc++.h"
using namespace std;

#define TEAR_DOWN_OPER 1

class CMyData
{
public:
    CMyData(int nParam)
            : m_nData(nParam)
    {
        cout << "CMyData(int)" << endl;
    }

    CMyData(const CMyData& _rhs)
            : m_nData(_rhs.m_nData)
    {
        cout << "CMyData(const CMyData &)" << endl;
    }

    CMyData(const CMyData&& _rhs) noexcept
            : m_nData(_rhs.m_nData)
    {
        cout << "CMyData(const CMyData &&)" << endl;
    }

    operator int()
    {
        return m_nData;
    }

    CMyData operator+(const CMyData& _rhs)
    {
        cout << "operator+" << endl;
        CMyData result(0);
        result.m_nData = this->m_nData + _rhs.m_nData;

        return std::move(result);
    }

    CMyData& operator=(const CMyData& _rhs)
    {
        cout << "operator=" << endl;
        m_nData = _rhs.m_nData;

        return *this;
    }

private:
    int m_nData{0};
};

int main()
{
    cout << "*****Begin*****" << endl;
    CMyData a(0), b(3), c(4);

#if !TEAR_DOWN_OPER
    a = b + c;
#else
    a.operator=(b.operator+(c));
#endif

    cout << a << endl; // operator int() 호출됨.
    cout << "******End******" << endl;
}
