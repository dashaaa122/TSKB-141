#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <stdbool.h>

/**
 * @brief считывает значение типа double с консоли
 * @param message - указатель на строку-приглашение (может быть NULL)
 * @return считанное значение типа double
 */
double getValue(const char* message);

/**
 * @brief проверяет, что шаг положительный
 * @param step - значение шага
 */
void checkStep(const double step);

/**
 * @brief проверяет корректность границ отрезка
 * @param xbegin - начало отрезка
 * @param xend - конец отрезка
 */
void checkSegment(const double xbegin, const double xend);

/**
 * @brief проверяет, принадлежит ли точка области допустимых значений (ОДЗ)
 * @details для функции y = 0.1x^2 - x*ln(x) необходимо, чтобы x > 0
 * @param x - проверяемое значение аргумента
 * @return true, если функция определена в точке x; false иначе
 */
bool isOOF(const double x);

/**
 * @brief вычисляет значение функции y = 0.1*x^2 - x*ln(x)
 * @param x - значение аргумента
 * @return вычисленное значение функции
 */
double getY(const double x);

/**
 * @brief точка входа в программу, табулирует функцию y = 0.1*x^2 - x*ln(x)
 * @details запрашивает у пользователя начало и конец отрезка, а также шаг.
 *          Выполняет проверку введенных данных (шаг > 0, начало <= конец).
 *          В цикле while вычисляет и выводит значения функции для каждого x.
 *          Если функция не определена в точке (x <= 0 из-за ln(x)),
 *          выводит сообщение об отсутствии решения.
 * @return 0 при успешном завершении программы
 */
int main()
{
    // Ввод данных пользователем
    // Для теста из таблицы: начало 1, конец 2, шаг 0.1
    double xbegin = getValue("Enter segment start: ");
    double xend = getValue("Enter segment end: ");
    double step = getValue("Enter step: ");
    
    checkStep(step);
    checkSegment(xbegin, xend);
    
    double x = xbegin;
    // Используем цикл while
    while (x < xend + step / 1000.0) // небольшая погрешность для вещественных чисел
    {
        if (isOOF(x))
        {
            // Если функция определена, выводим x и y
            printf("x = %.2lf, y = %.4lf\n", x, getY(x));
        }
        else
        {
            // Если не определена (x <= 0)
            printf("x = %.2lf, y is not define\n", x);
        }
        x += step;
    }
    return 0;
}

/**
 * @brief считывает значение типа double с консоли
 * @param message - указатель на строку-приглашение (может быть NULL)
 * @return считанное значение типа double
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
        printf("Input error\n");
        exit(1);
    }
    return value;
}

/**
 * @brief проверяет, что шаг положительный
 * @param step - значение шага
 */
void checkStep(const double step)
{
    if (step <= 0)
    {
        printf("Error, step have to be positive\n");
        exit(1);
    }
}

/**
 * @brief проверяет корректность границ отрезка
 * @param xbegin - начало отрезка
 * @param xend - конец отрезка
 */
void checkSegment(const double xbegin, const double xend)
{
    if (xbegin > xend)
    {
        printf("Error, segment begin have to be less or equal segment end\n");
        exit(1);
    }
}

/**
 * @brief проверяет, принадлежит ли точка области допустимых значений (ОДЗ)
 * @details для функции y = 0.1x^2 - x*ln(x) необходимо, чтобы x > 0
 * @param x - проверяемое значение аргумента
 * @return true, если функция определена в точке x; false иначе
 */
bool isOOF(const double x)
{
    return (x > 0.0); 
}

/**
 * @brief вычисляет значение функции y = 0.1*x^2 - x*ln(x)
 * @param x - значение аргумента
 * @return вычисленное значение функции
 */
double getY(const double x)
{
    return 0.1 * pow(x, 2) - x * log(x); 
}
