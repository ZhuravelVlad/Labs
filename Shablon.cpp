#include <iostream>
#include <cmath> // для pow()
using namespace std;

// Шаблонна функція для знаходження середнього геометричного
template <typename T1, typename T2, typename T3>
double GeometricMean(T1 a, T2 b, T3 c) {
    return pow(static_cast<double>(a) * b * c, 1.0 / 3);
}

int main() {
    // Вхідні дані різного типу
    int a;
    float b;
    double c;

    cout << "Введіть три числа різного типу:" << endl;
    cout << "Ціле (int): ";
    cin >> a;
    cout << "Дійсне (float): ";
    cin >> b;
    cout << "Дійсне (double): ";
    cin >> c;

    // Виклик шаблонної функції
    double result = GeometricMean(a, b, c);
    cout << "Середнє геометричне: " << result << endl;

    return 0;
}
