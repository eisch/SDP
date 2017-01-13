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
	//bool isLeaf;

	BTreeNode(int);

};
class BTree
{
	BTreeNode *root;
	int minimumDegree;
	void splitHelper(BTreeNode*, int, BTreeNode*);
public:
	BTree(int);
	bool isEmpty();
	int capacity();
};
#endif B_TREE
