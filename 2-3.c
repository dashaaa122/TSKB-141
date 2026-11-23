#include <stdio.h>
#include <locale.h>

/**
 * @brief считывает и проверяет значение часов
 * @param hours - указатель на переменную для хранения часов
 * @return 1 при успешном вводе, 0 при ошибке
 */
int read_hours(int *hours) {
    printf("введите часы:\n");
    if (scanf("%d", hours) != 1) {
        printf("ошибка: введено не число\n");
        return 0;
    }
    if (*hours < 0 || *hours > 23) {
        printf("ошибка: часы должны быть в диапазоне 0-23\n");
        return 0;
    }
    return 1;
}

/**
 * @brief считывает и проверяет значение минут
 * @param minutes - указатель на переменную для хранения минут
 * @return 1 при успешном вводе, 0 при ошибке
 */
int read_minutes(int *minutes) {
    printf("введите минуты: ");
    if (scanf("%d", minutes) != 1) {
        printf("ошибка: введено не число\n");
        return 0;
    }
    if (*minutes < 0 || *minutes > 59) {
        printf("ошибка: минуты должны быть в диапазоне 0-59\n");
        return 0;
    }
    return 1;
}

/**
 * @brief определяет пожелание по времени суток
 * @param hours - часы (0-23)
 * @param minutes - минуты (0-59)
 * @return указатель на строку с пожеланием
 */
const char* get_greeting(int hours, int minutes) {
    (void)minutes; /* минуты не влияют на выбор пожелания */
    if (hours >= 5 && hours < 12) {
        return "доброе утро!";
    } else if (hours >= 12 && hours < 17) {
        return "добрый день!";
    } else if (hours >= 17 && hours < 23) {
        return "добрый вечер!";
    } else {
        return "спокойной ночи!";
    }
}

/**
 * @brief точка входа в программу.
 * @return 0 при успешном завершении, 1 при ошибке ввода
 */
int main(void) {
    setlocale(LC_ALL, "Russian");

    int hours = 0;
    int minutes = 0;


    if (!read_hours(&hours)) {
        return 1;
    }
    if (!read_minutes(&minutes)) {
        return 1;
    }

    printf("\nтекущее время: %02d:%02d\n", hours, minutes);
    printf("%s\n", get_greeting(hours, minutes));

    return 0;
}
