#include <stdio.h>

// Function to be integrated
double f(double x) {
    return x * x; // Example function x^2
}

// Simpson's 1/3 rule implementation
double simpsonsOneThirdRule(double a, double b, int n) {
    double h = (b - a) / n;
    double result = f(a) + f(b);

    for (int i = 1; i < n; i += 2) {
        result += 4 * f(a + i * h);
    }

    for (int i = 2; i < n - 1; i += 2) {
        result += 2 * f(a + i * h);
    }

    return result * h / 3.0;
}

// Simpson's 2/3 rule implementation
double simpsonsTwoThirdRule(double a, double b, int n) {
    double h = (b - a) / n;
    double result = f(a) + f(b);

    for (int i = 1; i < n - 1; i += 3) {
        result += 3 * f(a + i * h);
    }

    for (int i = 2; i < n - 2; i += 3) {
        result += 3 * f(a + i * h);
    }

    return result * h * 3.0 / 8.0;
}

int main() {
    double a = 0.0;  // Lower limit
    double b = 1.0;  // Upper limit
    int n = 6;       // Number of subintervals (should be multiple of 3 for 2/3 rule)

    double integral1 = simpsonsOneThirdRule(a, b, n);
    double integral2 = simpsonsTwoThirdRule(a, b, n);

    printf("Result using Simpson's 1/3 Rule: %lf\n", integral1);
    printf("Result using Simpson's 2/3 Rule: %lf\n", integral2);

    return 0;
}
