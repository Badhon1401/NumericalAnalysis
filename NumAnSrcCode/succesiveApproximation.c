#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define MAX_ITER 100

double g(double x) {
    // Define your iterative function here, for example, x^3 - x - 1
    return cbrt(x + 1);
}

void successiveApproximationMethod(double initial_guess) {
    int iter;
    double x = initial_guess;

    for (iter = 0; iter < MAX_ITER; iter++) {
        double x_next = g(x);

        if (fabs(x_next - x) < EPSILON) {
            printf("Converged after %d iterations\n", iter + 1);
            printf("Root: %lf\n", x_next);
            return;
        }

        x = x_next;
    }

    printf("Did not converge within %d iterations\n", MAX_ITER);
}

int main() {
    double initial_guess = 1.0;

    printf("Initial guess: %lf\n", initial_guess);

    successiveApproximationMethod(initial_guess);

    return 0;
}
