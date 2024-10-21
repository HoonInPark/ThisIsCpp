//
// Created by Changjoon Lee on 2024. 10. 21..
//
#include "MyStringEx.h"
#include "bits/stdc++.h"

int CMyStringEx::Find(const char* pszParam)
{
    const int&& i_str_len_of_m = GetLength();
    const unsigned long&& i_str_len_of_param = strlen(pszParam);

    if (i_str_len_of_m < i_str_len_of_param) return false;

    for (int i = 0; i < i_str_len_of_m; i++)
    {
        if (pszParam[0] != GetString()[i]) continue;
        if (i_str_len_of_m - i < i_str_len_of_param) return false;

        bool b_is_diff = false;
        for (int j = 1; j < i_str_len_of_param; ++j) // index 0은 이미 검사.
            if (GetString()[i + j] != pszParam[j]) b_is_diff = true;

        if (b_is_diff)
            continue;
        else
            return i;
    }

    return -1;
}
