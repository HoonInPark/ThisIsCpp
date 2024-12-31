//
// Created by Changjoon Lee on 2024. 12. 28..
//

#ifndef CHAPTER11_DATAMANAGER_H
#define CHAPTER11_DATAMANAGER_H

#include <stdbool.h>
#include "LinkedList.h"

struct SNode* CreateNode(const char* _sUserName, const char* _sUserPhoneNum);
void ShowNodeInfo(struct SNode* _pInNode);
struct SNode* FreeNode(struct SNode* _pInNode);

struct SAddressBook* CreateList();

bool AddNode(struct SAddressBook* _pSelf, struct SNode* _pInNode);
bool DelNode(struct SAddressBook* _pSelf, const char* _sInChar);

bool FindNode(struct SAddressBook* _pSelf, const char* _sInChar,
              struct SNode* _pBeforeNode, struct SNode* _pNodeFound);

#endif //CHAPTER11_DATAMANAGER_H
