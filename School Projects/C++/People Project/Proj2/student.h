//student.h
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include "person.h"
#include "course.h"
using namespace std;

namespace people
{
    class Student : public Person
    {
        public:
            Student();
            Student(string studentName, int studentAge, int studentNumber);
            int getStudentNumber() const;
            void printCourseList();
            void addCourse(Course test);
            void delCourse(Course test);
            void printName();
            string enrolledClasses[3];
            friend bool operator == (people::Student s1, people::Student s2);
        private:
            int number;
            
    };
}
#endif