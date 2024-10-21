#include "MyStringEx.h"
#include <bits/stdc++.h>
using namespace std;

//void TestFunc(const CMyString& param)
//{
//    cout << param.GetString() << endl;
//}

void TestFunc(const CMyString& strParam)
{
    cout << strParam[0] << endl;
    cout << strParam[strParam.GetLength() - 1] << endl;
}

int main()
{
    CMyStringEx strTest;
    strTest.SetString("I am a boy.");
    cout << strTest << endl;

    int nIndex = strTest.Find("am");
    cout << "Index : " << nIndex << endl;
}
