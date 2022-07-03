// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		
	public:
	int solve(int ind, int tar, int cost[], vector<vector<int>> &dp){
	    if(tar == 0) return 0;
	    if(ind == 0){
	        if(cost[0] != -1) return tar * cost[0];
	        return 1e9;
	    }
	    
	    if(dp[ind][tar] != -1) return dp[ind][tar];
	    
	    int notTake = solve(ind - 1,tar,cost,dp);
	    int take = INT_MAX;
	    int packWgt = ind + 1;
	    if(cost[ind] != -1 && packWgt <= tar) take = cost[ind] + solve(ind,tar - packWgt,cost,dp);
	    
	    return dp[ind][tar] = min(notTake,take);
	}
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        vector<int> prev(W + 1, 0), cur(W + 1, 0);
        
        for(int j = 1; j <= W; j++){
            if(cost[0] != -1) prev[j] = j * cost[0];
            else prev[j] = 1e9;
        }
        
        for(int ind = 1; ind < N; ind++){
            for(int tar = 1; tar <= W; tar++){
                int notTake = prev[tar];
        	    int take = INT_MAX;
        	    int packWgt = ind + 1;
        	    if(cost[ind] != -1 && packWgt <= tar) take = cost[ind] + cur[tar - packWgt];
        	    
        	    cur[tar] = min(notTake,take);
            }
            prev = cur;
        }
        
        
        int ans = prev[W];
        
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
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends