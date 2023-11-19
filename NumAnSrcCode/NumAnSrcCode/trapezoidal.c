#include <stdio.h>

// Function to be integrated
double f(double x) {
    return x * x; // Example function x^2
}

// Trapezoidal rule implementation
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;
    double result = (f(a) + f(b)) / 2.0;

    for (int i = 1; i < n; ++i) {
        result += f(a + i * h);
    }

    return result * h;
}

int main() {
    double a = 0.0;  // Lower limit
    double b = 1.0;  // Upper limit
    int n = 100;     // Number of subintervals

    double integral = trapezoidalRule(a, b, n);

    printf("Result using Trapezoidal Rule: %lf\n", integral);

    return 0;
}
