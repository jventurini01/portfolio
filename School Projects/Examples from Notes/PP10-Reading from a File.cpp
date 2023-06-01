//pp10, reading from file
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    string line;
    ifstream myfile("Text2.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
            cout << line << '\n';
            myfile.close();
    }
    else
        cout << "we can't open the file, asshole";
    return 0;
}