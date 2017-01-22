int findName(BTreeNode*, const char*);
	void removeFromLeaf(BTreeNode*,int);
	void removeFromNotLeaf(BTreeNode*, int);
	void borrowFromPrevious(BTreeNode*, int);
	void borrowFromNext(BTreeNode*, int);
	void merge(BTreeNode*, int index);
	void fill(BTreeNode*, int index);
	void deleteHelper(BTreeNode*, const char* name);
  	void deleteStudent(const char* name);

  
int BTree::findName(BTreeNode* node, const char* name)
{
	int index = 0;
	while (index < node->allStudents.size() && compareNames(name, node->allStudents[index].getName())>0)
	{
		++index;
	}
	return index;
}

void BTree::removeFromLeaf(BTreeNode* node, int index)
{
	for (int i = index + 1; i < node->allStudents.size(); ++i)
	{
		node->allStudents.insert(node->allStudents.begin() + (i - 1), node->allStudents[i]);
		node->allStudents.erase(node->allStudents.begin() + (i));
	}
	
		node->allStudents.pop_back();

	
///	node->allStudents.pop_back();
}

void BTree::removeFromNotLeaf(BTreeNode* node, int index)
{
	Student s = node->allStudents[index];
	if (node->children[index]->allStudents.size() >= minimumDegree)
	{
		Student pred = getPredecessor(node,index);
		node->allStudents.insert(node->allStudents.begin() + (index), pred);
		deleteHelper(node->children[index], pred.getName());
	}
	else if (node->children[index + 1]->allStudents.size() >= minimumDegree)
	{
		Student succ = getSuccessor(node, index);
		node->allStudents.insert(node->allStudents.begin() + (index), succ);
		deleteHelper(node->children[index+1], succ.getName());

	}
	else
	{
		merge(node, index);
		deleteHelper(node->children[index], s.getName());
	}
}

void BTree::borrowFromPrevious(BTreeNode* node, int index)
{
	BTreeNode* child = node->children[index];
	BTreeNode* sibling = node->children[index - 1];

	for (int i = child->allStudents.size()-1; i >= 0; i--)
	{
		child->allStudents.insert(child->allStudents.begin() + (i + 1), child->allStudents[i]);
		child->allStudents.erase(child->allStudents.begin() + i);
	}
	if (child->children.size() != 0)
	{
		for (int i = child->allStudents.size(); i >= 0; i--)
		{
			child->children.insert(child->children.begin() + (i + 1), child->children[i]);
			child->children.erase(child->children.begin() + i);
		}
	}

	child->allStudents.insert(child->allStudents.begin(), node->allStudents[index - 1]);
	//child->allStudents.front() = node->allStudents[index - 1];

	if (node->children.size() != 0)
	{
		child->children.insert(child->children.begin(), sibling->children[sibling->allStudents.size()]);
		//child->children.front() = sibling->children[sibling->allStudents.size()];
	}
	node->allStudents.insert(node->allStudents.begin() + (index - 1), sibling->allStudents[sibling->allStudents.size() - 1]);
	//sibling->allStudents.erase(sibling->allStudents.)
	
	//sibling->allStudents.pop_back();
	for (int i = sibling->allStudents.size(); i >= sibling->minimumDegree; i--)
	{
		sibling->allStudents.pop_back();

	}
}

void BTree::borrowFromNext(BTreeNode* node, int index)
{
	BTreeNode* child = node->children[index];
	BTreeNode* sibling = node->children[index + 1];

	//child->allStudents[child->allStudents.size()] = node->allStudents[index];
	child->allStudents.insert(child->allStudents.begin() + (child->allStudents.size()), node->allStudents[index]);
	//child->allStudents.push_back(node->allStudents[index]);
	//?
	if (child->children.size() != 0)
	{
		//child->children[child->allStudents.size()+1] = sibling->children.front();
		//child->children.push_back(sibling->children.front());
		child->children.insert(child->children.begin() + ((child->children.size())+1), sibling->children.front());


	}
	//node->allStudents[index] = sibling->allStudents.front();
	node->allStudents.insert(node->allStudents.begin() + (index), sibling->allStudents.front());
	//node->allStudents.push_back(sibling->allStudents.front());
	for (int i = 1; i < sibling->allStudents.size(); i++)
	{
		sibling->allStudents.insert(sibling->allStudents.begin() + (i - 1), sibling->allStudents[i]);
		sibling->allStudents.erase(sibling->allStudents.begin() + (i));
	}
	if (sibling->children.size() != 0)
	{
		for (int i = 1; i <= sibling->allStudents.size(); i++)
		{
			sibling->children.insert(sibling->children.begin() + (i - 1), sibling->children[i]);
			sibling->children.erase(sibling->children.begin() + (i));
		}
	}
	for (int i = sibling->allStudents.size(); i >= sibling->minimumDegree; i--)
	{
		sibling->allStudents.pop_back();

	}
	
}

void BTree::merge(BTreeNode* node, int index)
{
	BTreeNode* child = node->children[index];
	BTreeNode* sibling = node->children[index + 1];

	child->allStudents.insert(child->allStudents.begin() + (minimumDegree - 1), node->allStudents[index]);

	for (int i = 0; i < sibling->allStudents.size(); i++)
	{
		child->allStudents.insert(child->allStudents.begin() + (i + node->minimumDegree), sibling->allStudents[i]);
		//child->allStudents.erase(child->allStudents.begin() + i);
	}

	if (child->children.size() != 0)
	{
		for (int i = 0; i <= sibling->allStudents.size(); i++)
		{
			child->children.insert(child->children.begin() + (i + node->minimumDegree), sibling->children[i]);
			//child->allStudents.erase(child->allStudents.begin() + i);

		}
	}
	for (int i = index + 1; i < node->allStudents.size(); i++)
	{
		node->allStudents.insert(node->allStudents.begin() + (i - 1), node->allStudents[i]);
		node->allStudents.erase(node->allStudents.begin() + (i));
	}
	for (int i = index + 2; i <= node->allStudents.size(); i++)
	{
		node->children.insert(node->children.begin() + (i - 1), node->children[i]);
		node->children.erase(node->children.begin() + i);
	}
	for (int i = node->allStudents.size(); i >=node->minimumDegree; i--)
	{
		node->allStudents.pop_back();

	}
	//node->allStudents.pop_back();
	delete (sibling);
}

void BTree::fill(BTreeNode* node,int index)
{
	if (index != 0 && node->children[index - 1]->allStudents.size() >=node-> minimumDegree)
	{
		borrowFromPrevious(node, index);
	}
	else if (index != node->allStudents.size() && node->children[index + 1]->allStudents.size() >= node->minimumDegree)
	{
		borrowFromNext(node, index);
	}
	else
	{
		if (index != node->allStudents.size()) merge(node, index);
		else merge(node, index - 1);
		
	}
}

void BTree::deleteHelper(BTreeNode* node, const char * name)
{
	int index = findName(node, name);
	if (index < node->allStudents.size() && compareNames(node->allStudents[index].getName(), name) == 0)
	{
		if (node->children.size() == 0)
		{
			removeFromLeaf(node, index);
		}
		else removeFromNotLeaf(node, index);
	}
	else
	{
		if (node->children.size() == 0) errorMessage();
		bool flag = (index == node->allStudents.size());
		if (node->children[index]->allStudents.size() < node->minimumDegree)
			fill(node, index);
		if (flag && index > node->allStudents.size())
		{
			deleteHelper(node->children[index - 1], name);
		}
		else deleteHelper(node->children[index], name);
	}
}

void BTree::deleteStudent(const char * name)
{
	if (isEmpty()) cout << "Empty database!" << '\n';
	deleteHelper(root, name);
	if (root->allStudents.size() == 0)
	{
		BTreeNode* temp = root;
		if (root->children.size() == 0) root = nullptr;
		else root = root->children.front();
		delete temp;
	}
}
