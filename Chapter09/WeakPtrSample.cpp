//
// Created by Changjoon Lee on 2024. 12. 11..
//
#include "bits/stdc++.h"

using namespace std;

class CNode
{
    std::string s;
    std::weak_ptr<CNode> other;

public:
    CNode(const std::string& s)
            : s(s)
    {
        std::cout << "자원을 획득함!" << std::endl;
    }

    ~CNode()
    {
        std::cout << "소멸자 호출!" << std::endl;
    }

    void set_other(std::weak_ptr<CNode> o) { other = o; }

    void access_other()
    {
        std::shared_ptr<CNode> o = other.lock();
        if (o)
        {
            std::cout << "접근 : " << o->name() << std::endl;
        }
        else
        {
            std::cout << "이미 소멸됨 ㅠ" << std::endl;
        }
    }

    std::string name() { return s; }
};

int main()
{
    std::vector<std::shared_ptr<CNode>> vec;
    vec.push_back(std::make_shared<CNode>("자원 1"));
    vec.push_back(std::make_shared<CNode>("자원 2"));

    vec[0]->set_other(vec[1]);
    vec[1]->set_other(vec[0]);

    // pa 와 pb 의 ref count 는 그대로다.
    std::cout << "vec[0] ref count : " << vec[0].use_count() << std::endl;
    std::cout << "vec[1] ref count : " << vec[1].use_count() << std::endl;

    // weak_ptr 로 해당 객체 접근하기
    vec[0]->access_other();

    // 벡터 마지막 원소 제거 (vec[1] 소멸)
    vec.pop_back();
    vec[0]->access_other();  // 접근 실패!
}
