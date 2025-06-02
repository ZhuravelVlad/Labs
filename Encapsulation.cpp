#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "windows.h"

using namespace std;

class Customer {
    string surname;
    string name;
    string patronymic;
    string address;
    string phone;
    long long creditCardNumber;
    long long bankAccount;

public:
    void set(string sn, string n, string p, string addr, string ph, long long cc, long long ba) {
        surname = sn; name = n; patronymic = p;
        address = addr; phone = ph;
        creditCardNumber = cc; bankAccount = ba;
    }

    string getSurname() const { return surname; }
    long long getCreditCardNumber() const { return creditCardNumber; }

    void show() const {
        cout << surname << " " << name << " " << patronymic << ", Адреса: " << address
             << ", Телефон: " << phone << ", Кредитна картка: " << creditCardNumber
             << ", Рахунок: " << bankAccount << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть кількість покупців: ";
    cin >> n;
    cin.ignore();

    vector<Customer> customers(n);
    for (int i = 0; i < n; i++) {
        string sn, name, pat, addr, phone;
        long long cc, ba;

        cout << "Покупець #" << i+1 << ":\n";
        cout << "Прізвище: "; getline(cin, sn);
        cout << "Ім'я: "; getline(cin, name);
        cout << "По батькові: "; getline(cin, pat);
        cout << "Адреса: "; getline(cin, addr);
        cout << "Телефон: "; getline(cin, phone);
        cout << "Номер кредитної картки: "; cin >> cc;
        cout << "Номер банківського рахунку: "; cin >> ba;
        cin.ignore();

        customers[i].set(sn, name, pat, addr, phone, cc, ba);
    }

    // а) Сортування по алфавіту (за прізвищем)
    sort(customers.begin(), customers.end(), [](const Customer &a, const Customer &b) {
        return a.getSurname() < b.getSurname();
    });

    cout << "\nПокупці в алфавітному порядку:\n";
    for (const auto &c : customers)
        c.show();

    // б) Вивід покупців із заданим діапазоном номера картки
    long long minCard, maxCard;
    cout << "\nВведіть інтервал номера кредитної картки:\n";
    cout << "Мінімум: "; cin >> minCard;
    cout << "Максимум: "; cin >> maxCard;

    cout << "\nПокупці з номером картки в інтервалі:\n";
    for (const auto &c : customers) {
        if (c.getCreditCardNumber() >= minCard && c.getCreditCardNumber() <= maxCard) {
            c.show();
        }
    }

    return 0;
}
