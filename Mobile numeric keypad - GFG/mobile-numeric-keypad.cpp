// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	long long solve(int n, int prev, vector<int>* adj, vector<vector<long long>> &dp){
	    if(n == 0) return 1;
	    
	    if(dp[n][prev] != -1) return dp[n][prev];
	    
	    long long ways = 0;
	    for(auto &it : adj[prev]) ways += solve(n - 1,it,adj,dp);
	    
	    return dp[n][prev] = ways;
	}
	long long getCount(int N)
	{
		// Your code goes here
		int keypad[][3] = {
		    {1,2,3},
		    {4,5,6},
		    {7,8,9},
		    {-1,0,-1}
		};
		
		int di[5] = {0,-1,0,1,0};
		int dj[5] = {0,0,1,0,-1};
		
		vector<int>* adj = new vector<int> [10];
		for(int i = 0; i < 4; i++){
		    for(int j = 0; j < 3; j++){
		        if(keypad[i][j] == -1) continue;
		        for(int k = 0; k < 5; k++){
		            int newI = i + di[k];
		            int newJ = j + dj[k];
		            if(newI < 0 || newI >= 4 || newJ < 0 || newJ >= 3 || keypad[newI][newJ] == -1) continue;
		            adj[keypad[i][j]].push_back(keypad[newI][newJ]);
		        }
		    }
		}
		
		vector<vector<long long>> dp(N, vector<long long> (10, -1));
		
        long long ans = 0;
        for(int i = 0; i <= 9; i++) ans += solve(N - 1,i,adj,dp);
        
        return ans;
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends