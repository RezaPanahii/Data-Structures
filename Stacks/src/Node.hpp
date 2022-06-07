template <typename T>
class Node
{
	T data;
	Node<T>* next;

public:
	Node(T& data)
	{
		this->data = data;
		next = nullptr;
	}

	~Node()
	{
		if (next != nullptr)
			delete next;
	}

	T& getData()
	{
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