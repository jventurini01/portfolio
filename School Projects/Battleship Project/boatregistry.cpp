#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;
int main()
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
            }
    }
        
    return 0;
}