//student.h
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "person.h"
using namespace std;

namespace people
{
    class Student : public Person
    {
        public:
            Student(string studentName, int studentAge, int studentNumber, string classList[3]);
            int getStudentNumber() const;
            void printCourseList() const;
            void addCourse();
            void delCourse();
            void printName();
            //friend bool equal
    };
}