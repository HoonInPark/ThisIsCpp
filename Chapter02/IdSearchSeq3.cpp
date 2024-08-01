//
// Created by Changjoon Lee on 12/30/23.
//
#include <iostream>
using namespace std;

int nData = 200;

namespace TEST{
//    int nData = 100;
    void TestFunc(void){
        cout << nData << endl;
    }
    int nData = 100;
}

int main(){
    TEST::TestFunc();

    return 0;
}