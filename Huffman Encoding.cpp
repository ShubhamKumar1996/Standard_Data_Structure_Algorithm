#include<bits/stdc++.h>
#define int long long
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct TreeNode{
    int frequency;
    char character;
    TreeNode *left;
    TreeNode *right;
};

struct comp{
    bool operator()(TreeNode *node1, TreeNode *node2){
        if(node1->frequency == node2->frequency){
            return node1->character > node2->character;
        }
        return (node1->frequency > node2->frequency);
    }
};

TreeNode *huffman_Encoding(vector<pair<int, char>>&v){
    priority_queue<TreeNode*, vector<TreeNode*>, comp>min_pq;
    for(auto &p:v){
        TreeNode *temp = new TreeNode();
        temp->frequency = p.first;
        temp->character = p.second;
        temp->right = NULL;
        temp->left = NULL;
        min_pq.push(temp);
    }
    while(min_pq.size()!=1){
        TreeNode *first = min_pq.top(); min_pq.pop();
        TreeNode *second = min_pq.top(); min_pq.pop();
        TreeNode *curr = new TreeNode();
        curr->frequency = first->frequency + second->frequency;
        curr->character = '.';
        curr->left = first; curr->right = second;
        min_pq.push(curr);
    }
    return min_pq.top();
}

void print_huffman_tree(TreeNode *root, string code){
    if(root==NULL) return;
    if(root->character != '.'){
        cout<<code<<" "; return;
    }
    code.push_back('0');
    print_huffman_tree(root->left, code);
    code.pop_back(); code.push_back('1');
    print_huffman_tree(root->right, code);
    return;
}

int32_t main(){
	FAST_IO;
	int t; cin>>t; while(t--){
	    string s; cin>>s;
	    vector<pair<int, char>>v;
	    for(int i=0;i<s.size();i++){
	        int x; cin>>x; v.push_back({x, s[i]});
	    }
	    sort(v.begin(), v.end());
	    TreeNode *root = huffman_Encoding(v);
	    print_huffman_tree(root, "");
	    cout<<"\n";
	}
	return 0;
}