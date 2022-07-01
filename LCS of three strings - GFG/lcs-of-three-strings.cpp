// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal
// } Driver Code Ends


int solve(int i, int j, int k, string &a, string &b, string &c, vector<vector<vector<int>>> &dp){
    if(i < 0 || j < 0 || k < 0) return 0;
    
    if(dp[i][j][k] != -1) return dp[i][j][k];
    
    if(a[i] == b[j] && b[j] == c[k]) return dp[i][j][k] =  1 + solve(i - 1,j - 1,k - 1,a,b,c,dp);
    
    if(a[i] == b[j] && b[j] != c[k]){
        return dp[i][j][k] = max(solve(i - 1,j - 1,k,a,b,c,dp),solve(i,j,k - 1,a,b,c,dp));
    }else if(a[i] == c[k] && c[k] != b[j]){
        return dp[i][j][k] = max(solve(i - 1,j,k - 1,a,b,c,dp),solve(i,j - 1,k,a,b,c,dp));
    }else if(b[j] == c[k] && c[k] != a[i]){
        return dp[i][j][k] = max(solve(i,j - 1,k - 1,a,b,c,dp),solve(i - 1,j,k,a,b,c,dp));
    }else if(a[i] != b[j] && b[j] != c[k]){
        int op1 = solve(i,j - 1,k - 1,a,b,c,dp);
        int op2 = solve(i - 1,j,k - 1,a,b,c,dp);
        int op3 = solve(i - 1,j - 1,k,a,b,c,dp);
        
        return dp[i][j][k] = max(op1,max(op2,op3));
    }
}
int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int>>> dp(n1, vector<vector<int>> (n2, vector<int> (n3 , -1)));
    
    return solve(n1 - 1,n2 - 1,n3 - 1,A,B,C,dp);
}