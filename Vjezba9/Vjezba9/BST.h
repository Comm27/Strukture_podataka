#pragma once
typedef struct _BST
{
	int x;
	struct _BST *left;
	struct _BST *right;
}BST;

BST* CreateNode();

BST* Find(BST *node, int value);
BST* FindMin(BST *node);
BST* FindMax(BST *node);

BST* Insert(BST *node, int x);
BST* DeleteA(BST *node, int x);
BST* Delete(BST *node, int x);

int Print(BST *node);