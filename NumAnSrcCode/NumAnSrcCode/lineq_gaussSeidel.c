#include <stdio.h>
#include <math.h>

#define N 3 // Number of equations/variables

void gaussSeidel(double A[N][N + 1], double X[N]) {
    int i, j, k;
    double sum;

    for (i = 0; i < N; i++) {
        X[i] = 0; // Initialize solution vector
    }

    int max_iterations = 100; // You can adjust the maximum number of iterations

    for (k = 0; k < max_iterations; k++) {
        for (i = 0; i < N; i++) {
            sum = A[i][N]; // Initialize sum with the right-hand side

            for (j = 0; j < N; j++) {
                if (j != i) {
                    sum -= A[i][j] * X[j]; // Subtract the known values except the current variable
                }
            }

            X[i] = sum / A[i][i]; // Update the current variable
        }

        // Check for convergence
        int converged = 1;
        for (i = 0; i < N; i++) {
            double error = fabs(A[i][N] - (A[i][0] * X[0] + A[i][1] * X[1] + A[i][2] * X[2])); // Calculate the error
            if (error > 0.0001) {
                converged = 0;
                break;
            }
        }

        if (converged) {
            printf("Converged after %d iterations\n", k + 1);
            return;
        }
    }

    printf("Did not converge within %d iterations\n", max_iterations);
}

int main() {
    double A[N][N + 1] = {
        {4, -1, 0, 3},
        {2, 5, -1, 9},
        {1, -2, 4, 7}
    };

    double X[N];

    gaussSeidel(A, X);

    // Print the solution
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("X%d = %.4f\n", i + 1, X[i]);
    }

    return 0;
}
