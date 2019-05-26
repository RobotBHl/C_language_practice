
#include<stdio.h>
#include<string.h>
#define MAX 1000000

int map[1005][1005];
int value[1005][1005];
int dis[1005];
int val[1005];
int vis[1005];

void Dijkstra(int start,int n)
{
    int i,j,k,min;
    for(i=1; i<=n; i++)
    {
        dis[i]=map[start][i];
        val[i]=value[start][i];
    }

    dis[start]=0;
    val[start]=0;

    for(i=1; i<=n-1;i++)
    {
        min=MAX;
        k=0;
        for(j=1; j<=n; j++)
        {
            if(!vis[j]&&min>dis[j])
            {
                min=dis[j];
                k=j;
            }
        }
        vis[k]=1;
        if(k==0)
            return;
        for(j=1; j<=n; j++)
        {
            if(dis[j]>dis[k]+map[k][j])
            {
                dis[j]=dis[k]+map[k][j];
                val[j]=val[k]+value[k][j];
            }
            else if(dis[j]==dis[k]+map[k][j]&&val[j]>val[k]+value[k][j])//距离相同就选择最小的花费
            {
                val[j]=val[k]+value[k][j];
            }
        }
    }
    return ;
}

int main()
{
    int n,m;
    int i;
    int s,t;
    while(scanf("%d%d",&n,&m) && n+m)
    {
        int a,b,d,p;
        memset(vis,0,sizeof(vis));
        memset(map,MAX,sizeof(map));
        memset(value,MAX,sizeof(value));
        for(i=0; i<m; i++)
        {
            scanf("%d%d%d%d",&a,&b,&d,&p);
            if(map[a][b]>d)//去重
            {
                map[a][b]=d;//双向图；
                map[b][a]=d;
                value[a][b]=p;
                value[b][a]=p;
            }
        }
        scanf("%d%d",&s,&t);
        Dijkstra(s,n);
        printf("%d %d\n",dis[t],val[t]);
    }
    return 0;
}
