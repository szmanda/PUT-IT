#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    time_t t;
    srand(time(&t));
    int goal = rand() % 10;
    int guess;
    do {
        printf("Guess the number 0-9: ");
        scanf("%d", &guess);
        fflush(stdin);
    } while(guess != goal);
    printf("You've got it!");
    return 0;
}