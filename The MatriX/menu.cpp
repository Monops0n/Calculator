#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include<math.h>
int main() {
	setlocale(LC_ALL, "ru");
	int choice;
	do {
		printf("\t+----------------------------------------------------------------------------------+\n");
		printf("\t|                                                                                  |\n");
		printf("\t|   Матричный калькулятор, выбор функции                                           |\n");
		printf("\t|                                                                                  |\n");
		printf("\t+----------------------------------------------------------------------------------+\n");
		printf("\t|                                                                                  |\n");
		printf("\t|    0 - Выход                                                                     |\n");
		printf("\t|    1 - Сложение матриц.                                                          |\n");
		printf("\t|    2 - Вычитание матриц.                                                         |\n");
		printf("\t|    3 - Умножение матриц.                                                         |\n");
		printf("\t|    4 - Умножение матрицы на число.                                               |\n");
		printf("\t|    5 - Сложение матрицы с числом.                                                |\n");
		printf("\t|    6 - Вычитание матрицы с числом.                                               |\n");
		printf("\t|    7 - Транспонирование матрицы.                                                 |\n");
		printf("\t|    8 - Нахождение обратной матрицы.                                              |\n");
		printf("\t|    9 - Нахождение определителя                                                   |\n");
		printf("\t|                                                                                  |\n");
		printf("\t+----------------------------------------------------------------------------------+\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:return 0;
		case 1:
		{
			float** A;
			float** B;
			int stlA, strA, stlB, strB;
			do {
				do {
					printf("Ввод количества строк первой матрицы "); scanf("%d", &strA);
					if (strA < 1) printf("Ошибка ввода\n");
				} while (strA < 1);
				do {
					printf("Ввод количества столбцов первой матрицы "); scanf("%d", &stlA);
					if (stlA < 1) printf("Ошибка ввода\n");
				} while (stlA < 1);
				do {
					printf("Ввод количества строк второй матрицы "); scanf("%d", &strB);
					if (strB < 1) printf("Ошибка ввода\n");
				} while (strB < 1);
				do {
					printf("Ввод количества столбцов второй матрицы "); scanf("%d", &stlB);
					if (stlB < 1) printf("Ошибка ввода\n");
				} while (stlB < 1);
				if (stlA != stlB || strA != strB)
					printf("Ошибка! Матрицы должны быть одного размера\n");
			} while (stlA != stlB || strA != strB);
			A = (float**)malloc(strA * sizeof(float*));
			B = (float**)malloc(strB * sizeof(float*));
			printf("Первая матрица:\n");
			inputMat(A, strA, stlA);
			printf("Вторая матрица:\n");
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
					printf("Ввод количества строк первой матрицы "); scanf("%d", &strA);
					if (strA < 1) printf("Ошибка ввода\n");
				} while (strA < 1);
				do {
					printf("Ввод количества столбцов первой матрицы "); scanf("%d", &stlA);
					if (stlA < 1) printf("Ошибка ввода\n");
				} while (stlA < 1);
				do {
					printf("Ввод количества строк второй матрицы "); scanf("%d", &strB);
					if (strB < 1) printf("Ошибка ввода\n");
				} while (strB < 1);
				do {
					printf("Ввод количества столбцов второй матрицы "); scanf("%d", &stlB);
					if (stlB < 1) printf("Ошибка ввода\n");
				} while (stlB < 1);
				if (stlA != stlB || strA != strB)
					printf("Ошибка! Матрицы должны быть одного размера\n");
			} while (stlA != stlB || strA != strB);
			A = (float**)malloc(strA * sizeof(float*));
			B = (float**)malloc(strB * sizeof(float*));
			printf("Первая матрица:\n");
			inputMat(A, strA, stlA);
			printf("Вторая матрица:\n");
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
					printf("Ввод количества строк первой матрицы "); scanf("%d", &strA);
					if (strA < 1) printf("Ошибка ввода\n");
				} while (strA < 1);
				do {
					printf("Ввод количества столбцов первой матрицы "); scanf("%d", &stlA);
					if (stlA < 1) printf("Ошибка ввода\n");
				} while (stlA < 1);
				do {
					printf("Ввод количества строк второй матрицы "); scanf("%d", &strB);
					if (strB < 1) printf("Ошибка ввода\n");
				} while (strB < 1);
				do {
					printf("Ввод количества столбцов второй матрицы "); scanf("%d", &stlB);
					if (stlB < 1) printf("Ошибка ввода\n");
				} while (stlB < 1);
				if (stlA != strB)
					printf("Ошибка! Число столбцов первой матрицы должно быть равно числу строк второй матрицы\n");
			} while (stlA != strB);
			A = (float**)malloc(strA * sizeof(float*));
			B = (float**)malloc(strB * sizeof(float*));
			result = (float**)malloc(strA * sizeof(float*));
			printf("Первая матрица:\n");
			inputMat(A, strA, stlA);
			printf("Вторая матрица:\n");
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
				printf("Ввод количества строк матрицы "); scanf("%d", &str);
				if (str < 1) printf("Ошибка ввода\n");
			} while (str < 1);
			do {
				printf("Ввод количества столбцов матрицы "); scanf("%d", &stl);
				if (stl < 1) printf("Ошибка ввода\n");
			} while (stl < 1);
			A = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			printf("Ввод числа "); scanf("%f", &num);
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
				printf("Ввод количества строк матрицы "); scanf("%d", &str);
				if (str < 1) printf("Ошибка ввода\n");
			} while (str < 1);
			do {
				printf("Ввод количества столбцов матрицы "); scanf("%d", &stl);
				if (stl < 1) printf("Ошибка ввода\n");
			} while (stl < 1);
			A = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			printf("Ввод числа "); scanf("%f", &num);
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
				printf("Ввод количества строк матрицы "); scanf("%d", &str);
				if (str < 1) printf("Ошибка ввода\n");
			} while (str < 1);
			do {
				printf("Ввод количества столбцов матрицы "); scanf("%d", &stl);
				if (stl < 1) printf("Ошибка ввода\n");
			} while (stl < 1);
			A = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			printf("Ввод числа "); scanf("%f", &num);
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
				printf("Ввод количества строк матрицы "); scanf("%d", &str);
				if (str < 1) printf("Ошибка ввода\n");
			} while (str < 1);
			do {
				printf("Ввод количества столбцов матрицы "); scanf("%d", &stl);
				if (stl < 1) printf("Ошибка ввода\n");
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
					printf("Ввод количества строк матрицы "); scanf("%d", &str);
					if (str < 1) printf("Ошибка ввода\n");
				} while (str < 1);
				do {
					printf("Ввод количества столбцов матрицы "); scanf("%d", &stl);
					if (stl < 1) printf("Ошибка ввода\n");
				} while (stl < 1);
				if (stl != str)
					printf("Ошибка! Матрица должна быть квадратной\n");
			} while (stl != str);
			A = (float**)malloc(str * sizeof(float*));
			result = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			det = deterMat(A, str);
			if (det == 0)
			{
				printf("Матрица не имеет обратную матрицу, так как она не вырождена(ее определитель равен 0)\n");
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
					printf("Ввод количества строк матрицы "); scanf("%d", &str);
					if (str < 1) printf("Ошибка ввода\n");
				} while (str < 1);
				do {
					printf("Ввод количества столбцов матрицы "); scanf("%d", &stl);
					if (stl < 1) printf("Ошибка ввода\n");
				} while (stl < 1);
				if (stl != str)
					printf("Ошибка! Матрица должна быть квадратной\n");
			} while (stl != str);
			A = (float**)malloc(str * sizeof(float*));
			inputMat(A, str, stl);
			result = deterMat(A, str);
			printf("%f\n", result);
			free(A, str, stl);
			break;
		}
		default:printf("Ошибка ввода\n"); break;
		}
	} while (choice != 0);
}
