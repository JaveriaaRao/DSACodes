#include<iostream>
#include<string>
#include<stack>
using namespace std;
int prec(char ch)
{
	if (ch == '^')
	{
		return 3;
	}
	else if (ch == '/' || ch == '*')
	{
		return 2;
	}
	else if (ch == '+' || ch == '-')
	{
		return 1;
	}
	return -1;
}
void reverseString(string &infix) {
	int n = infix.length();
	for (int i = 0; i < n / 2; i++) {
		char temp = infix[i];
		infix[i] = infix[n - i - 1];
		infix[n - i - 1] = temp;
	}
}

string infixTopostfix(string s)
{
	stack<char>st;
	string result;
	for (int i = 0; i < s.length(); i++)
	{
		int str = s[i];
		if ((str >= 'a'&&str <= 'z') || (str >= 'A'&&str <= 'Z') || (str >= '0'&&str <= '9'))
		{
			result += str;
		}
		else if (str == '(')
		{
			st.push(str);
		}
		else if (str == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				result +=st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while ((!st.empty() && prec(str) < prec(st.top())) || (!st.empty() && prec(str) == prec(st.top())))
			{
				result += st.top();
				st.pop();
			}
			st.push(str);
		}
	}
	while (!st.empty())
	{
		result += st.top();
		st.pop();
	}
	return result;
}
string infixToprefix(string s)
{
	stack<char>st;
	string result;
	reverseString(s);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') s[i] = ')';
		else if (s[i] == ')') s[i] = '(';
	}
	for (int i = 0; i < s.length(); i++)
	{
		int str = s[i];
		if ((str >= 'a'&&str <= 'z') || (str >= 'A'&&str <= 'Z') || (str >= '0'&&str <= '9'))
		{
			result += str;
		}
		else if (str == '(')
		{
			st.push(str);
		}
		else if (str == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				result += st.top();
				st.pop();
			}
			st.pop();
		}
		else{
			while ((!st.empty() && prec(str) < prec(st.top())) || (!st.empty() && prec(str) == prec(st.top())))
			{
				result += st.top();
				st.pop();
			}
			st.push(str);
		}
	}
	while (!st.empty())
	{
		result += st.top();
		st.pop();
	}
	reverseString(result);
	return result;
}
int power(int &val1, int &val2)
{
	int res=1;
	for (int i = 0; i < val2; i++)
	{
		res = res*val1;
	}
	return res;
}
int postfixEval(string s)
{
	stack<int>st;
	/*int result;*/
	for (int i = 0; i < s.length(); i++)
	{
		if ((s[i] >= '0'&&s[i] <= '9') || (s[i] >= 'a'&&s[i] <= 'z') || (s[i] >= 'A'&&s[i] <= 'Z'))
		{
			int value = s[i] - '0';
			st.push(value);
		}
		else
		{
			int val2=st.top();
			st.pop();
			 int val1=st.top();
			st.pop();
			int ans;
			if (s[i] == '*')
			{
				ans = val1*val2;
				st.push(ans);
			}
			else if (s[i] == '/')
			{
				ans = val1/val2;
				st.push(ans);
				
			}
			else if (s[i] == '-')
			{
				ans = val1 - val2;
				st.push(ans);
			}
			else if (s[i] == '+')
			{
				ans = val1 +val2;
				st.push(ans);
			}
			else if (s[i] == '^')
			{
				ans = power(val1 , val2);
				st.push(ans);
			}
			
		
		}
		
	}
	return st.top();
}
bool operand(char c)
{
	if ((c >= '0'&&c <= '9') || (c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
	{
		return true;
	}
	return false;
}
string postfixtoinfix(string s)
{
	stack<string>st;
	for (int i = 0; i < s.length(); i++)
	{
		if (operand(s[i]))
		{
			string ope(1, s[i]);
			st.push(ope);
		}
		else
		{
			string val2 = st.top();
			st.pop();
			string val1 = st.top();
			st.pop();
			string expression = "(" + val1 + s[i] + val2 + ")";
			st.push(expression);
			
		}
	}
	return st.top();
}
bool opera(char ch)
{
	if (ch == '+' || ch == '-' || ch == '/' || ch == '*' || ch == '^')
	{
		return true;

	}
	return false;
}
string prefixtoinfix(string s)
{
	stack<string>st;
	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (opera(s[i]))
		{
			string val1 = st.top();
			st.pop();
			string val2 = st.top();
			st.pop();
			string experession = "(" + val1 +s[i] + val2 + ")";
			st.push(experession);


		}
		else
		{
			string op(string(1, s[i]));
			st.push(op);
		}
	}
	return st.top();
}
int main()
{
   char contichoice;
   do{
	      int choice;
	
		while (true)
		{


			cout << "______________:) MENU :)_______________" << endl;
			cout << "|press 1 to Convert Infix to Postfix   |" << endl;
			cout << "|press 2 to Convert Infix to Prefix     |" << endl;
			cout << "|press 3 to Evaluate Postfix Expression |" << endl;
			cout << "|press 4 to Convert Postfix to Infix    |" << endl;
			cout << "|press 5 to Convert Prefix to Infix     |" << endl;
			cout << "|__________press 6 to Exit _____________|" << endl;

			cout << "Choose the option " << endl;
			cin >> choice;

			if (choice >= 1 && choice <= 6)
			{
				break; 
			}
			else
			{
				cout << "invalid choice please enter correct choice :( " << endl;
				cout << "enter choice again " << endl;
				/*cin >> choice;*/

			}
		}
		if (choice == 1)
		{
			string infix;
			cout << "enter the infix string " << endl;
			cin >> infix;
			string postfix = infixTopostfix(infix);
			cout << "The postfix expression is " << postfix << endl;
		}
		else if (choice == 2)
		{
			string infix;
			cout << "enter the infix string " << endl;
			cin >> infix;
			string prefix = infixToprefix(infix);
			cout << "The prefix expression is " << prefix << endl;
		}
		else if (choice == 3)
		{
			string postfix;
			cout << "enter a postfix expression to evaluate " << endl;
			cin >> postfix;
			int result = postfixEval(postfix);
			cout << "Result of postfix evalution is " << result << endl;


		}
		else if (choice == 4)
		{
			string postfix;
			cout << "enter a postfix expression to convert to infix " << endl;
			cin >> postfix;
			string infix = postfixtoinfix(postfix);
			cout << "Infix expression " << infix << endl;
		}
		else if (choice == 5)
		{
			string prefix;
			cout << "Enter a prefix expression to convert to infix " << endl;
			cin >> prefix;
			string infix = prefixtoinfix(prefix);
			cout << "Infix expression " << infix << endl;
		}
		else if (choice == 6)
		{
			cout << "You have exited from program :)" << endl;
			break;
		}
		cout << "Do you want to perform any other operation? " << endl;
		cout << "Press n or N to end program and Press Y or y to continue program " << endl;
		cin >> contichoice;
	} while (contichoice == 'y' || contichoice == 'Y');

	cout << "Shukriya....Allah Hfiz " << endl;

    system("pause");
	return 0;
}