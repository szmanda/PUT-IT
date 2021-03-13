#include <stdio.h>

int main(){
    int m, n;
    scanf("%d %d", &m, &n);
    float r =(5+4+3+2*(m-n-1))/(2*(m+n+1)-3-4-5);
    printf("%f",r);
    return 0;
}