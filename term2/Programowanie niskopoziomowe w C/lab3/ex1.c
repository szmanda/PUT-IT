#include <stdio.h>

void inputChars(){
    char c = getchar();
    if (c!=10)
        inputChars();
    printf("%c",c);
}

int main(){
    inputChars();
    return 0;
}