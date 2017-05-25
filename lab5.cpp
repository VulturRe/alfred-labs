#include <iostream>
using namespace std;

/*
 * Функция для формирования одномерного массива размерностью n.
 */
int* oneDimArray(int n) {
    int* temp = new int[n];
    cout << "\nВведите одномерный массив.\n";
    for (int i = 0; i < n; i++)
        cin >> temp[i];

    return temp;
}

/*
 * Функция для удаления чётных элементов из одномерного массива.
 * Первый цикл проходится по исходному массиву и при встрече чётного элемента
 * уменьшает количество элементов на 1. Затем создаётся новый одномерный массив
 * полученной размерности и во втором цикле в него записываются нечётные элементы
 * из первого массива.
 */
int* del(int *array, int size) {
    int count = size;

    for (int i = 0; i < size; i++)
        if (array[i] % 2 == 0)
            count--;

    int *temp = new int[count];
    int counter = 0;
    for (int i = 0; i < size; i++)
        if (array[i] % 2 != 0)
            temp[counter++] = array[i];

    return temp;
}

/*
 * Функция для формирования двумерного массива размерностью n, m
 */
int** twoDimArray(int n, int m) {
    int** temp = new int*[n];
    for (int i = 0; i < n; i++)
        temp[i] = new int[m];
    cout << "\nВведите двумерный массив.\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> temp[i][j];

    return temp;
}

/*
 * Функция для перевёртывания чётных столбцов двумерного массива.
 * Первый цикл итерируется по столбцам массива с шагом 2 начиная с 0 строки,
 * т. е. проходятся только чётные строки. Вложенный цикл проходится от начала
 * строки до её середины и меняет первый элемент с последним, второй с
 * предпоследним и т. д. в результате чего строка "переворачивается".
 */
void roll(int** &array, int n, int m) {
    for (int i = 0; i < m; i += 2)
        for (int j = 0; j < n / 2; j++)
            swap(array[j][i], array[n-j-1][i]);
}

/*
 * Функция для формирования строки.
 * cin.ignore() необходим для того, чтобы работала функция getline(). Без неё
 * не будет происходить считывание вводимой строки.
 */
string st() {
    string str;
    cin.ignore();
    getline(cin, str);
    return str;
}

/*
 * Функция для подсчёта количества слов в строке.
 */
int wordsCount(string str) {
    if (str.length() == 0)
        return 0;
    int count = 1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ')
            count++;
    }

    return count;
}

int main() {
    setlocale(LC_ALL, "rus");

    int n, m;
    cout << "Введите размерность одномерного массива.\n";
    cin >> n;
    int* array = oneDimArray(n);
    int *newArray = del(array, n);
    for (int i = 0; i < n; i++)
        if (array[i] % 2 == 0)
            n--;
    delete[] array;
    cout << "\nОдномерный массив с удалёнными чётными элементами:\n";
    for (int i = 0; i < n; i++)
        cout << newArray[i] << " ";

    cout << "\n\nВведите количество строк и столбцов двумерного массива.\n";
    cin >> n >> m;
    int** twoArray = twoDimArray(n, m);
    roll(twoArray, n, m);
    cout << "\nДвумерный массив с перевёрнутыми чётными строками:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << twoArray[i][j] << " ";
        cout << endl;
    }

    cout << "\nВведите строку.\n";
    string str = st();
    cout << "\nКоличество слов в строке = " << wordsCount(str) << endl;
    cin.get();

    return 0;
}
