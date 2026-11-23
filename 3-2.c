#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/**
 * @brief считывает целое число с консоли и проверяет корректность ввода
 * @param message - сообщение-приглашение для пользователя (может быть NULL)
 * @return введенное целое число
 */
int getInt(const char* message);

/**
 * @brief считывает вещественное число с консоли и проверяет корректность ввода
 * @param message - сообщение-приглашение для пользователя (может быть NULL)
 * @return введенное вещественное число
 */
double getValue(const char* message);

/**
 * @brief проверяет, что число n является положительным
 * @param n - проверяемое число
 */
void checkPositive(const int n);

/**
 * @brief проверяет, что число e является положительным
 * @param e - проверяемое число
 */
void checkEpsilon(const double e);

/**
 * @brief вычисляет сумму первых n членов последовательности
 * @param n - количество членов последовательности для суммирования
 * @return сумма первых n членов
 */
double sumN(const int n);

/**
 * @brief вычисляет сумму всех членов последовательности, по модулю не меньших e
 * @param e - заданное число (порог)
 * @return сумма членов последовательности, удовлетворяющих условию
 */
double sumE(const double e);

/**
 * @brief вычисляет коэффициент перехода от текущего члена последовательности к следующему
 * @param i - индекс текущего шага (начиная с 0)
 * @return коэффициент для пересчета следующего члена
 */
double getCoef(const int i);

/**
 * @brief точка входа в программу
 * считывает у пользователя значения n и e, проверяет их корректность,
 * после чего вычисляет и выводит на экран:
 *  - сумму первых n членов последовательности;
 *  - сумму всех членов последовательности, по модулю не меньших e.
 *
 * @return 0 при успешном завершении программы, 1 при ошибке ввода или
 *         некорректных значениях n и e
 */
int main() 
{
    int n = getInt("Enter n: ");
    checkPositive(n);
    double e = getValue("Enter e: ");
    checkEpsilon(e);
    
    printf("Summ of %d elements is: %lf\n", n, sumN(n));
    printf("Summ of elements not less than %lf is: %lf\n", e, sumE(e));
    
    return 0;
}

/**
 * @brief вычисляет коэффициент перехода от текущего члена последовательности к следующему
 * для последовательности a_k = (-1)^(k-1) / (2k-1)! 
 * рекуррентное соотношение имеет вид: a_{k+1} = a_k * (-1) / ((2k) * (2k+1)).
 * индекс i соответствует (k-1), так как цикл начинается с 0.
 * 
 * @param i - индекс текущего шага (начиная с 0)
 * @return коэффициент для пересчета следующего члена
 */
double getCoef(const int i)
{
    double k = i + 1.0;
    return -1.0 / ((2.0 * k) * (2.0 * k + 1.0));
}

/**
 * @brief вычисляет сумму первых n членов последовательности 
 * использует рекуррентное соотношение для вычисления факториала 
 * без прямого вызова функции факториала, что повышает производительность
 * 
 * @param n - количество членов последовательности для суммирования
 * @return сумма первых n членов
 */
double sumN(const int n)
{
    double a = 1.0; 
    double result = 0.0;
    
    for (int i = 0; i < n; i++)
    {
        result += a;
        a *= getCoef(i);
    }
    return result;
}

/**
 * @brief вычисляет сумму всех членов последовательности, по модулю не меньших e
 * 
 * суммирование продолжается до тех пор, пока модуль текущего члена 
 * не станет меньше заданного значения e
 * 
 * @param e - заданное число (порог)
 * @return сумма членов последовательности, удовлетворяющих условию
 */
double sumE(const double e)
{
    double a = 1.0;
    double result = 0.0;
    int i = 0;

    while (fabs(a) >= e - DBL_EPSILON)
    {
        result += a;
        a *= getCoef(i);
        i++;
        
        if (i > 100000) break; 
    }
    return result;
}

/**
 * @brief считывает вещественное число с консоли и проверяет корректность ввода
 * @param message - сообщение-приглашение для пользователя (может быть NULL)
 * @return введенное вещественное число
 */
double getValue(const char* message)
{
    if (message != NULL)
    {
        printf("%s\n", message);
    }
    double value = 0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Input error");
        exit(1);
    }
    return value;
}

/**
 * @brief считывает целое число с консоли и проверяет корректность ввода
 * @param message - сообщение-приглашение для пользователя (может быть NULL)
 * @return введенное целое число
 */
int getInt(const char* message)
{
    if (message != NULL)
    {
        printf("%s\n", message);
    }
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        printf("Input error");
        exit(1);
    }
    return value;
}

/**
 * @brief проверяет, что число n является положительным
 * @param n - проверяемое число
 */
void checkPositive(const int n)
{
    if (n <= 0)
    {
        printf("Error, n have to be positive\n");
        exit(1);
    }
}

/**
 * @brief проверяет, что число e является положительным
 * @param e - проверяемое число
 */
void checkEpsilon(const double e)
{
    if (e <= 0)
    {
        printf("Error, e have to be positive\n");
        exit(1);
    }
}
