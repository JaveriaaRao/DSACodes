#include<iostream>
#include<queue>
using namespace std;
class node{
public:
	int data;
	node* left;
	node* right;

	node( int d)
	{
		data = d;
		left = nullptr;
		right = nullptr;
	}
};
node* buildTree(node* root)
{
	cout << "enter the data " << endl;
	int data;
	cin >> data;
	root = new node(data);
	if (data == -1)
	{
		return NULL;
	}
	cout << "enter data for inserting in left of " <<data<< endl;
	root->left = buildTree(root->left);
	cout << "enter data for inserting in right of  "<<data << endl;
	root->right = buildTree(root->right);
	return root;

}
void levelordertriversal(node* &root)
{
	queue<node*>q1;
	q1.push(root);
	q1.push(NULL);
	while (!q1.empty())
	{
		node* temp = q1.front();
		q1.pop();
		if (temp == NULL)
		{
			cout << endl;
			if (!q1.empty())
			{
				q1.push(NULL);
			}
		}
		else
		{
			cout << temp->data << " ";
			if (temp->left)
			{
				q1.push(temp->left);
			}
			if (temp->right)
			{
				q1.push(temp->right);
			}
		}


	}
}
void inorder(node* root)
{
	if (root == NULL)
	{
		return;
	}
	inorder(root->left);
	cout << root->data<<" ";
	inorder(root->right);


}
void preorder(node* root)
{
	if (root == NULL)
	{
		return;
	}
	cout << root->data << " ";
	preorder(root->left);
	
	preorder(root->right);
}
void postorder(node* root)
{
	if (root == NULL)
	{
		return;
	}
	
	postorder(root->left);
	postorder(root->right);
	cout << root->data << " ";
}
void levelOrder(node* &root)
{
	queue<node*>q1;
	int data;
	cout << "enter data  for root " << endl;
	cin >> data;
	root = new node(data);
	q1.push(root);
	while (!q1.empty())
	{
		node* temp = q1.front();
		q1.pop();
		int leftval;
		cout << "enter value at left of " << temp->data << endl;
		cin >> leftval;

		if (leftval != -1)
		{
			temp->left = new node(leftval);
			q1.push(temp->left);
		}
		int rightval;
		cout << "enter value at right of " << temp->data << endl;
		cin >> rightval;
		if (rightval != -1)
		{
			temp->right = new node(rightval);
			q1.push(temp->right);
		}
		
	}



}

int main()
{
	node* root = nullptr;
	/*root = buildTree(root);*/
	//1,3,7,-1,11,-1,-1,5,17,-1,-1,-1
	/*levelordertriversal(root);*/

	/*inorder(root);
	cout << endl;
	preorder(root);
	cout << endl;
	postorder(root);
	cout << endl;*/
	levelOrder(root);
	levelordertriversal(root);
	system("pause");
	return 0;
}