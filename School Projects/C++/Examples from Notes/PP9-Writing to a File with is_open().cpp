//pp9, Writing to a file with is_open()
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream myfile("Text2.txt");
    if (myfile.is_open())
    {
        myfile << "yehehe";
        myfile.close();
    }
    else
    {
        cout << "you can't open this file, idiot";
    }
    return 0;
}