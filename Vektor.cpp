#include <iostream>
#include <vector>
#include <cctype>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<char> v(15);
    int i;

    cout << "Розмір вектора = " << v.size() << endl;

    // Заповнення від 'a' до 'o'
    for (i = 0; i < 15; i++)
        v[i] = 'a' + i;

    cout << "Поточний вміст вектора:\n";
    for (char c : v)
        cout << c << " ";
    cout << "\n\n";

    // Додавання ще 10 символів
    for (i = 0; i < 10; i++)
        v.push_back('a' + 15 + i);

    cout << "Новий розмір вектора = " << v.size() << endl;
    cout << "Поточний вміст вектора:\n";
    for (char c : v)
        cout << c << " ";
    cout << "\n\n";

    // Перетворення у верхній регістр
    for (char &c : v)
        c = toupper(c);

    cout << "Модифікований вміст:\n";
    for (char c : v)
        cout << c << " ";
    cout << endl;

    return 0;
}
