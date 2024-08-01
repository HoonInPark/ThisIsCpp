#include <bits/stdc++.h>
#include "MyString.h"

void TestFunc(const CMyString& param)
{
    cout << param.GetString() << endl;
}

int main()
{
    CMyString strData("Hello");

    CMyString strData_1 = CMyString(strData);
//    ::TestFunc("strData"); // 변환생성자를 통한 최적화 필요.

    strData_1.SetString("fuck");

    ::TestFunc(strData);
    ::TestFunc(CMyString("World"));

    auto cast_test = static_cast<const char*>(strData);
    cout << cast_test << endl;
}
