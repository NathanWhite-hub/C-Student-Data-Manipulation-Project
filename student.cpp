#include "student.h"

// Constructor
student::student(string aStudentID, string aFirstName, string aLastName, string aEmailAddress, int aAge, int aDaysToComplete[], DegreeProgram aDegreeProgram) {
	// Calls each of the setter functions which sets the variables to the arguments passed in.
	setStudentID(aStudentID);
	setFirstName(aFirstName);
	setLastName(aLastName);
	setEmailAddress(aEmailAddress);
	setAge(aAge);
	setDaysToComplete(aDaysToComplete);
	setDegreeProgram(aDegreeProgram);
}

// Setters for each of the variables. Assigns variable to argument when called.
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
void student::setDaysToComplete(int aDaysToComplete[]) {
	for (int i = 0; i < 3; i++)
	{
		this->daysToComplete[i] = aDaysToComplete[i];
	}
}
void student::setDegreeProgram(DegreeProgram aDegreeProgram) {
	this->degreeProgram = aDegreeProgram;
}

// Getters for each of the variables. Returns the current object's information.
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
int* student::getDaysToComplete() {
	return daysToComplete;
}
DegreeProgram student::getDegreeProgram() const {
	return degreeProgram;
}

void student::print() {
	/*
		The string strDegreeProgram is initialized.
		A switch statement with the degreeProgram parameter is set and cases for each of the enum types are set.
		If a case is triggered, then the strDegreeProgram variable is set to the correct string text of the enum value.
		The strDegreeProgram is then the variable printed to console.
	*/
	string strDegreeProgram;
	switch (degreeProgram)
	{
	case SECURITY:
		strDegreeProgram = "SECURITY";
		break;
	case NETWORK:
		strDegreeProgram = "NETWORK";
		break;
	case SOFTWARE:
		strDegreeProgram = "SOFTWARE";
		break;
	default:
		break;
	}
	cout << studentID << "\tFirst Name: " << firstName << "\tLast Name: " << lastName << "\tEmail Address: " << emailAddress
		<< "\tAge: " << age << "\tdaysInCourse: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "} \tDegree Program: " << strDegreeProgram << endl;
	cout << endl;
}