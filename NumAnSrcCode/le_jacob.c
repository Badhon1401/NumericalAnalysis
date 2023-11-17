#include <stdio.h>
#include <math.h>

#define N 3 // Number of equations/variables
#define MAX_ITER 100 // Maximum number of iterations
#define EPSILON 0.0001 // Tolerance for convergence

double f1(double x, double y, double z) {
    return x * x + y * y + z * z - 3;
}

double f2(double x, double y, double z) {
    return x * x - 2 * y + z * z - 1;
}

double f3(double x, double y, double z) {
    return x + y + z - 2;
}

void jacobianMethod(double x, double y, double z) {
    int iter;
    double x_new, y_new, z_new;

    for (iter = 0; iter < MAX_ITER; iter++) {
        x_new = x - (f1(x, y, z) / (2 * x));
        y_new = y - (f2(x, y, z) / (-2));
        z_new = z - (f3(x, y, z) / 1);

        if (fabs(x_new - x) < EPSILON && fabs(y_new - y) < EPSILON && fabs(z_new - z) < EPSILON) {
            printf("Converged after %d iterations\n", iter + 1);
            printf("Solution:\n");
            printf("x = %.4f\ny = %.4f\nz = %.4f\n", x_new, y_new, z_new);
            return;
        }

        x = x_new;
        y = y_new;
        z = z_new;
    }

    printf("Did not converge within %d iterations\n", MAX_ITER);
}

int main() {
    double x0 = 1.0, y0 = 1.0, z0 = 1.0;

    printf("Initial guess:\n");
    printf("x = %.2f\ny = %.2f\nz = %.2f\n", x0, y0, z0);

    jacobianMethod(x0, y0, z0);

    return 0;
}
