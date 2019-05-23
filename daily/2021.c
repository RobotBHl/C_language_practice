#include <stdio.h>
int main()
{
	int n;
	while(~scanf("%d",&n)&&n)
	{
		int t,x=0;
		while(n--)
		{
			scanf("%d",&t);
			if(t>=100) x+=t/100,t%=100;
			if(t>=50) x+=t/50,t%=50;
			if(t>=10) x+=t/10,t%=10;
			if(t>=5) x+=t/5,t%=5;
			if(t>=2) x+=t/2,t%=2;
			if(t==1) x+=t;
		}
		printf("%d\n",x);
	}
	return 0;
}
