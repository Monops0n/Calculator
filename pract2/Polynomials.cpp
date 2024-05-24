#include <iostream>
#include <math.h>
#include <Windows.h>
#include "Polynomials.h"

void clear() {
	system("cls");
}

Polynomial columnDivisionOfPolynomials(Polynomial plnnmial1, Polynomial plnmial2, Polynomial* remainder)
{
	Polynomial quotient;
	int	dividendDegree = plnnmial1.degree;
	int divisorDegree = plnmial2.degree;

	quotient.degree = dividendDegree - divisorDegree;

	for (int i = 0; i <= quotient.degree; i++) {
		quotient.kef[i] = 0;
	}

	for (int i = dividendDegree; i >= divisorDegree; i--) {
		double kef = plnnmial1.kef[i] / plnmial2.kef[plnmial2.degree];
		quotient.kef[i - divisorDegree] = kef;

		for (int j = 0; j <= plnmial2.degree; j++) {
			plnnmial1.kef[i - divisorDegree + j] -= kef * plnmial2.kef[j];
		}
	}

	(*remainder).degree = plnmial2.degree - 1;
	for (int i = 0; i <= (*remainder).degree; i++) {
		(*remainder).kef[i] = plnnmial1.kef[i];
	}

	return quotient;

}


Polynomial additionOfPolynomials(Polynomial plnmial1, Polynomial plnmial2)
{
	Polynomial result;
	int maxDegree;

	double kef1, kef2;

	if (plnmial1.degree > plnmial2.degree) {
		result.degree = plnmial1.degree;
		maxDegree = result.degree;
	}
	else
	{
		result.degree = plnmial2.degree;
		maxDegree = result.degree;
	}

	for (int i = 0; i <= maxDegree; i++) {
		if (i <= plnmial1.degree)
		{
			kef1 = plnmial1.kef[i];
		}
		else
		{
			kef1 = 0;
		}
		if (i <= plnmial2.degree)
		{
			kef2 = plnmial2.kef[i];
		}
		else
		{
			kef2 = 0;
		}
		result.kef[i] = kef1 + kef2;
	}

	return result;
}

Polynomial subtractingAPolynomial(Polynomial plnmial1, Polynomial plnmial2) {
	Polynomial result;
	int maxDegree;

	double kef1, kef2;

	if (plnmial1.degree > plnmial2.degree) {
		result.degree = plnmial1.degree;
		maxDegree = result.degree;
	}
	else
	{
		result.degree = plnmial2.degree;
		maxDegree = result.degree;
	}

	for (int i = 0; i <= maxDegree; i++) {
		if (i <= plnmial1.degree)
		{
			kef1 = plnmial1.kef[i];
		}
		else
		{
			kef1 = 0;
		}
		if (i <= plnmial2.degree)
		{
			kef2 = plnmial2.kef[i];
		}
		else
		{
			kef2 = 0;
		}
		result.kef[i] = kef1 - kef2;
	}

	return result;
}

Polynomial multiplyingOfPolynomials(Polynomial plnmial1, Polynomial plnmial2)
{
	Polynomial result;

	result.degree = plnmial1.degree + plnmial2.degree;

	for (int i = 0; i <= result.degree; i++)
	{
		result.kef[i] = 0;
	}

	for (int i = 0; i <= plnmial1.degree; i++)
	{
		for (int j = 0; j <= plnmial2.degree; j++)
		{
			result.kef[i + j] += plnmial1.kef[i] * plnmial2.kef[j];
		}
	}


	return result;
}

Polynomial multiplyingByANumber(Polynomial plnmial, double a)
{
	Polynomial result;

	result.degree = plnmial.degree;

	for (int i = 0; i <= result.degree; i++)
	{
		result.kef[i] = 0;
	}

	for (int i = 0; i <= plnmial.degree; i++)
	{
		result.kef[i] += plnmial.kef[i] * a;
	}
	return result;
}

Polynomial derivativeOfAPolynomial(Polynomial plnmial)
{
	Polynomial result;

	if (plnmial.degree == 0)
	{
		result.degree = 0;
		result.kef[0] = 0;
		return result;
	}

	result.degree = plnmial.degree - 1;

	for (int i = 1; i <= plnmial.degree; i++)
	{
		result.kef[i - 1] = i * plnmial.kef[i];
	}
	return result;
}

double evaluatePolynomials(Polynomial plnmial, double x)
{
	double result = 0;

	for (int i = 0; i <= plnmial.degree; i++)
	{
		result += plnmial.kef[i] * pow(x, i);
	}
	return result;
}

void printPolynomial(Polynomial plnmial) {
	if (plnmial.kef[0] == 0 && plnmial.degree == 0)
	{
		printf_s("0");
		return;
	}

	printf_s("%.2lfx^%d", plnmial.kef[plnmial.degree], plnmial.degree);

	for (int i = plnmial.degree - 1; i >= 0; i--)
	{

		if (plnmial.kef[i] == 0)
		{
			continue;
		}
		else if (i != 0)
		{
			printf_s(" + ");
			printf_s("%.2lfx^%d", plnmial.kef[i], i);
		}
		else
		{
			printf_s(" + ");
			printf_s("%.2lf", plnmial.kef[i]);
		}
	}
	printf_s("\n");
}

int firstTask()
{
	clear();
	Polynomial plnmial1, plnmial2, quotient, remainder;
	int degree;
	double x, value, value2;

	printf_s("������� ������������ ������� ��������(������� ������ ���� ����� � �������������): ");
	scanf_s("%d", &degree);
	while (degree < 0)
	{
		printf_s("����������, ������� ���������� ��������, ��������� ����: ");
		scanf_s("%d", &degree);
	}
	plnmial1.degree = degree;
	printf_s("������� ������������ ��� ��������:\n");
	for (int i = degree; i >= 0; i--) {
		printf_s("����������� ��� x ������� %d: ", i);
		scanf_s("%lf", &plnmial1.kef[i]);
	}
	printf_s("������� ������������ ������� �������� (������� ������ ���� ����� � �������������): ");
	scanf_s("%d", &degree);
	while (degree < 0)
	{
		printf_s("����������, ������� ���������� ��������, ��������� ����: ");
		scanf_s("%d", &degree);
	}
	plnmial2.degree = degree;
	printf_s("������� ������������ ��� ��������:\n");
	for (int i = degree; i >= 0; i--) {
		printf_s("����������� ��� x ������� %d: ", i);
		scanf_s("%lf", &plnmial2.kef[i]);
	}
	if (plnmial2.kef[plnmial2.degree] == 0)
	{
		printf_s("������� �� ���� - ������\n");
		return 0;
	}

	else if (plnmial2.degree > plnmial1.degree)
	{
		printf_s("������� �������� ������ ������� ��������, ����������� ��������\n");
		return 0;

	}

	quotient = columnDivisionOfPolynomials(plnmial1, plnmial2, &remainder);

	printf_s("������� �� �������: ");
	printPolynomial(quotient);
	printf_s("\n");

	printf_s("������� �� �������: ");
	printPolynomial(remainder);
	printf_s("\n");

	printf_s("������� �������� x, ����� ��������� ���������: ");
	scanf_s("%lf", &x);

	value = evaluatePolynomials(quotient, x);

	printf_s("������� ���������� = %.2lf\n", value);

	value2 = evaluatePolynomials(remainder, x);

	printf_s("������� ���������� = %.2lf\n", value2);

	Sleep(3750);
	return 0;
}

int secondTask()
{
	clear();
	int numsOfPolynomials;
	Polynomial summ = { 0 };
	double x, value;

	printf_s("������� ���������� �����������, ������� �� ������ ������� (�� 2� �� 10): ");
	scanf_s("%d", &numsOfPolynomials);

	while (numsOfPolynomials < 2 || numsOfPolynomials > 10)
	{
		printf_s("����������, ������� ���������� ��������, ��������� ����: ");
		scanf_s("%d", &numsOfPolynomials);
	}

	Polynomial polynomials[10];

	for (int i = 0; i < numsOfPolynomials; i++)
	{
		printf_s("������� ������� ���������� %d (������� ������ ���� ����� � �������������): ", i + 1);
		scanf_s("%d", &polynomials[i].degree);
		while (polynomials[i].degree < 0)
		{
			printf_s("����������, ������� ���������� ��������, ��������� ����: ");
			scanf_s("%d", &polynomials[i].degree);
		}

		printf_s("������� ������������ ��� ���������� %d: \n", i + 1);
		for (int j = polynomials[i].degree; j >= 0; j--)
		{
			printf_s("����������� ��� x ������� %d: ", j);
			scanf_s("%lf", &polynomials[i].kef[j]);
		}
		summ = additionOfPolynomials(summ, polynomials[i]);
	}

	printf_s("��������� ��������: ");
	printPolynomial(summ);

	printf_s("������� �������� x, ����� ����� ����� ��������: ");
	scanf_s("%lf", &x);
	value = evaluatePolynomials(summ, x);
	printf_s("����� ����������� = %.2lf\n", value);

	Sleep(3750);
	return 0;
}

int thirdTask()
{
	clear();
	int numsOfPolynomials;
	Polynomial quot = { 0 };
	double x, value;

	printf_s("������� ���������� �����������, ������� �� ������ ������� (�� 2� �� 10): ");
	scanf_s("%d", &numsOfPolynomials);

	while (numsOfPolynomials < 2 || numsOfPolynomials > 10)
	{
		printf_s("����������, ������� ���������� ��������, ��������� ����: ");
		scanf_s("%d", &numsOfPolynomials);
	}

	Polynomial polynomials[10];

	for (int i = 0; i < numsOfPolynomials; i++)
	{
		printf_s("������� ������� ���������� %d (������� ������ ���� ����� � �������������): ", i + 1);
		scanf_s("%d", &polynomials[i].degree);
		while (polynomials[i].degree < 0)
		{
			printf_s("����������, ������� ���������� ��������, ��������� ����: ");
			scanf_s("%d", &polynomials[i].degree);
		}

		printf_s("������� ������������ ��� ���������� %d: \n", i + 1);
		for (int j = polynomials[i].degree; j >= 0; j--)
		{
			printf_s("����������� ��� x ������� %d: ", j);
			scanf_s("%lf", &polynomials[i].kef[j]);
			if (i == 0)
			{
				polynomials[i].kef[j] *= -1;
			}
		}
		quot = subtractingAPolynomial(quot, polynomials[i]);
	}

	printf_s("��������� ���������: ");
	printPolynomial(quot);

	printf_s("������� �������� x, ����� ����� ��������: ");
	scanf_s("%lf", &x);
	value = evaluatePolynomials(quot, x);
	printf_s("�������� ����������� = %.2lf\n", value);

	Sleep(3750);
	return 0;
}

int fourthTask()
{
	clear();
	int numsOfPolynomials;
	Polynomial prod = { 0 };
	double x, value;

	printf_s("������� ���������� �����������, ������� �� ������ ����������� (�� 2� �� 10): ");
	scanf_s("%d", &numsOfPolynomials);

	while (numsOfPolynomials < 2 || numsOfPolynomials > 10)
	{
		printf_s("����������, ������� ���������� ��������, ��������� ����: ");
		scanf_s("%d", &numsOfPolynomials);
	}

	Polynomial polynomials[10];

	for (int i = 0; i < numsOfPolynomials; i++)
	{
		printf_s("������� ������� ���������� %d (������� ������ ���� ����� � �������������): ", i + 1);
		scanf_s("%d", &polynomials[i].degree);
		while (polynomials[i].degree < 0)
		{
			printf_s("����������, ������� ���������� ��������, ��������� ����: ");
			scanf_s("%d", &polynomials[i].degree);
		}

		printf_s("������� ������������ ��� ���������� %d: \n", i + 1);
		for (int j = polynomials[i].degree; j >= 0; j--)
		{
			printf_s("����������� ��� x ������� %d: ", j);
			scanf_s("%lf", &polynomials[i].kef[j]);
		}
		if (i == 0)
		{
			prod = polynomials[0];
		}
		else
		{
			prod = multiplyingOfPolynomials(prod, polynomials[i]);
		}
	}

	printf_s("��������� ���������: ");
	printPolynomial(prod);

	printf_s("������� �������� x, ����� ����� ������������ �����������: ");
	scanf_s("%lf", &x);
	value = evaluatePolynomials(prod, x);
	printf_s("������������ ����������� = %.2lf\n", value);

	Sleep(3750);
	return 0;
}

int fifthTask()
{
	clear();
	Polynomial plnmial1, result;
	int degree;
	double x, value, a;

	printf_s("������� ������������ ������� �������� � ���������� (������� ������ ���� ����� � �������������): ");
	scanf_s("%d", &degree);
	while (degree < 0)
	{
		printf_s("����������, ������� ���������� ��������, ��������� ����: ");
		scanf_s("%d", &degree);
	}
	plnmial1.degree = degree;
	printf_s("������� ������������ ��� ����������:\n");
	for (int i = degree; i >= 0; i--) {
		printf_s("����������� ��� x ������� %d: ", i);
		scanf_s("%lf", &plnmial1.kef[i]);
	}
	printf_s("������� �������� a, �� ������� ������ �������� ���������: ");
	scanf_s("%lf", &a);

	result = multiplyingByANumber(plnmial1, a);

	printf_s("��������� ���������: ");
	printPolynomial(result);

	printf_s("������� �������� x, ����� ����� ������������ ���������� �� �����: ");
	scanf_s("%lf", &x);
	value = evaluatePolynomials(result, x);
	printf_s("������������ ���������� �� ����� = %.2lf\n", value);

	Sleep(3750);
	return 0;
}

int sixthTask()
{
	clear();
	Polynomial plnmial1, result;
	int degree;
	double x, value;

	printf_s("������� ������������ ������� �������� � ���������� (������� ������ ���� ����� � �������������): ");
	scanf_s("%d", &degree);
	while (degree < 0)
	{
		printf_s("����������, ������� ���������� ��������, ��������� ����: ");
		scanf_s("%d", &degree);
	}
	plnmial1.degree = degree;
	printf_s("������� ������������ ��� ����������:\n");
	for (int i = degree; i >= 0; i--) {
		printf_s("����������� ��� x ������� %d: ", i);
		scanf_s("%lf", &plnmial1.kef[i]);
	}

	result = derivativeOfAPolynomial(plnmial1);

	printf_s("��������� ����������� �� ����������: ");
	printPolynomial(result);

	printf_s("������� �������� x, ����� ����� ����������� ����������: ");
	scanf_s("%lf", &x);
	value = evaluatePolynomials(result, x);
	printf_s("����������� ���������� = %.2lf\n", value);

	Sleep(3750);
	return 0;

}