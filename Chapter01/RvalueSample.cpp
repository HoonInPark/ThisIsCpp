//
// Created by Changjoon Lee on 11/6/23.
//

#include <iostream>
using namespace std;

int TestFunc(int nParam)
{
    int nResult = nParam * 2;

    return nResult;
}

int main() {
    int nInput = 0;
    cout << "Input number: ";
    cin >> nInput;

    int&& rdata = nInput + 5;
    cout << rdata << endl;
    // 위 rvalue 변수를 출력하는 행위는 다음 코드와 정확히 동일한 행위이다.
    cout << nInput + 5 << endl;

    int&& result = TestFunc(10);

    result += 10;
    cout << result << endl;

    return 0;
}
