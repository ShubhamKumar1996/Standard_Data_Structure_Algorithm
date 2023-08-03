#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//#define mod 1000000007
#define mod (int)1073741824
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define sz(x) ((int)(x).size())
#define INF 1e18

// Debugging Start
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" = "; _print(x); cerr<<"\n";
#else
#define debug(x) 
#endif

void _print(int x) { cerr<<x; }
void _print(double x) { cerr<<x; }
void _print(char x) { cerr<<x; }
void _print(string x) { cerr<<x; }
void _print(bool x) { cerr<<x; }

template<class T,class V> void _print(pair<T, V>p) {cerr<<"{";_print(p.ff);cerr<<",";_print(p.ss);cerr<<"}";}
template<class T> void _print(vector<T>v) { cerr<<"[ "; for(auto x: v){ _print(x); cerr<<" "; } cerr<<"]"; }
template<class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T,class V>void _print(map<T,V> v){cerr<<"[ "; for(auto i : v){_print(i);cerr<<" ";} cerr<<"]";}
// Debugging End

// Initial Method Starts
void initialMethod() {
	FAST_IO;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
}
// Initial Method End

void selectionSort(vector<int>&arr, int n) {
	if(n >= 2) {
		for(int i=0;i<n-1;i++) {
			int minElementIndex = i;
			for(int j=i+1;j<n;j++) {
				if(arr[j] < arr[minElementIndex]) {
					minElementIndex = j;
				}
			}
			if(minElementIndex != i) {
				swap(arr[minElementIndex], arr[i]);
			}
		}
	}
}

void insertionSort(vector<int>&arr, int n) {
	for(int i=1;i<n;i++) {
		int j = i-1, item = arr[i];
		for(j=i-1;j>=0;j--) {
			if(arr[j] > item) {
				arr[j+1] = arr[j];
			} else {
				break;
			}
		}
		arr[j+1] = item;
	}
}

void bubbleSort(vector<int>&arr, int n) {
	for(int i=0;i<n-1;i++) {
		for(int j=0;j<n-1;j++){
			if(arr[j] > arr[j+1]) {
				swap(arr[j], arr[j+1]);
			}
			debug(arr);
		}
	}
}

void merge(vector<int>&arr, int start, int end, int n) {
	if(start >= end) {
		return;
	}
	int mid = start + (end-start)/2;
	int i = start, j = mid + 1, k = start;
	vector<int>result(n);
	while(i<=mid && j<=end) {
		if(arr[i] < arr[j]) {
			result[k++] = arr[i++];
		} else {
			result[k++] = arr[j++];
		}
	}
	while(i<=mid) {
		result[k++] = arr[i++];
	}
	while(j<=end) {
		result[k++] = arr[j++];
	}
	for(int i=start;i<=end;i++) {
		arr[i] = result[i];
	}
	return;
}
void mergeSort(vector<int>&arr, int start, int end, int n) {
	if(start < end) {
		int mid = start + (end-start)/2;
		mergeSort(arr, start, mid, n);
		mergeSort(arr, mid+1, end, n);
		merge(arr, start, end, n);
	}
}

int partition(vector<int>&arr, int start, int end) {
	if(start > end) {
		return -1 ;
	}
	int pivot = arr[end];
	for(int i=start;i<=end;i++) {
		if(arr[i] > pivot) {
			swap(arr[i], arr[end]);
			i--; end--;
		}
		debug(arr);
	}
	arr[end] = pivot;
	return end;
}
void quickSort(vector<int>&arr, int start, int end) {
	if(start >= end) {
		return;
	}
	int partitionIndex = partition(arr, start, end);
	quickSort(arr, start, partitionIndex-1);
	quickSort(arr, partitionIndex+1, end);
	return;
}

void heapify(vector<int>&arr, int n, int parentIndex) {
	int leftChildIndex = parentIndex * 2 + 1, rightChildIndex = parentIndex * 2 + 2;
	int smallestIndex = parentIndex;
	if(leftChildIndex < n && arr[leftChildIndex] < arr[smallestIndex]) {
		smallestIndex = leftChildIndex;
	}
	if(rightChildIndex < n && arr[rightChildIndex] < arr[smallestIndex]) {
		smallestIndex = rightChildIndex;
	}
	if(smallestIndex != parentIndex) {
		swap(arr[parentIndex], arr[smallestIndex]);
		heapify(arr, n, smallestIndex);
	}
}
vector<int> heapSort(vector<int>&arr, int n) {
	// Min-heap
	for(int i=n/2-1;i>=0;i--) {
		heapify(arr, n, i);
		debug(arr);
	}
	vector<int>result;
	for(int i=n-1;i>=0;i--) {
		swap(arr[0], arr[i]);
		result.push_back(arr[i]);
		heapify(arr, i, 0);
	}
	return result;
}

void countingSort(vector<int>&arr, int n) {
	int maxElement = *max_element(all(arr));
	int minElement = *min_element(all(arr));
	int range = maxElement - minElement + 1;
	vector<int>countArr(range, 0);
	for(int i=0;i<n;i++) {
		countArr[arr[i] - minElement]++;
	}
	for(int i=1;i<range;i++) {
		countArr[i] += countArr[i-1];
	}
	vector<int>output(n);
	for(int i=0;i<n;i++) {
		output[countArr[arr[i] - minElement]-1] = arr[i];
		countArr[arr[i] - minElement]--;
	}
	for(int i=0;i<n;i++) {
		arr[i] = output[i];
	}
}

void fun() {
	int n;
	cin >> n;
	vector<int>arr(n);
	for(int i=0;i<n;i++) {
		cin >> arr[i];
	}
	// selectionSort(arr, n);
	// insertionSort(arr, n);
	// bubbleSort(arr, n);
	// mergeSort(arr, 0, n-1, n);
	// quickSort(arr, 0, n-1);
	// arr = heapSort(arr, n);
	countingSort(arr, n);

	for(int i=0;i<n;i++) {
		cout << arr[i] <<" ";
	}
}


int32_t main(){
	initialMethod();
	int t = 1; 
	// cin>>t;
	while(t-- > 0) {
		fun();
	}
}