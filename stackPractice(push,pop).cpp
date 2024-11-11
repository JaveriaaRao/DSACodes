#include<iostream>
#include<stack>
using namespace std;
class Stack{
private:
	int* arr;
	int size;
	int top;
public:
	Stack()
	{
		int size = 0;
		arr = nullptr;
		int top = -1;

	}
	Stack(int size)
	{
		this->size = size;
		top = -1;
		arr = new int[size];
	}
	void push(int num)
	{
		if (top == size-1)
		{
			cout << "stack is overflow " << endl;

		}
		else
		{
			top++;
			arr[top] = num;
			
		}
	}
	void pop()
	{
		if (top == -1)
		{
			cout << "stack is empty " << endl;
		}
		else
		{
			top--;
		}
	}
	bool empty()
	{
		if (top == -1)
		{
			cout << "stack is empty " << 1 << endl;
			return 1;
		}
		else
		{
			cout << "stack is not empty " << 0 << endl;
			return 0;
		}
	}
	bool isfull()
	{
		if (top >= size)
		{
			cout << "stack is full " << 1 << endl;
			return 1;
		}
		else{
			cout << "stack is not full " <<0<<endl;
			return 0;
		}
	}
	int Top()
	{
		if (top == -1)
		{
			cout << "no element to pop " << endl;
			return -1;
		}
		else
		{
			return arr[top];
		}

	}
	void print()
	{
		cout << "Array is " << endl;
		for (int i = 0; i <= top; i++)
		{
			cout  << arr[i] << " ";
		}
		cout << endl;
	}
	void Sort()
	{
		cout << "sorted Elements are " << endl;
		for (int i = 0; i <=top; i++)
		{
			for (int j = i+1; j <=top; j++)
			{
				if (arr[i]>arr[j])
				{

					int temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			}
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	void reverse()
	{
		for (int i = 0; i <= top / 2; i++)
		{
			int temp = arr[i];
			arr[i] = arr[top - i];
			arr[top - i] = temp;

		}
		
	}
	void average()
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
		{
			sum = sum + arr[i];
		}
		int ave = sum /size;
		cout << "average is " << ave << endl;
	}
	void maximum()
	{
		int max=INT_MIN;
		for (int i = 0; i <=top; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		cout << "maximum number in stack is " << max << endl;
	}
	void minimum()
	{
		int min = INT_MAX;
		for (int i = 0; i <= top; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}
		cout << "minimum number in stack is " << min << endl;
	}
	void mid()
	{
		if (top == -1)
		{
			cout << "stack is empty" << endl;
		}
		int midd = size / 2;
		cout << "mid of array is " << endl;
		cout << arr[midd] << " " << endl;
		
		
	}
	void removeLargest()
	{
		int max = INT_MIN;
		int maxindex = -1;
		for (int i = 0; i <= top; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
				maxindex = i;
			}
		}
		cout << "maximum number in stack is " << max << endl;
		for (int i = maxindex; i < top; i++)
		{
			arr[i] = arr[i + 1];
		}
		
		top--;
	}
	void deleteSamenum() {
		int count = 0; 
		bool counted[5] = { false }; 
		int originalTop = top; 

		
		for (int i = 0; i <= originalTop; i++) {
			
			if (!counted[i]) {
				count++; 
				for (int j = i + 1; j <= originalTop; j++) {
					
					if (arr[i] == arr[j]) {
						counted[j] = true; 
					}
				}
			}
		}

		top = -1; 
		for (int i = 0; i <= originalTop; i++) {
			if (!counted[i]) {
				push(arr[i]); 
			}
		}

		cout << "Duplicates removed. Unique elements in stack are: ";
		for (int i = 0; i <= top; i++) {
			cout << arr[i] << " "; 
		}
		cout << endl;
	}
	~Stack()
	{
		delete[]arr;
	}

};
int main()
{
	Stack obj(5);
	obj.push(2);
	obj.push(3);
	obj.push(4);
	obj.push(5);
	obj.push(9);
	obj.print();
	obj.push(6);
	obj.print();
	obj.pop();
	obj.pop();
	obj.print();
	obj.isfull();
	obj.empty();
	obj.push(1);
	obj.push(10);
	obj.print();
	obj.Sort( );
	obj.print();
	obj.reverse();
	obj.print();
	obj.average();
	obj.maximum();
	obj.reverse();
	obj.print();
	obj.pop();
	obj.pop();
	obj.push(100);
	obj.push(20);
	obj.maximum();
	obj.minimum();
	obj.print();
	obj.mid();
	obj.removeLargest();
	obj.print();
	obj.push(2);
	obj.print();
	obj.deleteSamenum();
	system("pause");
	return 0;
}