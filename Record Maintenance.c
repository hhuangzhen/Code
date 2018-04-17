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
  printf("100条空记录创建完毕\n\n");
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
    printf("请输入商品信息[ID为-1代表输入结束]\n");
    printf("商品ID:");
    int t;
    scanf("%d", &t);
    getchar();
    if(t==-1) break;
    a[t].id=t;
    printf("商品名:");
    gets(a[t].name);
    printf("数量:");
    scanf("%d", &a[t].num);
    printf("价格:");
    scanf("%lf", &a[t].price);

    id[++cnt]=t;
  }
  rewind(f);
  fwrite(a,sizeof(cd),100,f);

  printf("商品信息输入结束\n商品信息如下\n");
  printf("记录号（商品ID）\t商品名\t\t数量\t价格\n");

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
    printf("请输入待更新商品ID[ID为-1代表结束更新]:\n");
    int t;
    scanf("%d", &t);
    getchar();
    if(t==-1) break;
    if(strlen(a[t].name)==0)  printf("对不起，记录号为%d的商品不存在，无法更新\n", t);
    else
    {
      printf("原商品信息如下\n");
      printf("记录号（商品ID）\t商品名\t\t数量\t价格\n");
      printf("%-17d\t%-16s%-5d\t%.2lf\n", a[t].id, a[t].name, a[t].num, a[t].price);
      printf("请输入更新信息[如某项不更新请直接按回车键]:\n");
      printf("商品名:");
      int j=0;
      int flag=0;
      double temp;
      char ch;
      while((ch=getchar())!='\n') flag=1,a[t].name[j++]=ch;
      if(flag==1) a[t].name[j]='\0';
      printf("数量:");
      if((temp=read())!=-1) a[t].num=(int)temp;
      printf("价格:");
      if((temp=read())!=-1) a[t].price=temp;
      rewind(f);
      fseek(f,t*sizeof(cd),0);
      fwrite(&a[t],sizeof(cd),1,f);
      printf("更新后商品信息如下:\n");
      printf("记录号（商品ID）\t商品名\t\t数量\t价格\n");
      printf("%-17d\t%-16s%-5d\t%.2lf\n", a[t].id, a[t].name, a[t].num, a[t].price);
    }
  }
  printf("更新工作结束\n\n");
}

void output(FILE *f)
{
  cd a[100];
  rewind(f);
  fread(a,sizeof(cd),100,f);
  printf("商品信息如下:\n");
  printf("记录号（商品ID）\t商品名\t\t数量\t价格\n");
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
    printf("请输入待删除商品ID[记录号为-1代表结束删除]:\n");
    int t;
    scanf("%d", &t);
    getchar();
    if(t==-1) break;
    if(strlen(a[t].name)==0) printf("对不起，记录号为%d的商品不存在，无法进行删除操作\n", t);
    else
    {
      printf("该商品信息如下:\n");
      printf("记录号（商品ID）\t商品名\t\t数量\t价格\n");
      printf("%-17d\t%-16s%-5d\t%.2lf\n", a[t].id, a[t].name, a[t].num, a[t].price);
      printf("是否确实删除(确认按Y，取消按N)？\n");
      if(getchar()=='N') printf("您选择不删除记录号为%d的商品\n", t);
      else
      {
        memset(a[t].name,0,sizeof(a[t].name));
        a[t].num=0;
        a[t].price=0;
        rewind(f);
        fseek(f,t*sizeof(cd),0);
        fwrite(&a[t],sizeof(cd),1,f);
        printf("记录号为%d的商品成功删除\n", t);
        output(f);
      }
    }
  }
  printf("删除工作结束\n\n");
}

int main(int argc, char const *argv[]) {
  FILE *f = fopen("commodity.dat","rb+");
  while(1)
  {
    printf("请输入您的选择\n");
    printf("1--创建一个100条空记录的文件\n2--输入商品信息\n3--更新商品记录\n4--删除商品记录\n5--输出全部商品记录\n6--退出程序\n");
    printf("[选择]");
    int q;
    scanf("%d", &q);
    if(q==1) init(f);
    if(q==2) input(f);
    if(q==3) updata(f);
    if(q==4) _delete(f);
    if(q==5) output(f);
    if(q==6)
    {
      printf("程序运行结束，再见！\n\n");
      break;
    }
  }
  fclose(f);
  return 0;
}
