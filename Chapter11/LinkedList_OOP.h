#include "bits/stdc++.h"
using namespace std;

class CNode
{
public:
    CNode(const char* _inName, const char* _inPhoneNum);
    ~CNode();

private:
    char* m_sUserName;
    char* m_sUserPhoneNum;

    CNode* m_pNextNode;
};

/////////////////////////////////////////////////////////////////

class CAddressbook
{
public:
    CAddressbook(/* args */);
    ~CAddressbook();

private:
    /* data */
};
