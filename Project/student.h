#ifndef STUDENT
#define STUDENT
#include <iostream>

using std::ostream;
using std::istream; 

const int MAX_NAME_SIZE = 32;

class Student
{
	char name[MAX_NAME_SIZE];
	double average;
	unsigned long number;
public:
	
	Student();
	Student(const char*, double, unsigned long );
	const char* getName();
	double getAverage(); 
	unsigned long getNumber();
	void setName(const char*);
	void setNumber(unsigned long);
	void setAverage(double);
	Student& operator=(Student&);
	//friend istream& operator>> (istream&, Student&);
	friend ostream& operator<<(ostream&, Student&);
};
int compareNames(const char*, const char*);
void errorMessage();

#endif STUDENT