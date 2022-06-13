#pragma once
#include <iostream>
#include <queue>
#include "Node.h"

Node* buildTree()
{
	int data;
	std::cin >> data;
	
	if (data == -1)
	{
		return nullptr;
	}
	Node* node = new Node(data);
	node->left = buildTree();
	node->right = buildTree();
	return node;
}

void printPreorder(Node* root)
{
	if (root == nullptr)
	{
		return;
	}
	std::cout << root->data << " ";
	printPreorder(root->left);
	printPreorder(root->right);
}

void printInorder(Node* root)
{
	if (root == nullptr)
		return;

	printInorder(root->left);
	std::cout << root->data << " ";
	printInorder(root->right);
}

void printPostorder(Node* root)
{
	if (root == nullptr)
		return;
	
	printPostorder(root->left);
	printPostorder(root->right);
	std::cout << root->data << " ";
}

void levelOrderPrint(Node* root)
{
	std::queue<Node*> q;
	
	q.push(root);
	q.push(nullptr);

	while(!q.empty())
	{
		Node* front = q.front();
		if (!front)
		{
			std::cout << std::endl;
			q.pop();
			if (!q.empty())
				q.push(nullptr);
		}
		else
		{
			std::cout << front->data << " ";
			q.pop();
			if (front->left)
				q.push(front->left);
			if (front->right)
				q.push(front->right);
		}
	}
	return;
}

Node* levelOrderBuild()
{
	int data;
	std::cin >> data;

	Node* root = new Node(data);

	std::queue<Node*> q;
	q.push(root);

	while(!q.empty())
	{
		Node* front = q.front();
		q.pop();

		int left_child_value;
		int right_child_value;
		std::cin >> left_child_value;
		std::cin >> right_child_value;

		if (left_child_value != -1)
		{
			front->left = new Node(left_child_value);
			q.push(front->left);
		}
		if (right_child_value != -1)
		{
			front->right = new Node(right_child_value);
			q.push(front->right);
		}
	}
	return root;
}

int height(Node* root)
{
    if (root == nullptr)
        return 0;

    int left_height = height(root->left);
    int right_height = height(root->right);

    return std::max(left_height, right_height) + 1;
}

int diameter(Node* root)
{
	if (root == nullptr)
		return 0;

	// if diameter goes through root
	int d1 = height(root->left) + height(root->right);
	// left side of the root
	int d2 = diameter(root->left);
	// right side of the root
	int d3 = diameter(root->right);

	return std::max(d1, std::max(d2,d3));
}