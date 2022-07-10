// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int solve(int ind, int tar, int coins[], vector<vector<int>> &dp){
	    if(tar == 0) return 0;
	    if(ind == 0){
	        if(tar % coins[0] == 0) return tar / coins[0];
	        return 1e9;
	    }
	    
	    if(dp[ind][tar] != -1) return dp[ind][tar];
	    
	    int notTake = solve(ind - 1,tar,coins,dp);
	    int take = INT_MAX;
	    if(tar >= coins[ind]) take = 1 + solve(ind,tar - coins[ind],coins,dp);
	    
	    return dp[ind][tar] = min(notTake,take);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(M, vector<int> (V + 1, -1));
	    int ans = solve(M - 1,V,coins,dp);
	    
	    if(ans >= 1e9) return -1;
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
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends