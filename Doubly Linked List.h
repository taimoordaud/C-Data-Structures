#pragma once
#include<iostream>
using namespace std;

class Node 
{
public:
	int data;
	Node* next;
	Node* prev;
};

class DoublyLL
{
	Node* head;

	Node* createNode(int val)
	{
		Node* temp = new Node;
		temp->data = val;
		temp->next = nullptr;
		temp->prev = nullptr;
		return temp;
	}
public:
	DoublyLL()
	{
		head = nullptr;
	}
	void insertAtEnd(int val)
	{
		Node* newNode = createNode(val);
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			Node* itr = head;
			while (itr->next != nullptr)
				itr = itr->next;
			newNode->prev = itr;
			itr->next = newNode;
		}
	}

	void insertAtFront(int val)
	{
		Node* newNode = createNode(val);
		if (head == nullptr)
		{
			head = newNode;
		}
		else
		{
			newNode->next = head;
			head = newNode;
		}
	}

	void DeleteFromFront()
	{
		if (head == nullptr)
			cout << "List is Already Empty!\n";
		else
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			if (head != nullptr)
				head->prev = nullptr;
		}
	}
	void DeleteFromEnd()
	{
		if (head == nullptr)
			cout << "List is Already Empty!\n";
		else if (head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			Node* itr = head;
			while (itr->next->next != nullptr)
				itr = itr->next;
			Node* temp = itr->next;
			itr->next = nullptr;
			delete temp;
		}
	}
	Node* getHead()
	{
		return head;
	}
	void Display()
	{
		Node* itr = head;
		while (itr != nullptr)
		{
			cout << itr->data << " ";
			itr = itr->next;
		}
	}
};
