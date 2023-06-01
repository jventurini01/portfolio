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
    InitializeBoard (board);
    PlaceBoats(board, in);

    while (numHits < 12)
    {
        PrintBoard(board);
        cout << "\nFor your guess, enter in the row and column positions of" << '\n' << "the game board. Please enter the row value first." << '\n' << endl;
        cout << "ROW value (From 0 to 9): ";
        cin >> row;
        cout << '\n' << "COLUMN value (From 0 to 9): ";
        cin >> col;
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
    //first get both row and col inputted into another array
    ofstream inputFile;
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
}

bool CheckMove(int row, int col, GameBoard board)
{
	string row;
    string column;
    int bothSame = 0;
    string boatArray[12][3];
    ifstream boats("boats.txt");
    if(boats.is_open())
    {
        for(int a = 0; a < 12; a++)
        {
            for(int b = 0; b < 3; b++)
            {
                boats >> boatArray[a][b];
            }
        }
    }
    while (bothSame == 0)
    {
    cout << "ROW value (From 0 to 9): ";
    cin >> row;
    cout << '\n' << "COLUMN value (From 0 to 9): ";
    cin >> column;
   
        for(int c = 0; c < 12; c++)
        {
           if(bothSame == 0) 
            {
                if(row == boatArray[c][0])
                {
                    for(int d = 1; d < 2; d++)
                    if(column == boatArray[c][d])
                    {
                        cout << "\n......Hit!!!\n" << endl;
                        bothSame = 1;
                        break;
                    }
                    else continue;
                }
                else continue;
            }
            else break;     
        }
        if(bothSame == 0)
            {
                cout << "\n......Miss!!!\n" << endl;
                return true;
            }
    }
        
    return 0;

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
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
   while (in && count <= 12)
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
