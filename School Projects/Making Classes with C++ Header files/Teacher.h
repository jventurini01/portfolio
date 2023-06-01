#include <iostream>
#include<string>
#include "Employee.h"

using namespace std;

class Teacher : public Employee {
public:
	string Subject;
	void TeachSubject()
	{
		cout << getName() << " teaches " << Subject;
	}

	Teacher(string name, string job, int age, string subject)
		: Employee(name, job, age)
	{
		Subject = subject;
	}
	void Work() {
		cout << Name << " is teaching " << Subject << endl;
	}
}; 