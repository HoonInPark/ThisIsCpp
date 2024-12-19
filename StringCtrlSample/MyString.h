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
    virtual void OnSetString(char* pszData, int nLength);

    [[nodiscard]] inline const char* GetString() const
    {
        return m_pszData;
    }

    [[nodiscard]] inline int GetLength() const
    {
        return m_nLength;
    }

    void Release();

    int Append(const char* pszParam);

    CMyString& operator=(const CMyString& rhs);

    CMyString operator+(const CMyString& rhs);

    CMyString& operator+=(const CMyString& rhs);

    operator const char*() { return m_pszData; }

    char& operator[](int nIndex);
    char operator[](int nIndex) const;

    int operator==(const CMyString& rhs);
    int operator!=(const CMyString& rhs);

    friend CMyString operator+(const char* pszParam, const CMyString& strParam);

private:
    char* m_pszData{nullptr};
    int m_nLength{0};
};


#endif //STRINGCTRLSAMPLE_MYSTRING_H
