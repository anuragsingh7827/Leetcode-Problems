// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        int* keys = new int[V];
        int* parent = new int[V];
        bool* mst = new bool[V];
    
        for(int i = 0; i < V; i++){
            keys[i] = INT_MAX;
            parent[i] = -1;
            mst[i] = false;
        }
    
        keys[0] = 0;
    
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        minHeap.push({0,0});
        while(!minHeap.empty()){
            auto keyNodePair = minHeap.top();
            minHeap.pop();
    
            int node = keyNodePair.second;
    
            mst[node] = true;
    
            for(auto &it : adj[node]){
                if(mst[it[0]] == false && it[1] < keys[it[0]]){
                    keys[it[0]] = it[1];
                    minHeap.push({keys[it[0]],it[0]});
                }
            }
        }
    
        int cost = 0;
        for(int i = 0; i < V; i++) cost += keys[i];
    
        return cost;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends