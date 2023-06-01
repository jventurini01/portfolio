//person.cpp
#include <string>
#include <cstdlib>
#include <iostream>
#include "person.h"
using namespace std;

namespace people
{
    Person::Person(string personName, int personAge) : name(personName), age(personAge) //This line of code basically says that the name is the personName and the age is the personAge variable.
    {
        //This section of the code is empty on purpose, as its sole purpose is to put the code
        //below it into simpler terms.
    }

    string Person::getName() const
    {
        return name;
    }

    int Person::getAge() const
    {
        return age;
    }

    void Person::printName() const
    {
        cout << "This is " << getName() << '\n' << endl;
    }
}