#include <iostream>
#include <math.h>

using namespace std;

long double function(long double x) {
    return pow(2 * x + 1, 2) - 5 * cos(10 * x);
}

const long double B = (sqrt(5) - 1) / 2;
const long double A = pow(B, 2);

long double x3_f(long double x1, long double x2) {

    return x1 + A * (x2 - x1);

}

long double x4_f(long double x1, long double x2) {
    return x1 + B * (x2 - x1);
}

void min(){
    int counter = 0;

    long double x1 = -1;
    long double x2 = 0;
    long double x3, x4;

    do {

        x3 = x3_f(x1, x2);
        x4 = x4_f(x1, x2);

        if (function(x3) < function(x4)) {

            x2 = x4;


        } else {
            x1 = x3;

        }

        counter++;

    } while (abs(x1 - x2) > 0.001);


    cout <<"iter: " << counter << "\tx1: " << x1 << "\tx2: " << x2 << "\tf(x1): " << function(x1) << "\tf(x2): " << function(x2) << endl;

}


void max(){
    int counter = 0;

    long double x1 = -1;
    long double x2 = 0;
    long double x3, x4;

    do {

        x3 = x3_f(x1, x2);
        x4 = x4_f(x1, x2);

        if (function(x3) > function(x4)) {

            x2 = x4;


        } else {
            x1 = x3;

        }

        counter++;

    } while (abs(x1 - x2) > 0.001);


    cout <<"iter: " << counter << "\tx1: " << x1 << "\tx2: " << x2 << "\tf(x1): " << function(x1) << "\tf(x2): " << function(x2) << endl;

}

int main() {
    cout << "minimo:\n";
    min();
    cout << "maximo:\n";
    max();

    return 0;
}