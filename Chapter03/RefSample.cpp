//
// Created by Changjoon Lee on 1/8/24.
//
#include "bits/stdc++.h"
class CRefTest
{
public:
    // CRefTest(int& rParam) /*: m_nData(rParam)*/ { m_nData = rParam }; // error: constructor for 'CRefTest' must explicitly initialize the reference member 'm_nData'
//    CRefTest(int& rParam) : m_nData(rParam) {}; // error: constructor for 'CRefTest' must explicitly initialize the reference member 'm_nData'

    /*
     * 아래와 같은 복사 전달은 CRefTest 함수를 호출할 떄 넣은 값이 rParam 속으로 복사되는 것이다.
     * 이 rParam은 인수로서 해당 함수의 스코프 내에서만 살아 있다.
     * warning은 스택에 할당된 인수로 참조 변수를 초기화하려 한다고 경고하고 있다.
     * 참고로, 스택 메모리엔 지역변수와 인수가 저장된다.
     * 이들은 스코프 밖으로 벗어나면 해제된다.
     * */
    CRefTest(int rParam) : m_nData(rParam) {}; // warning: binding reference member 'm_nData' to stack allocated parameter 'rParam' [-Wdangling-field]
//    CRefTest(int &rParam) { m_nData = rParam };

    int GetData(void) { return m_nData; }

private:
    int& m_nData;
};

int main()
{
    int a = 10;
    CRefTest t(a);

    cout << t.GetData() << endl;

    a = 20;
    cout << t.GetData() << endl;

    return 0;
}
