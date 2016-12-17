#include "binaryTree.h"
#include <iostream>
using std::cout;
using std::cin;

void Node::addHelper(Student s)
{
	if (strcmp(data.getName(), s.getName()))
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
	if (!strcmp(data.getName(), s.getName())==0)
		cout << "There's a student with this name!" << s.getName() << '\n';
}

bool Node::findHelper(const char* name)
{
	if (compareNames(name, data.getName()) == 0) return true;
	else if (compareNames(name, data.getName()) < 0)
	{
		if (left == nullptr) {
			return false;
		}
		else {
			return left->findHelper(name);
		}
	}
	else if (compareNames(name, data.getName()) > 0)
	{
		if (right == nullptr) {
			return false;
		}
		else {
			return right->findHelper(name);
		}
	}
	return false;
}

double Node::findAverageHelper(const char * name)
{
	if (findHelper(name)) return data.getAverage();
	if (!findHelper(name)) errorMessage();
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
		cout << "The old average - " << data.getAverage() << '\n';
		cout << "Enter new average for this student:" << '\n';
		double newAverage;
	
		cin >> newAverage;

		data.setAverage(newAverage);
		cout << "The new average - " << data.getAverage() << '\n';
	
	}
	else errorMessage();
}
void Node::changeTelephoneHelper(const char* name)
{

	if (findHelper(name))
	{
		cout << "Enter new telephone number for this student:";
		unsigned long newTelephoneNumber;
		cin >> newTelephoneNumber;
		data.setNumber(newTelephoneNumber);
		
	}
}

Node* Node::deleteHelper(Student s, Node* parent)
{
	if (compareNames(s.getName(), data.getName()) == 0)
	{

		if (right != nullptr && left != nullptr)
		{
			data = right->minName();
			return right->deleteHelper(this->data, this);
		}

		else if (parent->left == this)
		{
			if (left != nullptr) parent->left = left;
			else parent->left = NULL;
			return this;
		}
		else if (parent->right == this)
		{
			if(left!=nullptr) parent->right = left;
			else parent->right = NULL;
			return this;
		}
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
	if (left)
	{
		left->printHelper();

	}
	cout << data << '\n';
	if (right)
	{
		right->printHelper();
	}
}

Student Node::minName()
{
	if (left == nullptr) return data;
	else return left->minName();
}

void BinaryTree::addHelper1(Node* s, Student p)
{
	if (strcmp(s->data.getName(), p.getName())) 
	{
		if (compareNames(p.getName(), s->data.getName()) < 0) {
			if (s->left == nullptr) s->left = new Node(p);
			else addHelper1(s->left, p);
		}
		else if (compareNames(p.getName(), s->data.getName()) > 0)
		{
			if (s->right == nullptr) s->right = new Node(p);
			else addHelper1(s->right, p);
		}
	}
	else
		cout << "There's a student with this name!" << p.getName() << '\n';
}

bool BinaryTree::isEmpty() {
	return root == nullptr;
}

void BinaryTree::addStudent(Student s)
{

	if (root == nullptr) root = new Node(s);
	else {
		root->addHelper(s);
	}
	
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
		if (compareNames(s.getName(), root->data.getName()) == 0)
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


