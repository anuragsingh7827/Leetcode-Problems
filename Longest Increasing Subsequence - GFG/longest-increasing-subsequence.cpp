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
        vector<int> arr;
        arr.push_back(a[0]);
        int len = 1;
        for(int i = 0; i < n; i++){
            if(a[i] > arr.back()){
                arr.push_back(a[i]);
                len++;
            }else{
                int ind = lower_bound(arr.begin(),arr.end(),a[i]) - arr.begin();
                arr[ind] = a[i];
            }
        }
        
        return len;
        
        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        
        // for(int ind = n - 1; ind >= 0; ind--){
        //     for(int prevInd = ind - 1; prevInd >= -1; prevInd--){
        //         int notTake = dp[ind + 1][prevInd + 1];
        //         int take = 0;
        //         if(prevInd == -1 || a[ind] > a[prevInd]) take = 1 + dp[ind + 1][ind + 1];
        //         dp[ind][prevInd + 1] = max(notTake,take);
        //     }
        // }
        
        // return dp[0][-1 + 1];
        
        // vector<int> dp(n, 1);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < i; j++){
        //         if(a[i] > a[j]) dp[i] = max(dp[i],1 + dp[j]);
        //     }
        // }
        
        // int ans = INT_MIN;
        // for(int i = 0; i < n; i++) ans = max(ans,dp[i]);
        
        // return ans;
        
        
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