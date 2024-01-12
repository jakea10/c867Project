#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"


int main() {
    const int NUM_STUDENTS = 5;
    const string studentData[] = {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jacob,Atencio,jatenc2@wgu.edu,30,10,1,6,SOFTWARE"
    };

    Roster classRoster = Roster();
    for (int i = 0; i < NUM_STUDENTS; i++) {
        classRoster.parse(studentData[i]);
    }
    classRoster.printAll();
    cout << endl;
    classRoster.printAverageDaysInCourse("A2");

    
    // classRoster.printAll();
    // cout << endl;
    // classRoster.remove("A1");
    // classRoster.remove("A4");
    // classRoster.printAll();
    // cout << endl;
    // classRoster.remove("B1");
    // cout << endl;
    // classRoster.add("A4", "Erin", "Black", "Erin.black@comcast.net", 22, daysInCourse, SECURITY);
    // classRoster.add("A1", "John", "Smith", "John1989@gm ail.com", 20, daysInCourse, SECURITY);
    // classRoster.printAll();
}
