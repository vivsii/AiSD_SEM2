#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;
double rekursia(double n);
double cycle(double n);

int main()
{
	setlocale(LC_CTYPE, "Russian");
	double n = 0;
	cout << "Введите N-ное число ряда Фибоначчи: " << endl;
	cin >> n;
	clock_t start1 = clock();
	cout << "Полученный результат через рекурсию:" << rekursia(n) << endl;
	clock_t end1 = clock();
	float sec1 = (float)(end1 - start1) / CLOCKS_PER_SEC;
	int min1 = (int) sec1 / 60;
	printf("Расчетное время рекурсией %d в минут %5.12f секунд\n", min1, sec1);
	clock_t start2 = clock();
	cout << "Полученный результат через цикл: " << cycle(n) << endl;
	clock_t end2 = clock();
	float sec2 = (float)(end2 - start2) / CLOCKS_PER_SEC;
	int min2 = (int)sec2 / 60;
	printf("Расчетное время циклом %d минут %5.12f секунд\n", min2, sec2);
	printf("Разница между затраченным временен: %5.12f\n", abs(sec2 - sec1));
	return 0;
}

double cycle(double n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n = 1)
	{
		return 1;
	}
	int i1 = 1, i2 = 1, next = 0;
	for (int i = 0; i < n - 2; i++)
	{
		next = i1 + i2;
		i1 = i2;
		i2 = next;
	}

	return  next;
}

double rekursia(double n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

	return rekursia(n - 1) + rekursia(n - 2);
}
