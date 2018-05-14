//
// Created by liuren on 18-5-14.
//

#include "evolution.h"
#include <cstring>

void jobshop::test()
{
    int temp[9];
    for(int i=0;i<9;i++)
        temp[i]=i+1;
    memcpy(theBestGene,temp,9*sizeof(int));
    output();
}
