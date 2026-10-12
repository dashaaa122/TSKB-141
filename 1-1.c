#include <stdio.h>
#include <math.h>

/*
* @brief вычисляет значение функции А по заданной формуле
* @param x - значение переменной x
* @param y - значение переменной y
* @param z - значение переменной z
* @return рассчитанное значение
*/
double A(const double x, const double y, const double z);

/*
* @brief вычисляет значение функции B по заданной формуле
* @param x - значение переменной x
* @param y - значение переменной y
* @param z - значение переменной z
* @return рассчитанное значение
*/
double B(const double x, const double y, const double z);

/*
* @brief точка входа в программу
* @return возвращает 0, если программа выполнена корректно
*/
int main()
{
	const double x = 2;
	const double y = 0.7;
	const double z = -1;
	printf("A = %lf\n", A(x, y, z));
	printf("B = %lf", B(x, y, z));
	return 0;
}

double A(const double x, const double y, const double z)
{
	return cbrt(x * y * z + fabs(z * sin(y)));
}

double B(const double x, const double y, const double z)
{
	return y * cos(x * z * sin(y)) + 3;
}