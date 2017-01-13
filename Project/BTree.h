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
	bool isLeaf;
	BTreeNode(int, bool);

};
#endif B_TREE
