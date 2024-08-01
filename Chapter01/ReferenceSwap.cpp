//
// Created by Changjoon Lee on 11/5/23.
//


#include <iostream>
using namespace std;

void Swap(int& a, int& b){
    int nTmp = a; // a의 주소를 넣는 게 아니라 a의 값을 넣는 것이기에 nTmp를 변경해도 a에는 영향이 없다.
    a = b; // 여기도 마찬가지.
    b = nTmp;
}

int main() {
    int x = 10, y = 20;

    Swap(x, y);

    cout << "x: " << x << endl;
    cout << "y: " << y << endl;

    return 0;
}