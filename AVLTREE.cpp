#include<iostream>
#include<algorithm>
using namespace std;
class node{
public:
	int data, height;
	node* left, *right;

	node(int value)
	{
		data = value;
		left = nullptr;
		right = nullptr;
		height = 1;
	}
};
int getheight(node* root)
{
	if (root == NULL)
	{
		return 0;
	}
	return root->height;
}
int getbalance(node* root)
{
	return getheight (root->left )- getheight(root->right);
}
node* rightrotation(node* root)
{
	node* child = root->left;
	node* childright = child->right;
	child->right = root;
	root->left = childright;

	//height
	root->height = 1 + max(getheight(root->left), getheight(root->right));
	child->height = 1 + max(getheight(child->left), getheight(child->right));
	return child;
}
node* leftrotation(node* root)
{
	node* child = root->right;
	node* childleft = child->left;
	child->left = root;
	root->right = childleft;

	root->height = 1 + max(getheight(root->left), getheight(root->right));
	child->height = 1 + max(getheight(child->left), getheight(child->right));
	return child;
}

node* insert(node* root, int key)
{
	if (root==NULL)
	{
		root = new node(key);
		return root;
	}
	//exist
	if (root->data > key)
	{
		root->left=insert(root->left, key);
	}
	else if(root->data < key)
	{
		root->right = insert(root->right, key);
	}
	else
	{
		return root;//duplicate not allowed
	}

	root->height = 1 + max(getheight(root->left), getheight(root->right));


	//balacing 

	int balance = getbalance(root);

	//left left case 
	if (balance > 1 && key < root->left->data)
	{
		return rightrotation(root);
	}

	//right right case
	else if (balance<-1 && key>root->right->data)
	{
		return leftrotation(root);
	}

	//left right case

	else if (balance > 1 && key > root->right->data)
	{
		root->left= leftrotation(root->left);
		return rightrotation(root);
	}
	//right left case
	else if (balance < -1 && key < root->left->data)
	{
		root->right= rightrotation(root->right);
		return leftrotation(root);
	}
	//no unbalancing
	else
	{
		return root;
	}
}
void inorder(node* &root)
{
	
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	cout << root->data <<" ";
	inorder(root->right);
}
int main()
{
	//duplicates are not allowed
	node *root = NULL;

	root=insert(root, 10);
	root=insert(root, 20);
	root=insert(root, 30);
	root=insert(root, 50);
	root=insert(root, 70);
	root=insert(root, 10);

	cout << "inorder " << endl;
	inorder(root);
	system("pause");
	return 0;
}