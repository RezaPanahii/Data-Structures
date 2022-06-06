#pragma once
#include <iostream>
#include "Node.hpp"

template <typename T>
class List
{
	Node<T>* Head;
	Node<T>* Tail;

public:

	// constructors
	List()
	{
		Head = nullptr;
		Tail = nullptr;
	}


	~List()
	{
		if (Head != nullptr)
		{
			delete Head;
			Head = nullptr;
		}
	}

	// print a list to the console
	std::ostream operator<<(const std::ostream& out)
	{
		Node<T>* ptr = Head;
		while (ptr != nullptr)
		{
			out << ptr->value << " ";
			ptr = ptr->next;
		}
		return out;
	}

	Node<T>* begin() const
	{
		return Head;
	}

	Node<T>* end() const
	{
		return Tail;
	}

	Node<T>* findNode(const T& value) const
	{
		Node<T>* ptr = Head;
		while (ptr != nullptr)
		{
			if (ptr->data == value) {
				return ptr;
			}
			ptr = ptr->next;
		}

		return ptr;
	}

	void print() const
	{
		Node<T>* temp = Head;
		while (temp != nullptr)
		{
			std::cout << temp->data << "->";
			temp = temp->next;
		}
		std::cout << std::endl;
	}

	// push back function
	Node<T>* pushBack(const T& value)
	{
		if (Head == nullptr)
		{
			Node<T>* node = new Node<T>(value);
			Head = Tail = node;
			return node;
		}
		else
		{
			Node<T>* node = new Node<T>(value);
			Tail->next = node;
			Tail = node;
			return node;
		}

	}

	Node<T>* pushFront(const T& value)
	{
		if (Head == nullptr)
		{
			Node<T>* node = new Node<T>(value);
			Head = Tail = node;
			return node;
		}
		else
		{
			Node<T>* node = new Node<T>(value);
			node->next = Head;
			Head = node;
			return node;
		}
	}

	Node<T>* insert(T value, int index)
	{
		if (index == 0)
		{
			return pushFront(value);
		}

		Node<T>* temp = Head;
		for (size_t i = 1; i < index; i++)
		{
			temp = temp->next;
		}
		Node<T>* node = new Node<T>(value);
		node->next = temp->next;
		temp->next = node;
		if (Tail == temp)
		{
			Tail = node;
		}

		return node;
	}

	void remove(int index)
	{
		Node<T>* temp;
		if (index == 0)
		{
			temp = Head->next;
			Head = temp;
			return;
		}

		temp = Head;
		for (size_t i = 1; i < index; i++)
		{
			temp = temp->next;
		}

		if (temp->next == Tail)
		{
			Tail = temp;
		}
		temp->next = temp->next->next;
	}

	//bool search(int value, Node<T>* head = Head)
	//{
	//	//Node<T>* temp = Head;

	//	if (head == nullptr)
	//	{
	//		return false;
	//	}
	//	
	//	if (value == head->data)
	//	{
	//		return true;
	//	}
	//	else
	//	{
	//		head = head->next;
	//		return search(head->data, head);
	//	}
	//	
	//}
};
