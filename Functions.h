#pragma once
#include <iostream>
#include <Windows.h>
#include <SDL.h>
using namespace std;
/*============================================ОБЩИЕ ФУНКЦИИ==========================================*/
void createPolynom(int degree, double* coeffs);
void inputDegreePolynom(int& degree);
void inputCoeffs3(double* coeff);
void inputCoeffs4(double *coeff);
void inputRangeForDeg(double &a, double &b);
double functionPolinom(double x, double* coeffs, int degree);
double functionDegree(double x, double a, double b, double c);
double functionInd(double x, double a, double b, double c, double d);
double functionLog(double x, double a, double b, double c);
double functionSin(double x, double a, double b, double c, double d);
double functionCos(double x, double a, double b, double c, double d);
/*============================================SDL==========================================*/
void drawBasic(SDL_Renderer *renderer);
void drawSDLPol(double *coeffs,int degree);
void drawSDLDeg(double *coeffs);
void drawSDLInd(double *coeffs);
void drawSDLLog(double *coeffs);
void drawSDLSin(double *coeffs);
void drawSDLCos(double *coeffs);
void inputCoeffsLog(double *coeff);
void graphics();
/*============================================ИНТЕГРАЛЫ==========================================*/
void inputCoeffsForLog(double *coeffs, double a, double b);
void inputRange(double& a, double& b);
double integratePolynom(double a, double b, double* coeffs, int degree);
double integrateDegree(double* coeffs, double A, double B, int num_intervals);
double integrateInd(double a, double b, double n, double *coeffs);
double integrateLog(double A, double B, double n, double *coeffs);
double integrateSin(double A, double B, double n, double *coeffs);
double integrateCos(double A, double B, double n, double *coeffs);
void DefiniteIntegral();
/*============================================ПОИСК Y=0 НА ОТРЕЗКЕ==========================================*/
void inputCoeffsLog(double *coeffs, double a, double b);
void inputRangeForSquare(double &a, double &b);
void inputRangeForSquareLog(double &a, double &b);
void inputEpsilonForSquare(double &epsilon);
double findSquarePolinom(double *coeffs, int degree, double a, double b, double epsilon);
double findSquareDeg(double *coeffs, double A, double B, double epsilon);
double findSquareInd(double *coeffs, double A, double B, double epsilon);
double findSquareLog(double *coeffs, double A, double B, double epsilon);
double findSquareSin(double a, double b, double c, double d, double A, double B, double epsilon);
double findSquareCos(double a, double b, double c, double d, double A, double B, double epsilon);
void squareOnRange();
/*============================================ПОИСК ЭКСТРЕМУМОВ НА ОТРЕЗКЕ===================================*/
void findExtremumsPol(double *coeffs, int degree, double A, double B, double epsilon);
void findExtremumsDeg(double *coeffs, double A, double B, double epsilon);
void findExtremumsInd(double *coeffs, double A, double B, double epsilon);
void findExtremumsLog(double *coeffs, double A, double B, double epsilon);
void findExtremumsSin(double *coeffs,double A, double B, double  epsilon);
void extremumsOnRange();