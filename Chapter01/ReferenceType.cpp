//
// Created by Changjoon Lee on 11/5/23.
//

#include <iostream>
using namespace std;

int main() {
    // 선언과 동시에 반드시 초기화돼야하고 상수에 대한 참조 안되고 참조 원본 없는 선언은 안된다.
    int nData = 10;

    // nData 변수에 대한 참조자 선언
    int& ref = nData;

    // 참조자의 값은 변경하면 원본도 변한다.
    ref = 20;
    cout << nData << endl;

    // 포인터를 쓰는 것과 비슷하다.
    int* pnData = &nData; // nData의 주소를 pnData 포인터에 대입
    *pnData = 30;
    cout << nData << endl;

    return 0;
}