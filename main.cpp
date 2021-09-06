// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include <iostream>
#include "roster.h"
#include "student.h"

using namespace std;

int main()
{
	cout << "C867 Scripting and Programming Applications" << endl;
	cout << "Programming Lanauge: C++" << endl;
	cout << "Student ID: 003663341" << endl;
	cout << "Nathan White\n\n" << endl;

	roster classRoster;

	classRoster.printAll();

	// PRINT ALL CLASS ROSTER
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