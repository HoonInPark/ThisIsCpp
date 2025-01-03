//
// Created by Changjoon Lee on 2024. 12. 28..
//

#ifndef CHAPTER11_DATAMANAGER_H
#define CHAPTER11_DATAMANAGER_H

#include <stdbool.h>
#include "LinkedList.h"

struct USERDATA* CreateNode(struct SAddressBook* _pSelf, const char* _sUserName, const char* _sUserPhoneNum);
bool ShowNodeInfo(struct SAddressBook* _pSelf, struct USERDATA* _pInNode);
struct USERDATA* FreeNode(struct SAddressBook* _pSelf, struct USERDATA* _pInNode);

struct SAddressBook* CreateList();

bool AddNode(struct SAddressBook* _pSelf, struct USERDATA* _pInNode);
bool DelNode(struct SAddressBook* _pSelf, const char* _sInChar);

bool FindNode(struct SAddressBook* _pSelf, const char* _sInChar,
              struct USERDATA* _pBeforeNode, struct USERDATA* _pNodeFound);

#endif //CHAPTER11_DATAMANAGER_H
