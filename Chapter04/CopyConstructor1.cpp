//
// Created by Changjoon Lee on 7/19/24.
//

#define REGION_YOU_CAN_USE_WITH_HEAP_ALLOC 1
#define IS_CONST_PARAMS_MEM_CAN_BE_MODIFIED 0
#define WHEN_YOU_USE_MEM_INI_LIST 0

#include "bits/stdc++.h"

class CMyData
{
public:
    CMyData() { cout << "CMyData()" << endl; }

    CMyData(const CMyData& rhs)
#if WHEN_YOU_USE_MEM_INI_LIST
        : m_pnData(rhs.m_pnData) // 얘는 private인데 왜 되지?
#else
#endif
    {
#if WHEN_YOU_USE_MEM_INI_LIST
#else
        this->m_pnData = rhs.m_pnData;
#endif

#if IS_CONST_PARAMS_MEM_CAN_BE_MODIFIED
        rhs.m_nData_public = 1; // 참조형식으로 가져온 변수에 const 한정자를 붙이면 그 변수의 멤버도 수정할 수 없다.
#endif
        cout << "CMyData(const CMyData& rhs)" << endl;
    }

#if REGION_YOU_CAN_USE_WITH_HEAP_ALLOC
    CMyData(CMyData* rhs)
    {
        this->m_pnData = rhs->m_pnData;
        cout << "CMyData(const CMyData& rhs)" << endl;
    }
#endif

    int GetData(void) const { return m_pnData; }
    void SetData(int nParam) { m_pnData = nParam; }

#if IS_CONST_PARAMS_MEM_CAN_BE_MODIFIED
public:
    int m_nData_public{0};
#endif

private:
    int m_pnData{0};
};

int main()
{
#if REGION_YOU_CAN_USE_WITH_HEAP_ALLOC
    auto a_heap_alloced = new CMyData();
    a_heap_alloced->SetData(10);

    auto b_heap_alloced = new CMyData(a_heap_alloced);
    cout << b_heap_alloced->GetData() << endl;

    delete b_heap_alloced;
    delete a_heap_alloced;
#else
    CMyData a;
    a.SetData(10);

    CMyData b(a);
    cout << b.GetData() << endl;
#endif
}
