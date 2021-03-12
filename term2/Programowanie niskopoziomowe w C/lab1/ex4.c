#include <stdio.h>

int main(){
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    printf("Wartość wyrażenia %d+%d-%d wynosi %d", x, y, z, x+y-z);
    return 0;
}