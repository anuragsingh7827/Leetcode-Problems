// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int start, vector<int> adj[], vector<int> &toposort, vector<bool> &visited){
	    visited[start] = true;
	    for(auto &it : adj[start]){
	        if(!visited[it]) dfs(it,adj,toposort,visited);
	    }
	    
	    toposort.push_back(start);
	}
	void solve(int start, int begin, vector<int> transpose[], vector<bool> &visited){
	    visited[start] = true;
	    for(auto &it : transpose[start]){
	        if(!visited[it]) solve(it,begin,transpose,visited);
	    }
	}
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<int> toposort;
        vector<bool> visited(V,false);
        for(int i = 0; i < V; i++){
            if(!visited[i]) dfs(i,adj,toposort,visited);
        }
        
        vector<int> transpose[V];
        for(int i = 0; i < V; i++){
            for(auto &it : adj[i]) transpose[it].push_back(i);
        }
                
        for(int i = 0; i < V; i++) visited[i] = false;
        
        int n = toposort.size();
        int ans = 0;
        for(int i = n - 1; i >= 0; i--){
            if(!visited[toposort[i]]){
                solve(toposort[i],toposort[i],transpose,visited);
                ans++;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends