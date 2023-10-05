#include<assert.h>
#include<stdio.h>
#include<stdlib.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL");
		return;
	}
	printf("%d ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL");
		return;
	}
	BinaryTreeInOrder(root->left);
	printf("%d ", root->data);
	BinaryTreeInOrder(root->right);
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL");
		return;
	}
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%d ", root->data);
}

BTNode* BinaryTreeCreate( )