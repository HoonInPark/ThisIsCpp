//
// Created by Changjoon Lee on 12/30/23.
//

#include <stdio.h>

typedef struct USERDATA {
    int nAge;
    char szName[32];
} USERDATA;

void PrintData(USERDATA *pUser) {
    printf("%d, %s\n", pUser->nAge, pUser->szName);
}

int main() {
    USERDATA user = {20, "철수"};
    // 다음과 같이, 출력을 위해 어떤 변수를 일일이 알아야 할 필요 없이 출력만 할 수 있게 한 것을 인터페이스라고 한다.
    // 그리고 이와 같은 역할을 수행하는 함수를 인터페이스 함수라 한다.
    PrintData(&user);

    return 0;
}

// 제작자와 사용자를 분리해서 생각하자. 만드는 사람 따로, 쓰는 사람 따로일 때, 개발 편의성을 증진하려면 어떻게 해야할까?
// 바로... 이럴 때 객체지향이 필요한 것이다.