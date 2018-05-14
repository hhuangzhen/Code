//
// Created by liuren on 18-5-14.
//
#include <cstdio>
#include <cstring>
#include "evolution.h"
#include <cstdlib>
void jobshop::lsort(int *a)
{
    int *b;
    b=(int *)malloc((n+1)*sizeof(int));
    memset(b,0,sizeof(b));
    for(int i=0;i<len;i++)
    {
        int t=a[i];
        a[i]=(b[pc[t].i]++)+startpro[pc[t].i];
    }
}