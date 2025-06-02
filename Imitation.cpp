#include <iostream>
#include <cstring>
#include "windows.h"
using namespace std;

// Клас Людина
class Human {
protected:
    char* name;
    int age;
    float weight;

public:
    Human(const char* name, int age, float weight) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        this->age = age;
        this->weight = weight;
    }

    virtual ~Human() {
        delete[] name;
        cout << "Знищення об'єкта класу Human\n";
    }

    virtual void print() const {
        cout << "Ім'я: " << name << "\nВік: " << age << "\nВага: " << weight << " кг" << endl;
    }
};

// Клас Повнолітній, що наслідує Human
class Adult : public Human {
private:
    long passport_number;

public:
    // Конструктор за замовчуванням
    Adult() : Human("Невідомо", 18, 60.0), passport_number(0) {}

    // Конструктор з параметрами
    Adult(const char* name, int age, float weight, long passport)
        : Human(name, age, weight), passport_number(passport) {}

    // Деструктор
    ~Adult() override {
        cout << "Знищення об'єкта класу Adult\n";
    }

    // Функція друку
    void print() const override {
        Human::print();
        cout << "Номер паспорта: " << passport_number << endl;
    }

    // Зміна віку
    void setAge(int new_age) {
        age = new_age;
    }

    // Зміна номера паспорта
    void setPassport(long new_passport) {
        passport_number = new_passport;
    }
};

// Функція main
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "Створення об'єкта adult1 за допомогою конструктора за замовчуванням:\n";
    Adult adult1;
    adult1.print();

    cout << "\nСтворення об'єкта adult2 за допомогою конструктора з параметрами:\n";
    Adult adult2("Олександр", 25, 75.5, 123456789);
    adult2.print();

    cout << "\nЗміна віку та номера паспорта об'єкта adult2:\n";
    adult2.setAge(30);
    adult2.setPassport(987654321);
    adult2.print();

    return 0;
}
