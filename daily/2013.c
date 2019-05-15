
#include <stdio.h>

int peach(int n) {
    if(n == 1)
        return 1;
    else {
        long res = 1L;
        while(--n)
            res = 2 * (res + 1);
        return res;
    }
}

int main(void)
{
    int n;

    while(scanf("%d", &n) != EOF)
        printf("%d\n", peach(n));

    return 0;
}
