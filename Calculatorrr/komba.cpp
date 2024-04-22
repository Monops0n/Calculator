#include "komba.h"

long long int factorial(int n)
{
    long long int f = 1, i;
    for (i = 1; i <= n; ++i)
    {
        f = f * i;
    }
    return f;
}

void tsk1()
{
    long long int n, k;
    do
    {
        cout << "\tВведите кол-во элементов <<N>>: ";
        cin >> n;
        if (n < 0)
        {
            cout << "\tОшибка, N не может быть меньше нуля, повторите ввод..." << endl;
        }
    } while (n < 0);
    do
    {
        cout << "\tВведите кол-во ячеек <<K>>: ";
        cin >> k;
        if (k < 0)
        {
            cout << "\tОшибка, K не может быть меньше нуля, повторите ввод..." << endl;
        }
    } while (k < 0);

    cout << "\tРазмещение с повторением при N = " << n << ", K = " << k << " получится равным: " << pow(n, k) << endl << endl << endl;
}

void tsk2()
{
    long long int n, k;
    do
    {
        do
        {
            cout << "\tВведите кол-во элементов <<N>>: ";
            cin >> n;
            if (n <= 0)
            {
                cout << "\tОшибка, N не может быть меньше или равно нулю, повторите ввод..." << endl;
            }
        } while (n <= 0);
        do
        {
            cout << "\tВведите кол-во ячеек <<K>>: ";
            cin >> k;
            if (k < 0)
            {
                cout << "\tОшибка, K не может быть меньше нуля, повторите ввод..." << endl;
            }
        } while (k < 0);
        if (n <= k)cout << "\tN не может быть меньше или равно K, повторите ввод..." << endl;
    } while (n <= k);
    cout << "\tРазмещение без повторений при N = " << n << ", K = " << k << " получится равным: " << factorial(n) / factorial(n - k) << endl << endl << endl;
}

void tsk3()
{
    long long int n, k;
    do
    {
        cout << "\tВведите кол-во элементов <<N>>: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "\tОшибка, N не может быть меньше или равно нулю, повторите ввод..." << endl;
        }
    } while (n <= 0);
    do
    {
        cout << "\tВведите кол-во ячеек <<K>>: ";
        cin >> k;
        if (k <= 0)
        {
            cout << "\tОшибка, K не может быть меньше или равно нулю, повторите ввод..." << endl;
        }
    } while (k <= 0);

    cout << "\tСочетание с повторениями при N = " << n << ", K = " << k << " получится равным: " << factorial(n + k - 1) / (factorial(k) * factorial(n - 1)) << endl << endl << endl;
}

void tsk4()
{
    long long int n, k;
    do
    {
        do
        {
            cout << "\tВведите кол-во элементов <<N>>: ";
            cin >> n;
            if (n <= 0)
            {
                cout << "\tОшибка, N не может быть меньше или равно нулю, повторите ввод..." << endl;
            }
        } while (n <= 0);
        do
        {
            cout << "\tВведите кол-во ячеек <<K>>: ";
            cin >> k;
            if (k <= 0)
            {
                cout << "\tОшибка, K не может быть меньше или равно нулю, повторите ввод..." << endl;
            }
        } while (k <= 0);
        if (n <= k)cout << "\tN не может быть меньше или равно K, повторите ввод..." << endl;
    } while (n <= k);
    cout << "\tСочетание без повторений при N = " << n << ", K = " << k << " получится равным: " << factorial(n) / (factorial(k) * factorial(n - k)) << endl << endl << endl;
}

void tsk5()
{
    long long int n;
    do
    {
        cout << "\tВведите кол-во элементов <<N>>: ";
        cin >> n;
        if (n < 0)
        {
            cout << "\tОшибка, N не может быть меньше нуля, повторите ввод..." << endl;
        }
    } while (n < 0);

    cout << "\tСочетание без повторений при N = " << n << " получится равным: " << factorial(n) << endl << endl << endl;
}
