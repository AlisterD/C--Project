
#ifndef roster_hpp
#define roster_hpp

// roster.cpp
// C867_Performance_Assessment //
// Created by Alister Cedeno on 9/1/20. //

#include "student.h"
#include <iostream>
#include <string>

using namespace std;

// the roster class
class Roster
{
    // the private data members of this class
private:
    
    // array of pointers to hold data
    Student *classRosterArray[10];
    
    // the number of students
    int numStudents;
    
public:
    
    // the constructor
    Roster();
     
    // the method to add a new student to the roster
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    
    // the method to remove the student with this ID
    void remove(string studentID);
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    Student ** getAllStudents();
    int size();
    
    // Deconstructor
    ~Roster();
};

#endif /* roster_h */
