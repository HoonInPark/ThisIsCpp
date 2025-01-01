//
// Created by Changjoon Lee on 2024. 12. 28..
//

#ifndef CHAPTER11_LINKEDLIST_H
#define CHAPTER11_LINKEDLIST_H

struct SNode
{
    char* m_sUserName;
    char* m_sUserPhoneNum;

    struct SNode* m_pNextNode;
};

struct SAddressBook
{
    struct SNode* m_HeadNode;
};

#endif //CHAPTER11_LINKEDLIST_H
