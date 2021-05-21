#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("\tReading file %s:\n", argv[1]);
    FILE *mFile;
    mFile = fopen(argv[1], "r");
    
    int c;
    unsigned int count[256] = {0}; 
    while ((c = fgetc(mFile)) != EOF){
        printf("%c",c);
        count[c]++;
    }
    for (int i = 0; i < 256; i++)
        if (count[i]>0)
            printf("%c: %d\n", i, count[i]);


    fclose(mFile);
    return 0;
}