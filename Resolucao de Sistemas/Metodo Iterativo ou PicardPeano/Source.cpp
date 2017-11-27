#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

const double AcceptableError = pow(10, -5);

long double g1(long double x, double long y) {
	return sqrt((x * y + 5 * x - 1) / 2);
}

long double g2(long double x, double long y) {
	return sqrt(x + 3 * log(x));
}

int main() {
	//long double xn1 = xn;    ---> metodo de gauss-seidel
	long double xn = 4; 
	long double xn0 = 4;
	long double yn = 4; 
	int counter = 0; 

	do {
		xn = g1(xn, yn); 
		yn = g2(xn0, yn);
		xn0 = xn;
		++counter;
	} while (abs(g1(xn, yn) - xn) > AcceptableError || abs(g2(xn, yn) - yn) > AcceptableError);

	cout << counter << " iteracoes, xn = " << xn << " ,yn = " << yn << endl;

	system("pause"); 
	return 0; 

}