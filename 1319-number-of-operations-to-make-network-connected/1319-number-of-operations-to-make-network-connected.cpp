class Solution {
public:
    void solve(int start, vector<int> adj[], int* visited){
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto &it : adj[node]){
                if(visited[it] == 0){
                    visited[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size();
        
        if(m < n - 1) return -1;
        
        vector<int> adj[n];
        for(int i = 0; i < m; i++){
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int components = 0;
        
        int* visited = new int[n]{0};
        
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                solve(i,adj,visited);
                components++;
            }
        }
        
        delete[] visited;
        visited = NULL;
        
        return components - 1;
    }
};