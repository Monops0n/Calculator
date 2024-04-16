#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include<math.h>
void free(float** A, int str, int stl) {
	for (int i = 0; i < str; i++)
		free(A[i]);
	free(A);
}
void inputMat(float** A, int str, int stl) {
	printf("Ввод матрицы\n");
	for (int i = 0; i < str; i++)
	{
		A[i] = (float*)malloc(stl * sizeof(float));
		for (int j = 0; j < stl; j++)
		{
			printf("Ввод элемента [%d][%d]: ", i, j);
			scanf("%f", &A[i][j]);
		}
	}
}
void outputMat(float** A, int str, int stl)
{
	printf("Полученная матрица:\n");
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < stl; j++)
			printf("%f ", A[i][j]);
		printf("\n");
	}
}
void plusNum(float** A, int str, int stl, float num)
{
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stl; j++)
			A[i][j] += num;
}
void minusNum(float** A, int str, int stl, float num)
{
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stl; j++)
			A[i][j] -= num;
}
void starNum(float** A, int str, int stl, float num)
{
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stl; j++)
			A[i][j] *= num;
}
void plusMat(float** A, float** B, int str, int stl)
{
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stl; j++)
			A[i][j] += B[i][j];
}
void minusMat(float** A, float** B, int str, int stl)
{
	for (int i = 0; i < str; i++)
		for (int j = 0; j < stl; j++)
			A[i][j] -= B[i][j];
}
void starMat(float** A, float** B, float** result, int strA, int stlA, int stlB)
{
	for (int i = 0; i < strA; i++)
	{
		result[i] = (float*)malloc(stlB * sizeof(float));
		for (int j = 0; j < stlB; j++)
		{
			result[i][j] = 0;
			for (int k = 0; k < stlA; k++)
				result[i][j] += A[i][k] * B[k][j];
		}
	}
}
void transMat(float** A, float** result, int str, int stl)
{
	for (int i = 0; i < stl; i++)
	{
		result[i] = (float*)malloc(str * sizeof(float));
		for (int j = 0; j < str; j++)
			result[i][j] = A[j][i];
	}
}
float deterMat(float** A, int str)
{
	float** minor;
	minor = (float**)malloc((str - 1) * sizeof(float*));
	int det = 0;
	if (str == 1)
		return A[0][0];
	for (int i = 0; i < str; i++)
	{
		for (int j = 0; j < str - 1; j++)
		{
			minor[j] = (float*)malloc((str - 1) * sizeof(float));
			for (int k = 0; k < str; k++)
				if (k != i)
					if (k < i)
						minor[j][k] = A[j + 1][k];
					else
						minor[j][k - 1] = A[j + 1][k];
		}
		det += pow(-1, i) * deterMat(minor, str - 1) * A[0][i];
	}
	return det;
}
void algMat(float** A, float** result, int str)
{
	float** temp;
	temp = (float**)malloc((str - 1) * sizeof(float*));
	for (int i = 0; i < str - 1; i++)
		temp[i] = (float*)malloc((str - 1) * sizeof(float));
	for (int i = 0; i < str; i++)
	{
		result[i] = (float*)malloc(str * sizeof(float));
		for (int j = 0; j < str; j++)
		{
			for (int k = 0; k < str; k++)
				for (int p = 0; p < str; p++)
				{
					if (k != i && p != j)
					{
						if (k < i && p < j)
							temp[k][p] = A[k][p];
						if (k > i && p < j)
							temp[k - 1][p] = A[k][p];
						if (k<i && p>j)
							temp[k][p - 1] = A[k][p];
						if (k > i && p > j)
							temp[k - 1][p - 1] = A[k][p];
					}
				}
			result[i][j] = pow(-1, i + j) * deterMat(temp, str - 1);
		}
	}
}