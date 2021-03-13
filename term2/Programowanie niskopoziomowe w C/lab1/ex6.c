#include <stdio.h>

int main(){
    int a, b;
    printf("podaj liczby a b: ");
    scanf("%d %d", &a, &b);
    printf("%d + %d\t%d\n\r", a, b, a+b);
    printf("%d - %d\t%d\n\r", a, b, a-b);
    printf("%d * %d\t%d\n\r", a, b, a*b);
    printf("%d / %d\t%d\n\r", a, b, a/b);
    return 0;
}