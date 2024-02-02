//
//  roster.h
//  C867 PA
//
//  Created by Gavin Corlette on 1/28/24.
//

#ifndef roster_h
#define roster_h

#include <iostream>
#include "student.h"
using namespace std;

class Roster {
private:
    int lastIndex = -1;
    const static int ROSTER_SIZE = 5;
public:
    Student* classRosterArray[ROSTER_SIZE];
    void parse(string input);
    void add(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram degreeProgram);
    void printAll();
    void remove(string studentID);
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
};

#endif /* roster_h */
