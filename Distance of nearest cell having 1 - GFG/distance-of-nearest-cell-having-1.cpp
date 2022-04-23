// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int** freq = new int*[grid.size()];
	    for(int i = 0; i < grid.size(); i++) freq[i] = new int[grid[0].size()];
	    
	    queue<pair<int,int>> q;
	    for(int i = 0; i < grid.size(); i++){
	        for(int j = 0; j < grid[0].size(); j++){
	            if(grid[i][j] == 1){
	                q.push(make_pair(i,j));
	                grid[i][j] = 0;
	                freq[i][j] = 1;
	            }else freq[i][j] = 0;
	        }
	    }
	    
	    if(q.empty()){
    	    for(int i = 0; i < grid.size(); i++){
    	        for(int j = 0; j < grid[0].size(); j++) grid[i][j] = INT_MAX;
    	    }
	        return grid;
	    }
	    
	    
	    int dx[4] = {-1,0,1,0};
	    int dy[4] = {0,1,0,-1};
	    while(!q.empty()){
	        auto p = q.front();
	        q.pop();
	        int xc = p.first;
	        int yc = p.second;
	        for(int i = 0; i < 4; i++){
	            int X = xc + dx[i];
	            int Y = yc + dy[i];
	            if(X < 0 || X >= grid.size() || Y < 0 || Y >= grid[0].size() || grid[X][Y] != 0) continue;
	            if(freq[X][Y] == 0){
	                grid[X][Y] = grid[xc][yc] + 1;
	                freq[X][Y] = 1;
	                q.push(make_pair(X,Y));
	            }
	        }
	    }
	    
	    return grid;
	    
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends