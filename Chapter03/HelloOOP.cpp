//
// Created by Changjoon Lee on 12/30/23.
//
#include <cstdio>

class USERDATA {
public:
    int nAge;
    char szName[32];

    // 본 멤버함수가 속한 클래스의 멤버변수를 끌어다가 쓰고 있다.
    void Print(void) {
        printf("%d, %s\n", nAge, szName);
    }
};

int main() {
    USERDATA user = {10, "철수"}; // 사용자가 객체의 초기화를 직접 해넣도록 했다는 문제가 있다. 그럼 어떻게? get/set을 통해!
    user.Print();

    return 0;
}