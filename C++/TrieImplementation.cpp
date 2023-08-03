#include<bits/stdc++.h>
using namespace std;

class Trie {
private:
	struct Node {
		Node *lists[26];
		bool isLeaf;

		bool containsKey(char ch) {
			return (lists[ch-'a'] != nullptr);
		}

		Node* getNext(char ch) {
			return this->lists[ch-'a'];
		}
	};
	Node *root;
public:
	Trie() {
		root = new Node();
	}

	void insert(string word) {
		Node *node = root;
		for(int i=0;i<word.size();i++) {
			if(node->containsKey(word[i]) == false) {
				Node *nextNode = new Node();
				node->lists[word[i] - 'a'] = nextNode;
			}
			node = node->getNext(word[i]);
		}
		node->isLeaf = true;
	}

	bool search(string word) {
		Node *node = root;
		for(int i=0;i<word.size();i++) {
			if(node->containsKey(word[i]) == false) {
				return false;
			}
			node = node->getNext(word[i]);
		}
		return node->isLeaf == true;
	}

	bool startsWith(string word) {
		Node *node = root;
		for(int i=0;i<word.size();i++) {
			if(node->containsKey(word[i]) == false) {
				return false;
			}
			node = node->getNext(word[i]);
		}
		return true;
	}
};

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	int numberOfWords; cin >> numberOfWords;
	Trie trie;
	for(int i=0;i<numberOfWords;i++) {
		string word; cin >> word;
		trie.insert(word);
	}
	int queries; cin >> queries;
	while(queries-- > 0) {
		string word; cin >> word;
		if(trie.search(word) == true) cout << "Found\n"; else cout << "Not Found\n";
	}
	cin>>queries;
	while(queries-- > 0) {
		string word; cin >> word;
		if(trie.startsWith(word) == true) cout << "Found\n"; else cout << "Not Found\n";
	}
}