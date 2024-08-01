//
// Created by Changjoon Lee on 11/5/23.
//

#include <iostream>

int main() {
    int a = 10;
    int b(a); // "b는 변수인 a를 복사해서 만든다"는 의미로, 나중에 복사생성자의 개념과 연결.
    auto c(b);

    std::cout << a + b + c << std::endl;

    return 0;
}