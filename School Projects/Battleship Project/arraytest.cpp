#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;
int main()
{
    int row;
    int column;
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
    for (int c = 0; c < 12; c++)
    {
        for (int d = 0; d < 3; d++)
        {
            cout << setw(15) << boatArray[c][d];   
        }
        cout << '\n';
    }
    return 0;
}