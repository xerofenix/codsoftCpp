#include <iostream>
using namespace std;

int main()
{
    double num1, num2;
    char operation;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the operation you want to perform ('+', '-', '*', '/'): ";
    cin >> operation;
    cout << "Enter the seond number: ";
    cin >> num2;

    if (operation == '+')
        cout << "The sum is: " << num1 + num2;

    else if (operation == '-')
        cout << "The difference is: " << num1 - num2;

    else if (operation == '*')
        cout << "The product is: " << num1 * num2;

    else if (operation == '/')
        cout << "The qoutient is: " << num1 / num2;
    else
        cout << "Invalid operation!";
}