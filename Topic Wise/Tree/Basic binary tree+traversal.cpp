#include<bits/stdc++.h>
using namespace std;

struct tree
{
	int data;
	tree *left, *right;
};

tree* newNode(int key)
{
	tree* node = new tree;
	node->data = key;
	node->left = node->right = NULL;

	return node;
}

void inorder(tree* root)
{
	if (root == NULL)
		return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}

void preorder(tree* root)
{
	if (root == NULL)
		return;
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

void postorder(tree* root)
{
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}

int main()
{
	tree *root = NULL;

	root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	//root->right->left = newNode(6);
	//root->right->right = newNode(7);
	cout << "Inorder: ";
	inorder(root);
	cout << endl;
	cout << "Preorder: ";
	preorder(root);
	cout << endl;
	cout << "Postorder: ";
	postorder(root);
	cout << endl;
}