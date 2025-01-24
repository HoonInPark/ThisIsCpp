//
// Created by Changjoon Lee on 2024. 12. 28..
//

#ifndef CHAPTER11_DATAMANAGER_H
#define CHAPTER11_DATAMANAGER_H

#include <stdbool.h>
#include "LinkedList.h"

struct SAddressBook* CreateList();
void ReleaseListItem(struct SAddressBook* _pSelf);

struct USERDATA* CreateNode(struct SAddressBook* _pSelf, const char* _sUserName, const char* _sUserPhoneNum);
bool ShowNodeInfo(struct SAddressBook* _pSelf, struct USERDATA* _pInNode);
struct USERDATA* FreeNode(struct SAddressBook* _pSelf, struct USERDATA* _pInNode);

bool AddNode(struct SAddressBook* _pSelf, struct USERDATA* _pInNode);
bool DelNode(struct SAddressBook* _pSelf, const char* _sInChar);

bool FindNode(struct SAddressBook* _pSelf, const char* _sInChar,
              struct USERDATA** _ppBeforeNode, struct USERDATA** _ppNodeFound);
int LoadList(struct SAddressBook* _pSelf, char* _sFileName);
int SaveList(struct SAddressBook* _pSelf, char* _sInChar);

#endif //CHAPTER11_DATAMANAGER_H
