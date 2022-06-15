#pragma once
#include<iostream>
using namespace std;

template<class T>
class Node {
public:
	T data;
	Node<T>* next;
	Node<T>* pre;
};

template<class T>
class DoubleList {
protected:
    Node<T>* head;
    Node<T>* tail;
public:
	DoubleList()
	{
        head = nullptr;
        tail = nullptr;
	}
	void insert(T val)
	{
        Node<T>* temp = new Node<T>;

        temp->data = val;
        temp->next = nullptr;
        temp->pre = nullptr;

        if (head == nullptr)
        {
            head = temp;
            head->next =head;
            head->pre = head;
            tail = head;
        }
        else
        {
            tail->next = temp;
            temp->pre = tail;
            temp->next = head;
            head->pre = temp;
            tail = temp;
        }
	}

    T front()
    {
        if (head != nullptr)
            return head->data;
        else
        {
            cout << "List is Empty\n";
            return 0;
        }
    }
    T rear()
    {
        if (head != nullptr)
            return tail->data;
        else
        {
            cout << "List is Empty\n";
            return 0;
        }
    }

    T delet()
    {
        Node<T>* temp = head;

        if (head == nullptr) 
        {
            cout << "List is Empty\n";
            return 0;
        }
        else 
        {
            head = head->next;
            tail->next = head;
            head->pre = tail;

            return temp->data;
        }
    }

    void display()
    {
        Node<T>* itr = head;
        if (head != nullptr)
        {
            do
            {
                cout << itr->data << " ";
                itr = itr->next;
            } while (itr != head);
        }
        else {
            cout << "List is Empty\n";
        }
    }
};
