#include <stdio.h>

int main(){
    float length, width, height;
    printf("Podaj wymiary skrzynki w cm: ");
    scanf("%f %f %f", &length, &width, &height);
    float volume = (length*width*height)/1000;
    printf("Objętość skrzynki wynosi %0.4f litrów.", volume);
    return 0;
}