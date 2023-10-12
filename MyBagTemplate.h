#pragma once
#include<iostream>
#include <algorithm>
using namespace std;

char inputChar(string prompt, string options);
void mainMenu();
int inputInteger(string prompt);
int inputInteger(string prompt, int startRange, int endRange);

template <typename T>
class MyBagTemplate;

//Template class MyBag for dynamic array
template<typename T>
class MyBagTemplate {
private:
	T* data;
	int size;
	int capacity;
public:

	// Functions to interact with the bag
	void add(double value);
	bool remove(double value);
	bool isEmpty() const { return size == 0; }
	int getCurrentSize() const { return size; }
	void clear();
	int getFrequencyOf(double value) const;
	bool contains(double value) const;
	void display() const;
	void ensureCapacity(int newCapacity);

	//defualt constructor
	MyBagTemplate();
	//constructor
	MyBagTemplate(int newCapacity);
	//destructor
	~MyBagTemplate();

	//getters(accesors)
	int getSize() const;
	//int getCapacity() const;

	//setters(mutators)
	void setSize(int newSize);
	//void setCapacity(int newCapacity);

	//member functions to clear, insert, search, remove, sort, and display
	void clearMyBag();
	void insertMyBag(const T& insert);
	bool searchMyBag(const T& search) const;
	bool removeMyBag(const T& remove);
	void sortMyBag();
	void subMenu();

	//overloading operators
	bool operator<(const MyBagTemplate<T>& obj)const;
	T& operator[](int index);
	const T& operator[](size_t index) const;
	friend ostream& operator<<(ostream& out, const MyBagTemplate<T>& bag);

};