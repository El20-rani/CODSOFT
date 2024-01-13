#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    srand((unsigned)time(NULL));
    int random_number = rand() % 100 + 1;
    int guessed_no;
    int counter = 7;
    cout << " Welcome to the number guessing game.\n Remember you only get 7 tries.";
    while (counter > 0)
    {
        cout << "\n Enter your guess (1 to 100):\n";
        cin >> guessed_no;
        counter--;
        if (guessed_no < random_number)
        {
            if (counter == 0)
            {
                cout << "\n Sorry! you have failed to guess correctly within 7 tries.\n The correct number was " << random_number << ".\n";
            }
            else
            {
                cout << " Your guess is too low. You have " << counter << " tries left. Guess again.\n";
            }
        }
        else if (guessed_no > random_number)
        {
            if (counter == 0)
            {
                cout << "\n Sorry!!! you have failed to guess correctly within 7 tries.\n The correct number was " << random_number << ".\n";
            }
            else
            {
                cout << " Your guess is too high. Guess again. You have " << counter << " tries left. Guess again.\n";
            }
        }
        else
        {
            cout << "\n Congrats!!! Your guess is correct! You got it with " << counter << " tries left\n";
            break;
        }
    }

    return 0;
}