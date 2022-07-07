// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(int s, int e, int freq[], vector<vector<int>> &dp){
        if(s > e) return 0;
        
        if(dp[s][e] != -1) return dp[s][e];
        
        int totF = 0;
        for(int i = s; i <= e; i++) totF += freq[i];
        
        int cost = INT_MAX;
        for(int i = s; i <= e; i++){
            int op1 = solve(s,i - 1,freq,dp);
            int op2 = solve(i + 1,e,freq,dp);
            
            cost = min(cost,totF + op1 + op2);
        }
        
        return dp[s][e] = cost;
    }
    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        return solve(0,n - 1,freq,dp);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;
}  // } Driver Code Ends