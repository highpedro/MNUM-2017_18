#include <iostream>
#include <cmath>

using namespace std; 

const double Ta = 37;

const double k = 2.5;

int isOdd(int x) {
	return x & 1;
}

long double f_pergunta1(long double t) {

	return -0.25 * (t - Ta);

}

void pergunta1() {

	long double T = 3.0;

	long double Tn = 3.0;

	long double t = 5; 

	long double h = 0.4; 

	for (int i = 0; i < 3; i++) {

		cout << "Iter: " << i << " - T: " << Tn << endl; 

		Tn = T + h*f_pergunta1(T);

		T = Tn;


	}

}

long double f_pergunta5(long double x) {

	return sqrt(1 + pow(k * exp(k * x), 2));

}

long double trapezio_5(long double h, long double a, long double b) {


	int n = (b - a) / h;

	double result = 0; 

	result += f_pergunta5(a);

	for (int i = 1; i < n; i++) {

		result += 2 * f_pergunta5(a + i*h);

	}

	result += f_pergunta5(b); 

	result *= (h / 2.0);

	return result;

}

long double simpson_5(long double h, long double a, long double b) {

	int n = (b - a) / h; 

	double result = 0; 

	result += f_pergunta5(a);

	for (int i = 1; i < n; i++) {
		if (isOdd(i))
			result += 4 * f_pergunta5(a + i*h);
		else
			result += 2 * f_pergunta5(a + i *h);
	}

	result += f_pergunta5(b); 

	result *= (h / 3.0);

	return result;


}

void cout_trapezio_5(long double a, long double b, long double h) {

	long double h1 = h / 2.0;
	long double h2 = h1 / 2.0;


	cout << "Trapezio:\n";
	cout << "h: " << h << " \t";
	long double S = trapezio_5(h, a, b);
	cout << "S: " << S << endl;
	cout << "h1: " << h1 << " \t";
	long double S1 = trapezio_5(h1, a, b);
	cout << "S: " << S1 << endl;
	cout << "h2: " << h2 << " \t";
	long double S2 = trapezio_5(h2, a, b);
	cout << "S: " << S2 << endl;

	long double Qc = (S1 - S) / (S2 - S1);

	cout << "Qc: " << Qc << endl;

	long double Error = (S2 - S1) / 3;

	cout << "Error: " << Error << endl;

}

void cout_simpson_5(long double a, long double b, long double h) {

	long double h1 = h / 2.0;
	long double h2 = h1 / 2.0;


	cout << "Simpson:\n";
	cout << "h: " << h << " \t";
	long double S = simpson_5(h, a, b);
	cout << "S: " << S << endl;
	cout << "h1: " << h1 << " \t";
	long double S1 = simpson_5(h1, a, b);
	cout << "S: " << S1 << endl;
	cout << "h2: " << h2 << " \t";
	long double S2 = simpson_5(h2, a, b);
	cout << "S: " << S2 << endl;

	long double Qc = (S1 - S) / (S2 - S1);

	cout << "Qc: " << Qc << endl;

	long double Error = (S2 - S1) / 15;

	cout << "Error: " << Error << endl;

}


void pergunta5() {

	long double a = 0; 
	long double b = 1; 
	long double h = 0.125;

	cout_trapezio_5(a, b, h);

	cout_simpson_5(a, b, h);
	

}

long double f_pergunta7(long double x) {
	return pow(x, 3) - 10 * sin(x) + 2.8;
}

void pergunta7() {

	long double a = 1.5; 
	long double b = 4.2;

	for (int i = 0; i < 3; i++) {
		
		cout << "Iter: " << i << ": a-" << a << " b- " << b << endl;

		long double x = (a + b) / 2.0; 

		if (f_pergunta7(a) * f_pergunta7(x) < 0)
			b = x;
		else
			a = x;
		
	}

}

void pergunta4() {

	long double x = 1.1; 

	for (int i = 0; i < 2; i++) {

		cout << "iter: " << i << ": x = " << x << endl;
		cout << "residuo: " << x - 1.1 << endl;
		x = 2 * log(2 * x);

	}


}


void main() {

	pergunta1(); 

	cout << endl << "Pergunta 4:\n"; 

	pergunta4();

	cout << endl << "pergunta 5:\n"; 
	pergunta5();

	cout << endl << "pergunta 7:\n";
	pergunta7();

	system("pause");
}