// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        int to = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] != 0) to++;
                if(grid[i][j] == 2) q.push(make_pair(i,j));
            }
        }
        
        int days = 0;
        int cnt = 0;
        int dx[4] = {-1, 0 , 1, 0};
        int dy[4] = {0, 1, 0, -1};
        
        while(!q.empty()){
            int size = q.size();
            cnt += size;
            for(int j = 0; j < size; j++){
                pair<int,int> p = q.front();
                q.pop();
                int xc = p.first;
                int yc = p.second;
                for(int i = 0; i < 4; i++){
                    int X = xc + dx[i];
                    int Y = yc + dy[i];
                    if(X < 0 || X >= grid.size() || Y < 0 || Y >= grid[0].size() || grid[X][Y] != 1) continue;
                    grid[X][Y] = 2;
                    q.push(make_pair(X,Y));
                }
            }
            if(!q.empty()) days++;
        }
        if(cnt == to) return days;
        return -1;
        
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends