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
            Teacher(string teacherName, int teacherAge, double teacherSalary);
            double getSalary() const;
            void printTeacherCourses();
            void printName();
            string teacherCourses[3];
        private:
            double salary;
    };
}
#endif