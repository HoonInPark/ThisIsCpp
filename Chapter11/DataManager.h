//
// Created by Changjoon Lee on 2024. 12. 28..
//

#ifndef CHAPTER11_DATAMANAGER_H
#define CHAPTER11_DATAMANAGER_H

struct SNode* CreateNode(const char* _sUserName, const char* _sUserPhoneNum);
void AddNode(struct SNode* _pInNode);
void ShowNodeInfo(struct SNode* _pNode);
void DelNode();
struct SNode* FindNode(const char* _sInChar);

#endif //CHAPTER11_DATAMANAGER_H
