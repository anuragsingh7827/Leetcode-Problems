// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int j, int &n, vector<vector<int>> &M, vector<vector<int>> &dp){
        if(i == 0 || i >= n + 1) return -1e9;
        if(j == 0) return M[i - 1][0];
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int op1 = M[i - 1][j] + solve(i - 1,j - 1,n,M,dp);
        int op2 = M[i - 1][j] + solve(i,j - 1,n,M,dp);
        int op3 = M[i - 1][j] + solve(i + 1,j - 1,n,M,dp);
        
        return dp[i][j] = max(op1,max(op2,op3));
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int ans = INT_MIN;
        vector<vector<int>> dp(n + 2, vector<int> (m, 0));
        
        for(int j = 1; j < m; j++) dp[0][j] = dp[n + 1][j] = -1e9;
        
        for(int i = 1; i <= n; i++) dp[i][0] = M[i - 1][0];
        
        for(int j = 1; j < m; j++){
            for(int i = 1; i <= n; i++){
                int op1 = M[i - 1][j] + dp[i - 1][j - 1];
                int op2 = M[i - 1][j] + dp[i][j - 1];
                int op3 = M[i - 1][j] + dp[i + 1][j - 1];
                
                dp[i][j] = max(op1,max(op2,op3));
            }
        }
        
        
        for(int i = 1; i < n + 1; i++){
            ans = max(ans,dp[i][m - 1]);
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends