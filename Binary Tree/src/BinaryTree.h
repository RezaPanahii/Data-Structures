#pragma once
#include <iostream>
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
