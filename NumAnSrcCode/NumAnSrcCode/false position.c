#include <stdio.h>
#include <math.h>

#define EPSILON 0.0001

double function(double x) {
    // Define your function here, for example, x^3 - x - 1
    return x * x * x - x - 1;
}

void falsePositionMethod(double a, double b) {
    if (function(a) * function(b) >= 0) {
        printf("False position method cannot guarantee a root in the given interval.\n");
        return;
    }

    double c = a;

    while ((b - a) >= EPSILON) {
        // Calculate the false position
        c = (a * function(b) - b * function(a)) / (function(b) - function(a));

        // Check if root is found
        if (function(c) == 0.0) {
            break;
        }
        // Update the interval
        else if (function(c) * function(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }

    printf("Root: %lf\n", c);
}

int main() {
    double a = 1.0, b = 2.0;

    printf("Initial interval: [%.2f, %.2f]\n", a, b);

    falsePositionMethod(a, b);

    return 0;
}
