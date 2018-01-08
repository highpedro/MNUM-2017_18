#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

long double function(long double x, long double y) {
    return pow(x, 2) + pow(y, 2);
}

long double dy1(long double h, long double x, long double y) {
    return h * function(x, y);
}

long double dy2(long double h, long double x, long double y) {
    return h * function(x + h / 2, y + dy1(h, x, y) / 2);
}

long double dy3(long double h, long double x, long double y) {
    return h * function(x + h / 2, y + dy2(h, x, y) / 2);
}

long double dy4(long double h, long double x, long double y) {
    return h * function(x + h, y + dy3(h, x, y));
}

long double rk4(long double h, long double x, long double y) {
    return y + dy1(h, x, y) / 6 + dy2(h, x, y) / 3 + dy3(h, x, y) / 3 + dy4(h, x, y) / 6;
}


int main() {
    //=============METODO DE EULER====================================


    /*
    long double x0 = 0, h = 0.1, y0 = 0, xf = 1.4;

    long double xn = x0;

    long double yn = y0;

    long double xn1 = 0;

    long double yn1 = 0;

    while( xn1 < xf ){



        xn1 = xn + h;

        yn1 = yn + h*function(xn,yn);

        xn = xn1;
        yn = yn1;

    }

    cout << "O valor de y e " << yn1 << endl;

    long double xn2 = 0;
    long double yn2 = 0;

    xn = 0;
    yn = 0;

    long double h2 = h /2;

    while(xn2 < xf){

        xn2 = xn + h2;
        yn2 = yn + h2 * function(xn, yn);

        xn = xn2;
        yn = yn2;
    }


    cout << "O valor de y e " << yn2 << endl;


    long double xn3 = 0;
    long double yn3 = 0;

    xn = 0;
    yn = 0;

    long double h3 = h2 / 2;

    while(xn3 < xf){

        xn3 = xn + h3;
        yn3 = yn + h3*function(xn, yn);

        xn = xn3;
        yn = yn3;


    }

    cout << "O valor de y e " << yn3 << endl;


    long double Qc = (yn2 - yn1) / ( yn3 - yn2);

    cout << "O valor de QC e " << Qc << endl;

    long double Error = yn3 - yn2;

    cout << "O erro e " << Error << endl;
     */



    //=============================================================


    //=============RK2============================

    /*
    long double x0 = 0, y0 = 0, xf = 1.4, h = 0.1;

    long double xn = x0;

    long double yn = y0;

    long double xn1 = 0;
    long double yn1 = 0;

    while(xn1 < xf){

        xn1 = xn + h;

        yn1 = yn + h*function(xn + h /2, yn + (h/2)*function(xn,yn));

        xn = xn1;
        yn = yn1;


    }


    cout << "O valor de y " << yn1 << endl;

    long double xn2 = 0;
    long double yn2 = 0;

    long double h2 = h /2;

    xn = 0;
    yn = 0;

    while(xn2 < xf){

        xn2 = xn + h2;

        yn2 = yn + h2*function(xn + h2 /2, yn + (h2/2)*function(xn,yn));

        xn = xn2;
        yn = yn2;


    }

    cout << "O valor de y " << yn2 << endl;

    long double xn3 = 0;
    long double yn3 = 0;

    long double h3 = h2 /2;

    xn = 0;
    yn = 0;

    while(xn3 < xf){

        xn3 = xn + h3;

        yn3 = yn + h3*function(xn + h3 /2, yn + (h3/2)*function(xn,yn));

        xn = xn3;
        yn = yn3;


    }

    cout << "O valor de y " << yn3 << endl;

    long double Qc = (yn2 - yn1) / ( yn3 - yn2);

    cout << "O valor de QC e " << Qc << endl;

    long double Error = (yn3 - yn2) / 3;

    cout << "O erro e " << Error << endl;

    */

    //==============================================



    long double x0 = 0, y0 = 0, xf = 1.4, h = 0.1;

    long double xn = x0;

    long double yn = y0;

    long double xn1 = 0;
    long double yn1 = 0;

    while (xn1 < xf) {

        xn1 = xn + h;

        yn1 = rk4(h, xn, yn);

        xn = xn1;
        yn = yn1;


    }


    cout << "O valor de y " << yn1 << endl;

    long double xn2 = 0;
    long double yn2 = 0;

    long double h2 = h / 2;

    xn = 0;
    yn = 0;

    while (xn2 < xf) {

        xn2 = xn + h2;

        yn2 = rk4(h2, xn, yn);

        xn = xn2;
        yn = yn2;


    }

    cout << "O valor de y " << yn2 << endl;

    long double xn3 = 0;
    long double yn3 = 0;

    long double h3 = h2 / 2;

    xn = 0;
    yn = 0;

    while (xn3 < xf) {

        xn3 = xn + h3;

        yn3 = rk4(h3, xn, yn);

        xn = xn3;
        yn = yn3;


    }

    cout << "O valor de y " << yn3 << endl;


    long double xn4 = 0;
    long double yn4 = 0;

    long double h4 = h3 / 2;

    xn = 0;
    yn = 0;

    while (xn4 < xf) {

        xn4 = xn + h4;

        yn4 = rk4(h4, xn, yn);

        xn = xn4;
        yn = yn4;


    }

    cout << "O valor de y " << yn4 << endl;


    long double xn5 = 0;
    long double yn5 = 0;

    long double h5 = h4 / 2;

    xn = 0;
    yn = 0;

    while (xn5 < xf) {

        xn5 = xn + h5;

        yn5 = rk4(h5, xn, yn);

        xn = xn5;
        yn = yn5;


    }

    cout << "O valor de y " << yn5 << endl;


    long double xn6 = 0;
    long double yn6 = 0;

    long double h6 = h5 / 2;

    xn = 0;
    yn = 0;

    while (xn6 < xf) {

        xn6 = xn + h6;

        yn6 = rk4(h6, xn, yn);

        xn = xn6;
        yn = yn6;


    }

    cout << "O valor de y " << yn6 << endl;


    long double xn7 = 0;
    long double yn7 = 0;

    long double h7 = h6 / 2;

    xn = 0;
    yn = 0;

    while (xn7 < xf) {

        xn7 = xn + h7;

        yn7 = rk4(h7, xn, yn);

        xn = xn7;
        yn = yn7;


    }

    cout << "O valor de y " << yn7 << endl;

    long double Qc1 = (yn2 - yn1) / (yn3 - yn2);

    long double Qc2 = (yn3 - yn2) / (yn4 - yn3);

    long double Qc3 = (yn4 - yn3) / (yn5 - yn4);

    long double Qc4 = (yn5 - yn4) / (yn6 - yn5);

    long double Qc5 = (yn6 - yn5) / (yn7 - yn6);

    cout << "O valor de QC e " << Qc1 << "  o outro valor e " << Qc2 << " o outro valor e " << Qc3 << " o outro e "
         << Qc4 << " o outro e " << Qc5 << endl;

    cout << "Os valores de H " << h << " " << h2 << "  " << h3 << "  " << h4 << "  " << h5 << "  " << h6 << "  " << h7
        << "  " <<h7 << endl;

    long double Error = (yn3 - yn2) / 15;

    long double Error1 = (yn4 - yn3) / 15;

    long double Error2 = (yn5 - yn4) / 15;

    long double Error3 = (yn6-yn5) / 15;

    long double Error4 = (yn7-yn6) / 15;

    cout << "O erro e " << Error << " o outro erro e " << Error4 << endl;


    return 0;
}