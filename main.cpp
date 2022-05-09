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
    double h = b - a, prevSum = 0, curSum = h * (f(a) + f(b)) / 3, prevSumBetween = f(a) + f(b), curSumBetween = 0;

    do {
        prevSum = curSum;
        prevSumBetween += curSumBetween / 2;
        curSumBetween = 0;

        for (double x = a + h / 2; x < b; x += h)
            curSumBetween += f(x);

        curSumBetween *= 4;
        h /= 2;
        curSum = h * (prevSumBetween + curSumBetween) / 3;
    } while (fabs(prevSum - curSum) >= e);

    return curSum;
}

double exF1(double x) {
    return sqrt(x);
}

int main() {
    std::cout << integralSimpson(0, 2, 0.001, exF1) << std::endl;
    return 0;
}
