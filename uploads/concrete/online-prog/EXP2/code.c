#include <stdio.h>

#define MAX 100

// Simple Transpose algorithm following exact pseudocode
void Transpose(int A[MAX][3], int B[MAX][3]) {
    int m = A[0][0];
    int n = A[0][1];
    int t = A[0][2];

    B[0][0] = n;
    B[0][1] = m;
    B[0][2] = t;

    if (t <= 0) return; // check for zero matrix

    int q = 1; // position of next term in B
    for (int col = 0; col < n; col++) {
        for (int p = 1; p <= t; p++) {
            if (A[p][1] == col) { // correct column
                B[q][0] = A[p][1];
                B[q][1] = A[p][0];
                B[q][2] = A[p][2];
                q = q + 1;
            }
        }
    }
}

// Fast Transpose algorithm following exact pseudocode tokens
void FAST_TRANSPOSE(int A[MAX][3], int B[MAX][3]) {
    int S[MAX], T[MAX];
    int m = A[0][0];
    int n = A[0][1];
    int t = A[0][2];

    B[0][0] = n;
    B[0][1] = m;
    B[0][2] = t;

    if (t <= 0) return; // check for zero matrix

    for (int i = 0; i < n; i++) {
        S[i] = 0;
    }

    // S(k) is the number of elements in row k of B
    for (int i = 1; i <= t; i++) {
        S[A[i][1]]++;
    }

    T[0] = 1; // T(i) is the starting position of row i in B
    for (int i = 1; i < n; i++) {
        T[i] = T[i - 1] + S[i - 1];
    }

    for (int i = 1; i <= t; i++) {
        int j = A[i][1];
        B[T[j]][0] = A[i][1];
        B[T[j]][1] = A[i][0];
        B[T[j]][2] = A[i][2];
        T[j] = T[j] + 1; // increase position for row j
    }
}
//EXTRA QUESTIONS:

// Addition algorithm following exact pseudocode tokens
void Addition(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        printf("Matrix dimensions do not match!\n");
        return;
    }

    int t1 = a[0][2];
    int t2 = b[0][2];

    if (t1 == 0 && t2 == 0) return;

    c[0][0] = a[0][0];
    c[0][1] = a[0][1];

    int i = 1, j = 1, k = 1;

    while (i <= t1 && j <= t2) {
        // Case A: row position matched
        if (a[i][0] == b[j][0]) {
            // Case 1: col position matched
            if (a[i][1] == b[j][1]) {
                int temp = a[i][2] + b[j][2];
                if (temp != 0) {
                    c[k][0] = a[i][0];
                    c[k][1] = a[i][1];
                    c[k][2] = temp;
                    k = k + 1;
                }
                i = i + 1;
                j = j + 1;
            }
            // Case 2: col position a < b
            else if (a[i][1] < b[j][1]) {
                c[k][0] = a[i][0];
                c[k][1] = a[i][1];
                c[k][2] = a[i][2];
                k = k + 1;
                i = i + 1;
            }
            // Case 3: col position a > b
            else {
                c[k][0] = b[j][0];
                c[k][1] = b[j][1];
                c[k][2] = b[j][2];
                k = k + 1;
                j = j + 1;
            }
        }
        // Case B: row position a < b
        else if (a[i][0] < b[j][0]) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            k = k + 1;
            i = i + 1;
        }
        // Case C: row position a > b
        else {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            k = k + 1;
            j = j + 1;
        }
    }

    while (i <= t1) {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++;
        k++;
    }

    while (j <= t2) {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++;
        k++;
    }

    c[0][2] = k - 1;
}

void printSparse(int M[MAX][3]) {
    printf("Row\tCol\tVal\n");
    printf("-------------------\n");
    for (int i = 0; i <= M[0][2]; i++) {
        printf("%d\t%d\t%d\n", M[i][0], M[i][1], M[i][2]);
    }
}

int main() {
    int A[MAX][3], B[MAX][3], C[MAX][3], B_fast[MAX][3];

    printf("Enter rows, cols, non-zero terms for Matrix A: ");
    scanf("%d %d %d", &A[0][0], &A[0][1], &A[0][2]);

    printf("Enter triple (row col val) for each term in A:\n");
    for (int i = 1; i <= A[0][2]; i++) {
        scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);
    }

    printf("\n--- Original Matrix A ---\n");
    printSparse(A);

    // Simple Transpose
    Transpose(A, B);
    printf("\n--- Simple Transpose (B) ---\n");
    printSparse(B);

    // Fast Transpose
    FAST_TRANSPOSE(A, B_fast);
    printf("\n--- Fast Transpose (B) ---\n");
    printSparse(B_fast);

    return 0;
}
