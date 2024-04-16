#include "terver.h"

void mainterver()
{
    setlocale(LC_ALL, "ru");
    int zadanie;
    do
    {
        cout << "\t+-------------------------------------------------------------------+" << endl;
        cout << "\t|                                                                   |" << endl;
        cout << "\t|   Калькулятор Теория вероятности и мат. статистика                |" << endl;
        cout << "\t|                                                                   |" << endl;
        cout << "\t+-------------------------------------------------------------------+" << endl;
        cout << "\t|                                                                   |" << endl;
        cout << "\t|    1 - Вероятность m/n.                                           |" << endl;
        cout << "\t|    2 - Дисперсия для дискретного распределения величин.           |" << endl;
        cout << "\t|    3 - Мать. ожидание для дискретного распределения величин.      |" << endl;
        cout << "\t|    6 - Назад.                                                     |" << endl;
        cout << "\t|                                                                   |" << endl;
        cout << "\t+-------------------------------------------------------------------+" << endl << endl << endl;
        cout << "\t";
        cin >> zadanie;
        switch (zadanie)
        {
        case 1:task1(); break;
        case 2:task2(); break;
        case 3:task3(); break;
        case 6:cout << "Выход из программы....." << endl << endl << endl; break;
        }
        if (zadanie != 1 && zadanie != 2 && zadanie != 3 && zadanie != 1 && zadanie != 4 && zadanie != 5 && zadanie != 6) cout << "\tТакого варианта нет, попробуйте ещё раз..." << endl << endl;
    } while (zadanie != 6);
}
