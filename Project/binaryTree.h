#ifndef BINARY_TREE
#define BINARY_TREE

#include "student.h"

struct Node
{
	Student data;
	Node* left;
	Node* right;

	Node(Student _data) : left(nullptr), right(nullptr)
	{
		data = _data;
	}
	//void addHelper(Student);
	//bool findHelper(const char*);
	//double findAverageHelper(const char*);
	//unsigned long findTelephoneNumberHelper(const char*);
	//void changeAverageHelper(const char*);
	//void changeTelephoneHelper(const char*);
	//bool deleteHelper(Node*, Node*, Student);
	Node* deleteHelper(Student, Node*);
	
	void setLeft(Node*);
	Node* getLeft();
	//void printHelper();
	Student minName();

};

class BinaryTree {
	Node* root;
	void addHelper(Node* s, Student);
	Student* findHelper(Node*, const char*);
	Node* findH(Node*, const char*);
	Student find(Node*, const char*);
	void avh(Node*, const char*, Student&);
	void printHelper(Node*);
public:
	BinaryTree()
	{
		root = nullptr;
	};
	void addS(Student a)
	{
		if (isEmpty()) root = new Node(a);
		else addHelper(root, a);
	}
	bool isEmpty();
	//void addStudent(Student);
	double findAverage(const char*);
	unsigned long findTelephoneNumber(const char*);
	void changeAverage(const char*);
	void changeTelephoneNumber(const char*);
    bool deleteStudent(Student);
	void print();
};

#endif BINARY_TREE
