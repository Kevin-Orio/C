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

BTNode* BinaryTreeCreate(BTDataType* array, int index)
{
	//static int index;ʹ�������ļ���������������˵�����ǲ��еģ���Ϊ��̬�洢��=���������ܳ��������ڴ�����һ����ʱindexδ���㣨�����˳����򣩡�
	if (array[index] == '#')
	{
		index++;
		return;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	if (root == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	root->data = array[index++];
	root->left = BinaryTreeCreate(array, index);
	root->right = BinaryTreeCreate(array, index);
	return root;
}

BTNode* BuyBTNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		perror("malloc");
		exit(-1);
	}
	newnode->data = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}

//�����
int BinaryTreeSize(BTNode* root)
{
	return (root == NULL) ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//Ҷ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root = NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->left);
}

int BinaryLevelKSize(BTNode* root, int k)
{
	for (int i = 1; i < k; i++)
	{

	}
	if (root != NULL)
	{
		return 1;
	}
	return BinaryLevelKSize(root->left, k-1) + BinaryLevelKSize(root->right, k-1);
}
