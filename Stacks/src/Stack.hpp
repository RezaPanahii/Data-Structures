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
};