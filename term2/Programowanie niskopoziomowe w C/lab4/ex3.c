#include <stdio.h>

int main(int argc, char *argv[]) {
    printf("\tReading file %s:\n", argv[1]);
    FILE *sFile, *oFile;
    sFile = fopen(argv[1], "r");
    oFile = fopen(argv[2], "w");

    int sum[20] = {0};
    int noCol = 20;

    char c;
    int prev = 0, i = 0;
    int row = 1;
    while (fscanf(sFile, "%c", &c) != EOF){
        if (c == '\n') { row++; i = 0; continue;} // new row
        if (c != ' ') { // new digit
            sum[i] += prev*10 + c - '0';
            prev = c-'0';
            //printf("-%d",sum[i]);
        }else{ // end of number
            //printf("=\n");
            i++;
            prev = 0;
        }
    }

    fprintf(oFile, "Sum: ");
    for (int o = 0; o < i; o++){
        fprintf(oFile, "%d ", sum[o]);
    }
    fprintf(oFile, "\nAverage: ");
    for (int o = 0; o < i; o++){
        float out = sum[o]*10/row/10.0f;
        fprintf(oFile, "%.1f ", out);
    }

    fclose(sFile);
    fclose(oFile);
    return 0;
}