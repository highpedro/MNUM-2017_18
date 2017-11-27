#include <iostream>
#include<cmath>
#include<math.h>

using namespace std; 

long double f1(long double x, long double y) {
	return 2 * pow(x, 2) - x * y - 5 * x + 1; 
}

long double f2(long double x, long double y) {
	return x + 3 * log(x) - pow(y, 2);
}

long double df1x(long double x, long double y) {
	return -y + 4 * x - 5;
}

long double df1y(long double x, long double y) {
	return -x;
}

long double df2x(long double x, long double y) {
	return 3 / x + 1;
}

long double df2y(long double x, long double y) {
	return -2 * y;
}

long double AcceptableError = pow(10, -4);

int main() {
	long double xn = 4;
	long double yn = 4;
	int counter = 0; 

	do {
		xn = xn - (f1(xn, yn)*df2y(xn, yn) - f2(xn, yn)*df1y(xn, yn)) / (df1x(xn, yn)*df2y(xn, yn) - df2x(xn, yn)*df1y(xn, yn));
		yn = yn - (f2(xn, yn)*df1x(xn, yn) - f1(xn, yn)*df2x(xn, yn)) / (df1x(xn, yn)*df2y(xn, yn) - df2x(xn, yn)*df1y(xn, yn));
		counter++;
	} while (abs((xn - (f1(xn, yn)*df2y(xn, yn) - f2(xn, yn)*df1y(xn, yn)) / (df1x(xn, yn)*df2y(xn, yn) - df2x(xn, yn)*df1y(xn, yn))) - xn) > AcceptableError ||
		abs((yn - (f2(xn, yn)*df1x(xn, yn) - f1(xn, yn)*df2x(xn, yn)) / (df1x(xn, yn)*df2y(xn, yn) - df2x(xn, yn)*df1y(xn, yn))) - yn) > AcceptableError);

	cout << "xn: " << xn << "   yn: " << yn << "   counter: " << counter; 
	system("pause"); 
	return 0; 
}