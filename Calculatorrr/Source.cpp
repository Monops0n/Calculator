#include "Header.h"

void main()
{
    setlocale(LC_ALL, "ru");
    int zadanie;
    do
    {
        cout << "\t+-----------------------------------------------------+" << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t|                    �����������                      |" << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t+-----------------------------------------------------+" << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t|    1 - ����������� �����������                      |" << endl;
        cout << "\t|    2 - ����������� �������������                    |" << endl;
        cout << "\t|    3 - ���. ���. � ���. ����������                  |" << endl;
        cout << "\t|    4 - ��������� �����������                        |" << endl;
        cout << "\t|    5 - ����������� ������������ ������              |" << endl;
        cout << "\t|    6 - ������ � ���������                           |" << endl;
        cout << "\t|    7 - �����                                        |" << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t+-----------------------------------------------------+" << endl << endl << endl;
        cout << "\t";
        cin >> zadanie;
        switch (zadanie)
        {
        case 1: mainPoly(); break;
        case 2: main_KOMBA(); break;
        case 3: mainterver(); break;
        case 4: mainmat(); break;
        case 5: maindrob(); break;
        case 6: MAIN_FUNCTIONS(); break;
        case 7:cout << "����� �� ���������....." << endl << endl << endl; break;
        }
        if (zadanie != 1 && zadanie != 2 && zadanie != 3 && zadanie != 1 && zadanie != 4 && zadanie != 5 && zadanie != 6 && zadanie != 7) cout << "\t������ �������� ���, ���������� ��� ���..." << endl << endl;
    } while (zadanie != 7);
}