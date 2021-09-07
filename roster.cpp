#include "roster.h"

roster::roster() {
	/*
		The default Constructor.
	*/
	this->numStudents = 0;
	this->students = nullptr;
}

roster::roster(int numStudents) {
	/*
		The real constructor that sets variables and creates the student object.
	*/
	this->numStudents = numStudents;
	students = new student * [numStudents];
}

roster::~roster() {
	/*
		The destructor which prints that the roster was destroyed to console before looping through each student doing each time:
			A.) Deleteing the current student from memory.
	*/
	cout << "Roster destroyed!" << endl;
	for (int i = 0; i < numStudents; i++) {
		delete this->students[i];
	}
}

void roster::convertData(string aStudentData, int currentStudent) {
	// Create a vector of strings called studentLines to store the seperated text.
	vector<string> studentLines;
	// Declare variables for string stream.
	istringstream ss(aStudentData);
	string word = "";

	// Run a while loop which seperates the words in the string by , and ignores the space that appears after the "student ID" (i.e. " John", " Doe". vs "John", "Doe").
	while (getline(ss, word, ',')) {
		ss.ignore(1);
		// Add the grabbed word onto the studentLines vector.
		studentLines.push_back(word);
	}

	/*
		Now that the while has finished and all words are stored, the add function is called to add the data into student object.
		Each parameter is passed into the add function, calling it by the location in the vector.
		For the degree program (always located at location 8), a conversion is neccisary
		(due to it being a string value and an enumerated value is required), so the function convertStringToEnum is called on it.
		A conversion from string to int is also called on locations 4, 5, 6, and 7, which are required to be integer variables (age, daysInCourse1, daysInCourse2, etc).
		The current student variable (the int i from the loop in main.cpp) is also passed in to keep track of the current student it is adding.
	*/
	add(studentLines.at(0), studentLines.at(1), studentLines.at(2), studentLines.at(3),
		stoi(studentLines.at(4)), stoi(studentLines.at(5)), stoi(studentLines.at(6)), stoi(studentLines.at(7)),
		convertStringToEnum(studentLines.at(8)), currentStudent);
}

DegreeProgram roster::convertStringToEnum(string aDegreeString) {
	// A series of if statements are ran to check what the string is. It then returns the correct enumerated value.
	if (aDegreeString == "SOFTWARE") {
		return SOFTWARE;
	}
	else if (aDegreeString == "NETWORK") {
		return NETWORK;
	}
	else if (aDegreeString == "SECURITY") {
		return SECURITY;
	}
}

void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram, int currentStudent) {
	/*
		The int array daysInCourse is created and each of the arguments (daysInCourse1, daysInCourse2, etc)
		are assigned to the first, second, and third elements of days in course. A new student is then created with it being assigned to the roster in the currentStudent element.
	*/
	int daysInCourse[3];
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;

	this->students[currentStudent] = new student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

void roster::remove(string studentID) {
	/*
		A for loop is run until:
			A.) It calls the current student (students[i]) and calls the getStudentID() function which returns the studentID.
				If the return string from getStudentID() matches the argument studentID, then:
					It outputs a message stating the student was removed, deletes the student from memory, decreases the number of students,
					and assigns the student in the last element to the location where the deleted student was. It then breaks from the for loop.

			B.) It has run through all of the students and has not found that student ID, at which point it outputs an error message (see else if statement).
	*/
	for (int i = 0; i < numStudents; i++) {
		if (students[i]->getStudentID() == studentID) {
			cout << "Removed student " << students[i]->getFirstName() << " " << students[i]->getLastName() << endl;
			delete this->students[i];
			numStudents--;
			this->students[i] = this->students[numStudents];
			break;
		}
		else if (i == numStudents - 1) {
			cout << "No student with studentID " << studentID << " found. Please try again.\n";
		}
	}
}

void roster::printAll() {
	/*
		A header is output to console and then a for loop is run through all of students doing each time:
			1.) Calling the print function on the current student (students[i]).
			2.) Outputing a spacer to console.
	*/
	for (int i = 0; i < numStudents; i++) {
		this->students[i]->print();
	}
}

void roster::printAverageDaysInCourse(string studentID) {
	/*
		A for loop is run through all of the students until either:
			A.) getStudentID() is called on the current student (students[i]), which returns the studentID and if the studentID argument matches the return value:
				1.) The integer pointer array daysInCourse is assigned to the return value of the getDaysToComplete() call on the current student.
				2.) The double averageDays variable is assigned to the sum of the first, second, and third elements of the int point array divided by 3.0 (which is the average).
				3.) The average number of days along with the student's name and studentID are output to console.
				4.) It them breaks from the for loop.

			B.) It has looped through all of the students and no studentID matches the argument StudentID. It then outputs an error message to console (see else if statement).
	*/
	for (int i = 0; i < numStudents; i++) {
		if (students[i]->getStudentID() == studentID) {
			int* daysInCourse = this->students[i]->getDaysToComplete();
			double averageDays = (daysInCourse[0] + daysInCourse[1] + daysInCourse[2]) / 3.0;
			cout << "Average Number of days for course completion for student " << this->students[i]->getFirstName() << " "
				<< this->students[i]->getLastName() << " (studentID " << studentID << ")" << ": " << averageDays << endl;
			break;
		}
		else if (i == numStudents - 1) {
			cout << "No student with studentID " << studentID << " found. Please try again.\n";
		}
	}
}

void roster::printInvalidEmails(int numStudents) {
	/*
		The boolean variable isFound is set to false.
		Since this function doesn't stop entirely when one student is found, this boolean keeps track of if at least one student was found (for the error message).
		The for loop loops through each student, doing each time:
			A.) Assign the variable studentEmail to the return value of the getEmailAddress() function.
			studentEmail.find() is called, with the parameters being @, ., and a space. If a @ is not found in the string, or a . or a space is found, then:
				1.) Print the student information to console.
				2.) Set isFound to true.

			B.) If the for loop has reached the end and isFound is equal to false:
				1.) Output error message to console (see else if statement).
	*/
	cout << "\nStudents with invalid email addresses:" << endl;
	bool isFound = false;

	for (int i = 0; i < numStudents; i++) {
		string studentEmail = this->students[i]->getEmailAddress();
		if (studentEmail.find('@') == string::npos or studentEmail.find('.') == string::npos or studentEmail.find(' ') != string::npos) {
			this->students[i]->print();
			isFound = true;
		}
		else if (i == numStudents - 1 and isFound == false) {
			cout << "No invalid email addresses found.\n" << endl;
		}
	}
}

void roster::printByDegreeProgram(DegreeProgram aDegreeProgram) {
	/*
		1.) Use a switch statement to assign the correct string text for the enum aDegreeProgram value.
		2.) Iterates through the for loop for the number of students in the program doing for each student:
			1.) Check if calling the getDegreeProgram function equals the argumentDegreeProgram
			2.) If it does, then calling the print function on that object.
	*/
	string strDegreeProgram;
	switch (aDegreeProgram)
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

	cout << "Students in the " << strDegreeProgram << " degree program: " << endl;
	for (int i = 0; i < numStudents; i++) {
		if (this->students[i]->getDegreeProgram() == aDegreeProgram) {
			this->students[i]->print();
		}
	}
}

void roster::printAsciiDesign() {
	// My neat Ascii art.
	cout << "                                                                                   " << endl;
	cout << "WWWWWWWW                           WWWWWWWW      GGGGGGGGGGGGGUUUUUUUU     UUUUUUUU" << endl;
	cout << "W::::::W                           W::::::W   GGG::::::::::::GU::::::U     U::::::U" << endl;
	cout << "W::::::W                           W::::::W GG:::::::::::::::GU::::::U     U::::::U" << endl;
	cout << "W::::::W                           W::::::WG:::::GGGGGGGG::::GUU:::::U     U:::::UU" << endl;
	cout << " W:::::W           WWWWW           W:::::WG:::::G       GGGGGG U:::::U     U:::::U " << endl;
	cout << "  W:::::W         W:::::W         W:::::WG:::::G               U:::::D     D:::::U " << endl;
	cout << "   W:::::W       W:::::::W       W:::::W G:::::G               U:::::D     D:::::U " << endl;
	cout << "    W:::::W     W:::::::::W     W:::::W  G:::::G    GGGGGGGGGG U:::::D     D:::::U " << endl;
	cout << "     W:::::W   W:::::W:::::W   W:::::W   G:::::G    G::::::::G U:::::D     D:::::U " << endl;
	cout << "      W:::::W W:::::W W:::::W W:::::W    G:::::G    GGGGG::::G U:::::D     D:::::U " << endl;
	cout << "       W:::::W:::::W   W:::::W:::::W     G:::::G        G::::G U:::::D     D:::::U " << endl;
	cout << "        W:::::::::W     W:::::::::W       G:::::G       G::::G U::::::U   U::::::U " << endl;
	cout << "         W:::::::W       W:::::::W         G:::::GGGGGGGG::::G U:::::::UUU:::::::U " << endl;
	cout << "          W:::::W         W:::::W           GG:::::::::::::::G  UU:::::::::::::UU  " << endl;
	cout << "           W:::W           W:::W              GGG::::::GGG:::G    UU:::::::::UU    " << endl;
	cout << "            WWW             WWW                  GGGGGG   GGGG      UUUUUUUUU      " << endl;
	cout << "                                                                                   " << endl;
	cout << "                                                                                   " << endl;
}