//ppt 7
#include <iostream>
#include <stdio.h>
using namespace std;

void PrintStars (int num)
{
    while (num > 0)
    {
        cout << '*';
        num--;
    }
    cout << endl;
}

int main()
{
    int n = 4;
    PrintStars(n);
    return 0;
} 