//
// Created by Changjoon Lee on 1/5/24.
//

#include <iostream>
using namespace std;

class CTest{
public:
    CTest(){
        cout << "CTest::CTest()" << endl;
    }
    ~CTest(){
        cout << "CTest::~CTest()" << endl;
    }
};

// main() 함수 내에서 선언되지 않은 전역변수이므로 main() 실행 전에 객체화되고 main() 실행이 끝날 때 소멸.
//CTest a;

int main(){
    cout << "Begin" << endl;
    // 객체화된 클래스는 이 main()함수 블록의 지역변수이므로 main()함수가 끝날 때 소멸.
    CTest a;
    cout << "Befor b" << endl;
    CTest b;
    cout << "End" << endl;
    return 0;
}