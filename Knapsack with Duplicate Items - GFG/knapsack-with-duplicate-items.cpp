// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int unboundedKnapsack(int ind, int tar, int wt[], int val[], vector<vector<int>> &dp){
        if(tar == 0) return 0;
        if(ind == 0) return (tar / wt[0]) * val[0];
        
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        int notTake = unboundedKnapsack(ind - 1,tar,wt,val,dp);
        int take = INT_MIN;
        if(tar >= wt[ind]) take = val[ind] + unboundedKnapsack(ind,tar - wt[ind],wt,val,dp);
        
        return dp[ind][tar] = max(notTake,take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N, vector<int> (W + 1, 0));
        
        for(int tar = 1; tar <= W; tar++) dp[0][tar] = (tar / wt[0]) * val[0];
        
        for(int ind = 1; ind < N; ind++){
            for(int tar = 1; tar <= W; tar++){
                int notTake = dp[ind - 1][tar];
                int take = INT_MIN;
                if(tar >= wt[ind]) take = val[ind] + dp[ind][tar - wt[ind]];
                
                dp[ind][tar] = max(notTake,take);
            }
        }
        
        return dp[N - 1][W];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends