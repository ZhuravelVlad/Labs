#include <iostream>
#include <windows.h>
using namespace std;

// Функція для лінійного пошуку
int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 25;
    int array[SIZE];

    // Заповнення масиву ступенями двійки
    for (int i = 0; i < SIZE; i++) {
        array[i] = 1 << i; // 2^i
    }

    // Виведення масиву
    cout << "Масив зі ступенів двійки:\n";
    for (int i = 0; i < SIZE; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Введення шуканого елемента
    int searchValue;
    cout << "Введіть число для пошуку: ";
    cin >> searchValue;

    // Пошук
    int result = linearSearch(array, SIZE, searchValue);

    if (result != -1)
        cout << "Елемент " << searchValue << " знайдено на індексі " << result << "." << endl;
    else
        cout << "Елемент " << searchValue << " не знайдено в масиві." << endl;

    return 0;
}
