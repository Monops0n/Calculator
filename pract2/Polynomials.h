#pragma once

typedef struct {
	int degree;
	double kef[100];
} Polynomial;
void clear();
Polynomial columnDivisionOfPolynomials(Polynomial plnnmial1, Polynomial plnmial2, Polynomial* remainder);
Polynomial additionOfPolynomials(Polynomial plnmial1, Polynomial plnmial2);
Polynomial subtractingAPolynomial(Polynomial plnmial1, Polynomial plnmial2);
Polynomial multiplyingOfPolynomials(Polynomial plnmial1, Polynomial plnmial2);
Polynomial multiplyingByANumber(Polynomial plnmial, double a);
Polynomial derivativeOfAPolynomial(Polynomial plnmial);
double evaluatePolynomials(Polynomial plnmial, double x);
void printPolynomial(Polynomial plnmial);
int firstTask();
int secondTask();
int thirdTask();
int fourthTask();
int fifthTask();
int sixthTask();

