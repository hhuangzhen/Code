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
    int j,k,a,b;               //k表示工件号，a表示时间，b表示机器号
    while(scanf("%d",&k)&&k!=-1)
    {
        j=0;
        while(scanf(" (%d,%d)",&a,&b))
        {
            pc[++len].t=a;
            pc[len].m=b;
            pc[len].i=k;
            pc[len].j=++j;
            TMJ[b][len]=a;
        }
    }

}
