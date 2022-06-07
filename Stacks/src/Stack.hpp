#pragma once
#include <vector>
#include "Node.hpp"

template <typename T>
class Stack
{
	Node<T>* Head;

public:
	Stack()
	{
		Head = nullptr;
	}

	~Stack()
	{
		if (Head != nullptr)
			delete Head;
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
			Head = node;
		else
		{
			node->next = Head;
			Head = node;
		}
	}

	void pop()
	{
		Node<T>* temp = Head;
		Head = Head->next;

		temp->next = nullptr;
		delete temp;
	}
};