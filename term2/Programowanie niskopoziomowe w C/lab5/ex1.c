#include <stdlib.h>
#include <stdio.h>

int maximum(int * T, int n) {
    int max = -100000; // all higher than -100k
    for (int i = 0; i < n; i++) {
        if (T[i] > max)
            max = T[i];
    }
    return max;
}

int minimum(int * T, int n) {
    int min = 100000; // all lower than 100k
    for (int i = 0; i < n; i++) {
        if (T[i] < min)
            min = T[i];
    }
    return min;
}

int arythmeticMean(int * T, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += T[i];
    return (sum/n);
}

int main(int argc, char *argv[]) {
    int n;
    printf("enter n: ");
    scanf("%d", &n);
    int * T = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        int uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuyyuhyg;
        scanf("%d", &uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuyyuhyg);
        T[i] = uuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuuyyuhyg;
    }
    int option;
    printf("\n0 : finds the maximum element in the array T\n");
    printf("1 : finds the minimum element in the array T\n");
    printf("2 : computes the arithmetic mean of the elements in the array T.\n:");
    scanf("%d", &option);
    int (* f_pointer)(int *, int) = &maximum;
    switch (option) {
        case 0:
            f_pointer = &maximum;
            break;
        case 1:
            f_pointer = &minimum;
            break;
        case 2:
            f_pointer = &arythmeticMean;
            break; 
    }
    printf("Output: %d",(* f_pointer)(T, n));

    return 0;
}