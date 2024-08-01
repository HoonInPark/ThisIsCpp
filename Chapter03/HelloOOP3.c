//
// Created by Changjoon Lee on 12/30/23.
//
#include <stdio.h>

typedef struct USERDATA {
    int nAge;
    char szName[32];

    /*
     * 함수가 들어갈 포인터 변수를 선언한 것임.
     * 근데, 이 함수는 자기 자신(객체지향의 언어로 따지자면 this)을 포인터로 지목하고 있다.
     * 이상하다!
     * */
    void (*Print)(struct USERDATA *);
} USERDATA;

void PrintData(USERDATA *pUser) {
    printf("%d, %s\n", pUser->nAge, pUser->szName);
}

int main() {
    USERDATA user = {20, "철수", PrintData};
    user.Print(&user);

    return 0;
}
