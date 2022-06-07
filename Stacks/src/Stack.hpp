#pragma once
#include <vector>
#include "Node.hpp"

template <typename T>
class stack
{
	Node<T>* Head;

public:
	stack()
	{
		Head = nullptr;
	}

	~stack()
	{
		if (Head != nullptr)
			delete Head;
	}

	void print()
	{
		Node<T>* temp = Head;
		while (temp != nullptr)
		{
			std::cout << temp->data << "->";
			temp = temp->next;
		}
		std::cout << std::endl;
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
};