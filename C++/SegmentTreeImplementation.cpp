#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
	vector<int>prefixSumArr;
	vector<int>segmentTreeArr;
public:
	SegmentTree(vector<int>&arr, int n) {
		prefixSumArr.push_back(arr[0]);
		for(int i=1;i<n;i++) {
			int prevSum = prefixSumArr[i-1];
			prefixSumArr.push_back(prevSum + arr[i]);
		}
		segmentTreeArr.assign(4 * n, -1);
		buildSegmentTree(0, n-1, 0);
	}
	void buildSegmentTree(int, int, int);
	void updateSegmentTree(int, int, int, int, int);
	int retriveSumInRange(int, int, int, int, int);
	void printSegmentTree();
};

void SegmentTree :: buildSegmentTree(int start, int end, int segmentTreeIndex) {
	if(start <= end) {
		if(start == 0) {
			segmentTreeArr[segmentTreeIndex] = prefixSumArr[end];
		} else {
			segmentTreeArr[segmentTreeIndex] = prefixSumArr[end] - prefixSumArr[start-1];
		}
		if(start < end) {
			int mid = start + (end - start)/2;
			buildSegmentTree(start, mid, 2 * segmentTreeIndex + 1);
			buildSegmentTree(mid+1, end, 2 * segmentTreeIndex + 2);
		}
	}
}

void SegmentTree :: updateSegmentTree(int start, int end, int segmentTreeIndex, int givenIndex, int changeInValue) {
	if(start <= end) {
		if(givenIndex >= start && givenIndex <= end) {
			segmentTreeArr[segmentTreeIndex] += changeInValue;
		}
		if(start < end) {
			int mid = start + (end - start)/2;
			updateSegmentTree(start, mid, 2 * segmentTreeIndex + 1, givenIndex, changeInValue);
			updateSegmentTree(mid+1, end, 2 * segmentTreeIndex + 2, givenIndex, changeInValue);
		}
	}
}

int SegmentTree :: retriveSumInRange(int start, int end, int segmentTreeIndex, int left, int right) {
	if(start > end || (start == end && start != segmentTreeIndex)) return 0;
	if(start >= left && end <= right) {
		return segmentTreeArr[segmentTreeIndex];
	}
	if(start < left || end > right) {
		int mid = start + (end - start)/2;
		int leftSum = retriveSumInRange(start, mid, left, right, 2 * segmentTreeIndex + 1);
		int rightSum = retriveSumInRange(mid + 1, end, left, right, 2 * segmentTreeIndex + 2);
		return leftSum + rightSum;
	}
	return 0;
}

void SegmentTree :: printSegmentTree() {
	for(auto &x: segmentTreeArr) {
		if(x == -1) break;
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i=0;i<n;i++) {
		cin >> arr[i] ;
	}
	SegmentTree segmentTreeObject(arr, n);
	segmentTreeObject.printSegmentTree();
	int numOfQuery; cin >> numOfQuery; 
	while(numOfQuery-- > 0) {
		int queryType;
		cin >> queryType ;
		if(queryType == 1) {
			int index, currValue;
			cin >> index >> currValue ;
			int prevValue = arr[index];
			segmentTreeObject.updateSegmentTree(0, n-1, 0, index, currValue - prevValue);
			segmentTreeObject.printSegmentTree();
		} else {
			int left, right; cin >> left >> right ;
			cout << segmentTreeObject.retriveSumInRange(0, n-1, 0, left, right) << "\n";
		}
	}
	
}