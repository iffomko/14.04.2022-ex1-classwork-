#include <iostream>
#include <cmath>

using tf = double (*)(double x);

double integralTrapezoid(double a, double b, double e, tf f) {
    double sum = (f(a) + f(b)) / 2, prevS = 0, h = b - a, curS = h * sum;

    do {
        prevS = curS;

        for (double x = a + h / 2; x < b; x += h)
            sum += f(x);

        h /= 2;

        curS = (sum * h);
    } while (fabs(curS - prevS) >= e);

    return curS;
}

double integralSimpson(double a, double b, double e, tf f) {
    int n = 0;
    double h = b - a, prevSum = 0, curSum = h / 3 * (f(a) + f(b));

    do {
        prevSum = curSum;
        curSum = f(a) + f(b);
        h /= 2;

        int index = 0;

        for (double x = a + h; x < b; x += h) {
            index++;

            if (index % 2 == 1)
                curSum += 4 * f(x);
            else
                curSum += 2 * f(x);
        }

        curSum *= h;
        curSum /= 3;
    } while (fabs(prevSum - curSum) >= e);

    return curSum;
}

double exF1(double x) {
    return x*x;
}

int main() {
    std::cout << integralSimpson(0, 2, 0.001, exF1) << std::endl;
    return 0;
}
