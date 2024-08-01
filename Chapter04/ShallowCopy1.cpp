//
// Created by Changjoon Lee on 7/21/24.
//
#define ALLOWING_COMPILERS_DEFAULT_COPY_CONSTRUCTOR 0
#define YOU_MUST_DESIGN_COPY_CONSTRUCTOR_LIKE_THIS 1
#define DELETING_PTR_MEM_VAR 0
#define SUBSTITUTE_IN_CUSTOM_CLASS 1
#define REDEF_SUBSTITUE_OPERATOR 1

#include "bits/stdc++.h"

class CMyData
{
public:
    CMyData(int nParam)
    {
        m_pnData = new int;
        *m_pnData = nParam;
    }

#if ALLOWING_COMPILERS_DEFAULT_COPY_CONSTRUCTOR
    CMyData(const CMyData& rhs)
    {
        m_pnData = rhs.m_pnData;
    }
#elif YOU_MUST_DESIGN_COPY_CONSTRUCTOR_LIKE_THIS
    CMyData(const CMyData& rhs)
    {
        if (!rhs.m_pnData) this->m_pnData = nullptr;

        this->m_pnData = new int;
        *(this->m_pnData) = *(rhs.m_pnData);
    }
#endif

    int GetData(void) const
    {
        if (!m_pnData) return 0;
        return *m_pnData;
    }
#if (DELETING_PTR_MEM_VAR && ALLOWING_COMPILERS_DEFAULT_COPY_CONSTRUCTOR) || YOU_MUST_DESIGN_COPY_CONSTRUCTOR_LIKE_THIS
    ~CMyData()
    {
        delete m_pnData;
    }
#endif

#if REDEF_SUBSTITUE_OPERATOR
    CMyData& operator=(const CMyData& rhs)
    {
        *(this->m_pnData) = *(rhs.m_pnData);
        return *this;
    }
#endif

private:
    int* m_pnData{nullptr};
};

int main()
{
    CMyData a(10);
#if SUBSTITUTE_IN_CUSTOM_CLASS
    CMyData b(20);

    a = b;
#else
    /*
     * 위 실행 줄에 중단점을 찍고 관찰해 보면 기본생성자는 호출되지 않는다.
     * 그러면 멤버변수 m_pnData에는 할당이 일어나지 않으며 a->m_pnData가 그대로 대입된다.
     * 하나의 메모리 주소를 바라보고 있는 포인터 변수가 두개인 것임.
     * ~CMyData()에 delete m_pnData를 써 넣으면 두번째로 ~CMyData()가 호출될 때 댕글링 포인터 문제가 발생.
     */
    CMyData b(a);
#endif
    cout << a.GetData() << endl;
    cout << b.GetData() << endl;
}
