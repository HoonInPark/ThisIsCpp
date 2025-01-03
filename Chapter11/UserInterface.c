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
 * 2. case 2에서 사용자 입력이 정상적으로 안되는 문제.
 * 3. 그리고 입력 버퍼? 얘 뭐 하는 애인가?
 * 3.
 * */

int InitAddressBook()
{
    // 동적할당 필요 없다. 이 스코프 바깥으로 해당 포인터가 벗어날 일이 없기에.
    struct SAddressBook SingleAddressBook;
    struct SAddressBook* pSelf = &SingleAddressBook;
    pSelf->m_HeadNode = NULL;

    int ReturnCode;
    for (;;)
    {
        PrintMenu();
        ReturnCode = ProcessMenuInput(pSelf);
        if (1 == ReturnCode) return 1;
        else if (0 == ReturnCode) return 0;
    }

    // 정상 종료되면 리턴 0
    return 0;
}

void PrintMenu()
{
    system("clear");
    printf("1. find address \n");
    printf("2. add address \n");
    printf("3. print all \n");
    printf("4. delete address \n");
    printf("5. close \n");
}

int ProcessMenuInput(struct SAddressBook* _pSelf)
{
    if (!_pSelf) return 1;

    system("clear");
    char cInput;
    printf("type : ");
    scanf("%cInput", &cInput);
    printf("\n");

    switch (cInput - 48)
    {
        case 1:
        {
            char sInput[64];
            printf("type name or phone number : ");
            scanf("%sInput", sInput);

            struct USERDATA* pNodeTmp;
            FindNode(_pSelf, sInput, NULL, pNodeTmp);
            ShowNodeInfo(_pSelf, pNodeTmp);

            break;
        }
        case 2:
        {
            char sInputName[64], sInputNum[16];
            printf("type name : ");
            fgets(sInputName, sizeof(sInputName), stdin);
//            sInputName[strcspn(sInputName, "\n")] = '\0';
            fflush(stdin);

            printf("\n");
            printf("type phone number : ");
            fgets(sInputNum, sizeof(sInputNum), stdin);
//            sInputNum[strcspn(sInputNum, "\n")] = '\0';

            struct USERDATA* pNodeTmp = CreateNode(_pSelf, sInputName, sInputNum);
            if (pNodeTmp)
                AddNode(_pSelf, pNodeTmp);

            break;
        }
        case 3:
        {
            struct USERDATA* pNodeTmp;
            pNodeTmp = _pSelf->m_HeadNode;
            for(;;)
            {
                if (!pNodeTmp) break;

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
            printf("type phone number : ");
            scanf("%sInputNum", sInputNum);

            if (!DelNode(_pSelf, sInputName) &&
                !DelNode(_pSelf, sInputNum))
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

    return -1;
}
