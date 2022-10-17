//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//Back-end complete function Template for C++
class node{
public:
    int data;
    node* left;
    node* right;
    node(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
class Solution{
    public:
    void buildTree(node* &root, int data, int &suc){
        if(root == NULL){
            root = new node(data);
            return;
        }
        
        if(data >= root -> data) buildTree(root -> right,data,suc);
        else{
            suc = root -> data;
            buildTree(root -> left,data,suc);
        }
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
        vector<int> ans(n);
        node* root = NULL;
        for(int i = n - 1; i >= 0; i--){
            int suc = -1;
            buildTree(root,arr[i],suc);
            ans[i] = suc;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}

// } Driver Code Ends