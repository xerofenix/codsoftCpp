#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    // taking user input to generate random value
    cout << "Enter any value to generate a random number: ";
    int seed_value;
    cin >> seed_value;
    srand(seed_value);
    // generating random value and storing
    int random = rand();
    // cout << random;
    cout << "Random value generated! Start guessing it\nEnter number: ";
    double num;
    int count = 0;
    while (true)
    {
        cin >> num;
        if (num == random)
        {
            cout << "Congratulations! You guessed it right";
            break;
        }
        if (num > random)
        {
            cout << num << " is high. Enter again: ";
        }
        if (num < random)
        {
            cout << num << " is less, Enter again: ";
        }
        count++;
    }

    // prompt if user want to see how many times it take to guess
    cout << "\nDo you want to display, how many times it took to guess? 'yes'(y),'no'(n): ";
    char ch;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        cout << "It took " << count + 1 << " times to guess it";
    }
    else if (ch == 'n' || ch == 'N')
    {
        cout << "OK, Thankyou!";
    }
    else
    {
        cout << "Invalid input";
    }

    return 0;
}