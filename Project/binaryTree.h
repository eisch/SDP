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
	void addHelper(Student);
	bool findHelper(const char*);
	double findAverageHelper(const char*);
	unsigned long findTelephoneNumberHelper(const char*);
	void changeAverageHelper(const char*);
	void changeTelephoneHelper(const char*);
	//bool deleteHelper(Node*, Node*, Student);
	Node* deleteHelper(Student, Node*);
	const char* minName();
	void setLeft(Node*);
	Node* getLeft();
	void printHelper();

};

class BinaryTree {
	Node* root;
	//bool deleteHelper(Node*, Node*, Student);



public:
	/*BinaryTree(Node* root) : root(nullptr) {

		};*/
	BinaryTree()
	{
		root = nullptr;
	};
	bool isEmpty();
	void addStudent(Student);
	double findAverage(const char*);
	unsigned long findTelephoneNumber(const char*);
	void changeAverage(const char*);
	void changeTelephoneNumber(const char*);
    bool deleteStudent(Student);
	void print();
	
};

#endif BINARY_TREE
