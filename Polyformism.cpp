#include <iostream>
#include <windows.h>
using namespace std;

class Number {
    int value;

    // Приватна функція для перевірки на просте число
    bool isPrime(int n) const {
        if (n <= 1) return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }
        return true;
    }

public:
    Number() : value(0) {}
    Number(int v) : value(v) {}

    void show() const {
        cout << "Value = " << value;
        cout << " => " << (isPrime(value) ? "Prime" : "Not prime") << endl;
    }

    // Оператори
    Number operator+(const Number& other) const {
        return Number(value + other.value);
    }

    Number operator-(const Number& other) const {
        return Number(value - other.value);
    }

    Number operator*(const Number& other) const {
        return Number(value * other.value);
    }

    Number operator/(const Number& other) const {
        if (other.value == 0) {
            cout << "Division by zero!" << endl;
            return Number(0);
        }
        return Number(value / other.value);
    }

    bool operator==(const Number& other) const {
        return value == other.value;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Number a(7), b(3);

    cout << "a: "; a.show();
    cout << "b: "; b.show();

    Number sum = a + b;
    cout << "a + b = "; sum.show();

    Number diff = a - b;
    cout << "a - b = "; diff.show();

    Number prod = a * b;
    cout << "a * b = "; prod.show();

    Number quot = a / b;
    cout << "a / b = "; quot.show();

    cout << "a == b: " << (a == b ? "True" : "False") << endl;

    return 0;
}
