#include <stdio.h>

// Function to be differentiated
double f(double x) {
    return x * x; // Example function x^2
}

// Backward difference method for numerical differentiation
double backwardDifference(double x, double h) {
    return (f(x) - f(x - h)) / h;
}

int main() {
    double x = 2.0;  // Point at which to calculate the derivative
    double h = 0.001; // Step size

    double derivative = backwardDifference(x, h);

    printf("Derivative at x = %lf: %lf\n", x, derivative);

    return 0;
}
