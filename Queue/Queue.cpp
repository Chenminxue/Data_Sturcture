/* 

C++ with vector

*/

//#include <bits/stdc++.h>
//using namespace std;
//
//class Queue {
//	vector<int> q1;
//
//public:
//	void enQueue(int data);
//
//	void deQueue();
//
//	void display();
//};
//
//int main() {
//
//	Queue q;
//	q.enQueue(1);
//	q.enQueue(2);
//	q.enQueue(3);
//	q.enQueue(4);
//	q.deQueue();
//	q.deQueue();
//
//	q.display();
//	return 0;
//}
//
//void Queue::enQueue(int data) {
//	q1.push_back(data);
//}
//
//void Queue::deQueue() {
//	if (q1.size() < 1) {
//		cout << "Add an element first!" << endl;
//		return;
//	}
//	else {
//		vector<int> temp;
//		for (int i = 1; i < q1.size(); i++) {
//			temp.push_back(q1[i]);
//		}
//		q1.clear();
//		q1 = temp;
//	}
//}
//
//void Queue::display() {
//	for (auto x : q1) {
//		cout << x << endl;
//	}
//	cout << "Size of the queue is : " << q1.size() << endl;
//
//}






/*

C with Array

*/

//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXSIZE 6 // Maximum size of the queue
//#define ERROR -99 // Error flag
//
//typedef struct {
//    int data[MAXSIZE];
//    int size; 
//}Queue;
//
//Queue* createQueue() {
//    Queue* q = (Queue*)malloc(sizeof(Queue));
//    if (!q) {
//        printf("Lack of memory!");
//        return NULL;
//    }
//    q->size = 0;
//
//    return q;
//}
//
//int isFull(Queue* q) {
//    return (q->size == MAXSIZE);
//}
//
//
//int isEmpty(Queue* q) {
//    return (q->size == 0);
//}
//
//void addItem(Queue*q, int newitem) {
//    if (isFull(q)) {
//        printf("Queue is full!");
//    }
//
//    q->data[q->size] = newitem;
//    q->size++;
//}
//
//void deleteItem(Queue* q) {
//    if (isEmpty(q)) {
//        printf("Queue is empty!");
//    }
//    for (int i = 0; i < q->size; i++) {
//        q->data[i] = q->data[i + 1];
//    }
//    q->data[q->size] = NULL;
//    q->size--;
//}
//
//void printQueue(Queue*q) {
//    printf("Size of the queue is %d", sizeof(q->data) / sizeof(q->data[0]));
//    for (int i = 0; i < MAXSIZE; i++) {
//        printf(" %d ", q->data[i]);
//    }
//    printf("\n");
//}
//
//
//
//int main(int argc, const char* argv[]) {
//    
//    Queue* q = createQueue();
//
//    addItem(q, 0);
//    addItem(q, 1);
//    addItem(q, 2);
//    addItem(q, 3);
//    addItem(q, 4);
//    printQueue(q);
//
//    deleteItem(q);
//    deleteItem(q);
//    deleteItem(q);
//    printQueue(q);
//
//    
//
//    return 0;
//}






/*

C with Linked List

*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

struct Queue {
	struct Node* front;
	struct Node* rear;
};

struct Node* createNode(int data) {
	struct Node* n = (struct Node*)malloc(sizeof(struct Node));

	n->data = data;
	n->next = NULL;
	return n;
}

struct Queue* createQueue() {
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));

	q->front = NULL;
	q->rear = NULL;
	return q;
}

void enqueue(struct Queue* q, int data) {
	struct Node* n = createNode(data);
	if (q->rear == NULL) {
		q->front = q->rear = n;
		return;
	}
	q->rear->next = n;
	q->rear = n;
}

void deleteQueue(struct Queue* q) {
	if (q->front == NULL) {
		printf("The queue is empty!");
		return;
	}

	struct Node* n = q->front;

	q->front = q->front->next;

	if (q->front == NULL) {
		q->rear = NULL;
	}
	
	free(n);
}

void printQueue(Queue* q){
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
	temp = q->front;
	if (temp == NULL) {
		printf("Empty!");
	}
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main() {

	struct Queue* q = createQueue();
	enqueue(q, 1);
	enqueue(q, 2);
	enqueue(q, 3);
	enqueue(q, 4);
	enqueue(q, 5);
	printQueue(q);
	deleteQueue(q);
	printQueue(q);
	deleteQueue(q);
	deleteQueue(q);
	deleteQueue(q);
	deleteQueue(q);
	printQueue(q);


	return 0;
}