/*
	Implementation of classes:
	- Data
	- Dictionary
	- Database
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "libdb.h"



using namespace std;

// ---------------- class Data ----------------

// constructor per default
Data::Data() {
	this->position = MyString("None");
	this->sex = MALE;
	this->age = 0;
	this->salary = 0.0;
}

// constructor by parameters
Data::Data(const MyString& position, int age, SEX sex, double salary) {
	this->position = position;
	this->age = age;
	this->sex = sex;
	this->salary = salary;
}

// operator<< for Data
ostream& operator<<(ostream& os, const Data& data) {
	os << "Position" << setw(15) << "Age" << setw(10)
		<< "Sex" << setw(15) << "Salary" << endl;
	os << "--------------------------------------------------" << endl;
	os << data.position << setw(15) << data.age << setw(10)
		<< (data.sex == MALE ? "Male" : "Female") << setw(15) << data.salary << endl;

	return os;
}

// ---------------- class Dictionary ----------------

// constructor per default
Dictionary::Dictionary() {
	this->key = MyString("NULL");
	this->data = Data();
}

// constructor by parameters
Dictionary::Dictionary(const MyString& key, const Data& data) {
	this->key = key;
	this->data = data;
}

// operator<< for Dictionary
ostream& operator<<(ostream& os, const Dictionary& pair) {
	os << "Key: " << pair.key << " ==> \nData: \n" << pair.data;
	return os;
}

// ---------------- class DB ----------------

// default constructor
DB::DB() {
	this->pairs = new Dictionary * [this->CHUNK_SIZE];
	this->size = 0;
	this->capacity = this->CHUNK_SIZE;
}

// copy constructor
DB::DB(const DB& db) {
	this->pairs = nullptr;
	this->size = 0;
	this->capacity = 0;
	*this = db;
}

// move constructor (исправлено)
DB::DB(DB&& db) {
	this->pairs = db.pairs;
	this->size = db.size;
	this->capacity = db.capacity;

	db.pairs = nullptr;
	db.size = 0;
	db.capacity = 0;
}

// destructor
DB::~DB() {
	for (int i = 0; i < this->size; i++)
		delete this->pairs[i];
	delete[] this->pairs;
}

// copy assignment operator
DB& DB::operator=(const DB& db) {
	if (this != &db) {
		if (this->capacity < db.size) {
			delete[] this->pairs;
			this->capacity = db.size + this->CHUNK_SIZE;
			this->pairs = new Dictionary * [this->capacity];
		}

		this->size = db.size;

		for (int i = 0; i < size; i++) {
			this->pairs[i] = new Dictionary(*db.pairs[i]); // глубокое копирование
		}
	}
	return *this;
}

// move assignment operator
DB& DB::operator=(DB&& db) {
	if (this != &db) {
		for (int i = 0; i < this->size; i++)
			delete this->pairs[i];
		delete[] this->pairs;

		this->pairs = db.pairs;
		this->size = db.size;
		this->capacity = db.capacity;

		db.pairs = nullptr;
		db.size = 0;
		db.capacity = 0;
	}
	return *this;
}

// operator[] — поиск или добавление нового
Data& DB::operator[](const MyString& key) {
	for (int i = 0; i < this->size; i++) {
		if (this->pairs[i]->key == key)
			return pairs[i]->data;
	}
	return Add(key, Data());
}

// добавление новой пары
Data& DB::Add(const MyString& key, const Data& data) {
	if (this->size >= this->capacity) {
		Dictionary** temp = new Dictionary * [this->capacity + this->CHUNK_SIZE];
		for (int i = 0; i < this->size; i++)
			temp[i] = this->pairs[i];

		delete[] this->pairs;
		this->pairs = temp;
		this->capacity += this->CHUNK_SIZE;
	}

	this->pairs[this->size] = new Dictionary(key, data);
	return this->pairs[size++]->data;
}

// удаление по ключу
void DB::Remove(const MyString& key) {
	bool deleted = false;

	for (int i = 0; i < this->size; i++) {
		if (this->pairs[i]->key == key) {
			deleted = true;
			delete this->pairs[i];
			this->pairs[i] = this->pairs[--this->size];
			cout << "Element deleted!" << endl;
			break;
		}
	}

	if (!deleted)
		cout << "Element not found!" << endl;
}

// operator<< для DB
ostream& operator<<(ostream& os, const DB& db) {
	for (int i = 0; i < db.size; i++)
		os << *db.pairs[i] << endl;

	return os;
}
