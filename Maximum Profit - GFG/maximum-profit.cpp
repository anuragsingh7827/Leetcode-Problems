// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int solve(int ind, int buy, int cap, int A[], int n, vector<vector<vector<int>>> &dp){
        if(cap == 0) return 0;
        if(ind == n) return 0;
        
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        
        if(buy){
            int op1 = -A[ind] + solve(ind + 1,0,cap,A,n,dp);
            int op2 = solve(ind + 1,1,cap,A,n,dp);
            
            return dp[ind][buy][cap] = max(op1,op2);
        }else{
            int op1 = A[ind] + solve(ind + 1,1,cap - 1,A,n,dp);
            int op2 = solve(ind + 1,0,cap,A,n,dp);
            
            return dp[ind][buy][cap] = max(op1,op2);
        }
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<vector<int>>> dp(N + 1, vector<vector<int>> (2, vector<int> (K + 1, 0)));
        
        for(int ind = N - 1; ind >= 0; ind--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= K; cap++){
                    if(buy){
                        int op1 = -A[ind] + dp[ind + 1][0][cap];
                        int op2 = dp[ind + 1][1][cap];
                        
                        dp[ind][buy][cap] = max(op1,op2);
                    }else{
                        int op1 = A[ind] + dp[ind + 1][1][cap - 1];
                        int op2 = dp[ind + 1][0][cap];
                        
                        dp[ind][buy][cap] = max(op1,op2);
                    }
                }
            }
        }
        
        return dp[0][1][K];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends