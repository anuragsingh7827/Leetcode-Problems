// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    void solve(int n, vector<int> KnightPos, int** dist){
        queue<pair<int,int>> q;
        int X = KnightPos[0] - 1;
        int Y = n - KnightPos[1];
        dist[X][Y] = 0;
        q.push({X,Y});
        
        int dx[8] = {1,2,2,1,-1,-2,-2,-1};
        int dy[8] = {2,1,-1,-2,-2,-1,1,2};
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            
            int x = p.first;
            int y = p.second;
            for(int i = 0; i < 8; i++){
                int newX = x + dx[i];
                int newY = y + dy[i];
                if(newX >= 0 && newX < n && newY >= 0 && newY < n){
                    if(dist[x][y] + 1 < dist[newX][newY]){
                        dist[newX][newY] = 1 + dist[x][y];
                        q.push({newX,newY});
                    }
                }
            }
        }
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    int** dist = new int*[N];
	    for(int i = 0; i < N; i++) dist[i] = new int[N];
	    
	    for(int i = 0; i < N; i++){
	        for(int j = 0; j < N; j++) dist[i][j] = INT_MAX;
	    }
	    
	    solve(N,KnightPos,dist);
	    
	    int x = TargetPos[0] - 1;
	    int y = N - TargetPos[1];

	    return dist[x][y];
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends