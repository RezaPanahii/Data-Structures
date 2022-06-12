#pragma once

class Node
{
public:
	int data;
	Node* right;
	Node* left;

	Node(int data)
	{
		this->data = data;
		left = right = nullptr;
	}
};
