#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    char grade;
    cout << "input letter grade: " << endl;
    cin >> grade;
    switch(grade)
    {
        case 'a':
        case 'b': cout << "Good Work!";
        break;
        case 'c': cout << "Average Work.";
        break;
        case 'd':
        case 'f': cout << "You failed!";
        break;
        default: cout << grade << " is not a valid letter grade." << endl;
    }
    return 0;
}