#ifndef B_TREE
#define B_TREE

#include <vector>
#include "student.h"

using std::vector;

struct BTreeNode
{
	vector<Student> allStudents;
	int minimum;
	vector<BTreeNode*> children;
	BTreeNode(int);
	
	BTreeNode();
	
};

class BTree
{
	BTreeNode *root;
	int minimumDegree;
	void splitHelper(BTreeNode*, int, BTreeNode*);
	void insertHelper(BTreeNode*, Student&);
	void printHelper(BTreeNode*, ostream&);
public:
	int capacity();
	BTree(int);
	void add(Student);
	bool isEmpty();
	void print();
	vector<Student> getRoot();
};
#endif B_TREE
