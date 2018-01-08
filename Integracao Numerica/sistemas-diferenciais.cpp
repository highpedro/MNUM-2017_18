#include <iostream>
#include <math.h>

using namespace std;

long double dk1(long double x, long double y, long double z, long double h);

long double dk2(long double x, long double y, long double z, long double h);

long double dk3(long double x, long double y, long double z, long double h);


long double f(long double x, long double y, long double z) {
    //return z * y + x;
    return z;
}

long double g(long double x, long double y, long double z) {
    //return z * x + y;
    return x - 2 * y - 3 * z;
}

long double dy1(long double x, long double y, long double z, long double h) {
    return h * f(x, y, z);
}


long double dy2(long double x, long double y, long double z, long double h) {

    return h * f(x + h / 2, y + dy1(x, y, z, h) / 2, z + dk1(x, y, z, h) / 2);
}

long double dy3(long double x, long double y, long double z, long double h) {

    return h * f(x + h / 2, y + dy2(x, y, z, h) / 2, z + dk2(x, y, z, h) / 2);
}

long double dy4(long double x, long double y, long double z, long double h) {

    return h * f(x + h, y + dy3(x, y, z, h), z + dk3(x, y, z, h));
}

long double dk1(long double x, long double y, long double z, long double h) {

    return h * g(x, y, z);

}

long double dk2(long double x, long double y, long double z, long double h) {
    return h * g(x + h / 2, y + dy1(x, y, z, h) / 2, z + dk1(x, y, z, h) / 2);
}

long double dk3(long double x, long double y, long double z, long double h) {
    return h * g(x + h / 2, y + dy2(x, y, z, h) / 2, z + dk2(x, y, z, h) / 2);
}

long double dk4(long double x, long double y, long double z, long double h) {
    return h * g(x + h, y + dy3(x, y, z, h), z + dk3(x, y, z, h));
}

long double yrk4(long double x, long double y, long double z, long double h) {
    return y + dy1(x, y, z, h) / 6 + dy2(x, y, z, h) / 3 + dy3(x, y, z, h) / 3 + dy4(x, y, z, h) / 6;
}

long double zrk4(long double x, long double y, long double z, long double h) {
    return z + dk1(x, y, z, h) / 6 + dk2(x, y, z, h) / 3 + dk3(x, y, z, h) / 3 + dk4(x, y, z, h) / 6;
}


long double EulerMethod(long double x0, long double y0, long double z0, long double xf, long double h){

    cout << "Metodo de Euler: " << endl;

    long double xn = x0;

    long double yn = y0;

    long double zn = z0;

    long double xn1 = 0;
    long double yn1 = 0;
    long double zn1 = 0;

    while(xn1 < xf){

        xn1 = xn + h;
        yn1 = yn + h*f(xn,yn,zn);
        zn1 = zn + h*g(xn,yn,zn);

        xn = xn1;
        yn = yn1;
        zn = zn1;
    }

    long double xn2 = 0, yn2 = 0, zn2 = 0;
    long double h2 = h/2;
    xn = x0; yn = y0; zn = z0;

    while(xn2 < xf){

        xn2 = xn + h2;
        yn2 = yn + h2 * f(xn, yn, zn);
        zn2 = zn + h2 *g(xn, yn, zn);

        xn = xn2;
        yn = yn2;
        zn = zn2;

    }

    long double xn3 = 0, yn3 = 0, zn3 = 0;
    long double h3 = h2/2;
    xn = x0; yn = y0; zn = z0;

    while(xn3 < xf){

        xn3 = xn + h3;
        yn3 = yn + h3 * f(xn, yn, zn);
        zn3 = zn + h3 *g(xn, yn, zn);

        xn = xn3;
        yn = yn3;
        zn = zn3;

    }


    long double Qcy = (yn2 - yn1) / (yn3 - yn2);
    long double Qcz = (zn2 - zn1) / (zn3 - zn2);
    cout << "Yn1: " << yn1 << "  Zn1 " << zn1 << endl;
    cout << "Yn2: " << yn2 << "  Zn2 " << zn2 << endl;
    cout << "Yn3: " << yn3 << "  Zn3 " << zn3 << endl;
    cout << "Qcy: " << Qcy << " Qcz: " << Qcz << endl;
    long double Error1y = (yn3 - yn2);
    long double Error1z = (zn3 - zn2);
    cout << "Error1y: " << Error1y << endl << " Error1z: " << Error1z << endl;

    return 1;
}

int RungaKutta(long double x0, long double y0, long double z0, long double xf, long double h){


    cout << "Runga-Kutta: " << endl;


    //given that we had to divide it already, the final h will be h/2/2 or h/64
    long double xn = x0;
    long double yn = y0;
    long double zn = z0;
    long double xn1 = 0;
    long double yn1 = 0;
    long double zn1 = 0;

    while (xn1 < xf) {

        xn1 = xn + h;

        yn1 = yrk4(xn, yn, zn, h);

        zn1 = zrk4(xn, yn, zn, h);

        xn = xn1;
        yn = yn1;
        zn = zn1;
    }

    cout << "Yn1: " << yn1 << "  Zn1: " << zn1 << endl;

    long double xn2 = 0;
    long double yn2 = 0;
    long double zn2 = 0;
    xn = x0;
    yn = y0;
    zn = z0;
    long double h2 = h / 2;


    while (xn2 < xf) {

        xn2 = xn + h2;

        yn2 = yrk4(xn, yn, zn, h2);

        zn2 = zrk4(xn, yn, zn, h2);

        xn = xn2;
        yn = yn2;
        zn = zn2;
    }

    cout << "Yn2: " << yn2 << "  Zn2: " << zn2 << endl;


    long double xn3 = 0;
    long double yn3 = 0;
    long double zn3 = 0;
    xn = x0;
    yn = y0;
    zn = z0;
    long double h3 = h2 /2;


    while (xn3< xf) {

        xn3 = xn + h3;

        yn3 = yrk4(xn, yn, zn, h3);

        zn3 = zrk4(xn, yn, zn, h3);

        xn = xn3;
        yn = yn3;
        zn = zn3;
    }

    cout << "Yn3: " << yn3 << "  Zn3: " << zn3 << endl;

    /*
    long double xn4 = 0;
    long double yn4 = 0;
    long double zn4 = 0;
   xn = x0;
    yn = y0;
    zn = z0;
    long double h4 = h3 /2;


    while (xn4 < xf) {

        xn4 = xn + h4;

        yn4 = yrk4(xn, yn, zn, h4);

        zn4 = zrk4(xn, yn, zn, h4);

        xn = xn4;
        yn = yn4;
        zn = zn4;
    }

    cout << "Yn4: " << yn4 << "  Zn4: " << zn4 << endl;


    long double xn5 = 0;
    long double yn5 = 0;
    long double zn5 = 0;
  xn = x0;
    yn = y0;
    zn = z0;
    long double h5 = h4 /2;


    while (xn5 < xf) {

        xn5 = xn + h5;

        yn5 = yrk4(xn, yn, zn, h5);

        zn5 = zrk4(xn, yn, zn, h5);

        xn = xn5;
        yn = yn5;
        zn = zn5;
    }

    cout << "Yn5: " << yn5 << "  Zn5: " << zn5 << endl;

    */

    long double Qcy = (yn2 - yn1) / (yn3 - yn2);
    // long double Qcy1 = (yn3 - yn2)/(yn4-yn3);
    //  long double Qcy2 = (yn4 - yn3)/(yn5-yn4);
    long double Qcz = (zn2 - zn1) / (zn3 - zn2);
    // long double Qcz1 = (zn3 - zn2)/(zn4-zn3);
    // long double Qcz2 = (zn4 - zn3)/(zn5-zn4);
    long double Error1y = (yn3 - yn2) / 15;
    //long double Error2y = (yn4-yn3)/15;
    // long double Error3y = (yn5-yn4)/15;
    long double Error1z = (zn3 - zn2) / 15;
    //  long double Error2z = (zn4-zn3)/15;
    //  long double Error3z = (zn5-zn4)/15;
    cout << "Qcy: " << Qcy << "  Qcz: " << Qcz << endl;
    cout << "Error1y: " << Error1y << endl <<" Error1z: " << Error1z << endl;
    // cout << "Qcy: " << Qcy1 << "  Qcz: " << Qcz1 << "  Error1y: " << Error2y << " Error1z: " << Error2z << endl;
    //  cout << "Qcy: " << Qcy2 << "  Qcz: " << Qcz2 << "  Error1y: " << Error3y << " Error1z: " << Error3z << endl;

    return 1;

}

int main() {

    long double x0 = 0, y0 = 1, z0 = 1, xf = 0.5;
    long double h = 0.1;

    EulerMethod(x0,y0,z0,xf,h);

    //either divide here or keep making more yn's and zn's
    RungaKutta(x0,y0,z0,xf,h/16);


    x0 = 0; y0 = 0; z0 = 0; h = 0.025; xf = 0.5;

    cout << endl << endl << "Euler Method 2: \n";

    EulerMethod(x0,y0,z0,xf,h);

     cout << endl << endl << "Runga Kutta 2: \n";
    RungaKutta(x0,y0,z0,xf,h);




    return 1;


}