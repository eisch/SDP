#include "BTree.h"
#include <iostream>

using std::cout;

BTreeNode::BTreeNode(int _minimum) : minimum(_minimum)
{
	allStudents.reserve(2 * minimum - 1);
	children.reserve(2 * minimum);
}

BTreeNode::BTreeNode()
{
	minimum = 1;
	allStudents.reserve(2 * minimum - 1);
	children.reserve(2 * minimum);
}

BTree::BTree(int _minimumDegree) : minimumDegree(_minimumDegree)
{
	//root->allStudents.resize(2 * minimumDegree - 1);
	//root->children.resize(2 * minimumDegree);
	root = nullptr;


}
int BTree::capacity()
{
	return root->allStudents.size();
}
void BTree::splitHelper(BTreeNode* root, int index, BTreeNode* oldNode) //root = newNode, index =0 , oldNode=root
{
	BTreeNode *newNode = new BTreeNode(oldNode->minimum);
	newNode->allStudents.reserve(root->minimum - 1);
	for (int i = 0; i < root->minimum - 1;i++)
	{
		newNode->allStudents.push_back(oldNode->allStudents[i + root->minimum]);
	}

	if (oldNode->children.size() != 0)
	{
		for (int i = 0; i < root->minimum; i++)
		{
			newNode->children.push_back(oldNode->children[i + root->minimum]);
		}
	}

	oldNode->allStudents.pop_back();
	for (int i = root->allStudents.size(); i >= index + 1; i--)
	{
		root->children.insert(root->children.begin()+(i+1), root->children[i]);
		root->children.erase(root->children.begin() + i);
		//cout << root->children[i + 1];
	}

	root->children.insert(root->children.begin() + (index + 1), newNode);

	for (int i = root->allStudents.size() - 1; i >= index; i--)
	{
		//root->allStudents[i + 1] = root->allStudents[i];
		root->allStudents.insert(root->allStudents.begin() + (i + 1), root->allStudents[i]);
		root->allStudents.erase(root->allStudents.begin() + (i));
		//root->allStudents.erase(root->allStudents.end() + (i));
	}

	root->allStudents.insert(root->allStudents.begin() + (index), oldNode->allStudents[root->minimum - 1]);
	oldNode->allStudents.erase(oldNode->allStudents.begin() + (root->minimum));
	//root->allStudents.push_back(Student());
	//cout <<  "Old node's size: " << oldNode->allStudents.size();
	/*oldNode->allStudents.pop_back();
	oldNode->allStudents.pop_back();
	oldNode->allStudents.pop_back();
	*/
	//root->allStudents.erase(root->allStudents.begin() + (index-1));
}

void BTree::insertHelper(BTreeNode* root, Student &s)
{

	int index = root->allStudents.size() - 1;
	if (root->children.size() == 0)
	{
		while (index >= 0 && compareNames(s.getName(), root->allStudents[index].getName()) < 0)
		{
			//cout << index << '\n';
			root->allStudents.insert(root->allStudents.begin() + (index + 1), root->allStudents[index]);
			root->allStudents.erase(root->allStudents.begin() + (index));

			index--;
		//	cout << " Size" << root->allStudents.size() << '\n';
			//cout << index << '\n';

		}
		root->allStudents.insert(root->allStudents.begin() + (index + 1), s);
		//root->allStudents.erase(root->allStudents.begin() + (index + 2));
	}
	else
	{
		//cout << root->allStudents.size();
		while (index >= 0 && compareNames( s.getName(), root->allStudents[index].getName()) < 0)
		{
			index--;
		}
		if (root->children.size() == 2 * root->minimum - 1)
		{
			//root->allStudents.clear();
			splitHelper(root, index + 1, root->children[index + 1]);
			if (compareNames( s.getName(), root->allStudents[index].getName()) > 0)index++;
		}
		insertHelper(root->children[index + 1], s);

	}
}

void BTree::printHelper(BTreeNode* root, ostream& o)
{
	unsigned index = 0;
	for (index = 0; index < root->allStudents.size(); index++)
	{
		if (root->children.size()!=0)
		{
			printHelper(root->children[index], o);
			cout << '\n' << "-----";

			
		}
		o << root->allStudents[index] << '\n';

	}

	if (root->children.size())
	{
		printHelper(root->children[index], o);
		cout << '\n' << "-----";

		//cout << "Root children size: " << root->children.size();
	}
	/*if (root->children.size())
		{
			for (BTreeNode* b : root->children)
			{
				printHelper(b, o);
				cout << '\n';
			}



		}*/
}

void BTree::print()
{
	if (root != nullptr)
	{
		printHelper(root, cout);
	}
}

vector<Student> BTree::getRoot()
{
	return root->allStudents;
}

bool BTree::isEmpty()
{
	return (root == nullptr);
}



void BTree::add(Student s)
{
	if (root == nullptr)
	{
		root = new BTreeNode(minimumDegree);
		root->allStudents.push_back(s);
	}
	else
	{
		if (root->allStudents.size() == (2 * minimumDegree - 1))
		{
		
			BTreeNode *newNode = new BTreeNode(minimumDegree);
			newNode->children.push_back(root);
			splitHelper(newNode, 0, root);
			int index = 0;

			//newNode->allStudents.front().getName();
			if (compareNames( s.getName(), newNode->allStudents.front().getName()) > 0)
			{
				index++;
			}
			
			insertHelper(newNode->children[index], s);
			//root->allStudents.clear();
			//root->allStudents.resize(2 * minimumDegree - 1);
			root = newNode;
			

		}
		else
		{
			/*cout << "Minimum degree: " << minimumDegree << "    " << "Root's size: "
				<< root->allStudents.size() << '\n';*/

			insertHelper(root, s);

			//jroot->children.erase(root->children.begin());

		}

	}
}

