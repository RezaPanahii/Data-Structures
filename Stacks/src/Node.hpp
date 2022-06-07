template <typename T>
class Node
{
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

	bool operator==(const Node& node) const
	{
		return (this->data == node.data and this->next == node.next);
	}

	bool operator!=(const Node& node) const
	{
		return !(*this == node);
	}
};