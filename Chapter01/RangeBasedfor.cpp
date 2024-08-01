//
// Created by Changjoon Lee on 11/6/23.
//

#include <iostream>
using namespace std;

int main() {
    int aList[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; ++i) {
        cout << aList[i] << ' ';
    }

    cout << endl;

    for (auto n : aList) {
        n = 10;
        /*
         * 이렇게 대입하면 다음과 같은 결과가 나온다.
         * 10 20 30 40 50
         * 10 10 10 10 10
         * 10 20 30 40 50
         *
         * 즉, aList 자체는 변하지 않는 것임.
         * 원본을 변하게 하고 싶으면 auto& n으로 선언해야.
         */
        cout << n << ' ';
    }

    cout << endl;

    for (auto& n : aList) {
        cout << n << ' ';
    }

    cout << endl;

    return 0;
}