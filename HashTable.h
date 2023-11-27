#pragma once
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