#include <iostream>
#include <vector>
#include <algorithm>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<int> v(10);
    int i, k = 0;

    // Введення елементів
    for (i = 0; i < v.size(); i++) {
        cout << "Уведіть " << i << " елемент вектора: ";
        cin >> v[i];
    }

    // Пошук індексів max та min
    int maxIndex = max_element(v.begin(), v.end()) - v.begin();
    int minIndex = min_element(v.begin(), v.end()) - v.begin();
    int maxVal = v[maxIndex], minVal = v[minIndex];

    // Підрахунок парних між ними
    if (maxIndex < minIndex) {
        for (i = maxIndex + 1; i < minIndex; i++)
            if (v[i] % 2 == 0) k++;
    } else if (minIndex < maxIndex) {
        for (i = minIndex + 1; i < maxIndex; i++)
            if (v[i] % 2 == 0) k++;
    }

    if (maxIndex == minIndex)
        cout << "Максимальний і мінімальний елементи збігаються.\n";
    else
        cout << "Кількість парних чисел між " << minVal << " та " << maxVal << ": " << k << endl;

    // Сортування
    sort(v.begin(), v.end());

    cout << "Відсортований вектор:\n";
    for (int val : v)
        cout << val << " ";
    cout << endl;

    return 0;
}
