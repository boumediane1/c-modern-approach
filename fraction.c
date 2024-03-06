typedef struct {
    int numerator;
    int denominator;
} Fraction;


Fraction reduce(Fraction f);

Fraction add(Fraction f1, Fraction f2);

Fraction subtract(Fraction f1, Fraction f2);

Fraction multiply(Fraction f1, Fraction f2);

Fraction divide(Fraction f1, Fraction f2);

int gcd(int a, int b);

void swap(int *a, int *b);

int main() {
    return 0;
}

Fraction reduce(Fraction f) {
    int result = gcd(f.numerator, f.denominator);

    return (Fraction) {f.numerator / result, f.denominator / result};
}

Fraction add(Fraction f1, Fraction f2) {
    int numerator = f1.numerator * f2.denominator + f1.denominator * f2.numerator;
    int denominator = f1.numerator * f2.denominator;

    return reduce((Fraction) {numerator, denominator});
}

Fraction subtract(Fraction f1, Fraction f2) {
    int numerator = f1.numerator * f2.denominator - f1.denominator * f2.numerator;
    int denominator = f1.numerator * f2.denominator;

    return (Fraction) {numerator, denominator};
}

Fraction multiply(Fraction f1, Fraction f2) {
    int numerator = f1.numerator * f2.numerator;
    int denominator = f1.denominator * f2.denominator;

    return (Fraction) {numerator, denominator};
}

Fraction divide(Fraction f1, Fraction f2) {
    int numerator = f1.numerator * f2.denominator;
    int denominator = f1.denominator * f2.numerator;

    return reduce((Fraction) {numerator, denominator});
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int gcd(int a, int b) {
    if (b > a)
        swap(&a, &b);

    while (a % b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }

    return b;
}
