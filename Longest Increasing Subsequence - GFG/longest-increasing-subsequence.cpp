// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    int solve(int ind, int prevInd, int a[], int n, vector<vector<int>> &dp){
        if(ind == n) return 0;
        
        if(dp[ind][prevInd + 1] != -1) return dp[ind][prevInd + 1];
        
        int notTake = solve(ind + 1,prevInd,a,n,dp);
        int take = 0;
        if(prevInd == -1 || a[ind] > a[prevInd]) take = 1 + solve(ind + 1,ind,a,n,dp);
        return dp[ind][prevInd + 1] = max(notTake,take);
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // your code here
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return solve(0,-1,a,n,dp);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}
  // } Driver Code Ends