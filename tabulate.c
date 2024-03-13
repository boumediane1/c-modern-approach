#include <stdio.h>
#include <math.h>

void tabulate(double (*f)(double), double first, double last, double increment);

int main() {
    double initial = 0;
    double final = .5;
    double increment = .1;

    printf("\n      x        cos(x)\n"
           "   -------    -------\n");
    tabulate(cos, initial, final, increment);

    printf("\n      x        sin(x)\n"
           "   -------    -------\n");
    tabulate(sin, initial, final, increment);


    printf("\n      x        tan(x)\n"
           "   -------    -------\n");
    tabulate(tan, initial, final, increment);

    return 0;
}

void tabulate(double (*f)(double), double first, double last, double increment) {
    double x;
    int num_intervals = ceil((last - first) / increment);

    for (int i = 0; i <= num_intervals; i++) {
        x = first + i * increment;
        printf("%10.5f %10.5f\n", x, (*f)(x));
    }
}
