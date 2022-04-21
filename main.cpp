#include <iostream>
#include <cmath>

using tf = double (*)(double x);

double integralTrapezoid(double a, double b, double e, tf f) {
    double sum = 0, prevS = 0, h = b - a, curS = h * (f(a) + f(b)) / 2;

    do {
        prevS = curS;

        for (double x = a + h / 2; x < b; x += h)
            sum += f(x);

        h /= 2;

        curS = (((f(a) + f(b)) / 2 + sum) * h);
    } while (fabs(curS - prevS) >= e);

    return curS;
}

double integralTrapezoid2(double a, double b, double e, tf f) {
    double prevS = 0, curS = (b - a) * (f(a) + f(b)) / 2;
    int n = 1;

    do {
        std::cout << curS << std::endl;
        n *= 2;
        prevS = curS;

        curS = (f(a) + f(b)) / 2;

        for (int i = 1; i < n - 1; i++)
            curS += (f(a + i * (b-a) / n));

        curS *= ((b-a) / n);
    } while (fabs(curS - prevS) >= e);

    return curS;
}

double integralSimpson(double a, double b, double e, tf f) {

}

double exF1(double x) {
    return 1 / (x * x);
}

int main() {
    std::cout << integralTrapezoid(1, 5, 0.001, exF1) << std::endl;
    return 0;
}
