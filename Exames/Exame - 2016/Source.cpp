#include <cmath>
#include <iostream>

using namespace std;

const long double a = 1.2; 
const long double b = 1.0;

inline int isOdd(int number) { return (number & 1); };



/*
	dy/dt = z;
	dz/dt = 0.5 + t^2 + t*z

*/

long double f1(long double z) {
	return z;
}
long double g1(long double t, long double z) {
	return 0.5 + pow(t, 2) + t * z;
}

long double dz1(long double h, long double t, long double z) {
	return h * g1(t, z);
}

long double dz2(long double h, long double t, long double z) {
	return h * g1(t + h / 2, z + dz1(h, t, z) / 2.0);
}
long double dz3(long double h, long double t, long double z) {
	return h * g1(t + h / 2, z + dz2(h, t, z) / 2.0);
}
long double dz4(long double h, long double t, long double z) {
	return h * g1(t + h, z + dz3(t, h, z));
}

long double rk4_z(long double h, long double t, long double z) {
	return z + 1 / 6.0 * dz1(h, t, z) + 1 / 3.0 * dz2(h, t, z) + 1 / 3.0 * dz3(h, t, z) + 1 / 6.0 * dz4(h, t, z);
}

long double dy1(long double h, long double t,long double z) {
	return h * f1(z);
}
long double dy2(long double h, long double t,long double z) {
	return h * f1(z + dz1(h, t, z) / 2.0);
}
long double dy3(long double h, long double t, long double z) {
	return h * f1(z + dz2(h, t, z) / 2.0);
}
long double dy4(long double h, long double t, long double z) {
	return h * f1(z + dz3(h, t, z));
}


long double rk4_y(long double h, long double t, long double z, long double y) {
	return y + 1 / 6.0 * dy1(h, t, z) + 1 / 3.0 * dy2(h, t, z) + 1 / 3.0 * dy3(h, t, z) + 1 / 6.0 * dy4(h, t, z);
}
void rk4() {

	long double h = 0.25;
	long double t0 = 0.0, t = 0;
	long double y0 = 0.0, y = 0; 
	long double z0 = 1.0, z = 1.0; 

	for (int i = 0; i < 3; i++) {

		cout << i << ": t: " << t << " y: " << y << endl;

		t = t0 + h;
		y = rk4_y(h, t0, z0, y0);
		z = rk4_z(h, t0, z0);

		t0 = t; 
		z0 = z; 
		y0 = y;


	}


}

void euler() {

	long double h = 0.25;
	long double t0 = 0.0, t = 0;
	long double y0 = 0.0, y = 0;
	long double z0 = 1.0, z = 1.0;

	for (int i = 0; i < 3; i++) {
		
		cout << i << ": t: " << t << " y: " << y << endl;

		t = t0 + h;
		y = y0 + h * f1(z0);
		z = z0 + h * g1(t0, z0);

		t0 = t; 
		y0 = y; 
		z0 = z;


	}



}


void pergunta5() {
	cout << "rk4:\n"; 
	rk4();
	cout << "euler:\n";
	euler();
}

long double f(long double x, long double y) {
	return pow(x, 2) - y - a;
}

long double g(long double x, long double y) {
	return -x + pow(y, 2) - b;
}

long double dfx(long double x, long double y) {
	return 2 * x;
}
long double dfy(long double x, long double y) {
	return -1;
}

long double dgx(long double x, long double y) {
	return -1;
}
long double dgy(long double x, long double y) {
	return 2 * y;
}

void pergunta2() {

	long double x0 = 1.0, x = 1.0;
	long double y0 = 1.0, y = 1.0;


	for (int i = 0; i < 3; i++) {

		cout << i << ": x: " << x << " y: " << y << endl;

		x = x0 - (f(x0, y0)*dgy(x0, y0) - g(x0, y0)*dfy(x0, y0)) / (dfx(x0, y0)*dgy(x0, y0) - dgx(x0, y0)*dfy(x0, y0));
		y = y0 - (g(x0, y0)*dfx(x0, y0) - f(x0, y0)*dgx(x0, y0)) / (dfx(x0, y0)*dgy(x0, y0) - dgx(x0, y0)*dfy(x0, y0));

		x0 = x; 
		y0 = y;

	}

}


long double f_4(long double x) {

	return pow(x, 7) + 0.5 * x - 0.5;

}


void pergunta4() {

	long double xa = 0.0;
	long double xd = 0.8;
	long double xn = 0.0;

	for (int i = 0; i < 4; i++) {
		xn = (xa * f_4(xd) - xd * f_4(xa)) / (f_4(xd) - f_4(xa));
		cout << i << ": xa: " << xa << " xd: " << xd << " xn: " << xn << endl;
		if (f_4(xa) * f_4(xn) < 0)
			xd = xn;
		else
			xa = xn;
		
	}


}

long double f_6(long double x) {
	long double k = 1.5;
	return sqrt(1 + pow(k * exp(k*x), 2));
}

long double trapezio(long double h, long double a, long double b) {
	
	long double n = (b - a) / h;

	long double f = 0.0; 

	f += f_6(a);

	for (int i = 1; i < n; i++) {
		f += 2 * f_6(a + i * h);
	}

	f += f_6(b); 

	f *= (h / 2.0);

	return f;


}


long double simpson(long double h, long double a, long double b) {

	long double n = (b - a) / h;

	long double f = 0.0;

	f += f_6(a);


	for (int i = 1; i < n; i++) {
		if (isOdd(i))
			f += 4 * f_6(a + i*h);
		else
			f += 2*f_6(a + i *h);
	}

	f += f_6(b);

	f *= (h / 3.0);

	return f;



}

void pergunta6() {

	long double a = 0.0; 
	long double b = 2.0;
	long double h = 0.5;
	long double h2 = h / 2.;
	long double h3 = h2 / 2.0;


	cout << "h: " << h << " h2: " << h2 << " h3: " << h3 << endl;

	long double S, S1, S2;

	S = trapezio(h, a, b);
	S1 = trapezio(h2, a, b);
	S2 = trapezio(h3, a, b);

	cout << "trap: S: " << S << " S1: " << S1 << " S2: " << S2 << endl;

	long double Qct = (S1 - S) / (S2 - S1);
	long double ErrorT = (S2 - S1) / 3.0;

	cout << "Qc: " << Qct << " Error: " << ErrorT << endl;

	S = simpson(h, a, b);
	S1 = simpson(h2, a, b);
	S2 = simpson(h3, a, b);

	cout << "simp: S: " << S << " S1: " << S1 << " S2: " << S2 << endl;
	Qct = (S1 - S) / (S2 - S1);
	 ErrorT = (S2 - S1) / 15;

	cout << "Qc: " << Qct << " Error: " << ErrorT << endl;





}

void main() {

	pergunta6();

	system("pause");

}