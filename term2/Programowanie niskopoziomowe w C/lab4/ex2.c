#include <stdio.h>

void asterixToNumber(char name[]){
    printf("Asterix to number conversion starting\n");
    FILE *sFile, *oFile;
    sFile = fopen(name, "r");
    oFile = fopen("converted.txt","w");
    printf("\tReading file %s:\n", name);

    int index [10] = {0};
    int lastIndex = -1;
    char word [128];
    while (fscanf(sFile, "%s\n", word) != EOF){
        int c = 0;
        while (word[c]=='*') c++;

        if (word[0]=='*') fprintf(oFile, "\n");

        if (c>lastIndex) index[lastIndex] -= 1;
        for (int i = lastIndex+1; i<10; i++) index[i] = 0;

        for (int i=2; i<=c; i++) fprintf(oFile, "  ");
        for (int i=1; i<=c; i++) {
            fprintf(oFile,"%d.",(index[i]+1));
            if (i==c){
                //printf("ttt");
                index[c] += 1;
                lastIndex = c;
            }
        }
        if (!c) fprintf(oFile," %s",word);
    }
    fclose(sFile);
    fclose(oFile);
}

void numberToAsterix(char name[]){
    printf("Number to asterix conversion starting\n");
    FILE *sFile, *oFile;
    sFile = fopen(name, "r");
    oFile = fopen("converted.txt","w");
    printf("\tReading file %s:\n", name);

    char word [128];
    while (fscanf(sFile, "%s\n", word) != EOF){
        int c = 0;
        while (word[2*c+1]=='.') c++;
        if (c==0) {
            fprintf(oFile,"%s", word);
        }
        else {
            fprintf(oFile,"\n");
            for (int i=0; i<c; i++)
                fprintf(oFile,"*");
        }
        fprintf(oFile," ");
    }
    fclose(sFile);
    fclose(oFile);
}

int main(int argc, char *argv[]) {
    
    if (argv[2][0]=='A')
        asterixToNumber(argv[1]);
    else if (argv[2][0]=='1')
        numberToAsterix(argv[1]);
    return 0;

}