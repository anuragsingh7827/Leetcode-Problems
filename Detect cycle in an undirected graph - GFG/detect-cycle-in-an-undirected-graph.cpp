// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCyclicDFS(int start, bool* vis, int parent, vector<int> adj[]){
        vis[start] = true;
        
        for(auto &it : adj[start]){
            if(!vis[it]){
                vis[it] = true;
                if(isCyclicDFS(it,vis,start,adj)) return true;
            }else if(vis[it] && it != parent) return true;
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool* vis = new bool[V];
        for(int i = 0; i < V; i++) vis[i] = false;
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(isCyclicDFS(i,vis,-1,adj)) return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends