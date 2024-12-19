//
// Created by Changjoon Lee on 2024. 11. 29..
//
#include "bits/stdc++.h"
using namespace std;

template<typename T>
class CTest
{
public:
    CTest();
    T TestFunc();

protected:
    static T m_Data;
};

template<typename T>
CTest<T>::CTest()
{

}

template<typename T>
T CTest<T>::TestFunc()
{
    return m_Data;
}

template<typename T>
T CTest<T>::m_Data = 15;

int main()
{
    CTest<double> a;
    cout << a.TestFunc() << endl;
}
