#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001
#define MAX_ITER 100

double function(double x) {
    // Define your function here, for example, x^3 - x - 1
    return x * x * x - x - 1;
}

void secantMethod(double x0, double x1) {
    int iter;
    double x2;

    for (iter = 0; iter < MAX_ITER; iter++) {
        x2 = x1 - (function(x1) * (x1 - x0)) / (function(x1) - function(x0));

        if (fabs(function(x2)) < EPSILON) {
            printf("Converged after %d iterations\n", iter + 1);
            printf("Root: %lf\n", x2);
            return;
        }

        x0 = x1;
        x1 = x2;
    }

    printf("Did not converge within %d iterations\n", MAX_ITER);
}

int main() {
    double x0 = 1.0, x1 = 2.0;

    printf("Initial values: x0 = %lf, x1 = %lf\n", x0, x1);

    secantMethod(x0, x1);

    return 0;
}
