﻿#include <iostream>  // Подключаем библиотеку для работы с вводом-выводом
#include <math.h>    // Подключаем библиотеку математических функций (sqrt, abs, log)
using namespace std; // Используем пространство имен std для упрощения записи

int main() {
    // Инициализация констант и переменных:
    double a = 2.17;     // Константа a
    double xn = -1.5;    // Начальное значение x
    double xk = 1.5;     // Конечное значение x
    double dx = 0.2;     // Шаг изменения x
    double y;            // Переменная для хранения результата вычислений y
    double sum = 0;      // Переменная для накопления суммы положительных y
    double product = 1;  // Переменная для накопления произведения положительных y
    int count = 0;       // Счетчик итераций цикла
    int positiveCount = 0; // Счетчик положительных значений y

    // Заголовок таблицы, поясняющий, какие данные будут выводиться
    cout << "x\t\ty\n";

    // Цикл for для перебора значений x от xn до xk включительно, с шагом dx
    for (double x = xn; x <= xk; x += dx) {
        // Вычисление y по заданной формуле
        y = sqrt(abs((a + x * x) * log(a * a + 3 * 4))) / 2;

        // Проверка, является ли текущая итерация четной
        if (count % 2 == 0) {
            // Вывод x и y в таблицу (на каждой четной итерации)
            cout << x << "\t\t" << y << endl;
        }

        // Если значение y положительное, выполняем дополнительные действия
        if (y > 0) {
            positiveCount++; // Увеличиваем счетчик положительных значений
            sum += y;        // Добавляем y к общей сумме
            product *= y;    // Умножаем y на общее произведение
        }

        count++; // Увеличиваем счетчик итераций
    }

    // Вывод итоговых значений после завершения цикла
    cout << "Sum: " << sum << "\nProduct: " << product
        << "\nPositive Count: " << positiveCount << endl;

    return 0; // Завершаем выполнение программы
}