#include <bits/stdc++.h>
using namespace std;

class Queue {
	vector<int> q1;

public:
	void enQueue(int data);

	void deQueue();

	void peek();

	void display();
};

int main() {

	Queue q;
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.deQueue();
	q.deQueue();

	q.display();
	return 0;
}

void Queue::enQueue(int data) {
	q1.push_back(data);
}

void Queue::deQueue() {
	if (q1.size() < 1) {
		cout << "Add an element first!" << endl;
		return;
	}
	else {
		vector<int> temp;
		for (int i = 1; i < q1.size(); i++) {
			temp.push_back(q1[i]);
		}
		q1.clear();
		q1 = temp;
	}
}

void Queue::peek() {


}

void Queue::display() {
	for (auto x : q1) {
		cout << x << endl;
	}
	cout << "Size of the queue is : " << q1.size() << endl;

}