#include<bits/stdc++.h>
using namespace std;

class Heap {
public:
	vector<int>heap;
	int currSize;
	bool isMaxHeap;
	Heap(bool isMaxHeap) {
		currSize = 0;
		this->isMaxHeap = isMaxHeap;
	}
	bool isEmpty();
	int topElement();
	void pushElement(int);
	void popElement();
	void MaxHeapRearrangement(int);
	void MinHeapRearrangement(int);
};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	Heap maxHeap(true);
	maxHeap.pushElement(50);
	maxHeap.pushElement(40);
	maxHeap.pushElement(30);
	maxHeap.popElement();
	maxHeap.pushElement(20);
	maxHeap.pushElement(10);
	while(maxHeap.isEmpty() == false) {
		cout << maxHeap.topElement() << " ";
		maxHeap.popElement();
	}
	cout << "\n";
	Heap minHeap(false);
	minHeap.pushElement(50);
	minHeap.pushElement(40);
	minHeap.pushElement(30);
	minHeap.popElement();
	minHeap.pushElement(20);
	minHeap.pushElement(10);
	while(minHeap.isEmpty() == false) {
		cout << minHeap.topElement() << " ";
		minHeap.popElement();
	}
}

bool Heap :: isEmpty() {
	return currSize == 0;
}

int Heap :: topElement() {
	if(isEmpty() == true) return INT_MIN;
	return heap[0];
}

void Heap :: pushElement(int num) {
	heap.push_back(num);
	currSize++;
	for(int i=currSize/2-1;i>=0;i--) {
		if(isMaxHeap == true) 
			MaxHeapRearrangement(i);
		else
			MinHeapRearrangement(i);
	}
}

void Heap :: popElement() {
	if(isEmpty() == true) return;
	swap(heap[0], heap[currSize-1]);
	heap.pop_back();
	currSize--;
	if(isMaxHeap == true) 
		MaxHeapRearrangement(0);
	else
		MinHeapRearrangement(0);
}

void Heap :: MaxHeapRearrangement(int parentIndex) {
	int leftChildIndex = 2*parentIndex+1, rightChildIndex = 2*parentIndex+2, largestIndex = parentIndex;
	if(leftChildIndex < currSize && heap[leftChildIndex] > heap[largestIndex]) {
		largestIndex = leftChildIndex;
	}
	if(rightChildIndex < currSize && heap[rightChildIndex] > heap[largestIndex]) {
		largestIndex = rightChildIndex;
	}
	if(largestIndex != parentIndex) {
		swap(heap[largestIndex], heap[parentIndex]);
		MaxHeapRearrangement(largestIndex);
	}
}

void Heap :: MinHeapRearrangement(int parentIndex) {
	int leftChildIndex = 2 * parentIndex + 1, rightChildIndex = 2 * parentIndex + 2, smallestIndex = parentIndex;
	if(leftChildIndex < currSize && heap[leftChildIndex] < heap[smallestIndex]) {
		smallestIndex = leftChildIndex;
	}
	if(rightChildIndex < currSize && heap[rightChildIndex] < heap[smallestIndex]) {
		smallestIndex = rightChildIndex;
	}
	if(smallestIndex != parentIndex) {
		swap(heap[smallestIndex], heap[parentIndex]);
		MinHeapRearrangement(smallestIndex);
	}
}