#include <iostream>
using namespace std;
int main()
{
    int h;
    double gp, r;
    cout << "enter hourly rate of pay: $";
    cin >> r;
    cout << "enter number of hours worked,\n" << "rounded to a whole number of hours:";
    cin >> h;
    if (h > 40)
        gp = r * 40 +1.5 * r * (h - 40);
    else
        gp = r * hl
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "hours:" << h << endl;
    cout << "hourly pay: $" << r << endl;
    cout << "gross pay: $" << gp << endl;
    return 0;
} 