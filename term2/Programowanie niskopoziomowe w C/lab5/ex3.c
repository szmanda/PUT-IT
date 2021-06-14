#include <stdio.h>

double maximum(double * T, int n) {
    double max = -100000; // all higher than -100k
    for (int i = 0; i < n; i++) {
        if (T[i] > max)
            max = T[i];
    }
    return max;
}

double minimum(double * T, int n) {
    double min = 100000; // all lower than 100k
    for (int i = 0; i < n; i++) {
        if (T[i] < min)
            min = T[i];
    }
    return min;
}

double arythmeticMean(double * T, int n) {
    double sum = 0;
    for (int i = 0; i < n; i++)
        sum += T[i];

    return (sum/n);
}

int main(int argc, char *argv[]) {
    printf("\tReading file: Calculations.txt\n");
    FILE *iFile, *oFile;
    iFile = fopen("Calculations.txt", "r");
    oFile = fopen("Results.txt", "w");
    
    double (* f_pointer[3])(double *, int) = {
        &arythmeticMean,
        &maximum,
        &minimum
    };

    int series;
    double measurement[4];
    int operationCode;
    while (fscanf(iFile, "%d", &series) != EOF){
        for (int i = 0; i < 4; i++)
            fscanf(iFile, "%lf\n", &measurement[i]);
        fscanf(iFile, "%d", &operationCode);
        
        double result = (* f_pointer[operationCode])(measurement, 4);
        //printf("%d\n", series);
        fprintf(oFile, "%d\n%lf\n%d\n", series, result, operationCode);
    }


    fclose(iFile);
    fclose(oFile);
    return 0;
}