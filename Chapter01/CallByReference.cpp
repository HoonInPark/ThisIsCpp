//
// Created by Changjoon Lee on 11/5/23.
//

#include <iostream>
using namespace std;

void TestFunc(int& rParam){
    rParam = 100; // 호출하는 쪽에서 rParam에 대입한 변수의 원래 주소로 가서 값을 변경.
}

int main() {
//    TestFunc(100); // 상수는 들어갈 수 없음

    int nData = 0;
    TestFunc(nData);
    cout << nData << endl;

    return 0;
}