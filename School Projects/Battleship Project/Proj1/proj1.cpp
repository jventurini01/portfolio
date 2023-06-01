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
    //no need for is open here
    // just read by getline(in,line,'\n) ; this will also remove the header
    //now you can check if the reading fails means empty by checking if in.fail()
    //if so then print empty messages and return 0
    //after closing the above if
    getline(in,line,'\n');
    if (in.fail())
    {
        cout << "************  File Is Empty  ************" << endl;
        cout << "==> Input configuration file is empty"<< endl;
        cout << "==> No information to process" << endl;
        cout << "==> Program is terminating" << endl;
        cout << "*****************************************" << endl;
        return 0;
    }
    InitializeBoard(board);
    PlaceBoats(board, in);

    while (numHits < MAX_HITS) //not 12 it is MAX_HITS
    {
        ObtainMove(row, col, board);
        if (CheckMove(row, col, board) == true)
        {
            numHits = numHits + 1;
        }
        numMoves = numMoves + 1; //I took this out because you need to increase the moves anyway

    }
    //Here print the congratulation messages and percentage as below
    cout << "\nCONGRATULATIONS!!!  You sunk all four boats.\n";
    cout << "It took " << numMoves << " shots to sink all the boats.\n";
    cout << "Your percentage of hits is " << float(numHits) / numMoves * 100.0 << "%.\n";
    
    PrintBoard(board);
    cout << '\n';
    return 0;
//call print function
//print empty line
//return0;
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
        cout << endl << string(11, '*') << "  File Open Error  " << string(11, '*') << endl;
        cout << "==> Input file failed to open properly!!\n";
        cout << "==> Attempted to open file: " << filename << endl;
        cout << "==> Please try again...\n";
        cout << string(41, '*') << endl << endl;
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
    for (row = 0; row < NUM_ROWS; row++)
        for (col = 0; col < NUM_COLS; col++)
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
    for (row = 0; row < NUM_ROWS; row++)
    {
        cout << setw(3) << row << ":";
        for (col = 0; col < NUM_COLS; col++)
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
    bool error = true;//leave only declaration remove the intialization
    while (error == true) //I would do while loop instead to allow me do guessting atleast one time
    {
        PrintBoard(board);
        cout << "\nFor your guess, enter in the row and column positions of" << '\n' << "the game board. Please enter the row value first." << '\n' << endl;
        cout << "ROW value (From 0 to 9): ";
        cin >> row;
        cout << '\n' << "COLUMN value (From 0 to 9): ";
        cin >> col;
        error == false;
       // below you check row and col then col only in case row if correct 
        if (row >= NUM_ROWS || row >= NUM_ROWS)//I made correction here
        {
            //print this message to match the out put (<< "\nINVALID ROW VALUE!!!  Valid row values are 0 to " 
          //  << NUM_ROWS - 1 << endl;)
            cout << '\n' << "INVALID CHOICE!!! please choose a position marked with a '.'" << '\n' << endl;
            error = true;
            //here you do same check for col same as you did for row
            //{inside the bracetes print invalide message }
        }
        else if (col >= NUM_COLS || col >= NUM_COLS)
        {
            cout << '\n' << "INVALID CHOICE!!! please choose a position marked with a '.'" << '\n' << endl;
            error = true;
        }
        //assign true to error because error happened
        //other you check only col for case when row is correct
        //use else if not if
        else if (row < 0 || col < 0) //(col< 0 || col >= NUM_COLS)
        {
           //replace the message (<< "\nINVALID COLUMN VALUE!!!  Valid column values are 0 to " 
           // << NUM_COLS - 1 << endl;)
            cout << '\n' << "INVALID CHOICE!!! please choose a position marked with a '.'" << '\n' << endl;
            error = true;
            //assign true to error
        }
        //make it else if 
        else if (board[row][col] == 'X' || board[row][col] == 'H')
        {
            //replace the message ( "\nINVALID CHOICE!!! please choose a position marked with a '.'\n")
            cout << '\n' << "INVALID CHOICE!!! please choose a position marked with a '.'" << '\n' << endl;
            error = true;
            //assign true to error
        }
        else
        {
            error = false;
        }
    }
   // while (error);
}
bool CheckMove(int row, int col, GameBoard board)
{
    //replace all above with on array you can call it boat[4]={0,0,0,0};
//you if should check between >=1 and <=4
    int boat[4];
    if (board[row][col] =='1' || board[row][col] =='2' || board[row][col] =='3' || board[row][col] =='4')
    {
        cout << "\n......Hit!" << endl;
        switch (board[row][col])
        {
        case '1':
            boat[0]++;
            if (boat[0]==3)
            {
                cout << "\nYou sank boat #1!\n";
            }
            break;
        case '2':
            boat[1]++;
            if (boat[1]==3)
            {
                cout << "\nYou sank boat #2!\n";
            }
            break;
        case '3':
            boat[2]++;
            if (boat[2]==3)
            {
                cout << "\nYou sank boat #3!\n";
            }
            break;
        case '4':
            boat[3]++;
            if (boat[3]==3)
            {
                cout << "\nYou sank boat #4!\n";
            }
            break;
        default:
            cout << "\nError on detecting a hit - invalid value\n";
            exit(1);
        }
        board[row][col] = 'H';
        return true;
    } 
    else if (board[row][col] = '.')
    {
        cout << "\n......Miss!";
        board[row][col] = 'X';
        return false;
    }
    else
    {
        cout << "Error in program.  There was a problem checking the move.\n";
        return false;
    }
//     then inside the bracets  print "Hit " message -
//     then inside thw bracetes do below-
    //easier than what you listed below is to use switch statment -
    //then check each case -
    //for case 1 as an example :-
    //your increament the index of boat array boat[0]++;-
    //then check if the boat[0] ==3 three bombs -
    //if yes print "You sank boat #-
    //then break -
    // all cases same with different index number -
    //your default should be error message "Error on detecting a hit - invalid value\n"-
    //then exit (1);-
    //close the switch and inside the first if write the following-
    //assign 'H' to board[row][col]-
    //return true; -
    //here close the first if-
    //you can remove below if control flow if you would like
    //remove below
    //here you need else if statment to check if the cell of the board empty means =='.'
    //then in bracetes 
    // print Miss messgae then assign 'X' to this cell
    //close this if bracetes
    //else add below
    // cout << "Error in program.  have a problem checking the move\n";
   // return false;
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