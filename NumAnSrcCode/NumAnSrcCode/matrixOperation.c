#include <stdio.h>
#include <math.h>

#define MAX_SIZE 10

void displayMatrix(int mat[MAX_SIZE][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

void transpose(int mat[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row, int col) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[j][i] = mat[i][j];
        }
    }
}

int determinant(int mat[MAX_SIZE][MAX_SIZE], int n) {
    int det = 0;
    if (n == 1) {
        return mat[0][0];
    } else if (n == 2) {
        return mat[0][0] * mat[1][1] - mat[0][1] * mat[1][0];
    } else {
        for (int i = 0; i < n; i++) {
            int cofactor = pow(-1, i) * mat[0][i] * determinant(mat, n - 1);
            det += cofactor;
        }
        return det;
    }
}

void inverse(int mat[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n) {
    int det = determinant(mat, n);
    if (det == 0) {
        printf("Inverse does not exist.\n");
        return;
    }

    int adj[MAX_SIZE][MAX_SIZE];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cofactor = pow(-1, i + j) * determinant(mat, n - 1);
            adj[j][i] = cofactor;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = adj[i][j] / det;
        }
    }
}

void square(int mat[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = mat[i][j] * mat[i][j];
        }
    }
}

void multiply(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int row1, int col1, int row2, int col2) {
    if (col1 != row2) {
        printf("Matrix multiplication not possible.\n");
        return;
    }

    for (int i = 0; i < row1; i++) {
        for (int j = 0; j < col2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < col1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int mat1[MAX_SIZE][MAX_SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row1 = 3, col1 = 3;

    int result[MAX_SIZE][MAX_SIZE];

    printf("Original Matrix 1:\n");
    displayMatrix(mat1, row1, col1);

    // Transpose
    printf("\nTranspose of Matrix 1:\n");
    transpose(mat1, result, row1, col1);
    displayMatrix(result, col1, row1);

    // Determinant
    printf("\nDeterminant of Matrix 1: %d\n", determinant(mat1, row1));

    // Inverse
    printf("\nInverse of Matrix 1:\n");
    inverse(mat1, result, row1);
    displayMatrix(result, row1, col1);

    // Square
    printf("\nSquare of Matrix 1:\n");
    square(mat1, result, row1);
    displayMatrix(result, row1, col1);

    // Matrix Multiplication
    int mat2[MAX_SIZE][MAX_SIZE] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    int row2 = 3, col2 = 3;

    printf("\nOriginal Matrix 2:\n");
    displayMatrix(mat2, row2, col2);

    printf("\nMatrix Multiplication (Matrix 1 * Matrix 2):\n");
    multiply(mat1, mat2, result, row1, col1, row2, col2);
    displayMatrix(result, row1, col2);

    return 0;
}
