#include <bits/stdc++.h>
#include "MyString.h"

//void TestFunc(const CMyString& param)
//{
//    cout << param.GetString() << endl;
//}

CMyString TestFunc()
{
    CMyString strTest("TestFunc() return");
    std::cout << strTest << std::endl;

    return strTest;
}

int main()
{
    TestFunc();
}
