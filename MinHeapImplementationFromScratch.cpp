#include<bits/stdc++.h>
#define int long long
using namespace std;

class MinHeap {
private:
	int size;
	vector<int>arr;
public:
	MinHeap() {
		size = 0;
	}

	bool empty() {
		return size == 0;
	}

	void heapify(int parent) {
		int smallest = parent;
		int left = 2 * parent + 1, right = 2 * parent + 2;
		if(left < size && arr[smallest] > arr[left]) {
			smallest = left;
		}
		if(right < size && arr[smallest] > arr[right]) {
			smallest = right;
		}
		if(parent != smallest) {
			swap(arr[parent], arr[smallest]);
			heapify(smallest);
		}
	}

	void push(int element) {
		arr.push_back(element);
		size++;
		if(size > 1) {
			for(int i=size/2-1;i>=0;i--) {
				heapify(i);
			}
		}
	}

	void print() {
		cout << "Size: " << size <<"\n";
		for(int i=0;i<size;i++) {
			cout << arr[i] << " ";
		}
	}

	void pop() {
		if(empty() == false) {
			swap(arr[0], arr[size-1]);
			size--;
			heapify(0);
		} else {
			cout << "No element in Heap\n";
		}
	}

	int top() {
		if(empty() == false) {
			return arr[0];
		} else {
			cout << "No element in Heap\n";
			return -1;
		}
	}
};

int32_t main() {
	MinHeap pq;
	pq.push(10);
	pq.push(20);
	pq.push(5);
	pq.push(45);
	pq.push(30);
	pq.push(83);
	while(pq.empty() == false) {
		cout << pq.top() << "\n";
		pq.pop();
	}
	// pq.print();
}