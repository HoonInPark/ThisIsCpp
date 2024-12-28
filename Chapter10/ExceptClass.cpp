//
// Created by Changjoon Lee on 2024. 12. 27..
//
#include "bits/stdc++.h"
using namespace std;

class CMyException
{
public:
    CMyException(int nCode, const char* szMsg)
    {
        m_nErrorCode = nCode;
        strcpy(m_szMsg, szMsg);
    }

    [[nodiscard]] int GetErrorCode() const { return m_nErrorCode; }
    [[nodiscard]] const char* GetMessage() const { return m_szMsg; }

private:
    int m_nErrorCode;
    char m_szMsg[128];
};

int main()
{
    try
    {
        int nInput = 0;
        cout << "양의 정수를 입력하세요 : ";
        cin >> nInput;

        if (nInput < 0)
        {
            CMyException exp(10, "양의 정수를 입력해야 합니다.");
            throw exp;
        }
    }
    catch (CMyException& exp)
    {
        cout << "ERROR CODE [" << exp.GetErrorCode() << "]"
        << exp.GetMessage() << endl;
    }
}
