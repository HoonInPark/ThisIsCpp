//
// Created by Changjoon Lee on 2024. 12. 28..
//

#include <printf.h>
#include <stdlib.h>
#include "UserInterface.h"

int InitAddressBook()
{
    // 동적할당 필요 없지 않나? 이 스코프 바깥으로 해당 포인터가 벗어날 일이 없는데?
    struct SAddressBook* SingleAddressBook; // = (struct SAddressBook*) malloc(sizeof(struct SAddressBook))
    SingleAddressBook->m_HeadNode = NULL;

    for (;;)
    {
        PrintMenu();
        if (ProcessMenuInput()) return 1;

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

int ProcessMenuInput()
{
    system("clear");
    char cInput;
    scanf("%cInput", &cInput);

    switch (cInput - 80)
    {
        case 1:
        {
            char sInput[64];

            printf("type name or phone number : ");
            scanf("%sInput", sInput);
//            FindNode();

            break;
        }
        case 2:
        {
            char sInput[64];
            printf("type name : ");
            scanf("%sInput", sInput);
            printf("type phone number : ");


            break;
        }
        case 3:
        {
            break;
        }
        case 4:
        {
            break;
        }
        case 5:
        {
            break;
        }
        default:
            break;
    }

    return 0;
}
