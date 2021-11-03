#include<bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) x.begin(), x.end()
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
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
template<class T> void _print(vector<T>v) { cerr<<"[ "; for(auto &x: v){ _print(x); cerr<<" "; } cerr<<"]"; }
template<class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template<class T,class V> void _print(map<T,V> v) {cerr<<"[ "; for(auto i : v){_print(i);cerr<<" ";} cerr<<"]";}
// Debugging End

// Initial Method 
void initialMethod() {
	FAST_IO;
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
		freopen("error.txt", "w", stderr);
	#endif
}
// Initial Method
void fun() {

}

int32_t main(){
	initialMethod();
	int t = 1;
	// cin>>t;
	while(t-- > 0) {
		fun();
	}
}