#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

const int ROWS = 10;
const int COLS = 15;

// Прототипи функцій
void fillMatrix(int matrix[ROWS][COLS]);
void printMatrix(int matrix[ROWS][COLS]);
void getMaxInColumns(int matrix[ROWS][COLS], int maxArray[COLS]);
void sortArrayAscending(int arr[], int size);
void printArray(int arr[], int size);

int main() {
    setlocale(LC_ALL, "ukr");
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    int matrix[ROWS][COLS];
    int maxInColumns[COLS];

    fillMatrix(matrix);
    cout << "Двомірний масив:\n";
    printMatrix(matrix);

    getMaxInColumns(matrix, maxInColumns);
    cout << "\nМаксимальні елементи в кожному стовпці:\n";
    printArray(maxInColumns, COLS);

    sortArrayAscending(maxInColumns, COLS);
    cout << "\nВідсортований масив за зростанням:\n";
    printArray(maxInColumns, COLS);

    return 0;
}

// Заповнення матриці випадковими числами
void fillMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            matrix[i][j] = rand() % 100; // значення від 0 до 99
}

// Виведення матриці
void printMatrix(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        cout << "| ";
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << "|\n";
    }
}

// Отримання максимумів по кожному стовпцю
void getMaxInColumns(int matrix[ROWS][COLS], int maxArray[COLS]) {
    for (int j = 0; j < COLS; j++) {
        int maxVal = matrix[0][j];
        for (int i = 1; i < ROWS; i++) {
            if (matrix[i][j] > maxVal)
                maxVal = matrix[i][j];
        }
        maxArray[j] = maxVal;
    }
}

// Сортування одномірного масиву за зростанням (метод бульбашки)
void sortArrayAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
}

// Виведення одномірного масиву
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
