#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "student.h"

using namespace std;

class roster
{
public:
	// Variables.
	student** students;
	int numStudents;

	// Constructors.
	roster();
	roster(int numStudents);

	// Deconstructor.
	~roster();

	// Functions.
	void convertData(string aStudentData, int currentStudent);
	DegreeProgram convertStringToEnum(string aDegreeString);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram, int currentStudent);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails(int numStudents);
	void printByDegreeProgram(DegreeProgram aDegreeProgram);
	void printAsciiDesign();
};
