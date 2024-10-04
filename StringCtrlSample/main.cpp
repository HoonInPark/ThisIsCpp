#include "MyString.h"
#include <bits/stdc++.h>
using namespace std;

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
    CMyString strLeft("Hello"), strRight("World"), strResult;
    strResult = strLeft + strRight;
    cout << strResult << endl;

    cout << strLeft << endl;
    strLeft += CMyString("World");
    cout << strLeft << endl;
}
