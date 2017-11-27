
#include <math.h>
#include <iostream>

using namespace std;

long double function(long double x, long double y) {
	return exp(y-x);
}


void main() {

	long double nx, ny;

	long double hx, hy;

	long double ay, by;
	long double ax, bx;

	ax = 0; bx = 0.5;
	ay = 0; by = 0.5;

	nx = 2; 
	ny = 2;

	hx = (bx - ax) / 2;
	hy = (by - ay) / 2;

	long double St = 0; 

	long double E0, E1, E2;

	E0 = function(ax, ay) + function(ax, by) + function(bx, ay) + function(bx, by);
	cout << "E0 " << E0 << endl;
	E1 = function(ax, hy) + function(hx, ay) + function(bx, hy) + function(hx, by);
	cout << "E1 " << E1 << endl;
	E2 = function(hx, hy);
	cout << "E2 " << E2 << endl;

	St = ((hx * hy) / 4.0) * (E0 + 2*E1 + 4*E2);

	cout << "St: " << St << endl;

	system("pause");
}

