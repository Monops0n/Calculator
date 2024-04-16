#include "komba.h"

long long int factorial(int n)
{
    long long int f = 1, i;
    for (i = 2; i <= n; ++i)
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
        cout << "\t¬ведите кол-во элементов <<N>>: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "\tќшибка, N не может быть меньше или равно нулю, повторите ввод..." << endl;
        }
    } while (n <= 0);
    do
    {
        cout << "\t¬ведите кол-во €чеек <<K>>: ";
        cin >> k;
        if (k <= 0)
        {
            cout << "\tќшибка, K не может быть меньше или равно нулю, повторите ввод..." << endl;
        }
    } while (k <= 0);

    cout << "\t–азмещение с повторением при N = " << n << ", K = " << k << " получитс€ равным: " << pow(n, k) << endl << endl << endl;

}

void tsk2()
{
    long long int n, k;
    do
    {
        cout << "\t¬ведите кол-во элементов <<N>>: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "\tќшибка, N не может быть меньше или равно нулю, повторите ввод..." << endl;
        }
    } while (n <= 0);
    do
    {
        cout << "\t¬ведите кол-во €чеек <<K>>: ";
        cin >> k;
        if (k <= 0)
        {
            cout << "\tќшибка, K не может быть меньше или равно нулю, повторите ввод..." << endl;
        }
    } while (k <= 0);

    cout << "\t–азмещение без повторений при N = " << n << ", K = " << k << " получитс€ равным: " << factorial(n) / factorial(n - k) << endl << endl << endl;
}

void tsk3()
{
    long long int n, k;
    do
    {
        cout << "\t¬ведите кол-во элементов <<N>>: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "\tќшибка, N не может быть меньше или равно нулю, повторите ввод..." << endl;
        }
    } while (n <= 0);
    do
    {
        cout << "\t¬ведите кол-во €чеек <<K>>: ";
        cin >> k;
        if (k <= 0)
        {
            cout << "\tќшибка, K не может быть меньше или равно нулю, повторите ввод..." << endl;
        }
    } while (k <= 0);

    cout << "\t—очетание с повторени€ми при N = " << n << ", K = " << k << " получитс€ равным: " << factorial(n + k - 1) / (factorial(k) * factorial(n - 1)) << endl << endl << endl;
}

void tsk4()
{
    long long int n, k;
    do
    {
        cout << "\t¬ведите кол-во элементов <<N>>: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "\tќшибка, N не может быть меньше или равно нулю, повторите ввод..." << endl;
        }
    } while (n <= 0);
    do
    {
        cout << "\t¬ведите кол-во €чеек <<K>>: ";
        cin >> k;
        if (k <= 0)
        {
            cout << "\tќшибка, K не может быть меньше или равно нулю, повторите ввод..." << endl;
        }
    } while (k <= 0);

    cout << "\t—очетание без повторений при N = " << n << ", K = " << k << " получитс€ равным: " << factorial(n) / (factorial(k) * factorial(n - k)) << endl << endl << endl;
}

void tsk5()
{
    long long int n;
    do
    {
        cout << "\t¬ведите кол-во элементов <<N>>: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "\tќшибка, N не может быть меньше или равно нулю, повторите ввод..." << endl;
        }
    } while (n <= 0);

    cout << "\t—очетание без повторений при N = " << n << " получитс€ равным: " << factorial(n) << endl << endl << endl;
}