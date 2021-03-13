#include <stdio.h>
#include <math.h>

int main(){
    double x, y;
    scanf("%f %f", &x, &y);
    float r =
        (
            (
                (4 * sin(x + 12.5)) -
                pow(y, 3)*(cos(x*y)*(5*x+2*y-1))
            )/
            (pow(x, 2) + pow(y, 2) + 1)
        )/
        (
            (
                log(10 * x + 2) -
                log(10 * y - 2)
            )/
            sqrt(pow(x, 4) + pow(y, 4) + 1)
        );
    printf("%f",r);
    return 0;
}