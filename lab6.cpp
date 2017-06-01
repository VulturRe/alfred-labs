#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
 * Функция для заполнения файла.
 * Сначала создаётся поток для записи в файл и в нём открывается файл для
 * бинарной записи. Если файл не может быть открыт, то выводится сообщение об
 * ошибке и выход из функции.
 */
void write() {
    ofstream ofs;
    ofs.open("/home/ilshat/DeeR/Projects/ClionProjects/alfredlabs/binary.bin",
             fstream::binary);
    if (!ofs.is_open()) {
        cerr << "File can't be open!\n";
        return;
    }

    cout << "Введите количество чисел.\n";
    int n;
    cin >> n;
    cout << "\nВведите числа.\n";
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        ofs << temp << endl;
    }

    ofs.close();
}

/*
 * Функция для формирования массива из нечётных элементов файла.
 * vector<int> - контейнер для хранения элементов типа int. Т. е. грубо
 * говоря это оболочка для динамического массива с автоматическим выделением
 * памяти (при добавлении нового элемента под него выделяется память и не
 * нужно создавать массив с не изменяемой размерностью).
 * push_back(temp) - функция, для добавления элемента temp в конец массива.
 */
vector<int> oddArrayForm() {
    ifstream ifs;
    vector<int> array;
    ifs.open("/home/ilshat/DeeR/Projects/ClionProjects/alfredlabs/binary.bin",
             fstream::binary);
    if (!ifs.is_open()) {
        cerr << "File can't be open!\n";
        return array;
    }

    int temp;
    while (ifs >> temp)
        if (temp % 2 != 0) // если не делится на два без остатка
            array.push_back(temp * 2); // добавляем в массив удвоенное нечётное число

    ifs.close();
    return array;
}

/*
 * Функция для печати массива
 */
void print(vector<int> array) {
    for (int i = 0; i < array.size(); i++)
        cout << array[i] << " ";
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "rus");

    write();
    vector<int> odd = oddArrayForm();
    cout << "\n\nМассив удвоенных нечётных чисел:\n";
    print(odd);

    cin.ignore();
    cin.get();
    return 0;
}
