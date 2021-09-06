// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "roster.h"

roster::roster() {
	this->numStudents = 0;
	this->students = nullptr;
}

roster::roster(int numStudents) {
	this->numStudents = numStudents;
	students = new student * [numStudents];
}

void roster::convertData(string aStudentData, int currentStudent) {
	vector<string> studentLines;
	istringstream ss(aStudentData);
	string word = "";

	while (getline(ss, word, ',')) {
		ss.ignore(1);
		studentLines.push_back(word);
	}

	add(studentLines.at(0), studentLines.at(1), studentLines.at(2), studentLines.at(3),
		stoi(studentLines.at(4)), stoi(studentLines.at(5)), stoi(studentLines.at(6)), stoi(studentLines.at(7)),
		studentLines.at(8), currentStudent);
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeProgram, int currentStudent) {
	this->students[currentStudent] = new student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void roster::printAll() {
	cout << "Student ID " << "First Name " << "Last Name " << "Age " << "Days In Course " << "Degree Program" << endl;
	for (int i = 0; i < numStudents; i++) {
		this->students[i]->print();
		cout << "\n___________________________________________________________" << endl;
	}
}