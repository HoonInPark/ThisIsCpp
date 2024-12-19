//
// Created by Changjoon Lee on 2024. 11. 22..
//
#include "bits/stdc++.h"

using namespace std;

class CMyObject
{
public:
    CMyObject() { cout << "CMyObject()" << endl; }
    virtual ~CMyObject() {}
};

class CMyImage : virtual public CMyObject
{
public:
    CMyImage() { cout << "CMyImage(int, int)" << endl; }
};

class CMyShape : virtual public CMyObject
{
public:
    CMyShape() { cout << "CMyShape(int)" << endl; }
};

class CMyPicture : public CMyImage, public CMyShape
{
public:
    CMyPicture() { cout << "CMyPicture()" << endl; }
};

int main()
{
    CMyPicture a;
}
/*
 * virtual public CMyObject와 같이 상속하지 않으면
 * CMyImage와 CMyShape가 모두 CMyObject를 부모로 두고 있기 떄문에
 * 다음과 같이 CMyObject()가 두번 호출된다.
 * CMyObject()
 * CMyImage(int, int)
 * CMyObject()
 * CMyShape(int)
 * CMyPicture()
*/
