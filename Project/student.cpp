#include <iostream>
#include "student.h"
#include "binaryTree.h"
#include "BTree.h"

using std::cout;
using std::endl;
using std::boolalpha;

Student::Student(char* _name, double _average, unsigned long _number) : average(_average), number(_number)
{

	strcpy_s(name, _name);

}
Student::Student()
{
	strcpy_s(name, "");
	average = 0;
	number = 0;
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
Student& Student::operator=(const Student& other)
{
	if (this != &other)
	{
		strcpy_s(name, other.name);
		average = other.average;
		number = other.number;
	}
	return *this;
}

bool operator==(Student &s, Student& p)
{
	return (strcmp(p.getName(), s.getName()) == 0) && (p.getAverage() == s.getAverage())
		&& (p.getNumber() == s.getNumber());
}

istream& operator >> (istream &i, Student &s)
{
	return (i >> s.number >> s.average).getline(s.name, MAX_NAME_SIZE);
}

ostream& operator<<(ostream &o, Student& s)
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
	Student a("J", 5.5, 11111);
	Student b("F", 4.5, 22222);
	Student c("Z", 6, 33333);
	Student d("P", 3.5, 44444);
	Student e("D", 5, 65444);
	Student f("Zl", 5, 65444);
	Student g("Zf", 5, 65444);
	Student h("Bc", 3.5, 44444);
	Student i("E", 5, 65444);
	Student j("Kl", 5, 65444);
	Student k("St", 5, 65444);
	Student l("M", 3, 4454);
	Student m("L", 4.5, 98494);
	//Node c(a);
	//BinaryTree first;*/

	/*first.addS(a);
	first.addS(b);
	first.addS(c);
	first.addS(d);
	first.addS(e);
	first.addS(f);
	first.addS(g);*/
	//cout << first.findAverage("J");
	//cout << first.findTelephoneNumber("Z");
	//cout << endl;
	//first.changeTelephoneNumber("Z");
	//first.changeTelephoneNumber("P");
	/*cout << d.getAverage();*/
	//first.writeStudenktsInFile();
	/*	cout << first.deleteStudent("J");
	first.print();
	first.deleteStudent("D");
	//cout << endl;
	//first.print();
	//	cout << endl;
	first.deleteStudent("A");
	//cout << endl;
	//first.print();*/

	BTree tree(3);
	tree.add(a);
	tree.add(b);
	tree.add(c);
	tree.add(d);
	tree.add(e);

	tree.add(f);

	//tree.add(g);

/*	tree.add(h);
	tree.add(i);
	tree.add(j);
	tree.add(k);
	tree.add(l);
	tree.add(m);*/

	tree.print();


	system("Pause");
	return 0;
}