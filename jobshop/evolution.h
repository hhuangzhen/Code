#ifndef EVOLUTION_H
#define EVOLUTION_H
//������ʣ�������ʣ���Ⱥ��������ֵ��������������
const int cr = 0.9;
const int mr = 0.1;
const int ps = 20;
const double r1=1;
const double r2=-0.5;

struct process{
    int m,t,i,j;  //�ֱ��ʾ��Ӧ����������ʱ��,��Ӧ�������ڶ�Ӧ�����е���Թ���
};

class jobshop
{
private:
    int n,m,len;               //����������������������
    int ans;                   //��С���ʱ��
    int TMJ[15][15*15],TT[15][15*15];        //�������
    process pc[15*15];         //��������
    char genes[51][15*15];     //�����飬�±��0��ʼ
    char theBestGene[15];      //���Ż���

public:
    jobshop(int,int);          //���캯��
    int decode(char *);    //����
    void lsort(char *);
    void input();     //����
    void init();      //��ʼ����Ⱥ������
    void select(double *);    //
    void crossover(); //����
    void mutate();    //����
    void output();    //���
    void test();      //����
};

#endif // EVOLUTION_H
