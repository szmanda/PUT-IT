#include <stdio.h>

int digits(int number){
    int sum = (number>10) ? digits(number/10) : 0;
    sum += number%10;
    return sum;
}

int main(){
    int input;
    scanf("%d", &input);
    printf("%d",digits(input));
    return 0;
}