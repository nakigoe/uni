/* 
* 6. Пользователь вводит 2 - мерный массив 3 на 3, вычислить сумму по строкам
* 7. Пользователь вводит 2-мерный массив 3 на 3 и произвольное число. Подсчитать, сколько раз это число встречается в массиве
*/

#include <iostream>

using namespace std;

void arrayWorkout()
{
    int a[3][3]; //manual input array
    int s[3] = { 0,0,0 }; //the sum of numbers in each line
    int n; //control number
    int c = 0; //counter

    cout << "Please enter an integer to find the number of its occurences in the coming array: ";
    cin >> n;

    cout << "\nPlease enter the 3x3 array:\n\n";

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "a[" << i << "][" << j << "] = ";
            cin >> a[i][j];
            if (n == a[i][j]) c++; //increase the counter if the control number is in the array
            s[i] = s[i] + a[i][j]; //sum up the numbers located in one line
        }
        cout << "\nThe sum of numbers in line " << i << " is " << s[i] << endl<<endl;
    }

    cout << "The number of occurences of " << n << " in the array is " << c << endl;
}

void main()
{
    arrayWorkout();
}