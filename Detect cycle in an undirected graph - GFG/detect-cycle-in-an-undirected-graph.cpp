// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCyclicBFS(int start, bool* vis, vector<int> adj[]){
        queue<pair<int,int>> q;
        q.push({start,-1});
        
        vis[start] = true;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            int node = p.first;
            int parent = p.second;
            
            for(int &it : adj[node]){
                if(!vis[it]){
                    vis[it] = true;
                    q.push({it,node});
                }else if(vis[it] && it != parent) return true;
            }
        }
        
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        bool* vis = new bool[V];
        for(int i = 0; i < V; i++) vis[i] = false;
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(isCyclicBFS(i,vis,adj)) return true;
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