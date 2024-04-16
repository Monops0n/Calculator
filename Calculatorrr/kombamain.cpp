#include "komba.h"

void main_KOMBA()
{
    setlocale(LC_ALL, "ru");
    int zadanie;
    do
    {
        cout << "\t+-----------------------------------------------------+" << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t|                   Комбинаторика                     |" << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t+-----------------------------------------------------+" << endl;
        cout << "\t|                                                     |" << endl;
        cout << "\t|    1 - Размещение с повторениями.                   |" << endl;
        cout << "\t|    2 - Размещение без повторений.                   |" << endl;
        cout << "\t|    3 - Сочетание с повторениями.                    |" << endl;
        cout << "\t|    4 - Сочетание без повторений.                    |" << endl;
        cout << "\t|    5 - Перестановки.                                |" << endl;
        cout << "\t|    6 - Назад.                                       |" << endl;
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
        case 6:cout << "Выход из программы....." << endl << endl << endl; break;
        }
        if (zadanie != 1 && zadanie != 2 && zadanie != 3 && zadanie != 1 && zadanie != 4 && zadanie != 5 && zadanie != 6) cout << "\tТакого варианта нет, попробуйте ещё раз..." << endl << endl;
    } while (zadanie != 6);
}
