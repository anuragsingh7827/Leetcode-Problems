// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
bool solve(int node, vector<int>* adj, vector<int> color, int m, int n){
    
    if(node == n) return true;
    
    
    for(int i = 0; i < m; i++){
        color[node] = i;
        int k = 0;
        for(auto &it : adj[node]){
            if(color[it] == color[node]){
                k = 1;
                break;
            }
        }
        if(k == 0){
            if(solve(node + 1,adj,color,m,n)) return true;
        }
    }
    
    return false;
    
}
bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    
    vector<int>* adj = new vector<int> [n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(graph[i][j] == 1) adj[i].push_back(j);
        }
    }

    vector<int> color(n,-1);
    
    return solve(0,adj,color,m,n);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends