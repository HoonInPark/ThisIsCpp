//
// Created by Changjoon Lee on 11/17/23.
//

#include <iostream>

template <typename T>
T Add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << Add(3, 4) << std::endl;
    std::cout << Add(3.3, 4.4) << std::endl;
    return 0;
}