#include "HashTable.h"

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
