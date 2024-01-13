#include <iostream>
using namespace std;

// initializes the game board
void initializeGameBoard(char gameBoard[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            gameBoard[i][j] = ' ';
        }
    }
}

// shows the current state of the board
void displayGameBoard(const char gameBoard[3][3])
{
    cout << "  1 2 3" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << i + 1 << " ";
        for (int j = 0; j < 3; j++)
        {
            cout << gameBoard[i][j] << " ";
        }
        cout << endl;
    }
}

// checks whether a move is valid or not
bool isTheMoveValid(const char gameBoard[3][3], int row, int col)
{
    return (row >= 1 && row <= 3 && col >= 1 && col <= 3 && gameBoard[row - 1][col - 1] == ' ');
}

// checks whether the current player has won
bool checkForWin(const char gameBoard[3][3], char player)
{
    // Checks the rows, columns, and diagonals
    for (int i = 0; i < 3; ++i)
    {
        if (gameBoard[i][0] == player && gameBoard[i][1] == player && gameBoard[i][2] == player)
        {
            return true;
        }
        if (gameBoard[0][i] == player && gameBoard[1][i] == player && gameBoard[2][i] == player)
        {
            return true;
        }
    }
    if (gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player)
    {
        return true; // Checks diagonal from top-left to bottom-right
    }
    if (gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player)
    {
        return true; // Check diagonal from top-right to bottom-left
    }
    return false;
}

// checks whether the game is a draw or not
bool checkForDraw(const char gameBoard[3][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (gameBoard[i][j] == ' ')
            {
                return false; // There is an empty space, the game is not a draw
            }
        }
    }
    return true; // All spaces are filled, the game is a draw
}

// switch players
void switchPlayers(char &currentPlayer)
{
    if (currentPlayer == 'X')
        currentPlayer = 'O';
    else
        currentPlayer = 'X';
}

void main()
{
    char gameBoard[3][3];
    char currentPlayer = 'X';
    bool gameRunning = true;

    do
    {
        initializeGameBoard(gameBoard);
        int row, col;

        while (true)
        {
            displayGameBoard(gameBoard);

            // Prompt the current player to enter their move
            cout << "Player " << currentPlayer << ", enter your move (by typing the numbers for row and column): ";
            cin >> row >> col;

            // Check if the move is valid
            if (isTheMoveValid(gameBoard, row, col))
            {
                // Update the board with the player's move
                gameBoard[row - 1][col - 1] = currentPlayer;

                // Check for a win
                if (checkForWin(gameBoard, currentPlayer))
                {
                    displayGameBoard(gameBoard);
                    cout << "Congratulations Player " << currentPlayer << " you won the game!!!!\n";
                    break;
                }

                // Check for a draw
                if (checkForDraw(gameBoard))
                {
                    displayGameBoard(gameBoard);
                    cout << "The game is a draw!\n";
                    break;
                }

                // Switch players for the next turn
                switchPlayers(currentPlayer);
            }
            else
            {
                cout << "That was an invalid move. Try again.\n";
            }
        }

        // Ask if the players want to play again
        char playAgain;
        cout << "Do you want to play again? (Type: y/n): ";
        cin >> playAgain;
        gameRunning = (playAgain == 'y' || playAgain == 'Y');

    } while (gameRunning);

    cout << "Thanks for playing! Hope You had fun with the game.\n";
}
