#include <math.h>
#include <iostream>
 
using namespace std;

long double function(long double x) {
	return sin(x) / pow(x, 2);
}

 inline int isOdd(int x) { return x & 1; }

const long double PI = atan(1) * 4;

void main() {

	//===================METODO DOS TRAPEZIOS=====================================
	/*

	long double a, b, St1, n1, n2, n3, h1, St2 = 0, St3 = 0, h2, h3;

	a = PI / 2; 
	b = PI;
	St1 = 0;
	n1 = 4;
	h1 = (b-a) / n1;
	long double counter = 1; 


	St1 += function(a) + function(b);

	while (counter < n1) {
		St1 += 2 * function(a + counter *h1);
		counter++;
	}

	St1 *= (h1 / 2);

	h2 = h1 / 2; 

	n2 = (b - a) / h2;

	St2 += function(a) + function(b);

	counter = 1; 

	while (counter < n2) {
		St2 += 2 * function(a + counter *h2);
		counter++;
	}

	St2 *= (h2 / 2);


	h3 = h2 / 2;
	n3 = (b - a) / h3;

	St3 += function(a) + function(b);

	counter = 1;

	while (counter < n3) {
		St3 += 2 * function(a + counter * h3);
		counter++;
	}
	 
	St3 *= (h3 / 2);

	long double quotient = 0; 

	quotient = (St2 - St1) / (St3 - St2);

	
	cout << "St: " << St1 << endl << "St2: " << St2 << endl << "St3: " << St3 << endl << "Quociente " << quotient << endl;


	*/

	//====================================METODO DE SIMPSON====================================

	long double a, b, St1, n1, n2, n3, h1, St2 = 0, St3 = 0, h2, h3;

	a = PI / 2;
	b = PI;
	St1 = 0;
	n1 = 4;
	h1 = (b - a) / n1;
	long double counter = 1;

	St1 += function(a) + function(b);

	while (counter < n1) {
		if (isOdd(counter))
			St1 += 4 * function(a + counter *h1);
		else
			St1 += 2 * function(a + counter *h1);

		counter++;
	}

	St1 *= h1 / 3;


	h2 = h1 / 2;

	n2 = (b - a) / h2;

	St2 += function(a) + function(b);

	counter = 1;

	while (counter < n2) {
		if (isOdd(counter))
			St2 += 4 * function(a + counter *h2);
		else
			St2 += 2 * function(a + counter *h2);
		counter++;
	}

	St2 *= (h2 / 3);


	h3 = h2 / 2;
	n3 = (b - a) / h3;

	St3 += function(a) + function(b);

	counter = 1;

	while (counter < n3) {
		if (isOdd(counter))
			St3 += 4 * function(a + counter *h3);
		else
			St3 += 2 * function(a + counter *h3);
		counter++;
	}

	St3 *= (h3 / 3);

	long double quotient = 0;

	quotient = (St2 - St1) / (St3 - St2);


	cout << "St: " << St1 << endl  << "St2: " << St2 << endl << "St3: " << St3 << endl << "Quociente " << quotient << endl; 


	system("pause");


}