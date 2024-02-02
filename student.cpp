//
//  student.cpp
//  C867 PA
//
//  Created by Gavin Corlette on 1/28/24.
//

#include <iostream>
#include "student.h"
#include "degree.h"
using namespace std;

Student::Student() {
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->email = "";
    this->age = 0;
    for (int i = 0; i < SIZE; i++) this->daysToComplete[i] = 0;
    this->degreeProgram = DegreeProgram::SECURITY;
}

Student::~Student() {
    
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int days1, int days2, int days3, DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;
    this->age = age;
    this->daysToComplete[0] = days1;
    this->daysToComplete[1] = days2;
    this->daysToComplete[2] = days3;
    this->degreeProgram = degreeProgram;
}

void Student::SetID(string studentID) {
    this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
    this->lastName = lastName;
}

void Student::SetEmail(string email) {
    this->email = email;
}

void Student::SetAge(int age) {
    this->age = age;
}

void Student::SetDays(int days1, int days2, int days3) {
    this->daysToComplete[0] = days1;
    this->daysToComplete[1] = days2;
    this->daysToComplete[2] = days3;
}

void Student::SetProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

string Student::GetID() {
    return this->studentID;
}

string Student::GetFirstName() {
    return this->firstName;
}

string Student::GetLastName() {
    return this->lastName;
}

string Student::GetEmail() {
    return this->email;
}

int Student::GetAge() {
    return this->age;
}

int* Student::GetDays() {
    return this->daysToComplete;
}

DegreeProgram Student::GetProgram() {
    return this->degreeProgram;
}

void Student::Print() {
    cout << GetID() << "    " << "First Name: " << GetFirstName() << "    " << "Last Name: " << GetLastName() << "    " << "Email: " << GetEmail() << "    " << "Age: " << GetAge() << "    " << "Days In Course: {" << GetDays()[0] << ", " << GetDays()[1] << ", " << GetDays()[2] << "}   Degree Program: " << degreeStrings[GetProgram()] << endl;
}
