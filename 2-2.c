#include <stdio.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

/**
 * @brief считывает вещественное число с консоли с проверкой на корректность ввода
 * @details функция использует scanf для чтения, если ввод не является числом
 *          программа выводит сообщение об ошибке и завершает работу с кодом 1
 * @return double - корректно введенное пользователем число
 */
double getDouble();

/**
 * @brief вычисляет значение кусочно-заданной функции согласно варианту 
 * @details функция реализует разветвленный алгоритм:
 *          - если x > 1: y = a * lg(x) + sqrt(|x|)
 *          - если x <= 1: y = 2a * cos(x) + 3x^2
 *          параметр a задан константой 0.9
 * @param x - значение аргумента функции
 * @return double - вычисленное значение функции y
 */
double calculate_y(const double x);

/**
 * @brief точка входа в программу
 * @details вызывает функции ввода и вычисления, выводит результат на экран
 * @return int - код возврата (0 при успешном завершении)
 */
int main()
{
    
    printf("параметр a = 0.9 (задан константой в условии)\n\n");

    printf("введите значение x: ");
    double x = getDouble();

    // Вызов функции вычисления
    double result = calculate_y(x);
    
    printf("\nрезультат:\n");
    printf("при x = %.4lf, y = %.5lf\n", x, result);

    return 0;
}

double getDouble()
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("ошибка: введено некорректное значение; введите число\n");
        exit(1);
    }
    return value;
}

double calculate_y(const double x)
{
    const double a = 0.9; // Параметр из задания
    double y = 0.0;

    if (x > 1)
    {
        // Ветвь 1: x > 1
        // y = a * lg(x) + sqrt(|x|)
        
        // Проверка ОДЗ логарифма (хотя при x > 1 она выполняется автоматически)
        if (x <= 0) 
        {
             printf("ошибка: аргумент логарифма должен быть положительным\n");
             exit(1);
        }

        // Для модуля используем fabs() (так как x - double).
        y = a * log10(x) + sqrt(fabs(x));
    }
    else
    {
        // Ветвь 2: x <= 1
        // y = 2a * cos(x) + 3x^2
        y = 2 * a * cos(x) + 3 * x * x;
    }

    return y;
}
