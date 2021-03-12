#include <stdio.h>

int main(){
    int a;
    char c;
    scanf("%d", &a);
    // czyszczenie bufora, aby jako input nie został uznany poprzedni 
    fflush(stdin);
    scanf("%c",&c);
    printf("Liczba = %d, Znak = %c", a, c);
    return 0;
}