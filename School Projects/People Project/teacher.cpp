//teacher.cpp
#include <string>
#include <cstdlib>
#include <iostream>
#include "teacher.h"
using namespace std;

namespace people
{
    Teacher::Teacher(string teacherName, double teacherSalary, string teacherCourses[3]):
                    name(teacherName), salary(teacherSalary), courses(teacherCourses);
    {
        //Empty on purpose
    }

    double Teacher::getSalary() const
    {
        return salary;
    }

    void Teacher::printTeacherCourses() const
    {
        cout << getName() << " Teaches:" << endl;
        for (int i = 0, i < 3)
        {
            cout << teacherCourses[i] << endl;
        }
    }

    void Teacher::printName()
    {
        cout << "This is teacher " << getName() << endl;
    }
}