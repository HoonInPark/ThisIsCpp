//
// Created by Changjoon Lee on 2024. 12. 28..
//
#include "DataManager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 생성자... 같은 것
struct USERDATA* CreateNode(struct SAddressBook* _pSelf, const char* _sUserName, const char* _sUserPhoneNum)
{
    if (!_pSelf) return NULL;
    struct USERDATA* pRetNode = (struct USERDATA*) malloc(sizeof(struct USERDATA));
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

// 소멸자... 같은 것
struct USERDATA* FreeNode(struct SAddressBook* _pSelf, struct USERDATA* _pInNode)
{
    if (!_pSelf) return NULL;
    if (!_pInNode) return NULL;

    free(_pInNode->m_sUserName);
    free(_pInNode->m_sUserPhoneNum);

    return _pInNode->m_pNextNode;
}

bool ShowNodeInfo(struct SAddressBook* _pSelf, struct USERDATA* _pInNode)
{
    if (!_pSelf) return false;
    if (!_pInNode) return false;

    printf("%s \n", _pInNode->m_sUserName);
    printf("%s \n", _pInNode->m_sUserPhoneNum);
    return true;
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

bool AddNode(struct SAddressBook* _pSelf, struct USERDATA* _pInNode)
{
    if (!_pSelf || !_pInNode) return false;

    if (!_pSelf->m_HeadNode)
    {
        _pSelf->m_HeadNode = _pInNode;
        return true;
    }

    if (FindNode(_pSelf, _pInNode->m_sUserPhoneNum, NULL, NULL))
    {
//        printf(""); // 이미 해당 노드와 정보가 같은 게 있다는 걸 알려줘야. 근데 이건 유저 인터페이스의 함수를 끌어 써야.
        return true;
    }

    _pInNode->m_pNextNode = _pSelf->m_HeadNode;
    _pSelf->m_HeadNode = _pInNode;
    return true;
}

bool DelNode(struct SAddressBook* _pSelf, const char* _sInChar)
{
    if (!_pSelf) return false;
    if (!_pSelf->m_HeadNode) return false;

    struct USERDATA* pBeforeNode = NULL;
    struct USERDATA* pNodeFound = NULL;
    if (FindNode(_pSelf, _sInChar, &pBeforeNode, &pNodeFound))
    {
        if (!pBeforeNode) // 만약 pBeforeNode가 NULL이면 pNodeFound는 m_HeadNode일 것.
        {
            if (_pSelf->m_HeadNode != pNodeFound) return false;

            _pSelf->m_HeadNode = FreeNode(_pSelf, pNodeFound);
            return true;
        }
        else
        {
            pBeforeNode->m_pNextNode = FreeNode(_pSelf, pNodeFound);
            return true;
        }
    }
    else return false;
}

bool FindNode(struct SAddressBook* _pSelf, const char* _sInChar,
              struct USERDATA** _ppBeforeNode, struct USERDATA** _ppNodeFound)
{
    if (!_pSelf) return false;
    struct USERDATA* pNodeTmp = _pSelf->m_HeadNode;
    if (!pNodeTmp) return false;

    struct USERDATA* pBeforeNodeTmp = NULL;
    for (;;)
    {
        if (strcmp(pNodeTmp->m_sUserName, _sInChar) == 0 ||
            strcmp(pNodeTmp->m_sUserPhoneNum, _sInChar) == 0)
        {
            if (_ppBeforeNode) *_ppBeforeNode = pBeforeNodeTmp;
            *_ppNodeFound = pNodeTmp;
            return true;
        }

        if (pNodeTmp->m_pNextNode)
        {
            pBeforeNodeTmp = pNodeTmp;
            pNodeTmp = pNodeTmp->m_pNextNode;
        }
        else break; // m_pNextNode가 없다는 뜻은 끝에 왔다는 것임. 따라서 브레이크
    }

    return false;
}
