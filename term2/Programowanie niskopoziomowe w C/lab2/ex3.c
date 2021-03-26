#include <stdio.h>
#include <math.h>

int main(){
    int n;
    double S;
    printf("enter (int) n: ");
    fflush(stdin);
    scanf("%d", &n);
    printf("enter (double) S: ");
    fflush(stdin);
    scanf("%lf", &S);
    double sumA = 0;
    double sumB = 0;
    for (int i = 1; i <= n; i++) {
        sumA += pow(i,3)/(pow(i,2)+1);
        sumB += -7/(pow(i,2)+1);
    }
    double a = (S-sumB)/sumA;
    printf("a = %lf;\r\n",a);
    printf("%lf = %lf a + (%lf)",S,sumA,sumB);
    return 0;
}