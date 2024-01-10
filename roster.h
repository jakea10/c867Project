#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"

using namespace std;

class Roster {
    private:
        Student* classRosterArray[5];
    public:
        // add will be called by parse method
        void add(string studentID, string firstName, string lastName,
                 string emailAddress, int age,
                 int daysInCourse1, int daysInCourse2, int daysInCourse3,
                 DegreeProgram degreeProgram);
};

#endif