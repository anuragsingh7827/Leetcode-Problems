// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
class Solution {
public:
    bool solve(int start, vector<pair<int,int>>* adj, int k, vector<bool> visited){
        if(k <= 0) return true;
        
        visited[start] = true;
        for(auto &it : adj[start]){
            int nbr = it.first;
            int wt = it.second;
            if(visited[nbr] == false && solve(nbr,adj,k - wt,visited)) return true; 
        }
        
        return false;
    }
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
        //  Code Here
        vector<pair<int,int>>* adj = new vector<pair<int,int>> [V];
        for(int i = 0; i < (3 * E); i += 3){
            int u = a[i];
            int v = a[i + 1];
            int wt = a[i + 2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        vector<bool> visited(V,false);
        return solve(0,adj,k,visited);
    } 
};




// { Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}  // } Driver Code Ends