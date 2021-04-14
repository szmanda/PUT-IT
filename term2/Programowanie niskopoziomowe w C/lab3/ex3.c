#include <stdio.h>
#include <math.h>

int automorphic(int a, int b) {
    if (a>b)
        return 0;
    int p = 10;
    while (a/p != 0) p*=10;
    if ((a*a) % p == a)
        printf("%d\n\r",a);
    automorphic(a+1, b);
}

int main(){
    int a, b;
    printf("podaj <a,b>: ");
    scanf("%d,%d", &a, &b);
    automorphic(a, b);
    return 0;
}