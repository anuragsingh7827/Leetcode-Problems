// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int mod = 1e9 + 7;
    long long add(long long a, long b){
        long long c = ((a % mod) + (b % mod)) % mod;
        return c;
    }
    long long mul(long long a, long long b){
        long long c = ((a % mod) * (b % mod)) % mod;
        return c;
    }
    long long solve(int n, int k, vector<long long> &dp){
        if(n == 1) return k;
        if(n == 2) return mul(k,k);
        
        if(dp[n] != -1) return dp[n] % mod;
         
        long long same = mul(solve(n - 2,k,dp),k - 1);
        long long diff = mul(solve(n - 1,k,dp),k - 1);
        
        long long ways = add(same,diff);
        
        return dp[n] = ways % mod;
    }
    long long countWays(int n, int k){
        // code here
        vector<long long> dp(n + 1, -1);
        long long ans = solve(n,k,dp);
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
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends