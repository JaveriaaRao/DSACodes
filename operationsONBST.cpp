#include<iostream>
#include<queue>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;

	node(int d)
	{
		data = d;
		left = nullptr;
		right = nullptr;
	}
};
node* insert(node* root, int d)
{
	if (root == NULL)
	{
		root = new node(d);
		return root;
	}

	if (root->data < d)
	{
		root->right = insert(root->right, d);
	}
	else
	{
		root->left = insert(root->left, d);
	}
	return root;

}
void takeinput(node* &root)
{
	int data;
	cin >> data;
	while (data != -1)
	{
		root=insert(root, data);
		cin >> data;
	}
}
void print(node* &root)
{
	queue<node*>q;
	q.push(root);
	q.push(NULL);
   while (!q.empty())
	{
	   node* temp = q.front();
	   q.pop();
	   if (temp == NULL)
	   {
		   cout << endl;
		   if (!q.empty())
		   {
			   q.push(NULL);
		   }
	   }
	   else
	   {

		   cout << temp->data << " ";
		   if (temp->left)
		   {
			   q.push(temp->left);
		   }
		   if (temp->right)
		   {
			   q.push(temp->right);
		   }
	   }
   }
	
}
bool searchBST(node* &root, int &key)
{
	if (root == NULL)
	{
		return false;
	}
	if (root->data == key)
	{
		return true;
	}
	else if (root->data > key)
	{
		return searchBST(root->left, key);
	}
	else
	{
		return searchBST(root->right, key);
	}
	return true;
}
void inorder(node* &root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	cout << root->data<<" ";
	inorder(root->right);
	
}
void preorder(node* &root)
{
	if (root == NULL)
	{
		return;
	}
	
	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);

}
void postorder(node* &root)
{
	if (root == NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";

}
//find max
node* minimum(node* root)
{
	/*if (root == NULL)
	{
		return;
    }*/
	node* temp = root;
	while (temp->left!=NULL)
	{
		temp = temp->left;
	}
	return temp;

}
node* maximum(node* root)
{
	node* temp = root;
	while (temp->right != NULL)
	{
		temp = temp->right;
	}
	return temp;
}
node* deletenode(node* root, int val)
{
	if (root == NULL)
	{
		return;
	}
	//one child 
	//node have left child 
	if (root->left != NULL&&root->right==NULL)
	{
		node* temp = root->left;
		delete temp;
		return temp;
	}
	//node have right child 
	if (root->left == NULL&&root->right != NULL)
	{
		node* temp = root->right;
		delete temp;
		return temp;

	}
	//have two childs
	if (root->left != NULL&&root->right != NULL)
	{
		int min = minimum(root->right)->data;
		root->right = deletenode(root->right,min);
		return root;

	}
}
int main()
{
	node* root = nullptr;
	cout << "create BST " << endl;
	takeinput(root);
	cout << "printing BST " << endl;
	print(root);
	cout << "inorder " << endl;
	inorder(root);
	cout << endl;
	cout << "preorder " << endl;
	preorder(root);
	cout << endl;
	cout << "postorder " << endl;
	postorder(root);
	cout << endl;
	int key;
	cout << "enter key to search " << endl;
	cin >> key;
	if (searchBST(root, key))
	{
		cout <<key << " node is found " << endl;
	}
	else
	{
		cout << key << " node is not found " << endl;
	}
	node* min= minimum(root);
	cout << "minimum value is " << min->data << endl;
	node* max = maximum(root);
	cout << "maximum value is " << max->data << endl;
	system("pause");
	return 0;
}