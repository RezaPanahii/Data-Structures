#pragma once
#include <iostream>
#include "Node.hpp"

template <typename T>
class Queue
{
	Node<T>* Head;
	Node<T>* Tail;

public:
	Queue()
	{
		Head = nullptr;
		Tail = nullptr;
	}
	~Queue()
	{
		if (Head != nullptr)
		{
			delete Head;
		}
	}

	void print()
	{
		Node<T>* temp = Head;
		while (temp != nullptr)
		{
			std::cout << temp->data << std::endl;
			temp = temp->next;
		}
	}

	void push(const T& value)
	{
		Node<T>* node = new Node<T>(value);
		if (Head == nullptr)
		{
			Head = Tail = node;
		}
		else
		{
			Tail->next = node;
			Tail = node;
		}
	}

	void pop()
	{
		if (Head != nullptr)
		{
			if (Head == Tail)
				Tail == nullptr;
			Node<T>* temp = Head;
			Head = Head->next;

			temp->next = nullptr;
			delete temp;
		}
	}

	const T& front()
	{
		return Head->data;
	}
};