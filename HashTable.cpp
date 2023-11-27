#include "HashTable.h"

HashTable::HashTable() {
    // Initialize the table with nullptr
    fill_n(table, TABLE_SIZE, nullptr);
}

// Hash function
int HashTable::hash(int key) {
    return key % TABLE_SIZE;
}

// Insert a student into the hash table
void HashTable::insert(const Student& student) {
    int index = hash(student.id);

    // Handle collisions by linear probing
    while (table[index] != nullptr) {
        index = (index + 1) % TABLE_SIZE;
    }

    table[index] = new Student(student);
}

// Display the contents of the hash table
void HashTable::display() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (table[i] != nullptr) {
            cout << "[" << i << "] " << table[i]->name << " (" << table[i]->major << ") - GPA: " << table[i]->gpa << endl;
        }
    }
}

/*
HashTable::HashTable() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        ids[i] = -1;
    }
}

int HashTable::hash(int key) {
    return key % TABLE_SIZE;
}

void HashTable::insert(int id, const string& name, const string& major, double gpa) {
    int index = hash(id);

    while (ids[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }

    ids[index] = id;
    names[index] = name;
    majors[index] = major;
    gpas[index] = gpa;
}

void HashTable::display(int numRecords) {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE && count < numRecords; ++i) {
        if (ids[i] != -1) {
            cout << "[" << count << "] " << i << ", " << names[i] << " (" << majors[i] << ") - GPA: " << gpas[i] << endl;
            ++count;
        }
    }
    system("pause");
}
*/