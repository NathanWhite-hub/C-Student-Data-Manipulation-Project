// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "roster.h"

const string studentData[] = { "A1, John, Smith, John1989@gm ali.com, 20, 30, 35, 40, SECURITY",
	"A2, Suzan, Erickson, Erickson_1990@gmailcom, 19, 50, 30, 40, NETWORK",
	"A3, Jack, Napoli, The_lawyer99@yahoo.com, 19, 20, 40, 33, SOFTWARE",
	"A4, Erin, Black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
	"A5, John, Doe, jdoe@wgu.edu, 24, 20, 33, 40, SOFTWARE"
};

roster::roster() {
	for (int i = 0; i <= 5; i++) {
		// classRosterArray[i] = &studentData[i];
	}
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeProgram) {
}

void roster::printAll() {
	for (int i = 0; i <= 5; i++) {
		cout << classRosterArray[i] << endl;
	}
}