// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool solve(int start, vector<int> &vis, vector<int> &dfsvis, vector<int> adj[]){
        vis[start] = 1;
        dfsvis[start] = 1;
        
        for(auto &it : adj[start]){
            if(vis[it] == 0){
                if(solve(it,vis,dfsvis,adj)) return true;
            }else if(dfsvis[it] == 1) return true;
        }
        dfsvis[start] = 0;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V);
        vector<int> dfsvis(V);
        
        for(int i = 0; i < V; i++){
            vis[i] = 0;
            dfsvis[i] = 0;
        }
        
        for(int i = 0; i < V; i++){
            if(vis[i] == 0){
                if(solve(i,vis,dfsvis,adj)) return true;
            }
        }
        
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends