#define _CRT_SECURE_NO_WARNINGS
#define myround(x) ((int)((x)+0.5))
#define myround2(x) ((int)((x)-0.5))
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <malloc.h> 
#include <math.h>
int main() {
	int N, i,n,min,max,fl = 0;
	int *mas_drob;
	double sum,z,a = 0.0;
	double *mas;
	setlocale(LC_ALL, "Russian");
	printf("Введите количество генерируемых случайных чисел\t");
	scanf("%d", &N);
	if (N < 0) {
		printf("Ошибка!!! Количество не может быть отрицательным!!\n!");
		return 0;
	}
	if (N == 0) {
		printf("Ошибка!!! Количество не может быть равно нулю\n!");
		return 0;
	}
	printf("Установите границы генерируемых случайных чисел\n");
	printf("Установите минимальную границу\t");
	scanf("%d", &min);
	printf("Установите максимальную границу\t");
	scanf("%d", &max);
	if (min > max) {
		printf("Ошибка!!!! min > max\n ");
		return 0;
	}	
	mas = (double*)malloc(N * sizeof(double));
	mas_drob = (int*)malloc(N * sizeof(int));
	for (i = 0; i < N; i++) {
		mas[i] = (((double)rand()) / RAND_MAX) * (max - min) + min;
		mas[i] = floor(mas[i] * 100) / 100;
	}
	for (i = 0; i < N; i++) {
		if (mas[i] < 0) {
			z = mas[i] + fabs(ceil(mas[i]));
			a = z * 100.00;
			mas_drob[i] = fabs((myround2(a)));
		}
		else {
			z = mas[i] - floor(mas[i]);
			a = z * 100.00;
			mas_drob[i] = myround(a);
		}
	}
	fl = 0;
	sum = 0;
	n = 0;
	for (i = 0; i < N; i++) {
		fl = 0;
		n = 0;
		for (n = 0; n < N; n++){
			if (mas_drob[n] == i) {
				sum = sum - mas[i];
				fl = 1;
				break;
			}
		}
		if (fl == 0) {
			sum = sum + mas[i];
		}
	}
	printf("sum = %lf\n", sum);
	free(mas); 
	free(mas_drob);
	return 0;

}