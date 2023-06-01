//student.cpp
#include <string>
#include <cstdlib>
#include <iostream>
#include "student.h"
using namespace std;

namespace people
{
    Student::Student(string studentName, int studentAge, int studentNumber, string classList[3]):
                    name(studentName), age(studentAge), number(studentNumber) list(classList)
    {
        //Empty on purpose
    }

    void Student::printCourseList()
    {
        cout << getName() << "is taking: " << endl;
        
        for (int i = 0, i < 3)
        {
            cout << string classList[i] << endl;
            i++;
        }
    }

    void Student::addCourse()
    {
        //Can't do this yet; need teacher information
    }

    void Student::delCourse()
    {
        //Can't do this yet; need teacher information
    }
    void Student::printName()
    {
        cout << "This is student " << getName() << endl;
    }
    bool equal()
    {
        //Can't do this yet; need teacher information
    }
}