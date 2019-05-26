#include<stdio.h>
int main()
{
    int n,m,i,j,a,b,c,u,k,min,sum=0;
    int inf=99999999;
    int dis[10],e[10][10],book[10]={0};
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            if(i==j)
                e[i][j]=0;
            else
                e[i][j]=inf;
        }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        e[a][b]=c;
        e[b][a]=c;
    }

    for(i=1;i<=n;i++)
        dis[i]=e[1][i];
    dis[1]=0;
    book[1]=1;
    for(j=1;j<=n-1;j++)
    {
        min=inf;
        for(i=1;i<=n;i++)
        {
            if(book[i]==0 && dis[i]<min)
            {
                min=dis[i];
                u=i;
            }
        }
        book[u]=1;
        sum+=dis[u];
        for(k=1;k<=n;k++)
        {
            if(book[k]==0 && dis[k]>e[u][k])
                dis[k]=e[u][k];
        }
    }
    printf("%d",sum);
    return 0;
}
