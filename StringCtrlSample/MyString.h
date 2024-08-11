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

private:
    char* m_pszData;
    int m_nLength;

public:
    int SetString(const char* pszParam = "");
    const char* GetString() const;
    void Release();

    CMyString& operator=(const CMyString& rhs);
    operator const char*(void) { return m_pszData; }
};


#endif //STRINGCTRLSAMPLE_MYSTRING_H
