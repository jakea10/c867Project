#include <iostream>
#include <string>
#include <vector>
#include "student.h"

int main() {
    // const string studentData[] = {
    //     "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    //     "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    //     "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    //     "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    //     "A5,Jacob,Atencio,jatenc2@wgu.edu,30,10,1,6,SOFTWARE"
    // };

    int daysInCourse[] = {10, 1, 6};
    Student jake = Student("A5", "Jacob", "Atencio", "jatenc2@wgu.edu", 30, daysInCourse, SOFTWARE);
    jake.Print();
    cout << jake.GetDaysInCourse(2) << endl;
    jake.SetDaysInCourse(1, 9);
    jake.Print();
}