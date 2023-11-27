#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int inputInteger(string prompt, int startRange, int endRange);

struct Student {
    int id;
    string name;
    string major;
    double gpa;
};

class HashTable {
private:
    static const int TABLE_SIZE = 100;
    Student* table[TABLE_SIZE];

public:
    HashTable();

    // Hash function
    int hash(int key);

    // Getter, to access TABLE_SIZE
    int getTable() const;

    // Insert a student into the hash table
    void insert(const Student& student);

    // Display the contents of the hash table
    void display(int numRecords);

    // Search Record with ID
    Student* searchRecord(int id);

    //remove record with ID
    void removeRecord();
};