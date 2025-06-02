#include <iostream>
#include <vector>
#include <ctime>
#include <windows.h>

using namespace std;

// Функція сортування бульбашкою
void bubbleSort(vector<int>& arr) {
    int temp;
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = 0; j < arr.size() - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функція сортування вибором
void selectionSort(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        int minIdx = i;
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }
        if (i != minIdx)
            swap(arr[i], arr[minIdx]);
    }
}

// Функція сортування вставками
void insertionSort(vector<int>& arr) {
    for (int i = 1; i < arr.size(); i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Функція швидкого сортування
void quickSort(vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

// Виведення масиву
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));
    vector<int> a(20);
    for (int& num : a)
        num = rand() % 200 - 50; // генеруємо числа від -50 до 149

    // Виведення масиву a
    cout << "Масив a: ";
    printArray(a);

    // Створення масиву b з двозначних чисел
    vector<int> b;
    for (int num : a) {
        if ((num >= 10 && num <= 99) || (num <= -10 && num >= -99))
            b.push_back(num);
    }

    cout << "Масив b (двозначні числа): ";
    printArray(b);

    // Копії для кожного сортування
    vector<int> b1 = b, b2 = b, b3 = b, b4 = b;

    // Виведення результатів
    bubbleSort(b1);
    cout << "Сортування бульбашкою: ";
    printArray(b1);

    selectionSort(b2);
    cout << "Сортування вибором: ";
    printArray(b2);

    insertionSort(b3);
    cout << "Сортування вставками: ";
    printArray(b3);

    quickSort(b4, 0, b4.size() - 1);
    cout << "Швидке сортування: ";
    printArray(b4);

    return 0;
}
