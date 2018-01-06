#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

const long double a = 1;
const long double b = 2;

long double f_5(long double t, long double x) {
	return sin(a*x) + sin(b*t);
}

long double dx1(long double h, long double t, long double x) {
	return h * f_5(t, x);
}
long double dx2(long double h, long double t, long double x) {
	return h * f_5(t + h / 2.0, x + dx1(h, t, x) / 2.0);
}
long double dx3(long double h, long double t, long double x) {
	return h * f_5(t + h / 2.0, x + dx2(h, t, x) / 2.0);
}
long double dx4(long double h, long double t, long double x) {
	return h * f_5(t + h, x + dx3(h, t, x));
}

long double rk4_x(long double h, long double t, long double x) {
	return x + 1 / 6.0 * dx1(h, t, x) + 1 / 3.0 * dx2(h, t, x) + 1 / 3.0*dx3(h, t, x) + 1 / 6.0*dx4(h, t, x);
}

void pergunta5() {

	long double t0 = 1.0, t = 1.0;
	long double tf = 1.5;
	long double x0 = 1.0, x = 1.0;
	long double S, S1, S2;

	long double h = 0.5;

	long double n = (tf - t0) / h;

	for (int i = 0; i <= n; i++) {

		cout << "t: " << t << " x: " << x << endl;
		S = x;
		t = t0 + h;
		x = rk4_x(h, t0, x0);

		t0 = t;
		x0 = x;

	}
	long double h1 = h / 2;
	t0 = 1.0, t = 1.0;
	x0 = 1.0, x = 1.0;

	n = (tf - t0) / h1;

	for (int i = 0; i <= n; i++) {

		cout << "t: " << t << " x: " << x << endl;
		S1 = x;
		t = t0 + h1;
		x = rk4_x(h1, t0, x0);

		t0 = t;
		x0 = x;

	}
	long double h2 = h1 / 2;
	t0 = 1.0, t = 1.0;
	x0 = 1.0, x = 1.0;

	n = (tf - t0) / h2;

	for (int i = 0; i <= n; i++) {

		cout << "t: " << t << " x: " << x << endl;
		S2 = x;
		t = t0 + h2;
		x = rk4_x(h2, t0, x0);

		t0 = t;
		x0 = x;

	}


	cout << "quo: " << (S1 - S) / (S2 - S1) << endl;


}

long double f_1(long double x) {
	return (x - 2.6) + pow(cos(x + 1.1), 3);
}

long double df_1(long double x) {
	return 1 - 3 * pow(cos(x + 1.1), 2)*sin(x + 1.1);
}

void pergunta1() {

	long double x0 = 1.8;

	x0 = x0 - f_1(x0) / df_1(x0);
	cout << "x0: " << x0 << endl;

}

long double f_4(long double x) {
	return 5 * cos(x) - sin(x);
}


void pergunta4() {

	long double B = (sqrt(5) - 1) / 2.0;
	long double A = pow(B, 2);

	long double x1 = 2;
	long double x2 = 4;
	long double x3 = 0;
	long double x4 = 0;

	for (int i = 0; i < 3; i++) {

		x3 = A*(x2 - x1) + x1;
		x4 = B*(x2 - x1) + x1;

		cout << x1 << '\t' << x2 << '\t' << x3 << '\t' << x4 << '\t' << f_4(x1) << '\t' << f_4(x2) << '\t' << f_4(x3) << '\t' << f_4(x4) << endl;

		if (f_4(x3) < f_4(x4))
			x2 = x4;
		else
			x1 = x3;

		cout << "amplitude: " << (x2 - x1) << endl;

	}


}

void main() {
	pergunta5();

	system("pause");
}