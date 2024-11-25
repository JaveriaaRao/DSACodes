#include<iostream>
using namespace std;
class node{

	int data;
	node* next;
public:
	node(int data)
	{
		this->data = data;
		this->next = NULL;

	}
	int getData() {
		return data;
	}

	node* getNext() {
		return next;
	}

};
int main()
{
	node* node1 = new node(10);
	cout << node1->getData() << endl;
	cout << node1->getNext() << endl;

	system("pause");
    return 0;
}