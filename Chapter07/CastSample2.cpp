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
