//
// Created by Changjoon Lee on 12/30/23.
//

#include <iostream>
using namespace std;

int nData = 100;

namespace TEST{
    int nData = 200;
}

using namespace TEST;
int main(){
    cout << TEST::nData << endl;

    return 0;
}