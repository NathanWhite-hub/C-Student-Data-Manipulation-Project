#include "roster.h"
#include "student.h"

using namespace std;

int main()
{
	const string studentData[] = { "A1, John, Smith, John1989@gm ali.com, 20, 30, 35, 40, SECURITY",
	"A2, Suzan, Erickson, Erickson_1990@gmailcom, 19, 50, 30, 40, NETWORK",
	"A3, Jack, Napoli, The_lawyer99@yahoo.com, 19, 20, 40, 33, SOFTWARE",
	"A4, Erin, Black, Erin.black@comcast.net, 22, 50, 58, 40, SECURITY",
	"A5, Enter, Tayne, tayne@cinco.com, 24, 20, 33, 40, SOFTWARE"
	};

	// Set classSize variable to the size of the studentData array.
	int classSize = size(studentData);

	// Create classRoster pointer of the new roster object with the argument classSize, which contains the size of the studentData array.
	roster* classRoster = new roster(classSize);

	// Print my neat ascii art of the WGU logo.
	cout << "\n\n";
	classRoster->printAsciiDesign();

	/* Iterate over a for loop for the classSizeand do the following each loop:
		1.) call convertData, passing in both the studentData with the current element (student) and the int i itself, which is refered to in convert data as currentStudent.
	*/
	for (int i = 0; i < classSize; i++) {
		classRoster->convertData(studentData[i], i);
	}

	// The printAll() function is called on classRoster (see printAll() in roster.cpp).
	classRoster->printAll();

	cout << "\n\n";

	// The printInvalidEmails() function is called with the parameter numStudents (the current number of students in the course.)
	classRoster->printInvalidEmails(classRoster->numStudents);

	cout << "\n\n";

	/* For each of the students in classRoster, do the following :
		1.) Call the printAverageDaysInCourse() function, and call the getStudentID() function for the "current student" (student[i])
		(see printAverageDaysInCourse() in roster.cpp).
	*/
	for (int i = 0; i < classRoster->numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->students[i]->getStudentID());
	}

	cout << "\n\n";

	/*
		Call the printByDegreeProgram() function on the class roster, with the parameter of the enum value SOFTWARE.
		(see printByDegreeProgram() in roster.cpp).
	*/
	classRoster->printByDegreeProgram(SOFTWARE);

	cout << "\n\n";

	// Call the remove() function with the parameter of the student ID "A3" (see remove() in roster.cpp).
	classRoster->remove("A3");

	cout << "\n\n";

	// Call printAll() again, which shows the student with studentID "A3" has been removed.
	classRoster->printAll();

	cout << "\n\n";

	// Call the remove() function again, which will output an error message to console as the student has already been deleted.
	classRoster->remove("A3");

	cout << "\n\n";

	// Deconstruct the classRoster (see ~roster() in roster.cpp)
	delete classRoster;
}