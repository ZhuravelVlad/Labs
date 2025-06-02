#include <iostream>
using namespace std;

// Рекурсивна функція для обчислення n-го члена
int sequence(int n) {
    if (n == 1)
        return 7;
    else
        return sequence(n - 1) + 10;
}

int main() {
    int n;
    cout << "Enter the term number (n): ";
    cin >> n;

    cout << "The " << n << "-th term of the sequence is: " << sequence(n) << endl;

    return 0;
}
