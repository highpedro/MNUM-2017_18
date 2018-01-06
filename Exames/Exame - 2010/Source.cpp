#include <cmath>
#include <iostream>

using namespace std;

const long double a = 1; 
const long double b = 2; 

long double f_3(long double t,long double x) {

	return sin(a*x) + sin(b*t);

}

long double dx1(long double h, long double t, long double x) {
	return h * f_3(t, x);
}
long double dx2(long double h, long double t, long double x) {
	return h * f_3(t + h / 2.0, x + dx1(h, t, x) / 2.0);
}
long double dx3(long double h, long double t, long double x) {
	return h * f_3(t + h / 2.0, x + dx2(h, t, x) / 2.0);
}
long double dx4(long double h, long double t, long double x) {
	return h * f_3(t + h, x + dx3(h, t, x));
}
long double rk4_x(long double h, long double t, long double x) {
	return x + 1 / 6.0 * dx1(h, t, x) + 1 / 3.0 * dx2(h, t, x) + 1 / 3.0 * dx3(h, t, x) + 1 / 6.0 * dx4(h, t, x);
}


void pergunta3() {

	long double t0 = 1; 
	long double t = 1; 
	long double x0 = 0; 
	long double x = 0; 
	long double S, S1, S2;

	long double h = 0.5;

	long double n = (1.5 - 1.0) / h;

	for (int i = 0; i <= n; i++) {
		cout << "iter " << i << ": t: " << t << " x: " << x << endl; 
		S = x;
		t = t0 + h;
		x = rk4_x(h, t0, x0);

		t0 = t; 
		x0 = x; 

	}

	t0 = 1; t = 1; x0 = 0; x = 0;

	long double h1 = h / 2;
	  n = (1.5 - 1.0) / h1;

	for (int i = 0; i <= n; i++) {
		cout << "iter " << i << ": t: " << t << " x: " << x << endl;
		S1 = x;
		t = t0 + h1;
		x = rk4_x(h1, t0, x0);

		t0 = t;
		x0 = x;

	}
	t0 = 1; t = 1; x0 = 0; x = 0;

	long double h2 = h1 / 2;
	n = (1.5 - 1.0) / h2;

	for (int i = 0; i <= n; i++) {
		cout << "iter " << i << ": t: " << t << " x: " << x << endl;
		S2 = x;
		t = t0 + h2;
		x = rk4_x(h2, t0, x0);

		t0 = t;
		x0 = x;

	}

	cout << "S: " << S << " S1: " << S1 << " S2: " << S2 << endl;

	long double Qc = (S1 - S) / (S2 - S1);
	cout << "Quociente:" << Qc << endl;

}

long double f_1(long double x) {
	return 2 * log(2 * x);
}

void pergunta1() {

	long double xn = 0.9; 

	for (int i = 0; i < 2; i++) {
		cout << "Iter: " <<  i << " x: " << xn << endl; 
		cout << "residuo: " << xn - 0.9 << endl;
		xn = f_1(xn);
	}

}


long double f_5(long double x, long double y) {
	return 6 * pow(x, 2) - x * y + 12 * y + pow(y, 2) - 8 * x;
}

long double dx_5(long double x, long double y) {
	return -y + 12 * x - 8;
}

long double dy_5(long double x, long double y) {
	return 2 * y - x + 12;
}

void pergunta5() {
	long double y = 0, ya = 0, yn = 0;
	long double x = 0, xa = 0, xn = 0;

	long double h = 0.5;

	long double fa = 0, fn = 5;

	for (int i = 0; i < 2; i++) {
		cout << "iter: " << i << ": x: " << x << " y: " << y << " Z(x,y): " << f_5(x, y) << " Grad(x): " << dx_5(x, y) << " Grad(y): " << dy_5(x, y) << endl;

		fa = f_5(xa, ya);

		xn = x - h * dx_5(x, y);
		yn = y - h * dy_5(x, y);

		fn = f_5(xn, yn);

		if (fn < fa) {

			cout << "passo correto" << endl;
			h = 2 * h;
			x = xn;
			y = yn;

		}
		else {
			cout << "passo incorreto" << endl;
			h = h / 2.0;
		}


	}
}

void main() {

	pergunta3();
	

	system("pause");
}