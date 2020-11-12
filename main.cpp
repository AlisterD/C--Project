
#include <iostream>
using namespace std;

// include the roster
#include "roster.h"

const string studentData[] =
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY","A5,[firstname],[lastname],[emailaddress],11, 11,11,11,SOFTWARE"
    };

// the size
const int STUDENT_DATA_SIZE = 5;

// the method to get the degree for the given name
DegreeProgram getDegree(string degreeName)
{
    // if this is secutiry
    if( degreeName == "SECURITY")
        return SECURITY;
    
    // if this is network
    else if( degreeName == "NETWORK")
        return NETWORK;
    
    // else return software
    else
        return SOFTWARE;
}

// the method to parse the string into a student
void parse(string line, Roster * roster)
{
    string studentID, firstName, lastName, emailAddress, degreeName;
    int age, daysCourse1, daysCourse2, daysCourse3;
    
    // the index of comma
    size_t commaIndex = line.find(',');
    // get the student id
    studentID = line.substr(0,commaIndex);
    // remove the studentID from the string
    line = line.substr(commaIndex+1);
    
    
    // the index of comma
    commaIndex = line.find(',');
    // get the firstName
    firstName = line.substr(0,commaIndex);
    // remove the firstName from the string
    line = line.substr(commaIndex+1);
    
    
    // the index of comma
    commaIndex = line.find(',');
    // get the last name
    lastName = line.substr(0,commaIndex);
    // remove the last name from the string
    line = line.substr(commaIndex+1);
    
    
    // the index of comma
    commaIndex = line.find(',');
    // get the email address
    emailAddress = line.substr(0,commaIndex);
    // remove the email address from the string
    line = line.substr(commaIndex+1);
    
    
    // the index of comma
    commaIndex = line.find(',');
    // get the age
    age = stoi(line.substr(0,commaIndex));
    // remove the age from the string
    line = line.substr(commaIndex+1);
    
    
    // the index of comma
    commaIndex = line.find(',');
    // get the number of days in course 1
    daysCourse1 = stoi(line.substr(0,commaIndex));
    // remove the daysCourse1 from the string
    line = line.substr(commaIndex+1);
    
    
    // the index of comma
    commaIndex = line.find(',');
    // get the number of days in course 1
    daysCourse2 = stoi(line.substr(0,commaIndex));
    // remove the daysCourse2 from the string
    line = line.substr(commaIndex+1);
    
    // the index of comma
    commaIndex = line.find(',');
    // get the number of days in course 1
    daysCourse3 = stoi(line.substr(0,commaIndex));
    // remove the daysCourse3 from the string
    line = line.substr(commaIndex+1);
    
    // get the degree name
    degreeName = line;
    
    // create a student and add to roster
    roster->add(studentID, firstName, lastName, emailAddress, age, daysCourse1, daysCourse2, daysCourse3, getDegree(degreeName));
}

int main(int argc, const char * argv[])
{
    // create a roster
    Roster classRoster;
    
    // add all students to the roster
    for( int i=0; i<STUDENT_DATA_SIZE; i++ )
        parse(studentData[i], &classRoster);
    
    // print all
    classRoster.printAll();
    
    // change line
    cout << endl;
    
    // print invalid emails
    classRoster.printInvalidEmails();
    
    // change line
    cout << endl;
    
    // for each of the student
    for( int i=0; i<classRoster.size(); i++ )
    {
        // print average days in course for this
        classRoster.printAverageDaysInCourse( classRoster.getAllStudents()[i]->getStudentID() );
    }
    
    // change line
    cout << endl;
    
    // print by degree program - software
    classRoster.printByDegreeProgram(SOFTWARE);
    
    // change line
    cout << endl;
    
    // remove A3
    classRoster.remove("A3");
    
    // change line
    cout << endl;
    
    // print all
    classRoster.printAll();
    
    // change line
    cout << endl;
    
    // remove A3
    classRoster.remove("A3");
    
    // change line
    cout << endl;
    
    return 0;
}
