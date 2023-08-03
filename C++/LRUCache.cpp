#include<bits/stdc++.h>
using namespace std;

class LRUCache {
private:
	struct Node {
		int key, value;
		Node *prev, *next;
		Node(int k, int v) {
			this->key = k;
			this->value = v;
		}
	};
	Node *head, *tail;
	map<int, Node*>cache;
	int currCap, totalCap;

public:
	LRUCache(int cap) {
		this->totalCap = cap;
		this->currCap = 0;
		head = tail = NULL;
	}

	int get(int);
	void set(int, int);
	void deleteNode(Node*);
	void insertNode(Node*);
	void printLRU();
};


int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	int cap; cin >> cap;
	LRUCache lruCache(cap);
	int operation; cin >> operation;
	while(operation--) {
		int choice, key, value; cin >> choice;
		switch(choice) {
			case 1:
				cin >> key;
				cout << lruCache.get(key) <<"\n";
				break;
			case 2:
				cin >> key >> value;
				lruCache.set(key, value);
				break;
		}
		lruCache.printLRU();
	}
}

void LRUCache :: deleteNode(Node *currNode) {
	if(currNode->prev != NULL) {
		currNode->prev->next = currNode->next;
	} else {
		head = head->next;
		if(head != NULL) head->prev = NULL;
	}
	if(currNode->next != NULL) {
		currNode->next->prev = currNode->prev;
	} else {
		tail = tail->prev;
		if(tail != NULL) tail->next = NULL;
	}
}

void LRUCache :: insertNode(Node *currNode) {
	if(head == NULL) {
		head = currNode;
		tail = currNode;
	} else {
		head->prev = currNode;
		currNode->next = head;
		head = currNode;
	}
}

int LRUCache :: get(int key) {
	if(cache.find(key) == cache.end()) return -1;
	// Found
	// 1. Remove that Node and attach it in front.
	Node *newNode = cache[key];
	deleteNode(newNode);
	insertNode(newNode);
	return newNode->value;
}

void LRUCache :: set(int key, int value) {
	Node *newNode = new Node(key, value);
	if(cache.find(key) == cache.end()) {
		// entry not found.
		// check capacity and add new node.
		if(currCap < totalCap) {
			insertNode(newNode);
			cache[key] = newNode;
			currCap++;
		} else {
			cache.erase(tail->key);
			deleteNode(tail);
			insertNode(newNode);
			cache[key] = newNode;
		}
	} else {
		deleteNode(cache[key]);
		insertNode(newNode);
		cache[key] = newNode;
	}
}

void LRUCache :: printLRU() {
	Node *curr = head;
	while(curr != NULL) {
		cout << "{" << curr->key << " " << curr->value << "} ";
		curr = curr->next;

	}
	cout << "\n";
}


