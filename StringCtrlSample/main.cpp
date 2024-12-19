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
    CMyString b("World"), c;
    c = "Hello" + b;
    cout << c << endl;
}
