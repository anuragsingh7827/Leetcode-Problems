// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int j, int &n, int &m, vector<vector<int>> &M, vector<vector<int>> &dp){
        if(j == m) return 0;
        if(i == 0 || i >= n + 1) return -1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int op1 = M[i - 1][j] + solve(i - 1,j + 1,n,m,M,dp);
        int op2 = M[i - 1][j] + solve(i,j + 1,n,m,M,dp);
        int op3 = M[i - 1][j] + solve(i + 1,j + 1,n,m,M,dp);
        
        return dp[i][j] = max(op1,max(op2,op3));
    }
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        // code here
        int ans = INT_MIN;
        vector<vector<int>> dp(n + 1, vector<int> (m, -1));
        for(int i = 1; i < n + 1; i++) ans = max(ans,solve(i,0,n,m,M,dp));
        
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