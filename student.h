#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

using namespace std;

class Student {
    private:
        string studentID;
        string firstName;
        string lastName;
        string emailAddress;
        int age;
        int daysInCourse[3];
        DegreeProgram degreeProgram;
    public:
        Student(
            string studentID,
            string firstName,
            string lastName,
            string emailAddress,
            int age,
            int daysInCourse[3],
            DegreeProgram degreeProgram
        );
        // Accessors
        string GetStudentID() const;
        string GetFirstName() const;
        string GetLastName() const;
        string GetEmailAddress() const;
        int GetAge() const;
        int GetDaysInCourse(int index) const;
        DegreeProgram GetDegreeProgram() const;
        // Mutators
        void SetStudentID(string studentID);
        void SetFirstName(string firstName);
        void SetLastName(string lastName);
        void SetEmailAddress(string emailAddress);
        void SetAge(int age);
        void SetDaysInCourse(int index, int days);
        void SetDegreeProgram(DegreeProgram degreeProgram);
        // Other
        void Print() const;
};

#endif /* student_h */