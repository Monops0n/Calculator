#include "komba.h"

void main_KOMBA()
{
    setlocale(LC_ALL, "ru");
    int zadanie;
    do
    {
        cout << "\t+-----------------------------------------------------+" << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t|                   �������������                     |" << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t+-----------------------------------------------------+" << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t|    1 - ���������� � ������������.                   |" << endl;
        cout << "\t|    2 - ���������� ��� ����������.                   |" << endl;
        cout << "\t|    3 - ��������� � ������������.                    |" << endl;
        cout << "\t|    4 - ��������� ��� ����������.                    |" << endl;
        cout << "\t|    5 - ������������.                                |" << endl;
        cout << "\t|    6 - �����.                                       |" << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t+-----------------------------------------------------+" << endl << endl << endl;
        cout << "\t";
        cin >> zadanie;
        switch (zadanie)
        {
        case 1:tsk1(); break;
        case 2:tsk2(); break;
        case 3:tsk3(); break;
        case 4:tsk4(); break;
        case 5:tsk5(); break;
        case 6:cout << "����� �� ���������....." << endl << endl << endl; break;
        }
        if (zadanie != 1 && zadanie != 2 && zadanie != 3 && zadanie != 1 && zadanie != 4 && zadanie != 5 && zadanie != 6) cout << "\t������ �������� ���, ���������� ��� ���..." << endl << endl;
    } while (zadanie != 6);
}