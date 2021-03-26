#include <stdio.h>
#include <math.h>

int main(){
    int a;
    printf("enter (int) a: ");
    fflush(stdin);
    scanf("%d",&a);
    for (int i = 2; i < a; i++){
        int sum = 1;
        for (int j = 2; j < i; j++){
            if (i%j == 0) {
                sum += j;
                if (sum > i) break;
            }
        }
        if (sum == i) printf("%d\n\r", sum);
    }
}