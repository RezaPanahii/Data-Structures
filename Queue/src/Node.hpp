#pragma once
#include "Queue.hpp"

template <typename T>
class Node
{
	template<typename R>
	friend class Queue;

	T data;
	Node<T>* next;

public:
	Node(const T& data)
	{
		this->data = data;
		next = nullptr;
	}

	~Node()
	{
		if (next != nullptr)
			delete next;
	}

	T& getData() const
	{
		return data;
	}
};