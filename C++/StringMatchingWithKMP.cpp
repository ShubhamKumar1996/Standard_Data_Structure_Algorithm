/* KMP is a String Matching algorithm.
	Time Complexity = O(n) for iterating through text, O(m) for creating lps. Hence O(n + m);
	Space Complexity = O(m)

	Finding LPS and searching pattern is 90% same.
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> findLPS(string pattern, int m) {
	vector<int>lps(m); lps[0] = 0;
	int index1 = 1, index2 = 0;
	while(index1 < m) {
		while(pattern[index1] != pattern[index2]) {
			if(index2 == 0) break;
			index2 = lps[index2-1];
		}
		if(pattern[index1] == pattern[index2]) {
			index2++;
		}
		lps[index1] = index2;
		index1++;
	}
	return lps;
}

int findPattern(string text, string pattern) {
	if(pattern.empty() == true) return 0;
	int n = text.size(), m = pattern.size();

	//Preprocessing
	vector<int>lps = findLPS(pattern, m);

	// KMP
	int index1 = 0, index2 = 0;
	while(index1 < n && index2 < m) {
		while(text[index1] != pattern[index2]) {
			if(index2 == 0) break;
			index2 = lps[index2-1];
		}
		if(text[index1] == pattern[index2]) {
			index2++;
		}
		index1++;
	}
	if(index2 == m) return index1 - m; else return -1;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
	string text, pattern;
	cin >> text >> pattern ;
	cout << findPattern(text, pattern);
}