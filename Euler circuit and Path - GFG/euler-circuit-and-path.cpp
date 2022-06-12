// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    void dfs(int start, vector<int> adj[], vector<bool> &visited, int &n){
        visited[start] = true;
        n++;
        for(auto &it : adj[start]){
            if(!visited[it]) dfs(it,adj,visited,n);
        }
    }
	int isEularCircuit(int V, vector<int>adj[]){
	    // Code here
	    int comp = 0;
	    vector<bool> visited(V,false);
	    for(int i = 0; i < V; i++){
	        if(!visited[i]){
	            int n = 0;
	            dfs(i,adj,visited,n);
	            if(n > 1) comp++;
	        }
	    }
	    
	    if(comp > 1) return 0;
	    
	    int oddDegreeNodes = 0;
	    for(int i = 0; i < V; i++){
	        int indegree = adj[i].size();
	        if(indegree & 1) oddDegreeNodes++;
	    }
	    
	    if(oddDegreeNodes == 0) return 2;
	    else if(oddDegreeNodes == 2) return 1;
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.isEularCircuit(V, adj);
		cout << ans <<"\n";	}
	return 0;
}  // } Driver Code Ends