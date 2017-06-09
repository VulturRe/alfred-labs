#include <iostream>
#include "student.h"
#include "rectParallelepiped.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    cout << "--------------\n";
    cout << "=Первый пункт=\n";
    cout << "--------------\n";
    rectParallelepiped();
    cout << "\n-------------\n";
    cout << "=Второй пункт=\n";
    cout << "--------------\n\n";
    student();
    cout << "\nНажмите на любую клавишу для завершения.";
    cin.ignore();
    cin.get();

    return 0;
}
