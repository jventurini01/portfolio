//pp8, this is for WRITING TO A FILE
#include<iostream>
#include<fstream>
using namespace std;
int main ()
{
    ofstream myfile;
    myfile.open("Text.txt");
    myfile << "yehehe";
    myfile.close();
    return 0;
}