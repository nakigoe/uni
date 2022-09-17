#include <iostream>
#include <cmath>

using namespace std;

/*
* 1. Пользователь вводит сторону квадрата, вывести его площадь и периметр
* 2. Даны два числа, найти их среднее арифметическое и среднее геометрическое
* 3. Даны два числа, вывести сначала наибольшее, затем наименьшее
* 4. Составить программу, которая считывает две скорости, одна в км/ч, другая м/сек,
*       определить, какая из них больше
* 5. Начинающий спортсмен в первую тренировку пробежал 2 километра, за каждую следующую тренировку
*       он бежит на 5% больше от предыдущей, написать программу, которая выводит пробег за 60 тренировок
*/

float findSportsmanProgress(float firstSprint, float sprintCount)
{
    float progress = firstSprint;
    float sum = 0;

    for (int i = 0; i < sprintCount; i++)
    {
        sum += progress;
        progress += progress * 0.05;
    }

    return sum;
}

int getSquareArea(int side)
{
    return side * side;
}

int getSquarePerimeter(int side)
{
    return 4*side;
}

void printAveragesValues(float first, float second)
{

    float averageArithmetical = (first + second) / 2;
    float averageGeometrical = sqrt(first * second);

    cout << "Average arithmetical: " << averageArithmetical << " "
        << "Average geometrical: " << averageGeometrical << endl;
}

void printSorted(int first, int second)
{
    if (first > second)
    {
        cout << "Answer: " << first << ", " << second << endl;
        return;
    }

    else if (second > first) 
    {
        cout << "Answer: " << second << ", " << first << endl;
    }

    else if (first = second)
    {
        cout << "The numbers are equal, " << first << " = " << second << endl;
    }
}

void compareTwoSpeeds(float kilometresPerHour, float meterPerSecond)
{
    if ((kilometresPerHour / 3.6) > meterPerSecond)
        cout << "km/h is greater than m/sec: " << kilometresPerHour;
    else if ((kilometresPerHour / 3.6) < meterPerSecond)
        cout << "m/sec is greater than km/h: " << meterPerSecond;
    else if ((kilometresPerHour / 3.6) == meterPerSecond)
        cout << meterPerSecond << " m/sec = " << kilometresPerHour << " km/h" << endl;
}

void main()
{
    int squareSide;
    int first, second;
    cout << "Enter a square Side value to see the square Area and Perimeter: ";
    cin >> squareSide;

    cout << "Area: " << getSquareArea(squareSide) << " ";
    cout << "Perimeter: " << getSquarePerimeter(squareSide) << endl << endl;

    cout << "Compute averages for two numbers" << endl << "Enter the first number: ";
    cin >> first;
    cout << "Enter the second number: ";
    cin >> second;

    printAveragesValues(first, second);
    cout << endl;

    cout << "Sort two numbers by descending order" << endl << "Enter the first number: ";
    cin >> first;
    cout << "Enter the second number: ";
    cin >> second;

    printSorted(first, second);
    cout << endl;

    cout << "Compare two speeds" << endl << "Enter the first speed in km/h: ";
    cin >> first;
    cout << "Enter the second speed in m/s: ";
    cin >> second;

    compareTwoSpeeds(first, second);
    cout << endl;

    cout << "Calculate total kilometers for the sportman" << endl << "Enter the first distance run: ";
    cin >> first;
    cout << "Enter the number of runs: ";
    cin >> second;

    float answer = findSportsmanProgress(first, second);
    cout << "Total number of kilometers the sportsman has run, concidering the 5% increase for each run: " << answer << endl;
    
    cout << endl;
    cout << "The program has completed its run. Have a nice day! "<<endl;
}