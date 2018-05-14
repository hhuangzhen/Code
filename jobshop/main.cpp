#include <iostream>
#include "evolution.h"
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    jobshop js(n,m);
    js.input();
    js.test();
    return 0;
}
