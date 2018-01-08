#include <iostream>
#include <math.h>

long double f(long double x, long double y){
    return pow(x+1,2) + pow(y-4,2);
}

long double dx(long double x){
    return 2*(x+1);
}
long double dy(long double y){
    return 2*(y-4);
}

long double hx(long double x){
    return  x+1;
}
long double hy(long double y){
    return y-4;
}


using namespace std;


int main() {

    long double x0 = 0;
    long double y0 = 0;

    long double lambda = 0.1;

    long double xn= x0;
    long double yn = y0;
    long double xna, yna;
    long double hLMx, hLMy;
    long double fna, fn;

    do{
        xna = xn;
        yna = yn;

        fna = f(xna,yna);

        hLMx = hx(x0) + lambda*dx(x0);
        hLMy = hy(y0) + lambda*dy(y0);

        xn = x0 - hLMx;
        yn = y0 - hLMy;

        fn = f(xn,yn);


        if(fn < fna){

            lambda = lambda/2;

        }
        else{

            lambda = lambda*2;

        }


    }while(abs(xna - xn) > 0.01 || abs(yna-yn) > 0.01);

    cout << "x: " << xn << "\tyn: " << yn << "\tf(x,y): " << f(xn,yn) << endl;





    return 0;
}