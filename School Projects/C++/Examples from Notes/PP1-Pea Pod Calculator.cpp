#include <iostream>
int main()
{
    int np, ppp, tp;
    cout << "press return after entering a number.\n";
    cout << "enter number of pods";
    cin >> np;
    cout << "enter number of peas in a pod";
    cin >> ppp;
    tp = np * ppp;
    cout << "if you have ";
    cout << np;
    cout << "pea pods,\n";
    cout << "and";
    cout << ppp;
    cout << "peas in each pod, then\n";
    cout << "you have";
    cout << tp;
    cout << "total peas.";
    return 0;
}