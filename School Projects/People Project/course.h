//course.h
#ifndef COURSE_H
#define COURSE_H
#include <string>
using namespace std;

namespace people
{
    class Course
    {
        public:
            Course(int courseNumber, string courseName, string courseDescription)
            int getCourseNumber();
            string getCourseName();
            string getCourseDescription();
    };
}
