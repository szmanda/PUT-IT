#include <stdio.h>
#include <math.h>

int main(){
    int n;
    printf("podaj dodatnie, całkowite n: ");
    scanf("%d", &n);
    if (n <= 1) {
        return 0;
    }
    int r = 1;
    for (int i = 1; i < n; i++)
        r *= (pow(n-i, 2) + 1);
    printf("%d", r);
    return 0;
}