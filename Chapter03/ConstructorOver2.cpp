//
// Created by Changjoon Lee on 1/8/24.
//

#include <iostream>
using namespace std;

class CMyPoint {
public:
    CMyPoint(int x) {
        cout << "CMyPoint(int)" << endl;
        if (x > 100)
            x = 100;

        m_x = 100;
    }

    CMyPoint(int x, int y)
            : CMyPoint(x) { // 여기서 하나의 생성자가 다른 생성자도 호출한다.
        cout << "CMyPoint(int, int)" << endl;

        if (y > 200)
            y = 200;

        m_y = 200;
    }

    void Print() {
        cout << "X:" << m_x << endl;
        cout << "Y:" << m_y << endl;
    }

private:
    int m_x = 0;
    int m_y = 0;
};

int main() {
    CMyPoint ptBegin(110);
    ptBegin.Print();

    CMyPoint ptEnd(50, 250);
    ptEnd.Print();

    return 0;
}
