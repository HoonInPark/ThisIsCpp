//
// Created by Changjoon Lee on 2024. 12. 28..
//
#include "DataManager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

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
