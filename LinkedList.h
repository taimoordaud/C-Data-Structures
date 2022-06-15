#pragma once
#include<iostream>
using namespace std;

template<class T>
class Node
{
public:
	T data;
	Node* next;
	Node()
	{
		data = NULL;
		next = nullptr;
	}
};

template<class T>
class LinkedList : public Node<T> {
protected:
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
	virtual void insertAtFront(T) = 0;
	virtual void insertAtEnd(T) = 0;
	virtual T removeFromFront() = 0;
	virtual T removeFromEnd() = 0;
};

template<class T>
class MyLinkedList : public LinkedList<T> {
public:
	MyLinkedList()
	{
		LinkedList<T>::head = nullptr;
		LinkedList<T>::tail = nullptr;
	}
	void insertAtFront(T val)
	{
		Node<T>* temp = new Node<T>;
		temp->data = val;
		temp->next = LinkedList<T>::head;
		LinkedList<T>::head = temp;
	}
	void insertAtEnd(T val)
	{
		Node<T>* temp = new Node<T>;
		temp->data = val;
		temp->next = LinkedList<T>::head;

		if (LinkedList<T>::head == nullptr)
			LinkedList<T>::head = temp;
		else
		{
			Node<T>* itr = LinkedList<T>::head;
			while (itr->next != nullptr)
				itr = itr->next;
			itr->next = temp;
		}
	}
	T removeFromFront()
	{
		if (LinkedList<T>::head == nullptr)
		{
			cout << "List is Empty!\n";
			return -1;
		}

		else
		{
			Node<T>* temp = LinkedList<T>::head;
			LinkedList<T>::head = LinkedList<T>::head->next;
			return temp->data;
		}
	}
	T removeFromEnd()
	{
		if (LinkedList<T>::head == nullptr)
		{
			cout << "List is empty \n";
			return -1;
		}

		else if (LinkedList<T>::head->next == nullptr)
		{
			T temp = LinkedList<T>::head->data;
			delete LinkedList<T>::head;
			LinkedList<T>::head = nullptr;
			return temp;
		}
		else
		{
			T temp = LinkedList<T>::head->data;
			Node<T>* itr = LinkedList<T>::head->next;
			Node<T>* pre = LinkedList<T>::head;
			while (itr->next != nullptr)
			{
				itr = itr->next;
				pre = pre->next;
			}
			temp = itr->data;
			delete itr;
			pre->next = nullptr;
			return temp;
		}
	}
	T front()
	{
		if (LinkedList<T>::head != nullptr)
			return LinkedList<T>::head->data;
		else
			cout << "List is empty\n";
	}
	T back()
	{
		if (LinkedList<T>::head != nullptr)
		{
			Node<T>* itr = LinkedList<T>::head->next;
			Node<T>* pre = LinkedList<T>::head;
			while (itr->next != nullptr)
			{
				itr = itr->next;
				pre = pre->next;
			}
			return itr->data;
		}
		else
			cout << "List is empty\n";
	}
	bool empty()
	{
		if (LinkedList<T>::head == nullptr)
			return true;
		else
			return false;
	}
	int size()
	{
		int count = 1;
		Node<T>* itr = LinkedList<T>::head;
		while (itr->next != nullptr)
		{
			itr = itr->next;
			count++;
		}
		return count;
	}
	void display()
	{
		Node<T>* itr = LinkedList<T>::head;
		while (itr != nullptr)
		{
			cout << itr->data << " ";
			itr = itr->next;
		}
	}
};
