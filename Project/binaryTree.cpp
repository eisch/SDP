#include "binaryTree.h"
#include <iostream>
using std::cout;
using std::cin;

void Node::addHelper(Student s)
{
	if (data.getName() != s.getName())
	{
		if (compareNames(s.getName(), data.getName()) < 0) {
			if (left == nullptr) left = new Node(s);
			else left->addHelper(s);
		}
		else if (compareNames(s.getName(), data.getName()) > 0)
		{
			if (right == nullptr) right = new Node(s);
			else right->addHelper(s);
		}
	}
}

bool Node::findHelper(const char * name)
{
	if (compareNames(name, data.getName()) == 0) return true;
	else if (compareNames(name, data.getName()) < 0)
	{
		if (left == nullptr) {
			return false;
		}
		else {
			return left->findAverageHelper(name);
		}
	}
	else if (compareNames(name, data.getName()) > 0)
	{
		if (right == nullptr) {
			return false;
		}
		else {
			return right->findAverageHelper(name);
		}
	}

}

double Node::findAverageHelper(const char * name)
{
	if (findHelper(name)) return data.getAverage();
	return 0;
}

unsigned long Node::findTelephoneNumberHelper(const char * name)
{
	if (findHelper(name)) return data.getNumber();
	return 0;
}

void Node::changeAverageHelper(const char* name)
{

	if (findHelper(name)) {
		cout << "Enter new average for this student:";
		double newAverage;
		cin >> newAverage;
		data.setAverage(newAverage);
		cout << data.getAverage();
	}
}
void Node::changeTelephoneHelper(const char* name)
{

	if (findHelper(name))
	{
		cout << "Enter new telephone number for this student:";
		unsigned long newTelephoneNumber;
		cin >> newTelephoneNumber;
		data.setNumber(newTelephoneNumber);
		cout << data.getNumber();
	}
}

Node* Node::deleteHelper(Student s, Node* parent)
{
	if (compareNames(s.getName(), data.getName()) == 0)
	{

		if (right!=nullptr && left != nullptr)
		{
			this->data.setName(this->right->data.getName());
			data = right->data;
			return right->deleteHelper(this->data, this); 
		}
	 
		else if (parent->left == this)
			{
				parent->left = left;
			}
			else if (parent->right == this)
			{
				parent->right = left;
			}
			
		else if (left == nullptr && right == nullptr)
		{
			if (parent != nullptr)
			{
				if (parent->left == this) parent->left = nullptr;
				else if (parent->right == this) parent->right = nullptr;
			}
			
		}
		return this;
	}

	else if (compareNames(s.getName(), data.getName()) < 0)
	{
		if (left != nullptr)
		{
			return left->deleteHelper(s, this);
		}
		else return nullptr;
	}
	else if (compareNames(s.getName(), data.getName()) > 0)
	{
		if (right != nullptr)
		{
			return right->deleteHelper(s, this);
		}
		else return nullptr; 
	}
	return this;
}

const char* Node::minName()
{
	if (left == nullptr) return data.getName();
	else return left->minName();
}

void Node::setLeft(Node * _left)
{
	this->left = _left;
}

Node * Node::getLeft()
{
	return left;
}

void Node::printHelper()
{
	if(left)
	{
		left->printHelper();

	}
	cout << data << '\n';
	if (right)
	{
		right->printHelper();
	}
}

bool BinaryTree::isEmpty() {
	return root == nullptr;
}

void BinaryTree::addStudent(Student s)
{
	if (root == nullptr) root = new Node(s);
	else root->addHelper(s);
}
double BinaryTree::findAverage(const char* name)
{
	if (root == nullptr)
	{
		return 0;
	}
	else return root->findAverageHelper(name);
}
unsigned long BinaryTree::findTelephoneNumber(const char* name)
{
	if (root == nullptr)
	{
		return 0;
	}
	else return root->findTelephoneNumberHelper(name);
}

void BinaryTree::changeAverage(const char* name)
{
	if (root == nullptr) errorMessage();
	else root->changeAverageHelper(name);

}


void BinaryTree::changeTelephoneNumber(const char* name)
{

	if (root == nullptr)
	{
		errorMessage();
	}
	else root->changeTelephoneHelper(name);
}

bool BinaryTree::deleteStudent(Student s)
{
	Student p;
	if (isEmpty()) return false;
	else
	{
		if (compareNames(s.getName(), root->data.getName())==0)
		{
			Node newNode(p); 
			newNode.setLeft(root);
			Node *removedNode = root->deleteHelper(s, &newNode);
			root = newNode.getLeft();
			if (removedNode != nullptr)
			{
				delete removedNode;
				return true;
			}
			else return false;
		}
		else {
			Node *removedNode = root->deleteHelper(s, nullptr);
			if (removedNode != nullptr)
			{
				delete removedNode;
				return true;
			}
			else return false;
		}
	}
}

void BinaryTree::print()
{
	if (root == nullptr) cout << "Error! Empty database!" << '\n';
	else root->printHelper();
}


