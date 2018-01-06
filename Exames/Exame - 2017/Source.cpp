#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std; 

const long double A = 1.5; 

long double f_6(long double z) {
	return z;
}

long double dz1(long double h, long double t, long double z);
long double dz2(long double h, long double t, long double z);
long double dz3(long double h, long double t, long double z);
long double dz4(long double h, long double t, long double z);

long double g_6(long double t, long double z) {
	return A + pow(t, 2) + t*z;
}

long double dy1(long double h, long double t, long double z) {
	return h * f_6(z);
}
long double dy2(long double h, long double t, long double z) {
	return h * f_6(z + dz1(h,t,z)/2.0);
}
long double dy3(long double h, long double t, long double z) {
	return h * f_6(z + dz2(h, t, z) / 2.0);
}
long double dy4(long double h, long double t, long double z) {
	return h * f_6(z + dz3(h, t, z));
}

long double rk4_y (long double h,long double t, long double z, long double y) {
	return y + 1 / 6.0 * dy1(h, t, z) + 1 / 3.0 * dy2(h, t, z) + 1 / 3.0 * dy3(h, t, z) + 1 / 6.0*dy4(h, t, z);
}

long double dz1(long double h, long double t, long double z) {
	return h * g_6(t, z);
}
long double dz2(long double h, long double t, long double z) {
	return h * g_6(t + h/2.0, z + dz1(h,t,z)/2.0);
}
long double dz3(long double h, long double t, long double z) {
	return h * g_6(t + h/2.0, z + dz2(h,t,z)/2.0);
}
long double dz4(long double h, long double t, long double z) {
	return h * g_6(t + h, z + dz3(h, t, z));
}

long double rk4_z(long double h, long double t, long double z) {
	return z + 1 / 6.0 * dz1(h, t, z) + 1 / 3.0 * dz2(h, t, z) + 1 / 3.0 * dz3(h, t, z) + 1 / 6.0 * dz4(h, t, z);
}

void pergunta6() {
	long double h = 0.1;

	long double t0 = 1; 
	long double t = 1; 
	long double y0 = 0;
	long double y = 0; 
	long double z0 = 1; 
	long double z = 1;

	cout.fixed;
	cout.precision(6);

	for (int i = 0; i < 3; i++) {

		cout << "Iter: " << i << ":  t->" << t << " y->" << y << endl;

		t = t0 + h;
		y = rk4_y(h, t0,z0,y0);
		z = rk4_z(h, t0, z0);

		t0 = t;
		y0 = y;
		z0 = z;


	}
}


void main() {

	cout << "Pergunta 6:\n"; 

	pergunta6();

	system("pause"); 

}