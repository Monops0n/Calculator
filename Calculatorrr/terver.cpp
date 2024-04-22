#include "terver.h"

void task1()
{
    double P;
    int m, n;
    do
    {
        cout << "\tУкажите кол-во событий: ";
        cin >> n;
        if (n <= 0) cout << "\tКол-во событий не может быть равно или меньше нуля, повторите ввод... " << endl;
    } while (n <= 0);
    do
    {
        cout << "\tУкажите кол-во благоприятных событий: ";
        cin >> m;
        if (m <= 0 || m > n) cout << "\tКол-во благоприятных событий не может быть равно или меньше нуля а также быть больше общего кол-ва событий, повторите ввод... " << endl;
    } while (m <= 0 || m > n);
    P = m*1.0 / n;
    cout << "\tВероятность благоприятного события равна : " << P * 100 << "%" << endl << endl << endl;
}

void task2()
{
    double x[100], p[100], E = 0, D = 0;
    int count;
    double checkp = 0;
    cout << "\tВведите кол-во элементов для нахождения дисперсии: ";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cout << "\tВведите величину № " << i << " : ";
        cin >> x[i];
        do
        {
            cout << "\tВведите вероятность величины № " << i << " : ";
            cin >> p[i];
            if (p[i] < 0 || p[i]>1) cout << "\tВероятность лежит в границах [0;1], повторите ввод..." << endl;
        } while (p[i] < 0 || p[i]>1);
        E += x[i] * p[i];
    }

    for (int i = 0; i < count; i++)
    {
        checkp += p[i];
        D += x[i] * x[i] * p[i];
    }
    if (checkp != 1)
    {
        cout << "\tОшибка! Сумма всех вероятностей получилась не равна единице, запуск программы сначала..." << endl;
        task2();
        return;
    }
    else
    {
        cout << "\tДисперсия для дискретного распределения величин равна : " << D-E << endl << endl << endl;
    }
}

void task3()
{
    double x[100], p[100], E = 0, D = 0;
    int count;
    double checkp = 0;
    cout << "\tВведите кол-во элементов для нахождения дисперсии: ";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        cout << "\tВведите величину № " << i << " : ";
        cin >> x[i];
        do
        {
            cout << "\tВведите вероятность величины № " << i << " : ";
            cin >> p[i];
            if (p[i] < 0 || p[i]>1) cout << "\tВероятность лежит в границах [0;1], повторите ввод..." << endl;
        } while (p[i] < 0 || p[i]>1);
        E += x[i] * p[i];
        checkp += p[i];
    }
    if (checkp != 1)
    {
        cout << "\tОшибка! Сумма всех вероятностей получилась не равна единице, запуск программы сначала..." << endl;
        task3();
        return;
    }
    else
    {
        cout << "\tМат. ожидание для дискретного распределения величин равно : " << E << endl << endl << endl;
    }
}
