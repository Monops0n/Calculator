#include "terver.h"

void mainterver()
{
    setlocale(LC_ALL, "ru");
    int zadanie;
    do
    {
        cout << "\t+-------------------------------------------------------------------+" << endl;
        cout << "\t|                                                                   |" << endl;
        cout << "\t|   ����������� ������ ����������� � ���. ����������                |" << endl;
        cout << "\t|                                                                   |" << endl;
        cout << "\t+-------------------------------------------------------------------+" << endl;
        cout << "\t|                                                                   |" << endl;
        cout << "\t|    1 - ����������� m/n.                                           |" << endl;
        cout << "\t|    2 - ��������� ��� ����������� ������������� �������.           |" << endl;
        cout << "\t|    3 - ����. �������� ��� ����������� ������������� �������.      |" << endl;
        cout << "\t|    6 - �����.                                                     |" << endl;
        cout << "\t|                                                                   |" << endl;
        cout << "\t+-------------------------------------------------------------------+" << endl << endl << endl;
        cout << "\t";
        cin >> zadanie;
        switch (zadanie)
        {
        case 1:task1(); break;
        case 2:task2(); break;
        case 3:task3(); break;
        case 6:cout << "����� �� ���������....." << endl << endl << endl; break;
        }
        if (zadanie != 1 && zadanie != 2 && zadanie != 3 && zadanie != 1 && zadanie != 4 && zadanie != 5 && zadanie != 6) cout << "\t������ �������� ���, ���������� ��� ���..." << endl << endl;
    } while (zadanie != 6);
}