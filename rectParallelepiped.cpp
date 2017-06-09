#include <iostream>
using namespace std;

struct RectParallelepiped {
    double width;
    double length;
    double height;
};

struct ParallList {
    RectParallelepiped parall;
    ParallList *next;
};

ParallList* add(ParallList *list, double width, double length, double height) {
    ParallList *temp = list;
    if (temp != nullptr) {
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = new ParallList;
        temp = temp->next;
    } else temp = new ParallList;
    temp->parall.width = width;
    temp->parall.length = length;
    temp->parall.height = height;
    temp->next = nullptr;
    if (list != nullptr) return list;
    return temp;
}

void free(ParallList *&list) {
    while (list != nullptr) {
        ParallList *temp = list->next;
        delete list;
        list = nullptr;
        list = temp;
    }
}

double volume(RectParallelepiped parall) {
    return parall.width * parall.length * parall.height;
}

pair<int, double> minVolume(ParallList *list) {
    int counter = 0;
    int minVolumeRectPos;
    double minVolume = 65535.0;
    while (list != nullptr) {
        double min = volume(list->parall);
        if (min < minVolume) {
            minVolume = min;
            minVolumeRectPos = counter;
        }
        counter++;
        list = list->next;
    }
    return make_pair(minVolumeRectPos, minVolume);
}

void printRect(ParallList *list) {
    while (list != nullptr) {
        cout << list->parall.width << " " << list->parall.length << " " << list->parall.height << endl;
        list = list->next;
    }
    cout << endl;
}

void rectParallelepiped() {
    setlocale(LC_ALL, "rus");

    ParallList *list = nullptr;

    cout << "Введите количество параллелепипедов.\n";
    int count;
    cin >> count;
    cout << "\nВведите a, b и h параллелепипедов.\n";
    double a, b, h;
    for (int i = 0; i < count; i++) {
        cin >> a >> b >> h;
        list = add(list, a, b, h);
    }

    cout << "\nВведённый список:\n";
    printRect(list);
    pair<int, double> min = minVolume(list);
    free(list);
    cout << "Наименьший объём у " << min.first << " параллелепипеда и = " << min.second << endl;
}
