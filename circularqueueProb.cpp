#include <iostream>
using namespace std;

class circularque {
	int *arr;
	int front, rear, size, capaci;

public:
	circularque(int capacity) 
    {
		capaci = capacity;
		arr = new int[capacity];
		front = 0;
		rear = -1;
		size = 0;
	}

	bool isempty() 
	{
		if (size == 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
		
	}

	bool isfull() {
		if (size == capaci)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void enqueue(int val) {
		if (isfull()) 
		{
			cout << "queue is full " << endl;
			
		}
		rear++;
		rear = rear%capaci;
		arr[rear] = val;
		size++;//using size to check current value in arr:)
	}

	int dequeue() {
		if (isempty()) 
		{
			cout << "queue is empty " <<endl;
			
		}
		int val1 = arr[front];
		front++;
		front = front%capaci;
		size--;
		return val1;
	}

	int getSize()
	{  
		return size;
	}
};

int josephus(int n, int k) {
	circularque q(n);

	
	for (int i = 1; i <=n; i++)
	{
		q.enqueue(i);
	}

	
	while (q.getSize() > 1) 
	{  
		
		for (int i = 0; i < k-1 ; i++) {
			int pers = q.dequeue();
			q.enqueue(pers);
		}
		
		q.dequeue();
	}

	return q.dequeue();
}

int main() {
	int n, k;
	cout << "enter number of people "<<endl;
	cin >> n;
	cout << "Enter the value of k "<<endl;
	cin >> k;

	int lastPerson = josephus(n, k);
	cout << "The position of the last remaining person is " << lastPerson << endl;
	system("pause");
	return 0;
}
