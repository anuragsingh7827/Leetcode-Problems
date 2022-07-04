// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod = 1e9 + 7;
    long long add(long long a, long long b){
        return ((a % mod) + (b % mod)) % mod;
    }
    long long mul(long long a, long long b){
        return ((a % mod) * (b % mod)) % mod;
    }
    long long countBBTS(int h, vector<int> &dp){
        if(h <= 1) return 1;
        
        if(dp[h] != -1) return dp[h] % mod;
        
        long long x = countBBTS(h - 1,dp) % mod;
        long long y = countBBTS(h - 2,dp) % mod;
        long long cnt = add(mul(2,mul(x,y)),mul(x,x));
        
        return dp[h] = cnt % mod;
    }
    long long int countBT(int h) { 
        // code here
        vector<long long> dp(h + 1, 0);
        
        dp[0] = dp[1] = 1;
        
        for(int i = 2; i <= h; i++){
            long long x = dp[i - 1] % mod;
            long long y = dp[i - 2] % mod;
            long long cnt = add(mul(2,mul(x,y)),mul(x,x));
            
            dp[i] = cnt % mod;
        }
        
        long long ans = dp[h] % mod;
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends