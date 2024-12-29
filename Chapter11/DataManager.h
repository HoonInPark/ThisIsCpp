//
// Created by Changjoon Lee on 2024. 12. 28..
//

#ifndef CHAPTER11_DATAMANAGER_H
#define CHAPTER11_DATAMANAGER_H

#include <stdbool.h>
#include "LinkedList.h"

struct SNode* CreateNode(const char* _sUserName, const char* _sUserPhoneNum);
void ShowNodeInfo(struct SNode* _pInNode);

struct SAddressBook* CreateList();

bool AddNode(struct SAddressBook* _pSelf, struct SNode* _pInNode);
bool DelNode(struct SAddressBook* _pSelf, struct SNode* _pInNode);

struct SNode* FindNode(const char* _sInChar);

#endif //CHAPTER11_DATAMANAGER_H
