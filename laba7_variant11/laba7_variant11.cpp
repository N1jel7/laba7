#include <iostream>
#include <string>
#include <regex>
using namespace std;

bool isInMinsk(string town) {
    regex search_town("Минск");
    return regex_search(town, search_town);
}

struct Exam { // создание структуры
    string name;
    string surname;
    string lastName;
    string town;
    string street;
    string house;
    int mark1;
    int mark2;
    int mark3;
    int averageMark;
} mark[3], student[15]; // массив из кол-ва абитуриентов


int main()
{
    int numOfStudents = 0;
    cout << "Введите количество абитуриентов: ";
    cin >> numOfStudents; // считывание кол-ва абитуриентов
    for (int i = 0; i < numOfStudents; i++) { // цикл для заполнения всех данных абитуриентов
        cout << "Введите ФИО абитуриента: " << endl; // заполнение ФИО
        cin >> student[i].surname;
        cin >> student[i].name;
        cin >> student[i].lastName;
        cout << "Введите адресс абитуриента (Город-улица-№дома/квартиры): " << endl; // заполнение адресса
        cin >> student[i].town;
        cin >> student[i].street;
        cin >> student[i].house;
        cout << "Введите 1-ю оценку абитуриента: " << endl; // заполнение оценок
        cin >> student[i].mark1;
        cout << "Введите 2-ю оценку абитуриента: " << endl;
        cin >> student[i].mark2;
        cout << "Введите 3-ю оценку абитуриента: " << endl;
        cin >> student[i].mark3;
    }

    for (int i = 0; i < numOfStudents; i++) { // цикл для расчёта среднего балла
        student[i].averageMark = (student[i].mark1 + student[i].mark2 + student[i].mark3) / 3; // средний балл
        if (student[i].averageMark >= 45 && isInMinsk(student[i].town)) { // условие для 45 баллов и выше
            cout << "Средний бал " << student[i].surname << " равен: " << student[i].averageMark; // вывод с/б
            cout << ", также он живёт в Минске. ";
        }

    }
}
