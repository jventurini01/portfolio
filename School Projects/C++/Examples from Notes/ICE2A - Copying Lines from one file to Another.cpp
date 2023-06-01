//ECE476 Class Exercise 2A | Joseph Venturini
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
    string line1;
    ifstream file1("ClassEx.txt");
    ofstream file2;
    file2.open("Writeto.txt");
    if (file1.is_open())
    {
        while (getline(file1, line1))
            file2 << line1 << '\n';
            file1.close();
            file2.close();
    }
    return 0;
}