// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int i, int j, vector<vector<char>> grid, bool** visited, int n, int m){
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = true;
        
        int di[8] = {0,1,1,1,0,-1,-1,-1};
        int dj[8] = {1,1,0,-1,-1,-1,0,1};
        
        while(!q.empty()){
            auto land = q.front();
            q.pop();
            
            int I = land.first;
            int J = land.second;
            
            for(int k = 0; k < 8; k++){
                int newI = I + di[k];
                int newJ = J + dj[k];
                
                if(newI < 0 || newI >= n || newJ < 0 || newJ >= m) continue;
                else if(grid[newI][newJ] == '1' && visited[newI][newJ] == false){
                    visited[newI][newJ] = true;
                    q.push({newI,newJ});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        
        bool** visited = new bool*[n];
        for(int i = 0; i < n; i++) visited[i] = new bool[m];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) visited[i][j] = false;
        }
        
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    bfs(i,j,grid,visited,n,m);
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends