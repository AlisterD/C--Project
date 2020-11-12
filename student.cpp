
#include "student.h"


//Default constructor if nothing is passed
Student::Student()
{
    // set all the data members to default values
    
    // set the ID, first name, last name, email to blank
    studentID = "";
    firstName = "";
    lastName = "";
    emailAddress = "";

    // set the age to 0
    age = 0;
    
    // create the array to hold the days to complete
    daysToComplete = new int[3];
    // set all the values in this array to 0
    for( int i=0; i<3; i++ )
        daysToComplete[i] = 0;
}

//D2.d Constructor using all of the input paramentes provided in the table
Student::Student( string studentID, string firstName, string lastName, string emailAddress, int age, int daysToCompleteArray[], DegreeProgram degreeProgram)
{
    // set the student ID
    setID(studentID);
    
    // set the first name
    setFirstName(firstName);
    
    // set the last name
    setLastName(lastName);
    
    // set the email address
    setEmailAddress(emailAddress);
    
    // set the age
    setAge(age);
    
    // create the days to complete array
    daysToComplete = new int[3];
    
    // copy the values into this array
    for( int i=0; i<3; i++ )
        this->daysToComplete[i] = daysToCompleteArray[i];
    
    // set the degree
    setDegreeProgram(degreeProgram);
}


// D2.a Create an accessor for each of the data member

string Student::getStudentID()
{
    // return the student ID
    return studentID;
}

string Student::getFirstName()
{
    // return the first name
    return firstName;
}

string Student::getLastName()
{
    // return the last name
    return lastName;
}

string Student::getEmailAddress()
{
    // return the email address
    return emailAddress;
}

int Student::getAge()
{
    // return the age
    return age;
}

int* Student::getDaysToComplete()
{
    // return the array for the days to complete
    return daysToComplete;
}

DegreeProgram Student::getDegreeProgram()
{
    // return the degree program
    return degreeProgram;
}


// D2.b mutator for each instance variable from part D1
void Student::setID(string studentID)
{
    // set the student ID
    this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
    // set the first name
    this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
    // set the last name
    this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
    // set the student email Address
    this->emailAddress = emailAddress;
}

void Student::setAge(int age)
{
    // set the age
    this->age = age;
}

void Student::setDaysToComplete(int daysToComplete[])
{
    // iterate the array and copy each value
    for( int i=0; i<3; i++ )
        this->daysToComplete[i] = daysToComplete[i];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
    // set the degree program
    this->degreeProgram = degreeProgram;
}


// Deconstructor
Student::~Student()
{
    // delete the array
    delete [] daysToComplete;
}

// the method to get the degree program name based on the given degree
string getDegreeProgramName(DegreeProgram degreeProgram)
{
    // if this is security
    if( degreeProgram == SECURITY )
    {
        // return the string "SECURITY"
        return "Security";
    }
    
    // else if this is network
    else if( degreeProgram == NETWORK )
    {
        // return the string "NETWORK"
        return "Network";
    }
    
    // else if this is software
    else if( degreeProgram == SOFTWARE )
    {
        // return the string "SOFTWARE"
        return "Software";
    }
    
    // return blank finally
    return "";
}


// D2 e. the method to print the student data
void Student::print()
{
    cout << studentID << " \t First Name: " << firstName << " \t Last Name: " << lastName << " \t Age: " << age << " \tdaysInCourse: {" << daysToComplete[0] << ", " << daysToComplete[1] << " , " << daysToComplete[2] << " } Degree Program: " << getDegreeProgramName(degreeProgram) << endl;
    
}

