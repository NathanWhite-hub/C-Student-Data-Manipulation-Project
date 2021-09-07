#pragma once
#include <string>
#include <memory>
#include <array>
#include <iostream>

#include "degree.h"

using namespace std;

class student
{
private:
	// Variables.
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	DegreeProgram degreeProgram;
	int age;
	int daysToComplete[3];

public:

	// Declaring getters for each of the variables.
	std::string getStudentID() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getEmailAddress() const;
	int getAge() const;
	int* getDaysToComplete();
	DegreeProgram getDegreeProgram() const;

	// Declaring setters for each of the varaibles.
	void setStudentID(std::string aStudentID);
	void setFirstName(std::string aFirstName);
	void setLastName(std::string aLastName);
	void setEmailAddress(std::string aEmailAddress);
	void setAge(int aAge);
	void setDaysToComplete(int aDaysToComplete[]);
	void setDegreeProgram(DegreeProgram aDegreeProgram);

	// Declaring print function
	void print();

	// Declaring constructor.
	student(std::string aStudentID, std::string aFirstName, std::string aLastName, std::string aEmailAddress, int aAge, int aDaysToComplete[], DegreeProgram aDegreeProgram);
};
