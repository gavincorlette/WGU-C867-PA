//
//  roster.cpp
//  C867 PA
//
//  Created by Gavin Corlette on 1/28/24.
//

#include <stdio.h>
#include <iostream>
#include "roster.h"
#include "student.h"
using namespace std;

void Roster::parse(string input) {
    int rhs = static_cast<int>(input.find(","));
    string studentID = input.substr(0, rhs);
    
    int lhs = rhs + 1;
    rhs = static_cast<int>(input.find(",", lhs));
    string firstName = input.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = static_cast<int>(input.find(",", lhs));
    string lastName = input.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = static_cast<int>(input.find(",", lhs));
    string email = input.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = static_cast<int>(input.find(",", lhs));
    int age = stoi(input.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = static_cast<int>(input.find(",", lhs));
    int days1 = stoi(input.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = static_cast<int>(input.find(",", lhs));
    int days2 = stoi(input.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    rhs = static_cast<int>(input.find(",", lhs));
    int days3 = stoi(input.substr(lhs, rhs - lhs));
    
    lhs = rhs + 1;
    DegreeProgram degreeProgram = SECURITY;
    if (input.at(lhs) == 'N') {
        degreeProgram = NETWORK;
    }
    else if (input.at(lhs) == 'S' && input.at(lhs + 1) == 'E') {
        degreeProgram = SECURITY;
    }
    else if (input.at(lhs) == 'S' && input.at(lhs + 1) == 'O') {
        degreeProgram = SOFTWARE;
    }
    
    add(studentID, firstName, lastName, email, age, days1, days2, days3, degreeProgram);
}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram degreeProgram) {
    
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, email, age, days1, days2, days3, degreeProgram);
}

void Roster::printAll() {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        classRosterArray[i]->Print();
    }
}

void Roster::remove(string studentID) {
    bool found = false;
    
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->GetID() == studentID) {
            found = true;
            if (i < ROSTER_SIZE - 1) {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[ROSTER_SIZE - 1];
                classRosterArray[ROSTER_SIZE - 1] = temp;
            }
            Roster::lastIndex--;
        }
    }
    
    if (found) {
        cout << studentID << " was removed." << endl;
    }
    else {
        cout << "The student with the ID: " << studentID << " was not found." << endl;
    }
}

void Roster::printAverageDaysInCourse(string studentID) {
    double average = 0.0;
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (classRosterArray[i]->GetID() == studentID) {
            average = (classRosterArray[i]->GetDays()[0] + classRosterArray[i]->GetDays()[1] + classRosterArray[i]->GetDays()[2]) / 3.0;
            cout << "Student ID: " << classRosterArray[i]->GetID() << ", average days in course is: " << average << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        string email = classRosterArray[i]->GetEmail();
        if (email.find("@") == string::npos || email.find(".") == string::npos || email.find(" ") != string::npos) {
            cout << classRosterArray[i]->GetEmail() << " - is invalid." << endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i <= Roster::lastIndex; i++) {
        if (Roster::classRosterArray[i]->GetProgram() == degreeProgram) {
            classRosterArray[i]->Print();
        }
    }
}

Roster::~Roster() {
    for (int i = 0; i < ROSTER_SIZE; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
