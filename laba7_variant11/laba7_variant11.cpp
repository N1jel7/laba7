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
    int marks[3];
    int averageMark;
} students[25]; // массив из кол-ва абитуриентов


int main()
{
    int numOfStudents = 0;
    cout << "Введите количество абитуриентов: ";
    cin >> numOfStudents; // считывание кол-ва абитуриентов
    for (int i = 0; i < numOfStudents; i++) { // цикл для заполнения всех данных абитуриентов
        cout << "Введите ФИО абитуриента: " << endl; // заполнение ФИО
        cin >> students[i].surname;
        cin >> students[i].name;
        cin >> students[i].lastName;

        cout << "Введите адресс абитуриента (Город-улица-№дома/квартиры): " << endl; // заполнение адресса
        cin >> students[i].town;
        cin >> students[i].street;
        cin >> students[i].house;
        bool isCorrect = false;
        while (!isCorrect) {
            if (students[i].marks[0, 1, 2] >= 1 && students[i].marks[0, 1, 2] <= 100) {
                isCorrect = true;
            }
            else {
                cout << "Введите 1-ю оценку абитуриента: " << endl; // заполнение оценок
                cin >> students[i].marks[0];
                cout << "Введите 2-ю оценку абитуриента: " << endl;
                cin >> students[i].marks[1];
                cout << "Введите 3-ю оценку абитуриента: " << endl;
                cin >> students[i].marks[2];
            }
        }
        
    }

    for (int i = 0; i < numOfStudents; i++) { // цикл для расчёта среднего балла
        students[i].averageMark = (students[i].marks[0] + students[i].marks[1] + students[i].marks[2]) / 3; // средний балл
        if (students[i].averageMark >= 45 && isInMinsk(students[i].town)) { // условие для 45 баллов и выше
            cout << "Средний бал " << students[i].surname << " равен: " << students[i].averageMark; // вывод с/б
            cout << ", также он живёт в Минске. ";
        }

    }
}