//project sample dumpster
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;
int main()
{
    int row = 0; 
    int column = 0;
    while (row == 0 && column == 0)
    {
        cout << "For your guess, enter in the row and column positions of" << '\n' << "the game board. Please enter the row value first." << '\n' << endl;
        cout << "ROW value (From 0 to 9): ";
        cin >> row;
        cout << '\n' << "COLUMN value (From 0 to 9): ";
        cin >> column;
        if (row <= 9 && column <= 9)
        {
            continue;
        }
        else 
        {
            cout << '\n' << "INVALID CHOICE!!! please choose a position marked with a '.'" << '\n' << endl;
            row = 0; 
            column = 0;
        }
    }
    return 0;
}