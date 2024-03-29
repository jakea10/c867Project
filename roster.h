#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include "student.h"

using namespace std;

class Roster {
    private:
        // Requirements call for a fixed size array of five pointers to Student objects
        static const int numStudents = 5;
        
    public:
        Student* classRosterArray[numStudents];
        Roster();
        ~Roster();
        // add will be called by parse method
        void add(string studentID, string firstName, string lastName, string emailAddress, int age,
                 int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
        void parse(string studentData);
        void remove(string studentID);
        void printAll() const;
        void printAverageDaysInCourse(string studentID) const;
        void printInvalidEmails() const;
        void printByDegreeProgram(DegreeProgram degreeProgram) const;
};

#endif