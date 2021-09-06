#pragma once
#include <string>
#include <memory>
#include <array>
#include <iostream>

using namespace std;

// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

class student
{
private:
	std::string studentID;
	std::string firstName;
	std::string lastName;
	std::string emailAddress;
	std::string degreeProgram;
	int age;
	int daysToComplete[];

public:

	// Declaring getters for each of the variables.
	std::string getStudentID() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getEmailAddress() const;
	int getAge() const;
	int getDaysToComplete() const;
	std::string getDegreeProgram() const;

	// Declaring setters for each of the varaibles.
	void setStudentID(std::string aStudentID);
	void setFirstName(std::string aFirstName);
	void setLastName(std::string aLastName);
	void setEmailAddress(std::string aEmailAddress);
	void setAge(int aAge);
	void setDaysToComplete(int aDaysToComplete1, int aDaysToComplete2, int aDaysToComplete3);
	void setDegreeProgram(std::string aDegreeProgram);

	// Declaring print function
	void print();

	// Declaring constructor.
	student(std::string aStudentID, std::string aFirstName, std::string aLastName, std::string aEmailAddress, int aAge, int aDaysToComplete1, int aDaysToComplete2, int aDaysToComplete3, std::string aDegreeProgram);
};
