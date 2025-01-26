//
// Created by Changjoon Lee on 2024. 12. 27..
//

#define TEST 1

// 충격적인 사실 : C언어의 구조체는 public, private이 없고, 내부에 함수를 정의할 수도 없다.
#if !TEST
#include <printf.h>
#include "UserInterface.h"

/*
 * 1. 노드를 만들어야. v
 * 2. 만들어진 노드가 들어갈 리스트가 있어야. v
 * 3. 노드 정보를, 노드가 그대로 있는 채로 쓸 수 있어야 x
 * 4. 노드 정보를 출력하는 함수 필요 v
 * 5. 노드를 검색하는 함수 v
 * 6. 노드를 삭제하는 함수 v
 * 7. 노드를 추가하는 함수 v
 * 8. 이 함수들을 어떻게 관리하지?
 * */
int main()
{
    return InitAddressBook();
}
#else // 일단 기본적인 예제가 제대로 동작하는지 확인해 보는 것부터 다시 시작해 보는 걸로!

#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

struct person
{
    char name[7], gender[3];
    int age;
};
typedef struct person PERSON;

int main()
{
    int i;
    PERSON user;
    FILE* fp = fopen(
        "/Users/changjoonlee/Documents/Cpp/ThisIsCpp/Chapter11/cmake-build-debug/Address.dat", 
        "wb");

    if (NULL == fp)
    {
        printf("file open error! \n");
        exit(1);
    }
    
    printf(">> type user info (num of %d)", SIZE);
    for (int i = 0; i < SIZE; i++)
    {
        printf("\n%d. name : ", i + 1) ; gets(user.name);
        printf("    sex : "); gets(user.gender);
        printf("    age : "); scanf("%d", &user.age);

        fwrite(&user, sizeof(PERSON), 1, fp);
        fflush(stdin);
    }
    
    fclose(fp);
    printf("\n==file output success==\n");
}
#endif

