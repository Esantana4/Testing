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
void HashTable::display(int numRecords) {
    int count = 0;
    for (int i = 0; i < TABLE_SIZE && count < numRecords; ++i) {
        if (table[i] != nullptr) {
            cout << "[" << count << "] " << i << ", " << table[i]->name << " (" << table[i]->major << ") - GPA: " << table[i]->gpa << endl;
            count++;
        }
        
    }
}

// Search for a student by ID
Student* HashTable::searchRecord(int id) {
    int index = hash(id);

    // Keep probing until an empty slot is found
    while (table[index] != nullptr) {
        // Check if the current student has the desired ID
        if (table[index]->id == id) {
            return table[index]; // Found the student
        }

        // Move to the next slot using linear probing
        index = (index + 1) % TABLE_SIZE;
    }

    return nullptr; // Student not found
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