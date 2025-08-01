#include <stdio.h>

#define MAX 100

// Function to input a matrix from the user
void inputMatrix(int matrix[MAX][MAX], int rows, int cols) {
    printf("Enter elements of %d×%d matrix:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Convert matrix to compact form, return non-zero count
int toCompact(int rows, int cols, int matrix[MAX][MAX], int compact[MAX][3]) {
    int size = 0;
    // Count non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0)
                size++;
        }
    }

    // First row contains metadata
    compact[0][0] = rows;
    compact[0][1] = cols;
    compact[0][2] = size;

    int k = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                compact[k][0] = i;
                compact[k][1] = j;
                compact[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    return size;
}

// Display a compact matrix
void displayCompact(int compact[MAX][3], int size) {
    printf("Row  Col  Val\n");
    for (int i = 0; i <= size; i++) {
        printf("%3d  %3d  %3d\n", compact[i][0], compact[i][1], compact[i][2]);
    }
}

// Add two compact matrices
int addCompact(int a[MAX][3], int b[MAX][3], int result[MAX][3]) {
    int i = 1, j = 1, k = 1;
    int sizeA = a[0][2], sizeB = b[0][2];

    result[0][0] = a[0][0];
    result[0][1] = a[0][1];

    while (i <= sizeA && j <= sizeB) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2];
            i++;
        } else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            result[k][0] = b[j][0];
            result[k][1] = b[j][1];
            result[k][2] = b[j][2];
            j++;
        } else {
            result[k][0] = a[i][0];
            result[k][1] = a[i][1];
            result[k][2] = a[i][2] + b[j][2];
            i++;
            j++;
        }
        k++;
    }

    while (i <= sizeA) {
        result[k][0] = a[i][0];
        result[k][1] = a[i][1];
        result[k][2] = a[i][2];
        i++;
        k++;
    }

    while (j <= sizeB) {
        result[k][0] = b[j][0];
        result[k][1] = b[j][1];
        result[k][2] = b[j][2];
        j++;
        k++;
    }

    result[0][2] = k - 1;
    return k - 1;
}

// Transpose a compact matrix
void transposeCompact(int compact[MAX][3], int transposed[MAX][3]) {
    int rows = compact[0][0];
    int cols = compact[0][1];
    int size = compact[0][2];

    transposed[0][0] = cols;
    transposed[0][1] = rows;
    transposed[0][2] = size;

    int k = 1;
    for (int i = 0; i < cols; i++) {
        for (int j = 1; j <= size; j++) {
            if (compact[j][1] == i) {
                transposed[k][0] = compact[j][1];
                transposed[k][1] = compact[j][0];
                transposed[k][2] = compact[j][2];
                k++;
            }
        }
    }
}

int main() {
    int rows, cols;
    int matrixA[MAX][MAX], matrixB[MAX][MAX];
    int compactA[MAX][3], compactB[MAX][3];
    int sum[MAX][3], transpose[MAX][3];

    // Input size
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input matrices
    printf("\nMatrix A:\n");
    inputMatrix(matrixA, rows, cols);
    printf("\nMatrix B:\n");
    inputMatrix(matrixB, rows, cols);

    // Convert to compact
    int sizeA = toCompact(rows, cols, matrixA, compactA);
    int sizeB = toCompact(rows, cols, matrixB, compactB);

    // Display compact forms
    printf("\nCompact form of Matrix A:\n");
    displayCompact(compactA, sizeA);

    printf("\nCompact form of Matrix B:\n");
    displayCompact(compactB, sizeB);

    // Add compact matrices
    int sizeSum = addCompact(compactA, compactB, sum);
    printf("\nSum of Matrix A and B in Compact form:\n");
    displayCompact(sum, sizeSum);

    // Transpose result
    transposeCompact(sum, transpose);
    printf("\nTranspose of the Result Matrix in Compact form:\n");
    displayCompact(transpose, transpose[0][2]);

    return 0;
}
