#include <iostream>
using namespace std;

void printNumbers(int start, int end) {
	if (start > end) return;
	cout << start << " ";
	printNumbers(start + 1, end);
}

void pyramidPattern(int n, int x, int current = 0) {
	if (current > x) return;

	printNumbers(n, n + current);
	cout << endl;

	pyramidPattern(n, x, current + 1);

	if (current < x) {
		printNumbers(n, n + current);
		cout << endl;
	}
}

int main() {
	int n = 47, x = 4;
	pyramidPattern(n, x);
	system("pause");
	return 0;
}
