#include <stdio.h>
#include <math.h>
int main()
{
int m;
double n,sum;
while(scanf("%lf%d",&n,&m)!=EOF)
{
sum=n;
while(--m)
sum+=n=sqrt(n);
printf("%.2lf\n",sum);
}

}
