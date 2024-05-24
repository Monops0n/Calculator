#include<iostream>
#include <Windows.h>
#include "Header.drobi.h"
using namespace std;
#include<locale.h>
void maindrob()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int ch1,zn1,ch2,zn2;
    int t;
    do
    {
        cout << "\t+--------------------------------------------------------------+" << endl;
        cout << "\t|                                                              |" << endl;
        cout << "\t|   Калькулятор обыкновенных дробей, выберите действие         |" << endl;
        cout << "\t|                                                              |" << endl;
        cout << "\t+--------------------------------------------------------------+" << endl;
        cout << "\t|                                                              |" << endl;
        cout << "\t|    1 - Сложение.                                             |" << endl;
        cout << "\t|    2 - Вычитание.                                            |" << endl;
        cout << "\t|    3 - Умножение.                                            |" << endl;
        cout << "\t|    4 - Деление.                                              |" << endl;
        cout << "\t|    5 - Сравнение.                                            |" << endl;
        cout << "\t|    6 - Сокращение.                                           |" << endl;
        cout << "\t|    7 - Представление в виде десятичной дроби.                |" << endl;
        cout << "\t|    0 - Вернуться в главное меню калькудятора.                |" << endl;
        cout << "\t|                                                              |" << endl;
        cout << "\t+--------------------------------------------------------------+" << endl << endl << endl;
        cin >> t;
        switch(t)
        {
            case 1:
                Input_2(ch1,zn1,ch2,zn2);
                Summa(ch1,zn1,ch2,zn2);
                break;//2
            case 2:
                Input_2(ch1,zn1,ch2,zn2);
                Raznost(ch1,zn1,ch2,zn2);
                break;//2
            case 3:
                Input_2(ch1,zn1,ch2,zn2);
                Proizvedenie(ch1,zn1,ch2,zn2);
                break;//2
            case 4:
                Input_2(ch1,zn1,ch2,zn2);
                Chastnoe(ch1,zn1,ch2,zn2);
                break;//2
            case 5:
                Input_2(ch1,zn1,ch2,zn2);
                Sravnenie(ch1,zn1,ch2,zn2);
                break;//2
            case 6:
                Input_1(ch1,zn1);
                Reduction_1(ch1,zn1);
                break;//1
            case 7:
                Input_1(ch1,zn1);
                Des_drob(ch1,zn1);
                break;//1
            case 0:
                SetConsoleCP(CP_UTF8);
                SetConsoleOutputCP(CP_UTF8); break;// запуск main главного меню
            default: cout << "Неверный ввод. Попробуйте снова" << endl; break;
        }
    }while(t!=0);
}