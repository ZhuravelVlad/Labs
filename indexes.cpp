#include <iostream>
#include "windows.h" // Для підтримки кирилиці в Windows
using namespace std;

int main() {
    SetConsoleCP(1251); // Встановлення кодування введення
    SetConsoleOutputCP(1251); // Встановлення кодування виведення

    char a, b;
    char *pa, *pb;

    pa = &a;
    pb = &b;

    cout << "Введіть перший символ (a): ";
    cin >> a;

    cout << "Введіть другий символ (b): ";
    cin >> b;

    // Обмін значеннями через покажчики
    char temp = *pa;
    *pa = *pb;
    *pb = temp;

    cout << "Після обміну:" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    return 0;
}
