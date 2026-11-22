#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief перечислимый тип для выбора вычисляемой величины
 * @param VOLUME - объём параллелепипеда
 * @param AREA - площадь поверхности параллелепипеда
 * @return возвращает выбранную величину: объём или площадь поверхности
 */
enum Choice
{
    VOLUME = 1,   
    AREA = 2      
};

/**
 * @brief вычисляет объём параллелепипеда
 * @param length длина параллелепипеда
 * @param width ширина параллелепипеда
 * @param height высота параллелепипеда
 * @return рассчитанное значение объёма
 */
double volume(const double length, const double width, const double height);

/**
 * @brief вычисляет площадь поверхности параллелепипеда
 * @param length длина параллелепипеда
 * @param width ширина параллелепипеда
 * @param height высота параллелепипеда
 * @return рассчитанное значение площади поверхности
 */
double area(const double length, const double width, const double height);

/**
 * @brief считывает с клавиатуры значение с плавающей точкой
 * @return считанное значение
 */
double getDouble();

/**
 * @brief считывает с клавиатуры целое число
 * @return считанное значение
 */
int getInt();

/**
 * @brief проверяет, что размер - положительное число
 * @param value - считанное значение размера
 */
void checkSide(const double value);

/**
 * @brief проверяет, что выбор пользователя корректен
 * @param choice - выбранный пункт
 */
void checkChoice(const int choice);

/**
 * @brief точка входа в программу
 * @return 0, если программа выполнена корректно, иначе не 0
 */
int main()
{
    printf("Enter length: ");
    double length = getDouble();
    checkSide(length);

    printf("\nEnter width: ");
    double width = getDouble();
    checkSide(width);

    printf("\nEnter height: ");
    double height = getDouble();
    checkSide(height);

    printf("\nChoose: 1 - Volume, 2 - Area: ");
    int choice = getInt();
    checkChoice(choice);

    switch (choice)
    {
    case VOLUME:
        printf("\nVolume is %lf\n", volume(length, width, height));
        break;
    case AREA:
        printf("\nArea is %lf\n", area(length, width, height));
        break;
    default:
        printf("Error");
        exit(1);
    }

    return 0;
}

double volume(const double length, const double width, const double height)
{
    return length * width * height;
}

double area(const double length, const double width, const double height)
{
    return 2 * (length * width + length * height + width * height);
}

double getDouble()
{
    double value = 0.0;
    if (scanf("%lf", &value) != 1)
    {
        printf("Error");
        exit(1);
    }
    return value;
}

int getInt()
{
    int value = 0;
    if (scanf("%d", &value) != 1)
    {
        printf("Error");
        exit(1);
    }
    return value;
}

void checkSide(const double value)
{
    if (value <= 0)
    {
        printf("Error");
        exit(1);
    }
}

void checkChoice(const int choice)
{
    if (choice != VOLUME && choice != AREA)
    {
        printf("Error");
        exit(1);
    }
}
