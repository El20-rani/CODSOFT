#include <iostream>
using namespace std;
int main()
{
    double n1, n2;
    int ch;
    cout << "\n\t\t\t\tWelcome to the simple calculator\n";
    cout << "\n\t\t\t\tEnter two numbers:";
    cin >> n1 >> n2;
    cout << "\t\t\t\tEnter:\n\t\t\t\t\t1. For Addition\n\t\t\t\t\t2. For Subtraction\n\t\t\t\t\t3. For Multiplication\n\t\t\t\t\t4. For Division\n\t\t\t\t\t5. To exit\n";
    cin >> ch;

    switch (ch)
    {
    case 1:
        cout << "\n\t\t\t" << n1 << " + " << n2 << " = " << n1 + n2 << "\n";
        break;
    case 2:
        cout << "\n\t\t\t" << n1 << " - " << n2 << " = " << n1 - n2 << "\n";
        break;
    case 3:
        cout << "\n\t\t\t" << n1 << " * " << n2 << " = " << n1 * n2 << "\n";
        break;
    case 4:
        if (n2 == 0)
            cout << "Division by zero not allowed.\n";
        else
            cout << "\n\t\t\t" << n1 << " / " << n2 << " = " << n1 / n2 << "\n";
        break;
    case 5:
        cout << "Exiting...\n";
        exit(0);
        // break;
    default:
        cout << "Invalid choice!!! Please Enter the right number.\n";
        break;
    }
    return 0;
}