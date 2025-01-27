//
// Created by Changjoon Lee on 2024. 12. 28..
//
#include "DataManager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void ReleaseListItem(struct SAddressBook* _pSelf)
{
    USERDATA* pNodeTmp = _pSelf->m_HeadNode;

    while (pNodeTmp)
    {
        pNodeTmp = FreeNode(_pSelf, pNodeTmp);
    }
}

// 생성자... 같은 것
USERDATA* CreateNode(struct SAddressBook* _pSelf, const char* _sUserName, const char* _sUserPhoneNum)
{
    if (!_pSelf) return NULL;
    USERDATA* pRetNode = (USERDATA*) malloc(sizeof(USERDATA));
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
USERDATA* FreeNode(struct SAddressBook* _pSelf, USERDATA* _pInNode)
{
    if (!_pSelf) return NULL;
    if (!_pInNode) return NULL;

    free(_pInNode->m_sUserName);
    free(_pInNode->m_sUserPhoneNum);

    return _pInNode->m_pNextNode;
}

bool ShowNodeInfo(struct SAddressBook* _pSelf, USERDATA* _pInNode)
{
    if (!_pSelf) return false;
    if (!_pInNode) return false;

    printf("%s \n", _pInNode->m_sUserName);
    printf("%s \n", _pInNode->m_sUserPhoneNum);
    return true;
}

bool AddNode(struct SAddressBook* _pSelf, USERDATA* _pInNode)
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

    USERDATA* pBeforeNode = NULL;
    USERDATA* pNodeFound = NULL;
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
              USERDATA** _ppBeforeNode, USERDATA** _ppNodeFound)
{
    if (!_pSelf) return false;
    USERDATA* pNodeTmp = _pSelf->m_HeadNode;
    if (!pNodeTmp) return false;

    USERDATA* pBeforeNodeTmp = NULL;
    for (;;)
    {
        if (strcmp(pNodeTmp->m_sUserName, _sInChar) == 0 ||
            strcmp(pNodeTmp->m_sUserPhoneNum, _sInChar) == 0)
        {
            if (_ppBeforeNode) *_ppBeforeNode = pBeforeNodeTmp;
            if (_ppNodeFound) *_ppNodeFound = pNodeTmp;
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

int LoadList(struct SAddressBook* _pSelf, char* _sFileName)
{
    if (!_pSelf || !_sFileName) return -1;

    FILE* pFile = fopen(_sFileName, "r");
    if (!pFile) return -1;

    char sUserName[100];
    char sUserPhoneNum[100];
    while (fscanf(pFile, "%s %s", sUserName, sUserPhoneNum) != EOF)
    {
        USERDATA* pNode = CreateNode(_pSelf, sUserName, sUserPhoneNum);
        if (!pNode)
        {
            fclose(pFile);
            return -1;
        }
        AddNode(_pSelf, pNode);
    }

    fclose(pFile);
    return 0;
}

int SaveList(struct SAddressBook* _pSelf, char* _sFileName)
{
    if (!_pSelf || !_sFileName) return -1;

    FILE* pFile = fopen(_sFileName, "w");
    if (!pFile) return 0;

    USERDATA* pNode = _pSelf->m_HeadNode;
    while (pNode)
    {
        fprintf(pFile, "%s %s\n", pNode->m_sUserName, pNode->m_sUserPhoneNum);
        pNode = pNode->m_pNextNode;
    }

    fclose(pFile);
    return 0;
}
