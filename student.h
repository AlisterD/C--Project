
#ifndef student_hpp
#define student_hpp

#include "degree.h"
#include <string> // gives string funtions
#include <iostream>

using namespace std;
// D1 Create the class Student
class Student
{

private:
    // the private data members
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int *daysToComplete;//dynamic array
    DegreeProgram degreeProgram; //enum data type from degree.h

public:
    //Default constructor if nothing is passed
    Student();

    //D2.D Constructor using all of the input paramentes provided in the table
    Student( string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteArray[], DegreeProgram degreeProgram);
    
    // D2.a Create an accessor for each of the data member
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getDaysToComplete();
    DegreeProgram getDegreeProgram();
    
    
    // D2.b mutator for each instance variable from part D1
    void setID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmailAddress(string emailAddress);
    void setAge(int age);
    void setDaysToComplete(int daysToComplete[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    //Deconstructor
    ~Student();
    
    // D2 e. the method to print the student data
    void print();
};

#endif /* student_h */
