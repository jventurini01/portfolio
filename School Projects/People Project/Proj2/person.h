//person.h
#ifndef PERSON_H
#define PERSON_H
#include <string>
using namespace std;

namespace people //new namespace, much like employeesavitch in ClassEx4
{
    class Person // Defines Person Class
    {
        public: 
            Person(string personName, int personAge); //String for name, Int for Age
            string getName() const; //Function to get the student's name
            int getAge() const; //Function to get the student's age
            void printName() const; //Function to print the student's name in a sentence.
        private:
            string name;
            int age;
    };
}
#endif