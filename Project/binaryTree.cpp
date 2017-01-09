#include "binaryTree.h"
#include <iostream>
#include <fstream>
using std::ofstream;
using std::cout;
using std::cin;

/*void Node::addHelper(Student s)
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
*/
/*bool Node::findHelper(const char* name)
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
}*/

/*double Node::findAverageHelper(const char * name)
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
*/
ofstream studentsFile("students.txt");

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
			if (left != nullptr) parent->right = left;
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



Student Node::minName()
{
	if (left == nullptr) return data;
	else return left->minName();
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

Student* BinaryTree::findHelper(Node* s, const char *name)
{
	if (compareNames(name, s->data.getName()) == 0) return &s->data;
	else if (compareNames(name, s->data.getName()) < 0)
	{
		if (s->left == nullptr) {
			return nullptr;
		}
		else {
			return findHelper(s->left, name);
		}
	}
	else if (compareNames(name, s->data.getName()) > 0)
	{
		if (s->right == nullptr) {
			return nullptr;
		}
		else {
			return findHelper(s->right, name);
		}
	}
	return nullptr;

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
Student BinaryTree::find(Node *s, const char *name)
{
	if (compareNames(name, s->data.getName()) == 0) return s->data;
	else if (compareNames(name, s->data.getName()) < 0)
	{
		if ((s)->left == nullptr) {
			return Student();
		}
		else {
			return find(s->left, name);
		}
	}
	else if (compareNames(name, s->data.getName()) > 0)
	{
		if (s->right == nullptr) {
			return Student();
		}
		else {
			return find(s->right, name);
		}
	}
	return Student();
}

void BinaryTree::avh(Node* s, const char* name, Student &st)
{
	if (compareNames(name, s->data.getName()) == 0)
	{
		st = *findHelper(s, name);
		cout << "The old average - " << (*findHelper(s, name)).getAverage() << '\n';
		cout << "Enter new average for this student:" << '\n';
		double newAverage;

		cin >> newAverage;
		st.setAverage(newAverage);

		cout << "The new average - " << (*findHelper(s, name)).getAverage() << '\n';

	}
	else if (compareNames(name, s->data.getName()) < 0)
	{
		if (s->left == nullptr) {
			errorMessage();
		}
		else {
			avh(s->left, name, st);
		}
	}
	else if (compareNames(name, s->data.getName()) > 0)
	{
		if (s->right == nullptr) {
			errorMessage();
		}
		else {
			avh(s->right, name, st);

		}
	}
}



Node * BinaryTree::minNameStudent(Node* s)
{
	if (s->left == nullptr) return s;
	else return minNameStudent(s->left);
}

double BinaryTree::findAverage(const char* name)
{

	if (isEmpty()) return 0;
	if (findHelper(root, name)) return (*findHelper(root, name)).getAverage();
	else errorMessage();
	return 0;
}

unsigned long BinaryTree::findTelephoneNumber(const char* name)
{
	if (isEmpty()) return 0;
	if (findHelper(root, name)) return (*findHelper(root, name)).getNumber();
	else errorMessage();
	return 0;
}

bool BinaryTree::isEmpty() {
	return root == nullptr;
}

/*void BinaryTree::addStudent(Student s)
{

	if (root == nullptr) root = new Node(s);
	else {
		root->addHelper(s);
	}

}*/



/*unsigned long BinaryTree::findTelephoneNumber(const char* name)
{
	if (root == nullptr)
	{
		return 0;
	}
	else return root->findTelephoneNumberHelper(name);
}
*/
//todo - asking if this is the right solving
void BinaryTree::changeAverage(const char* name)
{
	//avh(root, name);
	//(*(Student*)(findHelper(root, name)));
/*if (isEmpty()) errorMessage();
	if ((findHelper(root, name))) {

		cout << "The old average - " << (*findHelper(root, name)).getAverage() << '\n';
		cout << "Enter new average for this student:" << '\n';
		double newAverage;
		cin >> newAverage;


		//find(root, name) = *new Student();
		(*findHelper(root, name)).setAverage(newAverage);

		cout << "The new average - " << (*findHelper(root, name)).getAverage() << '\n';
		//findH(root, name) = *findHelper(root, name);
	}
	else errorMessage()
	*/
	avh(root, name, root->data);

}


void BinaryTree::changeTelephoneNumber(const char* name)
{

	if (isEmpty()) errorMessage();
	if (findHelper(root, name)) {

		cout << "The old telephone number - " << (*(findHelper(root, name))).getNumber() << '\n';
		cout << "Enter new telephone number for this student:" << '\n';
		unsigned long newNumber;

		cin >> newNumber;

		(*(findHelper(root, name))).setNumber(newNumber);

		cout << "The new telephone number - " << (*(findHelper(root, name))).getNumber() << '\n';


	}
	else errorMessage();
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
	else helperPrint(root, cout);
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
	/*while (saver->right != nullptr)
	{
	saver = saver->right;
	//}
	delete n;
	return true;

}
*/
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

void BinaryTree::writeStudentsInFile()
{
	if(root == nullptr) cout << "Error! Empty database!" << '\n';
	else helperPrint(root, studentsFile);

}


