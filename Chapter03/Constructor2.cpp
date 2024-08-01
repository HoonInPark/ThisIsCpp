//
// Created by Changjoon Lee on 1/5/24.
//
#include <iostream>

using namespace std;

class CTest {
    int m_nData;

public:
    CTest(int nParam) : m_nData(nParam) {
        cout << "CTest::CTest()" << endl;
    }
    ~CTest(){
        cout << "CTest::~CTest() " << m_nData << endl;
    }
};

int main() {
    cout << "Begin" << endl;
    CTest a(1);
//    CTest a; // 디폴트 생성자는 만들지 않았으므로 이렇게 만들면 에러가 발생한다.
    cout << "Befor b" << endl;
    CTest b(2);
    cout << "End" << endl;

    return 0;
}