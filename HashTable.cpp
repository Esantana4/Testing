#include "HashTable.h"

//Precondition: NA
//Postcondition: No return, Constructor.
HashTable::HashTable() {
    // Initialize the table with nullptr
    fill_n(table, TABLE_SIZE, nullptr);
}

//Precondition: NA
//Postcondition: Returns TABLE_SIZE
int HashTable::getTable() const
{
    return TABLE_SIZE;
}

//Responsible for determining the index in the hash table where an element with the given key should be stored or looked up.
//Precondition: Parameters - int key
//Postcondition: returns the result of the modulo operation: key % TABLE_SIZE
int HashTable::hash(int key) {
    return key % TABLE_SIZE;
}

//Precondition: Parameters - const Student& student
//Postcondition: No return, inserts a student into the hash table
void HashTable::insert(const Student& student) {
    int index = hash(student.id);

    // Handle collisions by linear probing
    while (table[index] != nullptr) {
        index = (index + 1) % TABLE_SIZE;
    }

    table[index] = new Student(student);
}

//Precondition: Parameters - int numRecords
//Postcondition: No return, displays the contents of the hash table
void HashTable::display(int numRecords) {
    int count = 0;
    cout << "\n\tRecord(s) found:\n";
    for (int i = 0; i < TABLE_SIZE && count < numRecords; ++i) {
        if (table[i] != nullptr) {
            cout << "\t[" << count << "] " << i << ", " << table[i]->name << ", " << table[i]->major << ", GPA: " << table[i]->gpa << endl;
            count++;
        }
    }
    cout << endl;
}

//Precondition: Parameters - int id
//Postcondition: Returns table[index], searches for a student by ID
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

//Precondition: No parameters
//Postcondition: No return, removes a record by ID
void HashTable::removeRecord() {
    // Get student ID to remove
    int idToRemove = inputInteger("\n\tEnter the ID of the student to remove: ", 0, 100);

    // Find the index in the hash table
    int index = hash(idToRemove);

    // Search for the student in the hash table
    while (table[index] != nullptr && table[index]->id != idToRemove) {
        index = (index + 1) % TABLE_SIZE;
    }

    // If student is not found
    if (table[index] == nullptr) {
        cout << "\n\tStudent with ID " << idToRemove << " not found.\n\n";
        return;
    }

    // Delete the student
    delete table[index];
    table[index] = nullptr;

    cout << "\n\tStudent with ID " << idToRemove << " has been removed.\n\n";
}