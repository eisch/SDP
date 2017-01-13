#include "BTree.h"

BTreeNode::BTreeNode(int _minimum) : minimum(_minimum)

{
	allStudents.resize(2 * minimum - 1);
	children.resize(2 * minimum);
}
BTree::BTree(int _minimumDegree) : minimumDegree(_minimumDegree)
{
	root = nullptr;
}
void BTree::splitHelper(BTreeNode* root, int index, BTreeNode* oldNode)
{
	BTreeNode *newNode = new BTreeNode(oldNode->minimum);
	for (int i = 0; i < root->minimum - 1;i++)
	{
		newNode->allStudents.push_back(oldNode->allStudents[i + root->minimum]);
	}
	if (oldNode->children.size())
	{
		for (int i = 0; i < root->minimum; i++)
		{
			newNode->children.push_back(oldNode->children[i + root->minimum]);
		}
	}
	for (int i = root->allStudents.size(); i >= index + 1; i--)
	{
		root->children[i + 1] = root->children[i];
	}
	root->children[index + 1] = newNode;
	for (int i = root->allStudents.size()-1; i > index; i--)
	{
		root->allStudents[i + 1] = root->allStudents[i];
	}
	root->allStudents[index] = oldNode->allStudents[root->minimum - 1];
}



bool BTree::isEmpty()
{
	return (root == nullptr);
}

int BTree::capacity()
{
	return root->allStudents.capacity();
}
