//
// Created by Changjoon Lee on 12/30/23.
//

#include <iostream>
using namespace std;

int nData = 100;

namespace TEST{
    int nData = 200;
}

int main(){
    cout << nData << endl;

    return 0;
}