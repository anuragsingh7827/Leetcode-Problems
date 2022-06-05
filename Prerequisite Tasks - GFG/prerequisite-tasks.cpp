// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool dfs(int start, vector<int> adj[], vector<bool> &visited, vector<bool> dfsVisited){
        
        visited[start] = true;
        dfsVisited[start] = true;
        
        for(auto &it : adj[start]){
            if(!visited[it]){
                if(dfs(it,adj,visited,dfsVisited)) return true;
            }else if(dfsVisited[it]) return true;
        }
        
        return false;
    }
	bool isPossible(int N, vector<pair<int, int> >& prerequisites) {
	    // Code here
	    int m = prerequisites.size();
	    vector<int> adj[N];
	    for(int i = 0; i < m; i++){
	        int u = prerequisites[i].second;
	        int v = prerequisites[i].first;
	        adj[u].push_back(v);
	    }
	    
	    vector<bool> visited(N,false);
	    vector<bool> dfsVisited(N,false);
	    
	    for(int i = 0; i < N; i++){
	        if(!visited[i]){
	            if(dfs(i,adj,visited,dfsVisited)) return false;
	        }
	    }
	    
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends