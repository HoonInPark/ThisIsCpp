//
// Created by Changjoon Lee on 1/8/24.
//

#include <iostream>

using namespace std;

class CTest {
    int m_nData;

public:
    CTest() {
        cout << "CTest::CTest()" << endl;
    }

    ~CTest() {
        cout << "CTest::~CTest()" << endl;
    }

};

int main() {
    cout << "Begin" << endl;

    CTest* pData = new CTest[3];
    cout << "Test" << endl;

    delete[] pData;
    cout << "End" << endl;

    return 0;
}