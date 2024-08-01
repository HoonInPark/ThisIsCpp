//
// Created by Changjoon Lee on 1/5/24.
//

#include <iostream>

using namespace std;

class CMyData {
    int m_nData;

public:
    int GetData(void) { return m_nData; }

    void SetData(int nParam) { m_nData = nParam; }
};

int main(){
    CMyData data;
    data.SetData(10);
    cout << data.GetData() << endl;
    return 0;
}