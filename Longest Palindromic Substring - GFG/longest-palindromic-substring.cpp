// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(int i, int j, string s, vector<vector<int>> &dp){
        if(i > j) return 0;
        if(i == j) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j]) return dp[i][j] = 2 + solve(i + 1,j - 1,s,dp);
        
        else return dp[i][j] = max(solve(i + 1,j,s,dp),solve(i,j - 1,s,dp));
        
    }
    string longestPalindrome(string s){
        // code here
        int n = s.size();
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i > j) dp[i][j] = 0;
                else if(i == j) dp[i][j] = 1;
            }
        }
        
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(s[i] == s[j]) dp[i][j] = 2 + dp[i + 1][j - 1];
        
                else dp[i][j] = max(dp[i + 1][j],dp[i][j - 1]);
            }
        }
        
        int maxi = 0;
        int start, end;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] > maxi && j - i + 1 == dp[i][j]){
                    maxi = dp[i][j];
                    start = i;
                    end = j;
                }
            }
        }
        
        string ans = "";
        for(int k = start; k <= end; k++) ans.push_back(s[k]);
        
        return ans;
    }
};

// { Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}
  // } Driver Code Ends