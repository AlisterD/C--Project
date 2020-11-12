
#include "roster.h"

// the constructor
Roster::Roster()
{
    // set the initial number of students to 0
    numStudents = 0;
}
 
// the method to add a new student to the roster
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)
{
    // create an array with three locations
    int daysToComplete[3];
    
    // set the days in this array
    daysToComplete[0] = daysInCourse1;
    daysToComplete[1] = daysInCourse2;
    daysToComplete[2] = daysInCourse3;
    
    // create a student
    Student * newStudent = new Student(studentID,firstName,lastName,emailAddress,age,daysToComplete,degreeprogram);
    
    // add this to the roster
    classRosterArray[numStudents++] = newStudent;
}

// the method to remove the student with this ID
void Roster::remove(string studentID)
{
    // iterate and look for a student for this ID
    
    // for each student
    for( int i=0; i<numStudents; i++ )
    {
        // if this is a student we are looking for
        if( classRosterArray[i]->getStudentID() == studentID )
        {
            // delete this student
            delete classRosterArray[i];
            
            // shift all the element from this index one position left
            for( int j=i; j<numStudents-1; j++ )
                classRosterArray[j] = classRosterArray[j+1];
            
            // decrement the number of studnets
            numStudents--;
            
            // show message
            cout << "Student with ID '" << studentID << "' removed!" << endl;
            
            // return
            return;
         }
    }
    
    // finally, show message, student with the given id not found
    cout << "No student found with ID '" << studentID << "'." << endl;
}

void Roster::printAll()
{
    // iterate through the roster and print all the students
    
    // for each student
    for( int i=0; i<numStudents; i++ )
    {
        // call the print function for this student
        classRosterArray[i]->print();
        
        // change a line
        cout << endl;
    }
}

void Roster::printAverageDaysInCourse(string studentID)
{
    // iterate and look for a student for this ID
    
    // for each student
    for( int i=0; i<numStudents; i++ )
    {
        // if this is a student we are looking for
        if( classRosterArray[i]->getStudentID() == studentID )
        {
            // get the array
            int * daysToComplete = classRosterArray[i]->getDaysToComplete();
            
            // find the sum of the values
            double total = daysToComplete[0] + daysToComplete[1] + daysToComplete[2];
            
            // find the average
            double avg = total/3.0;
            
            // print the average
            cout << "The average number of days for courses for student with ID '" << studentID << "' is " << avg << " days." << endl;
            
            // return
            return;
         }
    }
    
    // finally, show message, student with the given id not found
    cout << "No student found with ID '" << studentID << "'." << endl;
}

// the method to check if the given string contains the given character
bool containsChar(string str, char c)
{
    // iterate and look for this char
    
    // for each char in this email
    for( int i=0; i<str.length(); i++ )
    {
        // if there is a match
        if( str[i] == c )
        {
            // return true
            return true;
        }
    }
    
    // finally return false
    return false;
}

void Roster::printInvalidEmails()
{
    // the flag to store if found
    bool found = false;
    
    // for each student
    for( int i=0; i<numStudents; i++ )
    {
        // get the email for this student
        string email = classRosterArray[i]->getEmailAddress();
        
        // if this is not valid
        if( !(containsChar(email, '@') && containsChar(email, '.') && !containsChar(email, ' ') ) )
        {
            // print this as invalid email
            cout << "Student with ID '" << classRosterArray[i]->getStudentID() << "' has invalid email address '" << email << "'!" << endl;
            
            // set found to true
            found = true;
        }
    }
    
    // if not found
    if( !found )
    {
        // show no students with invalid emailsc
        cout << "No students with invalid emails!" << endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
    // print all the students with this given degree
    
    // for each student
    for( int i=0; i<numStudents; i++ )
    {
        // if this is the degree we need to print
        if( classRosterArray[i]->getDegreeProgram() == degreeProgram )
        {
            // print this
            classRosterArray[i]->print();
        }
    }
}

// getter for all the students
Student ** Roster::getAllStudents()
{
    // return the class roster
    return classRosterArray;
}

// get the size
int Roster::size()
{
    // return the size
    return numStudents;
}

// Deconstructor
Roster::~Roster()
{
    // delete all the students
    
    // for each student
    for( int i=0; i<numStudents; i++ )
    {
        // delete it
        delete classRosterArray[i];
    }
}
