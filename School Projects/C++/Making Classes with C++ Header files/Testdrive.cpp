#include <iostream>
#include<string>
#include "Employee.h"
#include "Teacher.h"
#include"Programmer.h"

using namespace std;



int main()

{
	//most common use of polymorphism is when parent class refrence 
	//is used to refer to child class object
	Employee Employee1 = Employee {"Wafa", "instructor", 35};
	Employee Employee2 = Employee{ "Laila", "instructor", 22 };
	Programmer P1 = Programmer{ "Subash", "programmer", 20 , "C++" }; 
	P1.ShowMyData();
	int l;
	int k;

	Employee test[10];
	for (int i = 0; i < 10; i++)
	{
		k = i + 1;
		cout << "Employee #" << k << ":\n" << "Name: ";
		cin >> test[i].Name;
		cout << "Job: ";
		cin >> test[i].Job;
		cout << "Age: ";
		cin >> test[i].Age;
	}

	for (int j = 0; j < 10; j++)
	{
		l = j + 1;
		cout << "Employee #" << l << ":\n";
		test[j].ShowMyData();
	}
	//Employee1.Work();
	//t.Work();
	//P1.Work();
	int testing = 10;
	cout << testing << " * " << testing << " = " << Employee1.function(testing) << endl;

}