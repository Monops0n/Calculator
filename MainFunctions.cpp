#include "Functions.h"
void MAIN_FUNCTIONS()
{
    int choice;
    do
    {
        cout << "\t+----------------------------------------------------------------------------------+" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t|                         Калькулятор работы с функциями                           |" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t+----------------------------------------------------------------------------------+" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t|    1 - Вычисление определенного интеграла на отрезке.                            |" << endl;
        cout << "\t|    2 - Построение графика функции(SDL).                                          |" << endl;
        cout << "\t|    3 - Поиск корня Y=0 на отрезке.                                               |" << endl;
        cout << "\t|    4 - Поиск экстремумов на отрезке.                                             |" << endl;
        cout << "\t|    5 - Назад.                                                                    |" << endl;
        cout << "\t|                                                                                  |" << endl;
        cout << "\t+----------------------------------------------------------------------------------+" << endl << endl << endl;

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            choice = 0;
        }

        switch (choice) {
        case 1:
            DefiniteIntegral();
            Sleep(1000);
            break;
        case 2:
            graphics();
            Sleep(1000);
            break;
        case 3:
            squareOnRange();
            Sleep(1000);
            break;
        case 4:
            extremumsOnRange();
            Sleep(1000);
            break;
        case 5:
            cout << "Возврат назад..." << endl;
            Sleep(1000);
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 5);
}