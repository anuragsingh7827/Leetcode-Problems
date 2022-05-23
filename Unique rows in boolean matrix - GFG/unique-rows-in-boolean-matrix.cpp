// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends

class node{
public:
    int data;
    bool isTerminal;
    node* h[2];
    node(int data){
        this -> data = data;
        isTerminal = false;
        h[0] = NULL;
        h[1] = NULL;
    }
};
class trie{
public:
    node* root;
    trie(){
        root = new node(-1);
    }
    void insert(int arr[], int cols){
        node* temp = root;
        for(int i = 0; i < cols; i++){
            int bit = arr[i];
            if(temp -> h[bit]) temp = temp -> h[bit];
            else{
                temp -> h[bit] = new node(bit);
                temp = temp -> h[bit];
            }
        }
        temp -> isTerminal = true;
    }
    vector<int> search(int arr[], int cols){
        vector<int> row;
        node* temp = root;
        for(int i = 0; i < cols; i++){
            int bit = arr[i];
            row.push_back(bit);
            temp = temp -> h[bit];
        }
        if(temp -> isTerminal){
            temp -> isTerminal = false;
            return row;
        }else return {};
    }
};
/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    //Your code here
    trie t;
    for(int i = 0; i < row; i++) t.insert(M[i],col);
    
    vector<vector<int>> ans;
    node* temp = t.root;
    for(int i = 0; i < row; i++){
        vector<int> v = t.search(M[i],col);
        if(v.size() > 0) ans.push_back(v);
    }
    
    return ans;
}