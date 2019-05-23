
#include<stdio.h>
int main()
{
    int n,m,k;
    int a[1000][100];
    double p[100],q[100],s;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,j,z,sum=0;
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%d",&a[i][j]);
        for(i=0;i<n;i++)
        { s=0;
            for(j=0;j<m;j++)
            {
                s=s+a[i][j];
            }
            p[i]=s/m;
            printf("%.2lf",p[i]);
            if(i<n-1) printf(" ");
        }
        printf("\n");
        for(j=0;j<m;j++)
        {s=0;
            for(i=0;i<n;i++)
            {s=s+a[i][j];}
        q[j]=s/n;
        printf("%.2lf",q[j]);
        if(j<m-1)printf(" ");
        }
        printf("\n");
        for(i=0;i<n;i++)
        {z=1;
            for(j=0;j<m;j++)
            {
                if(a[i][j]<q[j])
                {z=0;break;}
            }
            if(z) sum++;
        }
        printf("%d\n\n",sum);
    }
    return 0;
}
