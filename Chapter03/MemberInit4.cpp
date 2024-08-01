//
// Created by Changjoon Lee on 1/5/24.
//

#include <iostream>
using namespace std;

class CTest{
public:
    // 생성자는 퍼블릭 선언하지 않으면 해당 클래스의 객체화 시 컴파일 에러가 생긴다.
    CTest()
    : m_nData1(10), m_nData2(20)
    {}

    int m_nData1;
    int m_nData2;
    void PrintData(void){
        cout << m_nData1 << endl;
        cout << m_nData2 << endl;
    }
};

int main(){
    cout << "main() 함수 시작" << endl;

    CTest t;
    t.PrintData();

    cout << "main() 함수 끝" << endl;
    return 0;
}