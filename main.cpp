#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"


int main() {
    // F.1
    cout << "C867-Scripting & Programming: Applications" << endl;
    cout << "Language: C++" << endl;
    cout << "Student ID: 001304752" << endl;
    cout << "Name: Jacob Atencio" << endl << endl;

    // F.2
    Roster classRoster = Roster();

    // F.3
    const int NUM_STUDENTS = 5;
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jacob,Atencio,jatenc2@wgu.edu,30,10,1,6,SOFTWARE"
    };

    for (int i = 0; i < NUM_STUDENTS; i++) {
        classRoster.parse(studentData[i]);
    }

    // F.4
    classRoster.printAll();
    cout << endl;

    classRoster.printInvalidEmails();
    cout << endl;

    for (auto& student : classRoster.classRosterArray) {
        classRoster.printAverageDaysInCourse(student->GetStudentID());
    }
    cout << endl;

    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;

    classRoster.remove("A3");
    classRoster.printAll();
    cout << endl;
    classRoster.remove("A3");
}
