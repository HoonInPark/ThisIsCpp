//
// Created by Changjoon Lee on 2024. 11. 5..
//
#include "bits/stdc++.h"
using namespace std;

class CShape
{
public:
    CShape() {}
    virtual ~CShape() {}
    virtual void Draw() { cout << "CShape::Draw()" << endl; }
};

class CRectangle : public CShape
{
public:
    virtual void Draw() { cout << "CRectangle::Draw()" << endl; }
};

class CCircle : public CShape
{
public:
    virtual void Draw() { cout << "CCircle::Draw()" << endl; }
};

int main()
{
    cout << "도형 번호를 입력하세요 [1 : 사각형 2: 원] : " << endl;
    int nInput;
    cin >> nInput;
    CShape* pShape = nullptr;

    if (1 == nInput)
        pShape = new CRectangle;
    else if (2 == nInput)
        pShape = new CCircle;

    pShape->Draw();

    /*
     * 실형식으로 형변환이 되는지 판별하기 위해
     * 실형식으로 형변환시키는 dynamic_cast를 써서 아래와 같은 과정을 한 거 같은데...
     * 1. dynamic_cast는 비싸다.
     * 2. 코드가 길어진다. 그냥 virtual 쓰세요.
     * 3. dynamic_cast는 자식 객체간 캐스팅은 안된다.
     * 참조형식이 부모형식일 때 자식 형식 중 실형식과 동일한 것으로 캐스팅할 수 있을 뿐.
     * */
    CRectangle* pRect = dynamic_cast<CRectangle*>(pShape);
    if (pRect)
        cout << "CRectangle::Draw()" << endl;
    else
    {
        CCircle* pCircle = dynamic_cast<CCircle*>(pShape);
        if (pCircle)
            cout << "CCircle::Draw()" << endl;
        else
            cout << "CShape::Draw()" << endl;
    }
}
