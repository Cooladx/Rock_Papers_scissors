#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string> // Include the string header
#include <limits> // Include the limits header
using namespace std;

char getComputerMove();
int getResults(char playerMove, char computerMove);
void displayResults(int result, char playerMove, char computerMove);


int main() 
{
    char playerMove;
    char computerMove;
    int attempts;
    

    cout << "\n\n\n\t Welcome to the Rock Paper Scissors Game\n";
    cout << "\n\n\n\tHow many times do you want to play?\n";
    cin >> attempts;

    srand(time(NULL));
    // Called once before the loop as the seed 
    // is set only once when the program starts

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    // Ignore remaining characters in input buffer

    for (int i = 0; i < attempts; ++i)
    {
        cout << "\n\t\tEnter r for ROCK, p for PAPER, and s for SCISSOR\n\t\t\t\t\t";

        string line;
        getline(cin, line);

        if (line.size() != 1 || !(line[0] == 'r' || line[0] == 'p' || line[0] == 's')) 
        // Input validation: makes sure user can't enter more than one character, causing multiple outputs to occur.
        {
            cout << "\t\t\tInvalid Player Move!!! Please Try Again." << endl;
            --i; // Decrement i to repeat the current iteration
            continue;
        }

        playerMove = line[0];

        computerMove = getComputerMove();

        int result = getResults(playerMove, computerMove);

         displayResults(result, playerMove, computerMove);
     
    }

    return 0;
    // Terminate
}



int getResults(char playerMove, char computerMove) 
{
    if (playerMove == computerMove) 
    {
        return 0;
    } 
    else if 
    ((playerMove == 's' && computerMove == 'p') ||
    (playerMove == 'p' && computerMove == 'r') ||
    (playerMove == 'r' && computerMove == 's')) 
    {
        return 1;
    }

    return -1;
}

char getComputerMove() 
{
    int move = rand() % 3;

    if (move == 0) 
    {
        return 'p';
    } 
    else if (move == 1) 
    {
        return 's';
    }
    return 'r';
}


void displayResults(int result, char playerMove, char computerMove) 
{
    if (result == 0) 
    {
        cout << "\n\t\t\tGame Draw!\n";
    } 
    else if (result == 1) 
    {
        cout << "\n\t\t\tCongratulations! You won the game!\n";
    } 
    else 
    {
        cout << "\n\t\t\t Unfortunate. Computer wins!\n";
    }

    cout << "\t\t\tYour Move: " << playerMove << endl;
    cout << "\t\t\tComputer's Move: " << computerMove << endl;
}