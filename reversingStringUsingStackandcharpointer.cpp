#include<iostream>
#include<stack>
using namespace std;
char* reverse(char* arr, int size)
{
	stack<char>st;
	char* a = new char[size+1];
	for (int i = 0; arr[i] != '\0'; i++)
	{
		st.push(arr[i]);
	}
	int i = 0;
	while (!st.empty())
	{
		a[i] = st.top();
		st.pop();
		i++;

	}
	a[i] = '\0';
	return a;

}
int main()
{
	int size = 10;
	char* arr = new char[size];
	cout << "enter any string " << endl;
	cin >> arr;
	cout << "array is " <<arr<< endl;
	char* stt = reverse(arr, size);
	cout << "so reversed string is " << stt << endl; 
	system("pause");
	return 0;
}