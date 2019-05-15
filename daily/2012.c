

#include <stdio.h>
#include <math.h>

#define fun(n) n*n + n + 41

// �Գ����ж�һ�������Ƿ�Ϊ����
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
        // �ж���������
        if(x == 0 && y == 0)
            break;

        // �����ж�������x��y֮����������������ж�
        for(i=x; i<=y; i++) {
            if(isnotprime(fun(i)))
                break;
        }

        //������
        if(i > y)
            printf("OK\n");
        else
            printf("Sorry\n");
    }

    return 0;
}
