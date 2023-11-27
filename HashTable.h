#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    string major;
    double gpa;
};

class HashTable {
private:
    static const int TABLE_SIZE = 100;  // Choose an appropriate table size
    Student* table[TABLE_SIZE];

public:
    HashTable();

    // Hash function
    int hash(int key);

    // Insert a student into the hash table
    void insert(const Student& student);

    // Display the contents of the hash table
    void display();
};

/*
#include <iostream>
using namespace std;

int inputInteger(string prompt, int startRange, int endRange);

class HashTable {
private:
    static const int TABLE_SIZE = 100;
    int ids[TABLE_SIZE];
    string names[TABLE_SIZE];
    string majors[TABLE_SIZE];
    double gpas[TABLE_SIZE];

public:
    HashTable();

    int hash(int key);

    void insert(int id, const string& name, const string& major, double gpa);

    void display(int numRecords);
};
*/