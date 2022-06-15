#pragma once
#include<iostream>
using namespace std;


class Node {
public:
	int data;
	Node* left;
	Node* right;
};

class BST {
	Node* root;
	Node* insert(int val, Node* itr)
	{
		if (itr == nullptr)
		{
			Node* newNode = new Node;
			newNode->data = val;
			newNode->right = newNode->left = nullptr;
			return newNode;
		}
		else
		{
			if (itr->data < val)
				itr->right = insert(val, itr->right);
			else
				itr->left = insert(val, itr->left);
		}
		return itr;
	}
	void InOrder(Node* itr)
	{
		if (itr != nullptr)
		{
			InOrder(itr->left);
			cout << itr->data << " ";
			InOrder(itr->right);
		}
	}
	void PreOrder(Node* itr)
	{
		if (itr != nullptr)
		{
			cout << itr->data;
			PreOrder(itr->left);
			PreOrder(itr->right);
		}
	}
	void PostOrder(Node* itr)
	{
		if (itr != nullptr)
		{
			PostOrder(itr->left);
			PostOrder(itr->right);
			cout << itr->data;
		}
	}
	bool searchIN(int val, Node* itr)
	{
		bool temp = false;
		if (itr != nullptr)
		{
			if (val == itr->data)
			{
				temp = true;
			}
			else
			{
				if (itr->data < val)
					temp = searchIN(val, itr->right);
				else
					temp = searchIN(val, itr->left);
			}
		}
		return temp;
	}
	Node* findlast(Node* root)
	{
		Node* itr = root;
		while (itr && itr->left != nullptr)
			itr = itr->left;
		return itr;
	}
	Node* DeleteFun(int val, Node* root)
	{
		if (root == nullptr)
		{
			cout << "Not Found\n";
			return nullptr;
		}
		else if (val < root->data)
			root->left = DeleteFun(val, root->left);
		else if (val > root->data)
			root->right = DeleteFun(val, root->right);
		else
		{
			if (root->left == nullptr && root->right == nullptr)//no child
			{
				delete root;
				root = nullptr;
			}
			else if (root->left == nullptr)
			{
				Node* temp = root->right;
				delete root;
				root = temp;
			}
			else if (root->right == nullptr)
			{
				Node* temp = root->left;
				delete root;
				root = temp;
			}
			else
			{
				Node* temp = findlast(root->right);
				root->data = temp->data;
				root->right = DeleteFun(root->data, root->right);
			}
		}
		return root;
	}
public:


	BST()
	{
		root = nullptr;
	}

	void insert(int val)
	{
		root = insert(val, root);
	}

	void displayInOrder()
	{
		InOrder(root);
	}

	void displayPreOrder()
	{
		PreOrder(root);
	}

	void displayPostOrder()
	{
		PostOrder(root);
	}

	void search(int val)
	{
		bool isFound = searchIN(val, root);
		if (isFound)
			cout << val << " is Found\n";
		else
			cout << val << " not Found\n";
	}

	void Delete(int val)
	{
		if (root != nullptr)
			root = DeleteFun(val, root);
		else
			cout << "Tree is Empty\n";
	}

	Node* getroot()
	{
		return root;
	}

};