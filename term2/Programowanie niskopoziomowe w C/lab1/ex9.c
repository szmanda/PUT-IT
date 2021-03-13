#include <stdio.h>

int main(){
    float p, q;
    printf("podaj liczby przeczywiste p q: ");
    scanf("%0.4f %0.4f", &p, &q);
    printf("%0.4f + %0.4f\t%0.4f\n\r", p, q, p+q);
    printf("%0.4f - %0.4f\t%0.4f\n\r", p, q, p-q);
    printf("%0.4f * %0.4f\t%0.4f\n\r", p, q, p*q);
    printf("%0.4f / %0.4f\t%0.4f\n\r", p, q, p/q);
    return 0;
}