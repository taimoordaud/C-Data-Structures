#pragma once
#include<iostream>
using namespace std;

template<class T>
class Stack
{
protected:
	T* arr;
	int top;
	int size;
public:
	Stack()
	{
		arr = nullptr;
		top = 0;
		size = 0;
	}
	Stack(int s)
	{
		size = s;
		arr = new T[s];
		top = 0;
	}
	Stack(Stack& obj)
	{
		size = obj.size;
		top = obj.top;
		for (int i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	virtual void push(T) = 0;
	virtual void pop() = 0;
	virtual bool isfull() = 0;
	virtual bool isempty() = 0;
	virtual void display() = 0;
	virtual T top()=0;
	virtual ~Stack()
	{
		delete[] arr;
		size = 0;
		top = 0;
	}

};

template<class T>
class MyStack :public Stack<T>
{
public:
	MyStack()
	{

	}
	MyStack(int s) :Stack<T>(s)
	{

	}
	void push(T value)
	{
		if (!isfull())
		{
			Stack<T>::arr[Stack<T>::top] = value;
			Stack<T>::top++;
		}
		else
		{
			cout << "stack is full\n";
		}
	}

	void pop()
	{
		if (!isempty())
		{
			T temp = Stack<T>::arr[Stack<T>::top - 1];
			Stack<T>::top--;
		}
		else
		{
			cout << "stack is empty\n";
		}
	}
	T top()
	{
		return Stack<T>::arr[Stack<T>::top - 1];
	}
	bool isfull()
	{
		return(Stack<T>::top == Stack<T>::size);
	}

	bool isempty()
	{
		return(Stack<T>::size == 0);
	}

	void display()
	{
		for (int i = 0; i < Stack<T>::top; i++)
		{
			cout << Stack<T>::arr[i] << " ";
		}
	}

};

