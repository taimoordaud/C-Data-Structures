#pragma once
#include<iostream>
using namespace std;

template<class T>
class CircularQueue {
protected:
	T* arr;
	int front, rear, capacity, count;
public:
	CircularQueue()
	{
		arr = nullptr;
		front = -1; rear = -1; capacity = 0, count = 0;
	}
	CircularQueue(int size)
	{
		capacity = size;
		arr = new T[size];
		front = -1; rear = -1, count = 0;
	}
	CircularQueue(CircularQueue& obj)
	{
		capacity = obj.capacity;
		front = obj.front; rear = obj.rear;
		for (int i = 0; i < capacity; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	virtual void Enqueue(T) = 0;
	virtual T Dequeue() = 0;
	virtual bool isfull() = 0;
	virtual bool isempty() = 0;
	virtual void display() = 0;
	virtual ~CircularQueue()
	{
		delete[] arr;
		capacity = 0; front = 0; rear = 0;
	}
};

template<class T>
class MyCircularQueue :public CircularQueue<T>
{
public:
	MyCircularQueue()
	{

	}
	MyCircularQueue(int s) :CircularQueue<T>(s)
	{

	}
	void Enqueue(T val)
	{
		if (isfull())
		{
			cout << "Queue is Already Full\n";
		}
		if (CircularQueue<T> :: front == -1) 
		{
			CircularQueue<T> :: front = 0;
			CircularQueue<T> :: rear = 0;
		}
		else 
		{
			if (CircularQueue<T> :: rear == CircularQueue<T> :: capacity - 1)
				CircularQueue<T> :: rear = 0;
			else
				CircularQueue<T> ::rear = CircularQueue<T> :: rear + 1;
		}
		CircularQueue<T> :: arr[CircularQueue<T> :: rear] = val;
		CircularQueue<T> :: count++;
	}
	T Dequeue()
	{
		if (isempty())
			cout << "Queue is Already Empty\n";
		T temp = CircularQueue<T> :: arr[CircularQueue<T> :: front];

		if (CircularQueue<T> :: front == CircularQueue<T> :: rear) 
		{
			CircularQueue<T> :: front = -1;
			CircularQueue<T> :: rear = -1;
			CircularQueue<T> ::count--;
		}
		else 
		{
			if (CircularQueue<T> ::front == CircularQueue<T> ::capacity - 1)
			{
				CircularQueue<T> ::front = 0;
				CircularQueue<T> ::count--;
			}
			else
			{
				CircularQueue<T> ::front = CircularQueue<T> ::front + 1;
				CircularQueue<T> ::count--;
			}
		}
		return temp;
	}
	bool isfull()
	{
		if ((CircularQueue<T> :: front == 0 && CircularQueue<T> :: rear == CircularQueue<T> :: capacity - 1) || (CircularQueue<T> :: front == CircularQueue<T> :: rear + 1))
			return true;
		else
			return false;
	}
	bool isempty()
	{
		if (CircularQueue<T> :: front == -1)
			return true;
		else
			return false;
	}
	void display()
	{
		int f = CircularQueue<T> :: front, r = CircularQueue<T> :: rear;
		if (isempty())
		{
			cout << "Queue is Empty\n";
		}
		
		if (f <= r) 
		{
			while (f <= r) {
				cout << CircularQueue<T> :: arr[f] << " ";
				f++;
			}
		}
		else {
			while (f <= CircularQueue<T> :: capacity - 1) {
				cout << CircularQueue<T> :: arr[f] << " ";
				f++;
			}
			f = 0;
			while (f <= r) {
				cout << CircularQueue<T> :: arr[f] << " ";
				f++;
			}
		}
		cout << endl;
	}
	int size()
	{
		return CircularQueue<T> ::count;
	}
};