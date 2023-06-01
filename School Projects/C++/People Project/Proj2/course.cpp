//course.cpp
#include <string>
#include <cstdlib>
#include <iostream>
#include "course.h"
using namespace std;

namespace people
{
    Course::Course(int courseNumber, string courseName, string courseDescription):
                   number(courseNumber), name(courseName), description(courseDescription)
    {
        //This section of the code is empty on purpose.
    }

    int Course::getCourseNumber() const
    {
        return number;
    }

    string Course::getCourseName() const
    {
        return name;
    }

    string Course::getCourseDescription() const
    {
        return description;
    }

    void Course::printCourseInfo()
    {
        cout << "Class #" << getCourseNumber() << " : " << getCourseName() << endl;
        cout << "Class Description: " << getCourseDescription() << endl;
    }
}