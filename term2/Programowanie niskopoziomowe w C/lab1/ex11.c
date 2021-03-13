#include <stdio.h>

int main(){
    float a, b;
    scanf("%f %f", &a, &b);
    float r = 4*a+(2*((a-b-1)/a*a+b*b+1));
    printf("%f",r);
    return 0;
}