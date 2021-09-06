// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: http://www.viva64.com

#include "student.h"

// Constructor
student::student(string aStudentID, string aFirstName, string aLastName, string aEmailAddress, int aAge, int aDaysToComplete1, int aDaysToComplete2, int aDaysToComplete3, string aDegreeProgram) {
	// Calls each of the setter functions which sets the variables to the arguments passed in.
	setStudentID(aStudentID);
	setFirstName(aFirstName);
	setLastName(aLastName);
	setEmailAddress(aEmailAddress);
	setAge(aAge);
	setDaysToComplete(aDaysToComplete1, aDaysToComplete2, aDaysToComplete3);
	setDegreeProgram(aDegreeProgram);
}

// Setters for each of the varaibles. Assigns variable to argument when called.
void student::setStudentID(string aStudentID) {
	this->studentID = aStudentID;
}
void student::setFirstName(string aFirstName) {
	this->firstName = aFirstName;
}
void student::setLastName(string aLastName) {
	this->lastName = aLastName;
}
void student::setEmailAddress(string aEmailAddress) {
	this->emailAddress = aEmailAddress;
}
void student::setAge(int aAge) {
	this->age = aAge;
}
void student::setDaysToComplete(int aDaysToComplete1, int aDaysToComplete2, int aDaysToComplete3) {
	//this->daysToComplete[0] = aDaysToComplete1;
	//this->daysToComplete[1] = aDaysToComplete1;
	//this->daysToComplete[2] = aDaysToComplete1;
}
void student::setDegreeProgram(string aDegreeProgram) {
	this->degreeProgram = aDegreeProgram;
}

string student::getStudentID() const {
	return this->studentID;
}
string student::getFirstName() const {
	return this->firstName;
}
string student::getLastName() const {
	return this->lastName;
}
string student::getEmailAddress() const {
	return this->emailAddress;
}
int student::getAge() const {
	return this->age;
}
int student::getDaysToComplete() const {
	//return this->daysToComplete[2];
	return 0;
}
string student::getDegreeProgram() const {
	return this->degreeProgram;
}