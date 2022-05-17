// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool solve(string wild, int i, string pattern, int j, int** dp){
        
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0) return false;
        if(i >= 0 && j < 0){
            for(int k = 0; k <= i; k++){
                if(wild[k] != '*') return false;
            }
            return true;
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(wild[i] == pattern[j] || wild[i] == '?') return dp[i][j] = solve(wild,i - 1,pattern,j - 1,dp);
        else if(wild[i] == '*'){
            return dp[i][j] = solve(wild,i - 1,pattern,j,dp) || solve(wild,i,pattern,j - 1,dp);
        }
    }
    bool match(string wild, string pattern)
    {
        // code here
        int n = wild.length();
        int m = pattern.length();
        
        int** dp = new int*[n];
        for(int i = 0; i < n; i++) dp[i] = new int[m];
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++) dp[i][j] = -1;
        }
        
        return solve(wild,n - 1,pattern,m - 1,dp);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends