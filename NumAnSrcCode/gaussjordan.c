#include <stdio.h>

#define N 3 // Number of equations (adjust as needed)

void printMatrix(double matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%lf\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void gaussJordanElimination(double matrix[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        // Make the diagonal element 1
        double divisor = matrix[i][i];
        for (int j = i; j <= N; j++) {
            matrix[i][j] /= divisor;
        }

        // Eliminate other elements in the current column
        for (int k = 0; k < N; k++) {
            if (k != i) {
                double factor = matrix[k][i];
                for (int j = i; j <= N; j++) {
                    matrix[k][j] -= factor * matrix[i][j];
                }
            }
        }
    }
}

int main() {
    double matrix[N][N + 1] = {
        {2, -1, 1, 8},
        {-3, -1, 2, -11},
        {-2, 1, 2, -3}
    };

    printf("Original Augmented Matrix:\n");
    printMatrix(matrix);

    gaussJordanElimination(matrix);

    printf("\nMatrix in Reduced Row-Echelon Form:\n");
    printMatrix(matrix);

    printf("\nSolutions:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %lf\n", i + 1, matrix[i][N]);
    }

    return 0;
}
