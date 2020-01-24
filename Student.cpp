#include <iostream>
#include <iomanip>
#include "Student.h"
#include <cstring>

using namespace std;

Student::Student(char* firstName, char* secondName, int id, float gpa) {
	this->firstName = new char[strlen(firstName)+1];
	strcpy(this->firstName, firstName); //Allocates just enough memory for the names.
	this->secondName = new char[strlen(secondName)+1];
	strcpy(this->secondName, secondName);
	this->id = id;
	this->gpa = gpa;
}

Student::~Student() {
	if (firstName) {
		delete []firstName;
	}
	if (secondName) {
		delete []secondName;
	}
}

void Student::print() {
	cout << firstName << " " << secondName << ", " << id << ", " << setprecision(2) << fixed << gpa << endl;
}

int Student::getId() {
	return id;
}

float Student::getGpa() {
	return gpa;
}
