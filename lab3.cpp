#include <iostream>
using namespace std;

// функция для первого пункта лабораторной работы
void firstPart() {
    int n, firstNullPosition = 0, lastNullPosition = 0, minPosition = 0,
            maxPosition = 0;
    double max = 0, min = 65535, product = 1, sum = 0;
    double* array;

    cout << "\nВведите количество элементов массива.\n";
    cin >> n;
    array = new double[n];
    cout << "\nВведите элементы массива.\n";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        if (i == 0 || i % 2 == 0) product *= array[i];
        /*
         * Если текущий элемент больше максимального, то запоминаем его как
         * максимальный и запоминаем его позицию.
         */
        if (array[i] > max) {
            max = array[i];
            maxPosition = i;
        }
        /*
         * То же самое, но для минимального элемента
         */
        if (array[i] < min) {
            min = array[i];
            minPosition = i;
        }
    }

    /*
     * Ищем первый нулевой элемент циклом, который проходится по массиву от
     * начала к концу. При нахождении первого нулевого элемента выходим из
     * цикла.
     */
    for (int i = 0; i < n; i++)
        if(array[i] == 0) {
            firstNullPosition = i;
            break;
        }
    /*
     * Ищем последний нулевой элемент циклом, который проходится по массиву
     * от конца к началу. При нахождении первого нулевого элемента выходим из
     * цикла.
     */
    for (int i = n - 1; i >= 0; i++)
        if(array[i] == 0) {
            lastNullPosition = i;
            break;
        }
    /*
     * Считаем сумму элементов, находящихся между перым и последним нулевым
     * элементами.
     */
    for (int i = firstNullPosition + 1; i < lastNullPosition; i++)
        sum += array[i];

    /*
     * Меняем местами максимальный и минимальный элементы в массиве.
     */
    array[minPosition] = max;
    array[maxPosition] = min;

    cout << "\nПроизведение элементов с чётными номерами = " << product << endl;
    cout << "\nСумма элементов массива, расположенных между первым и "
            "последним нулевыми элементами = " << sum << endl;
    cout << "\nПреобразованный массив:\n";
    for (int i = 0; i < n; i++)
        cout << array[i] << " ";
    cout << endl;

    /*
     * Освобождаем выделенную память под массив.
     */
    delete []array;
}

// функция для второго пункта лабораторной работы
void secondPart() {
    int n, sortedColumnsCount = 0, nullCount = 0;
    int** matrix; // двумерный динамический массив

    cout << "\nВведите размерность матрицы n.\n";
    cin >> n;
    matrix = new int*[n];
    for (int i = 0; i < n; i++)
        matrix[i] = new int[n];

    cout << "\nВведите по очереди строки матрицы.\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 0)
                nullCount++;
        }

    for (int i = 0; i < n; i++) {
        bool sorted = true;
        for (int j = 0; j < n - 1; j++)
            if (matrix[j][i] > matrix[j + 1][i]) {
                sorted = false;
                break;
            }
        if (sorted) sortedColumnsCount++;
    }

    cout << "\nКоличество столбцов, упорядоченных по возрастанию = "
         << sortedColumnsCount << endl;
    cout << "\nКоличество нулевых элементов в матрице = " << nullCount << endl;

    /*
     * Освобождаем выделенную под матрицу память.
     */
    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete[] matrix;
}

int main() {
    setlocale(LC_ALL, "rus");

    cout << "--------------\n"
         << "=Первый пункт=\n"
         << "--------------\n";
    firstPart(); // вызов функции для первого пункта лабораторной
    cout << "--------------\n"
         << "=Второй пункт=\n"
         << "--------------\n";
    secondPart(); // вызов функции для второго пункта лабораторной
    cin.get();

    return 0;
}