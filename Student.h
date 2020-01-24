#pragma once
#include <iostream>

using namespace std;

//Emma Shu, 12/13/2019: The header file to the student class that is stored in the node class.

class Student {
	public:
		Student(char* firstName, char* secondName, int id, float gpa);
		virtual ~Student();
		void print();
		int getId();
		float getGpa();
	private:
		char* firstName;
		char* secondName;
		int id;
		float gpa;
};		
