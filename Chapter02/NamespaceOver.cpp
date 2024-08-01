//
// Created by Changjoon Lee on 11/19/23.
//
#include <iostream>

using namespace std;

inline void TestFunc(void) {
    cout << "::TestFunc()" << endl;
}

namespace TEST {
    void TestFunc(void) {
        cout << "TEST::TestFunc()" << endl;
    }
}

namespace MYDATA {
    void TestFunc(void) {
        cout << "DATA::TestFunc()" << endl;
    }
}

int main() {
    TestFunc();
    ::TestFunc();
    TEST::TestFunc();
    MYDATA::TestFunc();

    return 0;
}
