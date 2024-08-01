//
// Created by Changjoon Lee on 7/12/24.
//

#include "bits/stdc++.h"

#define CANNOT_WRITE_IN_CONST_METHOD 0

class CTest
{
public:
    CTest(int nParam) { m_nData = nParam; }

    ~CTest() {}

    [[nodiscard]] int GetData() const
    {
#if CANNOT_WRITE_IN_CONST_METHOD
        /*
         * 빌드하면 다음과 같은 메시지를 뱉는다.
         * 'this' argument to member function 'SetData' has type 'const CTest', but function is not marked const
         * 윈도우에서 빌드하면
         * error C2662 : 'function': 'this' 포인터를  'const XXXX'에서 'XXXX &'(으)로 변환할 수 없습니다.
         * 와 같은 메시지를 뱉는다.
         * 즉, const 함수를 만드는 과정은 곧 this를 const로 변환하는 것.
         *
         */
        /*this->*/SetData(20);
#endif
        return m_nData;
    }
    int SetData(int nParam)
    {
        m_nData = nParam;
        return 0;
    }

private:
    int m_nData = 0;
};

int main()
{
    CTest a(10);
    cout << a.GetData() << endl;
}
