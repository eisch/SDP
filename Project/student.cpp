#include <iostream>
#include "student.h"
#include "binaryTree.h"

using std::cout;
using std::endl;

Student::Student() {};
Student::Student(const char* _name = "", double _average = 0, unsigned long _number = 0): average(_average),
number(_number)
{
	strcpy_s(name, _name);
}
double Student::getAverage()
{
	return average;
}
unsigned long Student::getNumber()
{
	return number;
}
const char* Student::getName() {
	return name;
}
void Student::setNumber(unsigned long _number)
{
	number = _number;
}
void Student::setAverage(double _average)
{
	average = _average;
}
void Student::setName(const char* _name)
{
	strcpy_s(name, _name);
}
Student& Student::operator=(Student& other)
{
	if (this != &other)
	{
		strcpy_s(name, other.name);
		average = other.average;
		number = other.number;
	}
	return *this;
}

/*istream & operator >> (istream &, Student &)
{
	// TODO: insert return statement here
}*/

ostream & operator<<(ostream &o, Student& s)
{
	return o << s.name << "  " << s.number << "  " << s.average;
}

int compareNames(const char* first, const char* second)
{
	return strcmp(first, second);

}
void errorMessage()
{
	cout << "The student isn't in the database!" << endl;
}


int main()
{
	Student a("J", 5.5, 15554545);
	Student b("F", 4.5, 164648548);
	Student c("Z", 6, 5645441);
	Student d("C", 3.5, 7454544);
	//Node c(a);
	BinaryTree first;
	first.addStudent(a);
	first.addStudent(b);
	first.addStudent(c);
	first.addStudent(d);

	first.print();

	system("Pause");
	return 0; 
}