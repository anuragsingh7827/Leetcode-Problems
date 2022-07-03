// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(int i, int j, vector<int> &a, int k, vector<vector<int>> &dp){
        if(i >= j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(a[j] - a[i] <= k) return 0;
        
        return dp[i][j] = min(1 + solve(i + 1,j,a,k,dp),1 + solve(i,j - 1,a,k,dp));
    }
    int removals(vector<int>& a, int k){
        //Code here
        int n = a.size();
        
        sort(a.begin(),a.end());
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        
        return solve(0,n - 1,a,k,dp);
    }
};


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.removals(a,k);
        
        cout<<ans<<endl;
    }
}


  // } Driver Code Ends