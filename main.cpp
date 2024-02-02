//
//  main.cpp
//  C867 PA
//
//  Created by Gavin Corlette on 1/28/24.
//

#include <iostream>
#include "student.h"
#include "roster.h"
using namespace std;

int main() {
    
    cout << "Course: Scripting and Programming - Applications - C867" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "WGU Student ID: 009934028" << endl;
    cout << "Name: Gavin Corlette" << endl;
    cout << endl;
    
    const string studentData[] =

    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Gavin,Corlette,gcorlet@wgu.edu,25,24,22,15,SOFTWARE"};
    
    const int ROSTER_SIZE = 5;
    Roster classRoster;
    
    for (int i = 0; i < ROSTER_SIZE; i++) classRoster.parse(studentData[i]);
    
    classRoster.printAll();
    cout << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    for (int i = 0; i < ROSTER_SIZE; i++) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetID());
    }
    cout << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    cout << endl;
    classRoster.remove("A3");
    cout << endl;
    classRoster.printAll();
    cout << endl;
    classRoster.remove("A3");
    cout << endl;
    classRoster.~Roster();
}
