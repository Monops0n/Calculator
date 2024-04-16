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
        cout << "\t������� ���-�� ��������� <<N>>: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "\t������, N �� ����� ���� ������ ��� ����� ����, ��������� ����..." << endl;
        }
    } while (n <= 0);
    do
    {
        cout << "\t������� ���-�� ����� <<K>>: ";
        cin >> k;
        if (k <= 0)
        {
            cout << "\t������, K �� ����� ���� ������ ��� ����� ����, ��������� ����..." << endl;
        }
    } while (k <= 0);

    cout << "\t���������� � ����������� ��� N = " << n << ", K = " << k << " ��������� ������: " << pow(n, k) << endl << endl << endl;

}

void tsk2()
{
    long long int n, k;
    do
    {
        cout << "\t������� ���-�� ��������� <<N>>: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "\t������, N �� ����� ���� ������ ��� ����� ����, ��������� ����..." << endl;
        }
    } while (n <= 0);
    do
    {
        cout << "\t������� ���-�� ����� <<K>>: ";
        cin >> k;
        if (k <= 0)
        {
            cout << "\t������, K �� ����� ���� ������ ��� ����� ����, ��������� ����..." << endl;
        }
    } while (k <= 0);

    cout << "\t���������� ��� ���������� ��� N = " << n << ", K = " << k << " ��������� ������: " << factorial(n) / factorial(n - k) << endl << endl << endl;
}

void tsk3()
{
    long long int n, k;
    do
    {
        cout << "\t������� ���-�� ��������� <<N>>: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "\t������, N �� ����� ���� ������ ��� ����� ����, ��������� ����..." << endl;
        }
    } while (n <= 0);
    do
    {
        cout << "\t������� ���-�� ����� <<K>>: ";
        cin >> k;
        if (k <= 0)
        {
            cout << "\t������, K �� ����� ���� ������ ��� ����� ����, ��������� ����..." << endl;
        }
    } while (k <= 0);

    cout << "\t��������� � ������������ ��� N = " << n << ", K = " << k << " ��������� ������: " << factorial(n + k - 1) / (factorial(k) * factorial(n - 1)) << endl << endl << endl;
}

void tsk4()
{
    long long int n, k;
    do
    {
        cout << "\t������� ���-�� ��������� <<N>>: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "\t������, N �� ����� ���� ������ ��� ����� ����, ��������� ����..." << endl;
        }
    } while (n <= 0);
    do
    {
        cout << "\t������� ���-�� ����� <<K>>: ";
        cin >> k;
        if (k <= 0)
        {
            cout << "\t������, K �� ����� ���� ������ ��� ����� ����, ��������� ����..." << endl;
        }
    } while (k <= 0);

    cout << "\t��������� ��� ���������� ��� N = " << n << ", K = " << k << " ��������� ������: " << factorial(n) / (factorial(k) * factorial(n - k)) << endl << endl << endl;
}

void tsk5()
{
    long long int n;
    do
    {
        cout << "\t������� ���-�� ��������� <<N>>: ";
        cin >> n;
        if (n <= 0)
        {
            cout << "\t������, N �� ����� ���� ������ ��� ����� ����, ��������� ����..." << endl;
        }
    } while (n <= 0);

    cout << "\t��������� ��� ���������� ��� N = " << n << " ��������� ������: " << factorial(n) << endl << endl << endl;
}