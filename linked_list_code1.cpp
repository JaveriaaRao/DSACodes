#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;

	Node(int val) : data(val), next(nullptr) {}
};

class StackUsingList {
private:
	Node* top;
	int size;

public:
	StackUsingList() : top(nullptr), size(0) {}

	~StackUsingList() {
		while (!isEmpty()) {
			int temp;
			pop(temp);
		}
	}

	bool push(int pData) {
		Node* newNode = new Node(pData);
		if (!newNode) return false;
		newNode->next = top;
		top = newNode;
		size++;
		return true;
	}

	bool pop(int& pData) {
		if (isEmpty()) return false;
		Node* temp = top;
		pData = top->data;
		top = top->next;
		delete temp;
		size--;
		return true;
	}

	bool isEmpty() {
		return top == nullptr;
	}

	int getSize() {
		return size;
	}

	void printStack() {
		if (isEmpty()) {
			cout << "Stack is empty!" << endl;
			return;
		}
		Node* current = top;
		cout << "Stack: ";
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << endl;
	}
};

int main() {
	StackUsingList stack;
	int choice, value, poppedValue;

	do {
		cout << "\n--- Stack Menu ---" << endl;
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Check if Empty" << endl;
		cout << "4. Get Size" << endl;
		cout << "5. Print Stack" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter value to push: ";
			cin >> value;
			if (stack.push(value)) {
				cout << "Value pushed successfully!" << endl;
			}
			else {
				cout << "Failed to push value!" << endl;
			}
			break;

		case 2:
			if (stack.pop(poppedValue)) {
				cout << "Popped value: " << poppedValue << endl;
			}
			else {
				cout << "Stack is empty. Cannot pop!" << endl;
			}
			break;

		case 3:
			if (stack.isEmpty()) {
				cout << "Stack is empty!" << endl;
			}
			else {
				cout << "Stack is not empty!" << endl;
			}
			break;

		case 4:
			cout << "Size of stack: " << stack.getSize() << endl;
			break;

		case 5:
			stack.printStack();
			break;

		case 6:
			cout << "Exiting program. Goodbye!" << endl;
			break;

		default:
			cout << "Invalid choice! Please try again." << endl;
		}
	} while (choice != 6);
	system("pause");
	return 0;
}
