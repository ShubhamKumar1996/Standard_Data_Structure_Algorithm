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
		int j;
		int currNum = arr[i];
		for(j=i-1;j>=0;j--) {
			if(arr[j] > currNum) {
				arr[j+1] = arr[j];
			} else {
				break;
			}
		}
		/*
            Possible Scenarios:
            1. currNum was greatest compared to sorted elements -> then j will still be equal to (i-1) -> hence j + 1 will be currIndex -> hence arr[j+1] = currNum already.
            2. currNum is smallest element compared to sorted elements -> j = -1 -> then arr[j + 1] = currNum will work.
            3. CurrNum fall in between then j is pointing to element smaller then currNum. Hence we should modify element at next position -> arr[j + 1] = currNum. 
        */
		arr[j+1] = currNum;
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

void merge(vector<int>&arr, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;
    std::vector<int>result;

    while(left <= mid && right <= end) {
        int num = (nums[left] < nums[right]) ? nums[left++] : nums[right++];
        result.push_back(num);
    }

    while(left<=mid) {
        result.push_back(nums[left++]);
    }

    while(right <= end) {
        result.push_back(nums[right++]);
    }

    for(int i=start;i<=end;i++) {
        nums[i] = result[i-start];
    }
}
void mergeSort(vector<int>&arr, int start, int end) {
	if(start < end) {
		int mid = start + (end-start)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}

int partition(vector<int>&nums, int start, int end) {
    int pivotElement = nums[start];
    int left = start + 1;
    int right = end;
    while(left <= right) {
        if(nums[left] <= pivotElement) {
            left++;
        } else {
            std::swap(nums[left], nums[right]);
            right--;
        }
    }

    std::swap(nums[left-1], nums[start]);
    return left-1;
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
	// mergeSort(arr, 0, n-1);
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