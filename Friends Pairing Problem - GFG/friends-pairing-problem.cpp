// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int mod = 1e9 + 7;
    long long solve(int n, vector<long long> &dp){
        if(n <= 1) return 1;
        
        if(dp[n] != -1) return dp[n];
        
        long long op1 = solve(n - 1,dp) % mod ;
        long long op2 = (((n - 1) % mod) * (solve(n - 2,dp) % mod)) % mod;
        
        return dp[n] = ((op1 % mod) + (op2 % mod)) % mod;
    }
    long long countFriendsPairings(int n) 
    { 
        // code here
        vector<long long> dp(n + 1, -1);
        long long ans = solve(n,dp) % mod;
        
        return ans;
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
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends