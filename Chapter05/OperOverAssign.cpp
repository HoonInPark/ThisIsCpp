#include "bits/stdc++.h"
using namespace std;

int Foo(int inVal)
{
    return inVal;
}

int main()
{
    int&& r_val_ref = Foo(1);
}