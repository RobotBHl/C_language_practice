#include<stdio.h>
struct edge
{
    int x;
    int y;
    int w;
};
struct edge e[10],t,temp;
int n,m,sum=0,count=0,f[10]={0};
void quicksort(int left,int right)
{
    int i,j;
    if(left>right)
        return;
    i=left;
    j=right;
    t=e[left];
    while(i!=j)
    {
        while(e[j].w>=t.w && i<j)
            j--;
        while(e[i].w<=t.w && i<j)
            i++;
        if(i<j)
        {
            temp=e[i];
            e[i]=e[j];
            e[j]=temp;
        }
    }
    e[left]=e[i];
    e[i]=t;
    quicksort(left,i-1);
    quicksort(i+1,right);
    return;
}
int getf(int v)
{
    if(f[v]==v)
        return v;
    else
    {
        f[v]=getf(f[v]);
        return f[v];
    }
}
int merge(int x,int y)
{
    int t1,t2;
    t1=getf(x);
    t2=getf(y);
    if(t1!=t2)
    {
        f[t2]=t1;
        return 1;
    }
    return 0;
}
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
        scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
    for(i=1;i<=n;i++)
        f[i]=i;
    quicksort(1,m);
    for(i=1;i<=m;i++)
    {
        if(merge(e[i].x,e[i].y))
        {
            count++;
            sum+=e[i].w;
        }
        if(count==n-1)
            break;
    }
    printf("%d",sum);
    return 0;
}
