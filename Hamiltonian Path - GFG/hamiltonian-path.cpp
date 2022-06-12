// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    bool solve(int start, vector<int> adj[], int cnt, int n, vector<bool> visited){
        visited[start] = true;
        cnt++;
        
        for(auto &it : adj[start]){
            if(!visited[it]){
                if(solve(it,adj,cnt,n,visited)) return true;
            }
        }
        
        if(cnt == n) return true;
        
        return false;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<int> adj[N + 1];
        for(int i = 0; i < M; i++){
            int u = Edges[i][0];
            int v = Edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(N + 1,false);
        for(int i = 1; i <= N; i++){
            if(solve(i,adj,0,N,visited)) return true;
        }
        return false;
    }
};
 

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}  // } Driver Code Ends