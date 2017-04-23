#include <iostream>
#include <cmath>
using namespace std;

/*
 * Функция, возвращающая количество пересечений с осью OX (решений).
 */
int solutionsCount(int a, int b, int c) {
    /*
     * pow (b, 2) - функция, которая возвращает b в степени 2
     */
    double d = pow(b, 2) - 4*a*c;
    if (d < 0) return 0;
    if (d == 0) return 1;
    return 2;
}

int main() {
    setlocale(LC_ALL, "rus");

    int a, b, c;
    cout << "Введите a, b и c.\n";
    cin >> a >> b >> c;
    if (a > 0)
        cout << "\nВетви параболы направлены вверх.\n";
    else cout << "\nВетви параболы направлены вниз.\n";
    cout << "\nКоличество точек пересечения с осью OX = " << solutionsCount
            (a, b, c) << endl;

    return 0;
}