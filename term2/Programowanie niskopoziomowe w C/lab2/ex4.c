#include <stdio.h>
#include <math.h>

int main(){
    int n, m;
    double S = 0;
    printf("enter (int) n: ");
    fflush(stdin);
    scanf("%d", &n);
    printf("enter (int) m: ");
    fflush(stdin);
    scanf("%d", &m);
    printf("enter (double) S: ");
    for (int i = 1; i <= n; i++) {
        double I = 1;
        for (int j = 1; j <= m; j++){
            I *= (pow(i,2)+pow(j,2)-1)/
                 (2*i+3*j+4);
        }
        S += I;
    }
    printf("%lf", S);
    return 0;
}