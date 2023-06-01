//teacher.h
#ifndef TEACHER_H
#define TEACHER_H
#include <string>
#include "person.h"
using namespace std;

namespace people
{
    class Teacher : public Person
    {
        public:
            Teacher(string teacherName, double teacherSalary, string teacherCourses[3]);
            double getSalary() const;
            void printTeacherCourses();
            void printName;
    }
}
