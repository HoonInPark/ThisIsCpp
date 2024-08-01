//
// Created by Changjoon Lee on 12/30/23.
//
#include <iostream>
using namespace std;

int main(){
    int nInput = 0;
    cout << "11 이상의 정수를 입력하세요"<< endl;
    cin >> nInput;

    if (nInput > 10){
        cout << nInput << endl;
    } else
        cout << "Error" << endl;

    return 0;
}