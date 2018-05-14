#include "evolution.h"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
void jobshop::select(double* _q)
{
    _q[0] = r1*exp(r2*decode(genes[0]));
    for(int i=1;i<ps;i++)  _q[i] = _q[i-1] + r1*exp(r2*decode(genes[i]));
    double sum = _q[ps-1];
    for(int i=0;i<ps;i++) _q[i]/=sum;
}

void jobshop::crossover()
{
    double q[ps+1],p1,p2;
    int n1,n2,m1,m2,cnt=0;
    char tgenes[15][15*15];
    srand((unsigned)time(0));
    bool book1[15*15],book2[15*15];
    memcpy(tgenes,genes,sizeof(genes));

    select(q);

    while(cnt<ps)
    {
        p1=rand()/double(RAND_MAX);
        p2=rand()/double(RAND_MAX);
        for(int i=0;i<ps;i++)
        {
            if(n1==-1 && q[i]>p1) n1=i;
            if(n2==-1 && q[i]>p2) n2=i;
            if(n1!=-1 && n2!=-1) break;
        }

        do
        {
            m1=rand()%len;
            m2=rand()%len;
        }while(m1==m2);
        if(m1>m2) {int t;t=m1;m1=m2;m2=t;}

        memset(book1,false,sizeof(book1));
        memset(book2,false,sizeof(book2));

        for(int i=m1;i<=m2;i++)
        {
            genes[cnt][i]=tgenes[n1][i];
            for(int j=0;j<len;j++)
                if(tgenes[n2][j]==tgenes[n1][i]) book2[j]=true;
            genes[cnt+1][i]=tgenes[n2][i];
            for(int j=0;j<len;j++)
                if(tgenes[n2][j]==tgenes[n1][i]) book2[j]=true;
        }

        int j1=0,j2=0;
        for(int i=0;i<m1;i++)
        {
            while(book2[j2]) j2++;
            genes[cnt][i]=tgenes[n2][j2];
            while(book1[j1]) j1++;
            genes[cnt+1][i]=tgenes[n1][j1];
        }
        for(int i=m2+1;i<len;i++)
        {
            while(book2[j2]) j2++;
            genes[cnt][i]=tgenes[n2][j2];
            while(book1[j1]) j1++;
            genes[cnt+1][i]=tgenes[n1][j1];
        }

        lsort(genes[cnt]);
        lsort(genes[cnt+1]);
        cnt+=2;
    }
}
