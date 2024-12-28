//
// Created by Changjoon Lee on 2024. 12. 27..
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 충격적인 사실 : C언어의 구조체는 public, private이 없고, 내부에 함수를 정의할 수도 없다.

/*
 * 
 * */
struct SNode
{
    char* m_sUserName;
    char* m_sUserPhoneNum;

    struct SNode* m_pNextNode;
};

struct SAddressBook
{
    void (* m_fpAdd)(struct SNode*);


    struct SNode* m_HeadNode;
};

#pragma region func for managing data

struct SNode* CreateNode(const char* _sUserName, const char* _sUserPhoneNum)
{
    struct SNode* pRetNode = (struct SNode*) malloc(sizeof(struct SNode));
    if (pRetNode)
    {
        pRetNode->m_sUserName = (char*) malloc(
                sizeof(char) *
                (strlen(_sUserName) + 1));
        pRetNode->m_sUserPhoneNum = (char*) malloc(
                sizeof(char) *
                (strlen(_sUserPhoneNum) + 1));

        strcpy(pRetNode->m_sUserName, _sUserName);
        strcpy(pRetNode->m_sUserPhoneNum, _sUserPhoneNum);
    }

    return pRetNode;
}

void AddNode(struct SNode* _pInNode)
{

}

void ShowNodeInfo(struct SNode* _pNode)
{
    printf("%s \n", _pNode->m_sUserName);
    printf("%s \n", _pNode->m_sUserPhoneNum);
}

void DelNode()
{

}

struct SNode* FindNode(const char* _sInChar)
{
    return NULL;
}

#pragma endregion func for managing data

#pragma region func for user interface

void ShowUserInterface()
{

}

#pragma endregion func for user interface

void InitAddressBook()
{
    // init

    // get inputs
    while (1)
    {

    }
}

int main()
{
}
