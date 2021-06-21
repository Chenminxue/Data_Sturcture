#include <bits/stdc++.h>
using namespace std;

class Stack {
	int* arr;
	int top;

public:
	Stack();

	void push(int data);

	void pop();

	void display();
};

int main() {

	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.pop();
	s.pop();

	s.display();
	return 0;
}

Stack::Stack() {
	arr = new int[128];
	top = -1;
}

void Stack::push(int data) {
	if (top >= 127) {
		cout << "Stack Overflows!" << endl;
		return;
	}
	top += 1;
	arr[top] = data;
}

void Stack::pop() {
	if (top == -1) {
		cout << "Empty!" << endl;
		return;
	}
	int* temp = new int[128];
	for (int i = 0; i < top; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	top -= 1;
}

void Stack::display() {
	for (int i = 0; i <= top; i++) {
		cout << arr[i] << endl;
	}
	cout << "Size of the stack is: " << top + 1 << endl;
}