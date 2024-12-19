//
// Created by Changjoon Lee on 2024. 11. 23..
//
#include "bits/stdc++.h"
using namespace std;

class CNode
{
    friend class CMyList;

public:
    explicit CNode(const char* pszName)
    {
        strcpy(m_szName, pszName);
    }

private:
    char m_szName[32];
    CNode* pNext{nullptr};
};

class CMyList
{
public:
    CMyList() : m_HeadNode("Dummy Head") {}
    ~CMyList()
    {
        CNode* pNode = m_HeadNode.pNext;
        CNode* pDelete = nullptr;

        while (pNode)
        {
            pDelete = pNode;
            pNode = pNode->pNext;

            cout << pDelete->m_szName << endl;
            delete pDelete;
        }

        m_HeadNode.pNext = nullptr;
    }

    void AddNewNode(const char* pszName)
    {
        CNode* pNode = new CNode(pszName);

        /*
         * Head는 아무 정보도 담기지 않는다. Head는 노드가 들어갈 수 있는 기준점 역할만 할 뿐.
         * 그래서 Head 뒤에 여러 노드가 연결돼 있는 상황이라 할 때,
         * Head와 기존에 있던 바로 다음 노드를 뒤로 하나 밀고 새로 할당된 노드를 삽입.
         */
        pNode->pNext = m_HeadNode.pNext;
        m_HeadNode.pNext = pNode;
    }

private:
    CNode m_HeadNode;
};

int main()
{
    CMyList list;
    list.AddNewNode("길동");
    list.AddNewNode("철수");
    list.AddNewNode("영희");
}
