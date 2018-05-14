//
// Created by liuren on 18-5-14.
//

#include "evolution.h"
#include <cstring>

inline int max(int a, int b){if(a>=b) return a;return b;}

int jobshop::decode(int *g)
{
    int d[15],p[15];
    memset(TT,0,sizeof(TT));
    memset(d,0,sizeof(d));   //对应机器上的最大完成时间
    memset(p,0,sizeof(p));   //对应工件上的最大完成时间

    for(int j=0;j<len;j++)
    {
        int k=g[j];
        TT[pc[k].m][k] = max(d[pc[k].m], p[pc[k].i]) + pc[k].t;
        d[pc[k].m] = p[pc[k].i] = TT[pc[k].m][k];
    }

    int maxt=0;
    for(int i=0;i<m;i++)
        maxt = max(maxt,d[i]);
    ans = max(ans, maxt);
    return maxt;
}
