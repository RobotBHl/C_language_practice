
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int m,n,i,j,max,p,q,t;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        max=0;p=0;q=0;
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
            {
                scanf("%d",&t);
                if(abs(t)>abs(max))
                {p=i;q=j;max=t;}
            }
        printf("%d %d %d\n",p,q,max);
    }
    return 0;
}
