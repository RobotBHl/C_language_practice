
#include<stdio.h>
#include<string.h>
int main()
{
      int n,i,k,l;
      char a[50];
      scanf("%d",&n);
            getchar();

            while(n--)
            {
                  gets(a);
                  l=strlen(a);
                  k=0;
                  if((a[0]>='a'&&a[0]<='z')||(a[0]>='A'&&a[0]<='Z')||a[0]=='_')
                              k++;
                  for(i=1;i<l;i++)
                  {

                        if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')||a[i]=='_'||(a[i]>='0'&&a[i]<='9'))
                              k++;
                  }
                  if(k==l)
                        printf("yes\n");
                  else
                        printf("no\n");
            }
 }
