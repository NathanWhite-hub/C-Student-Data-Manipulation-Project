#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "student.h"

using namespace std;

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

class roster
{
public:
	student** students;
	int numStudents;

	// Constructors
	roster();
	roster(int numStudents);

	// Deconstructor
	//~roster();

	void convertData(string aStudentData, int currentStudent);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, string degreeProgram, int currentStudent);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(string aDegreeProgram);
	void createArray(string studentData);
};
