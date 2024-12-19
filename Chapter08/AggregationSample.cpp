//
// Created by Changjoon Lee on 2024. 11. 26..
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

    void PrintNode()
    {
        CNode* pNode = m_HeadNode.pNext;
        while (pNode)
        {
            cout << pNode->m_szName << endl;
            pNode = pNode->pNext;
        }
    }

private:
    CNode m_HeadNode;
};

class CMyUI
{
public:
    CMyUI(CMyList& rList) : m_list(rList) {}

    int PrintMenu()
    {
        system("cls");
        cout << "[1]Add\t" << "[2]Print\t" << "[1]Exit\n:";
        cout.flush();
        int nInput = 0;
        cin >> nInput;

        return nInput;
    }

    void Run()
    {
        char szName[32];
        int nInput = 0;

        while ((nInput = PrintMenu()) > 0)
        {
            switch (nInput)
            {
                case 1:
                {
                    cout << "이름 : ";
                    cout.flush();
                    cin >> szName;
                    m_list.AddNewNode(szName);
                    break;
                }
                case 2:
                {
                    m_list.PrintNode();
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    CMyList& m_list;
};

int main()
{
    CMyList list;
    CMyUI ui(list);
    ui.Run();
}
