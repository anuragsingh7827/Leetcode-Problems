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
	    vector<vector<int>> temp = grid;
	    queue<pair<int,int>> q;
	    for(int i = 0; i < temp.size(); i++){
	        for(int j = 0; j < temp[0].size(); j++){
	            if(temp[i][j] == 1){
	                q.push(make_pair(i,j));
	                temp[i][j] = -1;
	            }
	        }
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
	            if(X < 0 || X >= temp.size() || Y < 0 || Y >= temp[0].size() || temp[X][Y] != 0) continue;
	            else if(temp[xc][yc] == -1) temp[X][Y] = 1;
	            else temp[X][Y] = temp[xc][yc] + 1;
	            q.push(make_pair(X,Y));
	        }
	    }
	    
	    for(int i = 0; i < grid.size(); i++){
	        for(int j = 0; j < grid[0].size(); j++){
	            if(temp[i][j] == 0) temp[i][j] = INT_MAX;
	            if(temp[i][j] == -1) temp[i][j] = 0;
	        }
	    }
	    
	    return temp;
	    
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