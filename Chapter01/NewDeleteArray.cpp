//
// Created by Changjoon Lee on 11/5/23.
//

#include <iostream>
using namespace std;

int main() {
    // new 연산자는 객체의 생성자를 호출
    int *arr = new int[5]; // "[]"로 쓰면 인덱스이고, "()"로 쓰면 할당된 변수에 들어갈 값이다.
    for (int i = 0; i < 5; ++i)
        arr[i] = (i + 1) * 10;

    for (int i = 0; i < 5; ++i)
        cout << arr[i] << endl;

    // delete 연산자는 객체의 소멸자를 호출
    delete[] arr;

    return 0;
}