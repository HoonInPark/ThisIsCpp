//
// Created by Changjoon Lee on 11/5/23.
//

#include <string>
#include <cstdio>
#include <iostream>

int main() {
    int nAge;
    std::cout << "나이를 입력하세요." << std::endl;
    std::cin >> nAge;

    char szJob[32];
    std::cout << "직업을 입력하세요." << std::endl;
    std::cin >> szJob;

    std::string strName; // char와 달리 길이를 생각할 필요가 없다.
    std::cout << "이름을 입력하세요" << std::endl;
    std::cin >> strName;

    std::cout << "당신의 이름은 " << strName << "이고, " << "나이는 " << nAge << "살이며, " << "직업은 " << szJob << "입니다." << std::endl;

    return 0;
}