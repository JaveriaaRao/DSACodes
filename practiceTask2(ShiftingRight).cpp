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
void shiftingRight(int arr[], int size)
{
	cout << "values after right shift " << endl;
	for (int i = 0; i < size-1; i++)
	{
		arr[i] = arr[i + 1];
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Array after putting last value at first position " << endl;
	for (int i = 0; i < size-1; i++)
	{
		arr[0] = arr[size - 1];
		cout << arr[i] << " ";
	}

	cout << endl;
}
int main()
{
	const int size = 5;
	int arr[size];
	input(arr, size);
	shiftingRight(arr, size);
	system("pause");
	return 0;
}