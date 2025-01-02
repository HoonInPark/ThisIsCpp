//
// Created by Changjoon Lee on 2024. 12. 28..
//

#ifndef CHAPTER11_USERINTERFACE_H
#define CHAPTER11_USERINTERFACE_H

#include "DataManager.h"
/*
 * 주소 추가, 주소 검색, 모든 주소 출력, 주소 제거, 프로그램 종료
 * */

int InitAddressBook();

void PrintMenu();
int ProcessMenuInput(struct SAddressBook* _pSelf);

#endif //CHAPTER11_USERINTERFACE_H
