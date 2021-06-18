#include <bits/stdc++.h>
using namespace std;

class DynamicArray {
	int* arr;
	int totalNum;
	int capacity;

public:

	DynamicArray();

	void lookup(int index);

	void insert(int index, int data);

	void append(int data);

	void printInfo();
};


int main() {
	
	// Test code
	DynamicArray test;
	test.append(1);
	test.append(1);
	test.append(1);
	test.insert(0, 5);
	test.insert(0, 5);
	test.lookup(1);
	test.printInfo();

	return 0;
}

DynamicArray::DynamicArray() {
	arr = new int[2];
	totalNum = 0;
	capacity = 2;
}

void DynamicArray::append(int data) {
	if (totalNum < capacity - 1) {
		arr[totalNum] = data;
		totalNum += 1;
	}
	else {
		int* temp = new int[capacity * 2];
		for(int i = 0; i < totalNum; i++){
			temp[i] = arr[i];
		}
		delete[] arr;
		temp[totalNum] = data;
		capacity *= 2;
		totalNum += 1;
		arr = temp;
	}
}

void DynamicArray::insert(int index, int data) {
	if (index > totalNum) {
		cout << "Error! Index number is too large, please try again! " << endl;
	}
	else if(index < totalNum){
		int* temp = new int[capacity + 1];
		for (int i = 0; i < index; i++) {
			temp[i] = arr[i];
		}
		temp[index] = data;

		for (int j = index + 1; j < totalNum + 1; j++) {
			temp[j] = arr[j - 1];
		}
		totalNum += 1;
		capacity += 1;
		delete[] arr;
		arr = temp;
	}
	else {
		this->append(data);
	}

}

void DynamicArray::printInfo() {
	cout << "Dynamic Array is: ";
	for (int i = 0; i < totalNum; i++) {
		cout << " " << arr[i] << " ";
	}
	cout << endl;

	cout << "totalNum: " << totalNum << endl;

	cout << "capacity: " << capacity << endl;
}

void DynamicArray::lookup(int index) {
	cout << "Index " << index << " is : " << " ";
	cout << arr[index] << endl;
}