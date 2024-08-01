//
// Created by Changjoon Lee on 11/5/23.
//

#include <iostream>

int main() {
    // malloc()과 free()는 함수인데 반해, new와 delete는 연산자인 점에서 편의성이 있다.
    // 단일 인스턴스이고 초기값 없이 메모리 할당만 하는 경우
    int* pData = new int;

    // 초기값을 기술하는 경우
    int* pNewData = new int(10);

    *pData = 5;
    std::cout << *pData << std::endl;
    std::cout << *pNewData << std::endl;

    delete pData;
    delete pNewData;

    return 0;
}