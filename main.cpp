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

	// PRINT ALL INVALID EMAILS CLASS ROSTER
	/* LOOP THROUGH CLASSROSTERARRAY AND FOR EACH ELEMENT DO:
		classRoster.printAverageDaysInCourse(current object's student id) USE A GETTER TO ACCESS THE STUDENT ID
	*/
	// PRINT BY DEGREE PROGRAM (SOFTWARE) CLASS ROSTER
	//REMOVE A3 CLASS ROSTER
	// PRINT ALL CLASS ROSTER
	// REMOVE A3 CLASS ROSTER EXPECTED: SHOULD PRINT MESSAGE SAYING NO SUCH STUDENT WAS FOUND
	// USE DESTRUCTOR TO RELEASE MEMORY THAT WAS ALLOCATED DYNAMICALLY IN ROSTER
}