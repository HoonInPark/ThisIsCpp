//
// Created by Changjoon Lee on 11/5/23.
//

#include <string>
#include <iostream>

int main() {
    std::string strData = "Test string";
    std::cout << "Sample string" << std::endl;
    std::cout << strData << std::endl;

    strData = "New string";
    std::cout << strData << std::endl;

    std::cout << "저는" << 20 << "살" << "입니다." << std::endl;

    return 0;
}

// "저는 %d살 입니다."라고 적어야 하는 C언어와 달리 C++은 하나하나 조립하듯 문자열을 구성할 수 있다.