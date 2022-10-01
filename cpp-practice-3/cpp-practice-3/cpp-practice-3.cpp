// Практическая работа 3: 
// Пользователь вводит число от 1 до 7, программа показывает день недели
// Пользователь вводит чистло от 1 до 12, программа показывает месяц
#include <iostream>
using namespace std;

void weekday() {
    int n;
    cout << "Enter a number between 1 and 7 to see the corresponding weekday: ";
    cin >> n;
    switch (n)
    {
    case 1:
        cout << "\nMonday\n";
        break;
    case 2:
        cout << "\nTuesday\n";
        break;
    case 3:
        cout << "\nWednesday\n";
        break;
    case 4:
        cout << "\nThursday\n";
        break;
    case 5:
        cout << "\nFriday\n";
        break;
    case 6:
        cout << "\nSaturday\n";
        break;
    case 7:
        cout << "\nSunday\n";
        break;
    default:
        cout << "\nEnter a number between 1 and 7";
    }
}

void month() {
    int n;
    cout << "\nEnter a number between 1 and 12 to see the corresponding month name: ";
    cin >> n;
    switch (n)
    {
    case 1:
        cout << "\nJanuary\n";
        break;
    case 2:
        cout << "\nFebruary\n";
        break;
    case 3:
        cout << "\nMarch\n";
        break;
    case 4:
        cout << "\nApril\n";
        break;
    case 5:
        cout << "\nMay\n";
        break;
    case 6:
        cout << "\nJune\n";
        break;
    case 7:
        cout << "\nJuly\n";
        break;
    case 8:
        cout << "\nAugust\n";
        break;
    case 9:
        cout << "\nSeptember\n";
        break;
    case 10:
        cout << "\nOctober\n";
        break;
    case 11:
        cout << "\nNovember\n";
        break;
    case 12:
        cout << "\nDecember\n";
        break;
    default:
        cout << "\nEnter a number between 1 and 12";
    }
}

int main()
    {
        weekday();
        month();
        return 0;
    }