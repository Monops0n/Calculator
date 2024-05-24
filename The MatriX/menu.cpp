#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include<math.h>
#include"func.h"

void mainmat() {
	int choice;
	do {
		printf_s("\t+----------------------------------------------------------------------------------+\n");
		printf_s("\t|                                                                                  |\n");
		printf_s("\t|   Матричный калькулятор, выбор функции                                           |\n");
		printf_s("\t|                                                                                  |\n");
		printf_s("\t+----------------------------------------------------------------------------------+\n");
		printf_s("\t|                                                                                  |\n");
		printf_s("\t|    0 - Выход                                                                     |\n");
		printf_s("\t|    1 - Сложение матриц.                                                          |\n");
		printf_s("\t|    2 - Вычитание матриц.                                                         |\n");
		printf_s("\t|    3 - Умножение матриц.                                                         |\n");
		printf_s("\t|    4 - Умножение матрицы на число.                                               |\n");
		printf_s("\t|    5 - Сложение матрицы с числом.                                                |\n");
		printf_s("\t|    6 - Вычитание матрицы с числом.                                               |\n");
		printf_s("\t|    7 - Транспонирование матрицы.                                                 |\n");
		printf_s("\t|    8 - Нахождение обратной матрицы.                                              |\n");
		printf_s("\t|    9 - Нахождение определителя                                                   |\n");
		printf_s("\t|                                                                                  |\n");
		printf_s("\t+----------------------------------------------------------------------------------+\n");
		scanf_s("%d", &choice);
		switch (choice)
		{
		case 0: break;
		case 1:
		{
			float** A;
			float** B;
			int stlA, strA, stlB, strB;
			do {
				do {
					printf_s("Ввод количества строк первой матрицы "); scanf_s("%d", &strA);
					if (strA < 1) printf_s("Ошибка ввода\n");
				} while (strA < 1);
				do {
					printf_s("Ввод количества столбцов первой матрицы "); scanf_s("%d", &stlA);
					if (stlA < 1) printf_s("Ошибка ввода\n");
				} while (stlA < 1);
				do {
					printf_s("Ввод количества строк второй матрицы "); scanf_s("%d", &strB);
					if (strB < 1) printf_s("Ошибка ввода\n");
				} while (strB < 1);
				do {
					printf_s("Ввод количества столбцов второй матрицы "); scanf_s("%d", &stlB);
					if (stlB < 1) printf_s("Ошибка ввода\n");
				} while (stlB < 1);
				if (stlA != stlB || strA != strB)
					printf_s("Ошибка! Матрицы должны быть одного размера\n");
			} while (stlA != stlB || strA != strB);
			A = (float**)malloc(strA * sizeof(float*));
			B = (float**)malloc(strB * sizeof(float*));
			printf_s("Первая матрица:\n");
			inputMat(A, strA, stlA);
			printf_s("Вторая матрица:\n");
			inputMat(B, strB, stlB);
			plusMat(A,B,strA,stlA);
			outputMat(A,strA,stlA);
			free(A, strA, stlA);
			free(B,strB, stlB);
			break;
		}
		case 2:
		{
			float** A;
			float** B;
			int stlA, strA, stlB, strB;
			do {
				do {
					printf_s("Ввод количества строк первой матрицы "); scanf_s("%d", &strA);
					if (strA < 1) printf_s("Ошибка ввода\n");
				} while (strA < 1);
				do {
					printf_s("Ввод количества столбцов первой матрицы "); scanf_s("%d", &stlA);
					if (stlA < 1) printf_s("Ошибка ввода\n");
				} while (stlA < 1);
				do {
					printf_s("Ввод количества строк второй матрицы "); scanf_s("%d", &strB);
					if (strB < 1) printf_s("Ошибка ввода\n");
				} while (strB < 1);
				do {
					printf_s("Ввод количества столбцов второй матрицы "); scanf_s("%d", &stlB);
					if (stlB < 1) printf_s("Ошибка ввода\n");
				} while (stlB < 1);
				if (stlA != stlB || strA != strB)
					printf_s("Ошибка! Матрицы должны быть одного размера\n");
			} while (stlA != stlB || strA != strB);
			A = (float**)malloc(strA * sizeof(float*));
			B = (float**)malloc(strB * sizeof(float*));
			printf_s("Первая матрица:\n");
			inputMat(A, strA, stlA);
			printf_s("Вторая матрица:\n");
			inputMat(B, strB, stlB);
			minusMat(A, B, strA, stlA);
			outputMat(A, strA, stlA);
			free(A, strA, stlA);
			free(B, strB, stlB);
			break;
		}
		case 3:
		{
			float** A;
			float** B;
			float** result;
			int stlA, strA, stlB, strB;
			do {
				do {
					printf_s("Ввод количества строк первой матрицы "); scanf_s("%d", &strA);
					if (strA < 1) printf_s("Ошибка ввода\n");
				} while (strA < 1);
				do {
					printf_s("Ввод количества столбцов первой матрицы "); scanf_s("%d", &stlA);
					if (stlA < 1) printf_s("Ошибка ввода\n");
				} while (stlA < 1);
				do {
					printf_s("Ввод количества строк второй матрицы "); scanf_s("%d", &strB);
					if (strB < 1) printf_s("Ошибка ввода\n");
				} while (strB < 1);
				do {
					printf_s("Ввод количества столбцов второй матрицы "); scanf_s("%d", &stlB);
					if (stlB < 1) printf_s("Ошибка ввода\n");
				} while (stlB < 1);
				if (stlA != strB)
					printf_s("Ошибка! Число столбцов первой матрицы должно быть равно числу строк второй матрицы\n");
			} while (stlA != strB);
			A = (float**)malloc(strA * sizeof(float*));
			B = (float**)malloc(strB * sizeof(float*));
			result = (float**)malloc(strA * sizeof(float*));
			printf_s("Первая матрица:\n");
			inputMat(A, strA, stlA);
			printf_s("Вторая матрица:\n");
			inputMat(B, strB, stlB);
			starMat(A, B, result, strA, stlA, stlB);
			outputMat(result, strA, stlB);
			free(A, strA, strA);
			free(B, strB, stlB);
			free(result, strA, stlB);
			break;
		}
		case 4: {
			float num;
			float** A;
			int stl, str;
			do {
				printf_s("Ввод количества строк матрицы "); scanf_s("%d", &str);
				if (str < 1) printf_s("Ошибка ввода\n");
			} while (str < 1);
			do {
				printf_s("Ввод количества столбцов матрицы "); scanf_s("%d", &stl);
				if (stl < 1) printf_s("Ошибка ввода\n");
			} while (stl < 1);
			A = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			printf_s("Ввод числа "); scanf_s("%f", &num);
			starNum(A, str, stl, num);
			outputMat(A, str, stl);
			free(A, str, stl);
			break;
		}
		case 5:
		{
			float num;
			float **A;
			int stl, str;
			do {
				printf_s("Ввод количества строк матрицы "); scanf_s("%d", &str);
				if (str < 1) printf_s("Ошибка ввода\n");
			} while (str < 1);
			do {
				printf_s("Ввод количества столбцов матрицы "); scanf_s("%d", &stl);
				if (stl < 1) printf_s("Ошибка ввода\n");
			} while (stl < 1);
			A = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			printf_s("Ввод числа "); scanf_s("%f", &num);
			plusNum(A, str, stl, num);
			outputMat(A, str, stl);
			free(A, str, stl);
			break;
		}
		case 6: {
			float num;
			float** A;
			int stl, str;
			do {
				printf_s("Ввод количества строк матрицы "); scanf_s("%d", &str);
				if (str < 1) printf_s("Ошибка ввода\n");
			} while (str < 1);
			do {
				printf_s("Ввод количества столбцов матрицы "); scanf_s("%d", &stl);
				if (stl < 1) printf_s("Ошибка ввода\n");
			} while (stl < 1);
			A = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			printf_s("Ввод числа "); scanf_s("%f", &num);
			minusNum(A, str, stl, num);
			outputMat(A, str, stl);
			free(A, str, stl);
			break;
		}
		case 7:
		{
			float** A;
			float** result;
			int stl, str;
			do {
				printf_s("Ввод количества строк матрицы "); scanf_s("%d", &str);
				if (str < 1) printf_s("Ошибка ввода\n");
			} while (str < 1);
			do {
				printf_s("Ввод количества столбцов матрицы "); scanf_s("%d", &stl);
				if (stl < 1) printf_s("Ошибка ввода\n");
			} while (stl < 1);
			A = (float**)malloc(str * sizeof(float*));
			result = (float**)malloc(stl * sizeof(float*));
			inputMat(A, str, stl);
			transMat(A, result, str, stl);
			outputMat(result, stl, str);
			free(A, str, stl);
			free(result, stl, str);
			break;
		}
		case 8:
		{
			float** A;
			float** result;
			float det;
			int stl, str;
			do {
				do {
					printf_s("Ввод количества строк матрицы "); scanf_s("%d", &str);
					if (str < 1) printf_s("Ошибка ввода\n");
				} while (str < 1);
				do {
					printf_s("Ввод количества столбцов матрицы "); scanf_s("%d", &stl);
					if (stl < 1) printf_s("Ошибка ввода\n");
				} while (stl < 1);
				if (stl != str)
					printf_s("Ошибка! Матрица должна быть квадратной\n");
			} while (stl != str);
			A = (float**)malloc(str * sizeof(float*));
			result = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			det = deterMat(A, str);
			if (det == 0)
			{
				printf_s("Матрица не имеет обратную матрицу, так как она не вырождена(ее определитель равен 0)\n");
				break;
			}
			algMat(A,result, str);
			transMat(result, A, str, stl);
			starNum(A, str, stl, 1 / det);
			outputMat(A, str, stl);
			free(A, str, stl);
			free(result, str, str);
			break;
		}
		case 9:
		{
			float** A;
			float result;
			int stl, str;
			do {
				do {
					printf_s("Ввод количества строк матрицы "); scanf_s("%d", &str);
					if (str < 1) printf_s("Ошибка ввода\n");
				} while (str < 1);
				do {
					printf_s("Ввод количества столбцов матрицы "); scanf_s("%d", &stl);
					if (stl < 1) printf_s("Ошибка ввода\n");
				} while (stl < 1);
				if (stl != str)
					printf_s("Ошибка! Матрица должна быть квадратной\n");
			} while (stl != str);
			A = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			result = deterMat(A, str);
			printf_s("%f\n", result);
			free(A, str, stl);
			break;
		}
		default:printf_s("Ошибка ввода\n"); break;
		}
	} while (choice != 0);
}
