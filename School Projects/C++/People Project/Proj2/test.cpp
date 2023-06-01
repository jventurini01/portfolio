//test.cpp
#include <string>
#include <cstdlib>
#include <iostream>
#include "person.h"
#include "student.h"
#include "teacher.h"
#include "course.h"
using namespace people;

bool operator == (Student s1, Student s2)
{
    int matches;
    for (int i = 0; i < 3; i++)
    {
        if (s1.enrolledClasses[i] == s2.enrolledClasses[i])
        {
            matches++;
        }
    }
    
    if (matches == 3)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    //Task 1:
    //initializing 5 courses, with funny descriptions:
    Course ECE001(1, "Mathematical Methods", "It's self-explanatory.");
    Course ECE002(2, "Applied Electromagnetics", "It's like ECE001, but with every single letter in the Greek Alphabet!");
    Course ECE003(3, "Digital Systems", "Clearly the correct choice.");
    Course ECE004(4, "Big Data and Deep Learning", "You have big data, and you have very big data.");
    Course ECE005(5, "Virtual Machines", "Picture this. You're a computer, looking at a computer, inside a computer!");

    //initializing 3 persons:
    Person Ieuan("Ieuan", 21);
    Person Ethan("Ethan", 21);
    Person Kevin("Kevin", 20);

    //Task 2:
    //initializing 3 students:
    Student Joey("Joey", 20, 1);
    Student Stephen("Stephen", 21, 2);
    Student Brandon("Brandon", 21, 3);

    //initializing 3 teachers:
    Teacher Romeo("Romeo Pascone", 69, 25.00); 
    Teacher George("Georgio Giakos", 58, 30.00);
    Teacher Cristian("Cristian Simoni", 20, 20.00);

    //Task 3:
    //entering students' enrolled courses...
    Joey.enrolledClasses[0] = "Mathematical Methods";
    Joey.enrolledClasses[1] = "Big Data and Deep Learning";
    Joey.enrolledClasses[2] = "Virtual Machines";

    Stephen.enrolledClasses[0] = "Applied Electromagnetics";
    Stephen.enrolledClasses[1] = "Big Data and Deep Learning";
    Stephen.enrolledClasses[2] = "Virtual Machines";

    Brandon.enrolledClasses[0] = "Mathematical Methods";
    Brandon.enrolledClasses[1] = "Big Data and Deep Learning";
    Brandon.enrolledClasses[2] = "Digital Systems";

    //Entering Teachers' Taught courses...
    Romeo.teacherCourses[0] = "Mathematical Methods";
    Romeo.teacherCourses[1] = "Applied Electromagnetics";

    George.teacherCourses[0] = "Digital Systems";
    George.teacherCourses[1] = "Big Data and Deep Learning";

    Cristian.teacherCourses[0] = "Virtual Machines";

    //Task 4:
    //Joey wants to be in the same classes as Brandon, so he chooses to remove Virtual Machines, ECE005, from his class list:
    Joey.delCourse(ECE005);
    //Joey then adds Digital Systems, course #3:
    Joey.addCourse(ECE003);
    //So Joey is now in the same courses as Brandon.

    //Task 5:
    //Joey is in the same courses as Brandon, and there is a function to prove it:
//    if (Joey == Brandon)
//    {
//        cout << "These two students share a schedule!\n";
//    }
//    else
//   {
//        cout << "These two students do not share a course.\n";
//    }
    
    //Tasks 6 and 7 at the same time:
    //Starting with the Persons:
    Ieuan.printName();
    Ethan.printName();
    Kevin.printName();

    //then the students:
    Joey.printName();
    Joey.printCourseList();
    Stephen.printName();
    Stephen.printCourseList();
    Brandon.printName();
    Brandon.printCourseList();

    //then the teachers:
    Romeo.printName();
    Romeo.printTeacherCourses();
    George.printName();
    George.printTeacherCourses();
    Cristian.printName();
    Cristian.printTeacherCourses();

    //then the courses, which i made a function for to utilize the three that i have not used yet:
    ECE001.printCourseInfo();
    ECE002.printCourseInfo();
    ECE003.printCourseInfo();
    ECE004.printCourseInfo();
    ECE005.printCourseInfo();
}