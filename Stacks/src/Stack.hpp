#include <vector>

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
	}
};