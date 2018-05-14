//
// Created by liuren on 18-5-14.
//

#include <cstdio>
#include <cstring>
#include "evolution.h"

jobshop::jobshop(int nn,int mm)
{
    n=nn;
    m=mm;
    len=ans=0;
    memset(TMJ,0,sizeof(TMJ));
    memset(genes,0,sizeof(genes));
    memset(pc,0,sizeof(process));
}

void jobshop::input()
{
    int j,k,a,b,cnt=0;               //k��ʾ�����ţ�a��ʾʱ�䣬b��ʾ������
    while(scanf("%d",&k)&&k!=-1)
    {
        j=0;
        startpro[k]=cnt+1;
        while(scanf(" (%d,%d)",&a,&b))
        {
            pc[++len].t=a;
            pc[len].m=b;
            pc[len].i=k;
            pc[len].j=++j;
            TMJ[b][len]=a;
            ++cnt;
        }
    }

}
