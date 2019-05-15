#include<stdio.h>
int dg(int i)
{
    int a[3];
    int t=i;
    a[2]=i%10;
    i=i/10;
    a[1]=i%10;
    i=i/10;
    a[0]=i%10;
    if(a[0]*a[0]*a[0]+a[1]*a[1]*a[1]+a[2]*a[2]*a[2]==t)
        return 1;
    return 0;
}
int main()
{
    int m,n,i,count,j,a[100];
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        j=0;
        count=0;
        for(i=m;i<=n;i++)
        {
            if(dg(i))
            {
                count=1;
                a[j++]=i;
            }
        }
        if(count==0)
            printf("no");
        else
        {
            for(i=0;i<j-1;i++)
                printf("%d ",a[i]);
            printf("%d",a[j-1]);
        }
        printf("\n");

    }
    return 0;
}
