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
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        
        return lcs(n,n,A,copy,dp);
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