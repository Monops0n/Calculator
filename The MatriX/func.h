#pragma once
void free(float** A, int str, int stl);
void inputMat(float** A, int str, int stl);
void outputMat(float** A, int str, int stl);
void plusNum(float** A, int str, int stl, float num);
void minusNum(float** A, int str, int stl, float num);
void starNum(float** A, int str, int stl, float num);
void plusMat(float** A, float** B, int str, int stl);
void minusMat(float** A, float** B, int str, int stl);
void starMat(float** A, float** B, float** result, int strA, int stlA, int stlB);
void transMat(float** A, float** result, int str, int stl);
float deterMat(float** A, int str);
void algMat(float** A, float** result, int str);