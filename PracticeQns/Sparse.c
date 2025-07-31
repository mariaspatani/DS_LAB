#include <stdio.h>

int main() {
    int sizeA = 0, sizeB = 0;
    int matrixA[5][5], matrixB[5][5];
    int compactA[26][3], compactB[26][3];
    int result[26][3], transposeMatrix[26][3];

    // Input matrix A
    printf("Enter elements of Matrix A (5x5):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matrixA[i][j]);
        }
    }

    // Input matrix B
    printf("Enter elements of Matrix B (5x5):\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            scanf("%d", &matrixB[i][j]);
        }
    }

    // Convert matrixA to compactA
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrixA[i][j] != 0) {
                sizeA++;
            }
        }
    }

    compactA[0][0] = 5;
    compactA[0][1] = 5;
    compactA[0][2] = sizeA;
    int k = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrixA[i][j] != 0) {
                compactA[k][0] = i;
                compactA[k][1] = j;
                compactA[k][2] = matrixA[i][j];
                k++;
            }
        }
    }

    // Convert matrixB to compactB
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrixB[i][j] != 0) {
                sizeB++;
            }
        }
    }

    compactB[0][0] = 5;
    compactB[0][1] = 5;
    compactB[0][2] = sizeB;
    k = 1;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrixB[i][j] != 0) {
                compactB[k][0] = i;
                compactB[k][1] = j;
                compactB[k][2] = matrixB[i][j];
                k++;
            }
        }
    }

    // Display compact matrix A
    printf("Compact matrix of A:\n");
    for (int i = 0; i <= sizeA; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", compactA[i][j]);
        }
        printf("\n");
    }

    // Display compact matrix B
    printf("Compact matrix of B:\n");
    for (int i = 0; i <= sizeB; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", compactB[i][j]);
        }
        printf("\n");
    }

    // Sum of compact matrices
    int i = 1, j = 1;
    int sizeOfResult = 0;
    k = 1;
    result[0][0] = compactA[0][0];
    result[0][1] = compactA[0][1];

    while (i <= sizeA && j <= sizeB) {
        if ((compactA[i][0] < compactB[j][0]) || (compactA[i][0] == compactB[j][0] && compactA[i][1] < compactB[j][1])) {
            result[k][0] = compactA[i][0];
            result[k][1] = compactA[i][1];
            result[k][2] = compactA[i][2];
            i++;
        } else if ((compactA[i][0] > compactB[j][0]) || (compactA[i][0] == compactB[j][0] && compactA[i][1] > compactB[j][1])) {
            result[k][0] = compactB[j][0];
            result[k][1] = compactB[j][1];
            result[k][2] = compactB[j][2];
            j++;
        } else {
            result[k][0] = compactA[i][0];
            result[k][1] = compactA[i][1];
            result[k][2] = compactA[i][2] + compactB[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i <= sizeA) {
        result[k][0] = compactA[i][0];
        result[k][1] = compactA[i][1];
        result[k][2] = compactA[i][2];
        k++;
        i++;
    }

    while (j <= sizeB) {
        result[k][0] = compactB[j][0];
        result[k][1] = compactB[j][1];
        result[k][2] = compactB[j][2];
        k++;
        j++;
    }

    sizeOfResult = k - 1;
    result[0][2] = sizeOfResult;

    // Display sum result
    printf("Sum of compact matrices:\n");
    for (int i = 0; i <= sizeOfResult; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }

    // Transpose of result
    transposeMatrix[0][0] = result[0][1];
    transposeMatrix[0][1] = result[0][0];
    transposeMatrix[0][2] = result[0][2];
    k = 1;
    for (int i = 0; i < result[0][1]; i++) {
        for (int j = 1; j <= result[0][2]; j++) {
            if (result[j][1] == i) {
                transposeMatrix[k][0] = result[j][1];
                transposeMatrix[k][1] = result[j][0];
                transposeMatrix[k][2] = result[j][2];
                k++;
            }
        }
    }

    // Display transpose
    printf("Transpose of resultant matrix:\n");
    for (int i = 0; i <= sizeOfResult; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d\t", transposeMatrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
