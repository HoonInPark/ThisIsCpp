//
// Created by Changjoon Lee on 11/19/23.
//

#include <iostream>

namespace TEST {
    int g_nData = 100;
    void TestFunc(void) {
        std::cout << "TEST::TestFunc()" << std::endl;
    }
}

int main() {
    TEST::TestFunc();
    std::cout << TEST::g_nData << std::endl;

    return 0;
}