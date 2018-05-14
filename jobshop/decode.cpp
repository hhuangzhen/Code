#include "evolution.h"
#include <cstring>

inline int max(int a, int b){if(a>=b) return a;return b;}

int jobshop::decode(char *g)
{
    int d[15],p[15];
    memset(TT,0,sizeof(TT));
    memset(d,0,sizeof(d));   //��Ӧ�����ϵ�������ʱ��
    memset(p,0,sizeof(p));   //��Ӧ�����ϵ�������ʱ��

    for(int j=0;j<len;j++)
    {
        int k=g[j]-'0';
        TT[pc[k].m][k] = max(d[pc[k].m], p[pc[k].i]) + pc[k].t;
        d[pc[k].m] = p[pc[k].i] = TT[pc[k].m][k];
    }

    int maxt=0;
    for(int i=0;i<m;i++)
        maxt = max(maxt,d[i]);
    ans = max(ans, maxt);
    return maxt;
}
