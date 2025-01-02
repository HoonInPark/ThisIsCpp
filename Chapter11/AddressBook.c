//
// Created by Changjoon Lee on 2024. 12. 27..
//

// 충격적인 사실 : C언어의 구조체는 public, private이 없고, 내부에 함수를 정의할 수도 없다.

#include "UserInterface.h"

/*
 * 1. 노드를 만들어야. v
 * 2. 만들어진 노드가 들어갈 리스트가 있어야. v
 * 3. 노드 정보를, 노드가 그대로 있는 채로 쓸 수 있어야 x
 * 4. 노드 정보를 출력하는 함수 필요 v
 * 5. 노드를 검색하는 함수 v
 * 6. 노드를 삭제하는 함수 v
 * 7. 노드를 추가하는 함수 v
 * 8. 이 함수들을 어떻게 관리하지?
 * */
int main()
{
    return InitAddressBook();
}
