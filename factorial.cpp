#include<iostream>
using namespace std;
int factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	int prevfact = factorial(n - 1);
	return n*prevfact;
}
int main()
{
	int val;
	cout << "enter value " << endl;
	cin >> val;
	int result = factorial(val);
	cout << "The factorial of recursive function is " << result<<endl;

	system("pause");
	return 0;
}