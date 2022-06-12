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