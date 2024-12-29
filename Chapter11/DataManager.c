//
// Created by Changjoon Lee on 2024. 12. 28..
//
#include "DataManager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SNode* CreateNode(const char* _sUserName, const char* _sUserPhoneNum)
{
    struct SNode* pRetNode = (struct SNode*) malloc(sizeof(struct SNode));
    if (!pRetNode) return NULL;

    pRetNode->m_pNextNode = NULL;
    pRetNode->m_sUserName = (char*) malloc(
            sizeof(char) *
            (strlen(_sUserName) + 1));
    pRetNode->m_sUserPhoneNum = (char*) malloc(
            sizeof(char) *
            (strlen(_sUserPhoneNum) + 1));

    strcpy(pRetNode->m_sUserName, _sUserName);
    strcpy(pRetNode->m_sUserPhoneNum, _sUserPhoneNum);

    return pRetNode;
}

void ShowNodeInfo(struct SNode* _pInNode)
{
    printf("%s \n", _pInNode->m_sUserName);
    printf("%s \n", _pInNode->m_sUserPhoneNum);
}

struct SAddressBook* CreateList()
{
    struct SAddressBook* pRetList = (struct SAddressBook*) malloc(sizeof(struct SAddressBook));
    if (pRetList)
    {
        pRetList->m_HeadNode = NULL;
        return pRetList;
    }

    return NULL;
}

bool AddNode(struct SAddressBook* _pSelf, struct SNode* _pInNode)
{
    if (!_pSelf || !_pInNode) return false;

    if (!_pSelf->m_HeadNode)
    {
        _pSelf->m_HeadNode = _pInNode;
        return true;
    }

    _pInNode->m_pNextNode = _pSelf->m_HeadNode;
    _pSelf->m_HeadNode = _pInNode;
    return true;
}

bool DelNode(struct SAddressBook* _pSelf, struct SNode* _pInNode)
{
    if (_pSelf->m_HeadNode == _pInNode)
    {
        
    }

    struct SNode* pNodeBefore;
    struct SNode* pNodeCurr = _pSelf->m_HeadNode;
    while (pNodeCurr != NULL)
    {
        pNodeBefore = pNodeCurr;
        pNodeCurr = pNodeBefore->m_pNextNode;

        if (pNodeCurr == _pInNode)
        {

        }
    }

    return 0;
}

struct SNode* FindNode(const char* _sInChar)
{
    return NULL;
}
