#include <stdlib.h>
#include <stdio.h>

void calculateP(int **A, int **B, int **P, int row, int col) {
    for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
        P[i][j] = (A[i][j] > B[i][j]) ? 1 : 0; 
    }
}

void calculateR(int **A, int **B, int **R, int row, int col) {
    for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++) {
        R[i][j] = (A[i][j] == B[i][j]) ? 1 : 0; 
    }
}

void printMatrix(int **M, int row, int col, char label) {
    printf("--------%c-------",label);
    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++) {
        printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    printf("----------------");
}


int main(int argc, char *argv[]) {
    
    int n = 15, m = 15;
    printf("Give no. rows: ");
    fflush(stdin);
    scanf("%d", &n); 
    printf("Give no. columns: ");
    fflush(stdin);
    scanf("%d", &m);
    
    int size = sizeof(int *) * n + sizeof(int) * n * m;
    int **A = (int **)malloc(size);
    int **B = (int **)malloc(size);
    int **P = (int **)malloc(size);
    int **R = (int **)malloc(size);
    
    printf("matrix A:\n");
    for (int i = 0; i < n; i++){
        printf("enter next row: ");
        fflush(stdin);
        for (int j = 0; j < m; j++) {
            fflush(stdin);
            scanf("%d", &A[i][j]);
        }
    }
    printf("matrix B:\n");
    for (int i = 0; i < n; i++){
        printf("enter next row: ");
        fflush(stdin);
        for (int j = 0; j < m; j++) {
            fflush(stdin);
            scanf("%d", &B[i][j]);
        }
    }
    
    calculateP(A, B, P, n, m);
    calculateR(A, B, R, n, m);
    printMatrix(A, n, m, 'A');
    printMatrix(B, n, m, 'B');
    printMatrix(R, n, m, 'P');
    printMatrix(P, n, m, 'R');

    return 0;
}