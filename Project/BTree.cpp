#include "BTree.h"

BTreeNode::BTreeNode(int _minimum, bool _isLeaf) : minimum(_minimum), isLeaf(_isLeaf)

{
	allStudents.resize(2 * minimum - 1);
	children.resize(2 * minimum);
}
