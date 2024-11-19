#include<iostream>
using namespace std;
template<typename t>
class queue{
	t* arr;
	int size;
	int rear;
	int front;
public:
	queue(int size)
	{
		this->size = size;
		arr = new t[size];
		rear = 0;
		front = 0;

	}
	bool empty()
	{
		if (front == rear)
		{
			return true;
		}
		return false;
	}
	bool isfull()
	{
		if (rear == size)
		{
			return true;
		}
		return false;
	}
	int top()
	{
		if (!empty())
		{
			return arr[front];
		}
		else
		{
			return -1;
		}
	}
	void enque(t val)
	{
		if (!isfull())
		{
			
			arr[rear] = val;
			rear++;
			if (rear == front)
			{
				rear = 0;
				front = 0;
			}
			
		}
		else
		{
			cout << "queue is full " << endl;
		}

	}
	void deque()
	{
		if (!empty())
		{
			arr[front] = -1;
			front++;
			if (rear == front)
			{
				rear = 0;
				front = 0;
			}
		}
		else
		{
			cout << "queue is empty " << endl;
		}
	
	}
	void show()
	{
		cout << "elements in queue are " << endl;
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] <<" "<< endl;
		}
	}
	~queue()
	{
		delete[]arr;
	}
};
int main()
{
	queue<int>obj(5);
	obj.empty();
	obj.enque(1);
	obj.deque();
	obj.enque(2);
	cout << "top is " << obj.top() << endl;
	obj.enque(3);
	obj.enque(4);
	obj.enque(5);
	obj.show();
	obj.enque(6);
	obj.deque();
	obj.show();
	obj.enque(49);
	obj.show();
	system("pause");
	return 0;
}