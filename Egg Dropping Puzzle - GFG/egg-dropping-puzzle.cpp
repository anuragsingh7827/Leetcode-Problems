// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int e, int f, vector<vector<int>> &dp){
        if(e == 1) return f;
        if(f <= 1) return f; 
        
        if(dp[e][f] != -1) return dp[e][f];
        
        int ans = INT_MAX;
        for(int k = 1; k <= f; k++){
            int breakEgg = solve(e - 1,k - 1,dp);
            int notBreakEgg = solve(e,f - k,dp);
            
            int moves = 1 + max(breakEgg, notBreakEgg);
            ans = min(ans,moves);
        }
        
        return dp[e][f] = ans;
    }
    int eggDrop(int e, int f) 
    {
        // your code here
        vector<vector<int>> dp(e + 1, vector<int> (f + 1, 0));
        
        for(int i = 0; i <= f; i++) dp[1][i] = i;
        
        for(int i = 2; i <= e; i++){
            dp[i][0] = 0;
            dp[i][1] = 1;
        }
        
        for(int i = 2; i <= e; i++){
            for(int j = 2; j <= f; j++){
                int ans = INT_MAX;
                for(int k = 1; k <= f; k++){
                    int breakEgg = dp[i - 1][k - 1];
                    int notBreakEgg = dp[i][j - k];
                    
                    int moves = 1 + max(breakEgg, notBreakEgg);
                    ans = min(ans,moves);
                }
                
                dp[i][j] = ans;
            }
        }
        
        return dp[e][f];
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}
  // } Driver Code Ends