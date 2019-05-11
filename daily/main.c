#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct
{
int vertex[MAXSIZE];
int edgs[MAXSIZE][MAXSIZE];
}MGraph;

void creatgraph(MGraph* p,int n,int e)//n为节点数，e为边数
{
int i,j,k,x;
printf(“input vertex \n”);
for(i=0;i<n;i++)//设置化节点信息
{
scanf("%d",&x);
p->vertex[i]=x;
}
for(j=0;j<n;j++)//初始化边关系
for(i=0;i<n;i++)
p->edgs[i][j]=0;

for(k=1;k<=e;k++)
{
    printf("input edge of(i,j)\n");
    scanf("%d%d",&i,&j);
    p->edgs[i][j]=1;
    p->edgs[j][i]=1;
}
for(k=1;k<=e;k++)
{
    printf("input edge of(i,j)\n");
    scanf("%d%d",&i,&j);
    p->edgs[i][j]=1;
    p->edgs[j][i]=1;
}

int main()
{
int i,j;
MGraph M,*p=&M;
creatgraph(p,4,4);
for(i=0;i<4;i++)
{
printf("\n");
for(j=0;j<4;j++)
printf("%4d",M.edgs[i][j]);
}
return 0;
}
