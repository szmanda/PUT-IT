#include <stdio.h>
#include <math.h>

int sum(int a) {
    int sum = 1;
    for (int j = 2; j <= a/2; j++){
        if (a%j == 0) {sum += j;}
    }
    return sum;
}

int main(){
    int a;
    printf("enter (int) a: ");
    fflush(stdin);
    scanf("%d",&a);
    for (int i = 2; i <= a; i++){
        int s = sum(i);
        if (s>1 && s != i && sum(s) == i) 
        printf("%d;%d\n\r", i, s);
    }
}