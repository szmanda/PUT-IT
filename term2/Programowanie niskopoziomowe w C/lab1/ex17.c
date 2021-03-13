#include <stdio.h>

int main(){
    char * input = (char *)malloc(100 * sizeof(char));
    scanf("%s", input);
    int count[28] = {0};
    for (int i = 0; i < 100; i++) {
        count[(input[i]-'a')]++;
    }
    for (int i = 0; i < 28; i++) {
        printf("%c: %d\n", i+'a', count[i]);
    }
    return 0;
}