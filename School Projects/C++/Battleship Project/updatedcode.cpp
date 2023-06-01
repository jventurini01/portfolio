// Project -01 - Battle Boats

// This program creates a two-dimensional 10x10 game board.  Four boats
// are placed on the board by reading their location from a file
// The player tries to find all the boats in the fewest number of 
// tries.  Program outputs number of tries it takes to sink the
// four boats and the percentage of hits out of the attempts made

// ***********************************************************************

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

const int NUM_ROWS = 10;  // Number of rows and columns in the gameboard.
const int NUM_COLS = 10;
const int MAX_HITS = 12;
const string HASH = "####################"; // used when printing out the header

// create new data type for the two-dimensional array used for the game board
typedef char GameBoard[NUM_ROWS][NUM_COLS];  

// Function Prototypes
void InitializeBoard(GameBoard);  // initialize board to all .'s.

void OpenConfigFile(ifstream&);		// open the configuration file
void PlaceBoats(GameBoard, ifstream&);         // determine placement of bombs on the board
void PrintBoard(GameBoard);  // prints game board status during the playing of the game

void ObtainMove(int&, int&, GameBoard); // get a valid move for placement
bool CheckMove(int, int, GameBoard);  // place valid move onto the game board

int main()
{
    // varialbe declarations
    int row;				// row of guess
    int col;				// column of guess
    GameBoard board;		// 2-d array containing the board as characters
    int numMoves = 0;		// number of guesses made to hit ships
	int numHits = 0;		// number of hits on boats - should reach 12
	bool hit;				// indicates if a hit was made
	string line;			// reads the header line in the input configuration file

	ifstream in;			// file stream containg the configuration file
    
    
    OpenConfigFile(in);
    if (in.is_open())
    {
        while(getline(in, line))
            cout << line << '\n';
        in.close();
    }
    InitializeBoard(board);
    PlaceBoats(board, in);
    while (numHits < 12)
    {
        ObtainMove(row, col, board);
        if(CheckMove(row, col, board) == true)
        {
            numHits = numHits + 1;
            numMoves = numMoves + 1;
        }
        else
        {
            numMoves = numMoves + 1;
        }
    }
	
	
} // End main()

//********************************************************************************
//********************************************************************************
//********************************************************************************

void OpenConfigFile(ifstream& inFile)		// open the configuration file
{
	string  filename;                       // Name of user specified input file
	cout << "\nEnter the name of the input file now: ";
	cin >> filename;
	cout << filename << endl;
	inFile.open(filename.c_str());
	while (!inFile)
	{
		cout << endl << string(11,'*') << "  File Open Error  " << string(11,'*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << filename << endl;
		cout << "==> Please try again...\n";
		cout << string(41,'*') << endl << endl;
		inFile.clear();
		cout << "Enter the name of the input file now: ";
		cin >> filename;
		cout << filename << endl;
		inFile.open(filename.c_str());
	}
}
void InitializeBoard(GameBoard board)
{
     cout << "\nInitializing board....\n\n";
     int row, col;
     for (row = 0; row < NUM_ROWS ; row++)
         for (col = 0; col < NUM_COLS ; col++)
             board[row][col] = '.';
     cout << "Game board has been initialized....\n";
}  
void PrintBoard(GameBoard board)
{
	 cout << right;
     cout << "\n  =====> Current Board Status <=====\n";
     int row, col;

	 // Print out the column heading values for the board
     cout << setw(7) << "0";
     for (col = 1; col < NUM_COLS; col++)
         cout << setw(3) << col;
     cout << endl;				// terminate the column heading line

     cout << setw(7) << "-";
     for (col = 1; col < NUM_COLS; col++)
         cout << setw(3) << "---";
     cout << endl;

	 // Print out each row of the board
     for (row = 0; row < NUM_ROWS ; row++)
     {
         cout << setw(3) << row << ":";
         for (col = 0; col < NUM_COLS ; col++)
         {
		     // if the position to print out is a boat, print out
			 // a . instead.  Otherwise, print out the contents
			 // of the position
             if (board[row][col] >= '1' && board[row][col] <= '4')
                 cout << setw(3) << '.'; // hide the boat numbers
             else 
                 cout << setw(3) << board[row][col];    
         }
         cout << endl;
     }
}
void ObtainMove(int& row, int& col, GameBoard board)
{
    PrintBoard(board);
    bool error = true;
    while (error == true)
    {
        cout << "\nFor your guess, enter in the row and column positions of" << '\n' << "the game board. Please enter the row value first." << '\n' << endl;
        cout << "ROW value (From 0 to 9): ";
        cin >> row;
        cout << '\n' << "COLUMN value (From 0 to 9): ";
        cin >> col;
        
        if (row >= NUM_ROWS || col >= NUM_COLS)
        {
            cout << '\n' << "INVALID CHOICE!!! please choose a position marked with a '.'" << '\n' << endl;
            continue;
        }
        if (row < 0 || col < 0)
        {
            cout << '\n' << "INVALID CHOICE!!! please choose a position marked with a '.'" << '\n' << endl;
            continue;
        }
        if (board[row][col] == 'X' || board[row][col] == 'H')
        {
            cout << '\n' << "INVALID CHOICE!!! please choose a position marked with a '.'" << '\n' << endl;
            continue;
        }
        error = false;
    }
}
bool CheckMove(int row, int col, GameBoard board)
{
    int boat1 = 0;
    int boat2 = 0;
    int boat3 = 0;
    int boat4 = 0;
    string boatArray[MAX_HITS][3];
    

    if(board[row][col] == '1') 
    {
        board[row][col] = 'H';
        cout << "\n" << setw(3) << "......Hit!!!";
        boat1++;
        if(boat1 == 3) 
        {
            cout << "\n" << setw(3) << "You sank boat #1!" << endl;
        }
        return true;
    }
    else if (board[row][col] == '2') 
    {
        board[row][col] = 'H';
        cout << "\n" << setw(3) << "......Hit!!!";
        boat2++;
        if(boat2 == 3) 
        {
            cout << "\n" << setw(3) << "You sank boat #2!" << endl;
        }
        return true;
    }
    else if (board[row][col] == '3') 
    {
        board[row][col] = 'H';
        cout << "\n" << setw(3) << "......Hit!!!";
        boat3++;
        if(boat3 == 3) 
        {
            cout << "\n" << setw(3) << "You sank boat #3!" << endl;
        }
        return true;
    }
    else if (board[row][col] == '4') 
    {
        board[row][col] = 'H';
        cout << "\n" << setw(3) << "......Hit!!!";
        boat4++;
        if(boat4 == 3) 
        {
            cout << "\n" << setw(3) << "You sank boat #4!" << endl;
            }
        return true;
    }
    else 
    {
        board[row][col] = 'X';
        cout << "\n" << setw(3) << "......Miss!!!";
        return false;
    }
}
void PlaceBoats(GameBoard board, ifstream& in)         // determine placement of bombs on the board
{
    // This function places the boats into the board space.  
	// information is read from the input configuration file for the plackement
	// The files are assumed to be correct.
	// Boats are 3 spots lone each and are numbered 1,2,3 and 4.
    
    char boatNum;      // Number of boat to place in the game board
    int row, col;     // row and column of the array for bomb placement
	int count = 0;
    
    cout << "\nPlacing boats onto the game board....\n"; // information line
    
	// read all the information from the input configuration file

	// information on the line is row, col, boat number
    
   in >> row >> col >> boatNum;
   while (count <= 12)
   {
       board[row][col] = boatNum;
	   in >> row >> col >> boatNum;  // get next boat placement
	   count++; // used as a safety check for my input files
   }
   if (count < 12) // not required for students
   {
       cout << "not enough data in configuration file\n";
	   exit(1);
   }
}