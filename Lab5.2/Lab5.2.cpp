#include <iostream>
#include <malloc.h>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian"); // Установка локализации для работы с русским языком в консоли.
    int rows, cols; // Переменные для количества строк и столбцов матрицы.

    // Ввод количества строк и столбцов матрицы.
    cout << "Введите количество строк и столбцов матрицы: ";
    cin >> rows >> cols;

    // Выделение памяти для матрицы (массив указателей на строки).
    int** matrix = (int**)calloc(rows, sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)calloc(cols, sizeof(int)); // Выделение памяти для каждой строки.
    }

    // Ввод элементов матрицы.
    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j]; // Ввод каждого элемента матрицы.
        }
    }
    // Переменные для подсчёта количества положительных, отрицательных и нулевых элементов.

    int posCount = 0, negCount = 0, zeroCount = 0;

    // Вывод исходной матрицы.
    cout << "Исходная матрица:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";

            if (matrix[i][j] > 0) posCount++;
            else if (matrix[i][j] < 0) negCount++;
            else zeroCount++;
        }
        cout << endl;
    }

    int  temp;

    // Проход по каждому элементу матрицы и обработка.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
           

            if (matrix[i][j] > matrix[0][0]) { // Нахождение максимального элемента с заменой первого элемента.
                temp = matrix[0][0];
                matrix[0][0] = matrix[i][j];
                matrix[i][j] = temp;
            }

            if (matrix[i][j] < matrix[rows - 1][cols - 1]) { // Нахождение минимального элемента с заменой последнего.
                temp = matrix[rows - 1][cols - 1];
                matrix[rows - 1][cols - 1] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }

    // Вывод обработанной матрицы.
    cout << "Обработанная матрица:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }

    // Вывод количества положительных, отрицательных и нулевых элементов.
    cout << "Количество положительных элементов: " << posCount << endl;
    cout << "Количество отрицательных элементов: " << negCount << endl;
    cout << "Количество нулевых элементов: " << zeroCount << endl;

    // Освобождение памяти, выделенной для матрицы.
    for (int i = 0; i < rows; i++) {
        free(matrix[i]); // Освобождение памяти для каждой строки.
    }
    free(matrix); // Освобождение памяти для массива указателей.

    return 0; // Успешное завершение программы.
}
