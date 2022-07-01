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
    if(i == 0 || j == 0 || k == 0) return 0;
    
    if(dp[i][j][k] != -1) return dp[i][j][k];
    
    if(a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]) return dp[i][j][k] =  1 + solve(i - 1,j - 1,k - 1,a,b,c,dp);
    
    if(a[i - 1] == b[j - 1] && b[j - 1] != c[k - 1]){
        return dp[i][j][k] = max(solve(i - 1,j - 1,k,a,b,c,dp),solve(i,j,k - 1,a,b,c,dp));
    }else if(a[i - 1] == c[k - 1] && c[k - 1] != b[j - 1]){
        return dp[i][j][k] = max(solve(i - 1,j,k - 1,a,b,c,dp),solve(i,j - 1,k,a,b,c,dp));
    }else if(b[j - 1] == c[k - 1] && c[k - 1] != a[i - 1]){
        return dp[i][j][k] = max(solve(i,j - 1,k - 1,a,b,c,dp),solve(i - 1,j,k,a,b,c,dp));
    }else if(a[i - 1] != b[j - 1] && b[j - 1] != c[k - 1]){
        int op1 = solve(i,j - 1,k - 1,a,b,c,dp);
        int op2 = solve(i - 1,j,k - 1,a,b,c,dp);
        int op3 = solve(i - 1,j - 1,k,a,b,c,dp);
        
        return dp[i][j][k] = max(op1,max(op2,op3));
    }
}
int LCSof3 (string a, string b, string c, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int>>> dp(n1 + 1, vector<vector<int>> (n2 + 1, vector<int> (n3 + 1, 0)));
    
    for(int i = 1; i <= n1; i++){
        for(int j = 1; j <= n2; j++){
            for(int k = 1; k <= n3; k++){
                if(a[i - 1] == b[j - 1] && b[j - 1] == c[k - 1]){
                    
                    dp[i][j][k] =  1 + dp[i - 1][j - 1][k - 1];
                    
                }
                else if(a[i - 1] == b[j - 1] && b[j - 1] != c[k - 1]){
                    
                    dp[i][j][k] = max(dp[i - 1][j - 1][k], dp[i][j][k - 1]);
                    
                }else if(a[i - 1] == c[k - 1] && c[k - 1] != b[j - 1]){
                    
                    dp[i][j][k] = max(dp[i - 1][j][k - 1], dp[i][j - 1][k]);
                    
                }else if(b[j - 1] == c[k - 1] && c[k - 1] != a[i - 1]){
                    
                    dp[i][j][k] = max(dp[i][j - 1][k - 1], dp[i - 1][j][k]);
                    
                }else if(a[i - 1] != b[j - 1] && b[j - 1] != c[k - 1]){
                    int op1 = dp[i][j - 1][k - 1];
                    int op2 = dp[i - 1][j][k - 1];
                    int op3 = dp[i - 1][j - 1][k];
                    
                    dp[i][j][k] = max(op1,max(op2,op3));
                }
            }
        }
    }
    
    return dp[n1][n2][n3];
}