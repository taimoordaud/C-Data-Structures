#pragma once
#include<iostream>
using namespace std;

template<class T>
class Queue {
protected:
	T* arr;
	int capacity;
	int rear;
public:
	Queue()
	{
		cout << "Enter Size of Queue: ";
		cin >> capacity;
		arr = new T[capacity];
		rear = 0;
	}
	Queue(int size)
	{
		capacity = size;
		arr = new T[capacity];
		rear = 0;
	}
	bool full()
	{
		if (capacity == rear)
			return true;
		else
			return false;
	}
	bool empty()
	{
		if (rear == 0)
			return true;
		else
			return false;
	}
	void Enqueue(T val)
	{
		if (full())
			cout << "Queue is already full" << endl;
		else
		{
			
			arr[rear] = val;
			rear++;
		}
	}
	T Dequeue()
	{
		if (empty()) {
			cout << "Queue is already empty" << endl;
		}
		else
		{
			T temp = arr[0];
			rearrange();
			rear--;
			return temp;
		}
	}
	void rearrange()
	{
		for (int i = 0; i < rear; i++)
		{
			arr[i] = arr[i + 1];
		}
	}
	int size()
	{
		return rear;
	}
	void display()
	{
		cout << "Queue: ";
		for(int i = 0; i < rear; i++)
		{
			cout << arr[i] << " ";
		}
	}
};