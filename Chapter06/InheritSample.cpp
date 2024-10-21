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

// 만약 public CMyData이라 해주지 않았으면 CMyData의 public 함수들은 자식 클래스에서 private으로 취급된다.
class CMyDataEx : public CMyData
{
public:
    // 호출은 부모 클래스의 생성자보다 먼저 되지만 실행은 부모 클래스의 생성자보다 나중에 된다.
    CMyDataEx() { cout << "CMyDataEx()" << endl; }

    void TestFunc()
    {
        PrintData();
        SetData(5);
        cout << CMyData::GetData() << endl;
    }
};

int main()
{
    CMyDataEx data;
    data.SetData(10);
    cout << data.GetData() << endl;
    data.TestFunc();
}
