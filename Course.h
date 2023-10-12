#pragma once
#include "MyBagTemplate.cpp"
#include <string>
#include <iostream>
#include <iomanip>
#include<vector>
#include<string>
#include <fstream>
using namespace std;

//input (1) header files inputs validation
int inputInteger(string prompt);
int inputInteger(string prompt, int startRange, int endRange);
int inputInteger(string prompt, bool posNeg);
string inputString(string prompt, bool spaces);
string toUpper(string& str);
string removeLeadingTrailingSpaces(const string& input);

class Course {
private:
    string name;
    MyBagTemplate<int> studentIDs;
    MyBagTemplate<string> studentNames;
    MyBagTemplate<double> studentScores;
    MyBagTemplate<char> studentGrades;
    
public:
    Course() {};
    //constructor
    Course(const string& courseName);

    //getters(accesors)
    const string& getName() const;
    int getNumStudents() const;
    const MyBagTemplate<int>& getStudentIDs() const;

    //setters(mutators)
    void setName(const string newName);
    char calculateGrade(double score);
    void addStudent(int ID, const string& name, double score);
    const MyBagTemplate<string>& getStudentNames() const;

    //member fucntions
    bool removeStudent(int ID);
    void displayCourse();


    void menuInformation();
};
