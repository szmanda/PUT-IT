#include <stdio.h>

int main(){
    int n = 5;
    for (int i = 0; i < n; i++){
        for (int j = n-i; j > 1; j--){
            printf(" ");
        }
        printf("X");
        for (int j = 0; j < i; j++){
            printf("XX");
        }
        printf("\n\r");
    }
    return 0;
}