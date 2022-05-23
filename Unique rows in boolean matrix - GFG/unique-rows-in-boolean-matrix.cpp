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


/*You are required to complete this function*/
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
    //Your code here
    map<string,bool> h;
    for(int i = 0; i < row; i++){
        string s = "";
        for(int j = 0; j < col; j++) s.push_back(M[i][j] + '0');
        h[s] = true;
    }
    
    vector<vector<int>> ans;
    for(int i = 0; i < row; i++){
        string s = "";
        for(int j = 0; j < col; j++) s.push_back(M[i][j] + '0');
        
        if(h[s]){
            vector<int> v(col);
            for(int i = 0; s[i] != '\0'; i++) v[i] = s[i] - '0';
            ans.push_back(v);
            h[s] = false;
        }
    }
    
    return ans;
}