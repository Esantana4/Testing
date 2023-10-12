#include "MyBagTemplate.h"

//precondition: going to call my defaults constructor
//postcondition: going to initialize them and passing in the template
template<typename T>
MyBagTemplate<T>::MyBagTemplate() : data(nullptr), size(0), capacity(0) {}
//precondition: going to call my constructor
//postcondition: going to be allocating new to the data and newCapacity with size using templates
template<typename T>
MyBagTemplate<T>::MyBagTemplate(int newCapacity) : data(new T[newCapacity]), size(0), capacity(newCapacity) {}
//precondition: going to call my deconstructor
//postcondition: going to deallocate the memory so it does not leak, using templates
template<typename T>
MyBagTemplate<T>::~MyBagTemplate() {
    delete[] data;
}

//precondition: going to get the size , Template way
//postcondition: going to return the private size
template<typename T>
int MyBagTemplate<T>::getSize() const {
    return size;
}
//precondition: going to get the new size, Template way
//postcondition: going to set the private size with the new size member
template<typename T>
void MyBagTemplate<T>::setSize(int newSize) {
    size = newSize;
}

template<typename T>
void MyBagTemplate<T>::clearMyBag() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

template<typename T>
void MyBagTemplate<T>::insertMyBag(const T& insert) {
    if (size >= capacity) {
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        T* newData = new T[newCapacity];

        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        //deallocate the memory so it does not leak
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
    data[size++] = insert;
}

template<typename T>
bool MyBagTemplate<T>::searchMyBag(const T& search) const {
    for (int i = 0; i < size; ++i) {
        if (data[i] == search) {
            return true;
        }
    }
    return false;
}

template<typename T>
bool MyBagTemplate<T>::removeMyBag(const T& remove) {
    int index = -1;
    for (int i = 0; i < size; ++i) {
        if (data[i] == remove) {
            index = i;
            break;
        }
    }
    if (index != -1) {
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
        return true;
    }
    return false;
}

template<typename T>
void MyBagTemplate<T>::sortMyBag() {
    sort(data, data + size);
}

template<typename T>
bool MyBagTemplate<T>::operator<(const MyBagTemplate<T>& obj) const {
    return size < obj.size;
}

template<typename T>
T& MyBagTemplate<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return data[index];
}

template<typename T>
const T& MyBagTemplate<T>::operator[](size_t index) const {
    if (index >= 0 && index < size) {
        return data[index];
    }
    // Handle out-of-bounds access
    throw out_of_range("Index out of bounds");
}

template<typename T>
ostream& operator<<(ostream& out, const MyBagTemplate<T>& bag) {
    for (int i = 0; i < bag.size; ++i) {
        out << bag.data[i] << " ";
    }
    return out;
}

template<typename T>
void MyBagTemplate<T>::add(double value) {
    if (size == capacity) {
        ensureCapacity((capacity == 0) ? 1 : capacity * 2);
    }
    data[size++] = value;
}

template<typename T>
void MyBagTemplate<T>::clear() {
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

template<typename T>
void MyBagTemplate<T>::ensureCapacity(int newCapacity) {
    if (newCapacity > capacity) {
        double* newData = new double[newCapacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }
}

template<typename T>
bool MyBagTemplate<T>::remove(double value) {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            for (int j = i; j < size - 1; j++) {
                data[j] = data[j + 1];
            }
            size--;
            return true;
        }
    }
    return false;
}

template<typename T>
int MyBagTemplate<T>::getFrequencyOf(double value) const {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            count++;
        }
    }
    return count;
}

template<typename T>
bool MyBagTemplate<T>::contains(double value) const {
    for (int i = 0; i < size; i++) {
        if (data[i] == value) {
            return true;
        }
    }
    return false;
}

template<typename T>
void MyBagTemplate<T>::display() const {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }
    cout << endl;
}

template<typename T>
void MyBagTemplate<T>::subMenu()
{
    do
    {
        system("cls");
        cout << endl;
        cout << "\t1> Template MyBag of doubles" << endl;
        cout << "\t" << string(80, char(205)) << endl;
        cout << "\t\t1> clear" << endl;
        cout << "\t\t2> insert" << endl;
        cout << "\t\t3> search" << endl;
        cout << "\t\t4> remove" << endl;
        cout << "\t\t5> sort" << endl;
        cout << "\t\t6> display" << endl;
        cout << "\n\t" << string(80, char(169));
        cout << "\n\t0 > exit" << endl;
        cout << "\t" << string(80, char(205)) << endl;

        // get user input/option of main menu
        int option = inputInteger("\n\tOption: ", 0, 6);

        switch (option)
        {
        case 0: // Return to Main Menu
        {
            system("cls");
            mainMenu();
        } break;
        case 1: // Clear MyBag
        {
            clear();
            cout << "\nMy bag is cleared of all elements.\n\n";
        } break;
        case 2: // Insert a value to MyBag
        {
            double insertValue = static_cast<double>(inputInteger("\nEnter a value and insert into MyBag: "));
            add(insertValue);
            cout << "\nValue " << insertValue << " has been inserted into MyBag.\n\n";
        } break;
        case 3: // Search
        {
            double findValue = static_cast<double>(inputInteger("\nEnter a value to search from MyBag: "));
            bool found = contains(findValue);
            
            if (found) {
                cout << "\nValue " << findValue << " is in MyBag.\n\n";
            }
            else {
                cout << "\nValue " << findValue << " is not in MyBag.\n\n";
            }

        } break;
        case 4: // Remove an element at index
        {
            int index = inputInteger("\nEnter an index to be deleted: ", 0, size - 1);
            cout << endl;
            if (index < 0 || index >= size)
            {
                cout << "Invalid index or index out of range.\n\n";
            }
            else
            {
                double removedValue = data[index];
                for (int i = index; i < size - 1; i++) {
                    data[i] = data[i + 1];
                }
                size--;
                cout << "Value " << removedValue << " at subscript " << index << " has been deleted.\n\n";
            }
        } break;
        case 5: // Sort
        {
            sort(data, data + size);
            cout << "\nMyBag has been sorted.\n\n";
        } break;
        case 6: // Display
        {
            cout << "\nMyBag:\n ";
            for (int i = 0; i < size; i++)
            {
                cout << endl << "[" << i << "] - " << data[i] << " \n";
            }
            cout << endl << endl;
        } break;
        default:
            cout << "Invalid option. Please enter a valid option.\n";
        }

        // Pause display after every case
        system("pause");

        // New line
        cout << "\n";

    } while (true);
}