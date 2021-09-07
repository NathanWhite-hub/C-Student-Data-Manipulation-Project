// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "roster.h"
#include "student.h"

using namespace std;

int main()
{
	const string studentData[] = { "A1, John, Smith, John1989@gm ali.com, 20, 30, 35, 40, SECURITY",
	"A2, Suzan, Erickson, Erickson_1990@gmailcom, 19, 50, 30, 40, NETWORK",
	"A3, Jack, Napoli, The_lawyer99@yahoo.com, 19, 20, 40, 33, SOFTWARE",
	"A4, Erin, Black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
	"A5, John, Doe, jdoe@wgu.edu, 24, 20, 33, 40, SOFTWARE"
	};

	cout << "C867 Scripting and Programming Applications" << endl;
	cout << "Programming Lanauge: C++" << endl;
	cout << "Student ID: 003663341" << endl;
	cout << "Nathan White\n\n" << endl;

	int classSize = size(studentData);

	roster* classRoster = new roster(classSize);

	for (int i = 0; i < classSize; i++) {
		classRoster->convertData(studentData[i], i);
	}

	classRoster->printAll();

	classRoster->printInvalidEmails(classRoster->numStudents);

	cout << "\n\n";

	for (int i = 0; i < classRoster->numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->students[i]->getStudentID(), classSize);
	}

	cout << "\n\n";

	classRoster->printByDegreeProgram(SOFTWARE);

	cout << "\n\n";

	classRoster->remove("A3");
	//REMOVE A3 CLASS ROSTER
	cout << "\n\n";

	classRoster->printAll();
	// PRINT ALL CLASS ROSTER
	cout << "\n\n";

	classRoster->remove("A3");
	// REMOVE A3 CLASS ROSTER EXPECTED: SHOULD PRINT MESSAGE SAYING NO SUCH STUDENT WAS FOUND
	cout << "\n\n";

	// USE DESTRUCTOR TO RELEASE MEMORY THAT WAS ALLOCATED DYNAMICALLY IN ROSTER
}