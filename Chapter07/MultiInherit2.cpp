//
// Created by Changjoon Lee on 2024. 11. 18..
//
#include "bits/stdc++.h"

using namespace std;

class CMyImage
{
public:
    CMyImage(int nHeight, int nWidth) : m_nHeight(nHeight), m_nWidth(nWidth)
    {
        cout << "CMyImage(int, int)" << endl;
    }

    inline int GetHeight() { return m_nHeight; }
    inline int GetWidth() { return m_nWidth; }
    inline int GetSize() const { return 0; }

protected:
    int m_nHeight;
    int m_nWidth;
};

class CMyShape
{
public:
    CMyShape(int nType) : m_nType(nType)
    {
        cout << "CMyShape(int)" << endl;
    }
    inline int GetType() { return m_nType; }
    inline int GetSize() const { return 0; }

protected:
    int m_nType;
};

class CMyPicture : public CMyImage, public CMyShape
{
public:
    CMyPicture() : CMyImage(200, 120), CMyShape(1)
    {
        cout << "CMyPicture()" << endl;
    }
};

int main()
{
    CMyPicture a;

    cout << a.GetHeight() << endl;
    cout << a.GetWidth() << endl;
    cout << a.GetType() << endl;

//    a.GetSize(); // Member 'GetSize' found in multiple base classes of different types
    a.CMyImage::GetSize();
    a.CMyShape::GetSize();
}
