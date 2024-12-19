//
// Created by Changjoon Lee on 2024. 12. 2..
//
#include "bits/stdc++.h"

using namespace std;

template<typename T>
class CMyData
{
public:
    CMyData(T param) : m_Data(param) {}
    T GetData() { return m_Data; }
    void SetData(T param) { m_Data = param; }

private:
    T m_Data;
};

template<>
class CMyData<char*>
{
public:
    CMyData(char* pszParam)
    {
        int nLen = strlen(pszParam);
        m_Data = new char[nLen + 1];
        strcpy(m_Data, pszParam);
    }
    ~CMyData() { delete[] m_Data; }
    char* GetData() const { return m_Data; }

private:
    char* m_Data;
};

int main()
{
    CMyData<char*> a("Hello");
    cout << a.GetData() << endl;
}
