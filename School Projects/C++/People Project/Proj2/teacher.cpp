//teacher.cpp
#include <string>
#include <cstdlib>
#include <iostream>
#include "teacher.h"
using namespace std;

namespace people
{
    Teacher::Teacher(string teacherName, int teacherAge, double teacherSalary)
    : Person(teacherName, teacherAge), salary(teacherSalary)
    {
        //Empty on purpose
    }

    double Teacher::getSalary() const
    {
        return salary;
    }

    void Teacher::printTeacherCourses()
    {
        cout << getName() << " teaches:\n";
        for (int i = 0; i < 3; i++)
        {
            cout << teacherCourses[i] << endl;
        }
    }

    void Teacher::printName()
    {
        cout << "This is teacher " << getName() << endl;
    }
}