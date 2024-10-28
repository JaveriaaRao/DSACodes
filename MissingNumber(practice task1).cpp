#include<iostream>
using namespace std;

void input(int arr[], int size)
{
	cout << "enter the "<<size<<" values " << endl;
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
void sorted(int arr[], int size)
{
	cout << "sorted array is " << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
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
void missing(int arr[], int size)
{
	
	for(int i = 0; i < size-1; i++)
	{
		if (arr[i + 1] != arr[i]+1 )
		{
			cout << "Missing " << arr[i]+ 1<<" ";
		}
	}
	cout << endl;
}
int main()
{
	const int size = 5;
	int arr[size];
	input(arr, size);
	sorted(arr, size);
	missing(arr,size);

	system("pause");
	return 0;
}