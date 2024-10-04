//
// Created by Changjoon Lee on 2/4/24.
//

#ifndef STRINGCTRLSAMPLE_MYSTRING_H
#define STRINGCTRLSAMPLE_MYSTRING_H


class CMyString
{
public:
    CMyString();

    explicit CMyString(const char* _str); // 변환생성자
    CMyString(const CMyString& rhs);

    CMyString(CMyString&& rhs);

    ~CMyString();

public:
    int SetString(const char* pszParam = "");

    const char* GetString() const;

    int GetLenth() const;

    void Release();

    int Append(const char* pszParam);

    CMyString& operator=(const CMyString& rhs);

    CMyString operator+(const CMyString& rhs);

    CMyString& operator+=(const CMyString& rhs);

    operator const char*(void) { return m_pszData; }

private:
    char* m_pszData{nullptr};
    int m_nLength{0};

};


#endif //STRINGCTRLSAMPLE_MYSTRING_H
