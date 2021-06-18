#include <bits/stdc++.h>
using namespace std;
const int ARRAY_SIZE = 256;


class Node {
public:
	int key, value;

	Node(int key, int value);
};


class HashTable {
	
	Node** arr;

public:
	HashTable();

	int hashFunc(int key);

	void insert(int key, int value);

	void getKey(int key);
	
	void deleteKey(int key);

	void display();

};


int main() {

	HashTable ht;
	ht.insert(0, 1);
	ht.insert(1, 5);
	ht.insert(101, 45);
	ht.deleteKey(1);
	ht.getKey(101);
	ht.display();

	return 0;
}

Node::Node(int key, int value) {
	this->key = key;
	this->value = value;
}

HashTable::HashTable(){
	arr = new Node * [ARRAY_SIZE];
	for (int i = 0; i < ARRAY_SIZE; i++) {
		arr[i] = NULL;
	}
}

int HashTable::hashFunc(int key) {
	return key % ARRAY_SIZE;
}

void HashTable::insert(int key, int value) {
	int h = hashFunc(key);
	while (arr[h] != NULL && arr[h]->key != key) {
		h = hashFunc(h + 1);
	}
	if (arr[h] != NULL) {
		delete arr[h];
	}
	arr[h] = new Node(key, value); // update new key
}

void HashTable::getKey(int key){
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (arr[i] != NULL && arr[i]->key == key) {
			cout << "Key " << key << " is: " << arr[i]->value << endl;
		}
	}
}

void HashTable::deleteKey(int key) {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (arr[i] != NULL && arr[i]->key == key) {
			delete arr[i];
			arr[i] = NULL;
		}
		else {
			continue;
		}
	}
	cout << "Completed!" << endl;
}

void HashTable::display() {
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (arr[i] != NULL && arr[i]->key != -1) {
			cout << arr[i]->key << "------" << arr[i]->value << endl;
		}
	}
}