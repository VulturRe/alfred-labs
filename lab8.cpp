#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    string initials;
    unsigned groupNumber;
    unsigned firstMark;
    unsigned secondMark;
    unsigned thirdMark;
};

struct List {
    Student student;
    List *next;
};

List* add(List *list, string name, string initials, unsigned groupNumber,
          unsigned firstMark, unsigned secondMark, unsigned thirdMark) {
    List *temp = list;
    if (temp != nullptr) {
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = new List;
        temp = temp->next;
    } else temp = new List;
    temp->student.name = name;
    temp->student.initials = initials;
    temp->student.groupNumber = groupNumber;
    temp->student.firstMark = firstMark;
    temp->student.secondMark = secondMark;
    temp->student.thirdMark = thirdMark;
    temp->next = nullptr;
    if (list != nullptr) return list;
    return temp;
}

void free(List *&list) {
    while (list != nullptr) {
        List* temp = list->next;
        delete list;
        list = nullptr;
        list = temp;
    }
}

void print(List *list) {
    while (list != nullptr) {
        cout << list->student.name << " " << list->student.initials << " " <<
             list->student.groupNumber << " " << list->student.firstMark <<
             " " << list->student.secondMark << " " <<
             list->student.thirdMark << endl;
        list = list->next;
    }
}

List* makeExcellent(List *list) {
    List *temp = nullptr;
    while (list != nullptr) {
        if (list->student.firstMark == 5 && list->student.secondMark == 5
                && list->student.thirdMark == 5) {
            temp = add(temp, list->student.name, list->student.initials, list->student.groupNumber,
                list->student.firstMark, list->student.secondMark, list->student.thirdMark);
        }
        list = list->next;
    }
    return temp;
}

int main() {
    setlocale(LC_ALL, "rus");

    List* list = nullptr;
    unsigned count, groupNumber, firstMark, secondMark, thirdMark;
    string name, initials;

    cout << "Введите количество студентов.\n";
    cin >> count;
    cout << "\nВведите данные о студентах (Имя Ф.О. группа оценка оценка "
            "оценка).\n";
    for (int i = 0; i < count; i++) {
        cin >> name >> initials >> groupNumber >> firstMark >> secondMark >>
            thirdMark;
        list = add(list, name, initials, groupNumber, firstMark, secondMark,
                   thirdMark);
    }
    cout << "\nВведённый список:\n";
    print(list);
    cout << "\nСписок отличников:\n";
    List *excellent = makeExcellent(list);
    print(excellent);
    free(list);
    free(excellent);

    return 0;
}

