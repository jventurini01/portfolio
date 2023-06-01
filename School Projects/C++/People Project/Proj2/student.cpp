//student.cpp
#include <string>
#include <cstdlib>
#include <iostream>
#include "student.h"
using namespace std;

namespace people
{
    Student::Student(string studentName, int studentAge, int studentNumber)
    : Person(studentName, studentAge), number(studentNumber)
    {
        //empty on purpose
    }

    int Student::getStudentNumber() const
    {
        return number;
    }

    void Student::printCourseList()
    {
        cout << Person::getName() << " is taking: " << endl;
        
        for (int i = 0; i < 3; i++)
        {
            cout << enrolledClasses[i] << endl;
        }

        cout << '\n';
    }   

    void Student::addCourse(Course test)
    {
        cout << "Adding " << test.getCourseName() << " to " << Person::getName() << "'s list of courses...\n";
        for (int j = 0; j < 3; j++)
        {
            if (enrolledClasses[j] == "-")
            {
                enrolledClasses[j] == test.getCourseName();
                cout << "Course successfully added." << endl;
                continue;
            }
        }
    }

    void Student::delCourse(Course test)
    {
        cout << "Removing " << test.getCourseName() << " from " << Person::getName() << "'s list of courses...\n";
        for (int j = 0; j < 3; j++)
        {
            if (enrolledClasses[j] == test.getCourseName())
            {
                enrolledClasses[j] == "-";
                cout << "Course successfully removed." << endl;
                continue;
            }
        }
    }
    
    void Student::printName()
    {
        cout << "This is student " << Person::getName() << endl;
    }
}