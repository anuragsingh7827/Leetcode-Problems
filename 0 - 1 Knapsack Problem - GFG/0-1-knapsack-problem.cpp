// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int solve(int ind, int tar, int wt[], int val[], vector<vector<int>> &dp){
        if(tar == 0) return 0;
        if(ind == 0){
            if(wt[0] <= tar) return val[0];
            return 0;
        }
        
        if(dp[ind][tar] != -1) return dp[ind][tar];
        
        int notTake = solve(ind - 1,tar,wt,val,dp);
        int take = INT_MIN;
        if(tar >= wt[ind]){
            take = val[ind] + solve(ind - 1,tar - wt[ind],wt,val,dp);
        }
        
        return dp[ind][tar] = max(take,notTake);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> prev(W + 1, 0);
       
       for(int j = wt[0]; j <= W; j++) prev[j] = val[0];
       
       for(int ind = 1; ind < n; ind++){
           for(int tar = W; tar >= 1; tar--){
                int notTake = prev[tar];
                int take = INT_MIN;
                if(tar >= wt[ind]){
                    take = val[ind] + prev[tar - wt[ind]];
                }
                
                prev[tar] = max(take,notTake);
           }
       }
       
       return prev[W];
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
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends