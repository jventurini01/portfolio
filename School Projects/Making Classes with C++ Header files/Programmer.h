#pragma once
#include <iostream>
#include<string>
#include "Employee.h"
using namespace std;


class Programmer : public Employee {

public:
	string ProgLanguage;

	Programmer(string name, string job, int age, string progLanguage)
		: Employee(name, job, age)
	{
		ProgLanguage = progLanguage;
	}

	void Work() {
		cout << Name << " coding in " << ProgLanguage << endl;
	}
};