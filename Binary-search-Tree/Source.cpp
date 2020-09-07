#include <iostream>
#include <vector>
#include <cstdlib>
#include <cassert>

struct Node
{
	Node *left, *right;
	int data;

	Node(int d)
		: data{ d }, left{ nullptr }, right{ nullptr }
	{}
	~Node()
	{
		delete left;
		delete right;
	}
};


struct BinarySearchTree
{
	Node *root;

	BinarySearchTree()
		: root{ nullptr }
	{};
	~BinarySearchTree() { delete root; }

	Node *insertNode(Node *start, int value);
	Node *search(int value);
};


Node *BinarySearchTree::insertNode(Node *start, int value)
{
	if (start == nullptr)
	{
		std::cout << "X\n";
		return new Node(value);
	}
	else if (value < start->data)
	{
		std::cout << 'L';
		start->left = insertNode(start->left, value);
	}
	else if (value > start->data)
	{
		std::cout << 'R';
		start->right = insertNode(start->right, value);
	}
	else
	{
		assert(false);
	}
	return start;
}

Node *BinarySearchTree::search(int value)
{
	Node *temp = root;
	while (temp != nullptr)
	{
		if (temp->data == value)
		{
			std::cout << "X\n";
			return temp;
		}
		else if (value < temp->data)
		{
			std::cout << 'L';
			temp = temp->left;
		}
		else
		{
			std::cout << 'R';
			temp = temp->right;
		}
	}
	return nullptr;
}


int main(int argc, char **argv)
{
	BinarySearchTree bst;

	std::srand(1);
	std::vector<int> vec;
	int data;

	for (int i = 0; i < 10; ++i)
	{
		data = rand() % 1000;
		vec.push_back(data);
		std::cout << "Inserting node with data: " << data << '\n';
		bst.root = bst.insertNode(bst.root, data);
	}

	std::cout << "\n\n";
	for (int i : vec)
	{
		std::cout << "Searching for the node with data: " << i << '\n';
		bst.search(i);
	}

	return 0;
}