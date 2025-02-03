#include "LinkedList_OOP.h"


CNode::CNode(const char* _inName, const char* _inPhoneNum)
{
    m_sUserName = new char[strlen(_inName) + 1];
    m_sUserPhoneNum = new char[strlen(_inPhoneNum) + 1];

    strcpy(m_sUserName, _inName);
    strcpy(m_sUserPhoneNum, _inPhoneNum);
}

CNode::~CNode()
{
    delete[] m_sUserName;
    delete[] m_sUserPhoneNum;
}

/////////////////////////////////////////////////////////////////

CAddressbook::CAddressbook(/* args */)
{
}

CAddressbook::~CAddressbook()
{
}
