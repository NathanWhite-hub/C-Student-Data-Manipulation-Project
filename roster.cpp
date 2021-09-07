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
		convertStringToEnum(studentLines.at(8)), currentStudent);
}

DegreeProgram roster::convertStringToEnum(string aDegreeString) {
	if (aDegreeString == "SOFTWARE") {
		return SOFTWARE;
	}
	else if (aDegreeString == "NETWORK") {
		return NETWORK;
	}
	else if (aDegreeString == "SECURITY") {
		return SECURITY;
	}
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram, int currentStudent) {
	int daysInCourse[3];
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;

	this->students[currentStudent] = new student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

void roster::remove(string studentID) {
	for (int i = 0; i < numStudents; i++) {
		if (students[i]->getStudentID() == studentID) {
			cout << "Removed student " << students[i]->getFirstName() << " " << students[i]->getLastName() << endl;
			delete this->students[i];
			numStudents--;
			this->students[i] = this->students[numStudents];
			break;
		}
		else if (i == numStudents - 1) {
			cout << "No student with studentID " << studentID << " found. Please try again.\n";
		}
	}
}

void roster::printAll() {
	cout << "Student ID " << "First Name " << "Last Name " << "Age " << "Days In Course " << "Degree Program" << endl;
	for (int i = 0; i < numStudents; i++) {
		this->students[i]->print();
		cout << "___________________________________________________________" << endl;
	}
}

void roster::printAverageDaysInCourse(string studentID, int numStudents) {
	for (int i = 0; i < numStudents; i++) {
		if (students[i]->getStudentID() == studentID) {
			int* daysInCourse = this->students[i]->getDaysToComplete();
			double averageDays = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3.0;
			cout << "Average Number of days for course completion for student " << this->students[i]->getFirstName() << " "
				<< this->students[i]->getLastName() << "(studentID " << studentID << ")" << ": " << averageDays << endl;
			break;
		}
		else if (i == numStudents) {
			cout << "No student with studentID " << studentID << " found. Please try again.\n";
		}
	}
}

void roster::printInvalidEmails(int numStudents) {
	cout << "\nStudents with invalid email addresses:" << endl;
	bool isFound = false;

	for (int i = 0; i < numStudents; i++) {
		string studentEmail = this->students[i]->getEmailAddress();
		if (studentEmail.find('@') == string::npos or studentEmail.find('.') == string::npos or studentEmail.find(' ') != string::npos) {
			this->students[i]->print();
			isFound = true;
		}
		else if (i == numStudents and isFound == false) {
			cout << "No invalid email addresses found.\n" << endl;
		}
	}
}

void roster::printByDegreeProgram(DegreeProgram aDegreeProgram) {
	for (int i = 0; i < numStudents; i++) {
		if (this->students[i]->getDegreeProgram() == aDegreeProgram) {
			this->students[i]->print();
		}
	}
}