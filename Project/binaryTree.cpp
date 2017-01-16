#include "binaryTree.h"
#include <iostream>
#include <fstream>
using std::ofstream;
using std::cout;
using std::cin;

ofstream studentsFile("students.txt");

void Node::setLeft(Node * _left)
{
	this->left = _left;
}
void Node::setRight(Node* _right)
{
	this->right = _right;
}
Node * Node::getLeft()
{
	return left;
}

Node * Node::getRight()
{
	return right;
}

void BinaryTree::addHelper(Node* s, Student p)
{
	if (strcmp(s->data.getName(), p.getName()))
	{
		if (compareNames(p.getName(), s->data.getName()) < 0) {
			if (s->left == nullptr) s->left = new Node(p);
			else addHelper(s->left, p);
		}
		else if (compareNames(p.getName(), s->data.getName()) > 0)
		{
			if (s->right == nullptr) s->right = new Node(p);
			else addHelper(s->right, p);
		}
	}
	else
		cout << "There's a student with this name!" << p.getName() << '\n';
}

Node* BinaryTree::findH(Node* s, const char *name)
{
	if (compareNames(name, s->data.getName()) == 0) return s;
	else if (compareNames(name, s->data.getName()) < 0)
	{
		if (s->left == nullptr) {
			return nullptr;
		}
		else {
			return findH(s->left, name);
		}
	}
	else if (compareNames(name, s->data.getName()) > 0)
	{
		if (s->right == nullptr) {
			return nullptr;
		}
		else {
			return findH(s->right, name);
		}
	}
	return nullptr;

}

Student BinaryTree::minNameStudent(Node* s)
{

	if (s->left == nullptr) return s->data;
	else return minNameStudent(s->left);

}

double BinaryTree::findAverage(const char* name)
{

	if (isEmpty()) return 0;
	if (findH(root, name)) return (findH(root, name)->data).getAverage();
	else errorMessage();
	return 0;
}

unsigned long BinaryTree::findTelephoneNumber(const char* name)
{
	if (isEmpty()) return 0;
	if (findH(root, name)) return (findH(root, name)->data).getNumber();
	else errorMessage();
	return 0;
}

bool BinaryTree::isEmpty() {
	return root == nullptr;
}

void BinaryTree::changeAverage(const char* name)
{
	if (isEmpty()) errorMessage();
	if (findH(root, name)) {

		cout << "The old average - " << (findH(root, name)->data).getAverage() << '\n';
		cout << "Enter new average for this student:" << '\n';
		double newAverage;

		cin >> newAverage;

		(findH(root, name)->data).setAverage(newAverage);

		cout << "The new average - " << (findH(root, name)->data).getAverage() << '\n';


	}
	else errorMessage();

}


void BinaryTree::changeTelephoneNumber(const char* name)
{

	if (isEmpty()) errorMessage();
	if (findH(root, name)) {

		cout << "The old telephone number - " << (findH(root, name)->data).getNumber() << '\n';
		cout << "Enter new telephone number for this student:" << '\n';
		unsigned long newNumber;

		cin >> newNumber;

		(findH(root, name)->data).setNumber(newNumber);

		cout << "The new telephone number - " << (findH(root, name)->data).getNumber() << '\n';


	}
	else errorMessage();
}


void BinaryTree::print()
{
	if (root == nullptr) cout << "Error! Empty database!" << '\n';
	else helperPrint(root, cout);
}
void BinaryTree::helperPrint(Node*s, ostream &o)
{

	if (s->left != nullptr)
	{
		helperPrint(s->left, o);

	}
	o << s->data << '\n';

	if (s->right != nullptr)
	{
		helperPrint(s->right, o);
	}
}

Node* BinaryTree::deleteHelper(Student s, Node* parent, Node* r)
{
	if (compareNames(s.getName(), r->data.getName()) == 0)
	{

		if (r->right != nullptr && r->left != nullptr)
		{
			r->data = minNameStudent(r->right);
			return deleteHelper(r->data, r, r->right);
		}

		else if (parent->left == r)
		{
			if (r->left != nullptr) parent->left = r->left;
			else parent->left = NULL;
			return r;
		}
		else if (parent->right == r)
		{
			if (r->left != nullptr) parent->right = r->left;
			else parent->right = NULL;
			return r;
		}
	}

	else if (compareNames(s.getName(), r->data.getName()) < 0)
	{
		if (r->left != nullptr)
		{
			return deleteHelper(s, r, r->left);
		}
		else return nullptr;
	}
	else if (compareNames(s.getName(), r->data.getName()) > 0)
	{
		if (r->right != nullptr)
		{
			return deleteHelper(s, r, r->right);
		}
		else return nullptr;
	}
	return r;
}

void BinaryTree::writeStudentsInFile()
{
	if (root == nullptr) cout << "Error! Empty database!" << '\n';
	else helperPrint(root, studentsFile);

}

bool BinaryTree::deleteStudent(const char* name)
{
	Student s;
	if (findH(root, name))
	{
		s = findH(root, name)->data;
	}
	else
	{
		errorMessage();
		return false;
	}
	
	if (isEmpty()) return false;
	else
	{
		if (compareNames(s.getName(), root->data.getName()) == 0)
		{
			Node newNode;
			newNode.setLeft(root);
			Node *removedNode = deleteHelper(s, &newNode, root);
			//root = newNode.getLeft();
			if (removedNode != nullptr)
			{
				delete removedNode;
				return true;
			}
			else return false;
		}
		else {
			Node *removedNode = deleteHelper(s, nullptr, root);
			if (removedNode != nullptr)
			{
				delete removedNode;
				return true;
			}
			else return false;
		}
	}
}

/*bool BinaryTree::delSt(const char* name, Node* s)
{
	//if (isEmpty()) return false;
	Node *deleter = findH(s, name);
	cout << deleter->data << '\n';
	if (deleter == nullptr) return false;
	if (deleter->left == nullptr)
	{
		Node* copy = deleter;
		cout << copy->data;
		deleter = deleter->right;
		delete copy;
		return true;
	}
	if (deleter->right == nullptr)
	{
		Node* copy = deleter;
		cout << copy->data;
		deleter = deleter->left;
		delete copy;
		return true;
	}
	Node *saver = minNameStudent(deleter->right);
	cout << saver->data;
	deleter->data = saver->data;
	//deleter = saver;
	Node* n = saver;
	cout << n->data;

	saver = saver->right;

	delete n;
	return true;
}*/

