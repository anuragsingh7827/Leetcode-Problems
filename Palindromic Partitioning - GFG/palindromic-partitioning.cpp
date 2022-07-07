// { Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPalindrome(int i, int j, string s){
        while(i < j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(int i, string str, int n, vector<int> &dp){
        if(i == n) return 0;
        
        if(dp[i] != -1) return dp[i];
        
        int cuts = INT_MAX;
        for(int j = i; j < n; j++){
            if(isPalindrome(i,j,str)){
                cuts = min(cuts,1 + solve(j + 1,str,n,dp));
            }
        }
        
        return dp[i] = cuts;
    }
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n, -1);
        return solve(0,str,n,dp) - 1;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  // } Driver Code Ends