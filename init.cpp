//
// Created by liuren on 18-5-14.
//

#include "evolution.h"
#include <cstring>
#include <cstdlib>
#include <ctime>
void jobshop::init()
{
    int *fa;
    fa=(int *)malloc(len*sizeof(int));
    for (int i = 0; i < len; ++i) {
        fa[i]=i+1;
    }
    for(int k=0;k<ps;k++)
    {
        memcpy(genes[k],fa,len*sizeof(int));
        int t=len;
        srand(time(0));
        while(t--) {
            int i = rand() % len;
            int j = rand() % len;
            if (pc[genes[k][i]].i!=pc[genes[k][j]].i)
            {
                int tmp = genes[k][i];
                genes[k][i] = genes[k][j];
                genes[k][j]=tmp;
            }
        }
    }
}
