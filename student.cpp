#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"

using namespace std;

// Constructors
Student::Student(
    string studentID,
    string firstName,
    string lastName,
    string emailAddress,
    int age,
    int daysInCourse[3],
    DegreeProgram degreeProgram
) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i]; // array passed by reference
    }
    this->degreeProgram = degreeProgram;
}

// Accessors
string Student::GetStudentID() const { return studentID; }
string Student::GetFirstName() const { return firstName; }
string Student::GetLastName() const { return lastName; }
string Student::GetEmailAddress() const { return emailAddress; }
int Student::GetAge() const { return age; }
int Student::GetDaysInCourse(int index) const { return daysInCourse[index]; }
DegreeProgram Student::GetDegreeProgram() const { return degreeProgram; }

// Mutators
void Student::SetStudentID(string studentID) {
    this->studentID = studentID;
}
void Student::SetFirstName(string firstName) {
    this->firstName = firstName;
}
void Student::SetLastName(string lastName) {
    this->lastName = lastName;
}
void Student::SetEmailAddress(string emailAddress) {
    this->emailAddress = emailAddress;
}
void Student::SetAge(int age) {
    this->age = age;
}
void Student::SetDaysInCourse(int index, int days) {
    this->daysInCourse[index] = days;
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

// Other
void Student::Print() const {
    cout << studentID << "\t";
    cout << firstName << "\t";
    cout << lastName << "\t";
    cout << "Age: " << age << "\t";
    cout << "daysInCourse: {" << daysInCourse[0] << ",";
    cout << daysInCourse[1] << ",";
    cout << daysInCourse[2] << "}\t";
    cout << "Degree Program: ";
    switch (degreeProgram) {
        case SECURITY: cout << "SECURITY" << endl; break;
        case NETWORK: cout << "NETWORK" << endl; break;
        case SOFTWARE: cout << "SOFTWARE" << endl; break;
    }
    // FOR TESTING ONLY
    //cout << "A call to the print() function has been made." << endl;
}