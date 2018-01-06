#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std; 

const long double  B = (sqrt(5) - 1) / 2.0;
const long double A = pow(B, 2); 

long double f_5(long double x) {
	return 5 * cos(x) - sin(x);
}

void pergunta5() {

	long double x1 = 2.0; 
	long double x2 = 4.0; 
	long double x3 = 0.0; 
	long double x4 = 0.0; 
	long double fa = 0.0; 
	long double fn = 0.0; 


	for (int i = 0; i < 3; i++) {

		cout << "Iter: " << i << ": x1: " << x1 << " x2: " << x2;

		x3 = A * (x2 - x1) + x1; 
		x4 = B * (x2 - x1) + x1;

		cout << " x3: " << x3 << " x4: " << x4 << " f_5(x1): " << f_5(x1) << "f_5(x2): " << f_5(x2) << " f_5(x3): " << f_5(x3) << endl;

		if (f_5(x3) < f_5(x4))
			x2 = x4;
		else
			x1 = x3;

		cout << "Amplitude apos iteracao " << i << ": " << (x2 - x1) << endl;

	}

}


void main() {

	cout << "Pergunta5:\n"; 

	pergunta5();

	system("pause");

}


