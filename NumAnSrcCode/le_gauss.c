#include <stdio.h>

#define N 3 // Number of equations/variables

void printMatrix(double mat[N][N + 1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= N; j++) {
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");
    }
}

void gaussianElimination(double mat[N][N + 1]) {
    int i, j, k;
    
    // Applying Gaussian Elimination
    for (i = 0; i < N; i++) {
        for (k = i + 1; k < N; k++) {
            double factor = mat[k][i] / mat[i][i];
            for (j = i; j <= N; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }

    // Back Substitution
    double solutions[N];
    for (i = N - 1; i >= 0; i--) {
        solutions[i] = mat[i][N];
        for (j = i + 1; j < N; j++) {
            solutions[i] -= mat[i][j] * solutions[j];
        }
        solutions[i] /= mat[i][i];
    }

    // Print the results
    printf("Solution:\n");
    for (i = 0; i < N; i++) {
        printf("X%d = %.2f\n", i + 1, solutions[i]);
    }
}

int main() {
    double mat[N][N + 1] = {
        {4, -1, 0, 3},
        {2, 5, -1, 9},
        {1, -2, 4, 7}
    };

    printf("Original Augmented Matrix:\n");
    printMatrix(mat);

    gaussianElimination(mat);

    return 0;
}
