#include <stdio.h>

// Function to be differentiated
double f(double x) {
    return x * x; // Example function x^2
}

// Central difference method for numerical differentiation
double centralDifference(double x, double h) {
    return (f(x + h / 2.0) - f(x - h / 2.0)) / h;
}

int main() {
    double x = 2.0;  // Point at which to calculate the derivative
    double h = 0.001; // Step size

    double derivative = centralDifference(x, h);

    printf("Derivative at x = %lf: %lf\n", x, derivative);

    return 0;
}
