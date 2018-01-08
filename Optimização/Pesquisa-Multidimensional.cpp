#include <iostream>
#include <math.h>

using namespace std;

long double f(long double x, long double y) {
    return pow(y, 2) - 2 * x * y - 6 * y + 2 * pow(x, 2) + 12;
}

long double f2(long double x, long double y) {
    return pow(y, 2) - 2 * x * y - 6 * y + 2 * pow(x, 2) + 12 + cos(4 * x);
}

long double dx(long double x, long double y) {
    return 4 * x - 2 * y;
}

long double dy(long double x, long double y) {
    return 2 * y - 2 * x - 6;
}

long double hx(long double x, long double y) {
    return (2 * (2 * y - 2 * x - 6)) / (2 * (4 - 16 * cos(4 * x)) - 4) +
           (2 * (-2 * y - 4 * sin(4 * x) + 4 * x)) / (2 * (4 - 16 * cos(4 * x)) - 4);
}

long double hy(long double x, long double y) {
    return ((4 - 16 * cos(4 * x)) * (2 * y - 2 * x - 6)) / (2 * (4 - 16 * cos(4 * x)) - 4) +
           (2 * (-2 * y - 4 * sin(4 * x) + 4 * x)) / (2 * (4 - 16 * cos(4 * x)) - 4);
}


void gradiente() {

    long double x0 = 1;
    long double y0 = 1;
    long double h = 1;
    long double xn, yn, xna, yna;
    xn = x0;
    yn = y0;
    long double fa = 0;
    long double fn = 0;
    do {
        xna = xn;
        yna = yn;

        fa = f(xna, yna);

        xn = x0 - h * dx(x0, y0);
        yn = y0 - h * dy(x0, y0);

        fn = f(xn, yn);

        if (fn < fa) {

            x0 = xn;
            y0 = yn;
            h = h *1.5;

        } else {

            h = h / 2;

        }
    } while (abs(xna - xn) > 0.001 || abs(yna - yn) > 0.001);


    cout << "x: " << xn << "\ty: " << yn << "\tf(x): " << f(xn, yn) << endl;

}


void quadratica() {

    long double x0 = 1;
    long double y0 = 1;
    long double xn, yn, xna, yna;
    xn = x0;
    yn = y0;
    long double fa = 0;
    long double fn = 0;
    do {
        xna = xn;
        yna = yn;

        fa = f2(xna, yna);

        xn = x0 - hx(x0, y0);
        yn = y0 - hy(x0, y0);

        fn = f2(xn, yn);

        if (fn < fa) {

            x0 = xn;
            y0 = yn;

        } else {

            x0 = 0.6;
            y0 = 0.5;
            xn = x0;
            yn = y0;

        }
    } while (abs(xna - xn) > 0.0001 || abs(yna - yn) > 0.0001);


    cout << "x: " << xn << "\ty: " << yn << "\tf(x): " << f2(xn, yn) << endl;

}

int main() {


    cout << "gradinte: ";
    gradiente();
    cout << "\nquadrica: ";
    quadratica();


    return 0;
}