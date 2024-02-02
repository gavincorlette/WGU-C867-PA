//
//  student.h
//  C867 PA
//
//  Created by Gavin Corlette on 1/28/24.
//

#ifndef student_h
#define student_h

#include <iostream>
#include "degree.h"
using namespace std;

class Student {
public:
    const static int SIZE = 3;
private:
    string studentID;
    string firstName;
    string lastName;
    string email;
    int age;
    int days1;
    int days2;
    int days3;
    int daysToComplete[SIZE];
    DegreeProgram degreeProgram;
public:
    Student();
    Student(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram degreeProgram);
    ~Student();
    
    void SetID(string studentID);
    void SetFirstName(string firstName);
    void SetLastName(string lastName);
    void SetEmail(string email);
    void SetAge(int age);
    void SetDays(int days1, int days2, int days3);
    void SetProgram(DegreeProgram degreeProgram);
    
    string GetID();
    string GetFirstName();
    string GetLastName();
    string GetEmail();
    int GetAge();
    int* GetDays();
    DegreeProgram GetProgram();
    
    void Print();
}; 

#endif /* student_h */
