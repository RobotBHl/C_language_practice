##include<stdio.h>
int main(void)
{
    int n,score[100],i,j,temp;
    float ave;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&score[i]);
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                if(score[i]>score[j])
                {
                    temp=score[i];
                    score[i]=score[j];
                    score[j]=temp;
                }
            }
        for(i=1,ave=0;i<n-1;i++)
            ave+=score[i];
       ave=ave/(n-2);
        printf("%.2f\n",ave);
    }
    return 0;
}½Ó£¡
