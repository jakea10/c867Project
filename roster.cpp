#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "roster.h"

using namespace std;

// Constructor
Roster::Roster() {
    // Initialize each element of the roster as a null pointer to indicate no Students.
    for (int i = 0; i < 5; i++) {
        classRosterArray[i] = nullptr;
    }
}

// Mutators
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
                 int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    // Dynamically construct a new Student object and add its pointer to classRosterArray
    for (int i = 0; i < numStudents; i++) {
        if (classRosterArray[i] == nullptr) {
            int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
            classRosterArray[i] = new Student(
                studentID, firstName, lastName, emailAddress, age,
                daysInCourse, degreeProgram
            );
            return;
        }
    }
}

void Roster::parse(string studentData) {
    // parse a string of student data and pass to Roster::add
    // Expected string format:
    //   "[studentID],[firstname],[lastname],[emailaddress],[age],
    //    [daysInCourse1],[daysInCourse2],[daysInCourse3],[degreeProgram]"
    vector<string> parsedData;
    stringstream studentDataStream(studentData);
    while (studentDataStream.good()) {
        string substr;
        getline(studentDataStream, substr, ',');
        parsedData.push_back(substr);
    }
    string studentID     = parsedData.at(0);
    string firstName     = parsedData.at(1);
    string lastName      = parsedData.at(2);
    string emailAddress  = parsedData.at(3);
    int age              = stoi(parsedData.at(4));
    int daysInCourse1    = stoi(parsedData.at(5));
    int daysInCourse2    = stoi(parsedData.at(6));
    int daysInCourse3    = stoi(parsedData.at(7));
    string programString = parsedData.at(8);

    DegreeProgram degreeProgram;
    if (programString == "SECURITY") {
        degreeProgram = SECURITY;
    }
    else if (programString == "SOFTWARE") {
        degreeProgram = SOFTWARE;
    }
    else if (programString == "NETWORK") {
        degreeProgram = NETWORK;
    }

    this->add(studentID, firstName, lastName, emailAddress, age,
              daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::remove(string studentID) {
    // TODO: Destructor

    // Remove given student from class roster
    for (int student = 0; student < numStudents; student++) {
        if (classRosterArray[student] != nullptr &&
            classRosterArray[student]->GetStudentID() == studentID) {
            delete classRosterArray[student];     // deallocate the Student object's memory
            classRosterArray[student] = nullptr;  // clear the spot in the roster
            return;
        }
    }

    cout << "Student not found." << endl;   // no match occurred
}

// Other
void Roster::printAll() const {
    for (int student = 0; student < numStudents; student++) {
        if (classRosterArray[student] != nullptr) {     // nullptr indicates no Student
            classRosterArray[student]->Print();
        }
    }
}

void Roster::printAverageDaysInCourse(string studentID) const {
    // First, search for a matching Student
    for (int student = 0; student < numStudents; student++) {
        if (classRosterArray[student] != nullptr &&
            classRosterArray[student]->GetStudentID() == studentID) {
            // Found, now calculate average days in course
            int totalDays = 0;
            int numCourses = 3;
            for (int course = 0; course < numCourses; course++) {
                totalDays += classRosterArray[student]->GetDaysInCourse(course);
            }
            cout << "Student ID: " << studentID << ", ";
            cout << "average days in course is: ";
            cout << (double) totalDays / (double) numCourses << endl;
            return;
        }
    }
}

void Roster::printInvalidEmails() const {
    // Verify student email addresses and display invalid addresses
    // A valid email is defined as having:
    // - an '@' sign
    // - a period '.'
    // - no spaces
    string currEmail;
    for (int student = 0; student < numStudents; student++) {
        currEmail = classRosterArray[student]->GetEmailAddress();
        if (currEmail.find(' ') != string::npos ||
            currEmail.find('@') == string::npos ||
            currEmail.find('.') == string::npos) {
            cout << currEmail << " - is invalid." << endl;
            continue;
        }
    }
}
