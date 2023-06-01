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
            Course(int courseNumber, string courseName, string courseDescription);
            int getCourseNumber() const;
            string getCourseName() const;
            string getCourseDescription() const;
            void printCourseInfo();
        private:
            int number;
            string name;
            string description;
    };
}
#endif