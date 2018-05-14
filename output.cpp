//
// Created by liuren on 18-5-14.
//

#include "evolution.h"
#include <cstdio>

void jobshop::output()
{
    decode(theBestGene);
    for(int i=0;i<m;i++)
    {
        printf("M%d ", i);
        for(int j=0;j<len;j++)
        {
            int k=theBestGene[j];
            if(pc[k].m == i)
                printf("(%d,%d-%d,%d)",TT[i][k]-pc[k].t, pc[k].i, pc[k].j, TT[i][k]);
        }
        putchar('\n');
    }
    printf("End %d\n", ans);
}
