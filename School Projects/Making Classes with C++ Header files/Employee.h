#include <iostream>
#include<string>
#include "AbstractEmp.h"


using namespace std;


class Employee : public AbstractEmployee {
protected:
	static int variable;

public:
	void setName(string name)
	{
		Name = name;
	}
	string getName()
	{
		return Name;
	}

	string Name;
	string Job;
	int Age;

	void setJob(string job)
	{
		Job = job;
	}
	string getJob()
	{
		return Job;
	}

	void setAge(int age)
	{
		Age = age;
	}

	int getAge()
	{
		return Age;
	}
	void ShowMyData() {
		cout << "Name - " << Name << " is " << Age << " works as " << Job << endl;
	}

	Employee(string name, string job, int age) {
		Name = name;
		Job = job;
		Age = age;

	}
	Employee(): Name(""), Job(""), Age(0) { 	}

	void GetPromoted() {
		if (Age > 30)
			cout << Name << " Got promoted" << endl;
		else
			cout << Name << " Sorry no promotion for you" << endl;
	}

	virtual void Work() {
		cout << Name << " fix bugs, distrubute tasks ,..." << endl;
	}
	
	static int function(int A)
	{
		return (A*A);
	}
};
#pragma once
