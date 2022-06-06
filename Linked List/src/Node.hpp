#pragma once
#include "List.hpp"

template <typename T>
class Node
{
	template<typename R>
	friend class List;

	T data;
	Node* next;

public:

	Node(T data)
	{
		this->data = data;
		next = nullptr;
	}

	~Node()
	{
		if (next != nullptr)
		{
			delete next;
		}
	}

	T getData() const {
		return data;
	}

	bool operator==(const Node& node)
	{
		return (this->data == node.data and this->next == node.next);
	}

	bool operator!=(const Node& node)
	{
		return !(*this == node);
	}
};
