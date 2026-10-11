#include <stdio.h>

#define MAX 10

void readMatrix(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void printMatrix(int mat[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtractMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void multiplyMatrices(int A[MAX][MAX], int B[MAX][MAX], int C[MAX][MAX], int r1, int c1, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void transposeMatrix(int A[MAX][MAX], int T[MAX][MAX], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            T[j][i] = A[i][j];
        }
    }
}

int main() {
    int A[MAX][MAX], B[MAX][MAX], Res[MAX][MAX];
    int r1, c1, r2, c2;

    printf("Enter rows and columns for Matrix A: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter elements of Matrix A:\n");
    readMatrix(A, r1, c1);

    printf("Enter rows and columns for Matrix B: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter elements of Matrix B:\n");
    readMatrix(B, r2, c2);

    // Addition & Subtraction
    if (r1 == r2 && c1 == c2) {
        addMatrices(A, B, Res, r1, c1);
        printf("\n--- Addition (A + B) ---\n");
        printMatrix(Res, r1, c1);

        subtractMatrices(A, B, Res, r1, c1);
        printf("\n--- Subtraction (A - B) ---\n");
        printMatrix(Res, r1, c1);
    } else {
        printf("\n[Addition/Subtraction] Not possible (Dimensions mismatch)\n");
    }

    // Multiplication
    if (c1 == r2) {
        multiplyMatrices(A, B, Res, r1, c1, c2);
        printf("\n--- Multiplication (A * B) ---\n");
        printMatrix(Res, r1, c2);
    } else {
        printf("\n[Multiplication] Not possible (Columns of A != Rows of B)\n");
    }

    // Transpose of Matrix A
    transposeMatrix(A, Res, r1, c1);
    printf("\n--- Transpose of Matrix A ---\n");
    printMatrix(Res, c1, r1);

    return 0;
}
