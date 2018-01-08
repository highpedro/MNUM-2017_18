#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

const double AcceptableError = pow(10, -4);

long double f(long double x) {
	return  x - 2 * log(x) - 5;
}

long double g1(long double x) {
	return  2 * log(x) + 5;
}

long double g2(long double x) {
	return exp((x - 5) / 2);
}

long double diffF(long double x) {
	return 1 - 2 / x;
}

long double f2(long double x) {
	return pow(2, sqrt(x)) - 10 * x + 1;
}

long double diffF2(long double x) {
	return ((log(2) * pow(2, sqrt(x) - 1)) / sqrt(x)) - 10;
}

long double cot(long double x) {
	return 1 / tan(x);
}

long double f3(long double x) {
	return cot(x) * sin(3 * x) - x + 1;
}

int main() {

	//funcao a)
	/*
	long double a = 0.001;
	long double b = 0.1;
	long double xn;
	int bisecIter = 0;

	do{
	xn = (a + b) / 2;

	if (f(a)*f(xn) > 0) {
	a = xn;
	b = b;
	}
	else {
	a = a;
	b = xn;
	}

	bisecIter++;
	} while (abs(xn - (a + b) / 2) > AcceptableError);

	long double a2 = 9;
	long double b2 = 10;
	long double xn2 = (a2 + b2) / 2;


	int bisecIter2 = 0;


	do{
	xn2 = (a2 + b2) / 2;

	if (f(a2)*f(xn2) > 0) {
	a2 = xn2;
	b2 = b2;
	}
	else {
	a2 = a2;
	b2 = xn2;
	}

	bisecIter2++;
	} while (abs(xn2 - (a2 + b2) / 2) > AcceptableError);

	cout << "METODO DA BISSECCAO:" << endl << endl;
	cout << "Primeiro zero: " << endl;
	cout << "valor de f(a) : " << f(a) << " para a = " << a << endl << "valor de f(b): " << f(b) << " para b = " << b << endl << "valor de f(xn): " << f(xn) << " para xn = " << xn << "    " << "com " << bisecIter << " iteracoes" << endl << endl << endl;

	cout << "Segundo zero: " << endl;
	cout << "valor de f(a2) : " << f(a2) << " para a2 = " << a2 << endl << "valor de f(b2): " << f(b2) << " para b2 = " << b2 << endl << "valor de f(xn2): " << f(xn2) << " para xn2 = " << xn2 << "    " << "com " << bisecIter2 << " iteracoes" << endl;



	//METODO DA CORDA

	long double aC = 0.001;
	long double bC = 0.1;
	long double xnC;
	int cordaIter = 0;



	do {
	xnC = (aC * f(bC) - bC * f(aC)) / (f(bC) - f(aC));

	if (f(aC)*f(xnC) < 0) {
	aC = aC;
	bC = xnC;
	}
	else {
	aC = xnC;
	bC = bC;
	}

	cordaIter++;


	} while (abs(xnC - (aC * f(bC) - bC * f(aC)) / (f(bC) - f(aC))) > AcceptableError);


	long double a2C = 9;
	long double b2C = 10;
	long double xn2C;
	int cordaIter2 = 0;


	do{
	xn2C = (a2C * f(b2C) - b2C * f(a2C)) / (f(b2C) - f(a2C));

	if (f(a2C)*f(xn2C) < 0) {
	a2C = a2C;
	b2C = xn2C;
	}
	else {
	a2C = xn2C;
	b2C = b2C;
	}

	cordaIter2++;
	} while (abs(xn2C - (a2C * f(b2C) - b2C * f(a2C)) / (f(b2C) - f(a2C))) > AcceptableError);


	cout << endl << endl << "METODO DA CORDA" << endl << endl;
	cout << "Primeiro zero: " << endl;
	cout << "valor de f(a) : " << f(aC) << " para a = " << aC << endl << "valor de f(b): " << f(bC) << " para b = " << bC << endl << "valor de f(xn): " << f(xnC) << " para xn = " << xnC << "    " << "com " << cordaIter << " iteracoes" << endl << endl << endl;

	cout << "Segundo zero: " << endl;
	cout << "valor de f(a2) : " << f(a2C) << " para a2 = " << a2C << endl << "valor de f(b2): " << f(b2C) << " para b2 = " << b2C << endl << "valor de f(xn2): " << f(xn2C) << " para xn2 = " << xn2C << "    " << "com " << cordaIter2 << " iteracoes" << endl;

	//METODO DE NEWTON

	long double xNewton = 0.02;
	int newtonIter = 0;

	do {
	xNewton = xNewton - f(xNewton) / diffF(xNewton);
	newtonIter++;
	} while (abs(xNewton - (xNewton - f(xNewton) / diffF(xNewton))) > AcceptableError);

	cout << endl << endl << "METODO DE NEWTON" << endl << endl;
	cout << "Primeiro zero :" << endl;
	cout << "valor de f(xn): " << f(xNewton) << " para xn = " << xNewton << "  com " << newtonIter << " iteracoes." << endl;


	long double xNewton2 = 9;
	int newtonIter2 = 0;

	do {
	xNewton2 = xNewton2 - f(xNewton2) / diffF(xNewton2);
	newtonIter2++;
	} while (abs(xNewton2 - (xNewton2 - f(xNewton2) / diffF(xNewton2))) > AcceptableError);


	cout << "Segundo zero :" << endl;
	cout << "valor de f(xn): " << f(xNewton2) << " para xn = " << xNewton2 << "  com " << newtonIter2 << " iteracoes." << endl;
	*/

	long double xn = 9;
	int counter = 0;

	do {

		xn = g1(xn);

		counter++;

		if (counter == 3)
			cout << counter << " iteracoes: -xn = " << xn << "  g(xn) : " << g1(xn) << endl;
		if (counter == 8)
			cout << counter << " iteracoes: -xn = " << xn << "  g(xn) : " << g1(xn) << endl;


	} while (counter < 1001);

	cout << counter << " iteracoes: -xn = " << xn << "  g(xn) : " << g1(xn) << endl;



	//funcao b)
	/*
	long double a = 0.2;
	long double b = 0.25;
	long double xn;
	int bisecIter = 0;

	do{
	xn = (a + b) / 2;

	if (f2(a)*f2(xn) > 0) {
	a = xn;
	b = b;
	}
	else {
	a = a;
	b = xn;
	}

	bisecIter++;
	} while (abs(xn - (a + b) / 2) > AcceptableError);

	long double a2 = 98.5;
	long double b2 = 99.5;
	long double xn2 = (a2 + b2) / 2;


	int bisecIter2 = 0;


	do{
	xn2 = (a2 + b2) / 2;

	if (f2(a2)*f2(xn2) > 0) {
	a2 = xn2;
	b2 = b2;
	}
	else {
	a2 = a2;
	b2 = xn2;
	}

	bisecIter2++;
	} while (abs(xn2 - (a2 + b2) / 2) > AcceptableError);

	cout << "METODO DA BISSECCAO:" << endl << endl;
	cout << "Primeiro zero: " << endl;
	cout << "valor de f(a) : " << f2(a) << " para a = " << a << endl << "valor de f(b): " << f2(b) << " para b = " << b << endl << "valor de f(xn): " << f2(xn) << " para xn = " << xn << "    " << "com " << bisecIter << " iteracoes" << endl << endl << endl;

	cout << "Segundo zero: " << endl;
	cout << "valor de f(a2) : " << f2(a2) << " para a2 = " << a2 << endl << "valor de f(b2): " << f2(b2) << " para b2 = " << b2 << endl << "valor de f(xn2): " << f2(xn2) << " para xn2 = " << xn2 << "    " << "com " << bisecIter2 << " iteracoes" << endl;



	//METODO DA CORDA

	long double aC = 0.2;
	long double bC = 0.25;
	long double xnC;
	int cordaIter = 0;



	do {
	xnC = (aC * f2(bC) - bC * f2(aC)) / (f2(bC) - f2(aC));

	if (f2(aC)*f2(xnC) < 0) {
	aC = aC;
	bC = xnC;
	}
	else {
	aC = xnC;
	bC = bC;
	}

	cordaIter++;


	} while (abs(xnC - (aC * f2(bC) - bC * f2(aC)) / (f2(bC) - f2(aC))) > AcceptableError);


	long double a2C = 98.6;
	long double b2C = 99.5;
	long double xn2C;
	int cordaIter2 = 0;


	do{
	xn2C = (a2C * f2(b2C) - b2C * f2(a2C)) / (f2(b2C) - f2(a2C));

	if (f2(a2C)*f2(xn2C) < 0) {
	a2C = a2C;
	b2C = xn2C;
	}
	else {
	a2C = xn2C;
	b2C = b2C;
	}

	cordaIter2++;
	} while (abs(xn2C - (a2C * f2(b2C) - b2C * f2(a2C)) / (f2(b2C) - f2(a2C))) > AcceptableError);


	cout << endl << endl << "METODO DA CORDA" << endl << endl;
	cout << "Primeiro zero: " << endl;
	cout << "valor de f(a) : " << f2(aC) << " para a = " << aC << endl << "valor de f(b): " << f2(bC) << " para b = " << bC << endl << "valor de f(xn): " << f2(xnC) << " para xn = " << xnC << "    " << "com " << cordaIter << " iteracoes" << endl << endl << endl;

	cout << "Segundo zero: " << endl;
	cout << "valor de f(a2) : " << f2(a2C) << " para a2 = " << a2C << endl << "valor de f(b2): " << f2(b2C) << " para b2 = " << b2C << endl << "valor de f(xn2): " << f2(xn2C) << " para xn2 = " << xn2C << "    " << "com " << cordaIter2 << " iteracoes" << endl;

	//METODO DE NEWTON

	long double xNewton = 0.22;
	int newtonIter = 0;

	do {
	xNewton = xNewton - f2(xNewton) / diffF2(xNewton);
	newtonIter++;
	} while (abs(xNewton - (xNewton - f2(xNewton) / diffF2(xNewton))) > AcceptableError);

	cout << endl << endl << "METODO DE NEWTON" << endl << endl;
	cout << "Primeiro zero :" << endl;
	cout << "valor de f(xn): " << f2(xNewton) << " para xn = " << xNewton << "  com " << newtonIter << " iteracoes." << endl;


	long double xNewton2 = 98.7;
	int newtonIter2 = 0;

	do {
	xNewton2 = xNewton2 - f2(xNewton2) / diffF2(xNewton2);
	newtonIter2++;
	} while (abs(xNewton2 - (xNewton2 - f2(xNewton2) / diffF2(xNewton2))) > AcceptableError);


	cout << "Segundo zero :" << endl;
	cout << "valor de f(xn): " << f2(xNewton2) << " para xn = " << xNewton2 << "  com " << newtonIter2 << " iteracoes." << endl;
	*/

	//funcao c)
	/*
	long double a = 0.7;
	long double b = 1.3;
	long double xn;
	int bisecIter = 0;

	do{
	xn = (a + b) / 2;

	if (f(a)*f(xn) > 0) {
	a = xn;
	b = b;
	}
	else {
	a = a;
	b = xn;
	}

	bisecIter++;
	} while (abs(xn - (a + b) / 2) > AcceptableError);



	cout << "METODO DA BISSECCAO:" << endl << endl;
	cout << "Primeiro zero: " << endl;
	cout << "valor de f(a) : " << f(a) << " para a = " << a << endl << "valor de f(b): " << f(b) << " para b = " << b << endl << "valor de f(xn): " << f(xn) << " para xn = " << xn << "    " << "com " << bisecIter << " iteracoes" << endl << endl << endl;


	//METODO DA CORDA

	long double aC = 0.7;
	long double bC = 1.3;
	long double xnC;
	int cordaIter = 0;



	do {
	xnC = (aC * f(bC) - bC * f(aC)) / (f(bC) - f(aC));

	if (f(aC)*f(xnC) < 0) {
	aC = aC;
	bC = xnC;
	}
	else {
	aC = xnC;
	bC = bC;
	}

	cordaIter++;


	} while (abs(xnC - (aC * f(bC) - bC * f(aC)) / (f(bC) - f(aC))) > AcceptableError);



	cout << endl << endl << "METODO DA CORDA" << endl << endl;
	cout << "Primeiro zero: " << endl;
	cout << "valor de f(a) : " << f(aC) << " para a = " << aC << endl << "valor de f(b): " << f(bC) << " para b = " << bC << endl << "valor de f(xn): " << f(xnC) << " para xn = " << xnC << "    " << "com " << cordaIter << " iteracoes" << endl << endl << endl;


	//METODO DE NEWTON

	long double xNewton = 0.8;
	int newtonIter = 0;

	do {
	xNewton = xNewton - f(xNewton) / diffF(xNewton);
	newtonIter++;
	} while (abs(xNewton - (xNewton - f(xNewton) / diffF(xNewton))) > AcceptableError);

	cout << endl << endl << "METODO DE NEWTON" << endl << endl;
	cout << "Primeiro zero :" << endl;
	cout << "valor de f(xn): " << f(xNewton) << " para xn = " << xNewton << "  com " << newtonIter << " iteracoes." << endl;
	*/

	system("pause");
	return 0;
};