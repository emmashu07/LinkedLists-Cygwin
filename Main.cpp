/*
 * Emma Shu, 1/20/2020: Linked lists is a student list program that uses a linked list
 * where the user can add, delete, print, and average the GPAs of the students.
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include "Node.h"
#include "Student.h"

using namespace std;

void addNode(Node* prev, Node* curr, int id, Node* newNode);
void deleteNode(Node* prev, Node* curr, int id);
void print(Node* head);
void average(Node* head, float &sum, int &num);
void releaseMemory(Node* head);
Student* readInStudent();

const int MAX_CHAR = 20;

int main() {
	char input[MAX_CHAR];
	bool running = true;
	Node* head = NULL;
	Node* null = NULL;

	cout << "Type HELP to view the commands and their functions." << endl;

	while (running) {
		cin.get(input, MAX_CHAR);
		cin.ignore(MAX_CHAR, '\n');

		for(int i = 0; i < strlen(input); i++) {
			input[i] = toupper(input[i]);
		}
	
		if (strcmp(input, "HELP") == 0) {
			cout << "Type ADD to add a student." << endl;
	       		cout << "Type PRINT to print all the students." << endl;
			cout << "Type AVERAGE to average all the GPAs." << endl;
			cout << "Type DELETE to delete a student." << endl;
			cout << "Type QUIT to exit the program." << endl;
		}
		else if (strcmp(input, "ADD") == 0) {
			Student* newStudent = readInStudent();
			int id = newStudent -> getId();
			Node* newNode = new Node(newStudent);
			if (!head) { // A couple of cases that can't be put in the method because the nodes cannot be passed by reference.
				head = newNode;
			}
			else if (id < head -> getStudent() -> getId()) {
				newNode -> setNext(head);
				head = newNode;
			}
			else {
				addNode(null, head, id, newNode);
			}
		}			
		else if (strcmp(input, "DELETE") == 0) {
			if (!head) { // Empty list.
				cout << "There is nothing to delete!" << endl;
			}
			else {
				cout << "Please enter the ID of the student you wish to delete: " << endl;
				int id;
				cin >> id;
				cin.ignore(MAX_CHAR, '\n');
				if (head -> getStudent() -> getId() == id) { // Head gets deleted.
					Node* temp = head;
					head = head -> getNext();
					delete temp;
				}
				else {
					deleteNode(null, head, id);
				}
			}
		}	
		else if (strcmp(input, "PRINT") == 0) {
			if (head) { // Make sure there is something to print.
				print(head);
			}
			else {
				cout << "No nodes are in the list." << endl;
			}
		}
		else if (strcmp(input, "AVERAGE") == 0) {
			float sum = 0;
			int num = 0;
			average(head, sum, num); // Passed by reference.
			if (head) {
				float average = sum / num;
				cout << setprecision(2) << fixed << average << endl;
			}
		}
		else if (strcmp(input, "QUIT") == 0) {
			running = false;
		}
		else {
			cout << "Not a valid command." << endl;
			cout << "Type HELP to view commands and their functions." << endl;
			cin.get(input, MAX_CHAR);
			cin.ignore(MAX_CHAR, '\n');

		}
	}
	if (head) {	
		releaseMemory(head);
	}
	return 0;
}

void releaseMemory(Node* head) {
	if (head -> getNext()) {
		releaseMemory(head -> getNext());
	}
	else {
		delete head;
	}
}
		

void addNode(Node* prev, Node* curr, int id, Node* newNode) { // The rest of the cases that do not involve the head.
	if(prev && !curr) {
		prev -> setNext(newNode);
		return;
	}
	if(prev && (id < curr -> getStudent() -> getId())) {
		prev -> setNext(newNode);
		newNode -> setNext(curr);
		return;
	}	
	else {
		addNode(curr, curr->getNext(), id, newNode);
	}	

}

void deleteNode(Node* prev, Node* curr, int id) { 
	if (prev && !curr) { // Must be first case so error is not thrown when getting the student of a null pointer.
		cout << "The node does not exist on the list." << endl;
		return;
	}
	if (prev && (id == curr -> getStudent() -> getId())) {
		prev -> setNext(curr -> getNext());
		delete curr;
	}
	else {
		deleteNode(curr, curr->getNext(), id);
	}
}
	

void print(Node* head) {
	if (head) {
		head -> getStudent() -> print(); // Print function defined in student class.
		print(head -> getNext());
	}
}

void average(Node* head, float &sum, int &num) {
	if (!head) {
		cout << "No nodes are in the list." << endl;
	}
	else {
		sum += head -> getStudent() -> getGpa();
		num++;
		if (head -> getNext()) {
			average(head->getNext(), sum, num);
		}
	}
} 

Student* readInStudent() {
	char firstName[MAX_CHAR];
	char lastName[MAX_CHAR];
	int id;
	float gpa;

	cout << "Please enter in the first name of the student: ";
	cin.get(firstName, MAX_CHAR);
	cin.ignore(MAX_CHAR, '\n');
	cout << "\nPlease enter in the last name of the student: ";
	cin.get(lastName, MAX_CHAR);
	cin.ignore(MAX_CHAR, '\n');
	cout << "\nPlease enter in the student ID of the student: ";
	cin >> id;
	cin.ignore(MAX_CHAR, '\n');
	cout << "\nPlease enter in the GPA of the student: ";
	cin >> gpa;
	cin.ignore(MAX_CHAR, '\n');
	Student* student = new Student(firstName, lastName, id, gpa);
	return student;
}
