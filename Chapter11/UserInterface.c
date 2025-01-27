//
// Created by Changjoon Lee on 2024. 12. 28..
//
#include "UserInterface.h"

#include <printf.h>
#include <stdlib.h>
#include <string.h>

/*
 * 문제들
 * 1. InitAddressBook() 안에서 동적할당 없이 SAddressBook를 쓰고 싶다. 근데 터지네? v
 * 2. case 2에서 사용자 입력이 정상적으로 안되는 문제. -> 지금은 Find 함수가 안되는 중
 * 3. 그리고 입력 버퍼? 얘 뭐 하는 애인가? -> <C 프로그래밍> 100p 참조. v
 * 3. 왜 또 입력이 안되지? -> 한글 자판으로 쳐서! v
 * 4. 왜 선택하고자 하는 옵션이 나타나지 않지? v
 * */

#define DATA_FILE_NAME "/Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter11/cmake-build-debug/Address.dat"

int InitAddressBook()
{
    struct SAddressBook *pSelf = CreateList();
    pSelf->m_HeadNode = NULL;

    LoadList(pSelf, DATA_FILE_NAME);

    int ReturnCode;
    for (;;)
    {
        // system("clear");
        PrintMenu();
        ReturnCode = ProcessMenuInput(pSelf);
        if (1 == ReturnCode)
            break;
        else if (0 == ReturnCode)
            break;
    }

    if (pSelf)
    {
        SaveList(pSelf, DATA_FILE_NAME);
        
        ReleaseListItem(pSelf);
        free(pSelf);

        return ReturnCode;
    }
    else
        return 0;
}

void PrintMenu()
{
    system("clear");
    printf("\n 1. find address");
    printf("\n 2. add address");
    printf("\n 3. print all");
    printf("\n 4. delete address");
    printf("\n 5. close \n");
}

int ProcessMenuInput(struct SAddressBook *_pSelf)
{
    if (!_pSelf)
        return 1;

    printf("type : ");
    char cInput;

    scanf("%cInput", &cInput);
    fflush(stdin);
    printf("\n");

    switch (cInput - 48)
    {
    case 1:
    {
        char sInput[64];
        printf("type name or phone number : ");
        scanf("%[^\n]s", sInput);
        fflush(stdin);

        USERDATA* pNodeTmp;
        if (FindNode(_pSelf, sInput, NULL, &pNodeTmp))
            ShowNodeInfo(_pSelf, pNodeTmp);
        else
            printf("can't find %s", sInput);

        break;
    }
    case 2:
    {
        char sInputName[64], sInputNum[16];

        printf("type name : ");
        scanf("%[^\n]s", sInputName);
        fflush(stdin);
        printf("%s", sInputName);

        printf("\ntype phone number : ");
        scanf("%[^\n]s", sInputNum);
        fflush(stdin);
        printf("%s", sInputNum);

        USERDATA *pNodeTmp = CreateNode(_pSelf, sInputName, sInputNum);
        if (pNodeTmp)
            AddNode(_pSelf, pNodeTmp);

        break;
    }
    case 3:
    {
        USERDATA *pNodeTmp;
        pNodeTmp = _pSelf->m_HeadNode;
        for (;;)
        {
            if (!pNodeTmp)
                break;

            ShowNodeInfo(_pSelf, pNodeTmp);
            pNodeTmp = pNodeTmp->m_pNextNode;
        }
        break;
    }
    case 4:
    {
        char sInputName[64], sInputNum[16];
        printf("type name : ");
        scanf("%sInputName", sInputName);
        fflush(stdin);

        if (!DelNode(_pSelf, sInputName))
            break;

        break;
    }
    case 5:
    {
        return 0;
        break;
    }
    default:
        break;
    }

    getchar();

    return -1;
}
