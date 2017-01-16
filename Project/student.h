#ifndef STUDENT
#define STUDENT
#include <iostream>

using std::ostream;
using std::istream; 

const int MAX_NAME_SIZE = 32;

class Student
{
	char name[MAX_NAME_SIZE];
	unsigned long number;
	double average;
public:
	
	Student(char*, double, unsigned long);
	Student();
	const char* getName();
	double getAverage(); 
	unsigned long getNumber();
	void setName(const char*);
	void setNumber(unsigned long);
	void setAverage(double);
    Student& operator=(const Student&);
	friend istream& operator>> (istream&, Student&);
	friend ostream& operator<<(ostream&, Student&);
	friend bool operator==(Student&, Student&);
};
int compareNames(const char*, const char*);
void errorMessage();

#endif STUDENT