//
// Created by Changjoon Lee on 11/6/23.
//

#include <iostream>
using namespace std;

int Add(int a, int b, int c) {
    std::cout << "Add(int, int, int): ";

    return a + b + c;
}

int Add(int a, int b) {
    std::cout << "Add(int, int): ";
    return a + b;
}

double Add(double a, double b) {
    std::cout << "Add(double, double): ";
    return a + b;
}

/*
int _cdecl Add(int a, int b);
int _stdcall Add(int a, int b);
위와 같이 호출 규칙만 다르면 함수 오버로딩이 안된다.
*/

int main() {
    std::cout << Add(3, 4) << std::endl;
    std::cout << Add(3, 4, 5) << std::endl;
    std::cout << Add(3.3, 4.4) << std::endl;

    return 0;
}