//
// Created by Changjoon Lee on 2024. 12. 28..
//

#include <printf.h>
#include <stdlib.h>
#include "UserInterface.h"

int InitAddressBook()
{
    // 동적할당 필요 없다. 이 스코프 바깥으로 해당 포인터가 벗어날 일이 없기에.
    struct SAddressBook* pSingleAddressBook;
    pSingleAddressBook->m_HeadNode = NULL;

    for (;;)
    {
        PrintMenu();
        if (ProcessMenuInput(pSingleAddressBook)) return 1;
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

            struct SNode* pNodeTmp;
            FindNode(_pSelf, sInput, NULL, pNodeTmp);
            ShowNodeInfo(_pSelf, pNodeTmp);

            break;
        }
        case 2:
        {
            char sInputName[64], sInputNum[16];
            printf("type name : ");
            fgets(sInputName, sizeof(sInputName), stdin);
            printf("\n");
            printf("type phone number : ");
            fgets(sInputNum, sizeof(sInputNum), stdin);

            struct SNode* pNodeTmp = CreateNode(_pSelf, sInputName, sInputNum);
            if (pNodeTmp)
                AddNode(_pSelf, pNodeTmp);

            break;
        }
        case 3:
        {
            struct SNode* pNodeTmp;
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

    return 0;
}
