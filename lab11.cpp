#include <iostream>
#include <cmath>
using namespace std;

bool is_true(int *array, int start, int stop) {
    if (start > stop) return false;
    if (pow(array[start], 3) > -10 && pow(array[start], 3) < 20) return true;
    is_true(array, ++start, stop);
}

int main() {
    setlocale(LC_ALL, "rus");

    int *array, count, middle;
    cout << "Введите количество элементов массива\n";
    cin >> count;
    array = new int[count];
    middle = count / 2;
    cout << "\nВведите элементы массива\n";
    for (int i = 0; i < count; i++)
        cin >> array[i];
    if (is_true(array, 0, middle - 1) || is_true(array, middle, count - 1))
        cout << "\nУсловие истинно.\n";
    else cout << "\nУсловие ложно.\n";

    return 0;
}
