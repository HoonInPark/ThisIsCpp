//
// Created by Changjoon Lee on 2024. 12. 27..
//
#include <stdio.h>

// 충격적인 사실 : C언어의 구조체는 public, private이 없고, 내부에 함수를 정의할 수도 없다.
struct SNode
{
    char* m_sUserName;
    char* m_sUserPhoneNum;

    struct SNode* m_pNextNode;
};

struct SAddressBook
{

    struct SNode* m_HeadNode;
};

int main()
{

}
