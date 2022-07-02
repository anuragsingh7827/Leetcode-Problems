// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i, int j, vector<vector<int>> Matrix, int n, vector<vector<int>> &dp){
        if(i == 0) return Matrix[0][j - 1];
        if(j == 0 || j >= n + 1) return -1e9;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = Matrix[i][j - 1] + solve(i - 1,j,Matrix,n,dp);
        int dgl = Matrix[i][j - 1] + solve(i - 1,j - 1,Matrix,n,dp);
        int dgr = Matrix[i][j - 1] + solve(i - 1,j + 1,Matrix,n,dp);
        
        return dp[i][j] = max(up, max(dgl,dgr));
    }
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>> dp(N, vector<int> (N + 2, 0));
        
        for(int j = 1; j <= N; j++) dp[0][j] = Matrix[0][j - 1];
        
        for(int i = 1; i < N; i++) dp[i][0] = dp[i][N + 1] = -1e9;
        
        for(int i = 1; i < N; i++){
            for(int j = 1; j <= N; j++){
                int up = Matrix[i][j - 1] + dp[i - 1][j];
                int dgl = Matrix[i][j - 1] + dp[i - 1][j - 1];
                int dgr = Matrix[i][j - 1] + dp[i - 1][j + 1];
                
                dp[i][j] = max(up, max(dgl,dgr));
            }
        }
        
        int ans = 0;
        for(int j = 0; j < N + 2; j++) ans = max(ans,dp[N - 1][j]);
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends