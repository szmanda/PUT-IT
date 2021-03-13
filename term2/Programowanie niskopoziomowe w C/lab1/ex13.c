#include <stdio.h>
#include <math.h>

int main(){
    double x;
    scanf("%f", &x);
    float r =
        sqrt(
            (pow(sin(pow(x, 3)), 2) + 1.25) /
            (pow(cos(pow(x, 2)), 3) + 1.25)
        )/
        (log(pow(tan(x+2), 2)) + 2.5)
    ;
    printf("%f",r);
    return 0;
}