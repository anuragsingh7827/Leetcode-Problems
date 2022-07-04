// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int lcs(int i, int j, string s1, string s2, vector<vector<int>> &dp){
        if(i == 0 || j == 0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i - 1] == s2[j - 1]) return dp[i][j] = 1 + lcs(i - 1,j - 1,s1,s2,dp);
        
        return dp[i][j] = max(lcs(i,j - 1,s1,s2,dp),lcs(i - 1,j,s1,s2,dp));
    }
    int longestPalinSubseq(string A) {
        //code here
        int n = A.size();
        
        string copy = A;
        reverse(A.begin(),A.end());
        
        vector<int> prev(n + 1, 0), cur(n + 1, 0);
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(copy[i - 1] == A[j - 1]) cur[j] = 1 + prev[j - 1];
        
                else cur[j] = max(cur[j - 1],prev[j]);
            }
            prev = cur;
        }
        
        return prev[n];
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends