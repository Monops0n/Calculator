#include <iostream>
#include <Windows.h>
#include "Polynomials.h"

int mainPoly()
{
	int num;
	setlocale(0, "");
	do
	{
		printf_s("\t+-----------------------------------------------+\n");
		printf_s("\t| ����������� �����������, �������� �������\t|\n");
		printf_s("\t+-----------------------------------------------+\n");
		printf_s("\t|1 - ������� ����������� � �������\t\t|\n");
		printf_s("\t|2 - �������� �����������\t\t\t|\n");
		printf_s("\t|3 - ��������� �����������\t\t\t|\n");
		printf_s("\t|4 - ��������� �����������\t\t\t|\n");
		printf_s("\t|5 - ��������� ���������� �� �����\t\t|\n");
		printf_s("\t|6 - ���������� ����������� �� ����������\t|\n");
		printf_s("\t|7 - �����\t\t\t\t\t|\n");
		printf_s("\t+-----------------------------------------------+\n");
		do
		{
			scanf_s("%d", &num);
			if (num != 1 && num != 2 && num != 3 && num != 4 && num != 5 && num != 6 && num != 7)
			{
				printf_s("������� ���������� ������\n");
			}

		} while (num != 1 && num != 2 && num != 3 && num != 4 && num != 5 && num != 6 && num != 7);

		switch (num)
		{
		case 1:firstTask();break;
		case 2:secondTask(); break;
		case 3:thirdTask(); break;
		case 4:fourthTask();break;
		case 5:fifthTask();break;
		case 6:sixthTask();break;
		case 7:clear();break;
		}
	} while (num != 7);
	return 0;
}
