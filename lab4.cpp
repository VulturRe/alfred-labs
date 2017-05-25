#include <iostream>
using namespace std;

bool isPrime(int number) {
    bool isPrime = true;
    for (int i = 2; i <= number / 2; ++i)
        if (number % i == 0) {
            isPrime = false;
            break;
        }
    return isPrime;
}

void firstPart() {
    int number, sum = 0;
    cout << "\nВведите последовательность чисел (0 - конец последовательности).\n";
    while (cin >> number) {
        if (!number) break;
        sum = 0;
        for (int i = 1; i < number + 1; i++) {
            if (number % i == 0 && isPrime(i))
                sum += i;
        }
        cout << "Сумма простых делителей числа \"" << number << "\" = " << sum << endl;
    }
}

int* put(int *array, int size, int number, int position) {
    int *newArray = new int[size + 1];
    for (int i = 0; i < position + 1; i++)
        newArray[i] = array[i];
    newArray[position + 1] = number;
    for (int i = position + 1, j = position + 2; i < size; i++, j++)
        newArray[j] = array[i];
    return newArray;
}

double average(int *array, int size) {
    double average = 0;
    for (int i = 0; i < size; i++)
        average += array[i];
    average /= size;
    return average;
}

int findMax(int *array, int size) {
    int max = 0;
    for (int i = 0; i < size; i++)
        if (array[i] > max)
            max = array[i];
    //delete[] *array;
    return max;
}

void secondPart() {
    int size, maxNum;

    cout << "Введите количество элементов массива X(N)\n";
    cin >> size;
    int *array = new int[size];
    cout << "\nВведите элементы массива\n";
    for (int i = 0; i < size; i++)
        cin >> array[i];

    maxNum = findMax(array, size);

    cout << "\nМаксимальный элемент в массиве = " << maxNum << endl;
    cout << "\nСреднее арифметическое до вставки = " << average(array, size) << endl;

    for (int i = 0; i < size; i++) {
        if (array[i] % 2 == 0)
            array = put(array, size++, maxNum, i);
    }

    cout << "\nМассив после вставки максимального числа после чётных чисел:\n";
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
    cout << "\nСреднее арифметическое после вставки = " << (double)average(array, size) << endl;
    delete[] array;
}

int main() {
    setlocale(LC_ALL, "rus");

    cout << "--------------\n";
    cout << "=Первый пункт=\n";
    cout << "--------------\n";
    firstPart();
    cout << "\n-------------\n";
    cout << "=Второй пункт=\n";
    cout << "--------------\n\n";
    secondPart();
    cout << "\nНажмите на любую клавишу для завершения.";
    cin.ignore();
    cin.get();

    return 0;
}
