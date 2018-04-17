#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct{
  int id;
  char name[40];
  int num;
  double price;
}cd;

void init(FILE *f)
{
  cd a[100];
  memset(a,0,sizeof(a));
  rewind(f);
  fwrite(a,sizeof(cd),100,f);
  printf("100���ռ�¼�������\n\n");
}

void input(FILE *f)
{
  cd a[100];
  int id[100];
  int cnt=-1;
  memset(a,0,sizeof(a));
  rewind(f);
  fread(a,sizeof(cd),100,f);
  while(1)
  {
    printf("��������Ʒ��Ϣ[IDΪ-1�����������]\n");
    printf("��ƷID:");
    int t;
    scanf("%d", &t);
    getchar();
    if(t==-1) break;
    a[t].id=t;
    printf("��Ʒ��:");
    gets(a[t].name);
    printf("����:");
    scanf("%d", &a[t].num);
    printf("�۸�:");
    scanf("%lf", &a[t].price);

    id[++cnt]=t;
  }
  rewind(f);
  fwrite(a,sizeof(cd),100,f);

  printf("��Ʒ��Ϣ�������\n��Ʒ��Ϣ����\n");
  printf("��¼�ţ���ƷID��\t��Ʒ��\t\t����\t�۸�\n");

  for(int i=0;i<=cnt;i++)
    printf("%-17d\t%-16s%-5d\t%.2lf\n", id[i], a[id[i]].name, a[id[i]].num, a[id[i]].price);
  putchar('\n');
}

double read()
{
  char ch;
  double t=0;
  double r=1;
  int flag=0;
  while((ch=getchar())!='\n')
  {
    flag=1;
    if(isdigit(ch))
    {
      if(r==1)  t=t*10+(ch-'0');
      else
      {
        t+=(ch-'0')*r;
        r*=0.1;
      }
    }
    else if(ch=='.')  r=0.1;
  }
  if(flag) return t;
  return -1;
}

void updata(FILE *f)
{
  cd a[100];
  rewind(f);
  fread(a,sizeof(cd),100,f);

  while(1)
  {
    printf("�������������ƷID[IDΪ-1�����������]:\n");
    int t;
    scanf("%d", &t);
    getchar();
    if(t==-1) break;
    if(strlen(a[t].name)==0)  printf("�Բ��𣬼�¼��Ϊ%d����Ʒ�����ڣ��޷�����\n", t);
    else
    {
      printf("ԭ��Ʒ��Ϣ����\n");
      printf("��¼�ţ���ƷID��\t��Ʒ��\t\t����\t�۸�\n");
      printf("%-17d\t%-16s%-5d\t%.2lf\n", a[t].id, a[t].name, a[t].num, a[t].price);
      printf("�����������Ϣ[��ĳ�������ֱ�Ӱ��س���]:\n");
      printf("��Ʒ��:");
      int j=0;
      int flag=0;
      double temp;
      char ch;
      while((ch=getchar())!='\n') flag=1,a[t].name[j++]=ch;
      if(flag==1) a[t].name[j]='\0';
      printf("����:");
      if((temp=read())!=-1) a[t].num=(int)temp;
      printf("�۸�:");
      if((temp=read())!=-1) a[t].price=temp;
      rewind(f);
      fseek(f,t*sizeof(cd),0);
      fwrite(&a[t],sizeof(cd),1,f);
      printf("���º���Ʒ��Ϣ����:\n");
      printf("��¼�ţ���ƷID��\t��Ʒ��\t\t����\t�۸�\n");
      printf("%-17d\t%-16s%-5d\t%.2lf\n", a[t].id, a[t].name, a[t].num, a[t].price);
    }
  }
  printf("���¹�������\n\n");
}

void output(FILE *f)
{
  cd a[100];
  rewind(f);
  fread(a,sizeof(cd),100,f);
  printf("��Ʒ��Ϣ����:\n");
  printf("��¼�ţ���ƷID��\t��Ʒ��\t\t����\t�۸�\n");
  for(int i=0;i<100;i++)
  {
    if(strlen(a[i].name)!=0)
      printf("%-17d\t%-16s%-5d\t%.2lf\n", a[i].id, a[i].name, a[i].num, a[i].price);
  }
  putchar('\n');
}

void _delete(FILE *f)
{
  cd a[100];
  rewind(f);
  fread(a,sizeof(cd),100,f);
  while(1)
  {
    printf("�������ɾ����ƷID[��¼��Ϊ-1�������ɾ��]:\n");
    int t;
    scanf("%d", &t);
    getchar();
    if(t==-1) break;
    if(strlen(a[t].name)==0) printf("�Բ��𣬼�¼��Ϊ%d����Ʒ�����ڣ��޷�����ɾ������\n", t);
    else
    {
      printf("����Ʒ��Ϣ����:\n");
      printf("��¼�ţ���ƷID��\t��Ʒ��\t\t����\t�۸�\n");
      printf("%-17d\t%-16s%-5d\t%.2lf\n", a[t].id, a[t].name, a[t].num, a[t].price);
      printf("�Ƿ�ȷʵɾ��(ȷ�ϰ�Y��ȡ����N)��\n");
      if(getchar()=='N') printf("��ѡ��ɾ����¼��Ϊ%d����Ʒ\n", t);
      else
      {
        memset(a[t].name,0,sizeof(a[t].name));
        a[t].num=0;
        a[t].price=0;
        rewind(f);
        fseek(f,t*sizeof(cd),0);
        fwrite(&a[t],sizeof(cd),1,f);
        printf("��¼��Ϊ%d����Ʒ�ɹ�ɾ��\n", t);
        output(f);
      }
    }
  }
  printf("ɾ����������\n\n");
}

int main(int argc, char const *argv[]) {
  FILE *f = fopen("commodity.dat","rb+");
  while(1)
  {
    printf("����������ѡ��\n");
    printf("1--����һ��100���ռ�¼���ļ�\n2--������Ʒ��Ϣ\n3--������Ʒ��¼\n4--ɾ����Ʒ��¼\n5--���ȫ����Ʒ��¼\n6--�˳�����\n");
    printf("[ѡ��]");
    int q;
    scanf("%d", &q);
    if(q==1) init(f);
    if(q==2) input(f);
    if(q==3) updata(f);
    if(q==4) _delete(f);
    if(q==5) output(f);
    if(q==6)
    {
      printf("�������н������ټ���\n\n");
      break;
    }
  }
  fclose(f);
  return 0;
}
