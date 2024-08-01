//
// Created by Changjoon Lee on 11/6/23.
//

#include <iostream>

int TestFunc(int nParam1, int nParam2 = 2) {
    return nParam1 * nParam2;
}

int main() {
    // 디폴트 인수를 사용하면 함수 정의를 유지보수할 일이 있을 때, 함수 호출 코드까지 유지보수할 일이 없디.
    std::cout << TestFunc(10) << std::endl; // 왼쪽부터 짝을 맞춘다. 디폴트 값은 오른쪽 매개변수부터 선언해야 한다.
    std::cout << TestFunc(10, 5) << std::endl;

    return 0;
}