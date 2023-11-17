#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define MAX_ITER 100

double function(double x) {
    // Define your function here, for example, x^3 - x - 1
    return x * x * x - x - 1;
}

double derivative(double x) {
    // Define the derivative of your function
    return 3 * x * x - 1;
}

void newtonRaphsonMethod(double initial_guess) {
    double x = initial_guess;
    int iter;

    for (iter = 0; iter < MAX_ITER; iter++) {
        double f_value = function(x);
        double f_prime_value = derivative(x);

        if (fabs(f_prime_value) < EPSILON) {
            printf("Derivative is too small. Newton-Raphson method cannot converge.\n");
            return;
        }

        x = x - f_value / f_prime_value;

        if (fabs(f_value) < EPSILON) {
            printf("Converged after %d iterations\n", iter + 1);
            printf("Root: %lf\n", x);
            return;
        }
    }

    printf("Did not converge within %d iterations\n", MAX_ITER);
}

int main() {
    double initial_guess = 1.0;

    printf("Initial guess: %lf\n", initial_guess);

    newtonRaphsonMethod(initial_guess);

    return 0;
}
