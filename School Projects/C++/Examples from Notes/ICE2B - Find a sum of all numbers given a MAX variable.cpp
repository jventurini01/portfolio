//ECE476 Class Exercise 2B | Joseph Venturini
#include<iostream>
using namespace std;
const int MAX = 10;
int main()
{
    int values[MAX];
    int num;
    int sum = 0;

    for (num = 0; num < MAX; num++)
        cin >> values[num];
    
    for (num = MAX-1; num >= 0; num--)
        {
            cout << values[num] <<endl;
            sum = sum + values[num];
        }

    cout << "sum = " << sum << endl;
    return 0;
}