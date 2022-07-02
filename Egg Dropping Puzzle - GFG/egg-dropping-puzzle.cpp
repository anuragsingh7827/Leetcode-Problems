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
        vector<int> prev(f + 1, 0), cur(f + 1, 0);
        
        prev[0] = 0;
        prev[1] = 1;
        
        for(int i = 0; i <= f; i++) prev[i] = i;
        
        for(int i = 2; i <= e; i++){
            cur[0] = 0;
            cur[1] = 1;
            for(int j = 2; j <= f; j++){
                int ans = INT_MAX;
                for(int k = 1; k <= f; k++){
                    int breakEgg = prev[k - 1];
                    int notBreakEgg = cur[j - k];
                    
                    int moves = 1 + max(breakEgg, notBreakEgg);
                    ans = min(ans,moves);
                }
                
                cur[j] = ans;
            }
            prev = cur;
        }
        
        return prev[f];
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