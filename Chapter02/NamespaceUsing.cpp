//
// Created by Changjoon Lee on 11/19/23.
//

#include <iostream>

using namespace std;

namespace TEST {
    int g_nData = 10;

    void TestFunc(void) {
        cout << "TEST::TestFunc()" << endl;
    }
}

using namespace TEST;
int main() {
    TestFunc();
    cout << g_nData << endl;
    return 0;
}