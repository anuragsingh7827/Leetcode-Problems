//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        pq.push(make_pair(0,source));
        
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        dist[source.first][source.second] = 0;
        
        int di[4] = {-1,0,1,0};
        int dj[4] = {0,1,0,-1};
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int i = p.second.first;
            int j = p.second.second;
            
            for(int k = 0; k < 4; k++){
                int newI = i + di[k];
                int newJ = j + dj[k];
                
                if(newI < 0 || newI >= n || newJ < 0 || newJ >= m || grid[i][j] == 0) continue;
                
                else if(dist[newI][newJ] > dist[i][j] + 1){
                    dist[newI][newJ] = dist[i][j] + 1;
                    pq.push(make_pair(dist[newI][newJ],make_pair(newI,newJ)));
                }
            }
        }
        
        int ans = dist[destination.first][destination.second];
        
        return ans == INT_MAX ? -1 : ans;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends