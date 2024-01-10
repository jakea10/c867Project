#include <iostream>
#include <string>
#include "roster.h"

using namespace std;

// Cosntructor
Roster::Roster() {
    // Initialize each element of the roster as a null pointer.
    // This will help determine next available index when populating the roster.
    for (int i = 0; i < 5; i++) {
        this->classRosterArray[i] = nullptr;
    }
}

// Mutators
void Roster::add(string studentID, string firstName, string lastName,
                 string emailAddress, int age,
                 int daysInCourse1, int daysInCourse2, int daysInCourse3,
                 DegreeProgram degreeProgram)
{
    //TODO: Create a new Student object and add to classRosterArray
}