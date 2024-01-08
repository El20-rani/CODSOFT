#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    int random_number = rand() % 100 + 1;
    int guessed_no;
    int counter = 0;
    while (true)
    {
        cout << "Enter your guess (1 to 100):";
        cin >> guessed_no;
        counter++;
        if (guessed_no < random_number)
        {
            cout << "Your guess is too low. Guess again.\n";
        }
        else if (guessed_no > random_number)
        {
            cout << "Your guess is too high. Guess again.\n";
        }
        else
        {
            cout << "\nYour guess is correct! You got it after " << counter << " tries.\n";
            break;
        }
    }

    return 0;
}