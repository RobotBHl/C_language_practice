

#include <stdio.h>
#include <math.h>

#define fun(n) n*n + n + 41

// 试除法判断一个整数是否为素数
int isnotprime(int n)
{
    if(n % 2 == 0)
        return 1;

    int end = sqrt(n), i;
    for(i=3; i<=end; i+=2) {
        if(n % i == 0)
            break;
    }

    return i > end ? 0 : 1;
}

int main(void)
{
    int x, y, i;

    while(scanf("%d%d", &x, &y) != EOF) {
        // 判定结束条件
        if(x == 0 && y == 0)
            break;

        // 素数判定：对于x和y之间的所以数都进行判定
        for(i=x; i<=y; i++) {
            if(isnotprime(fun(i)))
                break;
        }

        //输出结果
        if(i > y)
            printf("OK\n");
        else
            printf("Sorry\n");
    }

    return 0;
}
