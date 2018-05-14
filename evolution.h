//
// Created by liuren on 18-5-14.
//
#ifndef JSP_EVOLUTION_H
#define JSP_EVOLUTION_H
//交叉概率，变异概率，种群数量，适值函数的两个参数
const int cr = 0.9;
const int mr = 0.1;
const int ps = 20;
const double r1=1;
const double r2=-0.5;

struct process{
    int m,t,i,j;  //分别表示对应机器，所需时间,对应工件，在对应工件中的相对工序
};

class jobshop
{
private:
    int n,m,len;               //工件数，机器数，工序数
    int ans;                   //最小完成时间
    int TMJ[15][15*15],TT[15][15*15];        //解码矩阵
    process pc[15*15];         //工序数组
    int genes[51][15*15];     //基因组，下标从0开始
    int theBestGene[15];      //最优基因
    int  startpro[15];         //每个工件开始的工序号

public:
    jobshop(int,int);          //构造函数
    int decode(int *);    //解码
    void lsort(int *);
    void input();     //输入
    void init();      //初始化种群基因组
    void select(double *);    //
    void crossover(); //交叉
    void mutate();    //变异
    void output();    //输出
    void test();      //测试
};

#endif //JSP_EVOLUTION_H
