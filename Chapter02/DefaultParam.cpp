#include <iostream>

int TestFunc(int = 10); // 디폴트 값을 선언할 거면 반드시 정의 부분에 디폴트 값을 선언해야 한다.

int TestFunc(int nParam) {
    return nParam;
}

int main() {
    std::cout << TestFunc() << std::endl;
    std::cout << TestFunc(20) << std::endl;
    // 호출자의 코드만 보고는 함수 원형을 알기 어렵다

    return 0;
}
