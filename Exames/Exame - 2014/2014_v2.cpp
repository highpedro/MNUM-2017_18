#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std; 

long double f_pergunta_1(long double x) {
	return pow(4*pow(x, 3) - x + 1, 0.25);
}

void pergunta1() {
	long double xn = 4.0;

	for (int i = 0; i < 3; i++) {
		cout << fixed << setprecision(5) << "Iter: " << i << ": xn- " << xn << endl; 
		xn = f_pergunta_1(xn);
	}
}

long double f_pergunta6(long double x) {
	return x + (pow((x - 2), 2) / (sin(x) + 4));
}

void pergunta6() {
	long double x1 = -1.0;
	long double x2 = 1.5; 
	long double B = (sqrt(5) - 1) / 2.0;
	long double A = pow(B, 2);
	long double x3 = 0, x4 = 0;

	cout << "A: " << A << " B: " << B << endl;

	for (int i = 0; i < 3; i++) {

		cout << "Iter: " << i << ": x1: " << x1 << "  x2: " << x2;

		x3 = A * (x2 - x1) + x1;
		x4 = B*(x2 - x1) + x1;

		cout << " x3: " << x3 << "  x4: " << x4 << " f(x1): " << f_pergunta6(x1);
		cout << " f(x2) " << f_pergunta6(x2) << " f(x3) " << f_pergunta6(x3) << " f(x4) " << f_pergunta6(x4) << endl;

		

		if (f_pergunta6(x3) < f_pergunta6(x4))
			x2 = x4;
		else
			x1 = x3;
		
		cout << "Amplitude: " << x2 - x1 << endl;

	}
}

long double f_pergunta7(long double x) {

	return -x + 60 * cos(sqrt(x)) + 2;

}

long double df_pergunta7(long double x) {
	return -((30 * sin(sqrt(x))) / sqrt(x)) - 1;
}

void pergunta7() {

	long double x = 1.8; 
	long double xn = 1.8; 

	for (int i = 0; i < 3; i++) {
		cout << "Iter: " << i << ": x: " << x << " g(x): " << f_pergunta7(x) << endl;

		x = x - f_pergunta7(x) / df_pergunta7(x);

	}

}

void main() {

	cout << "pergunta 1:\n"; 
	pergunta1();
	cout << "pergunta 6:\n";
	pergunta6();
	cout << "pergunta 7:\n";
	pergunta7();

	system("pause");
}