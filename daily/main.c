
#include <stdio.h>
int main(){
    char a, b, c, temp;
    while(scanf("%c%c%c", &a, &b, &c) != EOF){
        getchar();//不加getchar()函数不正确
        if(a > b){
            temp = a;
            a = b;
            b = temp;
        }
        //执行完这个if语句之后，a<=b
        if(a>=c){
            temp = c;
            c = b;
            b = temp;
            temp = b;
            b = a;
            a = temp;
        }
        //执行完上边两个if语句之后，a已经是最小的了
        if(c < b){
            temp = c;
            c = b;
            b = temp;
        }
        printf("%c %c %c\n", a, b, c);
    }
    return 0;
}
