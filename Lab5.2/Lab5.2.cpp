#include <iostream> // Подключение библиотеки для работы с вводом и выводом (cout, cin, endl).
#include <malloc.h> // Подключение библиотеки для работы с функциями выделения памяти (calloc, free).

using namespace std; // Использование пространства имён std для упрощения доступа к стандартным функциям.

// Функция для вывода матрицы.
void printMatrix(int** matrix, int rows, int cols) {
    // Цикл по строкам матрицы.
    for (int i = 0; i < rows; i++) {
        // Цикл по столбцам матрицы.
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t"; // Вывод элемента матрицы с табуляцией для форматирования.
        }
        cout << endl; // Переход на следующую строку после вывода всех элементов строки.
    }
}

// Функция обработки матрицы.
void processMatrix(int** matrix, int rows, int cols) {
    
    // Переменные для подсчёта количества положительных, отрицательных и нулевых элементов.
    int posCount = 0, negCount = 0, zeroCount = 0, temp;

    // Проход по каждому элементу матрицы.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            // Подсчёт положительных, отрицательных и нулевых элементов.
            if (matrix[i][j] > 0) posCount++;
            else if (matrix[i][j] < 0) negCount++;
            else zeroCount++;
            
            if (matrix[i][j] > matrix[0][0]) //нахождение максимального элемента с сменой первого элемента
            {
                temp = matrix[0][0];
                matrix[0][0] = matrix[i][j];
                matrix[i][j] = temp;
            }

            if (matrix[i][j] < matrix[rows - 1][cols - 1])//нахождение минимального элемента со сменой последеним
            {
                temp = matrix[rows - 1][cols - 1];
                matrix[rows - 1][cols -1] = matrix[i][j];
                matrix[i][j] = temp;
            }
           
        }
    }

    // Вывод обработанной матрицы.
    cout << "Обработанная матрица:\n";
    printMatrix(matrix, rows, cols);

    // Вывод количества положительных, отрицательных и нулевых элементов.
    cout << "Количество положительных элементов: " << posCount << endl;
    cout << "Количество отрицательных элементов: " << negCount << endl;
    cout << "Количество нулевых элементов: " << zeroCount << endl;
}

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

    // Вывод исходной матрицы.
    cout << "Исходная матрица:\n";
    printMatrix(matrix, rows, cols);

    // Обработка матрицы.
    processMatrix(matrix, rows, cols);

    // Освобождение памяти, выделенной для матрицы.
    for (int i = 0; i < rows; i++) {
        free(matrix[i]); // Освобождение памяти для каждой строки.
    }
    free(matrix); // Освобождение памяти для массива указателей.

    return 0; // Успешное завершение программы.
}
