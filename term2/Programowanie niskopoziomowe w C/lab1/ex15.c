#include <stdio.h>
#include <math.h>

int main(){
    float a, b;
    printf("podaj liczby x y: ");
    scanf("%f", &a);
    scanf("%f", &b);
    int x, y;
    if ((a <= 5) || (b - 3 <=0)) {
        printf("Brak rozwiązania");
        return 0;
    }
    float r = (log(x-5)+1)/sqrt(y-3);
    printf("%f", r);
    return 0;
}