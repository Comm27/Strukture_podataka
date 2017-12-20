#include "BST.h"
#include <stdlib.h>
#include "../../libs/mylibs/ErrorHandler.h"

BST* CreateNode()
{
	BST *node = (BST*)malloc(sizeof(BST));
	if (node == NULL)
	{
		ErrorHandler(ALLOC_FAILED, "CreateNode");
		return NULL;
	}
	node->left = NULL;
	node->right = NULL;

	return node;
}

BST* Find(BST * node, int value)
{
	if (node == NULL)
		return NULL;
	else if (node->x > value)
		Find(node->left, value);
	else if (node->x < value)
		Find(node->right, value);
	else
		return node;
}

BST* FindMin(BST * node)
{
	if (node->left == NULL)
		return node;
	FindMin(node->left);
}

BST* FindMax(BST * node)
{
	if (node->right == NULL)
		return node;
	FindMax(node->right);
}

BST* Insert(BST *node, int x)
{
	if (node == NULL)
	{
		node = CreateNode();
		if (node == NULL)
			return NULL;
		node->x = x;
	}
	else if (node->x > x)
		node->left = Insert(node->left, x);
	else
		node->right = Insert(node->right, x);

	return node;
}

BST* DeleteA(BST * node, int x)
{
	BST *tempNode = Find(node, x);
	if (tempNode == NULL)
	{
		printf("No element found!\n");
		return NULL;
	}
	else if (tempNode->left && tempNode->right)
	{
		tempNode->x = FindMax(tempNode->left)->x;
		tempNode->left = Delete(tempNode->left, tempNode->x);
	}
	else if (tempNode->left)
	{
		tempNode->x = tempNode->left->x;
		tempNode->left = Delete(tempNode->left, tempNode->x);
	}
	else if (tempNode->right)
	{
		tempNode->x = tempNode->right->x;
		tempNode->right = Delete(tempNode->right, tempNode->x);
	}
	else
	{
		free(tempNode);
		return NULL;
	}
}

BST * Delete(BST * node, int x)
{
	BST *tempNode = NULL;
	if (node == NULL)
	{
		printf("Element not found!\n");
		return NULL;
	}
	if (x < node->x)
		node->left = Delete(node->left, x);
	else if (x > node->x)
		node->right = Delete(node->right, x);
	else
	{
		if (node->left && node->right)
		{
			tempNode = FindMax(node->left);
			node->x = tempNode->x;
			node->left = Delete(node->left, node->x);
		}
		else if (node->left)
		{
			node->x = node->left->x;
			node->left = Delete(node->left, node->x);
		}
		else if (node->right)
		{
			node->x = node->right->x;
			node->right = Delete(node->right, node->x);
		}
		else
		{
			free(node);
			node = NULL;
		}
	}
	return node;
}

int Print(BST * node)
{
	if (node == NULL)
		return 0;
	printf("%d\n", node->x);
	Print(node->left);
	Print(node->right);

	return 0;
}