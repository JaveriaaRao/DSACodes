#include<iostream>
using namespace std;

void input(int arr[], int size)
{
	cout << "enter the " << size << " values " << endl;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	cout << "entered values are " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void Frequency(int arr[], int size)
{
	bool counted[5] = { false };

	for (int i = 0; i < size; i++)
	{
		if (!counted[i]) 
		{
			int count = 1;

			for (int j = i + 1; j < size; j++)
			{
				if (arr[i] == arr[j]) 
				{
					count++;
					counted[j] = true; 
				}
			}
			cout << arr[i] << " frequency is " << count << endl; 
		}
	}
}
int main()
{
	const int size = 5;
	int arr[size];
	input(arr, size);
	Frequency(arr, size);
	system("pause");
	return 0;
}