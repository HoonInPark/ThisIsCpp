//
// Created by Changjoon Lee on 1/5/24.
//

#include <iostream>
using namespace std;

class CTest{
public:
    // 생성자는 퍼블릭 선언하지 않으면 해당 클래스의 객체화 시 컴파일 에러가 생긴다.
    CTest(){
        m_nData = 10;
    }

    int m_nData;

    void PrintData(void);
};

void CTest::PrintData(void){
    cout << m_nData << endl;
}


int main(){
    cout << "main() 함수 시작" << endl;

    CTest t;
    t.PrintData();

    cout << "main() 함수 끝" << endl;
    return 0;
}