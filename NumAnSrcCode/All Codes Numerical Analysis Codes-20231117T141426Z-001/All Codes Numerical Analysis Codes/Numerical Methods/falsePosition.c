#include <stdio.h>
#include <math.h>
#define func(x) ((x)*(x)*(x) + 4*(x)*(x) - 10)
#define EPS 1e-9

int main()
{

    double a = 1, b = 2, c;
    int itr = 0;

    while (1)
    {

        itr++;
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));

        if (fabs(func(c)) <= EPS)
        {
            printf("Root (False Position Method) is: %0.9lf", c);
            printf("\nIteration: %d\n", itr);
            break;
        }

        else if (func(a) * func(c) < 0)
        {
            b = c;
        }

        else
        {
            a = c;
        }

    }
}
